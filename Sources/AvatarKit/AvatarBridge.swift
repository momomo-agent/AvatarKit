import Foundation
import UIKit
import ARKit
import simd
import QuartzCore

/// Internal bridge to Apple's private AvatarKit framework.
/// Handles framework loading, avatar creation, and tracking data application.
/// All interaction is via ObjC runtime — no headers needed.
@MainActor
final class AvatarBridge {
    
    private(set) var avtView: NSObject?
    private var avatar: NSObject?
    private var frameworkLoaded = false
    private var trackInfoCls: AnyClass?
    private var frameCount = 0
    
    /// Cached tracking data bytes from a real ARFrame (neutral forward-facing).
    /// Used as baseline for preset expressions — only blendshapes get overwritten.
    private var baselineTrackingData: Data?
    
    // MARK: - Setup
    
    private func ensureFramework() -> Bool {
        if frameworkLoaded { return true }
        let handle = dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY)
        frameworkLoaded = handle != nil
        trackInfoCls = NSClassFromString("AVTFaceTrackingInfo")
        return frameworkLoaded
    }
    
    func createView(frame: CGRect) -> UIView? {
        guard ensureFramework() else { return nil }
        guard let viewClass = NSClassFromString("AVTRecordView") as? UIView.Type else { return nil }
        
        let view = viewClass.init(frame: frame)
        self.avtView = view as? NSObject
        view.backgroundColor = .clear
        setBool(on: view as NSObject, selector: "setRendersContinuously:", value: true)
        // Disable AVTRecordView's built-in ARSession face tracking
        // to prevent conflict with external ARSession (e.g. HumanSenseKit).
        // These selectors may not exist — setBool safely checks responds(to:).
        setBool(on: view as NSObject, selector: "setAutoTrackingEnabled:", value: false)
        setBool(on: view as NSObject, selector: "setFaceTrackingEnabled:", value: false)
        // Try to pause any internal ARSession
        let arSel = NSSelectorFromString("arSession")
        if (view as NSObject).responds(to: arSel),
           let session = (view as NSObject).perform(arSel)?.takeUnretainedValue() as? ARSession {
            session.pause()
            NSLog("[AvatarBridge] Paused AVTRecordView's internal ARSession")
        }
        return view
    }
    
    // MARK: - Avatar Loading
    
    func loadAnimoji(_ name: String) {
        guard ensureFramework() else { return }
        guard let animojiCls = NSClassFromString("AVTAnimoji") else { return }
        
        let sel = NSSelectorFromString("animojiNamed:")
        guard animojiCls.responds(to: sel) else { return }
        guard let result = (animojiCls as AnyObject).perform(sel, with: name) else { return }
        let newAvatar = result.takeUnretainedValue() as! NSObject
        
        self.avatar = newAvatar
        avtView?.setValue(newAvatar, forKeyPath: "avatar")
        
        // Default to front-facing neutral pose — AVTRecordView's default is back-of-head
        applyTracking(.neutral)
    }
    
    // MARK: - Apply Tracking Data
    
    /// Apply face tracking data from any source.
    func applyTracking(_ tracking: AvatarFaceTracking) {
        guard let avatar = avatar, let trackInfoCls = trackInfoCls else { return }
        
        frameCount += 1
        
        // Prefer baseline path (correct orientation from real ARFrame),
        // fall back to manual struct with 180° Y rotation
        guard let trackingInfo = buildTrackingInfoFromBaseline(tracking)
                ?? buildTrackingInfo(tracking) else { return }
        
        // Always apply blendshapes
        let bsSel = NSSelectorFromString("applyBlendShapesWithTrackingInfo:")
        if avatar.responds(to: bsSel) {
            avatar.perform(bsSel, with: trackingInfo)
        }
        
        // Always apply head pose — the trackingInfo already contains the correct orientation
        // (from baseline if available, or from the manual struct).
        // Skipping this leaves the avatar in whatever pose it was last in (possibly back-of-head).
        let poseSel = NSSelectorFromString("applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:")
        if avatar.responds(to: poseSel),
           let poseMethod = class_getInstanceMethod(type(of: avatar), poseSel) {
            let poseImp = method_getImplementation(poseMethod)
            typealias PoseFunc = @convention(c) (NSObject, Selector, NSObject, Bool, NSObject?) -> Void
            let poseFn = unsafeBitCast(poseImp, to: PoseFunc.self)
            poseFn(avatar, poseSel, trackingInfo, false, nil)
        }
    }
    
    // MARK: - Build TrackingInfo
    
    /// Apply an ARFrame directly using AvatarKit's own dataWithARFrame pipeline.
    /// This is the most reliable path — AvatarKit handles all orientation mapping internally.
    func applyARFrame(_ frame: ARFrame) {
        guard let avatar = avatar, let trackInfoCls = trackInfoCls else { return }
        guard frame.anchors.contains(where: { $0 is ARFaceAnchor }) else { return }
        
        frameCount += 1
        
        guard let meta = object_getClass(trackInfoCls) else { return }
        
        // Step 1: ARFrame → raw NSData via dataWithARFrame:captureOrientation:interfaceOrientation:
        let dataSel = NSSelectorFromString("dataWithARFrame:captureOrientation:interfaceOrientation:")
        guard let dataMethod = class_getClassMethod(meta, dataSel) else { return }
        let dataImp = method_getImplementation(dataMethod)
        typealias DataFunc = @convention(c) (AnyClass, Selector, AnyObject, Int, Int) -> NSObject?
        let dataFn = unsafeBitCast(dataImp, to: DataFunc.self)
        guard let data = dataFn(trackInfoCls, dataSel, frame, 4, 1) else { return }
        
        guard let nsData = data as? Data else { return }
        
        // Cache first frame's tracking data as baseline for presets
        if baselineTrackingData == nil {
            baselineTrackingData = nsData
            // Log the orientation from baseline so we know what "forward" looks like
            nsData.withUnsafeBytes { raw in
                let base = raw.baseAddress!
                let qx = (base + 24).load(as: Float.self)
                let qy = (base + 28).load(as: Float.self)
                let qz = (base + 32).load(as: Float.self)
                let qw = (base + 36).load(as: Float.self)
                print("[AvatarKit] ✅ Baseline captured (\(nsData.count) bytes) orientation=(\(qx), \(qy), \(qz), \(qw))")
            }
        }
        
        // Step 2: NSData → AVTFaceTrackingInfo via trackingInfoWithTrackingData:
        let infoSel = NSSelectorFromString("trackingInfoWithTrackingData:")
        guard let infoMethod = class_getClassMethod(meta, infoSel) else { return }
        let infoImp = method_getImplementation(infoMethod)
        
        guard let trackingInfo = nsData.withUnsafeBytes({ rawBuf -> NSObject? in
            typealias InfoFunc = @convention(c) (AnyClass, Selector, UnsafeRawPointer) -> NSObject?
            let infoFn = unsafeBitCast(infoImp, to: InfoFunc.self)
            return infoFn(trackInfoCls, infoSel, rawBuf.baseAddress!)
        }) else { return }
        
        // Apply blendshapes + head pose
        let bsSel = NSSelectorFromString("applyBlendShapesWithTrackingInfo:")
        if avatar.responds(to: bsSel) {
            avatar.perform(bsSel, with: trackingInfo)
        }
        
        let poseSel = NSSelectorFromString("applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:")
        if avatar.responds(to: poseSel),
           let poseMethod = class_getInstanceMethod(type(of: avatar), poseSel) {
            let poseImp = method_getImplementation(poseMethod)
            typealias PoseFunc = @convention(c) (NSObject, Selector, NSObject, Bool, NSObject?) -> Void
            let poseFn = unsafeBitCast(poseImp, to: PoseFunc.self)
            poseFn(avatar, poseSel, trackingInfo, false, nil)
        }
    }
    
    // MARK: - Build TrackingInfo (baseline path)
    
    /// Build AVTFaceTrackingInfo by copying a real ARFrame's data and overwriting only blendshapes.
    /// This preserves the correct orientation/translation/cameraSpace from a real tracking session.
    private func buildTrackingInfoFromBaseline(_ tracking: AvatarFaceTracking) -> NSObject? {
        guard let baseline = baselineTrackingData,
              let trackInfoCls = trackInfoCls,
              let meta = object_getClass(trackInfoCls) else { return nil }
        
        var buffer = [UInt8](baseline)
        
        buffer.withUnsafeMutableBytes { raw in
            let base = raw.baseAddress!
            
            // Update timestamp
            var ts = CACurrentMediaTime()
            memcpy(base, &ts, 8)
            
            // Apply user's head rotation on top of baseline orientation
            if tracking.headRotation != simd_quatf(ix: 0, iy: 0, iz: 0, r: 1) {
                // Read baseline orientation
                var baseOrientation = simd_quatf()
                memcpy(&baseOrientation, base + 24, 16)
                // Compose: baseline * user rotation
                var newOrientation = baseOrientation * tracking.headRotation
                memcpy(base + 24, &newOrientation, 16)
            }
            
            // Zero out blendshapes first, then write preset values
            // blendShapeWeights_smooth (offset 44, 51 floats = 204 bytes)
            // blendShapeWeights_raw (offset 248, 51 floats = 204 bytes)
            memset(base + 44, 0, 204)
            memset(base + 248, 0, 204)
            
            for (name, value) in tracking.blendshapes {
                if let idx = Self.arkitBlendShapeOrder[name], idx < 51 {
                    var val = value
                    memcpy(base + 44 + idx * 4, &val, 4)
                    memcpy(base + 248 + idx * 4, &val, 4)
                }
            }
        }
        
        let sel = NSSelectorFromString("trackingInfoWithTrackingData:")
        guard let method = class_getClassMethod(meta, sel) else { return nil }
        let imp = method_getImplementation(method)
        
        return buffer.withUnsafeBytes { rawBuf -> NSObject? in
            typealias Func = @convention(c) (AnyClass, Selector, UnsafeRawPointer) -> NSObject?
            let fn = unsafeBitCast(imp, to: Func.self)
            return fn(trackInfoCls, sel, rawBuf.baseAddress!)
        }
    }
    
    // MARK: - Build TrackingInfo (manual path)
    
    /// Build AVTFaceTrackingInfo from our AvatarFaceTracking struct.
    /// Layout: 480-byte C struct → trackingInfoWithTrackingData:
    private func buildTrackingInfo(_ tracking: AvatarFaceTracking) -> NSObject? {
        guard let trackInfoCls = trackInfoCls,
              let meta = object_getClass(trackInfoCls) else { return nil }
        
        let bufferSize = 480
        var buffer = [UInt8](repeating: 0, count: bufferSize)
        
        buffer.withUnsafeMutableBytes { raw in
            let base = raw.baseAddress!
            
            // timestamp (offset 0, Double)
            var ts = CACurrentMediaTime()
            memcpy(base, &ts, 8)
            
            // translation (offset 8, simd_float3 = 12 bytes)
            var translation = simd_float3(0, 0, 0)
            memcpy(base + 8, &translation, 12)
            
            // orientation (offset 24, simd_quatf = 16 bytes)
            // AvatarKit's coordinate system has identity = back-of-head.
            // Rotate 180° around Y to face forward, then apply user's rotation on top.
            let faceForward = simd_quatf(angle: .pi, axis: simd_float3(0, 1, 0))
            var orientation = faceForward * tracking.headRotation
            memcpy(base + 24, &orientation, 16)
            
            // cameraSpace = true (offset 40)
            base.storeBytes(of: UInt8(1), toByteOffset: 40, as: UInt8.self)
            
            // blendShapeWeights_smooth (offset 44, 51 floats = 204 bytes)
            // blendShapeWeights_raw (offset 248, 51 floats = 204 bytes)
            for (name, value) in tracking.blendshapes {
                if let idx = Self.arkitBlendShapeOrder[name], idx < 51 {
                    var val = value
                    memcpy(base + 44 + idx * 4, &val, 4)
                    memcpy(base + 248 + idx * 4, &val, 4)
                }
            }
        }
        
        // Convert raw bytes → AVTFaceTrackingInfo
        let sel = NSSelectorFromString("trackingInfoWithTrackingData:")
        guard let method = class_getClassMethod(meta, sel) else { return nil }
        let imp = method_getImplementation(method)
        
        return buffer.withUnsafeBytes { rawBuf -> NSObject? in
            typealias Func = @convention(c) (AnyClass, Selector, UnsafeRawPointer) -> NSObject?
            let fn = unsafeBitCast(imp, to: Func.self)
            return fn(trackInfoCls, sel, rawBuf.baseAddress!)
        }
    }
    
    // MARK: - Helpers
    
    private func setBool(on obj: NSObject, selector: String, value: Bool) {
        let sel = NSSelectorFromString(selector)
        guard obj.responds(to: sel) else { return }
        let method = class_getInstanceMethod(type(of: obj), sel)!
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, Bool) -> Void
        unsafeBitCast(imp, to: Func.self)(obj, sel, value)
    }
    
    // MARK: - Constants
    
    static let availableAnimoji: [String] = [
        "alien", "bear", "boar", "cat", "chicken", "cow",
        "dog", "dragon", "fox", "ghost", "giraffe", "koala",
        "lion", "monkey", "mouse", "octopus", "owl", "panda",
        "pig", "poo", "rabbit", "robot", "shark", "skull",
        "tiger", "trex", "unicorn"
    ]
    
    static let arkitBlendShapeOrder: [String: Int] = {
        let names = [
            "browDownLeft", "browDownRight", "browInnerUp", "browOuterUpLeft", "browOuterUpRight",
            "cheekPuff", "cheekSquintLeft", "cheekSquintRight",
            "eyeBlinkLeft", "eyeBlinkRight", "eyeLookDownLeft", "eyeLookDownRight",
            "eyeLookInLeft", "eyeLookInRight", "eyeLookOutLeft", "eyeLookOutRight",
            "eyeLookUpLeft", "eyeLookUpRight", "eyeSquintLeft", "eyeSquintRight",
            "eyeWideLeft", "eyeWideRight",
            "jawForward", "jawLeft", "jawOpen", "jawRight",
            "mouthClose", "mouthDimpleLeft", "mouthDimpleRight", "mouthFrownLeft", "mouthFrownRight",
            "mouthFunnel", "mouthLeft", "mouthLowerDownLeft", "mouthLowerDownRight",
            "mouthPressLeft", "mouthPressRight", "mouthPucker", "mouthRight",
            "mouthRollLower", "mouthRollUpper", "mouthShrugLower", "mouthShrugUpper",
            "mouthSmileLeft", "mouthSmileRight", "mouthStretchLeft", "mouthStretchRight",
            "mouthUpperUpLeft", "mouthUpperUpRight",
            "noseSneerLeft", "noseSneerRight",
        ]
        var map: [String: Int] = [:]
        for (i, name) in names.enumerated() { map[name] = i }
        return map
    }()
}
