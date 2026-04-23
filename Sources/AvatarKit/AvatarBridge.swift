import Foundation
import simd
import UIKit
import ObjectiveC
import SceneKit
import ARKit
import os.log

private let brLog = OSLog(subsystem: "com.momomo.avatarkit", category: "bridge")

// MARK: - Avatar Bridge

/// Bridge to Apple's private AvatarKit framework via ObjC runtime.
///
/// Loads animoji characters, applies face tracking data, and provides
/// the AVTView for rendering (VFX-based on iOS 18+).
///
/// Thread safety: all methods must be called from the main thread.
public final class AvatarBridge {
    
    /// The loaded animoji instance (AVTAnimoji).
    private var animoji: AnyObject?
    
    /// The AVTView instance for rendering.
    public private(set) var avtView: UIView?
    
    /// AVTView's scene camera (pointOfView). Used as pov in camera-space tracking.
    /// Different from animoji's cameraNode — this is the scene camera that _applyHeadPose
    /// multiplies against to transform world-space quaternions into scene-relative space.
    public var scenePointOfView: AnyObject? {
        guard let view = avtView else { return nil }
        let sel = NSSelectorFromString("pointOfView")
        guard (view as AnyObject).responds(to: sel) else { return nil }
        return (view as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    /// The character ID currently loaded.
    public private(set) var characterID: String?
    
    /// Whether AvatarKit framework is available.
    public static var isAvailable: Bool {
        loadFrameworks()
        return NSClassFromString("AVTAnimoji") != nil
    }
    
    /// Available animoji character names.
    public static var availableAnimoji: [String] {
        loadFrameworks()
        guard let cls = NSClassFromString("AVTAnimoji") else { return [] }
        let sel = NSSelectorFromString("puppetNames")
        guard let result = (cls as AnyObject).perform(sel)?.takeUnretainedValue() as? [String] else { return [] }
        return result
    }
    
    @discardableResult
    private static func loadFrameworks() -> Bool {
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY)
        dlopen("/System/Library/PrivateFrameworks/AvatarUI.framework/AvatarUI", RTLD_LAZY)
        return NSClassFromString("AVTAnimoji") != nil
    }
    
    public init() {
        Self.loadFrameworks()
        createAVTView()
    }
    
    // MARK: - AVTView Setup
    
    private func createAVTView() {
        guard let avtViewCls = NSClassFromString("AVTView") as? UIView.Type else { return }
        
        let view = avtViewCls.init(frame: CGRect(x: 0, y: 0, width: 400, height: 400))
        
        // Disable face tracking — we drive expressions manually
        let sel = NSSelectorFromString("setEnableFaceTracking:")
        if view.responds(to: sel),
           let imp = class_getMethodImplementation(type(of: view), sel) {
            typealias F = @convention(c) (AnyObject, Selector, Bool) -> Void
            unsafeBitCast(imp, to: F.self)(view, sel, false)
        }
        
        self.avtView = view
    }
    
    // MARK: - Loading
    
    /// Load an animoji character by name (e.g. "cat", "dog", "robot").
    @discardableResult
    public func load(_ characterID: String) -> Bool {
        guard let cls = NSClassFromString("AVTAnimoji") else { return false }
        
        // AVTAnimoji.animojiNamed:
        let createSel = NSSelectorFromString("animojiNamed:")
        guard (cls as AnyObject).responds(to: createSel),
              let obj = (cls as AnyObject).perform(createSel, with: characterID)?.takeUnretainedValue()
        else { return false }
        
        // loadIfNeeded
        let loadSel = NSSelectorFromString("loadIfNeeded")
        if obj.responds(to: loadSel) {
            _ = obj.perform(loadSel)
        }
        
        self.animoji = obj
        self.characterID = characterID
        
        // Set avatar on AVTView
        if let view = avtView {
            let setAvatarSel = NSSelectorFromString("setAvatar:")
            if view.responds(to: setAvatarSel) {
                view.perform(setAvatarSel, with: obj)
            }
        }
        
        return true
    }
    
    // MARK: - Tracking
    
    /// Apply face tracking data to the loaded animoji.
    ///
    /// Calls `_applyBlendShapesWithTrackingData:` and
    /// `_applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:` directly
    /// with the 480-byte tracking struct.
    ///
    /// Falls back to `updatePoseWithFaceTrackingData:applySmoothing:` (NSData wrapper)
    /// if the direct methods are unavailable.
    /// Stored ARFrame for Apple comparison
    private var lastFrame: ARFrame?
    
    public func applyTracking(_ tracking: AvatarFaceTracking) {
        applyTrackingInternal(tracking)
    }
    
    /// Apply tracking with ARFrame reference for Apple buffer comparison.
    public func applyTracking(_ tracking: AvatarFaceTracking, frame: ARFrame?) {
        lastFrame = frame
        applyTrackingInternal(tracking)
    }
    
    /// Verification: track calls per frame and blendshape stability
    private var verifyCallCount = 0
    private var verifyFrameTime: TimeInterval = 0
    private var verifyCallsThisFrame = 0
    private var verifyPrevBS: [String: Float] = [:]

    private func applyTrackingInternal(_ tracking: AvatarFaceTracking) {
        guard let animoji else { return }
        let obj = animoji as AnyObject

        // Merge bodyTranslation into headTranslation before building buffer,
        // so Apple's updatePose applies the combined position in one shot.
        var merged = tracking
        if let bodyT = tracking.bodyTranslation {
            merged.headTranslation = tracking.headTranslation + bodyT
        }
        let data = TrackingDataBuilder.build(from: merged)

        // --- Verification logging ---
        verifyCallCount += 1
        let now = CACurrentMediaTime()
        if now - verifyFrameTime < 0.001 {
            verifyCallsThisFrame += 1
        } else {
            if verifyCallsThisFrame > 1 {
                os_log(.default, log: brLog, "[VERIFY] MULTI-CALL: %{public}d calls in one frame!", verifyCallsThisFrame)
            }
            verifyCallsThisFrame = 1
            verifyFrameTime = now
        }

        if verifyCallCount % 10 == 0 {
            // Check max blendshape delta
            var maxD: Float = 0; var maxK = ""
            for (k, v) in tracking.blendshapes {
                let d = abs(v - (verifyPrevBS[k] ?? 0))
                if d > maxD && k != "eyeBlinkLeft" && k != "eyeBlinkRight" { maxD = d; maxK = k }
            }
            if maxD > 0.05 {
                os_log(.default, log: brLog, "[VERIFY] DELTA %{public}@=%.3f", maxK, maxD)
            }
            verifyPrevBS = tracking.blendshapes
        }

        // Use Apple's unified method — avoids ghosting from separate blendshape + headPose calls
        let updateSel = NSSelectorFromString("updatePoseWithFaceTrackingData:applySmoothing:")
        if obj.responds(to: updateSel),
           let imp = class_getMethodImplementation(type(of: obj), updateSel) {
            typealias UpdateFunc = @convention(c) (AnyObject, Selector, NSData, Bool) -> Void
            unsafeBitCast(imp, to: UpdateFunc.self)(obj, updateSel, data as NSData, true)
        }
    }
    
    /// Apply face tracking with direct head pose control.
    /// Uses _applyBlendShapes for expressions but sets neckNode(head_JNT) orientation directly,
    /// bypassing _applyHeadPose and its pointOfView multiplication.
    public func applyTrackingDirect(_ tracking: AvatarFaceTracking) {
        guard let animoji else { return }
        let obj = animoji as AnyObject

        var data = TrackingDataBuilder.build(from: tracking)

        // Zero out quaternion in buffer so _applyBlendShapes doesn't also
        // apply head pose (we set it manually via setNeckOrientation below).
        // This prevents ghosting from two competing head orientations.
        data.withUnsafeMutableBytes { raw in
            guard let ptr = raw.baseAddress else { return }
            var identity = simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)
            memcpy(ptr + 0x20, &identity, 16)
        }

        data.withUnsafeBytes { raw in
            guard let ptr = raw.baseAddress else { return }
            let blendSel = NSSelectorFromString("_applyBlendShapesWithTrackingData:")
            if obj.responds(to: blendSel),
               let imp = class_getMethodImplementation(type(of: obj), blendSel) {
                typealias Func = @convention(c) (AnyObject, Selector, UnsafeRawPointer) -> Void
                unsafeBitCast(imp, to: Func.self)(obj, blendSel, ptr)
            }
        }
        
        // Set orientation on neckNode (head_JNT)
        // If body rotation exists, compose: world_head = body * head
        // Otherwise just use rawQuaternion directly
        if let headQ = tracking.rawQuaternion {
            if let bodyQ = tracking.bodyRotation {
                // head_JNT gets body rotation * head-relative rotation
                // This makes the head follow the body AND add its own motion
                setNeckOrientation(bodyQ * headQ)
            } else {
                setNeckOrientation(headQ)
            }
        }
        
        // Set position on rootJointNode (root_JNT)
        // Body translation = sway + breathing (the whole character moves)
        // Head translation = neck pivot displacement (added on top)
        if let bodyT = tracking.bodyTranslation {
            let headT = tracking.headTranslation
            setRootJointPosition(bodyT + headT)
        } else {
            let t = tracking.headTranslation
            if t.x != 0 || t.y != 0 || t.z != 0 {
                setRootJointPosition(t)
            }
        }
    }

    /// Apply a preset expression.
    public func applyPreset(_ preset: ExpressionPreset, pitch: Float = 0, yaw: Float = 0) {
        applyTracking(preset.tracking(pitch: pitch, yaw: yaw))
    }
    
    // MARK: - Node Access (VFXNode, not SCNNode)
    //
    // Node hierarchy (from ivar analysis 2026-04-13):
    //   AVTAnimoji._headNode   (0x100) = 'head'      — mesh node (visual)
    //   AVTAvatar._headNode    (0x18)  = 'head'      — same, inherited
    //   AVTAvatar._neckNode    (0x30)  = 'head_JNT'  — bone joint (Apple sets orientation here)
    //   AVTAvatar._rootJointNode(0x38) = 'root_JNT'  — root bone (Apple sets position here)
    //   AVTAnimoji._cameraNode (0x110) = 'cameras'   — camera node
    //
    // _applyHeadPose uses:
    //   [self._neckNode setOrientation:]     — NOT headNode!
    //   [self._rootJointNode setPosition:]   — NOT neckNode!
    
    /// The head mesh node ('head'). Visual node, NOT where Apple sets orientation.
    public var headNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("headNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    /// The neck bone joint ('head_JNT'). Apple's _applyHeadPose sets orientation on this node.
    public var neckNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("neckNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    /// The root bone joint ('root_JNT'). Apple's _applyHeadPose sets position on this node.
    public var rootJointNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("rootJointNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    /// The avatar root node (VFXNode type on iOS 18+).
    public var avatarNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("avatarNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    /// The camera node ('cameras'). Used as pointOfView for camera-relative head pose.
    public var cameraNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("cameraNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    /// Read the camera node's worldTransform (4x4 matrix).
    public func getCameraWorldTransform() -> simd_float4x4? {
        guard let cam = cameraNode else { return nil }
        let sel = NSSelectorFromString("worldTransform")
        let obj = cam as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return nil }
        typealias F = @convention(c) (AnyObject, Selector) -> simd_float4x4
        return unsafeBitCast(imp, to: F.self)(obj, sel)
    }
    
    // MARK: - Direct Node Manipulation
    
    /// Read the root joint's current position ('root_JNT').
    /// This is where Apple's _applyHeadPose sets position.
    public func getRootJointPosition() -> SIMD3<Float>? {
        guard let node = rootJointNode else { return nil }
        let sel = NSSelectorFromString("position")
        let obj = node as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return nil }
        typealias F = @convention(c) (AnyObject, Selector) -> SIMD4<Float>
        let pos = unsafeBitCast(imp, to: F.self)(obj, sel)
        return SIMD3(pos.x, pos.y, pos.z)
    }
    
    /// Read the neck joint's current orientation ('head_JNT').
    /// This is where Apple's _applyHeadPose sets orientation.
    public func getNeckOrientation() -> simd_quatf? {
        guard let node = neckNode else { return nil }
        let sel = NSSelectorFromString("orientation")
        let obj = node as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return nil }
        typealias F = @convention(c) (AnyObject, Selector) -> simd_quatf
        return unsafeBitCast(imp, to: F.self)(obj, sel)
    }
    
    /// Read the neck node's current position ('head_JNT').
    public func getNeckPosition() -> SIMD3<Float>? {
        guard let node = neckNode else { return nil }
        let sel = NSSelectorFromString("position")
        let obj = node as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return nil }
        typealias F = @convention(c) (AnyObject, Selector) -> SIMD4<Float>
        let pos = unsafeBitCast(imp, to: F.self)(obj, sel)
        return SIMD3(pos.x, pos.y, pos.z)
    }
    
    /// Read the head mesh node's current orientation ('head').
    /// Note: this is the mesh node, NOT where Apple sets orientation.
    /// Use getNeckOrientation() for the bone joint that Apple actually drives.
    public func getHeadOrientation() -> simd_quatf? {
        guard let node = headNode else { return nil }
        let sel = NSSelectorFromString("orientation")
        let obj = node as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return nil }
        typealias F = @convention(c) (AnyObject, Selector) -> simd_quatf
        return unsafeBitCast(imp, to: F.self)(obj, sel)
    }
    
    /// Set the root joint's position directly ('root_JNT').
    public func setRootJointPosition(_ position: SIMD3<Float>) {
        guard let node = rootJointNode else { return }
        let sel = NSSelectorFromString("setPosition:")
        let obj = node as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return }
        let pos = SIMD4<Float>(position.x, position.y, position.z, 0)
        typealias F = @convention(c) (AnyObject, Selector, SIMD4<Float>) -> Void
        unsafeBitCast(imp, to: F.self)(obj, sel, pos)
    }
    
    /// Set the neck joint's orientation directly ('head_JNT').
    public func setNeckOrientation(_ orientation: simd_quatf) {
        guard let node = neckNode else { return }
        let sel = NSSelectorFromString("setOrientation:")
        let obj = node as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return }
        typealias F = @convention(c) (AnyObject, Selector, simd_quatf) -> Void
        unsafeBitCast(imp, to: F.self)(obj, sel, orientation)
    }
    
    /// Set the neck node's position directly.
    public func setNeckPosition(_ position: SIMD3<Float>) {
        guard let node = neckNode else { return }
        let sel = NSSelectorFromString("setPosition:")
        let obj = node as AnyObject
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return }
        let pos = SIMD4<Float>(position.x, position.y, position.z, 0)
        typealias F = @convention(c) (AnyObject, Selector, SIMD4<Float>) -> Void
        unsafeBitCast(imp, to: F.self)(obj, sel, pos)
    }
    
    // MARK: - Head Projection

    /// Read the head node's bounding box (min, max) in local space.
    /// Returns nil if headNode doesn't respond to boundingBox.
    public func getHeadBoundingBox() -> (min: SIMD3<Float>, max: SIMD3<Float>)? {
        guard let node = headNode else { return nil }
        let obj = node as AnyObject

        // VFXNode/SCNNode: - (BOOL)getBoundingBoxMin:(SCNVector3 *)min max:(SCNVector3 *)max
        let sel = NSSelectorFromString("getBoundingBoxMin:max:")
        guard obj.responds(to: sel),
              let imp = obj.method(for: sel) else { return nil }

        var bMin = SIMD4<Float>.zero
        var bMax = SIMD4<Float>.zero
        typealias F = @convention(c) (AnyObject, Selector, UnsafeMutablePointer<SIMD4<Float>>, UnsafeMutablePointer<SIMD4<Float>>) -> Bool
        let ok = unsafeBitCast(imp, to: F.self)(obj, sel, &bMin, &bMax)
        guard ok else { return nil }

        return (SIMD3(bMin.x, bMin.y, bMin.z), SIMD3(bMax.x, bMax.y, bMax.z))
    }

    /// Project a point relative to the avatar's root joint into AVTView coordinates.
    ///
    /// `offset` is in scene space: +x = right, +y = up, +z = toward camera.
    /// Pass .zero to get the head center. Pass e.g. (5, 5, 0) for top-right.
    /// Returns nil if nodes or view are unavailable.
    public func projectPoint(offset: SIMD3<Float> = .zero) -> CGPoint? {
        guard let view = avtView,
              view.bounds.width > 0, view.bounds.height > 0 else { return nil }

        guard let rootPos = getRootJointPosition() else { return nil }
        guard let camTransform = getCameraWorldTransform() else { return nil }

        let worldPos = SIMD4<Float>(rootPos.x + offset.x, rootPos.y + offset.y, rootPos.z + offset.z, 1.0)

        // View matrix = inverse of camera world transform
        let viewMatrix = camTransform.inverse
        let cameraSpace = viewMatrix * worldPos

        guard cameraSpace.z < -0.001 else { return nil }

        let fov: Float = 30.0 * .pi / 180.0
        let aspect = Float(view.bounds.width / view.bounds.height)
        let tanHalfFov = tan(fov / 2.0)

        let ndcX = cameraSpace.x / (-cameraSpace.z * tanHalfFov * aspect)
        let ndcY = cameraSpace.y / (-cameraSpace.z * tanHalfFov)

        let viewX = CGFloat((1.0 + ndcX) / 2.0) * view.bounds.width
        let viewY = CGFloat((1.0 - ndcY) / 2.0) * view.bounds.height

        return CGPoint(x: viewX, y: viewY)
    }

    /// Project the head's bounding box top-right corner into AVTView coordinates.
    /// Uses the actual head mesh bounding box for precise positioning.
    /// Returns (projected point, depth scale relative to first call) or nil.
    public func projectHeadTopRight() -> CGPoint? {
        guard let bbox = getHeadBoundingBox() else { return nil }
        let cx = (bbox.min.x + bbox.max.x) / 2
        let cy = (bbox.min.y + bbox.max.y) / 2
        let cz = (bbox.min.z + bbox.max.z) / 2
        // x: 25% inward from max toward center, y: 50% inward
        let x = cx + (bbox.max.x - cx) * 0.75
        let y = (cy + bbox.max.y) / 2
        return projectPoint(offset: SIMD3<Float>(x, y, cz))
    }

    // MARK: - Apple Buffer Comparison
    
    /// Compare our tracking buffer with Apple's AVTFaceTrackingInfo output.
    public func compareWithApple(frame: ARFrame, constrainHeadPose: Bool, ourTracking: AvatarFaceTracking) {
        guard let cls = NSClassFromString("AVTFaceTrackingInfo") as? NSObject.Type else {
//            print("[CMP] AVTFaceTrackingInfo not found")
            return
        }
        
        // +[AVTFaceTrackingInfo trackingInfoWithARFrame:inputOrientation:outputOrientation:constrainHeadPose:]
        let sel = NSSelectorFromString("trackingInfoWithARFrame:inputOrientation:outputOrientation:constrainHeadPose:")
        
        // Get the class method IMP directly via objc runtime
        guard let method = class_getClassMethod(cls, sel) else {
//            print("[CMP] can't get class method")
            return
        }
        let funcImp = method_getImplementation(method)
        typealias CreateFunc = @convention(c) (AnyObject, Selector, AnyObject, Int, Int, Bool) -> AnyObject?
        let createFunc = unsafeBitCast(funcImp, to: CreateFunc.self)
        
        guard let trackingInfo = createFunc(cls, sel, frame, 1, 1, constrainHeadPose) else {
//            print("[CMP] Apple returned nil")
            return
        }
        
        // trackingData returns a pointer to the internal struct (ivar at offset 16)
        let tdSel = NSSelectorFromString("trackingData")
        guard let tdMethod = class_getInstanceMethod(type(of: trackingInfo) as? AnyClass, tdSel) else {
//            print("[CMP] can't get trackingData method")
            return
        }
        let tdImp = method_getImplementation(tdMethod)
        typealias TDFunc = @convention(c) (AnyObject, Selector) -> UnsafeRawPointer
        let applePtr = unsafeBitCast(tdImp, to: TDFunc.self)(trackingInfo, tdSel)
        
        // Dump first 64 bytes of Apple's buffer as hex for layout verification
        let mode = constrainHeadPose ? "WORLD" : "AR"
        var hexDump = ""
        for i in 0..<64 {
            let byte = applePtr.load(fromByteOffset: i, as: UInt8.self)
            hexDump += String(format: "%02x", byte)
            if (i + 1) % 16 == 0 { hexDump += "\n" }
            else if (i + 1) % 4 == 0 { hexDump += " " }
        }
//        print("[CMP-\(mode)] apple raw hex (64 bytes):")
        for line in hexDump.split(separator: "\n") {
//            print("[CMP-\(mode)]   \(line)")
        }
        
        // Also dump the face anchor transform from the frame for reference
        if let faceAnchor = frame.anchors.compactMap({ $0 as? ARFaceAnchor }).first {
            let ft = faceAnchor.transform
//            print("[CMP-\(mode)] frame face.t=(\(String(format: "%.4f,%.4f,%.4f", ft.columns.3.x, ft.columns.3.y, ft.columns.3.z)))")
//            print("[CMP-\(mode)] frame face.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", simd_quatf(ft).imag.x, simd_quatf(ft).imag.y, simd_quatf(ft).imag.z, simd_quatf(ft).real)))")
            let ct = frame.camera.transform
//            print("[CMP-\(mode)] frame cam.q=(\(String(format: "%.4f,%.4f,%.4f,%.4f", simd_quatf(ct).imag.x, simd_quatf(ct).imag.y, simd_quatf(ct).imag.z, simd_quatf(ct).real)))")
        }
        
        // Read Apple's buffer fields
        let appleTranslation = applePtr.load(fromByteOffset: 0x10, as: SIMD4<Float>.self)
        let appleQuat = applePtr.load(fromByteOffset: 0x20, as: SIMD4<Float>.self)
        let appleCameraSpace = applePtr.load(fromByteOffset: 0x30, as: UInt8.self)
        
        // Build our buffer for comparison using the matching mode
        // For AR (constrainHeadPose=false): rebuild with .appleAR to match Apple's formula
        // For WORLD (constrainHeadPose=true): rebuild with .world to match Apple's formula
        let cmpTracking: AvatarFaceTracking
        if let faceAnchor = frame.anchors.compactMap({ $0 as? ARFaceAnchor }).first {
            let mode: AvatarFaceTracking.TrackingMode = constrainHeadPose ? .world : .appleAR
            cmpTracking = AvatarFaceTracking(faceAnchor: faceAnchor, frame: frame, mode: mode)
        } else {
            cmpTracking = ourTracking
        }
        let ourData = TrackingDataBuilder.build(from: cmpTracking)
        ourData.withUnsafeBytes { raw in
            guard let ourPtr = raw.baseAddress else { return }
            let ourTranslation = ourPtr.load(fromByteOffset: 0x10, as: SIMD4<Float>.self)
            let ourQuat = ourPtr.load(fromByteOffset: 0x20, as: SIMD4<Float>.self)
            let ourCameraSpace = ourPtr.load(fromByteOffset: 0x30, as: UInt8.self)
            
            let tDiff = simd_length(appleTranslation - ourTranslation)
            // quaternion dot product (treat as SIMD4 to handle sign)
            let qDot = abs(simd_dot(appleQuat, ourQuat) / (simd_length(appleQuat) * simd_length(ourQuat)))
            
            let mode = constrainHeadPose ? "WORLD" : "AR"
//            print("[CMP-\(mode)] apple.t=(\(String(format: "%.4f,%.4f,%.4f,%.4f", appleTranslation.x, appleTranslation.y, appleTranslation.z, appleTranslation.w)))")
//            print("[CMP-\(mode)]   our.t=(\(String(format: "%.4f,%.4f,%.4f,%.4f", ourTranslation.x, ourTranslation.y, ourTranslation.z, ourTranslation.w)))")
//            print("[CMP-\(mode)]   t_diff=\(String(format: "%.6f", tDiff))")
//            print("[CMP-\(mode)] apple.q=(\(String(format: "%.6f,%.6f,%.6f,%.6f", appleQuat.x, appleQuat.y, appleQuat.z, appleQuat.w)))")
//            print("[CMP-\(mode)]   our.q=(\(String(format: "%.6f,%.6f,%.6f,%.6f", ourQuat.x, ourQuat.y, ourQuat.z, ourQuat.w)))")
//            print("[CMP-\(mode)]   q_dot=\(String(format: "%.8f", qDot)) (1.0=identical)")
//            print("[CMP-\(mode)] apple.cs=\(appleCameraSpace) our.cs=\(ourCameraSpace)")
            
            // Also compare first 5 blendshapes
            let appleBS0 = applePtr.load(fromByteOffset: 0x34, as: Float.self)
            let appleBS1 = applePtr.load(fromByteOffset: 0x38, as: Float.self)
            let ourBS0 = ourPtr.load(fromByteOffset: 0x34, as: Float.self)
            let ourBS1 = ourPtr.load(fromByteOffset: 0x38, as: Float.self)
//            print("[CMP-\(mode)] apple.bs[0,1]=(\(String(format: "%.4f,%.4f", appleBS0, appleBS1)))")
//            print("[CMP-\(mode)]   our.bs[0,1]=(\(String(format: "%.4f,%.4f", ourBS0, ourBS1)))")
//            print("[CMP-\(mode)] ---")
        }
    }
}
