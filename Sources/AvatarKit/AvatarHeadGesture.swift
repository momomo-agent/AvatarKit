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

    /// Called every frame with spatial translation (x, y, z) in avatar scene units.
    public var onTranslation: ((_ translation: SIMD3<Float>) -> Void)?

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
            return (
                pitch: GestureCurve(amplitude: -14, oscillations: 1, duration: 0.45, asymmetry: 0.3, anticipation: 0.3, overshoot: 0.1),
                yaw: GestureCurve(amplitude: 3, oscillations: 1, duration: 0.45, asymmetry: 0.35),
                roll: GestureCurve(),
                duration: 0.45
            )
        case .doubleNod:
            return (
                pitch: GestureCurve(amplitude: -12, oscillations: 2, duration: 0.7, asymmetry: 0.3, anticipation: 0.25, declination: 0.8),
                yaw: GestureCurve(amplitude: 2, oscillations: 1, duration: 0.7, asymmetry: 0.5), // arc: slight yaw during nod
                roll: GestureCurve(),
                duration: 0.7
            )
        case .enthusiasticNod:
            return (
                pitch: GestureCurve(amplitude: -14, oscillations: 3, duration: 0.8, asymmetry: 0.25, anticipation: 0.2, overshoot: 0.15, declination: 0.75),
                yaw: GestureCurve(amplitude: 3, oscillations: 1, duration: 0.8, asymmetry: 0.5),
                roll: GestureCurve(amplitude: 3, oscillations: 1, duration: 0.8, asymmetry: 0.5),
                duration: 0.8
            )
        case .reluctantNod:
            return (
                pitch: GestureCurve(amplitude: -8, oscillations: 1, duration: 1.0, asymmetry: 0.45),
                yaw: GestureCurve(amplitude: -4, oscillations: 1, duration: 1.0, asymmetry: 0.5),
                roll: GestureCurve(),
                duration: 1.0
            )

        // ── Disagreement ──

        case .shake:
            return (
                pitch: GestureCurve(amplitude: -3, oscillations: 1, duration: 1.0, asymmetry: 0.3),
                yaw: GestureCurve(amplitude: 18, oscillations: 3, duration: 1.0, asymmetry: 0.5, anticipation: 0.2, declination: 0.85),
                roll: GestureCurve(amplitude: 3, oscillations: 2, duration: 1.0, asymmetry: 0.5), // slight roll coupling
                duration: 1.0
            )
        case .gentleShake:
            return (
                pitch: GestureCurve(),
                yaw: GestureCurve(amplitude: 10, oscillations: 2, duration: 0.7, asymmetry: 0.5, declination: 0.7),
                roll: GestureCurve(amplitude: 2, oscillations: 2, duration: 0.7, asymmetry: 0.5),
                duration: 0.7
            )
        case .dismissive:
            return (
                pitch: GestureCurve(amplitude: 5, oscillations: 1, duration: 0.8, asymmetry: 0.6),
                yaw: GestureCurve(amplitude: 20, oscillations: 2, duration: 0.8, asymmetry: 0.4, declination: 0.6),
                roll: GestureCurve(amplitude: -5, oscillations: 1, duration: 0.8, asymmetry: 0.5),
                duration: 0.8
            )

        // ── Curiosity / Thinking ──

        case .tilt:
            let dir: Float = Bool.random() ? 1 : -1
            return (
                pitch: GestureCurve(),
                yaw: GestureCurve(amplitude: 3 * dir, oscillations: 1, duration: 0.6, asymmetry: 0.4), // arc coupling
                roll: GestureCurve(amplitude: 12 * dir, oscillations: 1, duration: 0.6, asymmetry: 0.35, anticipation: 0.25, overshoot: 0.12),
                duration: 0.6
            )
        case .tiltNod:
            let dir: Float = Bool.random() ? 1 : -1
            return (
                pitch: GestureCurve(amplitude: -7, oscillations: 1, duration: 0.7, asymmetry: 0.4),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 8 * dir, oscillations: 1, duration: 0.7, asymmetry: 0.35, anticipation: 0.2),
                duration: 0.7
            )
        case .think:
            return (
                pitch: GestureCurve(amplitude: 8, oscillations: 1, duration: 1.2, asymmetry: 0.6),
                yaw: GestureCurve(amplitude: -12, oscillations: 1, duration: 1.2, asymmetry: 0.55),
                roll: GestureCurve(amplitude: 6, oscillations: 1, duration: 1.2, asymmetry: 0.5),
                duration: 1.2
            )
        case .consider:
            return (
                pitch: GestureCurve(amplitude: 3, oscillations: 1, duration: 1.4, asymmetry: 0.6),
                yaw: GestureCurve(amplitude: 8, oscillations: 2, duration: 1.4, asymmetry: 0.5),
                roll: GestureCurve(amplitude: 10, oscillations: 2, duration: 1.4, asymmetry: 0.5, declination: 0.9),
                duration: 1.4
            )

        // ── Surprise / Realization ──

        case .surprise:
            return (
                pitch: GestureCurve(amplitude: 12, oscillations: 1, duration: 0.5, asymmetry: 0.2, anticipation: 0.35, overshoot: 0.18),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.5
            )
        case .realize:
            return (
                pitch: GestureCurve(amplitude: 10, oscillations: 1, duration: 0.35, asymmetry: 0.2, overshoot: 0.2),
                yaw: GestureCurve(amplitude: 3, oscillations: 1, duration: 0.35, asymmetry: 0.3),
                roll: GestureCurve(),
                duration: 0.35
            )

        // ── Emphasis ──

        case .emphasize:
            return (
                pitch: GestureCurve(amplitude: -8, oscillations: 1, duration: 0.3, asymmetry: 0.25, anticipation: 0.2),
                yaw: GestureCurve(amplitude: 2, oscillations: 1, duration: 0.3, asymmetry: 0.4),
                roll: GestureCurve(),
                duration: 0.3
            )
        case .strongEmphasize:
            // Bigger forward + slight nod + body lean.
            return (
                pitch: GestureCurve(amplitude: -12, oscillations: 1, duration: 0.4, asymmetry: 0.25, anticipation: 0.3, overshoot: 0.12),
                yaw: GestureCurve(amplitude: 5, oscillations: 1, duration: 0.4, asymmetry: 0.3),
                roll: GestureCurve(amplitude: 2, oscillations: 1, duration: 0.4, asymmetry: 0.4),
                duration: 0.4
            )

        // ── Emotional ──

        case .empathize:
            return (
                pitch: GestureCurve(amplitude: -9, oscillations: 1, duration: 1.0, asymmetry: 0.5),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 5, oscillations: 1, duration: 1.0, asymmetry: 0.5),
                duration: 1.0
            )
        case .excited:
            return (
                pitch: GestureCurve(amplitude: -8, oscillations: 4, duration: 0.7, asymmetry: 0.3, overshoot: 0.15, declination: 0.85),
                yaw: GestureCurve(amplitude: 3, oscillations: 2, duration: 0.7, asymmetry: 0.4),
                roll: GestureCurve(amplitude: 5, oscillations: 3, duration: 0.7, asymmetry: 0.4),
                duration: 0.7
            )
        case .sad:
            return (
                pitch: GestureCurve(amplitude: -10, oscillations: 1, duration: 1.5, asymmetry: 0.65),
                yaw: GestureCurve(amplitude: -3, oscillations: 1, duration: 1.5, asymmetry: 0.6),
                roll: GestureCurve(amplitude: 5, oscillations: 1, duration: 1.5, asymmetry: 0.6),
                duration: 1.5
            )
        case .skeptical:
            return (
                pitch: GestureCurve(amplitude: 8, oscillations: 1, duration: 0.8, asymmetry: 0.4, anticipation: 0.15),
                yaw: GestureCurve(amplitude: -8, oscillations: 1, duration: 0.8, asymmetry: 0.45),
                roll: GestureCurve(amplitude: -5, oscillations: 1, duration: 0.8, asymmetry: 0.4),
                duration: 0.8
            )

        // ── Conversational ──

        case .acknowledge:
            return (
                pitch: GestureCurve(amplitude: -5, oscillations: 1, duration: 0.25, asymmetry: 0.3),
                yaw: GestureCurve(),
                roll: GestureCurve(),
                duration: 0.25
            )
        case .swaggle:
            // Milt Kahl figure-8: yaw oscillates, pitch at 2x frequency.
            return (
                pitch: GestureCurve(amplitude: -5, oscillations: 2, duration: 0.8, asymmetry: 0.5),
                yaw: GestureCurve(amplitude: 12, oscillations: 1, duration: 0.8, asymmetry: 0.5),
                roll: GestureCurve(amplitude: 6, oscillations: 2, duration: 0.8, asymmetry: 0.5),
                duration: 0.8
            )
        case .shrug:
            // Head component of shrug: slight raise + tilt.
            return (
                pitch: GestureCurve(amplitude: 5, oscillations: 1, duration: 0.6, asymmetry: 0.35, anticipation: 0.2),
                yaw: GestureCurve(),
                roll: GestureCurve(amplitude: 8, oscillations: 1, duration: 0.6, asymmetry: 0.4),
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
            return SecondaryAction([
                "browInnerUp": 0.25,
                "mouthSmileLeft": 0.12,
                "mouthSmileRight": 0.12,
                "eyeSquintLeft": 0.06,
                "eyeSquintRight": 0.06,
            ], onset: 0.1, peak: 0.3, offset: 0.7)

        case .enthusiasticNod:
            return SecondaryAction([
                "browInnerUp": 0.35,
                "mouthSmileLeft": 0.3,
                "mouthSmileRight": 0.3,
                "cheekSquintLeft": 0.2,
                "cheekSquintRight": 0.2,
                "eyeWideLeft": 0.1,
                "eyeWideRight": 0.1,
            ], onset: 0.05, peak: 0.2, offset: 0.8)

        case .reluctantNod:
            return SecondaryAction([
                "mouthPressLeft": 0.25,
                "mouthPressRight": 0.25,
                "browDownLeft": 0.12,
                "browDownRight": 0.12,
                "mouthFrownLeft": 0.08,
                "mouthFrownRight": 0.08,
            ], onset: 0.2, peak: 0.5, offset: 0.85)

        case .shake, .gentleShake:
            return SecondaryAction([
                "mouthPressLeft": 0.2,
                "mouthPressRight": 0.2,
                "browDownLeft": 0.15,
                "browDownRight": 0.15,
                "mouthFrownLeft": 0.06,
                "mouthFrownRight": 0.06,
            ], onset: 0.1, peak: 0.3, offset: 0.8)

        case .dismissive:
            return SecondaryAction([
                "eyeSquintLeft": 0.2,
                "eyeSquintRight": 0.2,
                "mouthLeft": 0.12,
                "mouthSmileLeft": 0.08,
                "browOuterUpLeft": 0.1,
            ], onset: 0.1, peak: 0.35, offset: 0.7)

        case .think:
            return SecondaryAction([
                "browDownLeft": 0.15,
                "browDownRight": 0.15,
                "eyeSquintLeft": 0.12,
                "eyeSquintRight": 0.12,
                "mouthLeft": 0.08,
                "mouthPucker": 0.1,
            ], onset: 0.15, peak: 0.4, offset: 0.85)

        case .consider:
            return SecondaryAction([
                "browInnerUp": 0.18,
                "mouthPucker": 0.15,
                "eyeLookUpLeft": 0.1,
                "eyeLookUpRight": 0.1,
            ], onset: 0.1, peak: 0.3, offset: 0.8)

        case .surprise:
            return SecondaryAction([
                "eyeWideLeft": 0.6,
                "eyeWideRight": 0.6,
                "browInnerUp": 0.5,
                "browOuterUpLeft": 0.45,
                "browOuterUpRight": 0.45,
                "jawOpen": 0.35,
            ], onset: 0.0, peak: 0.15, offset: 0.6)

        case .realize:
            return SecondaryAction([
                "eyeWideLeft": 0.45,
                "eyeWideRight": 0.45,
                "browInnerUp": 0.4,
                "browOuterUpLeft": 0.3,
                "browOuterUpRight": 0.3,
                "mouthSmileLeft": 0.2,
                "mouthSmileRight": 0.2,
                "jawOpen": 0.15,
            ], onset: 0.0, peak: 0.2, offset: 0.7)

        case .empathize:
            return SecondaryAction([
                "browInnerUp": 0.25,
                "mouthSmileLeft": 0.15,
                "mouthSmileRight": 0.15,
                "eyeSquintLeft": 0.1,
                "eyeSquintRight": 0.1,
            ], onset: 0.15, peak: 0.45, offset: 0.9)

        case .excited:
            return SecondaryAction([
                "eyeWideLeft": 0.35,
                "eyeWideRight": 0.35,
                "mouthSmileLeft": 0.45,
                "mouthSmileRight": 0.45,
                "cheekSquintLeft": 0.25,
                "cheekSquintRight": 0.25,
                "jawOpen": 0.15,
            ], onset: 0.05, peak: 0.2, offset: 0.85)

        case .sad:
            return SecondaryAction([
                "browInnerUp": 0.3,
                "mouthFrownLeft": 0.3,
                "mouthFrownRight": 0.3,
                "eyeBlinkLeft": 0.2,
                "eyeBlinkRight": 0.2,
            ], onset: 0.1, peak: 0.5, offset: 0.95)

        case .skeptical:
            return SecondaryAction([
                "browOuterUpLeft": 0.5,
                "browDownRight": 0.2,
                "mouthLeft": 0.1,
                "eyeSquintRight": 0.15,
                "mouthSmileLeft": 0.06,
            ], onset: 0.1, peak: 0.35, offset: 0.75)

        case .shrug:
            return SecondaryAction([
                "browInnerUp": 0.4,
                "browOuterUpLeft": 0.3,
                "browOuterUpRight": 0.3,
                "mouthPressLeft": 0.15,
                "mouthPressRight": 0.15,
                "mouthStretchLeft": 0.1,
                "mouthStretchRight": 0.1,
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

    /// Spatial translation per gesture type (avatar scene units).
    /// Disney: characters move THROUGH space, not just rotate.
    /// ARKit scale: X~50, Y~20, Z~100. Values here are in scene units.
    /// 0.3 Y ≈ 1.5cm real, 1.0 Z ≈ 1cm real, 0.5 X ≈ 1cm real.
    private func spatialTranslation(for type: GestureType) -> SIMD3<Float> {
        switch type {
        case .nod, .doubleNod, .enthusiasticNod:
            return SIMD3(0, -0.05, 0.2)        // lean forward on nod
        case .reluctantNod:
            return SIMD3(0, -0.02, 0.08)       // minimal
        case .shake, .gentleShake:
            return SIMD3(0.1, 0, 0)             // slight side shift
        case .dismissive:
            return SIMD3(0.15, 0, -0.2)         // lean away + side
        case .tilt, .tiltNod:
            return SIMD3(0.08, 0, 0.1)          // lean in + side
        case .think:
            return SIMD3(0, 0.06, -0.25)        // lean back, sit up
        case .consider:
            return SIMD3(0.12, 0, 0)            // side-to-side weight shift
        case .surprise:
            return SIMD3(0, 0.12, -0.5)         // jump back + up (big!)
        case .realize:
            return SIMD3(0, 0.1, 0.3)           // snap forward + up
        case .emphasize:
            return SIMD3(0, -0.04, 0.3)         // thrust forward
        case .strongEmphasize:
            return SIMD3(0, -0.06, 0.5)         // bigger thrust
        case .empathize:
            return SIMD3(0, 0, 0.2)             // lean in
        case .excited:
            return SIMD3(0, 0.15, 0.15)         // bounce up + forward
        case .sad:
            return SIMD3(0, -0.15, 0)           // sink down
        case .skeptical:
            return SIMD3(0, 0, -0.2)            // lean back
        case .acknowledge:
            return SIMD3(0, -0.03, 0.08)        // micro lean
        case .swaggle:
            return SIMD3(0.15, 0, 0)            // side sway
        case .shrug:
            return SIMD3(0, 0.1, 0)             // rise up
        case .custom:
            return .zero
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
        var totalTranslation = SIMD3<Float>.zero

        // Evaluate and sum all active gestures
        activeGestures.removeAll { gesture in
            let (pitchCurve, yawCurve, rollCurve, duration) = curves(for: gesture.type)
            let elapsed = Float(now - gesture.startTime)

            if elapsed > duration { return true } // remove finished

            let t = elapsed / duration
            totalPitch += pitchCurve.evaluate(at: t) * gesture.intensity
            totalYaw += yawCurve.evaluate(at: t) * gesture.intensity
            totalRoll += rollCurve.evaluate(at: t) * gesture.intensity

            // Spatial translation: envelope follows the main gesture curve
            let transTarget = spatialTranslation(for: gesture.type)
            if transTarget != .zero {
                // Use a simple attack-sustain-release envelope for translation
                let transEnvelope: Float
                if t < 0.3 {
                    let at = t / 0.3
                    transEnvelope = at * at * (3 - 2 * at) // smoothstep in
                } else if t < 0.6 {
                    transEnvelope = 1.0
                } else {
                    let rt = (t - 0.6) / 0.4
                    transEnvelope = 1.0 - rt * rt // quadratic out
                }
                totalTranslation += transTarget * transEnvelope * gesture.intensity
            }

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
        if totalTranslation != .zero {
            onTranslation?(totalTranslation)
        }
    }
}
