import SwiftUI
import ARKit

/// A SwiftUI view that renders an Animoji driven by face tracking data.
///
/// Two modes:
/// 1. **Direct ARFrame** (60fps, no SwiftUI overhead): set `arFrameSource` callback.
///    ARFrames go straight to UIKit. `tracking` is used as fallback when no face detected.
/// 2. **SwiftUI-driven**: omit `arFrameSource`, pass `tracking` for presets/blendshapes.
///
/// ```swift
/// // Real-time via direct callback (preferred for performance)
/// AvatarView(animoji: "skull", tracking: fallbackExpression)
///     .arFrameSource { callback in
///         humanSense.onARFrame = callback
///     }
///
/// // Preset only
/// AvatarView(animoji: "skull", tracking: .wink, transition: .smooth())
/// ```
public struct AvatarView: UIViewRepresentable {
    
    public var animoji: String
    public var tracking: AvatarFaceTracking
    public var transition: AvatarTransition
    
    /// Optional: register a callback that receives ARFrames directly at 60fps.
    /// The closure receives a `(ARFrame) -> Void` that the caller should wire to their ARFrame source.
    var arFrameRegistration: ((@escaping (ARFrame) -> Void) -> Void)?
    
    /// Optional: register a callback that receives AvatarFaceTracking directly at 60fps.
    /// Bypasses SwiftUI diffing for smooth audio-driven animation.
    var trackingRegistration: ((@escaping (AvatarFaceTracking) -> Void) -> Void)?
    
    /// Optional: override blendshapes (e.g. from audio lip sync).
    /// When non-nil, these blendshapes are applied instead of ARFrame/tracking.
    var blendshapeOverrideValue: [String: Float]?
    
    public init(
        animoji: String = "skull",
        tracking: AvatarFaceTracking = .init(),
        transition: AvatarTransition = .none
    ) {
        self.animoji = animoji
        self.tracking = tracking
        self.transition = transition
    }
    
    /// Register a direct ARFrame source for 60fps rendering without SwiftUI overhead.
    public func arFrameSource(_ registration: @escaping (@escaping (ARFrame) -> Void) -> Void) -> AvatarView {
        var copy = self
        copy.arFrameRegistration = registration
        return copy
    }
    
    /// Register a direct tracking source for 60fps rendering without SwiftUI overhead.
    /// Use for audio-driven animation or any non-ARKit tracking source that updates at high frequency.
    public func trackingSource(_ registration: @escaping (@escaping (AvatarFaceTracking) -> Void) -> Void) -> AvatarView {
        var copy = self
        copy.trackingRegistration = registration
        return copy
    }
    
    /// Override blendshapes from an external source (e.g. audio lip sync).
    /// When non-nil, these blendshapes take priority over ARFrame and tracking.
    public func blendshapeOverride(_ blendshapes: [String: Float]?) -> AvatarView {
        var copy = self
        copy.blendshapeOverrideValue = blendshapes
        return copy
    }
    
    public func makeUIView(context: Context) -> UIView {
        let container = AvatarContainerView()
        container.loadAnimoji(animoji)
        
        // Wire up direct ARFrame path if provided
        if let registration = arFrameRegistration {
            context.coordinator.hasARFrameSource = true
            registration { [weak container, weak coordinator = context.coordinator] frame in
                guard let container = container else { return }
                container.cancelTransition()
                container.bridge.applyARFrame(frame)
                coordinator?.lastARFrameTime = CACurrentMediaTime()
                coordinator?.lastUsedARFrame = true
            }
        }
        
        // Wire up direct tracking path if provided (for audio-driven animation)
        if let registration = trackingRegistration {
            registration { [weak container, weak coordinator = context.coordinator] tracking in
                guard let container = container else { return }
                container.cancelTransition()
                container.bridge.applyTracking(tracking)
                coordinator?.hasTrackingSource = true
                coordinator?.lastTrackingSourceTime = CACurrentMediaTime()
            }
        }
        
        return container
    }
    
    public func updateUIView(_ uiView: UIView, context: Context) {
        guard let container = uiView as? AvatarContainerView else { return }
        
        // Switch animoji if changed
        if container.currentAnimoji != animoji {
            container.loadAnimoji(animoji)
        }
        
        // If using direct tracking source, skip SwiftUI-driven updates while active
        if context.coordinator.hasTrackingSource {
            let timeSinceLastTracking = CACurrentMediaTime() - context.coordinator.lastTrackingSourceTime
            if timeSinceLastTracking < 0.2 {
                return
            }
            // Tracking source stopped → fall through to SwiftUI path
            context.coordinator.hasTrackingSource = false
        }
        
        // Blendshape override takes priority (e.g. audio lip sync)
        if let override = blendshapeOverrideValue {
            container.cancelTransition()
            var overrideTracking = AvatarFaceTracking()
            overrideTracking.blendshapes = override
            container.bridge.applyTracking(overrideTracking)
            context.coordinator.lastUsedARFrame = false
            return
        }
        
        // If using direct ARFrame source, only apply SwiftUI fallback when ARFrames
        // have stopped arriving (face lost). This prevents SwiftUI redraws from
        // fighting with the 60fps ARFrame callback.
        if context.coordinator.hasARFrameSource {
            let timeSinceLastFrame = CACurrentMediaTime() - context.coordinator.lastARFrameTime
            // ARFrames still arriving (within ~200ms) → skip SwiftUI entirely
            if timeSinceLastFrame < 0.2 {
                return
            }
            // ARFrames stopped → apply fallback preset
            if context.coordinator.lastUsedARFrame {
                container.resetPose()
                context.coordinator.lastUsedARFrame = false
            }
            switch transition {
            case .none:
                container.cancelTransition()
                container.bridge.applyTracking(tracking)
            case .smooth(let duration):
                container.animateTo(tracking, duration: duration)
            }
            return
        }
        
        // Legacy SwiftUI-only path
        let wasUsingARFrame = context.coordinator.lastUsedARFrame
        let isUsingARFrame = tracking.isTracking && tracking.arFrame != nil
        
        if wasUsingARFrame && !isUsingARFrame {
            container.resetPose()
        }
        context.coordinator.lastUsedARFrame = isUsingARFrame
        
        if tracking.isTracking {
            if let frame = tracking.arFrame {
                container.cancelTransition()
                container.bridge.applyARFrame(frame)
            } else {
                switch transition {
                case .none:
                    container.cancelTransition()
                    container.bridge.applyTracking(tracking)
                case .smooth(let duration):
                    container.animateTo(tracking, duration: duration)
                }
            }
        } else {
            switch transition {
            case .none:
                container.bridge.applyTracking(tracking)
            case .smooth(let duration):
                container.animateTo(tracking, duration: duration)
            }
        }
    }
    
    public func makeCoordinator() -> Coordinator {
        Coordinator()
    }
    
    public class Coordinator {
        var lastUsedARFrame = false
        var hasARFrameSource = false
        var lastARFrameTime: CFTimeInterval = 0
        var hasTrackingSource = false
        var lastTrackingSourceTime: CFTimeInterval = 0
    }
    
    public static var availableAnimoji: [String] {
        AvatarBridge.availableAnimoji
    }
}
