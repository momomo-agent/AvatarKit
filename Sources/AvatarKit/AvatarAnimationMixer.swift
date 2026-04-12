import Foundation
import simd

// MARK: - Animation Mixer

/// Merges outputs from multiple animation sources (LipSync, IdleAnimator, manual)
/// into a single AvatarFaceTracking that can be applied to the avatar.
///
/// Priority order (higher overrides lower for conflicting blendshapes):
/// 1. Manual overrides (explicit blendshape sets)
/// 2. Lip sync (mouth region)
/// 3. Idle animation (eyes, brows, breathing, head)
///
/// For non-conflicting blendshapes, values are additive.
/// Head rotation is composed (idle × lip emphasis).
public class AvatarAnimationMixer {
    
    /// The lip sync source. Mouth blendshapes from here take priority.
    public var lipSync: AvatarLipSync?
    
    /// The idle animator source. Provides blinks, breathing, head motion, expressions.
    public var idleAnimator: AvatarIdleAnimator?
    
    /// Manual blendshape overrides. These always win.
    public var manualOverrides: [String: Float] = [:]
    
    /// Manual head rotation override. Set to nil to use computed rotation.
    public var manualHeadRotation: simd_quatf?
    
    /// The latest mixed result. Updated every frame.
    public private(set) var currentTracking = AvatarFaceTracking()
    
    /// Called every frame with the mixed tracking data.
    public var onFrame: ((AvatarFaceTracking) -> Void)?
    
    // MARK: - State
    
    private var lipSyncBlendshapes: [String: Float] = [:]
    private var idleBlendshapes: [String: Float] = [:]
    private var idleHeadRotation: simd_quatf = .init(ix: 0, iy: 0, iz: 0, r: 1)
    
    // MARK: - Init
    
    public init() {}
    
    /// Wire up the animation sources. Call this after setting lipSync and idleAnimator.
    public func connect() {
        lipSync?.onFrame = { [weak self] blendshapes in
            self?.lipSyncBlendshapes = blendshapes
            self?.mix()
        }
        
        idleAnimator?.onFrame = { [weak self] blendshapes, headRotation in
            self?.idleBlendshapes = blendshapes
            self?.idleHeadRotation = headRotation
            self?.mix()
        }
    }
    
    // MARK: - Mixing
    
    private func mix() {
        var merged: [String: Float] = [:]
        
        // Layer 1: Idle (base layer)
        for (key, value) in idleBlendshapes {
            merged[key] = value
        }
        
        // Layer 2: Lip sync (mouth region overrides idle, others additive)
        for (key, value) in lipSyncBlendshapes {
            if Self.mouthBlendshapes.contains(key) {
                // Mouth: lip sync takes priority
                merged[key] = value
            } else {
                // Non-mouth: additive
                merged[key] = (merged[key] ?? 0) + value
            }
        }
        
        // Layer 3: Manual overrides (always win)
        for (key, value) in manualOverrides {
            merged[key] = value
        }
        
        // Clamp all values to [0, 1]
        for key in merged.keys {
            merged[key] = min(max(merged[key]!, 0), 1)
        }
        
        // Remove near-zero
        merged = merged.filter { $0.value > 0.001 }
        
        // Head rotation
        // Head rotation: convert quaternion to HeadRotation degrees
        let q = manualHeadRotation ?? idleHeadRotation
        let pitch = atan2(2 * (q.real * q.imag.x + q.imag.y * q.imag.z),
                          1 - 2 * (q.imag.x * q.imag.x + q.imag.y * q.imag.y)) * 180 / .pi
        let yaw = asin(max(-1, min(1, 2 * (q.real * q.imag.y - q.imag.z * q.imag.x)))) * 180 / .pi
        let headRotation = AvatarFaceTracking.HeadRotation(pitch: pitch, yaw: yaw)
        
        let tracking = AvatarFaceTracking(
            blendshapes: merged,
            headRotation: headRotation
        )
        
        currentTracking = tracking
        onFrame?(tracking)
    }
    
    // MARK: - Convenience
    
    /// Update the idle animator's speaking state and audio energy.
    /// Call this from your audio pipeline.
    public func updateSpeakingState(isSpeaking: Bool, audioEnergy: Float = 0) {
        idleAnimator?.isSpeaking = isSpeaking
        idleAnimator?.audioEnergy = audioEnergy
    }
    
    /// Set the mood for expression overlay.
    public func setMood(_ mood: AvatarIdleAnimator.Mood) {
        idleAnimator?.setMood(mood)
    }
    
    // MARK: - Blendshape Categories
    
    /// Blendshapes that belong to the mouth region.
    /// Lip sync has priority over idle for these.
    private static let mouthBlendshapes: Set<String> = [
        "jawOpen", "jawForward", "jawLeft", "jawRight",
        "mouthClose", "mouthFunnel", "mouthPucker",
        "mouthLeft", "mouthRight",
        "mouthSmileLeft", "mouthSmileRight",
        "mouthFrownLeft", "mouthFrownRight",
        "mouthDimpleLeft", "mouthDimpleRight",
        "mouthStretchLeft", "mouthStretchRight",
        "mouthRollLower", "mouthRollUpper",
        "mouthShrugLower", "mouthShrugUpper",
        "mouthPressLeft", "mouthPressRight",
        "mouthLowerDownLeft", "mouthLowerDownRight",
        "mouthUpperUpLeft", "mouthUpperUpRight",
    ]
}
