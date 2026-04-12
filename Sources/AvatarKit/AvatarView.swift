import SwiftUI
import SceneKit

// MARK: - Avatar View

/// SwiftUI view that displays an animated Animoji character.
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
    var antialiasingMode: SCNAntialiasingMode
    
    public init(
        bridge: AvatarBridge,
        character: String,
        backgroundColor: UIColor = .clear,
        antialiasingMode: SCNAntialiasingMode = .multisampling4X
    ) {
        self.bridge = bridge
        self.character = character
        self.backgroundColor = backgroundColor
        self.antialiasingMode = antialiasingMode
    }
    
    public func makeUIView(context: Context) -> SCNView {
        bridge.load(character)
        
        let scnView = SCNView()
        scnView.scene = bridge.scene
        scnView.backgroundColor = backgroundColor
        scnView.antialiasingMode = antialiasingMode
        scnView.isPlaying = true
        scnView.autoenablesDefaultLighting = true
        
        return scnView
    }
    
    public func updateUIView(_ scnView: SCNView, context: Context) {
        if scnView.scene !== bridge.scene {
            scnView.scene = bridge.scene
        }
        scnView.backgroundColor = backgroundColor
    }
}
