// AVTRenderer-Reconstructed.swift
// Full reverse engineering of AVTRenderer (iOS 26.4 AvatarKit.framework)
// AVTRenderer : NSObject (wraps VFXWorldRenderer / SCNRenderer)
// 1455 methods (!) — the rendering engine

import Foundation

// MARK: - AVTRenderer Overview
//
// AVTRenderer is the Metal rendering engine for AvatarKit.
// It wraps SceneKit's VFXWorldRenderer (private SCNRenderer subclass)
// and adds avatar-specific rendering features:
//
// - Subdivision surface rendering (Catmull-Clark)
// - Custom shader modifiers for skin/eye/hair materials
// - Multi-pass rendering (main pass + post-process)
// - Transition effects (fade, dissolve)
// - Performance HUD overlay
// - Compositor integration for multi-avatar scenes
//
// The 1455 methods include many inherited from VFXWorldRenderer/SCNRenderer.
// The avatar-specific methods are ~50.

// MARK: - Key Methods

/// -[AVTRenderer _avtSetupWithOptions:]
/// Configures the renderer with avatar-specific options.
///
/// Evidence: decompiled at line 15059-15083
/// Sets up Metal device, render pipeline, shader cache.

/// -[AVTRenderer _initWithDevice:options:isPrivateRenderer:privateRendererOwner:clearsOnDraw:]
/// Full initializer with Metal device and options.
///
/// Evidence: decompiled at line 15084-15102

/// -[AVTRenderer setAvatar:] / avatar
/// Sets/gets the avatar being rendered.
///
/// Evidence: decompiled at line 15183-15244
/// setAvatar: calls __setAvatar: which calls _setAvatar:
/// The chain handles:
/// 1. Detach old avatar from renderer
/// 2. Remove old avatar node from scene
/// 3. Add new avatar node to scene
/// 4. Configure renderer for new avatar's requirements
/// 5. Call avatarDidChange

/// -[AVTRenderer _detachAvatarFromRenderer]
/// Disconnects the current avatar from the rendering pipeline.
///
/// Evidence: decompiled at line 15195-15202
/// Removes bindings, stops animations, clears cached state.


// MARK: - Render Loop

/// -[AVTRenderer _renderer:didApplyAnimationsAtTime:]
/// Post-animation callback from VFXWorldRenderer.
///
/// Evidence: decompiled at line 15269-15279
/// Calls avatar.updateAfterAnimationsEvaluatedAtTime:renderer:
/// This is the main per-frame update hook.

/// -[AVTRenderer _renderer:updateAtTime:]
/// Per-frame update.
///
/// Evidence: decompiled at line 15329-15341
/// Updates framing, camera position, environment.

/// -[AVTRenderer _renderer:subdivDataForHash:]
/// Provides subdivision surface data.
///
/// Evidence: decompiled at line 15280-15299
/// Returns cached subdivision data for mesh smoothing.
/// Catmull-Clark subdivision is used for smooth avatar meshes.

/// -[AVTRenderer _renderer:didBuildSubdivDataForHash:dataProvider:]
/// Caches newly computed subdivision data.
///
/// Evidence: decompiled at line 15300-15328


// MARK: - Framing

/// framingMode / setFramingMode: / setFramingModeForcingPointOfViewUpdate:
/// Controls camera framing of the avatar.
///
/// Framing modes determine how much of the avatar is visible:
/// - Head only (for Memoji keyboard)
/// - Head + shoulders (for FaceTime)
/// - Full body (for stickers)
/// - Custom (for AR)


// MARK: - Presentation

/// presentationConfiguration / setPresentationConfiguration:
/// Controls visual presentation settings.

/// backgroundContentsBehindDrawable / setBackgroundContentsBehindDrawable:
/// Sets what appears behind the avatar (color, image, camera feed).


// MARK: - Visual Effects

/// -[AVTRenderer fadePuppetToWhite:]
/// Fades the avatar to white (used during transitions).

/// -[AVTRenderer isWarmingUp] / setWarmingUp:
/// During warmup, the renderer pre-compiles shaders and loads textures.
/// The avatar is not displayed until warmup completes.


// MARK: - Anti-aliasing

/// avt_antialiasingMode / setAvt_antialiasingMode:
/// Controls MSAA level for avatar rendering.
/// Higher quality for recording, lower for live preview.


// MARK: - Continuous Rendering

/// -[AVTRenderer _avtUpdateRendersContinuously]
/// Determines if the renderer should run every frame.
///
/// Evidence: decompiled at line 15426+
/// Considers:
/// - Is an avatar set?
/// - Is it transitioning?
/// - Is face tracking active?
/// - Does the technique require continuous rendering?


// MARK: - Error Handling

/// -[AVTRenderer renderer:commandBufferDidCompleteWithError:]
/// Handles Metal command buffer errors.
///
/// Evidence: decompiled at line 15380-15425
/// Logs errors and may trigger recovery (re-create pipeline state).

/// -[AVTRenderer renderer:didFallbackToDefaultTextureForSource:message:]
/// Called when a texture fails to load and a default is used.
///
/// Evidence: decompiled at line 15347-15379

/// -[AVTRenderer crashAppExtensionOrViewService_rdar98130076:]
/// Crash handler for a specific radar bug.
/// Intentionally crashes the app extension to prevent data corruption.


// MARK: - AVTRendererViewTransitionTechnique

/// A render technique that handles visual transitions between states.
/// Implements AVTRendererTechnique protocol.
///
/// 84 methods, handles:
/// - Fade in/out
/// - Cross-dissolve between poses
/// - Blur during transitions
/// - Custom post-processing effects
///
/// Uses an extra render target for the transition effect,
/// compositing the old and new states with a blend factor.


// MARK: - AVTCompositor

/// AVTCompositor manages multi-avatar rendering.
/// 103 methods.
///
/// Used when multiple avatars need to be rendered together
/// (e.g., group FaceTime with multiple Memoji).
///
/// Key classes:
/// - AVTCompositor: orchestrates multi-avatar rendering
/// - AVTCompositorTextureProvider: provides textures for compositing
/// - AVTCompositorPipeline: the Metal compute/render pipeline
/// - AVTCompositorPipelineCache: caches compiled pipelines


// MARK: - AVTRecordView

/// AVTRecordView : AVTView
/// Specialized view for recording Animoji/Memoji videos.
///
/// 18 methods:
/// - startRecording / stopRecording / cancelRecording
/// - startPreviewing / playPreviewOnce / stopPreviewing
/// - isRecording / isPreviewing
/// - exportMovieToURL:options:completionHandler:
/// - mute / setMute:
/// - maxRecordingDuration / setMaxRecordingDuration:
/// - recordDelegate / setRecordDelegate:
///
/// Records the avatar animation + audio to a movie file.
/// Used by the Messages app Animoji recording feature.
