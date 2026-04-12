import SwiftUI
import AvatarKit

struct ContentView: View {
    @State private var bridge = AvatarBridge()
    @State private var character = "cat"
    @State private var testLog: [String] = []
    @State private var isTesting = false
    @State private var currentExpr = "neutral"
    @State private var exprIndex = 0
    
    private let characters = AvatarBridge.availableAnimoji
    
    private let presets: [(String, ExpressionPreset)] = [
        ("😊 Smile", .smile),
        ("😃 Grin", .grin),
        ("😢 Sad", .sad),
        ("😮 Surprised", .surprised),
        ("😠 Angry", .angry),
        ("😉 Wink", .winkLeft),
        ("😛 Tongue", .tongueOut),
        ("🤔 Think", .thinking),
        ("😴 Sleepy", .sleepy),
        ("😐 Neutral", .neutral),
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
                    ForEach(characters, id: \.self) { name in
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
            
            // Expression buttons
            ScrollView(.horizontal, showsIndicators: false) {
                HStack(spacing: 8) {
                    ForEach(presets, id: \.0) { label, preset in
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
            .padding(.vertical, 8)
            
            // Auto-cycle button — cycles through expressions every 2 seconds
            HStack {
                Button(isTesting ? "⏹ Stop" : "▶️ Auto Cycle") {
                    isTesting.toggle()
                    if isTesting { startCycle() }
                }
                .buttonStyle(.borderedProminent)
            }
            .padding(.vertical, 8)
            
            // Test log
            ScrollView {
                Text(testLog.joined(separator: "\n"))
                    .font(.system(.caption, design: .monospaced))
                    .frame(maxWidth: .infinity, alignment: .leading)
                    .padding(.horizontal)
            }
        }
        .onAppear {
            // Start auto-cycle after 1 second for automated testing
            DispatchQueue.main.asyncAfter(deadline: .now() + 1.0) {
                isTesting = true
                startCycle()
            }
        }
    }
    
    private func startCycle() {
        guard isTesting else { return }
        
        let (label, preset) = presets[exprIndex % presets.count]
        bridge.applyPreset(preset)
        currentExpr = preset.name
        testLog.append("[\(exprIndex)] \(label)")
        
        // Keep only last 10 lines
        if testLog.count > 10 { testLog.removeFirst() }
        
        exprIndex += 1
        
        // After cycling all expressions, stop
        if exprIndex >= presets.count {
            isTesting = false
            testLog.append("=== Cycle complete ===")
            return
        }
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 2.0) {
            startCycle()
        }
    }
}
