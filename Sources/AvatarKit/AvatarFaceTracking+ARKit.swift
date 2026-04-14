import ARKit

extension AvatarFaceTracking {
    
    /// Debug counter for periodic logging
    private static var debugInitCount = 0
    
    /// World-space tracking — passes ARKit quaternion directly to the buffer.
    ///
    /// ARKit's faceAnchor.transform rotation IS the delta from neutral:
    /// - Neutral face (looking at camera) = identity rotation
    /// - Head tilted 15° down = Rx(15°)
    /// - Head turned 30° left = Ry(30°)
    ///
    /// Apple's `dataWithARFrame` extracts the quaternion from the face transform
    /// matrix directly (via `__convertARFaceAnchorTransformToSceneKitTransform`,
    /// which returns identity × face.transform for portrait mode).
    /// `_applyHeadPose` then sets neckNode.orientation = this quaternion.
    ///
    /// Previous implementation decomposed to euler angles and reconstructed,
    /// which introduced up to 0.077 error for combined rotations.
    public init(faceAnchor: ARFaceAnchor, worldSpace: Bool = true) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(faceAnchor.transform)
        let t = faceAnchor.transform.columns.3
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q  // Direct quaternion — bit-exact with Apple's pipeline
        self.headTranslation = SIMD3(t.x, t.y, t.z)
        self.coordinateSpace = .world
        self.timestamp = CACurrentMediaTime()
        
        // === DEBUG POINT B: World init output ===
        Self.debugInitCount += 1
        if Self.debugInitCount % 120 == 1 {
            print("[B-WORLD] ARKit.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", q.imag.x, q.imag.y, q.imag.z, q.real)))")
            print("[B-WORLD] output.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", rawQuaternion!.imag.x, rawQuaternion!.imag.y, rawQuaternion!.imag.z, rawQuaternion!.real)))")
            print("[B-WORLD] output.t=(\(String(format: "%.4f,%.4f,%.4f", headTranslation.x, headTranslation.y, headTranslation.z)))")
            print("[B-WORLD] ---")
        }
    }
    
    /// Camera-relative tracking — same quaternion as world mode.
    ///
    /// From binary analysis of `dataWithARFrame` + `_applyHeadPose`:
    /// - Buffer quaternion = face quaternion from ARKit (world-space delta from neutral)
    /// - `_applyHeadPose` camera branch: combined = rotMatrix(q) × pov.worldTransform
    ///   - neckNode.orientation = quaternion(combined.rotation)
    ///   - rootJoint.position = combined.translation - convertPosition(arOffset)
    ///
    /// Translation is zero because raw ARKit meters don't map to avatar coordinate units.
    /// Apple's `dataWithARFrame` converts meters→avatar-units; we haven't reverse
    /// engineered that conversion yet.
    public init(faceAnchor: ARFaceAnchor, cameraTransform: simd_float4x4) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }

        let q = simd_quatf(faceAnchor.transform)

        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q  // Direct quaternion — same as world mode
        self.headTranslation = .zero  // Zero: meters→avatar-units conversion unknown
        self.coordinateSpace = .cameraRotationOnly
        self.timestamp = CACurrentMediaTime()
        
        // === DEBUG POINT B: Camera init output ===
        Self.debugInitCount += 1
        if Self.debugInitCount % 120 == 2 {
            let cq = simd_quatf(cameraTransform)
            print("[B-CAM] face.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", q.imag.x, q.imag.y, q.imag.z, q.real)))")
            print("[B-CAM] cam.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", cq.imag.x, cq.imag.y, cq.imag.z, cq.real)))")
            print("[B-CAM] output.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", rawQuaternion!.imag.x, rawQuaternion!.imag.y, rawQuaternion!.imag.z, rawQuaternion!.real)))")
            print("[B-CAM] ---")
        }
    }
    
    /// Camera-relative with translation tracking.
    public init(faceAnchor: ARFaceAnchor, cameraTransform: simd_float4x4, withTranslation: Bool) {
        self.init(faceAnchor: faceAnchor, cameraTransform: cameraTransform)
        if withTranslation {
            self.coordinateSpace = .cameraFull
        }
    }

    /// Create tracking data from an ARFrame (convenience).
    public init(arFrame: ARFrame) {
        let faceAnchor = arFrame.anchors.compactMap { $0 as? ARFaceAnchor }.first
        if let faceAnchor {
            self.init(faceAnchor: faceAnchor, cameraTransform: arFrame.camera.transform)
        } else {
            self.init()
        }
    }

    /// Whether a face is being tracked.
    public var isTracking: Bool {
        !blendshapes.isEmpty
    }
}
