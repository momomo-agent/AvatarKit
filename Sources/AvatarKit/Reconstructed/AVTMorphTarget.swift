// AVTMorphTarget.swift
// Reconstructed from AvatarKit.framework (iOS 26.4)
//
// MorphInfo struct and the blendshape application pipeline.
//
// Evidence chain:
//   MorphInfo layout: _applyBlendShapes:parameters: loop at 0x33a24-0x33aa8
//     - Stride: add x26, x26, #0x20 → 32 bytes per entry
//     - morpher: ldr x23, [x8] → offset 0
//     - targetIndex: ldr x22, [x8, #0x10] → offset 16
//     - isEnabled: ldrb w8, [x8, #0x18] → offset 24
//     - Count: cmp x21, #0x33 → 51 entries
//   TongueOut MorphInfo: separate at offset 0x660 from ivar base
//     - morpher: ldr x22, [x8, #0x660] → offset 0x660
//     - targetIndex: ldr x21, [x8, #0x670] → offset 0x670
//     - isEnabled: ldrb w8, [x8, #0x678] → offset 0x678
//   Tongue lerp: ldr s2, [x8, #0xe00] → const(float=0.3) at __TEXT,__const
//   FriendlyPose: loop at 0x33abc-0x33ae4, array at self+0x48, count at self+0x50

import SceneKit

// MARK: - MorphInfo

/// Per-blendshape morph target binding.
///
/// Each ARKit blendshape index maps to one MorphInfo entry.
/// The morpher is a VFXMorpher (SCNMorpher wrapper) and targetIndex
/// identifies which morph target to set the weight on.
///
/// Memory layout (32 bytes, verified from loop stride):
/// ```
/// offset  0: morpher       (pointer, 8 bytes) — VFXMorpher node
/// offset  8: (reserved)    (pointer, 8 bytes) — unknown
/// offset 16: targetIndex   (Int64,   8 bytes) — morph target index
/// offset 24: isEnabled     (Bool,    1 byte)  — whether this mapping is active
/// offset 25: (padding)     (7 bytes)
/// ```
struct AVTMorphInfo {
    weak var morpher: SCNMorpher?
    let targetIndex: Int
    let isEnabled: Bool
    
    static let stride = 32  // Evidence: add x26, x26, #0x20
    static let count = 51   // Evidence: cmp x21, #0x33
}

// MARK: - Blendshape Application Pipeline

/// Reconstructed `_applyBlendShapes:parameters:` logic.
///
/// This is the core loop that maps ARKit face tracking data to SceneKit morph targets.
/// Called every frame by `updatePoseWithFaceTrackingData:applySmoothing:`.
enum AVTBlendshapeApplicator {
    
    /// Tongue lerp factor for smooth interpolation.
    /// Evidence: ldr s2, [x8, #0xe00] → __TEXT,__const @ 0x65e00 = 0.3 (Float)
    ///
    /// The tongue morph weight is NOT set directly. Instead:
    ///   newWeight = currentWeight + (clampedTongue - currentWeight) * 0.3
    /// This creates smooth tongue in/out transitions.
    static let tongueLerpFactor: Float = 0.3
    
    /// Apply face tracking data to morph targets.
    ///
    /// Reconstructed from _applyBlendShapes:parameters: at 0x3393c.
    /// Three phases:
    ///   1. Handle tongueOut parameter (lerp to target)
    ///   2. Apply 51 blendshape weights (with corrections)
    ///   3. Reset friendlyPose morphs to zero
    ///
    /// - Parameters:
    ///   - trackingData: The 480-byte face tracking data
    ///   - morphInfos: Array of 51 MorphInfo bindings (ARKit index order)
    ///   - tongueMorphInfo: Separate MorphInfo for tongueOut (at ivar offset 0x660)
    ///   - friendlyPoseMorphInfos: Idle pose morph bindings (reset to 0 each frame)
    static func apply(
        trackingData: AVTFaceTrackingData,
        morphInfos: [AVTMorphInfo],
        tongueMorphInfo: AVTMorphInfo?,
        friendlyPoseMorphInfos: [AVTMorphInfo]
    ) {
        // --- Phase 1: TongueOut ---
        // Evidence: 0x33970-0x33a10
        //   ldr x8, [x0, #0x40]        → load ivar base
        //   ldr x21, [x8, #0x670]       → tongueOut targetIndex
        //   cmp x21, x25 (0x7fff...)    → skip if sentinel
        //   ldr s0, [x3]                → read tongueParam from parameters_smooth
        //   fcmp s0, s8 (-1.0)          → skip if inactive
        
        var tongueWeight: Float = -1.0
        
        if let tongue = tongueMorphInfo, tongue.isEnabled {
            let tongueParam = trackingData.smoothParams
            if tongueParam != -1.0, let morpher = tongue.morpher {
                let clamped = min(max(tongueParam, 0), 1)
                
                // Lerp: read current weight, interpolate toward target
                // Evidence: 0x339ec weightForTargetAtIndex: → 0x339fc fmadd s9, s1, s2, s0
                //   s0 = currentWeight
                //   s1 = clamped - currentWeight (delta)
                //   s2 = 0.3 (lerp factor)
                //   s9 = currentWeight + delta * 0.3
                let current = Float(morpher.weight(forTargetAt: tongue.targetIndex))
                tongueWeight = current + (clamped - current) * tongueLerpFactor
                
                morpher.setWeight(CGFloat(tongueWeight), forTargetAt: tongue.targetIndex)
            }
        }
        
        // --- Phase 2: 51 Blendshapes ---
        // Evidence: loop at 0x33a14-0x33aa8
        //   mov x21, #0x0               → index = 0
        //   add x26, x26, #0x20         → stride 32 bytes
        //   cmp x21, #0x33              → loop until 51
        
        for i in 0..<AVTMorphInfo.count {
            guard i < morphInfos.count else { break }
            let info = morphInfos[i]
            guard info.isEnabled, let morpher = info.morpher else { continue }
            guard let blendshape = AVTBlendshapeIndex(rawValue: i) else { continue }
            
            var weight = trackingData.smoothBlendshapes[i]
            
            // Skip inactive (-1.0)
            // Evidence: fcmp s0, s10 (-1.0); b.eq 0x33a9c
            if weight == -1.0 { continue }
            
            // Clamp to [0, 1]
            // Evidence: fminnm s0, s0, s11 (1.0); fmaxnm s9, s0, s12 (0.0)
            weight = min(max(weight, 0), 1)
            
            // Apply corrections (tongue first, then blink)
            // Evidence: bl _AVTMorphWeightApplyCorrectionForTongue at 0x33a78
            //           bl _AVTMorphWeightApplyBlinkCorrection at 0x33a80
            weight = AVTBlendshapeCorrection.applyAll(weight, blendshape: blendshape, tongueParam: tongueWeight)
            
            morpher.setWeight(CGFloat(weight), forTargetAt: info.targetIndex)
        }
        
        // --- Phase 3: Reset FriendlyPose ---
        // Evidence: loop at 0x33abc-0x33ae4
        //   ldr x8, [x19, #0x48]        → friendlyPoseMorphInfos array
        //   ldr x8, [x19, #0x50]        → count
        //   movi.2d v0, #0              → weight = 0
        //   setWeight:forTargetAtIndex:  → reset each to zero
        
        for info in friendlyPoseMorphInfos {
            guard let morpher = info.morpher else { continue }
            morpher.setWeight(0, forTargetAt: info.targetIndex)
        }
    }
}

// MARK: - Head Pose Application

/// Reconstructed `_applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:` logic.
///
/// Evidence: disassembly at 0x33b14
///   translation: ldp q at [ptr+0x10]
///   orientation: ldp q at [ptr+0x20]
///   cameraSpace: ldrb at [ptr+0x30]
enum AVTHeadPoseApplicator {
    
    /// Apply head pose from tracking data to the head node.
    ///
    /// - Parameters:
    ///   - trackingData: The 480-byte face tracking data
    ///   - headNode: The SCNNode representing the avatar's head
    ///   - arOffset: Camera-space offset (only used when cameraSpace=true)
    static func apply(
        trackingData: AVTFaceTrackingData,
        headNode: SCNNode,
        arOffset: SIMD3<Float> = .zero
    ) {
        var position = SIMD3<Float>(
            trackingData.translation.x,
            trackingData.translation.y,
            trackingData.translation.z
        )
        
        // Evidence: ldrb w8, [x21, #0x30]; tbnz w8, #0x0, <camera_space_path>
        if trackingData.cameraSpace {
            position -= arOffset
        }
        
        headNode.simdPosition = position
        headNode.simdOrientation = trackingData.orientation
    }
}
