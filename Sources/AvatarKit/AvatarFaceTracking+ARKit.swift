import ARKit

extension AvatarFaceTracking {
    
    /// Create tracking data from an ARFrame.
    public init(arFrame: ARFrame) {
        let faceAnchor = arFrame.anchors.compactMap { $0 as? ARFaceAnchor }.first
        
        var bs: [String: Float] = [:]
        if let faceAnchor {
            for (location, value) in faceAnchor.blendShapes {
                bs[location.rawValue] = value.floatValue
            }
        }
        
        let q = faceAnchor.map { simd_quatf($0.transform) } ?? simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)
        let pitch = atan2(2 * (q.real * q.imag.x + q.imag.y * q.imag.z),
                          1 - 2 * (q.imag.x * q.imag.x + q.imag.y * q.imag.y)) * 180 / .pi
        let yaw = asin(max(-1, min(1, 2 * (q.real * q.imag.y - q.imag.z * q.imag.x)))) * 180 / .pi
        
        self.blendshapes = bs
        self.headRotation = HeadRotation(pitch: pitch, yaw: yaw)
        self.timestamp = CACurrentMediaTime()
    }
    
    /// Create tracking data from an ARFaceAnchor.
    public init(faceAnchor: ARFaceAnchor) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }
        
        let q = simd_quatf(faceAnchor.transform)
        // Mirror for front camera: negate x and z
        let mirrored = simd_quatf(ix: -q.imag.x, iy: q.imag.y, iz: -q.imag.z, r: q.real)
        let pitch = atan2(2 * (mirrored.real * mirrored.imag.x + mirrored.imag.y * mirrored.imag.z),
                          1 - 2 * (mirrored.imag.x * mirrored.imag.x + mirrored.imag.y * mirrored.imag.y)) * 180 / .pi
        let yaw = asin(max(-1, min(1, 2 * (mirrored.real * mirrored.imag.y - mirrored.imag.z * mirrored.imag.x)))) * 180 / .pi
        
        self.blendshapes = bs
        self.headRotation = HeadRotation(pitch: pitch, yaw: yaw)
        self.timestamp = CACurrentMediaTime()
    }
}
