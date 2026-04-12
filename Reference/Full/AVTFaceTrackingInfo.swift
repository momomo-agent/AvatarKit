// AVTFaceTrackingInfo.swift
// Reconstructed from AvatarKit.framework (iOS 26.4)
//
// AVTFaceTrackingInfo is a thin NSObject wrapper around the 480-byte
// AVTFaceTrackingData struct. It provides the Objective-C bridge between
// the Nigiri face tracking pipeline and AvatarKit's morph target system.
//
// Evidence chain:
//   Class: otool -oV → AVTFaceTrackingInfo : NSObject, SIZE: 496
//   Ivar:  +16 _trackingData {?="timestamp"d"translation""orientation""cameraSpace"B
//          "blendShapeWeights_smooth"[51f]"blendShapeWeights_raw"[51f]
//          "parameters_smooth"[1f]"parameters_raw"[1f]}
//   Category: AVTFaceTrackingInfo(Nigiri) — factory method
//   trackingData accessor: returns (self + 0x10) — pointer to inline struct
//   Factory: alloc_init + memcpy(obj+0x10, data, 0x1E0)

import Foundation
import simd

// MARK: - AVTFaceTrackingInfo Class Layout

/// AVTFaceTrackingInfo wraps the raw 480-byte face tracking data.
///
/// Instance layout (496 bytes total):
/// ```
/// +0    8B   isa pointer (NSObject)
/// +8    8B   NSObject internals
/// +16 480B   _trackingData (AVTFaceTrackingData, inline)
/// ```
///
/// Evidence: SIZE: 496 in header. 496 - 16 (NSObject overhead) = 480 = 0x1E0.
/// The struct is stored inline starting at offset +16 (0x10).
///
/// The class has exactly 1 instance method and 1 category class method:
///   - trackingData → returns pointer to self+0x10 (the inline struct)
///   - +[AVTFaceTrackingInfo(Nigiri) trackingInfoWithTrackingData:] → factory
class AVTFaceTrackingInfo: NSObject {

    // MARK: - Inline Tracking Data

    /// The 480-byte tracking data struct, stored inline at offset +16.
    ///
    /// Evidence: ivar declaration at offset +16 with full type encoding.
    /// The trackingData accessor returns `(self + 0x10)` — a direct pointer
    /// to this inline storage, NOT a copy.
    ///
    /// Decompiled (line 9010-9013):
    /// ```
    /// -(id)trackingData:(id)trackingData {
    ///     return (self + 0x10);
    /// }
    /// ```
    var _trackingData: AVTFaceTrackingData = AVTFaceTrackingData()

    // MARK: - trackingData Accessor

    /// Returns a pointer to the inline tracking data.
    ///
    /// Evidence: decompiled at line 9010-9013
    /// The method returns `self + 0x10`, which is a raw pointer to the
    /// inline _trackingData struct. Callers use this to read blendshape
    /// weights and head pose without copying.
    ///
    /// In ObjC, the return type is `r^{?=d...}` — a const pointer to the struct.
    /// The `r` prefix means read-only (const).
    func trackingData() -> UnsafePointer<AVTFaceTrackingData> {
        return withUnsafePointer(to: &_trackingData) { $0 }
    }
}

// MARK: - Nigiri Category

/// AVTFaceTrackingInfo(Nigiri) — factory method for creating tracking info
/// from raw Nigiri pipeline data.
///
/// "Nigiri" is Apple's internal name for their face tracking pipeline
/// (likely named after the sushi, following Apple's food-themed codenames).
///
/// Evidence: decompiled at line 9019-9043
/// Category: AVTFaceTrackingInfo(Nigiri)
/// Single method: +trackingInfoWithTrackingData:
extension AVTFaceTrackingInfo {

    /// Creates an AVTFaceTrackingInfo by copying raw tracking data.
    ///
    /// Evidence: decompiled at line 9025-9030
    /// ```
    /// +(id)trackingInfoWithTrackingData:(id)trackingInfoWithTrackingData {
    ///     _objc_alloc_init();
    ///     _memcpy();        // memcpy(obj+0x10, data, 0x1E0)
    ///     goto loc_6105c;   // return obj (autorelease)
    /// }
    /// ```
    ///
    /// The method:
    /// 1. Allocates and inits a new AVTFaceTrackingInfo
    /// 2. memcpy's 0x1E0 (480) bytes from the input pointer to obj+0x10
    /// 3. Returns the populated object
    ///
    /// Parameter: pointer to a 480-byte AVTFaceTrackingData struct
    /// Returns: autoreleased AVTFaceTrackingInfo with copied data
    ///
    /// Class method signature from header:
    ///   CMETHOD trackingInfoWithTrackingData: @24@0:8^{?=dB[51f][51f][1f][1f]}16
    ///   → takes a pointer to the tracking data struct
    static func trackingInfoWithTrackingData(_ data: UnsafePointer<AVTFaceTrackingData>) -> AVTFaceTrackingInfo {
        let info = AVTFaceTrackingInfo()
        // memcpy(info + 0x10, data, 0x1E0)
        // Evidence: _memcpy() call in decompiled code
        // Copies exactly 480 bytes (AVTFaceTrackingData.size) into the inline storage
        withUnsafeMutablePointer(to: &info._trackingData) { dst in
            dst.withMemoryRebound(to: UInt8.self, capacity: AVTFaceTrackingData.size) { dstBytes in
                data.withMemoryRebound(to: UInt8.self, capacity: AVTFaceTrackingData.size) { srcBytes in
                    dstBytes.update(from: srcBytes, count: AVTFaceTrackingData.size)
                }
            }
        }
        return info
    }
}

// MARK: - Integration with AVTAvatar

/// How AVTFaceTrackingInfo flows through the system:
///
/// 1. Nigiri pipeline produces raw 480-byte tracking data each frame
/// 2. +[AVTFaceTrackingInfo(Nigiri) trackingInfoWithTrackingData:] wraps it
/// 3. AVTAvatar receives it via:
///    - applyBlendShapesWithTrackingInfo: → calls _applyBlendShapesWithTrackingData:
///    - applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:
///      → calls _applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:
///
/// Evidence for the flow (decompiled lines 2204-2241):
/// ```
/// -(id)applyBlendShapesWithTrackingInfo:(id)info {
///     trackingData = [info trackingData];  // gets pointer to inline struct
///     [self _applyBlendShapesWithTrackingData:trackingData];
/// }
///
/// -(id)applyHeadPoseWithTrackingInfo:(id)info {
///     trackingData = [info trackingData];
///     [self _applyHeadPoseWithTrackingData:trackingData gazeCorrection:NO pointOfView:nil];
/// }
/// ```
///
/// The alternative path is updatePoseWithFaceTrackingData:applySmoothing:
/// which takes an NSData of 480 bytes directly (verified by length == 0x1E0 check).

// MARK: - Compile-Time Layout Verification

#if DEBUG
enum _AVTFaceTrackingInfoLayoutCheck {
    static func verify() {
        // AVTFaceTrackingInfo instance size should be 496
        // NSObject base (16) + AVTFaceTrackingData (480) = 496
        assert(MemoryLayout<AVTFaceTrackingData>.size == 480,
               "AVTFaceTrackingData must be exactly 480 bytes")

        // The _trackingData ivar is at offset +16 from instance base
        // In Swift, this is the first stored property after NSObject's internals
    }
}
#endif
