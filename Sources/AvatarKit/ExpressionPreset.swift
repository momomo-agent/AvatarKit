import Foundation
import QuartzCore

// MARK: - Expression Presets

/// Named expression presets — sparse blendshape dictionaries.
///
/// Each preset only specifies the blendshapes that matter for that expression.
/// Unspecified blendshapes use the -1.0 sentinel (skip/preserve previous value).
///
/// Usage:
/// ```swift
/// let tracking = ExpressionPreset.smile.tracking()
/// bridge.applyTracking(tracking)
/// ```
public struct ExpressionPreset: Sendable {
    
    public let name: String
    public let blendshapes: [String: Float]
    
    /// Convert to AvatarFaceTracking with optional head pose.
    public func tracking(
        pitch: Float = 0,
        yaw: Float = 0
    ) -> AvatarFaceTracking {
        AvatarFaceTracking(
            blendshapes: blendshapes,
            headRotation: .init(pitch: pitch, yaw: yaw, roll: 0),
            timestamp: CACurrentMediaTime()
        )
    }
}

// MARK: - Built-in Presets

extension ExpressionPreset {
    
    /// Neutral face — all blendshapes at 0.
    public static let neutral = ExpressionPreset(
        name: "neutral",
        blendshapes: Dictionary(
            uniqueKeysWithValues: BlendshapeOrder.names.map { ($0, Float(0)) }
        )
    )
    
    /// Smile.
    public static let smile = ExpressionPreset(
        name: "smile",
        blendshapes: [
            "mouthSmileLeft": 0.8,
            "mouthSmileRight": 0.8,
            "cheekSquintLeft": 0.3,
            "cheekSquintRight": 0.3,
            "jawOpen": 0.1,
        ]
    )
    
    /// Big grin.
    public static let grin = ExpressionPreset(
        name: "grin",
        blendshapes: [
            "mouthSmileLeft": 1.0,
            "mouthSmileRight": 1.0,
            "cheekSquintLeft": 0.5,
            "cheekSquintRight": 0.5,
            "jawOpen": 0.3,
            "eyeSquintLeft": 0.3,
            "eyeSquintRight": 0.3,
        ]
    )
    
    /// Surprised / shocked.
    public static let surprised = ExpressionPreset(
        name: "surprised",
        blendshapes: [
            "jawOpen": 0.7,
            "eyeWideLeft": 0.8,
            "eyeWideRight": 0.8,
            "browInnerUp": 0.6,
            "browOuterUpLeft": 0.5,
            "browOuterUpRight": 0.5,
        ]
    )
    
    /// Sad / frown.
    public static let sad = ExpressionPreset(
        name: "sad",
        blendshapes: [
            "mouthFrownLeft": 0.7,
            "mouthFrownRight": 0.7,
            "browDownLeft": 0.3,
            "browDownRight": 0.3,
            "browInnerUp": 0.5,
            "mouthPucker": 0.2,
        ]
    )
    
    /// Angry.
    public static let angry = ExpressionPreset(
        name: "angry",
        blendshapes: [
            "browDownLeft": 0.8,
            "browDownRight": 0.8,
            "eyeSquintLeft": 0.5,
            "eyeSquintRight": 0.5,
            "jawForward": 0.3,
            "mouthPressLeft": 0.4,
            "mouthPressRight": 0.4,
            "noseSneerLeft": 0.5,
            "noseSneerRight": 0.5,
        ]
    )
    
    /// Wink (left eye).
    public static let winkLeft = ExpressionPreset(
        name: "winkLeft",
        blendshapes: [
            "eyeBlinkLeft": 0.9,
            "mouthSmileLeft": 0.5,
            "mouthSmileRight": 0.3,
            "cheekSquintLeft": 0.4,
        ]
    )
    
    /// Wink (right eye).
    public static let winkRight = ExpressionPreset(
        name: "winkRight",
        blendshapes: [
            "eyeBlinkRight": 0.9,
            "mouthSmileRight": 0.5,
            "mouthSmileLeft": 0.3,
            "cheekSquintRight": 0.4,
        ]
    )
    
    /// Tongue out.
    public static let tongueOut = ExpressionPreset(
        name: "tongueOut",
        blendshapes: [
            "jawOpen": 0.5,
            "tongueOut": 0.8,
            "mouthSmileLeft": 0.3,
            "mouthSmileRight": 0.3,
        ]
    )
    
    /// Thinking — slight head tilt, raised brow.
    public static let thinking = ExpressionPreset(
        name: "thinking",
        blendshapes: [
            "browOuterUpLeft": 0.6,
            "eyeLookUpLeft": 0.4,
            "eyeLookUpRight": 0.4,
            "mouthPucker": 0.3,
            "mouthLeft": 0.2,
        ]
    )
    
    /// Sleepy — droopy eyes.
    public static let sleepy = ExpressionPreset(
        name: "sleepy",
        blendshapes: [
            "eyeBlinkLeft": 0.6,
            "eyeBlinkRight": 0.6,
            "jawOpen": 0.15,
            "mouthStretchLeft": 0.2,
            "mouthStretchRight": 0.2,
        ]
    )
    
    /// All built-in presets.
    public static let all: [ExpressionPreset] = [
        .neutral, .smile, .grin, .surprised, .sad, .angry,
        .winkLeft, .winkRight, .tongueOut, .thinking, .sleepy,
    ]
}
