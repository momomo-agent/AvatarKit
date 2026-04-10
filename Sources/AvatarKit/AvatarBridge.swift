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
    }
    
    // MARK: - Apply Tracking Data
    
    /// Apply face tracking data from any source.
    func applyTracking(_ tracking: AvatarFaceTracking) {
        guard let avatar = avatar, let trackInfoCls = trackInfoCls else { return }
        guard tracking.isTracking else { return }
        
        frameCount += 1
        
        // Build the raw tracking data struct that AvatarKit expects
        guard let trackingInfo = buildTrackingInfo(tracking) else { return }
        
        // Apply blendshapes
        let bsSel = NSSelectorFromString("applyBlendShapesWithTrackingInfo:")
        if avatar.responds(to: bsSel) {
            avatar.perform(bsSel, with: trackingInfo)
        }
        
        // Apply head pose
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
        // captureOrientation: 4 = landscapeRight (front camera sensor)
        // interfaceOrientation: 1 = portrait (UI)
        guard let data = dataFn(trackInfoCls, dataSel, frame, 4, 1) else { return }
        
        // Step 2: NSData → AVTFaceTrackingInfo via trackingInfoWithTrackingData:
        let infoSel = NSSelectorFromString("trackingInfoWithTrackingData:")
        guard let infoMethod = class_getClassMethod(meta, infoSel),
              let nsData = data as? Data else { return }
        let infoImp = method_getImplementation(infoMethod)
        
        guard let trackingInfo = nsData.withUnsafeBytes({ rawBuf -> NSObject? in
            typealias InfoFunc = @convention(c) (AnyClass, Selector, UnsafeRawPointer) -> NSObject?
            let infoFn = unsafeBitCast(infoImp, to: InfoFunc.self)
            return infoFn(trackInfoCls, infoSel, rawBuf.baseAddress!)
        }) else { return }
        
        // Apply blendshapes
        let bsSel = NSSelectorFromString("applyBlendShapesWithTrackingInfo:")
        if avatar.responds(to: bsSel) {
            avatar.perform(bsSel, with: trackingInfo)
        }
        
        // Apply head pose
        let poseSel = NSSelectorFromString("applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:")
        if avatar.responds(to: poseSel),
           let poseMethod = class_getInstanceMethod(type(of: avatar), poseSel) {
            let poseImp = method_getImplementation(poseMethod)
            typealias PoseFunc = @convention(c) (NSObject, Selector, NSObject, Bool, NSObject?) -> Void
            let poseFn = unsafeBitCast(poseImp, to: PoseFunc.self)
            poseFn(avatar, poseSel, trackingInfo, false, nil)
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
            var orientation = tracking.headRotation
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
