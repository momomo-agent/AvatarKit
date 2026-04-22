import Foundation
import simd

// MARK: - Emotion Engine

/// Continuous emotion model using the Valence-Arousal circumplex.
///
/// Instead of discrete presets (happy/sad/angry), emotions live in a 2D space:
/// - **Valence** (-1 to 1): negative ← → positive
/// - **Arousal** (-1 to 1): calm ← → excited
///
/// This allows smooth blending between any emotional state.
/// Based on Russell's Circumplex Model of Affect (1980).
///
/// Mapping:
/// - Happy:    valence=0.8,  arousal=0.3
/// - Excited:  valence=0.6,  arousal=0.8
/// - Calm:     valence=0.3,  arousal=-0.5
/// - Sad:      valence=-0.6, arousal=-0.3
/// - Angry:    valence=-0.7, arousal=0.7
/// - Surprised: valence=0.2, arousal=0.9
/// - Thinking: valence=0.0,  arousal=0.1
/// - Neutral:  valence=0.0,  arousal=0.0
public class EmotionEngine {
    
    // MARK: - State
    
    /// Current valence (-1 negative ... +1 positive).
    public private(set) var valence: Float = 0
    
    /// Current arousal (-1 calm ... +1 excited).
    public private(set) var arousal: Float = 0
    
    /// Target valence (we smoothly interpolate toward this).
    private var targetValence: Float = 0
    private var targetArousal: Float = 0
    
    /// Transition speed (higher = faster). Default ~2s to reach target.
    public var transitionSpeed: Float = 2.0
    
    /// Micro-fluctuation intensity. Emotions aren't perfectly stable.
    public var fluctuation: Float = 0.15
    
    // Noise generators for micro-fluctuation
    private let valenceNoise = SmoothNoise(frequency: 0.3)
    private let arousalNoise = SmoothNoise(frequency: 0.25)
    
    // MARK: - Presets
    
    public struct EmotionPreset {
        public let valence: Float
        public let arousal: Float
        
        public static let neutral   = EmotionPreset(valence: 0.0,  arousal: 0.0)
        public static let happy     = EmotionPreset(valence: 0.8,  arousal: 0.3)
        public static let excited   = EmotionPreset(valence: 0.6,  arousal: 0.8)
        public static let calm      = EmotionPreset(valence: 0.3,  arousal: -0.5)
        public static let sad       = EmotionPreset(valence: -0.6, arousal: -0.3)
        public static let angry     = EmotionPreset(valence: -0.7, arousal: 0.7)
        public static let surprised = EmotionPreset(valence: 0.2,  arousal: 0.9)
        public static let thinking  = EmotionPreset(valence: 0.0,  arousal: 0.1)
        public static let concerned = EmotionPreset(valence: -0.3, arousal: 0.2)
        public static let amused    = EmotionPreset(valence: 0.7,  arousal: 0.5)
    }
    
    // MARK: - API
    
    /// Set target emotion. Smoothly transitions from current state.
    public func setEmotion(_ preset: EmotionPreset) {
        targetValence = preset.valence
        targetArousal = preset.arousal
    }
    
    /// Set target emotion with explicit values.
    public func setEmotion(valence: Float, arousal: Float) {
        targetValence = max(-1, min(1, valence))
        targetArousal = max(-1, min(1, arousal))
    }
    
    /// Nudge emotion (additive). Good for reactive micro-shifts.
    /// e.g., hearing something funny → nudge(valence: 0.2, arousal: 0.1)
    public func nudge(valence: Float = 0, arousal: Float = 0) {
        targetValence = max(-1, min(1, targetValence + valence))
        targetArousal = max(-1, min(1, targetArousal + arousal))
    }
    
    /// Update per frame. Returns blendshapes for the current emotional state.
    public func update(dt: Float, elapsed: Float) -> [String: Float] {
        // Smooth interpolation toward target
        let speed = transitionSpeed * dt
        valence += (targetValence - valence) * min(speed, 1)
        arousal += (targetArousal - arousal) * min(speed, 1)
        
        // Add micro-fluctuation (emotions aren't perfectly stable)
        let vNoise = valenceNoise.sample(t: elapsed) * fluctuation
        let aNoise = arousalNoise.sample(t: elapsed) * fluctuation
        let effectiveV = max(-1, min(1, valence + vNoise))
        let effectiveA = max(-1, min(1, arousal + aNoise))
        
        // Map valence-arousal to blendshapes
        return mapToBlendshapes(valence: effectiveV, arousal: effectiveA)
    }
    
    // MARK: - Valence-Arousal → Blendshapes
    
    private func mapToBlendshapes(valence v: Float, arousal a: Float) -> [String: Float] {
        var bs: [String: Float] = [:]
        
        // --- Mouth region ---
        
        // Smile: positive valence + any arousal
        let smile = max(0, v) * 0.25
        if smile > 0.01 {
            bs["mouthSmileLeft"] = smile
            bs["mouthSmileRight"] = smile
            // Duchenne smile: cheek squint accompanies genuine smile
            bs["cheekSquintLeft"] = smile * 0.6
            bs["cheekSquintRight"] = smile * 0.6
        }
        
        // Frown: negative valence
        let frown = max(0, -v) * 0.2
        if frown > 0.01 {
            bs["mouthFrownLeft"] = frown
            bs["mouthFrownRight"] = frown
        }
        
        // Mouth tension: high arousal (positive or negative)
        let tension = max(0, abs(a) - 0.3) * 0.15
        if tension > 0.01 {
            bs["mouthPressLeft"] = tension
            bs["mouthPressRight"] = tension
        }
        
        // --- Eye region ---
        
        // Wide eyes: high arousal + positive valence (surprise/excitement)
        let wideEyes = max(0, a - 0.3) * max(0, v + 0.3) * 0.3
        if wideEyes > 0.01 {
            bs["eyeWideLeft"] = wideEyes
            bs["eyeWideRight"] = wideEyes
        }
        
        // Squint: negative valence + high arousal (anger) or positive + moderate (amused)
        let squint = max(0, abs(v) * a) * 0.15
        if squint > 0.01 {
            bs["eyeSquintLeft"] = squint
            bs["eyeSquintRight"] = squint
        }
        
        // --- Brow region ---
        
        // Inner brow raise: concern (negative valence, low arousal) or surprise
        let innerBrowUp = max(0, -v * 0.5 + a * 0.3) * 0.2
        if innerBrowUp > 0.01 {
            bs["browInnerUp"] = innerBrowUp
        }
        
        // Outer brow raise: surprise/excitement
        let outerBrowUp = max(0, a - 0.4) * 0.2
        if outerBrowUp > 0.01 {
            bs["browOuterUpLeft"] = outerBrowUp
            bs["browOuterUpRight"] = outerBrowUp
        }
        
        // Brow down: anger/frustration (negative valence + high arousal)
        let browDown = max(0, -v - 0.2) * max(0, a) * 0.25
        if browDown > 0.01 {
            bs["browDownLeft"] = browDown
            bs["browDownRight"] = browDown
        }
        
        // --- Nose ---
        
        // Nose wrinkle: disgust/strong negative
        let noseWrinkle = max(0, -v - 0.5) * 0.15
        if noseWrinkle > 0.01 {
            bs["noseSneerLeft"] = noseWrinkle
            bs["noseSneerRight"] = noseWrinkle
        }
        
        // --- Jaw ---
        
        // Slight jaw drop: surprise
        let jawDrop = max(0, a - 0.6) * max(0, v + 0.5) * 0.1
        if jawDrop > 0.01 {
            bs["jawOpen"] = jawDrop
        }
        
        return bs
    }
    
    // MARK: - Smooth Noise
    
    private struct SmoothNoise {
        let frequency: Float
        let phase1 = Float.random(in: 0...(2 * .pi))
        let phase2 = Float.random(in: 0...(2 * .pi))
        let phase3 = Float.random(in: 0...(2 * .pi))
        
        func sample(t: Float) -> Float {
            let f = frequency
            return sin(t * f + phase1) * 0.5
                 + sin(t * f * 1.7 + phase2) * 0.3
                 + sin(t * f * 3.1 + phase3) * 0.2
        }
    }
}
