
=== CLASS AVTAvatar ===
SUPER: NSObject
SIZE: 240
PROTOCOLS: AVTPhysicsControllerDelegate NSCopying NSSecureCoding
IVAR +8 0 _avatarNode @"VFXNode"
IVAR +16 0 _skeleton @"VFXNode"
IVAR +24 0 _headNode @"VFXNode"
IVAR +32 0 _leftEye @"VFXNode"
IVAR +40 0 _rightEye @"VFXNode"
IVAR +48 0 _neckNode @"VFXNode"
IVAR +56 0 _rootJointNode @"VFXNode"
IVAR +64 0 _morphInfoFromARKitBlendShapeIndex ^{?=@@qB}
IVAR +72 0 _friendlyPoseMorphInfos ^{?=@@qB}
IVAR +80 0 _friendlyPoseMorphInfoCount Q
IVAR +88 0 _friendlyPoseMorphInfoProxy {?="morphWeight"f"isEnabled"B}
IVAR +96 0 _presentationConfiguration @"AVTPresentationConfiguration"
IVAR +104 0 _portalPresentationConfigurationNode @"VFXNode"
IVAR +112 0 _transitionCount i
IVAR +116 0 _optimizedForSnapshot B
IVAR +120 0 _physicsController @"AVTPhysicsController"
IVAR +128 0 _dynamics @"NSMutableArray"
IVAR +136 0 _morpherDrivenMaterialDescriptors @"NSMutableArray"
IVAR +144 0 _pupilReflectionCorrectionDescriptor @"AVTPupilReflectionCorrectionDescriptor"
IVAR +152 0 _eyeSkinningDescriptor @"AVTEyeSkinningDescriptor"
IVAR +160 0 _arOffset 
IVAR +176 0 _arScale f
IVAR +184 0 _physicsScaleFactor d
IVAR +192 0 _lastRenderTime d
IVAR +200 0 _bakedAnimation @"CAAnimation"
IVAR +208 0 _bakedAnimationPlayer_lazy @"VFXAnimationPlayer"
IVAR +216 0 _didUpdateAtTimeLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +224 0 _didUpdateAtTimeCallbackItems @"NSMutableArray"
IVAR +232 0 _specializationSettings @"NSDictionary"
CMETHOD supportsSecureCoding B16@0:8
CMETHOD applyGazeCorrectionWithInputAngle:translation: {?=}48@0:8{?=}1632
CMETHOD avatarWithDataRepresentation:error: @32@0:8@16^@24
CMETHOD avatarWithDataRepresentation:usageIntent:error: @40@0:8@16Q24^@32
CMETHOD avatarWithDescriptor:usageIntent:error: @40@0:8@16Q24^@32
CMETHOD canLoadDataRepresentation: B24@0:8@16
CMETHOD preloadAvatar: v24@0:8@16
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD dataRepresentation @16@0:8
METHOD opacity f16@0:8
METHOD pose @16@0:8
METHOD setOpacity: v20@0:8f16
METHOD update v16@0:8
METHOD isTransitioning B16@0:8
METHOD snapshotWithSize:scale:options: @48@0:8{CGSize=dd}16d32@40
METHOD setPose: v24@0:8@16
METHOD updateWithOptions: v24@0:8Q16
METHOD renderer:didApplyAnimationsAtTime: v32@0:8@16d24
METHOD physicsState @16@0:8
METHOD transitionFromPose:toPose:duration:delay:completionHandler: v56@0:8@16@24d32d40@?48
METHOD addDidUpdateAfterAnimationsEvaluatedAtTimeCallbackForKey:block: v32@0:8@16@?24
METHOD setBakedAnimationReferenceTime: v24@0:8d16
METHOD _addNodesMatchingStickerPattern:inHierarchy:toArray:options: v48@0:8@16@24@32Q40
METHOD arScale f16@0:8
METHOD avatarNodeForPhysicsController: @24@0:8@16
METHOD _applyBlendShapes:parameters: v32@0:8r^f16r^f24
METHOD _applyBlendShapesWithTrackingData: v24@0:8r^{?=dB[51f][51f][1f][1f]}16
METHOD _applyHeadPoseWithTrackingData:gazeCorrection:pointOfView: v36@0:8r^{?=dB[51f][51f][1f][1f]}16B24@28
METHOD _avatarNodeAndHeadNodeAreNowAvailable v16@0:8
METHOD _cachePresentationConfigurationShaderModifiersForMaterial:cacheKey:shaderModifiersBuilder: @40@0:8@16@24@?32
METHOD _objectsInDescriptors:andHierarchy:passingTest: @40@0:8@16@24@?32
METHOD _preparePrePass: v20@0:8B16
METHOD _resetFaceToRandomPosition v16@0:8
METHOD _restoreOriginalShaderModifiersOfMaterial: v24@0:8@16
METHOD _transitionFromPose:toPose:bakedAnimationBlendFactor:duration:delay:timingFunction:timingAnimation:completionHandler: v80@0:8@16@24d32d40d48@56@64@?72
METHOD _updateARModeShaderModifiersForMaterial:withOnTopMask: v28@0:8@16B24
METHOD addCustomBehavioursInHierarchy:forBodyParts: v32@0:8@16Q24
METHOD addDerivedNodesMatchingStickerPattern:toArray:options: v40@0:8@16@24Q32
METHOD addDynamicsInHierarchy:ignoringUpperNodes: v32@0:8@16@24
METHOD addMorpherDrivenMaterialsInHierarchy: v24@0:8@16
METHOD addMorphingSkinningControllersInHierarchy: v24@0:8@16
METHOD animatePhysicsScaleFactor:duration: v32@0:8d16d24
METHOD applyBlendShapesWithTrackingInfo: v24@0:8@16
METHOD applyHeadPoseWithTrackingInfo: v24@0:8@16
METHOD applyHeadPoseWithTrackingInfo:gazeCorrection: v28@0:8@16B24
METHOD applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView: v36@0:8@16B24@28
METHOD arMode B16@0:8
METHOD arOffset 16@0:8
METHOD avatarCommonInit v16@0:8
METHOD avatarNode @16@0:8
METHOD avatarSpecificTechniqueClass #16@0:8
METHOD bakedAnimationCopy @16@0:8
METHOD bakedAnimationPlayer @16@0:8
METHOD blendShapeIndexForARKitBlendShapeName: q24@0:8@16
METHOD blendShapeNameForARKitBlendShapeIndex: @24@0:8Q16
METHOD cameraNode @16@0:8
METHOD configureForBestAnimationQuality v16@0:8
METHOD copyWithUsageIntent: @24@0:8Q16
METHOD debugPoseJSONRepresentation @16@0:8
METHOD didAddToScene: v24@0:8@16
METHOD disabledBlendshapesSpecializationSettingsDidChange v16@0:8
METHOD effectiveMorphedNodeForTargetName: @24@0:8@16
METHOD enumerateMorphInfoForCustomBlendShapeName:usingBlock: v32@0:8@16@?24
METHOD evaluateDynamicsAtTime: v24@0:8d16
METHOD headNode @16@0:8
METHOD lightingNode @16@0:8
METHOD morphInfoForARKitBlendShapeIndex: {?=@@qB}24@0:8Q16
METHOD neckNode @16@0:8
METHOD newAvatarSpecificTechniqueWithRenderer: @24@0:8@16
METHOD newDescriptor @16@0:8
METHOD nodesMatchingStickerPattern:inHierarchy:options:includingDerivedNodes: @44@0:8@16@24Q32B40
METHOD optimizeForSnapshot B16@0:8
METHOD pauseBakedAnimation v16@0:8
METHOD physicsController:downforceForNodeNamed: d32@0:8@16@24
METHOD physicsDownforceForNodeNamed: d24@0:8@16
METHOD physicsSpecializationSettingsDidChange v16@0:8
METHOD removeCustomBehavioursInHierarchy:forBodyParts: v32@0:8@16Q24
METHOD removeDidUpdateAfterAnimationsEvaluatedAtTimeCallbackForKey: v24@0:8@16
METHOD removeDynamicsInHierarchy: v24@0:8@16
METHOD removeMorpherDrivenMaterialsInHierarchy: v24@0:8@16
METHOD removeMorphingSkinningControllersInHierarchy: v24@0:8@16
METHOD removePresentationConfigurationBehavioursInHierarchy:forBodyParts: v32@0:8@16Q24
METHOD resetCustomBehaviours v16@0:8
METHOD resetDynamics v16@0:8
METHOD resetMorpherDrivenMaterials v16@0:8
METHOD resetMorphingSkinningControllers v16@0:8
METHOD resetPresentationConfigurationBehavioursInHierarchy:forBodyParts: v32@0:8@16Q24
METHOD resetToPhysicsState:assumeRestStateIfNil: v28@0:8@16B24
METHOD resumeBakedAnimation v16@0:8
METHOD rootJointNode @16@0:8
METHOD setArMode: v20@0:8B16
METHOD setOptimizeForSnapshot: v20@0:8B16
METHOD setPhysicsScaleFactor: v24@0:8d16
METHOD setPresentationConfiguration: v24@0:8@16
METHOD setupEyeOrientationAndReflections v16@0:8
METHOD setupMorphInfo v16@0:8
METHOD setupMorphInfoForChangeInSubHierarchy v16@0:8
METHOD specializationSettings @16@0:8
METHOD stickerPhysicsStateIdentifier @16@0:8
METHOD stopTransitionAnimation v16@0:8
METHOD stopTransitionAnimationWithBlendOutDuration: v24@0:8d16
METHOD transitionFromPose:duration:delay:completionHandler: v48@0:8@16d24d32@?40
METHOD transitionFromPose:toPose:duration:delay:timingAnimation:completionHandler: v64@0:8@16@24d32d40@48@?56
METHOD transitionFromPose:toPose:duration:delay:timingFunction:completionHandler: v64@0:8@16@24d32d40@48@?56
METHOD transitionToPose:duration:delay:completionHandler: v48@0:8@16d24d32@?40
METHOD updateAfterAnimationsEvaluatedAtTime:renderer: v32@0:8d16@24
METHOD updateBindings v16@0:8
METHOD updateBindingsOfNode: v24@0:8@16
METHOD updateEyeOrientationAndReflections v16@0:8
METHOD updateMorpherDrivenMaterialsWithDeltaTime: v24@0:8d16
METHOD updatePoseWithFaceTrackingData:applySmoothing: v28@0:8@16B24
METHOD updatePoseWithPoseProvider:applySmoothing: v28@0:8@16B24
METHOD upperNodesIgnoredByDynamics @16@0:8
METHOD usageIntent Q16@0:8
METHOD usesSkinningForEyeOrientation B16@0:8
METHOD willRemoveFromWorld: v24@0:8@16

=== CLASS AVTAnimoji ===
SUPER: AVTAvatar
SIZE: 296
IVAR +240 0 _url @"NSURL"
IVAR +248 0 _lightingNode @"VFXNode"
IVAR +256 0 _headNode @"VFXNode"
IVAR +264 0 _avatarNode @"VFXNode"
IVAR +272 0 _cameraNode @"VFXNode"
IVAR +280 0 _specializationSettings @"NSDictionary"
IVAR +288 0 _name @"NSString"
CMETHOD supportsSecureCoding B16@0:8
CMETHOD animojiNames @16@0:8
CMETHOD thumbnailForAnimojiNamed:options: @32@0:8@16@24
CMETHOD _sceneURLForPuppetDirectoryURL: @24@0:8@16
CMETHOD _scenePathForPuppetNamed: @24@0:8@16
CMETHOD animojiNamed: @24@0:8@16
CMETHOD animojiWithContentsOfURL: @24@0:8@16
CMETHOD preloadAnimojiNamed: v24@0:8@16
CMETHOD preloadPuppet: v24@0:8@16
CMETHOD preloadPuppetNamed: v24@0:8@16
CMETHOD puppetNamed:options: @32@0:8@16@24
CMETHOD puppetNames @16@0:8
CMETHOD thumbnailForPuppetNamed:options: @32@0:8@16@24
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD name @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD setName: v24@0:8@16
METHOD url @16@0:8
METHOD setUrl: v24@0:8@16
METHOD _load v16@0:8
METHOD loadIfNeeded v16@0:8
METHOD updateWithOptions: v24@0:8Q16
METHOD initWithName:error: @32@0:8@16^@24
METHOD _sceneURL @16@0:8
METHOD avatarNode @16@0:8
METHOD cameraNode @16@0:8
METHOD configureForBestAnimationQuality v16@0:8
METHOD copyWithUsageIntent: @24@0:8Q16
METHOD headNode @16@0:8
METHOD initWithDescriptor:usageIntent:error: @40@0:8@16Q24^@32
METHOD lightingNode @16@0:8
METHOD modelNode @16@0:8
METHOD newDescriptor @16@0:8
METHOD specializationSettings @16@0:8
METHOD stickerPhysicsStateIdentifier @16@0:8
METHOD usageIntent Q16@0:8

=== CLASS AVTAvatarPose ===
SUPER: NSObject
SIZE: 64
PROTOCOLS: NSCopying
IVAR +8 0 _hasNeckPosition B
IVAR +9 0 _hasNeckOrientation B
IVAR +16 0 _bakedAnimationBlendFactor d
IVAR +24 0 _weights @"NSMutableDictionary"
IVAR +32 0 _neckPosition 
IVAR +48 0 _neckOrientation {?="vector"}
CMETHOD friendlyPose @16@0:8
CMETHOD neutralPose @16@0:8
CMETHOD posesForAnimojiNamed:inPosePack: @32@0:8@16@24
CMETHOD posesForMemojiInPosePack: @24@0:8@16
CMETHOD posesInPosePack: @24@0:8@16
CMETHOD posesInPosePack:avatarSelectionBlock: @32@0:8@16@?24
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD .cxx_destruct v16@0:8
METHOD dictionaryRepresentation @16@0:8
METHOD setWeights: v24@0:8@16
METHOD hashString @16@0:8
METHOD initWithDictionaryRepresentation: @24@0:8@16
METHOD initWithScene: @24@0:8@16
METHOD isEqualToPose: B24@0:8@16
METHOD isFriendlyPose B16@0:8
METHOD isNeutralPose B16@0:8
METHOD poseByMergingPose: @24@0:8@16
METHOD neckOrientation {?=}16@0:8
METHOD affectsPhysicsSimulation B16@0:8
METHOD bakedAnimationBlendFactor d16@0:8
METHOD initWithWeights:neckPosition:neckOrientation:bakedAnimationBlendFactor: @48@0:8@16^24^{?=}32d40
METHOD neckPosition 16@0:8
METHOD setBakedAnimationBlendFactor: v24@0:8d16
METHOD setNeckOrientation: v32@0:8{?=}16
METHOD setNeckPosition: v32@0:816
METHOD setNeckPositionAndOrientationFromHierarchy: v24@0:8@16
METHOD setWeight:forBlendShapeNamed: v32@0:8d16@24
METHOD weightForBlendShapeNamed: d24@0:8@16

=== CLASS AVTView ===
SUPER: VFXView
SIZE: 680
PROTOCOLS: _VFXWorldCommandBufferStatusMonitor _VFXWorldRendererResourceManagerMonitor VFXWorldRendererDelegate AVTRendererTechniqueSupport AVTSceneRenderer AVTWorldRenderer
IVAR +600 0 _environment @"AVTAvatarEnvironment"
IVAR +608 0 _presentationConfiguration @"AVTPresentationConfiguration"
IVAR +616 0 _avatar @"AVTAvatar"
IVAR +624 0 _avatarNode @"VFXNode"
IVAR +632 0 _avtRendersContinuously B
IVAR +640 0 _avtRendererTechnique @"<AVTRendererTechnique>"
IVAR +648 0 _avtRendererTechniquePresentationTree @"<AVTRendererTechnique>"
IVAR +656 0 _backgroundContentsBehindDrawable @
IVAR +664 0 _transitionHelper @"AVTViewTransitionHelper"
IVAR +672 0 _lock @"NSRecursiveLock"
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD environment @16@0:8
METHOD initWithFrame: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD didMoveToWindow v16@0:8
METHOD presentationConfiguration @16@0:8
METHOD scene @16@0:8
METHOD setup v16@0:8
METHOD avatar @16@0:8
METHOD setAvatar: v24@0:8@16
METHOD updateInterfaceOrientation v16@0:8
METHOD _defaultBackgroundColor @16@0:8
METHOD _UIOrientationDidChangeNotification: v24@0:8@16
METHOD _customMainPassPostProcessUsesExtraRenderTargetForRenderer:pixelFormat: B32@0:8@16^Q24
METHOD _drawAtTime: v24@0:8d16
METHOD _encodeCustomMainPassPostProcessForRenderer:atTime:helper: v40@0:8@16d24@32
METHOD _renderer:didApplyAnimationsAtTime: v32@0:8@16d24
METHOD _renderer:didBuildSubdivDataForHash:dataProvider: v40@0:8@16@24@?32
METHOD _renderer:subdivDataForHash: @32@0:8@16@24
METHOD _renderer:updateAtTime: v32@0:8@16d24
METHOD _usesSpecificMainPassClearColorForRenderer:clearColor: B32@0:8@16^24
METHOD _wantsCustomMainPassPostProcessForRenderer: B24@0:8@16
METHOD initWithFrame:options: @56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD renderer:commandBufferDidCompleteWithError: v32@0:8@16@24
METHOD renderer:didFallbackToDefaultTextureForSource:message: v40@0:8@16@24@32
METHOD rendersContinuously B16@0:8
METHOD setRendersContinuously: v20@0:8B16
METHOD updateAtTime: v24@0:8d16
METHOD setFramingMode: v24@0:8@16
METHOD setShowPerfHUD: v20@0:8B16
METHOD addAvatarPresentedOnScreenCallbackWithQueue:block: v32@0:8@16@?24
METHOD framingMode @16@0:8
METHOD snapshotWithSize:scaleFactor: @36@0:8{CGSize=dd}16f32
METHOD snapshotWithSize:scaleFactor:options: @44@0:8{CGSize=dd}16f32@36
METHOD transitionToPose:duration:completionHandler: v40@0:8@16d24@?32
METHOD transitionToStickerConfiguration:duration:completionHandler: v40@0:8@16d24@?32
METHOD transitionToStickerConfiguration:duration:style:completionHandler: v48@0:8@16d24Q32@?40
METHOD avatarDidChange v16@0:8
METHOD _avatarWantsSpecificTechniqueDidChange: v24@0:8@16
METHOD _avtCommonInit v16@0:8
METHOD _avtUpdateRendersContinuously v16@0:8
METHOD _didLostTrackingForAWhile v16@0:8
METHOD _disconnectRendererFromAllAvatars v16@0:8
METHOD _disconnectRendererFromAvatar:avatarNode: v32@0:8@16@24
METHOD _drawWithUpdate: v24@0:8@16
METHOD _renderer:willRenderWorld:atTime: v40@0:8@16@24d32
METHOD _resetFaceToRandomPosition v16@0:8
METHOD _transitionCoordinatorOutOfStickerConfigurationWithDuration:style:options: v40@0:8d16Q24Q32
METHOD _transitionCoordinatorToStickerConfiguration:duration:style:options: v48@0:8@16d24Q32Q40
METHOD _transitionToCustomFaceTrackingWithDuration:style:enableBakedAnimations:faceTrackingDidStartHandlerReceiverBlock:completionHandler: v52@0:8d16Q24B32@?36@?44
METHOD allowTrackSmoothing B16@0:8
METHOD avtRendererTechnique @16@0:8
METHOD backgroundContentsBehindDrawable @16@0:8
METHOD crashAppExtensionOrViewService_rdar98130076: v24@0:8@?16
METHOD faceIsFullyActive B16@0:8
METHOD lockAvatar v16@0:8
METHOD setAvtRendererTechnique: v24@0:8@16
METHOD setBackgroundContentsBehindDrawable: v24@0:8@16
METHOD setFramingMode:animationDuration: v32@0:8@16d24
METHOD setPresentationConfiguration: v24@0:8@16
METHOD setupOrientation v16@0:8
METHOD showPerfHUD B16@0:8
METHOD snapshotWithSize: @32@0:8{CGSize=dd}16
METHOD transitionToCustomFaceTrackingWithDuration:style:enableBakedAnimations:faceTrackingDidStartHandlerReceiverBlock:completionHandler: v52@0:8d16Q24B32@?36@?44
METHOD transitionToPose:duration:style:completionHandler: v48@0:8@16d24Q32@?40
METHOD unlockAvatar v16@0:8
METHOD updateForMultiAvatarPositioningStyle v16@0:8
METHOD warmupMemoji v16@0:8

=== CLASS AVTRecordView ===
SUPER: AVTView
SIZE: 696
IVAR +680 0 mute B
IVAR +684 0 maxRecordingDuration f
IVAR +688 0 recordDelegate @"<AVTRecordViewDelegate>"
METHOD .cxx_destruct v16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD isPreviewing B16@0:8
METHOD isRecording B16@0:8
METHOD setMute: v20@0:8B16
METHOD cancelRecording v16@0:8
METHOD setRecordDelegate: v24@0:8@16
METHOD startRecording v16@0:8
METHOD stopRecording v16@0:8
METHOD initWithFrame:options: @56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD mute B16@0:8
METHOD playPreviewOnce v16@0:8
METHOD startPreviewing v16@0:8
METHOD exportMovieToURL:options:completionHandler: B40@0:8@16@24@?32
METHOD maxRecordingDuration f16@0:8
METHOD recordDelegate @16@0:8
METHOD setMaxRecordingDuration: v20@0:8f16
METHOD stopPreviewing v16@0:8

=== CLASS AVTFaceTrackingInfo ===
SUPER: NSObject
SIZE: 496
IVAR +16 0 _trackingData {?="timestamp"d"translation""orientation""cameraSpace"B"blendShapeWeights_smooth"[51f]"blendShapeWeights_raw"[51f]"parameters_smooth"[1f]"parameters_raw"[1f]}
CMETHOD trackingInfoWithTrackingData: @24@0:8^{?=dB[51f][51f][1f][1f]}16
METHOD trackingData r^{?=dB[51f][51f][1f][1f]}16@0:8

=== CLASS AVTMemoji ===
SUPER: AVTAvatar
SIZE: 2424
IVAR +240 0 _usageIntent Q
IVAR +248 0 _visibleBodyParts Q
IVAR +256 0 _resourceCache @"AVTAssetResourceCache"
IVAR +264 0 _needsUpdate B
IVAR +268 0 _updateLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +272 0 _headComponentContainer @"VFXNode"
IVAR +280 0 _bodyComponentContainer @"VFXNode"
IVAR +288 0 _handsComponentContainer @"VFXNode"
IVAR +296 0 _headNode @"VFXNode"
IVAR +304 0 _torsoNode @"VFXNode"
IVAR +312 0 _avatarNode @"VFXNode"
IVAR +320 0 _eyelashes @"VFXNode"
IVAR +328 0 _eyesAndTongue @"VFXNode"
IVAR +336 0 _skeletonRootNode @"VFXNode"
IVAR +344 0 _outfitWrapDeformerDriverInfo @"AVTMemojiWrapDeformerDriverInfo"
IVAR +352 0 _headwearWrapDeformerDriverInfo @"AVTMemojiWrapDeformerDriverInfo"
IVAR +360 0 _eyeMaterialLeft @"VFXMaterial"
IVAR +368 0 _eyeMaterialRight @"VFXMaterial"
IVAR +376 0 _eyesAndTongueSpecializationSettings @"NSDictionary"
IVAR +384 0 _components [42@"AVTComponent"]
IVAR +720 0 _componentInstances [42@"AVTComponentInstance"]
IVAR +1056 0 _componentDirtyMask Q
IVAR +1064 0 _componentAnimatedMask Q
IVAR +1072 0 _presetStore @"AVTPresetStore"
IVAR +1080 0 _currentPresetsForVariants [40@"AVTPreset"]
IVAR +1400 0 _colorPresets [40[3@"AVTColorPreset"]]
IVAR +2360 0 _combinedAOImage ^{CGImage=}
IVAR +2368 0 _skinAOIsValid B
IVAR +2376 0 _compositor @"AVTCompositor"
IVAR +2384 0 _compositorComponentDirtyMask Q
IVAR +2392 0 _hairPhysicsShouldIgnoreUpperNodes B
IVAR +2400 0 _bodyPose @"AVTAvatarBodyPose"
IVAR +2408 0 _specializationSettings @"NSDictionary"
IVAR +2416 0 _componentAssetNodeObservationForStickerBlock @?
CMETHOD supportsSecureCoding B16@0:8
CMETHOD memoji @16@0:8
CMETHOD neutralMemojiPresetsIdentifiersPerCategory @16@0:8
CMETHOD skinTextureSize d16@0:8
CMETHOD neutralMemojiDataRepresentation @16@0:8
CMETHOD memojiWithContentsOfURL:error: @32@0:8@16^@24
CMETHOD memojiWithContentsOfURL:usageIntent:error: @40@0:8@16Q24^@32
CMETHOD neutralMemoji @16@0:8
CMETHOD neutralMemojiDescriptor @16@0:8
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD bodyPose @16@0:8
METHOD updateWithOptions: v24@0:8Q16
METHOD resetToDefault v16@0:8
METHOD randomize v16@0:8
METHOD setPreset:forCategory:animated: v36@0:8@16q24B32
METHOD colorPresetForCategory:colorIndex: @32@0:8q16Q24
METHOD presetForCategory: @24@0:8q16
METHOD setColorPreset:forCategory:colorIndex: v40@0:8@16q24Q32
METHOD setShowsBody: v20@0:8B16
METHOD skinColor @16@0:8
METHOD _removeComponent: v24@0:8@16
METHOD removeAllComponents v16@0:8
METHOD updateEyeLashes v16@0:8
METHOD arScale f16@0:8
METHOD facialhairColor @16@0:8
METHOD _addHandsComponentInstanceIfNeeded v16@0:8
METHOD _addTorsoComponentInstanceIfNeeded B16@0:8
METHOD _applyAllColorPresetsForCategory: v24@0:8q16
METHOD _applyColorPresetForCategory:colorIndex: v32@0:8q16Q24
METHOD _applyMorphVariantsForLazyComponentInstanceOfType:assetNode: v32@0:8q16@24
METHOD _assetNodesForComponentType:includingBuiltInAssetNodes:includingComponentAssetNode: @32@0:8q16B24B28
METHOD _componentInstanceAssetNodesForDependencyOfType:isAssetSpecific: @28@0:8q16B24
METHOD _didActivateLazyComponentInstanceOfType:assetNode: v32@0:8q16@24
METHOD _didInstantiateLazyComponentInstanceOfType:assetNode: v32@0:8q16@24
METHOD _invalidateSkinAO v16@0:8
METHOD _locked_invalidate v16@0:8
METHOD _setAssetSpecificVariantDependenciesEnabled:forPreset:dirtyComponents: v36@0:8B16@20Q28
METHOD _setMorphWeight:forDependencyVariant:ofType:isAssetSpecific: v40@0:8f16@20q28B36
METHOD _setVariantDependenciesEnabled:forPreset:dirtyComponents: v36@0:8B16@20Q28
METHOD _updateSkinAO v16@0:8
METHOD _updateWithOptions: v24@0:8Q16
METHOD _willDeactivateLazyComponentInstanceOfType:assetNode: v32@0:8q16@24
METHOD _wrapDeformerDriverInfoForComponentType: @24@0:8q16
METHOD addComponent:animated: v28@0:8@16B24
METHOD addComponentAssetNode:toNode:forBodyParts: v40@0:8@16@24Q32
METHOD addDerivedNodesMatchingStickerPattern:toArray:options: v40@0:8@16@24Q32
METHOD allAssetNodesForComponentType: @24@0:8q16
METHOD allBuiltinAssetNodes @16@0:8
METHOD applyVariantDependenciesForPreset:dirtyComponents: v32@0:8@16Q24
METHOD arOffset 16@0:8
METHOD assetResourceCache @16@0:8
METHOD avatarNode @16@0:8
METHOD bodyComponentContainer @16@0:8
METHOD builtinAssetNodesForComponentType: @24@0:8q16
METHOD colorPresetForCategory: @24@0:8q16
METHOD componentDidChangeForType:animated: v28@0:8q16B24
METHOD componentInstanceForType: @24@0:8q16
METHOD componentMaterialDidUpdate: v24@0:8@16
METHOD componentWithType: @24@0:8q16
METHOD copyWithUsageIntent: @24@0:8Q16
METHOD createSkinCombinedAOImage ^{CGImage=}16@0:8
METHOD effectiveMorphedNodeForTargetName: @24@0:8@16
METHOD enumerateActiveWrapDeformerDriversForComponentType:usingBlock: v32@0:8q16@?24
METHOD eyebrowsColor @16@0:8
METHOD hairColor @16@0:8
METHOD handsComponentContainer @16@0:8
METHOD headComponentContainer @16@0:8
METHOD headNode @16@0:8
METHOD initWithDescriptor:usageIntent:error: @40@0:8@16Q24^@32
METHOD lipsColor @16@0:8
METHOD newDescriptor @16@0:8
METHOD rebuildSpecializationSettings v16@0:8
METHOD removeComponentAssetNodeFromParentNode:forBodyParts: v32@0:8@16Q24
METHOD removeComponentWithType: v24@0:8q16
METHOD resolvedPresetForCategory: @24@0:8q16
METHOD secondaryColorPresetForCategory: @24@0:8q16
METHOD setBodyPose: v24@0:8@16
METHOD setColorPreset:forCategory: v32@0:8@16q24
METHOD setComponentAssetNodeObservationForStickerBlock: v24@0:8@?16
METHOD setInstance:forComponentType: v32@0:8@16q24
METHOD setPreset:forCategory: v32@0:8@16q24
METHOD setSecondaryColorPreset:forCategory: v32@0:8@16q24
METHOD setVisibleBodyParts: v24@0:8Q16
METHOD showsBody B16@0:8
METHOD specializationSettings @16@0:8
METHOD stickerPhysicsStateIdentifier @16@0:8
METHOD unapplyVariantDependenciesForPreset:dirtyComponents: v32@0:8@16Q24
METHOD updateBodyPoseForSkinnerVariantsWithDirtyComponents: v24@0:8Q16
METHOD updateHighlightsForComponentType: v24@0:8q16
METHOD updateMorphVariantsInNodeHierarchy:componentType:variant:weight: v44@0:8@16q24@32f40
METHOD updateMorphVariantsInStickerPropNodeHierarchy: v24@0:8@16
METHOD updateSkinMaterial: v24@0:8@16
METHOD updateWrapDeformerIsActiveForComponentType: v24@0:8q16
METHOD upperNodesIgnoredByDynamics @16@0:8
METHOD usageIntent Q16@0:8
METHOD usesSkinningForEyeOrientation B16@0:8
METHOD visibleBodyParts Q16@0:8
METHOD wrapDeformedDriverNamed:forComponentType: @32@0:8@16q24

=== CLASS AVTPhysicsController ===
SUPER: NSObject
SIZE: 48
IVAR +8 0 _physicsWorld @"VFXPhysicsWorld"
IVAR +16 0 _physicsRigs @"NSArray"
IVAR +24 0 _physicsBehaviorsAreInstalledInPhysicsWorld B
IVAR +28 0 _frameCount I
IVAR +32 0 _lock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +36 0 _setupDone B
IVAR +37 0 _hasPhysicsStateOverride B
IVAR +40 0 _delegate @"<AVTPhysicsControllerDelegate>"
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD delegate @16@0:8
METHOD setDelegate: v24@0:8@16
METHOD physicsState @16@0:8
METHOD _setupPhysicsChain:physicsRigs: v32@0:8@16@24
METHOD _setupCollisionNode: v24@0:8@16
METHOD addToPhysicsWorld: v24@0:8@16
METHOD applyForcesWithMultiplier: v24@0:8d16
METHOD downforcesDidChange v16@0:8
METHOD installPhysics v16@0:8
METHOD offsetFromRestingPositionForNode:inCoordinateSpaceOfNode: 32@0:8@16@24
METHOD removeFromPhysicsWorld: v24@0:8@16
METHOD resetToPhysicsState:assumeRestStateIfNil: v28@0:8@16B24
METHOD setupPhysics v16@0:8
METHOD setupPhysicsIfNeeded v16@0:8
METHOD updateAtTime:forceMultiplier: v32@0:8d16d24

=== CLASS AVTAvatarEnvironment ===
SUPER: NSObject
SIZE: 112
IVAR +8 0 _scene @"VFXWorld"
IVAR +16 0 _renderer @"<VFXWorldRenderer>"
IVAR +24 0 _avatar @"AVTAvatar"
IVAR +32 0 _shadowPlaneMaterial @"VFXMaterial"
IVAR +40 0 _whitePlane @"VFXNode"
IVAR +48 0 _environmentNode @"VFXNode"
IVAR +56 0 _defaultPointOfView @"VFXNode"
IVAR +64 0 _framingMode @"NSString"
IVAR +72 0 _animojiCamera @"VFXNode"
IVAR +80 0 _memojiCameraGroup @"VFXNode"
IVAR +88 0 _customCamera @"VFXNode"
IVAR +96 0 _specializedLightingNode @"VFXNode"
IVAR +104 0 _defaultLightingNode @"VFXNode"
METHOD .cxx_destruct v16@0:8
METHOD didSnapshot v16@0:8
METHOD willSnapshot v16@0:8
METHOD setFramingMode: v24@0:8@16
METHOD framingMode @16@0:8
METHOD environmentNode @16@0:8
METHOD initAndInstallInScene:renderer: @32@0:8@16@24
METHOD avatarDidChange:presentationConfiguration: v32@0:8@16@24
METHOD currentPointOfView @16@0:8
METHOD defaultEnvironmentNode @16@0:8
METHOD defaultPointOfView @16@0:8
METHOD faceIsFullyVisible B16@0:8
METHOD fadeFactor f16@0:8
METHOD pointOfViewForFramingMode: @24@0:8@16
METHOD setEnablePhysicsSimulation: v20@0:8B16
METHOD setFadeFactor: v20@0:8f16
METHOD setFramingMode:animationDuration: v32@0:8@16d24
METHOD setFramingModeForcingPointOfViewUpdate: v24@0:8@16
METHOD updateCustomCameras v16@0:8
METHOD updatePointOfViewFromFramingMode v16@0:8
METHOD updateSpecializedLighting v16@0:8
METHOD updateWithPresentationConfiguration: v24@0:8@16

=== CLASS AVTAvatarPoseAnimation ===
SUPER: NSObject
SIZE: 48
IVAR +8 0 _staticPose @"AVTAvatarPose"
IVAR +16 0 _staticPhysicsStates @"NSDictionary"
IVAR +24 0 _blendshapeAnimations @"NSDictionary"
IVAR +32 0 _perNodeAnimations @"NSDictionary"
IVAR +40 0 _animationBaseKey @"NSString"
CMETHOD animationFromDataRepresentation:keyPath: @32@0:8@16@24
CMETHOD animationFromDictionaryRepresentation:keyPath: @32@0:8@16@24
CMETHOD dataRepresentationForAnimation:completionHandler: v32@0:8@16@?24
CMETHOD dictionaryRepresentationForAnimation:completionHandler: v32@0:8@16@?24
CMETHOD optimizeSceneKitAnimation:target: @32@0:8@16@24
CMETHOD removeAllAnimationsFromAvatar: v24@0:8@16
METHOD .cxx_destruct v16@0:8
METHOD duration d16@0:8
METHOD physicalizedPose @16@0:8
METHOD animatedPoseRepresentationWithDictionaryAnimationRepresentation @16@0:8
METHOD _addAnimationToAvatar:options:transitionInDuration:transitionOutDuration:isTransient:completionQueue:completionHandler: @68@0:8@16Q24d32d40B48@52@?60
METHOD _initWithSceneKitScene:usdaMetadata:identifier: @64@0:8@16{?=Bddd}24@56
METHOD _initWithStaticPoseRepresentation:animatedPoseRepresentation:staticPhysicsStatesRepresentation:identifier: @48@0:8@16@24@32@40
METHOD addToAvatar:options: @32@0:8@16Q24
METHOD addToAvatar:options:transitionDuration: @40@0:8@16Q24d32
METHOD addToAvatar:useStaticPhysicsState: @28@0:8@16B24
METHOD addToAvatar:useStaticPhysicsState:transitionDuration: @36@0:8@16B24d28
METHOD animatedPoseRepresentationWithAnimationRepresentationBuilder: @24@0:8@?16
METHOD animatedPoseRepresentationWithDataAnimationRepresentation @16@0:8
METHOD animationsForAvatar: @24@0:8@16
METHOD commonInitWithIdentifier: v24@0:8@16
METHOD initWithAnimatedPoseRepresentationAtURL: @24@0:8@16
METHOD initWithSceneKitScene: @24@0:8@16
METHOD initWithSceneKitScene:usdaMetadata: @56@0:8@16{?=Bddd}24
METHOD initWithSceneKitSceneAtURL: @24@0:8@16
METHOD initWithSceneKitSceneAtURL:usdaMetadata: @56@0:8@16{?=Bddd}24
METHOD initWithStaticPose:staticPhysicsStates: @32@0:8@16@24
METHOD initWithStaticPoseRepresentation:animatedPoseRepresentation:staticPhysicsStatesRepresentation: @40@0:8@16@24@32
METHOD playOnceOnAvatar:options:transitionInDuration:transitionOutDuration:completionQueue:completionHandler: v64@0:8@16Q24d32d40@48@?56
METHOD staticPose @16@0:8
METHOD staticPoseRepresentation @16@0:8

=== CLASS AVTAvatarPoseAnimationController ===
SUPER: NSObject
SIZE: 24
PROTOCOLS: AVTAvatarPoseAnimationController
IVAR +8 0 _avatar @"AVTAvatar"
IVAR +16 0 _animationKeys @"NSArray"
METHOD .cxx_destruct v16@0:8
METHOD initWithAvatar:animationKeys: @32@0:8@16@24
METHOD removeAnimationWithBlendOutDuration: v24@0:8d16

=== CLASS AVTCompositor ===
SUPER: NSObject
SIZE: 16
IVAR +8 0 _textureProviders @"NSMutableSet"
CMETHOD propertyNames @16@0:8
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD addClient: v24@0:8@16
METHOD removeClient: v24@0:8@16
METHOD componentDidChangeForTypes: v24@0:8Q16
METHOD configureMaterial:propertyNamed:memoji: v40@0:8@16@24@32
METHOD skinColorDidChange v16@0:8

=== CLASS AVTPreset ===
SUPER: NSObject
SIZE: 136
IVAR +8 0 _category q
IVAR +16 0 _identifier @"NSString"
IVAR +24 0 _assets @"NSArray"
IVAR +32 0 _editableColorCount Q
IVAR +40 0 _morphVariant @"NSString"
IVAR +48 0 _imageVariant @"NSString"
IVAR +56 0 _materialVariant @"NSString"
IVAR +64 0 _morphVariantIntensity f
IVAR +68 0 _bodyPoseVariantIntensity f
IVAR +72 0 _textureAssetPresence f
IVAR +80 0 _dependencies @"NSArray"
IVAR +88 0 _assetSpecificMorphVariantDependencies @"NSDictionary"
IVAR +96 0 _assetSpecificImageVariantDependencies @"NSDictionary"
IVAR +104 0 _assetSpecificMaterialVariantDependencies @"NSDictionary"
IVAR +112 0 _presetSpecificPresetDependencies @"NSDictionary"
IVAR +120 0 _tags @"NSDictionary"
IVAR +128 0 _specializationSettings @"NSDictionary"
CMETHOD availablePresetsForCategory: @24@0:8q16
CMETHOD colorPresetsForCategory:colorIndex: @32@0:8q16Q24
CMETHOD presetWithCategory:identifier: @32@0:8q16@24
CMETHOD colorPresetsForCategory: @24@0:8q16
CMETHOD editableColorCountForCategory: Q24@0:8q16
CMETHOD secondaryColorPresetsForCategory: @24@0:8q16
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD identifier @16@0:8
METHOD category q16@0:8
METHOD localizedName @16@0:8
METHOD tags @16@0:8
METHOD cache @16@0:8
METHOD assets @16@0:8
METHOD displayableName @16@0:8
METHOD localizedPairedName @16@0:8
METHOD editableColorCount Q16@0:8
METHOD enumerateAssetSpecificVariantDependenciesOfKind:block: v32@0:8Q16@?24
METHOD enumeratePresetDependencies: v24@0:8@?16
METHOD enumeratePresetSpecificPresetDependencies: v24@0:8@?16
METHOD enumerateVariantDependenciesOfKind:block: v32@0:8Q16@?24
METHOD enumerateVisibilityDependencies: v24@0:8@?16
METHOD hasComponent B16@0:8
METHOD newComponent @16@0:8
METHOD rebuildSpecializationSettings v16@0:8
METHOD specializationSettings @16@0:8

=== CLASS AVTComponent ===
SUPER: NSObject
SIZE: 88
IVAR +8 0 _type q
IVAR +16 0 _assets @"NSArray"
IVAR +24 0 _materials [3@"AVTMaterial"]
IVAR +48 0 _morphVariantIntensity f
IVAR +52 0 _bodyPoseVariantIntensity f
IVAR +56 0 _textureAssetPresence f
IVAR +64 0 _morphVariant @"NSString"
IVAR +72 0 _imageVariant @"NSString"
IVAR +80 0 _materialVariant @"NSString"
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD type q16@0:8
METHOD assets @16@0:8
METHOD materialAtIndex: @24@0:8Q16
METHOD materialVariant @16@0:8
METHOD bodyPoseVariantIntensity f16@0:8
METHOD imageVariant @16@0:8
METHOD initWithType:assets:morphVariant:imageVariant:materialVariant:morphVariantIntensity:bodyPoseVariantIntensity:textureAssetPresence: @68@0:8q16@24@32@40@48f56f60f64
METHOD morphVariant @16@0:8
METHOD morphVariantIntensity f16@0:8
METHOD setMaterial:atIndex: v32@0:8@16Q24
METHOD textureAssetPresence f16@0:8

=== CLASS AVTAvatarDescriptor ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: NSCopying NSSecureCoding
CMETHOD supportsSecureCoding B16@0:8
CMETHOD classIdentifier C16@0:8
CMETHOD _canLoadDataRepresentationWithVersion:minimumCompatibleVersion:error: B32@0:8S16S20^@24
CMETHOD _descriptorWithDictionaryRepresentation:error: @32@0:8@16^@24
CMETHOD _dictionaryRepresentationFromDataRepresentation:error: @32@0:8@16^@24
CMETHOD canLoadDataRepresentation: B24@0:8@16
CMETHOD dataRepresentationFromUnsecureDataRepresentation:error: @32@0:8@16^@24
CMETHOD descriptorWithDataRepresentation:error: @32@0:8@16^@24
CMETHOD descriptorWithURL:error: @32@0:8@16^@24
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD dataRepresentation @16@0:8
METHOD initWithDictionaryRepresentation:error: @32@0:8@16^@24
METHOD encodeInDictionaryRepresentation: v24@0:8@16

=== CLASS AVTMemojiDescriptor ===
SUPER: AVTAvatarDescriptor
SIZE: 1288
IVAR +8 0 _presetIdentifiers [40@"NSString"]
IVAR +328 0 _colorPresets [40[3@"AVTColorPreset"]]
CMETHOD supportsSecureCoding B16@0:8
CMETHOD classIdentifier C16@0:8
CMETHOD colorPresetFromColorData:forCategory:colorIndex:version:didFail:error: @60@0:8@16q24Q32S40^B44^@52
CMETHOD presetsDictionaryFromRecipe:didFail:error: @40@0:8@16^B24^@32
CMETHOD randomDescriptor @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD debugDescription @16@0:8
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithDictionaryRepresentation:error: @32@0:8@16^@24
METHOD colorPresetForCategory:colorIndex: @32@0:8q16Q24
METHOD setColorPreset:forCategory:colorIndex: v40@0:8@16q24Q32
METHOD initWithMemoji: @24@0:8@16
METHOD _decode:isResettingToDefault:error: v36@0:8@16B24^@28
METHOD applyToMemoji: v24@0:8@16
METHOD encodeInDictionaryRepresentation: v24@0:8@16
METHOD initWithDictionaryRepresentation:error:isResettingToDefault: @36@0:8@16^@24B32
METHOD presetIdentifierForCategory: @24@0:8q16
METHOD setPresetIdentifier:forCategory: v32@0:8@16q24

=== CLASS AVTPresentationConfiguration ===
SUPER: NSObject
SIZE: 16
IVAR +8 0 _style Q
METHOD init @16@0:8
METHOD _initWithStyle: @24@0:8Q16
METHOD internalStyle Q16@0:8
METHOD usesAR B16@0:8

=== CLASS AVTStickerConfiguration ===
SUPER: NSObject
SIZE: 144
IVAR +8 0 _lock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +16 0 _legacySizeOption @"NSNumber"
IVAR +24 0 _assetsPath @"NSString"
IVAR +32 0 _configurationDictionary @"NSDictionary"
IVAR +40 0 _hasLoadedFromConfiguration B
IVAR +48 0 _name @"NSString"
IVAR +56 0 _localizedName @"NSString"
IVAR +64 0 _physicalizedPose @"AVTAvatarPhysicalizedPose"
IVAR +72 0 _bodyPose @"AVTAvatarBodyPose"
IVAR +80 0 _props @"NSArray"
IVAR +88 0 _shaderModifiers @"NSArray"
IVAR +96 0 _camera @"AVTStickerCamera"
IVAR +104 0 _stickerPack @"NSString"
IVAR +112 0 _morpherOverrides @"NSArray"
IVAR +120 0 _presetOverrides @"NSArray"
IVAR +128 0 _poseAdjustments @"NSArray"
IVAR +136 0 _stickerVersion Q
CMETHOD stickerConfigurationForAnimojiNamed:inStickerPack:stickerName: @40@0:8@16@24@32
CMETHOD stickerConfigurationForMemojiInStickerPack:stickerName: @32@0:8@16@24
CMETHOD availableStickerNamesForAnimojiNamed:inStickerPack: @32@0:8@16@24
CMETHOD availableStickerNamesForMemojiInStickerPack: @24@0:8@16
CMETHOD stickerConfigurationsForAnimojiNamed:inStickerPack: @32@0:8@16@24
CMETHOD stickerConfigurationsForMemojiInStickerPack: @24@0:8@16
CMETHOD unavailableAnimojiNamesForStickerPack: @24@0:8@16
CMETHOD _availableStickerNamesForPuppetNamed:inStickerPack: @32@0:8@16@24
CMETHOD _stickerConfigurationForPuppetNamed:inStickerPack:stickerName: @40@0:8@16@24@32
CMETHOD _stickerConfigurationsForPuppetNamed:inStickerPack: @32@0:8@16@24
CMETHOD allStickerPackNames @16@0:8
CMETHOD stickerConfigurationsForAnimojiNamed: @24@0:8@16
CMETHOD stickerConfigurationsForMemoji @16@0:8
METHOD description @16@0:8
METHOD name @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD localizedName @16@0:8
METHOD size {CGSize=dd}16@0:8
METHOD unload v16@0:8
METHOD camera @16@0:8
METHOD setCamera: v24@0:8@16
METHOD bodyPose @16@0:8
METHOD initWithName:pose:props:shaders:camera:options: @64@0:8@16@24@32@40@48@56
METHOD loadIfNeeded v16@0:8
METHOD physicalizedPose @16@0:8
METHOD initWithConfigurationAtPath: @24@0:8@16
METHOD shaderModifiers @16@0:8
METHOD setShaderModifiers: v24@0:8@16
METHOD presetOverrides @16@0:8
METHOD framingMode @16@0:8
METHOD preRendered B16@0:8
METHOD stickerPack @16@0:8
METHOD definesPoseOnly B16@0:8
METHOD poseAdjustments @16@0:8
METHOD _updateDictionary:withTargetPath: v32@0:8@16@24
METHOD dictionaryWithTargetPath: @24@0:8@16
METHOD emojiRepresentation @16@0:8
METHOD hasProps B16@0:8
METHOD initWithConfigDictionary:assetsPath:forStickerPack: @40@0:8@16@24@32
METHOD initWithConfigurationAtPath:forStickerPack: @32@0:8@16@24
METHOD initWithName:pose:bodyPose:props:shaders:camera:options: @72@0:8@16@24@32@40@48@56@64
METHOD initWithName:poseAnimation:bodyPose:props:shaders:camera:options: @72@0:8@16@24@32@40@48@56@64
METHOD legacySizeOption @16@0:8
METHOD morpherOverrides @16@0:8
METHOD poseAnimation @16@0:8
METHOD props @16@0:8
METHOD setBodyPose: v24@0:8@16
METHOD setPhysicalizedPose: v24@0:8@16
METHOD setPoseAdjustments: v24@0:8@16
METHOD setProps: v24@0:8@16
METHOD setupOptions: v24@0:8@16
METHOD showsBody B16@0:8
METHOD stickerVersion Q16@0:8

=== CLASS AVTPhysicalizedMorpherDynamic ===
SUPER: NSObject
SIZE: 104
PROTOCOLS: AVTAvatarDynamic
IVAR +8 0 _simulationFactor f
IVAR +16 0 _referenceNode @"VFXNode"
IVAR +24 0 _drivingNode @"VFXNode"
IVAR +32 0 _writeMorpher @"VFXMorpher"
IVAR +40 0 _forwardMorphTargetIndex Q
IVAR +48 0 _backwardMorphTargetIndex Q
IVAR +56 0 _leftwardMorphTargetIndex Q
IVAR +64 0 _rightwardMorphTargetIndex Q
IVAR +72 0 _upwardMorphTargetIndex Q
IVAR +80 0 _downwardMorphTargetIndex Q
IVAR +88 0 _extraSimulationFactorReadMorpherNode @"VFXNode"
IVAR +96 0 _extraSimulationFactorTargetIndex Q
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD affectsNode: B24@0:8@16
METHOD evaluateAtTime:physicsController: v32@0:8d16@24
METHOD resetTarget v16@0:8

=== CLASS AVTPhysicalizedSkeletonDynamic ===
SUPER: NSObject
SIZE: 104
PROTOCOLS: AVTAvatarDynamic
IVAR +8 0 _simulationFactor f
IVAR +16 0 _referenceNode @"VFXNode"
IVAR +24 0 _drivingNode @"VFXNode"
IVAR +32 0 _rootJoint @"VFXNode"
IVAR +40 0 _targetNodes @"NSArray"
IVAR +48 0 _upDownRotation 
IVAR +64 0 _leftRightRotation 
IVAR +80 0 _forwardBackRotation 
IVAR +96 0 _side Q
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD affectsNode: B24@0:8@16
METHOD evaluateAtTime:physicsController: v32@0:8d16@24
METHOD resetTarget v16@0:8

=== CLASS AVTAvatarMemoryOptimizer ===
SUPER: NSObject
SIZE: 224
IVAR +8 0 _memoji @"AVTMemoji"
IVAR +16 0 _requiredVariantsPerMorpher @"NSMapTable"
IVAR +24 0 _requiredMorphVariantComponents @"NSMutableArray"
IVAR +32 0 _presetVariantPrefixes @"NSMutableSet"
IVAR +40 0 _oldWeights @"NSArray"
IVAR +48 0 _oldMainTargets @"NSArray"
IVAR +56 0 _hasInBetweens B
IVAR +64 0 _newWeights @"NSMutableArray"
IVAR +72 0 _newTargetsAndInBetweens @"NSMutableArray"
IVAR +80 0 _newInBetweenCounts @"NSMutableArray"
IVAR +88 0 _newInBetweenWeights @"NSMutableArray"
IVAR +96 0 _indicesOfTargetsToFlattenInBaseGeometry @"NSMutableArray"
IVAR +104 0 _indicesOfTargetsToFlattenInOtherTarget @"NSMutableDictionary"
IVAR +112 0 _nonOneWeightsOfTargetsToFlatten @"NSMutableDictionary"
IVAR +120 0 _oldCorrectives @"NSArray"
IVAR +128 0 _oldCorrectiveDriverCounts @"NSArray"
IVAR +136 0 _oldCorrectiveDriverIndices @"NSArray"
IVAR +144 0 _hasCorrectives B
IVAR +145 0 _hasCorrectiveInBetweens B
IVAR +152 0 _newCorrectivesAndInBetweens @"NSMutableArray"
IVAR +160 0 _newCorrectiveDriverCounts @"NSMutableArray"
IVAR +168 0 _newCorrectiveDriverIndices @"NSMutableArray"
IVAR +176 0 _newCorrectiveInBetweenCounts @"NSMutableArray"
IVAR +184 0 _newCorrectiveInBetweenWeights @"NSMutableArray"
IVAR +192 0 _indicesOfCorrectivesToFlattenInBaseGeometry @"NSMutableArray"
IVAR +200 0 _indicesOfCorrectivesToFlattenInMainTarget @"NSMutableDictionary"
IVAR +208 0 _indicesOfCorrectivesToFlattenInOtherCorrective @"NSMutableDictionary"
IVAR +216 0 _nonOneWeightsOfCorrectivesToFlatten @"NSMutableDictionary"
METHOD .cxx_destruct v16@0:8
METHOD shouldClearCPUDataAfterUpload B16@0:8
METHOD initWithMemoji: @24@0:8@16
METHOD applyMorphTarget:weight:toBaseGeometryBuffer:vertexCount: v44@0:8@16f24^v28Q36
METHOD applyMorphTarget:weight:toMorphTargetBuffer:vertexCount: v44@0:8@16f24^{?=fff}28Q36
METHOD classifyTargetsOfMorpher:node: v32@0:8@16@24
METHOD flattenCorrectiveAtIndex:inBaseGeometryUsingWeight: v28@0:8Q16f24
METHOD flattenCorrectiveAtIndex:inCorrectiveAtIndex:weight: v36@0:8Q16Q24f32
METHOD flattenCorrectiveAtIndex:inTargetAtIndex:weight: v36@0:8Q16Q24f32
METHOD flattenCorrectivesAtIndices:inCorrective:weight:morpher: v44@0:8@16@24f32@36
METHOD flattenCorrectivesAtIndices:inCorrectiveAtIndex:morpher: v40@0:8@16Q24@32
METHOD flattenRelevantTargetsInOtherTargetsOfMorpher: v24@0:8@16
METHOD flattenRelevantTargetsOfMorpher:inBaseGeometryOfNode: v32@0:8@16@24
METHOD flattenTarget0:weight0:target1:weight1:inMorphTarget:originalMorphTarget: @56@0:8@16f24@28f36@40@48
METHOD flattenTargetAtIndex:inBaseGeometryUsingWeight: v28@0:8Q16f24
METHOD flattenTargetAtIndex:inTargetAtIndex:weight: v36@0:8Q16Q24f32
METHOD flattenTargetsAtIndices:correctivesAtIndices:inTarget:weight:morpher: v52@0:8@16@24@32f40@44
METHOD flattenTargetsAtIndices:correctivesAtIndices:inTargetAtIndex:morpher: v48@0:8@16@24Q32@40
METHOD flattenTargetsOfMorpher:node: v32@0:8@16@24
METHOD keepCorrectiveAtIndex:morpher: v32@0:8Q16@24
METHOD keepCorrectiveAtIndex:withDriverIndices:morpher: v40@0:8Q16@24@32
METHOD keepTargetAtIndex:morpher: v32@0:8Q16@24
METHOD optimizeMemoji v16@0:8
METHOD optimizeNode: v24@0:8@16
METHOD optimizeNodeHierarchy: v24@0:8@16
METHOD preprocessMemoji v16@0:8
METHOD registerRequiredVariant:weight:inHierarchy: v36@0:8@16f24@28
METHOD resolveInBetweensForTarget:weight:inBetweenWeights:inBetweenTargets:block: v52@0:8@16f24@28@36@?44
METHOD shouldKeepCreasesAndCorners B16@0:8

=== CLASS AVTViewTransitionHelper ===
SUPER: NSObject
SIZE: 40
IVAR +8 0 _view @"AVTView"
IVAR +16 0 _stickerConfiguration @"AVTStickerConfiguration"
IVAR +24 0 _stickerTransitionReversionContext @"AVTStickerConfigurationReversionContext"
IVAR +32 0 _transitionTechnique @"AVTRendererViewTransitionTechnique"
METHOD .cxx_destruct v16@0:8
METHOD viewBackgroundColor 16@0:8
METHOD coordinator_performCrossFadeThenAnimateTransitionToStickerConfiguration:duration:options:avatar:avatarNode:oldReversionContext: v64@0:8@16d24Q32@40@48@56
METHOD coordinator_performCrossFadeThenAnimateTransitionOutOfStickerConfigurationWithDuration:avatar:avatarNode:oldReversionContext: v48@0:8d16@24@32@40
METHOD coordinator_performCrossFadeTransitionOutOfStickerConfigurationWithDuration:avatar:avatarNode:oldReversionContext: v48@0:8d16@24@32@40
METHOD coordinator_performCrossFadeTransitionToStickerConfiguration:duration:options:avatar:avatarNode:oldReversionContext: v64@0:8@16d24Q32@40@48@56
METHOD snapshotViewUsingBackgroundColor: @32@0:816
METHOD transitionTechnique @16@0:8
METHOD view_performAnimateThenCrossFadeTransitionFromStickerConfiguration:toStickerConfiguration:duration:avatar:avatarNode:oldReversionContext:completionHandler:simultaneousAnimationsBlock: v80@0:8@16@24d32@40@48@56@?64@?72
METHOD view_performCrossFadeThenAnimateTransitionToStickerConfiguration:fallbackPose:duration:avatar:avatarNode:oldReversionContext:completionHandler:simultaneousAnimationsBlock: v80@0:8@16@24d32@40@48@56@?64@?72
METHOD view_performCrossFadeTransitionToStickerConfiguration:fallbackPose:duration:avatar:avatarNode:oldReversionContext:completionHandler:simultaneousAnimationsBlock: v80@0:8@16@24d32@40@48@56@?64@?72

=== CLASS AVTRendererViewTransitionTechnique ===
SUPER: NSObject
SIZE: 136
PROTOCOLS: AVTRendererTechnique
IVAR +8 0 _viewIsOpaque B
IVAR +12 0 _framebufferTextureOpacity f
IVAR +16 0 _snapshotTexture @"<MTLTexture>"
IVAR +24 0 _helper @"AVTMetalHelper"
IVAR +32 0 _renderPipelineState @"<MTLRenderPipelineState>"
IVAR +40 0 _renderPipelineStateDescriptor {?="color0PixelFormat"Q"depthPixelFormat"Q"colorBlendingEnabled"B"colorRGBBlendOperation"Q"colorSourceRGBBlendFactor"Q"colorDestinationRGBBlendFactor"Q"colorAlphaBlendOperation"Q"colorSourceAlphaBlendFactor"Q"colorDestinationAlphaBlendFactor"Q"vertexFunctionName"@"NSString""fragmentFunctionName"@"NSString""rasterSampleCount"Q}
METHOD .cxx_destruct v16@0:8
METHOD snapshotTexture @16@0:8
METHOD encodeTechniqueCommandsForRenderer:atTime:helper: v40@0:8@16d24@32
METHOD framebufferTextureOpacity f16@0:8
METHOD initWithWorldRenderer: @24@0:8@16
METHOD rebuildRenderPipelineStateIfNeededForPixelFormat: v24@0:8Q16
METHOD setFramebufferTextureOpacity: v20@0:8f16
METHOD setSnapshotTexture: v24@0:8@16
METHOD techniqueIsActive B16@0:8
METHOD techniqueUsesExtraRenderTargetForRenderer:pixelFormat: B32@0:8@16^Q24
METHOD techniqueUsesSpecificMainPassClearColorForRenderer:clearColor: B32@0:8@16^24

