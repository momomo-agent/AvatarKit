import Foundation
import simd

// MARK: - Tracking Data Builder

/// Builds the 480-byte tracking data buffer consumed by AvatarKit.
///
/// Layout (verified via AVTFaceTrackingInfo ivar + disassembly):
/// ```
/// 0x00   8B   timestamp          Double
/// 0x08   8B   (padding)          alignment to 16 bytes
/// 0x10  16B   translation        simd_float4 (x, y, z, w=0)
/// 0x20  16B   orientation        simd_quatf (ix, iy, iz, r)
/// 0x30   1B   cameraSpace        Bool
/// 0x31   3B   (padding)
/// 0x34 204B   smoothBlendshapes  Float × 51
/// 0x100 204B  rawBlendshapes     Float × 51
/// 0x1CC  4B   smoothParams       Float × 1 (tongueOut)
/// 0x1D0  4B   rawParams          Float × 1 (tongueOut)
/// 0x1D4 12B   (padding to 480)
/// ```
enum TrackingDataBuilder {
    
    static let bufferSize = 480
    
    /// Build a tracking buffer from AvatarFaceTracking.
    static func build(from tracking: AvatarFaceTracking) -> Data {
        var buf = Data(count: bufferSize)
        
        buf.withUnsafeMutableBytes { raw in
            let ptr = raw.baseAddress!
            
            // Timestamp at +0x00
            var ts = tracking.timestamp
            memcpy(ptr, &ts, 8)
            
            // +0x08 is padding (8 bytes for SIMD alignment)
            
            // Translation at +0x10 (simd_float4, 16 bytes)
            var t = SIMD4<Float>(tracking.headTranslation.x,
                                 tracking.headTranslation.y,
                                 tracking.headTranslation.z,
                                 0)
            memcpy(ptr + 0x10, &t, 16)
            
            // Orientation quaternion at +0x20 (simd_quatf, 16 bytes)
            // Prefer raw quaternion from ARKit (preserves roll, avoids euler artifacts)
            var q = tracking.rawQuaternion ?? tracking.headRotation.quaternion
            memcpy(ptr + 0x20, &q, 16)
            
            // cameraSpace flag at +0x30
            let cameraFlag: UInt8 = tracking.coordinateSpace == .world ? 0 : 1
            ptr.storeBytes(of: cameraFlag, toByteOffset: 0x30, as: UInt8.self)
            
            // Blendshapes at +0x34 (smooth) and +0x100 (raw)
            writeBlendshapes(ptr, tracking.blendshapes)
            
            // Tongue parameter at +0x1CC (smooth) and +0x1D0 (raw)
            writeTongue(ptr, tracking.blendshapes["tongueOut"])
        }
        
        return buf
    }
    
    // MARK: - Private
    
    private static func writeBlendshapes(_ ptr: UnsafeMutableRawPointer, _ values: [String: Float]) {
        for i in 0..<51 {
            var zero: Float = 0
            memcpy(ptr + 0x34 + i * 4, &zero, 4)
            memcpy(ptr + 0x100 + i * 4, &zero, 4)
        }
        
        for (name, value) in values {
            guard name != "tongueOut" else { continue }
            guard let idx = BlendshapeOrder.index(of: name) else { continue }
            var v = value
            memcpy(ptr + 0x34 + idx * 4, &v, 4)
            memcpy(ptr + 0x100 + idx * 4, &v, 4)
        }
    }
    
    private static func writeTongue(_ ptr: UnsafeMutableRawPointer, _ value: Float?) {
        var v = value ?? 0
        memcpy(ptr + 0x1CC, &v, 4)
        memcpy(ptr + 0x1D0, &v, 4)
    }
}
