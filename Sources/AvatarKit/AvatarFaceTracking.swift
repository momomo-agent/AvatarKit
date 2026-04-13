import Foundation
import simd
import QuartzCore

// MARK: - Face Tracking Data

/// Public face tracking data — the input to AvatarBridge.applyTracking().
///
/// Holds ARKit-compatible blendshape values and head orientation.
/// Can be constructed from ARFaceAnchor, preset expressions, or manual values.
public struct AvatarFaceTracking: Sendable {
    
    /// Blendshape name → weight (0..1). Uses ARKit camelCase names.
    /// Missing keys use the -1.0 sentinel (skip/preserve previous value).
    public var blendshapes: [String: Float]
    
    /// Head orientation (Euler angles). Used when rawQuaternion is nil.
    public var headRotation: HeadRotation
    
    /// Raw quaternion from ARKit — preferred over headRotation when set.
    /// Avoids Euler decomposition/recomposition errors and preserves roll.
    public var rawQuaternion: simd_quatf?
    
    /// Head translation (x, y, z) from ARKit.
    public var headTranslation: SIMD3<Float>
    
    /// Coordinate space of the tracking data.
    public var coordinateSpace: CoordinateSpace
    
    /// Frame timestamp (CACurrentMediaTime).
    public var timestamp: Double
    
    /// Coordinate space for head tracking.
    public enum CoordinateSpace: Sendable {
        /// World-space: raw ARKit quaternion, moves with phone tilt.
        case world
        /// Camera-relative rotation only: compensates for phone movement.
        case cameraRotationOnly
        /// Camera-relative with translation.
        case cameraFull
    }
    
    /// Head rotation in degrees.
    public struct HeadRotation: Sendable {
        /// Pitch (nod up/down) in degrees. Positive = look up.
        public var pitch: Float
        /// Yaw (turn left/right) in degrees. Positive = turn left.
        public var yaw: Float
        /// Roll (tilt) in degrees. Note: Apple ignores roll.
        public var roll: Float
        
        public init(pitch: Float = 0, yaw: Float = 0, roll: Float = 0) {
            self.pitch = pitch
            self.yaw = yaw
            self.roll = roll
        }
        
        /// Convert to quaternion (ix, iy, iz, r) for the tracking buffer.
        internal var quaternion: simd_quatf {
            let p = pitch * .pi / 180
            let y = yaw * .pi / 180
            let qPitch = simd_quatf(angle: p, axis: SIMD3<Float>(1, 0, 0))
            let qYaw = simd_quatf(angle: y, axis: SIMD3<Float>(0, 1, 0))
            return qPitch * qYaw
        }
        
        public static let zero = HeadRotation()
    }
    
    public init(
        blendshapes: [String: Float] = [:],
        headRotation: HeadRotation = .zero,
        rawQuaternion: simd_quatf? = nil,
        headTranslation: SIMD3<Float> = .zero,
        coordinateSpace: CoordinateSpace = .world,
        timestamp: Double = CACurrentMediaTime()
    ) {
        self.blendshapes = blendshapes
        self.headRotation = headRotation
        self.rawQuaternion = rawQuaternion
        self.headTranslation = headTranslation
        self.coordinateSpace = coordinateSpace
        self.timestamp = timestamp
    }
}
