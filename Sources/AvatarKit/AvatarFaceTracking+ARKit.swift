import ARKit

extension AvatarFaceTracking {
    
    /// Debug counter for periodic logging
    private static var debugInitCount = 0
    
    /// World-space tracking — extracts head pose delta from ARKit quaternion.
    ///
    /// ARKit's face quaternion includes the base orientation (face looking at camera ≈ Ry(π)).
    /// _applyHeadPose expects a delta from neutral, so we extract pitch/yaw/roll
    /// which naturally represent the delta (neutral face → pitch≈0, yaw≈0, roll≈0).
    public init(faceAnchor: ARFaceAnchor, worldSpace: Bool = true) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(faceAnchor.transform)
        let t = faceAnchor.transform.columns.3
        
        // Extract Euler angles (delta from neutral face orientation)
        let pitch = atan2(2 * (q.real * q.imag.x + q.imag.y * q.imag.z),
                          1 - 2 * (q.imag.x * q.imag.x + q.imag.y * q.imag.y))
        let yaw = asin(max(-1, min(1, 2 * (q.real * q.imag.y - q.imag.z * q.imag.x))))
        let roll = atan2(2 * (q.real * q.imag.z + q.imag.x * q.imag.y),
                         1 - 2 * (q.imag.y * q.imag.y + q.imag.z * q.imag.z))
        
        // Reconstruct as delta quaternion (pitch × yaw × roll)
        let qP = simd_quatf(angle: pitch, axis: SIMD3<Float>(1, 0, 0))
        let qY = simd_quatf(angle: yaw, axis: SIMD3<Float>(0, 1, 0))
        let qR = simd_quatf(angle: roll, axis: SIMD3<Float>(0, 0, 1))
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = qP * qY * qR
        self.headTranslation = SIMD3(t.x, t.y, t.z)
        self.coordinateSpace = .world
        self.timestamp = CACurrentMediaTime()
        
        // === DEBUG POINT B: World init output ===
        Self.debugInitCount += 1
        if Self.debugInitCount % 120 == 1 {
            print("[B-WORLD] ARKit.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", q.imag.x, q.imag.y, q.imag.z, q.real)))")
            print("[B-WORLD] euler=(p:\(String(format: "%.4f", pitch)) y:\(String(format: "%.4f", yaw)) r:\(String(format: "%.4f", roll)))")
            print("[B-WORLD] output.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", rawQuaternion!.imag.x, rawQuaternion!.imag.y, rawQuaternion!.imag.z, rawQuaternion!.real)))")
            print("[B-WORLD] output.t=(\(String(format: "%.4f,%.4f,%.4f", headTranslation.x, headTranslation.y, headTranslation.z)))")
            print("[B-WORLD] ---")
        }
    }
    
    /// Camera-relative tracking — replicates Apple's AvatarKit pipeline.
    ///
    /// From binary analysis of `dataWithARFrame` + `_applyHeadPose`:
    /// - `dataWithARFrame` puts WORLD-SPACE face quaternion in the buffer
    ///   (coordTransform = identity for portrait, the only ARKit face tracking orientation)
    /// - `_applyHeadPose` camera branch multiplies buffer quaternion × pov.worldTransform
    ///   to transform into scene-camera space
    ///
    /// So the buffer quaternion is the same as world mode — the camera-relative
    /// transformation happens inside `_applyHeadPose`, not here.
    public init(faceAnchor: ARFaceAnchor, cameraTransform: simd_float4x4) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }

        // World-space face quaternion — same extraction as world mode.
        // _applyHeadPose handles the camera-relative transform internally
        // when cameraSpace=1 and pov is provided.
        let q = simd_quatf(faceAnchor.transform)
        let t = faceAnchor.transform.columns.3

        // Extract Euler angles and reconstruct as delta quaternion (same as world init)
        let pitch = atan2(2 * (q.real * q.imag.x + q.imag.y * q.imag.z),
                          1 - 2 * (q.imag.x * q.imag.x + q.imag.y * q.imag.y))
        let yaw = asin(max(-1, min(1, 2 * (q.real * q.imag.y - q.imag.z * q.imag.x))))
        let roll = atan2(2 * (q.real * q.imag.z + q.imag.x * q.imag.y),
                         1 - 2 * (q.imag.y * q.imag.y + q.imag.z * q.imag.z))
        
        let qP = simd_quatf(angle: pitch, axis: SIMD3<Float>(1, 0, 0))
        let qY = simd_quatf(angle: yaw, axis: SIMD3<Float>(0, 1, 0))
        let qR = simd_quatf(angle: roll, axis: SIMD3<Float>(0, 0, 1))

        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = qP * qY * qR
        // Camera mode: zero translation. Raw ARKit meters don't map to avatar units,
        // and _applyHeadPose camera branch subtracts arOffset then transforms by
        // pov.worldTransform — small meter values produce wildly wrong positions.
        // Apple's dataWithARFrame does a meters→avatar-units conversion we haven't
        // reverse engineered yet. Translation tracking requires that conversion.
        self.headTranslation = .zero
        self.coordinateSpace = .cameraRotationOnly
        self.timestamp = CACurrentMediaTime()
        
        // === DEBUG POINT B: Camera init output ===
        Self.debugInitCount += 1
        if Self.debugInitCount % 120 == 2 {
            let cq = simd_quatf(cameraTransform)
            print("[B-CAM] face.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", q.imag.x, q.imag.y, q.imag.z, q.real)))")
            print("[B-CAM] cam.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", cq.imag.x, cq.imag.y, cq.imag.z, cq.real)))")
            print("[B-CAM] output.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", rawQuaternion!.imag.x, rawQuaternion!.imag.y, rawQuaternion!.imag.z, rawQuaternion!.real)))")
            print("[B-CAM] output.t=(\(String(format: "%.4f,%.4f,%.4f", headTranslation.x, headTranslation.y, headTranslation.z)))")
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
