import ARKit

extension AvatarFaceTracking {
    
    /// Debug counter for periodic logging
    private static var debugInitCount = 0
    
    /// Create tracking data from an ARKit face anchor.
    ///
    /// Uses camera mode (cameraSpace=1) so that `_applyHeadPose` applies the
    /// SceneKit pov transform at render time. This is the correct approach because:
    ///
    /// 1. ARKit's faceAnchor.transform is in world space
    /// 2. Apple's `dataWithARFrame` pre-bakes the camera viewMatrix into the quaternion
    ///    (via `__convertARFaceAnchorTransformToSceneKitTransform`), then stores as world mode
    /// 3. We don't have access to ARKit's viewMatrix, but we DO have the SceneKit pov
    /// 4. Camera mode lets `_applyHeadPose` apply the pov transform:
    ///    `combined = rotMatrix(q) × pov.worldTransform`
    ///    `neckNode.orientation = quaternion(combined.rotation)`
    ///
    /// Both approaches produce the same visual result when pov matches the ARKit camera.
    ///
    /// The quaternion is extracted directly from the face transform matrix using
    /// `simd_quatf(matrix)` (Shepperd's method), matching Apple's extraction in
    /// `_AVTTrackingDataFromARFrame`. No euler decomposition is performed.
    ///
    /// Translation is zero because:
    /// - In camera mode, `_applyHeadPose` computes position from `combined.translation`
    /// - ARKit meters don't map directly to avatar coordinate units
    /// - Apple's pipeline converts meters→avatar-units in `dataWithARFrame`; we haven't
    ///   reverse engineered that conversion
    public init(faceAnchor: ARFaceAnchor) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(faceAnchor.transform)
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = .zero
        self.coordinateSpace = .cameraRotationOnly
        self.timestamp = CACurrentMediaTime()
        
        Self.debugInitCount += 1
        if Self.debugInitCount % 120 == 1 {
            print("[TRACK] q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", q.imag.x, q.imag.y, q.imag.z, q.real))) mode=camera")
        }
    }
    
    /// Create tracking data with explicit coordinate space control.
    ///
    /// - `cameraRelative: true` (default): camera mode — `_applyHeadPose` applies pov transform.
    ///   Use this when passing raw ARKit face quaternions.
    /// - `cameraRelative: false`: world mode — `_applyHeadPose` sets neckNode directly.
    ///   Use this ONLY when the quaternion has already been transformed to avatar space
    ///   (e.g., pre-baked with viewMatrix × clampedRotation, as Apple does internally).
    public init(faceAnchor: ARFaceAnchor, cameraRelative: Bool) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(faceAnchor.transform)
        let t = faceAnchor.transform.columns.3
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = cameraRelative ? .zero : SIMD3(t.x, t.y, t.z)
        self.coordinateSpace = cameraRelative ? .cameraRotationOnly : .world
        self.timestamp = CACurrentMediaTime()
    }

    /// Create tracking data from an ARFrame (convenience).
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
