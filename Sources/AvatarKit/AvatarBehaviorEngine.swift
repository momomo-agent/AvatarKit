import Foundation
import QuartzCore
import simd

// MARK: - Behavior Engine

/// Autonomous behavior state machine that coordinates all animation subsystems.
///
/// Inspired by:
/// - Disney Research: "Animating an Autonomous 3D Talking Avatar"
///   - Hierarchical state machine with smooth transitions
///   - Behavior layers: base (idle) + reactive (listening) + active (speaking)
///
/// - SmartBody (USC ICT): Composable behavior controllers
///   - Controllers can schedule/blend other controllers
///   - Priority-based conflict resolution
///
/// States:
/// ```
/// IDLE ←→ LISTENING ←→ SPEAKING ←→ THINKING
///   ↕         ↕           ↕          ↕
/// (baked)  (nod/gaze)  (viseme)   (aversion)
/// ```
///
/// Each state configures the subsystems differently:
/// - IDLE: baked animation + random saccades + occasional blink emphasis
/// - LISTENING: look at speaker + nod feedback + "mm" expressions
/// - SPEAKING: viseme-driven + emphasis nods + hand gestures (future)
/// - THINKING: gaze aversion + micro-frown + head tilt
public class AvatarBehaviorEngine {
    
    // MARK: - State
    
    public enum BehaviorState: String {
        case idle
        case listening
        case speaking
        case thinking
        case emoting   // Playing a preset expression
    }
    
    /// Current behavior state.
    public private(set) var state: BehaviorState = .idle
    
    /// Time spent in current state.
    public private(set) var stateTime: TimeInterval = 0
    
    // MARK: - Subsystems
    
    /// Lip sync engine (mouth animation from audio).
    public let lipSync: AvatarLipSync
    
    /// Idle animator (breathing, blinks, micro-movement).
    public let idleAnimator: AvatarIdleAnimator
    
    /// Gaze controller (eye movement, saccades, aversion).
    public let gazeController: AvatarGazeController
    
    /// Head gesture generator (nod, shake, tilt).
    public let headGesture: AvatarHeadGesture
    
    /// Continuous emotion model (valence-arousal circumplex).
    public let emotion = EmotionEngine()
    
    /// Expression animator (preset expression transitions).
    public let expressionAnimator: ExpressionAnimator
    
    /// Animation mixer (merges all sources).
    public let mixer: AvatarAnimationMixer
    
    // MARK: - Configuration
    
    /// Listener nod interval range (seconds).
    public var nodInterval: ClosedRange<TimeInterval> = 2.0...4.0
    
    /// How long to stay in thinking state before auto-returning.
    public var thinkingTimeout: TimeInterval = 3.0
    
    /// Called every frame with the final mixed tracking data.
    public var onFrame: ((AvatarFaceTracking) -> Void)?
    
    // MARK: - Internal State
    
    private var displayLink: CADisplayLink?
    private var lastTime: TimeInterval = 0
    private var stateEntryTime: TimeInterval = 0
    
    // Listening state
    private var nextNodTime: TimeInterval = 0
    
    // Speaking state
    private var lastEnergyPeak: TimeInterval = 0
    
    // Gaze output
    private var gazeEyeBlendshapes: [String: Float] = [:]
    private var gazeHeadDelta: SIMD2<Float> = .zero
    private var smoothedGazeHeadDelta: SIMD2<Float> = .zero
    
    // Head gesture output
    private var gesturePitch: Float = 0
    private var gestureYaw: Float = 0
    private var gestureRoll: Float = 0
    
    // MARK: - Init
    
    public init() {
        lipSync = AvatarLipSync()
        lipSync.externallyDriven = true  // We drive it from our DisplayLink
        idleAnimator = AvatarIdleAnimator()
        gazeController = AvatarGazeController()
        headGesture = AvatarHeadGesture()
        expressionAnimator = ExpressionAnimator()
        mixer = AvatarAnimationMixer()
        
        // Wire subsystems
        mixer.lipSync = lipSync
        mixer.idleAnimator = idleAnimator
        
        // Lip sync amplitude → idle animator energy (for head motion)
        lipSync.onAmplitude = { [weak self] rms in
            self?.idleAnimator.audioEnergy = rms
        }
        
        // Gaze output → merge into mixer
        gazeController.onFrame = { [weak self] eyeBS, headDelta in
            self?.gazeEyeBlendshapes = eyeBS
            self?.gazeHeadDelta = headDelta
        }
        
        // Head gesture output → merge into mixer
        headGesture.onFrame = { [weak self] pitch, yaw, roll in
            self?.gesturePitch = pitch
            self?.gestureYaw = yaw
            self?.gestureRoll = roll
        }
        
        // Override mixer's onFrame to add gaze + gesture
        mixer.onFrame = { [weak self] tracking in
            guard let self else { return }
            var merged = tracking

            // Tick gaze and gesture from the animation frame (single driver)
            self.gazeController.externalTick()
            self.headGesture.externalTick()

            // Add gaze eye blendshapes
            for (key, value) in self.gazeEyeBlendshapes {
                merged.blendshapes[key] = (merged.blendshapes[key] ?? 0) + value
            }

            // Compose gaze + gesture head rotation as quaternion (avoids euler jitter)
            // Smooth gaze head delta so head follows eyes gradually, not in saccade jumps
            let smoothRate: Float = 0.08
            self.smoothedGazeHeadDelta += (self.gazeHeadDelta - self.smoothedGazeHeadDelta) * smoothRate
            let totalPitch = self.smoothedGazeHeadDelta.y * 10 + self.gesturePitch
            let totalYaw = self.smoothedGazeHeadDelta.x * 10 + self.gestureYaw
            let totalRoll = self.gestureRoll
            let rad = Float.pi / 180.0
            let extraQ = simd_quatf(angle: totalYaw * rad, axis: SIMD3(0, 1, 0))
                       * simd_quatf(angle: totalPitch * rad, axis: SIMD3(1, 0, 0))
                       * simd_quatf(angle: totalRoll * rad, axis: SIMD3(0, 0, 1))
            let baseQ = merged.rawQuaternion ?? merged.headRotation.quaternion
            merged.rawQuaternion = baseQ * extraQ
            
            // Add emotion blendshapes (continuous valence-arousal)
            let emotionBS = self.emotion.update(
                dt: Float(CACurrentMediaTime() - self.lastTime),
                elapsed: Float(CACurrentMediaTime() - self.stateEntryTime)
            )
            for (key, value) in emotionBS {
                merged.blendshapes[key] = (merged.blendshapes[key] ?? 0) + value
            }
            
            self.onFrame?(merged)
        }
        
        mixer.connect()
    }
    
    // MARK: - Lifecycle
    
    public func start() {
        let now = CACurrentMediaTime()
        lastTime = now
        stateEntryTime = now

        // Do NOT call subsystem start() — they would create their own DisplayLinks.
        // Instead, we drive them via externalTick() from our single DisplayLink.

        displayLink = CADisplayLink(target: self, selector: #selector(tick))
        displayLink?.preferredFrameRateRange = CAFrameRateRange(minimum: 30, maximum: 60, preferred: 60)
        displayLink?.add(to: .main, forMode: .common)

        enterState(.idle)
    }
    
    public func stop() {
        displayLink?.invalidate()
        displayLink = nil
        lipSync.stop()
        // Subsystems don't have their own DisplayLinks — nothing to stop.
    }
    
    public var isRunning: Bool { displayLink != nil }
    
    deinit { stop() }
    
    // MARK: - State Transitions
    
    /// Transition to a new behavior state.
    public func transition(to newState: BehaviorState) {
        guard newState != state else { return }
        exitState(state)
        enterState(newState)
    }
    
    private func enterState(_ newState: BehaviorState) {
        state = newState
        stateEntryTime = CACurrentMediaTime()
        stateTime = 0
        
        switch newState {
        case .idle:
            idleAnimator.isSpeaking = false
            idleAnimator.isListening = false
            gazeController.isListening = false
            gazeController.releaseGaze()
            idleAnimator.setMood(.neutral)
            emotion.setEmotion(.calm)
            
        case .listening:
            idleAnimator.isSpeaking = false
            idleAnimator.isListening = true
            gazeController.isListening = true
            gazeController.lookAt(SIMD2(0, 0))
            idleAnimator.setMood(.listening)
            emotion.setEmotion(.neutral)
            scheduleNextNod()
            
        case .speaking:
            idleAnimator.isSpeaking = true
            idleAnimator.isListening = false
            gazeController.isListening = false
            emotion.setEmotion(.happy)
            
        case .thinking:
            idleAnimator.isSpeaking = false
            gazeController.avertGaze(direction: .upLeft, duration: thinkingTimeout)
            idleAnimator.setMood(.thinking)
            emotion.setEmotion(.thinking)
            
        case .emoting:
            // Expression animator handles this externally
            break
        }
    }
    
    private func exitState(_ oldState: BehaviorState) {
        switch oldState {
        case .speaking:
            lipSync.stop()
            mixer.updateSpeakingState(isSpeaking: false)
        case .thinking:
            gazeController.releaseGaze()
        default:
            break
        }
    }
    
    // MARK: - Speaking Helpers
    
    /// Start speaking with audio analysis (no viseme data).
    public func speakWithAudio(engine: AVAudioEngine) {
        transition(to: .speaking)
        lipSync.startWithAudioEngine(engine)
        mixer.updateSpeakingState(isSpeaking: true)
    }
    
    /// Start speaking with audio node.
    public func speakWithAudioNode(_ node: AVAudioNode, engine: AVAudioEngine) {
        transition(to: .speaking)
        lipSync.startWithAudioNode(node, engine: engine)
        mixer.updateSpeakingState(isSpeaking: true)
    }
    
    /// Start speaking with pre-computed viseme keyframes (from TTS).
    public func speakWithVisemes(_ keyframes: [VisemeKeyframe]) {
        transition(to: .speaking)
        lipSync.startWithKeyframes(keyframes)
        mixer.updateSpeakingState(isSpeaking: true)
    }
    
    /// Stop speaking and return to idle.
    public func stopSpeaking() {
        transition(to: .idle)
    }
    
    // MARK: - Expression Helpers
    
    /// Play a preset expression, then return to previous state.
    public func emote(_ preset: ExpressionPreset, duration: TimeInterval = 0.3, holdFor: TimeInterval = 1.0) {
        let previousState = state

        // Seed the expression animator with current blendshape state for smooth transition
        _ = expressionAnimator.set(mixer.currentTracking.blendshapes)

        transition(to: .emoting)

        expressionAnimator.animate(to: preset, duration: duration) { [weak self] tracking in
            self?.onFrame?(tracking)
        } completion: { [weak self] in
            // Hold, then animate back to neutral before returning to previous state
            DispatchQueue.main.asyncAfter(deadline: .now() + holdFor) {
                guard let self else { return }
                // Animate back to neutral (empty blendshapes)
                self.expressionAnimator.animate(to: [:], duration: duration) { [weak self] tracking in
                    self?.onFrame?(tracking)
                } completion: { [weak self] in
                    self?.transition(to: previousState)
                }
            }
        }
    }
    
    // MARK: - Main Loop (State Behavior)
    
    @objc private func tick() {
        let now = CACurrentMediaTime()
        stateTime = now - stateEntryTime

        // Drive subsystems from this single DisplayLink.
        // Skip idle/lipSync when emoting — ExpressionAnimator drives onFrame directly.
        if state != .emoting {
            // Note: gazeController and headGesture are ticked inside mixer.onFrame
            // (after idle produces its output) so they merge in the same frame.
            idleAnimator.externalTick()
            lipSync.externalTick()
        }

        switch state {
        case .idle:
            tickIdle(now: now)
        case .listening:
            tickListening(now: now)
        case .speaking:
            tickSpeaking(now: now)
        case .thinking:
            tickThinking(now: now)
        case .emoting:
            break // handled by ExpressionAnimator
        }
        
        lastTime = now
    }
    
    private func tickIdle(now: TimeInterval) {
        // Idle: nothing special, subsystems handle themselves
    }
    
    private func tickListening(now: TimeInterval) {
        // Tell idle animator we're listening (affects blink rate, attention)
        idleAnimator.isListening = true
        
        // Research (Hale et al. 2020): Listener nod patterns
        // 1. Mimicry nods at 600ms delay following speaker's head movement
        // 2. Fast nodding (>1.5Hz) = backchannel "I'm following"
        // 3. Triple-nod clusters encourage speaker to continue
        if now >= nextNodTime {
            let roll = Float.random(in: 0...1)
            if roll < 0.45 {
                // Single nod — basic acknowledgment
                headGesture.nod(intensity: Float.random(in: 0.5...0.8))
            } else if roll < 0.7 {
                // Double nod — stronger agreement
                headGesture.doubleNod(intensity: 0.7)
            } else if roll < 0.85 {
                // Triple nod cluster — "keep going" signal
                headGesture.nod(intensity: 0.5)
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.3) { [weak self] in
                    self?.headGesture.nod(intensity: 0.4)
                }
                DispatchQueue.main.asyncAfter(deadline: .now() + 0.6) { [weak self] in
                    self?.headGesture.nod(intensity: 0.3)
                }
            } else {
                // Tilt-nod — thoughtful listening
                headGesture.play(.tiltNod, intensity: 0.6)
            }
            scheduleNextNod()
        }
        
        // Research (Max Planck 2025): Eyebrow signals during listening
        // Furrow = "I don't understand" → speaker elaborates
        // Raise = "tell me more" / surprise
        // We don't auto-trigger these — they should be driven by comprehension state
        // But we DO ensure gaze is maintained (70% eye contact for listeners)
    }
    
    private func tickSpeaking(now: TimeInterval) {
        idleAnimator.isListening = false
        
        // Emphasis nods on audio energy peaks
        let energy = idleAnimator.audioEnergy
        if energy > 0.3 && (now - lastEnergyPeak) > 0.8 {
            headGesture.nod(intensity: min(energy * 2, 1.0))
            lastEnergyPeak = now
            
            // Research: Brow raise accompanies vocal emphasis
            if energy > 0.5 {
                emotion.nudge(arousal: 0.1) // brief arousal spike
            }
        }
        
        // Research (Microsoft): Speakers look away ~60% of time
        // But look BACK at listener before turn end (turn-taking signal)
        if stateTime > 2.0 {
            let cyclePos = stateTime.truncatingRemainder(dividingBy: 3.0)
            if cyclePos < 0.1 { // check once per 3s cycle
                let shouldAvert = Float.random(in: 0...1) < 0.55
                if shouldAvert {
                    gazeController.avertGaze(
                        direction: [.left, .right, .upLeft, .upRight].randomElement()!,
                        duration: Double.random(in: 0.8...2.0)
                    )
                } else {
                    // Look back at listener
                    gazeController.lookAt(SIMD2(0, 0))
                }
            }
        }
    }
    
    /// Signal that speaking is about to end.
    /// Research: speakers look at listener before yielding the turn.
    public func willStopSpeaking() {
        gazeController.lookAt(SIMD2(0, 0)) // look at listener
    }
    
    private func tickThinking(now: TimeInterval) {
        // Auto-return from thinking after timeout
        if stateTime > thinkingTimeout {
            transition(to: .idle)
        }
    }
    
    // MARK: - Helpers
    
    private func scheduleNextNod() {
        let interval = TimeInterval.random(in: nodInterval)
        nextNodTime = CACurrentMediaTime() + interval
    }
}

// MARK: - AVFoundation Import

import AVFoundation
