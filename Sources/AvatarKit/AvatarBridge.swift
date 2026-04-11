import Foundation
import UIKit
import ARKit
import simd
import QuartzCore

/// Internal bridge to Apple's private AvatarKit framework.
///
/// All interaction with Apple's ObjC runtime goes through `ObjCRuntime`.
/// Tracking data construction is delegated to `TrackingDataBuilder`.
/// Blendshape order lives in `BlendshapeOrder`.
@MainActor
final class AvatarBridge {
    
    private(set) var avtView: NSObject?
    private var avatar: NSObject?
    private var frameworkLoaded = false
    private var trackInfoCls: AnyClass?
    private var frameCount = 0
    
    /// Cached tracking data from a real ARFrame (neutral forward-facing).
    /// Used as baseline for preset expressions.
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
        self.avtView = view as NSObject
        view.backgroundColor = .clear
        
        let obj = view as NSObject
        ObjCRuntime.setBool(on: obj, "setRendersContinuously:", true)
        ObjCRuntime.setBool(on: obj, "setAutoTrackingEnabled:", false)
        ObjCRuntime.setBool(on: obj, "setFaceTrackingEnabled:", false)
        
        // Pause any internal ARSession to prevent conflict with external tracking
        if let session = ObjCRuntime.callReturning(obj, "arSession") as? ARSession {
            session.pause()
        }
        
        return view
    }
    
    // MARK: - Avatar Loading
    
    private var currentAnimojiName: String?
    
    func resetPose() {
        guard avatar != nil, let name = currentAnimojiName else { return }
        loadAnimoji(name)
    }
    
    func loadAnimoji(_ name: String) {
        guard ensureFramework() else { return }
        guard let animojiCls = NSClassFromString("AVTAnimoji") else { return }
        guard let newAvatar = ObjCRuntime.callClass(animojiCls, "animojiNamed:", name) else { return }
        
        self.avatar = newAvatar
        self.currentAnimojiName = name
        avtView?.setValue(newAvatar, forKeyPath: "avatar")
        applyTracking(.neutral)
    }
    
    // MARK: - Apply Tracking
    
    func applyTracking(_ tracking: AvatarFaceTracking) {
        guard let avatar = avatar else { return }
        frameCount += 1
        
        guard let trackingInfo = makeTrackingInfo(from: tracking) else { return }
        
        // Apply blendshapes
        ObjCRuntime.call(avatar, "applyBlendShapesWithTrackingInfo:", trackingInfo)
        
        // Apply head pose (gazeCorrection=false, pointOfView=nil → world-space)
        typealias PoseFunc = @convention(c) (NSObject, Selector, NSObject, Bool, NSObject?) -> Void
        if let fn = ObjCRuntime.imp(avatar, "applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:", as: PoseFunc.self) {
            fn(avatar, ObjCRuntime.sel("applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:"),
               trackingInfo, false, nil)
        }
    }
    
    /// Apply with VFXTransaction smoothing animation.
    func updatePose(with trackingData: Data, applySmoothing: Bool = true) {
        guard let avatar = avatar else { return }
        typealias Func = @convention(c) (NSObject, Selector, NSData, Bool) -> Void
        if let fn = ObjCRuntime.imp(avatar, "updatePoseWithFaceTrackingData:applySmoothing:", as: Func.self) {
            fn(avatar, ObjCRuntime.sel("updatePoseWithFaceTrackingData:applySmoothing:"),
               trackingData as NSData, applySmoothing)
        }
    }
    
    /// Apply with a pose provider (AVTAvatarPose).
    func updatePose(withProvider provider: NSObject, applySmoothing: Bool = true) {
        guard let avatar = avatar else { return }
        typealias Func = @convention(c) (NSObject, Selector, NSObject, Bool) -> Void
        if let fn = ObjCRuntime.imp(avatar, "updatePoseWithPoseProvider:applySmoothing:", as: Func.self) {
            fn(avatar, ObjCRuntime.sel("updatePoseWithPoseProvider:applySmoothing:"),
               provider, applySmoothing)
        }
    }
    
    // MARK: - Blendshape Access
    
    func weightForBlendShape(named name: String) -> Float? {
        guard let pose = currentPose() else { return nil }
        typealias Func = @convention(c) (NSObject, Selector, NSString) -> Float
        guard let fn = ObjCRuntime.imp(pose, "weightForBlendShapeNamed:", as: Func.self) else { return nil }
        return fn(pose, ObjCRuntime.sel("weightForBlendShapeNamed:"), name as NSString)
    }
    
    func setWeight(_ weight: Float, forBlendShapeNamed name: String) {
        guard let pose = currentPose() else { return }
        typealias Func = @convention(c) (NSObject, Selector, Float, NSString) -> Void
        if let fn = ObjCRuntime.imp(pose, "setWeight:forBlendShapeNamed:", as: Func.self) {
            fn(pose, ObjCRuntime.sel("setWeight:forBlendShapeNamed:"), weight, name as NSString)
        }
    }
    
    private func currentPose() -> NSObject? {
        guard let avatar = avatar else { return nil }
        return ObjCRuntime.callReturning(avatar, "currentPose")
    }
    
    // MARK: - Transitions
    
    func transitionToCustomFaceTracking(
        duration: Double = 0.3,
        style: Int = 1,
        enableBakedAnimations: Bool = false,
        didStart: (() -> Void)? = nil,
        completion: (() -> Void)? = nil
    ) {
        guard let view = avtView else { return }
        let selName = "transitionToCustomFaceTrackingWithDuration:style:enableBakedAnimations:faceTrackingDidStartHandlerReceiverBlock:completionHandler:"
        
        typealias Func = @convention(c) (NSObject, Selector, Double, Int, Bool, AnyObject?, AnyObject?) -> Void
        guard let fn = ObjCRuntime.imp(view, selName, as: Func.self) else { return }
        
        let startBlock: @convention(block) () -> Void = { didStart?() }
        let completionBlock: @convention(block) () -> Void = { completion?() }
        
        fn(view, ObjCRuntime.sel(selName), duration, style, enableBakedAnimations,
           didStart != nil ? unsafeBitCast(startBlock, to: AnyObject.self) : nil,
           completion != nil ? unsafeBitCast(completionBlock, to: AnyObject.self) : nil)
    }
    
    // MARK: - Animation
    
    func addAnimation(
        _ animation: NSObject,
        options: UInt = 0,
        transitionIn: Double = 0.2,
        transitionOut: Double = 0.2,
        isTransient: Bool = true,
        completion: (() -> Void)? = nil
    ) {
        guard let avatar = avatar else { return }
        let selName = "_addAnimationToAvatar:options:transitionInDuration:transitionOutDuration:isTransient:completionQueue:completionHandler:"
        
        typealias Func = @convention(c) (NSObject, Selector, NSObject, UInt, Double, Double, Bool, AnyObject?, AnyObject?) -> NSObject?
        guard let fn = ObjCRuntime.imp(animation, selName, as: Func.self) else { return }
        
        let completionBlock: @convention(block) () -> Void = { completion?() }
        _ = fn(animation, ObjCRuntime.sel(selName), avatar, options, transitionIn, transitionOut, isTransient,
               nil, completion != nil ? unsafeBitCast(completionBlock, to: AnyObject.self) : nil)
    }
    
    func removeAnimation(blendOutDuration: Double = 0.2) {
        guard let avatar = avatar else { return }
        guard let controller = ObjCRuntime.callReturning(avatar, "animationController") else { return }
        
        typealias Func = @convention(c) (NSObject, Selector, Double) -> Void
        if let fn = ObjCRuntime.imp(controller, "removeAnimationWithBlendOutDuration:", as: Func.self) {
            fn(controller, ObjCRuntime.sel("removeAnimationWithBlendOutDuration:"), blendOutDuration)
        }
    }
    
    // MARK: - Pose Construction
    
    func transitionFromPose(
        _ fromPose: NSObject,
        toPose: NSObject,
        duration: Double = 0.3,
        completion: (() -> Void)? = nil
    ) {
        guard let avatar = avatar else { return }
        let selName = "transitionFromPose:toPose:duration:completionHandler:"
        
        typealias Func = @convention(c) (NSObject, Selector, NSObject, NSObject, Double, AnyObject?) -> Void
        guard let fn = ObjCRuntime.imp(avatar, selName, as: Func.self) else { return }
        
        let completionBlock: @convention(block) () -> Void = { completion?() }
        fn(avatar, ObjCRuntime.sel(selName), fromPose, toPose, duration,
           completion != nil ? unsafeBitCast(completionBlock, to: AnyObject.self) : nil)
    }
    
    var bakedAnimationPlayer: NSObject? {
        guard let avatar = avatar else { return nil }
        return ObjCRuntime.callReturning(avatar, "animationController")
    }
    
    var bakedAnimationCopy: NSObject? {
        guard let avatar = avatar else { return nil }
        guard let controller = ObjCRuntime.callReturning(avatar, "animationController") else { return nil }
        guard let animation = ObjCRuntime.callReturning(controller, "animation") else { return nil }
        return ObjCRuntime.callReturning(animation, "copy")
    }
    
    func createPose(
        blendshapes: [String: Float],
        neckPosition: SIMD3<Float>? = nil,
        neckOrientation: simd_quatf? = nil
    ) -> NSObject? {
        guard let poseCls = NSClassFromString("AVTAvatarPose") else { return nil }
        guard let pose = ObjCRuntime.callClass(poseCls, "alloc") else { return nil }
        guard let initialized = ObjCRuntime.callReturning(pose, "init") else { return nil }
        
        // Set blendshape weights
        typealias SetWeightFunc = @convention(c) (NSObject, Selector, Float, NSString) -> Void
        if let fn = ObjCRuntime.imp(initialized, "setWeight:forBlendShapeNamed:", as: SetWeightFunc.self) {
            let sel = ObjCRuntime.sel("setWeight:forBlendShapeNamed:")
            for (name, weight) in blendshapes {
                fn(initialized, sel, weight, name as NSString)
            }
        }
        
        // Set neck position/orientation if provided
        if let pos = neckPosition {
            typealias SetVec3Func = @convention(c) (NSObject, Selector, SIMD3<Float>) -> Void
            if let fn = ObjCRuntime.imp(initialized, "setNeckPosition:", as: SetVec3Func.self) {
                fn(initialized, ObjCRuntime.sel("setNeckPosition:"), pos)
            }
        }
        if let orient = neckOrientation {
            typealias SetQuatFunc = @convention(c) (NSObject, Selector, simd_quatf) -> Void
            if let fn = ObjCRuntime.imp(initialized, "setNeckOrientation:", as: SetQuatFunc.self) {
                fn(initialized, ObjCRuntime.sel("setNeckOrientation:"), orient)
            }
        }
        
        return initialized
    }
    
    // MARK: - Snapshot & Sticker
    
    func snapshot(size: CGSize, scale: Float = 2.0) -> UIImage? {
        guard let view = avtView else { return nil }
        typealias Func = @convention(c) (NSObject, Selector, CGSize, Float, NSObject?) -> UIImage?
        guard let fn = ObjCRuntime.imp(view, "snapshotWithSize:scaleFactor:options:", as: Func.self) else { return nil }
        return fn(view, ObjCRuntime.sel("snapshotWithSize:scaleFactor:options:"), size, scale, nil)
    }
    
    func generateSticker(
        configuration: NSObject,
        completion: @escaping (UIImage?) -> Void
    ) {
        guard let avatar = avatar,
              let genCls = NSClassFromString("AVTStickerGenerator") else {
            completion(nil)
            return
        }
        
        guard let rawGen = ObjCRuntime.callClass(genCls, "alloc"),
              let generator = ObjCRuntime.callReturning(rawGen, "initWithAvatar:", avatar) else {
            completion(nil)
            return
        }
        
        let block: @convention(block) (UIImage?) -> Void = { image in completion(image) }
        
        typealias Func = @convention(c) (NSObject, Selector, NSObject, AnyObject) -> Void
        if let fn = ObjCRuntime.imp(generator, "stickerImageWithConfiguration:completionHandler:", as: Func.self) {
            fn(generator, ObjCRuntime.sel("stickerImageWithConfiguration:completionHandler:"),
               configuration, unsafeBitCast(block, to: AnyObject.self))
        } else {
            completion(nil)
        }
    }
    
    func snapshotView(backgroundColor: UIColor) -> UIView? {
        guard let view = avtView else { return nil }
        return ObjCRuntime.callReturning(view, "snapshotViewUsingBackgroundColor:", backgroundColor) as? UIView
    }
    
    // MARK: - Physics
    
    func setupPhysics() {
        guard let avatar = avatar else { return }
        ObjCRuntime.call(avatar, "setupPhysicsIfNeeded")
    }
    
    // MARK: - ARFrame Pipeline
    
    /// Apply an ARFrame directly using Apple's own dataWithARFrame pipeline.
    /// Most reliable path — Apple handles all orientation mapping internally.
    func applyARFrame(_ frame: ARFrame) {
        guard let avatar = avatar, let trackInfoCls = trackInfoCls else { return }
        guard frame.anchors.contains(where: { $0 is ARFaceAnchor }) else { return }
        
        frameCount += 1
        
        // ARFrame → raw NSData
        typealias DataFunc = @convention(c) (AnyClass, Selector, AnyObject, Int, Int) -> NSObject?
        guard let dataFn = ObjCRuntime.classImp(trackInfoCls, "dataWithARFrame:captureOrientation:interfaceOrientation:", as: DataFunc.self) else { return }
        guard let data = dataFn(trackInfoCls, ObjCRuntime.sel("dataWithARFrame:captureOrientation:interfaceOrientation:"), frame, 4, 1) else { return }
        guard let nsData = data as? Data else { return }
        
        // Cache first frame as baseline
        if baselineTrackingData == nil {
            baselineTrackingData = nsData
            let t = TrackingDataBuilder.readTranslation(from: nsData)
            let q = TrackingDataBuilder.readOrientation(from: nsData)
            print("[AvatarKit] ✅ Baseline captured (\(nsData.count) bytes) translation=(\(t.x), \(t.y), \(t.z)) orientation=(\(q.vector.x), \(q.vector.y), \(q.vector.z), \(q.vector.w))")
        }
        
        // NSData → AVTFaceTrackingInfo → apply
        guard let trackingInfo = makeTrackingInfoFromData(nsData) else { return }
        
        ObjCRuntime.call(avatar, "applyBlendShapesWithTrackingInfo:", trackingInfo)
        
        typealias PoseFunc = @convention(c) (NSObject, Selector, NSObject, Bool, NSObject?) -> Void
        if let fn = ObjCRuntime.imp(avatar, "applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:", as: PoseFunc.self) {
            fn(avatar, ObjCRuntime.sel("applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:"),
               trackingInfo, false, nil)
        }
    }
    
    // MARK: - TrackingInfo Construction
    
    /// Build AVTFaceTrackingInfo from our AvatarFaceTracking struct.
    /// Uses baseline path if available, otherwise manual construction.
    private func makeTrackingInfo(from tracking: AvatarFaceTracking) -> NSObject? {
        let buffer: [UInt8]
        if let baseline = baselineTrackingData {
            buffer = TrackingDataBuilder.buildFromBaseline(baseline, tracking: tracking)
        } else {
            buffer = TrackingDataBuilder.build(from: tracking)
        }
        return trackingInfoFromBuffer(buffer)
    }
    
    /// Convert raw NSData to AVTFaceTrackingInfo.
    private func makeTrackingInfoFromData(_ data: Data) -> NSObject? {
        guard let trackInfoCls = trackInfoCls else { return nil }
        typealias Func = @convention(c) (AnyClass, Selector, UnsafeRawPointer) -> NSObject?
        guard let fn = ObjCRuntime.classImp(trackInfoCls, "trackingInfoWithTrackingData:", as: Func.self) else { return nil }
        return data.withUnsafeBytes { raw -> NSObject? in
            fn(trackInfoCls, ObjCRuntime.sel("trackingInfoWithTrackingData:"), raw.baseAddress!)
        }
    }
    
    /// Convert a byte buffer to AVTFaceTrackingInfo via trackingInfoWithTrackingData:.
    private func trackingInfoFromBuffer(_ buffer: [UInt8]) -> NSObject? {
        guard let trackInfoCls = trackInfoCls else { return nil }
        typealias Func = @convention(c) (AnyClass, Selector, UnsafeRawPointer) -> NSObject?
        guard let fn = ObjCRuntime.classImp(trackInfoCls, "trackingInfoWithTrackingData:", as: Func.self) else { return nil }
        return buffer.withUnsafeBytes { raw -> NSObject? in
            fn(trackInfoCls, ObjCRuntime.sel("trackingInfoWithTrackingData:"), raw.baseAddress!)
        }
    }
    
    // MARK: - Constants
    
    nonisolated static let availableAnimoji: [String] = [
        "alien", "bear", "boar", "cat", "chicken", "cow", "default",
        "dog", "dragon", "fox", "ghost", "giraffe", "koala",
        "lion", "monkey", "mouse", "octopus", "owl", "panda",
        "pig", "poo", "rabbit", "robot", "shark", "skull",
        "tiger", "trex", "unicorn"
    ]
}
