import ARKit

extension AvatarFaceTracking {
    
    /// Create tracking data from an ARFrame.
    /// Preserves the original ARFrame so AvatarView can use the reliable dataWithARFrame: path.
    public init(arFrame: ARFrame) {
        let faceAnchor = arFrame.anchors.compactMap { $0 as? ARFaceAnchor }.first
        
        var bs: [String: Float] = [:]
        if let faceAnchor {
            for (location, value) in faceAnchor.blendShapes {
                bs[location.rawValue] = value.floatValue
            }
        }
        
        let q = faceAnchor.map { simd_quatf($0.transform) } ?? simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)
        
        self.blendshapes = bs
        self.headRotation = q
        self.isTracking = faceAnchor?.isTracked ?? false
        self.arFrame = arFrame
    }
    
    /// Create tracking data from an ARFaceAnchor (no ARFrame, uses manual struct path).
    public init(faceAnchor: ARFaceAnchor) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        // Mirror quaternion for front camera: negate x and z
        let q = simd_quatf(faceAnchor.transform)
        let mirrored = simd_quatf(ix: -q.imag.x, iy: q.imag.y, iz: -q.imag.z, r: q.real)
        
        self.blendshapes = bs
        self.headRotation = mirrored
        self.isTracking = faceAnchor.isTracked
        self.arFrame = nil
    }
}
