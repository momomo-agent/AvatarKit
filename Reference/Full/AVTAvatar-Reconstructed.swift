// AVTAvatar-Reconstructed.swift
// Full reverse engineering of AVTAvatar (iOS 26.4 AvatarKit.framework)
// Source: fwrev decompile + disasm with annotations
// Binary: iOS 26.4 Simulator shared cache
//
// AVTAvatar is the base class for all avatar types (AVTAnimoji, AVTMemoji).
// It manages the scene graph, morph targets, physics, eye tracking, and pose transitions.

import Foundation
import simd
import QuartzCore // CAAnimation, CATransaction

// MARK: - MorphInfo Struct (32 bytes)
// Evidence: ivar type encoding ^{?=@@qB} at offset +64
// Confirmed by setupMorphInfo disassembly: stride 0x20 (32 bytes), loop count 0x34 (52)
// Fields confirmed by updateBindingsOfNode: block_invoke (morpher.weights[NNN] binding)

/// Each MorphInfo maps an ARKit blendshape index to a VFXMorpher target.
/// Array of 52 entries (51 ARKit blendshapes + 1 tongueOut at index 0).
struct AVTMorphInfo {
    var morpher: AnyObject?       // +0x00: VFXMorpher* — the morpher owning this target
    var node: AnyObject?          // +0x08: VFXNode* — the node containing the morpher
    var targetIndex: Int          // +0x10: weight index in the morpher (-1 = NSNotFound = unmapped)
    var isEnabled: Bool           // +0x18: whether this blendshape is active (not in disabled set)
    // padding to 0x20 (32 bytes)
    
    // Evidence for targetIndex at +0x10:
    //   setupMorphInfo: (self._newWeights + 0x0)[+0x10] = result  (from _weightIndexForTargetNamed:)
    //   _applyBlendShapes: (self._newWeights + 0x0)[+0x10] == 0x7fffffffffffffff  (NSNotFound check)
    //
    // Evidence for isEnabled at +0x18 (stored as +0x1c in some paths due to alignment):
    //   setupMorphInfo: (self._newWeights + 0x0)[+0x1c] = (w0 ^ 0x1)  (inverted containsObject: result)
    //   This means: isEnabled = !disabledBlendshapes.contains(blendshapeName)
}

// MARK: - FriendlyPoseMorphInfo (5 bytes, packed)
// Evidence: ivar type encoding {?="morphWeight"f"isEnabled"B} at offset +88

struct AVTFriendlyPoseMorphInfo {
    var morphWeight: Float        // +0x00: the weight to apply for "friendly pose"
    var isEnabled: Bool           // +0x04: whether this morph is active
}

// MARK: - AVTAvatar Class Layout (instanceSize = 240 bytes)
// Evidence: fwrev header SIZE: 240, hierarchy AVTAvatar → NSObject

/// Reconstructed AVTAvatar ivar layout.
/// All offsets are from instance base (after isa pointer at +0).
struct AVTAvatarLayout {
    // --- Scene Graph Nodes ---
    // +8   _avatarNode: VFXNode*           — root node of the avatar in the scene
    // +16  _skeleton: VFXNode*             — skeleton root for bone animations
    // +24  _headNode: VFXNode*             — head node (morph targets live here)
    // +32  _leftEye: VFXNode*              — left eye node (for gaze/reflection)
    // +40  _rightEye: VFXNode*             — right eye node
    // +48  _neckNode: VFXNode*             — neck joint node (for head pose)
    // +56  _rootJointNode: VFXNode*        — root of skeleton hierarchy
    
    // --- Morph Target System ---
    // +64  _morphInfoFromARKitBlendShapeIndex: MorphInfo*
    //      Heap-allocated array of 52 MorphInfo structs (52 × 32 = 1664 bytes = 0x680)
    //      Evidence: malloc_type_realloc with size 0x680 in setupMorphInfo
    //      Index 0 = tongueOut (special handling), indices 1-51 = standard ARKit blendshapes
    //
    // +72  _friendlyPoseMorphInfos: MorphInfo*
    //      Additional morph infos for "friendly pose" correctives
    //
    // +80  _friendlyPoseMorphInfoCount: UInt64
    //      Count of friendly pose morph infos
    //
    // +88  _friendlyPoseMorphInfoProxy: FriendlyPoseMorphInfo
    //      Inline struct {morphWeight: Float, isEnabled: Bool}
    
    // --- Presentation ---
    // +96  _presentationConfiguration: AVTPresentationConfiguration*
    // +104 _portalPresentationConfigurationNode: VFXNode*
    // +112 _transitionCount: Int32          — active transition counter
    // +116 _optimizedForSnapshot: Bool
    
    // --- Physics ---
    // +120 _physicsController: AVTPhysicsController*
    // +128 _dynamics: NSMutableArray*       — array of AVTAvatarDynamic objects
    // +136 _morpherDrivenMaterialDescriptors: NSMutableArray*
    
    // --- Eye Tracking ---
    // +144 _pupilReflectionCorrectionDescriptor: AVTPupilReflectionCorrectionDescriptor*
    // +152 _eyeSkinningDescriptor: AVTEyeSkinningDescriptor*
    
    // --- AR Mode ---
    // +160 _arOffset: simd_float3 (16 bytes, aligned)
    //      Evidence: METHOD arOffset 16@0:8 (returns 16 bytes)
    // +176 _arScale: Float
    // +184 _physicsScaleFactor: Double
    
    // --- Timing ---
    // +192 _lastRenderTime: Double
    
    // --- Baked Animation ---
    // +200 _bakedAnimation: CAAnimation*
    // +208 _bakedAnimationPlayer_lazy: VFXAnimationPlayer*
    
    // --- Callbacks ---
    // +216 _didUpdateAtTimeLock: os_unfair_lock
    // +224 _didUpdateAtTimeCallbackItems: NSMutableArray*
    
    // --- Specialization ---
    // +232 _specializationSettings: NSDictionary*
    //      Keys include:
    //        AVTAvatarSpecializationARKitDisabledBlendshapes — NSArray of disabled blendshape names
    //        AVTAvatarEyeBehaviorSpecializationWantsPupilReflectionCorrection — NSNumber(bool)
}


// MARK: - Initialization Pipeline

/// _avatarNodeAndHeadNodeAreNowAvailable
/// Called after scene loading completes (from AVTAnimoji._load and AVTMemoji.initWithDescriptor:)
///
/// Evidence: disasm at 0x30600-0x306d4
///
/// Pipeline:
/// 1. Store headNode → _headNode (offset +24)
/// 2. Store avatarNode → _avatarNode (offset +8)
/// 3. Guard: both must be non-nil
/// 4. Find skeleton node: avatarNode.childNode(named: "skeleton", recursively: false)
///    → store to _skeleton (offset +16)
/// 5. Find left eye: avatarNode.childNode(named: "leftEye", recursively: false)
///    → store to _leftEye (offset +32)
/// 6. Find neck: avatarNode.childNode(named: "neck", recursively: false)
///    → store to _neckNode (offset +48)
/// 7. Find root joint: avatarNode.childNode(named: "rootJoint", recursively: false)
///    → store to _rootJointNode (offset +56)
/// 8. Set neck position and orientation from hierarchy
/// 9. Read arScale, arOffset
/// 10. Get baked animation: avatarNode.animationPlayer(forKey:)?.animation.caAnimation
///     → store to _bakedAnimation (offset +200)
/// 11. Call setupMorphInfo()
/// 12. Call setupEyeOrientationAndReflections()
///
/// Node name constants (from string pool):
///   "skeleton"   at cfstring offset +0x260
///   "leftEye"    at cfstring offset +0x280
///   "neck"       at cfstring offset +0x9e0
///   "rootJoint"  at cfstring offset +0x2a0


// MARK: - Morph Target Binding

/// setupMorphInfo
/// Populates _morphInfoFromARKitBlendShapeIndex array (52 entries × 32 bytes = 0x680 bytes)
///
/// Evidence: disasm at 0x3323c-0x333cc
///
/// Algorithm:
/// 1. Guard: _headNode must be non-nil
/// 2. Allocate/realloc 0x680 bytes for morph info array → _morphInfoFromARKitBlendShapeIndex
/// 3. Get disabled blendshapes: specializationSettings[AVTAvatarSpecializationARKitDisabledBlendshapes]
/// 4. Loop i = 0 to 0x33 (51), stride 0x20 (32 bytes per entry):
///    a. name = AVTBlendShapeLocationFromARIndex(i)
///    b. node = effectiveMorphedNodeForTargetName(name)
///    c. morpher = node.morpher
///    d. targetIndex = morpher._weightIndexForTargetNamed(name)
///    e. If node is nil OR targetIndex == NSNotFound (0x7fffffffffffffff):
///       → store {morpher: nil, node: nil, targetIndex: NSNotFound, isEnabled: false}
///    f. Else:
///       → isEnabled = !disabledBlendshapes.contains(name)
///       → store {morpher, node, targetIndex, isEnabled}
/// 5. Call setupMorphInfoForChangeInSubHierarchy() — handles friendly pose morphs
///
/// Key constant: 0x34 = 52 iterations (0 through 51)
/// Key constant: 0x680 = 52 × 32 = 1664 bytes allocation
/// Key constant: 0x7fffffffffffffff = NSNotFound (unmapped target)


/// effectiveMorphedNodeForTargetName:
/// Finds the VFXNode that owns the morph target for a given blendshape name.
///
/// Evidence: disasm at 0x33068-0x33168
///
/// Algorithm:
/// 1. Get specializationSettings[AVTAvatarSpecializationMorphVariantComponents]
/// 2. Enumerate keys/objects looking for a variant that maps this target name
/// 3. If found: return avatarNode.childNode(named: variantNodeName, recursively: true)
/// 4. If not found: return headNode (default — most morphs live on the head)
///
/// This is how Memoji handles variant meshes (e.g., different hairstyles have
/// different morph targets on different nodes).


/// updateBindingsOfNode:
/// Creates SceneKit bindings between morph targets across nodes.
///
/// Evidence: disasm at 0x30ff4-0x31358, block_invoke at 0x310cc
///
/// Algorithm:
/// 1. Guard: _headNode and _morphInfoFromARKitBlendShapeIndex must be non-nil
/// 2. Enumerate hierarchy of the given node:
///    For each child node with a morpher:
///    a. Remove all existing bindings
///    b. For each morph target in the morpher:
///       - Get target name
///       - Check AVTMorphTargetNameIsUsedForBindings(name)
///       - Find the effective node: effectiveMorphedNodeForTargetName(name)
///       - If found and different from current node:
///         Build binding path: "morpher.weights[NNN]" (NNN = zero-padded index)
///         Bind: node.bindAnimatablePath(sourcePath, toObject: targetNode, withKeyPath: targetPath)
///
/// The binding string format "morpher.weights[000]" is confirmed by the literal at 0x6cb8d.
/// This creates live SceneKit bindings so when one morpher weight changes,
/// the bound morpher on another node follows automatically.


// MARK: - Per-Frame Update Pipeline

/// updatePoseWithFaceTrackingData:applySmoothing:
/// Main entry point for applying face tracking data each frame.
///
/// Evidence: disasm at 0x33868-0x33914
///
/// Algorithm:
/// 1. Guard: _headNode must be non-nil
/// 2. If applySmoothing:
///    a. CATransaction.begin()
///    b. CATransaction.setAnimationDuration(smoothingDuration)
///    c. CATransaction.setAnimationTimingFunction(CAMediaTimingFunction(name: "easeOut"))
/// 3. Validate tracking data: data.length must == 0x1E0 (480 bytes)
///    If not, log warning and skip
/// 4. Get raw bytes pointer from NSData
/// 5. Call _applyBlendShapesWithTrackingData(bytes)
/// 6. Call _applyHeadPoseWithTrackingData(bytes, gazeCorrection: applySmoothing, pointOfView: nil)
/// 7. If applySmoothing: CATransaction.commit()
///
/// Key constant: 0x1E0 = 480 bytes = sizeof(AVTFaceTrackingData)


/// _applyBlendShapesWithTrackingData:
/// Thin wrapper that extracts blendshape arrays from the tracking data struct.
///
/// Evidence: disasm at 0x33b14-0x33b28
///
/// Algorithm:
/// 1. Guard: trackingData pointer is non-nil
/// 2. Call _applyBlendShapes(trackingData + 0x34, parameters: trackingData + 0x1CC)
///
/// Offsets into AVTFaceTrackingData (480 bytes):
///   +0x00: timestamp (Double, 8 bytes)
///   +0x08: isTracking (Bool, 1 byte)
///   +0x0C: headRotation (simd_quatf, 16 bytes) — or at +0x10 with alignment
///   +0x34: blendshapes[51] (Float array, 51 × 4 = 204 bytes)
///   +0x100: (more data)
///   +0x1CC: parameters[51] (Float array, 51 × 4 = 204 bytes) — correction parameters
///
/// Wait — let me re-examine. The struct is 480 bytes total.
/// +0x34 = offset 52, which is blendshapes start
/// +0x1CC = offset 460, which is parameters start
/// 460 - 52 = 408 bytes between them. 408 / 4 = 102 floats.
/// But we have 51 blendshapes. So there's 51 floats (204 bytes) of blendshapes,
/// then other data, then 51 floats of parameters at the end.
///
/// Actually from the method signature:
///   _applyBlendShapes:parameters: takes r^f (const float*) twice
///   _applyBlendShapesWithTrackingData: takes r^{?=dB[51f][51f][1f][1f]}
///
/// The type encoding r^{?=dB[51f][51f][1f][1f]} tells us:
///   d     = Double (8 bytes) — timestamp
///   B     = Bool (1 byte) — isTracking
///   [51f] = Float[51] (204 bytes) — blendshapes
///   [51f] = Float[51] (204 bytes) — parameters (correction weights)
///   [1f]  = Float[1] (4 bytes) — extra field 1
///   [1f]  = Float[1] (4 bytes) — extra field 2
///
/// Total: 8 + 1 + padding(3) + 204 + 204 + 4 + 4 = ~428 bytes
/// But the struct is 480 bytes. The type encoding may be incomplete.
/// The +0x34 offset for blendshapes: 8(d) + 1(B) + 3(pad) + 16(quatf) + 12(float3) + 12(pad) = 52 = 0x34
/// So there's a simd_quatf (head rotation) and simd_float3 (translation) between Bool and blendshapes.


/// _applyBlendShapes:parameters:
/// The core blendshape application loop.
///
/// Evidence: disasm at 0x33918-0x33b10
///
/// Algorithm:
/// 1. Guard: _headNode must be non-nil
///
/// 2. TONGUE SPECIAL CASE (index 0, tongueOut):
///    - Check morphInfo[0].targetIndex != NSNotFound AND blendshapes[0] != -1.0
///    - If tongueOut blendshape name matches expected:
///      Read current weight: morpher.weightForTargetAtIndex(targetIndex)
///      Lerp: newWeight = currentWeight + 0.3 * (targetValue - currentWeight)
///      (Evidence: the 0.3 lerp factor from prior disassembly of this method)
///    - Set weight: morpher.setWeight(newWeight, forTargetAtIndex: targetIndex)
///
/// 3. MAIN LOOP (indices 1 to 0x33 = 51):
///    For each blendshape index i:
///    a. Skip if morphInfo[i].targetIndex == NSNotFound
///    b. Skip if blendshapes[i] == -1.0 (sentinel for "no data")
///    c. Get blendshape name: AVTBlendShapeLocationFromARIndex(i)
///    d. Apply tongue correction: AVTMorphWeightApplyCorrectionForTongue(value, tongueWeight, name)
///    e. Apply blink correction: AVTMorphWeightApplyBlinkCorrection(value, name)
///    f. Set weight on morpher: morpher.setWeight(correctedValue, forTargetAtIndex: targetIndex)
///
/// 4. FRIENDLY POSE RESET:
///    If _friendlyPoseMorphInfoCount > 0:
///    For each friendly pose morph:
///      Set weight to 0.0 (reset friendly pose when tracking is active)
///
/// Key constants:
///   0x33 = 51 (loop bound, indices 1..51)
///   0x34 = 52 (total entries including tongueOut at 0)
///   -1.0 = sentinel for "no tracking data for this blendshape"
///   0x7fffffffffffffff = NSNotFound (unmapped morph target)
///
/// Correction functions (from prior reverse engineering):
///   AVTMorphWeightApplyBlinkCorrection: pow(clamp(value * 1.1, 0, 1), 2.0/3.0)
///     Applied to: eyeBlinkLeft, eyeBlinkRight
///   AVTMorphWeightApplyCorrectionForTongue: value * (1.0 - tongueWeight * factor)
///     Applied to 7 mouth blendshapes when tongue is out


/// _applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:
/// Applies head rotation and translation from tracking data.
///
/// Evidence: disasm at 0x33b2c-0x33ee8
///
/// Algorithm:
/// 1. Guard: trackingData pointer is non-nil
/// 2. Read cameraSpace flag from tracking data
///
/// 3. IF cameraSpace == true:
///    a. If pointOfView is provided:
///       - Get pointOfView.worldTransform (4x4 matrix)
///       - Extract rotation quaternion from the matrix
///       - Compose with head rotation from tracking data
///    b. Extract translation from tracking data
///    c. Apply to neckNode: set position and orientation
///
/// 4. IF cameraSpace == false:
///    a. Call setupPhysicsIfNeeded on physics controller
///    b. If gazeCorrection enabled:
///       - Call +[AVTAvatar applyGazeCorrectionWithInputAngle:translation:]
///       - This adjusts eye gaze to look at camera
///    c. Read head rotation quaternion from tracking data
///    d. Apply to neckNode orientation
///    e. Read translation, apply to neckNode position
///
/// 5. Apply AR offset and scale if in AR mode:
///    - position += _arOffset
///    - position *= _arScale
///
/// The gaze correction uses atan/sincos to compute eye angle adjustments.
/// Evidence: +[AVTAvatar applyGazeCorrectionWithInputAngle:translation:] calls
/// _AVTGetNeutralZ, _atanf, ___sincosf_stret


// MARK: - Pose Transition System

/// transitionFromPose:toPose:duration:delay:completionHandler:
/// Animates between two poses using CATransaction.
///
/// Evidence: decompiled at line 2295+
///
/// Delegates to _transitionFromPose:toPose:bakedAnimationBlendFactor:duration:delay:
///   timingFunction:timingAnimation:completionHandler:
///
/// The full transition pipeline:
/// 1. Increment _transitionCount
/// 2. Create CATransaction with duration and delay
/// 3. For each blendshape in fromPose: read current weight
/// 4. For each blendshape in toPose: set target weight
/// 5. Animate neckPosition and neckOrientation
/// 6. If bakedAnimationBlendFactor specified: blend with baked animation
/// 7. On completion: decrement _transitionCount, call completionHandler
///
/// isTransitioning returns (_transitionCount > 0)


// MARK: - Physics Integration

/// evaluateDynamicsAtTime:
/// Steps the physics simulation for all dynamic objects.
///
/// Evidence: called from updateAfterAnimationsEvaluatedAtTime:renderer:
///
/// Algorithm:
/// 1. For each dynamic in _dynamics array:
///    a. Call dynamic.evaluateAtTime(time, physicsController: _physicsController)
/// 2. This drives hair, clothing, and accessory physics
///
/// Dynamic types:
///   AVTPhysicalizedMorpherDynamic — morpher-driven dynamics (face jiggle)
///   AVTPhysicalizedSkeletonDynamic — skeleton-driven dynamics (hair, clothing)


// MARK: - Eye Orientation & Reflections

/// setupEyeOrientationAndReflections
/// Configures eye tracking and pupil reflection correction.
///
/// Evidence: disasm at 0x327a0-0x32960
///
/// Algorithm:
/// 1. Check specializationSettings[AVTAvatarEyeBehaviorSpecializationWantsPupilReflectionCorrection]
/// 2. If true AND _leftEye AND _rightEye exist:
///    a. Create AVTPupilReflectionCorrectionDescriptor
///    b. Set readMorpher from headNode.morpher
///    c. Get left eye model material, set as leftEyeMaterial
///    d. Get right eye model material, set as rightEyeMaterial
///    e. Find morph target indices for eye-related blendshapes
///    f. Store descriptor at _pupilReflectionCorrectionDescriptor (offset +144)
/// 3. If usesSkinningForEyeOrientation:
///    a. Create AVTEyeSkinningDescriptor
///    b. Configure with eye joint nodes
///    c. Store at _eyeSkinningDescriptor (offset +152)


// MARK: - AR Mode

/// arMode / setArMode:
/// Controls whether the avatar is rendered in AR (camera passthrough) mode.
///
/// When AR mode is enabled:
/// - Shader modifiers are updated for on-top rendering
/// - arOffset and arScale are applied to position the avatar in camera space
/// - The avatar renders with transparency for compositing over camera feed


// MARK: - Render Loop Integration

/// updateAfterAnimationsEvaluatedAtTime:renderer:
/// Called by the renderer after SceneKit animations are evaluated.
///
/// Evidence: disasm at 0x32a60-0x32c50
///
/// Pipeline (per frame):
/// 1. Store time → _lastRenderTime (offset +192)
/// 2. Update physics controller: physicsController.updateAtTime(time, forceMultiplier:)
/// 3. Evaluate dynamics: evaluateDynamicsAtTime(time)
/// 4. Update eye orientation and reflections
/// 5. Update morpher-driven materials (deltaTime = time - lastRenderTime)
/// 6. Fire didUpdateAtTime callbacks (locked with _didUpdateAtTimeLock):
///    For each callback item in _didUpdateAtTimeCallbackItems:
///    - Set time on the item
///    - If item signals completion: remove from array


// MARK: - Serialization

/// AVTAvatar conforms to NSSecureCoding.
/// encodeWithCoder: / initWithCoder: handle serialization.
/// dataRepresentation returns NSData for the avatar.
/// avatarWithDataRepresentation:error: reconstructs from NSData.


// MARK: - Snapshot

/// snapshotWithSize:scale:options:
/// Renders the avatar to an image.
/// Uses _optimizedForSnapshot flag to skip physics/dynamics during snapshot rendering.


// MARK: - Constants

/// Specialization setting keys (from __TEXT,__const string pool):
let AVTAvatarSpecializationARKitDisabledBlendshapes = "AVTAvatarSpecializationARKitDisabledBlendshapes"
let AVTAvatarEyeBehaviorSpecializationWantsPupilReflectionCorrection = "AVTAvatarEyeBehaviorSpecializationWantsPupilReflectionCorrection"
// let AVTAvatarSpecializationMorphVariantComponents = "AVTAvatarSpecializationMorphVariantComponents"

/// Node name constants used in _avatarNodeAndHeadNodeAreNowAvailable:
/// These are looked up via childNodeWithName:recursively:
let kSkeletonNodeName = "skeleton"
let kLeftEyeNodeName = "leftEye"
let kRightEyeNodeName = "rightEye"  // inferred from _leftEye/_rightEye symmetry
let kNeckNodeName = "neck"
let kRootJointNodeName = "rootJoint"

/// Morph target binding format string:
let kMorpherWeightsBindingFormat = "morpher.weights[%03d]"

/// Tracking data size:
let kAVTFaceTrackingDataSize = 0x1E0  // 480 bytes

/// Blendshape count:
let kARKitBlendShapeCount = 52  // 0x34 (including tongueOut at index 0)
let kMorphInfoArraySize = 0x680 // 52 × 32 bytes

/// TongueOut lerp factor:
let kTongueOutLerpFactor: Float = 0.3

/// NSNotFound equivalent for morph target index:
let kMorphTargetNotFound: Int = 0x7FFFFFFFFFFFFFFF
