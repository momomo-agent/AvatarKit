import SwiftUI

/// A SwiftUI view that renders an Animoji driven by face tracking data.
///
/// Usage:
/// ```swift
/// AvatarView(animoji: "skull", tracking: faceTracking)
/// ```
public struct AvatarView: UIViewRepresentable {
    
    /// Which animoji to display (e.g. "skull", "tiger", "cat").
    /// See `AvatarView.availableAnimoji` for the full list.
    public var animoji: String
    
    /// Face tracking data to drive the avatar.
    public var tracking: AvatarFaceTracking
    
    public init(animoji: String = "skull", tracking: AvatarFaceTracking = .init()) {
        self.animoji = animoji
        self.tracking = tracking
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
            container.bridge.applyTracking(tracking)
        }
    }
    
    /// All available animoji names.
    public static var availableAnimoji: [String] {
        AvatarBridge.availableAnimoji
    }
}
