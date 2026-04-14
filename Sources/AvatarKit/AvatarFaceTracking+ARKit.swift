import ARKit
import ObjectiveC

extension AvatarFaceTracking {

    // MARK: - Tracking Mode

    /// Tracking mode determines how head pose is computed from ARKit data.
    public enum TrackingMode: String, CaseIterable, Sendable {
        /// Apple's constrainHeadPose=1 (default). Head constrained to small range.
        /// Translation scaled by (50, 20, 100), neutralZ subtracted, cameraSpace=0.
        /// Used by Animoji/Memoji stickers, iMessage recording.
        case world

        /// Our camera-relative mode. inv(correctedCamera) × face.
        /// +90° Z compensates TrueDepth sensor landscape orientation.
        /// Translation scaled by (50, 20, 100), cameraSpace=1.
        case camera

        /// Apple's constrainHeadPose=0. Free head movement, camera-relative.
        /// Translation scaled uniformly by 100.0, then face × camera.transform.
        /// cameraSpace=1.
        case appleAR
    }

    // MARK: - Translation Constants (from binary analysis)

    /// Translation scale factors extracted from AvatarKit binary at __TEXT,__const +0x620.
    /// Apple's `__convertARFaceAnchorTransformToSceneKitTransform` multiplies
    /// the face transform's translation column by these factors (constrainHeadPose=1 path).
    ///
    /// ARKit translation is in meters; these convert to avatar coordinate units.
    private static let translationScale = SIMD3<Float>(50.0, 20.0, 100.0)

    /// Uniform translation scale for Apple AR mode (constrainHeadPose=0).
    /// 0x42C80000 = 100.0f (IEEE 754). Applied uniformly to all axes.
    private static let appleARScale: Float = 100.0

    /// Neutral Z offset subtracted from translation.z before scaling.
    /// Determined by `AVTGetNeutralZ()` via `dispatch_once` + `UIDevice.userInterfaceIdiom`:
    /// - iPhone (idiom != 1): 0.0 (BSS default — block_invoke only writes for iPad)
    /// - iPad (idiom == 1): -0.465 (0xBEEE147B as float)
    ///
    /// This centers the avatar's Z position around the typical face distance.
    private static let neutralZ: Float = {
        #if targetEnvironment(simulator)
        return 0.0
        #else
        return UIDevice.current.userInterfaceIdiom == .pad ? -0.465 : 0.0
        #endif
    }()

    // MARK: - ARKit Initializers

    /// Create tracking data from an ARKit face anchor — bit-exact with Apple's pipeline.
    ///
    /// Replicates `_AVTTrackingDataFromARFrame` (constrainHeadPose=1, portrait mode):
    ///
    /// 1. `displayCenterTransform` translation subtracted from face position
    ///    (Apple builds identity-rotation + negated-translation matrix, multiplies face by it)
    /// 2. `AVTARKitTransformToSceneKitTransformMatrix`: identity for portrait→portrait
    /// 3. Translation: `((t.x - dct.tx) * 50, (t.y - dct.ty) * 20, (t.z - dct.tz - neutralZ) * 100)`
    ///    Scale factors from binary __TEXT,__const +0x620: `(50.0, 20.0, 100.0)`
    /// 4. Quaternion: `simd_quatf(faceTransform)` — Shepperd's method (unaffected by dct)
    /// 5. cameraSpace: `constrainHeadPose ^ 1` = 0 (world mode)
    /// 6. Blendshapes: mapped via `AVTBlendShapeLocationFromARIndex` order
    /// 7. Smooth slots = raw slots (memcpy at +0x704..+0x758)
    /// 8. translation.w = 1.0 (preserved from original 4x4 matrix column)
    ///
    /// Device-dependent: `neutralZ` (0.0 iPhone, -0.465 iPad).
    /// Frame-dependent: `displayCenterTransform` (camera position offset, ~constant per session).
    ///
    /// - Note: Without `frame`, displayCenterTransform offset is zero (translation will differ).
    public init(faceAnchor: ARFaceAnchor) {
        self.init(faceAnchor: faceAnchor, frame: nil, mode: .world)
    }

    /// Create tracking data from an ARKit face anchor with a specific tracking mode.
    ///
    /// - Parameters:
    ///   - faceAnchor: The face anchor from ARKit.
    ///   - frame: The AR frame (required for `.camera` and `.appleAR` modes).
    ///   - mode: The tracking mode to use.
    public init(faceAnchor: ARFaceAnchor, frame: ARFrame?, mode: TrackingMode) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }

        let q: simd_quatf
        let t: SIMD3<Float>
        let space: CoordinateSpace

        switch mode {
        case .world:
            // constrainHeadPose=1: direct quaternion + scaled translation
            //
            // Apple's __convertARFaceAnchorTransformToSceneKitTransform (WORLD path):
            // 1. Build modified displayCenterTransform: identity rotation + negated translation
            // 2. Multiply: modified_dct × face → subtracts dct translation from face position
            // 3. Multiply by orientationMatrix (identity for portrait→portrait)
            // 4. Scale translation by (50, 20, 100), subtract neutralZ from Z
            //
            // Net effect on translation:
            //   t.x = (face.x - dct.tx) * 50
            //   t.y = (face.y - dct.ty) * 20
            //   t.z = (face.z - dct.tz - neutralZ) * 100
            // where dct = camera.displayCenterTransform.columns.3
            //
            // Quaternion is unaffected (identity rotation in both transforms).
            q = simd_quatf(faceAnchor.transform)
            let col3 = faceAnchor.transform.columns.3
            
            // Subtract displayCenterTransform translation (camera position offset)
            // displayCenterTransform is a private ARCamera property (4x4 matrix).
            // Confirmed accessible via ObjC runtime from device testing.
            let dct: SIMD3<Float>
            if let frame {
                let camera = frame.camera as AnyObject
                let sel = NSSelectorFromString("displayCenterTransform")
                if camera.responds(to: sel),
                   let imp = class_getMethodImplementation(type(of: camera) as? AnyClass, sel) {
                    typealias DCTFunc = @convention(c) (AnyObject, Selector) -> simd_float4x4
                    let dctMatrix = unsafeBitCast(imp, to: DCTFunc.self)(camera, sel)
                    dct = SIMD3<Float>(dctMatrix.columns.3.x, dctMatrix.columns.3.y, dctMatrix.columns.3.z)
                } else {
                    dct = .zero
                }
            } else {
                dct = .zero
            }
            
            t = SIMD3<Float>(
                (col3.x - dct.x) * Self.translationScale.x,
                (col3.y - dct.y) * Self.translationScale.y,
                (col3.z - dct.z - Self.neutralZ) * Self.translationScale.z
            )
            space = .world

        case .camera:
            // inv(correctedCamera) × face, +90° Z for portrait TrueDepth sensor
            guard let frame else {
                q = simd_quatf(faceAnchor.transform)
                t = .zero
                space = .cameraRotationOnly
                break
            }
            let portraitCorrection = simd_float4x4(
                simd_quatf(angle: .pi / 2, axis: SIMD3<Float>(0, 0, 1))
            )
            let correctedCamera = frame.camera.transform * portraitCorrection
            let relativeTransform = simd_inverse(correctedCamera) * faceAnchor.transform
            q = simd_quatf(relativeTransform)
            t = SIMD3<Float>(
                relativeTransform.columns.3.x * Self.translationScale.x,
                relativeTransform.columns.3.y * Self.translationScale.y,
                relativeTransform.columns.3.z * Self.translationScale.z
            )
            space = .cameraRotationOnly

        case .appleAR:
            // constrainHeadPose=0: inv(camera) × face, uniform 100.0 scale.
            //
            // Confirmed from Apple's AVTFaceTrackingInfo buffer comparison:
            // - quaternion = inv(camera.transform) × face.transform (NO portrait correction)
            // - translation = inv(camera.transform) × face.position × 100.0
            // - cameraSpace = 1
            //
            // Apple's _applyHeadPose then compensates the sensor rotation using
            // the internal camera node's worldTransform (M_ref). Since our internal
            // camera is identity, the buffer quaternion goes through as-is.
            // This means the animoji will appear rotated ~90° in our scene,
            // which is expected — this mode exists for bit-exact buffer comparison.
            guard let frame else {
                q = simd_quatf(faceAnchor.transform)
                t = .zero
                space = .cameraRotationOnly
                break
            }
            let arRelative = simd_inverse(frame.camera.transform) * faceAnchor.transform
            q = simd_quatf(arRelative)
            t = SIMD3<Float>(
                arRelative.columns.3.x * Self.appleARScale,
                arRelative.columns.3.y * Self.appleARScale,
                arRelative.columns.3.z * Self.appleARScale
            )
            space = .cameraRotationOnly
        }

        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = t
        self.coordinateSpace = space
        self.timestamp = CACurrentMediaTime()
    }

    /// Create tracking data from an ARFrame (convenience).
    /// Uses the first face anchor found in the frame.
    public init(arFrame: ARFrame, mode: TrackingMode = .world) {
        let faceAnchor = arFrame.anchors.compactMap { $0 as? ARFaceAnchor }.first
        if let faceAnchor {
            self.init(faceAnchor: faceAnchor, frame: arFrame, mode: mode)
        } else {
            self.init()
        }
    }

    /// Whether a face is being tracked.
    public var isTracking: Bool {
        !blendshapes.isEmpty
    }
}
