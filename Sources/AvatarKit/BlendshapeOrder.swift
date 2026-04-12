import Foundation

// MARK: - Blendshape Order

/// Apple's internal ARKit blendshape index order.
///
/// This is the canonical mapping used by `_applyBlendShapes:parameters:`
/// to iterate MorphInfo[51]. NOT alphabetical, NOT the same as ARKit's order.
///
/// Evidence: runtime introspection via `blendShapeNameForARKitBlendShapeIndex:`
/// on AVTAnimoji (iOS 26.4 simulator, 2026-04-12).
///
/// Apple uses underscore naming internally (eyeBlink_L) but we map to
/// ARKit's camelCase names (eyeBlinkLeft) for public API compatibility.
enum BlendshapeOrder {
    
    /// Ordered names — index in this array = offset in the 480-byte buffer's
    /// blendshape arrays (smooth at +0x34, raw at +0x100).
    ///
    /// Verified via `blendShapeNameForARKitBlendShapeIndex:` runtime call.
    static let names: [String] = [
        // [0-1] Eye blink
        "eyeBlinkLeft",       // 0  (eyeBlink_L)
        "eyeBlinkRight",      // 1  (eyeBlink_R)
        // [2-3] Eye squint
        "eyeSquintLeft",      // 2  (eyeSquint_L)
        "eyeSquintRight",     // 3  (eyeSquint_R)
        // [4-5] Eye look down
        "eyeLookDownLeft",    // 4  (eyeLookDown_L)
        "eyeLookDownRight",   // 5  (eyeLookDown_R)
        // [6-7] Eye look in
        "eyeLookInLeft",      // 6  (eyeLookIn_L)
        "eyeLookInRight",     // 7  (eyeLookIn_R)
        // [8-9] Eye wide
        "eyeWideLeft",        // 8  (eyeWide_L)
        "eyeWideRight",       // 9  (eyeWide_R)
        // [10-11] Eye look out
        "eyeLookOutLeft",     // 10 (eyeLookOut_L)
        "eyeLookOutRight",    // 11 (eyeLookOut_R)
        // [12-13] Eye look up
        "eyeLookUpLeft",      // 12 (eyeLookUp_L)
        "eyeLookUpRight",     // 13 (eyeLookUp_R)
        // [14-15] Brow down
        "browDownLeft",       // 14 (browDown_L)
        "browDownRight",      // 15 (browDown_R)
        // [16] Brow inner up
        "browInnerUp",        // 16 (browInnerUp)
        // [17-18] Brow outer up
        "browOuterUpLeft",    // 17 (browOuterUp_L)
        "browOuterUpRight",   // 18 (browOuterUp_R)
        // [19] Jaw open
        "jawOpen",            // 19 (jawOpen)
        // [20] Mouth close
        "mouthClose",         // 20 (mouthClose)
        // [21-22] Jaw left/right
        "jawLeft",            // 21 (jawLeft)
        "jawRight",           // 22 (jawRight)
        // [23] Jaw forward
        "jawForward",         // 23 (jawForward)
        // [24-25] Mouth upper up
        "mouthUpperUpLeft",   // 24 (mouthUpperUp_L)
        "mouthUpperUpRight",  // 25 (mouthUpperUp_R)
        // [26-27] Mouth lower down
        "mouthLowerDownLeft", // 26 (mouthLowerDown_L)
        "mouthLowerDownRight",// 27 (mouthLowerDown_R)
        // [28-29] Mouth roll
        "mouthRollUpper",     // 28 (mouthRollUpper)
        "mouthRollLower",     // 29 (mouthRollLower)
        // [30-31] Mouth smile
        "mouthSmileLeft",     // 30 (mouthSmile_L)
        "mouthSmileRight",    // 31 (mouthSmile_R)
        // [32-33] Mouth dimple
        "mouthDimpleLeft",    // 32 (mouthDimple_L)
        "mouthDimpleRight",   // 33 (mouthDimple_R)
        // [34-35] Mouth stretch
        "mouthStretchLeft",   // 34 (mouthStretch_L)
        "mouthStretchRight",  // 35 (mouthStretch_R)
        // [36-37] Mouth frown
        "mouthFrownLeft",     // 36 (mouthFrown_L)
        "mouthFrownRight",    // 37 (mouthFrown_R)
        // [38-39] Mouth press
        "mouthPressLeft",     // 38 (mouthPress_L)
        "mouthPressRight",    // 39 (mouthPress_R)
        // [40] Mouth pucker
        "mouthPucker",        // 40 (mouthPucker)
        // [41] Mouth funnel
        "mouthFunnel",        // 41 (mouthFunnel)
        // [42-43] Mouth left/right
        "mouthLeft",          // 42 (mouthLeft)
        "mouthRight",         // 43 (mouthRight)
        // [44-45] Mouth shrug
        "mouthShrugLower",    // 44 (mouthShrugLower)
        "mouthShrugUpper",    // 45 (mouthShrugUpper)
        // [46-47] Nose sneer
        "noseSneerLeft",      // 46 (noseSneer_L)
        "noseSneerRight",     // 47 (noseSneer_R)
        // [48] Cheek puff
        "cheekPuff",          // 48 (cheekPuff)
        // [49-50] Cheek squint
        "cheekSquintLeft",    // 49 (cheekSquint_L)
        "cheekSquintRight",   // 50 (cheekSquint_R)
    ]
    
    /// Name → index lookup.
    static let nameToIndex: [String: Int] = {
        var map: [String: Int] = [:]
        for (i, name) in names.enumerated() { map[name] = i }
        return map
    }()
    
    /// Look up the buffer index for a blendshape name.
    static func index(of name: String) -> Int? {
        nameToIndex[name]
    }
}
