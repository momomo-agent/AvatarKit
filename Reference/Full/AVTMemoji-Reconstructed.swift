// AVTMemoji-Reconstructed.swift
// Full reverse engineering of AVTMemoji (iOS 26.4 AvatarKit.framework)
// AVTMemoji : AVTAvatar : NSObject
// 183 methods — the most complex avatar type

import Foundation

// MARK: - AVTMemoji Overview
//
// AVTMemoji is the user-customizable avatar (your personal Memoji).
// Unlike AVTAnimoji (pre-built characters), Memoji is assembled from
// components: head shape, eyes, nose, mouth, hair, accessories, etc.
//
// Key differences from AVTAnimoji:
// 1. No single .scn file — assembled from component meshes
// 2. Has a descriptor (AVTMemojiDescriptor) defining all customization choices
// 3. Components are loaded and composed at runtime
// 4. Supports color presets (skin, hair, eyebrows, lips, facial hair)
// 5. Has body controller for full-body rendering
// 6. Much more complex initialization pipeline

// MARK: - Key Ivars (from decompiled code analysis)
//
// AVTMemoji adds many ivars on top of AVTAvatar's 240 bytes.
// Key ones identified from decompiled methods:
//
// - _descriptor: AVTMemojiDescriptor* — the customization descriptor
// - _usageIntent: NSUInteger — how the memoji will be used (preview, recording, sticker)
// - _assetResourceCache: id — cache for loaded component assets
// - _headComponentContainer: VFXNode* — container for head components
// - _bodyComponentContainer: VFXNode* — container for body components
// - _handsComponentContainer: VFXNode* — container for hand components
// - _skinColor: id — current skin color
// - _hairColor: id — current hair color
// - _eyebrowsColor: id — current eyebrow color
// - _facialhairColor: id — current facial hair color
// - _lipsColor: id — current lip color
// - _bodyController: AVTMemojiBodyController* — manages body pose/animation


// MARK: - Initialization Pipeline

/// -[AVTMemoji initWithDescriptor:usageIntent:error:]
/// The primary initializer. This is where the Memoji is assembled.
///
/// Evidence: decompiled at line 9794-9934 (140 lines of pseudocode!)
///
/// Pipeline:
/// 1. Call [super init] (AVTAvatar.init)
/// 2. Store descriptor and usageIntent
/// 3. Create asset resource cache
/// 4. Load head components from descriptor
/// 5. Load body components (if usage requires body)
/// 6. Load hand components (if usage requires hands)
/// 7. Assemble scene graph:
///    a. Create root avatarNode
///    b. Add head container with all head components
///    c. Add body container
///    d. Add hands container
/// 8. Apply color presets (skin, hair, etc.)
/// 9. Call _avatarNodeAndHeadNodeAreNowAvailable (inherited from AVTAvatar)
///    → This triggers setupMorphInfo + setupEyeOrientationAndReflections
/// 10. Setup physics
/// 11. Apply specialization settings
///
/// The descriptor (AVTMemojiDescriptor) contains:
/// - Head shape parameters
/// - Eye style, color, lashes
/// - Nose shape
/// - Mouth shape
/// - Hair style and color
/// - Skin tone
/// - Accessories (glasses, earrings, headwear)
/// - Facial hair style and color
/// - Age appearance


// MARK: - Component System

/// AVTMemoji uses AVTComponent and AVTComponentInstance for modular assembly.
///
/// Each component (eyes, nose, hair, etc.) is:
/// 1. Defined by an AVTComponent (the template)
/// 2. Instantiated as AVTComponentInstance (the actual mesh in the scene)
/// 3. Loaded from .scn/.usdz resources in the framework bundle
/// 4. Composed into the scene graph under the appropriate container node
///
/// Components can have:
/// - Multiple variants (different styles)
/// - Color presets (applied via material properties)
/// - Morph targets (for animation)
/// - Physics (for hair/accessories)


// MARK: - Color Presets

/// -[AVTMemoji _applyAllColorPresetsForCategory:]
/// Applies all color presets for a given category.
///
/// Evidence: decompiled at line 10111-10119
/// Categories: skin, hair, eyebrows, facial hair, lips

/// -[AVTMemoji _applyColorPresetForCategory:colorIndex:]
/// Applies a specific color preset.
///
/// Evidence: decompiled at line 10120-10178 (59 lines)
/// This modifies material properties on the component meshes.
/// Color presets are defined per-component and include:
/// - Base color
/// - Specular
/// - Roughness adjustments
/// - Subsurface scattering parameters (for skin)

/// -[AVTMemoji colorPresetForCategory:]
/// Returns the current color preset index for a category.

/// -[AVTMemoji secondaryColorPresetForCategory:]
/// Some categories have secondary colors (e.g., hair highlights).

/// -[AVTMemoji colorPresetForCategory:colorIndex:]
/// Returns the color value for a specific preset index.


// MARK: - Node Accessors

/// headComponentContainer / bodyComponentContainer / handsComponentContainer
/// Return the container nodes for each body part.
/// Components are children of these containers.

/// headNode / avatarNode
/// Override AVTAvatar accessors.
/// headNode returns the head mesh node (where morph targets live).
/// avatarNode returns the root of the entire Memoji scene graph.


// MARK: - AR Mode

/// arOffset / arScale
/// Override AVTAvatar to provide Memoji-specific AR positioning.
/// Memoji may have different scale/offset than Animoji due to
/// the assembled nature of the mesh.


// MARK: - Serialization

/// encodeWithCoder: / initWithCoder:
/// Serializes the descriptor and usage intent.
/// The Memoji is reconstructed from the descriptor on decode.

/// newDescriptor
/// Creates a new AVTMemojiDescriptor from the current state.
/// Used for copying and serialization.

/// copyWithZone: / copyWithUsageIntent:
/// Creates copies, potentially with different usage intents.
/// Different intents load different LOD levels.


// MARK: - Update

/// -[AVTMemoji updateWithOptions:]
/// Updates the Memoji after descriptor changes.
///
/// Evidence: decompiled at line 10003+
/// This is called when the user modifies their Memoji in the editor.
/// It reloads affected components and reapplies settings.

/// -[AVTMemoji resetToDefault]
/// Resets all customizations to default values.

/// -[AVTMemoji removeAllComponents]
/// Removes all component instances from the scene graph.
/// Used during reset or before rebuilding.


// MARK: - Skin AO

/// -[AVTMemoji _invalidateSkinAO]
/// Invalidates the ambient occlusion texture for skin.
/// Called when skin color or head shape changes.
/// AO is recomputed to match the new geometry.


// MARK: - Body Controller

/// AVTMemojiBodyController manages:
/// - Body pose (standing, sitting, etc.)
/// - Body animation (breathing, idle movement)
/// - Hand gestures
/// - Full-body physics (clothing, accessories)
///
/// Only active when usageIntent includes body rendering
/// (e.g., FaceTime full-body mode, sticker generation).


// MARK: - AVTMemojiDescriptor

/// AVTMemojiDescriptor (24 methods) contains all customization data.
///
/// Evidence: fwrev survey shows 24 methods including:
/// - componentForCategory:
/// - setComponent:forCategory:
/// - colorPresetForCategory:
/// - setColorPreset:forCategory:
/// - secondaryColorPresetForCategory:
/// - setSecondaryColorPreset:forCategory:
/// - isEqualToDescriptor:
/// - dictionaryRepresentation
/// - initWithDictionaryRepresentation:
///
/// The descriptor is the "blueprint" — it defines WHAT the Memoji looks like.
/// AVTMemoji is the "instance" — it's the actual rendered avatar.
/// Multiple AVTMemoji instances can share the same descriptor
/// (e.g., different usage intents for the same person's Memoji).
