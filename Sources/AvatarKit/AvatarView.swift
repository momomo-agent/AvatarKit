import SwiftUI

// MARK: - Avatar View

/// SwiftUI view that displays an animated Animoji character.
///
/// Uses Apple's private AVTView (VFX-based renderer) for rendering.
/// AVTView is created lazily when the character is loaded to avoid
/// VFX render-thread crashes on empty scene graphs.
///
/// Usage:
/// ```swift
/// struct ContentView: View {
///     let bridge = AvatarBridge()
///
///     var body: some View {
///         AvatarView(bridge: bridge, character: "cat")
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
        // Use a container view. AVTView is added as a subview after load().
        let container = AvatarContainerUIView()
        container.backgroundColor = backgroundColor
        container.bridge = bridge
        return container
    }
    
    public func updateUIView(_ uiView: UIView, context: Context) {
        uiView.backgroundColor = backgroundColor
        
        guard let container = uiView as? AvatarContainerUIView else { return }
        
        // Load character if needed
        if bridge.characterID != character {
            bridge.load(character)
        }
        
        // Embed AVTView into container if not already done
        container.embedAVTViewIfNeeded()
    }
}

// MARK: - Container UIView

/// Container that hosts the lazily-created AVTView.
class AvatarContainerUIView: UIView {
    weak var bridge: AvatarBridge?
    private var didEmbed = false
    
    func embedAVTViewIfNeeded() {
        guard !didEmbed, let avtView = bridge?.avtView else { return }
        didEmbed = true
        
        avtView.translatesAutoresizingMaskIntoConstraints = false
        avtView.backgroundColor = backgroundColor
        addSubview(avtView)
        NSLayoutConstraint.activate([
            avtView.topAnchor.constraint(equalTo: topAnchor),
            avtView.bottomAnchor.constraint(equalTo: bottomAnchor),
            avtView.leadingAnchor.constraint(equalTo: leadingAnchor),
            avtView.trailingAnchor.constraint(equalTo: trailingAnchor),
        ])
    }
    
    override func didMoveToWindow() {
        super.didMoveToWindow()
        // Try embedding when we get a window (view is in hierarchy)
        if window != nil {
            embedAVTViewIfNeeded()
        }
    }
}
