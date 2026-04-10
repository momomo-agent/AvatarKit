import Foundation
import ARKit
import simd

/// Face tracking data that AvatarView consumes.
/// Provide this from any tracking source (ARKit, HumanSenseKit, etc.)
public struct AvatarFaceTracking {
    /// 51 ARKit blendshape coefficients keyed by ARFaceAnchor.BlendShapeLocation rawValue.
    /// e.g. ["jawOpen": 0.5, "eyeBlinkLeft": 0.8, ...]
    public var blendshapes: [String: Float]
    
    /// Head rotation as a quaternion (identity = facing camera straight on).
    public var headRotation: simd_quatf
    
    /// Whether a face is currently detected.
    public var isTracking: Bool
    
    /// Original ARFrame for the most reliable rendering path.
    /// When available, AvatarView uses dataWithARFrame: instead of manual struct building.
    internal var arFrame: ARFrame?
    
    public init(
        blendshapes: [String: Float] = [:],
        headRotation: simd_quatf = simd_quatf(angle: .pi, axis: simd_float3(0, 1, 0)),
        isTracking: Bool = false
    ) {
        self.blendshapes = blendshapes
        self.headRotation = headRotation
        self.isTracking = isTracking
        self.arFrame = nil
    }
}
