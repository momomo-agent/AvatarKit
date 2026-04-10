import UIKit

/// Internal UIView that hosts the AVTRecordView and manages its lifecycle.
final class AvatarContainerView: UIView {
    let bridge = AvatarBridge()
    var currentAnimoji: String?
    private var avtViewAdded = false
    /// Animoji name queued before the view was ready.
    private var pendingAnimoji: String?
    
    /// Load an animoji, deferring if the AVTRecordView isn't in the hierarchy yet.
    func loadAnimoji(_ name: String) {
        currentAnimoji = name
        if avtViewAdded {
            bridge.loadAnimoji(name)
        } else {
            pendingAnimoji = name
        }
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        guard bounds.width > 0, bounds.height > 0 else { return }
        
        if !avtViewAdded {
            guard let avtView = bridge.createView(frame: bounds) else { return }
            avtView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
            addSubview(avtView)
            avtViewAdded = true
            
            // Load any animoji that was requested before the view was ready
            if let pending = pendingAnimoji {
                pendingAnimoji = nil
                bridge.loadAnimoji(pending)
            }
        } else if let avtView = subviews.first {
            avtView.frame = bounds
        }
    }
}
