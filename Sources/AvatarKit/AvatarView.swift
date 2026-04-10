import SwiftUI

/// A SwiftUI view that renders an Animoji driven by face tracking data.
///
/// Usage:
/// ```swift
/// // Real-time tracking
/// AvatarView(animoji: "skull", tracking: faceTracking)
///
/// // Preset with smooth transition
/// AvatarView(animoji: "skull", tracking: .wink, transition: .smooth())
/// ```
public struct AvatarView: UIViewRepresentable {
    
    /// Which animoji to display (e.g. "skull", "tiger", "cat").
    public var animoji: String
    
    /// Face tracking data to drive the avatar.
    public var tracking: AvatarFaceTracking
    
    /// How to transition when tracking data changes.
    /// Use `.none` for real-time tracking, `.smooth()` for preset switches.
    public var transition: AvatarTransition
    
    public init(
        animoji: String = "skull",
        tracking: AvatarFaceTracking = .init(),
        transition: AvatarTransition = .none
    ) {
        self.animoji = animoji
        self.tracking = tracking
        self.transition = transition
    }
    
    public func makeUIView(context: Context) -> UIView {
        let container = AvatarContainerView()
        container.loadAnimoji(animoji)
        return container
    }
    
    public func updateUIView(_ uiView: UIView, context: Context) {
        guard let container = uiView as? AvatarContainerView else { return }
        
        // Switch animoji if changed
        if container.currentAnimoji != animoji {
            container.loadAnimoji(animoji)
        }
        
        // Apply tracking
        if tracking.isTracking {
            if let frame = tracking.arFrame {
                // ARFrame path — always immediate, full pose (real-time)
                container.cancelTransition()
                container.bridge.applyARFrame(frame)
            } else {
                // Manual path — blendshapes only, skip head pose (keeps default forward)
                switch transition {
                case .none:
                    container.cancelTransition()
                    container.bridge.applyTracking(tracking)
                case .smooth(let duration):
                    container.animateTo(tracking, duration: duration)
                }
            }
        } else {
            // No face detected — apply as preset pose (blendshapes only)
            switch transition {
            case .none:
                container.bridge.applyTracking(tracking)
            case .smooth(let duration):
                container.animateTo(tracking, duration: duration)
            }
        }
    }
    
    /// All available animoji names.
    public static var availableAnimoji: [String] {
        AvatarBridge.availableAnimoji
    }
}
