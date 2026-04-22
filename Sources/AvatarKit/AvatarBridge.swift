import Foundation
import simd
import UIKit
import ObjectiveC
import SceneKit
import ARKit

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
    /// Debug counter for periodic logging
    private var debugApplyCount = 0
    /// Stored ARFrame for Apple comparison (set via applyTracking(_:frame:))
    private var lastFrame: ARFrame?
    /// Pre-_applyHeadPose tracking data for accurate CMP comparison
    private var preApplyTracking: AvatarFaceTracking?
    
    public func applyTracking(_ tracking: AvatarFaceTracking) {
        applyTrackingInternal(tracking)
    }
    
    /// Apply tracking with ARFrame reference for Apple buffer comparison.
    public func applyTracking(_ tracking: AvatarFaceTracking, frame: ARFrame?) {
        lastFrame = frame
        applyTrackingInternal(tracking)
    }
    
    private func applyTrackingInternal(_ tracking: AvatarFaceTracking) {
        guard let animoji else { return }
        let obj = animoji as AnyObject
        
        let data = TrackingDataBuilder.build(from: tracking)
        
        debugApplyCount += 1
        let shouldLog = debugApplyCount % 60 == 1
        
        // Save pre-_applyHeadPose tracking for accurate CMP comparison
        preApplyTracking = tracking
        
        // One-time log of pov.worldTransform
        if debugApplyCount == 1, let pov = scenePointOfView {
            let wt = (pov as AnyObject).value(forKeyPath: "worldTransform") as? SCNMatrix4
            if let wt {
//                print("[POV] worldTransform:")
//                print("[POV]   col0=(\(wt.m11), \(wt.m21), \(wt.m31), \(wt.m41))")
//                print("[POV]   col1=(\(wt.m12), \(wt.m22), \(wt.m32), \(wt.m42))")
//                print("[POV]   col2=(\(wt.m13), \(wt.m23), \(wt.m33), \(wt.m43))")
//                print("[POV]   col3=(\(wt.m14), \(wt.m24), \(wt.m34), \(wt.m44))")
            }
            let t = (pov as AnyObject).value(forKeyPath: "transform") as? SCNMatrix4
            if let t {
//                print("[POV] transform:")
//                print("[POV]   col0=(\(t.m11), \(t.m21), \(t.m31), \(t.m41))")
//                print("[POV]   col1=(\(t.m12), \(t.m22), \(t.m32), \(t.m42))")
//                print("[POV]   col2=(\(t.m13), \(t.m23), \(t.m33), \(t.m43))")
//                print("[POV]   col3=(\(t.m14), \(t.m24), \(t.m34), \(t.m44))")
            }
//            print("[POV] scenePointOfView class: \(type(of: pov))")
        }
        // === DEBUG POINT D-pre: Before Apple calls ===
        if shouldLog {
            if let rootPos = getRootJointPosition() {
//                print("[D-PRE] rootJointPos=(\(String(format: "%.4f,%.4f,%.4f", rootPos.x, rootPos.y, rootPos.z)))")
            }
            if let neckQ = getNeckOrientation() {
//                print("[D-PRE] neckQ=(\(String(format: "%.4f,%.4f,%.4f,%.4f", neckQ.imag.x, neckQ.imag.y, neckQ.imag.z, neckQ.real)))")
            }
            if let wt = getCameraWorldTransform() {
                let camQ = simd_quatf(wt)
//                print("[D-PRE] camWT.pos=(\(String(format: "%.3f,%.3f,%.3f", wt.columns.3.x, wt.columns.3.y, wt.columns.3.z)))")
//                print("[D-PRE] camWT.quat=(\(String(format: "%.4f,%.4f,%.4f,%.4f", camQ.imag.x, camQ.imag.y, camQ.imag.z, camQ.real)))")
                // Print full matrix for rotation analysis
//                print("[D-PRE] camWT.col0=(\(String(format: "%.4f,%.4f,%.4f", wt.columns.0.x, wt.columns.0.y, wt.columns.0.z)))")
//                print("[D-PRE] camWT.col1=(\(String(format: "%.4f,%.4f,%.4f", wt.columns.1.x, wt.columns.1.y, wt.columns.1.z)))")
//                print("[D-PRE] camWT.col2=(\(String(format: "%.4f,%.4f,%.4f", wt.columns.2.x, wt.columns.2.y, wt.columns.2.z)))")
            }
//            print("[D-PRE] pov=\(cameraNode == nil ? "nil" : "exists") coordSpace=\(tracking.coordinateSpace)")
        }
        
        // Primary: direct struct pointer calls (avoids NSData overhead)
        var applied = false
        
        data.withUnsafeBytes { raw in
            guard let ptr = raw.baseAddress else { return }
            
            // Apply blendshapes
            let blendSel = NSSelectorFromString("_applyBlendShapesWithTrackingData:")
            if obj.responds(to: blendSel),
               let imp = class_getMethodImplementation(type(of: obj), blendSel) {
                typealias Func = @convention(c) (AnyObject, Selector, UnsafeRawPointer) -> Void
                unsafeBitCast(imp, to: Func.self)(obj, blendSel, ptr)
                applied = true
            }
            
            // Apply head pose
            // _applyHeadPose for cameraSpace=1 does: neckQ = inv(pov) × trackingQ
            // With pov=nil (identity): neckQ = trackingQ directly.
            // - .world (cameraSpace=0): uses quaternion directly ✓
            // - .camera: portrait-corrected quaternion, pov=nil works ✓
            // - .appleAR: quaternion is inv(cam)×face (~90° Z), pov=nil → 90° ✗
            //   Fix: use _applyBlendShapes only, then set neckNode/rootJoint directly
            //   with the face's world-space quaternion (cam × inv(cam) × face = face).
            if tracking.trackingMode == .appleAR {
                if let frame = lastFrame, let q = tracking.rawQuaternion {
                    // Convert camera-space quaternion back to world space
                    let camQ = simd_quatf(frame.camera.transform)
                    let worldQ = camQ * q
                    setNeckOrientation(worldQ)
                    // Convert camera-space translation to world space
                    // headTranslation is already scaled by AvatarFaceTracking+ARKit
                    let t = tracking.headTranslation
                    let worldT = camQ.act(t)
                    setRootJointPosition(worldT)
                }
                // No frame → skip head pose entirely (don't fall through to _applyHeadPose
                // which would show 90° rotated for one frame)
            } else {
                let poseSel = NSSelectorFromString("_applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:")
                if obj.responds(to: poseSel),
                   let imp = class_getMethodImplementation(type(of: obj), poseSel) {
                    typealias Func = @convention(c) (AnyObject, Selector, UnsafeRawPointer, Bool, AnyObject?) -> Void
                    unsafeBitCast(imp, to: Func.self)(obj, poseSel, ptr, false, nil)
                }
                
                // Apple's _applyHeadPose in world mode (cameraSpace=0) does NOT apply
                // translation — it only sets neck orientation. We must apply translation
                // manually for idle animation spatial movement to work.
                // Note: headTranslation is already in avatar scene units (pre-scaled
                // by AvatarFaceTracking+ARKit or the idle animator).
                let t = tracking.headTranslation
                if t.x != 0 || t.y != 0 || t.z != 0 {
                    setRootJointPosition(t)
                }
            }
        }
        
        // === DEBUG POINT D-post: After Apple calls ===
        if shouldLog {
            if let rootPos = getRootJointPosition() {
//                print("[D-POST] rootJointPos=(\(String(format: "%.4f,%.4f,%.4f", rootPos.x, rootPos.y, rootPos.z)))")
            }
            if let neckQ = getNeckOrientation() {
//                print("[D-POST] neckQ=(\(String(format: "%.4f,%.4f,%.4f,%.4f", neckQ.imag.x, neckQ.imag.y, neckQ.imag.z, neckQ.real)))")
            }
//            print("[D-POST] ---")
        }
        
        // Apple buffer comparison (every 60 frames)
        if shouldLog, let frame = lastFrame, let preTracking = preApplyTracking {
            let isWorld = tracking.coordinateSpace == .world
            compareWithApple(frame: frame, constrainHeadPose: isWorld, ourTracking: preTracking)
        }
        
        // Fallback: NSData wrapper
        if !applied {
            let sel = NSSelectorFromString("updatePoseWithFaceTrackingData:applySmoothing:")
            if obj.responds(to: sel),
               let imp = class_getMethodImplementation(type(of: obj), sel) {
                typealias UpdateFunc = @convention(c) (AnyObject, Selector, NSData, Bool) -> Void
                unsafeBitCast(imp, to: UpdateFunc.self)(obj, sel, data as NSData, false)
            }
        }
    }
    
    /// Apply face tracking with direct head pose control.
    /// Uses _applyBlendShapes for expressions but sets neckNode(head_JNT) orientation directly,
    /// bypassing _applyHeadPose and its pointOfView multiplication.
    public func applyTrackingDirect(_ tracking: AvatarFaceTracking) {
        guard let animoji else { return }
        let obj = animoji as AnyObject
        
        let data = TrackingDataBuilder.build(from: tracking)
        
        data.withUnsafeBytes { raw in
            guard let ptr = raw.baseAddress else { return }
            
            // Apply blendshapes only
            let blendSel = NSSelectorFromString("_applyBlendShapesWithTrackingData:")
            if obj.responds(to: blendSel),
               let imp = class_getMethodImplementation(type(of: obj), blendSel) {
                typealias Func = @convention(c) (AnyObject, Selector, UnsafeRawPointer) -> Void
                unsafeBitCast(imp, to: Func.self)(obj, blendSel, ptr)
            }
        }
        
        // Set orientation on neckNode (head_JNT) — this is where Apple sets it
        if let q = tracking.rawQuaternion {
            setNeckOrientation(q)
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
