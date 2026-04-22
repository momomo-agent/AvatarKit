import SwiftUI
import AvatarKit

struct ContentView: View {
    @State private var bridge = AvatarBridge()
    @State private var character = "cat"
    @State private var currentExpr = "neutral"
    @State private var idleActive = false
    
    // Behavior engine for autonomous animation
    @State private var behaviorEngine: AvatarBehaviorEngine?
    
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
        GeometryReader { geo in
            VStack(spacing: 0) {
                // Avatar — fills top portion, edge to edge
                ZStack(alignment: .topLeading) {
                    AvatarView(bridge: bridge, character: character)
                        .frame(maxWidth: .infinity)
                        .frame(height: geo.size.height * 0.55)
                    
                    Text("\(character) — \(currentExpr)")
                        .font(.caption.weight(.medium))
                        .padding(.horizontal, 10)
                        .padding(.vertical, 5)
                        .background(.ultraThinMaterial, in: Capsule())
                        .padding(.top, geo.safeAreaInsets.top + 8)
                        .padding(.leading, 12)
                }
                
                // Controls panel
                VStack(spacing: 10) {
                    // Idle animation toggle
                    HStack {
                        Button(idleActive ? "Stop Idle" : "Start Idle") {
                            toggleIdle()
                        }
                        .buttonStyle(.borderedProminent)
                        .controlSize(.small)
                        .tint(idleActive ? .red : .green)
                        
                        if idleActive {
                            // Mood buttons
                            ForEach(["Neutral", "Happy", "Thinking", "Concerned"], id: \.self) { mood in
                                Button(mood) {
                                    setMood(mood)
                                    currentExpr = "idle:\(mood.lowercased())"
                                }
                                .buttonStyle(.bordered)
                                .controlSize(.mini)
                                .font(.caption2)
                            }
                        }
                    }
                    .padding(.horizontal, 16)
                    
                    // Character picker
                    ScrollView(.horizontal, showsIndicators: false) {
                        HStack(spacing: 10) {
                            ForEach(AvatarBridge.availableAnimoji, id: \.self) { name in
                                Button(name) {
                                    character = name
                                    currentExpr = "loaded"
                                    // Restart idle if active
                                    if idleActive {
                                        stopIdle()
                                        DispatchQueue.main.asyncAfter(deadline: .now() + 0.3) {
                                            startIdle()
                                        }
                                    }
                                }
                                .buttonStyle(.bordered)
                                .controlSize(.small)
                                .tint(character == name ? .blue : .gray)
                            }
                        }
                        .padding(.horizontal, 16)
                    }
                    
                    Divider().padding(.horizontal, 16)
                    
                    // Expression grid (disabled when idle is running)
                    ScrollView {
                        LazyVGrid(columns: [GridItem(.adaptive(minimum: 90))], spacing: 8) {
                            ForEach(eyeTests, id: \.0) { label, preset in
                                Button(label) {
                                    stopIdle()
                                    bridge.applyPreset(preset)
                                    currentExpr = preset.name
                                }
                                .buttonStyle(.bordered)
                                .controlSize(.small)
                                .font(.caption)
                                .disabled(idleActive)
                                .opacity(idleActive ? 0.4 : 1.0)
                            }
                        }
                        .padding(.horizontal, 16)
                    }
                }
                .padding(.top, 12)
            }
            .ignoresSafeArea(edges: .top)
        }
    }
    
    // MARK: - Idle Animation
    
    private func toggleIdle() {
        if idleActive {
            stopIdle()
        } else {
            startIdle()
        }
    }
    
    private func startIdle() {
        let engine = AvatarBehaviorEngine()
        
        // Wire engine output → bridge
        engine.onFrame = { [bridge] tracking in
            bridge.applyTracking(tracking)
        }
        
        engine.start()
        behaviorEngine = engine
        idleActive = true
        currentExpr = "idle"
    }
    
    private func stopIdle() {
        behaviorEngine?.stop()
        behaviorEngine = nil
        idleActive = false
        // Reset to neutral
        bridge.applyPreset(.neutral)
        currentExpr = "neutral"
    }
    
    private func setMood(_ name: String) {
        guard let engine = behaviorEngine else { return }
        switch name {
        case "Happy": engine.idleAnimator.setMood(.happy)
        case "Thinking":
            engine.transition(to: .thinking)
        case "Concerned": engine.idleAnimator.setMood(.concerned)
        default: engine.idleAnimator.setMood(.neutral)
        }
    }
}
