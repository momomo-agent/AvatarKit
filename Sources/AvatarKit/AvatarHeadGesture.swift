import Foundation
import QuartzCore

// MARK: - Head Gesture Generator

/// Generates procedural head gestures with Disney animation principles:
/// anticipation, overshoot, follow-through, secondary facial action, and arcs.
///
/// References:
/// - Disney's 12 Principles of Animation (Thomas & Johnston, 1981)
/// - Kocoń (2020): "Head Movements in the Idle Loop Animation"
/// - Cassell et al. (2001): BEAT system — gesture phases (prep/stroke/retract)
/// - McNeill (1992): gesture taxonomy (beats, iconics, metaphorics)
/// - PMC nod structure: 42% single-cycle, 95% are 1-5 cycles, ~0.94s per nod
/// - Eye-head coordination: eyes lead head by 25-40ms (PMC2605952)
/// - Milt Kahl head swaggle: figure-8 arc during head turns
///
/// Output: pitch/yaw/roll deltas in degrees + optional blendshape overrides.
public class AvatarHeadGesture {

    // MARK: - Gesture Types

    public enum GestureType {
        // --- Agreement ---
        /// Single nod. Pitch down + slow return. Disney: anticipation up first.
        case nod
        /// Double nod (strong agreement). Declination: 2nd nod ~80% of 1st.
        case doubleNod
        /// Triple nod (enthusiastic). Fast, bouncy, with smile.
        case enthusiasticNod
        /// Reluctant nod. Slow, single, slight grimace.
        case reluctantNod

        // --- Disagreement ---
        /// Head shake. Yaw oscillation, 2-3 cycles.
        case shake
        /// Gentle shake (soft no). Smaller amplitude, 1-2 cycles.
        case gentleShake
        /// Dismissive. Look away + slight shake + eye roll hint.
        case dismissive

        // --- Curiosity / Thinking ---
        /// Head tilt (curiosity). Roll axis, single direction.
        case tilt
        /// Tilt with slight nod (interest/engagement).
        case tiltNod
        /// Think/ponder. Look up-left, slight tilt, brow furrow.
        case think
        /// Consider/weigh. Head tilts side to side (weighing options).
        case consider

        // --- Surprise / Realization ---
        /// Surprise. Quick pull back, eyes wide, brows up.
        case surprise
        /// Realization/eureka. Snap head up, eyes widen, lean forward.
        case realize

        // --- Emphasis ---
        /// Forward thrust on beat. Body leans in.
        case emphasize
        /// Strong emphasis. Bigger forward + slight nod.
        case strongEmphasize

        // --- Emotional ---
        /// Empathize. Slow nod, forward lean, soft expression.
        case empathize
        /// Excitement. Quick bouncy motion, wide eyes.
        case excited
        /// Sad/sympathetic. Slow droop, heavy head.
        case sad
        /// Skeptical. Lean back, one brow up, slight turn.
        case skeptical

        // --- Conversational ---
        /// Listening acknowledgment. Micro-nod.
        case acknowledge
        /// Swaggle (Milt Kahl). Cocky side-to-side figure-8.
        case swaggle
        /// Shrug (head component). Slight raise + tilt + brow raise.
        case shrug

        /// Custom gesture from parameters.
        case custom(pitch: GestureCurve, yaw: GestureCurve, roll: GestureCurve)
    }

    /// A single-axis animation curve with Disney anticipation and overshoot.
    public struct GestureCurve {
        /// Peak amplitude in degrees.
        public var amplitude: Float
        /// Number of oscillations (1 = single movement, 2+ = back and forth).
        public var oscillations: Int
        /// Total duration in seconds.
        public var duration: Float
        /// Asymmetry: 0.5 = symmetric, <0.5 = fast attack, >0.5 = fast release.
        public var asymmetry: Float
        /// Anticipation: counter-movement before main action (0 = none, 0.3 = 30% reverse).
        public var anticipation: Float
        /// Overshoot: how much past target (0 = none, 0.15 = 15% past).
        public var overshoot: Float
        /// Declination: each successive oscillation shrinks by this factor (1.0 = no decay).
        public var declination: Float

        public init(
            amplitude: Float = 0,
            oscillations: Int = 1,
            duration: Float = 0.4,
            asymmetry: Float = 0.4,
            anticipation: Float = 0,
            overshoot: Float = 0,
            declination: Float = 1.0
        ) {
            self.amplitude = amplitude
            self.oscillations = oscillations
            self.duration = duration
            self.asymmetry = asymmetry
            self.anticipation = anticipation
            self.overshoot = overshoot
            self.declination = declination
        }

        /// Evaluate the curve at normalized time t (0..1).
        func evaluate(at t: Float) -> Float {
            guard amplitude != 0, t >= 0, t <= 1 else { return 0 }

            // Phase 1: Anticipation (counter-movement)
            let anticipDur: Float = anticipation > 0 ? 0.12 : 0  // 12% of duration for anticipation
            if anticipation > 0 && t < anticipDur {
                let at = t / anticipDur
                let ease = at * at * (3 - 2 * at) // smoothstep in
                return -amplitude * anticipation * ease
            }

            // Remap t to exclude anticipation phase
            let mainT: Float
            if anticipDur > 0 {
                mainT = (t - anticipDur) / (1 - anticipDur)
            } else {
                mainT = t
            }
            guard mainT >= 0 else { return -amplitude * anticipation }

            // Envelope: attack-sustain-release
            let envelope: Float
            if mainT < asymmetry {
                let at = mainT / asymmetry
                envelope = at * at * (3 - 2 * at) // smoothstep
            } else {
                let rt = (mainT - asymmetry) / (1 - asymmetry)
                // Overshoot: slight bounce past zero on release
                if overshoot > 0 && rt > 0.7 {
                    let ot = (rt - 0.7) / 0.3
                    envelope = (1 - rt * rt) - overshoot * sin(ot * .pi)
                } else {
                    envelope = 1 - rt * rt // quadratic decay
                }
            }

            // Oscillation with declination
            let phase = mainT * Float(oscillations) * 2 * .pi
            let cycleIndex = mainT * Float(oscillations)
            let decayFactor = pow(declination, floor(cycleIndex))
            let wave = sin(phase)

            return wave * envelope * amplitude * decayFactor
        }
    }

    /// Secondary facial action that accompanies a gesture.
    public struct SecondaryAction {
        public var blendshapes: [String: Float]
        /// Onset time (0..1 of gesture duration).
        public var onset: Float
        /// Peak time.
        public var peak: Float
        /// Offset time.
        public var offset: Float

        public init(_ bs: [String: Float], onset: Float = 0.1, peak: Float = 0.3, offset: Float = 0.8) {
            self.blendshapes = bs
            self.onset = onset
            self.peak = peak
            self.offset = offset
        }

        /// Evaluate intensity at normalized time t.
        func intensity(at t: Float) -> Float {
            if t < onset { return 0 }
            if t < peak {
                let p = (t - onset) / (peak - onset)
                return p * p * (3 - 2 * p) // smoothstep in
            }
            if t < offset { return 1.0 }
            let r = (t - offset) / (1 - offset)
            return max(0, 1 - r * r) // quadratic out
        }
    }

    // MARK: - State

    private struct ActiveGesture {
        let type: GestureType
        let startTime: TimeInterval
        let intensity: Float
    }

    private var activeGestures: [ActiveGesture] = []

    /// Called every frame with pitch/yaw/roll deltas in degrees.
    public var onFrame: ((_ pitch: Float, _ yaw: Float, _ roll: Float) -> Void)?

    /// Called every frame with secondary blendshape deltas.
    public var onBlendshapes: ((_ blendshapes: [String: Float]) -> Void)?

    private var displayLink: CADisplayLink?
    private var lastTime: TimeInterval = 0

    // MARK: - Lifecycle

    public init() {}

    public func start() {
        lastTime = CACurrentMediaTime()
    }

    public func stop() {
        activeGestures.removeAll()
    }

    public var isRunning: Bool { true }

    // MARK: - Trigger Gestures

    /// Play a gesture with optional intensity scaling.
    public func play(_ type: GestureType, intensity: Float = 1.0) {
        activeGestures.append(ActiveGesture(type: type, startTime: CACurrentMediaTime(), intensity: intensity))
    }

    public func nod(intensity: Float = 1.0) { play(.nod, intensity: intensity) }
    public func doubleNod(intensity: Float = 1.0) { play(.doubleNod, intensity: intensity) }
    public func shake(intensity: Float = 1.0) { play(.shake, intensity: intensity) }
    public func tilt(intensity: Float = 1.0) { play(.tilt, intensity: intensity) }

    // MARK: - Gesture Parameters

    private func curves(for type: GestureType) -> (pitch: GestureCurve, yaw: GestureCurve, roll: GestureCurve, duration: Float) {
        switch type {

        // ── Agreement ──

        case .nod:
            // Disney nod: anticipation up 3°, then down 10°, slow return.
            return (
                pitch: GestureCurve(amplitude: -10, oscillations: 1, duration: 0.45, asymmetry: 0.3, anticipation: 0.3, overshoot: 0.08),
                yaw: GestureCurve(amplitude: 2, oscillations: 1, duration: 0.45, asymmetry: 0.35), // arc: slight yaw during nod
                roll: GestureCurve(),
                duration: 0.45
            )
        case .doubleNod:
            // Two nods, 2nd is 80% of 1st (declination).
            return (
                pitch: GestureCurve(amplitude: -8, oscillations: 2, duration: 0.7, asymmetry: 0.3, anticipation: 0.25, declination: 0.8),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.7
            )
        case .enthusiasticNod:
            // Fast triple nod with bounce, declination.
            return (
                pitch: GestureCurve(amplitude: -9, oscillations: 3, duration: 0.8, asymmetry: 0.25, anticipation: 0.2, overshoot: 0.12, declination: 0.75),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 2, oscillations: 1, duration: 0.8, asymmetry: 0.5), // slight lean in
                duration: 0.8
            )
        case .reluctantNod:
            // Slow, heavy single nod. Long release.
            return (
                pitch: GestureCurve(amplitude: -6, oscillations: 1, duration: 0.9, asymmetry: 0.45),
                yaw: GestureCurve(amplitude: -3, oscillations: 1, duration: 0.9, asymmetry: 0.5), // slight look away
                roll: GestureCurve(),
                duration: 0.9
            )

        // ── Disagreement ──

        case .shake:
            // 3 oscillations, symmetric, with anticipation.
            return (
                pitch: GestureCurve(amplitude: -2, oscillations: 1, duration: 1.0, asymmetry: 0.3), // slight dip during shake
                yaw: GestureCurve(amplitude: 12, oscillations: 3, duration: 1.0, asymmetry: 0.5, anticipation: 0.2, declination: 0.85),
                roll: GestureCurve(),
                duration: 1.0
            )
        case .gentleShake:
            // Soft no. Small, 1.5 oscillations.
            return (
                pitch: GestureCurve(),
                yaw: GestureCurve(amplitude: 6, oscillations: 2, duration: 0.7, asymmetry: 0.5, declination: 0.7),
                roll: GestureCurve(),
                duration: 0.7
            )
        case .dismissive:
            // Look away + slight shake. Yaw bias to one side.
            return (
                pitch: GestureCurve(amplitude: 3, oscillations: 1, duration: 0.8, asymmetry: 0.6), // slight lean back
                yaw: GestureCurve(amplitude: 15, oscillations: 2, duration: 0.8, asymmetry: 0.4, declination: 0.6),
                roll: GestureCurve(amplitude: -3, oscillations: 1, duration: 0.8, asymmetry: 0.5),
                duration: 0.8
            )

        // ── Curiosity / Thinking ──

        case .tilt:
            // Single roll tilt. Disney: anticipation in opposite direction.
            let dir: Float = Bool.random() ? 1 : -1
            return (
                pitch: GestureCurve(),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 8 * dir, oscillations: 1, duration: 0.6, asymmetry: 0.35, anticipation: 0.25, overshoot: 0.1),
                duration: 0.6
            )
        case .tiltNod:
            // Tilt + micro nod = "I see, interesting"
            let dir: Float = Bool.random() ? 1 : -1
            return (
                pitch: GestureCurve(amplitude: -5, oscillations: 1, duration: 0.7, asymmetry: 0.4),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 6 * dir, oscillations: 1, duration: 0.7, asymmetry: 0.35, anticipation: 0.2),
                duration: 0.7
            )
        case .think:
            // Look up-left, slight tilt, hold, then return. Slow and contemplative.
            return (
                pitch: GestureCurve(amplitude: 5, oscillations: 1, duration: 1.2, asymmetry: 0.6), // look up (hold longer)
                yaw: GestureCurve(amplitude: -8, oscillations: 1, duration: 1.2, asymmetry: 0.55), // look left
                roll: GestureCurve(amplitude: 4, oscillations: 1, duration: 1.2, asymmetry: 0.5),
                duration: 1.2
            )
        case .consider:
            // Head tilts side to side — weighing options.
            return (
                pitch: GestureCurve(),
                yaw: GestureCurve(amplitude: 5, oscillations: 2, duration: 1.4, asymmetry: 0.5),
                roll: GestureCurve(amplitude: 6, oscillations: 2, duration: 1.4, asymmetry: 0.5, declination: 0.9),
                duration: 1.4
            )

        // ── Surprise / Realization ──

        case .surprise:
            // Quick pull back. Anticipation: slight forward lean first.
            return (
                pitch: GestureCurve(amplitude: 8, oscillations: 1, duration: 0.5, asymmetry: 0.2, anticipation: 0.35, overshoot: 0.15),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.5
            )
        case .realize:
            // Snap head up, then lean forward. Two-phase.
            return (
                pitch: GestureCurve(amplitude: 6, oscillations: 1, duration: 0.35, asymmetry: 0.2, overshoot: 0.2), // snap up
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.35
            )

        // ── Emphasis ──

        case .emphasize:
            // Forward thrust on beat. Quick, snappy.
            return (
                pitch: GestureCurve(amplitude: -5, oscillations: 1, duration: 0.3, asymmetry: 0.25, anticipation: 0.2),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.3
            )
        case .strongEmphasize:
            // Bigger forward + slight nod + body lean.
            return (
                pitch: GestureCurve(amplitude: -8, oscillations: 1, duration: 0.4, asymmetry: 0.25, anticipation: 0.3, overshoot: 0.1),
                yaw: GestureCurve(amplitude: 3, oscillations: 1, duration: 0.4, asymmetry: 0.3),
                roll: GestureCurve(),
                duration: 0.4
            )

        // ── Emotional ──

        case .empathize:
            // Slow nod, forward lean, gentle.
            return (
                pitch: GestureCurve(amplitude: -6, oscillations: 1, duration: 1.0, asymmetry: 0.5),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 3, oscillations: 1, duration: 1.0, asymmetry: 0.5), // slight tilt
                duration: 1.0
            )
        case .excited:
            // Quick bouncy up-down. High frequency, small amplitude.
            return (
                pitch: GestureCurve(amplitude: -5, oscillations: 3, duration: 0.6, asymmetry: 0.3, overshoot: 0.15, declination: 0.85),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 3, oscillations: 2, duration: 0.6, asymmetry: 0.4),
                duration: 0.6
            )
        case .sad:
            // Slow droop. Heavy head falls forward, very slow return.
            return (
                pitch: GestureCurve(amplitude: -7, oscillations: 1, duration: 1.5, asymmetry: 0.65), // hold the droop
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 3, oscillations: 1, duration: 1.5, asymmetry: 0.6),
                duration: 1.5
            )
        case .skeptical:
            // Lean back, slight turn. One brow up (via secondary action).
            return (
                pitch: GestureCurve(amplitude: 5, oscillations: 1, duration: 0.8, asymmetry: 0.4, anticipation: 0.15),
                yaw: GestureCurve(amplitude: -6, oscillations: 1, duration: 0.8, asymmetry: 0.45),
                roll: GestureCurve(amplitude: -3, oscillations: 1, duration: 0.8, asymmetry: 0.4),
                duration: 0.8
            )

        // ── Conversational ──

        case .acknowledge:
            // Micro-nod. Tiny, quick. Listener feedback.
            return (
                pitch: GestureCurve(amplitude: -3, oscillations: 1, duration: 0.25, asymmetry: 0.3),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.25
            )
        case .swaggle:
            // Milt Kahl figure-8: yaw oscillates, pitch at 2x frequency.
            return (
                pitch: GestureCurve(amplitude: -3, oscillations: 2, duration: 0.8, asymmetry: 0.5),
                yaw: GestureCurve(amplitude: 8, oscillations: 1, duration: 0.8, asymmetry: 0.5),
                roll: GestureCurve(amplitude: 4, oscillations: 2, duration: 0.8, asymmetry: 0.5),
                duration: 0.8
            )
        case .shrug:
            // Head component of shrug: slight raise + tilt.
            return (
                pitch: GestureCurve(amplitude: 3, oscillations: 1, duration: 0.6, asymmetry: 0.35, anticipation: 0.2),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 5, oscillations: 1, duration: 0.6, asymmetry: 0.4),
                duration: 0.6
            )

        case .custom(let p, let y, let r):
            return (p, y, r, max(p.duration, y.duration, r.duration))
        }
    }

    /// Secondary facial actions for each gesture type.
    private func secondaryAction(for type: GestureType) -> SecondaryAction? {
        switch type {
        case .nod, .doubleNod:
            // Brows raise slightly on nod, eyes may narrow on down-beat
            return SecondaryAction([
                "browInnerUp": 0.12,
                "mouthSmileLeft": 0.05,
                "mouthSmileRight": 0.05,
            ], onset: 0.1, peak: 0.3, offset: 0.7)

        case .enthusiasticNod:
            return SecondaryAction([
                "browInnerUp": 0.15,
                "mouthSmileLeft": 0.15,
                "mouthSmileRight": 0.15,
                "cheekSquintLeft": 0.08,
                "cheekSquintRight": 0.08,
            ], onset: 0.05, peak: 0.2, offset: 0.8)

        case .reluctantNod:
            return SecondaryAction([
                "mouthPressLeft": 0.1,
                "mouthPressRight": 0.1,
                "browDownLeft": 0.05,
                "browDownRight": 0.05,
            ], onset: 0.2, peak: 0.5, offset: 0.85)

        case .shake, .gentleShake:
            // Mouth tightens during shake
            return SecondaryAction([
                "mouthPressLeft": 0.1,
                "mouthPressRight": 0.1,
                "browDownLeft": 0.08,
                "browDownRight": 0.08,
            ], onset: 0.1, peak: 0.3, offset: 0.8)

        case .dismissive:
            return SecondaryAction([
                "eyeSquintLeft": 0.1,
                "eyeSquintRight": 0.1,
                "mouthLeft": 0.06,
            ], onset: 0.1, peak: 0.35, offset: 0.7)

        case .think:
            return SecondaryAction([
                "browDownLeft": 0.08,
                "browDownRight": 0.08,
                "eyeSquintLeft": 0.06,
                "eyeSquintRight": 0.06,
                "mouthLeft": 0.04,
            ], onset: 0.15, peak: 0.4, offset: 0.85)

        case .consider:
            return SecondaryAction([
                "browInnerUp": 0.08,
                "mouthPucker": 0.06,
            ], onset: 0.1, peak: 0.3, offset: 0.8)

        case .surprise:
            // Eyes widen 50ms before head snaps back, jaw drops after
            return SecondaryAction([
                "eyeWideLeft": 0.35,
                "eyeWideRight": 0.35,
                "browInnerUp": 0.3,
                "browOuterUpLeft": 0.25,
                "browOuterUpRight": 0.25,
                "jawOpen": 0.15,
            ], onset: 0.0, peak: 0.15, offset: 0.6)

        case .realize:
            return SecondaryAction([
                "eyeWideLeft": 0.25,
                "eyeWideRight": 0.25,
                "browInnerUp": 0.2,
                "browOuterUpLeft": 0.15,
                "browOuterUpRight": 0.15,
                "mouthSmileLeft": 0.08,
                "mouthSmileRight": 0.08,
            ], onset: 0.0, peak: 0.2, offset: 0.7)

        case .empathize:
            return SecondaryAction([
                "browInnerUp": 0.1,
                "mouthSmileLeft": 0.06,
                "mouthSmileRight": 0.06,
            ], onset: 0.15, peak: 0.45, offset: 0.9)

        case .excited:
            return SecondaryAction([
                "eyeWideLeft": 0.15,
                "eyeWideRight": 0.15,
                "mouthSmileLeft": 0.2,
                "mouthSmileRight": 0.2,
                "cheekSquintLeft": 0.1,
                "cheekSquintRight": 0.1,
            ], onset: 0.05, peak: 0.2, offset: 0.85)

        case .sad:
            return SecondaryAction([
                "browInnerUp": 0.15,
                "mouthFrownLeft": 0.12,
                "mouthFrownRight": 0.12,
            ], onset: 0.1, peak: 0.5, offset: 0.95)

        case .skeptical:
            // Asymmetric brow — one up, one down
            return SecondaryAction([
                "browOuterUpLeft": 0.3,
                "browDownRight": 0.1,
                "mouthLeft": 0.05,
                "eyeSquintRight": 0.08,
            ], onset: 0.1, peak: 0.35, offset: 0.75)

        case .shrug:
            return SecondaryAction([
                "browInnerUp": 0.2,
                "browOuterUpLeft": 0.15,
                "browOuterUpRight": 0.15,
                "mouthPressLeft": 0.08,
                "mouthPressRight": 0.08,
            ], onset: 0.1, peak: 0.3, offset: 0.7)

        case .swaggle:
            return SecondaryAction([
                "mouthSmileLeft": 0.08,
                "mouthSmileRight": 0.08,
                "browOuterUpLeft": 0.1,
            ], onset: 0.1, peak: 0.3, offset: 0.7)

        default:
            return nil
        }
    }

    // MARK: - External Tick (driven by BehaviorEngine's single DisplayLink)

    /// Call this from an external display link instead of using start()/stop().
    public func externalTick() {
        _tick()
    }

    // MARK: - Main Loop

    @objc private func tick() {
        _tick()
    }

    private func _tick() {
        let now = CACurrentMediaTime()

        var totalPitch: Float = 0
        var totalYaw: Float = 0
        var totalRoll: Float = 0
        var totalBS: [String: Float] = [:]

        // Evaluate and sum all active gestures
        activeGestures.removeAll { gesture in
            let (pitchCurve, yawCurve, rollCurve, duration) = curves(for: gesture.type)
            let elapsed = Float(now - gesture.startTime)

            if elapsed > duration { return true } // remove finished

            let t = elapsed / duration
            totalPitch += pitchCurve.evaluate(at: t) * gesture.intensity
            totalYaw += yawCurve.evaluate(at: t) * gesture.intensity
            totalRoll += rollCurve.evaluate(at: t) * gesture.intensity

            // Secondary facial action
            if let secondary = secondaryAction(for: gesture.type) {
                let si = secondary.intensity(at: t) * gesture.intensity
                if si > 0.001 {
                    for (key, value) in secondary.blendshapes {
                        totalBS[key, default: 0] += value * si
                    }
                }
            }

            return false
        }

        onFrame?(totalPitch, totalYaw, totalRoll)
        if !totalBS.isEmpty {
            onBlendshapes?(totalBS)
        }
    }
}
