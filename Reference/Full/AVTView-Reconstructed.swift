// AVTView-Reconstructed.swift
// Full reverse engineering of AVTView (iOS 26.4 AvatarKit.framework)
// AVTView : VFXView (which is SCNView under the hood)
// 10 ivars, 69 methods

import Foundation

// MARK: - AVTView Ivar Layout
// Evidence: fwrev survey

struct AVTViewLayout {
    // +8   _environment: AVTAvatarEnvironment*     — lighting/environment config
    // +16  _presentationConfiguration: AVTPresentationConfiguration*
    // +24  _avatar: AVTAvatar*                     — the current avatar being displayed
    // +32  _avatarNode: VFXNode*                   — cached avatar node reference
    // +40  _avtRendersContinuously: Bool            — whether to render every frame
    // +48  _avtRendererTechnique: id<AVTRendererTechnique>  — custom render technique
    // +56  _avtRendererTechniquePresentationTree: id<AVTRendererTechnique>
    // +64  _backgroundContentsBehindDrawable: id    — background content (image/color)
    // +72  _transitionHelper: AVTViewTransitionHelper*  — manages view transitions
    // +80  _lock: NSRecursiveLock*                  — thread safety for avatar access
}


// MARK: - Initialization

/// -[AVTView initWithFrame:options:]
/// Primary initializer.
///
/// Evidence: decompiled at line 21823
/// Calls [super initWithFrame:options:] (VFXView/SCNView init)
/// Then calls _avtCommonInit

/// -[AVTView _avtCommonInit]
/// Common initialization shared by all init paths.
///
/// Evidence: decompiled at line 21780-21806
/// Sets up:
/// 1. Default background color
/// 2. Creates NSRecursiveLock for thread safety
/// 3. Sets rendersContinuously = false initially
/// 4. Registers for orientation change notifications


// MARK: - Avatar Management

/// -[AVTView setAvatar:]
/// Sets the avatar to display.
///
/// Evidence: decompiled at line 21958-21990
/// Algorithm:
/// 1. Lock
/// 2. If same avatar, return
/// 3. Disconnect old avatar from renderer
/// 4. Remove old avatar node from scene
/// 5. Store new avatar → _avatar
/// 6. If new avatar:
///    a. Get avatar's avatarNode
///    b. Add to scene's rootNode
///    c. Store → _avatarNode
///    d. Call avatarDidChange
/// 7. Unlock

/// -[AVTView lockAvatar] / unlockAvatar
/// Thread-safe avatar access using _lock (NSRecursiveLock).
/// Must bracket any direct avatar manipulation.


// MARK: - Rendering

/// -[AVTView updateAtTime:]
/// Called each frame by the render loop.
///
/// Evidence: decompiled at line 21889-21897
/// Forwards to the avatar's update pipeline.

/// -[AVTView _drawAtTime:]
/// Internal draw call.
///
/// Evidence: decompiled at line 21898-21911
/// Handles the actual Metal rendering pass.

/// -[AVTView rendersContinuously] / setRendersContinuously:
/// Controls whether the view renders every frame or only on demand.
/// When tracking is active, this should be true.
/// When showing a static pose, false saves battery.

/// -[AVTView _avtUpdateRendersContinuously]
/// Recalculates whether continuous rendering is needed.
/// Considers: avatar presence, transition state, technique requirements.


// MARK: - Transitions

/// -[AVTView transitionToPose:duration:completionHandler:]
/// Animates the avatar to a new pose.
///
/// Evidence: decompiled at line 22032
/// Delegates to transitionToPose:duration:style:completionHandler:

/// -[AVTView transitionToPose:duration:style:completionHandler:]
/// Full transition with style parameter.
///
/// Style controls the animation curve and visual treatment.

/// -[AVTView transitionToCustomFaceTrackingWithDuration:style:enableBakedAnimations:
///     faceTrackingDidStartHandlerReceiverBlock:completionHandler:]
/// Transitions from a static pose to live face tracking.
///
/// Evidence: decompiled at line 22044-22072
/// This is the key method called when the user starts a FaceTime call
/// or opens the Memoji keyboard. It:
/// 1. Creates a transition coordinator
/// 2. Starts the face tracking session
/// 3. Smoothly blends from the current pose to live tracking
/// 4. Calls faceTrackingDidStartHandler when tracking begins
/// 5. Calls completionHandler when transition finishes

/// -[AVTView transitionToStickerConfiguration:duration:completionHandler:]
/// Transitions to a sticker pose configuration.
/// Used when generating sticker images from the avatar.


// MARK: - Face Tracking State

/// -[AVTView faceIsFullyActive]
/// Returns true when face tracking is active and the transition is complete.
///
/// Evidence: decompiled at line 22073
/// Checks that the avatar is receiving tracking data and not mid-transition.

/// -[AVTView _didLostTrackingForAWhile]
/// Called when face tracking has been lost for a significant duration.
/// Triggers transition back to friendly pose.

/// -[AVTView allowTrackSmoothing]
/// Returns whether smoothing should be applied to tracking data.
/// Smoothing reduces jitter but adds latency.


// MARK: - Renderer Delegate Methods

/// These methods are called by the VFXWorldRenderer (SceneKit's Metal renderer):

/// -[AVTView _renderer:willRenderWorld:atTime:]
/// Pre-render callback. Sets up render state.

/// -[AVTView _renderer:didApplyAnimationsAtTime:]
/// Post-animation callback. Triggers avatar update pipeline.
/// This is where updateAfterAnimationsEvaluatedAtTime:renderer: gets called.

/// -[AVTView _renderer:updateAtTime:]
/// Per-frame update callback.

/// -[AVTView _renderer:subdivDataForHash:]
/// Subdivision surface data provider.
/// Returns cached subdivision data for mesh smoothing.

/// -[AVTView _renderer:didBuildSubdivDataForHash:dataProvider:]
/// Caches newly built subdivision data.


// MARK: - Snapshot

/// -[AVTView snapshotWithSize:scaleFactor:options:]
/// Renders the avatar to a UIImage at the specified size.
///
/// Evidence: decompiled at line 22073+
/// Uses the avatar's snapshotWithSize:scale:options: method.
/// Sets _optimizedForSnapshot on the avatar during rendering.


// MARK: - Orientation

/// -[AVTView setupOrientation]
/// Configures the view for the current device orientation.

/// -[AVTView updateInterfaceOrientation]
/// Updates rendering when orientation changes.

/// -[AVTView _UIOrientationDidChangeNotification:]
/// Notification handler for orientation changes.


// MARK: - Custom Render Techniques

/// AVTRendererTechnique protocol methods:
/// These allow custom post-processing effects on the avatar render.
///
/// _wantsCustomMainPassPostProcessForRenderer:
/// _customMainPassPostProcessUsesExtraRenderTargetForRenderer:pixelFormat:
/// _usesSpecificMainPassClearColorForRenderer:clearColor:
/// _encodeCustomMainPassPostProcessForRenderer:atTime:helper:
///
/// Used by AVTRendererViewTransitionTechnique for smooth visual transitions.


// MARK: - Presentation Configuration

/// presentationConfiguration / setPresentationConfiguration:
/// Controls how the avatar is presented (framing, background, effects).
///
/// AVTPresentationConfiguration includes:
/// - Framing mode (head only, head+shoulders, full body)
/// - Background treatment
/// - Lighting overrides
/// - AR mode settings


// MARK: - Framing

/// framingMode / setFramingMode: / setFramingMode:animationDuration:
/// Controls the camera framing of the avatar.
/// Can animate between framing modes (e.g., zoom from head to full body).
