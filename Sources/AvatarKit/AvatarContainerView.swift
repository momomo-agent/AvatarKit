import UIKit
import simd

/// Internal UIView that hosts the AVTRecordView and manages its lifecycle.
final class AvatarContainerView: UIView {
    let bridge = AvatarBridge()
    var currentAnimoji: String?
    var hasReceivedTracking = false
    private var avtViewAdded = false
    private var pendingAnimoji: String?
    
    // Animation state
    private var displayLink: CADisplayLink?
    private var animStartTime: CFTimeInterval = 0
    private var animDuration: TimeInterval = 0
    private var animFrom: AvatarFaceTracking?
    private var animTo: AvatarFaceTracking?
    private var lastAppliedTracking: AvatarFaceTracking?
    
    /// Load an animoji, deferring if the AVTRecordView isn't in the hierarchy yet.
    func loadAnimoji(_ name: String) {
        print("[AvatarKit] loadAnimoji(\(name)) avtViewAdded=\(avtViewAdded)")
        currentAnimoji = name
        if avtViewAdded {
            bridge.loadAnimoji(name)
        } else {
            pendingAnimoji = name
        }
    }
    
    /// Animate from current expression to target over duration.
    func animateTo(_ target: AvatarFaceTracking, duration: TimeInterval) {
        let from = lastAppliedTracking ?? AvatarFaceTracking(isTracking: true)
        animFrom = from
        animTo = target
        animDuration = duration
        animStartTime = CACurrentMediaTime()
        
        if displayLink == nil {
            let link = CADisplayLink(target: self, selector: #selector(animationTick))
            link.add(to: .main, forMode: .common)
            displayLink = link
        }
    }
    
    /// Cancel any in-progress transition.
    func cancelTransition() {
        displayLink?.invalidate()
        displayLink = nil
        animFrom = nil
        animTo = nil
    }
    
    @objc private func animationTick() {
        guard let from = animFrom, let to = animTo else {
            cancelTransition()
            return
        }
        
        let elapsed = CACurrentMediaTime() - animStartTime
        let progress = min(Float(elapsed / animDuration), 1.0)
        
        // Ease in-out cubic
        let t = easeInOutCubic(progress)
        
        let interpolated = interpolate(from: from, to: to, t: t)
        bridge.applyTracking(interpolated)
        lastAppliedTracking = interpolated
        
        if progress >= 1.0 {
            cancelTransition()
        }
    }
    
    private func easeInOutCubic(_ t: Float) -> Float {
        if t < 0.5 {
            return 4 * t * t * t
        } else {
            let f = (2 * t - 2)
            return 0.5 * f * f * f + 1
        }
    }
    
    private func interpolate(from: AvatarFaceTracking, to: AvatarFaceTracking, t: Float) -> AvatarFaceTracking {
        // Collect all blendshape keys
        var allKeys = Set(from.blendshapes.keys)
        allKeys.formUnion(to.blendshapes.keys)
        
        var blendshapes: [String: Float] = [:]
        for key in allKeys {
            let a = from.blendshapes[key] ?? 0
            let b = to.blendshapes[key] ?? 0
            blendshapes[key] = a + (b - a) * t
        }
        
        // Slerp for quaternion
        let rotation = simd_slerp(from.headRotation, to.headRotation, t)
        
        return AvatarFaceTracking(
            blendshapes: blendshapes,
            headRotation: rotation,
            isTracking: true
        )
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        print("[AvatarKit] layoutSubviews bounds=\(bounds) avtViewAdded=\(avtViewAdded)")
        guard bounds.width > 0, bounds.height > 0 else { return }
        
        if !avtViewAdded {
            guard let avtView = bridge.createView(frame: bounds) else {
                print("[AvatarKit] ❌ createView returned nil")
                return
            }
            avtView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
            addSubview(avtView)
            avtViewAdded = true
            print("[AvatarKit] ✅ AVTRecordView added to hierarchy")
            
            if let pending = pendingAnimoji {
                pendingAnimoji = nil
                print("[AvatarKit] Loading pending animoji: \(pending)")
                bridge.loadAnimoji(pending)
                // Apply default front-facing pose immediately so it doesn't show back-of-head
                bridge.applyTracking(.slightSmile)
            }
        } else if let avtView = subviews.first {
            avtView.frame = bounds
        }
    }
    
    deinit {
        displayLink?.invalidate()
    }
}
