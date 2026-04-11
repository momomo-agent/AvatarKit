# AvatarKit 逆向覆盖地图

> 总量: 76 AVT类 + 26 VFX类 = 102 核心类, 1403 方法, 5613 符号
> 更新: 2026-04-11

## 状态标记

- ✅ 已逆向并还原为代码（有证据链）
- 🔍 已探索（读过反汇编，理解逻辑）
- 📋 已侦察（知道 ivars/methods，未深入）
- ❌ 未探索

---

## 1. 核心 Avatar (18 类, 最重要)

我们的目标：完整理解 face tracking → blendshape → 渲染 的数据流。

| 类 | 方法数 | 状态 | 已知内容 |
|----|--------|------|----------|
| **AVTAvatar** | 128 | 🔍 | 父类，核心逻辑所在。已逆向: _applyBlendShapes:parameters:, _applyBlendShapesWithTrackingData:, _applyHeadPoseWithTrackingData:gazeCorrection:pointOfView:, updatePoseWithFaceTrackingData:applySmoothing: |
| **AVTAnimoji** | 41 | ✅ | 7 ivars, _load 流程, initWithName:, 28 角色列表。已还原为 AVTAnimoji+Internals.swift |
| **AVTMemoji** | 102 | ❌ | Memoji（自定义形象），比 Animoji 复杂得多。102 个方法，最大的类之一 |
| **AVTFaceTrackingInfo** | 1 | ✅ | 480 字节结构体容器。type encoding 暴露全部字段名。Nigiri category 工厂方法 |
| **AVTAvatarPose** | 32 | ❌ | 姿态数据，可能包含 blendshape + transform 的快照 |
| **AVTAvatarPoseAnimation** | 26 | ❌ | 姿态动画，预设表情动画？ |
| **AVTAvatarPoseAnimationController** | 3 | ❌ | 动画控制器 |
| **AVTAvatarBodyPose** | 11 | ❌ | 身体姿态（上半身） |
| **AVTAvatarEnvironment** | 23 | ❌ | 环境设置（光照？背景？） |
| **AVTAvatarPhysicalizedPose** | 8 | ❌ | 物理化姿态（布料/头发模拟后的结果？） |
| **AVTAvatarPhysicsState** | 3 | ❌ | 物理状态 |
| **AVTAvatarMemoryOptimizer** | 23 | ❌ | 内存优化（LOD？纹理卸载？） |
| **AVTAvatarDescriptor** | 16 | ❌ | Avatar 描述符（序列化？） |
| **AVTAvatarDidUpdateAtTimeCallbackItem** | 1 | ❌ | 回调 |
| **AVTAnimojiDescriptor** | 13 | ❌ | Animoji 描述符 |
| **AVTMemojiDescriptor** | 20 | ❌ | Memoji 描述符 |
| **AVTMemojiBodyController** | 1 | ❌ | Memoji 身体控制 |
| **AVTMemojiWrapDeformerDriverInfo** | 2 | ❌ | Wrap deformer 驱动信息 |

### 已逆向的关键方法 (AVTAvatar)

| 方法 | 状态 | 发现 |
|------|------|------|
| updatePoseWithFaceTrackingData:applySmoothing: | ✅ | 入口。验证 data.length==480, CATransaction smoothing, 调用链 |
| _applyBlendShapesWithTrackingData: | ✅ | trampoline: 提取 blendshapes(+0x34) 和 params(+0x1cc) 指针 |
| _applyBlendShapes:parameters: | ✅ | 核心循环。tongueOut lerp(0.3), 51 blendshape 循环, 修正函数, friendlyPose 重置 |
| _applyHeadPoseWithTrackingData:gazeCorrection:pointOfView: | ✅ | 读 translation/orientation/cameraSpace, 条件减 arOffset |
| applyBlendShapesWithTrackingInfo: | ✅ | 薄 wrapper: trackingInfo.trackingData → _applyBlendShapesWithTrackingData: |
| _load | 🔍 | VFXWorld 加载场景, 提取 lightingNode/headNode/cameraNode/skeleton |
| initWithName:error: | 🔍 | 验证 name 在列表中, 检查场景路径 |

### 已逆向的独立函数

| 函数 | 状态 | 发现 |
|------|------|------|
| AVTMorphWeightApplyBlinkCorrection | ✅ | pow(clamp(w*1.1, 0,1), 2/3)。常量: scale=1.1, exp=2/3 |
| AVTMorphWeightApplyCorrectionForTongue | ✅ | 7 个嘴部 blendshape × (1-tongueParam)。符号地址全部确认 |
| AVTBlendShapeLocationFromARIndex | 📋 | ARKit index → blendshape name 字符串 |

### 已确认的数据结构

| 结构 | 状态 | 发现 |
|------|------|------|
| AVTFaceTrackingData (480 bytes) | ✅ | 完整字段名+偏移+类型。字段名来自 type encoding |
| MorphInfo (32 bytes × 51) | ✅ | morpher + reserved + targetIndex + isEnabled。步长和字段偏移从循环确认 |
| AVTAnimoji ivars (7) | ✅ | url/lightingNode/headNode/avatarNode/cameraNode/specializationSettings/name |
| AVTAvatar ivars (关键) | 🔍 | morphInfoArray(+0x40)/friendlyPoseMorphInfos(+0x48)/count(+0x50)/arOffset/arScale |

---

## 2. 渲染/显示 (15 类)

| 类 | 方法数 | 状态 | 说明 |
|----|--------|------|------|
| **AVTRenderer** | 38 | ❌ | 主渲染器 |
| **AVTView** | 59 | ❌ | 显示视图（UIView 子类？） |
| **AVTCompositor** | 8 | ❌ | 合成器 |
| **AVTCompositorPipeline** | 3 | ❌ | 渲染管线 |
| **AVTCompositorPipelineCache** | 4 | ❌ | 管线缓存 |
| **AVTCompositorTextureProvider** | 7 | ❌ | 纹理提供者 |
| **AVTSnapshotBuilder** | 16 | ❌ | 截图/贴纸生成 |
| **AVTSnapshotHelper** | 7 | ❌ | 截图辅助 |
| **AVTHUDView** | 9 | ❌ | HUD 覆盖层 |
| **AVTMaterial** | 8 | ❌ | 材质 |
| **AVTPresentationConfiguration** | 4 | ❌ | 展示配置 |
| **AVTClassicPresentationConfiguration** | 3 | ❌ | 经典展示配置 |
| **AVTRendererViewTransitionTechnique** | 11 | ❌ | 视图过渡技术 |
| **AVTViewTransitionHelper** | 15 | ❌ | 过渡辅助 |
| **AVTCameraEffectsKitRenderer** | 1 | ❌ | 相机特效渲染 |

---

## 3. Sticker/贴纸系统 (15 类)

| 类 | 方法数 | 状态 | 说明 |
|----|--------|------|------|
| AVTStickerConfiguration | 47 | ❌ | 贴纸配置（最大的贴纸类） |
| AVTStickerProp | 46 | ❌ | 贴纸道具 |
| AVTStickerGenerator | 17 | ❌ | 贴纸生成器 |
| AVTStickerGeneratorOptions | 15 | ❌ | 生成选项 |
| AVTStickerGeneratorPosterOptions | 9 | ❌ | 海报选项 |
| AVTStickerShaderModifier | 20 | ❌ | Shader 修改器 |
| AVTStickerShaderModifierProperty | 12 | ❌ | Shader 属性 |
| AVTStickerCamera | 8 | ❌ | 贴纸相机 |
| AVTStickerMorpherOverride | 8 | ❌ | Morpher 覆盖 |
| AVTStickerPoseAdjustment | 9 | ❌ | 姿态调整 |
| AVTStickerPresetOverride | 7 | ❌ | 预设覆盖 |
| AVTStickerPropAdjustTransformProperty | 8 | ❌ | 变换属性 |
| AVTStickerConfigurationReversionContext | 13 | ❌ | 回退上下文 |
| AVTStickerSceneProp | 6 | ❌ | 场景道具 |
| AVTStickerImageProp | 6 | ❌ | 图片道具 |

---

## 4. 物理/动画 (7 类)

| 类 | 方法数 | 状态 | 说明 |
|----|--------|------|------|
| AVTPhysicsController | 20 | ❌ | 物理控制器（头发/配饰摆动） |
| AVTPhysicsRig | 1 | ❌ | 物理骨架 |
| AVTPhysicalizedSkeletonDynamic | 6 | ❌ | 骨骼动力学 |
| AVTPhysicalizedMorpherDynamic | 6 | ❌ | Morpher 动力学 |
| AVTSpringDynamic | 6 | ❌ | 弹簧动力学 |
| AVTMassSpringDamperSystem | 5 | ❌ | 质量-弹簧-阻尼系统 |
| AVTMorpherDrivenMaterialDescriptor | 1 | ❌ | Morpher 驱动材质 |

---

## 5. 资源/预设 (13 类)

| 类 | 方法数 | 状态 | 说明 |
|----|--------|------|------|
| AVTResourceLocator | 24 | ❌ | 资源定位器（场景文件路径） |
| AVTAssetLibrary | 5 | ❌ | 资源库 |
| AVTAsset | 23 | ❌ | 资源 |
| AVTAssetResourceCache | 7 | ❌ | 资源缓存 |
| AVTPresetStore | 12 | ❌ | 预设存储 |
| AVTPreset | 25 | ❌ | 预设 |
| AVTPresetDependency | 6 | ❌ | 预设依赖 |
| AVTPresetStoreDependency | 7 | ❌ | 存储依赖 |
| AVTPresetStoreDependencyCondition | 6 | ❌ | 依赖条件 |
| AVTColorPreset | 28 | ❌ | 颜色预设 |
| AVTComponent | 13 | ❌ | 组件 |
| AVTComponentInstance | 15 | ❌ | 组件实例 |
| AVTImageUtilities | 5 | ❌ | 图片工具 |

---

## 6. VFX 渲染引擎 (26 类)

SceneKit 的私有封装层。所有 VFX* 类都是 SCN* 的 wrapper 或扩展。

| 类 | 方法数 | 状态 | 说明 |
|----|--------|------|------|
| **VFXWorld** | 18 | 📋 | 场景加载入口。avt_rootNodeForWorldAtURL:options:error: |
| **VFXNode** | 13 | 📋 | 节点。childNodeWithName:recursively: |
| **VFXMorpher** | 8 | 📋 | Morpher。setWeight:forTargetAtIndex:, weightForTargetAtIndex: |
| **VFXSkinner** | 16 | ❌ | 蒙皮 |
| VFXView | 3 | ❌ | 视图 |
| VFXRenderer | 2 | ❌ | 渲染器 |
| VFXCamera | 10 | ❌ | 相机 |
| VFXAnimation/Event/Player | 3 | ❌ | 动画系统 |
| VFXMesh/MeshSource | 2 | ❌ | 网格 |
| VFXMaterialProperty | 2 | ❌ | 材质属性 |
| VFXModelWrapDeformer | 1 | ❌ | Wrap 变形器 |
| VFXModelTessellator | 1 | ❌ | 细分曲面 |
| VFXParametricModel | 1 | ❌ | 参数化模型 |
| VFXPhysics* | 3 | ❌ | 物理 |
| VFXTransaction | 1 | ❌ | 事务 |
| VFXKeyed* | 2 | ❌ | 序列化 |
| *_CEKWorkaround | 3 | ❌ | Camera Effects Kit 兼容 |

---

## 覆盖率总结

| 域 | 类数 | ✅ 已还原 | 🔍 已探索 | 📋 已侦察 | ❌ 未探索 |
|----|------|-----------|-----------|-----------|-----------|
| 核心 Avatar | 18 | 2 | 1 | 0 | 15 |
| 渲染/显示 | 15 | 0 | 0 | 0 | 15 |
| Sticker | 15 | 0 | 0 | 0 | 15 |
| 物理/动画 | 7 | 0 | 0 | 0 | 7 |
| 资源/预设 | 13 | 0 | 0 | 0 | 13 |
| VFX 引擎 | 26 | 0 | 0 | 3 | 23 |
| **合计** | **94** | **2** | **1** | **3** | **88** |

**覆盖率: 6/94 类有实质理解 (6.4%)**

### 但——我们覆盖了最关键的数据流

```
ARKit FaceAnchor
    ↓ blendshapes + transform
buildTrackingInfo()                    ← ✅ 我们写的
    ↓ 480 bytes
AVTFaceTrackingInfo                    ← ✅ 完全理解
    ↓ trackingData pointer
updatePoseWithFaceTrackingData:        ← ✅ 完全理解
    ↓
_applyBlendShapes:parameters:          ← ✅ 完全理解
    ├── tongueOut lerp(0.3)            ← ✅
    ├── 51× blendshape loop            ← ✅
    ├── BlinkCorrection                ← ✅ 常量确认
    ├── TongueCorrection               ← ✅ 7个符号确认
    └── friendlyPose reset             ← ✅
    ↓
_applyHeadPose:gazeCorrection:pointOfView: ← ✅ 完全理解
    ↓
VFXMorpher.setWeight:forTargetAtIndex: ← 📋 接口已知
VFXNode.position/orientation           ← 📋 接口已知
    ↓
SceneKit 渲染                          ← (系统框架)
```

### 下一步优先级

1. **AVTMemoji** (102 方法) — Memoji 比 Animoji 复杂得多，自定义形象的加载/配置
2. **AVTAvatarPose** (32 方法) — 姿态数据结构，预设表情的基础
3. **AVTRenderer** (38 方法) — 渲染管线，理解输出端
4. **AVTPhysicsController** (20 方法) — 头发/配饰物理模拟
5. **AVTResourceLocator** (24 方法) — 场景文件定位，理解资源结构
6. **VFXMorpher** (8 方法) — morph target 的底层实现
