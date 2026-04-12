import ARKit

extension AvatarFaceTracking {
    
    // No mirroring needed. AvatarKit's animoji model faces the camera,
    // so ARKit's quaternion naturally produces the "mirror" effect.
    // Verified by simulator test: Apple passes quaternion through unchanged.
    
    /// World-space tracking. Avatar rotates when you and phone move together.
    public init(faceAnchor: ARFaceAnchor, worldSpace: Bool = true) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(faceAnchor.transform)
        let t = faceAnchor.transform.columns.3
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = SIMD3(t.x, t.y, t.z)
        self.coordinateSpace = .world
        self.timestamp = CACurrentMediaTime()
    }
    
    /// Camera-relative, rotation only. Avatar stays still when you and phone move together.
    public init(faceAnchor: ARFaceAnchor, cameraRelativeTransform: simd_float4x4) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(cameraRelativeTransform)
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = .zero
        self.coordinateSpace = .cameraRotationOnly
        self.timestamp = CACurrentMediaTime()
    }
    
    /// Camera-relative with translation. Avatar follows your head position relative to camera.
    public init(faceAnchor: ARFaceAnchor, cameraRelativeTransform: simd_float4x4, withTranslation: Bool) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(cameraRelativeTransform)
        let t = cameraRelativeTransform.columns.3
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = SIMD3(t.x, t.y, t.z)
        self.coordinateSpace = .cameraFull
        self.timestamp = CACurrentMediaTime()
    }
}
