import Foundation
import SceneKit

// MARK: - AVTAnimoji Mirror
//
// Swift recreation of AVTAnimoji class hierarchy.
// Reverse-engineered from AvatarKit.framework (iOS 26.4) using fwrev CLI.
//
// Class hierarchy: AVTAnimoji : AVTAvatar : NSObject
//
// This file documents the internal structure for reference.
// AvatarBridge.swift handles the actual ObjC runtime interaction.

// MARK: - AVTAnimoji Ivars (offset 8-64, instanceSize 64)

/// Mirrors AVTAnimoji's 7 own ivars.
/// These are all scene graph node references loaded by `_load`.
///
/// ```
/// offset  8: _url                      NSURL?
/// offset 16: _lightingNode             VFXNode?
/// offset 24: _headNode                 VFXNode?
/// offset 32: _avatarNode               VFXNode?
/// offset 40: _cameraNode               VFXNode?
/// offset 48: _specializationSettings   NSDictionary?
/// offset 56: _name                     NSString
/// ```
struct AnimojiLayout {
    static let url = 8
    static let lightingNode = 16
    static let headNode = 24
    static let avatarNode = 32
    static let cameraNode = 40
    static let specializationSettings = 48
    static let name = 56
    static let instanceSize = 64
}

// MARK: - MorphInfo (32 bytes per entry, 51 entries)

/// Mirrors the internal MorphInfo struct used by `_applyBlendShapes:parameters:`.
///
/// Each ARKit blendshape index maps to one MorphInfo entry.
/// The morpher is a VFXNode (SCNMorpher wrapper) and targetIndex
/// identifies which morph target to set the weight on.
///
/// Reverse-engineered from loop at _applyBlendShapes:parameters:
///   - Loop count: 0x33 (51)
///   - Stride: 0x20 (32 bytes)
///   - Field access: [x8] = morpher, [x8+0x10] = targetIndex, [x8+0x18] = isEnabled
///
/// ```
/// offset  0: morpher       (VFXNode*)   — 8 bytes, the morpher node
/// offset  8: (reserved)    (ptr)        — 8 bytes, unknown (possibly morph target name)
/// offset 16: targetIndex   (Int64)      — 8 bytes, morph target index on the morpher
/// offset 24: isEnabled     (Bool)       — 1 byte, whether this mapping is active
/// offset 25: (padding)                  — 7 bytes
/// ```
struct MorphInfo {
    let morpher: AnyObject?     // VFXNode (SCNMorpher wrapper)
    let reserved: AnyObject?    // Unknown pointer
    let targetIndex: Int64      // Morph target index
    let isEnabled: Bool         // Whether this blendshape mapping is active
    
    static let size = 32
    static let count = 51       // 0x33 — matches ARKit blendshape count
}

// MARK: - AVTFaceTrackingInfo (wrapper for 480-byte tracking data)
//
// Class: AVTFaceTrackingInfo : NSObject
// Category: AVTFaceTrackingInfo(Nigiri) — provides factory method
//
// Single ivar at offset 16:
//   _trackingData: 480 bytes, inline struct (not a pointer)
//
// Construction:
//   +[AVTFaceTrackingInfo(Nigiri) trackingInfoWithTrackingData:]
//     alloc_init → memcpy(obj+0x10, data, 0x1e0) → autorelease
//
// Access:
//   -[AVTFaceTrackingInfo trackingData]
//     return self + 0x10  (direct pointer to inline struct)
//
// Field names from ObjC type encoding (evidence: otool -oV ivar metadata):
//   {?=
//     "timestamp"d                        — Double, offset 0
//     "translation"                       — simd type (opaque in encoding), offset 16
//     "orientation"                       — simd type (opaque in encoding), offset 32
//     "cameraSpace"B                      — Bool (NOT "trackingFlag"), offset 48
//     "blendShapeWeights_smooth"[51f]     — Float[51], offset 52
//     "blendShapeWeights_raw"[51f]        — Float[51], offset 256 (52+204)
//     "parameters_smooth"[1f]             — Float[1], offset 460
//     "parameters_raw"[1f]                — Float[1], offset 464
//   }
//
// Key insight: the field we called "trackingFlag" is actually "cameraSpace" (Bool).
//   0 = non-camera-space (skip arOffset subtraction)
//   1 = camera-space (subtract arOffset from translation)

// MARK: - AVTAvatar Key Ivars (offset 8-240)

/// Mirrors AVTAvatar's inherited ivars relevant to face tracking.
///
/// ```
/// offset  64: _morphInfoFromARKitBlendShapeIndex  — MorphInfo[51] pointer
/// offset  72: _friendlyPoseMorphInfos             — MorphInfo[] pointer (idle pose)
/// offset  80: _friendlyPoseMorphInfoCount          — UInt64
/// offset 160: _arOffset                            — simd_float3 (16 bytes aligned)
/// offset 176: _arScale                             — Float
/// offset 192: _lastRenderTime                      — Double
/// ```
struct AvatarLayout {
    static let morphInfoArray = 64
    static let friendlyPoseMorphInfos = 72
    static let friendlyPoseMorphInfoCount = 80
    static let arOffset = 160
    static let arScale = 176
    static let lastRenderTime = 192
    static let instanceSize = 240
}

// MARK: - Blendshape Application Pipeline
//
// This is the exact call chain Apple uses to apply face tracking data:
//
// updatePoseWithFaceTrackingData:applySmoothing:
//   │
//   ├── if applySmoothing:
//   │   ├── CATransaction.begin()
//   │   ├── CATransaction.setAnimationDuration(duration)  // from constants
//   │   └── CATransaction.setAnimationTimingFunction(.easeOut)
//   │
//   ├── _applyBlendShapesWithTrackingData:
//   │   │  // Extracts pointers from tracking data:
//   │   │  //   blendshapes = trackingData + 0x34 (offset 52)
//   │   │  //   parameters  = trackingData + 0x1cc (offset 460)
//   │   │
//   │   └── _applyBlendShapes:parameters:
//   │       │
//   │       ├── 1. Handle tongueOut parameter (MorphInfo at offset 0x660 from ivar base)
//   │       │   ├── Read tongueParam = parameters_smooth[0]
//   │       │   ├── if tongueParam == -1.0: skip
//   │       │   ├── clamp(tongueParam, 0, 1)
//   │       │   ├── currentWeight = morpher.weightForTargetAtIndex(targetIdx)
//   │       │   ├── delta = clampedTongue - currentWeight
//   │       │   └── newWeight = currentWeight + delta * 0.3  // lerp with 0.3 factor!
//   │       │       Evidence: ldr s2, [x8, #0xe00] → const(float=0.3) at __TEXT,__const
//   │       │       This is smooth interpolation, NOT direct assignment.
//   │       │
//   │       └── 2. Loop i = 0..<51:
//   │           ├── weight = smoothBlendshapes[i]
//   │           ├── if weight == -1.0: skip (inactive)
//   │           ├── clamp(weight, 0, 1)
//   │           ├── name = AVTBlendShapeLocationFromARIndex(i)
//   │           ├── weight = AVTMorphWeightApplyCorrectionForTongue(name, weight, tongueParam)
//   │           ├── weight = AVTMorphWeightApplyBlinkCorrection(name, weight)
//   │           └── morphInfo[i].morpher.setWeight(weight, forTargetAtIndex: morphInfo[i].targetIndex)
//   │
//   │       └── 3. Reset friendlyPose morphs (idle state)
//   │           ├── Read _friendlyPoseMorphInfos (self+0x48) and count (self+0x50)
//   │           ├── Loop over friendlyPoseMorphInfos:
//   │           │   └── morpher.setWeight(0, forTargetAtIndex: targetIdx)
//   │           └── If count == 0: clear flag at self+0x58
//   │
//   │
//   ├── _applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:
//   │   │  // Reads from tracking data:
//   │   │  //   translation = [ptr+0x10] (simd_float4)
//   │   │  //   orientation = [ptr+0x20] (simd_quatf)
//   │   │  //   trackingFlag = [ptr+0x30] (UInt8)
//   │   │
//   │   ├── if cameraSpace == 1 (camera-space mode):
//   │   │   └── position = translation - convertPosition(arOffset, neckNode→rootJointNode)
//   │   ├── else (non-camera-space):
//   │   │   └── position = translation
//   │   │
//   │   ├── headNode.position = position
//   │   └── headNode.orientation = orientation
//   │
//   └── if applySmoothing:
//       └── CATransaction.commit()

// MARK: - Animoji Load Pipeline
//
// _load method reconstructs the scene graph:
//
// 1. _sceneURL → resolve scene file URL
//    - If _url is set: use directly
//    - Else: _scenePathForPuppetNamed:(_name) → NSURL
//
// 2. VFXWorld.avt_rootNodeForWorldAtURL:options:error:
//    → Load VFX scene from .scn file
//
// 3. Extract named nodes from scene:
//    - "lightingNode" → _lightingNode (removed from parent)
//    - "headNode"     → _headNode
//    - "cameraNode"   → _cameraNode
//    - "skeleton"     → skeleton (for bone animation)
//
// 4. AVTPrecompiledAnimojiSpecializationSettings[_name]
//    → _specializationSettings (per-character rendering config)
//
// 5. avt_enableSubdivisionOnHierarchyWithQuality:1 animoji:YES
//    → Enable mesh subdivision for smooth rendering
//
// 6. _avatarNodeAndHeadNodeAreNowAvailable
//    → Triggers morph target binding setup
//
// 7. resetCustomBehaviours → updateBindings
//    → Connects blendshape indices to morph targets

// MARK: - Available Animoji (28 characters)

/// All built-in Animoji names, from +[AVTAnimoji animojiNames].
/// "default" is the robot face used as fallback.
/// Canonical definition — referenced by Reconstructed/AVTAnimojiScene.swift.
let availableAnimoji: [String] = AvatarBridge.availableAnimoji
