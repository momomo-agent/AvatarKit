import UIKit

// MARK: - Avatar Container View

/// UIKit container that hosts an AVTView for avatar rendering.
///
/// Use this when you need UIKit integration or more control over
/// the rendering view. For SwiftUI, use `AvatarView` instead.
public final class AvatarContainerView: UIView {
    
    public let bridge: AvatarBridge
    
    public init(bridge: AvatarBridge, frame: CGRect = .zero) {
        self.bridge = bridge
        super.init(frame: frame)
    }
    
    @available(*, unavailable)
    required init?(coder: NSCoder) { fatalError() }
    
    /// Load a character and set up the rendering view.
    public func load(_ characterID: String) {
        guard bridge.load(characterID) else { return }
        
        guard let avtView = bridge.avtView else { return }
        avtView.frame = bounds
        avtView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        if avtView.superview !== self {
            avtView.removeFromSuperview()
            addSubview(avtView)
        }
    }
}
