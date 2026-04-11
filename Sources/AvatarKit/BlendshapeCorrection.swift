import Foundation

// MARK: - Blendshape Corrections

/// Per-blendshape corrections applied by Apple's `_applyBlendShapes:parameters:`
/// after reading weights and before setting morph targets.
///
/// Reverse-engineered from AvatarKit.framework (iOS 26.4):
///   - `_AVTMorphWeightApplyBlinkCorrection` (nm: 0x32ea4)
///   - `_AVTMorphWeightApplyCorrectionForTongue` (nm: 0x32f10)
enum BlendshapeCorrection {
    
    // MARK: - Blink
    
    /// Non-linear blink correction: `pow(clamp(max(0, weight) * 1.1, 0, 1), 2/3)`
    ///
    /// Applied to eyeBlinkLeft and eyeBlinkRight.
    /// The gamma curve (exponent 2/3) compresses the upper range
    /// so partial blinks are more visible — makes animation feel natural.
    ///
    /// Constants from `__TEXT,__const` at 0x65d90:
    ///   scale = 1.1 (Double), exponent = 0.6666... (Double, i.e. 2/3)
    static func applyBlink(_ weight: Float, name: String) -> Float {
        guard name == "eyeBlinkLeft" || name == "eyeBlinkRight" else { return weight }
        let w = Double(max(0, weight))
        let scaled = min(w * 1.1, 1.0)
        return Float(min(pow(scaled, 2.0 / 3.0), 1.0))
    }
    
    // MARK: - Tongue
    
    /// Tongue-out correction: attenuates 7 mouth blendshapes when tongue is extended.
    ///
    /// Formula: `correctedWeight = weight * (1.0 - tongueParam)`
    ///
    /// Affected blendshapes: mouthClose, mouthFunnel, mouthPucker,
    /// mouthPressLeft, mouthPressRight, mouthRollLower, mouthShrugLower.
    ///
    /// Prevents mouth geometry from clipping through the tongue mesh.
    static func applyTongue(_ weight: Float, name: String, tongueParam: Float) -> Float {
        guard tongueParam != -1.0 else { return weight }
        guard tongueAffected.contains(name) else { return weight }
        let t = max(0, min(tongueParam, 1))
        return weight * (1.0 - t)
    }
    
    /// Apply all corrections in order (tongue first, then blink).
    /// Matches Apple's application order in `_applyBlendShapes:parameters:`.
    static func applyAll(_ weight: Float, name: String, tongueParam: Float) -> Float {
        let afterTongue = applyTongue(weight, name: name, tongueParam: tongueParam)
        return applyBlink(afterTongue, name: name)
    }
    
    // MARK: - Private
    
    private static let tongueAffected: Set<String> = [
        "mouthClose", "mouthFunnel", "mouthPucker",
        "mouthPressLeft", "mouthPressRight",
        "mouthRollLower", "mouthShrugLower",
    ]
}
