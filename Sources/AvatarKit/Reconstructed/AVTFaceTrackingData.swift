// AVTFaceTrackingData.swift
// Reconstructed from AvatarKit.framework (iOS 26.4)
//
// This is a pure Swift reconstruction of Apple's internal 480-byte
// face tracking data structure. No ObjC runtime dependency.
//
// Evidence chain:
//   Structure: otool -oV → AVTFaceTrackingInfo._trackingData type encoding
//   Field names: {?="timestamp"d"translation""orientation""cameraSpace"B
//                "blendShapeWeights_smooth"[51f]"blendShapeWeights_raw"[51f]
//                "parameters_smooth"[1f]"parameters_raw"[1f]}
//   SIMD types: otool -tV → ldp q at [ptr+0x10] (float4), [ptr+0x20] (quatf)
//   Total size: cmp x0, #0x1e0 in updatePoseWithFaceTrackingData: → 480 bytes
//   Construction: +[AVTFaceTrackingInfo(Nigiri) trackingInfoWithTrackingData:]
//                 → alloc_init, memcpy(obj+0x10, data, 0x1e0)

import simd

/// 480-byte face tracking data, binary-compatible with Apple's internal layout.
///
/// Memory layout (verified against disassembly):
/// ```
/// 0x00   8B   timestamp          Double
/// 0x08   8B   (padding)          alignment to 16 bytes
/// 0x10  16B   translation        simd_float4 (w=0, effectively float3)
/// 0x20  16B   orientation        simd_quatf (ix, iy, iz, r)
/// 0x30   1B   cameraSpace        Bool
/// 0x31   3B   (padding)
/// 0x34 204B   smoothBlendshapes  Float × 51
/// 0x100 204B  rawBlendshapes     Float × 51
/// 0x1CC  4B   smoothParams       Float × 1 (tongueOut)
/// 0x1D0  4B   rawParams          Float × 1 (tongueOut)
/// 0x1D4 12B   (padding to 480)
/// ```
struct AVTFaceTrackingData {
    
    // MARK: - Layout Constants
    
    /// Total byte size. Evidence: `cmp x0, #0x1e0` in updatePoseWithFaceTrackingData:
    static let size = 480
    
    /// Number of ARKit blendshapes. Evidence: loop bound `cmp x21, #0x33` in _applyBlendShapes:
    static let blendshapeCount = 51
    
    /// Number of extra parameters (currently just tongueOut).
    /// Evidence: `parameters_smooth[1f]` in type encoding
    static let parameterCount = 1
    
    // MARK: - Fields
    
    /// Timestamp of the tracking frame.
    /// Offset 0x00, Double (8 bytes)
    var timestamp: Double = 0
    
    /// Padding for 16-byte SIMD alignment.
    private var _padding0: UInt64 = 0
    
    /// Head translation in 3D space (w component unused, set to 0).
    /// Offset 0x10, simd_float4 (16 bytes)
    /// Evidence: `ldp q17, q7, [x21, #0x10]` in _applyHeadPoseWithTrackingData:
    var translation: SIMD4<Float> = .zero
    
    /// Head orientation as quaternion (ix, iy, iz, r).
    /// Offset 0x20, simd_quatf (16 bytes)
    /// Evidence: `ldp q at [ptr+0x20]` in _applyHeadPoseWithTrackingData:
    var orientation: simd_quatf = simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)
    
    /// Whether translation is in camera space.
    /// Offset 0x30, Bool (1 byte)
    /// - `false`: position = translation directly (non-AR mode)
    /// - `true`:  position = translation - arOffset (camera-space mode)
    /// Evidence: field name "cameraSpace" in type encoding; `ldrb w8, [x21, #0x30]`
    var cameraSpace: Bool = false
    
    /// Padding after Bool to align to 4-byte boundary.
    private var _padding1: UInt8 = 0
    private var _padding2: UInt16 = 0
    
    /// Smoothed blendshape weights, indexed by ARKit blendshape order.
    /// Offset 0x34, Float[51] (204 bytes)
    /// Evidence: `add x2, x2, #0x34` in _applyBlendShapesWithTrackingData:
    /// Value -1.0 means inactive (skipped in apply loop).
    var smoothBlendshapes: BlendshapeArray = BlendshapeArray()
    
    /// Raw (unsmoothed) blendshape weights.
    /// Offset 0x100, Float[51] (204 bytes)
    var rawBlendshapes: BlendshapeArray = BlendshapeArray()
    
    /// Smoothed parameters (index 0 = tongueOut).
    /// Offset 0x1CC, Float[1] (4 bytes)
    /// Evidence: `add x3, x8, #0x1cc` in _applyBlendShapesWithTrackingData:
    var smoothParams: Float = -1.0
    
    /// Raw parameters (index 0 = tongueOut).
    /// Offset 0x1D0, Float[1] (4 bytes)
    var rawParams: Float = -1.0
    
    /// Trailing padding to reach 480 bytes.
    private var _padding3: (UInt32, UInt32, UInt32) = (0, 0, 0)
}

// MARK: - Fixed-Size Blendshape Array

/// 51-element Float array with fixed memory layout.
/// Needed because Swift tuples guarantee contiguous layout matching C arrays.
struct BlendshapeArray {
    // 51 floats as a tuple — guarantees C-compatible memory layout
    var values: (
        Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, // 0-9
        Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, // 10-19
        Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, // 20-29
        Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, // 30-39
        Float, Float, Float, Float, Float, Float, Float, Float, Float, Float, // 40-49
        Float                                                                  // 50
    ) = (
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1
    )
    
    /// Default: all -1.0 (inactive, skipped by apply loop)
    init() {}
    
    subscript(index: Int) -> Float {
        get {
            precondition(index >= 0 && index < 51)
            return withUnsafePointer(to: values) { ptr in
                ptr.withMemoryRebound(to: Float.self, capacity: 51) { $0[index] }
            }
        }
        set {
            precondition(index >= 0 && index < 51)
            withUnsafeMutablePointer(to: &values) { ptr in
                ptr.withMemoryRebound(to: Float.self, capacity: 51) { $0[index] = newValue }
            }
        }
    }
}

// MARK: - Compile-Time Layout Verification

#if DEBUG
enum _AVTFaceTrackingDataLayoutCheck {
    static func verify() {
        assert(MemoryLayout<AVTFaceTrackingData>.size == 480,
               "AVTFaceTrackingData must be exactly 480 bytes")
        assert(MemoryLayout<BlendshapeArray>.size == 204,
               "BlendshapeArray must be exactly 204 bytes (51 × Float)")
    }
}
#endif
