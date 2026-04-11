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
    
    /// Reset head pose to default forward-facing by reloading the current animoji.
    func resetPose() {
        guard let avatar = avatar, let name = currentAnimojiName else { return }
        loadAnimoji(name)
    }
    
    private var currentAnimojiName: String?
    
    func loadAnimoji(_ name: String) {
        guard ensureFramework() else { return }
        guard let animojiCls = NSClassFromString("AVTAnimoji") else { return }
        
        let sel = NSSelectorFromString("animojiNamed:")
        guard animojiCls.responds(to: sel) else { return }
        guard let result = (animojiCls as AnyObject).perform(sel, with: name) else { return }
        let newAvatar = result.takeUnretainedValue() as! NSObject
        
        self.avatar = newAvatar
        self.currentAnimojiName = name
        avtView?.setValue(newAvatar, forKeyPath: "avatar")
        
        // Default to front-facing neutral pose — AVTRecordView's default is back-of-head
        applyTracking(.neutral)
    }
    
    // MARK: - Apply Tracking Data
    
    /// Apply face tracking data from any source.
    /// Applies blendshapes via applyBlendShapesWithTrackingInfo: (same as Apple's pipeline).
    /// Applies head pose via applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:
    /// with gazeCorrection=false and pointOfView=nil (world-space orientation).
    func applyTracking(_ tracking: AvatarFaceTracking) {
        guard let avatar = avatar, let trackInfoCls = trackInfoCls else { return }
        
        frameCount += 1
        
        guard let trackingInfo = buildTrackingInfo(tracking) else { return }
        
        // Apply blendshapes — matches Apple's applyBlendShapesWithTrackingInfo:
        // which calls trackingData → _applyBlendShapesWithTrackingData:
        // which reads blendshapes at offset 52 in ARIndex order
        let bsSel = NSSelectorFromString("applyBlendShapesWithTrackingInfo:")
        if avatar.responds(to: bsSel) {
            avatar.perform(bsSel, with: trackingInfo)
        }
        
        // Apply head pose — matches Apple's applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:
        // which reads quaternion at offset 32, translation at offset 16, flag at offset 48
        // gazeCorrection=false, pointOfView=nil → uses quaternion directly (world space)
        let poseSel = NSSelectorFromString("applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:")
        if avatar.responds(to: poseSel),
           let poseMethod = class_getInstanceMethod(type(of: avatar), poseSel) {
            let poseImp = method_getImplementation(poseMethod)
            typealias PoseFunc = @convention(c) (NSObject, Selector, NSObject, Bool, NSObject?) -> Void
            let poseFn = unsafeBitCast(poseImp, to: PoseFunc.self)
            poseFn(avatar, poseSel, trackingInfo, false, nil)
        }
    }
    
    /// Apply tracking data with VFXTransaction smoothing animation.
    /// Matches Apple's updatePoseWithFaceTrackingData:applySmoothing:
    /// When applySmoothing=true, wraps apply calls in a VFXTransaction with easeOut timing.
    func updatePose(with trackingData: Data, applySmoothing: Bool = true) {
        guard let avatar = avatar else { return }
        
        let sel = NSSelectorFromString("updatePoseWithFaceTrackingData:applySmoothing:")
        guard avatar.responds(to: sel),
              let method = class_getInstanceMethod(type(of: avatar), sel) else { return }
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, NSData, Bool) -> Void
        let fn = unsafeBitCast(imp, to: Func.self)
        fn(avatar, sel, trackingData as NSData, applySmoothing)
    }
    
    /// Apply tracking with a pose provider (AVTAvatarPose).
    /// Matches Apple's updatePoseWithPoseProvider:applySmoothing:
    /// The pose provider supplies blendshape weights + neck position/orientation.
    func updatePose(withProvider provider: NSObject, applySmoothing: Bool = true) {
        guard let avatar = avatar else { return }
        
        let sel = NSSelectorFromString("updatePoseWithPoseProvider:applySmoothing:")
        guard avatar.responds(to: sel),
              let method = class_getInstanceMethod(type(of: avatar), sel) else { return }
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, NSObject, Bool) -> Void
        let fn = unsafeBitCast(imp, to: Func.self)
        fn(avatar, sel, provider, applySmoothing)
    }
    
    /// Read a single blendshape weight by name.
    /// Matches Apple's AVTAvatarPose.weightForBlendShapeNamed:
    /// Returns the current weight from the avatar's internal pose dictionary.
    func weightForBlendShape(named name: String) -> Float? {
        guard let avatar = avatar else { return nil }
        
        // Get the avatar's current pose
        let poseSel = NSSelectorFromString("currentPose")
        guard avatar.responds(to: poseSel),
              let poseResult = avatar.perform(poseSel),
              let pose = poseResult.takeUnretainedValue() as? NSObject else { return nil }
        
        let sel = NSSelectorFromString("weightForBlendShapeNamed:")
        guard pose.responds(to: sel),
              let method = class_getInstanceMethod(type(of: pose), sel) else { return nil }
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, NSString) -> Float
        let fn = unsafeBitCast(imp, to: Func.self)
        return fn(pose, sel, name as NSString)
    }
    
    /// Set a single blendshape weight by name.
    /// Matches Apple's AVTAvatarPose.setWeight:forBlendShapeNamed:
    /// Setting weight to 0 removes the key from the internal dictionary.
    func setWeight(_ weight: Float, forBlendShapeNamed name: String) {
        guard let avatar = avatar else { return }
        
        let poseSel = NSSelectorFromString("currentPose")
        guard avatar.responds(to: poseSel),
              let poseResult = avatar.perform(poseSel),
              let pose = poseResult.takeUnretainedValue() as? NSObject else { return }
        
        let sel = NSSelectorFromString("setWeight:forBlendShapeNamed:")
        guard pose.responds(to: sel),
              let method = class_getInstanceMethod(type(of: pose), sel) else { return }
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, Float, NSString) -> Void
        let fn = unsafeBitCast(imp, to: Func.self)
        fn(pose, sel, weight, name as NSString)
    }
    
    /// Transition to custom face tracking mode with animation.
    /// Matches Apple's transitionToCustomFaceTrackingWithDuration:style:enableBakedAnimations:
    ///   faceTrackingDidStartHandlerReceiverBlock:completionHandler:
    /// style: 1-5 (different transition animations)
    /// enableBakedAnimations: whether to enable idle animations during custom tracking
    func transitionToCustomFaceTracking(
        duration: Double = 0.3,
        style: Int = 1,
        enableBakedAnimations: Bool = false,
        didStart: (() -> Void)? = nil,
        completion: (() -> Void)? = nil
    ) {
        guard let view = avtView else { return }
        
        let sel = NSSelectorFromString("transitionToCustomFaceTrackingWithDuration:style:enableBakedAnimations:faceTrackingDidStartHandlerReceiverBlock:completionHandler:")
        guard view.responds(to: sel),
              let method = class_getInstanceMethod(type(of: view), sel) else { return }
        let imp = method_getImplementation(method)
        
        // Wrap Swift closures as ObjC blocks
        let startBlock: @convention(block) () -> Void = { didStart?() }
        let completionBlock: @convention(block) () -> Void = { completion?() }
        
        typealias Func = @convention(c) (NSObject, Selector, Double, Int, Bool, AnyObject?, AnyObject?) -> Void
        let fn = unsafeBitCast(imp, to: Func.self)
        fn(view, sel, duration, style, enableBakedAnimations,
           didStart != nil ? unsafeBitCast(startBlock, to: AnyObject.self) : nil,
           completion != nil ? unsafeBitCast(completionBlock, to: AnyObject.self) : nil)
    }
    
    // MARK: - Animation Playback
    
    /// Add a pose animation to the avatar with transition.
    /// Matches Apple's AVTAvatarPoseAnimation._addAnimationToAvatar:options:
    ///   transitionInDuration:transitionOutDuration:isTransient:completionQueue:completionHandler:
    /// This is how Animoji stickers play their baked animations (wink, heart eyes, etc.)
    /// - Parameters:
    ///   - animation: AVTAvatarPoseAnimation object (loaded from .scn or dictionary)
    ///   - options: Animation options (0 = default)
    ///   - transitionIn: Blend-in duration in seconds
    ///   - transitionOut: Blend-out duration in seconds
    ///   - isTransient: If true, animation auto-removes after playing once
    ///   - completion: Called when animation finishes
    func addAnimation(
        _ animation: NSObject,
        options: UInt = 0,
        transitionIn: Double = 0.2,
        transitionOut: Double = 0.2,
        isTransient: Bool = true,
        completion: (() -> Void)? = nil
    ) {
        guard let avatar = avatar else { return }
        
        let sel = NSSelectorFromString("_addAnimationToAvatar:options:transitionInDuration:transitionOutDuration:isTransient:completionQueue:completionHandler:")
        guard animation.responds(to: sel),
              let method = class_getInstanceMethod(type(of: animation), sel) else { return }
        let imp = method_getImplementation(method)
        
        let completionBlock: @convention(block) () -> Void = { completion?() }
        
        typealias Func = @convention(c) (NSObject, Selector, NSObject, UInt, Double, Double, Bool, AnyObject?, AnyObject?) -> NSObject?
        let fn = unsafeBitCast(imp, to: Func.self)
        _ = fn(animation, sel, avatar, options, transitionIn, transitionOut, isTransient,
               nil, // completionQueue — nil = main queue
               completion != nil ? unsafeBitCast(completionBlock, to: AnyObject.self) : nil)
    }
    
    /// Remove the current animation with a blend-out duration.
    /// Matches Apple's AVTAvatarPoseAnimationController.removeAnimationWithBlendOutDuration:
    func removeAnimation(blendOutDuration: Double = 0.2) {
        guard let avatar = avatar else { return }
        
        // Get the animation controller from the avatar
        let ctrlSel = NSSelectorFromString("animationController")
        guard avatar.responds(to: ctrlSel),
              let ctrlResult = avatar.perform(ctrlSel),
              let controller = ctrlResult.takeUnretainedValue() as? NSObject else { return }
        
        let sel = NSSelectorFromString("removeAnimationWithBlendOutDuration:")
        guard controller.responds(to: sel),
              let method = class_getInstanceMethod(type(of: controller), sel) else { return }
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, Double) -> Void
        let fn = unsafeBitCast(imp, to: Func.self)
        fn(controller, sel, blendOutDuration)
    }
    
    /// Transition between two poses with animation.
    /// Matches Apple's _transitionFromPose:toPose:bakedAnimationBlendFactor:
    ///   duration:delay:timingFunction:timingAnimation:completionHandler:
    /// Used for smooth transitions between expressions (e.g. neutral → smile).
    func transitionFromPose(
        _ fromPose: NSObject,
        toPose: NSObject,
        bakedAnimationBlendFactor: Double = 0.0,
        duration: Double = 0.3,
        delay: Double = 0.0,
        completion: (() -> Void)? = nil
    ) {
        guard let avatar = avatar else { return }
        
        let sel = NSSelectorFromString("_transitionFromPose:toPose:bakedAnimationBlendFactor:duration:delay:timingFunction:timingAnimation:completionHandler:")
        guard avatar.responds(to: sel),
              let method = class_getInstanceMethod(type(of: avatar), sel) else { return }
        let imp = method_getImplementation(method)
        
        let completionBlock: @convention(block) () -> Void = { completion?() }
        
        typealias Func = @convention(c) (NSObject, Selector, NSObject, NSObject, Double, Double, Double, NSObject?, NSObject?, AnyObject?) -> Void
        let fn = unsafeBitCast(imp, to: Func.self)
        fn(avatar, sel, fromPose, toPose, bakedAnimationBlendFactor, duration, delay,
           nil, nil, // timingFunction, timingAnimation — nil = default easeOut
           completion != nil ? unsafeBitCast(completionBlock, to: AnyObject.self) : nil)
    }
    
    /// Get the avatar's baked animation player (SCNAnimationPlayer).
    /// Baked animations are the idle/breathing animations built into each Animoji.
    var bakedAnimationPlayer: NSObject? {
        guard let avatar = avatar else { return nil }
        let sel = NSSelectorFromString("bakedAnimationPlayer")
        guard avatar.responds(to: sel),
              let result = avatar.perform(sel) else { return nil }
        return result.takeUnretainedValue() as? NSObject
    }
    
    /// Get a copy of the baked animation (SCNAnimation).
    var bakedAnimationCopy: NSObject? {
        guard let avatar = avatar else { return nil }
        let sel = NSSelectorFromString("bakedAnimationCopy")
        guard avatar.responds(to: sel),
              let result = avatar.perform(sel) else { return nil }
        return result.takeUnretainedValue() as? NSObject
    }
    
    // MARK: - Pose Construction
    
    /// Create an AVTAvatarPose from blendshape weights and neck transform.
    /// Matches Apple's initWithWeights:neckPosition:neckOrientation:bakedAnimationBlendFactor:
    /// This is the data object used by transitionFromPose/toPose and updatePoseWithPoseProvider.
    func createPose(
        weights: [String: Float],
        neckPosition: simd_float3 = .zero,
        neckOrientation: simd_quatf = simd_quatf(ix: 0, iy: 0, iz: 0, r: 1),
        bakedAnimationBlendFactor: Double = 0.0
    ) -> NSObject? {
        guard let poseCls = NSClassFromString("AVTAvatarPose") else { return nil }
        
        // Convert weights dict to NSDictionary<NSString, NSNumber>
        let nsWeights = NSMutableDictionary(capacity: weights.count)
        for (key, value) in weights {
            nsWeights[key as NSString] = NSNumber(value: value)
        }
        
        let sel = NSSelectorFromString("initWithWeights:neckPosition:neckOrientation:bakedAnimationBlendFactor:")
        let allocSel = NSSelectorFromString("alloc")
        guard let rawObj = (poseCls as AnyObject).perform(allocSel)?.takeUnretainedValue() as? NSObject,
              rawObj.responds(to: sel),
              let method = class_getInstanceMethod(type(of: rawObj), sel) else { return nil }
        let imp = method_getImplementation(method)
        
        typealias Func = @convention(c) (NSObject, Selector, NSDictionary, simd_float3, simd_quatf, Double) -> NSObject?
        let fn = unsafeBitCast(imp, to: Func.self)
        return fn(rawObj, sel, nsWeights, neckPosition, neckOrientation, bakedAnimationBlendFactor)
    }
    
    // MARK: - Snapshot & Sticker
    
    /// Take a snapshot of the current avatar view.
    /// Matches Apple's AVTView.snapshotWithSize:scaleFactor:options:
    func snapshot(size: CGSize, scale: Float = 2.0) -> UIImage? {
        guard let view = avtView else { return nil }
        
        let sel = NSSelectorFromString("snapshotWithSize:scaleFactor:options:")
        guard view.responds(to: sel),
              let method = class_getInstanceMethod(type(of: view), sel) else { return nil }
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, CGSize, Float, NSObject?) -> UIImage?
        let fn = unsafeBitCast(imp, to: Func.self)
        return fn(view, sel, size, scale, nil)
    }
    
    /// Generate a sticker image with a given configuration.
    /// Matches Apple's AVTStickerGenerator.stickerImageWithConfiguration:completionHandler:
    /// Used for generating Animoji sticker images (the static emoji-like images).
    func generateSticker(
        configuration: NSObject,
        completion: @escaping (UIImage?) -> Void
    ) {
        guard let avatar = avatar,
              let genCls = NSClassFromString("AVTStickerGenerator") else {
            completion(nil)
            return
        }
        
        // Create generator: [[AVTStickerGenerator alloc] initWithAvatar:]
        let allocSel = NSSelectorFromString("alloc")
        guard let rawGen = (genCls as AnyObject).perform(allocSel)?.takeUnretainedValue() as? NSObject else {
            completion(nil)
            return
        }
        let initSel = NSSelectorFromString("initWithAvatar:")
        guard rawGen.responds(to: initSel),
              let genResult = rawGen.perform(initSel, with: avatar),
              let generator = genResult.takeUnretainedValue() as? NSObject else {
            completion(nil)
            return
        }
        
        let sel = NSSelectorFromString("stickerImageWithConfiguration:completionHandler:")
        guard generator.responds(to: sel),
              let method = class_getInstanceMethod(type(of: generator), sel) else {
            completion(nil)
            return
        }
        let imp = method_getImplementation(method)
        
        let block: @convention(block) (UIImage?) -> Void = { image in
            completion(image)
        }
        
        typealias Func = @convention(c) (NSObject, Selector, NSObject, AnyObject) -> Void
        let fn = unsafeBitCast(imp, to: Func.self)
        fn(generator, sel, configuration, unsafeBitCast(block, to: AnyObject.self))
    }
    
    /// Take a snapshot view (UIView) with a background color.
    /// Matches Apple's AVTView.snapshotViewUsingBackgroundColor:
    func snapshotView(backgroundColor: UIColor) -> UIView? {
        guard let view = avtView else { return nil }
        
        let sel = NSSelectorFromString("snapshotViewUsingBackgroundColor:")
        guard view.responds(to: sel),
              let result = view.perform(sel, with: backgroundColor) else { return nil }
        return result.takeUnretainedValue() as? UIView
    }
    
    // MARK: - Physics
    
    /// Setup physics simulation on the avatar (hair, accessories dynamics).
    /// Matches Apple's AVTAvatar.setupPhysics
    /// Called automatically by AvatarKit when needed, but can be triggered manually.
    func setupPhysics() {
        guard let avatar = avatar else { return }
        let sel = NSSelectorFromString("setupPhysicsIfNeeded")
        if avatar.responds(to: sel) {
            avatar.perform(sel)
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
            nsData.withUnsafeBytes { raw in
                let base = raw.baseAddress!
                let qx = (base + StructLayout.orientation).load(as: Float.self)
                let qy = (base + StructLayout.orientation + 4).load(as: Float.self)
                let qz = (base + StructLayout.orientation + 8).load(as: Float.self)
                let qw = (base + StructLayout.orientation + 12).load(as: Float.self)
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
            memcpy(base + StructLayout.timestamp, &ts, 8)
            
            // Apply user's head rotation on top of baseline orientation
            if tracking.headRotation != simd_quatf(ix: 0, iy: 0, iz: 0, r: 1) {
                var baseOrientation = simd_quatf()
                memcpy(&baseOrientation, base + StructLayout.orientation, 16)
                var newOrientation = baseOrientation * tracking.headRotation
                memcpy(base + StructLayout.orientation, &newOrientation, 16)
            }
            
            // Zero out blendshapes, then write preset values (ARIndex order)
            memset(base + StructLayout.smoothBlendshapes, 0, StructLayout.blendshapeCount * 4)
            memset(base + StructLayout.rawBlendshapes, 0, StructLayout.blendshapeCount * 4)
            
            for (name, value) in tracking.blendshapes {
                guard let idx = Self.arkitBlendShapeOrder[name], idx < StructLayout.blendshapeCount else { continue }
                var val = value
                memcpy(base + StructLayout.smoothBlendshapes + idx * 4, &val, 4)
                memcpy(base + StructLayout.rawBlendshapes + idx * 4, &val, 4)
            }
            
            // TongueOut via parameters
            if let tongueOut = tracking.blendshapes["tongueOut"], tongueOut > 0 {
                var val = tongueOut
                memcpy(base + StructLayout.smoothParams, &val, 4)
                memcpy(base + StructLayout.rawParams, &val, 4)
            } else {
                // Zero out parameters
                memset(base + StructLayout.smoothParams, 0, 4)
                memset(base + StructLayout.rawParams, 0, 4)
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
    /// Layout matches Apple's internal AVTFaceTrackingData (480 bytes).
    /// Offsets confirmed by Ghidra reverse engineering of AvatarKit.framework.
    private func buildTrackingInfo(_ tracking: AvatarFaceTracking) -> NSObject? {
        guard let trackInfoCls = trackInfoCls,
              let meta = object_getClass(trackInfoCls) else { return nil }
        
        var buffer = [UInt8](repeating: 0, count: StructLayout.size)
        
        buffer.withUnsafeMutableBytes { raw in
            let base = raw.baseAddress!
            
            // Timestamp (offset 0, Double)
            var ts = CACurrentMediaTime()
            memcpy(base + StructLayout.timestamp, &ts, 8)
            
            // Translation (offset 8, simd_float3 = 12 bytes)
            var translation = simd_float3(0, 0, 0)
            memcpy(base + StructLayout.translation, &translation, 12)
            
            // Orientation quaternion (offset 32, simd_quatf = 16 bytes)
            var orientation = tracking.headRotation
            memcpy(base + StructLayout.orientation, &orientation, 16)
            
            // Tracking valid flag (offset 48, UInt8)
            base.storeBytes(of: UInt8(1), toByteOffset: StructLayout.trackingFlag, as: UInt8.self)
            
            // Blendshapes: smooth (offset 52) and raw (offset 264), both in ARIndex order
            for (name, value) in tracking.blendshapes {
                guard let idx = Self.arkitBlendShapeOrder[name], idx < StructLayout.blendshapeCount else { continue }
                var val = value
                memcpy(base + StructLayout.smoothBlendshapes + idx * 4, &val, 4)
                memcpy(base + StructLayout.rawBlendshapes + idx * 4, &val, 4)
            }
            
            // TongueOut via parameters (offset 460/464)
            if let tongueOut = tracking.blendshapes["tongueOut"], tongueOut > 0 {
                var val = tongueOut
                memcpy(base + StructLayout.smoothParams, &val, 4)
                memcpy(base + StructLayout.rawParams, &val, 4)
            }
        }
        
        // Convert raw bytes → AVTFaceTrackingInfo via trackingInfoWithTrackingData:
        // This does: alloc AVTFaceTrackingInfo, memcpy(obj+0x10, data, 0x1e0)
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
    
    // MARK: - Struct Layout (from Ghidra reverse engineering of AvatarKit.framework)
    //
    // AVTFaceTrackingData: 480 bytes total
    //
    // Offset  Size  Description
    // ------  ----  -----------
    // 0       8     timestamp (Double)
    // 8       12    translation (simd_float3)
    // 20      12    unknown
    // 32      16    orientation (simd_quatf x,y,z,w)
    // 48      1     tracking valid flag (UInt8, 1=valid)
    // 49      3     padding
    // 52      204   smooth blendshapes (51 floats, ARIndex order)
    // 256     8     metadata
    // 264     204   raw blendshapes (51 floats, same order)
    // 460     4     params_smooth (tongueOut)
    // 464     4     params_raw (tongueOut)
    // 468     12    padding
    
    /// Struct offsets confirmed by Ghidra disassembly of _applyBlendShapesWithTrackingData:
    ///   add x2, x2, #0x34  → blendshapes at offset 52
    ///   add x3, x8, #0x1cc → parameters at offset 460
    private enum StructLayout {
        static let size = 480
        static let timestamp = 0          // Double (8 bytes)
        static let translation = 8        // simd_float3 (12 bytes)
        static let orientation = 32       // simd_quatf (16 bytes)
        static let trackingFlag = 48      // UInt8 (1 byte)
        static let smoothBlendshapes = 52 // 51 × Float (204 bytes)
        static let rawBlendshapes = 264   // 51 × Float (204 bytes)
        static let smoothParams = 460     // Float (4 bytes) — tongueOut
        static let rawParams = 464        // Float (4 bytes) — tongueOut
        static let blendshapeCount = 51
    }
    
    /// Blendshape index order matching _kAVTBlendShapeLocationFromARIndex.
    /// Confirmed by Ghidra static analysis of _initialiseBlendshapeMappingIfNeeded_block_invoke.
    /// This is the order used by _applyBlendShapes:parameters: to map array indices to morph targets.
    /// NOT alphabetical — it's Apple's internal ARKit index order.
    static let arkitBlendShapeOrder: [String: Int] = {
        let names = [
            // [0-7] Eyes: blink, squint, lookDown, lookIn
            "eyeBlinkLeft", "eyeBlinkRight",
            "eyeSquintLeft", "eyeSquintRight",
            "eyeLookDownLeft", "eyeLookDownRight",
            "eyeLookInLeft", "eyeLookInRight",
            // [8-13] Eyes: wide, lookOut, lookUp
            "eyeWideLeft", "eyeWideRight",
            "eyeLookOutLeft", "eyeLookOutRight",
            "eyeLookUpLeft", "eyeLookUpRight",
            // [14-18] Brows
            "browDownLeft", "browDownRight",
            "browInnerUp",
            "browOuterUpLeft", "browOuterUpRight",
            // [19-23] Jaw
            "jawOpen", "mouthClose",
            "jawLeft", "jawRight", "jawForward",
            // [24-29] Mouth upper/lower/roll
            "mouthUpperUpLeft", "mouthUpperUpRight",
            "mouthLowerDownLeft", "mouthLowerDownRight",
            "mouthRollUpper", "mouthRollLower",
            // [30-35] Mouth expressions 1
            "mouthSmileLeft", "mouthSmileRight",
            "mouthDimpleLeft", "mouthDimpleRight",
            "mouthStretchLeft", "mouthStretchRight",
            // [36-41] Mouth expressions 2
            "mouthFrownLeft", "mouthFrownRight",
            "mouthPressLeft", "mouthPressRight",
            "mouthPucker", "mouthFunnel",
            // [42-45] Mouth misc
            "mouthLeft", "mouthRight",
            "mouthShrugLower", "mouthShrugUpper",
            // [46-50] Nose & cheeks
            "noseSneerLeft", "noseSneerRight",
            "cheekPuff",
            "cheekSquintLeft", "cheekSquintRight",
        ]
        var map: [String: Int] = [:]
        for (i, name) in names.enumerated() { map[name] = i }
        return map
    }()
}
