import Foundation
import ObjectiveC

// MARK: - ObjC Runtime Helpers

/// Thin wrapper around ObjC runtime calls to Apple's private frameworks.
/// Eliminates the 5-line boilerplate (selector → responds → method → imp → bitCast).
enum ObjCRuntime {
    
    // MARK: - Void Instance Calls
    
    /// Call a no-arg instance method returning Void.
    @discardableResult
    static func call(_ target: NSObject, _ selector: String) -> Bool {
        let sel = NSSelectorFromString(selector)
        guard target.responds(to: sel) else { return false }
        target.perform(sel)
        return true
    }
    
    /// Call a single-arg instance method returning Void.
    @discardableResult
    static func call(_ target: NSObject, _ selector: String, _ arg: Any?) -> Bool {
        let sel = NSSelectorFromString(selector)
        guard target.responds(to: sel) else { return false }
        target.perform(sel, with: arg)
        return true
    }
    
    // MARK: - Object-Returning Instance Calls
    
    /// Call a no-arg instance method returning NSObject?.
    static func callReturning(_ target: NSObject, _ selector: String) -> NSObject? {
        let sel = NSSelectorFromString(selector)
        guard target.responds(to: sel) else { return nil }
        return target.perform(sel)?.takeUnretainedValue() as? NSObject
    }
    
    /// Call a single-arg instance method returning NSObject?.
    static func callReturning(_ target: NSObject, _ selector: String, _ arg: Any?) -> NSObject? {
        let sel = NSSelectorFromString(selector)
        guard target.responds(to: sel) else { return nil }
        return target.perform(sel, with: arg)?.takeUnretainedValue() as? NSObject
    }
    
    // MARK: - Class Calls
    
    /// Call a class method returning NSObject?.
    static func callClass(_ cls: AnyClass, _ selector: String, _ arg: Any? = nil) -> NSObject? {
        let sel = NSSelectorFromString(selector)
        guard cls.responds(to: sel) else { return nil }
        if let arg = arg {
            return (cls as AnyObject).perform(sel, with: arg)?.takeUnretainedValue() as? NSObject
        }
        return (cls as AnyObject).perform(sel)?.takeUnretainedValue() as? NSObject
    }
    
    // MARK: - Typed Function Pointers
    
    /// Get a typed function pointer for an instance method.
    /// Use when you need non-object return types (Float, Bool, struct) or >2 args.
    ///
    /// Usage:
    /// ```
    /// typealias Func = @convention(c) (NSObject, Selector, Float, NSString) -> Void
    /// if let fn = ObjCRuntime.imp(target, "setWeight:forBlendShapeNamed:", as: Func.self) {
    ///     fn(target, ObjCRuntime.sel("setWeight:forBlendShapeNamed:"), 0.5, "jawOpen")
    /// }
    /// ```
    static func imp<F>(_ target: NSObject, _ selector: String, as _: F.Type) -> F? {
        let sel = NSSelectorFromString(selector)
        guard target.responds(to: sel),
              let method = class_getInstanceMethod(type(of: target), sel) else { return nil }
        return unsafeBitCast(method_getImplementation(method), to: F.self)
    }
    
    /// Get a typed function pointer for a class method.
    static func classImp<F>(_ cls: AnyClass, _ selector: String, as _: F.Type) -> F? {
        let sel = NSSelectorFromString(selector)
        guard let meta = object_getClass(cls),
              let method = class_getClassMethod(meta, sel) else { return nil }
        return unsafeBitCast(method_getImplementation(method), to: F.self)
    }
    
    /// Get the Selector value — needed when passing to typed function pointers.
    static func sel(_ name: String) -> Selector {
        NSSelectorFromString(name)
    }
    
    /// Set a Bool property via setter selector. No-ops if selector doesn't exist.
    static func setBool(on target: NSObject, _ selector: String, _ value: Bool) {
        let sel = NSSelectorFromString(selector)
        guard target.responds(to: sel),
              let method = class_getInstanceMethod(type(of: target), sel) else { return }
        let imp = method_getImplementation(method)
        typealias Func = @convention(c) (NSObject, Selector, Bool) -> Void
        unsafeBitCast(imp, to: Func.self)(target, sel, value)
    }
}
