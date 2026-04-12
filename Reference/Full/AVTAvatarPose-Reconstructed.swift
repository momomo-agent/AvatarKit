// AVTAvatarPose-Reconstructed.swift
// Full reverse engineering of AVTAvatarPose (iOS 26.4 AvatarKit.framework)
// AVTAvatarPose : NSObject
// instanceSize = 64 bytes, 6 ivars, 31 methods

import Foundation
import simd

// MARK: - AVTAvatarPose Ivar Layout (64 bytes)
// Evidence: fwrev survey

struct AVTAvatarPoseLayout {
    // +8   _hasNeckPosition: Bool           — whether neckPosition is set
    // +9   _hasNeckOrientation: Bool        — whether neckOrientation is set
    // +16  _bakedAnimationBlendFactor: Double — blend factor with baked animation (0.0-1.0)
    // +24  _weights: NSMutableDictionary*   — blendshape name → NSNumber(float) weight
    // +32  _neckPosition: simd_float3       — neck translation (16 bytes, aligned)
    // +48  _neckOrientation: simd_quatf     — neck rotation quaternion (16 bytes)
}


// MARK: - Factory Methods

/// +[AVTAvatarPose neutralPose]
/// Returns a pose with all weights at 0.0 and neutral neck position/orientation.
///
/// Evidence: decompiled at line 475+
/// This is the "resting face" — no expression, head centered.

/// +[AVTAvatarPose friendlyPose]
/// Returns the default "friendly" expression used when not tracking.
///
/// Evidence: decompiled at line 475+
/// This is the slight smile / pleasant expression shown in the Memoji picker.
/// The friendly pose weights are applied via _friendlyPoseMorphInfos on AVTAvatar.

/// +[AVTAvatarPose posesInPosePack:]
/// Loads poses from a pose pack (plist/dictionary).
///
/// Evidence: decompiled at line 475+
/// Pose packs contain named poses with blendshape weights and neck transforms.
/// Used for sticker generation and preset expressions.

/// +[AVTAvatarPose posesForMemojiInPosePack:]
/// Filters pose pack for Memoji-compatible poses.

/// +[AVTAvatarPose posesForAnimojiNamed:inPosePack:]
/// Filters pose pack for a specific animoji character.
/// Some poses are character-specific (e.g., tongue out works differently for different animals).


// MARK: - Weight Management

/// -[AVTAvatarPose weightForBlendShapeNamed:]
/// Returns the weight for a named blendshape, or 0.0 if not set.
///
/// Evidence: reads from _weights dictionary (offset +24)

/// -[AVTAvatarPose setWeight:forBlendShapeNamed:]
/// Sets a blendshape weight in the _weights dictionary.
///
/// Evidence: writes to _weights dictionary
/// Creates the dictionary lazily if nil.


// MARK: - Neck Transform

/// neckPosition / setNeckPosition:
/// The 3D translation of the neck joint.
/// Setting this also sets _hasNeckPosition = true.

/// neckOrientation / setNeckOrientation:
/// The quaternion rotation of the neck joint.
/// Setting this also sets _hasNeckOrientation = true.

/// -[AVTAvatarPose setNeckPositionAndOrientationFromHierarchy:]
/// Reads the current neck position and orientation from the scene graph.
///
/// Evidence: called from _avatarNodeAndHeadNodeAreNowAvailable
/// Extracts the transform from the actual VFXNode hierarchy.


// MARK: - Serialization

/// -[AVTAvatarPose dictionaryRepresentation]
/// Converts the pose to an NSDictionary for serialization.
/// Keys: "weights" (dict), "neckPosition" (array of 3 floats), 
///        "neckOrientation" (array of 4 floats), "bakedAnimationBlendFactor" (number)

/// -[AVTAvatarPose initWithDictionaryRepresentation:]
/// Reconstructs a pose from a dictionary.

/// -[AVTAvatarPose initWithScene:]
/// Creates a pose by reading current state from a scene.
/// Iterates all morph targets and records their weights.


// MARK: - Comparison

/// -[AVTAvatarPose isNeutralPose]
/// Returns true if all weights are 0.0 and neck is at neutral.

/// -[AVTAvatarPose isFriendlyPose]
/// Returns true if this matches the friendly pose weights.

/// -[AVTAvatarPose isEqualToPose:]
/// Deep comparison of weights and neck transform.

/// -[AVTAvatarPose poseByMergingPose:]
/// Creates a new pose by merging another pose's non-zero weights into this one.
/// The other pose's weights override this pose's weights where set.


// MARK: - Physics

/// -[AVTAvatarPose affectsPhysicsSimulation]
/// Returns true if this pose has weights that would affect physics.
/// Used to determine if physics needs to be reset after a pose change.


// MARK: - Baked Animation

/// bakedAnimationBlendFactor
/// Controls how much the baked (pre-recorded) animation contributes vs. live tracking.
/// 0.0 = fully live tracking, 1.0 = fully baked animation.
/// Used during pose transitions to smoothly blend between states.
