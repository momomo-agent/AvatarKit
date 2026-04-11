import Foundation
import simd
import QuartzCore

// MARK: - Tracking Data Builder

/// Constructs the 480-byte AVTFaceTrackingData buffer that Apple's AvatarKit expects.
///
/// Single source of truth for memory layout — replaces the three separate
/// buildTrackingInfo paths that previously existed in AvatarBridge.
///
/// Memory layout (from reverse engineering of AvatarKit.framework, iOS 26.4):
/// ```
/// 0x00   8B   timestamp          Double
/// 0x08   8B   (padding)          alignment to 16 bytes
/// 0x10  16B   translation        simd_float4 (w=0)
/// 0x20  16B   orientation        simd_quatf (ix, iy, iz, r)
/// 0x30   1B   cameraSpace        Bool
/// 0x31   3B   (padding)
/// 0x34 204B   smoothBlendshapes  Float × 51
/// 0x100 204B  rawBlendshapes     Float × 51
/// 0x1CC  4B   smoothParams       Float × 1 (tongueOut)
/// 0x1D0  4B   rawParams          Float × 1 (tongueOut)
/// 0x1D4 12B   (trailing padding to 480)
/// ```
enum TrackingDataBuilder {
    
    // MARK: - Layout Constants
    
    static let size              = 480
    static let timestamp         = 0x00   // Double (8 bytes)
    static let translation       = 0x10   // simd_float4 (16 bytes)
    static let orientation       = 0x20   // simd_quatf (16 bytes)
    static let cameraSpace       = 0x30   // Bool (1 byte)
    static let smoothBlendshapes = 0x34   // Float[51] (204 bytes)
    static let rawBlendshapes    = 0x100  // Float[51] (204 bytes)
    static let smoothParams      = 0x1CC  // Float[1] (4 bytes)
    static let rawParams         = 0x1D0  // Float[1] (4 bytes)
    static let blendshapeCount   = 51
    
    // MARK: - Build from AvatarFaceTracking
    
    /// Build a 480-byte buffer from our public AvatarFaceTracking struct.
    /// This is the primary path for non-ARKit tracking sources.
    static func build(from tracking: AvatarFaceTracking) -> [UInt8] {
        var buffer = [UInt8](repeating: 0, count: size)
        
        buffer.withUnsafeMutableBytes { raw in
            let base = raw.baseAddress!
            
            // Timestamp
            var ts = CACurrentMediaTime()
            memcpy(base + Self.timestamp, &ts, 8)
            
            // Translation (zero — no AR positioning)
            var t = SIMD4<Float>(0, 0, 0, 0)
            memcpy(base + Self.translation, &t, 16)
            
            // Orientation
            var q = tracking.headRotation
            memcpy(base + Self.orientation, &q, 16)
            
            // cameraSpace — use tracking's preference
            base.storeBytes(of: tracking.cameraSpace ? UInt8(1) : UInt8(0), toByteOffset: Self.cameraSpace, as: UInt8.self)
            
            // Blendshapes
            writeBlendshapes(base: base, blendshapes: tracking.blendshapes)
            
            // TongueOut via parameters
            writeTongue(base: base, blendshapes: tracking.blendshapes)
        }
        
        return buffer
    }
    
    /// Build by patching a baseline buffer (captured from a real ARFrame).
    /// Preserves the baseline's translation/orientation/cameraSpace,
    /// only overwrites blendshapes, params, and optionally orientation.
    static func buildFromBaseline(
        _ baseline: Data,
        tracking: AvatarFaceTracking
    ) -> [UInt8] {
        var buffer = [UInt8](repeating: 0, count: size)
        
        // Copy baseline
        baseline.withUnsafeBytes { src in
            buffer.withUnsafeMutableBytes { dst in
                memcpy(dst.baseAddress!, src.baseAddress!, min(baseline.count, size))
            }
        }
        
        buffer.withUnsafeMutableBytes { raw in
            let base = raw.baseAddress!
            
            // Update timestamp
            var ts = CACurrentMediaTime()
            memcpy(base + Self.timestamp, &ts, 8)
            
            // Override orientation if non-identity
            let identity = simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)
            if tracking.headRotation != identity {
                var baseOrientation: simd_quatf = .init()
                memcpy(&baseOrientation, base + Self.orientation, 16)
                var newOrientation = baseOrientation * tracking.headRotation
                memcpy(base + Self.orientation, &newOrientation, 16)
            }
            
            // Clear and rewrite blendshapes
            memset(base + Self.smoothBlendshapes, 0, blendshapeCount * 4)
            memset(base + Self.rawBlendshapes, 0, blendshapeCount * 4)
            writeBlendshapes(base: base, blendshapes: tracking.blendshapes)
            
            // Clear and rewrite tongue
            memset(base + Self.smoothParams, 0, 4)
            memset(base + Self.rawParams, 0, 4)
            writeTongue(base: base, blendshapes: tracking.blendshapes)
        }
        
        return buffer
    }
    
    // MARK: - Read Helpers
    
    /// Read orientation quaternion from a tracking data buffer.
    static func readOrientation(from data: Data) -> simd_quatf {
        data.withUnsafeBytes { raw in
            let base = raw.baseAddress!
            let x = (base + Self.orientation).load(as: Float.self)
            let y = (base + Self.orientation + 4).load(as: Float.self)
            let z = (base + Self.orientation + 8).load(as: Float.self)
            let w = (base + Self.orientation + 12).load(as: Float.self)
            return simd_quatf(ix: x, iy: y, iz: z, r: w)
        }
    }
    
    /// Read translation from a tracking data buffer.
    static func readTranslation(from data: Data) -> SIMD3<Float> {
        data.withUnsafeBytes { raw in
            let base = raw.baseAddress!
            let x = (base + Self.translation).load(as: Float.self)
            let y = (base + Self.translation + 4).load(as: Float.self)
            let z = (base + Self.translation + 8).load(as: Float.self)
            return SIMD3(x, y, z)
        }
    }
    
    // MARK: - Private
    
    private static func writeBlendshapes(base: UnsafeMutableRawPointer, blendshapes: [String: Float]) {
        for (name, value) in blendshapes {
            guard name != "tongueOut",
                  let idx = BlendshapeOrder.index(of: name) else { continue }
            var val = value
            memcpy(base + Self.smoothBlendshapes + idx * 4, &val, 4)
            memcpy(base + Self.rawBlendshapes + idx * 4, &val, 4)
        }
    }
    
    private static func writeTongue(base: UnsafeMutableRawPointer, blendshapes: [String: Float]) {
        if let tongueOut = blendshapes["tongueOut"], tongueOut > 0 {
            var val = tongueOut
            memcpy(base + Self.smoothParams, &val, 4)
            memcpy(base + Self.rawParams, &val, 4)
        }
    }
}
