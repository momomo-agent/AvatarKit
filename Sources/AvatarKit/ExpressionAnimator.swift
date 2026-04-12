import Foundation
import QuartzCore
import UIKit

// MARK: - Expression Animator

/// Smoothly interpolates between expression states.
///
/// Uses a display-link-style callback to lerp blendshapes from current
/// to target over a specified duration. Supports easing curves.
///
/// Usage:
/// ```swift
/// let animator = ExpressionAnimator()
/// animator.animate(to: .smile, duration: 0.3) { tracking in
///     bridge.applyTracking(tracking)
/// }
/// ```
public final class ExpressionAnimator: NSObject {
    
    /// Easing curve for transitions.
    public enum Easing: Sendable {
        case linear
        case easeIn
        case easeOut
        case easeInOut
        
        func apply(_ t: Float) -> Float {
            switch self {
            case .linear: return t
            case .easeIn: return t * t
            case .easeOut: return t * (2 - t)
            case .easeInOut:
                return t < 0.5
                    ? 2 * t * t
                    : -1 + (4 - 2 * t) * t
            }
        }
    }
    
    /// Current blendshape state (all 51 values).
    private var current: [String: Float] = [:]
    
    /// Target blendshape state.
    private var target: [String: Float] = [:]
    
    /// Start state for current animation.
    private var start: [String: Float] = [:]
    
    /// Head rotation (current).
    private var currentRotation: AvatarFaceTracking.HeadRotation = .init(pitch: 0, yaw: 0, roll: 0)
    private var targetRotation: AvatarFaceTracking.HeadRotation = .init(pitch: 0, yaw: 0, roll: 0)
    private var startRotation: AvatarFaceTracking.HeadRotation = .init(pitch: 0, yaw: 0, roll: 0)
    
    private var animationStart: CFTimeInterval = 0
    private var animationDuration: CFTimeInterval = 0
    private var easing: Easing = .easeInOut
    private var displayLink: CADisplayLink?
    private var onFrame: ((AvatarFaceTracking) -> Void)?
    private var completion: (() -> Void)?
    
    public override init() {
        // Initialize all blendshapes to 0
        for name in BlendshapeOrder.names {
            current[name] = 0
        }
    }
    
    /// Animate to a preset expression.
    public func animate(
        to preset: ExpressionPreset,
        duration: TimeInterval = 0.3,
        easing: Easing = .easeInOut,
        pitch: Float = 0,
        yaw: Float = 0,
        onFrame: @escaping (AvatarFaceTracking) -> Void,
        completion: (() -> Void)? = nil
    ) {
        animate(
            to: preset.blendshapes,
            headRotation: .init(pitch: pitch, yaw: yaw, roll: 0),
            duration: duration,
            easing: easing,
            onFrame: onFrame,
            completion: completion
        )
    }
    
    /// Animate to arbitrary blendshape values.
    public func animate(
        to blendshapes: [String: Float],
        headRotation: AvatarFaceTracking.HeadRotation? = nil,
        duration: TimeInterval = 0.3,
        easing: Easing = .easeInOut,
        onFrame: @escaping (AvatarFaceTracking) -> Void,
        completion: (() -> Void)? = nil
    ) {
        stop()
        
        self.start = current
        self.startRotation = currentRotation
        
        // Build target: merge sparse blendshapes into full state
        self.target = current
        for (name, value) in blendshapes {
            self.target[name] = value
        }
        
        if let rot = headRotation {
            self.targetRotation = rot
        }
        
        self.easing = easing
        self.onFrame = onFrame
        self.completion = completion
        self.animationStart = CACurrentMediaTime()
        self.animationDuration = duration
        
        if duration <= 0 {
            // Instant
            current = target
            currentRotation = targetRotation
            let tracking = buildTracking()
            onFrame(tracking)
            completion?()
            return
        }
        
        let link = CADisplayLink(target: self, selector: #selector(tick))
        link.add(to: .main, forMode: .common)
        displayLink = link
    }
    
    /// Stop current animation.
    public func stop() {
        displayLink?.invalidate()
        displayLink = nil
        onFrame = nil
        completion = nil
    }
    
    /// Set state immediately without animation.
    public func set(
        _ preset: ExpressionPreset,
        pitch: Float = 0,
        yaw: Float = 0
    ) -> AvatarFaceTracking {
        for (name, value) in preset.blendshapes {
            current[name] = value
        }
        currentRotation = .init(pitch: pitch, yaw: yaw, roll: 0)
        return buildTracking()
    }
    
    /// Set state immediately from blendshape dict.
    public func set(_ blendshapes: [String: Float]) -> AvatarFaceTracking {
        for (name, value) in blendshapes {
            current[name] = value
        }
        return buildTracking()
    }
    
    // MARK: - Private
    
    @objc private func tick() {
        let now = CACurrentMediaTime()
        let elapsed = now - animationStart
        let rawT = Float(min(elapsed / animationDuration, 1.0))
        let t = easing.apply(rawT)
        
        // Lerp blendshapes
        for name in BlendshapeOrder.names {
            let s = start[name] ?? 0
            let e = target[name] ?? 0
            current[name] = s + (e - s) * t
        }
        // tongueOut
        let ts = start["tongueOut"] ?? 0
        let te = target["tongueOut"] ?? 0
        current["tongueOut"] = ts + (te - ts) * t
        
        // Lerp rotation
        currentRotation = .init(
            pitch: startRotation.pitch + (targetRotation.pitch - startRotation.pitch) * t,
            yaw: startRotation.yaw + (targetRotation.yaw - startRotation.yaw) * t,
            roll: 0
        )
        
        let tracking = buildTracking()
        onFrame?(tracking)
        
        if rawT >= 1.0 {
            let cb = completion
            stop()
            cb?()
        }
    }
    
    private func buildTracking() -> AvatarFaceTracking {
        AvatarFaceTracking(
            blendshapes: current,
            headRotation: currentRotation,
            timestamp: CACurrentMediaTime()
        )
    }
}
