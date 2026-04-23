import SwiftUI

// MARK: - Avatar View

/// SwiftUI view that displays an animated Animoji character.
///
/// Uses Apple's private AVTView (VFX-based renderer) for rendering.
/// On iOS 18+, AvatarKit uses VFXNode/VFXView instead of SceneKit.
///
/// Usage:
/// ```swift
/// struct ContentView: View {
///     @State private var bridge = AvatarBridge()
///
///     var body: some View {
///         AvatarView(bridge: bridge, character: "cat")
///             .onAppear {
///                 bridge.applyPreset(.smile)
///             }
///     }
/// }
/// ```
public struct AvatarView: UIViewRepresentable {
    
    let bridge: AvatarBridge
    let character: String
    var backgroundColor: UIColor
    
    public init(
        bridge: AvatarBridge,
        character: String,
        backgroundColor: UIColor = .clear
    ) {
        self.bridge = bridge
        self.character = character
        self.backgroundColor = backgroundColor
    }
    
    public func makeUIView(context: Context) -> UIView {
        bridge.load(character)
        
        guard let view = bridge.avtView else {
            // Fallback: return empty view if AVTView unavailable
            let fallback = UIView()
            fallback.backgroundColor = backgroundColor
            return fallback
        }
        
        view.backgroundColor = backgroundColor
        view.clipsToBounds = false
        return view
    }
    
    public func updateUIView(_ uiView: UIView, context: Context) {
        uiView.backgroundColor = backgroundColor
        
        // If character changed, reload
        if bridge.characterID != character {
            bridge.load(character)
        }
    }
}
