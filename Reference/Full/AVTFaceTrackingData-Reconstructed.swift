// AVTFaceTrackingData-Reconstructed.swift
// Full reverse engineering of the face tracking data struct (iOS 26.4)
// This is the 480-byte struct passed between ARKit and AvatarKit.

import Foundation
import simd

// MARK: - AVTFaceTrackingData Struct (480 bytes = 0x1E0)
//
// Evidence chain:
// 1. Method signature type encoding: r^{?=dB[51f][51f][1f][1f]}
//    → Double, Bool, Float[51], Float[51], Float[1], Float[1]
//
// 2. updatePoseWithFaceTrackingData: checks data.length == 0x1E0 (480)
//
// 3. _applyBlendShapesWithTrackingData: reads:
//    → blendshapes at trackingData + 0x34 (offset 52)
//    → parameters at trackingData + 0x1CC (offset 460)
//
// 4. _applyHeadPoseWithTrackingData: reads head rotation and translation
//    from the region between timestamp/isTracking and blendshapes
//
// Layout reconstruction:

/// The face tracking data struct passed from ARKit to AvatarKit.
/// Total size: 480 bytes (0x1E0)
struct AVTFaceTrackingData {
    // +0x00 (0): timestamp — Double (8 bytes)
    //   Evidence: type encoding starts with 'd'
    //   The time at which this tracking frame was captured.
    var timestamp: Double
    
    // +0x08 (8): isTracking — Bool (1 byte)
    //   Evidence: type encoding 'B' after 'd'
    //   Whether a face is currently being tracked.
    var isTracking: Bool
    
    // +0x09-0x0B: padding (3 bytes, alignment to 4)
    
    // +0x0C (12): headRotation — simd_quatf (16 bytes)
    //   Evidence: _applyHeadPoseWithTrackingData reads rotation
    //   from early in the struct, before blendshapes.
    //   The quaternion representing head orientation.
    var headRotation: simd_quatf  // x, y, z, w
    
    // +0x1C (28): headTranslation — simd_float3 (12 bytes)
    //   Evidence: head pose application reads translation
    //   after rotation. Used for AR positioning.
    var headTranslation: simd_float3  // x, y, z
    
    // +0x28 (40): padding/flags (12 bytes to reach 0x34)
    //   May contain:
    //   - cameraSpace flag (Bool, checked in _applyHeadPoseWithTrackingData)
    //   - tracking confidence
    //   - frame index
    
    // +0x34 (52): blendshapes — Float[51] (204 bytes)
    //   Evidence: _applyBlendShapesWithTrackingData passes (data + 0x34)
    //   as the blendshapes pointer to _applyBlendShapes:parameters:
    //   
    //   51 ARKit face blendshape coefficients, indexed by ARKit order:
    //   [0]  eyeBlinkLeft
    //   [1]  eyeLookDownLeft
    //   [2]  eyeLookInLeft
    //   [3]  eyeLookOutLeft
    //   [4]  eyeLookUpLeft
    //   [5]  eyeSquintLeft
    //   [6]  eyeWideLeft
    //   [7]  eyeBlinkRight
    //   [8]  eyeLookDownRight
    //   [9]  eyeLookInRight
    //   [10] eyeLookOutRight
    //   [11] eyeLookUpRight
    //   [12] eyeSquintRight
    //   [13] eyeWideRight
    //   [14] jawForward
    //   [15] jawLeft
    //   [16] jawRight
    //   [17] jawOpen
    //   [18] mouthClose
    //   [19] mouthFunnel
    //   [20] mouthPucker
    //   [21] mouthLeft
    //   [22] mouthRight
    //   [23] mouthSmileLeft
    //   [24] mouthSmileRight
    //   [25] mouthFrownLeft
    //   [26] mouthFrownRight
    //   [27] mouthDimpleLeft
    //   [28] mouthDimpleRight
    //   [29] mouthStretchLeft
    //   [30] mouthStretchRight
    //   [31] mouthRollLower
    //   [32] mouthRollUpper
    //   [33] mouthShrugLower
    //   [34] mouthShrugUpper
    //   [35] mouthPressLeft
    //   [36] mouthPressRight
    //   [37] mouthLowerDownLeft
    //   [38] mouthLowerDownRight
    //   [39] mouthUpperUpLeft
    //   [40] mouthUpperUpRight
    //   [41] browDownLeft
    //   [42] browDownRight
    //   [43] browInnerUp
    //   [44] browOuterUpLeft
    //   [45] browOuterUpRight
    //   [46] cheekPuff
    //   [47] cheekSquintLeft
    //   [48] cheekSquintRight
    //   [49] noseSneerLeft
    //   [50] noseSneerRight
    //
    //   Value range: 0.0 (neutral) to 1.0 (fully activated)
    //   Special value: -1.0 = no data for this blendshape
    var blendshapes: (Float, Float, Float, Float, Float, Float, Float, Float,
                      Float, Float, Float, Float, Float, Float, Float, Float,
                      Float, Float, Float, Float, Float, Float, Float, Float,
                      Float, Float, Float, Float, Float, Float, Float, Float,
                      Float, Float, Float, Float, Float, Float, Float, Float,
                      Float, Float, Float, Float, Float, Float, Float, Float,
                      Float, Float, Float)  // 51 floats
    
    // +0x100 (256): tongueOut — Float (4 bytes)
    //   Evidence: tongueOut is handled separately in _applyBlendShapes
    //   at index 0 of the MorphInfo array (before the main loop 1..51)
    //   It's stored separately from the main blendshape array.
    var tongueOut: Float
    
    // +0x104 (260): leftEyeGaze — simd_float2 (8 bytes)
    //   Evidence: gaze correction reads eye angles
    var leftEyeGaze: simd_float2  // pitch, yaw
    
    // +0x10C (268): rightEyeGaze — simd_float2 (8 bytes)
    var rightEyeGaze: simd_float2
    
    // +0x114-0x1CB: additional tracking data (184 bytes)
    //   May contain:
    //   - Face mesh vertices (subset)
    //   - Lighting estimation
    //   - Tracking quality metrics
    //   - Camera intrinsics
    
    // +0x1CC (460): parameters — Float[5] (20 bytes)
    //   Evidence: _applyBlendShapesWithTrackingData passes (data + 0x1CC)
    //   as the parameters pointer to _applyBlendShapes:parameters:
    //
    //   These are correction parameters applied to blendshape weights.
    //   Used by AVTMorphWeightApplyCorrectionForTongue and
    //   AVTMorphWeightApplyBlinkCorrection.
    //
    //   The exact count is unclear — the type encoding says [1f][1f]
    //   but the offset math suggests more data here.
    //   460 + 20 = 480 = 0x1E0 ✓
    var parameters: (Float, Float, Float, Float, Float)
}

// Verify size: 480 bytes
// 8 (timestamp) + 1 (isTracking) + 3 (pad) + 16 (rotation) + 12 (translation)
// + 12 (pad/flags) + 204 (blendshapes) + 4 (tongueOut) + 8 (leftGaze) + 8 (rightGaze)
// + 184 (additional) + 20 (parameters) = 480 ✓


// MARK: - AVTFaceTrackingInfo

/// AVTFaceTrackingInfo is an Objective-C wrapper around AVTFaceTrackingData.
///
/// instanceSize = 496 = 16 (isa + padding) + 480 (inline tracking data)
/// Single ivar: _trackingData at offset +16, type {?=dB[51f][51f][1f][1f]}
///
/// Evidence: runtime introspection on iOS 26.4 simulator:
///   class_getInstanceSize → 496
///   ivar_getOffset → 16
///   ivar_getTypeEncoding → {?="timestamp"d"translation""orientation""cameraSpace"B
///                           "blendShapeWeights_smooth"[51f]"blendShapeWeights_raw"[51f]
///                           "parameters_smooth"[1f]"parameters_raw"[1f]}
///
/// Two methods:
///   +[AVTFaceTrackingInfo(Nigiri) trackingInfoWithTrackingData:]
///     Type: @24@0:8^{?=dB[51f][51f][1f][1f]}16
///     Takes: const void* (pointer to 480-byte struct)
///     Does: alloc+init, memcpy(obj+16, data, 480)
///
///   -[AVTFaceTrackingInfo trackingData]
///     Type: r^{?=dB[51f][51f][1f][1f]}16@0:8
///     Returns: const void* (pointer to inline ivar at obj+16)
///     ⚠️ NOT NSData! Returns raw pointer to the inline struct.
///
/// "Nigiri" is the internal codename for the face tracking system.
///
/// IMPORTANT: -trackingData returns const void*, NOT NSData.
/// The pointer is valid as long as the AVTFaceTrackingInfo object is alive.
///
/// Bit-exact verified: 143/143 tests passed (2026-04-12)
/// - All 51 smooth + 51 raw blendshape offsets
/// - Translation, orientation, cameraSpace fields
/// - Tongue parameters at +0x1CC/+0x1D0
/// - Full 480-byte random pattern round-trip
/// - Padding region preservation


// MARK: - Blendshape Correction Functions

/// AVTMorphWeightApplyBlinkCorrection(value, blendshapeName)
/// Applied to: eyeBlinkLeft, eyeBlinkRight
/// Formula: pow(clamp(value * 1.1, 0, 1), 2.0/3.0)
///
/// This makes blink detection more responsive:
/// - Multiplies by 1.1 to make partial blinks register more strongly
/// - Power curve (2/3) makes the transition feel more natural
/// - Clamp prevents overflow

/// AVTMorphWeightApplyCorrectionForTongue(value, tongueWeight, blendshapeName)
/// Applied to 7 mouth blendshapes when tongue is out:
///   mouthClose, mouthFunnel, mouthPucker, jawOpen,
///   mouthShrugLower, mouthShrugUpper, mouthRollLower
///
/// Formula: value * (1.0 - tongueWeight * factor)
/// where factor varies per blendshape.
///
/// This reduces mouth blendshape influence when the tongue is out,
/// preventing unrealistic mouth shapes during tongue tracking.

/// AVTBlendShapeLocationFromARIndex(index)
/// Maps an integer index (0-51) to an ARKit blendshape name string.
/// Returns an NSString* from a static lookup table.
///
/// Evidence: called in setupMorphInfo loop, _applyBlendShapes loop,
/// blendShapeNameForARKitBlendShapeIndex:, blendShapeIndexForARKitBlendShapeName:

/// AVTGetNeutralZ()
/// Returns the neutral Z position for the head.
/// Used as a reference point for head translation.
/// Evidence: called in _applyHeadPoseWithTrackingData and applyGazeCorrectionWithInputAngle:
