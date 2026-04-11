# AVTAnimoji 逆向分析

> 2026-04-11 使用 fwrev CLI 完整逆向

## 类层次

```
AVTAnimoji : AVTAvatar : NSObject
```

- instanceStart: 8, instanceSize: 64
- AVTAvatar instanceSize: 240

## AVTAnimoji 自有 Ivars (8-64)

| offset | size | name | type |
|--------|------|------|------|
| 8 | 8 | _url | NSURL |
| 16 | 8 | _lightingNode | VFXNode |
| 24 | 8 | _headNode | VFXNode |
| 32 | 8 | _avatarNode | VFXNode |
| 40 | 8 | _cameraNode | VFXNode |
| 48 | 8 | _specializationSettings | NSDictionary |
| 56 | 8 | _name | NSString |

## AVTAvatar 继承 Ivars (8-240)

关键字段：
| offset | size | name | type | 说明 |
|--------|------|------|------|------|
| 64 | 8 | _morphInfoFromARKitBlendShapeIndex | ^{?=@@qB} | 指向 MorphInfo 结构体数组 |
| 72 | 8 | _friendlyPoseMorphInfos | ^{?=@@qB} | 友好姿态 morph 信息 |
| 80 | 8 | _friendlyPoseMorphInfoCount | UInt64 | |
| 160 | 16 | _arOffset | (opaque, simd_float3?) | AR 偏移量 |
| 176 | 4 | _arScale | Float | AR 缩放 |
| 192 | 8 | _lastRenderTime | Double | |
| 232 | 8 | _specializationSettings | NSDictionary | |

## MorphInfo 结构体 (32 bytes)

从 `_applyBlendShapes:parameters:` 反汇编推导：

```
offset  0: morpher (VFXNode*)     — 8 bytes, [x8]
offset  8: (unknown ptr)          — 8 bytes, [x8, #0x8]
offset 16: targetIndex (Int64)    — 8 bytes, [x8, #0x10]
offset 24: isEnabled (Bool)       — 1 byte,  [x8, #0x18]
```

- 循环步长 = 0x20 (32 bytes)，共 0x33 (51) 次迭代
- `_morphInfoFromARKitBlendShapeIndex` 是 MorphInfo[51] 数组
- 每个 ARKit blendshape index 映射到一个 morpher + target index

## 核心调用链

```
updatePoseWithFaceTrackingData:applySmoothing:
  ├── 验证 data.length == 0x1e0 (480)
  ├── 如果 applySmoothing=YES:
  │   ├── CATransaction.begin
  │   ├── setAnimationDuration: (从常量加载)
  │   └── setAnimationTimingFunction: kCAMediaTimingFunctionEaseOut
  ├── _applyBlendShapesWithTrackingData:
  │   └── _applyBlendShapes:parameters:
  │       ├── 先处理 tongueOut parameter (index 0x33=51)
  │       │   └── setWeight:forTargetAtIndex: on morpher
  │       └── 循环 51 个 blendshapes:
  │           ├── 读 smoothBlendshapes[i]
  │           ├── 跳过 -1.0 (未激活)
  │           ├── clamp [0, 1]
  │           ├── AVTBlendShapeLocationFromARIndex(i) → name
  │           ├── AVTMorphWeightApplyCorrectionForTongue(name, weight, tongueParam)
  │           ├── AVTMorphWeightApplyBlinkCorrection(name, weight)
  │           └── morpher.setWeight:forTargetAtIndex:
  ├── _applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:
  │   └── (已分析，见 reverse-engineering-methodology.md)
  └── 如果 applySmoothing=YES:
      └── CATransaction.commit
```

## Blendshape 修正函数

### AVTMorphWeightApplyBlinkCorrection

对 eyeBlinkLeft / eyeBlinkRight 两个 blendshape 做非线性修正：

```
if name == "eyeBlinkLeft" || name == "eyeBlinkRight":
    weight = max(0, weight)
    weight = weight * 1.1             // scale, from __TEXT,__const @ 0x65d90
    weight = min(weight, 1.0)
    weight = pow(weight, 2.0/3.0)     // exponent, from __TEXT,__const @ 0x65d98
    weight = min(weight, 1.0)
```

Constants (Double, little-endian):
- 0x65d90: `9a 99 99 99 99 99 f1 3f` → 1.1
- 0x65d98: `55 55 55 55 55 55 e5 3f` → 0.6666... (2/3)

效果：gamma 曲线让部分眨眼更可见（压缩上半段，展开下半段）

### AVTMorphWeightApplyCorrectionForTongue

对 7 个嘴部 blendshape 做舌头修正（当 tongueOut 参数激活时）：

Affected blendshapes (from nm symbol addresses):
- 0xa5590: _AVTBlendShapeLocationMouthClose
- 0xa5598: _AVTBlendShapeLocationMouthFunnel
- 0xa55a0: _AVTBlendShapeLocationMouthPressLeft
- 0xa55a8: _AVTBlendShapeLocationMouthPressRight
- 0xa55b0: _AVTBlendShapeLocationMouthPucker
- 0xa55b8: _AVTBlendShapeLocationMouthRollLower
- 0xa55c0: _AVTBlendShapeLocationMouthShrugLower

```
if tongueParam != -1.0:
    if name in [mouthClose, mouthFunnel, mouthPucker, mouthPressLeft,
                mouthPressRight, mouthRollLower, mouthShrugLower]:
        correctedWeight = weight * (1.0 - tongueParam)
```

效果：舌头伸出时，嘴部 blendshape 权重按比例衰减，避免穿模

## 加载流程 (_load)

```
_load:
  1. _sceneURL → 获取场景文件 URL
     - 优先用 _url (直接 URL)
     - 否则用 _name → _scenePathForPuppetNamed: → NSURL
  2. VFXWorld.avt_rootNodeForWorldAtURL:options:error:
     → 加载 VFX 场景
  3. childNodeWithName:"lightingNode" recursively:YES
     → 存入 _lightingNode, removeFromParentNode
  4. AVTPrecompiledAnimojiSpecializationSettings[_name]
     → 存入 _specializationSettings
  5. avt_enableSubdivisionOnHierarchyWithQuality:1 animoji:YES
  6. childNodeWithName:"headNode" → _headNode (ivar offset 0x2fc)
  7. childNodeWithName:"cameraNode" → _cameraNode (ivar offset 0x300)
  8. childNodeWithName:"skeleton" → skeleton (ivar offset 0x304)
  9. _avatarNodeAndHeadNodeAreNowAvailable
  10. resetCustomBehaviours
  11. updateBindings
```

## 初始化 (initWithName:error:)

```
initWithName:error:
  1. 验证 name 在 animojiNames 列表中
  2. [super init] (AVTAvatar)
  3. 存 _name (ivar offset 0x2f0)
  4. _scenePathForPuppetNamed: 验证路径存在
  5. 如果路径不存在 → NSError domain + "invalid puppet name"
```

## 可用 Animoji 列表 (28 个)

alien, bear, boar, cat, chicken, cow, default, dog, dragon, fox, ghost, giraffe, koala, lion, monkey, mouse, octopus, owl, panda, pig, poo, rabbit, robot, shark, skull, tiger, trex, unicorn

## 场景文件路径

通过 `AVTResourceLocator.sharedResourceLocator` 定位：
```
pathForAnimojiResource:<name> ofType:nil inDirectory:<name> isDirectory:NO
```

实际路径在 AvatarKit.framework/Resources/ 或 AvatarKitResources.bundle/ 中。

## 关键常量

- blendshape 数量: 51 (0x33)
- tongueOut parameter index: 51 (0x33) — 在 morphInfo 数组之后
- MorphInfo 结构体大小: 32 bytes (0x20)
- tracking data 大小: 480 bytes (0x1e0)
- 未激活标记: -1.0 (float)
- smoothing: CATransaction + kCAMediaTimingFunctionEaseOut
