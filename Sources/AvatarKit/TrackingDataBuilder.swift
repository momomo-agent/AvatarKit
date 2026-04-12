import Foundation
import simd

// MARK: - Tracking Data Builder

/// Builds tracking data buffers consumed by AvatarKit's private API.
///
/// Two buffer formats:
///
/// 1. **BlendShape struct** (428 bytes) — for `_applyBlendShapesWithTrackingData:`
///    ```
///    +0x00  Double     timestamp
///    +0x08  UInt8      cameraSpace
///    +0x0C  Float×51   smooth blendshapes (Apple order)
///    +0xD8  Float×51   raw blendshapes (Apple order)
///    +0x1A4 Float×1    smooth tongue parameter
///    +0x1A8 Float×1    raw tongue parameter
///    ```
///
/// 2. **Full pose struct** (480 bytes) — for `updatePoseWithFaceTrackingData:applySmoothing:`
///    ```
///    +0x00  Double     timestamp
///    +0x08  Float×3    translation (x, y, z)
///    +0x14  Float      padding
///    +0x18  Float      padding
///    +0x1C  Float      padding
///    +0x20  Float×4    orientation quaternion (ix, iy, iz, r)
///    +0x30  UInt8      cameraSpace
///    +0x34  Float×51   smooth blendshapes
///    +0x100 Float×51   raw blendshapes
///    +0x1CC Float      smooth tongue
///    +0x1D0 Float      raw tongue
///    ```
enum TrackingDataBuilder {
    
    /// Size of the blendshape-only struct (matches _applyBlendShapes type encoding).
    static let blendShapeBufferSize = 428
    
    /// Size of the full pose buffer (matches updatePoseWithFaceTrackingData).
    static let fullBufferSize = 480
    
    /// Build the 428-byte blendshape struct for `_applyBlendShapesWithTrackingData:`.
    ///
    /// Layout verified from ObjC type encoding:
    /// `{?=dB[51f][51f][1f][1f]}` with natural alignment padding.
    static func buildBlendShapeData(from tracking: AvatarFaceTracking) -> Data {
        var buf = Data(count: blendShapeBufferSize)
        
        buf.withUnsafeMutableBytes { raw in
            let ptr = raw.baseAddress!
            
            // Timestamp (offset 0, 8 bytes)
            var ts = tracking.timestamp
            memcpy(ptr, &ts, 8)
            
            // cameraSpace (offset 8, 1 byte)
            ptr.storeBytes(of: UInt8(0), toByteOffset: 8, as: UInt8.self)
            
            // Smooth blendshapes (offset 12, 51×4 = 204 bytes)
            writeBlendshapes(ptr, offset: 12, values: tracking.blendshapes)
            
            // Raw blendshapes (offset 216, 51×4 = 204 bytes)
            writeBlendshapes(ptr, offset: 216, values: tracking.blendshapes)
            
            // Tongue parameters
            let tongue = tracking.blendshapes["tongueOut"] ?? 0
            var t = tongue
            memcpy(ptr + 420, &t, 4) // smooth
            memcpy(ptr + 424, &t, 4) // raw
        }
        
        return buf
    }
    
    /// Build the 480-byte full pose buffer for `updatePoseWithFaceTrackingData:applySmoothing:`.
    static func buildFullPoseData(from tracking: AvatarFaceTracking) -> Data {
        var buf = Data(count: fullBufferSize)
        
        buf.withUnsafeMutableBytes { raw in
            let ptr = raw.baseAddress!
            
            // Timestamp
            var ts = tracking.timestamp
            memcpy(ptr, &ts, 8)
            
            // Orientation quaternion (offset 0x20)
            let q = tracking.headRotation.quaternion
            var ix = q.imag.x, iy = q.imag.y, iz = q.imag.z, r = q.real
            memcpy(ptr + 0x20, &ix, 4)
            memcpy(ptr + 0x24, &iy, 4)
            memcpy(ptr + 0x28, &iz, 4)
            memcpy(ptr + 0x2C, &r, 4)
            
            // cameraSpace = false
            ptr.storeBytes(of: UInt8(0), toByteOffset: 0x30, as: UInt8.self)
            
            // Smooth blendshapes (offset 0x34)
            writeBlendshapes(ptr, offset: 0x34, values: tracking.blendshapes)
            
            // Raw blendshapes (offset 0x100)
            writeBlendshapes(ptr, offset: 0x100, values: tracking.blendshapes)
            
            // Tongue
            let tongue = tracking.blendshapes["tongueOut"] ?? 0
            var t = tongue
            memcpy(ptr + 0x1CC, &t, 4)
            memcpy(ptr + 0x1D0, &t, 4)
        }
        
        return buf
    }
    
    // MARK: - Private
    
    private static func writeBlendshapes(
        _ ptr: UnsafeMutableRawPointer,
        offset: Int,
        values: [String: Float]
    ) {
        // Initialize all to 0 (explicit zero, not -1 sentinel)
        for i in 0..<51 {
            var zero: Float = 0
            memcpy(ptr + offset + i * 4, &zero, 4)
        }
        
        // Write provided values at correct indices
        for (name, value) in values {
            guard name != "tongueOut" else { continue }
            guard let idx = BlendshapeOrder.index(of: name) else { continue }
            var v = value
            memcpy(ptr + offset + idx * 4, &v, 4)
        }
    }
}
