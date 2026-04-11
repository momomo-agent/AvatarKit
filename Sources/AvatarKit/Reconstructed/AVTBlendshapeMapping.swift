// AVTBlendshapeMapping.swift
// Reconstructed from AvatarKit.framework (iOS 26.4)
//
// The complete ARKit blendshape index → name mapping, plus correction functions.
//
// Evidence chain:
//   Order: _initialiseBlendshapeMappingIfNeeded_block_invoke disassembly
//   Names: _AVTBlendShapeLocation* symbol addresses (nm output)
//   Corrections: _AVTMorphWeightApplyBlinkCorrection, _AVTMorphWeightApplyCorrectionForTongue

import Foundation

// MARK: - ARKit Blendshape Index Order

/// Apple's internal ARKit blendshape index → name mapping.
///
/// This is NOT alphabetical. It's the order used by `_applyBlendShapes:parameters:`
/// to iterate MorphInfo[51].
///
/// Evidence: otool disassembly of _initialiseBlendshapeMappingIfNeeded_block_invoke,
/// cross-referenced with _AVTBlendShapeLocation* symbol addresses from nm.
enum AVTBlendshapeIndex: Int, CaseIterable {
    case eyeBlinkLeft = 0
    case eyeLookDownLeft = 1
    case eyeLookInLeft = 2
    case eyeLookOutLeft = 3
    case eyeLookUpLeft = 4
    case eyeSquintLeft = 5
    case eyeWideLeft = 6
    case eyeBlinkRight = 7
    case eyeLookDownRight = 8
    case eyeLookInRight = 9
    case eyeLookOutRight = 10
    case eyeLookUpRight = 11
    case eyeSquintRight = 12
    case eyeWideRight = 13
    case jawForward = 14
    case jawLeft = 15
    case jawRight = 16
    case jawOpen = 17
    case mouthClose = 18
    case mouthFunnel = 19
    case mouthPucker = 20
    case mouthLeft = 21
    case mouthRight = 22
    case mouthSmileLeft = 23
    case mouthSmileRight = 24
    case mouthFrownLeft = 25
    case mouthFrownRight = 26
    case mouthDimpleLeft = 27
    case mouthDimpleRight = 28
    case mouthStretchLeft = 29
    case mouthStretchRight = 30
    case mouthRollLower = 31
    case mouthRollUpper = 32
    case mouthShrugLower = 33
    case mouthShrugUpper = 34
    case mouthPressLeft = 35
    case mouthPressRight = 36
    case mouthLowerDownLeft = 37
    case mouthLowerDownRight = 38
    case mouthUpperUpLeft = 39
    case mouthUpperUpRight = 40
    case browDownLeft = 41
    case browDownRight = 42
    case browInnerUp = 43
    case browOuterUpLeft = 44
    case browOuterUpRight = 45
    case cheekPuff = 46
    case cheekSquintLeft = 47
    case cheekSquintRight = 48
    case noseSneerLeft = 49
    case noseSneerRight = 50
    
    /// The ARKit blendshape location string.
    var name: String {
        switch self {
        case .eyeBlinkLeft: return "eyeBlinkLeft"
        case .eyeLookDownLeft: return "eyeLookDownLeft"
        case .eyeLookInLeft: return "eyeLookInLeft"
        case .eyeLookOutLeft: return "eyeLookOutLeft"
        case .eyeLookUpLeft: return "eyeLookUpLeft"
        case .eyeSquintLeft: return "eyeSquintLeft"
        case .eyeWideLeft: return "eyeWideLeft"
        case .eyeBlinkRight: return "eyeBlinkRight"
        case .eyeLookDownRight: return "eyeLookDownRight"
        case .eyeLookInRight: return "eyeLookInRight"
        case .eyeLookOutRight: return "eyeLookOutRight"
        case .eyeLookUpRight: return "eyeLookUpRight"
        case .eyeSquintRight: return "eyeSquintRight"
        case .eyeWideRight: return "eyeWideRight"
        case .jawForward: return "jawForward"
        case .jawLeft: return "jawLeft"
        case .jawRight: return "jawRight"
        case .jawOpen: return "jawOpen"
        case .mouthClose: return "mouthClose"
        case .mouthFunnel: return "mouthFunnel"
        case .mouthPucker: return "mouthPucker"
        case .mouthLeft: return "mouthLeft"
        case .mouthRight: return "mouthRight"
        case .mouthSmileLeft: return "mouthSmileLeft"
        case .mouthSmileRight: return "mouthSmileRight"
        case .mouthFrownLeft: return "mouthFrownLeft"
        case .mouthFrownRight: return "mouthFrownRight"
        case .mouthDimpleLeft: return "mouthDimpleLeft"
        case .mouthDimpleRight: return "mouthDimpleRight"
        case .mouthStretchLeft: return "mouthStretchLeft"
        case .mouthStretchRight: return "mouthStretchRight"
        case .mouthRollLower: return "mouthRollLower"
        case .mouthRollUpper: return "mouthRollUpper"
        case .mouthShrugLower: return "mouthShrugLower"
        case .mouthShrugUpper: return "mouthShrugUpper"
        case .mouthPressLeft: return "mouthPressLeft"
        case .mouthPressRight: return "mouthPressRight"
        case .mouthLowerDownLeft: return "mouthLowerDownLeft"
        case .mouthLowerDownRight: return "mouthLowerDownRight"
        case .mouthUpperUpLeft: return "mouthUpperUpLeft"
        case .mouthUpperUpRight: return "mouthUpperUpRight"
        case .browDownLeft: return "browDownLeft"
        case .browDownRight: return "browDownRight"
        case .browInnerUp: return "browInnerUp"
        case .browOuterUpLeft: return "browOuterUpLeft"
        case .browOuterUpRight: return "browOuterUpRight"
        case .cheekPuff: return "cheekPuff"
        case .cheekSquintLeft: return "cheekSquintLeft"
        case .cheekSquintRight: return "cheekSquintRight"
        case .noseSneerLeft: return "noseSneerLeft"
        case .noseSneerRight: return "noseSneerRight"
        }
    }
}

// MARK: - Blendshape Corrections

/// Corrections applied by `_applyBlendShapes:parameters:` after reading weights
/// and before setting morph targets. Order: tongue first, then blink.
enum AVTBlendshapeCorrection {
    
    // MARK: Blink Correction
    
    /// Non-linear blink correction for eyeBlinkLeft and eyeBlinkRight.
    ///
    /// Formula: `pow(clamp(max(0, weight) * scale, 0, 1), exponent)`
    ///
    /// The gamma curve (exponent < 1) compresses the upper range,
    /// making partial blinks more visible and the animation more natural.
    ///
    /// Evidence:
    ///   Function: _AVTMorphWeightApplyBlinkCorrection (nm: 0x32ea4)
    ///   Scale: ldr d1, [x8, #0xd90] → __TEXT,__const @ 0x65d90 = 1.1 (Double)
    ///   Exponent: ldr d1, [x8, #0xd98] → __TEXT,__const @ 0x65d98 = 0.6666... (Double, 2/3)
    ///   Affected: isEqualToString: checks against _AVTBlendShapeLocationEyeBlinkLeft (0xa5580)
    ///            and _AVTBlendShapeLocationEyeBlinkRight (0xa5588)
    
    private static let blinkScale: Double = 1.1       // 0x65d90: 9999999a 3ff19999
    private static let blinkExponent: Double = 2.0/3.0 // 0x65d98: 55555555 3fe55555
    
    static func applyBlink(_ weight: Float, blendshape: AVTBlendshapeIndex) -> Float {
        guard blendshape == .eyeBlinkLeft || blendshape == .eyeBlinkRight else {
            return weight
        }
        let w = Double(max(0, weight))
        let scaled = min(w * blinkScale, 1.0)
        return Float(min(pow(scaled, blinkExponent), 1.0))
    }
    
    // MARK: Tongue Correction
    
    /// Attenuates 7 mouth blendshapes when tongue is extended.
    ///
    /// Formula: `weight * (1.0 - tongueParam)`
    /// When tongueParam == -1.0 (inactive), no correction is applied.
    ///
    /// This prevents mouth geometry from clipping through the tongue mesh.
    /// The 7 affected blendshapes are the ones that close/narrow the mouth opening.
    ///
    /// Evidence:
    ///   Function: _AVTMorphWeightApplyCorrectionForTongue (nm: 0x32f48)
    ///   Affected blendshapes (from isEqualToString: checks against nm symbols):
    ///     0xa5590: _AVTBlendShapeLocationMouthClose
    ///     0xa5598: _AVTBlendShapeLocationMouthFunnel
    ///     0xa55a0: _AVTBlendShapeLocationMouthPressLeft
    ///     0xa55a8: _AVTBlendShapeLocationMouthPressRight
    ///     0xa55b0: _AVTBlendShapeLocationMouthPucker
    ///     0xa55b8: _AVTBlendShapeLocationMouthRollLower
    ///     0xa55c0: _AVTBlendShapeLocationMouthShrugLower
    
    private static let tongueAffected: Set<AVTBlendshapeIndex> = [
        .mouthClose, .mouthFunnel, .mouthPucker,
        .mouthPressLeft, .mouthPressRight,
        .mouthRollLower, .mouthShrugLower
    ]
    
    static func applyTongue(_ weight: Float, blendshape: AVTBlendshapeIndex, tongueParam: Float) -> Float {
        guard tongueParam != -1.0, tongueAffected.contains(blendshape) else {
            return weight
        }
        return Float(Double(weight) * (1.0 - Double(tongueParam)))
    }
    
    // MARK: Combined
    
    /// Apply all corrections in the order used by _applyBlendShapes:parameters:.
    /// Evidence: call order at 0x33a78 (tongue) then 0x33a80 (blink)
    static func applyAll(_ weight: Float, blendshape: AVTBlendshapeIndex, tongueParam: Float) -> Float {
        var w = applyTongue(weight, blendshape: blendshape, tongueParam: tongueParam)
        w = applyBlink(w, blendshape: blendshape)
        return w
    }
}
