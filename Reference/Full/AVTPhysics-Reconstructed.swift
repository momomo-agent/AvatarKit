// AVTPhysics-Reconstructed.swift
// Full reverse engineering of AvatarKit physics system (iOS 26.4)
// AVTPhysicsController: 125 methods
// AVTPhysicsRig: 13 methods
// AVTPhysicalizedMorpherDynamic: 80 methods
// AVTPhysicalizedSkeletonDynamic: 77 methods

import Foundation

// MARK: - AVTPhysicsController
//
// The central physics coordinator for an avatar.
// Manages all dynamic objects (hair, clothing, accessories, face jiggle).
//
// Conforms to: (delegates to AVTAvatar via AVTPhysicsControllerDelegate)
//   - avatarNodeForPhysicsController: → returns the avatar's root node
//   - physicsController:downforceForNodeNamed: → returns gravity multiplier per node
//
// Evidence: 125 methods, decompiled at line ~physics section

/// Key methods:
///
/// updateAtTime:forceMultiplier:
/// Called every frame from AVTAvatar.updateAfterAnimationsEvaluatedAtTime:
/// Steps the physics simulation forward.
///
/// addToPhysicsWorld: / removeFromPhysicsWorld:
/// Adds/removes the physics rig from the SceneKit physics world.
/// Called from AVTAvatar.didAddToScene: / willRemoveFromWorld:
///
/// setupPhysicsIfNeeded
/// Lazy initialization of the physics rig.
/// Creates AVTPhysicsRig and configures all dynamic objects.


// MARK: - AVTPhysicsRig
//
// The physics simulation rig.
// 13 methods — lightweight wrapper around SceneKit physics.
//
// Contains:
// - Physics bodies for dynamic nodes
// - Cone-twist joints for hair/accessory chains
// - Collision shapes
// - Gravity and force configuration


// MARK: - AVTPhysicalizedMorpherDynamic
//
// Morpher-driven dynamics — makes the face "jiggle" realistically.
// 80 methods.
//
// Conforms to AVTAvatarDynamic protocol:
//   - affectsNode: → returns true if this dynamic affects the given node
//   - evaluateAtTime:physicsController: → steps the simulation
//   - resetTarget → resets to rest state
//
// How it works:
// 1. Monitors morph target weight changes (blendshape deltas)
// 2. Applies spring-damper physics to create secondary motion
// 3. Writes back modified weights to the morpher
//
// Example: When you quickly open your mouth, the cheeks jiggle slightly
// due to the spring-damper response on cheek-related morph targets.
//
// Evidence: decompiled at /tmp/avt-morpherdynamic-decompiled.m (220 lines)
// Key ivars from survey:
//   - _targetNode: VFXNode* — the node this dynamic affects
//   - _morpher: VFXMorpher* — the morpher to read/write weights
//   - _springConstant: Float — spring stiffness
//   - _dampingRatio: Float — damping factor
//   - _velocity: Float — current velocity
//   - _displacement: Float — current displacement from rest


// MARK: - AVTPhysicalizedSkeletonDynamic
//
// Skeleton-driven dynamics — makes hair, clothing, and accessories move.
// 77 methods.
//
// Conforms to AVTAvatarDynamic protocol.
//
// How it works:
// 1. Reads bone transforms from the skeleton
// 2. Applies physics simulation (spring chains, collision)
// 3. Writes back modified bone transforms
//
// Used for:
// - Hair strands (ponytails, braids, bangs)
// - Earrings and other dangling accessories
// - Clothing (collars, scarves)
// - Hats and headwear
//
// Evidence: decompiled at /tmp/avt-skeletondynamic-decompiled.m (210 lines)
// Key ivars:
//   - _jointNodes: NSArray* — the bone chain to simulate
//   - _restTransforms: NSArray* — rest pose transforms
//   - _physicsBody: VFXPhysicsBody* — SceneKit physics body
//   - _joint: VFXPhysicsConeTwistJoint* — constraint for the chain


// MARK: - Physics Pipeline (per frame)
//
// Called from AVTAvatar.updateAfterAnimationsEvaluatedAtTime:renderer:
//
// 1. physicsController.updateAtTime(time, forceMultiplier: 1.0)
//    → Steps the SceneKit physics world
//    → Applies gravity, collision, constraints
//
// 2. avatar.evaluateDynamicsAtTime(time)
//    → For each dynamic in _dynamics:
//       dynamic.evaluateAtTime(time, physicsController: controller)
//    → Morpher dynamics: read blendshape deltas, apply spring response
//    → Skeleton dynamics: read bone transforms, apply chain physics
//
// 3. Results are written back to the scene graph
//    → Morpher weights updated (face jiggle)
//    → Bone transforms updated (hair/accessory movement)


// MARK: - AVTAvatarMemoryOptimizer
//
// Manages memory for avatar rendering.
// 58 methods.
//
// Handles:
// - Texture memory management (load/unload based on visibility)
// - Mesh LOD (level of detail) switching
// - Component caching and eviction
// - Memory pressure responses
//
// Evidence: decompiled at /tmp/avt-memoptimizer-decompiled.m (1266 lines!)
// This is a substantial system — the optimizer tracks:
// - Which textures are currently needed
// - Which LOD level is appropriate for the current rendering context
// - Memory budget and current usage
// - Priority ordering for eviction


// MARK: - AVTAvatarPhysicsState
//
// Captures the current physics state for save/restore.
// 5 methods.
//
// Used by the sticker system to save physics state between
// sticker generations (so hair position is consistent).
//
// Evidence: referenced by AVTAvatar.physicsState and resetToPhysicsState:


// MARK: - AVTAvatarBodyPose
//
// Body pose data (separate from face pose).
// 15 methods.
//
// Contains:
// - Body joint rotations
// - Hand pose
// - Body position/orientation
//
// Used for full-body Memoji rendering (FaceTime, stickers).
