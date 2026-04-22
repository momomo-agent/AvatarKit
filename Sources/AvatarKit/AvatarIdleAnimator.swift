import Foundation
import QuartzCore
import simd

// MARK: - Idle Animator

/// Generates natural idle motion: breathing, eye blinks, micro head movement,
/// and speaking-aware expression overlays.
///
/// Based on research from:
/// - USC ICT: Neurobiological model of visual attention (Lee et al. 2002)
/// - Disney Research: Modeling and Animating Eye Blinks
/// - AnimSchool: Breathing Life into Idle Animations
/// - NVIDIA Audio2Face: Emotion-driven expression layering
///
/// Key parameters from literature:
/// - Blink interval: 2-10s (mean ~4s), duration ~150ms (close) + ~250ms (open)
/// - Saccade interval: exponential distribution, mean ~350ms during conversation
/// - Breathing cycle: 12-20 breaths/min (3-5s per cycle)
/// - Head micro-movement: ±2-5° during speech, ±1-2° during idle
public class AvatarIdleAnimator {
    
    // MARK: - Configuration
    
    /// Master intensity (0 = off, 1 = full). Affects all idle layers.
    public var intensity: Float = 1.0
    
    /// Enable/disable individual layers.
    public var blinkEnabled = true
    public var breathingEnabled = true
    public var headMotionEnabled = true
    public var expressionEnabled = true
    public var saccadeEnabled = true
    
    /// Whether the character is currently speaking.
    /// When true: blink rate decreases, head motion increases, breathing adapts.
    public var isSpeaking = false
    
    /// Audio energy (RMS amplitude, 0-1). Drives head motion intensity during speech.
    /// Feed this from AvatarLipSync's audio analysis or your own audio tap.
    public var audioEnergy: Float = 0
    
    /// Called every frame with idle blendshapes to merge into tracking.
    /// These should be ADDED to lip sync blendshapes, not replace them.
    public var onFrame: ((_ blendshapes: [String: Float], _ headRotation: simd_quatf) -> Void)?
    
    // MARK: - State
    
    private var displayLink: CADisplayLink?
    private var startTime: TimeInterval = 0
    private var lastTime: TimeInterval = 0
    
    // Blink state
    private var nextBlinkTime: TimeInterval = 0
    private var blinkPhase: BlinkPhase = .open
    private var blinkPhaseStart: TimeInterval = 0
    
    // Breathing state
    private var breathPhase: Float = 0 // 0-2π
    
    // Head motion (Perlin-like smooth noise)
    private var headNoiseX = PerlinOctave()
    private var headNoiseY = PerlinOctave()
    private var headNoiseZ = PerlinOctave()
    
    // Saccade state
    private var nextSaccadeTime: TimeInterval = 0
    private var saccadeTarget: SIMD2<Float> = .zero
    private var saccadeCurrent: SIMD2<Float> = .zero
    
    // Expression state
    private var currentMood: Mood = .neutral
    private var moodBlendshapes: [String: Float] = [:]
    private var moodTransitionProgress: Float = 1.0
    
    // Audio energy smoothing
    private var smoothedEnergy: Float = 0
    
    // Asymmetric micro-expressions (Disney-level detail)
    private var nextMicroExpressionTime: TimeInterval = 0
    private var microExpressionBS: [String: Float] = [:]
    private var microExpressionDecay: Float = 0
    
    // Asymmetric blink (occasional single-eye squint)
    private var asymmetricBlinkSide: Int = 0 // 0=both, 1=left heavier, 2=right heavier
    
    // Breathing variation
    private var breathDepthVariation: Float = 1.0
    private var nextBreathVariationTime: TimeInterval = 0
    
    // MARK: - Init / Lifecycle
    
    public init() {
        scheduleNextBlink(from: 0)
        scheduleNextSaccade(from: 0)
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
        
        guard dt > 0, dt < 0.5 else { return } // skip huge gaps
        
        // Smooth audio energy
        smoothedEnergy += (audioEnergy - smoothedEnergy) * min(dt * 8, 1)
        
        var blendshapes: [String: Float] = [:]
        var headPitch: Float = 0
        var headYaw: Float = 0
        var headRoll: Float = 0
        
        // --- Layer 1: Breathing ---
        if breathingEnabled {
            let rate: Float = isSpeaking ? 0.8 : 1.2 // faster when speaking
            breathPhase += dt * rate * 2 * .pi / 3.5 // ~3.5s per cycle
            if breathPhase > 2 * .pi { breathPhase -= 2 * .pi }
            
            // Sinusoidal chest rise: jawOpen micro-movement + slight head tilt
            let breathAmount = sin(breathPhase) * 0.5 + 0.5 // 0-1
            let breathIntensity: Float = (isSpeaking ? 0.3 : 0.6) * breathDepthVariation
            
            blendshapes["jawOpen"] = (blendshapes["jawOpen"] ?? 0) + breathAmount * 0.02 * breathIntensity
            headPitch += sin(breathPhase) * 0.3 * breathIntensity // subtle nod with breath
        }
        
        // --- Layer 2: Eye Blinks ---
        if blinkEnabled {
            let blinkValue = updateBlink(now: now)
            if blinkValue > 0 {
                blendshapes["eyeBlinkLeft"] = blinkValue
                blendshapes["eyeBlinkRight"] = blinkValue
            }
        }
        
        // --- Layer 3: Eye Saccades ---
        if saccadeEnabled {
            updateSaccade(now: now, dt: dt)
            if abs(saccadeCurrent.x) > 0.001 || abs(saccadeCurrent.y) > 0.001 {
                // Map saccade to eye look blendshapes
                if saccadeCurrent.x > 0 {
                    blendshapes["eyeLookOutLeft"] = saccadeCurrent.x * 0.3
                    blendshapes["eyeLookInRight"] = saccadeCurrent.x * 0.3
                } else {
                    blendshapes["eyeLookInLeft"] = -saccadeCurrent.x * 0.3
                    blendshapes["eyeLookOutRight"] = -saccadeCurrent.x * 0.3
                }
                if saccadeCurrent.y > 0 {
                    blendshapes["eyeLookUpLeft"] = saccadeCurrent.y * 0.2
                    blendshapes["eyeLookUpRight"] = saccadeCurrent.y * 0.2
                } else {
                    blendshapes["eyeLookDownLeft"] = -saccadeCurrent.y * 0.2
                    blendshapes["eyeLookDownRight"] = -saccadeCurrent.y * 0.2
                }
            }
        }
        
        // --- Layer 4: Head Micro-Movement ---
        if headMotionEnabled {
            let speed: Float = isSpeaking ? 0.6 : 0.3
            let amplitude: Float = isSpeaking
                ? 1.5 + smoothedEnergy * 3.0  // ±1.5-4.5° when speaking
                : 0.8                           // ±0.8° when idle
            
            headYaw  += headNoiseX.sample(t: elapsed * speed) * amplitude
            headPitch += headNoiseY.sample(t: elapsed * speed * 0.7) * amplitude * 0.6
            headRoll += headNoiseZ.sample(t: elapsed * speed * 0.5) * amplitude * 0.3
            
            // Speaking emphasis: nod on energy peaks
            if isSpeaking && smoothedEnergy > 0.15 {
                let nodAmount = (smoothedEnergy - 0.15) * 4.0 // 0-3.4°
                headPitch -= nodAmount // nod down on emphasis
            }
        }
        
        // --- Layer 5: Expression Overlay ---
        if expressionEnabled {
            updateMood(dt: dt)
            for (key, value) in moodBlendshapes {
                blendshapes[key] = (blendshapes[key] ?? 0) + value * moodTransitionProgress
            }
        }
        
        // --- Layer 6: Micro-Expressions (Disney detail) ---
        updateMicroExpressions(now: now, dt: dt)
        if microExpressionDecay > 0.01 {
            for (key, value) in microExpressionBS {
                blendshapes[key] = (blendshapes[key] ?? 0) + value * microExpressionDecay
            }
        }
        
        // --- Layer 7: Asymmetric Brow Movement ---
        // Subtle asymmetry makes faces look alive (humans are never perfectly symmetric)
        let asymmetry = headNoiseX.sample(t: elapsed * 0.15) * 0.08
        if abs(asymmetry) > 0.01 {
            if asymmetry > 0 {
                blendshapes["browOuterUpLeft"] = (blendshapes["browOuterUpLeft"] ?? 0) + asymmetry
            } else {
                blendshapes["browOuterUpRight"] = (blendshapes["browOuterUpRight"] ?? 0) - asymmetry
            }
        }
        
        // --- Layer 8: Breathing Depth Variation ---
        if now > nextBreathVariationTime {
            breathDepthVariation = Float.random(in: 0.7...1.3)
            nextBreathVariationTime = now + Double.random(in: 8...15)
        }
        
        // Apply master intensity
        if intensity != 1.0 {
            for key in blendshapes.keys {
                blendshapes[key]! *= intensity
            }
            headYaw *= intensity
            headPitch *= intensity
            headRoll *= intensity
        }
        
        // Convert head angles to quaternion (degrees → radians)
        let rad = Float.pi / 180.0
        let qPitch = simd_quatf(angle: headPitch * rad, axis: SIMD3(1, 0, 0))
        let qYaw   = simd_quatf(angle: headYaw * rad, axis: SIMD3(0, 1, 0))
        let qRoll  = simd_quatf(angle: headRoll * rad, axis: SIMD3(0, 0, 1))
        let headRotation = qYaw * qPitch * qRoll
        
        onFrame?(blendshapes, headRotation)
    }
    
    // MARK: - Blink System
    
    private enum BlinkPhase {
        case open
        case closing  // ~80ms
        case closed   // ~50ms
        case opening  // ~200ms
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
            let t = Float(now - blinkPhaseStart) / 0.08 // 80ms close
            if t >= 1.0 {
                blinkPhase = .closed
                blinkPhaseStart = now
                return 1.0
            }
            return easeIn(t)
            
        case .closed:
            let holdDuration: Float = 0.05 // 50ms hold
            if Float(now - blinkPhaseStart) >= holdDuration {
                blinkPhase = .opening
                blinkPhaseStart = now
            }
            return 1.0
            
        case .opening:
            let t = Float(now - blinkPhaseStart) / 0.20 // 200ms open (slower than close)
            if t >= 1.0 {
                blinkPhase = .open
                scheduleNextBlink(from: now)
                return 0
            }
            return 1.0 - easeOut(t)
        }
    }
    
    private func scheduleNextBlink(from time: TimeInterval) {
        // Literature: mean ~4s, range 2-10s
        // Speaking reduces blink rate slightly
        let mean: Double = isSpeaking ? 5.0 : 4.0
        let variance: Double = 2.0
        // Gaussian-ish via Box-Muller
        let u1 = Double.random(in: 0.001...1.0)
        let u2 = Double.random(in: 0.001...1.0)
        let gaussian = sqrt(-2.0 * log(u1)) * cos(2.0 * .pi * u2)
        let interval = max(1.5, mean + gaussian * variance)
        nextBlinkTime = time + interval
    }
    
    // MARK: - Saccade System
    
    private func updateSaccade(now: TimeInterval, dt: Float) {
        if now >= nextSaccadeTime {
            // New saccade target: ±0.3-1.0 normalized
            saccadeTarget = SIMD2(
                Float.random(in: -0.6...0.6),
                Float.random(in: -0.3...0.3)
            )
            scheduleNextSaccade(from: now)
        }
        
        // Saccade movement: fast ballistic (30-40ms for the jump, then settle)
        let saccadeSpeed: Float = 15.0 // fast convergence
        saccadeCurrent += (saccadeTarget - saccadeCurrent) * min(dt * saccadeSpeed, 1.0)
    }
    
    private func scheduleNextSaccade(from time: TimeInterval) {
        // Exponential distribution, mean ~800ms idle, ~500ms speaking
        let mean: Double = isSpeaking ? 0.5 : 0.8
        let interval = -mean * log(Double.random(in: 0.001...1.0))
        nextSaccadeTime = time + max(0.2, min(interval, 3.0))
    }
    
    // MARK: - Micro-Expression System
    
    /// Occasional fleeting expressions that flash across the face.
    /// Humans do this constantly — a brief lip corner pull, a nostril flare,
    /// a quick brow flash. Duration: 200-500ms. Interval: 5-15s.
    private func updateMicroExpressions(now: TimeInterval, dt: Float) {
        // Decay current micro-expression
        if microExpressionDecay > 0 {
            microExpressionDecay -= dt * 3.0 // ~300ms decay
            if microExpressionDecay <= 0 {
                microExpressionDecay = 0
                microExpressionBS = [:]
            }
        }
        
        // Schedule next
        if now >= nextMicroExpressionTime {
            triggerMicroExpression()
            let interval = Double.random(in: 5...15)
            nextMicroExpressionTime = now + interval
        }
    }
    
    private func triggerMicroExpression() {
        microExpressionDecay = 1.0
        
        // Random micro-expression type
        let type = Int.random(in: 0...7)
        switch type {
        case 0: // Lip corner pull (asymmetric smile flash)
            let side = Bool.random()
            microExpressionBS = [
                side ? "mouthSmileLeft" : "mouthSmileRight": 0.15,
                side ? "cheekSquintLeft" : "cheekSquintRight": 0.08,
            ]
        case 1: // Brow flash (universal greeting signal)
            microExpressionBS = [
                "browOuterUpLeft": 0.2, "browOuterUpRight": 0.2,
                "browInnerUp": 0.1,
            ]
        case 2: // Nostril flare
            microExpressionBS = [
                "noseSneerLeft": 0.1, "noseSneerRight": 0.1,
            ]
        case 3: // Lip press (thinking micro-gesture)
            microExpressionBS = [
                "mouthPressLeft": 0.15, "mouthPressRight": 0.15,
                "mouthClose": 0.1,
            ]
        case 4: // Single brow raise
            let side = Bool.random()
            microExpressionBS = [
                side ? "browOuterUpLeft" : "browOuterUpRight": 0.2,
            ]
        case 5: // Slight squint (processing)
            microExpressionBS = [
                "eyeSquintLeft": 0.12, "eyeSquintRight": 0.12,
            ]
        case 6: // Mouth corner tighten
            microExpressionBS = [
                "mouthDimpleLeft": 0.1, "mouthDimpleRight": 0.1,
            ]
        default: // Jaw shift
            microExpressionBS = [
                Bool.random() ? "jawLeft" : "jawRight": 0.05,
            ]
        }
    }
    
    // MARK: - Mood / Expression System
    
    /// Mood affects subtle background expressions.
    public enum Mood {
        case neutral
        case happy
        case thinking
        case surprised
        case concerned
    }
    
    /// Set the current mood. Transitions smoothly over ~0.5s.
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
            moodTransitionProgress = min(1.0, moodTransitionProgress + dt * 2.0) // ~0.5s
        }
    }
    
    // MARK: - Perlin-like Smooth Noise
    
    /// Simple smooth noise generator using layered sine waves.
    /// Cheaper than real Perlin, good enough for organic micro-movement.
    private struct PerlinOctave {
        let freq1 = Float.random(in: 0.8...1.2)
        let freq2 = Float.random(in: 1.8...2.5)
        let freq3 = Float.random(in: 3.5...4.5)
        let phase1 = Float.random(in: 0...(2 * .pi))
        let phase2 = Float.random(in: 0...(2 * .pi))
        let phase3 = Float.random(in: 0...(2 * .pi))
        
        /// Returns value in roughly [-1, 1].
        func sample(t: Float) -> Float {
            let o1 = sin(t * freq1 + phase1) * 0.6
            let o2 = sin(t * freq2 + phase2) * 0.3
            let o3 = sin(t * freq3 + phase3) * 0.1
            return o1 + o2 + o3
        }
    }
    
    // MARK: - Easing
    
    private func easeIn(_ t: Float) -> Float {
        t * t
    }
    
    private func easeOut(_ t: Float) -> Float {
        1.0 - (1.0 - t) * (1.0 - t)
    }
}
