import Foundation
import SceneKit

// MARK: - Avatar Bridge

/// Bridge to Apple's private AvatarKit framework via ObjC runtime.
///
/// Loads animoji characters, applies face tracking data, and provides
/// the SceneKit scene for rendering.
///
/// Thread safety: all methods must be called from the main thread.
public final class AvatarBridge {
    
    /// The loaded animoji instance (AVTAnimoji).
    private var animoji: AnyObject?
    
    /// Cached scene from the animoji.
    public private(set) var scene: SCNScene?
    
    /// The character ID currently loaded.
    public private(set) var characterID: String?
    
    /// Whether AvatarKit framework is available.
    public static var isAvailable: Bool {
        NSClassFromString("AVTAnimoji") != nil
    }
    
    public init() {
        // Load framework
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY)
    }
    
    // MARK: - Loading
    
    /// Load an animoji character by name (e.g. "cat", "dog", "robot").
    @discardableResult
    public func load(_ characterID: String) -> Bool {
        guard let cls = NSClassFromString("AVTAnimoji") else { return false }
        
        // AVTAnimoji.animojiNamed:
        let createSel = NSSelectorFromString("animojiNamed:")
        guard cls.responds(to: createSel),
              let obj = cls.perform(createSel, with: characterID)?.takeUnretainedValue()
        else { return false }
        
        // loadIfNeeded
        let loadSel = NSSelectorFromString("loadIfNeeded")
        if obj.responds(to: loadSel) {
            _ = obj.perform(loadSel)
        }
        
        self.animoji = obj
        self.characterID = characterID
        
        // Extract scene
        let sceneSel = NSSelectorFromString("scene")
        if obj.responds(to: sceneSel),
           let scn = obj.perform(sceneSel)?.takeUnretainedValue() as? SCNScene {
            self.scene = scn
        }
        
        return true
    }
    
    // MARK: - Tracking
    
    /// Apply face tracking data to the loaded animoji.
    ///
    /// This is the primary method — builds the 480-byte buffer and calls
    /// `updatePoseWithFaceTrackingData:applySmoothing:` which handles both
    /// blendshapes (→ headNode morpher) and head pose (→ neckNode).
    public func applyTracking(_ tracking: AvatarFaceTracking) {
        guard let animoji else { return }
        
        let data = TrackingDataBuilder.build(from: tracking)
        
        // Try unified path first
        let sel = NSSelectorFromString("updatePoseWithFaceTrackingData:applySmoothing:")
        let obj = animoji as AnyObject
        if obj.responds(to: sel),
           let imp = class_getMethodImplementation(type(of: obj), sel) {
            typealias UpdateFunc = @convention(c) (AnyObject, Selector, NSData, Bool) -> Void
            unsafeBitCast(imp, to: UpdateFunc.self)(obj, sel, data as NSData, false)
            return
        }
        
        // Fallback: apply blendshapes and head pose separately
        applyBlendshapesFallback(data)
        applyHeadPoseFallback(data)
    }
    
    /// Apply a preset expression.
    public func applyPreset(_ preset: ExpressionPreset, pitch: Float = 0, yaw: Float = 0) {
        applyTracking(preset.tracking(pitch: pitch, yaw: yaw))
    }
    
    // MARK: - Node Access
    
    /// The head node (owns the morpher for blendshapes).
    public var headNode: SCNNode? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("headNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue() as? SCNNode
    }
    
    /// The neck node (receives head pose rotation).
    public var neckNode: SCNNode? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("neckNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue() as? SCNNode
    }
    
    /// The avatar root node.
    public var avatarNode: SCNNode? {
        guard let animoji else { return nil }
        let sel = NSSelectorFromString("avatarNode")
        guard (animoji as AnyObject).responds(to: sel) else { return nil }
        return (animoji as AnyObject).perform(sel)?.takeUnretainedValue() as? SCNNode
    }
    
    // MARK: - Private Fallbacks
    
    private func applyBlendshapesFallback(_ data: Data) {
        guard let animoji else { return }
        
        let sel = NSSelectorFromString("_applyBlendShapesWithTrackingData:")
        let obj = animoji as AnyObject
        guard obj.responds(to: sel),
              let imp = class_getMethodImplementation(type(of: obj), sel)
        else { return }
        
        data.withUnsafeBytes { raw in
            guard let ptr = raw.baseAddress else { return }
            typealias Func = @convention(c) (AnyObject, Selector, UnsafeRawPointer) -> Void
            unsafeBitCast(imp, to: Func.self)(obj, sel, ptr)
        }
    }
    
    private func applyHeadPoseFallback(_ data: Data) {
        guard let animoji else { return }
        
        let sel = NSSelectorFromString("_applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:")
        let obj = animoji as AnyObject
        guard obj.responds(to: sel),
              let imp = class_getMethodImplementation(type(of: obj), sel)
        else { return }
        
        data.withUnsafeBytes { raw in
            guard let ptr = raw.baseAddress else { return }
            typealias Func = @convention(c) (AnyObject, Selector, UnsafeRawPointer, Bool, AnyObject?) -> Void
            unsafeBitCast(imp, to: Func.self)(obj, sel, ptr, false, nil)
        }
    }
}
