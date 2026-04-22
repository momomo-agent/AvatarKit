import Foundation
import QuartzCore
import simd

// MARK: - Idle Animator

/// Generates natural idle motion with research-backed behavioral parameters.
///
/// Research sources:
/// - Disney Research: Modeling and Animating Eye Blinks (close 80ms, open 200ms)
/// - USC ICT: Neurobiological model of visual attention (Lee et al. 2002)
/// - FACS: Onset 200-500ms, apex 500ms-4s, offset 500ms-1s
/// - Frontiers in Psychology: Breathing in Conversation (McFarland 2001)
/// - PMC: Eye blinks as communicative signals in face-to-face interaction
/// - Max Planck: Eyebrow movements as signals of communicative problems (2025)
/// - Hale et al. 2020: Listener head mimicry at 600ms delay, fast nodding >1.5Hz
/// - Koç University ICASSP: Prosody-driven head gesture animation
/// - Russell 1980: Circumplex Model of Affect (valence-arousal)
///
/// Architecture: 10 independent layers, each with its own timing and state.
/// Layers are additive — the mixer resolves conflicts (mouth region priority etc.)
public class AvatarIdleAnimator {
    
    // MARK: - Configuration
    
    /// Master intensity (0 = off, 1 = full).
    public var intensity: Float = 1.0
    
    /// Enable/disable individual layers.
    public var blinkEnabled = true
    public var breathingEnabled = true
    public var headMotionEnabled = true
    public var expressionEnabled = true
    public var saccadeEnabled = true
    public var microExpressionEnabled = true
    public var swallowEnabled = true
    
    /// Whether the character is currently speaking.
    public var isSpeaking = false
    
    /// Whether the character is currently listening to someone.
    /// Affects blink rate (decreases), attention (increases), nod mimicry.
    public var isListening = false
    
    /// Audio energy (RMS amplitude, 0-1).
    public var audioEnergy: Float = 0
    
    /// Audio pitch (Hz, 0 = unknown). Drives prosody-linked head motion.
    public var audioPitch: Float = 0
    
    /// Callback every frame.
    public var onFrame: ((_ blendshapes: [String: Float], _ headRotation: simd_quatf) -> Void)?
    
    // MARK: - Internal State
    
    private var displayLink: CADisplayLink?
    private var startTime: TimeInterval = 0
    private var lastTime: TimeInterval = 0
    
    // Smoothed inputs
    private var smoothedEnergy: Float = 0
    private var smoothedPitch: Float = 0
    private var prevSmoothedPitch: Float = 0
    
    // --- Blink ---
    private var nextBlinkTime: TimeInterval = 0
    private var blinkPhase: BlinkPhase = .open
    private var blinkPhaseStart: TimeInterval = 0
    
    // --- Breathing ---
    private var breathPhase: Float = 0
    private var breathDepthVariation: Float = 1.0
    private var nextBreathVariationTime: TimeInterval = 0
    
    // --- Head motion ---
    private var headNoiseX = PerlinOctave()
    private var headNoiseY = PerlinOctave()
    private var headNoiseZ = PerlinOctave()
    
    // --- Saccade ---
    private var nextSaccadeTime: TimeInterval = 0
    private var saccadeTarget: SIMD2<Float> = .zero
    private var saccadeCurrent: SIMD2<Float> = .zero
    
    // --- Mood ---
    private var currentMood: Mood = .neutral
    private var moodBlendshapes: [String: Float] = [:]
    private var moodTransitionProgress: Float = 1.0
    
    // --- Micro-expressions ---
    private var nextMicroExpressionTime: TimeInterval = 0
    private var microExpressionBS: [String: Float] = [:]
    private var microExpressionPhase: MicroExprPhase = .idle
    private var microExprPhaseStart: TimeInterval = 0
    private var microExprOnsetDuration: Float = 0
    private var microExprApexDuration: Float = 0
    private var microExprOffsetDuration: Float = 0
    
    // --- Swallow ---
    private var nextSwallowTime: TimeInterval = 0
    private var swallowPhase: Float = -1 // -1 = not swallowing
    
    // --- Asymmetry ---
    // Left side shows ~5-10% more emotional intensity (research: right hemisphere → left face)
    private let leftEmotionBias: Float = 1.08
    
    // MARK: - Init / Lifecycle
    
    public init() {
        scheduleNextBlink(from: 0)
        scheduleNextSaccade(from: 0)
        nextMicroExpressionTime = Double.random(in: 3...8)
        nextSwallowTime = Double.random(in: 60...180)
    }
    
    public func start() {
        guard displayLink == nil else { return }
        startTime = CACurrentMediaTime()
        lastTime = startTime
        displayLink = CADisplayLink(target: self, selector: #selector(tick))
        displayLink?.preferredFrameRateRange = CAFrameRateRange(minimum: 30, maximum: 60, preferred: 60)
        displayLink?.add(to: .main, forMode: .common)
    }
    
    public func stop() {
        displayLink?.invalidate()
        displayLink = nil
    }
    
    public var isRunning: Bool { displayLink != nil }
    
    deinit { stop() }
    
    // MARK: - Main Loop
    
    @objc private func tick() {
        let now = CACurrentMediaTime()
        let dt = Float(now - lastTime)
        lastTime = now
        let elapsed = Float(now - startTime)
        
        guard dt > 0, dt < 0.5 else { return }
        
        // Smooth inputs
        smoothedEnergy += (audioEnergy - smoothedEnergy) * min(dt * 8, 1)
        prevSmoothedPitch = smoothedPitch
        if audioPitch > 0 {
            smoothedPitch += (audioPitch - smoothedPitch) * min(dt * 5, 1)
        }
        
        var bs: [String: Float] = [:]
        var headPitch: Float = 0
        var headYaw: Float = 0
        var headRoll: Float = 0
        
        // ═══════════════════════════════════════════
        // Layer 1: Breathing
        // Research: 12-20 breaths/min, speaking suppresses visible breathing
        // ═══════════════════════════════════════════
        if breathingEnabled {
            // Speaking: breathing is driven by speech, suppress idle breathing animation
            let breathVisible: Float = isSpeaking ? 0.15 : 0.6
            let rate: Float = isSpeaking ? 0.6 : 1.0
            breathPhase += dt * rate * 2 * .pi / 3.8
            if breathPhase > 2 * .pi { breathPhase -= 2 * .pi }
            
            let breathAmount = sin(breathPhase) * 0.5 + 0.5
            let depth = breathVisible * breathDepthVariation
            
            bs["jawOpen"] = (bs["jawOpen"] ?? 0) + breathAmount * 0.02 * depth
            // Chest/shoulder rise implied by head micro-tilt
            headPitch += sin(breathPhase) * 0.25 * depth
            
            // Breath depth variation (not every breath is the same)
            if now > nextBreathVariationTime {
                breathDepthVariation = Float.random(in: 0.6...1.4)
                nextBreathVariationTime = now + Double.random(in: 6...12)
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 2: Eye Blinks
        // Research: close 80ms (fast), hold 50ms, open 200ms (slow)
        // Listening: blink rate DECREASES (cognitive load)
        // Speaking: blink rate slightly INCREASES
        // ═══════════════════════════════════════════
        if blinkEnabled {
            let blinkValue = updateBlink(now: now)
            if blinkValue > 0 {
                bs["eyeBlinkLeft"] = blinkValue
                bs["eyeBlinkRight"] = blinkValue
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 3: Eye Saccades
        // Research: ballistic jumps 200-800ms apart, ±0.3-1.0°
        // ═══════════════════════════════════════════
        if saccadeEnabled {
            updateSaccade(now: now, dt: dt)
            if abs(saccadeCurrent.x) > 0.001 || abs(saccadeCurrent.y) > 0.001 {
                if saccadeCurrent.x > 0 {
                    bs["eyeLookOutLeft"] = saccadeCurrent.x * 0.3
                    bs["eyeLookInRight"] = saccadeCurrent.x * 0.3
                } else {
                    bs["eyeLookInLeft"] = -saccadeCurrent.x * 0.3
                    bs["eyeLookOutRight"] = -saccadeCurrent.x * 0.3
                }
                if saccadeCurrent.y > 0 {
                    bs["eyeLookUpLeft"] = saccadeCurrent.y * 0.2
                    bs["eyeLookUpRight"] = saccadeCurrent.y * 0.2
                } else {
                    bs["eyeLookDownLeft"] = -saccadeCurrent.y * 0.2
                    bs["eyeLookDownRight"] = -saccadeCurrent.y * 0.2
                }
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 4: Head Micro-Movement
        // Research (Koç ICASSP): prosody-linked head motion
        //   - Emphasis → nod, pitch rise → head raise, pause → tilt
        // ═══════════════════════════════════════════
        if headMotionEnabled {
            let speed: Float = isSpeaking ? 0.6 : (isListening ? 0.4 : 0.3)
            let amplitude: Float
            if isSpeaking {
                amplitude = 1.5 + smoothedEnergy * 3.0
            } else if isListening {
                amplitude = 1.0 // slightly more than idle, less than speaking
            } else {
                amplitude = 0.8
            }
            
            headYaw  += headNoiseX.sample(t: elapsed * speed) * amplitude
            headPitch += headNoiseY.sample(t: elapsed * speed * 0.7) * amplitude * 0.6
            headRoll += headNoiseZ.sample(t: elapsed * speed * 0.5) * amplitude * 0.3
            
            // Prosody-driven: energy peaks → nod down
            if isSpeaking && smoothedEnergy > 0.15 {
                let nodAmount = (smoothedEnergy - 0.15) * 4.0
                headPitch -= nodAmount
            }
            
            // Prosody-driven: pitch contour → head tilt
            // Rising pitch → head raises slightly, falling → lowers
            if isSpeaking && smoothedPitch > 0 {
                let pitchDelta = smoothedPitch - prevSmoothedPitch
                let pitchInfluence = pitchDelta * 0.01 // subtle
                headPitch -= pitchInfluence // rising pitch → head up (negative pitch = up)
                headRoll += pitchInfluence * 0.5 // slight roll with pitch change
            }
            
            // Listening: slight forward lean (interest signal)
            if isListening {
                headPitch -= 1.5 // subtle forward lean
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 5: Mood Expression Overlay
        // ═══════════════════════════════════════════
        if expressionEnabled {
            updateMood(dt: dt)
            for (key, value) in moodBlendshapes {
                bs[key] = (bs[key] ?? 0) + value * moodTransitionProgress
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 6: Micro-Expressions (FACS three-phase timing)
        // Research: onset 200-500ms, apex 200-500ms, offset 300-800ms
        // Onset FAST + offset SLOW = natural
        // ═══════════════════════════════════════════
        if microExpressionEnabled {
            let microIntensity = updateMicroExpression(now: now)
            if microIntensity > 0.01 {
                for (key, value) in microExpressionBS {
                    // Apply left-side emotional bias
                    var adjusted = value * microIntensity
                    if key.hasSuffix("Left") {
                        adjusted *= leftEmotionBias
                    }
                    bs[key] = (bs[key] ?? 0) + adjusted
                }
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 7: Facial Asymmetry
        // Research: left side more emotionally expressive (right hemisphere)
        // Continuous subtle asymmetry, not just on micro-expressions
        // ═══════════════════════════════════════════
        let browAsymmetry = headNoiseX.sample(t: elapsed * 0.15) * 0.06
        if browAsymmetry > 0.01 {
            bs["browOuterUpLeft"] = (bs["browOuterUpLeft"] ?? 0) + browAsymmetry
        } else if browAsymmetry < -0.01 {
            bs["browOuterUpRight"] = (bs["browOuterUpRight"] ?? 0) - browAsymmetry
        }
        
        // Mouth asymmetry (very subtle)
        let mouthAsymmetry = headNoiseZ.sample(t: elapsed * 0.12) * 0.03
        if abs(mouthAsymmetry) > 0.005 {
            if mouthAsymmetry > 0 {
                bs["mouthSmileLeft"] = (bs["mouthSmileLeft"] ?? 0) + mouthAsymmetry
            } else {
                bs["mouthSmileRight"] = (bs["mouthSmileRight"] ?? 0) - mouthAsymmetry
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 8: Swallow (every 2-3 minutes)
        // Research: 18-400/hour, average ~every 2-3 min
        // Visible as: jaw micro-close + slight head dip
        // ═══════════════════════════════════════════
        if swallowEnabled {
            updateSwallow(now: now, dt: dt, bs: &bs, headPitch: &headPitch)
        }
        
        // ═══════════════════════════════════════════
        // Layer 9: Speaking-specific mouth details
        // Research: lip press between phrases, lip lick when thinking
        // ═══════════════════════════════════════════
        if isSpeaking {
            // Between-phrase lip press (when energy drops briefly)
            if smoothedEnergy < 0.05 {
                bs["mouthPressLeft"] = (bs["mouthPressLeft"] ?? 0) + 0.08
                bs["mouthPressRight"] = (bs["mouthPressRight"] ?? 0) + 0.08
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 10: Secondary actions (Disney principle)
        // When smiling: cheeks rise, eyes narrow, nose widens
        // ═══════════════════════════════════════════
        let smileAmount = max(bs["mouthSmileLeft"] ?? 0, bs["mouthSmileRight"] ?? 0)
        if smileAmount > 0.05 {
            // Duchenne markers: cheek squint + eye narrow
            bs["cheekSquintLeft"] = (bs["cheekSquintLeft"] ?? 0) + smileAmount * 0.5
            bs["cheekSquintRight"] = (bs["cheekSquintRight"] ?? 0) + smileAmount * 0.5
            bs["eyeSquintLeft"] = (bs["eyeSquintLeft"] ?? 0) + smileAmount * 0.3
            bs["eyeSquintRight"] = (bs["eyeSquintRight"] ?? 0) + smileAmount * 0.3
            bs["noseSneerLeft"] = (bs["noseSneerLeft"] ?? 0) + smileAmount * 0.1
            bs["noseSneerRight"] = (bs["noseSneerRight"] ?? 0) + smileAmount * 0.1
        }
        
        // Frown secondary: inner brow raise
        let frownAmount = max(bs["mouthFrownLeft"] ?? 0, bs["mouthFrownRight"] ?? 0)
        if frownAmount > 0.05 {
            bs["browInnerUp"] = (bs["browInnerUp"] ?? 0) + frownAmount * 0.4
        }
        
        // Apply master intensity
        if intensity != 1.0 {
            for key in bs.keys { bs[key]! *= intensity }
            headYaw *= intensity
            headPitch *= intensity
            headRoll *= intensity
        }
        
        // Convert to quaternion
        let rad = Float.pi / 180.0
        let qPitch = simd_quatf(angle: headPitch * rad, axis: SIMD3(1, 0, 0))
        let qYaw   = simd_quatf(angle: headYaw * rad, axis: SIMD3(0, 1, 0))
        let qRoll  = simd_quatf(angle: headRoll * rad, axis: SIMD3(0, 0, 1))
        
        onFrame?(bs, qYaw * qPitch * qRoll)
    }
    
    // MARK: - Blink System
    
    private enum BlinkPhase {
        case open
        case closing  // 80ms (fast — research confirmed)
        case closed   // 50ms hold
        case opening  // 200ms (slow — asymmetric timing is key to realism)
    }
    
    private func updateBlink(now: TimeInterval) -> Float {
        switch blinkPhase {
        case .open:
            if now >= nextBlinkTime {
                blinkPhase = .closing
                blinkPhaseStart = now
            }
            return 0
        case .closing:
            let t = Float(now - blinkPhaseStart) / 0.08
            if t >= 1.0 {
                blinkPhase = .closed
                blinkPhaseStart = now
                return 1.0
            }
            return easeIn(t)
        case .closed:
            if Float(now - blinkPhaseStart) >= 0.05 {
                blinkPhase = .opening
                blinkPhaseStart = now
            }
            return 1.0
        case .opening:
            let t = Float(now - blinkPhaseStart) / 0.20
            if t >= 1.0 {
                blinkPhase = .open
                scheduleNextBlink(from: now)
                return 0
            }
            return 1.0 - easeOut(t)
        }
    }
    
    private func scheduleNextBlink(from time: TimeInterval) {
        // Research: listening → blink rate DECREASES (cognitive load)
        // Speaking → slightly increases. Idle → baseline ~4s
        let mean: Double
        if isListening {
            mean = 5.5 // less frequent when concentrating on listening
        } else if isSpeaking {
            mean = 3.5 // slightly more frequent when speaking
        } else {
            mean = 4.0 // baseline
        }
        let variance: Double = 2.0
        let u1 = Double.random(in: 0.001...1.0)
        let u2 = Double.random(in: 0.001...1.0)
        let gaussian = sqrt(-2.0 * log(u1)) * cos(2.0 * .pi * u2)
        nextBlinkTime = time + max(1.5, mean + gaussian * variance)
    }
    
    // MARK: - Saccade System
    
    private func updateSaccade(now: TimeInterval, dt: Float) {
        if now >= nextSaccadeTime {
            saccadeTarget = SIMD2(
                Float.random(in: -0.6...0.6),
                Float.random(in: -0.3...0.3)
            )
            scheduleNextSaccade(from: now)
        }
        let saccadeSpeed: Float = 15.0
        saccadeCurrent += (saccadeTarget - saccadeCurrent) * min(dt * saccadeSpeed, 1.0)
    }
    
    private func scheduleNextSaccade(from time: TimeInterval) {
        let mean: Double = isSpeaking ? 0.5 : (isListening ? 1.0 : 0.8)
        let interval = -mean * log(Double.random(in: 0.001...1.0))
        nextSaccadeTime = time + max(0.2, min(interval, 3.0))
    }
    
    // MARK: - Micro-Expression System (FACS three-phase)
    
    private enum MicroExprPhase {
        case idle
        case onset   // fast rise (200-500ms)
        case apex    // hold (200-500ms)
        case offset  // slow decay (300-800ms) — SLOWER than onset = natural
    }
    
    private func updateMicroExpression(now: TimeInterval) -> Float {
        switch microExpressionPhase {
        case .idle:
            if now >= nextMicroExpressionTime {
                triggerMicroExpression()
                microExpressionPhase = .onset
                microExprPhaseStart = now
                // Randomize durations per FACS research
                microExprOnsetDuration = Float.random(in: 0.15...0.35)
                microExprApexDuration = Float.random(in: 0.2...0.5)
                microExprOffsetDuration = Float.random(in: 0.3...0.7) // slower than onset!
            }
            return 0
            
        case .onset:
            let t = Float(now - microExprPhaseStart) / microExprOnsetDuration
            if t >= 1.0 {
                microExpressionPhase = .apex
                microExprPhaseStart = now
                return 1.0
            }
            return easeOut(t) // fast rise
            
        case .apex:
            if Float(now - microExprPhaseStart) >= microExprApexDuration {
                microExpressionPhase = .offset
                microExprPhaseStart = now
            }
            return 1.0
            
        case .offset:
            let t = Float(now - microExprPhaseStart) / microExprOffsetDuration
            if t >= 1.0 {
                microExpressionPhase = .idle
                microExpressionBS = [:]
                nextMicroExpressionTime = now + Double.random(in: 4...12)
                return 0
            }
            return 1.0 - easeIn(t) // slow decay
        }
    }
    
    private func triggerMicroExpression() {
        let type = Int.random(in: 0...9)
        switch type {
        case 0: // Asymmetric lip corner pull
            let side = Bool.random()
            microExpressionBS = [
                side ? "mouthSmileLeft" : "mouthSmileRight": 0.15,
                side ? "cheekSquintLeft" : "cheekSquintRight": 0.08,
            ]
        case 1: // Brow flash (universal greeting/emphasis signal)
            microExpressionBS = [
                "browOuterUpLeft": 0.2, "browOuterUpRight": 0.2,
                "browInnerUp": 0.1,
            ]
        case 2: // Nostril flare
            microExpressionBS = [
                "noseSneerLeft": 0.1, "noseSneerRight": 0.1,
            ]
        case 3: // Lip press (thinking)
            microExpressionBS = [
                "mouthPressLeft": 0.15, "mouthPressRight": 0.15,
                "mouthClose": 0.1,
            ]
        case 4: // Single brow raise
            let side = Bool.random()
            microExpressionBS = [
                side ? "browOuterUpLeft" : "browOuterUpRight": 0.2,
            ]
        case 5: // Slight squint
            microExpressionBS = [
                "eyeSquintLeft": 0.12, "eyeSquintRight": 0.12,
            ]
        case 6: // Mouth corner tighten (dimple)
            microExpressionBS = [
                "mouthDimpleLeft": 0.1, "mouthDimpleRight": 0.1,
            ]
        case 7: // Jaw shift
            microExpressionBS = [
                Bool.random() ? "jawLeft" : "jawRight": 0.05,
            ]
        case 8: // Lip roll (thinking/processing)
            microExpressionBS = [
                "mouthRollLower": 0.12,
            ]
        default: // Cheek puff (very subtle, very human)
            microExpressionBS = [
                "cheekPuff": 0.08,
            ]
        }
    }
    
    // MARK: - Swallow System
    
    private func updateSwallow(now: TimeInterval, dt: Float,
                               bs: inout [String: Float], headPitch: inout Float) {
        if swallowPhase < 0 {
            if now >= nextSwallowTime {
                swallowPhase = 0
                nextSwallowTime = now + Double.random(in: 90...200)
            }
            return
        }
        
        // Swallow animation: ~0.6s total
        // Phase 0-0.2: jaw closes slightly
        // Phase 0.2-0.4: throat movement (head dips)
        // Phase 0.4-0.6: return to normal
        swallowPhase += dt / 0.6
        
        if swallowPhase >= 1.0 {
            swallowPhase = -1
            return
        }
        
        let p = swallowPhase
        if p < 0.33 {
            let t = p / 0.33
            bs["jawOpen"] = (bs["jawOpen"] ?? 0) - 0.03 * easeIn(t)
            bs["mouthClose"] = (bs["mouthClose"] ?? 0) + 0.1 * easeIn(t)
        } else if p < 0.66 {
            let t = (p - 0.33) / 0.33
            headPitch += sin(t * .pi) * 1.2 // subtle head dip
            bs["mouthClose"] = (bs["mouthClose"] ?? 0) + 0.1 * (1.0 - t)
        } else {
            // Return to normal — handled by values going to 0
        }
    }
    
    // MARK: - Mood System
    
    public enum Mood {
        case neutral, happy, thinking, surprised, concerned
    }
    
    public func setMood(_ mood: Mood) {
        guard mood != currentMood else { return }
        currentMood = mood
        moodTransitionProgress = 0
        
        switch mood {
        case .neutral:
            moodBlendshapes = [:]
        case .happy:
            moodBlendshapes = [
                "mouthSmileLeft": 0.15, "mouthSmileRight": 0.15,
                "cheekSquintLeft": 0.1, "cheekSquintRight": 0.1,
            ]
        case .thinking:
            moodBlendshapes = [
                "browInnerUp": 0.15,
                "eyeSquintLeft": 0.1, "eyeSquintRight": 0.1,
                "mouthPucker": 0.05,
                "mouthRollLower": 0.06, // lip roll — thinking gesture
            ]
        case .surprised:
            moodBlendshapes = [
                "eyeWideLeft": 0.2, "eyeWideRight": 0.2,
                "browOuterUpLeft": 0.15, "browOuterUpRight": 0.15,
                "jawOpen": 0.05,
            ]
        case .concerned:
            moodBlendshapes = [
                "browInnerUp": 0.2,
                "mouthFrownLeft": 0.1, "mouthFrownRight": 0.1,
            ]
        }
    }
    
    private func updateMood(dt: Float) {
        if moodTransitionProgress < 1.0 {
            moodTransitionProgress = min(1.0, moodTransitionProgress + dt * 2.0)
        }
    }
    
    // MARK: - Perlin-like Smooth Noise
    
    struct PerlinOctave {
        let freq1 = Float.random(in: 0.8...1.2)
        let freq2 = Float.random(in: 1.8...2.5)
        let freq3 = Float.random(in: 3.5...4.5)
        let phase1 = Float.random(in: 0...(2 * .pi))
        let phase2 = Float.random(in: 0...(2 * .pi))
        let phase3 = Float.random(in: 0...(2 * .pi))
        
        func sample(t: Float) -> Float {
            sin(t * freq1 + phase1) * 0.6
            + sin(t * freq2 + phase2) * 0.3
            + sin(t * freq3 + phase3) * 0.1
        }
    }
    
    // MARK: - Easing
    
    private func easeIn(_ t: Float) -> Float { t * t }
    private func easeOut(_ t: Float) -> Float { 1.0 - (1.0 - t) * (1.0 - t) }
}
