import Foundation
import simd

/// Controls how expression transitions are animated.
public enum AvatarTransition: Sendable {
    /// Instant switch, no animation.
    case none
    /// Smooth interpolation over the given duration (seconds).
    case smooth(duration: TimeInterval = 0.3)
}
