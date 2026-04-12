import ARKit

extension AvatarFaceTracking {
    
    /// Mirror quaternion for front camera → animoji "mirror" effect.
    /// Flips yaw (y-axis rotation) so left turn shows as left turn from user's perspective.
    /// Preserves pitch (nod) direction.
    ///
    /// For a quaternion q = (ix, iy, iz, r):
    /// - Negating ix,iz flips pitch+roll but preserves yaw → WRONG (pitch inverts)
    /// - Negating iy,iz flips yaw but preserves pitch → CORRECT
    private static func mirrorQuaternion(_ q: simd_quatf) -> simd_quatf {
        simd_quatf(ix: q.imag.x, iy: -q.imag.y, iz: -q.imag.z, r: q.real)
    }
    
    /// World-space tracking. Avatar rotates when you and phone move together.
    public init(faceAnchor: ARFaceAnchor, worldSpace: Bool = true) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(faceAnchor.transform)
        let mirrored = Self.mirrorQuaternion(q)
        
        let t = faceAnchor.transform.columns.3
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = mirrored
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
        let mirrored = Self.mirrorQuaternion(q)
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = mirrored
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
        let mirrored = Self.mirrorQuaternion(q)
        
        let t = cameraRelativeTransform.columns.3
        
        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = mirrored
        self.headTranslation = SIMD3(t.x, t.y, t.z)
        self.coordinateSpace = .cameraFull
        self.timestamp = CACurrentMediaTime()
    }
}
