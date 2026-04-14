import ARKit

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
    /// 1. Coordinate transform: identity for portrait (rotation matrices from binary data section)
    /// 2. `AVTARKitTransformToSceneKitTransformMatrix`: identity for portrait mode
    /// 3. Translation: `(t.x * 50, t.y * 20, (t.z - neutralZ) * 100)`
    ///    Scale factors from binary __TEXT,__const +0x620: `(50.0, 20.0, 100.0)`
    /// 4. Quaternion: `simd_quatf(faceTransform)` — Shepperd's method, same as Apple's
    ///    inline extraction at +0x4e8..+0x698 in `_AVTTrackingDataFromARFrame`
    /// 5. cameraSpace: `constrainHeadPose ^ 1` = 0 (world mode)
    /// 6. Blendshapes: mapped via `AVTBlendShapeLocationFromARIndex` order
    ///    (our `BlendshapeOrder.blendshapeSlotOrder` matches this exactly)
    /// 7. Smooth slots = raw slots (memcpy at +0x704..+0x758)
    ///
    /// The only device-dependent value is `neutralZ` (0.0 for iPhone, -0.465 for iPad).
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
            q = simd_quatf(faceAnchor.transform)
            let col3 = faceAnchor.transform.columns.3
            t = SIMD3<Float>(
                col3.x * Self.translationScale.x,
                col3.y * Self.translationScale.y,
                (col3.z - Self.neutralZ) * Self.translationScale.z
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
            // constrainHeadPose=0: camera-relative with uniform 100.0 scale.
            //
            // Apple's internal pipeline does scaledFace × camera.transform in the buffer,
            // then _applyHeadPose multiplies by the environment camera's worldTransform
            // (set via configureARCameraForFaceTracking) to compensate sensor rotation.
            //
            // We can't access that internal camera node, so we compute the final
            // camera-relative quaternion ourselves (same as Camera mode) and use
            // uniform 100.0 translation scale (Apple AR's defining characteristic).
            guard let frame else {
                q = simd_quatf(faceAnchor.transform)
                t = .zero
                space = .cameraRotationOnly
                break
            }
            let arPortraitCorrection = simd_float4x4(
                simd_quatf(angle: .pi / 2, axis: SIMD3<Float>(0, 0, 1))
            )
            let arCorrectedCamera = frame.camera.transform * arPortraitCorrection
            let arRelative = simd_inverse(arCorrectedCamera) * faceAnchor.transform
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
