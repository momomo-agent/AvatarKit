import Foundation
import QuartzCore

// MARK: - Head Gesture Generator

/// Generates procedural head gestures: nod, shake, tilt, and custom curves.
///
/// Based on:
/// - Kocoń (2020): "Head Movements in the Idle Loop Animation"
///   - Nod: pitch axis, fast down + slow return, 8-12° amplitude, 0.3-0.5s
///   - Shake: yaw axis, 2-3 oscillations, 10-15° amplitude, 0.8-1.2s
///   - Tilt: roll axis, single direction, 5-10° amplitude, 0.5s
///
/// - Cassell et al. (1994): "Animated Conversation"
///   - Listener nods: every 2-4s during active listening
///   - Speaker nods: on emphasis/stress, amplitude proportional to emphasis
///   - Head tilt: signals curiosity, engagement, or confusion
///
/// Output: pitch/yaw/roll deltas in degrees, to be added to base head rotation.
public class AvatarHeadGesture {
    
    // MARK: - Gesture Types
    
    public enum GestureType {
        /// Nod (agreement/acknowledgment). Pitch axis, fast down + slow return.
        case nod
        /// Double nod (strong agreement). Two quick nods.
        case doubleNod
        /// Shake (disagreement). Yaw axis, 2-3 oscillations.
        case shake
        /// Tilt (curiosity/confusion). Roll axis, single direction.
        case tilt
        /// Tilt with slight nod (interest/engagement).
        case tiltNod
        /// Custom gesture from parameters.
        case custom(pitch: GestureCurve, yaw: GestureCurve, roll: GestureCurve)
    }
    
    /// A single-axis animation curve.
    public struct GestureCurve {
        /// Peak amplitude in degrees.
        public var amplitude: Float
        /// Number of oscillations (1 = single movement, 2+ = back and forth).
        public var oscillations: Int
        /// Total duration in seconds.
        public var duration: Float
        /// Asymmetry: 0.5 = symmetric, <0.5 = fast attack, >0.5 = fast release.
        public var asymmetry: Float
        
        public init(amplitude: Float = 0, oscillations: Int = 1, duration: Float = 0.4, asymmetry: Float = 0.4) {
            self.amplitude = amplitude
            self.oscillations = oscillations
            self.duration = duration
            self.asymmetry = asymmetry
        }
        
        /// Evaluate the curve at time t (0..1).
        func evaluate(at t: Float) -> Float {
            guard amplitude != 0, t >= 0, t <= 1 else { return 0 }
            
            // Envelope: attack-sustain-release based on asymmetry
            let envelope: Float
            if t < asymmetry {
                // Attack phase
                let at = t / asymmetry
                envelope = at * at * (3 - 2 * at) // smoothstep
            } else {
                // Release phase
                let rt = (t - asymmetry) / (1 - asymmetry)
                envelope = 1 - rt * rt // quadratic decay
            }
            
            // Oscillation
            let phase = t * Float(oscillations) * 2 * .pi
            let wave = sin(phase)
            
            return wave * envelope * amplitude
        }
    }
    
    // MARK: - State
    
    /// Active gesture queue.
    private var activeGestures: [(type: GestureType, startTime: TimeInterval, intensity: Float)] = []
    
    /// Called every frame with pitch/yaw/roll deltas in degrees.
    public var onFrame: ((_ pitch: Float, _ yaw: Float, _ roll: Float) -> Void)?
    
    private var displayLink: CADisplayLink?
    private var lastTime: TimeInterval = 0
    
    // MARK: - Lifecycle
    
    public init() {}
    
    public func start() {
        guard displayLink == nil else { return }
        lastTime = CACurrentMediaTime()
        displayLink = CADisplayLink(target: self, selector: #selector(tick))
        displayLink?.preferredFrameRateRange = CAFrameRateRange(minimum: 30, maximum: 60, preferred: 60)
        displayLink?.add(to: .main, forMode: .common)
    }
    
    public func stop() {
        displayLink?.invalidate()
        displayLink = nil
        activeGestures.removeAll()
    }
    
    public var isRunning: Bool { displayLink != nil }
    
    deinit { stop() }
    
    // MARK: - Trigger Gestures
    
    /// Play a gesture with optional intensity scaling.
    public func play(_ type: GestureType, intensity: Float = 1.0) {
        activeGestures.append((type: type, startTime: CACurrentMediaTime(), intensity: intensity))
    }
    
    /// Play a nod. Shorthand for common use.
    public func nod(intensity: Float = 1.0) {
        play(.nod, intensity: intensity)
    }
    
    /// Play a double nod (strong agreement).
    public func doubleNod(intensity: Float = 1.0) {
        play(.doubleNod, intensity: intensity)
    }
    
    /// Play a head shake.
    public func shake(intensity: Float = 1.0) {
        play(.shake, intensity: intensity)
    }
    
    /// Play a head tilt (curiosity).
    public func tilt(intensity: Float = 1.0) {
        play(.tilt, intensity: intensity)
    }
    
    // MARK: - Gesture Parameters
    
    private func curves(for type: GestureType) -> (pitch: GestureCurve, yaw: GestureCurve, roll: GestureCurve, duration: Float) {
        switch type {
        case .nod:
            // Fast down, slow return. Pitch 10°, 0.4s.
            return (
                pitch: GestureCurve(amplitude: -10, oscillations: 1, duration: 0.4, asymmetry: 0.3),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.4
            )
        case .doubleNod:
            // Two quick nods. Pitch 8°, 0.6s.
            return (
                pitch: GestureCurve(amplitude: -8, oscillations: 2, duration: 0.6, asymmetry: 0.35),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.6
            )
        case .shake:
            // 2.5 oscillations. Yaw 12°, 1.0s.
            return (
                pitch: GestureCurve(),
                yaw: GestureCurve(amplitude: 12, oscillations: 3, duration: 1.0, asymmetry: 0.5),
                roll: GestureCurve(),
                duration: 1.0
            )
        case .tilt:
            // Single direction tilt. Roll 8°, 0.5s.
            let direction: Float = Bool.random() ? 1 : -1
            return (
                pitch: GestureCurve(),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 8 * direction, oscillations: 1, duration: 0.5, asymmetry: 0.4),
                duration: 0.5
            )
        case .tiltNod:
            // Tilt + slight nod. 0.6s.
            let direction: Float = Bool.random() ? 1 : -1
            return (
                pitch: GestureCurve(amplitude: -5, oscillations: 1, duration: 0.6, asymmetry: 0.35),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 6 * direction, oscillations: 1, duration: 0.6, asymmetry: 0.4),
                duration: 0.6
            )
        case .custom(let p, let y, let r):
            let dur = max(p.duration, y.duration, r.duration)
            return (pitch: p, yaw: y, roll: r, duration: dur)
        }
    }
    
    // MARK: - Main Loop
    
    @objc private func tick() {
        let now = CACurrentMediaTime()
        
        var totalPitch: Float = 0
        var totalYaw: Float = 0
        var totalRoll: Float = 0
        
        // Evaluate and sum all active gestures
        activeGestures.removeAll { gesture in
            let (pitchCurve, yawCurve, rollCurve, duration) = curves(for: gesture.type)
            let elapsed = Float(now - gesture.startTime)
            
            if elapsed > duration { return true } // remove finished
            
            let t = elapsed / duration
            totalPitch += pitchCurve.evaluate(at: t) * gesture.intensity
            totalYaw += yawCurve.evaluate(at: t) * gesture.intensity
            totalRoll += rollCurve.evaluate(at: t) * gesture.intensity
            
            return false
        }
        
        onFrame?(totalPitch, totalYaw, totalRoll)
    }
}
