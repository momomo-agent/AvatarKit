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
    
    /// The performative pose blender. Provides semantic expression overlays.
    public let poseBlender = PoseBlender()
    
    /// Whether the character is currently speaking (set by BehaviorEngine).
    /// Used to suppress idle mouth shapes even when lip sync data is momentarily empty.
    public var isSpeaking = false
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
    private var idleHeadTranslation: SIMD3<Float> = .zero
    private var idleBodyRotation: simd_quatf = .init(ix: 0, iy: 0, iz: 0, r: 1)
    private var idleBodyTranslation: SIMD3<Float> = .zero

    // MARK: - Init

    public init() {}

    /// Wire up the animation sources. Call this after setting lipSync and idleAnimator.
    public func connect() {
        // LipSync only updates data — does NOT trigger mix.
        // IdleAnimator triggers the single mix() per frame.
        lipSync?.onFrame = { [weak self] blendshapes in
            self?.lipSyncBlendshapes = blendshapes
        }

        idleAnimator?.onFrame = { [weak self] blendshapes, headRotation, headTranslation, bodyRotation, bodyTranslation in
            self?.idleBlendshapes = blendshapes
            self?.idleHeadRotation = headRotation
            self?.idleHeadTranslation = headTranslation
            self?.idleBodyRotation = bodyRotation
            self?.idleBodyTranslation = bodyTranslation
            self?.mix()
        }
    }
    
    // MARK: - Mixing
    
    private func mix() {
        var merged: [String: Float] = [:]

        // Layer 1: Idle (base layer)
        // When speaking, strip ALL mouth blendshapes from idle
        // Use isSpeaking flag (not lipSyncBlendshapes.isEmpty) to avoid flicker
        let lipSyncActive = isSpeaking || !lipSyncBlendshapes.isEmpty
        for (key, value) in idleBlendshapes {
            if lipSyncActive && Self.mouthBlendshapes.contains(key) { continue }
            merged[key] = value
        }
        
        // Layer 1.5: Performative pose (additive on idle, before lip sync)
        poseBlender.update(dt: 1.0 / 60.0)
        let poseBS = poseBlender.blendshapes()
        for (key, value) in poseBS {
            // Skip mouth shapes entirely when lip sync is active
            if lipSyncActive && Self.mouthBlendshapes.contains(key) { continue }
            let weight: Float = Self.mouthBlendshapes.contains(key) ? 0.3 : 0.6
            merged[key] = (merged[key] ?? 0) + value * weight
        }

        // Layer 2: Lip sync (mouth region)
        // When lip sync is active, mouth-region idle values should be suppressed,
        // but emotion-driven mouth shapes (smile, frown) should BLEND, not override.
        for (key, value) in lipSyncBlendshapes {
            if Self.mouthBlendshapes.contains(key) {
                if Self.emotionMouthBlendshapes.contains(key) {
                    // Emotion-linked mouth shapes: weighted blend
                    // Lip sync gets 70%, emotion gets 30% (so you can smile while talking)
                    let idleValue = merged[key] ?? 0
                    merged[key] = value * 0.7 + idleValue * 0.3
                } else {
                    // Pure articulation shapes: lip sync wins
                    merged[key] = value
                }
            } else {
                merged[key] = (merged[key] ?? 0) + value
            }
        }
        
        // Suppress idle mouth shapes that conflict with active lip sync
        if lipSyncActive {
            for key in Self.articulationBlendshapes {
                if lipSyncBlendshapes[key] == nil {
                    merged[key] = nil // clear idle articulation when lip sync is driving
                }
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
        
        // Head rotation: compose idle + pose neck orientation
        let poseNeck = poseBlender.neckOrientation()
        let composedRotation = manualHeadRotation ?? simd_mul(idleHeadRotation, poseNeck)

        let tracking = AvatarFaceTracking(
            blendshapes: merged,
            rawQuaternion: composedRotation,
            headTranslation: idleHeadTranslation,
            bodyRotation: idleBodyRotation,
            bodyTranslation: idleBodyTranslation
        )
        
        currentTracking = tracking
        onFrame?(tracking)
    }
    
    // MARK: - Convenience
    
    /// Update the idle animator's speaking state and audio energy.
    /// Call this from your audio pipeline.
    public func updateSpeakingState(isSpeaking speaking: Bool, audioEnergy: Float = 0) {
        self.isSpeaking = speaking
        idleAnimator?.isSpeaking = speaking
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
    
    /// Mouth shapes driven by emotion (smile, frown).
    /// These should BLEND with lip sync, not be overridden.
    /// Research: you can smile while talking — it's additive.
    private static let emotionMouthBlendshapes: Set<String> = [
        "mouthSmileLeft", "mouthSmileRight",
        "mouthFrownLeft", "mouthFrownRight",
        "mouthDimpleLeft", "mouthDimpleRight",
    ]
    
    /// Pure articulation shapes that should be cleared when lip sync is active.
    /// These are the shapes that ONLY make sense for speech, not emotion.
    private static let articulationBlendshapes: Set<String> = [
        "jawOpen", "jawForward",
        "mouthClose", "mouthFunnel", "mouthPucker",
        "mouthStretchLeft", "mouthStretchRight",
        "mouthRollLower", "mouthRollUpper",
        "mouthShrugLower", "mouthShrugUpper",
        "mouthPressLeft", "mouthPressRight",
        "mouthLowerDownLeft", "mouthLowerDownRight",
        "mouthUpperUpLeft", "mouthUpperUpRight",
    ]
}
