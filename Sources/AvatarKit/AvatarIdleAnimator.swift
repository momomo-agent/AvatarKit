import Foundation
import QuartzCore
import simd

// MARK: - Idle Animator

/// Generates natural idle motion with Disney-level behavioral parameters.
///
/// Research sources:
/// - Disney 12 Principles: Slow In/Out, Arcs, Anticipation, Follow-Through, Secondary Action
/// - Disney Research: Modeling and Animating Eye Blinks (close 80ms, open 200ms)
/// - USC ICT: Neurobiological model of visual attention (Lee et al. 2002)
/// - FACS: Onset 200-500ms, apex 500ms-4s, offset 500ms-1s
/// - Frontiers in Psychology: Breathing in Conversation (McFarland 2001)
/// - PMC: Eye blinks as communicative signals in face-to-face interaction
/// - Max Planck: Eyebrow movements as signals of communicative problems (2025)
/// - Hale et al. 2020: Listener head mimicry at 600ms delay, fast nodding >1.5Hz
/// - Koç University ICASSP: Prosody-driven head gesture animation
/// - Russell 1980: Circumplex Model of Affect (valence-arousal)
/// - MoCap Online: Idle animation system (weight shift, fidgets, pose variation)
/// - Basque University 2023: Idle animation believability evaluation
///
/// Architecture: 13 independent layers with inter-layer causal coupling.
/// Disney magic = slow in/out + arcs + anticipation + secondary action + follow-through.
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
    public var isSpeaking = false {
        didSet {
            if isSpeaking != oldValue {
                // State transition anticipation
                if isSpeaking {
                    speakAnticipationPhase = 0  // start "about to speak" animation
                } else {
                    speakWindDownPhase = 0  // start "settling after speaking"
                }
                prevSpeakingState = oldValue
            }
        }
    }
    
    /// Whether the character is currently listening to someone.
    public var isListening = false
    
    /// Audio energy (RMS amplitude, 0-1).
    public var audioEnergy: Float = 0
    
    /// Audio pitch (Hz, 0 = unknown). Drives prosody-linked head motion.
    public var audioPitch: Float = 0
    
    /// Callback every frame.
    /// Parameters: blendshapes, headRotation, headTranslation, bodyRotation, bodyTranslation
    /// Body = root_JNT (whole character position/lean), Head = head_JNT (on top of body)
    public var onFrame: ((_ blendshapes: [String: Float], _ headRotation: simd_quatf, _ headTranslation: SIMD3<Float>, _ bodyRotation: simd_quatf, _ bodyTranslation: SIMD3<Float>) -> Void)?
    
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
    
    // --- Breathing (asymmetric: inhale fast, exhale slow) ---
    private var breathPhase: Float = 0  // 0→1 = one full breath cycle
    private var breathDepthVariation: Float = 1.0
    private var nextBreathVariationTime: TimeInterval = 0
    private var nextSighTime: TimeInterval = 0
    private var sighPhase: Float = -1
    
    // --- Head motion (spring dynamics for slow in/out) ---
    private var headTarget = SIMD3<Float>.zero  // target angles (yaw, pitch, roll)
    private var headCurrent = SIMD3<Float>.zero  // current angles
    private var headVelocity = SIMD3<Float>.zero // angular velocity
    private var nextHeadTargetTime: TimeInterval = 0
    
    // --- Body position (driven by breathing, head follows with drag) ---
    private var bodyY: Float = 0          // current body Y from breathing
    private var bodyZ: Float = 0          // current body Z from breathing (lean)
    private var bodyYVelocity: Float = 0  // for smooth following
    private var headDragY: Float = 0      // head's delayed follow of bodyY
    private var headDragYVel: Float = 0
    private var headDragZ: Float = 0      // head's delayed follow of bodyZ
    private var headDragZVel: Float = 0
    
    // --- Body sway (organic whole-body drift, independent of head rotation) ---
    private var bodySwayPhase: SIMD3<Float> = SIMD3(
        Float.random(in: 0...(.pi * 2)),
        Float.random(in: 0...(.pi * 2)),
        Float.random(in: 0...(.pi * 2))
    )
    // Second harmonic for organic feel (not pure sine)
    private var bodySwayPhase2: SIMD3<Float> = SIMD3(
        Float.random(in: 0...(.pi * 2)),
        Float.random(in: 0...(.pi * 2)),
        Float.random(in: 0...(.pi * 2))
    )
    
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
    private var swallowPhase: Float = -1
    
    // --- Asymmetry ---
    private let leftEmotionBias: Float = 1.08
    
    // --- Weight Shift (4-8s cycle) ---
    private var weightShiftPhase: Float = 0
    
    // --- Fidgets ---
    private var nextFidgetTime: TimeInterval = 0
    private var fidgetPhase: Float = -1
    private var fidgetType: Int = 0
    private var fidgetDirection: Float = 1  // locked at fidget start, not per-frame random
    
    // --- Pose Drift (no return to exact zero) ---
    private var poseDriftTarget = SIMD3<Float>.zero  // yaw, pitch, roll offset
    private var poseDriftCurrent = SIMD3<Float>.zero
    private var nextPoseDriftTime: TimeInterval = 0
    
    // --- State Transition Anticipation ---
    private var speakAnticipationPhase: Float = -1  // -1 = inactive
    private var speakWindDownPhase: Float = -1
    private var prevSpeakingState = false
    
    // --- Beat Detection (onset-driven head gestures while speaking) ---
    // Detect energy rises (onsets) to trigger beat gestures at speech rhythm
    private var prevEnergy: Float = 0
    private var energyRiseAccum: Float = 0     // accumulates rising energy
    private var lastBeatTime: TimeInterval = 0  // when last beat fired
    private var beatCooldown: Double = 0.25     // min time between beats
    private var beatGesturePhase: Float = -1    // -1 = inactive, 0→1 = gesture
    private var beatGestureDuration: Float = 0.3
    private var beatGestureTarget = SIMD3<Float>.zero  // yaw, pitch, roll impulse
    private var beatCount: Int = 0              // for varying gesture type
    
    // --- Secondary Action Coupling ---
    // Tracks recent head motion for shoulder/brow follow-through
    private var recentHeadYawDelta: Float = 0
    private var recentHeadPitchDelta: Float = 0
    private var prevHeadYaw: Float = 0
    private var prevHeadPitch: Float = 0
    
    // MARK: - Init / Lifecycle
    
    public init() {
        scheduleNextBlink(from: 0)
        scheduleNextSaccade(from: 0)
        nextMicroExpressionTime = Double.random(in: 3...8)
        nextSwallowTime = Double.random(in: 60...180)
        nextFidgetTime = Double.random(in: 5...12)
        nextSighTime = Double.random(in: 30...90)
        nextHeadTargetTime = Double.random(in: 2...5)
        nextPoseDriftTime = Double.random(in: 20...40)
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
    
    // MARK: - External Tick
    
    public func externalTick() { _tick() }
    
    @objc private func tick() { _tick() }
    
    // MARK: - Main Loop
    
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
        var headYaw: Float = 0
        var headPitch: Float = 0
        var headRoll: Float = 0
        
        // ═══════════════════════════════════════════
        // Layer 1: Breathing (BASE LAYER — drives body Y, head follows with drag)
        // AnimSchool: "hips drive the motion, overlap travels up the spine"
        // The body rises/falls with breath. The head follows ~0.15s later.
        // This creates natural overlap/drag — the Disney "follow-through" principle.
        // ═══════════════════════════════════════════
        if breathingEnabled {
            let breathVisible: Float = isSpeaking ? 0.15 : 0.6
            let rate: Float = isSpeaking ? 0.6 : 1.0
            breathPhase += dt * rate / 3.8
            if breathPhase > 1.0 { breathPhase -= 1.0 }
            
            let breathAmount: Float
            if breathPhase < 0.4 {
                let t = breathPhase / 0.4
                breathAmount = cubicEaseOut(t)
            } else {
                let t = (breathPhase - 0.4) / 0.6
                breathAmount = 1.0 - cubicEaseIn(t)
            }
            
            let depth = breathVisible * breathDepthVariation
            bs["jawOpen"] = breathAmount * 0.02 * depth
            
            // Body Y driven by breathing (this is the "hips" in a bust)
            // Face tracking scale: Y × 20, so 0.1 here ≈ 5mm real movement
            bodyY = breathAmount * 0.3 * depth
            // Body Z: inhale = slight lean back, exhale = lean forward
            // Face tracking scale: Z × 100, so 0.5 here ≈ 5mm real movement
            bodyZ = -breathAmount * 0.5 * depth
            
            // Head follows body Y and Z with DRAG (overlap principle)
            // Spring-damper with lower stiffness = delayed follow
            let dragStiffness: Float = 8.0
            let dragDamping: Float = 2.0 * sqrt(dragStiffness)
            
            let dragForceY = (bodyY - headDragY) * dragStiffness
            let dragDampY = -headDragYVel * dragDamping
            headDragYVel += (dragForceY + dragDampY) * dt
            headDragY += headDragYVel * dt
            
            let dragForceZ = (bodyZ - headDragZ) * dragStiffness
            let dragDampZ = -headDragZVel * dragDamping
            headDragZVel += (dragForceZ + dragDampZ) * dt
            headDragZ += headDragZVel * dt
            
            // Head pitch from breathing: rises on inhale (overlap = slightly delayed)
            headPitch += breathAmount * 0.3 * depth
            
            // Occasional sigh (deep breath + exhale sound)
            if sighPhase >= 0 {
                sighPhase += dt / 2.5  // sigh lasts ~2.5s
                if sighPhase >= 1.0 {
                    sighPhase = -1
                } else {
                    let sighEnvelope = sin(sighPhase * .pi)
                    bs["jawOpen"] = (bs["jawOpen"] ?? 0) + sighEnvelope * 0.06
                    headPitch += sighEnvelope * 1.5  // head tilts back on sigh
                    headRoll += sighEnvelope * 0.8   // slight roll
                }
            } else if now > nextSighTime && !isSpeaking {
                sighPhase = 0
                nextSighTime = now + Double.random(in: 40...120)
            }
            
            // Breath depth variation
            if now > nextBreathVariationTime {
                breathDepthVariation = Float.random(in: 0.6...1.4)
                nextBreathVariationTime = now + Double.random(in: 6...12)
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 2: Eye Blinks
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
        // Layer 4: Head Motion (spring dynamics = natural slow in/out)
        // Disney: movements accelerate and decelerate, never constant speed
        // Spring model: F = -k*x - d*v (critically damped for organic feel)
        // ═══════════════════════════════════════════
        if headMotionEnabled {
            // Pick new head targets periodically
            // Disney EXAGGERATION: all amplitudes 50-100% larger than realistic
            if now > nextHeadTargetTime {
                let amp: Float
                let interval: Double
                if isSpeaking {
                    // Speaking head targets are now driven by beats (below).
                    // Between beats, hold a gentle forward-leaning "engaged" pose
                    // that drifts slowly — the beats punch through this base.
                    amp = 3.0
                    interval = Double.random(in: 1.5...3.0)
                    headTarget = SIMD3(
                        Float.random(in: -amp...amp),
                        Float.random(in: 2.0...5.0),   // slight forward lean
                        Float.random(in: -2.0...2.0)
                    )
                } else if isListening || currentMood == .listening {
                    // LISTENING: head slightly tilted, frequent nods, forward lean
                    // Visually distinct: "I'm paying attention to you"
                    amp = 5.0
                    interval = Double.random(in: 0.8...2.0)  // frequent nods
                    let r = Float.random(in: 0...1)
                    if r < 0.5 {
                        // Nod (most common when listening)
                        headTarget = SIMD3(
                            Float.random(in: -1.5...1.5),
                            Float.random(in: 5.0...10.0),   // big nod down
                            Float.random(in: -1.0...1.0)
                        )
                    } else if r < 0.75 {
                        // Slight head tilt (curious/engaged)
                        let tiltDir: Float = Float.random(in: 0...1) < 0.5 ? 1 : -1
                        headTarget = SIMD3(
                            tiltDir * Float.random(in: 1.0...3.0),
                            Float.random(in: 2.0...5.0),    // still slightly nodded
                            tiltDir * Float.random(in: 3.0...6.0)  // visible tilt
                        )
                    } else {
                        // Small adjustment
                        headTarget = SIMD3(
                            Float.random(in: -amp...amp),
                            Float.random(in: -2.0...3.0),
                            Float.random(in: -2.0...2.0)
                        )
                    }
                } else if currentMood == .thinking {
                    // THINKING: look up and away, slow drifting gaze, head tilted
                    // Visually distinct: "I'm processing something"
                    amp = 10.0
                    interval = Double.random(in: 1.5...3.5)  // slower, contemplative
                    let thinkDir = Float.random(in: 0...1) < 0.6 ? Float(1) : Float(-1)
                    let r = Float.random(in: 0...1)
                    if r < 0.6 {
                        // Look up and to the side (classic "thinking" pose)
                        headTarget = SIMD3(
                            thinkDir * Float.random(in: 5.0...10.0),
                            Float.random(in: -10.0 ... -4.0),  // look UP
                            thinkDir * Float.random(in: 3.0...7.0)
                        )
                    } else {
                        // Look down (reading/pondering)
                        headTarget = SIMD3(
                            thinkDir * Float.random(in: 2.0...6.0),
                            Float.random(in: 3.0...8.0),   // look DOWN
                            thinkDir * Float.random(in: 1.0...4.0)
                        )
                    }
                } else {
                    // IDLE: casual, relaxed, looking around
                    amp = 8.0
                    interval = Double.random(in: 1.0...2.5)  // fairly active
                    headTarget = SIMD3(
                        Float.random(in: -amp...amp),
                        Float.random(in: -amp*0.5...amp*0.5),
                        Float.random(in: -amp*0.3...amp*0.3)
                    )
                }
                nextHeadTargetTime = now + interval
            }
            
            // Spring physics — SNAPPY response for cartoon feel
            // High stiffness = head reaches target in ~0.3s
            let stiffness: Float
            if isSpeaking {
                stiffness = 20.0  // very snappy
            } else if currentMood == .thinking {
                stiffness = 6.0   // slower, contemplative
            } else if isListening || currentMood == .listening {
                stiffness = 14.0  // responsive nods
            } else {
                stiffness = 10.0  // active idle
            }
            // Critical damping (ζ = 1): fastest without oscillation
            let damping: Float = 2.0 * sqrt(stiffness)
            
            // Add pose drift to target (so we never return to exact zero)
            let effectiveTarget = headTarget + poseDriftCurrent
            
            let springForce = (effectiveTarget - headCurrent) * stiffness
            let dampForce = -headVelocity * damping
            let acceleration = springForce + dampForce
            
            headVelocity += acceleration * dt
            headCurrent += headVelocity * dt
            
            headYaw += headCurrent.x
            headPitch += headCurrent.y
            headRoll += headCurrent.z
            
            // ═══════════════════════════════════════════
            // Beat Gesture System (speaking only)
            // Detect audio energy onsets → trigger head gestures at speech rhythm
            // Disney: head moves on EMPHASIS, not randomly
            // ═══════════════════════════════════════════
            if isSpeaking {
                // Onset detection: energy rising = potential beat
                let energyDelta = smoothedEnergy - prevEnergy
                if energyDelta > 0 {
                    energyRiseAccum += energyDelta
                }
                prevEnergy = smoothedEnergy
                
                // Fire beat when: enough energy accumulated + cooldown passed
                let timeSinceBeat = now - lastBeatTime
                if energyRiseAccum > 0.05 && timeSinceBeat > beatCooldown && smoothedEnergy > 0.08 {
                    // BEAT! Pick gesture type based on count (variety)
                    beatCount += 1
                    let intensity = min(energyRiseAccum * 6.0, 1.5)
                    
                    switch beatCount % 5 {
                    case 0:
                        // Nod down (most common — emphasis)
                        beatGestureTarget = SIMD3(0, intensity * 8.0, 0)
                    case 1:
                        // Tilt + slight nod ("you know what I mean")
                        let dir: Float = Float.random(in: 0...1) < 0.5 ? 1 : -1
                        beatGestureTarget = SIMD3(dir * intensity * 3.0, intensity * 5.0, dir * intensity * 4.0)
                    case 2:
                        // Forward lean ("listen to this")
                        beatGestureTarget = SIMD3(0, intensity * 6.0, 0)
                        // Also push body Z forward
                        bodyZ += intensity * 0.3
                    case 3:
                        // Yaw turn ("on the other hand")
                        let dir: Float = Float.random(in: 0...1) < 0.5 ? 1 : -1
                        beatGestureTarget = SIMD3(dir * intensity * 6.0, intensity * 3.0, 0)
                    default:
                        // Head back + slight roll ("wow" / emphasis)
                        let dir: Float = Float.random(in: 0...1) < 0.5 ? 1 : -1
                        beatGestureTarget = SIMD3(0, -intensity * 4.0, dir * intensity * 3.0)
                    }
                    
                    beatGesturePhase = 0
                    beatGestureDuration = Float.random(in: 0.2...0.4)
                    lastBeatTime = now
                    energyRiseAccum = 0
                    
                    // Vary cooldown: fast speech = shorter cooldown
                    beatCooldown = smoothedEnergy > 0.3 ? 0.2 : 0.35
                }
                
                // Decay accumulator if energy drops (missed beat)
                if energyDelta <= 0 {
                    energyRiseAccum *= 0.85
                }
                
                // Apply active beat gesture with ease-out
                if beatGesturePhase >= 0 {
                    beatGesturePhase += dt / beatGestureDuration
                    if beatGesturePhase >= 1.0 {
                        beatGesturePhase = -1
                    } else {
                        // Sharp attack, smooth decay (like a real head gesture)
                        let t = beatGesturePhase
                        let envelope: Float = t < 0.3 ? cubicEaseOut(t / 0.3) : 1.0 - cubicEaseIn((t - 0.3) / 0.7)
                        headPitch += beatGestureTarget.y * envelope
                        headYaw += beatGestureTarget.x * envelope
                        headRoll += beatGestureTarget.z * envelope
                    }
                }
            } else {
                // Reset beat state when not speaking
                prevEnergy = 0
                energyRiseAccum = 0
                beatGesturePhase = -1
                beatCount = 0
            }
            if isListening {
                headPitch -= 7.0  // big forward lean ("I'm all ears")
            }
            
            // ═══════════════════════════════════════════
            // Layer 4b: Weight Shift (rotation only, translation derived later)
            // ═══════════════════════════════════════════
            weightShiftPhase += dt * 2 * .pi / 6.0
            if weightShiftPhase > 2 * .pi { weightShiftPhase -= 2 * .pi }
            let swayAmount = sin(weightShiftPhase) * 0.8
            headRoll += swayAmount * 1.5
            headYaw += swayAmount * 0.5
        }
        
        // ═══════════════════════════════════════════
        // Layer 5: Pose Drift (no return to exact zero)
        // Real humans never return to the same "neutral" pose.
        // Slow random walk of the resting position.
        // ═══════════════════════════════════════════
        if now > nextPoseDriftTime {
            poseDriftTarget = SIMD3(
                Float.random(in: -2.0...2.0),   // yaw drift
                Float.random(in: -1.0...1.0),   // pitch drift
                Float.random(in: -0.5...0.5)    // roll drift
            )
            nextPoseDriftTime = now + Double.random(in: 15...35)
        }
        // Very slow interpolation toward drift target
        poseDriftCurrent += (poseDriftTarget - poseDriftCurrent) * min(dt * 0.3, 1.0)
        
        // ═══════════════════════════════════════════
        // Layer 6: Mood Expression Overlay
        // ═══════════════════════════════════════════
        if expressionEnabled {
            updateMood(dt: dt)
            for (key, value) in moodBlendshapes {
                bs[key] = (bs[key] ?? 0) + value * moodTransitionProgress
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 7: Micro-Expressions (FACS three-phase)
        // ═══════════════════════════════════════════
        if microExpressionEnabled {
            let microIntensity = updateMicroExpression(now: now)
            if microIntensity > 0.01 {
                for (key, value) in microExpressionBS {
                    var adjusted = value * microIntensity
                    if key.hasSuffix("Left") { adjusted *= leftEmotionBias }
                    bs[key] = (bs[key] ?? 0) + adjusted
                }
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 8: Facial Asymmetry
        // ═══════════════════════════════════════════
        let browAsym = sin(elapsed * 0.15) * 0.06
        if browAsym > 0.01 {
            bs["browOuterUpLeft"] = (bs["browOuterUpLeft"] ?? 0) + browAsym
        } else if browAsym < -0.01 {
            bs["browOuterUpRight"] = (bs["browOuterUpRight"] ?? 0) - browAsym
        }
        let mouthAsym = sin(elapsed * 0.12 + 1.7) * 0.03
        if abs(mouthAsym) > 0.005 {
            if mouthAsym > 0 {
                bs["mouthSmileLeft"] = (bs["mouthSmileLeft"] ?? 0) + mouthAsym
            } else {
                bs["mouthSmileRight"] = (bs["mouthSmileRight"] ?? 0) - mouthAsym
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 9: Swallow
        // ═══════════════════════════════════════════
        if swallowEnabled {
            updateSwallow(now: now, dt: dt, bs: &bs, headPitch: &headPitch)
        }
        
        // ═══════════════════════════════════════════
        // Layer 10: State Transition Anticipation
        // Disney: ANTICIPATION before every action
        // About to speak → micro jaw open, brow lift, slight forward lean
        // Finished speaking → settle back, lip press, exhale
        // ═══════════════════════════════════════════
        if speakAnticipationPhase >= 0 {
            speakAnticipationPhase += dt / 0.3  // 300ms anticipation
            if speakAnticipationPhase >= 1.0 {
                speakAnticipationPhase = -1
            } else {
                let a = cubicEaseOut(speakAnticipationPhase)
                bs["jawOpen"] = (bs["jawOpen"] ?? 0) + a * 0.04       // mouth opens slightly
                bs["browInnerUp"] = (bs["browInnerUp"] ?? 0) + a * 0.1 // brows lift
                headPitch -= a * 1.5                                     // lean forward
            }
        }
        if speakWindDownPhase >= 0 {
            speakWindDownPhase += dt / 0.6  // 600ms wind-down (slower than anticipation)
            if speakWindDownPhase >= 1.0 {
                speakWindDownPhase = -1
            } else {
                let w = sin(speakWindDownPhase * .pi)  // bell curve
                bs["mouthPressLeft"] = (bs["mouthPressLeft"] ?? 0) + w * 0.1
                bs["mouthPressRight"] = (bs["mouthPressRight"] ?? 0) + w * 0.1
                headPitch += w * 1.0  // settle back
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 11: Speaking-specific
        // ═══════════════════════════════════════════
        if isSpeaking {
            if smoothedEnergy < 0.05 {
                bs["mouthPressLeft"] = (bs["mouthPressLeft"] ?? 0) + 0.08
                bs["mouthPressRight"] = (bs["mouthPressRight"] ?? 0) + 0.08
            }
        }
        
        // ═══════════════════════════════════════════
        // Layer 12: Fidgets (with anticipation + follow-through)
        // ═══════════════════════════════════════════
        if !isSpeaking {
            updateFidget(now: now, dt: dt, bs: &bs,
                        headYaw: &headYaw, headPitch: &headPitch,
                        headRoll: &headRoll)
        }
        
        // ═══════════════════════════════════════════
        // Layer 13: Secondary Action (inter-layer coupling)
        // Disney: when one part moves, related parts follow
        // Head turns → brow raises on leading side
        // Head nods → slight eye squint
        // Big movements → "shoulder" follow (head translation)
        // ═══════════════════════════════════════════
        
        // Track head motion deltas for follow-through
        let yawDelta = headYaw - prevHeadYaw
        let pitchDelta = headPitch - prevHeadPitch
        // Smooth the deltas (follow-through = delayed response)
        recentHeadYawDelta += (yawDelta - recentHeadYawDelta) * min(dt * 3.0, 1.0)
        recentHeadPitchDelta += (pitchDelta - recentHeadPitchDelta) * min(dt * 3.0, 1.0)
        prevHeadYaw = headYaw
        prevHeadPitch = headPitch
        
        // Head turn → brow raise on leading side (overlapping action)
        if abs(recentHeadYawDelta) > 0.3 {
            let browAmount = min(abs(recentHeadYawDelta) * 0.02, 0.12)
            if recentHeadYawDelta > 0 {
                bs["browOuterUpRight"] = (bs["browOuterUpRight"] ?? 0) + browAmount
            } else {
                bs["browOuterUpLeft"] = (bs["browOuterUpLeft"] ?? 0) + browAmount
            }
        }
        
        // Head nod down → slight eye squint (effort/emphasis)
        if recentHeadPitchDelta > 0.5 {
            let squintAmount = min(recentHeadPitchDelta * 0.015, 0.08)
            bs["eyeSquintLeft"] = (bs["eyeSquintLeft"] ?? 0) + squintAmount
            bs["eyeSquintRight"] = (bs["eyeSquintRight"] ?? 0) + squintAmount
        }
        
        // Big head movement → additional rotation (not translation)
        // The neck pivot model handles the spatial consequence automatically
        
        // Smile secondary actions
        let smileAmount = max(bs["mouthSmileLeft"] ?? 0, bs["mouthSmileRight"] ?? 0)
        if smileAmount > 0.05 {
            bs["cheekSquintLeft"] = (bs["cheekSquintLeft"] ?? 0) + smileAmount * 0.5
            bs["cheekSquintRight"] = (bs["cheekSquintRight"] ?? 0) + smileAmount * 0.5
            bs["eyeSquintLeft"] = (bs["eyeSquintLeft"] ?? 0) + smileAmount * 0.3
            bs["eyeSquintRight"] = (bs["eyeSquintRight"] ?? 0) + smileAmount * 0.3
            bs["noseSneerLeft"] = (bs["noseSneerLeft"] ?? 0) + smileAmount * 0.1
            bs["noseSneerRight"] = (bs["noseSneerRight"] ?? 0) + smileAmount * 0.1
        }
        let frownAmount = max(bs["mouthFrownLeft"] ?? 0, bs["mouthFrownRight"] ?? 0)
        if frownAmount > 0.05 {
            bs["browInnerUp"] = (bs["browInnerUp"] ?? 0) + frownAmount * 0.4
        }
        
        // ═══════════════════════════════════════════
        // Final: Two-layer output (Disney three-layer adapted for head-only rig)
        //
        // BODY LAYER (root_JNT):
        //   Rotation: weight shift lean + breathing lean + speaking forward lean
        //   Translation: body sway + breathing Y
        //   This is the "torso" — the whole character moves as a unit
        //
        // HEAD LAYER (head_JNT, additive on body):
        //   Rotation: gaze targets + beat gestures + fidgets + pose drift
        //   The head rotates RELATIVE to the body, not world space
        //
        // Disney insight: "Simply composing layers by masking results in
        // robotic and uncanny motions, because the dynamics for other body
        // parts is lost." — We couple them: head motion feeds back into
        // body lean (secondary action), and body motion feeds into head
        // (follow-through/drag).
        // ═══════════════════════════════════════════
        if intensity != 1.0 {
            for key in bs.keys { bs[key]! *= intensity }
            headYaw *= intensity; headPitch *= intensity; headRoll *= intensity
        }
        
        let rad = Float.pi / 180.0
        
        // --- Body rotation ---
        // Weight shift: lean left/right (roll) + slight yaw
        // Breathing: slight pitch oscillation
        // Speaking: forward lean (pitch)
        // Head motion coupling: big head turns pull body slightly
        var bodyYaw: Float = 0
        var bodyPitch: Float = 0
        var bodyRoll: Float = 0
        
        // Weight shift drives body lean (primary body motion)
        bodyRoll = sin(weightShiftPhase) * 3.0 * intensity   // visible lean
        bodyYaw = sin(weightShiftPhase) * 1.5 * intensity    // slight turn with lean
        
        // Breathing drives body pitch
        bodyPitch = headDragZ * 0.5 * intensity  // body leans with breath
        
        // Speaking forward lean
        if isSpeaking {
            bodyPitch += 2.0 * intensity  // engaged forward lean
        } else if isListening {
            bodyPitch += 3.0 * intensity  // attentive forward lean
        }
        
        // Secondary action: head turns pull body (delayed, reduced)
        bodyYaw += recentHeadYawDelta * 0.15
        bodyPitch += recentHeadPitchDelta * 0.1
        
        let bodyQ = simd_quatf(angle: bodyYaw * rad, axis: SIMD3(0, 1, 0))
                  * simd_quatf(angle: bodyPitch * rad, axis: SIMD3(1, 0, 0))
                  * simd_quatf(angle: bodyRoll * rad, axis: SIMD3(0, 0, 1))
        
        // --- Head rotation (relative to body) ---
        // Remove body contribution from head angles so head is additive
        let headOnlyYaw = headYaw - bodyYaw
        let headOnlyPitch = headPitch - bodyPitch
        let headOnlyRoll = headRoll - bodyRoll
        
        let headQ = simd_quatf(angle: headOnlyYaw * rad, axis: SIMD3(0, 1, 0))
                  * simd_quatf(angle: headOnlyPitch * rad, axis: SIMD3(1, 0, 0))
                  * simd_quatf(angle: headOnlyRoll * rad, axis: SIMD3(0, 0, 1))
        
        // Translation: rotation-only for now.
        // Apple's neckNode (head_JNT) is offset from root_JNT, so rotation
        // naturally produces spatial displacement — no explicit translation needed.
        // Body sway is expressed purely through bodyQ roll/yaw.
        let headTranslation = SIMD3<Float>.zero
        let bodyTranslation = SIMD3<Float>.zero
        
        onFrame?(bs, headQ, headTranslation, bodyQ, bodyTranslation)
    }
    
    // MARK: - Blink System
    
    private enum BlinkPhase {
        case open
        case closing  // 80ms
        case closed   // 50ms hold
        case opening  // 200ms (asymmetric: slow open = natural)
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
            return cubicEaseIn(t)
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
            return 1.0 - cubicEaseOut(t)
        }
    }
    
    private func scheduleNextBlink(from time: TimeInterval) {
        let mean: Double = isListening ? 5.5 : (isSpeaking ? 3.5 : 4.0)
        let u1 = Double.random(in: 0.001...1.0)
        let u2 = Double.random(in: 0.001...1.0)
        let gaussian = sqrt(-2.0 * log(u1)) * cos(2.0 * .pi * u2)
        nextBlinkTime = time + max(1.5, mean + gaussian * 2.0)
    }
    
    // MARK: - Saccade System
    
    private func updateSaccade(now: TimeInterval, dt: Float) {
        if now >= nextSaccadeTime {
            saccadeTarget = SIMD2(
                Float.random(in: -0.3...0.3),
                Float.random(in: -0.15...0.15)
            )
            scheduleNextSaccade(from: now)
        }
        // Saccades: smooth follow instead of ballistic jump
        saccadeCurrent += (saccadeTarget - saccadeCurrent) * min(dt * 5.0, 1.0)
    }
    
    private func scheduleNextSaccade(from time: TimeInterval) {
        let mean: Double = isSpeaking ? 0.5 : (isListening ? 1.0 : 0.8)
        let interval = -mean * log(Double.random(in: 0.001...1.0))
        nextSaccadeTime = time + max(0.2, min(interval, 3.0))
    }
    
    // MARK: - Micro-Expression System (FACS three-phase)
    
    private enum MicroExprPhase {
        case idle, onset, apex, offset
    }
    
    private func updateMicroExpression(now: TimeInterval) -> Float {
        switch microExpressionPhase {
        case .idle:
            if now >= nextMicroExpressionTime {
                triggerMicroExpression()
                microExpressionPhase = .onset
                microExprPhaseStart = now
                microExprOnsetDuration = Float.random(in: 0.15...0.35)
                microExprApexDuration = Float.random(in: 0.2...0.5)
                microExprOffsetDuration = Float.random(in: 0.3...0.7)
            }
            return 0
        case .onset:
            let t = Float(now - microExprPhaseStart) / microExprOnsetDuration
            if t >= 1.0 {
                microExpressionPhase = .apex
                microExprPhaseStart = now
                return 1.0
            }
            return cubicEaseOut(t)  // fast rise
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
            return 1.0 - cubicEaseIn(t)  // slow decay
        }
    }
    
    private func triggerMicroExpression() {
        let type = Int.random(in: 0...9)
        switch type {
        case 0:
            let side = Bool.random()
            microExpressionBS = [
                side ? "mouthSmileLeft" : "mouthSmileRight": 0.08,
                side ? "cheekSquintLeft" : "cheekSquintRight": 0.04,
            ]
        case 1:
            microExpressionBS = [
                "browOuterUpLeft": 0.1, "browOuterUpRight": 0.1,
                "browInnerUp": 0.05,
            ]
        case 2:
            microExpressionBS = [
                "noseSneerLeft": 0.04, "noseSneerRight": 0.04,
            ]
        case 3:
            microExpressionBS = [
                "mouthPressLeft": 0.15, "mouthPressRight": 0.15,
                "mouthClose": 0.1,
            ]
        case 4:
            let side = Bool.random()
            microExpressionBS = [
                side ? "browOuterUpLeft" : "browOuterUpRight": 0.1,
            ]
        case 5:
            microExpressionBS = [
                "eyeSquintLeft": 0.12, "eyeSquintRight": 0.12,
            ]
        case 6:
            microExpressionBS = [
                "mouthDimpleLeft": 0.1, "mouthDimpleRight": 0.1,
            ]
        case 7:
            microExpressionBS = [
                Bool.random() ? "jawLeft" : "jawRight": 0.05,
            ]
        case 8:
            microExpressionBS = ["mouthRollLower": 0.12]
        default:
            microExpressionBS = ["cheekPuff": 0.08]
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
        swallowPhase += dt / 0.6
        if swallowPhase >= 1.0 { swallowPhase = -1; return }
        
        let p = swallowPhase
        if p < 0.33 {
            let t = p / 0.33
            bs["jawOpen"] = (bs["jawOpen"] ?? 0) - 0.03 * cubicEaseIn(t)
            bs["mouthClose"] = (bs["mouthClose"] ?? 0) + 0.1 * cubicEaseIn(t)
        } else if p < 0.66 {
            let t = (p - 0.33) / 0.33
            headPitch += sin(t * .pi) * 1.2
            bs["mouthClose"] = (bs["mouthClose"] ?? 0) + 0.1 * (1.0 - t)
        }
    }
    
    // MARK: - Mood System
    
    public enum Mood {
        case neutral, happy, thinking, surprised, concerned, listening
    }
    
    public func setMood(_ mood: Mood) {
        guard mood != currentMood else { return }
        currentMood = mood
        moodTransitionProgress = 0
        switch mood {
        // Disney EXAGGERATION: expressions 2-3x stronger than realistic
        case .neutral: moodBlendshapes = [:]
        case .happy: moodBlendshapes = [
            "mouthSmileLeft": 0.4, "mouthSmileRight": 0.4,
            "cheekSquintLeft": 0.25, "cheekSquintRight": 0.25,
            "eyeSquintLeft": 0.15, "eyeSquintRight": 0.15,
            "noseSneerLeft": 0.08, "noseSneerRight": 0.08,
        ]
        case .thinking: moodBlendshapes = [
            "browInnerUp": 0.35,
            "eyeSquintLeft": 0.2, "eyeSquintRight": 0.2,
            "mouthPucker": 0.15,
            "mouthRollLower": 0.18,
            "eyeLookUpLeft": 0.25, "eyeLookUpRight": 0.25,
            "browOuterUpLeft": 0.15,
        ]
        case .surprised: moodBlendshapes = [
            "eyeWideLeft": 0.5, "eyeWideRight": 0.5,
            "browOuterUpLeft": 0.4, "browOuterUpRight": 0.4,
            "browInnerUp": 0.35,
            "jawOpen": 0.06,
        ]
        case .concerned: moodBlendshapes = [
            "browInnerUp": 0.4,
            "mouthFrownLeft": 0.25, "mouthFrownRight": 0.25,
            "eyeSquintLeft": 0.15, "eyeSquintRight": 0.15,
            "mouthPressLeft": 0.12, "mouthPressRight": 0.12,
        ]
        case .listening: moodBlendshapes = [
            "eyeWideLeft": 0.12, "eyeWideRight": 0.12,
            "browInnerUp": 0.12,
            "mouthClose": 0.08,
            "mouthPressLeft": 0.06, "mouthPressRight": 0.06,
        ]
        }
    }
    
    private func updateMood(dt: Float) {
        if moodTransitionProgress < 1.0 {
            // Cubic ease-out for mood transitions (slow in/out)
            moodTransitionProgress = min(1.0, moodTransitionProgress + dt * 2.0)
        }
    }
    
    // MARK: - Fidget System (with anticipation + follow-through)
    
    private func updateFidget(now: TimeInterval, dt: Float,
                              bs: inout [String: Float],
                              headYaw: inout Float, headPitch: inout Float,
                              headRoll: inout Float) {
        if fidgetPhase < 0 {
            if now >= nextFidgetTime {
                fidgetPhase = 0
                fidgetType = Int.random(in: 0...6)
                fidgetDirection = Bool.random() ? 1 : -1  // lock direction at start
                nextFidgetTime = now + Double.random(in: 8...20)
            }
            return
        }
        
        let duration: Float
        switch fidgetType {
        case 0: duration = 1.8  // look to side (longer for anticipation)
        case 1: duration = 1.5  // shoulder roll
        case 2: duration = 2.5  // big head turn
        case 3: duration = 1.2  // quick glance up
        case 4: duration = 2.0  // lean back then forward
        case 5: duration = 1.8  // head tilt with brow
        default: duration = 1.5 // jaw stretch
        }
        
        fidgetPhase += dt / duration
        if fidgetPhase >= 1.0 { fidgetPhase = -1; return }
        
        let p = fidgetPhase
        let dir = fidgetDirection
        
        // Disney three-phase envelope:
        // 0.0-0.12: anticipation (slight opposite move)
        // 0.12-0.55: main action (cubic ease-out: fast start, slow arrival)
        // 0.55-1.0: follow-through + settle (overshoot then return)
        let anticipation: Float
        let mainAction: Float
        let followThrough: Float
        
        if p < 0.12 {
            // Anticipation: small opposite movement
            anticipation = -sin(p / 0.12 * .pi) * 0.2
            mainAction = 0
            followThrough = 0
        } else if p < 0.55 {
            // Main action: cubic ease-out (fast start, decelerating)
            let t = (p - 0.12) / 0.43
            anticipation = 0
            mainAction = cubicEaseOut(t)
            followThrough = 0
        } else {
            // Follow-through: slight overshoot then settle back
            let t = (p - 0.55) / 0.45
            anticipation = 0
            mainAction = 1.0
            // Damped oscillation: overshoot then return
            followThrough = -sin(t * .pi * 1.5) * exp(-t * 3.0) * 0.15
        }
        
        let envelope = anticipation + mainAction + followThrough
        
        switch fidgetType {
        case 0: // Look to one side — BIG turn
            headYaw += dir * envelope * 18.0
            // Eyes lead head (overlapping action: eyes 30% ahead)
            let eyePhase = min(p * 1.3, 1.0)
            let eyeEnvelope = eyePhase < 0.5 ? cubicEaseOut(eyePhase * 2) : 1.0 - cubicEaseIn((eyePhase - 0.5) * 2)
            if dir > 0 {
                bs["eyeLookOutRight"] = (bs["eyeLookOutRight"] ?? 0) + eyeEnvelope * 0.35
                bs["eyeLookInLeft"] = (bs["eyeLookInLeft"] ?? 0) + eyeEnvelope * 0.35
            } else {
                bs["eyeLookOutLeft"] = (bs["eyeLookOutLeft"] ?? 0) + eyeEnvelope * 0.35
                bs["eyeLookInRight"] = (bs["eyeLookInRight"] ?? 0) + eyeEnvelope * 0.35
            }
            // Brow follows head (secondary action, delayed)
            let browDelay = max(0, p - 0.2)
            let browEnvelope = sin(browDelay / 0.8 * .pi) * 0.12
            if dir > 0 {
                bs["browOuterUpRight"] = (bs["browOuterUpRight"] ?? 0) + browEnvelope
            } else {
                bs["browOuterUpLeft"] = (bs["browOuterUpLeft"] ?? 0) + browEnvelope
            }
            
        case 1: // Shoulder roll
            headRoll += dir * envelope * 10.0
            headPitch += envelope * 4.0
            
        case 2: // Big head turn — like double-take
            headYaw += dir * envelope * 22.0
            headPitch -= envelope * 5.0
            // Squint on the side we're turning toward (effort)
            let squintSide = dir > 0 ? "eyeSquintRight" : "eyeSquintLeft"
            bs[squintSide] = (bs[squintSide] ?? 0) + max(0, mainAction) * 0.08
            
        case 3: // Quick glance up
            headPitch -= envelope * 12.0
            bs["eyeLookUpLeft"] = (bs["eyeLookUpLeft"] ?? 0) + max(0, envelope) * 0.4
            bs["eyeLookUpRight"] = (bs["eyeLookUpRight"] ?? 0) + max(0, envelope) * 0.4
            bs["browOuterUpLeft"] = (bs["browOuterUpLeft"] ?? 0) + max(0, envelope) * 0.15
            bs["browOuterUpRight"] = (bs["browOuterUpRight"] ?? 0) + max(0, envelope) * 0.15
            
        case 4: // Lean back then forward
            let leanCurve = sin(p * 2 * .pi)
            headPitch += leanCurve * 8.0
            
        case 5: // Head tilt with curious brow
            headRoll += dir * envelope * 14.0
            headPitch -= envelope * 4.0
            bs["browInnerUp"] = (bs["browInnerUp"] ?? 0) + max(0, envelope) * 0.2
            let browSide = dir > 0 ? "browOuterUpRight" : "browOuterUpLeft"
            bs[browSide] = (bs[browSide] ?? 0) + max(0, envelope) * 0.15
            
        default: // Jaw stretch — keep subtle to avoid twitchy appearance
            bs["jawOpen"] = (bs["jawOpen"] ?? 0) + max(0, envelope) * 0.08
            bs["mouthStretchLeft"] = (bs["mouthStretchLeft"] ?? 0) + max(0, envelope) * 0.05
            bs["mouthStretchRight"] = (bs["mouthStretchRight"] ?? 0) + max(0, envelope) * 0.05
            headPitch += envelope * 2.0
        }
    }
    
    // MARK: - Easing Functions (Disney: slow in / slow out)
    
    /// Cubic ease-in: slow start, fast end. t² × t
    private func cubicEaseIn(_ t: Float) -> Float { t * t * t }
    
    /// Cubic ease-out: fast start, slow end. 1 - (1-t)³
    private func cubicEaseOut(_ t: Float) -> Float {
        let inv = 1.0 - t
        return 1.0 - inv * inv * inv
    }
    
    /// Cubic ease-in-out: slow start and end.
    private func cubicEaseInOut(_ t: Float) -> Float {
        if t < 0.5 {
            return 4.0 * t * t * t
        } else {
            let inv = -2.0 * t + 2.0
            return 1.0 - inv * inv * inv / 2.0
        }
    }
}
