// AVTSticker-Reconstructed.swift
// Full reverse engineering of AvatarKit sticker system (iOS 26.4)
// 15 classes, 525 methods total

import Foundation

// MARK: - Sticker System Overview
//
// The sticker system generates static images from avatar poses.
// Used by Messages app for Memoji stickers, contact photos, etc.
//
// Architecture:
//   AVTStickerGenerator → orchestrates sticker creation
//   AVTStickerConfiguration → defines what the sticker looks like
//   AVTStickerProp → 3D props added to the scene (hats, signs, etc.)
//   AVTStickerShaderModifier → custom shaders for sticker effects
//   AVTStickerCamera → camera setup for sticker rendering


// MARK: - AVTStickerGenerator (76 methods)
//
// The main entry point for generating sticker images.
//
// Key methods:
// - generateStickerWithAvatar:configuration:completionHandler:
// - generatePosterWithAvatar:configuration:options:completionHandler:
//
// Pipeline:
// 1. Set avatar pose from configuration
// 2. Add props to scene
// 3. Apply shader modifiers
// 4. Configure camera
// 5. Render to image
// 6. Post-process (crop, add effects)
// 7. Return UIImage


// MARK: - AVTStickerConfiguration (112 methods)
//
// Defines the complete sticker appearance.
//
// Properties:
// - pose: AVTAvatarPose — the facial expression
// - props: [AVTStickerProp] — 3D objects in the scene
// - shaderModifiers: [AVTStickerShaderModifier] — visual effects
// - camera: AVTStickerCamera — camera position/angle
// - backgroundColor: UIColor
// - morpherOverrides: [AVTStickerMorpherOverride] — morph target overrides
// - poseAdjustments: [AVTStickerPoseAdjustment] — fine-tuning
//
// AVTStickerConfigurationReversionContext (25 methods):
// Saves the pre-sticker state so the avatar can be restored after generation.


// MARK: - AVTStickerProp (96 methods)
//
// A 3D prop that can be added to a sticker scene.
//
// Props are loaded from .scn/.usdz files and positioned relative to the avatar.
// They can be:
// - Static (signs, backgrounds)
// - Animated (sparkles, hearts)
// - Physics-enabled (dangling objects)
//
// Subclasses:
// - AVTStickerImageProp (9 methods): 2D image as a prop
// - AVTStickerSceneProp (9 methods): 3D scene as a prop
//
// AVTStickerPropAdjustTransformProperty (19 methods):
// Allows fine-tuning prop position/rotation/scale per avatar type.


// MARK: - AVTStickerShaderModifier (55 methods)
//
// Custom shader modifications for sticker effects.
//
// AVTStickerShaderModifierProperty (22 methods):
// Individual shader property (color, intensity, etc.)
//
// Used for effects like:
// - Glow/bloom
// - Color tinting
// - Outline/stroke
// - Background blur


// MARK: - AVTStickerCamera (10 methods)
//
// Camera configuration for sticker rendering.
// Defines position, rotation, FOV, and framing.


// MARK: - AVTStickerGeneratorOptions (29 methods)
//
// Options for the generation process.
// - outputSize: CGSize
// - scaleFactor: CGFloat
// - quality: rendering quality level
//
// AVTStickerGeneratorPosterOptions (18 methods):
// Extended options for poster-style stickers (larger, higher quality).


// MARK: - AVTStickerPresetOverride (14 methods)
//
// Overrides preset values for specific sticker configurations.
// Used when a sticker needs different material settings than the default.


// MARK: - AVTStickerMorpherOverride (15 methods)
//
// Overrides morph target weights for specific stickers.
// Allows stickers to have expressions that go beyond normal tracking range
// (e.g., exaggerated surprise, extreme tongue out).


// MARK: - AVTStickerPoseAdjustment (16 methods)
//
// Fine-tunes the pose for a specific sticker.
// Adjusts individual blendshape weights or bone transforms
// to make the sticker expression look better at the specific camera angle.


// MARK: - Preset System

// AVTPreset (100 methods)
// Defines material presets for avatar components.
// Each preset specifies:
// - Material properties (color, roughness, metalness, etc.)
// - Texture maps
// - Shader parameters
//
// AVTPresetStore (37 methods)
// Manages loading and caching of presets.
// Presets are loaded from plist files in the framework bundle.
//
// AVTPresetStoreDependency (25 methods)
// Defines dependencies between presets.
// Some presets require other presets to be loaded first.
//
// AVTPresetStoreDependencyCondition (11 methods)
// Conditional dependencies (e.g., "load this preset only if skin tone is dark").
//
// AVTPresetDependency (10 methods)
// Individual dependency specification.


// MARK: - Component System

// AVTComponent (60 methods)
// A component template (e.g., "round eyes", "button nose").
// Defines the mesh, materials, morph targets, and physics for a component.
//
// AVTComponentInstance (29 methods)
// An instantiated component in the scene graph.
// Created from an AVTComponent and added to the avatar's node hierarchy.
//
// Components are the building blocks of Memoji:
// - Head shape
// - Eyes (shape, color, lashes)
// - Eyebrows (shape, color)
// - Nose
// - Mouth
// - Ears
// - Hair (style, color)
// - Facial hair (style, color)
// - Skin (tone, freckles, beauty marks)
// - Accessories (glasses, earrings, headwear)
// - Clothing (for full-body)
