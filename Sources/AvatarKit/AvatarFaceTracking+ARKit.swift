import ARKit

extension AvatarFaceTracking {
    
    /// World-space tracking — raw ARKit quaternion.
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
    
    /// Camera-relative tracking — replicates Apple's AvatarKit pipeline.
    ///
    /// From binary analysis of __convertARFaceAnchorTransformToSceneKitTransform
    /// (iPhone18,4 26.3, __TEXT,__const):
    /// - coordTransform = identity for portrait (the only orientation ARKit face tracking uses)
    /// - Result: inverse(camera.transform) × face.transform
    public init(faceAnchor: ARFaceAnchor, cameraTransform: simd_float4x4) {
        var bs: [String: Float] = [:]
        for (location, value) in faceAnchor.blendShapes {
            bs[location.rawValue] = value.floatValue
        }

        // Portrait: coordTransform = identity, so just inverse(camera) × face
        let result = cameraTransform.inverse * faceAnchor.transform

        let q = simd_quatf(result)
        let t = result.columns.3

        self.blendshapes = bs
        self.headRotation = .zero
        self.rawQuaternion = q
        self.headTranslation = SIMD3(t.x, t.y, t.z)
        self.coordinateSpace = .cameraRotationOnly
        self.timestamp = CACurrentMediaTime()
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
