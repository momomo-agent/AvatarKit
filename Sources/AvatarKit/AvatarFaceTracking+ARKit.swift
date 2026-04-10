import ARKit

extension AvatarFaceTracking {
    
    /// Create tracking data from an ARFaceAnchor.
    /// Mirrors X axis for front camera (selfie mode).
    public init(faceAnchor: ARFaceAnchor) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        // Mirror quaternion for front camera: negate x and z
        let q = simd_quatf(faceAnchor.transform)
        let mirrored = simd_quatf(ix: -q.imag.x, iy: q.imag.y, iz: -q.imag.z, r: q.real)
        
        self.init(
            blendshapes: bs,
            headRotation: mirrored,
            isTracking: faceAnchor.isTracked
        )
    }
}
