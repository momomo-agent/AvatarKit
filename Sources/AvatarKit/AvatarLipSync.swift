import Foundation
import AVFoundation
import Accelerate

// MARK: - Viseme Definition

/// Standard viseme set based on Microsoft/Oculus mapping.
/// Each viseme maps to a set of ARKit blendshape weights.
public enum Viseme: Int, CaseIterable {
    case silence = 0    // —
    case ae = 1         // æ, ə, ʌ
    case aa = 2         // ɑ
    case ao = 3         // ɔ
    case eh = 4         // ɛ, ʊ
    case er = 5         // ɝ
    case ih = 6         // j, i, ɪ
    case uw = 7         // w, u
    case oh = 8         // o
    case ow = 9         // aʊ
    case oy = 10        // ɔɪ
    case ay = 11        // aɪ
    case h = 12         // h
    case r = 13         // ɹ
    case l = 14         // l
    case s = 15         // s, z
    case sh = 16        // ʃ, tʃ, dʒ, ʒ
    case th = 17        // ð
    case f = 18         // f, v
    case dt = 19        // d, t, n, θ
    case kg = 20        // k, g, ŋ
    case pp = 21        // p, b, m
    
    /// ARKit blendshape weights for this viseme.
    /// Tuned for Animoji — values are intentionally expressive.
    public var blendshapes: [String: Float] {
        switch self {
        case .silence:
            return [:]
        case .ae: // æ, ə, ʌ — mid-open, relaxed
            return [
                "jawOpen": 0.35,
                "mouthFunnel": 0.05,
                "mouthUpperUpLeft": 0.1, "mouthUpperUpRight": 0.1,
                "mouthLowerDownLeft": 0.15, "mouthLowerDownRight": 0.15,
            ]
        case .aa: // ɑ — wide open
            return [
                "jawOpen": 0.55,
                "mouthUpperUpLeft": 0.15, "mouthUpperUpRight": 0.15,
                "mouthLowerDownLeft": 0.25, "mouthLowerDownRight": 0.25,
            ]
        case .ao: // ɔ — rounded open
            return [
                "jawOpen": 0.45,
                "mouthFunnel": 0.25,
                "mouthPucker": 0.1,
            ]
        case .eh: // ɛ, ʊ — mid spread
            return [
                "jawOpen": 0.25,
                "mouthStretchLeft": 0.15, "mouthStretchRight": 0.15,
                "mouthLowerDownLeft": 0.1, "mouthLowerDownRight": 0.1,
            ]
        case .er: // ɝ — slightly rounded
            return [
                "jawOpen": 0.2,
                "mouthFunnel": 0.15,
                "mouthRollLower": 0.1,
            ]
        case .ih: // j, i, ɪ — spread, narrow
            return [
                "jawOpen": 0.12,
                "mouthSmileLeft": 0.2, "mouthSmileRight": 0.2,
                "mouthStretchLeft": 0.25, "mouthStretchRight": 0.25,
            ]
        case .uw: // w, u — tight round
            return [
                "jawOpen": 0.08,
                "mouthPucker": 0.5,
                "mouthFunnel": 0.35,
            ]
        case .oh: // o — round open
            return [
                "jawOpen": 0.35,
                "mouthFunnel": 0.4,
                "mouthPucker": 0.15,
            ]
        case .ow: // aʊ — open to round
            return [
                "jawOpen": 0.4,
                "mouthFunnel": 0.3,
                "mouthUpperUpLeft": 0.1, "mouthUpperUpRight": 0.1,
            ]
        case .oy: // ɔɪ — round to spread
            return [
                "jawOpen": 0.35,
                "mouthFunnel": 0.2,
                "mouthStretchLeft": 0.1, "mouthStretchRight": 0.1,
            ]
        case .ay: // aɪ — open to spread
            return [
                "jawOpen": 0.45,
                "mouthSmileLeft": 0.1, "mouthSmileRight": 0.1,
                "mouthUpperUpLeft": 0.1, "mouthUpperUpRight": 0.1,
            ]
        case .h: // h — relaxed open
            return [
                "jawOpen": 0.25,
            ]
        case .r: // ɹ — slight pucker
            return [
                "jawOpen": 0.15,
                "mouthFunnel": 0.2,
                "mouthPucker": 0.1,
            ]
        case .l: // l — tongue tip (jaw slightly open)
            return [
                "jawOpen": 0.18,
                "mouthUpperUpLeft": 0.05, "mouthUpperUpRight": 0.05,
            ]
        case .s: // s, z — teeth close, spread
            return [
                "jawOpen": 0.05,
                "mouthStretchLeft": 0.2, "mouthStretchRight": 0.2,
                "mouthClose": 0.3,
            ]
        case .sh: // ʃ, tʃ, dʒ, ʒ — rounded teeth
            return [
                "jawOpen": 0.08,
                "mouthFunnel": 0.3,
                "mouthShrugUpper": 0.15,
            ]
        case .th: // ð — tongue between teeth
            return [
                "jawOpen": 0.1,
                "mouthUpperUpLeft": 0.1, "mouthUpperUpRight": 0.1,
                "mouthLowerDownLeft": 0.1, "mouthLowerDownRight": 0.1,
            ]
        case .f: // f, v — lower lip to upper teeth
            return [
                "jawOpen": 0.03,
                "mouthUpperUpLeft": 0.15, "mouthUpperUpRight": 0.15,
                "mouthLowerDownLeft": 0.05, "mouthLowerDownRight": 0.05,
                "mouthClose": 0.15,
            ]
        case .dt: // d, t, n, θ — tongue to alveolar ridge
            return [
                "jawOpen": 0.1,
                "mouthClose": 0.2,
                "mouthStretchLeft": 0.1, "mouthStretchRight": 0.1,
            ]
        case .kg: // k, g, ŋ — back of tongue
            return [
                "jawOpen": 0.15,
                "mouthClose": 0.1,
            ]
        case .pp: // p, b, m — lips pressed
            return [
                "jawOpen": 0.02,
                "mouthClose": 0.6,
                "mouthPressLeft": 0.3, "mouthPressRight": 0.3,
                "mouthPucker": 0.15,
            ]
        }
    }
}

// MARK: - Viseme Keyframe

/// A single viseme event with timing information.
public struct VisemeKeyframe {
    /// The viseme to display.
    public let viseme: Viseme
    /// Time offset in seconds from the start of the audio.
    public let time: TimeInterval
    /// Duration of this viseme (used for interpolation).
    public let duration: TimeInterval
    
    public init(viseme: Viseme, time: TimeInterval, duration: TimeInterval = 0.05) {
        self.viseme = viseme
        self.time = time
        self.duration = duration
    }
}

// MARK: - Lip Sync Engine

/// Drives avatar lip sync from either viseme keyframes (TTS) or audio analysis (fallback).
///
/// Two modes:
/// 1. **Viseme mode**: Feed pre-computed VisemeKeyframes from TTS (Azure, ElevenLabs, etc.)
/// 2. **Audio mode**: Real-time FFT analysis of audio buffer, maps frequency bands to visemes
///
/// Both modes output AvatarFaceTracking at 60fps via the `onFrame` callback.
public class AvatarLipSync {
    
    // MARK: - Configuration
    
    /// Smoothing factor for blendshape transitions (0 = instant, 1 = no change).
    /// 0.3-0.5 gives natural-looking mouth movement.
    public var smoothing: Float = 0.35
    
    /// Coarticulation strength (0 = none, 1 = full anticipatory blending).
    /// Real speech has overlapping mouth shapes — the mouth starts forming
    /// the next sound before the current one finishes.
    public var coarticulation: Float = 0.3
    
    /// Overall intensity multiplier for lip sync blendshapes.
    public var intensity: Float = 1.0
    
    /// Called every frame with the computed mouth blendshapes.
    /// Merge these into your AvatarFaceTracking before calling applyTracking().
    public var onFrame: (([String: Float]) -> Void)?
    
    // MARK: - State
    
    private var displayLink: CADisplayLink?
    private var startTime: TimeInterval = 0
    private var currentBlendshapes: [String: Float] = [:]
    
    // Viseme mode
    private var keyframes: [VisemeKeyframe] = []
    private var keyframeIndex: Int = 0
    
    // Audio mode
    private var audioEngine: AVAudioEngine?
    private var fftSetup: vDSP_DFT_Setup?
    private let fftSize: Int = 512
    private var magnitudes: [Float] = []
    private var currentAudioViseme: Viseme = .silence
    private var audioAmplitude: Float = 0
    
    // MARK: - Init
    
    public init() {
        fftSetup = vDSP_DFT_zop_CreateSetup(nil, vDSP_Length(fftSize), .FORWARD)
        magnitudes = [Float](repeating: 0, count: fftSize / 2)
    }
    
    deinit {
        stop()
        if let setup = fftSetup {
            vDSP_DFT_DestroySetup(setup)
        }
    }
    
    // MARK: - Viseme Mode (TTS-driven)
    
    /// Start lip sync from pre-computed viseme keyframes.
    /// Typically from Azure Speech SDK viseme events or similar TTS output.
    public func startWithKeyframes(_ keyframes: [VisemeKeyframe]) {
        stop()
        self.keyframes = keyframes.sorted { $0.time < $1.time }
        self.keyframeIndex = 0
        self.startTime = CACurrentMediaTime()
        startDisplayLink()
    }
    
    /// Append a viseme keyframe in real-time (streaming TTS).
    public func appendKeyframe(_ keyframe: VisemeKeyframe) {
        keyframes.append(keyframe)
    }
    
    // MARK: - Audio Mode (FFT-driven fallback)
    
    /// Start lip sync by analyzing an audio node's output in real-time.
    /// Use this when no viseme data is available (playing music, voice messages, etc.)
    public func startWithAudioNode(_ node: AVAudioNode, engine: AVAudioEngine) {
        stop()
        self.audioEngine = engine
        
        let format = node.outputFormat(forBus: 0)
        node.installTap(onBus: 0, bufferSize: AVAudioFrameCount(fftSize), format: format) { [weak self] buffer, _ in
            self?.processAudioBuffer(buffer)
        }
        
        self.startTime = CACurrentMediaTime()
        startDisplayLink()
    }
    
    /// Start lip sync by analyzing an AVAudioPlayer's audio.
    /// Installs a tap on the audio engine's main mixer.
    public func startWithAudioEngine(_ engine: AVAudioEngine) {
        startWithAudioNode(engine.mainMixerNode, engine: engine)
    }
    
    // MARK: - Control
    
    public func stop() {
        displayLink?.invalidate()
        displayLink = nil
        
        // Remove audio tap if installed
        audioEngine?.mainMixerNode.removeTap(onBus: 0)
        audioEngine = nil
        
        keyframes = []
        keyframeIndex = 0
        currentBlendshapes = [:]
        currentAudioViseme = .silence
        audioAmplitude = 0
    }
    
    public var isRunning: Bool {
        displayLink != nil
    }
    
    // MARK: - Display Link
    
    private func startDisplayLink() {
        displayLink = CADisplayLink(target: self, selector: #selector(tick))
        displayLink?.preferredFrameRateRange = CAFrameRateRange(minimum: 30, maximum: 60, preferred: 60)
        displayLink?.add(to: .main, forMode: .common)
    }
    
    @objc private func tick() {
        let elapsed = CACurrentMediaTime() - startTime
        
        let targetBlendshapes: [String: Float]
        
        if !keyframes.isEmpty {
            targetBlendshapes = evaluateKeyframes(at: elapsed)
        } else {
            targetBlendshapes = evaluateAudio()
        }
        
        // Smooth transition
        var smoothed: [String: Float] = [:]
        let allKeys = Set(currentBlendshapes.keys).union(targetBlendshapes.keys)
        for key in allKeys {
            let current = currentBlendshapes[key] ?? 0
            let target = (targetBlendshapes[key] ?? 0) * intensity
            smoothed[key] = current + (target - current) * (1.0 - smoothing)
        }
        
        // Remove near-zero values
        smoothed = smoothed.filter { $0.value > 0.001 }
        
        currentBlendshapes = smoothed
        onFrame?(smoothed)
    }
    
    // MARK: - Viseme Evaluation
    
    private func evaluateKeyframes(at time: TimeInterval) -> [String: Float] {
        // Advance keyframe index
        while keyframeIndex < keyframes.count - 1 && keyframes[keyframeIndex + 1].time <= time {
            keyframeIndex += 1
        }
        
        guard keyframeIndex < keyframes.count else {
            return Viseme.silence.blendshapes
        }
        
        let current = keyframes[keyframeIndex]
        
        // If we have a next keyframe, interpolate with coarticulation
        if keyframeIndex + 1 < keyframes.count {
            let next = keyframes[keyframeIndex + 1]
            let segmentDuration = next.time - current.time
            guard segmentDuration > 0 else { return current.viseme.blendshapes }
            
            let t = Float((time - current.time) / segmentDuration)
            let clampedT = min(max(t, 0), 1)
            
            // Ease in-out for more natural movement
            let easedT = clampedT * clampedT * (3.0 - 2.0 * clampedT)
            
            var result = interpolateBlendshapes(
                from: current.viseme.blendshapes,
                to: next.viseme.blendshapes,
                t: easedT
            )
            
            // Coarticulation: blend in the NEXT-next viseme anticipatorily
            // The mouth starts preparing for upcoming sounds
            if coarticulation > 0, keyframeIndex + 2 < keyframes.count {
                let upcoming = keyframes[keyframeIndex + 2]
                let anticipation = clampedT * clampedT * coarticulation * 0.3
                if anticipation > 0.01 {
                    for (key, value) in upcoming.viseme.blendshapes {
                        result[key] = (result[key] ?? 0) + value * anticipation
                    }
                }
            }
            
            return result
        }
        
        // Last keyframe — hold then fade to silence
        let holdTime = current.time + current.duration
        if time > holdTime {
            let fadeT = Float((time - holdTime) / 0.15)
            let clampedT = min(fadeT, 1.0)
            return interpolateBlendshapes(
                from: current.viseme.blendshapes,
                to: Viseme.silence.blendshapes,
                t: clampedT
            )
        }
        
        return current.viseme.blendshapes
    }
    
    // MARK: - Audio Analysis
    
    private func processAudioBuffer(_ buffer: AVAudioPCMBuffer) {
        guard let channelData = buffer.floatChannelData?[0],
              let setup = fftSetup else { return }
        
        let frameCount = Int(buffer.frameLength)
        let count = min(frameCount, fftSize)
        
        // Calculate RMS amplitude
        var rms: Float = 0
        vDSP_rmsqv(channelData, 1, &rms, vDSP_Length(count))
        audioAmplitude = rms
        
        // Skip FFT if too quiet (silence threshold)
        guard rms > 0.01 else {
            currentAudioViseme = .silence
            return
        }
        
        // Apply Hann window
        var windowed = [Float](repeating: 0, count: fftSize)
        var window = [Float](repeating: 0, count: fftSize)
        vDSP_hann_window(&window, vDSP_Length(fftSize), Int32(vDSP_HANN_NORM))
        
        // Copy and zero-pad if needed
        for i in 0..<count {
            windowed[i] = channelData[i]
        }
        vDSP_vmul(windowed, 1, window, 1, &windowed, 1, vDSP_Length(fftSize))
        
        // FFT
        var realIn = [Float](repeating: 0, count: fftSize)
        let imagIn = [Float](repeating: 0, count: fftSize)
        var realOut = [Float](repeating: 0, count: fftSize)
        var imagOut = [Float](repeating: 0, count: fftSize)
        
        realIn = windowed
        vDSP_DFT_Execute(setup, realIn, imagIn, &realOut, &imagOut)
        
        // Magnitude spectrum (first half)
        let halfSize = fftSize / 2
        for i in 0..<halfSize {
            magnitudes[i] = sqrt(realOut[i] * realOut[i] + imagOut[i] * imagOut[i])
        }
        
        // Map frequency bands to viseme
        // Assuming 44100 Hz sample rate, each bin = 44100/512 ≈ 86 Hz
        // Speech fundamentals: 85-255 Hz (bins 1-3)
        // Formant F1: 200-900 Hz (bins 2-10)
        // Formant F2: 900-2500 Hz (bins 10-29)
        
        let binWidth: Float = 44100.0 / Float(fftSize)
        
        // Energy in frequency bands
        let lowEnergy = bandEnergy(from: 85, to: 300, binWidth: binWidth)    // F0 + low F1
        let midLowEnergy = bandEnergy(from: 300, to: 700, binWidth: binWidth) // F1
        let midEnergy = bandEnergy(from: 700, to: 1500, binWidth: binWidth)   // F1-F2 transition
        let highEnergy = bandEnergy(from: 1500, to: 3000, binWidth: binWidth) // F2
        let veryHighEnergy = bandEnergy(from: 3000, to: 6000, binWidth: binWidth) // fricatives
        
        let totalEnergy = lowEnergy + midLowEnergy + midEnergy + highEnergy + veryHighEnergy + 0.001
        
        // Classify based on spectral shape
        let lowRatio = lowEnergy / totalEnergy
        let midLowRatio = midLowEnergy / totalEnergy
        let highRatio = highEnergy / totalEnergy
        let veryHighRatio = veryHighEnergy / totalEnergy
        
        if veryHighRatio > 0.35 {
            // High frequency energy → fricatives (s, sh, f)
            currentAudioViseme = highRatio > 0.2 ? .sh : .s
        } else if lowRatio > 0.5 && midLowRatio < 0.15 {
            // Dominant low frequency → O/U sounds
            currentAudioViseme = .oh
        } else if midLowRatio > 0.35 {
            // Strong mid-low → A sounds
            currentAudioViseme = .aa
        } else if highRatio > 0.3 {
            // High F2 → E/I sounds
            currentAudioViseme = midLowRatio > 0.2 ? .eh : .ih
        } else if lowRatio > 0.3 && midLowRatio > 0.2 {
            // Balanced low-mid → open vowels
            currentAudioViseme = .ae
        } else {
            // Default to a neutral open mouth scaled by amplitude
            currentAudioViseme = .ae
        }
    }
    
    private func bandEnergy(from freqLow: Float, to freqHigh: Float, binWidth: Float) -> Float {
        let binLow = max(0, Int(freqLow / binWidth))
        let binHigh = min(magnitudes.count - 1, Int(freqHigh / binWidth))
        guard binLow <= binHigh else { return 0 }
        
        var energy: Float = 0
        for i in binLow...binHigh {
            energy += magnitudes[i] * magnitudes[i]
        }
        return sqrt(energy / Float(binHigh - binLow + 1))
    }
    
    private func evaluateAudio() -> [String: Float] {
        guard audioAmplitude > 0.01 else {
            return Viseme.silence.blendshapes
        }
        
        // Scale blendshapes by amplitude (louder = more exaggerated)
        let amplitudeScale = min(audioAmplitude * 5.0, 1.5) // Boost quiet speech, cap loud
        var blendshapes = currentAudioViseme.blendshapes
        for (key, value) in blendshapes {
            blendshapes[key] = value * amplitudeScale
        }
        return blendshapes
    }
    
    // MARK: - Interpolation
    
    private func interpolateBlendshapes(
        from a: [String: Float],
        to b: [String: Float],
        t: Float
    ) -> [String: Float] {
        var result: [String: Float] = [:]
        let allKeys = Set(a.keys).union(b.keys)
        for key in allKeys {
            let va = a[key] ?? 0
            let vb = b[key] ?? 0
            result[key] = va + (vb - va) * t
        }
        return result
    }
}

// MARK: - Azure Speech SDK Helpers

extension AvatarLipSync {
    
    /// Parse Azure Speech SDK blend shapes JSON output.
    /// Azure outputs a 2D array: each row is a frame (60fps), each frame has 55 float values.
    /// The 55 values map to ARKit blendshapes in Apple's order.
    ///
    /// Usage:
    /// ```
    /// let keyframes = AvatarLipSync.parseAzureBlendShapes(jsonString, audioOffset: 0)
    /// lipSync.startWithKeyframes(keyframes)
    /// ```
    public static func parseAzureBlendShapes(_ json: String, audioOffset: TimeInterval = 0) -> [VisemeKeyframe] {
        // Azure outputs 55 blendshape values per frame at 60fps
        // We convert to our viseme keyframes by finding the closest matching viseme
        guard let data = json.data(using: .utf8),
              let frames = try? JSONSerialization.jsonObject(with: data) as? [[Double]] else {
            return []
        }
        
        let frameDuration: TimeInterval = 1.0 / 60.0
        var keyframes: [VisemeKeyframe] = []
        
        for (i, frame) in frames.enumerated() {
            let time = audioOffset + Double(i) * frameDuration
            // Find best matching viseme based on jaw openness and other features
            let viseme = classifyAzureFrame(frame)
            keyframes.append(VisemeKeyframe(viseme: viseme, time: time, duration: frameDuration))
        }
        
        return keyframes
    }
    
    /// Parse Azure viseme ID events (simpler format).
    /// Each event has a viseme ID (0-21) and audio offset in ticks (100ns units).
    public static func parseAzureVisemeEvents(_ events: [(visemeId: Int, audioOffsetTicks: Int64)]) -> [VisemeKeyframe] {
        return events.compactMap { event in
            guard let viseme = Viseme(rawValue: event.visemeId) else { return nil }
            let time = TimeInterval(event.audioOffsetTicks) / 10_000_000.0 // ticks to seconds
            return VisemeKeyframe(viseme: viseme, time: time)
        }
    }
    
    private static func classifyAzureFrame(_ frame: [Double]) -> Viseme {
        guard frame.count >= 55 else { return .silence }
        
        // Key indices in Azure's 55-value blendshape array:
        // 26: jawOpen, 27: mouthClose, 31: mouthFunnel, 37: mouthPucker
        // 43: mouthSmileLeft, 44: mouthSmileRight
        // 34: mouthLowerDownLeft, 35: mouthLowerDownRight
        let jawOpen = Float(frame[26])
        let mouthClose = Float(frame[27])
        let mouthFunnel = Float(frame[31])
        let mouthPucker = Float(frame[37])
        
        if jawOpen < 0.05 && mouthClose > 0.3 {
            return .pp // lips pressed
        } else if mouthPucker > 0.3 {
            return mouthFunnel > 0.2 ? .uw : .oh
        } else if mouthFunnel > 0.3 {
            return jawOpen > 0.3 ? .ao : .sh
        } else if jawOpen > 0.4 {
            return .aa
        } else if jawOpen > 0.2 {
            return .ae
        } else if jawOpen > 0.1 {
            return .eh
        } else if jawOpen > 0.03 {
            return .s
        } else {
            return .silence
        }
    }
}
