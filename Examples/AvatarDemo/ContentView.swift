import SwiftUI
import AvatarKit

struct ContentView: View {
    @State private var bridge = AvatarBridge()
    @State private var character = "cat"
    @State private var currentExpr = "neutral"
    
    // Extreme eye test presets
    private let eyeTests: [(String, ExpressionPreset)] = [
        ("Normal", .neutral),
        ("Left Blink", ExpressionPreset(name: "leftBlink", blendshapes: [
            "eyeBlinkLeft": 1.0,
        ])),
        ("Both Blink", ExpressionPreset(name: "bothBlink", blendshapes: [
            "eyeBlinkLeft": 1.0, "eyeBlinkRight": 1.0,
        ])),
        ("Wide Open", ExpressionPreset(name: "wideOpen", blendshapes: [
            "eyeWideLeft": 1.0, "eyeWideRight": 1.0,
            "browOuterUpLeft": 1.0, "browOuterUpRight": 1.0,
            "browInnerUp": 1.0,
        ])),
        ("Squint", ExpressionPreset(name: "squint", blendshapes: [
            "eyeSquintLeft": 1.0, "eyeSquintRight": 1.0,
        ])),
        ("Look Up", ExpressionPreset(name: "lookUp", blendshapes: [
            "eyeLookUpLeft": 1.0, "eyeLookUpRight": 1.0,
        ])),
        ("Look Down", ExpressionPreset(name: "lookDown", blendshapes: [
            "eyeLookDownLeft": 1.0, "eyeLookDownRight": 1.0,
        ])),
        ("Surprised", .surprised),
        ("Sleepy", .sleepy),
        ("Wink L", .winkLeft),
    ]
    
    var body: some View {
        VStack(spacing: 0) {
            ZStack(alignment: .topLeading) {
                AvatarView(bridge: bridge, character: character)
                    .frame(maxWidth: .infinity)
                    .frame(height: 400)
                    .background(Color(.systemBackground))
                
                Text("\(character) — \(currentExpr)")
                    .font(.headline)
                    .padding(8)
                    .background(.ultraThinMaterial, in: RoundedRectangle(cornerRadius: 8))
                    .padding(12)
            }
            
            // Character picker
            ScrollView(.horizontal, showsIndicators: false) {
                HStack(spacing: 12) {
                    ForEach(AvatarBridge.availableAnimoji, id: \.self) { name in
                        Button(name) {
                            character = name
                            currentExpr = "loaded"
                        }
                        .buttonStyle(.bordered)
                        .tint(character == name ? .blue : .gray)
                    }
                }
                .padding(.horizontal)
            }
            .padding(.vertical, 8)
            
            // Eye test buttons
            Text("Eye Tests").font(.caption).foregroundStyle(.secondary)
            ScrollView {
                LazyVGrid(columns: [GridItem(.adaptive(minimum: 100))], spacing: 8) {
                    ForEach(eyeTests, id: \.0) { label, preset in
                        Button(label) {
                            bridge.applyPreset(preset)
                            currentExpr = preset.name
                        }
                        .buttonStyle(.bordered)
                        .font(.caption)
                    }
                }
                .padding(.horizontal)
            }
        }
    }
}
