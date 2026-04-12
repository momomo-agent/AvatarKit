import Foundation
import simd

/// Preset facial expressions mapped to iOS face emoji.
/// Each preset is a set of ARKit blendshape values that approximate the emoji's expression.
extension AvatarFaceTracking {
    
    // MARK: - Happy / Positive
    
    /// 😀 Grinning Face — big open smile
    public static let grinning = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.9, "mouthSmileRight": 0.9,
            "jawOpen": 0.3,
            "cheekSquintLeft": 0.3, "cheekSquintRight": 0.3,
        ]
    )
    
    /// 😃 Grinning Face with Big Eyes — excited smile, eyes wide
    public static let grinningBigEyes = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.9, "mouthSmileRight": 0.9,
            "jawOpen": 0.35,
            "eyeWideLeft": 0.5, "eyeWideRight": 0.5,
        ]
    )
    
    /// 😄 Grinning Face with Smiling Eyes — happy smile, eyes squint
    public static let grinningSmileEyes = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.9, "mouthSmileRight": 0.9,
            "jawOpen": 0.3,
            "eyeSquintLeft": 0.6, "eyeSquintRight": 0.6,
            "cheekSquintLeft": 0.5, "cheekSquintRight": 0.5,
        ]
    )
    
    /// 😁 Beaming Face with Smiling Eyes — teeth showing grin
    public static let beaming = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 1.0, "mouthSmileRight": 1.0,
            "jawOpen": 0.15,
            "eyeSquintLeft": 0.7, "eyeSquintRight": 0.7,
            "cheekSquintLeft": 0.6, "cheekSquintRight": 0.6,
        ]
    )
    
    /// 😆 Grinning Squinting Face — laughing hard
    public static let squintingLaugh = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 1.0, "mouthSmileRight": 1.0,
            "jawOpen": 0.4,
            "eyeSquintLeft": 0.9, "eyeSquintRight": 0.9,
            "cheekSquintLeft": 0.7, "cheekSquintRight": 0.7,
            "noseSneerLeft": 0.3, "noseSneerRight": 0.3,
        ]
    )
    
    /// 🙂 Slightly Smiling Face — subtle smile
    public static let slightSmile = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.4, "mouthSmileRight": 0.4,
        ]
    )
    
    /// 😊 Smiling Face with Smiling Eyes — warm smile
    public static let warmSmile = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.6, "mouthSmileRight": 0.6,
            "eyeSquintLeft": 0.5, "eyeSquintRight": 0.5,
            "cheekSquintLeft": 0.4, "cheekSquintRight": 0.4,
        ]
    )
    
    // MARK: - Wink / Playful
    
    /// 😉 Winking Face
    public static let wink = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.5, "mouthSmileRight": 0.5,
            "eyeBlinkRight": 0.9,
        ]
    )
    
    /// 😜 Winking Face with Tongue
    public static let winkTongue = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.5, "mouthSmileRight": 0.5,
            "eyeBlinkRight": 0.9,
            "tongueOut": 0.8,
        ]
    )
    
    /// 😛 Face with Tongue
    public static let tongue = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.3, "mouthSmileRight": 0.3,
            "tongueOut": 0.9,
        ]
    )
    
    /// 😝 Squinting Face with Tongue
    public static let squintTongue = AvatarFaceTracking(
        blendshapes: [
            "eyeSquintLeft": 0.9, "eyeSquintRight": 0.9,
            "mouthSmileLeft": 0.4, "mouthSmileRight": 0.4,
            "tongueOut": 0.9,
        ]
    )
    
    // MARK: - Kiss / Pucker
    
    /// 😘 Face Blowing a Kiss
    public static let blowKiss = AvatarFaceTracking(
        blendshapes: [
            "mouthPucker": 0.9,
            "eyeBlinkRight": 0.9,
        ]
    )
    
    /// 😗 Kissing Face — puckered lips
    public static let kiss = AvatarFaceTracking(
        blendshapes: [
            "mouthPucker": 0.8,
        ]
    )
    
    /// 😚 Kissing Face with Closed Eyes
    public static let kissClosedEyes = AvatarFaceTracking(
        blendshapes: [
            "mouthPucker": 0.8,
            "eyeBlinkLeft": 0.9, "eyeBlinkRight": 0.9,
            "eyeSquintLeft": 0.5, "eyeSquintRight": 0.5,
        ]
    )
    
    // MARK: - Surprised / Shocked
    
    /// 😮 Face with Open Mouth
    public static let openMouth = AvatarFaceTracking(
        blendshapes: [
            "jawOpen": 0.6,
            "eyeWideLeft": 0.4, "eyeWideRight": 0.4,
        ]
    )
    
    /// 😲 Astonished Face — very surprised
    public static let astonished = AvatarFaceTracking(
        blendshapes: [
            "jawOpen": 0.8,
            "eyeWideLeft": 0.9, "eyeWideRight": 0.9,
            "browInnerUp": 0.8,
            "browOuterUpLeft": 0.7, "browOuterUpRight": 0.7,
        ]
    )
    
    /// 😳 Flushed Face — wide eyes, slight embarrassment
    public static let flushed = AvatarFaceTracking(
        blendshapes: [
            "eyeWideLeft": 0.8, "eyeWideRight": 0.8,
            "browInnerUp": 0.5,
        ]
    )
    
    /// 😱 Face Screaming in Fear
    public static let scream = AvatarFaceTracking(
        blendshapes: [
            "jawOpen": 1.0,
            "eyeWideLeft": 1.0, "eyeWideRight": 1.0,
            "browInnerUp": 0.9,
            "browOuterUpLeft": 0.8, "browOuterUpRight": 0.8,
            "cheekPuff": 0.3,
        ]
    )
    
    // MARK: - Sad / Crying
    
    /// 🙁 Slightly Frowning Face
    public static let slightFrown = AvatarFaceTracking(
        blendshapes: [
            "mouthFrownLeft": 0.5, "mouthFrownRight": 0.5,
            "browInnerUp": 0.3,
        ]
    )
    
    /// ☹️ Frowning Face
    public static let frown = AvatarFaceTracking(
        blendshapes: [
            "mouthFrownLeft": 0.8, "mouthFrownRight": 0.8,
            "browInnerUp": 0.5,
            "browDownLeft": 0.3, "browDownRight": 0.3,
        ]
    )
    
    /// 😢 Crying Face
    public static let crying = AvatarFaceTracking(
        blendshapes: [
            "mouthFrownLeft": 0.7, "mouthFrownRight": 0.7,
            "browInnerUp": 0.7,
            "eyeSquintLeft": 0.4, "eyeSquintRight": 0.4,
        ]
    )
    
    /// 😭 Loudly Crying Face
    public static let loudCrying = AvatarFaceTracking(
        blendshapes: [
            "mouthFrownLeft": 0.9, "mouthFrownRight": 0.9,
            "jawOpen": 0.5,
            "browInnerUp": 0.9,
            "eyeSquintLeft": 0.8, "eyeSquintRight": 0.8,
            "cheekSquintLeft": 0.5, "cheekSquintRight": 0.5,
        ]
    )
    
    /// 🥺 Pleading Face — puppy eyes
    public static let pleading = AvatarFaceTracking(
        blendshapes: [
            "browInnerUp": 0.9,
            "browOuterUpLeft": 0.3, "browOuterUpRight": 0.3,
            "eyeWideLeft": 0.6, "eyeWideRight": 0.6,
            "mouthFrownLeft": 0.3, "mouthFrownRight": 0.3,
        ]
    )
    
    /// 😞 Disappointed Face
    public static let disappointed = AvatarFaceTracking(
        blendshapes: [
            "mouthFrownLeft": 0.6, "mouthFrownRight": 0.6,
            "browInnerUp": 0.4,
            "eyeLookDownLeft": 0.5, "eyeLookDownRight": 0.5,
        ]
    )
    
    // MARK: - Angry
    
    /// 😠 Angry Face
    public static let angry = AvatarFaceTracking(
        blendshapes: [
            "browDownLeft": 0.8, "browDownRight": 0.8,
            "mouthFrownLeft": 0.6, "mouthFrownRight": 0.6,
            "jawForward": 0.3,
            "noseSneerLeft": 0.4, "noseSneerRight": 0.4,
        ]
    )
    
    /// 😡 Pouting Face — very angry
    public static let pouting = AvatarFaceTracking(
        blendshapes: [
            "browDownLeft": 1.0, "browDownRight": 1.0,
            "mouthFrownLeft": 0.8, "mouthFrownRight": 0.8,
            "jawForward": 0.4,
            "noseSneerLeft": 0.6, "noseSneerRight": 0.6,
            "mouthPressLeft": 0.5, "mouthPressRight": 0.5,
        ]
    )
    
    /// 😤 Face with Steam from Nose — determined/frustrated
    public static let steamNose = AvatarFaceTracking(
        blendshapes: [
            "browDownLeft": 0.7, "browDownRight": 0.7,
            "mouthPressLeft": 0.6, "mouthPressRight": 0.6,
            "noseSneerLeft": 0.7, "noseSneerRight": 0.7,
            "jawForward": 0.2,
        ]
    )
    
    // MARK: - Skeptical / Thinking
    
    /// 🤨 Face with Raised Eyebrow
    public static let raisedBrow = AvatarFaceTracking(
        blendshapes: [
            "browOuterUpRight": 0.9,
            "browDownLeft": 0.4,
            "eyeSquintLeft": 0.3,
        ]
    )
    
    /// 😏 Smirking Face — one-sided smile
    public static let smirk = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileRight": 0.7,
            "mouthSmileLeft": 0.1,
            "eyeSquintRight": 0.3,
        ]
    )
    
    /// 😒 Unamused Face
    public static let unamused = AvatarFaceTracking(
        blendshapes: [
            "mouthFrownLeft": 0.4, "mouthFrownRight": 0.4,
            "eyeSquintLeft": 0.4, "eyeSquintRight": 0.4,
            "browDownLeft": 0.3, "browDownRight": 0.3,
            "eyeLookDownLeft": 0.3, "eyeLookDownRight": 0.3,
        ]
    )
    
    /// 🙄 Face with Rolling Eyes
    public static let rollingEyes = AvatarFaceTracking(
        blendshapes: [
            "eyeLookUpLeft": 0.9, "eyeLookUpRight": 0.9,
            "mouthFrownLeft": 0.2, "mouthFrownRight": 0.2,
        ]
    )
    
    // MARK: - Neutral / Expressionless
    
    /// 😐 Neutral Face
    public static let neutral = AvatarFaceTracking(
        blendshapes: [:]
    )
    
    /// 😑 Expressionless Face — eyes half closed
    public static let expressionless = AvatarFaceTracking(
        blendshapes: [
            "eyeBlinkLeft": 0.5, "eyeBlinkRight": 0.5,
            "mouthPressLeft": 0.3, "mouthPressRight": 0.3,
        ]
    )
    
    // MARK: - Sleepy / Tired
    
    /// 😴 Sleeping Face
    public static let sleeping = AvatarFaceTracking(
        blendshapes: [
            "eyeBlinkLeft": 1.0, "eyeBlinkRight": 1.0,
            "mouthClose": 0.5,
        ],
        headRotation: .init(roll: 17) // slight head tilt
    )
    
    /// 😪 Sleepy Face
    public static let sleepy = AvatarFaceTracking(
        blendshapes: [
            "eyeBlinkLeft": 0.7, "eyeBlinkRight": 0.7,
            "eyeSquintLeft": 0.5, "eyeSquintRight": 0.5,
            "mouthFrownLeft": 0.2, "mouthFrownRight": 0.2,
        ]
    )
    
    /// 🥱 Yawning Face
    public static let yawn = AvatarFaceTracking(
        blendshapes: [
            "jawOpen": 0.9,
            "mouthFunnel": 0.6,
            "eyeSquintLeft": 0.6, "eyeSquintRight": 0.6,
            "browInnerUp": 0.3,
        ]
    )
    
    // MARK: - Grimace / Awkward
    
    /// 😬 Grimacing Face — teeth clenched
    public static let grimace = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.6, "mouthSmileRight": 0.6,
            "mouthStretchLeft": 0.7, "mouthStretchRight": 0.7,
            "jawOpen": 0.1,
            "eyeWideLeft": 0.4, "eyeWideRight": 0.4,
        ]
    )
    
    /// 😖 Confounded Face
    public static let confounded = AvatarFaceTracking(
        blendshapes: [
            "mouthFrownLeft": 0.7, "mouthFrownRight": 0.7,
            "eyeSquintLeft": 0.9, "eyeSquintRight": 0.9,
            "browDownLeft": 0.5, "browDownRight": 0.5,
            "browInnerUp": 0.6,
            "mouthPucker": 0.3,
        ]
    )
    
    // MARK: - Cheeks
    
    /// 🤗 Hugging Face — big warm smile, cheeks puffed slightly
    public static let hugging = AvatarFaceTracking(
        blendshapes: [
            "mouthSmileLeft": 0.8, "mouthSmileRight": 0.8,
            "eyeSquintLeft": 0.4, "eyeSquintRight": 0.4,
            "cheekPuff": 0.3,
            "cheekSquintLeft": 0.4, "cheekSquintRight": 0.4,
        ]
    )
    
    /// 😶 Face Without Mouth — mouth completely closed/pressed
    public static let noMouth = AvatarFaceTracking(
        blendshapes: [
            "mouthClose": 0.9,
            "mouthPressLeft": 0.8, "mouthPressRight": 0.8,
            "mouthRollLower": 0.5, "mouthRollUpper": 0.5,
        ]
    )
    
    // MARK: - All Presets
    
    /// All available preset expressions with their emoji and name.
    public static let allPresets: [(emoji: String, name: String, expression: AvatarFaceTracking)] = [
        ("😀", "grinning", .grinning),
        ("😃", "grinningBigEyes", .grinningBigEyes),
        ("😄", "grinningSmileEyes", .grinningSmileEyes),
        ("😁", "beaming", .beaming),
        ("😆", "squintingLaugh", .squintingLaugh),
        ("🙂", "slightSmile", .slightSmile),
        ("😊", "warmSmile", .warmSmile),
        ("😉", "wink", .wink),
        ("😜", "winkTongue", .winkTongue),
        ("😛", "tongue", .tongue),
        ("😝", "squintTongue", .squintTongue),
        ("😘", "blowKiss", .blowKiss),
        ("😗", "kiss", .kiss),
        ("😚", "kissClosedEyes", .kissClosedEyes),
        ("😮", "openMouth", .openMouth),
        ("😲", "astonished", .astonished),
        ("😳", "flushed", .flushed),
        ("😱", "scream", .scream),
        ("🙁", "slightFrown", .slightFrown),
        ("☹️", "frown", .frown),
        ("😢", "crying", .crying),
        ("😭", "loudCrying", .loudCrying),
        ("🥺", "pleading", .pleading),
        ("😞", "disappointed", .disappointed),
        ("😠", "angry", .angry),
        ("😡", "pouting", .pouting),
        ("😤", "steamNose", .steamNose),
        ("🤨", "raisedBrow", .raisedBrow),
        ("😏", "smirk", .smirk),
        ("😒", "unamused", .unamused),
        ("🙄", "rollingEyes", .rollingEyes),
        ("😐", "neutral", .neutral),
        ("😑", "expressionless", .expressionless),
        ("😴", "sleeping", .sleeping),
        ("😪", "sleepy", .sleepy),
        ("🥱", "yawn", .yawn),
        ("😬", "grimace", .grimace),
        ("😖", "confounded", .confounded),
        ("🤗", "hugging", .hugging),
        ("😶", "noMouth", .noMouth),
    ]
}
