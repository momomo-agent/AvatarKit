import Foundation
import simd

// MARK: - Tracking Data Builder

/// Builds the 480-byte tracking data buffer consumed by AvatarKit.
///
/// Layout (verified via AVTFaceTrackingInfo ivar, struct_size = 480):
/// ```
/// +0x00  Double   timestamp (CACurrentMediaTime)
/// +0x08  Float×3  translation (x, y, z)
/// +0x14  Float    padding
/// +0x18  Float    padding
/// +0x1C  Float    padding
/// +0x20  Float×4  orientation quaternion (ix, iy, iz, r)
/// +0x30  UInt8    cameraSpace flag
/// +0x34  Float×51 smooth blendshapes (Apple order)
/// +0x100 Float×51 raw blendshapes (Apple order)
/// +0x1CC Float    smooth tongue parameter
/// +0x1D0 Float    raw tongue parameter
/// ```
///
/// Note: `_applyBlendShapesWithTrackingData:` also takes a pointer to this
/// same 480-byte struct (type encoding omits translation/orientation types
/// but the struct size is identical).
enum TrackingDataBuilder {
    
    static let bufferSize = 480
    
    /// Build a tracking buffer from AvatarFaceTracking.
    static func build(from tracking: AvatarFaceTracking) -> Data {
        var buf = Data(count: bufferSize)
        
        buf.withUnsafeMutableBytes { raw in
            let ptr = raw.baseAddress!
            
            // Timestamp
            var ts = tracking.timestamp
            memcpy(ptr, &ts, 8)
            
            // Orientation quaternion at +0x20
            let q = tracking.headRotation.quaternion
            var ix = q.imag.x, iy = q.imag.y, iz = q.imag.z, r = q.real
            memcpy(ptr + 0x20, &ix, 4)
            memcpy(ptr + 0x24, &iy, 4)
            memcpy(ptr + 0x28, &iz, 4)
            memcpy(ptr + 0x2C, &r, 4)
            
            // cameraSpace = false — don't reposition head from translation
            ptr.storeBytes(of: UInt8(0), toByteOffset: 0x30, as: UInt8.self)
            
            // Blendshapes: all 51 slots explicitly set (0 for unspecified)
            writeBlendshapes(ptr, tracking.blendshapes)
            
            // Tongue parameter
            writeTongue(ptr, tracking.blendshapes["tongueOut"])
        }
        
        return buf
    }
    
    // MARK: - Private
    
    private static func writeBlendshapes(_ ptr: UnsafeMutableRawPointer, _ values: [String: Float]) {
        // Initialize all 51 slots to 0 (not -1 sentinel)
        // This ensures previous expression state is fully cleared
        for i in 0..<51 {
            var zero: Float = 0
            memcpy(ptr + 0x34 + i * 4, &zero, 4)
            memcpy(ptr + 0x100 + i * 4, &zero, 4)
        }
        
        // Write provided values at correct indices
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
