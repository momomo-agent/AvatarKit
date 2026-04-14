import ARKit

extension AvatarFaceTracking {

    // MARK: - Translation Constants (from binary analysis)

    /// Translation scale factors extracted from AvatarKit binary at __TEXT,__const +0x620.
    /// Apple's `__convertARFaceAnchorTransformToSceneKitTransform` multiplies
    /// the face transform's translation column by these factors (constrainHeadPose=1 path).
    ///
    /// ARKit translation is in meters; these convert to avatar coordinate units.
    private static let translationScale = SIMD3<Float>(50.0, 20.0, 100.0)

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
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }

        // Quaternion: direct extraction from face transform matrix.
        // simd_quatf(matrix) uses Shepperd's method internally,
        // identical to Apple's inline implementation in _AVTTrackingDataFromARFrame.
        let q = simd_quatf(faceAnchor.transform)

        // Translation: apply Apple's scale factors.
        // For portrait mode, coordTransform = identity, so face transform = ARKit transform.
        let t = faceAnchor.transform.columns.3
        let scaledT = SIMD3<Float>(
            t.x * Self.translationScale.x,
            t.y * Self.translationScale.y,
            (t.z - Self.neutralZ) * Self.translationScale.z
        )

        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = scaledT
        self.coordinateSpace = .world  // constrainHeadPose ^ 1 = 0
        self.timestamp = CACurrentMediaTime()
    }

    /// Create tracking data from an ARFrame (convenience).
    /// Uses the first face anchor found in the frame.
    public init(arFrame: ARFrame) {
        let faceAnchor = arFrame.anchors.compactMap { $0 as? ARFaceAnchor }.first
        if let faceAnchor {
            self.init(faceAnchor: faceAnchor)
        } else {
            self.init()
        }
    }

    /// Whether a face is being tracked.
    public var isTracking: Bool {
        !blendshapes.isEmpty
    }
}
