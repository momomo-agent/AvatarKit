import Foundation

// MARK: - Blendshape Order

/// Apple's internal ARKit blendshape index order.
///
/// This is the canonical mapping used by `_applyBlendShapes:parameters:`
/// to iterate MorphInfo[51]. NOT alphabetical.
///
/// Evidence: otool disassembly of `_initialiseBlendshapeMappingIfNeeded_block_invoke`,
/// cross-referenced with `_AVTBlendShapeLocation*` symbol addresses from nm.
enum BlendshapeOrder {
    
    /// Ordered names — index in this array = offset in the 480-byte buffer.
    static let names: [String] = [
        // [0-6] Left eye
        "eyeBlinkLeft",       // 0
        "eyeLookDownLeft",    // 1
        "eyeLookInLeft",      // 2
        "eyeLookOutLeft",     // 3
        "eyeLookUpLeft",      // 4
        "eyeSquintLeft",      // 5
        "eyeWideLeft",        // 6
        // [7-13] Right eye
        "eyeBlinkRight",      // 7
        "eyeLookDownRight",   // 8
        "eyeLookInRight",     // 9
        "eyeLookOutRight",    // 10
        "eyeLookUpRight",     // 11
        "eyeSquintRight",     // 12
        "eyeWideRight",       // 13
        // [14-18] Jaw
        "jawForward",         // 14
        "jawLeft",            // 15
        "jawRight",           // 16
        "jawOpen",            // 17
        "mouthClose",         // 18
        // [19-22] Mouth shape
        "mouthFunnel",        // 19
        "mouthPucker",        // 20
        "mouthLeft",          // 21
        "mouthRight",         // 22
        // [23-26] Mouth smile/frown
        "mouthSmileLeft",     // 23
        "mouthSmileRight",    // 24
        "mouthFrownLeft",     // 25
        "mouthFrownRight",    // 26
        // [27-30] Mouth dimple/stretch
        "mouthDimpleLeft",    // 27
        "mouthDimpleRight",   // 28
        "mouthStretchLeft",   // 29
        "mouthStretchRight",  // 30
        // [31-34] Mouth roll/shrug
        "mouthRollLower",     // 31
        "mouthRollUpper",     // 32
        "mouthShrugLower",    // 33
        "mouthShrugUpper",    // 34
        // [35-40] Mouth press/lower/upper
        "mouthPressLeft",     // 35
        "mouthPressRight",    // 36
        "mouthLowerDownLeft", // 37
        "mouthLowerDownRight",// 38
        "mouthUpperUpLeft",   // 39
        "mouthUpperUpRight",  // 40
        // [41-45] Brows
        "browDownLeft",       // 41
        "browDownRight",      // 42
        "browInnerUp",        // 43
        "browOuterUpLeft",    // 44
        "browOuterUpRight",   // 45
        // [46-50] Cheeks & nose
        "cheekPuff",          // 46
        "cheekSquintLeft",    // 47
        "cheekSquintRight",   // 48
        "noseSneerLeft",      // 49
        "noseSneerRight",     // 50
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
