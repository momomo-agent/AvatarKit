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
        guard let view = bridge.avtView else {
            let fallback = UIView()
            fallback.backgroundColor = backgroundColor
            return fallback
        }
        
        view.backgroundColor = backgroundColor
        return view
    }
    
    public func updateUIView(_ uiView: UIView, context: Context) {
        uiView.backgroundColor = backgroundColor
        
        // Load avatar once the view is in the hierarchy (has a window).
        // Loading in makeUIView can crash VFX because the render loop
        // starts before Metal shaders finish compiling.
        if bridge.characterID != character {
            if uiView.window != nil {
                bridge.load(character)
            } else {
                // View not yet in hierarchy — defer to next run loop
                DispatchQueue.main.async { [bridge, character] in
                    bridge.load(character)
                }
            }
        }
    }
}
