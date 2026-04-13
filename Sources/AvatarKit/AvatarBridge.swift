import Foundation
import simd
import UIKit
import ObjectiveC

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
    public func applyTracking(_ tracking: AvatarFaceTracking) {
        guard let animoji else { return }
        let obj = animoji as AnyObject
        
        let data = TrackingDataBuilder.build(from: tracking)
        
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
            let poseSel = NSSelectorFromString("_applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:")
            if obj.responds(to: poseSel),
               let imp = class_getMethodImplementation(type(of: obj), poseSel) {
                typealias Func = @convention(c) (AnyObject, Selector, UnsafeRawPointer, Bool, AnyObject?) -> Void
                // Pass cameraNode as pointOfView for world-space tracking:
                // _applyHeadPose uses it to transform the quaternion into scene space.
                // For camera-relative tracking, callers should use applyTrackingDirect instead.
                let pov = self.cameraNode
                unsafeBitCast(imp, to: Func.self)(obj, poseSel, ptr, false, pov)
            }
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
    /// Uses _applyBlendShapes for expressions but sets headNode.orientation directly,
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
        
        // Set head orientation directly via ObjC runtime
        if let headNode = self.headNode,
           let q = tracking.rawQuaternion {
            let sel = NSSelectorFromString("setOrientation:")
            let node = headNode as AnyObject
            if node.responds(to: sel),
               let imp = node.method(for: sel) {
                typealias F = @convention(c) (AnyObject, Selector, simd_quatf) -> Void
                unsafeBitCast(imp, to: F.self)(node, sel, q)
            }
        }
    }
    
    /// Apply a preset expression.
    public func applyPreset(_ preset: ExpressionPreset, pitch: Float = 0, yaw: Float = 0) {
        applyTracking(preset.tracking(pitch: pitch, yaw: yaw))
    }
    
    // MARK: - Node Access (VFXNode, not SCNNode)
    
    /// The head node (VFXNode type on iOS 18+).
    public var headNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("headNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    /// The neck node (VFXNode type on iOS 18+).
    public var neckNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("neckNode")
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
    
    /// The camera node (VFXNode type on iOS 18+).
    /// Used as pointOfView for camera-relative head pose transformation.
    public var cameraNode: AnyObject? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("cameraNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue()
    }
    
    // MARK: - Direct Node Manipulation
    
    /// Read the neck node's current position.
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
    
    /// Set the neck node's position directly (bypasses _applyHeadPose translation).
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
}
