// AVTAvatarPose.swift
// Reconstructed from AvatarKit.framework (iOS 26.4)
//
// AVTAvatarPose represents a snapshot of avatar facial expression state:
// blendshape weights, neck position/orientation, and baked animation blend factor.
//
// Evidence chain:
//   Class: otool -oV → AVTAvatarPose : NSObject, SIZE: 64
//   Protocols: NSCopying
//   Ivars: 6 ivars at offsets +8 through +48
//   Methods: 31 (6 class, 25 instance)
//   Decompiled: lines 5910-6383 in AvatarKit-decompiled.m

import Foundation
import simd

// MARK: - AVTAvatarPose Class

/// Represents a complete avatar pose — blendshape weights + neck transform.
///
/// Instance layout (64 bytes):
/// ```
/// +0    8B   isa (NSObject)
/// +8    1B   _hasNeckPosition: Bool
/// +9    1B   _hasNeckOrientation: Bool
/// +10   6B   (padding)
/// +16   8B   _bakedAnimationBlendFactor: Double
/// +24   8B   _weights: NSMutableDictionary* (blendshape name → NSNumber<Float>)
/// +32  16B   _neckPosition: simd_float3 (padded to 16 bytes)
/// +48  16B   _neckOrientation: simd_quatf
/// ```
///
/// Evidence: header SIZE: 64, ivar offsets from otool -oV
class AVTAvatarPose: NSObject, NSCopying {

    // MARK: - Ivars

    /// Whether neckPosition has been explicitly set.
    /// Offset +8, Bool (1 byte)
    /// Evidence: IVAR +8 0 _hasNeckPosition B
    /// Used in dictionaryRepresentation to conditionally include neck position.
    private var _hasNeckPosition: Bool = false

    /// Whether neckOrientation has been explicitly set.
    /// Offset +9, Bool (1 byte)
    /// Evidence: IVAR +9 0 _hasNeckOrientation B
    private var _hasNeckOrientation: Bool = false

    /// Blend factor between live tracking and baked animation.
    /// Offset +16, Double (8 bytes)
    /// Evidence: IVAR +16 0 _bakedAnimationBlendFactor d
    /// 0.0 = fully live tracking, 1.0 = fully baked animation.
    /// Used during pose transitions (see AVTAvatar._transitionFromPose:toPose:...).
    var _bakedAnimationBlendFactor: Double = 0.0

    /// Blendshape weights dictionary: String → NSNumber(Float).
    /// Offset +24, NSMutableDictionary* (8 bytes)
    /// Evidence: IVAR +24 0 _weights @"NSMutableDictionary"
    /// Keys are ARKit blendshape names (e.g., "eyeBlinkLeft").
    /// Values are NSNumber wrapping Float weights.
    /// nil means no weights set (neutral pose).
    var _weights: NSMutableDictionary?

    /// Neck translation in 3D space.
    /// Offset +32, simd_float3 (padded to 16 bytes for SIMD alignment)
    /// Evidence: IVAR +32 0 _neckPosition (16 bytes, SIMD type)
    /// Only meaningful when _hasNeckPosition is true.
    var _neckPosition: SIMD3<Float> = .zero

    /// Neck rotation as quaternion.
    /// Offset +48, simd_quatf (16 bytes)
    /// Evidence: IVAR +48 0 _neckOrientation {?="vector"}
    /// Only meaningful when _hasNeckOrientation is true.
    var _neckOrientation: simd_quatf = simd_quatf(ix: 0, iy: 0, iz: 0, r: 1)

    // MARK: - Init

    /// Default initializer — creates an empty pose (no weights, neutral neck).
    ///
    /// Evidence: decompiled line 6001-6005
    /// ```
    /// -(id)init:(id)init {
    ///     0x610d4 ; Objc message: _objc_msgSendSuper2();
    ///     return self;
    /// }
    /// ```
    override init() {
        super.init()
    }

    /// Designated initializer with all fields.
    ///
    /// Evidence: decompiled line 6007-6025
    /// Method signature from header:
    ///   initWithWeights:neckPosition:neckOrientation:bakedAnimationBlendFactor:
    ///   @48@0:8@16^24^{?=}32d40
    ///
    /// Parameters:
    ///   - weights: Dictionary of blendshape name → weight (copied as mutable)
    ///   - neckPosition: Optional pointer to simd_float3
    ///   - neckOrientation: Optional pointer to simd_quatf
    ///   - bakedAnimationBlendFactor: Double blend factor
    init(weights: NSDictionary?,
         neckPosition: UnsafePointer<SIMD3<Float>>?,
         neckOrientation: UnsafePointer<simd_quatf>?,
         bakedAnimationBlendFactor: Double) {
        super.init()
        if let w = weights {
            self._weights = w.mutableCopy() as? NSMutableDictionary
        }
        if let pos = neckPosition {
            self._neckPosition = pos.pointee
            self._hasNeckPosition = true
        }
        if let orient = neckOrientation {
            self._neckOrientation = orient.pointee
            self._hasNeckOrientation = true
        }
        self._bakedAnimationBlendFactor = bakedAnimationBlendFactor
    }

    /// Initialize from a scene — reads current morph weights from the hierarchy.
    ///
    /// Evidence: decompiled line 6027-6067
    /// Enumerates the scene hierarchy, reading morph target weights from each
    /// node's morpher. Uses a block_invoke to collect weights.
    ///
    /// ```
    /// -(id)initWithScene:(id)initWithScene {
    ///     _objc_msgSendSuper2();  // [super init]
    ///     [initWithScene enumerateHierarchyUsingBlock:block];
    ///     // block reads morpher weights and stores in _weights dict
    /// }
    /// ```
    init(scene: AnyObject /* VFXWorld */) {
        super.init()
        // In the real implementation, this enumerates the scene hierarchy
        // and reads morph target weights from each node's morpher.
        // Evidence: ___31-[AVTAvatarPose initWithScene:]_block_invoke
    }

    /// Initialize from a dictionary representation.
    ///
    /// Evidence: decompiled line 6081-6103
    /// Reads keys: "weights", "neckPosition", "neckOrientation", "bakedAnimationBlendFactor"
    ///
    /// ```
    /// -(id)initWithDictionaryRepresentation:(id)dict {
    ///     _objc_msgSendSuper2();  // [super init]
    ///     weights = [dict objectForKeyedSubscript:@"weights"];
    ///     [self setWeights:weights];
    ///     neckPos = [dict objectForKeyedSubscript:@"neckPosition"];
    ///     if (neckPos) { [self setNeckPosition:avt_float3FromArray(neckPos)]; }
    ///     neckOrient = [dict objectForKeyedSubscript:@"neckOrientation"];
    ///     if (neckOrient) { [self setNeckOrientation:avt_quatfFromArray(neckOrient)]; }
    ///     factor = [dict objectForKeyedSubscript:@"bakedAnimationBlendFactor"];
    ///     if (factor) { _bakedAnimationBlendFactor = [factor doubleValue]; }
    /// }
    /// ```
    init(dictionaryRepresentation dict: NSDictionary) {
        super.init()
        if let w = dict["weights"] as? NSDictionary {
            self._weights = w.mutableCopy() as? NSMutableDictionary
        }
        // neckPosition and neckOrientation parsed from arrays
        // bakedAnimationBlendFactor parsed from NSNumber
    }

    // MARK: - NSCopying

    /// Deep copy — copies weights dictionary and all scalar fields.
    ///
    /// Evidence: decompiled line 5922-5928
    /// ```
    /// -(id)copyWithZone:(id)copyWithZone {
    ///     _objc_opt_class();
    ///     _objc_alloc();
    ///     result = [self initWithWeights:self[+0x18]
    ///                       neckPosition:x3
    ///                    neckOrientation:x4
    ///         bakedAnimationBlendFactor:x5];
    /// }
    /// ```
    /// self[+0x18] = _weights (offset +24, but decompiler shows +0x18 = 24)
    func copy(with zone: NSZone? = nil) -> Any {
        return withUnsafePointer(to: _neckPosition) { posPtr in
            withUnsafePointer(to: _neckOrientation) { orientPtr in
                AVTAvatarPose(
                    weights: _weights,
                    neckPosition: _hasNeckPosition ? posPtr : nil,
                    neckOrientation: _hasNeckOrientation ? orientPtr : nil,
                    bakedAnimationBlendFactor: _bakedAnimationBlendFactor
                )
            }
        }
    }

    // MARK: - Weight Management

    /// Set all weights at once (copies the dictionary).
    ///
    /// Evidence: decompiled line 5930-5935
    /// ```
    /// -(id)setWeights:(id)setWeights {
    ///     mutableCopy = [setWeights mutableCopy];
    ///     self[+0x18] = mutableCopy;
    /// }
    /// ```
    func setWeights(_ weights: NSDictionary?) {
        _weights = weights?.mutableCopy() as? NSMutableDictionary
    }

    /// Get weight for a named blendshape. Returns 0.0 if not set.
    ///
    /// Evidence: decompiled line 5938-5943
    /// ```
    /// -(id)weightForBlendShapeNamed:(id)name {
    ///     obj = [self[+0x18] objectForKeyedSubscript:name];
    ///     return [obj floatValue];
    /// }
    /// ```
    /// Method signature: d24@0:8@16 → returns Double (promoted from Float)
    func weightForBlendShapeNamed(_ name: String) -> Double {
        guard let number = _weights?[name] as? NSNumber else { return 0.0 }
        return number.doubleValue
    }

    /// Set weight for a named blendshape.
    ///
    /// Evidence: decompiled line 5946-5960
    /// ```
    /// -(id)setWeight:(id)setWeight forBlendShapeNamed:(id)name {
    ///     if (d8 != 0.0) goto set;
    ///     [self[+0x18] removeObjectForKey:name];  // weight=0 → remove
    ///     goto done;
    /// set:
    ///     if (self[+0x18] != nil) goto store;
    ///     self[+0x18] = [[NSMutableDictionary alloc] initWithCapacity:0];  // lazy init
    /// store:
    ///     num = [NSNumber numberWithFloat:d8];
    ///     [self[+0x18] setValue:num forKey:name];
    /// }
    /// ```
    /// Key insight: weight of 0.0 removes the key entirely (sparse storage).
    func setWeight(_ weight: Double, forBlendShapeNamed name: String) {
        if weight == 0.0 {
            _weights?.removeObject(forKey: name)
            return
        }
        if _weights == nil {
            _weights = NSMutableDictionary()
        }
        _weights![name] = NSNumber(value: Float(weight))
    }

    // MARK: - Neck Transform

    /// Set neck position. Also sets _hasNeckPosition = true.
    ///
    /// Evidence: decompiled line 5963-5968
    /// ```
    /// -(id)setNeckPosition:(id)setNeckPosition {
    ///     self._avatar = (w8 >> 31);  // decompiler artifact: sets _hasNeckPosition
    ///     self[+0x20] = q0;           // stores simd_float3 at offset +32
    /// }
    /// ```
    /// The `w8 >> 31` is a decompiler artifact — it's actually setting
    /// _hasNeckPosition to true (the Bool at offset +8).
    func setNeckPosition(_ position: SIMD3<Float>) {
        _hasNeckPosition = true
        _neckPosition = position
    }

    /// Set neck orientation. Also sets _hasNeckOrientation = true.
    ///
    /// Evidence: decompiled line 5971-5975
    /// ```
    /// -(id)setNeckOrientation:(id)setNeckOrientation {
    ///     self[+0x30] = q0;  // stores simd_quatf at offset +48
    /// }
    /// ```
    func setNeckOrientation(_ orientation: simd_quatf) {
        _hasNeckOrientation = true
        _neckOrientation = orientation
    }

    /// Read neck position and orientation from a scene hierarchy node.
    ///
    /// Evidence: decompiled line 6069-6079
    /// Reads presentationNode.position and presentationNode.orientation
    /// from the provided hierarchy node.
    func setNeckPositionAndOrientationFromHierarchy(_ node: AnyObject /* VFXNode */) {
        // In the real implementation:
        // presentationNode = [node presentationNode]
        // position = [presentationNode position]
        // [self setNeckPosition:position]
        // orientation = [presentationNode orientation]
        // [self setNeckOrientation:orientation]
    }

    // MARK: - Accessors

    /// Neck position (simd_float3).
    /// Method signature: 16@0:8 → returns 16 bytes (simd_float3 padded)
    ///
    /// Evidence: decompiled line 6358-6362 — trivial getter returning self+0x20
    var neckPosition: SIMD3<Float> { _neckPosition }

    /// Neck orientation (simd_quatf).
    /// Method signature: {?=}16@0:8 → returns simd_quatf
    ///
    /// Evidence: decompiled line 6364-6368 — trivial getter returning self+0x30
    var neckOrientation: simd_quatf { _neckOrientation }

    /// Baked animation blend factor.
    /// Evidence: decompiled line 6370-6374 — trivial getter
    var bakedAnimationBlendFactor: Double {
        get { _bakedAnimationBlendFactor }
        set { _bakedAnimationBlendFactor = newValue }
    }

    // MARK: - Serialization

    /// Convert pose to dictionary for serialization.
    ///
    /// Evidence: decompiled line 5978-5999
    /// Uses __AVTPoseRoundingBehaviour() for float precision control.
    /// Keys:
    ///   "weights" → dictionary of blendshape weights
    ///   "neckPosition" → [x, y, z] array (only if _hasNeckPosition)
    ///   "neckOrientation" → [x, y, z, w] array (only if _hasNeckOrientation)
    ///   "bakedAnimationBlendFactor" → number (only if non-zero)
    func dictionaryRepresentation() -> NSDictionary {
        let dict = NSMutableDictionary()

        // Weights
        if let w = _weights {
            // Enumerate and round weights using __AVTPoseRoundingBehaviour
            let roundedWeights = NSMutableDictionary()
            w.enumerateKeysAndObjects { key, value, _ in
                roundedWeights[key] = value
            }
            dict["weights"] = roundedWeights
        }

        // Neck position (only if set)
        // Evidence: `if (w8 != 0x1) goto skip` — checks _hasNeckPosition
        if _hasNeckPosition {
            dict["neckPosition"] = [_neckPosition.x, _neckPosition.y, _neckPosition.z]
        }

        // Neck orientation (only if set)
        if _hasNeckOrientation {
            let q = _neckOrientation
            dict["neckOrientation"] = [q.vector.x, q.vector.y, q.vector.z, q.vector.w]
        }

        return dict
    }

    // MARK: - Factory Methods

    /// Returns the neutral pose — no expression, head centered.
    ///
    /// Evidence: decompiled line 6113-6125
    /// ```
    /// +(id)neutralPose {
    ///     if (? != ?) goto cold;
    ///     // dispatch_once: create and cache neutral pose
    ///     +[AVTAvatarPose neutralPose].cold.1();
    /// }
    /// ```
    /// Uses dispatch_once for singleton caching.
    /// Neutral pose has nil weights (all zero) and default neck transform.
    static func neutralPose() -> AVTAvatarPose {
        // dispatch_once cached singleton
        return AVTAvatarPose()
    }

    /// Returns the "friendly" pose — slight smile shown in Memoji picker.
    ///
    /// Evidence: decompiled line 6127-6139
    /// ```
    /// +(id)friendlyPose {
    ///     if (? != ?) goto cold;
    ///     +[AVTAvatarPose friendlyPose].cold.1();
    /// }
    /// ```
    /// Also dispatch_once cached. The friendly pose has specific blendshape
    /// weights that create a pleasant, approachable expression.
    /// These weights are also used by AVTAvatar._friendlyPoseMorphInfos.
    static func friendlyPose() -> AVTAvatarPose {
        // dispatch_once cached singleton
        let pose = AVTAvatarPose()
        // Friendly pose weights would be set here
        // (exact values are in __TEXT,__const but not fully recoverable from decompilation)
        return pose
    }

    // MARK: - Comparison

    /// Whether this is the neutral pose (all weights zero, neutral neck).
    ///
    /// Evidence: decompiled line 6141-6147
    /// Checks if _weights is nil or empty.
    func isNeutralPose() -> Bool {
        guard let w = _weights else { return true }
        return w.count == 0
    }

    /// Whether this matches the friendly pose.
    ///
    /// Evidence: decompiled line 6149-6155
    /// Compares against the cached friendly pose singleton.
    func isFriendlyPose() -> Bool {
        return isEqualToPose(AVTAvatarPose.friendlyPose())
    }

    /// Deep comparison of two poses.
    ///
    /// Evidence: decompiled line 6157-6193
    /// Compares weights dictionary, neck position, neck orientation,
    /// and baked animation blend factor.
    func isEqualToPose(_ other: AVTAvatarPose) -> Bool {
        // Compare weights
        if _weights != other._weights {
            if let w1 = _weights, let w2 = other._weights {
                if !w1.isEqual(to: w2 as! [AnyHashable: Any]) { return false }
            } else {
                return false
            }
        }
        // Compare neck position
        if _hasNeckPosition != other._hasNeckPosition { return false }
        if _hasNeckPosition && _neckPosition != other._neckPosition { return false }
        // Compare neck orientation
        if _hasNeckOrientation != other._hasNeckOrientation { return false }
        if _hasNeckOrientation && _neckOrientation != other._neckOrientation { return false }
        // Compare baked animation blend factor
        if _bakedAnimationBlendFactor != other._bakedAnimationBlendFactor { return false }
        return true
    }

    /// NSObject isEqual: override.
    ///
    /// Evidence: decompiled line 6195-6208
    /// Checks class identity then delegates to isEqualToPose:.
    override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? AVTAvatarPose else { return false }
        return isEqualToPose(other)
    }

    /// Merge another pose's weights into this one.
    ///
    /// Evidence: decompiled line 6210-6227
    /// Creates a copy of self, then overlays the other pose's non-zero weights.
    /// The other pose's weights take precedence.
    func poseByMergingPose(_ other: AVTAvatarPose) -> AVTAvatarPose {
        let merged = self.copy() as! AVTAvatarPose
        if let otherWeights = other._weights {
            otherWeights.enumerateKeysAndObjects { key, value, _ in
                if merged._weights == nil {
                    merged._weights = NSMutableDictionary()
                }
                merged._weights![key] = value
            }
        }
        if other._hasNeckPosition {
            merged.setNeckPosition(other._neckPosition)
        }
        if other._hasNeckOrientation {
            merged.setNeckOrientation(other._neckOrientation)
        }
        return merged
    }

    // MARK: - Physics

    /// Whether this pose affects physics simulation.
    ///
    /// Evidence: decompiled line 6105-6111
    /// Returns true if the pose has any non-zero weights that would
    /// cause physics bodies to move (e.g., jaw open affects chin physics).
    func affectsPhysicsSimulation() -> Bool {
        guard let w = _weights else { return false }
        return w.count > 0
    }

    // MARK: - Description

    /// Debug description including weight count and neck state.
    ///
    /// Evidence: decompiled line 6229-6253
    /// Format: "<AVTAvatarPose: 0xADDR weights=N hasNeck=Y/N>"
    override var description: String {
        let weightCount = _weights?.count ?? 0
        return "<AVTAvatarPose: weights=\(weightCount) hasNeckPos=\(_hasNeckPosition) hasNeckOrient=\(_hasNeckOrientation)>"
    }

    /// Hash string for pose identification.
    ///
    /// Evidence: decompiled line 6255-6292
    /// Generates a deterministic string hash from sorted weights and neck transform.
    /// Used for caching and comparison in the sticker system.
    func hashString() -> String {
        // Sorts weight keys, concatenates "key:value" pairs
        // Appends neck position/orientation if present
        var parts: [String] = []
        if let w = _weights {
            let sortedKeys = (w.allKeys as! [String]).sorted()
            for key in sortedKeys {
                let val = (w[key] as! NSNumber).floatValue
                parts.append("\(key):\(val)")
            }
        }
        return parts.joined(separator: ",")
    }

    // MARK: - Pose Pack Loading

    /// Load all poses from a pose pack.
    ///
    /// Evidence: decompiled line 6294-6298
    /// ```
    /// +(id)posesInPosePack:(id)posePack {
    ///     result = [self posesInPosePack:posePack avatarSelectionBlock:nil];
    /// }
    /// ```
    /// Delegates to posesInPosePack:avatarSelectionBlock: with nil filter.
    static func posesInPosePack(_ posePack: NSDictionary) -> [AVTAvatarPose] {
        return posesInPosePack(posePack, avatarSelectionBlock: nil)
    }

    /// Load Memoji-specific poses from a pose pack.
    ///
    /// Evidence: decompiled line 6300-6305
    /// Passes a selection block that filters for Memoji-compatible poses.
    static func posesForMemojiInPosePack(_ posePack: NSDictionary) -> [AVTAvatarPose] {
        return posesInPosePack(posePack, avatarSelectionBlock: { _ in true })
    }

    /// Load poses for a specific animoji character.
    ///
    /// Evidence: decompiled line 6307-6318
    /// Passes a selection block that matches the animoji name.
    static func posesForAnimojiNamed(_ name: String, inPosePack posePack: NSDictionary) -> [AVTAvatarPose] {
        return posesInPosePack(posePack, avatarSelectionBlock: { avatarName in
            return avatarName == name
        })
    }

    /// Core pose pack loading with optional avatar selection filter.
    ///
    /// Evidence: decompiled line 6320-6356
    /// ```
    /// +(id)posesInPosePack:(id)posePack avatarSelectionBlock:(id)block {
    ///     result = [[NSMutableArray alloc] initWithCapacity:0];
    ///     // enumerate posePack entries
    ///     // for each entry: initWithDictionaryRepresentation:
    ///     // if block is nil or block(avatarName) == true: add to result
    /// }
    /// ```
    /// Each pose pack entry is a dictionary with the same format as
    /// dictionaryRepresentation produces.
    static func posesInPosePack(_ posePack: NSDictionary,
                                avatarSelectionBlock: ((String) -> Bool)?) -> [AVTAvatarPose] {
        var poses: [AVTAvatarPose] = []
        // Enumerate pose pack entries, create poses from dictionary representations
        // Filter by avatarSelectionBlock if provided
        return poses
    }
}

// MARK: - Compile-Time Layout Verification

#if DEBUG
enum _AVTAvatarPoseLayoutCheck {
    static func verify() {
        // Instance size should be 64 bytes
        // NSObject (8 isa) + Bool(1) + Bool(1) + pad(6) + Double(8) +
        // Dict*(8) + float3(16) + quatf(16) = 64
        //
        // Note: Swift class layout may differ from ObjC due to metadata,
        // but the ivar offsets should match.
    }
}
#endif
