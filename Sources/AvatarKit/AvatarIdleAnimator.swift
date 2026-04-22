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
    public var onFrame: ((_ blendshapes: [String: Float], _ headRotation: simd_quatf, _ headTranslation: SIMD3<Float>) -> Void)?
    
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
    
    // --- Weight Shift (Disney: natural sway, 4-8s cycle) ---
    private var weightShiftNoise = PerlinOctave()
    private var weightShiftPhase: Float = 0
    
    // --- Pose Variation (fidgets + pose changes every 15-30s) ---
    private var nextFidgetTime: TimeInterval = 0
    private var fidgetPhase: Float = -1
    private var fidgetType: Int = 0
    private var fidgetBS: [String: Float] = [:]
    
    // --- Head Translation (spatial movement, not just rotation) ---
    private var headTranslationNoise = (x: PerlinOctave(), y: PerlinOctave(), z: PerlinOctave())
    
    // MARK: - Init / Lifecycle
    
    public init() {
        scheduleNextBlink(from: 0)
        scheduleNextSaccade(from: 0)
        nextMicroExpressionTime = Double.random(in: 3...8)
        nextSwallowTime = Double.random(in: 60...180)
        nextFidgetTime = Double.random(in: 15...30)
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
        if startTime == 0 { startTime = now; lastTime = now }
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
        var headTx: Float = 0  // translation X (left/right)
        var headTy: Float = 0  // translation Y (up/down)
        var headTz: Float = 0  // translation Z (forward/back)
        
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
                amplitude = 3.0 + smoothedEnergy * 5.0  // much more expressive when speaking
            } else if isListening {
                amplitude = 2.0
            } else {
                amplitude = 2.5  // idle: ±2-5° (research: real humans)
            }
            
            headYaw  += headNoiseX.sample(t: elapsed * speed) * amplitude
            headPitch += headNoiseY.sample(t: elapsed * speed * 0.7) * amplitude * 0.6
            headRoll += headNoiseZ.sample(t: elapsed * speed * 0.5) * amplitude * 0.3
            
            // ═══════════════════════════════════════════
            // Layer 4b: Head Translation (spatial movement)
            // Disney: characters move IN SPACE, not just rotate
            // Weight shift causes head to drift laterally
            // Breathing causes slight vertical bob
            // ═══════════════════════════════════════════
            let txSpeed: Float = isSpeaking ? 0.4 : 0.2
            let txAmp: Float = isSpeaking ? 0.008 : 0.005  // meters
            headTx += headTranslationNoise.x.sample(t: elapsed * txSpeed) * txAmp
            headTy += sin(breathPhase) * 0.002  // breathing bob
            headTy += headTranslationNoise.y.sample(t: elapsed * txSpeed * 0.5) * txAmp * 0.3
            headTz += headTranslationNoise.z.sample(t: elapsed * txSpeed * 0.7) * txAmp * 0.5
            
            // ═══════════════════════════════════════════
            // Layer 4c: Weight Shift (Disney: natural sway)
            // 4-8 second cycle, lateral drift + slight roll
            // MoCap Online: "subtle weight transfer foot to foot"
            // ═══════════════════════════════════════════
            weightShiftPhase += dt * 2 * .pi / 6.0  // ~6 second cycle
            if weightShiftPhase > 2 * .pi { weightShiftPhase -= 2 * .pi }
            let swayAmount = sin(weightShiftPhase) * 0.4 + weightShiftNoise.sample(t: elapsed * 0.15) * 0.2
            headTx += swayAmount * 0.004  // lateral drift from weight shift
            headRoll += swayAmount * 0.8   // body roll follows weight shift
            headYaw += swayAmount * 0.3    // slight yaw with sway
            
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
            // Speaking head translation: lean forward slightly when emphasizing
            if smoothedEnergy > 0.2 {
                headTz -= (smoothedEnergy - 0.2) * 0.01  // lean forward on emphasis
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 9b: Fidgets (Disney: break monotony)
        // MoCap Online: "short one-shot animations every 30-60 seconds"
        // Examples: shoulder roll, head scratch, look around, stretch
        // ═══════════════════════════════════════════
        if !isSpeaking {
            updateFidget(now: now, dt: dt, bs: &bs, headYaw: &headYaw, headPitch: &headPitch, headRoll: &headRoll, headTx: &headTx)
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
            headTx *= intensity
            headTy *= intensity
            headTz *= intensity
        }
        
        // Convert to quaternion
        let rad = Float.pi / 180.0
        let qPitch = simd_quatf(angle: headPitch * rad, axis: SIMD3(1, 0, 0))
        let qYaw   = simd_quatf(angle: headYaw * rad, axis: SIMD3(0, 1, 0))
        let qRoll  = simd_quatf(angle: headRoll * rad, axis: SIMD3(0, 0, 1))
        
        onFrame?(bs, qYaw * qPitch * qRoll, SIMD3(headTx, headTy, headTz))
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
    
    // MARK: - Fidget System (Disney: break monotony)
    
    private func updateFidget(now: TimeInterval, dt: Float,
                              bs: inout [String: Float],
                              headYaw: inout Float, headPitch: inout Float,
                              headRoll: inout Float, headTx: inout Float) {
        if fidgetPhase < 0 {
            if now >= nextFidgetTime {
                fidgetPhase = 0
                fidgetType = Int.random(in: 0...6)
                nextFidgetTime = now + Double.random(in: 20...45)
            }
            return
        }
        
        let duration: Float
        switch fidgetType {
        case 0: duration = 1.5  // look to side
        case 1: duration = 1.2  // shoulder roll (head tilt)
        case 2: duration = 2.0  // big head turn and back
        case 3: duration = 1.0  // quick glance up
        case 4: duration = 1.8  // lean back then forward
        case 5: duration = 1.5  // head tilt with brow
        default: duration = 1.3 // jaw stretch
        }
        
        fidgetPhase += dt / duration
        if fidgetPhase >= 1.0 {
            fidgetPhase = -1
            return
        }
        
        let p = fidgetPhase
        // Bell curve envelope: smooth in, peak at 0.4, smooth out
        let envelope = sin(p * .pi) * (p < 0.4 ? easeOut(p / 0.4) : 1.0)
        
        switch fidgetType {
        case 0: // Look to one side — big yaw turn
            let dir: Float = Bool.random() ? 1 : -1
            headYaw += dir * envelope * 8.0
            headTx += dir * envelope * 0.006
            // Eyes lead the head (overlapping action)
            let eyeLead = sin(min(p * 1.3, 1.0) * .pi)
            if dir > 0 {
                bs["eyeLookOutRight"] = (bs["eyeLookOutRight"] ?? 0) + eyeLead * 0.3
                bs["eyeLookInLeft"] = (bs["eyeLookInLeft"] ?? 0) + eyeLead * 0.3
            } else {
                bs["eyeLookOutLeft"] = (bs["eyeLookOutLeft"] ?? 0) + eyeLead * 0.3
                bs["eyeLookInRight"] = (bs["eyeLookInRight"] ?? 0) + eyeLead * 0.3
            }
            
        case 1: // Shoulder roll — head tilts, slight roll
            let dir: Float = Bool.random() ? 1 : -1
            headRoll += dir * envelope * 5.0
            headPitch += envelope * 2.0
            headTx += dir * envelope * 0.004
            
        case 2: // Big head turn and back — like checking something
            let dir: Float = Bool.random() ? 1 : -1
            // Anticipation: slight opposite move first
            let antic = p < 0.15 ? -sin(p / 0.15 * .pi) * 0.3 : 0.0
            headYaw += dir * (envelope * 12.0 + antic * 3.0)
            headPitch -= envelope * 3.0  // chin dips slightly during turn
            headTx += dir * envelope * 0.008
            
        case 3: // Quick glance up
            headPitch -= envelope * 6.0
            bs["eyeLookUpLeft"] = (bs["eyeLookUpLeft"] ?? 0) + envelope * 0.4
            bs["eyeLookUpRight"] = (bs["eyeLookUpRight"] ?? 0) + envelope * 0.4
            bs["browOuterUpLeft"] = (bs["browOuterUpLeft"] ?? 0) + envelope * 0.15
            bs["browOuterUpRight"] = (bs["browOuterUpRight"] ?? 0) + envelope * 0.15
            
        case 4: // Lean back then forward
            let leanCurve = sin(p * 2 * .pi)  // full cycle: back then forward
            headPitch += leanCurve * 4.0
            headTx += -leanCurve * 0.003  // slight Z shift (mapped to X for now)
            
        case 5: // Head tilt with curious brow
            let dir: Float = Bool.random() ? 1 : -1
            headRoll += dir * envelope * 7.0
            headPitch -= envelope * 2.0
            bs["browInnerUp"] = (bs["browInnerUp"] ?? 0) + envelope * 0.2
            let browSide = dir > 0 ? "browOuterUpRight" : "browOuterUpLeft"
            bs[browSide] = (bs[browSide] ?? 0) + envelope * 0.15
            
        default: // Jaw stretch / mouth movement
            bs["jawOpen"] = (bs["jawOpen"] ?? 0) + envelope * 0.15
            bs["mouthStretchLeft"] = (bs["mouthStretchLeft"] ?? 0) + envelope * 0.1
            bs["mouthStretchRight"] = (bs["mouthStretchRight"] ?? 0) + envelope * 0.1
            headPitch += envelope * 2.0  // head tilts back slightly
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
