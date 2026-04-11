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
    
    /// Whether the avatar renders in camera coordinate space.
    /// `true` (default): avatar position follows head translation (natural for AR/face tracking).
    /// `false`: avatar stays centered on screen (better for audio-driven animation).
    public var cameraSpace: Bool
    
    /// Original ARFrame for the most reliable rendering path.
    /// When available, AvatarView uses dataWithARFrame: instead of manual struct building.
    internal var arFrame: ARFrame?
    
    public init(
        blendshapes: [String: Float] = [:],
        headRotation: simd_quatf = simd_quatf(ix: 0, iy: 0, iz: 0, r: 1),
        isTracking: Bool = false,
        cameraSpace: Bool = true
    ) {
        self.blendshapes = blendshapes
        self.headRotation = headRotation
        self.isTracking = isTracking
        self.cameraSpace = cameraSpace
        self.arFrame = nil
    }
}
