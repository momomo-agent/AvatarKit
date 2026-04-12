import Foundation

// MARK: - Blendshape Order

/// Maps ARKit blendshape names to buffer slot indices for `_applyBlendShapesWithTrackingData:`.
///
/// The 480-byte tracking buffer uses ARKit's standard ordering (51 slots),
/// which differs from VFXMorpher.targets order. This was determined empirically
/// by setting each buffer slot to 1.0 and observing which morpher target activates.
///
/// Apple uses underscore naming internally (eyeBlink_L) but we accept both
/// ARKit camelCase (eyeBlinkLeft) and Apple underscore (eyeBlink_L) formats.
enum BlendshapeOrder {
    
    /// Buffer slot order — what `_applyBlendShapesWithTrackingData:` reads from each slot.
    /// Determined empirically: set slot[i]=1.0, observe which VFXMorpher target activates.
    static let order: [String] = [
        "eyeBlink_L",         // 0
        "eyeBlink_R",         // 1
        "eyeSquint_L",        // 2
        "eyeSquint_R",        // 3
        "eyeLookDown_L",      // 4
        "eyeLookDown_R",      // 5
        "eyeLookIn_L",        // 6
        "eyeLookIn_R",        // 7
        "eyeWide_L",          // 8
        "eyeWide_R",          // 9
        "eyeLookOut_L",       // 10
        "eyeLookOut_R",       // 11
        "eyeLookUp_L",        // 12
        "eyeLookUp_R",        // 13
        "browDown_L",         // 14
        "browDown_R",         // 15
        "browInnerUp",        // 16
        "browOuterUp_L",      // 17
        "browOuterUp_R",      // 18
        "jawOpen",            // 19
        "mouthClose",         // 20
        "jawLeft",            // 21
        "jawRight",           // 22
        "jawForward",         // 23
        "mouthUpperUp_L",     // 24
        "mouthUpperUp_R",     // 25
        "mouthLowerDown_L",   // 26
        "mouthLowerDown_R",   // 27
        "mouthRollUpper",     // 28
        "mouthRollLower",     // 29
        "mouthSmile_L",       // 30
        "mouthSmile_R",       // 31
        "mouthDimple_L",      // 32
        "mouthDimple_R",      // 33
        "mouthStretch_L",     // 34
        "mouthStretch_R",     // 35
        "mouthFrown_L",       // 36
        "mouthFrown_R",       // 37
        "mouthPress_L",       // 38
        "mouthPress_R",       // 39
        "mouthPucker",        // 40
        "mouthFunnel",        // 41
        "mouthLeft",          // 42
        "mouthRight",         // 43
        "mouthShrugLower",    // 44
        "mouthShrugUpper",    // 45
        "noseSneer_L",        // 46
        "noseSneer_R",        // 47
        "cheekPuff",          // 48
        "cheekSquint_L",      // 49
        "cheekSquint_R",      // 50
    ]
    
    /// ARKit camelCase → Apple underscore name mapping.
    private static let arkitToApple: [String: String] = [
        "eyeBlinkLeft": "eyeBlink_L",
        "eyeBlinkRight": "eyeBlink_R",
        "eyeSquintLeft": "eyeSquint_L",
        "eyeSquintRight": "eyeSquint_R",
        "eyeLookDownLeft": "eyeLookDown_L",
        "eyeLookDownRight": "eyeLookDown_R",
        "eyeLookInLeft": "eyeLookIn_L",
        "eyeLookInRight": "eyeLookIn_R",
        "eyeWideLeft": "eyeWide_L",
        "eyeWideRight": "eyeWide_R",
        "eyeLookOutLeft": "eyeLookOut_L",
        "eyeLookOutRight": "eyeLookOut_R",
        "eyeLookUpLeft": "eyeLookUp_L",
        "eyeLookUpRight": "eyeLookUp_R",
        "browDownLeft": "browDown_L",
        "browDownRight": "browDown_R",
        "browInnerUp": "browInnerUp",
        "browOuterUpLeft": "browOuterUp_L",
        "browOuterUpRight": "browOuterUp_R",
        "jawOpen": "jawOpen",
        "mouthClose": "mouthClose",
        "jawLeft": "jawLeft",
        "jawRight": "jawRight",
        "jawForward": "jawForward",
        "mouthUpperUpLeft": "mouthUpperUp_L",
        "mouthUpperUpRight": "mouthUpperUp_R",
        "mouthLowerDownLeft": "mouthLowerDown_L",
        "mouthLowerDownRight": "mouthLowerDown_R",
        "mouthRollUpper": "mouthRollUpper",
        "mouthRollLower": "mouthRollLower",
        "mouthSmileLeft": "mouthSmile_L",
        "mouthSmileRight": "mouthSmile_R",
        "mouthDimpleLeft": "mouthDimple_L",
        "mouthDimpleRight": "mouthDimple_R",
        "mouthStretchLeft": "mouthStretch_L",
        "mouthStretchRight": "mouthStretch_R",
        "mouthFrownLeft": "mouthFrown_L",
        "mouthFrownRight": "mouthFrown_R",
        "mouthPressLeft": "mouthPress_L",
        "mouthPressRight": "mouthPress_R",
        "mouthPucker": "mouthPucker",
        "mouthFunnel": "mouthFunnel",
        "mouthLeft": "mouthLeft",
        "mouthRight": "mouthRight",
        "mouthShrugLower": "mouthShrugLower",
        "mouthShrugUpper": "mouthShrugUpper",
        "noseSneerLeft": "noseSneer_L",
        "noseSneerRight": "noseSneer_R",
        "cheekPuff": "cheekPuff",
        "cheekSquintLeft": "cheekSquint_L",
        "cheekSquintRight": "cheekSquint_R",
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
    
    /// All blendshape names in buffer order.
    static var names: [String] { order }
}
