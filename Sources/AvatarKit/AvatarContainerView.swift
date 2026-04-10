import UIKit

/// Internal UIView that hosts the AVTRecordView and manages its lifecycle.
final class AvatarContainerView: UIView {
    let bridge = AvatarBridge()
    var currentAnimoji: String?
    private var avtViewAdded = false
    
    override func layoutSubviews() {
        super.layoutSubviews()
        guard bounds.width > 0, bounds.height > 0 else { return }
        
        if !avtViewAdded {
            guard let avtView = bridge.createView(frame: bounds) else { return }
            avtView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
            addSubview(avtView)
            avtViewAdded = true
        } else if let avtView = subviews.first {
            avtView.frame = bounds
        }
    }
}
