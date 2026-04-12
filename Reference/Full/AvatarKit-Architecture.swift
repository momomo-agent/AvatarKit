// AvatarKit-Architecture.swift
// High-level architecture overview of AvatarKit.framework (iOS 26.4)
// 176 classes, 10659 methods

import Foundation

// MARK: - Architecture Overview
//
// AvatarKit is Apple's private framework for rendering Animoji and Memoji.
// It sits between ARKit (face tracking) and SceneKit/Metal (rendering).
//
//  ┌─────────────┐
//  │   ARKit      │  Face tracking data (480 bytes per frame)
//  └──────┬───────┘
//         │ AVTFaceTrackingData
//         ▼
//  ┌─────────────────────────────────────────────────┐
//  │                  AvatarKit                       │
//  │                                                  │
//  │  ┌──────────┐  ┌──────────┐  ┌──────────────┐  │
//  │  │ AVTAnimoji│  │ AVTMemoji│  │ AVTAvatarPose│  │
//  │  └────┬─────┘  └────┬─────┘  └──────────────┘  │
//  │       │              │                           │
//  │       └──────┬───────┘                           │
//  │              ▼                                   │
//  │       ┌──────────┐                               │
//  │       │ AVTAvatar │ ← Base class                 │
//  │       │           │   - MorphInfo[52] binding     │
//  │       │           │   - Physics integration       │
//  │       │           │   - Eye tracking              │
//  │       │           │   - Pose transitions          │
//  │       └────┬─────┘                               │
//  │            │                                     │
//  │            ▼                                     │
//  │  ┌─────────────────┐  ┌──────────────────────┐  │
//  │  │   AVTRenderer    │  │  AVTPhysicsController │  │
//  │  │ (Metal pipeline) │  │  (Spring-damper sim)  │  │
//  │  └────────┬────────┘  └──────────────────────┘  │
//  │           │                                      │
//  │           ▼                                      │
//  │  ┌─────────────────┐                             │
//  │  │    AVTView       │ ← UIView subclass          │
//  │  │  (SCNView-based) │                             │
//  │  └─────────────────┘                             │
//  │                                                  │
//  └──────────────────────────────────────────────────┘
//         │
//         ▼
//  ┌─────────────┐
//  │ SceneKit/    │  VFXWorld, VFXNode, VFXMorpher
//  │ Metal        │  (Private SceneKit layer)
//  └─────────────┘


// MARK: - Class Hierarchy

// Avatar Types:
//   NSObject
//   └── AVTAvatar (base, 240 bytes, 121 methods)
//       ├── AVTAnimoji (pre-built characters, 39 methods)
//       └── AVTMemoji (user-customizable, 183 methods)

// Rendering:
//   VFXView (private SCNView)
//   └── AVTView (69 methods)
//       └── AVTRecordView (18 methods)
//
//   NSObject
//   └── AVTRenderer (wraps VFXWorldRenderer, 1455 methods)
//   └── AVTCompositor (multi-avatar, 103 methods)

// Physics:
//   NSObject
//   └── AVTPhysicsController (125 methods)
//   └── AVTPhysicsRig (13 methods)
//   └── AVTPhysicalizedMorpherDynamic (80 methods, face jiggle)
//   └── AVTPhysicalizedSkeletonDynamic (77 methods, hair/clothing)

// Stickers:
//   NSObject
//   └── AVTStickerGenerator (76 methods)
//   └── AVTStickerConfiguration (112 methods)
//   └── AVTStickerProp (96 methods)

// Components (Memoji assembly):
//   NSObject
//   └── AVTComponent (60 methods)
//   └── AVTComponentInstance (29 methods)
//   └── AVTPreset (100 methods)
//   └── AVTPresetStore (37 methods)

// Pose:
//   NSObject
//   └── AVTAvatarPose (31 methods)
//   └── AVTAvatarPoseAnimation (104 methods)
//   └── AVTAvatarPoseAnimationController (65 methods)


// MARK: - Per-Frame Pipeline
//
// 1. ARKit delivers AVTFaceTrackingData (480 bytes) at 60fps
//
// 2. AVTView receives tracking data:
//    view.avatar.updatePoseWithFaceTrackingData(data, applySmoothing: true)
//
// 3. AVTAvatar processes tracking data:
//    a. CATransaction.begin() (if smoothing)
//    b. _applyBlendShapesWithTrackingData(bytes)
//       → Extracts blendshapes[51] from offset +0x34
//       → For each blendshape:
//         - Look up MorphInfo[i] for the morpher and target index
//         - Apply corrections (blink, tongue)
//         - Set weight on morpher
//    c. _applyHeadPoseWithTrackingData(bytes, gazeCorrection, pointOfView)
//       → Extract rotation quaternion and translation
//       → Apply gaze correction if enabled
//       → Set neckNode position and orientation
//    d. CATransaction.commit() (if smoothing)
//
// 4. SceneKit evaluates animations (including the bindings we set up)
//
// 5. AVTRenderer._renderer:didApplyAnimationsAtTime: fires
//    → avatar.updateAfterAnimationsEvaluatedAtTime(time, renderer)
//      a. Physics controller update
//      b. Evaluate dynamics (face jiggle, hair physics)
//      c. Update eye orientation and reflections
//      d. Update morpher-driven materials
//      e. Fire didUpdateAtTime callbacks
//
// 6. SceneKit renders the frame via Metal


// MARK: - Key Design Patterns
//
// 1. LAZY LOADING: Animoji scenes are loaded on first access (loadIfNeeded)
//    Memoji components are loaded during init but textures may be lazy.
//
// 2. MORPH TARGET BINDING: SceneKit's bindAnimatablePath creates live
//    connections between morph targets on different nodes. This means
//    setting a weight on the head morpher automatically updates bound
//    morphers on other nodes (body, accessories).
//
// 3. SPECIALIZATION SETTINGS: A dictionary of per-avatar settings that
//    control rendering behavior. Checked at multiple points to customize
//    behavior per character/component.
//
// 4. PHYSICS AS DYNAMICS: Physics objects conform to AVTAvatarDynamic
//    protocol and are evaluated after animation. This creates secondary
//    motion (jiggle, sway) on top of the primary animation.
//
// 5. VFX LAYER: AvatarKit uses VFX* classes (VFXWorld, VFXNode, VFXMorpher)
//    which are private SceneKit classes. VFXWorld ≈ SCNScene, VFXNode ≈ SCNNode.
//    The VFX layer adds features not in public SceneKit:
//    - Better morpher support (named targets, weight bindings)
//    - Subdivision surfaces
//    - Custom render techniques
//    - Animation players with more control


// MARK: - File Summary
//
// Reconstructed files in this directory:
//
// AVTAvatar-Reconstructed.swift      — Base avatar class (morph binding, tracking, physics)
// AVTAnimoji-Reconstructed.swift     — Pre-built character avatars
// AVTAvatarPose-Reconstructed.swift  — Pose data (weights, neck transform)
// AVTView-Reconstructed.swift        — UIView for displaying avatars
// AVTMemoji-Reconstructed.swift      — User-customizable avatars
// AVTRenderer-Reconstructed.swift    — Metal rendering engine
// AVTPhysics-Reconstructed.swift     — Physics simulation system
// AVTSticker-Reconstructed.swift     — Sticker generation system
// AVTFaceTrackingData-Reconstructed.swift — Face tracking data struct
// AvatarKit-Architecture.swift       — This file (architecture overview)
//
// Raw data files:
// AvatarKit-decompiled.m             — 27424 lines of decompiled ObjC pseudocode
// AvatarKit.h                        — 982 lines of class headers
// AvatarKit-protocols.txt            — All protocols
// AvatarKit-map.txt                  — Class/method coverage map
