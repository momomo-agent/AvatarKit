import Foundation
import QuartzCore
import simd

// MARK: - Gaze Controller

/// Controls avatar eye gaze with biologically-grounded saccade dynamics.
///
/// Based on:
/// - Ruhland et al. (2015): "A Review of Eye Gaze in Virtual Agents"
///   - Fixation duration: 200-600ms (normal distribution, μ=350ms)
///   - Saccade velocity: Ev = 473(1 - e^(-E/7.8))°/s (main sequence)
///   - Mutual gaze: listener looks at speaker ~70% of time
///
/// - Lee et al. (2002): "Eyes Alive" — USC ICT neurobiological model
///   - Saccade amplitude: exponential distribution, μ=5° for micro, μ=15° for macro
///   - Gaze aversion: look away when thinking (up-left), recalling (down-left)
///
/// - Canales et al. (2023): "Real-Time Conversational Gaze Synthesis"
///   - Turn-taking gaze: look at speaker during listen, look away during speech planning
///
/// Output: eye look blendshapes (eyeLookIn/Out/Up/Down L/R) + optional head contribution.
public class AvatarGazeController {
    
    // MARK: - Configuration
    
    /// Master intensity (0 = off, 1 = full).
    public var intensity: Float = 1.0
    
    /// How much head follows gaze (0 = eyes only, 1 = full head-eye coordination).
    /// Literature: head contributes ~30-50% of gaze shift for targets >15°.
    public var headContribution: Float = 0.35
    
    /// Whether the avatar is currently the listener (affects gaze patterns).
    public var isListening = true
    
    /// External gaze target in normalized coordinates (-1..1, -1..1).
    /// Set to nil for autonomous gaze behavior.
    public var gazeTarget: SIMD2<Float>? = nil
    
    /// Called every frame with eye blendshapes and head rotation delta.
    public var onFrame: ((_ eyeBlendshapes: [String: Float], _ headDelta: SIMD2<Float>) -> Void)?
    
    // MARK: - State
    
    /// Current eye position in normalized space (-1..1 horizontal, -1..1 vertical).
    private(set) var currentEyePosition: SIMD2<Float> = .zero
    
    /// Current gaze target.
    private var targetPosition: SIMD2<Float> = .zero
    
    /// Saccade in progress.
    private var saccadeActive = false
    private var saccadeStart: SIMD2<Float> = .zero
    private var saccadeEnd: SIMD2<Float> = .zero
    private var saccadeStartTime: TimeInterval = 0
    private var saccadeDuration: TimeInterval = 0
    
    /// Fixation timer.
    private var nextSaccadeTime: TimeInterval = 0
    
    /// Gaze aversion state.
    private var isAverting = false
    private var aversionDirection: GazeAversionDirection = .upLeft
    
    /// Mutual gaze probability (varies by role).
    private var mutualGazeProbability: Float = 0.7
    
    private var displayLink: CADisplayLink?
    private var lastTime: TimeInterval = 0
    
    // MARK: - Types
    
    /// Direction of gaze aversion (based on cognitive load research).
    public enum GazeAversionDirection {
        case upLeft     // Thinking / constructing
        case upRight    // Visual recall
        case downLeft   // Internal dialogue
        case downRight  // Emotional processing
        case left       // Auditory construction
        case right      // Auditory recall
        
        var offset: SIMD2<Float> {
            switch self {
            case .upLeft:    return SIMD2(-0.6, 0.4)
            case .upRight:   return SIMD2(0.6, 0.4)
            case .downLeft:  return SIMD2(-0.5, -0.3)
            case .downRight: return SIMD2(0.5, -0.3)
            case .left:      return SIMD2(-0.7, 0.0)
            case .right:     return SIMD2(0.7, 0.0)
            }
        }
    }
    
    // MARK: - Lifecycle
    
    public init() {
        scheduleNextFixation(from: CACurrentMediaTime())
    }
    
    public func start() {
        lastTime = CACurrentMediaTime()
    }
    
    public func stop() {
        // Driven externally by BehaviorEngine
    }
    
    public var isRunning: Bool { true }
    
    // MARK: - Public Control
    
    /// Trigger a gaze aversion (look away). Used when avatar starts thinking.
    public func avertGaze(direction: GazeAversionDirection = .upLeft, duration: TimeInterval = 1.5) {
        isAverting = true
        aversionDirection = direction
        targetPosition = direction.offset
        triggerSaccade(to: targetPosition, from: CACurrentMediaTime())
        
        // Schedule return to forward gaze
        nextSaccadeTime = CACurrentMediaTime() + duration
    }
    
    /// Look at a specific point. Coordinates: x (-1=left, 1=right), y (-1=down, 1=up).
    public func lookAt(_ point: SIMD2<Float>) {
        isAverting = false
        gazeTarget = point
    }
    
    /// Return to autonomous gaze behavior.
    public func releaseGaze() {
        gazeTarget = nil
        isAverting = false
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
        if lastTime == 0 { lastTime = now }
        let dt = Float(now - lastTime)
        lastTime = now
        guard dt > 0, dt < 0.5 else { return }
        
        // Update saccade if active
        if saccadeActive {
            let elapsed = now - saccadeStartTime
            let t = Float(min(elapsed / saccadeDuration, 1.0))
            
            // Saccade trajectory: fast start, slight overshoot, settle
            // Based on main sequence dynamics
            let easedT = saccadeEasing(t)
            currentEyePosition = saccadeStart + (saccadeEnd - saccadeStart) * easedT
            
            if t >= 1.0 {
                saccadeActive = false
                currentEyePosition = saccadeEnd
            }
        }
        
        // Check if it's time for a new saccade
        if !saccadeActive && now >= nextSaccadeTime {
            if let target = gazeTarget {
                // External target: saccade to it
                triggerSaccade(to: target, from: now)
                scheduleNextFixation(from: now)
            } else if isAverting {
                // Return from aversion
                isAverting = false
                triggerSaccade(to: .zero, from: now)
                scheduleNextFixation(from: now)
            } else {
                // Autonomous behavior
                generateAutonomousSaccade(at: now)
            }
        }
        
        // Convert eye position to blendshapes
        let blendshapes = eyePositionToBlendshapes(currentEyePosition)
        
        // Head contribution
        let headDelta = currentEyePosition * headContribution
        
        onFrame?(blendshapes, headDelta)
    }
    
    // MARK: - Saccade Generation
    
    private func generateAutonomousSaccade(at now: TimeInterval) {
        // Decide: mutual gaze or look away?
        let lookAtTarget = Float.random(in: 0...1) < mutualGazeProbability
        
        let newTarget: SIMD2<Float>
        if lookAtTarget && isListening {
            // Look at speaker (center with small jitter)
            newTarget = SIMD2(
                Float.random(in: -0.1...0.1),
                Float.random(in: -0.05...0.05)
            )
        } else {
            // Micro-saccade: small random shift
            // Amplitude: exponential distribution, mean ~5° → ~0.15 normalized
            let amplitude = -0.15 * log(Float.random(in: 0.01...1.0))
            let angle = Float.random(in: 0...(2 * .pi))
            let dx = cos(angle) * min(amplitude, 0.5)
            let dy = sin(angle) * min(amplitude, 0.3)
            newTarget = SIMD2(
                max(-0.8, min(0.8, currentEyePosition.x + dx)),
                max(-0.5, min(0.5, currentEyePosition.y + dy))
            )
        }
        
        triggerSaccade(to: newTarget, from: now)
        scheduleNextFixation(from: now)
    }
    
    private func triggerSaccade(to target: SIMD2<Float>, from now: TimeInterval) {
        saccadeStart = currentEyePosition
        saccadeEnd = target
        saccadeStartTime = now
        
        // Duration based on amplitude (main sequence relationship)
        // Small saccades (~5°): ~30ms, large (~30°): ~80ms
        let amplitude = simd_length(target - currentEyePosition)
        let degrees = amplitude * 30.0 // rough: 1.0 normalized ≈ 30°
        saccadeDuration = TimeInterval(0.02 + degrees * 0.002) // 20-80ms
        saccadeDuration = max(0.02, min(saccadeDuration, 0.1))
        
        saccadeActive = true
    }
    
    private func scheduleNextFixation(from now: TimeInterval) {
        // Fixation duration: normal distribution, μ=350ms, σ=100ms
        // Range clamped to 150-800ms
        let u1 = Double.random(in: 0.001...1.0)
        let u2 = Double.random(in: 0.001...1.0)
        let gaussian = sqrt(-2.0 * log(u1)) * cos(2.0 * .pi * u2)
        let duration = max(0.15, min(0.8, 0.35 + gaussian * 0.1))
        nextSaccadeTime = now + duration
        
        // Update mutual gaze probability based on role
        mutualGazeProbability = isListening ? 0.7 : 0.4
    }
    
    // MARK: - Saccade Easing
    
    /// Saccade velocity profile: fast acceleration, slight overshoot, settle.
    /// Models the "main sequence" relationship.
    private func saccadeEasing(_ t: Float) -> Float {
        if t < 0.7 {
            // Fast phase: cubic ease-in
            let normalized = t / 0.7
            return normalized * normalized * (3.0 - 2.0 * normalized) * 1.05 // slight overshoot
        } else {
            // Settle phase: ease back from overshoot
            let normalized = (t - 0.7) / 0.3
            return 1.05 - 0.05 * normalized // 1.05 → 1.0
        }
    }
    
    // MARK: - Blendshape Conversion
    
    private func eyePositionToBlendshapes(_ pos: SIMD2<Float>) -> [String: Float] {
        var bs: [String: Float] = [:]
        let x = pos.x * intensity
        let y = pos.y * intensity
        
        // Horizontal: positive = look right
        if x > 0 {
            bs["eyeLookOutRight"] = x * 0.4
            bs["eyeLookInLeft"] = x * 0.4
        } else {
            bs["eyeLookOutLeft"] = -x * 0.4
            bs["eyeLookInRight"] = -x * 0.4
        }
        
        // Vertical: positive = look up
        if y > 0 {
            bs["eyeLookUpLeft"] = y * 0.3
            bs["eyeLookUpRight"] = y * 0.3
        } else {
            bs["eyeLookDownLeft"] = -y * 0.3
            bs["eyeLookDownRight"] = -y * 0.3
        }
        
        return bs
    }
}
