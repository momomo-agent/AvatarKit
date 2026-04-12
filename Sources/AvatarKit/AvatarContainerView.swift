import UIKit
import SceneKit

// MARK: - Avatar Container View

/// UIKit container that hosts an SCNView for avatar rendering.
///
/// Use this when you need UIKit integration or more control over
/// the SceneKit view. For SwiftUI, use `AvatarView` instead.
public final class AvatarContainerView: UIView {
    
    public let bridge: AvatarBridge
    public private(set) var scnView: SCNView?
    
    public init(bridge: AvatarBridge, frame: CGRect = .zero) {
        self.bridge = bridge
        super.init(frame: frame)
    }
    
    @available(*, unavailable)
    required init?(coder: NSCoder) { fatalError() }
    
    /// Load a character and set up the SceneKit view.
    public func load(_ characterID: String) {
        guard bridge.load(characterID) else { return }
        
        let view = SCNView(frame: bounds)
        view.scene = bridge.scene
        view.backgroundColor = .clear
        view.antialiasingMode = .multisampling4X
        view.isPlaying = true
        view.autoenablesDefaultLighting = true
        view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        scnView?.removeFromSuperview()
        addSubview(view)
        scnView = view
    }
}
