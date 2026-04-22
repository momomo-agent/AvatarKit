import Foundation
import simd

// MARK: - Performative Pose System

/// Apple-sourced expression poses for performative animation.
/// These are professional animator-tuned blendshape + neck orientation presets
/// extracted from AvatarKitContent.framework pose packs.
///
/// Usage: BehaviorEngine triggers pose transitions based on semantic context
/// (not random timing). The poses blend additively with the continuous
/// idle animation layer.
public struct PerformativePose {
    public let name: String
    public let blendshapes: [String: Float]
    public let neckOrientation: simd_quatf
    
    /// How strongly this pose should blend (0-1). Allows partial expressions.
    public var blendFactor: Float = 1.0
}

// MARK: - Pose Library

public enum PoseLibrary {
    
    /// All available poses, keyed by semantic name.
    public static let poses: [String: PerformativePose] = {
        var lib: [String: PerformativePose] = [:]
        for (name, data) in rawPoses {
            let bs = data.blendshapes.mapValues { Float($0) }
            let q = data.neckOrientation
            let quat = simd_quatf(ix: q[0], iy: q[1], iz: q[2], r: q[3])
            lib[name] = PerformativePose(name: name, blendshapes: bs, neckOrientation: quat)
        }
        return lib
    }()
    
    /// Poses suitable for speaking emphasis moments.
    public static let speakingEmphasis: [String] = [
        "big_happy", "surprise", "proud", "one_raised_eyebrow"
    ]
    
    /// Poses for listening/engaged reactions.
    public static let listeningReactions: [String] = [
        "happy", "head_tilt", "pleasant_neutral", "surprise"
    ]
    
    /// Poses for thinking/contemplation.
    public static let thinkingPoses: [String] = [
        "pleasant_neutral", "grizzled", "pursed_lips"
    ]
    
    /// Poses for playful/casual moments.
    public static let playful: [String] = [
        "wink", "tongue_out", "front_pucker"
    ]
    
    // MARK: - Raw Data (from Apple AvatarKitContent.framework posesPack)
    
    private struct RawPose {
        let blendshapes: [String: Double]
        let neckOrientation: [Float]
    }
    
    private static let rawPoses: [String: RawPose] = [
        "happy": RawPose(
            blendshapes: [
                "browInnerUp": 0.124204, "browOuterUp_L": 0.219745, "browOuterUp_R": 0.347134,
                "cheekSquint_L": 0.528662, "cheekSquint_R": 0.547771,
                "eyeBlink_L": 0.439491, "eyeBlink_R": 0.468153,
                "eyeLookDown_L": 0.092357, "eyeLookDown_R": 0.092357,
                "eyeSquint_L": 0.88535, "eyeSquint_R": 0.821656,
                "jawOpen": 0.210191,
                "mouthDimple_L": 0.738854, "mouthDimple_R": 0.71656,
                "mouthLeft": 0.117834,
                "mouthSmile_L": 0.694268, "mouthSmile_R": 0.732484,
                "mouthStretch_L": 0.035032, "mouthStretch_R": 0.098726,
                "mouthUpperUp_L": 0.117834, "mouthUpperUp_R": 0.130573,
            ],
            neckOrientation: [-0.045111, 0, 0, 0.998982]
        ),
        "big_happy": RawPose(
            blendshapes: [
                "browInnerUp": 0.557325, "browOuterUp_L": 0.917197, "browOuterUp_R": 0.592357,
                "cheekSquint_L": 0.707006, "cheekSquint_R": 0.859873,
                "eyeLookUp_L": 0.092357, "eyeLookUp_R": 0.073248,
                "eyeSquint_L": 0.528662, "eyeSquint_R": 0.468153,
                "eyeWide_L": 0.531847, "eyeWide_R": 0.423567,
                "jawOpen": 0.754777,
                "mouthDimple_L": 0.640127, "mouthDimple_R": 0.49363,
                "mouthLeft": 0.10828,
                "mouthSmile_L": 0.917197, "mouthSmile_R": 0.866242,
                "mouthUpperUp_L": 0.300275, "mouthUpperUp_R": 0.333333,
                "noseSneer_L": 0.398089, "noseSneer_R": 0.111465,
            ],
            neckOrientation: [0.009481, 0.000208, -0.036338, 0.999295]
        ),
        "surprise": RawPose(
            blendshapes: [
                "browInnerUp": 0.980892, "browOuterUp_L": 0.882166, "browOuterUp_R": 0.821656,
                "eyeLookDown_R": 0.057325, "eyeLookIn_R": 0.095541,
                "eyeLookOut_L": 0.063694, "eyeLookUp_R": 0.003185,
                "eyeWide_L": 0.77707, "eyeWide_R": 0.61465,
                "jawOpen": 0.627388,
                "mouthClose": 0.143312, "mouthFunnel": 0.579618,
                "mouthLeft": 0.140127, "mouthPucker": 0.321656,
                "mouthSmile_L": 0.156051, "mouthSmile_R": 0.117835,
            ],
            neckOrientation: [-0.026227, -0.037106, -0.049982, 0.997716]
        ),
        "annoyed": RawPose(
            blendshapes: [
                "browDown_L": 0.114094, "browDown_R": 0.600671,
                "cheekPuff": 0.234899, "cheekSquint_L": 0.543624,
                "eyeBlink_L": 0.194631, "eyeBlink_R": 0.295302,
                "eyeLookIn_L": 0.145161, "eyeLookOut_R": 0.158065,
                "eyeLookUp_L": 0.087097, "eyeLookUp_R": 0.090323,
                "mouthFrown_L": 0.051613, "mouthFrown_R": 0.103226,
                "mouthLeft": 1.0, "mouthPress_R": 0.429032,
                "mouthShrugLower": 0.316129, "mouthShrugUpper": 0.316129,
                "noseSneer_L": 0.329032, "noseSneer_R": 0.132258,
            ],
            neckOrientation: [0.024252, 0.061797, 0.028874, 0.997376]
        ),
        "head_tilt": RawPose(
            blendshapes: [
                "browInnerUp": 0.42069, "browOuterUp_L": 0.411494, "browOuterUp_R": 0.308046,
                "cheekSquint_L": 0.475862, "cheekSquint_R": 0.429885,
                "eyeLookIn_L": 0.114943, "eyeLookOut_R": 0.094253,
                "eyeSquint_L": 0.425287, "eyeSquint_R": 0.370115,
                "jawOpen": 0.285058,
                "mouthDimple_L": 0.406619, "mouthDimple_R": 0.302601,
                "mouthRight": 0.222222,
                "mouthSmile_L": 0.689655, "mouthSmile_R": 0.629885,
                "mouthStretch_R": 0.229314, "mouthUpperUp_R": 0.208038,
            ],
            neckOrientation: [-0.158073, 0.157772, -0.168072, 0.960142]
        ),
        "one_raised_eyebrow": RawPose(
            blendshapes: [
                "browDown_L": 0.802548, "browInnerUp": 0.617834, "browOuterUp_R": 1.0,
                "cheekSquint_L": 0.165605, "cheekSquint_R": 0.39172,
                "eyeBlink_L": 0.187898, "eyeBlink_R": 0.133758,
                "eyeLookIn_L": 0.22293, "eyeLookOut_R": 0.121019,
                "eyeSquint_L": 0.375796, "eyeSquint_R": 0.347134,
                "mouthDimple_R": 0.592357,
                "mouthPress_L": 0.496815, "mouthPress_R": 0.207006,
                "mouthRight": 0.350318,
                "mouthShrugLower": 0.16242, "mouthShrugUpper": 0.159236,
                "mouthSmile_L": 0.245223, "mouthSmile_R": 0.22293,
                "mouthStretch_L": 0.10828, "mouthStretch_R": 0.187898,
            ],
            neckOrientation: [0.013799, 0.092764, 0.051293, 0.99427]
        ),
        "pleasant_neutral": RawPose(
            blendshapes: [
                "browInnerUp": 0.5, "browOuterUp_L": 0.280255, "browOuterUp_R": 0.694267,
                "cheekSquint_L": 0.33758, "cheekSquint_R": 0.480892,
                "eyeBlink_L": 0.165605, "eyeBlink_R": 0.070064,
                "eyeLookDown_L": 0.105096, "eyeLookDown_R": 0.070064,
                "eyeLookIn_L": 0.286688, "eyeLookOut_R": 0.135159,
                "eyeSquint_L": 0.468153, "eyeSquint_R": 0.436306,
                "jawOpen": 0.098726, "mouthClose": 0.095541,
                "mouthDimple_L": 0.308917, "mouthDimple_R": 0.535032,
                "mouthPress_L": 0.203822, "mouthPress_R": 0.267516,
                "mouthPucker": 0.095541, "mouthRight": 0.124204,
                "mouthShrugLower": 0.235669, "mouthShrugUpper": 0.238854,
                "mouthSmile_L": 0.242038, "mouthSmile_R": 0.261147,
            ],
            neckOrientation: [0.010161, 0.16331, 0.051009, 0.985203]
        ),
        "proud": RawPose(
            blendshapes: [
                "browInnerUp": 0.805733, "browOuterUp_L": 0.308917, "browOuterUp_R": 0.375796,
                "cheekSquint_L": 0.423567, "cheekSquint_R": 0.621019,
                "eyeBlink_L": 0.143312, "eyeBlink_R": 0.149682,
                "eyeLookDown_L": 0.17, "eyeLookDown_R": 0.17,
                "eyeLookIn_R": 0.12, "eyeLookOut_L": 0.08,
                "eyeSquint_L": 0.063694, "eyeSquint_R": 0.133758,
                "jawOpen": 0.117834, "mouthClose": 0.117834,
                "mouthDimple_L": 0.675159, "mouthDimple_R": 0.592357,
                "mouthLeft": 0.079618,
                "mouthPress_L": 0.171975, "mouthPress_R": 0.238853,
                "mouthShrugLower": 0.165605, "mouthShrugUpper": 0.16242,
                "mouthSmile_L": 0.49363, "mouthSmile_R": 0.372612,
            ],
            neckOrientation: [-0.070333, -0.04841, -0.012201, 0.996274]
        ),
        "grizzled": RawPose(
            blendshapes: [
                "browDown_L": 0.2, "browDown_R": 0.7, "browInnerUp": 0.098726,
                "cheekSquint_L": 0.29, "cheekSquint_R": 0.289809,
                "eyeBlink_L": 0.2, "eyeBlink_R": 0.217,
                "eyeLookDown_L": 0.194268, "eyeLookDown_R": 0.066879,
                "eyeLookIn_L": 0.194268, "eyeLookIn_R": 0.15,
                "eyeLookOut_L": 0.05, "eyeLookOut_R": 0.111465,
                "eyeLookUp_L": 0.02, "eyeLookUp_R": 0.02,
                "eyeSquint_L": 0.238854, "eyeSquint_R": 0.273885,
                "mouthDimple_L": 0.255, "mouthLeft": 0.162,
                "mouthPress_L": 0.518, "mouthPress_R": 0.361,
                "noseSneer_L": 0.197, "noseSneer_R": 0.197452,
            ],
            neckOrientation: [-0.008986, -0.079711, -0.111663, 0.990503]
        ),
        "pursed_lips": RawPose(
            blendshapes: [
                "browInnerUp": 0.312102, "browOuterUp_L": 0.39172,
                "cheekSquint_L": 0.582803, "cheekSquint_R": 0.595541,
                "eyeBlink_L": 0.121019, "eyeBlink_R": 0.124204,
                "eyeLookIn_R": 0.343949, "eyeLookOut_L": 0.33121,
                "eyeLookUp_L": 0.050955, "eyeLookUp_R": 0.076433,
                "eyeSquint_L": 0.662421, "eyeSquint_R": 0.770701,
                "mouthPress_L": 0.006369, "mouthPress_R": 0.156051,
                "mouthPucker": 1.0, "mouthRight": 0.095541,
                "mouthSmile_L": 0.079618, "mouthSmile_R": 0.076433,
            ],
            neckOrientation: [0.005898, -0.147409, 0.084422, 0.985449]
        ),
        "wink": RawPose(
            blendshapes: [
                "browDown_R": 0.484076, "browInnerUp": 0.261147, "browOuterUp_L": 0.535032,
                "cheekSquint_L": 0.388535, "cheekSquint_R": 1.0,
                "eyeBlink_L": 0.136943, "eyeBlink_R": 1.0,
                "eyeLookIn_L": 0.429936, "eyeLookOut_R": 0.423567,
                "eyeSquint_L": 0.840764, "eyeSquint_R": 1.0,
                "jawOpen": 0.315287, "mouthClose": 0.095541,
                "mouthDimple_L": 0.818472, "mouthDimple_R": 0.993631,
                "mouthPress_L": 0.22293, "mouthPress_R": 0.468153,
                "mouthRight": 0.439491,
                "mouthShrugLower": 0.191083,
                "mouthSmile_L": 0.585987, "mouthSmile_R": 0.812102,
                "mouthStretch_R": 0.171975,
                "noseSneer_L": 0.194268, "noseSneer_R": 0.232484,
            ],
            neckOrientation: [-0.020193, 0.12597, -0.075179, 0.988975]
        ),
    ]
}

// MARK: - Pose Blender

/// Blends performative poses with continuous idle animation output.
/// Handles smooth transitions between poses with configurable timing.
public class PoseBlender {
    
    /// Current active pose (nil = no performative overlay).
    public private(set) var activePose: PerformativePose?
    
    /// Transition progress (0 = previous pose, 1 = target pose).
    public private(set) var transitionProgress: Float = 1.0
    
    /// Current effective blend factor after transition.
    public var effectiveBlend: Float {
        guard activePose != nil else { return 0 }
        return transitionProgress * (activePose?.blendFactor ?? 0)
    }
    
    private var previousBlendshapes: [String: Float] = [:]
    private var transitionDuration: Float = 0.4
    private var transitionTime: Float = 0
    
    /// Transition to a new pose with smooth blending.
    public func transition(to pose: PerformativePose?, duration: Float = 0.4) {
        // Capture current state as "previous"
        if let current = activePose, transitionProgress > 0 {
            previousBlendshapes = interpolatedBlendshapes()
        } else {
            previousBlendshapes = [:]
        }
        activePose = pose
        transitionDuration = max(duration, 0.05)
        transitionTime = 0
        transitionProgress = 0
    }
    
    /// Clear the active pose (fade out).
    public func clear(duration: Float = 0.3) {
        transition(to: nil, duration: duration)
    }
    
    /// Tick the blender. Call every frame.
    public func update(dt: Float) {
        guard transitionProgress < 1.0 else { return }
        transitionTime += dt
        transitionProgress = min(transitionTime / transitionDuration, 1.0)
        // Ease in-out for smooth transitions
        transitionProgress = smoothStep(transitionProgress)
    }
    
    /// Get the current blended blendshapes to ADD to idle output.
    /// Returns empty dict if no pose is active.
    public func blendshapes() -> [String: Float] {
        return interpolatedBlendshapes()
    }
    
    /// Get the current neck orientation contribution.
    /// Returns identity if no pose is active.
    public func neckOrientation() -> simd_quatf {
        guard let pose = activePose else {
            if !previousBlendshapes.isEmpty && transitionProgress < 1.0 {
                // Fading out — return identity
                return simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)
            }
            return simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)
        }
        let t = transitionProgress * pose.blendFactor
        return simd_slerp(simd_quatf(ix: 0, iy: 0, iz: 0, r: 1), pose.neckOrientation, t)
    }
    
    // MARK: - Private
    
    private func interpolatedBlendshapes() -> [String: Float] {
        guard let pose = activePose else {
            // Fading out from previous
            if !previousBlendshapes.isEmpty && transitionProgress < 1.0 {
                let fadeOut = 1.0 - transitionProgress
                return previousBlendshapes.mapValues { $0 * fadeOut }
            }
            return [:]
        }
        
        let t = transitionProgress * pose.blendFactor
        var result: [String: Float] = [:]
        
        // Blend from previous to target
        let allKeys = Set(previousBlendshapes.keys).union(pose.blendshapes.keys)
        for key in allKeys {
            let prev = previousBlendshapes[key] ?? 0
            let target = pose.blendshapes[key] ?? 0
            let value = prev + (target - prev) * t
            if abs(value) > 0.001 {
                result[key] = value
            }
        }
        
        return result
    }
    
    private func smoothStep(_ t: Float) -> Float {
        // Hermite smoothstep: 3t² - 2t³
        return t * t * (3.0 - 2.0 * t)
    }
}
