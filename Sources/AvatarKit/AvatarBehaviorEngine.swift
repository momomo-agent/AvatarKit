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
    
    // Head gesture output
    private var gesturePitch: Float = 0
    private var gestureYaw: Float = 0
    private var gestureRoll: Float = 0
    
    // MARK: - Init
    
    public init() {
        lipSync = AvatarLipSync()
        idleAnimator = AvatarIdleAnimator()
        gazeController = AvatarGazeController()
        headGesture = AvatarHeadGesture()
        expressionAnimator = ExpressionAnimator()
        mixer = AvatarAnimationMixer()
        
        // Wire subsystems
        mixer.lipSync = lipSync
        mixer.idleAnimator = idleAnimator
        
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
            
            // Add gaze eye blendshapes
            for (key, value) in self.gazeEyeBlendshapes {
                merged.blendshapes[key] = (merged.blendshapes[key] ?? 0) + value
            }
            
            // Add gaze head contribution + gesture head rotation
            let totalHeadPitch = self.gazeHeadDelta.y * 10 + self.gesturePitch
            let totalHeadYaw = self.gazeHeadDelta.x * 10 + self.gestureYaw
            let totalHeadRoll = self.gestureRoll
            
            if abs(totalHeadPitch) > 0.01 || abs(totalHeadYaw) > 0.01 || abs(totalHeadRoll) > 0.01 {
                merged.headRotation.pitch += totalHeadPitch
                merged.headRotation.yaw += totalHeadYaw
                merged.headRotation.roll += totalHeadRoll
            }
            
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
        
        idleAnimator.start()
        gazeController.start()
        headGesture.start()
        
        displayLink = CADisplayLink(target: self, selector: #selector(tick))
        displayLink?.preferredFrameRateRange = CAFrameRateRange(minimum: 10, maximum: 30, preferred: 30)
        displayLink?.add(to: .main, forMode: .common)
        
        enterState(.idle)
    }
    
    public func stop() {
        displayLink?.invalidate()
        displayLink = nil
        lipSync.stop()
        idleAnimator.stop()
        gazeController.stop()
        headGesture.stop()
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
            gazeController.isListening = false
            gazeController.releaseGaze()
            idleAnimator.setMood(.neutral)
            emotion.setEmotion(.calm)
            
        case .listening:
            idleAnimator.isSpeaking = false
            gazeController.isListening = true
            gazeController.lookAt(SIMD2(0, 0)) // look at speaker
            idleAnimator.setMood(.neutral)
            emotion.setEmotion(.neutral)
            scheduleNextNod()
            
        case .speaking:
            idleAnimator.isSpeaking = true
            gazeController.isListening = false
            emotion.setEmotion(.happy) // default speaking emotion
            
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
        transition(to: .emoting)
        
        expressionAnimator.animate(to: preset, duration: duration) { [weak self] tracking in
            self?.onFrame?(tracking)
        } completion: { [weak self] in
            // Hold, then return
            DispatchQueue.main.asyncAfter(deadline: .now() + holdFor) {
                self?.transition(to: previousState)
            }
        }
    }
    
    // MARK: - Main Loop (State Behavior)
    
    @objc private func tick() {
        let now = CACurrentMediaTime()
        stateTime = now - stateEntryTime
        
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
        // Periodic nods while listening
        if now >= nextNodTime {
            // Vary nod type
            let roll = Float.random(in: 0...1)
            if roll < 0.6 {
                headGesture.nod(intensity: Float.random(in: 0.5...1.0))
            } else if roll < 0.85 {
                headGesture.doubleNod(intensity: 0.7)
            } else {
                headGesture.play(.tiltNod, intensity: 0.6)
            }
            scheduleNextNod()
        }
    }
    
    private func tickSpeaking(now: TimeInterval) {
        // Emphasis nods on audio energy peaks
        let energy = idleAnimator.audioEnergy
        if energy > 0.3 && (now - lastEnergyPeak) > 0.8 {
            headGesture.nod(intensity: min(energy * 2, 1.0))
            lastEnergyPeak = now
            
            // Brow raise on strong emphasis (Disney-level detail)
            if energy > 0.5 {
                // Brief brow flash accompanies vocal emphasis
                // This is handled by the emotion engine nudge
            }
        }
        
        // Periodic gaze aversion while speaking (speakers look away ~60% of time)
        if stateTime > 2.0 && Int(stateTime * 2) % 5 == 0 {
            let shouldAvert = Float.random(in: 0...1) < 0.4
            if shouldAvert {
                gazeController.avertGaze(
                    direction: [.left, .right, .upLeft, .upRight].randomElement()!,
                    duration: Double.random(in: 0.5...1.5)
                )
            }
        }
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
