// AVTAnimoji-Reconstructed.swift
// Full reverse engineering of AVTAnimoji (iOS 26.4 AvatarKit.framework)
// AVTAnimoji : AVTAvatar : NSObject
// instanceSize = 64 bytes (own ivars) + 240 bytes (AVTAvatar) = 304 total
// 39 methods (13 class, 26 instance)

import Foundation

// MARK: - AVTAnimoji Ivar Layout (own ivars, 64 bytes)
// Evidence: fwrev survey, offsets relative to AVTAnimoji instance base

struct AVTAnimojiLayout {
    // +8   _url: NSURL*                    — URL to the .scn scene file
    // +16  _lightingNode: VFXNode*         — lighting setup node
    // +24  _headNode: VFXNode*             — head node (overrides AVTAvatar._headNode)
    // +32  _avatarNode: VFXNode*           — avatar root (overrides AVTAvatar._avatarNode)
    // +40  _cameraNode: VFXNode*           — camera node for rendering
    // +48  _specializationSettings: NSDictionary* — per-animoji settings
    // +56  _name: NSString*                — animoji name (e.g., "cat", "robot")
}


// MARK: - Scene Loading Pipeline

/// +[AVTAnimoji animojiNames]
/// Returns the list of available animoji character names.
///
/// Evidence: decompiled at line 55-62
/// Uses dispatch_once to lazily initialize the list.
/// The names come from the AvatarKit.framework bundle resources.


/// +[AVTAnimoji _scenePathForPuppetNamed:]
/// Resolves animoji name → file path using AVTResourceLocator.
///
/// Evidence: decompiled at line 65-68
/// Calls: [AVTResourceLocator sharedResourceLocator]
///        [locator pathForAnimojiResource:name ofType:@"scn" inDirectory:name isDirectory:NO]
///
/// The .scn files live in AvatarKit.framework/Resources/<name>/<name>.scn


/// +[AVTAnimoji _sceneURLForPuppetDirectoryURL:]
/// Given a directory URL, finds the .scn file inside it.
///
/// Evidence: decompiled at line 71-96
/// Algorithm:
/// 1. List directory contents
/// 2. For each file:
///    a. Get lastPathComponent, delete extension
///    b. Compare with directory name (stem must match)
///    c. Check extension is "scn" or "usdz"
///    d. Return first match as file URL
///
/// This handles both .scn (legacy) and .usdz (modern) scene formats.


/// -[AVTAnimoji _sceneURL]
/// Returns the URL to load the scene from.
///
/// Evidence: decompiled at line 99-110
/// Algorithm:
/// 1. If _url is set (loaded from URL): return _sceneURLForPuppetDirectoryURL(_url)
/// 2. If _name is set (loaded by name): 
///    path = _scenePathForPuppetNamed(_name)
///    return [NSURL fileURLWithPath:path isDirectory:NO]


/// -[AVTAnimoji _load]
/// The main scene loading pipeline. This is where the magic happens.
///
/// Evidence: decompiled at line 113-145, disasm cross-referenced
///
/// Pipeline:
/// 1. sceneURL = [self _sceneURL]
/// 2. Guard: sceneURL must be non-nil
///
/// 3. Load scene:
///    rootNode = [VFXWorld avt_rootNodeForWorldAtURL:sceneURL options:nil error:&error]
///    If error: log and return
///
/// 4. Extract nodes from loaded scene:
///    a. Find "model" node: rootNode.childNode(named: "model", recursively: false)
///       → Remove from parent (will be re-parented)
///
/// 5. Get specialization settings:
///    settings = AVTPrecompiledAnimojiSpecializationSettings[_name]
///    → Store to _specializationSettings (offset +48)
///
/// 6. Find key nodes in the model hierarchy:
///    a. avatarNode = settings-directed node lookup
///       → Store to _avatarNode (offset +32)
///    b. Enable subdivision: avatarNode.avt_enableSubdivisionOnHierarchyWithQuality(quality, animoji: true)
///    c. headNode = avatarNode.childNode(named: "head", recursively: false)
///       → Store to _headNode (offset +24)
///    d. lightingNode = avatarNode.childNode(named: "lighting", recursively: false)
///       → Store to _lightingNode (offset +16)
///    e. cameraNode = avatarNode.childNode(named: "camera", recursively: false)
///       → Store to _cameraNode (offset +40)
///
/// 7. Initialize base class:
///    [self _avatarNodeAndHeadNodeAreNowAvailable]
///    This triggers: setupMorphInfo() + setupEyeOrientationAndReflections()
///
/// 8. Reset and bind:
///    [self resetCustomBehaviours]
///    [self updateBindings]
///
/// Node name constants (from string pool):
///   "model"    at cfstring offset +0x840
///   "head"     at cfstring offset +0x860
///   "lighting" at cfstring offset +0x880
///   "camera"   at cfstring offset +0xcc0


/// -[AVTAnimoji loadIfNeeded]
/// Lazy loading guard.
///
/// Evidence: decompiled at line 148-151
/// If _avatarNode (offset +32) is nil, calls _load.
/// Otherwise returns immediately.


/// -[AVTAnimoji avatarNode]
/// Overrides AVTAvatar.avatarNode.
///
/// Evidence: decompiled at line 154-156
/// Calls loadIfNeeded first, then returns _avatarNode.
/// This ensures the scene is loaded before anyone accesses the node.


// MARK: - Puppet API (Legacy Compatibility)

/// The "puppet" API is a legacy wrapper around the "animoji" API.
/// All puppet methods simply forward to their animoji equivalents:
///
///   puppetNames → animojiNames
///   puppetNamed:options: → animojiNamed:
///   thumbnailForPuppetNamed:options: → thumbnailForAnimojiNamed:options:
///   preloadPuppet: → preloadAvatar:
///   preloadPuppetNamed: → preloadAnimojiNamed:
///
/// Evidence: each puppet method is 1 instruction (tail call to animoji variant)


// MARK: - Initialization

/// -[AVTAnimoji initWithName:error:]
/// Creates an animoji by name.
///
/// Evidence: decompiled at line 177-217
/// Algorithm:
/// 1. Validate name is non-nil
/// 2. Check name is in animojiNames list
/// 3. If not found: set error, return nil
/// 4. Call [super init] (AVTAvatar.init → avatarCommonInit)
/// 5. Store name → _name (offset +56)
/// 6. Return self (scene is NOT loaded yet — lazy via loadIfNeeded)


/// -[AVTAnimoji initWithDescriptor:usageIntent:error:]
/// Creates from a descriptor (for serialization).
///
/// Evidence: decompiled at line 220+
/// Extracts name from descriptor, calls initWithName:error:


/// +[AVTAnimoji animojiWithContentsOfURL:]
/// Creates from a URL (for custom animoji scenes).
///
/// Evidence: decompiled at line 165-169
/// 1. alloc + init
/// 2. Set _url
/// 3. Return (scene loaded lazily)


// MARK: - Serialization (NSSecureCoding)

/// encodeWithCoder: stores _name
/// initWithCoder: reads _name, calls initWithName:error:
///
/// supportsSecureCoding returns YES


// MARK: - Specialization Settings

/// AVTPrecompiledAnimojiSpecializationSettings
/// A global dictionary mapping animoji names to their rendering settings.
///
/// Each animoji has specific settings for:
/// - Which morph targets are available
/// - Subdivision quality
/// - Physics configuration
/// - Eye behavior
///
/// This is loaded from a plist or hardcoded in the framework.
/// Evidence: referenced in _load at the settings lookup step.


// MARK: - Sticker Physics

/// stickerPhysicsStateIdentifier
/// Returns _name as the physics state identifier.
/// Used by the sticker system to save/restore physics state per animoji.


// MARK: - Best Animation Quality

/// configureForBestAnimationQuality
/// Enables highest quality rendering settings.
/// Called when the avatar is used for recording/export vs. live preview.
