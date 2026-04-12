import Foundation

// MARK: - Blendshape Order

/// Maps ARKit blendshape names to Apple's internal morph target indices.
///
/// The 480-byte tracking buffer uses Apple's internal ordering (51 slots),
/// which differs from ARKit's `ARFaceAnchor.BlendShapeLocation` order.
///
/// Internal order was extracted from VFXMorpher targets on a loaded AVTAnimoji.
/// The first 51 targets are face blendshapes; remaining targets are character-specific
/// (e.g. ear dynamics for cat).
///
/// Apple uses underscore naming internally (eyeBlink_L) but we accept both
/// ARKit camelCase (eyeBlinkLeft) and Apple underscore (eyeBlink_L) formats.
enum BlendshapeOrder {
    
    /// Apple's internal morph target order (first 51 slots in the tracking buffer).
    /// Extracted from VFXMorpher.targets on AVTAnimoji.
    static let order: [String] = [
        "browDown_L",         // 0
        "browDown_R",         // 1
        "browInnerUp",        // 2
        "browOuterUp_L",      // 3
        "browOuterUp_R",      // 4
        "cheekSquint_L",      // 5
        "cheekSquint_R",      // 6
        "mouthShrugLower",    // 7
        "mouthShrugUpper",    // 8
        "eyeBlink_L",         // 9
        "eyeBlink_R",         // 10
        "eyeLookDown_L",      // 11
        "eyeLookDown_R",      // 12
        "eyeLookIn_L",        // 13
        "eyeLookIn_R",        // 14
        "eyeWide_L",          // 15
        "eyeWide_R",          // 16
        "eyeLookOut_L",       // 17
        "eyeLookOut_R",       // 18
        "eyeSquint_L",        // 19
        "eyeSquint_R",        // 20
        "eyeLookUp_L",        // 21
        "eyeLookUp_R",        // 22
        "jawForward",         // 23
        "jawLeft",            // 24
        "jawOpen",            // 25
        "jawRight",           // 26
        "mouthFunnel",        // 27
        "mouthRollLower",     // 28
        "mouthLowerDown_L",   // 29
        "mouthLowerDown_R",   // 30
        "mouthPucker",        // 31
        "mouthStretch_L",     // 32
        "mouthStretch_R",     // 33
        "mouthClose",         // 34
        "mouthRollUpper",     // 35
        "mouthUpperUp_L",     // 36
        "mouthUpperUp_R",     // 37
        "mouthDimple_L",      // 38
        "mouthDimple_R",      // 39
        "mouthFrown_L",       // 40
        "mouthFrown_R",       // 41
        "mouthLeft",          // 42
        "mouthPress_L",       // 43
        "mouthPress_R",       // 44
        "mouthRight",         // 45
        "mouthSmile_L",       // 46
        "mouthSmile_R",       // 47
        "cheekPuff",          // 48
        "noseSneer_L",        // 49
        "noseSneer_R",        // 50
    ]
    
    /// ARKit camelCase → Apple underscore name mapping.
    private static let arkitToApple: [String: String] = [
        "browDownLeft": "browDown_L",
        "browDownRight": "browDown_R",
        "browInnerUp": "browInnerUp",
        "browOuterUpLeft": "browOuterUp_L",
        "browOuterUpRight": "browOuterUp_R",
        "cheekSquintLeft": "cheekSquint_L",
        "cheekSquintRight": "cheekSquint_R",
        "mouthShrugLower": "mouthShrugLower",
        "mouthShrugUpper": "mouthShrugUpper",
        "eyeBlinkLeft": "eyeBlink_L",
        "eyeBlinkRight": "eyeBlink_R",
        "eyeLookDownLeft": "eyeLookDown_L",
        "eyeLookDownRight": "eyeLookDown_R",
        "eyeLookInLeft": "eyeLookIn_L",
        "eyeLookInRight": "eyeLookIn_R",
        "eyeWideLeft": "eyeWide_L",
        "eyeWideRight": "eyeWide_R",
        "eyeLookOutLeft": "eyeLookOut_L",
        "eyeLookOutRight": "eyeLookOut_R",
        "eyeSquintLeft": "eyeSquint_L",
        "eyeSquintRight": "eyeSquint_R",
        "eyeLookUpLeft": "eyeLookUp_L",
        "eyeLookUpRight": "eyeLookUp_R",
        "jawForward": "jawForward",
        "jawLeft": "jawLeft",
        "jawOpen": "jawOpen",
        "jawRight": "jawRight",
        "mouthFunnel": "mouthFunnel",
        "mouthRollLower": "mouthRollLower",
        "mouthLowerDownLeft": "mouthLowerDown_L",
        "mouthLowerDownRight": "mouthLowerDown_R",
        "mouthPucker": "mouthPucker",
        "mouthStretchLeft": "mouthStretch_L",
        "mouthStretchRight": "mouthStretch_R",
        "mouthClose": "mouthClose",
        "mouthRollUpper": "mouthRollUpper",
        "mouthUpperUpLeft": "mouthUpperUp_L",
        "mouthUpperUpRight": "mouthUpperUp_R",
        "mouthDimpleLeft": "mouthDimple_L",
        "mouthDimpleRight": "mouthDimple_R",
        "mouthFrownLeft": "mouthFrown_L",
        "mouthFrownRight": "mouthFrown_R",
        "mouthLeft": "mouthLeft",
        "mouthPressLeft": "mouthPress_L",
        "mouthPressRight": "mouthPress_R",
        "mouthRight": "mouthRight",
        "mouthSmileLeft": "mouthSmile_L",
        "mouthSmileRight": "mouthSmile_R",
        "cheekPuff": "cheekPuff",
        "noseSneerLeft": "noseSneer_L",
        "noseSneerRight": "noseSneer_R",
    ]
    
    /// Precomputed index lookup (both ARKit camelCase and Apple underscore names).
    private static let indexMap: [String: Int] = {
        var map = [String: Int]()
        // Apple underscore names
        for (i, name) in order.enumerated() {
            map[name] = i
        }
        // ARKit camelCase names
        for (arkit, apple) in arkitToApple {
            if let idx = map[apple] {
                map[arkit] = idx
            }
        }
        return map
    }()
    
    /// Look up the buffer index for a blendshape name.
    /// Accepts both ARKit camelCase and Apple underscore formats.
    static func index(of name: String) -> Int? {
        indexMap[name]
    }
    
    /// All blendshape names in Apple's internal order.
    static var names: [String] { order }
}
