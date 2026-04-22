
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

=== CLASS AVTAnimojiDescriptor ===
SUPER: AVTAvatarDescriptor
SIZE: 16
IVAR +8 0 _name @"NSString"
CMETHOD supportsSecureCoding B16@0:8
CMETHOD classIdentifier C16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD name @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithName: @24@0:8@16
METHOD setName: v24@0:8@16
METHOD initWithDictionaryRepresentation:error: @32@0:8@16^@24
METHOD encodeInDictionaryRepresentation: v24@0:8@16
METHOD initWithAnimoji: @24@0:8@16

=== CLASS AVTAsset ===
SUPER: NSObject
SIZE: 176
IVAR +8 0 _identifier @"NSString"
IVAR +16 0 _resourcePath @"NSString"
IVAR +24 0 _componentType q
IVAR +32 0 _resourceType C
IVAR +40 0 _morphVariantDependencies @"NSDictionary"
IVAR +48 0 _imageVariantDependencies @"NSDictionary"
IVAR +56 0 _materialVariantDependencies @"NSDictionary"
IVAR +64 0 _editableColorCount Q
IVAR +72 0 _ambientOcclusion @"NSString"
IVAR +80 0 _highlights @"NSDictionary"
IVAR +88 0 _refCount Q
IVAR +96 0 _cachedResource @
IVAR +104 0 _cacheLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +108 0 _forceHighTessellation B
IVAR +112 0 _specializationSettings @"NSDictionary"
IVAR +120 0 _layers @"NSDictionary"
IVAR +128 0 _wrapDeformerDriverNames @"NSDictionary"
IVAR +136 0 _perAssetMain @"NSDictionary"
IVAR +144 0 _uvRemappingInfo {?="mirroringEnabled"B"transform"{?="columns"[3]}}
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD identifier @16@0:8
METHOD layers @16@0:8
METHOD componentType q16@0:8
METHOD ambientOcclusion @16@0:8
METHOD uvRemappingInfo {?=B{?=[3]}}16@0:8
METHOD assetImageForAsset: @24@0:8@16
METHOD decrUseCount v16@0:8
METHOD editableColorCount Q16@0:8
METHOD enumerateVariantDependenciesOfKind:block: v32@0:8Q16@?24
METHOD freeCache v16@0:8
METHOD incrUseCount v16@0:8
METHOD initWithType:identifier:path: @40@0:8q16@24@32
METHOD instantiateResource @16@0:8
METHOD is2DAsset B16@0:8
METHOD is3DAsset B16@0:8
METHOD resourceByCachingIfNeeded: @20@0:8B16
METHOD specializationSettings @16@0:8

=== CLASS AVTAssetLibrary ===
SUPER: NSObject
SIZE: 680
IVAR +8 0 _assets [42@"NSMutableArray"]
IVAR +344 0 _assetsByName [42@"NSMutableDictionary"]
CMETHOD sharedAssetLibrary @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD reload v16@0:8
METHOD assetWithType:identifier: @32@0:8q16@24

=== CLASS AVTAssetResourceCache ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _resources @"NSMapTable"
IVAR +16 0 _policy Q
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD policy Q16@0:8
METHOD setPolicy: v24@0:8Q16
METHOD retainAsset: v24@0:8@16
METHOD releaseAsset: v24@0:8@16
METHOD resourceForAsset: @24@0:8@16

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

=== CLASS AVTAvatarBodyPose ===
SUPER: NSObject
SIZE: 16
IVAR +8 0 _dictionaryRepresentation @"NSDictionary"
CMETHOD neutralPose @16@0:8
CMETHOD posesInPosePack: @24@0:8@16
METHOD .cxx_destruct v16@0:8
METHOD dictionaryRepresentation @16@0:8
METHOD initWithDictionaryRepresentation: @24@0:8@16
METHOD _applyBodyPoseWithDictionaryRepresentation:skeletonRootJoint: v32@0:8@16@24
METHOD _applyBodyPoseWithDictionaryRepresentationA:dictionaryRepresentationB:dictionaryRepresentationC:dictionaryRepresentationD:variantIntensityX:variantIntensityY:skeletonRootJoint: v64@0:8@16@24@32@40f48f52@56
METHOD _applyBodyPoseWithDictionaryRepresentationA:dictionaryRepresentationB:variantIntensity:skeletonRootJoint: v44@0:8@16@24f32@36
METHOD applyToBodySkeletonWithRootJoint:ageBodyPoseVariantIntensity:shoulderWidthBodyPoseVariantIntensity: v32@0:8@16f24f28
METHOD initWithSceneKitHierarchy: @24@0:8@16
METHOD initWithSceneKitRootJoints: @24@0:8@16
METHOD initWithSceneKitSceneAtURL: @24@0:8@16

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

=== CLASS AVTAvatarDidUpdateAtTimeCallbackItem ===
SUPER: NSObject
SIZE: 40
IVAR +8 0 _firstExecutionHasCompleted B
IVAR +16 0 _firstExecutionTime d
IVAR +24 0 _key @"NSString"
IVAR +32 0 _block @?
METHOD .cxx_destruct v16@0:8

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

=== CLASS AVTAvatarPhysicalizedPose ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _pose @"AVTAvatarPose"
IVAR +16 0 _physicsStates @"NSDictionary"
METHOD .cxx_destruct v16@0:8
METHOD pose @16@0:8
METHOD initWithPoseRepresentation:physicsStatesRepresentation: @32@0:8@16@24
METHOD physicsStates @16@0:8
METHOD initWithPose:physicsStates: @32@0:8@16@24
METHOD applyToAvatar: v24@0:8@16
METHOD applyWithTransitionToAvatar:duration:completionHandler: v40@0:8@16d24@?32
METHOD initWithSceneKitSceneAtURL: @24@0:8@16

=== CLASS AVTAvatarPhysicsState ===
SUPER: NSObject
SIZE: 16
IVAR +8 0 _dictionaryRepresentation @"NSDictionary"
METHOD .cxx_destruct v16@0:8
METHOD dictionaryRepresentation @16@0:8
METHOD initWithDictionaryRepresentation: @24@0:8@16

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

=== CLASS AVTCameraEffectsKitRenderer ===
SUPER: AVTRenderer
SIZE: 472

=== CLASS AVTClassicPresentationConfiguration ===
SUPER: AVTPresentationConfiguration
SIZE: 16
CMETHOD sharedConfiguration @16@0:8
METHOD init @16@0:8

=== CLASS AVTColorPreset ===
SUPER: NSObject
SIZE: 80
IVAR +8 0 _name @"NSString"
IVAR +16 0 _category q
IVAR +24 0 _propertyColors @"NSDictionary"
IVAR +32 0 _derivedColors @"NSDictionary"
IVAR +40 0 _previewColor @"AVTVaryingColor"
IVAR +48 0 _previewAccentColor @"AVTVaryingColor"
IVAR +56 0 _previewAccentType Q
IVAR +64 0 _variation f
IVAR +72 0 _material @"AVTMaterial"
CMETHOD colorPresetWithName:category:colorIndex:variation: @44@0:8@16q24Q32f40
CMETHOD colorPresetWithName:category:variation: @36@0:8@16q24f32
CMETHOD colorPresetsForCategory:colorIndex: @32@0:8q16Q24
CMETHOD _colorPresetsForCategory:palette: @32@0:8q16@24
CMETHOD colorPresetWithName:category: @32@0:8@16q24
CMETHOD colorPresetsForCategory: @24@0:8q16
CMETHOD fallbackColorPresetForNilPresetAndCategory:colorIndex: @32@0:8q16Q24
CMETHOD secondaryColorPresetWithName:category:variation: @36@0:8@16q24f32
CMETHOD secondaryColorPresetsForCategory: @24@0:8q16
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD isEqual: B24@0:8@16
METHOD name @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD category q16@0:8
METHOD localizedName @16@0:8
METHOD thumbnail @16@0:8
METHOD baseColor @16@0:8
METHOD variation f16@0:8
METHOD colorPresetWithVariation: @20@0:8f16
METHOD derivedColorNameForPresetCategory: @24@0:8q16
METHOD gradientLayerWithRangeMin:max:withSkinColor: @32@0:8f16f20@24
METHOD renderColorIntoCALayer:withSkinColor: v32@0:8@16@24
METHOD enumerateDerivedColorPresetsUsingBlock: v24@0:8@?16
METHOD gradientLayerWithRangeMin:max: @24@0:8f16f20
METHOD initWithCategory:description: @32@0:8q16@24
METHOD isNaturalLipsColor B16@0:8
METHOD makeMaterial @16@0:8
METHOD previewAccentColor @16@0:8
METHOD previewColor @16@0:8
METHOD shouldBlendWithSkinColor B16@0:8

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

=== CLASS AVTComponentInstance ===
SUPER: NSObject
SIZE: 80
IVAR +8 0 _assets @"NSArray"
IVAR +16 0 _assetNode @"VFXNode"
IVAR +24 0 _materialVariant @"NSString"
IVAR +32 0 _assetImage @"NSString"
IVAR +40 0 _assetImageVariant @"NSString"
IVAR +48 0 _skinnerVariantIntensity f
IVAR +52 0 _didInitializeVariantSkinnerPairs B
IVAR +56 0 _variantSkinnerPairs @"NSMapTable"
IVAR +64 0 _visibilityRules @"NSMutableDictionary"
IVAR +72 0 _layers @"NSDictionary"
METHOD .cxx_destruct v16@0:8
METHOD assetImage @16@0:8
METHOD uvRemappingInfo {?=B{?=[3]}}16@0:8
METHOD _initializeVariantSkinnerPairsIfNeeded v16@0:8
METHOD assetImageForAsset: @24@0:8@16
METHOD assetImageWithLayerNamed: @24@0:8@16
METHOD assetNode @16@0:8
METHOD has2DAsset B16@0:8
METHOD has3DAsset B16@0:8
METHOD initWithComponent:assetResourceCache: @32@0:8@16@24
METHOD setImageVariant: v24@0:8@16
METHOD setMaterialVariant: v24@0:8@16
METHOD setSkinnerVariantIntensity:skeleton: v28@0:8f16@20
METHOD setVisibilityRules:dictatedByCategory: v32@0:8@16q24
METHOD updateMaterialsWithComponent: v24@0:8@16

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

=== CLASS AVTCompositorPipeline ===
SUPER: NSObject
SIZE: 40
IVAR +8 0 _isAffectedBySkin B
IVAR +9 0 _shouldCompositeAgainDueToGPUError B
IVAR +16 0 _affectingComponentsMask Q
IVAR +24 0 _bindings @"NSArray"
IVAR +32 0 _pipelineState @"<MTLComputePipelineState>"
METHOD .cxx_destruct v16@0:8
METHOD initWithFunction: @24@0:8@16
METHOD compositeTexture:forMemoji:considerSkin:componentsToConsider:computeCommandHandler:blitCommandHandler:completionHandler:helper:helperTokens: v84@0:8@16@24B32Q36@?44@?52@?60@68@76

=== CLASS AVTCompositorPipelineCache ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _helper @"AVTMetalHelper"
IVAR +16 0 _pipelines @"NSMutableDictionary"
CMETHOD pipelineForPropertyName:device: @32@0:8@16@24
METHOD .cxx_destruct v16@0:8
METHOD initWithMetalHelper: @24@0:8@16
METHOD pipelineForPropertyName: @24@0:8@16

=== CLASS AVTCompositorTextureProvider ===
SUPER: NSObject
SIZE: 72
PROTOCOLS: VFXMaterialPropertyTextureProvider
IVAR +8 0 _memoji @"AVTMemoji"
IVAR +16 0 _compositor @"AVTCompositor"
IVAR +24 0 _pipeline @"AVTCompositorPipeline"
IVAR +32 0 _propertyName @"NSString"
IVAR +40 0 _skinIsDirty B
IVAR +48 0 _componentDirtyMask Q
IVAR +56 0 _helperTokens @"NSMutableSet"
IVAR +64 0 _lastRenderedTexture @"<MTLTexture>"
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD newTextureForDevice: @24@0:8@16
METHOD renderToTexture:computeCommandHandler:blitCommandHandler:completionHandler:helper: v56@0:8@16@?24@?32@?40@48
METHOD componentDidChangeForTypes: v24@0:8Q16
METHOD initWithCompositor:memoji:propertyName: @40@0:8@16@24@32
METHOD skinColorDidChange v16@0:8

=== CLASS AVTEyeSkinningDescriptor ===
SUPER: NSObject
SIZE: 96
IVAR +8 0 _readMorpher @"VFXMorpher"
IVAR +16 0 _leftEyeJoint @"VFXNode"
IVAR +24 0 _rightEyeJoint @"VFXNode"
IVAR +32 0 _leftEyeLookDownTargetIndex q
IVAR +40 0 _leftEyeLookInTargetIndex q
IVAR +48 0 _leftEyeLookOutTargetIndex q
IVAR +56 0 _leftEyeLookUpTargetIndex q
IVAR +64 0 _rightEyeLookDownTargetIndex q
IVAR +72 0 _rightEyeLookInTargetIndex q
IVAR +80 0 _rightEyeLookOutTargetIndex q
IVAR +88 0 _rightEyeLookUpTargetIndex q
METHOD .cxx_destruct v16@0:8

=== CLASS AVTFaceTrackingInfo ===
SUPER: NSObject
SIZE: 496
IVAR +16 0 _trackingData {?="timestamp"d"translation""orientation""cameraSpace"B"blendShapeWeights_smooth"[51f]"blendShapeWeights_raw"[51f]"parameters_smooth"[1f]"parameters_raw"[1f]}
CMETHOD trackingInfoWithTrackingData: @24@0:8^{?=dB[51f][51f][1f][1f]}16
METHOD trackingData r^{?=dB[51f][51f][1f][1f]}16@0:8

=== CLASS AVTHUDView ===
SUPER: UIView
SIZE: 592
IVAR +408 0 _totalLatencyLabel @"UILabel"
IVAR +416 0 _arKitLatencyLabel @"UILabel"
IVAR +424 0 _updateSyncLatencyLabel @"UILabel"
IVAR +432 0 _metalLatencyLabel @"UILabel"
IVAR +440 0 _fpsLabel @"UILabel"
IVAR +448 0 _audioTimeLabel @"UILabel"
IVAR +456 0 _timeBetweenARFrameLabel @"UILabel"
IVAR +464 0 _droppedFrameLabel @"UILabel"
IVAR +472 0 _shaderCompilationLabel @"UILabel"
IVAR +480 0 _lastFrameData {?="totalLatency"d"arKitLatency"d"updateSyncLatency"d"metalLatency"d"timeBetweenARFrame"d"fps"I"audioTime"d"droppedFrame"I"doubleBuffer"B"onlineShaderCompilationCount"I}
IVAR +552 0 _arKitLatencyBar @"CALayer"
IVAR +560 0 _updateLatencyBar @"CALayer"
IVAR +568 0 _metalLatencyBar @"CALayer"
IVAR +576 0 _totalLatencyGraphLayers @"NSMutableArray"
IVAR +584 0 _selectedGraphIndex i
METHOD .cxx_destruct v16@0:8
METHOD initWithFrame: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD updateWithData: v88@0:8{?=dddddIdIBI}16
METHOD _label @16@0:8
METHOD _tapAction: v24@0:8@16
METHOD layoutSubviews v16@0:8
METHOD _loadSubviews v16@0:8
METHOD _updateLatencyBar: v24@0:8^{?=dddddIdIBI}16
METHOD _updateLatencyGraph: v24@0:8^{?=dddddIdIBI}16

=== CLASS AVTImageUtilities ===
SUPER: NSObject
SIZE: 8
CMETHOD transparencyInsetsForImage:requiringFullOpacity: {UIEdgeInsets=dddd}28@0:8^{CGImage=}16B24
CMETHOD trimmedImageByTrimmingTransparentPixelsFromImage: @24@0:8@16
CMETHOD trimmedImageByTrimmingTransparentPixelsFromImage:requiringFullOpacity: @28@0:8@16B24
CMETHOD _transparencyInsetsForUInt8AlphaContext:requiringFullOpacity: {UIEdgeInsets=dddd}28@0:8^{CGContext=}16B24
CMETHOD cropImageWhitespace:outsideRect:insideRect:resultBlock: v96@0:8^{CGImage=}16{CGRect={CGPoint=dd}{CGSize=dd}}24{CGRect={CGPoint=dd}{CGSize=dd}}56@?88
CMETHOD posterWithStickerImage:posterSize:minimumHorizontalMargin:thumbnailRect:allowsExtraTallContent:expectsExtraTallContent:resultBlock: v92@0:8^{CGImage=}16{CGSize=dd}24f40{CGRect={CGPoint=dd}{CGSize=dd}}44B76B80@?84
CMETHOD transparencyInsetsForImage:imageRect:requiringFullOpacity: {UIEdgeInsets=dddd}60@0:8^{CGImage=}16{CGRect={CGPoint=dd}{CGSize=dd}}24B56

=== CLASS AVTMassSpringDamperSystem ===
SUPER: NSObject
SIZE: 56
IVAR +8 0 _mass f
IVAR +12 0 _stiffness f
IVAR +16 0 _damping f
IVAR +20 0 _velocity f
IVAR +24 0 _allowsOverdamping B
IVAR +32 0 w0 d
IVAR +40 0 zeta d
IVAR +48 0 wd d
METHOD init @16@0:8
METHOD _updateParameters v16@0:8

=== CLASS AVTMaterial ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _baseColor @"UIColor"
IVAR +16 0 _additionalPropertyColors @"NSDictionary"
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD baseColor @16@0:8
METHOD setBaseColor: v24@0:8@16
METHOD additionalPropertyColors @16@0:8
METHOD applyToVFXMaterial: v24@0:8@16
METHOD setAdditionalPropertyColors: v24@0:8@16

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

=== CLASS AVTMemojiBodyController ===
SUPER: NSObject
SIZE: 160
IVAR +8 0 _bodyJoints @"NSMutableArray"
IVAR +16 0 _leftHandJoints @"NSMutableArray"
IVAR +24 0 _rightHandJoints @"NSMutableArray"
IVAR +32 0 _bodyRoot @"VFXNode"
IVAR +40 0 _leftHand @"VFXNode"
IVAR +48 0 _rightHand @"VFXNode"
IVAR +56 0 _leftHandModel @"VFXNode"
IVAR +64 0 _rightHandModel @"VFXNode"
IVAR +80 0 spine0_originalOrientation {?="vector"}
IVAR +96 0 r_shoulderNeutralSrcInv {?="vector"}
IVAR +112 0 l_shoulderNeutralSrcInv {?="vector"}
IVAR +128 0 r_shoulderNeutralDst {?="vector"}
IVAR +144 0 l_shoulderNeutralDst {?="vector"}
METHOD .cxx_destruct v16@0:8

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

=== CLASS AVTMemojiWrapDeformerDriverInfo ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _driverNodes @"NSMutableDictionary"
IVAR +16 0 _driverStates @"NSMutableDictionary"
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8

=== CLASS AVTMetalHelper ===
SUPER: NSObject
SIZE: 56
IVAR +8 0 _device @"<MTLDevice>"
IVAR +16 0 _library @"<MTLLibrary>"
IVAR +24 0 _lock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +32 0 _functions @"NSMutableDictionary"
IVAR +40 0 _renderPipelineStates @"NSMutableDictionary"
IVAR +48 0 _computePipelineStates @"NSMutableDictionary"
METHOD .cxx_destruct v16@0:8
METHOD _initWithDevice: @24@0:8@16
METHOD _locked_computePipelineStateWithFunctionName: @24@0:8@16
METHOD _locked_functionNamed: @24@0:8@16
METHOD _locked_instanciateLibraryIfNeeded v16@0:8
METHOD _locked_renderPipelineStateWithDescriptor:hashNumber: @120@0:8{?=QQBQQQQQQ@@Q}16@112

=== CLASS AVTMorpherDrivenMaterialDescriptor ===
SUPER: NSObject
SIZE: 48
IVAR +8 0 _readMorpher @"VFXMorpher"
IVAR +16 0 _readMorpherNode @"VFXNode"
IVAR +24 0 _morphTargetIndex q
IVAR +32 0 _material @"VFXMaterial"
IVAR +40 0 _propertyName @"NSString"
METHOD .cxx_destruct v16@0:8

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

=== CLASS AVTPhysicsRig ===
SUPER: NSObject
SIZE: 208
IVAR +8 0 _coneConstraintLength f
IVAR +12 0 _coneConstraintSinusAngularLimit f
IVAR +16 0 _rig @"VFXNode"
IVAR +24 0 _chainRoot @"VFXNode"
IVAR +32 0 _physicsBody @"VFXPhysicsBody"
IVAR +40 0 _physicsBehavior @"VFXPhysicsConeTwistJoint"
IVAR +48 0 _downForceFactor d
IVAR +64 0 _restPosition_chainRoot 
IVAR +80 0 _restGravityVector_chainRoot 
IVAR +96 0 _coneConstraintBasis_chainParent {?="columns"[3]}
IVAR +144 0 _coneConstraintAnchorB {?="columns"[4]}
METHOD .cxx_destruct v16@0:8

=== CLASS AVTPresentationConfiguration ===
SUPER: NSObject
SIZE: 16
IVAR +8 0 _style Q
METHOD init @16@0:8
METHOD _initWithStyle: @24@0:8Q16
METHOD internalStyle Q16@0:8
METHOD usesAR B16@0:8

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

=== CLASS AVTPresetDependency ===
SUPER: NSObject
SIZE: 64
IVAR +8 0 _morphVariantIntensity f
IVAR +16 0 _category q
IVAR +24 0 _preset @"AVTPreset"
IVAR +32 0 _morphVariant @"NSString"
IVAR +40 0 _imageVariant @"NSString"
IVAR +48 0 _materialVariant @"NSString"
IVAR +56 0 _visibilityRules @"NSDictionary"
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8

=== CLASS AVTPresetStore ===
SUPER: NSObject
SIZE: 976
IVAR +8 0 _presets [40@"AVTPreset"]
IVAR +328 0 _resolvedPresets [40@"AVTPreset"]
IVAR +648 0 _unresolvedDependencies [40@"NSMutableArray"]
IVAR +968 0 _unresolvedDependencyCount Q
METHOD debugDescription @16@0:8
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD hasUnresolvedDependenciesForCategory: B24@0:8q16
METHOD registerDependenciesForPreset:previouslyRegisteredPresets: v32@0:8@16@24
METHOD solveDependencies Q16@0:8
METHOD solveDependenciesForCategory: v24@0:8q16

=== CLASS AVTPresetStoreDependency ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _overridePreset @"AVTPreset"
IVAR +16 0 _conditions @"NSMutableArray"
METHOD .cxx_destruct v16@0:8
METHOD conditions @16@0:8
METHOD setConditions: v24@0:8@16
METHOD addConditionOnPreset: v24@0:8@16
METHOD addConditionOnPreset:forSpecificPresetIdentifier: v32@0:8@16@24
METHOD initWithOverridePreset:conditionedOnPreset: @32@0:8@16@24
METHOD initWithOverridePreset:conditionedOnPreset:forSpecificPresetIdentifier: @40@0:8@16@24@32
METHOD overridePreset @16@0:8
METHOD setOverridePreset: v24@0:8@16

=== CLASS AVTPresetStoreDependencyCondition ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _presetOfOtherCategory @"AVTPreset"
IVAR +16 0 _specificPresetIdentifier @"NSString"
METHOD .cxx_destruct v16@0:8
METHOD displayString @16@0:8
METHOD presetOfOtherCategory @16@0:8
METHOD setPresetOfOtherCategory: v24@0:8@16
METHOD setSpecificPresetIdentifier: v24@0:8@16
METHOD specificPresetIdentifier @16@0:8

=== CLASS AVTPupilReflectionCorrectionDescriptor ===
SUPER: NSObject
SIZE: 48
IVAR +8 0 _readMorpher @"VFXMorpher"
IVAR +16 0 _leftEyeMaterial @"VFXMaterial"
IVAR +24 0 _rightEyeMaterial @"VFXMaterial"
IVAR +32 0 _leftEyeTargetIndex q
IVAR +40 0 _rightEyeTargetIndex q
METHOD .cxx_destruct v16@0:8

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

=== CLASS AVTRenderer ===
SUPER: VFXRenderer
SIZE: 472
PROTOCOLS: _VFXWorldCommandBufferStatusMonitor _VFXWorldRendererResourceManagerMonitor VFXWorldRendererDelegate _VFXWorldRendererDelegateSPI AVTRendererTechniqueSupport AVTSceneRenderer AVTWorldRenderer
IVAR +392 0 _environment @"AVTAvatarEnvironment"
IVAR +400 0 _presentationConfiguration @"AVTPresentationConfiguration"
IVAR +408 0 _avatar @"AVTAvatar"
IVAR +416 0 _avatarNode @"VFXNode"
IVAR +424 0 _lock @"NSLock"
IVAR +432 0 _pauseSimulation B
IVAR +433 0 _warmingUp B
IVAR +440 0 _antialiasingMode Q
IVAR +448 0 _avtRendererTechnique @"<AVTRendererTechnique>"
IVAR +456 0 _avtRendererTechniquePresentationTree @"<AVTRendererTechnique>"
IVAR +464 0 _backgroundContentsBehindDrawable @
CMETHOD renderer @16@0:8
CMETHOD _cek_renderer @16@0:8
CMETHOD _cek_rendererWithDevice:options: @32@0:8@16@24
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD isWarmingUp B16@0:8
METHOD setWarmingUp: v20@0:8B16
METHOD presentationConfiguration @16@0:8
METHOD scene @16@0:8
METHOD avatar @16@0:8
METHOD setAvatar: v24@0:8@16
METHOD _customMainPassPostProcessUsesExtraRenderTargetForRenderer:pixelFormat: B32@0:8@16^Q24
METHOD _encodeCustomMainPassPostProcessForRenderer:atTime:helper: v40@0:8@16d24@32
METHOD _renderer:didApplyAnimationsAtTime: v32@0:8@16d24
METHOD _renderer:didBuildSubdivDataForHash:dataProvider: v40@0:8@16@24@?32
METHOD _renderer:subdivDataForHash: @32@0:8@16@24
METHOD _renderer:updateAtTime: v32@0:8@16d24
METHOD _usesSpecificMainPassClearColorForRenderer:clearColor: B32@0:8@16^24
METHOD _wantsCustomMainPassPostProcessForRenderer: B24@0:8@16
METHOD renderer:commandBufferDidCompleteWithError: v32@0:8@16@24
METHOD renderer:didFallbackToDefaultTextureForSource:message: v40@0:8@16@24@32
METHOD setFramingMode: v24@0:8@16
METHOD framingMode @16@0:8
METHOD _implementCEKWorkaroundIfNeeded v16@0:8
METHOD avatarDidChange v16@0:8
METHOD __setAvatar: v24@0:8@16
METHOD _avatarWantsSpecificTechniqueDidChange: v24@0:8@16
METHOD _avtSetupWithOptions: v24@0:8@16
METHOD _avtUpdateRendersContinuously v16@0:8
METHOD _cek_applyBlendshapeWeightsInHierarchyUsingBlock: v24@0:8@?16
METHOD _cek_beginTransaction v16@0:8
METHOD _cek_commitTransaction v16@0:8
METHOD _cek_currentPointOfViewSensorHeight f16@0:8
METHOD _cek_fetchBlendshapeWeightsInHierarchyUsingBlock: v24@0:8@?16
METHOD _cek_renderAtTime:enableAntialiasing:viewport:commandBuffer:passDescriptor: v76@0:8d16B24{CGRect={CGPoint=dd}{CGSize=dd}}28@60@68
METHOD _cek_setCurrentPointOfViewFocalLength: v20@0:8f16
METHOD _detachAvatarFromRenderer v16@0:8
METHOD _initWithDevice:options:isPrivateRenderer:privateRendererOwner:clearsOnDraw: @48@0:8@16@24B32@36B44
METHOD _setAvatar: v24@0:8@16
METHOD avtRendererTechnique @16@0:8
METHOD avt_antialiasingMode Q16@0:8
METHOD backgroundContentsBehindDrawable @16@0:8
METHOD crashAppExtensionOrViewService_rdar98130076: v24@0:8@?16
METHOD deprecated_ntk_isPaused B16@0:8
METHOD deprecated_ntk_setPaused: v20@0:8B16
METHOD deprecated_ntk_setPhysicsWorldTimeStep: v20@0:8f16
METHOD fadePuppetToWhite: v20@0:8f16
METHOD setAvtRendererTechnique: v24@0:8@16
METHOD setAvt_antialiasingMode: v24@0:8Q16
METHOD setBackgroundContentsBehindDrawable: v24@0:8@16
METHOD setFramingModeForcingPointOfViewUpdate: v24@0:8@16
METHOD setPresentationConfiguration: v24@0:8@16

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

=== CLASS AVTRenderer_CEKWorkaround ===
SUPER: AVTRenderer
SIZE: 472
METHOD scene @16@0:8
METHOD pointOfView @16@0:8

=== CLASS AVTResourceLocator ===
SUPER: NSObject
SIZE: 88
IVAR +8 0 _imageCache @"NSMutableDictionary"
IVAR +16 0 _resourcesURL @"NSURL"
IVAR +24 0 _environmentResourcesURL @"NSURL"
IVAR +32 0 _animojiResourcesURL @"NSURL"
IVAR +40 0 _memojiResourcesURL @"NSURL"
IVAR +48 0 _stickerResourcesURL @"NSURL"
IVAR +56 0 _poseResourcesURL @"NSURL"
IVAR +64 0 _memojiAssetsURL @"NSURL"
IVAR +72 0 _rootCacheURL @"NSURL"
IVAR +80 0 _subdivDataCacheURL @"NSURL"
CMETHOD _resourcePathInDirectoryURL:subDirectory:name:ofType:isDirectory: @52@0:8@16@24@32@40B48
METHOD .cxx_destruct v16@0:8
METHOD _init @16@0:8
METHOD deleteLegacyCache v16@0:8
METHOD deleteObsoleteVersionsInCache:currentVersion: v32@0:8@16Q24
METHOD initCaches v16@0:8

=== CLASS AVTSkinnerVariantPair ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _originalSkinner @"VFXSkinner"
IVAR +16 0 _variantSkinner @"VFXSkinner"
METHOD .cxx_destruct v16@0:8

=== CLASS AVTSnapshotBuilder ===
SUPER: NSObject
SIZE: 40
IVAR +8 0 _avatar @"AVTAvatar"
IVAR +16 0 _snapshotedAvatar @"AVTAvatar"
IVAR +24 0 _renderer @"AVTRenderer"
IVAR +32 0 _snapshotHelper @"AVTSnapshotHelper"
CMETHOD sharedInstance @16@0:8
CMETHOD copyRescaledCGImage:by: ^{CGImage=}28@0:8^{CGImage=}16f24
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD avatar @16@0:8
METHOD setAvatar: v24@0:8@16
METHOD renderer @16@0:8
METHOD deprecated_avtui_applyModificationsForFramingMode:projectionDirectionModification:fieldOfViewModification:lensShiftModification: v48@0:8@16q24d3240
METHOD deprecated_avtui_fieldOfViewForFramingMode: d24@0:8@16
METHOD imageWithSize:scale:options: @48@0:8{CGSize=dd}16d32@40
METHOD _applyOptions: v24@0:8@16
METHOD _imageWithSize:scale:options: @48@0:8{CGSize=dd}16d32@40
METHOD _imageWithSize:scale:options:useACopy: @52@0:8{CGSize=dd}16d32@40B48
METHOD animatedImageWithSize:scale:options: @48@0:8{CGSize=dd}16d32@40
METHOD setupAvatarWithOptions:useACopy: v28@0:8@16B24

=== CLASS AVTSnapshotHelper ===
SUPER: NSObject
SIZE: 144
IVAR +8 0 _device @"<MTLDevice>"
IVAR +16 0 _commandQueue @"<MTLCommandQueue>"
IVAR +24 0 _renderPassDescriptor @"MTLRenderPassDescriptor"
IVAR +32 0 _supportsReadWriteTexture B
IVAR +40 0 _convertPremultipliedAlphaTexture @"<MTLTexture>"
IVAR +48 0 _convertPremultipliedAlphaTextureView @"<MTLTexture>"
IVAR +56 0 _convertPremultipliedAlphaExtraTexture @"<MTLTexture>"
IVAR +64 0 _convertPremultipliedAlphaPipelineState @"<MTLComputePipelineState>"
IVAR +72 0 _pixelWidth Q
IVAR +80 0 _pixelHeight Q
IVAR +88 0 _antialiasingMode Q
IVAR +96 0 _backgroundColor @"UIColor"
IVAR +104 0 _backgroundColorForMetal {?="red"d"green"d"blue"d"alpha"d}
IVAR +136 0 _bitmapContext ^{CGContext=}
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD _isRenderPassDescriptorValid B16@0:8
METHOD _rebuildBitmapContextIfNeeded v16@0:8
METHOD _rebuildRenderPassDescriptorIfNeeded v16@0:8

=== CLASS AVTSpringDynamic ===
SUPER: NSObject
SIZE: 168
PROTOCOLS: AVTAvatarDynamic
IVAR +8 0 _dynamicNode @"VFXNode"
IVAR +16 0 _dynamicPresentationNode @"VFXNode"
IVAR +24 0 _dynamicParentPresentationNode @"VFXNode"
IVAR +32 0 _targetPresentationNode @"VFXNode"
IVAR +40 0 _hasMaxOffsets B
IVAR +48 0 _maxOffsets 
IVAR +64 0 _system @"AVTMassSpringDamperSystem"
IVAR +72 0 _beginTime d
IVAR +80 0 _beginVelocity 
IVAR +96 0 _beginWorldPosition 
IVAR +112 0 _endWorldPosition 
IVAR +128 0 _lastEvaluationTime d
IVAR +144 0 _lastWorldPosition 
IVAR +160 0 _shouldReset B
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD affectsNode: B24@0:8@16
METHOD evaluateAtTime:physicsController: v32@0:8d16@24
METHOD resetTarget v16@0:8

=== CLASS AVTStickerCamera ===
SUPER: NSObject
SIZE: 16
IVAR +8 0 _node @"VFXNode"
CMETHOD cameraFromDictionary:assetsPath: @32@0:8@16@24
CMETHOD stickerCameraCache @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD node @16@0:8
METHOD setNode: v24@0:8@16
METHOD buildNode @16@0:8
METHOD initWithCameraNode: @24@0:8@16

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

=== CLASS AVTStickerConfigurationReversionContext ===
SUPER: NSObject
SIZE: 96
IVAR +8 0 _scene @"VFXWorld"
IVAR +16 0 _avatar @"AVTAvatar"
IVAR +24 0 _presetOverrides @"NSMutableArray"
IVAR +32 0 _morpherOverrides @"NSMutableArray"
IVAR +40 0 _shaderModifiers @"NSMapTable"
IVAR +48 0 _customMaterialProperties @"NSMapTable"
IVAR +56 0 _singleSidedMaterials @"NSMutableArray"
IVAR +64 0 _extraCameraNode @"VFXNode"
IVAR +72 0 _extraPropsNode @"VFXNode"
IVAR +80 0 _showMemojiBody @"NSNumber"
IVAR +88 0 _environmentForPointOfViewUpdateFromFramingMode @"AVTAvatarEnvironment"
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD resetForAvatar: v24@0:8@16
METHOD revertChangesWithScope:animationDuration: v32@0:8Q16d24
METHOD saveCustomMaterialPropertyNamed:forMaterial: v32@0:8@16@24
METHOD saveExtraCameraNode: v24@0:8@16
METHOD saveExtraPropsNode: v24@0:8@16
METHOD saveMorpherOverride: v24@0:8@16
METHOD savePresetOverride: v24@0:8@16
METHOD saveShaderModifiers:forMaterial: v32@0:8@16@24
METHOD saveShowMemojiBody: v20@0:8B16
METHOD saveSingleSidedForMaterial: v24@0:8@16
METHOD saveUpdatePointOfViewFromFramingModeInEnvironment: v24@0:8@16

=== CLASS AVTStickerGenerator ===
SUPER: NSObject
SIZE: 56
IVAR +8 0 _renderer @"AVTRenderer"
IVAR +16 0 _snapshotHelper @"AVTSnapshotHelper"
IVAR +24 0 _context @"AVTStickerConfigurationReversionContext"
IVAR +32 0 _workQueue @"NSObject<OS_dispatch_queue>"
IVAR +40 0 _async B
IVAR +48 0 _avatar @"AVTAvatar"
CMETHOD addProps:toScene:forAvatar:withCamera:options:reversionContext: v64@0:8@16@24@32@40@48@56
CMETHOD addCamera:inScene:reversionContext: @40@0:8@16@24@32
CMETHOD applyViewTransitionConfiguration:forLateAdditionOfComponentAssetNode:ofAvatar: v40@0:8@16@24@32
CMETHOD applyViewTransitionConfiguration:toView:scope:options:duration:avatar:context:completionHandler: v80@0:8@16@24Q32Q40d48@56@64@?72
CMETHOD poseByApplyingAdjustmentsForConfiguration:avatar: @32@0:8@16@24
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD avatar @16@0:8
METHOD setAvatar: v24@0:8@16
METHOD async B16@0:8
METHOD setAsync: v20@0:8B16
METHOD initWithAvatar: @24@0:8@16
METHOD stickerImageWithConfiguration:options:completionHandler: v40@0:8@16@24@?32
METHOD _snapshotAtTime:configuration:options:completionBlock: v48@0:8d16@24@32@?40
METHOD _stickerImageWithConfiguration:options:startTime:completionHandler: v48@0:8@16@24d32@?40
METHOD applyConfiguration:options:snapshotBlock: v40@0:8@16@24@?32
METHOD posterWithConfiguration:options:completionHandler: v40@0:8@16@24@?32
METHOD stickerImageWithConfiguration:completionHandler: v32@0:8@16@?24
METHOD stickerImageWithConfiguration:correctClipping:completionHandler: v36@0:8@16B24@?28
METHOD updateConfiguration:atTime: v32@0:8@16d24

=== CLASS AVTStickerGeneratorOptions ===
SUPER: NSObject
SIZE: 64
IVAR +8 0 _posterSizeInPixels {CGSize="width"d"height"d}
IVAR +24 0 _posterMinimumHorizontalMargin f
IVAR +28 0 _useLegacyCorrectClippingImplementation B
IVAR +32 0 _size d
IVAR +40 0 _sizeMultiplier d
IVAR +48 0 _scaleFactor d
IVAR +56 0 _contentMode Q
CMETHOD defaultOptions @16@0:8
CMETHOD optionsWithCorrectClipping: @20@0:8B16
METHOD init @16@0:8
METHOD size d16@0:8
METHOD setScaleFactor: v24@0:8d16
METHOD scaleFactor d16@0:8
METHOD setSize: v24@0:8d16
METHOD contentMode Q16@0:8
METHOD setContentMode: v24@0:8Q16
METHOD setCorrectClipping: v20@0:8B16
METHOD correctClipping B16@0:8
METHOD setSizeMultiplier: v24@0:8d16
METHOD setUseLegacyCorrectClippingImplementation: v20@0:8B16
METHOD sizeMultiplier d16@0:8
METHOD useLegacyCorrectClippingImplementation B16@0:8

=== CLASS AVTStickerGeneratorPosterOptions ===
SUPER: NSObject
SIZE: 48
IVAR +8 0 _growsForExtraTallContent B
IVAR +16 0 _minimumHorizontalMargin d
IVAR +24 0 _scaleFactor d
IVAR +32 0 _size {CGSize="width"d"height"d}
METHOD init @16@0:8
METHOD size {CGSize=dd}16@0:8
METHOD setScaleFactor: v24@0:8d16
METHOD scaleFactor d16@0:8
METHOD setSize: v32@0:8{CGSize=dd}16
METHOD minimumHorizontalMargin d16@0:8
METHOD growsForExtraTallContent B16@0:8
METHOD setGrowsForExtraTallContent: v20@0:8B16
METHOD setMinimumHorizontalMargin: v24@0:8d16

=== CLASS AVTStickerImageProp ===
SUPER: AVTStickerProp
SIZE: 136
IVAR +128 0 _imagePath @"NSString"
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD .cxx_destruct v16@0:8
METHOD imagePath @16@0:8
METHOD buildNodeForAvatar:withCamera:options:completionHandler: v48@0:8@16@24@32@?40
METHOD dictionaryWithTargetPath: @24@0:8@16
METHOD initWithImageAtPath:size:scale:position:renderLast:orientToCamera:rotation:palettesDescriptions:modifiers:adjustments: @120@0:8@16{CGSize=dd}244056B72B7680@96@104@112

=== CLASS AVTStickerMorpherOverride ===
SUPER: NSObject
SIZE: 32
IVAR +8 0 _weight f
IVAR +16 0 _nodeNames @
IVAR +24 0 _morphTargetName @"NSString"
CMETHOD morpherOverrideFromDictionary: @24@0:8@16
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD weight f16@0:8
METHOD morphTargetName @16@0:8
METHOD applyToAvatar:inHierarchy:reversionContext: v40@0:8@16@24@32
METHOD initWithNodeNames:morphTargetName:weight: @36@0:8@16@24f32
METHOD nodeNames @16@0:8

=== CLASS AVTStickerPoseAdjustment ===
SUPER: NSObject
SIZE: 32
IVAR +8 0 _presetCategory q
IVAR +16 0 _presetIdentifier @"NSString"
IVAR +24 0 _pose @"AVTAvatarPose"
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD pose @16@0:8
METHOD setPose: v24@0:8@16
METHOD presetCategory q16@0:8
METHOD presetIdentifier @16@0:8
METHOD poseByApplyingToPose:forAvatar: @32@0:8@16@24
METHOD setPresetCategory: v24@0:8q16
METHOD setPresetIdentifier: v24@0:8@16

=== CLASS AVTStickerPresetOverride ===
SUPER: NSObject
SIZE: 32
IVAR +8 0 _category q
IVAR +16 0 _presetIdentifier @"NSString"
IVAR +24 0 _unlessIdentifiers @"NSArray"
CMETHOD presetOverrideFromDictionary:forCategoryName: @32@0:8@16@24
METHOD .cxx_destruct v16@0:8
METHOD category q16@0:8
METHOD presetIdentifier @16@0:8
METHOD applyToAvatar:reversionContext: v32@0:8@16@24
METHOD initWithCategory:presetIdentifier:unless: @40@0:8q16@24@32
METHOD unlessIdentifiers @16@0:8

=== CLASS AVTStickerProp ===
SUPER: NSObject
SIZE: 128
PROTOCOLS: NSCopying
IVAR +8 0 _orientToCamera B
IVAR +9 0 _renderLast B
IVAR +16 0 _node @"VFXNode"
IVAR +24 0 _originalName @"NSString"
IVAR +32 0 _palettesDescriptions @"NSArray"
IVAR +40 0 _shaderModifiers @"NSArray"
IVAR +48 0 _adjustments @"NSArray"
IVAR +56 0 _opacity d
IVAR +64 0 _size {CGSize="width"d"height"d}
IVAR +80 0 _position 
IVAR +96 0 _scale 
IVAR +112 0 _rotation 
CMETHOD adjustmentFromDictionary:presetCategory: @32@0:8@16@24
CMETHOD applyPalettesForAvatar:toNode:palettesDescriptions: v40@0:8@16@24@32
CMETHOD cacheKeyForSize:position:rotation:scale:palettesDescriptions:filePath: @96@0:8{CGSize=dd}16324864@80@88
CMETHOD getOpacityInDictionary: f24@0:8@16
CMETHOD getOrientToCameraInDictionary: B24@0:8@16
CMETHOD getPositionInDictionary: 24@0:8@16
CMETHOD getRenderLastInDictionary: B24@0:8@16
CMETHOD getRotationInDictionary: 24@0:8@16
CMETHOD getScaleInDictionary: 24@0:8@16
CMETHOD getSizeInDictionary: {CGSize=dd}24@0:8@16
CMETHOD propFromDictionary:assetsPath: @32@0:8@16@24
CMETHOD stickerPropCache @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD .cxx_destruct v16@0:8
METHOD identifier @16@0:8
METHOD displayName @16@0:8
METHOD position 16@0:8
METHOD scale 16@0:8
METHOD setPosition: v32@0:816
METHOD size {CGSize=dd}16@0:8
METHOD setScale: v32@0:816
METHOD opacity d16@0:8
METHOD rotation 16@0:8
METHOD setOpacity: v24@0:8d16
METHOD setRotation: v32@0:816
METHOD node @16@0:8
METHOD setNode: v24@0:8@16
METHOD originalName @16@0:8
METHOD setOriginalName: v24@0:8@16
METHOD adjustments @16@0:8
METHOD nodeName @16@0:8
METHOD shaderModifiers @16@0:8
METHOD setShaderModifiers: v24@0:8@16
METHOD applyCamera:toNode:distToHead: v40@0:8@16@24d32
METHOD buildNodeForAvatar:withCamera:options:completionHandler: v48@0:8@16@24@32@?40
METHOD cloneWithShaderModifiers: @24@0:8@16
METHOD dictionaryWithTargetPath: @24@0:8@16
METHOD initWithSize:scale:position:renderLast:orientToCamera:rotation:palettesDescriptions:shaderModifiers:adjustments: @112@0:8{CGSize=dd}163248B64B6872@88@96@104
METHOD orientToCamera B16@0:8
METHOD palettesDescriptions @16@0:8
METHOD renderLast B16@0:8
METHOD stickerGenerationDidEnd v16@0:8
METHOD stickerGenerationWillBegin v16@0:8
METHOD updateNode:withContentAtTime: v48@0:8@16{?=qiIq}24
METHOD wantsTimedUpdates B16@0:8

=== CLASS AVTStickerPropAdjustTransformProperty ===
SUPER: NSObject
SIZE: 80
IVAR +8 0 _presetCategory q
IVAR +16 0 _presetValue @
IVAR +32 0 _position 
IVAR +48 0 _rotation 
IVAR +64 0 _scale 
METHOD .cxx_destruct v16@0:8
METHOD position 16@0:8
METHOD scale 16@0:8
METHOD rotation 16@0:8
METHOD presetCategory q16@0:8
METHOD applyAdjustmentIfNeededToNode:forMemoji:ignoreScaleZ: v36@0:8@16@24B32
METHOD initWithPresetCategory:presetValue:position:rotation:scale: @80@0:8q16@24324864
METHOD presetValue @16@0:8

=== CLASS AVTStickerSceneProp ===
SUPER: AVTStickerProp
SIZE: 136
IVAR +128 0 _rootNode @"VFXNode"
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD .cxx_destruct v16@0:8
METHOD rootNode @16@0:8
METHOD buildNodeForAvatar:withCamera:options:completionHandler: v48@0:8@16@24@32@?40
METHOD dictionaryWithTargetPath: @24@0:8@16
METHOD initWithRootNode:scale:position:rotation:renderLast:palettesDescriptions:modifiers:adjustments: @100@0:8@16244056B72@76@84@92

=== CLASS AVTStickerShaderModifier ===
SUPER: NSObject
SIZE: 56
IVAR +8 0 _isCropShaderModifier B
IVAR +9 0 _forceDoubleSided B
IVAR +16 0 _entryPoint @"NSString"
IVAR +24 0 _nodeNames @
IVAR +32 0 _data @"NSString"
IVAR +40 0 _properties @"NSArray"
IVAR +48 0 _dictionary @"NSDictionary"
CMETHOD encapsulateShaderData: @24@0:8@16
CMETHOD entryPointForModifierName: @24@0:8@16
CMETHOD shaderModifierCache @16@0:8
CMETHOD shaderModifierFromDictionary:assetsPath: @32@0:8@16@24
METHOD description @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD data @16@0:8
METHOD dictionary @16@0:8
METHOD setDictionary: v24@0:8@16
METHOD properties @16@0:8
METHOD entryPoint @16@0:8
METHOD applyToAllMaterialsOfNode:options:reversionContext: v40@0:8@16@24@32
METHOD applyToMatchedMaterialsOfAvatar:inHierarchy:options:reversionContext: v48@0:8@16@24@32@40
METHOD applyToMaterial:options:reversionContext: v40@0:8@16@24@32
METHOD cloneWithProperties: @24@0:8@16
METHOD dictionaryWithTargetPath: @24@0:8@16
METHOD forceDoubleSided B16@0:8
METHOD initWithEntryPoint:nodeNames:data:properties:forceDoubleSided: @52@0:8@16@24@32@40B48
METHOD nodeNames @16@0:8

=== CLASS AVTStickerShaderModifierProperty ===
SUPER: NSObject
SIZE: 48
IVAR +8 0 _name @"NSString"
IVAR +16 0 _type @"NSString"
IVAR +24 0 _value @
IVAR +32 0 _originalValue @
IVAR +40 0 _effectiveValue @
CMETHOD shaderModifierPropertyCache @16@0:8
CMETHOD shaderModifierPropertyFromDictionary:assetsPath: @32@0:8@16@24
METHOD name @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD type @16@0:8
METHOD value @16@0:8
METHOD originalValue @16@0:8
METHOD setOriginalValue: v24@0:8@16
METHOD dictionaryWithTargetPath: @24@0:8@16
METHOD effectiveValue @16@0:8
METHOD initWithName:type:value:originalValue: @48@0:8@16@24@32@40

=== CLASS AVTVariantBatchSnapshotter ===
SUPER: NSObject
SIZE: 64
IVAR +8 0 _avatar @"AVTAvatar"
IVAR +16 0 _renderer @"AVTRenderer"
IVAR +24 0 _size {CGSize="width"d"height"d}
IVAR +40 0 _scale d
IVAR +48 0 _antialiasingMode Q
IVAR +56 0 _snapshotHelper @"AVTSnapshotHelper"
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD imageWithOptions:modifications: @32@0:8@16@?24
METHOD initWithAvatar:size:scale:antialiasingMode:device: @64@0:8@16{CGSize=dd}24d40Q48@56

=== CLASS AVTVaryingColor ===
SUPER: NSObject
SIZE: 32
IVAR +8 0 _baseColor @"UIColor"
IVAR +16 0 _variationMinColor @"UIColor"
IVAR +24 0 _variationMaxColor @"UIColor"
METHOD .cxx_destruct v16@0:8
METHOD colorByApplyingVariation: @20@0:8f16

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

=== CLASS CAAnimationGroup ===
SUPER: CAAnimation
SIZE: 24
METHOD avt_animationsByUngroupingRecursively @16@0:8
METHOD animations @16@0:8
METHOD setAnimations: v24@0:8@16
METHOD CA_prepareRenderValue v16@0:8
METHOD _copyRenderAnimationForLayer: ^v24@0:8@16
METHOD _propertyFlagsForLayer: I24@0:8@16
METHOD applyForTime:presentationObject:modelObject: v40@0:8d16@24@32
METHOD setDefaultDuration: v24@0:8d16

=== CLASS CABasicAnimation ===
SUPER: CAPropertyAnimation
SIZE: 24
CMETHOD normalizedAnimationWithKeyPath:fromValue:toValue: @40@0:8@16@24@32
METHOD toValue @16@0:8
METHOD fromValue @16@0:8
METHOD setByValue: v24@0:8@16
METHOD setFromValue: v24@0:8@16
METHOD setStartAngle: v24@0:8d16
METHOD setToValue: v24@0:8@16
METHOD startAngle d16@0:8
METHOD CA_prepareRenderValue v16@0:8
METHOD byValue @16@0:8
METHOD roundsToInteger B16@0:8
METHOD _copyRenderAnimationForLayer: ^v24@0:8@16
METHOD _setCARenderAnimation:layer: B32@0:8^v16@24
METHOD _timeFunction: d24@0:8d16
METHOD applyForTime:presentationObject:modelObject: v40@0:8d16@24@32
METHOD endAngle d16@0:8
METHOD setEndAngle: v24@0:8d16
METHOD setRoundsToInteger: v20@0:8B16

=== CLASS CAGradientLayer ===
SUPER: CALayer
SIZE: 48
CMETHOD defaultValueForKey: @24@0:8@16
CMETHOD CA_automaticallyNotifiesObservers: B24@0:8#16
CMETHOD _hasRenderLayerSubclass B16@0:8
METHOD didChangeValueForKey: v24@0:8@16
METHOD setType: v24@0:8@16
METHOD type @16@0:8
METHOD colorSpace ^{CGColorSpace=}16@0:8
METHOD setColorSpace: v24@0:8^{CGColorSpace=}16
METHOD colors @16@0:8
METHOD endPoint {CGPoint=dd}16@0:8
METHOD implicitAnimationForKeyPath: @24@0:8@16
METHOD locations @16@0:8
METHOD setColors: v24@0:8@16
METHOD setEndPoint: v32@0:8{CGPoint=dd}16
METHOD setInterpolations: v24@0:8@16
METHOD setLocations: v24@0:8@16
METHOD setPremultiplied: v20@0:8B16
METHOD setStartPoint: v32@0:8{CGPoint=dd}16
METHOD startPoint {CGPoint=dd}16@0:8
METHOD CA_validateValue:forKey: B32@0:8@16@24
METHOD _colorSpaceDidChange v16@0:8
METHOD _copyRenderLayer:layerFlags:commitFlags: ^v36@0:8^v16I24^I28
METHOD _renderBackgroundInContext: v24@0:8^{CGContext=}16
METHOD _renderLayerDefinesProperty: B20@0:8I16
METHOD _renderLayerPropertyAnimationFlags: I20@0:8I16
METHOD colorMap @16@0:8
METHOD interpolations @16@0:8
METHOD noiseScale d16@0:8
METHOD premultiplied B16@0:8
METHOD setColorMap: v24@0:8@16
METHOD setNoiseScale: v24@0:8d16

=== CLASS CAKeyframeAnimation ===
SUPER: CAPropertyAnimation
SIZE: 24
CMETHOD normalizedKeyframeAnimationWithKeyPath: @24@0:8@16
METHOD SCN_evaluateAtTime:reverse:to: B36@0:8d16B24^v28
METHOD VFX_evaluateAtTime:reverse:to: B36@0:8d16B24^v28
METHOD initWithSerializedVFXBindingDataPointer: @24@0:8^v16
METHOD serializedVFXBindingData @16@0:8
METHOD serializedVFXBindingSize i16@0:8
METHOD path ^{CGPath=}16@0:8
METHOD setPath: v24@0:8^{CGPath=}16
METHOD values @16@0:8
METHOD setValues: v24@0:8@16
METHOD keyTimes @16@0:8
METHOD setCalculationMode: v24@0:8@16
METHOD setKeyTimes: v24@0:8@16
METHOD setTensionValues: v24@0:8@16
METHOD setTimingFunctions: v24@0:8@16
METHOD CA_prepareRenderValue v16@0:8
METHOD CA_validateValue:forKey: B32@0:8@16@24
METHOD calculationMode @16@0:8
METHOD timingFunctions @16@0:8
METHOD _copyRenderAnimationForLayer: ^v24@0:8@16
METHOD _setCARenderAnimation:layer: B32@0:8^v16@24
METHOD applyForTime:presentationObject:modelObject: v40@0:8d16@24@32
METHOD biasValues @16@0:8
METHOD continuityValues @16@0:8
METHOD rotationMode @16@0:8
METHOD setBiasValues: v24@0:8@16
METHOD setContinuityValues: v24@0:8@16
METHOD setRotationMode: v24@0:8@16
METHOD tensionValues @16@0:8

=== CLASS CALayer ===
SUPER: NSObject
SIZE: 48
PROTOCOLS: CAPropertyInfo NSSecureCoding CAMediaTiming
IVAR +8 0 _attr {_CALayerIvars="refcount"i"magic"I"layer"^v"_objc_observation_info"^v}
IVAR +32 0 _wantsDynamicContentScaling B
IVAR +36 0 _autoresizingMask I
IVAR +40 0 _layoutManager @"<CALayoutManager>"
CMETHOD _web_renderLayerWithContextID:shouldPreserveFlip: @24@0:8I16B20
CMETHOD SCNJSExportProtocol @16@0:8
CMETHOD _swiftUI_platformViewDefinition r^v16@0:8
CMETHOD VFXJSExportProtocol @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD initialize v16@0:8
CMETHOD resolveInstanceMethod: B24@0:8:16
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
CMETHOD supportsSecureCoding B16@0:8
CMETHOD properties @16@0:8
CMETHOD cornerCurveExpansionFactor: d24@0:8@16
CMETHOD defaultValueForKey: @24@0:8@16
CMETHOD layer @16@0:8
CMETHOD needsDisplayForKey: B24@0:8@16
CMETHOD CAMLParserEndElement: v24@0:8@16
CMETHOD CAMLParserStartElement: v24@0:8@16
CMETHOD CA_automaticallyNotifiesObservers: B24@0:8#16
CMETHOD CA_getterForProperty: ^?24@0:8r^{_CAPropertyInfo=Ib16b16[2:]^{__CFString}}16
CMETHOD CA_setterForProperty: ^?24@0:8r^{_CAPropertyInfo=Ib16b16[2:]^{__CFString}}16
CMETHOD _hasRenderLayerSubclass B16@0:8
CMETHOD defaultActionForKey: @24@0:8@16
CMETHOD layerWithRenderLayer: @24@0:8^v16
CMETHOD layerWithRenderLayer:options: @32@0:8^v16@24
CMETHOD needsLayoutForKey: B24@0:8@16
METHOD _uis_provideRenderingAttributes @16@0:8
METHOD _configureUsingLayer: v24@0:8@16
METHOD _labelLayerToClipDuringBoundsSizeAnimation @16@0:8
METHOD _setLabelMasksToBoundsForAnimation: v20@0:8B16
METHOD _ui_animationForHDRHeadroomUsageEnabled: @20@0:8B16
METHOD _ui_configureForHDRHeadroomUsageEnabled: v20@0:8B16
METHOD _ui_layoutRun @16@0:8
METHOD _ui_setLayoutRun: v24@0:8@16
METHOD compareTextEffectsOrdering: q24@0:8@16
METHOD setPerspectiveDistance: v24@0:8d16
METHOD uiHasFilterWithName: B24@0:8@16
METHOD _uis_renderingAttributes @16@0:8
METHOD _web_clearContents v16@0:8
METHOD _web_maskContainsPoint: B32@0:8{CGPoint=dd}16
METHOD _web_maskMayIntersectRect: B48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD web_disableAllActions v16@0:8
METHOD _web_setLayerBoundsOrigin: v32@0:8{CGPoint=dd}16
METHOD _web_setLayerTopLeftPosition: v32@0:8{CGPoint=dd}16
METHOD mt_applyVisualStying: v24@0:8@16
METHOD mt_removeAllVisualStyling v16@0:8
METHOD mt_replaceAllVisualStylingWithStyling: v24@0:8@16
METHOD displayHeadroomMayHaveChanged B16@0:8
METHOD setCoordinatedAnimationDelegate v16@0:8
METHOD setNoAnimationDelegate v16@0:8
METHOD setSDFCoordinatedAnimationDelegate v16@0:8
METHOD setSwiftUI_displayListID: v24@0:8q16
METHOD setSwiftUI_viewTestProperties: v24@0:8Q16
METHOD swiftUI_displayListID q16@0:8
METHOD swiftUI_viewTestProperties Q16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD allowsWeakReference B16@0:8
METHOD debugDescription @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD retainWeakReference B16@0:8
METHOD context @16@0:8
METHOD _flags I16@0:8
METHOD delegate @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD isHidden B16@0:8
METHOD setDelegate: v24@0:8@16
METHOD setHidden: v20@0:8B16
METHOD setName: v24@0:8@16
METHOD setObservationInfo: v24@0:8^v16
METHOD observationInfo ^v16@0:8
METHOD duration d16@0:8
METHOD position {CGPoint=dd}16@0:8
METHOD setPosition: v32@0:8{CGPoint=dd}16
METHOD setStyle: v24@0:8@16
METHOD setValue:forKey: v32@0:8@16@24
METHOD setValue:forKeyPath: v32@0:8@16@24
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD size {CGSize=dd}16@0:8
METHOD style @16@0:8
METHOD transform {CATransform3D=dddddddddddddddd}16@0:8
METHOD valueForKey: @24@0:8@16
METHOD valueForKeyPath: @24@0:8@16
METHOD valueForUndefinedKey: @24@0:8@16
METHOD shadowColor ^{CGColor=}16@0:8
METHOD shadowOffset {CGSize=dd}16@0:8
METHOD actions @16@0:8
METHOD setActions: v24@0:8@16
METHOD filters @16@0:8
METHOD opacity f16@0:8
METHOD bounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD contents @16@0:8
METHOD frame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD isFlipped B16@0:8
METHOD isOpaque B16@0:8
METHOD mask @16@0:8
METHOD preferredDynamicRange @16@0:8
METHOD setBounds: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setContents: v24@0:8@16
METHOD setFlipped: v20@0:8B16
METHOD setMask: v24@0:8@16
METHOD setOpacity: v20@0:8f16
METHOD setPreferredDynamicRange: v24@0:8@16
METHOD setShadowOffset: v32@0:8{CGSize=dd}16
METHOD setShadowRadius: v24@0:8d16
METHOD setTransform: v144@0:8{CATransform3D=dddddddddddddddd}16
METHOD shadowRadius d16@0:8
METHOD setDuration: v24@0:8d16
METHOD beginTime d16@0:8
METHOD setBeginTime: v24@0:8d16
METHOD setOpaque: v20@0:8B16
METHOD setSpeed: v20@0:8f16
METHOD speed f16@0:8
METHOD backgroundColor ^{CGColor=}16@0:8
METHOD setBorderColor: v24@0:8^{CGColor=}16
METHOD setShadowColor: v24@0:8^{CGColor=}16
METHOD containsPoint: B32@0:8{CGPoint=dd}16
METHOD layoutManager @16@0:8
METHOD needsDisplay B16@0:8
METHOD setBackgroundColor: v24@0:8^{CGColor=}16
METHOD setFrame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setLayoutManager: v24@0:8@16
METHOD setNeedsDisplayInRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setNeedsLayout v16@0:8
METHOD visibleRect {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD affineTransform {CGAffineTransform=dddddd}16@0:8
METHOD contentsGravity @16@0:8
METHOD contentsScaling @16@0:8
METHOD display v16@0:8
METHOD isDescendantOf: B24@0:8@16
METHOD layoutSublayers v16@0:8
METHOD setAnchorPoint: v32@0:8{CGPoint=dd}16
METHOD setBorderWidth: v24@0:8d16
METHOD setCornerCurve: v24@0:8@16
METHOD setNeedsDisplay v16@0:8
METHOD setNeedsLayoutOnGeometryChange: v20@0:8B16
METHOD shouldRasterize B16@0:8
METHOD displayIfNeeded v16@0:8
METHOD setCornerRadii: v80@0:8{CACornerRadii={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16
METHOD setDoubleSided: v20@0:8B16
METHOD setInvertsMask: v20@0:8B16
METHOD setRepeatCount: v20@0:8f16
METHOD setToneMapMode: v24@0:8@16
METHOD _display v16@0:8
METHOD actionForKey: @24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD addPresentationModifier: v24@0:8@16
METHOD addSublayer: v24@0:8@16
METHOD allowsEdgeAntialiasing B16@0:8
METHOD allowsGroupBlending B16@0:8
METHOD allowsGroupOpacity B16@0:8
METHOD allowsHitTesting B16@0:8
METHOD ancestorSharedWithLayer: @24@0:8@16
METHOD anchorPoint {CGPoint=dd}16@0:8
METHOD animationForKey: @24@0:8@16
METHOD animationKeys @16@0:8
METHOD autoresizingMask I16@0:8
METHOD autoreverses B16@0:8
METHOD borderColor ^{CGColor=}16@0:8
METHOD borderOffset d16@0:8
METHOD borderWidth d16@0:8
METHOD clearHasBeenCommitted v16@0:8
METHOD clearsContext B16@0:8
METHOD compositingFilter @16@0:8
METHOD contentsCenter {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD contentsEDRStrength d16@0:8
METHOD contentsFormat @16@0:8
METHOD contentsGravityEnum q16@0:8
METHOD contentsMultiplyColor ^{CGColor=}16@0:8
METHOD contentsRect {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD contentsScale d16@0:8
METHOD contentsTransform {CGAffineTransform=dddddd}16@0:8
METHOD convertPoint:fromLayer: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD convertPoint:toLayer: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD convertRect:fromLayer: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:toLayer: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertTime:fromLayer: d32@0:8d16@24
METHOD convertTime:toLayer: d32@0:8d16@24
METHOD cornerCurve @16@0:8
METHOD cornerRadii {CACornerRadii={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD cornerRadius d16@0:8
METHOD disableUpdateMask I16@0:8
METHOD drawInContext: v24@0:8^{CGContext=}16
METHOD drawsAsynchronously B16@0:8
METHOD edgeAntialiasingMask I16@0:8
METHOD flipsHorizontalAxis B16@0:8
METHOD gain f16@0:8
METHOD hasBeenCommitted B16@0:8
METHOD hidden B16@0:8
METHOD hitTest: @32@0:8{CGPoint=dd}16
METHOD hitTestsAsOpaque B16@0:8
METHOD identifiers @16@0:8
METHOD implicitAnimationForKeyPath: @24@0:8@16
METHOD initWithLayer: @24@0:8@16
METHOD insertSublayer:above: v32@0:8@16@24
METHOD insertSublayer:atIndex: v28@0:8@16I24
METHOD insertSublayer:below: v32@0:8@16@24
METHOD isDoubleSided B16@0:8
METHOD isFrozen B16@0:8
METHOD isGeometryFlipped B16@0:8
METHOD layoutBelowIfNeeded v16@0:8
METHOD layoutIfNeeded v16@0:8
METHOD layoutIsActive B16@0:8
METHOD maskedCorners Q16@0:8
METHOD masksToBounds B16@0:8
METHOD meshTransform @16@0:8
METHOD needsDisplayOnBoundsChange B16@0:8
METHOD needsLayout B16@0:8
METHOD needsLayoutOnGeometryChange B16@0:8
METHOD needsPreLayoutUpdate B16@0:8
METHOD opaque B16@0:8
METHOD presentationLayer @16@0:8
METHOD rasterizationScale d16@0:8
METHOD recursiveDescription @16@0:8
METHOD reloadValueForKeyPath: v24@0:8@16
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD removeFromSuperlayer v16@0:8
METHOD removePresentationModifier: v24@0:8@16
METHOD renderInContext: v24@0:8^{CGContext=}16
METHOD repeatCount f16@0:8
METHOD replaceSublayer:with: v32@0:8@16@24
METHOD setAffineTransform: v64@0:8{CGAffineTransform=dddddd}16
METHOD setAllowsDisplayCompositing: v20@0:8B16
METHOD setAllowsEdgeAntialiasing: v20@0:8B16
METHOD setAllowsGroupBlending: v20@0:8B16
METHOD setAllowsGroupOpacity: v20@0:8B16
METHOD setAllowsHitTesting: v20@0:8B16
METHOD setAllowsLimitedHeadroom: v20@0:8B16
METHOD setAutoresizingMask: v20@0:8I16
METHOD setAutoreverses: v20@0:8B16
METHOD setBorderOffset: v24@0:8d16
METHOD setClearsContext: v20@0:8B16
METHOD setCompositingFilter: v24@0:8@16
METHOD setContentsAlignsToPixels: v20@0:8B16
METHOD setContentsCenter: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setContentsEDRStrength: v24@0:8d16
METHOD setContentsFormat: v24@0:8@16
METHOD setContentsGravity: v24@0:8@16
METHOD setContentsHeadroom: v24@0:8d16
METHOD setContentsMaximumDesiredEDR: v24@0:8d16
METHOD setContentsMultiplyColor: v24@0:8^{CGColor=}16
METHOD setContentsRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setContentsScale: v24@0:8d16
METHOD setContentsScaling: v24@0:8@16
METHOD setContentsSwizzle: v24@0:8@16
METHOD setContentsTransform: v64@0:8{CGAffineTransform=dddddd}16
METHOD setContinuousCorners: v20@0:8B16
METHOD setCornerContents: v24@0:8@16
METHOD setCornerContentsCenter: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setCornerContentsMasksEdges: v20@0:8B16
METHOD setCornerRadius: v24@0:8d16
METHOD setCreatesCompositingGroup: v20@0:8B16
METHOD setDisableUpdateMask: v20@0:8I16
METHOD setDrawsAsynchronously: v20@0:8B16
METHOD setEdgeAntialiasingMask: v20@0:8I16
METHOD setFillMode: v24@0:8@16
METHOD setFilters: v24@0:8@16
METHOD setFlipsHorizontalAxis: v20@0:8B16
METHOD setFrozen: v20@0:8B16
METHOD setGain: v20@0:8f16
METHOD setGeometryFlipped: v20@0:8B16
METHOD setHitTestsAsOpaque: v20@0:8B16
METHOD setInheritsTiming: v20@0:8B16
METHOD setInvertsShadow: v20@0:8B16
METHOD setMagnificationFilter: v24@0:8@16
METHOD setMaskedCorners: v24@0:8Q16
METHOD setMasksToBounds: v20@0:8B16
METHOD setMeshTransform: v24@0:8@16
METHOD setMinificationFilter: v24@0:8@16
METHOD setNeedsDisplayOnBoundsChange: v20@0:8B16
METHOD setNeedsPreLayoutUpdate v16@0:8
METHOD setPreloadsCache: v20@0:8B16
METHOD setPunchoutShadow: v20@0:8B16
METHOD setRasterizationScale: v24@0:8d16
METHOD setRimColor: v24@0:8^{CGColor=}16
METHOD setRimOpacity: v20@0:8f16
METHOD setRimWidth: v24@0:8d16
METHOD setSecurityMode: v24@0:8@16
METHOD setShadowOpacity: v20@0:8f16
METHOD setShadowPath: v24@0:8^{CGPath=}16
METHOD setShadowPathIsBounds: v20@0:8B16
METHOD setShouldRasterize: v20@0:8B16
METHOD setSkipHitTesting: v20@0:8B16
METHOD setSublayerTransform: v144@0:8{CATransform3D=dddddddddddddddd}16
METHOD setSublayers: v24@0:8@16
METHOD setTimeOffset: v24@0:8d16
METHOD setUnsafeUnretainedDelegate: v24@0:8@16
METHOD setWantsExtendedDynamicRangeContent: v20@0:8B16
METHOD setZPosition: v24@0:8d16
METHOD shadowOpacity f16@0:8
METHOD shadowPath ^{CGPath=}16@0:8
METHOD stateWithName: @24@0:8@16
METHOD sublayerTransform {CATransform3D=dddddddddddddddd}16@0:8
METHOD sublayers @16@0:8
METHOD superlayer @16@0:8
METHOD timeOffset d16@0:8
METHOD unsafeUnretainedDelegate @16@0:8
METHOD wantsExtendedDynamicRangeContent B16@0:8
METHOD zPosition d16@0:8
METHOD addIdentifier: v24@0:8@16
METHOD CAMLTypeSupportedForKey: B24@0:8@16
METHOD allowsCornerContentsEdgeEffects B16@0:8
METHOD contentsSwizzle @16@0:8
METHOD rimPathIsBounds B16@0:8
METHOD shouldReflatten B16@0:8
METHOD softRim B16@0:8
METHOD CAMLTypeForKey: @24@0:8@16
METHOD CAMLParser:setValue:forKey: v40@0:8@16@24@32
METHOD CA_archivingValueForKey: @24@0:8@16
METHOD CA_initialize_for_decoding v16@0:8
METHOD CA_validateValue:forKey: B32@0:8@16@24
METHOD layerBeingDrawn @16@0:8
METHOD prepareContents v16@0:8
METHOD sizeRequisition {CGSize=dd}16@0:8
METHOD _canDisplayConcurrently B16@0:8
METHOD _cancelAnimationTimer v16@0:8
METHOD _colorSpaceDidChange v16@0:8
METHOD _contentsFormatDidChange: v24@0:8@16
METHOD _continuousCorners B16@0:8
METHOD _copyRenderLayer:layerFlags:commitFlags: ^v36@0:8^v16I24^I28
METHOD _dealloc v16@0:8
METHOD _defersDidBecomeVisiblePostCommit B16@0:8
METHOD _didCommitLayer: v24@0:8^v16
METHOD _initWithReference: @24@0:8@16
METHOD _layoutHash @16@0:8
METHOD _overrideImageFormat i16@0:8
METHOD _performPreLayoutUpdate v16@0:8
METHOD _preferredSize {CGSize=dd}16@0:8
METHOD _prepareContext: v24@0:8^{CGContext=}16
METHOD _previousLayoutHash @16@0:8
METHOD _renderBackgroundInContext: v24@0:8^{CGContext=}16
METHOD _renderBorderInContext: v24@0:8^{CGContext=}16
METHOD _renderForegroundInContext: v24@0:8^{CGContext=}16
METHOD _renderImageCopyFlags I16@0:8
METHOD _renderLayerDefinesProperty: B20@0:8I16
METHOD _renderLayerPropertyAnimationFlags: I20@0:8I16
METHOD _renderSublayersInContext: v24@0:8^{CGContext=}16
METHOD _retainColorSpace ^{CGColorSpace=}16@0:8
METHOD _saveCurrentLayoutHash v16@0:8
METHOD _scheduleAnimationTimer B16@0:8
METHOD _scrollPoint:fromLayer: v40@0:8{CGPoint=dd}16@32
METHOD _scrollRect:fromLayer: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _setPreviousLayoutHash: v24@0:8@16
METHOD _thread_flags I16@0:8
METHOD _usesCornerRadii B16@0:8
METHOD _validateLayoutHashHasChangedWithLayoutTime: v24@0:8d16
METHOD _visibleRectOfLayer: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD acceleratesDrawing B16@0:8
METHOD addState: v24@0:8@16
METHOD allowedContentsHideSublayers B16@0:8
METHOD allowsColorMatching B16@0:8
METHOD allowsDisplayCompositing B16@0:8
METHOD allowsLimitedHeadroom B16@0:8
METHOD anchorPointZ d16@0:8
METHOD backgroundColorPhase {CGSize=dd}16@0:8
METHOD backgroundFilters @16@0:8
METHOD borderPathIsBounds B16@0:8
METHOD canDrawConcurrently B16@0:8
METHOD contentsAlignsToPixels B16@0:8
METHOD contentsAreFlipped B16@0:8
METHOD contentsCDRStrength d16@0:8
METHOD contentsContainsSubtitles B16@0:8
METHOD contentsDirtyRect {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD contentsDither B16@0:8
METHOD contentsHeadroom d16@0:8
METHOD contentsMaximumDesiredEDR d16@0:8
METHOD contentsOpaque B16@0:8
METHOD continuousCorners B16@0:8
METHOD cornerContents @16@0:8
METHOD cornerContentsCenter {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD cornerContentsMasksEdges B16@0:8
METHOD createsCompositingGroup B16@0:8
METHOD definesDisplayRegionOfInterest B16@0:8
METHOD dependentStatesOfState: @24@0:8@16
METHOD displayMaximumDesiredEDR d16@0:8
METHOD doubleSided B16@0:8
METHOD drawsMipmapLevels B16@0:8
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD fillMode @16@0:8
METHOD getRendererInfo:size: B32@0:8^{_CARenderRendererInfo=iII}16Q24
METHOD hitTestsContentsAlphaChannel B16@0:8
METHOD ignoresHitTesting B16@0:8
METHOD inheritsTiming B16@0:8
METHOD insertState:atIndex: v28@0:8@16I24
METHOD invalidateContents v16@0:8
METHOD invertsMask B16@0:8
METHOD invertsShadow B16@0:8
METHOD layerAtTime: @24@0:8d16
METHOD layerDidBecomeVisible: v20@0:8B16
METHOD literalContentsCenter B16@0:8
METHOD magnificationFilter @16@0:8
METHOD minificationFilter @16@0:8
METHOD minificationFilterBias f16@0:8
METHOD modelLayer @16@0:8
METHOD motionBlurAmount d16@0:8
METHOD optimizationOpportunities: @20@0:8B16
METHOD preferredFrameSize {CGSize=dd}16@0:8
METHOD preloadsCache B16@0:8
METHOD presentationModifiers @16@0:8
METHOD punchoutShadow B16@0:8
METHOD rasterizationPrefersDisplayCompositing B16@0:8
METHOD rasterizationPrefersWindowServerAwareBackdrops B16@0:8
METHOD rasterizeInParentSpace B16@0:8
METHOD regionBeingDrawn ^v16@0:8
METHOD remapAnimation:forKey: B32@0:8@16@24
METHOD removeIdentifier: v24@0:8@16
METHOD removeState: v24@0:8@16
METHOD repeatDuration d16@0:8
METHOD rimColor ^{CGColor=}16@0:8
METHOD rimOpacity f16@0:8
METHOD rimWidth d16@0:8
METHOD scrollPoint: v32@0:8{CGPoint=dd}16
METHOD scrollRectToVisible: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD securityMode @16@0:8
METHOD setAcceleratesDrawing: v20@0:8B16
METHOD setAllowedContentsHideSublayers: v20@0:8B16
METHOD setAllowsColorMatching: v20@0:8B16
METHOD setAllowsCornerContentsEdgeEffects: v20@0:8B16
METHOD setAnchorPointZ: v24@0:8d16
METHOD setBackgroundColorPhase: v32@0:8{CGSize=dd}16
METHOD setBackgroundFilters: v24@0:8@16
METHOD setBorderPathIsBounds: v20@0:8B16
METHOD setCanDrawConcurrently: v20@0:8B16
METHOD setContentsCDRStrength: v24@0:8d16
METHOD setContentsChanged v16@0:8
METHOD setContentsContainsSubtitles: v20@0:8B16
METHOD setContentsDirtyRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setContentsDither: v20@0:8B16
METHOD setContentsOpaque: v20@0:8B16
METHOD setDefinesDisplayRegionOfInterest: v20@0:8B16
METHOD setDisplayMaximumDesiredEDR: v24@0:8d16
METHOD setHitTestsContentsAlphaChannel: v20@0:8B16
METHOD setLiteralContentsCenter: v20@0:8B16
METHOD setMinificationFilterBias: v20@0:8f16
METHOD setMotionBlurAmount: v24@0:8d16
METHOD setPresentationModifiers: v24@0:8@16
METHOD setRasterizationPrefersDisplayCompositing: v20@0:8B16
METHOD setRasterizationPrefersWindowServerAwareBackdrops: v20@0:8B16
METHOD setRasterizeInParentSpace: v20@0:8B16
METHOD setRepeatDuration: v24@0:8d16
METHOD setRimPathIsBounds: v20@0:8B16
METHOD setShouldFlatten: v20@0:8B16
METHOD setShouldReflatten: v20@0:8B16
METHOD setSizeRequisition: v32@0:8{CGSize=dd}16
METHOD setSoftRim: v20@0:8B16
METHOD setSortsSublayers: v20@0:8B16
METHOD setToneMapToStandardDynamicRange: v20@0:8B16
METHOD setTreatRec709AsSRGB: v20@0:8B16
METHOD setUsesWebKitBehavior: v20@0:8B16
METHOD setWantsDynamicContentScaling: v20@0:8B16
METHOD shadowPathIsBounds B16@0:8
METHOD shouldArchiveValueForKey: B24@0:8@16
METHOD shouldFlatten B16@0:8
METHOD skipHitTesting B16@0:8
METHOD sortsSublayers B16@0:8
METHOD stateTransitionFrom:to: @32@0:8@16@24
METHOD toneMapMode @16@0:8
METHOD toneMapToStandardDynamicRange B16@0:8
METHOD treatRec709AsSRGB B16@0:8
METHOD usesWebKitBehavior B16@0:8
METHOD wantsDynamicContentScaling B16@0:8

=== CLASS CAMediaTimingFunction ===
SUPER: NSObject
SIZE: 16
PROTOCOLS: NSSecureCoding
IVAR +8 0 _priv ^{CAMediaTimingFunctionPrivate=[2f][2f]}
CMETHOD _kbTimingFunction @16@0:8
CMETHOD uiFunctionWithControlPoints: @24@0:8r^{CGPoint=dd}16
CMETHOD supportsSecureCoding B16@0:8
CMETHOD functionWithName: @24@0:8@16
CMETHOD functionWithControlPoints:::: @32@0:8f16f20f24f28
CMETHOD CAMLParserEndElement:content: v32@0:8@16@24
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD _solveForInput: f20@0:8f16
METHOD getControlPointAtIndex:values: v32@0:8Q16[2f]24
METHOD CA_numericValueCount Q16@0:8
METHOD CA_copyRenderValue ^{Object=^^?{Atomic={?=i}}b8b24}16@0:8
METHOD initWithControlPoints:::: @32@0:8f16f20f24f28
METHOD CAMLType @16@0:8
METHOD CA_copyNumericValue: Q24@0:8^d16
METHOD _getPoints: v24@0:8^d16
METHOD encodeWithCAMLWriter: v24@0:8@16

=== CLASS CAPropertyAnimation ===
SUPER: CAAnimation
SIZE: 24
CMETHOD animationWithKeyPath: @24@0:8@16
METHOD avt_isUseless B16@0:8
METHOD keyPath @16@0:8
METHOD isAdditive B16@0:8
METHOD setAdditive: v20@0:8B16
METHOD setKeyPath: v24@0:8@16
METHOD setValueFunction: v24@0:8@16
METHOD _propertyFlagsForLayer: I24@0:8@16
METHOD _setCARenderAnimation:layer: B32@0:8^v16@24
METHOD additive B16@0:8
METHOD applyForTime:presentationObject:modelObject: v40@0:8d16@24@32
METHOD cumulative B16@0:8
METHOD isCumulative B16@0:8
METHOD setCumulative: v20@0:8B16
METHOD valueFunction @16@0:8

=== CLASS CATransaction ===
SUPER: NSObject
SIZE: 8
CMETHOD mt_addCompletionBlock: v24@0:8@?16
CMETHOD lock v16@0:8
CMETHOD synchronize v16@0:8
CMETHOD unlock v16@0:8
CMETHOD completionBlock @?16@0:8
CMETHOD activate v16@0:8
CMETHOD currentState I16@0:8
CMETHOD setCompletionBlock: v24@0:8@?16
CMETHOD setValue:forKey: v32@0:8@16@24
CMETHOD valueForKey: @24@0:8@16
CMETHOD begin v16@0:8
CMETHOD commit v16@0:8
CMETHOD inputTime d16@0:8
CMETHOD setInputTime: v24@0:8d16
CMETHOD batch v16@0:8
CMETHOD flush v16@0:8
CMETHOD activateBackground: v20@0:8B16
CMETHOD beginTime d16@0:8
CMETHOD setBeginTime: v24@0:8d16
CMETHOD setDisableActions: v20@0:8B16
CMETHOD setEarliestAutomaticCommitTime: v24@0:8d16
CMETHOD addCommitHandler:forPhase: B28@0:8@?16i24
CMETHOD animationDuration d16@0:8
CMETHOD animationTimingFunction @16@0:8
CMETHOD animator @?16@0:8
CMETHOD commitTime d16@0:8
CMETHOD currentPhase i16@0:8
CMETHOD disableActions B16@0:8
CMETHOD earliestAutomaticCommitTime d16@0:8
CMETHOD enableUpdateCycleSupport v16@0:8
CMETHOD finishFrameWithToken: v20@0:8I16
CMETHOD flushAsRunLoopObserver v16@0:8
CMETHOD lowLatency B16@0:8
CMETHOD setAnimationDuration: v24@0:8d16
CMETHOD setAnimationTimingFunction: v24@0:8@16
CMETHOD setCommitTime: v24@0:8d16
CMETHOD setCommittingContexts: v24@0:8@16
CMETHOD setDefaultDisableRunLoopObserverCommits: v20@0:8B16
CMETHOD setDisableRunLoopObserverCommits: v20@0:8B16
CMETHOD setEmptyLowLatency: v20@0:8B16
CMETHOD setFrameInputTime:withToken: v28@0:8d16I24
CMETHOD setFrameStallSkipRequest: v20@0:8B16
CMETHOD setImplicitTransactionDidBeginHandler: v24@0:8@?16
CMETHOD setLowLatency: v20@0:8B16
CMETHOD setRemoteInputMachTime: v24@0:8Q16
CMETHOD setUpdateDeadline: v24@0:8d16
CMETHOD startFrameWithReason:beginTime:commitDeadline: I36@0:8i16d20d28
CMETHOD batchWithDefaultServerObserver: B24@0:8@?16
CMETHOD emptyLowLatency B16@0:8
CMETHOD registerBoolKey I16@0:8
CMETHOD _implicitAnimationForLayer:keyPath: @32@0:8@16@24
CMETHOD animatesFromModelValues B16@0:8
CMETHOD assertInactive v16@0:8
CMETHOD boolValueForKey: B20@0:8I16
CMETHOD committingContexts @16@0:8
CMETHOD defaultDisableRunLoopObserverCommits B16@0:8
CMETHOD disableImplicitTransactionMainThreadAssert B16@0:8
CMETHOD disableRunLoopObserverCommits B16@0:8
CMETHOD disableSignPosts B16@0:8
CMETHOD frameStallSkipRequest B16@0:8
CMETHOD generateSeed I16@0:8
CMETHOD popAnimator v16@0:8
CMETHOD pushAnimator: v24@0:8@?16
CMETHOD remoteInputMachTime Q16@0:8
CMETHOD setAnimatesFromModelValues: v20@0:8B16
CMETHOD setBoolValue:forKey: v24@0:8B16I20
CMETHOD setCommitHandler: v24@0:8@?16
CMETHOD setDisableImplicitTransactionMainThreadAssert: v20@0:8B16
CMETHOD setDisableSignPosts: v20@0:8B16
CMETHOD setPresentationHandler:queue: v32@0:8@?16@24
CMETHOD updateDeadline d16@0:8

=== CLASS MTLCommandBufferDescriptor ===
SUPER: NSObject
SIZE: 16
PROTOCOLS: NSCopying
IVAR +8 0 _logState @"<MTLLogState>"
CMETHOD alloc @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD logState @16@0:8
METHOD setLogState: v24@0:8@16

=== CLASS MTLComputePipelineDescriptor ===
SUPER: NSObject
SIZE: 16
PROTOCOLS: NSCopying
IVAR +8 0 _insertLibraries @"NSArray"
CMETHOD alloc @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD reset v16@0:8
METHOD insertLibraries @16@0:8
METHOD setInsertLibraries: v24@0:8@16

=== CLASS MTLRenderPassDescriptor ===
SUPER: NSObject
SIZE: 40
PROTOCOLS: NSCopying
IVAR +8 0 _imageblockSampleLength Q
IVAR +16 0 _threadgroupMemoryLength Q
IVAR +24 0 _tileWidth Q
IVAR +32 0 _tileHeight Q
CMETHOD alloc @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD renderPassDescriptor @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD imageblockSampleLength Q16@0:8
METHOD setImageblockSampleLength: v24@0:8Q16
METHOD tileHeight Q16@0:8
METHOD tileWidth Q16@0:8
METHOD getSamplePositions:count: Q32@0:8^{?=ff}16Q24
METHOD setSamplePositions:count: v32@0:8r^{?=ff}16Q24
METHOD setThreadgroupMemoryLength: v24@0:8Q16
METHOD setTileHeight: v24@0:8Q16
METHOD setTileWidth: v24@0:8Q16
METHOD threadgroupMemoryLength Q16@0:8

=== CLASS MTLRenderPipelineDescriptor ===
SUPER: NSObject
SIZE: 48
PROTOCOLS: NSCopying
IVAR +8 0 _supportAddingVertexBinaryFunctions B
IVAR +9 0 _supportAddingFragmentBinaryFunctions B
IVAR +16 0 _vertexPreloadedLibraries @"NSArray"
IVAR +24 0 _fragmentPreloadedLibraries @"NSArray"
IVAR +32 0 _maxVertexCallStackDepth Q
IVAR +40 0 _maxFragmentCallStackDepth Q
CMETHOD alloc @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD reset v16@0:8
METHOD fragmentPreloadedLibraries @16@0:8
METHOD maxFragmentCallStackDepth Q16@0:8
METHOD maxVertexCallStackDepth Q16@0:8
METHOD setFragmentPreloadedLibraries: v24@0:8@16
METHOD setMaxFragmentCallStackDepth: v24@0:8Q16
METHOD setMaxVertexCallStackDepth: v24@0:8Q16
METHOD setSupportAddingFragmentBinaryFunctions: v20@0:8B16
METHOD setSupportAddingVertexBinaryFunctions: v20@0:8B16
METHOD setVertexPreloadedLibraries: v24@0:8@16
METHOD supportAddingFragmentBinaryFunctions B16@0:8
METHOD supportAddingVertexBinaryFunctions B16@0:8
METHOD vertexPreloadedLibraries @16@0:8

=== CLASS MTLTextureDescriptor ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: NSCopying
CMETHOD alloc @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD texture2DDescriptorWithPixelFormat:width:height:mipmapped: @44@0:8Q16Q24Q32B40
CMETHOD textureBufferDescriptorWithPixelFormat:width:resourceOptions:usage: @48@0:8Q16Q24Q32Q40
CMETHOD textureCubeDescriptorWithPixelFormat:size:mipmapped: @36@0:8Q16Q24B32
METHOD copyWithZone: @24@0:8^{_NSZone=}16

=== CLASS NSArray ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: BSCollection CKDeepCopying CKRecordValue CUByteCodable INIntentResolutionResultDataProviding INCodableAttributeRelationComparing INImageProxyInjecting INJSONSerializable INCacheableContainer INKeyImageProducing CSCoderEncoder ISStackedCompositorResource PQLBindable _OSXPCObjectRepresentable CRCodable NSCopying NSMutableCopying NSSecureCoding NSFastEnumeration
CMETHOD _subclassesMustBeExplicitlyMentionedWhenDecoded B16@0:8
CMETHOD newWithContentsOf:immutable: @28@0:8@16B24
CMETHOD arrayWithContentsOfFile: @24@0:8@16
CMETHOD arrayWithContentsOfURL: @24@0:8@16
CMETHOD arrayWithContentsOfURL:error: @32@0:8@16^@24
CMETHOD newWithContentsOf:immutable:error: @36@0:8@16B24^@28
CMETHOD arrayByFilteringLaunchProhibitedAppsFrom: @24@0:8@16
CMETHOD ui_arrayByCompactingArray: @24@0:8@16
CMETHOD _geo_arrayFromXPCObject: @24@0:8@16
CMETHOD createWithBytesNoCopy:length:error: @40@0:8^v16Q24^@32
CMETHOD axArrayByIgnoringNilElementsWithCount: @24@0:8Q16
CMETHOD axArrayWithPossiblyNilArrays: @24@0:8Q16
CMETHOD ak_arrayWithJSONResponseData: @24@0:8@16
CMETHOD arrayWithValues:inBlock: @32@0:8@16@?24
CMETHOD _pas_proxyArrayWithObject:repetitions: @32@0:8@16Q24
CMETHOD _pas_arrayNoCopyLeavesWithPropertyListData:error: @32@0:8@16^@24
CMETHOD _pas_proxyArrayUsingObjectAtIndexBlock:andCountBlock: @32@0:8@?16@?24
CMETHOD fm_arrayByRepeatingWithCount:generatorBlock: @32@0:8Q16@?24
CMETHOD fm_arrayWithSafeObject: @24@0:8@16
CMETHOD fp_sortDescriptorByDocumentSize @16@0:8
CMETHOD fp_sortDescriptorByLastUsedDate @16@0:8
CMETHOD fp_sortDescriptorByDisplayName @16@0:8
CMETHOD fp_sortDescriptorByModifiedDateDescending @16@0:8
CMETHOD SCN_arrayWithSimdMatrix4: @80@0:8{?=[4]}16
CMETHOD avt_arrayWithFloat3: @32@0:816
CMETHOD avt_arrayWithFloat3:roundingBehavior: @40@0:816@32
CMETHOD avt_arrayWithFloat4: @32@0:816
CMETHOD avt_arrayWithFloat4:roundingBehavior: @40@0:816@32
CMETHOD avt_arrayWithFloat4x4: @80@0:8{?=[4]}16
CMETHOD avt_arrayWithFloat4x4:roundingBehavior: @88@0:8{?=[4]}16@80
CMETHOD if_arrayWithObjectIfNonNil: @24@0:8@16
CMETHOD _inf_arrayWithObjectIfNonNil: @24@0:8@16
CMETHOD aaf_empty @16@0:8
CMETHOD bm_shuffledArrayWithArray: @24@0:8@16
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD arrayWithArray: @24@0:8@16
CMETHOD arrayWithArray:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
CMETHOD array @16@0:8
CMETHOD arrayWithArray:copyItems: @28@0:8@16B24
CMETHOD arrayWithArray:range: @40@0:8@16{_NSRange=QQ}24
CMETHOD arrayWithObject: @24@0:8@16
CMETHOD arrayWithObjects: @24@0:8@16
CMETHOD arrayWithObjects:count: @32@0:8r^@16Q24
CMETHOD arrayWithOrderedSet: @24@0:8@16
CMETHOD arrayWithOrderedSet:copyItems: @28@0:8@16B24
CMETHOD arrayWithOrderedSet:range: @40@0:8@16{_NSRange=QQ}24
CMETHOD arrayWithOrderedSet:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
CMETHOD arrayWithSet: @24@0:8@16
CMETHOD arrayWithSet:copyItems: @28@0:8@16B24
CMETHOD newArrayWithObjects:count: @32@0:8r^@16Q24
CMETHOD supportsSecureCoding B16@0:8
METHOD fp_map: @24@0:8@?16
METHOD _fp_componentsJoinedByAnd @16@0:8
METHOD _fp_componentsJoinedByOr @16@0:8
METHOD _fp_componentsWrappedInQuotes @16@0:8
METHOD _fp_filter: @24@0:8@?16
METHOD _fp_map: @24@0:8@?16
METHOD fp_categorize: @24@0:8@?16
METHOD fp_comparator @?16@0:8
METHOD fp_compareItem:toItem: q32@0:8@16@24
METHOD fp_filter: @24@0:8@?16
METHOD fp_itemIDs @16@0:8
METHOD fp_itemIdentifiers @16@0:8
METHOD fp_mapWithIndex: @24@0:8@?16
METHOD fp_pickItemsFromArray:correspondingToIndexesOfItemsInArray: @32@0:8@16@24
METHOD fp_removingObjectsNotKindOfClasses: @24@0:8@16
METHOD fp_shortDescriptionExpandingAtMost: @24@0:8Q16
METHOD bs_map: @24@0:8@?16
METHOD bs_array @16@0:8
METHOD bs_compactMap: @24@0:8@?16
METHOD bs_containsObjectPassingTest: B24@0:8@?16
METHOD bs_dictionaryByPartitioning: @24@0:8@?16
METHOD bs_differenceWithArray: @24@0:8@16
METHOD bs_each: v24@0:8@?16
METHOD bs_enumerateObjectsOfClass:usingBlock: v32@0:8#16@?24
METHOD bs_filter: @24@0:8@?16
METHOD bs_first: @24@0:8Q16
METHOD bs_firstObjectOfClass: @24@0:8#16
METHOD bs_firstObjectOfClassNamed: @24@0:8@16
METHOD bs_firstObjectPassingTest: @24@0:8@?16
METHOD bs_flatten @16@0:8
METHOD bs_flattenedDifferenceWithArray: @24@0:8@16
METHOD bs_mapNoNulls: @24@0:8@?16
METHOD bs_objectsOfClass: @24@0:8#16
METHOD bs_orderedSet @16@0:8
METHOD bs_reduce:block: @32@0:8@16@?24
METHOD bs_reverse @16@0:8
METHOD bs_set @16@0:8
METHOD bpsPublisher @16@0:8
METHOD publisher @16@0:8
METHOD CA_addValue:multipliedBy: @28@0:8@16i24
METHOD CA_interpolateValue:byFraction: @28@0:8@16f24
METHOD CA_interpolateValues:::interpolator: @48@0:8@16@24@32r^{ValueInterpolator=ddddddddddddddB}40
METHOD CAMLType @16@0:8
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD ac_mapNullable: @24@0:8@?16
METHOD ac_map: @24@0:8@?16
METHOD ac_filter: @24@0:8@?16
METHOD ac_firstObjectPassingTest: @24@0:8@?16
METHOD _FTFilteredArrayForAPS @16@0:8
METHOD _IDsFromURIs @16@0:8
METHOD _URIsFromIDs @16@0:8
METHOD aa_map: @24@0:8@?16
METHOD aa_mapNullable: @24@0:8@?16
METHOD aa_arrayByRemovingObject: @24@0:8@16
METHOD aa_filter: @24@0:8@?16
METHOD aa_firstObjectPassingTest: @24@0:8@?16
METHOD aa_isSubsetOfArray: B24@0:8@16
METHOD aaf_arrayByRemovingObject: @24@0:8@16
METHOD aaf_filter: @24@0:8@?16
METHOD aaf_firstObjectPassingTest: @24@0:8@?16
METHOD aaf_map: @24@0:8@?16
METHOD aaf_arrayAsCommaSeperatedString @16@0:8
METHOD aaf_hasObjects B16@0:8
METHOD aaf_isSubsetOfArray: B24@0:8@16
METHOD aaf_mapStoppable: @24@0:8@?16
METHOD _EX_arrayAtIndex: @24@0:8Q16
METHOD _EX_boolAtIndex: B24@0:8Q16
METHOD _EX_boolAtIndex:defaultValue: B28@0:8Q16B24
METHOD _EX_dictionaryAtIndex: @24@0:8Q16
METHOD _EX_objectAtIndex:ofClass: @32@0:8Q16#24
METHOD _EX_stringAtIndex: @24@0:8Q16
METHOD _OS_xpcObjectRepresentation @16@0:8
METHOD resourceStack @16@0:8
METHOD longestKeyLength Q16@0:8
METHOD un_nonEmptyCopy @16@0:8
METHOD un_map: @24@0:8@?16
METHOD un_each: v24@0:8@?16
METHOD un_filter: @24@0:8@?16
METHOD un_safeArrayContainingClass: @24@0:8#16
METHOD un_safeArrayContainingClasses: @24@0:8@16
METHOD _pas_componentsJoinedByString: @24@0:8@16
METHOD _pas_enumerateChunksOfSize:usingBlock: v32@0:8Q16@?24
METHOD _pas_filteredArrayWithIndexedTest: @24@0:8@?16
METHOD _pas_filteredArrayWithTest: @24@0:8@?16
METHOD _pas_mappedArrayWithIndexedTransform: @24@0:8@?16
METHOD _pas_mappedArrayWithTransform: @24@0:8@?16
METHOD _pas_proxyArrayWithRepetitions: @24@0:8Q16
METHOD _pas_ensureImmutable @16@0:8
METHOD _pas_leftFoldWithInitialObject:accumulate: @32@0:8@16@?24
METHOD _pas_leftFoldWithInitialObject:indexedAccumulate: @32@0:8@16@?24
METHOD _pas_proxyArrayByAppendingArray: @24@0:8@16
METHOD _pas_proxyArrayDistillingStrings @16@0:8
METHOD _pas_proxyArrayReversed @16@0:8
METHOD _pas_proxyArrayRevivingStrings @16@0:8
METHOD _pas_proxyArrayWithMapping: @24@0:8@?16
METHOD _pas_proxyArrayWithObjectsAtIndexes: @24@0:8@16
METHOD _pas_proxyComponentsJoinedByString: @24@0:8@16
METHOD _pas_proxySubarrayWithRange: @32@0:8{_NSRange=QQ}16
METHOD _pas_rightFoldWithInitialObject:accumulate: @32@0:8@16@?24
METHOD _pas_rightFoldWithInitialObject:indexedAccumulate: @32@0:8@16@?24
METHOD _pas_shuffledArrayUsingRng: @24@0:8@16
METHOD _pas_unlazyArray @16@0:8
METHOD _pas_unproxy @16@0:8
METHOD cuFilteredArrayUsingBlock: @24@0:8@?16
METHOD encodedBytesAndReturnLength:error: r*32@0:8^Q16^@24
METHOD encodedDataAndReturnError: @24@0:8^@16
METHOD dicomVRForArray @16@0:8
METHOD sortedPids @16@0:8
METHOD powerSet @16@0:8
METHOD _bmdsl_randomObjectForKey: @24@0:8@16
METHOD bmdsl_randomObject @16@0:8
METHOD dslWithClass: @24@0:8#16
METHOD dslWithValueClassName: @24@0:8@16
METHOD axFilterObjectsUsingBlock: @24@0:8@?16
METHOD axFirstObjectsUsingBlock: @24@0:8@?16
METHOD axIsEqualToOrderedArray:withPredicate: B32@0:8@16@?24
METHOD axMapObjectsUsingBlock: @24@0:8@?16
METHOD axSafeObjectAtIndex: @24@0:8Q16
METHOD axUniqueArrayWithPredicate: @24@0:8@?16
METHOD ax_arrayByRemovingDuplicates @16@0:8
METHOD ax_containsObjectUsingBlock: B24@0:8@?16
METHOD ax_filteredArrayUsingBlock: @24@0:8@?16
METHOD ax_firstObjectUsingBlock: @24@0:8@?16
METHOD ax_flatMappedArrayUsingBlock: @24@0:8@?16
METHOD ax_mappedArrayUsingBlock: @24@0:8@?16
METHOD cutFirstObject @16@0:8
METHOD ct_descriptionWithShortDescriptions @16@0:8
METHOD containsObjectIdenticalTo: B24@0:8@16
METHOD SHA256HexString @16@0:8
METHOD SHA256Data @16@0:8
METHOD __imFirstObject @16@0:8
METHOD _SHA256Bytes: v24@0:8*16
METHOD __IMStripPotentialTokenURIs @16@0:8
METHOD __imArrayByApplyingBlock: @24@0:8@?16
METHOD __imArrayByApplyingBlock:filter: @32@0:8@?16@?24
METHOD __imArrayByFilteringWithBlock: @24@0:8@?16
METHOD __imDeepCopy @16@0:8
METHOD __imForEach: v24@0:8@?16
METHOD __imIsMutable B16@0:8
METHOD __imMapToDictionary: @24@0:8@?16
METHOD __imSetFromArray @16@0:8
METHOD _copyForEnumerating @16@0:8
METHOD _hasSameMembers: B24@0:8@16
METHOD containsObject:matchingComparison: B32@0:8@16:24
METHOD indexOfObject:matchingComparison: q32@0:8@16:24
METHOD _arrayByFilteringCandidatesForNonExtendedView @16@0:8
METHOD _arrayByFilteringEmojiCandidates: @24@0:8q16
METHOD _sortedArrayByFrequency @16@0:8
METHOD _sortedArrayByFrequency:extensionCandidateIndex:maxEmojisPerCandidate:ignoreTransliterateCandidate: @44@0:8Q16Q24Q32B40
METHOD _geo_compactMap: @24@0:8@?16
METHOD _geo_filtered: @24@0:8@?16
METHOD _geo_firstPhotoOfAtLeastSize: @32@0:8{CGSize=dd}16
METHOD _geo_map: @24@0:8@?16
METHOD _geo_newXPCObject @16@0:8
METHOD exMRL_numberArrayDescription @16@0:8
METHOD VNObservationsWithOriginatingRequestSpecifier: @24@0:8@16
METHOD vn_enumerateObjectsAsSubarraysOfCount:usingBlock: v32@0:8Q16@?24
METHOD _fieldsOfSource: @24@0:8Q16
METHOD _fieldsOfType: @24@0:8Q16
METHOD _flattenedFields @16@0:8
METHOD _nonFieldRegions @16@0:8
METHOD crCodableDataRepresentation @16@0:8
METHOD initWithCRCodableDataRepresentation:objectProviderBlock: @32@0:8@16@?24
METHOD CKMapWithIndex: @24@0:8@?16
METHOD CKShuffledArray @16@0:8
METHOD CKAssignToContainerWithID: v24@0:8@16
METHOD CKCompactMap: @24@0:8@?16
METHOD CKContains: B24@0:8@?16
METHOD CKDeepCopy @16@0:8
METHOD CKDescriptionPropertiesWithPublic:private:shouldExpand: @28@0:8B16B20B24
METHOD CKFirstObjectPassingTest: @24@0:8@?16
METHOD CKReduceIntoDictionary: @24@0:8@?16
METHOD CKCompactMapToDictionary: @24@0:8@?16
METHOD CKCompactReduceIntoDictionary: @24@0:8@?16
METHOD CKComponentsAndSubcomponentsJoinedByString: @24@0:8@16
METHOD CKDeepCopyWithLeafNodeCopyBlock: @24@0:8@?16
METHOD CKFilter: @24@0:8@?16
METHOD CKFirstObjectWithOptions:passingTest: @32@0:8Q16@?24
METHOD CKFlatMap: @24@0:8@?16
METHOD CKMap: @24@0:8@?16
METHOD CKMapToDictionary: @24@0:8@?16
METHOD _CKReduceIntoDictionary:block: @28@0:8B16@?20
METHOD ckEquivalencyProperties @16@0:8
METHOD cksqlcs_appendSQLConstantValueToString: @24@0:8@16
METHOD _injectProxiesForImages:completion: v32@0:8@?16@?24
METHOD _keyImage @16@0:8
METHOD _intents_compareValue:relation: B32@0:8@16Q24
METHOD _intents_indexingRepresentation @16@0:8
METHOD _JSONDictionaryRepresentationForIntent:parameterName: @32@0:8@16@24
METHOD _compareSubProducerOne:subProducerTwo: q32@0:8@16@24
METHOD _intents_cacheableObjects @16@0:8
METHOD _intents_encodeWithJSONEncoder:codableDescription: @32@0:8@16@24
METHOD _intents_localizedCopyWithLocalizer: @24@0:8@16
METHOD _intents_readableTitleWithLocalizer:metadata: @32@0:8@16@24
METHOD _intents_updateContainerWithCache: v24@0:8@16
METHOD descriptionAtIndent: @24@0:8Q16
METHOD resolutionResultDataForIntent:intentSlotDescription:error: @40@0:8@16@24^@32
METHOD transformResolutionResultForIntent:intentSlotDescription:withOptionsProvider:completion: v48@0:8@16@24@32@?40
METHOD if_map: @24@0:8@?16
METHOD if_arrayByRemovingObject: @24@0:8@16
METHOD if_compactMap: @24@0:8@?16
METHOD if_escapedComponentsJoinedByString:forLocale: @32@0:8@16@24
METHOD if_firstObjectPassingTest: @24@0:8@?16
METHOD if_flatMap: @24@0:8@?16
METHOD if_objectsPassingTest: @24@0:8@?16
METHOD if_firstObjectWithValue:forKey: @32@0:8@16@24
METHOD if_arrayByRemovingObjectsInArray: @24@0:8@16
METHOD if_enumerateAsynchronously:completionHandler: v32@0:8@?16@?24
METHOD if_enumerateAsynchronouslyInSequence:completionHandler: v32@0:8@?16@?24
METHOD if_enumerateAsynchronouslyInSequenceOnQueue:block:completionHandler: v40@0:8@16@?24@?32
METHOD if_enumerateAsynchronouslyOnQueue:block:completionHandler: v40@0:8@16@?24@?32
METHOD if_firstObjectWithIntValue:forKey: @28@0:8i16@20
METHOD if_flatMapAsynchronously:completionHandler: v32@0:8@?16@?24
METHOD if_mapAsynchronously:completionHandler: v32@0:8@?16@?24
METHOD if_objectsOfClass: @24@0:8#16
METHOD if_objectsWithBoolValue:forKey: @28@0:8B16@20
METHOD if_firstObjectWithBoolValue:forKey: @28@0:8B16@20
METHOD if_objectsNotOfClass: @24@0:8#16
METHOD if_objectsWithIntValue:forKey: @28@0:8i16@20
METHOD if_objectsWithValue:forKey: @32@0:8@16@24
METHOD _inf_flatMap: @24@0:8@?16
METHOD _inf_objectsPassingTest: @24@0:8@?16
METHOD if_compactMapConcurrently: @24@0:8@?16
METHOD if_flatMapAsynchronouslyOnQueue:transform:completionHandler: v40@0:8@16@?24@?32
METHOD if_mapAsynchronouslyOnQueue:transform:completionHandler: v40@0:8@16@?24@?32
METHOD if_mapConcurrently: @24@0:8@?16
METHOD sg_enumerateChunksOfSize:usingBlock: v32@0:8Q16@?24
METHOD encodeWithCSCoder: v24@0:8@16
METHOD br_all_of_type: B24@0:8#16
METHOD br_firstItemOf: @24@0:8@?16
METHOD _br_minMaxWithMax:comparator: @28@0:8B16@?20
METHOD br_all_of: B24@0:8@?16
METHOD br_any_of: B24@0:8@?16
METHOD br_copy_if: @24@0:8@?16
METHOD br_count_if: Q24@0:8@?16
METHOD br_lastIndexOfObject: Q24@0:8@16
METHOD br_maxWithComparator: @24@0:8@?16
METHOD br_minWithComparator: @24@0:8@?16
METHOD br_none_of: B24@0:8@?16
METHOD br_transform: @24@0:8@?16
METHOD br_transform:keepNull: @28@0:8@?16B24
METHOD br_zipApplyWithArray:applyBlock: @32@0:8@16@?24
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD sf_differencesFromArray:removedIndexes:insertedIndexes: v40@0:8@16^@24^@32
METHOD sf_differencesFromArray:usingComparator:removedIndexes:insertedIndexes: v48@0:8@16@?24^@32^@40
METHOD filteredLanguagesBySearchString: @24@0:8@16
METHOD fm_any: B24@0:8@?16
METHOD fm_map: @24@0:8@?16
METHOD fm_all: B24@0:8@?16
METHOD fm_arrayByFlattening @16@0:8
METHOD fm_arrayWithResultsOfBlock: @24@0:8@?16
METHOD fm_dictionaryWithKeyGenerator: @24@0:8@?16
METHOD fm_each: v24@0:8@?16
METHOD fm_filter: @24@0:8@?16
METHOD fm_firstObjectPassingTest: @24@0:8@?16
METHOD avt_float3 16@0:8
METHOD avt_float4 16@0:8
METHOD avt_float4x4 {?=[4]}16@0:8
METHOD avt_mutableContainersCopy @16@0:8
METHOD avt_randomObject @16@0:8
METHOD SCNMutableDeepCopy @16@0:8
METHOD SCN_simdMatrix4Value {?=[4]}16@0:8
METHOD VFXMutableDeepCopy @16@0:8
METHOD VFX_compactMapObjectsUsingBlock: @24@0:8@?16
METHOD _ui_firstObject @16@0:8
METHOD _filteredArrayOfObjectsPassingTest: @24@0:8@?16
METHOD _legacy_drawComponentsJoinedByString:atPoint:forWidth:withFont:lineBreakMode: {CGSize=dd}56@0:8@16^{CGPoint=dd}24d32@40q48
METHOD _makeObjectsPerformSelector:object:range: v48@0:8:16@24{_NSRange=QQ}32
METHOD _ui_onlyObject @16@0:8
METHOD ui_arrayByRemovingLastObjectEqualTo: @24@0:8@16
METHOD unionRange {_NSRange=QQ}16@0:8
METHOD sh_allClassNames @16@0:8
METHOD _doc_ranksForInsertingBelowRank:spacing:count: @40@0:8@16Q24Q32
METHOD doc_computeNewRankForIndex: @24@0:8q16
METHOD doc_ranksForInsertingBelowRank:count: @32@0:8@16Q24
METHOD doc_ranksForInsertingBetweenHigherRank:lowerRank:count: @40@0:8@16@24Q32
METHOD fpfs_syncFPItemsFromNodes @16@0:8
METHOD _web_lowercaseStrings @16@0:8
METHOD bls_boundedDescriptionWithMax:transformer: @32@0:8q16@?24
METHOD bls_boundedDescription @16@0:8
METHOD bls_boundedDescriptionWithMax: @24@0:8q16
METHOD bls_boundedDescriptionWithTransformer: @24@0:8@?16
METHOD _axRecursivelyPropertyListCoercedRepresentationWithError: @24@0:8^@16
METHOD _axRecursivelyReconstitutedRepresentationFromPropertyListWithError: @24@0:8^@16
METHOD debugDescription @16@0:8
METHOD classForCoder #16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithContentsOfFile: @24@0:8@16
METHOD initWithContentsOfURL: @24@0:8@16
METHOD _distinctUnionOfSetsForKeyPath: @24@0:8@16
METHOD _maxForKeyPath: @24@0:8@16
METHOD _minForKeyPath: @24@0:8@16
METHOD _sumForKeyPath: @24@0:8@16
METHOD _avgForKeyPath: @24@0:8@16
METHOD sortedArrayHint @16@0:8
METHOD _countForKeyPath: @24@0:8@16
METHOD _distinctUnionOfArraysForKeyPath: @24@0:8@16
METHOD _distinctUnionOfObjectsForKeyPath: @24@0:8@16
METHOD _mutableArrayValueForKeyPath:ofObjectAtIndex: @32@0:8@16Q24
METHOD _mutableOrderedSetValueForKeyPath:ofObjectAtIndex: @32@0:8@16Q24
METHOD _mutableSetValueForKeyPath:ofObjectAtIndex: @32@0:8@16Q24
METHOD _setValue:forKeyPath:ofObjectAtIndex: v40@0:8@16@24Q32
METHOD _stringToWrite @16@0:8
METHOD _unionOfArraysForKeyPath: @24@0:8@16
METHOD _unionOfObjectsForKeyPath: @24@0:8@16
METHOD _unionOfSetsForKeyPath: @24@0:8@16
METHOD _validateValue:forKeyPath:ofObjectAtIndex:error: B48@0:8N^@16@24Q32o^@40
METHOD _valueForKeyPath:ofObjectAtIndex: @32@0:8@16Q24
METHOD addObserver:forKeyPath:options:context: v48@0:8@16@24Q32^v40
METHOD addObserver:toObjectsAtIndexes:forKeyPath:options:context: v56@0:8@16@24@32Q40^v48
METHOD arrayByApplyingDifference: @24@0:8@16
METHOD differenceFromArray: @24@0:8@16
METHOD differenceFromArray:withOptions: @32@0:8@16Q24
METHOD differenceFromArray:withOptions:usingEquivalenceTest: @40@0:8@16Q24@?32
METHOD filteredArrayUsingPredicate: @24@0:8@16
METHOD initWithContentsOfURL:error: @32@0:8@16^@24
METHOD pathsMatchingExtensions: @24@0:8@16
METHOD removeObserver:forKeyPath: v32@0:8@16@24
METHOD removeObserver:forKeyPath:context: v40@0:8@16@24^v32
METHOD removeObserver:fromObjectsAtIndexes:forKeyPath: v40@0:8@16@24@32
METHOD removeObserver:fromObjectsAtIndexes:forKeyPath:context: v48@0:8@16@24@32^v40
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD setValue:forKey: v32@0:8@16@24
METHOD sortedArrayUsingDescriptors: @24@0:8@16
METHOD sortedArrayUsingFunction:context:hint: @40@0:8^?16^v24@32
METHOD sortedArrayUsingSelector:hint: @32@0:8:16@24
METHOD stringsByAppendingPathComponent: @24@0:8@16
METHOD valueForKey: @24@0:8@16
METHOD valueForKeyPath: @24@0:8@16
METHOD writeToFile:atomically: B28@0:8@16B24
METHOD writeToURL:atomically: B28@0:8@16B24
METHOD writeToURL:error: B32@0:8@16^@24
METHOD ls_caseInsensitiveContainsString: B24@0:8@16
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD isEqual: B24@0:8@16
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD initWithObject: @24@0:8@16
METHOD isEqualToArray: B24@0:8@16
METHOD _cfTypeID Q16@0:8
METHOD arrayByExcludingObjectsInArray: @24@0:8@16
METHOD containsObject: B24@0:8@16
METHOD countForObject: Q24@0:8@16
METHOD objectsWithOptions:passingTest: @32@0:8Q16@?24
METHOD _initByAdoptingBuffer:count:size: @40@0:8^@16Q24Q32
METHOD allObjects @16@0:8
METHOD arrayByAddingObject: @24@0:8@16
METHOD arrayByAddingObjectsFromArray: @24@0:8@16
METHOD arrayByApplyingSelector: @24@0:8:16
METHOD arrayByExcludingToObjectsInArray: @24@0:8@16
METHOD componentsJoinedByString: @24@0:8@16
METHOD containsObject:inRange: B40@0:8@16{_NSRange=QQ}24
METHOD containsObjectIdenticalTo: B24@0:8@16
METHOD containsObjectIdenticalTo:inRange: B40@0:8@16{_NSRange=QQ}24
METHOD count Q16@0:8
METHOD countByEnumeratingWithState:objects:count: Q40@0:8^{?=Q^@^Q[5Q]}16^@24Q32
METHOD countForObject:inRange: Q40@0:8@16{_NSRange=QQ}24
METHOD descriptionWithLocale: @24@0:8@16
METHOD descriptionWithLocale:indent: @32@0:8@16Q24
METHOD encodeWithCoder: v24@0:8@16
METHOD enumerateObjectsAtIndexes:options:usingBlock: v40@0:8@16Q24@?32
METHOD enumerateObjectsUsingBlock: v24@0:8@?16
METHOD enumerateObjectsWithOptions:usingBlock: v32@0:8Q16@?24
METHOD firstObject @16@0:8
METHOD firstObjectCommonWithArray: @24@0:8@16
METHOD getObjects: v24@0:8^@16
METHOD getObjects:range: v40@0:8^@16{_NSRange=QQ}24
METHOD indexOfObject: Q24@0:8@16
METHOD indexOfObject:inRange: Q40@0:8@16{_NSRange=QQ}24
METHOD indexOfObject:inSortedRange:options:usingComparator: Q56@0:8@16{_NSRange=QQ}24Q40@?48
METHOD indexOfObjectAtIndexes:options:passingTest: Q40@0:8@16Q24@?32
METHOD indexOfObjectIdenticalTo: Q24@0:8@16
METHOD indexOfObjectIdenticalTo:inRange: Q40@0:8@16{_NSRange=QQ}24
METHOD indexOfObjectPassingTest: Q24@0:8@?16
METHOD indexOfObjectWithOptions:passingTest: Q32@0:8Q16@?24
METHOD indexesOfObject: @24@0:8@16
METHOD indexesOfObject:inRange: @40@0:8@16{_NSRange=QQ}24
METHOD indexesOfObjectIdenticalTo: @24@0:8@16
METHOD indexesOfObjectIdenticalTo:inRange: @40@0:8@16{_NSRange=QQ}24
METHOD indexesOfObjectsAtIndexes:options:passingTest: @40@0:8@16Q24@?32
METHOD indexesOfObjectsPassingTest: @24@0:8@?16
METHOD indexesOfObjectsWithOptions:passingTest: @32@0:8Q16@?24
METHOD initWithArray: @24@0:8@16
METHOD initWithArray:copyItems: @28@0:8@16B24
METHOD initWithArray:range: @40@0:8@16{_NSRange=QQ}24
METHOD initWithArray:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
METHOD initWithCoder: @24@0:8@16
METHOD initWithObjects: @24@0:8@16
METHOD initWithObjects:count: @32@0:8r^@16Q24
METHOD initWithOrderedSet: @24@0:8@16
METHOD initWithOrderedSet:copyItems: @28@0:8@16B24
METHOD initWithOrderedSet:range: @40@0:8@16{_NSRange=QQ}24
METHOD initWithOrderedSet:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
METHOD initWithSet: @24@0:8@16
METHOD initWithSet:copyItems: @28@0:8@16B24
METHOD isNSArray__ B16@0:8
METHOD lastObject @16@0:8
METHOD makeObjectsPerformSelector: v24@0:8:16
METHOD makeObjectsPerformSelector:withObject: v32@0:8:16@24
METHOD objectAtIndex: @24@0:8Q16
METHOD objectAtIndexedSubscript: @24@0:8Q16
METHOD objectAtIndexes:options:passingTest: @40@0:8@16Q24@?32
METHOD objectEnumerator @16@0:8
METHOD objectPassingTest: @24@0:8@?16
METHOD objectWithOptions:passingTest: @32@0:8Q16@?24
METHOD objectsAtIndexes: @24@0:8@16
METHOD objectsAtIndexes:options:passingTest: @40@0:8@16Q24@?32
METHOD objectsPassingTest: @24@0:8@?16
METHOD reverseObjectEnumerator @16@0:8
METHOD reversedArray @16@0:8
METHOD sortedArrayFromRange:options:usingComparator: @48@0:8{_NSRange=QQ}16Q32@?40
METHOD sortedArrayUsingComparator: @24@0:8@?16
METHOD sortedArrayUsingFunction:context: @32@0:8^?16^v24
METHOD sortedArrayUsingSelector: @24@0:8:16
METHOD sortedArrayWithOptions:usingComparator: @32@0:8Q16@?24
METHOD subarrayWithRange: @32@0:8{_NSRange=QQ}16

=== CLASS NSBundle ===
SUPER: NSObject
SIZE: 72
IVAR +8 0 _flags AQ
IVAR +16 0 _cfBundle A^{__CFBundle}
IVAR +24 0 _attributedStringTable @"NSMutableDictionary"
IVAR +32 0 _principalClass #
IVAR +40 0 _initialPath @
IVAR +48 0 _resolvedPath @
IVAR +56 0 _firstClassName @"NSString"
IVAR +64 0 _lock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
CMETHOD currentNibLoadingBundle @16@0:8
CMETHOD currentNibPath @16@0:8
CMETHOD popNibLoadingBundle v16@0:8
CMETHOD popNibPath v16@0:8
CMETHOD pushNibLoadingBundle: v24@0:8@16
CMETHOD pushNibPath: v24@0:8@16
CMETHOD __geoBundle @16@0:8
CMETHOD un_safeBundleWithURL: @24@0:8@16
CMETHOD userNotificationsBundleWithIdentifier: @24@0:8@16
CMETHOD _setCoreMaterialOverrideRecipeBundleURL: v24@0:8@16
CMETHOD coreMaterialOverrideRecipeBundle @16@0:8
CMETHOD coreMaterialOverrideRecipeBundleURL @16@0:8
CMETHOD coreMaterialRecipeBundle @16@0:8
CMETHOD __IS__frameworkLocalizedString: @24@0:8@16
CMETHOD __IS__frameworkBundle @16@0:8
CMETHOD __IS__iconsetResourceAssetsCatalogURL @16@0:8
CMETHOD __IS__iconsetResourceBundle @16@0:8
CMETHOD debugDescription @16@0:8
CMETHOD URLsForResourcesWithExtension:subdirectory:inBundleWithURL: @40@0:8@16@24@32
CMETHOD bundleForClass: @24@0:8#16
CMETHOD bundleWithPath: @24@0:8@16
CMETHOD URLForResource:withExtension:subdirectory:inBundleWithURL: @48@0:8@16@24@32@40
CMETHOD _bundleWithIdentifier:andLibraryName: @32@0:8@16@24
CMETHOD _localizedStringsForKeys:forAllLocalizationsOfTable:inBundleWithURL: @40@0:8@16@24@32
CMETHOD allBundles @16@0:8
CMETHOD allFrameworks @16@0:8
CMETHOD bundleWithIdentifier: @24@0:8@16
CMETHOD bundleWithURL: @24@0:8@16
CMETHOD findBundleResourceURLsCallingMethod:baseURL:passingTest: @40@0:8:16@24@?32
CMETHOD findBundleResources:callingMethod:directory:languages:name:types:limit: @72@0:8@16:24@32@40@48@56Q64
CMETHOD loadedBundles @16@0:8
CMETHOD mainBundle @16@0:8
CMETHOD pathForResource:ofType:inDirectory: @40@0:8@16@24@32
CMETHOD pathsForResourcesOfType:inDirectory: @32@0:8@16@24
CMETHOD preferredLocalizationsFromArray: @24@0:8@16
CMETHOD preferredLocalizationsFromArray:forPreferences: @32@0:8@16@24
CMETHOD setSystemLanguages: v24@0:8@16
METHOD _preferredEnglishLocalizationBundle @16@0:8
METHOD dataForResourceName: @24@0:8@16
METHOD loadNibNamed:owner:options: @40@0:8@16@24@32
METHOD _cachedMainBundleResourcePath @16@0:8
METHOD URLForMaterialRecipeDescendant: @24@0:8@16
METHOD URLForVisualStyleSetDescendant: @24@0:8@16
METHOD URLForMaterialRecipe: @24@0:8@16
METHOD URLForVisualStyleSet: @24@0:8@16
METHOD URLsForMaterialRecipeDescendants @16@0:8
METHOD URLsForMaterialRecipes @16@0:8
METHOD URLsForVisualStyleSets @16@0:8
METHOD normalizedLocalizations @16@0:8
METHOD localizedStringInDeviceLanguageForKey: @24@0:8@16
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD load B16@0:8
METHOD initWithURL: @24@0:8@16
METHOD bundleLanguages @16@0:8
METHOD URLForResource:withExtension:subdirectory: @40@0:8@16@24@32
METHOD URLForResource:withExtension:subdirectory:localization: @48@0:8@16@24@32@40
METHOD URLForAuxiliaryExecutable: @24@0:8@16
METHOD URLForResource:withExtension: @32@0:8@16@24
METHOD URLsForResourcesWithExtension:subdirectory: @32@0:8@16@24
METHOD URLsForResourcesWithExtension:subdirectory:localization: @40@0:8@16@24@32
METHOD setPreservationPriority:forTag: v32@0:8d16@24
METHOD __static v16@0:8
METHOD _cfBundle ^{__CFBundle=}16@0:8
METHOD _cfBundleIfPresent ^{__CFBundle=}16@0:8
METHOD _initUniqueWithPath: @24@0:8@16
METHOD _initUniqueWithURL: @24@0:8@16
METHOD _localizedStringForKey:value:table:localizations: @48@0:8@16@24@32@40
METHOD _localizedStringNoCacheNoMarkdownParsingForKey:value:table:localizations:actualTableURL:formatSpecifierConfiguration: @64@0:8@16@24@32@40^@48^@56
METHOD _localizedStringsForKeys:forAllLocalizationsOfTable: @32@0:8@16@24
METHOD _objectForUnlocalizedInfoDictionaryKey: @24@0:8@16
METHOD _pathForResource:ofType:inDirectory:forRegion: @48@0:8@16@24@32@40
METHOD _pathsForResourcesOfType:inDirectory:forRegion: @40@0:8@16@24@32
METHOD _regionsArray @16@0:8
METHOD _searchForLocalizedString:foundKey:foundTable: B40@0:8@16^@24^@32
METHOD _wrappedBundleURL @16@0:8
METHOD _wrapperContainerURL @16@0:8
METHOD appStoreReceiptURL @16@0:8
METHOD builtInPlugInsPath @16@0:8
METHOD builtInPlugInsURL @16@0:8
METHOD bundleIdentifier @16@0:8
METHOD bundlePath @16@0:8
METHOD bundleURL @16@0:8
METHOD classNamed: #24@0:8@16
METHOD developmentLocalization @16@0:8
METHOD executableArchitectures @16@0:8
METHOD executablePath @16@0:8
METHOD executableURL @16@0:8
METHOD findBundleResourceURLsCallingMethod:passingTest: @32@0:8:16@?24
METHOD infoDictionary @16@0:8
METHOD initWithPath: @24@0:8@16
METHOD invalidateResourceCache v16@0:8
METHOD isLoaded B16@0:8
METHOD loadAndReturnError: B24@0:8^@16
METHOD localizations @16@0:8
METHOD localizedAttributedStringForKey:value:table: @40@0:8@16@24@32
METHOD localizedAttributedStringForKey:value:table:localization: @48@0:8@16@24@32@40
METHOD localizedInfoDictionary @16@0:8
METHOD localizedStringForKey:value:table: @40@0:8@16@24@32
METHOD localizedStringForKey:value:table:localization: @48@0:8@16@24@32@40
METHOD localizedStringForKey:value:table:localizations: @48@0:8@16@24@32@40
METHOD localizedStringsForTable:localization: @32@0:8@16@24
METHOD objectForInfoDictionaryKey: @24@0:8@16
METHOD pathForAuxiliaryExecutable: @24@0:8@16
METHOD pathForResource:ofType: @32@0:8@16@24
METHOD pathForResource:ofType:inDirectory: @40@0:8@16@24@32
METHOD pathForResource:ofType:inDirectory:forLanguage: @48@0:8@16@24@32@40
METHOD pathForResource:ofType:inDirectory:forLocalization: @48@0:8@16@24@32@40
METHOD pathsForResourcesOfType:inDirectory: @32@0:8@16@24
METHOD pathsForResourcesOfType:inDirectory:forLanguage: @40@0:8@16@24@32
METHOD pathsForResourcesOfType:inDirectory:forLocalization: @40@0:8@16@24@32
METHOD preferredLocalizations @16@0:8
METHOD preflightAndReturnError: B24@0:8^@16
METHOD preservationPriorityForTag: d24@0:8@16
METHOD principalClass #16@0:8
METHOD privateFrameworksPath @16@0:8
METHOD privateFrameworksURL @16@0:8
METHOD resourcePath @16@0:8
METHOD resourceURL @16@0:8
METHOD setPreservationPriority:forTags: v32@0:8d16@24
METHOD sharedFrameworksPath @16@0:8
METHOD sharedFrameworksURL @16@0:8
METHOD sharedSupportPath @16@0:8
METHOD sharedSupportURL @16@0:8
METHOD unload B16@0:8
METHOD versionNumber Q16@0:8

=== CLASS NSByteCountFormatter ===
SUPER: NSFormatter
SIZE: 24
PROTOCOLS: NSObservable NSObserver
IVAR +8 0 _allowedUnits I
IVAR +12 0 _formattingContext i
IVAR +16 0 _countStyle c
IVAR +17 0 _allowsNonnumericFormatting B
IVAR +18 0 _includesUnit B
IVAR +19 0 _includesCount B
IVAR +20 0 _includesActualByteCount B
IVAR +21 0 _adaptive B
IVAR +22 0 _zeroPadsFractionDigits B
CMETHOD stringFromByteCount:countStyle: @32@0:8q16q24
CMETHOD stringFromMeasurement:countStyle: @32@0:8@16q24
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD _mayDecorateAttributedStringForObjectValue: B24@0:8@16
METHOD _options Q16@0:8
METHOD allowedUnits Q16@0:8
METHOD allowsNonnumericFormatting B16@0:8
METHOD countStyle q16@0:8
METHOD formattingContext q16@0:8
METHOD getObjectValue:forString:errorDescription: B40@0:8o^@16@24o^@32
METHOD includesActualByteCount B16@0:8
METHOD includesCount B16@0:8
METHOD includesUnit B16@0:8
METHOD isAdaptive B16@0:8
METHOD isPartialStringValid:proposedSelectedRange:originalString:originalSelectedRange:errorDescription: B64@0:8^@16^{_NSRange=QQ}24@32{_NSRange=QQ}40^@56
METHOD receiveObservedValue: v24@0:8@16
METHOD setAdaptive: v20@0:8B16
METHOD setAllowedUnits: v24@0:8Q16
METHOD setAllowsNonnumericFormatting: v20@0:8B16
METHOD setCountStyle: v24@0:8q16
METHOD setFormattingContext: v24@0:8q16
METHOD setIncludesActualByteCount: v20@0:8B16
METHOD setIncludesCount: v20@0:8B16
METHOD setIncludesUnit: v20@0:8B16
METHOD setZeroPadsFractionDigits: v20@0:8B16
METHOD stringForObjectValue: @24@0:8@16
METHOD stringFromByteCount: @24@0:8q16
METHOD stringFromMeasurement: @24@0:8@16
METHOD zeroPadsFractionDigits B16@0:8

=== CLASS NSCache ===
SUPER: NSObject
SIZE: 48
IVAR +8 0 _cacheDelegate @"<NSCacheDelegate>"
IVAR +16 0 _cache ^{cache_s=}
IVAR +24 0 _discardableContentState C
IVAR +25 0 _evictOnSuspension B
IVAR +26 0 _evictsDiscarded B
IVAR +27 0 _moribund B
IVAR +28 0 _doDelegateWillEvictValue B
IVAR +29 0 _observesNotification B
IVAR +32 0 _notificationToken Q
IVAR +40 0 _notificationLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
METHOD mapTableRepresentation @16@0:8
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD __apply: v24@0:8@?16
METHOD allObjects @16@0:8
METHOD countLimit Q16@0:8
METHOD delegate @16@0:8
METHOD evictsObjectsWhenApplicationEntersBackground B16@0:8
METHOD evictsObjectsWithDiscardedContent B16@0:8
METHOD minimumObjectCount Q16@0:8
METHOD objectForKey: @24@0:8@16
METHOD removeAllObjects v16@0:8
METHOD removeObjectForKey: v24@0:8@16
METHOD setCountLimit: v24@0:8Q16
METHOD setDelegate: v24@0:8@16
METHOD setEvictsObjectsWhenApplicationEntersBackground: v20@0:8B16
METHOD setEvictsObjectsWithDiscardedContent: v20@0:8B16
METHOD setMinimumObjectCount: v24@0:8Q16
METHOD setName: v24@0:8@16
METHOD setObject:forKey: v32@0:8@16@24
METHOD setObject:forKey:cost: v40@0:8@16@24Q32
METHOD setTotalCostLimit: v24@0:8Q16
METHOD totalCostLimit Q16@0:8

=== CLASS NSConstantArray ===
SUPER: NSArray
SIZE: 24
IVAR +8 0 _count Q
IVAR +16 0 _objects r^@
CMETHOD new @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
METHOD _isDeallocating B16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD _tryRetain B16@0:8
METHOD autorelease @16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD mutableCopy @16@0:8
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD count Q16@0:8
METHOD getObjects:range: v40@0:8^@16{_NSRange=QQ}24
METHOD initWithObjects:count: @32@0:8r^@16Q24
METHOD objectAtIndex: @24@0:8Q16
METHOD objectAtIndexedSubscript: @24@0:8Q16
METHOD objectEnumerator @16@0:8

=== CLASS NSConstantDictionary ===
SUPER: NSDictionary
SIZE: 40
PROTOCOLS: NSFastEnumeration
IVAR +8 0 _options Q
IVAR +16 0 _count Q
IVAR +24 0 _keys r^@
IVAR +32 0 _objects r^@
CMETHOD new @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
METHOD _isDeallocating B16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD _tryRetain B16@0:8
METHOD autorelease @16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD mutableCopy @16@0:8
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD allKeys @16@0:8
METHOD __apply:context: v32@0:8^?16^v24
METHOD allValues @16@0:8
METHOD count Q16@0:8
METHOD countByEnumeratingWithState:objects:count: Q40@0:8^{?=Q^@^Q[5Q]}16^@24Q32
METHOD enumerateKeysAndObjectsWithOptions:usingBlock: v32@0:8Q16@?24
METHOD getObjects:andKeys:count: v40@0:8^@16^@24Q32
METHOD initWithObjects:forKeys:count: @40@0:8r^@16r^@24Q32
METHOD keyEnumerator @16@0:8
METHOD keyOfEntryWithOptions:passingTest: @32@0:8Q16@?24
METHOD keysOfEntriesWithOptions:passingTest: @32@0:8Q16@?24
METHOD objectEnumerator @16@0:8
METHOD objectForKey: @24@0:8@16
METHOD objectForKeyedSubscript: @24@0:8@16

=== CLASS NSConstantDoubleNumber ===
SUPER: NSNumber
SIZE: 16
IVAR +8 0 _value d
CMETHOD new @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
METHOD _isDeallocating B16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD _tryRetain B16@0:8
METHOD autorelease @16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD charValue c16@0:8
METHOD doubleValue d16@0:8
METHOD floatValue f16@0:8
METHOD intValue i16@0:8
METHOD longLongValue q16@0:8
METHOD longValue q16@0:8
METHOD objCType r*16@0:8
METHOD shortValue s16@0:8
METHOD unsignedCharValue C16@0:8
METHOD unsignedIntValue I16@0:8
METHOD unsignedLongLongValue Q16@0:8
METHOD unsignedLongValue Q16@0:8
METHOD unsignedShortValue S16@0:8
METHOD boolValue B16@0:8
METHOD getValue: v24@0:8^v16
METHOD integerValue q16@0:8
METHOD unsignedIntegerValue Q16@0:8
METHOD decimalValue {?=b8b4b1b1b18[8S]}16@0:8
METHOD getValue:size: v32@0:8^v16Q24

=== CLASS NSConstantFloatNumber ===
SUPER: NSNumber
SIZE: 16
IVAR +8 0 _value f
CMETHOD new @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
METHOD _isDeallocating B16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD _tryRetain B16@0:8
METHOD autorelease @16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD charValue c16@0:8
METHOD doubleValue d16@0:8
METHOD floatValue f16@0:8
METHOD intValue i16@0:8
METHOD longLongValue q16@0:8
METHOD longValue q16@0:8
METHOD objCType r*16@0:8
METHOD shortValue s16@0:8
METHOD unsignedCharValue C16@0:8
METHOD unsignedIntValue I16@0:8
METHOD unsignedLongLongValue Q16@0:8
METHOD unsignedLongValue Q16@0:8
METHOD unsignedShortValue S16@0:8
METHOD boolValue B16@0:8
METHOD getValue: v24@0:8^v16
METHOD integerValue q16@0:8
METHOD unsignedIntegerValue Q16@0:8
METHOD decimalValue {?=b8b4b1b1b18[8S]}16@0:8
METHOD getValue:size: v32@0:8^v16Q24

=== CLASS NSConstantIntegerNumber ===
SUPER: NSNumber
SIZE: 24
IVAR +8 0 _encoding r*
IVAR +16 0 _value q
CMETHOD new @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
METHOD _isDeallocating B16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD _tryRetain B16@0:8
METHOD autorelease @16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD charValue c16@0:8
METHOD doubleValue d16@0:8
METHOD floatValue f16@0:8
METHOD intValue i16@0:8
METHOD longLongValue q16@0:8
METHOD longValue q16@0:8
METHOD objCType r*16@0:8
METHOD shortValue s16@0:8
METHOD unsignedCharValue C16@0:8
METHOD unsignedIntValue I16@0:8
METHOD unsignedLongLongValue Q16@0:8
METHOD unsignedLongValue Q16@0:8
METHOD unsignedShortValue S16@0:8
METHOD boolValue B16@0:8
METHOD getValue: v24@0:8^v16
METHOD integerValue q16@0:8
METHOD unsignedIntegerValue Q16@0:8
METHOD decimalValue {?=b8b4b1b1b18[8S]}16@0:8
METHOD getValue:size: v32@0:8^v16Q24

=== CLASS NSData ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: CKPropertiesDescription CKRecordValue CUByteCodable INJSONSerializable _PASDistilledString PQLValuable _OSXPCObjectRepresentable CCDatabaseValue NSCopying NSMutableCopying NSSecureCoding
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD _subclassesMustBeExplicitlyMentionedWhenDecoded B16@0:8
CMETHOD data @16@0:8
CMETHOD dataWithBytes:length: @32@0:8r^v16Q24
CMETHOD _alloc @16@0:8
CMETHOD _base64DecodingAlwaysSucceedsForOptions: B24@0:8Q16
CMETHOD _newZeroingDataWithBytes:length: @32@0:8r^v16Q24
CMETHOD _newZeroingDataWithBytesNoCopy:length:deallocator: @40@0:8^v16Q24@?32
CMETHOD _readBytesAndEncodingFromPath:maxLength:encoding:bytes:length:didMap:options:reportProgress:error: B84@0:8@16q24^Q32^^v40^q48^B56Q64B72^@76
CMETHOD _readBytesFromPath:maxLength:bytes:length:didMap:options:reportProgress:error: B76@0:8@16q24^^v32^q40^B48Q56B64^@68
CMETHOD _writeDataToPath:data:options:reportProgress:error: B52@0:8@16@24Q32B40^@44
CMETHOD _writeDataToPath:data:options:stringEncodingAttributeData:reportProgress:error: B60@0:8@16@24Q32@40B48^@52
CMETHOD dataWithBytesNoCopy:length: @32@0:8^v16Q24
CMETHOD dataWithBytesNoCopy:length:freeWhenDone: @36@0:8^v16Q24B32
CMETHOD dataWithContentsOfFile: @24@0:8@16
CMETHOD dataWithContentsOfFile:options:error: @40@0:8@16Q24^@32
CMETHOD dataWithContentsOfMappedFile: @24@0:8@16
CMETHOD dataWithContentsOfURL: @24@0:8@16
CMETHOD dataWithContentsOfURL:options:error: @40@0:8@16Q24^@32
CMETHOD dataWithContentsOfURL:options:maxLength:error: @48@0:8@16Q24Q32^@40
CMETHOD dataWithData: @24@0:8@16
CMETHOD CKDataWithHexString:stringIsUppercase: @28@0:8@16B24
CMETHOD CKDataWithHexString: @24@0:8@16
CMETHOD MCDataWithCFData: @24@0:8^{__CFData=}16
CMETHOD MCDataFromFile: @24@0:8@16
CMETHOD MCDataWithHexString: @24@0:8@16
CMETHOD bs_dataWithVMAllocatedBytes:length: @32@0:8r^v16Q24
CMETHOD CKDataWithHexString:stringIsUppercase: @28@0:8@16B24
CMETHOD CKDataWithHexString: @24@0:8@16
CMETHOD CKDataFromBase64URLSafeString: @24@0:8@16
CMETHOD _geo_dataForHexString: @24@0:8@16
CMETHOD _geo_withXPCData: @24@0:8@16
CMETHOD __imDataWithHexString: @24@0:8@16
CMETHOD __imDataWithRandomBytes: @24@0:8Q16
CMETHOD __imHexStringOfBytes:withLength: @32@0:8*16Q24
CMETHOD createWithBytesNoCopy:length:error: @40@0:8^v16Q24^@32
CMETHOD _IDSDataFromBase64String: @24@0:8@16
CMETHOD ak_dataWithBase64UrlEncodedString: @24@0:8@16
CMETHOD _intents_decodeWithJSONDecoder:codableDescription:from: @40@0:8@16@24@32
CMETHOD encodedClipStrokeKeyframesFromString:subpathOffset: @28@0:8@16f24
CMETHOD mergingRawIndexedKeyframes: @24@0:8@16
CMETHOD fp_dataWithFavoriteRank: @24@0:8@16
CMETHOD fp_dataWithLastUsedDate: @24@0:8@16
CMETHOD _ISMutableStoreIndex_mappedDataWithCapacity:additionalSize: @32@0:8Q16Q24
CMETHOD _ISMutableStoreIndex_mappedDataWithSize: @24@0:8Q16
CMETHOD _ISMutableStoreIndex_mappedDataWithURL: @24@0:8@16
CMETHOD _ISStoreIndex_mappedDataWithURL: @24@0:8@16
CMETHOD __is__bookmarkDataWithContentsOfURL: @24@0:8@16
CMETHOD __is__dataWithContentsOfURL: @24@0:8@16
CMETHOD _is_invalidToken @16@0:8
CMETHOD _is_staleToken @16@0:8
CMETHOD _is_validToken @16@0:8
CMETHOD newFromSqliteStatement:atIndex: @28@0:8^{sqlite3_stmt=}16i24
CMETHOD newFromSqliteValue: @24@0:8^{sqlite3_value=}16
CMETHOD dataWithEncodedSequenceData:data:error: @40@0:8@16@24^@32
CMETHOD dataWithEncodedSequenceString:data:error: @40@0:8@16@24^@32
CMETHOD dataWithEncodedString:error: @32@0:8@16^@24
CMETHOD if_dataWithAuditToken: @48@0:8{?=[8I]}16
CMETHOD if_dataWithValue: @24@0:8@16
CMETHOD triDataWithHexString: @24@0:8@16
CMETHOD triVerifiedMappedDataWithFile:error: @32@0:8@16^@24
CMETHOD dataWithRandomBytesOfSize: @24@0:8Q16
CMETHOD fromUUID: @24@0:8@16
CMETHOD aaf_fromImageRef: @24@0:8^{CGImage=}16
CMETHOD DMCDataWithCFData: @24@0:8^{__CFData=}16
CMETHOD _DMCCreateFolderExistError @16@0:8
CMETHOD supportsSecureCoding B16@0:8
METHOD fp_favoriteRank @16@0:8
METHOD fp_lastUsedDate @16@0:8
METHOD getFileIDFromXattr:docID:genCount: B40@0:8^Q16^I24^Q32
METHOD bs_lengthForMIG I16@0:8
METHOD bs_bytesForMIG ^v16@0:8
METHOD MCHexString @16@0:8
METHOD MCSHA256Hash @16@0:8
METHOD NRSHA256: v24@0:8[32C]16
METHOD NRSHA256 @16@0:8
METHOD matchesDataAtFilePath: B24@0:8@16
METHOD toUUID @16@0:8
METHOD MI_writeAtomicallyToURL:withMode:owner:group:error: B44@0:8@16S24I28I32^@36
METHOD MI_writeAtomicallyToURL:withMode:owner:group:protectionClass:withBarrier:error: B52@0:8@16S24I28I32i36B40^@44
METHOD MI_writeAtomicallyToURL:withMode:owner:group:protectionClass:error: B48@0:8@16S24I28I32i36^@40
METHOD MI_writeAtomicallyToURLMatchingCurrentFileMetadata:error: B32@0:8@16^@24
METHOD __IS_copyCGImageBlockSetWithProvider: ^{CGImageBlockSet=}24@0:8^{CGImageProvider=}16
METHOD __IS_getImageBuffer:size: v32@0:8^^v16^Q24
METHOD __IS_imageHeader ^{?=IIIIffffff{?=CCC[1C]}f[0C]}16@0:8
METHOD validate: B24@0:8^Q16
METHOD rawKeyframeData @16@0:8
METHOD _rawKeyframesAtIndex:validatedOffsetCount: @32@0:8Q16Q24
METHOD clipStrokeKeyframeString @16@0:8
METHOD containsCompoundKeyframesAtIndex: B24@0:8Q16
METHOD encodedKeyframesReferencedSubpaths @16@0:8
METHOD encodedSubpathKeyframes @16@0:8
METHOD indexedRawKeyframes @16@0:8
METHOD isEqualToClipStrokeData:withAccuracy: B28@0:8@16f24
METHOD numOffsets I16@0:8
METHOD rawKeyframesAtIndex: @24@0:8Q16
METHOD rawKeyframesOffset Q16@0:8
METHOD CAMLType @16@0:8
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD _FTCopyGzippedData @16@0:8
METHOD _FTCopyOptionallyGzippedData @16@0:8
METHOD _FTStringFromBaseData @16@0:8
METHOD aa_compressedData: @20@0:8i16
METHOD aa_hexString @16@0:8
METHOD aaf_toHexString @16@0:8
METHOD aaf_toCompressedData: @20@0:8i16
METHOD aaf_toImageRef ^{CGImage=}16@0:8
METHOD ak_SHA256Data @16@0:8
METHOD DMCSHA256Hash @16@0:8
METHOD DMCAtomicWriteToPath:writeOptions:error: B40@0:8@16Q24^@32
METHOD DMCHexString @16@0:8
METHOD DMCAtomicWriteToURL:writeOptions:error: B40@0:8@16Q24^@32
METHOD _OS_xpcObjectRepresentation @16@0:8
METHOD _ISMutableStoreIndex_addBlobBuffer:size: (?={?=II}Q)32@0:8r^v16Q24
METHOD _ISMutableStoreIndex_addBlobData: (?={?=II}Q)24@0:8@16
METHOD _ISMutableStoreIndex_addValue: B24@0:8r^{?=[16C]{?=dd}dI[16C][16C]{?=[16C]Q[16C]}}16
METHOD _ISMutableStoreIndex_addValue:size:forUUID: B40@0:8r^v16Q24[16C]32
METHOD _ISMutableStoreIndex_availableSpace Q16@0:8
METHOD _ISMutableStoreIndex_makeBackedByFileAtURL: B24@0:8@16
METHOD _ISMutableStoreIndex_removeBlobForID: v24@0:8(?={?=II}Q)16
METHOD _ISStoreIndex_addNodeWithSize: (?={?=II}Q)24@0:8Q16
METHOD _ISStoreIndex_blobDataForID: @24@0:8(?={?=II}Q)16
METHOD _ISStoreIndex_blobForID: ^{?=(?={?=II}Q)B[3C][0C]}24@0:8(?={?=II}Q)16
METHOD _ISStoreIndex_blobTableHeader ^{?=IBI}16@0:8
METHOD _ISStoreIndex_checkNodeBounds: B24@0:8^{?=(?={?=II}Q)[16C](?={?=II}Q)B[3C][0C]}16
METHOD _ISStoreIndex_enumerateBlobsWithBock: v24@0:8@?16
METHOD _ISStoreIndex_enumerateValuesForUUID:bock: B32@0:8[16C]16@?24
METHOD _ISStoreIndex_enumerateValuesWithBock: v24@0:8@?16
METHOD _ISStoreIndex_hashTable ^(?={?=II}Q)16@0:8
METHOD _ISStoreIndex_hashTableHeader ^{?=IBIII}16@0:8
METHOD _ISStoreIndex_isValid B16@0:8
METHOD _ISStoreIndex_isValid B16@0:8
METHOD _ISStoreIndex_nodeForRef: ^{?=(?={?=II}Q)[16C](?={?=II}Q)B[3C][0C]}24@0:8(?={?=II}Q)16
METHOD _ISStoreIndex_nodeRefForKey: (?={?=II}Q)24@0:8Q16
METHOD _ISStoreIndex_nodesOffset Q16@0:8
METHOD _ISStoreIndex_setNodeRef:forKey: B32@0:8(?={?=II}Q)16Q24
METHOD __is__bookmarkResourcePropertyForKey: @24@0:8@16
METHOD _is_SequenceNumber Q16@0:8
METHOD _is_databaseUUID @16@0:8
METHOD _is_getSequenceNumber:andUUID: v32@0:8^Q16^@24
METHOD _is_persistentIdentifierDigest @16@0:8
METHOD si_asNSUUID @16@0:8
METHOD _pas_dataWithNonnullBytes @16@0:8
METHOD _pas_revivedString @16@0:8
METHOD encodedBytesAndReturnLength:error: r*32@0:8^Q16^@24
METHOD encodedDataAndReturnError: @24@0:8^@16
METHOD databaseValue_blobRepresentationWithLength: r^v24@0:8^Q16
METHOD databaseValue_toData @16@0:8
METHOD databaseValue_toNumber @16@0:8
METHOD databaseValue_toString @16@0:8
METHOD databaseValue_type q16@0:8
METHOD _CUTCopyGzippedData @16@0:8
METHOD _CUTDecompressData @16@0:8
METHOD _CUTOptionallyDecompressData @16@0:8
METHOD _CUTStringFromBaseData @16@0:8
METHOD SHA1Data @16@0:8
METHOD SHA256Data @16@0:8
METHOD SHA1HexString @16@0:8
METHOD _FTDecompressData @16@0:8
METHOD _FTOptionallyDecompressData @16@0:8
METHOD __imHexString @16@0:8
METHOD __imHexStringOfBytes:withLength: @32@0:8*16Q24
METHOD subdataWithRangeNoCopy: @32@0:8{_NSRange=QQ}16
METHOD truncatedDescription @16@0:8
METHOD _geo_SHA256Hash @16@0:8
METHOD _geo_SHA512Hash @16@0:8
METHOD _geo_newXPCData @16@0:8
METHOD _GEOCreateDispatchData @16@0:8
METHOD _geo_MD5Hash @16@0:8
METHOD _geo_SHA1Hash @16@0:8
METHOD _geo_compressedDataViaAlgo: @20@0:8i16
METHOD _geo_decompressedDataViaAlgo: @20@0:8i16
METHOD _geo_hexString @16@0:8
METHOD triHexlify @16@0:8
METHOD triSha256 @16@0:8
METHOD triSha256Base64String @16@0:8
METHOD VNPersonsModelSubdataWithRange:rangeDescription:error: @48@0:8{_NSRange=QQ}16@32^@40
METHOD VNPersonsModelSubdataWithRange:rangeDescriptionProvidingBlock:error: @48@0:8{_NSRange=QQ}16@?32^@40
METHOD CKUppercaseHexStringWithoutSpaces @16@0:8
METHOD CKHexString @16@0:8
METHOD CKLowercaseHexStringWithoutSpaces @16@0:8
METHOD CKBase64URLSafeString @16@0:8
METHOD CKCompare: q24@0:8@16
METHOD CKDescribePropertiesUsing: v24@0:8@16
METHOD CKDescriptionPropertiesWithPublic:private:shouldExpand: @28@0:8B16B20B24
METHOD CKSHA256 @16@0:8
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD ck_dataByAppendingData: @24@0:8@16
METHOD cksqlcs_blobBindingValue:destructor:error: r^v40@0:8^Q16^^?24^@32
METHOD _in_writeDataToPathForImage:storeType:error: @40@0:8@16Q24^@32
METHOD _intents_encodeWithJSONEncoder:codableDescription: @32@0:8@16@24
METHOD _intents_readableTitleWithLocalizer:metadata: @32@0:8@16@24
METHOD decodeSequenceData:data:error: B40@0:8^@16^@24^@32
METHOD decodeSequenceString:data:error: B40@0:8^@16^@24^@32
METHOD if_auditToken {?=[8I]}16@0:8
METHOD if_valueOfType: @24@0:8r*16
METHOD br_md5 @16@0:8
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD hexString @16@0:8
METHOD fm_MACAddressString @16@0:8
METHOD fm_hexString @16@0:8
METHOD fm_hmac_md5WithKey: @24@0:8@16
METHOD fm_hmac_sha1WithKey: @24@0:8@16
METHOD fm_hmac_sha256WithKey: @24@0:8@16
METHOD fm_hmac_sha512WithKey: @24@0:8@16
METHOD fm_sha1Hash @16@0:8
METHOD fm_sha256Hash @16@0:8
METHOD fm_sha512Hash @16@0:8
METHOD _operateOnDataUsingCompressionAlgorithm:operation: @24@0:8i16i20
METHOD scn_compressedDataUsingCompressionAlgorithm: @20@0:8i16
METHOD scn_indexedDataDecodingDeltaWithBytesPerIndex: @24@0:8Q16
METHOD scn_indexedDataDecodingHighWatermarkWithBytesPerIndex: @24@0:8Q16
METHOD scn_indexedDataDecodingTrianglePairsWithBytesPerIndex: @24@0:8Q16
METHOD scn_indexedDataEncodingDeltaWithBytesPerIndex: @24@0:8Q16
METHOD scn_indexedDataEncodingHighWatermarkWithBytesPerIndex: @24@0:8Q16
METHOD scn_indexedDataEncodingTrianglePairsWithBytesPerIndex: @24@0:8Q16
METHOD scn_uncompressedDataUsingCompressionAlgorithm: @20@0:8i16
METHOD _operateOnDataUsingCompressionAlgorithm:operation: @24@0:8i16i20
METHOD vfx_compressedDataUsingCompressionAlgorithm: @20@0:8i16
METHOD vfx_uncompressedDataUsingCompressionAlgorithm: @20@0:8i16
METHOD vfx_indexedDataDecodingDeltaWithBytesPerIndex: @24@0:8Q16
METHOD vfx_indexedDataDecodingHighWatermarkWithBytesPerIndex: @24@0:8Q16
METHOD vfx_indexedDataDecodingTrianglePairsWithBytesPerIndex: @24@0:8Q16
METHOD vfx_indexedDataEncodingDeltaWithBytesPerIndex: @24@0:8Q16
METHOD vfx_indexedDataEncodingHighWatermarkWithBytesPerIndex: @24@0:8Q16
METHOD vfx_indexedDataEncodingTrianglePairsWithBytesPerIndex: @24@0:8Q16
METHOD _uiSaveContentsToTemporaryFile @16@0:8
METHOD _web_isCaseInsensitiveEqualToCString: B24@0:8r*16
METHOD _webkit_guessedMIMEType @16@0:8
METHOD _webkit_guessedMIMETypeForXML @16@0:8
METHOD _axRecursivelyPropertyListCoercedRepresentationWithError: @24@0:8^@16
METHOD _axRecursivelyReconstitutedRepresentationFromPropertyListWithError: @24@0:8^@16
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD debugDescription @16@0:8
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD isEqual: B24@0:8@16
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD initWithBytes:length: @32@0:8r^v16Q24
METHOD length Q16@0:8
METHOD _isCompact B16@0:8
METHOD bytes r^v16@0:8
METHOD initWithBytes:length:copy:freeWhenDone:bytesAreVM: @44@0:8^v16Q24B32B36B40
METHOD _copyWillRetain B16@0:8
METHOD getBytes:range: v40@0:8^v16{_NSRange=QQ}24
METHOD _cfTypeID Q16@0:8
METHOD _createDispatchData @16@0:8
METHOD _getBPlistMarker:offset:trailer: B40@0:8*16^Q24^{?=[5C]CCCQQQ}32
METHOD _providesConcreteBacking B16@0:8
METHOD classForCoder #16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD getBytes:length: v32@0:8^v16Q24
METHOD initWithBytes:length:copy:deallocator: @44@0:8^v16Q24B32@?36
METHOD initWithBytesNoCopy:length: @32@0:8^v16Q24
METHOD initWithBytesNoCopy:length:freeWhenDone: @36@0:8^v16Q24B32
METHOD initWithCoder: @24@0:8@16
METHOD initWithContentsOfFile: @24@0:8@16
METHOD initWithContentsOfURL: @24@0:8@16
METHOD initWithData: @24@0:8@16
METHOD isNSData__ B16@0:8
METHOD base64EncodedStringWithOptions: @24@0:8Q16
METHOD _isDispatchData B16@0:8
METHOD _allowsDirectEncoding B16@0:8
METHOD _asciiDescription @16@0:8
METHOD _base64EncodingAsString:withOptions: @28@0:8B16Q20
METHOD _canReplaceWithDispatchDataForXPCCoder B16@0:8
METHOD _compressedDataUsingCompressionAlgorithm:error: @28@0:8i16^@20
METHOD _decodeBase64EncodedCharacterBuffer:length:options:buffer:bufferLength:state: B64@0:8r*16Q24Q32*40Q48^{?=BBQQQI}56
METHOD _decompressedDataUsingCompressionAlgorithm:error: @28@0:8i16^@20
METHOD _initWithBase64EncodedObject:options: @32@0:8@16Q24
METHOD _produceDataWithCompressionOperation:algorithm:handler: v32@0:8i16i20@?24
METHOD _replaceCString:withCString: @32@0:8r*16r*24
METHOD _web_guessedMIMEType @16@0:8
METHOD _web_guessedMIMETypeForExtension: @24@0:8@16
METHOD _web_guessedMIMETypeForXML @16@0:8
METHOD _web_parseRFC822HeaderFields @16@0:8
METHOD base64EncodedDataWithOptions: @24@0:8Q16
METHOD base64Encoding @16@0:8
METHOD compressedDataUsingAlgorithm:error: @32@0:8q16^@24
METHOD decompressedDataUsingAlgorithm:error: @32@0:8q16^@24
METHOD enumerateByteRangesUsingBlock: v24@0:8@?16
METHOD getBytes: v24@0:8^v16
METHOD initWithBase64EncodedData:options: @32@0:8@16Q24
METHOD initWithBase64EncodedString:options: @32@0:8@16Q24
METHOD initWithBase64Encoding: @24@0:8@16
METHOD initWithBytesNoCopy:length:deallocator: @40@0:8^v16Q24@?32
METHOD initWithContentsOfFile:error: @32@0:8@16^@24
METHOD initWithContentsOfFile:options:error: @40@0:8@16Q24^@32
METHOD initWithContentsOfFile:options:maxLength:error: @48@0:8@16Q24Q32^@40
METHOD initWithContentsOfMappedFile: @24@0:8@16
METHOD initWithContentsOfMappedFile:error: @32@0:8@16^@24
METHOD initWithContentsOfURL:options:error: @40@0:8@16Q24^@32
METHOD initWithContentsOfURL:options:maxLength:error: @48@0:8@16Q24Q32^@40
METHOD isEqualToData: B24@0:8@16
METHOD rangeOfData:options:range: {_NSRange=QQ}48@0:8@16Q24{_NSRange=QQ}32
METHOD replacementObjectForCoder: @24@0:8@16
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD subdataWithRange: @32@0:8{_NSRange=QQ}16
METHOD writeToFile:atomically: B28@0:8@16B24
METHOD writeToFile:atomically:error: B36@0:8@16B24^@28
METHOD writeToFile:options:error: B40@0:8@16Q24^@32
METHOD writeToURL:atomically: B28@0:8@16B24
METHOD writeToURL:options:error: B40@0:8@16Q24^@32
METHOD CKUppercaseHexStringWithoutSpaces @16@0:8
METHOD CKHexString @16@0:8
METHOD CKLowercaseHexStringWithoutSpaces @16@0:8
METHOD asMessageSecurityHexString @16@0:8
METHOD MI_writeAtomicallyToURL:withMode:owner:group:error: B44@0:8@16S24I28I32^@36
METHOD MI_writeAtomicallyToURL:withMode:owner:group:protectionClass:withBarrier:error: B52@0:8@16S24I28I32i36B40^@44
METHOD MI_writeAtomicallyToURL:withMode:owner:group:protectionClass:error: B48@0:8@16S24I28I32i36^@40
METHOD MI_writeAtomicallyToURLMatchingCurrentFileMetadata:error: B32@0:8@16^@24

=== CLASS NSDecimalNumber ===
SUPER: NSNumber
SIZE: 16
PROTOCOLS: INJSONSerializable
IVAR +8 0 _exponent b8
IVAR +9 0 _length b4
IVAR +9 0 _isNegative b1
IVAR +9 0 _isCompact b1
IVAR +9 0 _reserved b1
IVAR +9 0 _hasExternalRefCount b1
IVAR +10 0 _refs b16
IVAR +12 0 _mantissa ^S
CMETHOD _intents_decodeWithJSONDecoder:codableDescription:from: @40@0:8@16@24@32
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD initialize v16@0:8
CMETHOD numberWithBool: @20@0:8B16
CMETHOD numberWithDouble: @24@0:8d16
CMETHOD numberWithLongLong: @24@0:8q16
CMETHOD numberWithUnsignedChar: @20@0:8C16
CMETHOD supportsSecureCoding B16@0:8
CMETHOD decimalNumberWithString:locale: @32@0:8@16@24
CMETHOD numberWithChar: @20@0:8c16
CMETHOD one @16@0:8
CMETHOD defaultBehavior @16@0:8
CMETHOD numberWithLong: @24@0:8q16
CMETHOD decimalNumberWithDecimal: @36@0:8{?=b8b4b1b1b18[8S]}16
CMETHOD decimalNumberWithMantissa:exponent:isNegative: @32@0:8Q16s24B28
CMETHOD decimalNumberWithString: @24@0:8@16
CMETHOD maximumDecimalNumber @16@0:8
CMETHOD minimumDecimalNumber @16@0:8
CMETHOD notANumber @16@0:8
CMETHOD numberWithFloat: @20@0:8f16
CMETHOD numberWithInt: @20@0:8i16
CMETHOD numberWithInteger: @24@0:8q16
CMETHOD numberWithShort: @20@0:8s16
CMETHOD numberWithUnsignedInt: @20@0:8I16
CMETHOD numberWithUnsignedInteger: @24@0:8Q16
CMETHOD numberWithUnsignedLong: @24@0:8Q16
CMETHOD numberWithUnsignedLongLong: @24@0:8Q16
CMETHOD numberWithUnsignedShort: @20@0:8S16
CMETHOD setDefaultBehavior: v24@0:8@16
CMETHOD zero @16@0:8
METHOD _intents_encodeWithJSONEncoder:codableDescription: @32@0:8@16@24
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD isEqual: B24@0:8@16
METHOD charValue c16@0:8
METHOD doubleValue d16@0:8
METHOD floatValue f16@0:8
METHOD intValue i16@0:8
METHOD longLongValue q16@0:8
METHOD longValue q16@0:8
METHOD objCType r*16@0:8
METHOD shortValue s16@0:8
METHOD unsignedCharValue C16@0:8
METHOD unsignedIntValue I16@0:8
METHOD unsignedLongLongValue Q16@0:8
METHOD unsignedLongValue Q16@0:8
METHOD unsignedShortValue S16@0:8
METHOD initWithString: @24@0:8@16
METHOD _getCString:length:multiplier: B36@0:8*16i24d28
METHOD boolValue B16@0:8
METHOD classForCoder #16@0:8
METHOD compare: q24@0:8@16
METHOD descriptionWithLocale: @24@0:8@16
METHOD encodeWithCoder: v24@0:8@16
METHOD getValue: v24@0:8^v16
METHOD initWithCoder: @24@0:8@16
METHOD _allowsDirectEncoding B16@0:8
METHOD decimalNumberByAdding: @24@0:8@16
METHOD decimalNumberByAdding:withBehavior: @32@0:8@16@24
METHOD decimalNumberByDividingBy: @24@0:8@16
METHOD decimalNumberByDividingBy:withBehavior: @32@0:8@16@24
METHOD decimalNumberByMultiplyingBy: @24@0:8@16
METHOD decimalNumberByMultiplyingBy:withBehavior: @32@0:8@16@24
METHOD decimalNumberByMultiplyingByPowerOf10: @20@0:8s16
METHOD decimalNumberByMultiplyingByPowerOf10:withBehavior: @28@0:8s16@20
METHOD decimalNumberByRaisingToPower: @24@0:8Q16
METHOD decimalNumberByRaisingToPower:withBehavior: @32@0:8Q16@24
METHOD decimalNumberByRoundingAccordingToBehavior: @24@0:8@16
METHOD decimalNumberBySubstracting: @24@0:8@16
METHOD decimalNumberBySubstracting:withBehavior: @32@0:8@16@24
METHOD decimalNumberBySubtracting: @24@0:8@16
METHOD decimalNumberBySubtracting:withBehavior: @32@0:8@16@24
METHOD decimalValue {?=b8b4b1b1b18[8S]}16@0:8
METHOD initWithDecimal: @36@0:8{?=b8b4b1b1b18[8S]}16
METHOD initWithMantissa:exponent:isNegative: @32@0:8Q16s24B28
METHOD initWithString:locale: @32@0:8@16@24

=== CLASS NSDecimalNumberHandler ===
SUPER: NSObject
SIZE: 32
PROTOCOLS: NSDecimalNumberBehaviors NSCoding
IVAR +8 0 _scale b16
IVAR +10 0 _roundingMode b3
IVAR +10 0 _raiseOnExactness b1
IVAR +10 0 _raiseOnOverflow b1
IVAR +10 0 _raiseOnUnderflow b1
IVAR +10 0 _raiseOnDivideByZero b1
IVAR +10 0 _unused b9
IVAR +16 0 _reserved2 ^v
IVAR +24 0 _reserved ^v
CMETHOD decimalNumberHandlerWithRoundingMode:scale:raiseOnExactness:raiseOnOverflow:raiseOnUnderflow:raiseOnDivideByZero: @44@0:8Q16s24B28B32B36B40
CMETHOD defaultDecimalNumberHandler @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD exceptionDuringOperation:error:leftOperand:rightOperand: @48@0:8:16Q24@32@40
METHOD initWithRoundingMode:scale:raiseOnExactness:raiseOnOverflow:raiseOnUnderflow:raiseOnDivideByZero: @44@0:8Q16s24B28B32B36B40
METHOD roundingMode Q16@0:8
METHOD scale s16@0:8

=== CLASS NSDictionary ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: NSFetchRequestResult CKDeepCopying CUByteCodable INJSONSerializable CSCoderEncoder PQLBindable _OSXPCObjectRepresentable NSCopying NSMutableCopying NSSecureCoding NSFastEnumeration
CMETHOD _subclassesMustBeExplicitlyMentionedWhenDecoded B16@0:8
CMETHOD newWithContentsOf:immutable: @28@0:8@16B24
CMETHOD supportsSecureCoding B16@0:8
CMETHOD dictionaryWithContentsOfFile: @24@0:8@16
CMETHOD dictionaryWithContentsOfURL: @24@0:8@16
CMETHOD dictionaryWithContentsOfURL:error: @32@0:8@16^@24
CMETHOD newWithContentsOf:immutable:error: @36@0:8@16B24^@28
CMETHOD MCDictionaryFromFile: @24@0:8@16
CMETHOD MCShortenedData: @24@0:8@16
CMETHOD MCShortenedObject: @24@0:8@16
CMETHOD MCShortenedArray: @24@0:8@16
CMETHOD MCShortenedDictionary: @24@0:8@16
CMETHOD bsobjc_attributesForProperty: @24@0:8^{objc_property=}16
CMETHOD _geo_dictionaryFromXPCObject: @24@0:8@16
CMETHOD _geo_replyDictionaryForError:key: @32@0:8@16@24
CMETHOD dictionaryWithKeyArray:defaultValue: @32@0:8@16@24
CMETHOD dictionaryWithPlistData: @24@0:8@16
CMETHOD createWithBytesNoCopy:length:error: @40@0:8^v16Q24^@32
CMETHOD _intents_decodeWithJSONDecoder:codableDescription:from: @40@0:8@16@24@32
CMETHOD _pas_dictionaryNoCopyLeavesWithPropertyListData:error: @32@0:8@16^@24
CMETHOD dictionaryWithContentsOfURL:error: @32@0:8@16^@24
CMETHOD dictionaryWithContentsOfData: @24@0:8@16
CMETHOD fm_dictionaryWithContentsOfData: @24@0:8@16
CMETHOD fm_dictionaryWithContentsOfURL:error: @32@0:8@16^@24
CMETHOD dm_migrationRebootCountPrefWithRebootCount:buildVersion: @32@0:8Q16@24
CMETHOD dm_migrationRebootCountPref_buildVersionKey @16@0:8
CMETHOD dm_migrationRebootCountPref_rebootCountKey @16@0:8
CMETHOD dmlmr_buildVersionKey @16@0:8
CMETHOD dmlmr_lastMigrationResultsWithSuccess:buildVersion: @28@0:8B16@20
CMETHOD dmlmr_successKey @16@0:8
CMETHOD if_dictionaryWithObjects:forKeys:count:uniquingKeysWith: @48@0:8r^@16r^@24Q32@?40
CMETHOD if_dictionaryWithObjects:forKeys:uniquingKeysWith: @40@0:8@16@24@?32
CMETHOD _EX_dictionaryWithSignedURL:error: @32@0:8@16^@24
CMETHOD aaf_empty @16@0:8
CMETHOD DMCDictionaryFromFile: @24@0:8@16
CMETHOD DMCShortenedData: @24@0:8@16
CMETHOD DMCShortenedObject: @24@0:8@16
CMETHOD DMCShortenedArray: @24@0:8@16
CMETHOD DMCShortenedDictionary: @24@0:8@16
CMETHOD dmc_jsonDictionaryFromData: @24@0:8@16
CMETHOD MI_dictionaryWithContentsOfURL:options:error: @40@0:8@16Q24^@32
CMETHOD MI_dictionaryByMergingDictionaries: @24@0:8@16
CMETHOD safeSummaryForDictionary: @24@0:8@16
CMETHOD _safeKeyName:paddedToLength: @32@0:8@16Q24
CMETHOD _safeValueName:ofMaxFieldLength:providingSubstitutionMap: @40@0:8@16Q24@32
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD dictionary @16@0:8
CMETHOD dictionaryWithDictionary: @24@0:8@16
CMETHOD dictionaryWithDictionary:copyItems: @28@0:8@16B24
CMETHOD dictionaryWithObject:forKey: @32@0:8@16@24
CMETHOD dictionaryWithObjects:forKeys: @32@0:8@16@24
CMETHOD dictionaryWithObjects:forKeys:count: @40@0:8r^@16r^@24Q32
CMETHOD dictionaryWithObjectsAndKeys: @24@0:8@16
CMETHOD newDictionaryWithObjects:forKeys:count: @40@0:8r^@16r^@24Q32
CMETHOD sharedKeySetForKeys: @24@0:8@16
CMETHOD supportsSecureCoding B16@0:8
METHOD fp_copyItemKeysAndValuesUnwrappedAndKeyMap: @24@0:8@16
METHOD fp_copyItemKeysUnwrappedAndKeyMap: @24@0:8@16
METHOD fp_filter: @24@0:8@?16
METHOD fp_removingObjectsNotKindOfClasses: @24@0:8@16
METHOD fp_valueForKeyPath: @24@0:8@16
METHOD bs_boolForKey: B24@0:8@16
METHOD bs_dictionaryByAddingEntriesFromDictionary: @24@0:8@16
METHOD bs_each: v24@0:8@?16
METHOD bs_filter: @24@0:8@?16
METHOD bs_safeArrayForKey: @24@0:8@16
METHOD bs_safeDictionaryForKey: @24@0:8@16
METHOD bs_safeNumberForKey: @24@0:8@16
METHOD bs_safeObjectForKey:ofType: @32@0:8@16#24
METHOD bs_safeStringForKey: @24@0:8@16
METHOD bs_safeURLForKey: @24@0:8@16
METHOD MCDeepCopy @16@0:8
METHOD MCDictionaryWithLeafValuesSetToValue: @24@0:8@16
METHOD MCMutableDeepCopy @16@0:8
METHOD MCRemovedKeysFromDictionary: @24@0:8@16
METHOD MCRetainOptionalObjectKey:type:errorDomain:invalidDataCode:invalidDataErrorString:outError: @64@0:8@16#24@32q40@48^@56
METHOD MCRetainRequiredObjectKey:type:errorDomain:missingDataCode:missingDataErrorString:invalidDataCode:invalidDataErrorString:outError: @80@0:8@16#24@32q40@48q56@64^@72
METHOD MCValidateBoolRestriction:inRestrictions:defaultRestrictions: B40@0:8@16@24@32
METHOD MCValidateRestrictions B16@0:8
METHOD MCValidateValueRestriction:inRestrictions:defaultRestrictions: B40@0:8@16@24@32
METHOD MCWriteToBinaryFile: B24@0:8@16
METHOD MCWriteToBinaryFile:atomically: B28@0:8@16B24
METHOD MCDeepCopyWithZone: @24@0:8^{_NSZone=}16
METHOD MCDictionaryAdditiveDeltaToCreateDictionary: @24@0:8@16
METHOD MCDictionarySubtractiveDeltaToCreateDictionary: @24@0:8@16
METHOD MCInsertedKeysFromDictionary:withNewLeafValue: @32@0:8@16@24
METHOD MCMutableDeepCopyWithZone: @24@0:8^{_NSZone=}16
METHOD MCRetainOptionalNonZeroLengthStringKey:errorDomain:invalidDataCode:invalidDataErrorString:outError: @56@0:8@16@24q32@40^@48
METHOD MCRetainRequiredNonZeroLengthStringKey:errorDomain:missingDataCode:missingDataErrorString:invalidDataCode:invalidDataErrorString:outError: @72@0:8@16@24q32@40q48@56^@64
METHOD MCShortenedPlistDescription @16@0:8
METHOD MCValidateIntersectionRestriction:inRestrictions:defaultRestrictions: B40@0:8@16@24@32
METHOD MCValidateUnionRestriction:inRestrictions:defaultRestrictions: B40@0:8@16@24@32
METHOD entriesToStringWithIndent:debug: @24@0:8i16B20
METHOD dm_migrationRebootCountPref_buildVersion @16@0:8
METHOD dm_migrationRebootCountPref_rebootCount Q16@0:8
METHOD dmlmr_buildVersion @16@0:8
METHOD dmlmr_success @16@0:8
METHOD _IF_boolForKey: B24@0:8@16
METHOD _IF_arrayForKey: @24@0:8@16
METHOD _IF_boolForKeys:defaultValue: B28@0:8@16B24
METHOD _IF_dictionaryAddingEntriesFromDictionary: @24@0:8@16
METHOD _IF_dictionaryForKey: @24@0:8@16
METHOD _IF_objectOfClass:forKey: @32@0:8#16@24
METHOD _IF_stringForKey: @24@0:8@16
METHOD _IF_stringForKeys: @24@0:8@16
METHOD _IF_dataForKey: @24@0:8@16
METHOD _IF_arrayForKeys: @24@0:8@16
METHOD _IF_boolForKey:defaultValue: B28@0:8@16B24
METHOD _IF_boolForKeys: B24@0:8@16
METHOD _IF_dictionaryForKeys: @24@0:8@16
METHOD _IF_dictionarySubsetForKeys: @24@0:8@16
METHOD _IF_numberForKey: @24@0:8@16
METHOD _IF_numberForKeys: @24@0:8@16
METHOD _IF_objectOfClass:forKeys: @32@0:8#16@24
METHOD CA_copyRenderKeyPathValueArray ^v16@0:8
METHOD CAMLType @16@0:8
METHOD CA_copyRenderKeyValueArray ^v16@0:8
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD ac_mapValues: @24@0:8@?16
METHOD ac_mapValuesNullable: @24@0:8@?16
METHOD _FTFilteredDictionaryForAPS @16@0:8
METHOD aa_dictionaryByAddingEntriesFromDictionary: @24@0:8@16
METHOD aaf_dictionaryByAddingEntriesFromDictionary: @24@0:8@16
METHOD aaf_filter: @24@0:8@?16
METHOD aaf_map: @24@0:8@?16
METHOD aaf_hasObjects B16@0:8
METHOD aaf_toUrlQueryString @16@0:8
METHOD aaf_dictionaryByAddingValue:forKey: @32@0:8@16@24
METHOD aaf_mapStoppable: @24@0:8@?16
METHOD aaf_toUrlQueryItems @16@0:8
METHOD ak_dictionaryWithKeysFromArray: @24@0:8@16
METHOD ak_redactedCopy @16@0:8
METHOD _ak_shortenServiceIdentifier: @24@0:8@16
METHOD _ak_truncateTokenDict: @24@0:8@16
METHOD _ak_truncateTokenString: @24@0:8@16
METHOD hasValueAtKey:ofType: B32@0:8@16@24
METHOD DMCWriteToBinaryFile: B24@0:8@16
METHOD DMCShortenedPlistDescription @16@0:8
METHOD DMCWriteToBinaryFile:protectionType: B32@0:8@16@24
METHOD _writingOptionsFromProtectionType: Q24@0:8@16
METHOD dmc_valueOfClass:forKey: @32@0:8#16@24
METHOD _EX_boolForKey: B24@0:8@16
METHOD _EX_arrayForKey: @24@0:8@16
METHOD _EX_arrayForKeys: @24@0:8@16
METHOD _EX_boolForKey:defaultValue: B28@0:8@16B24
METHOD _EX_dictionaryByRemovingObjectForKey: @24@0:8@16
METHOD _EX_dictionaryBySettingObject:forKey: @32@0:8@16@24
METHOD _EX_dictionaryBySettingValuesForKeysWithDictionary: @24@0:8@16
METHOD _EX_dictionaryForKey: @24@0:8@16
METHOD _EX_dictionaryForKeys: @24@0:8@16
METHOD _EX_integerForKey: q24@0:8@16
METHOD _EX_objectForKey:ofClass: @32@0:8@16#24
METHOD _EX_objectForKeys:ofClass: @32@0:8@16#24
METHOD _EX_stringForKey: @24@0:8@16
METHOD _EX_stringForKeys: @24@0:8@16
METHOD _OS_xpcObjectRepresentation @16@0:8
METHOD _IS_layerObjectForKey: @24@0:8q16
METHOD _IS_resourceNamed: @24@0:8@16
METHOD dictionaryChanging:to: @32@0:8@16@24
METHOD safeDictionaryForKey: @24@0:8@16
METHOD safeIntegerForKey: q24@0:8@16
METHOD safeStringForKey: @24@0:8@16
METHOD safeObjectForKey:ofClass: @32@0:8@16#24
METHOD safeSummary @16@0:8
METHOD safeDataForKey: @24@0:8@16
METHOD safeIntegerForKey:defaultValue: q32@0:8@16q24
METHOD safeBooleanForKey:defaultValue: B28@0:8@16B24
METHOD safeDateForKey: @24@0:8@16
METHOD _logReturningDefault:forKey:valueType:defaultValueName: v48@0:8@16@24@32@40
METHOD _logReturningNil:forKey:valueType: v40@0:8@16@24@32
METHOD _logReturningNil:forKey:valueType:fromBase:withKeyDescription: v56@0:8@16@24@32@40@48
METHOD _safeDescriptionWithName:atNestedLevel:maxNestedLevel:showingSubLevelName:withMaxValueLength:providingSubstitutionMap: @60@0:8@16Q24Q32B40Q44@52
METHOD safeBooleanForKey: B24@0:8@16
METHOD safeDescriptionWithName: @24@0:8@16
METHOD safeDescriptionWithName:maxNestedLevel:withMaxValueLength:providingSubstitutionMap: @48@0:8@16Q24Q32@40
METHOD safeDictionaryForKey:fromBase:withKeyDescription: @40@0:8@16@24@32
METHOD safeIntForKey:defaultValue: i28@0:8@16i24
METHOD safeLLForKey: q24@0:8@16
METHOD safeLLForKey:defaultValue: q32@0:8@16q24
METHOD safeSubDescriptionAtNestedLevel:instanceAtLevel:withMaxValueLength:providingSubstitutionMap: @48@0:8Q16Q24Q32@40
METHOD safeTriStateForKey: q24@0:8@16
METHOD safeTriStateForKey:defaultValue: q32@0:8@16q24
METHOD safeULForKey: Q24@0:8@16
METHOD safeULForKey:defaultValue: Q32@0:8@16Q24
METHOD safeULLForKey: Q24@0:8@16
METHOD safeULLForKey:defaultValue: Q32@0:8@16Q24
METHOD un_nonEmptyCopy @16@0:8
METHOD un_safeCastObjectForKey:class: @32@0:8@16#24
METHOD _pas_unlazyDictionary @16@0:8
METHOD matchesUID: B24@0:8@16
METHOD encodedBytesAndReturnLength:error: r*32@0:8^Q16^@24
METHOD encodedDataAndReturnError: @24@0:8^@16
METHOD reduceWithNext: @24@0:8@16
METHOD ax_deepMutableCopy @16@0:8
METHOD keysOfChangedEntriesComparedTo: @24@0:8@16
METHOD __imDeepCopy @16@0:8
METHOD __imDictionaryByFilteringWithBlock: @24@0:8@?16
METHOD __imIsMutable B16@0:8
METHOD _arrayForKey: @24@0:8@16
METHOD _dataForKey: @24@0:8@16
METHOD _dictionaryForKey: @24@0:8@16
METHOD _numberForKey: @24@0:8@16
METHOD _stringForKey: @24@0:8@16
METHOD dictionaryFromChanges: @24@0:8@16
METHOD fileHFSFlags S16@0:8
METHOD fileHFSResourceForkSize Q16@0:8
METHOD plistData @16@0:8
METHOD _geo_errorForKey: @24@0:8@16
METHOD _geo_newXPCObject @16@0:8
METHOD _placeOrCurrentLocation: @24@0:8^B16
METHOD exMRL_arrayForKey: @24@0:8@16
METHOD exMRL_boolForKey: B24@0:8@16
METHOD exMRL_boolForKey:keyPresent: B32@0:8@16^B24
METHOD exMRL_dataForKey: @24@0:8@16
METHOD exMRL_dictionaryForKey: @24@0:8@16
METHOD exMRL_numberForKey: @24@0:8@16
METHOD exMRL_setForKey: @24@0:8@16
METHOD exMRL_stringForKey: @24@0:8@16
METHOD CKAssignToContainerWithID: v24@0:8@16
METHOD CKCompactMap: @24@0:8@?16
METHOD CKCompactMapValues: @24@0:8@?16
METHOD CKDeepCopy @16@0:8
METHOD CKDescriptionPropertiesWithPublic:private:shouldExpand: @28@0:8B16B20B24
METHOD CKFirstUrlForKeys: @24@0:8@16
METHOD CKMapKeysAndValues: @24@0:8@?16
METHOD CKMapValues: @24@0:8@?16
METHOD CKPropertiesStyleString @16@0:8
METHOD CKDeepCopyWithLeafNodeCopyBlock: @24@0:8@?16
METHOD CKFilter: @24@0:8@?16
METHOD CKFlatMap: @24@0:8@?16
METHOD CKMap: @24@0:8@?16
METHOD CKObjectForKeyCaseInsensitive: @24@0:8@16
METHOD _intents_indexingRepresentation @16@0:8
METHOD _intents_encodeWithJSONEncoder:codableDescription: @32@0:8@16@24
METHOD _intents_widgetPlistRepresentableForKey:ofClass:error: @40@0:8@16#24^@32
METHOD descriptionAtIndent: @24@0:8Q16
METHOD intents_boolForKey: B24@0:8@16
METHOD intents_doubleForKey: d24@0:8@16
METHOD intents_int64ForKey: q24@0:8@16
METHOD intents_intForKey: q24@0:8@16
METHOD intents_numberForKey: @24@0:8@16
METHOD intents_safeObjectForKey:ofType: @32@0:8@16#24
METHOD intents_stringForKey: @24@0:8@16
METHOD intents_urlForKey: @24@0:8@16
METHOD if_dictionaryWithNonEmptyValues @16@0:8
METHOD if_JSONStringRepresentation @16@0:8
METHOD if_compactMap: @24@0:8@?16
METHOD if_dictionaryByAddingEntriesFromDictionary: @24@0:8@16
METHOD encodeKeysAndValuesWithCSCoder:filterBlock: v32@0:8@16@?24
METHOD encodeWithCSCoder: v24@0:8@16
METHOD pet_dictForKey: @24@0:8@16
METHOD pet_arrayForKey: @24@0:8@16
METHOD pet_numForKey: @24@0:8@16
METHOD pet_objectForKey:class: @32@0:8@16#24
METHOD pet_strForKey: @24@0:8@16
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD sh_removingUnsupportedTypes @16@0:8
METHOD fm_dictionaryByDeeplySettingValuesForKeysWithDictionary: @24@0:8@16
METHOD invertedDictionary @16@0:8
METHOD dictionaryWithLowercaseKeys @16@0:8
METHOD fm_dictionaryByMappingValues: @24@0:8@?16
METHOD fm_dictionaryWithLowercaseKeys @16@0:8
METHOD fm_filter: @24@0:8@?16
METHOD avt_mutableContainersCopy @16@0:8
METHOD avt_objectForKey:ofClass:didFail:error: @48@0:8@16#24^B32^@40
METHOD avt_objectForKey:ofClasses:didFail:error: @48@0:8@16@24^B32^@40
METHOD SCNMatrix4Value {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD SCNVector4Value {SCNVector4=ffff}16@0:8
METHOD SCNVector3Value {SCNVector3=fff}16@0:8
METHOD SCNMutableDeepCopy @16@0:8
METHOD SCN_safeHash Q16@0:8
METHOD VFXFloat4Value 16@0:8
METHOD VFXFloat3Value 16@0:8
METHOD VFXMatrix4Value {?=[4]}16@0:8
METHOD VFXMutableDeepCopy @16@0:8
METHOD VFX_safeHash Q16@0:8
METHOD _boolForKey: B24@0:8@16
METHOD _ui_attributesForDictionaryContainingUIStringDrawingKeys @16@0:8
METHOD _ui_dictionaryContainsUIStringDrawingKeys B16@0:8
METHOD _web_messageLineNumber i16@0:8
METHOD _web_messageSourceURL @16@0:8
METHOD _web_messageText @16@0:8
METHOD _web_messageType i16@0:8
METHOD _webkit_arrayForKey: @24@0:8@16
METHOD _webkit_boolForKey: B24@0:8@16
METHOD _webkit_numberForKey: @24@0:8@16
METHOD _webkit_objectForMIMEType: @24@0:8@16
METHOD _webkit_stringForKey: @24@0:8@16
METHOD _axRecursivelyPropertyListCoercedRepresentationWithError: @24@0:8^@16
METHOD _axRecursivelyReconstitutedRepresentationFromPropertyListWithError: @24@0:8^@16
METHOD classForCoder #16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithContentsOfFile: @24@0:8@16
METHOD initWithContentsOfURL: @24@0:8@16
METHOD _web_intForKey: i24@0:8@16
METHOD fileHFSTypeCode I16@0:8
METHOD fileIsImmutable B16@0:8
METHOD __swiftInitWithDictionary_NSDictionary: @24@0:8@16
METHOD __swift_objectForKeyedSubscript: @24@0:8@16
METHOD _stringToWrite @16@0:8
METHOD _web_numberForKey: @24@0:8@16
METHOD _web_objectForMIMEType: @24@0:8@16
METHOD _web_stringForKey: @24@0:8@16
METHOD descriptionInStringsFileFormat @16@0:8
METHOD fileCreationDate @16@0:8
METHOD fileExtensionHidden B16@0:8
METHOD fileGroupOwnerAccountID @16@0:8
METHOD fileGroupOwnerAccountName @16@0:8
METHOD fileGroupOwnerAccountNumber Q16@0:8
METHOD fileHFSCreatorCode I16@0:8
METHOD fileIsAppendOnly B16@0:8
METHOD fileModificationDate @16@0:8
METHOD fileOwnerAccountID @16@0:8
METHOD fileOwnerAccountName @16@0:8
METHOD fileOwnerAccountNumber Q16@0:8
METHOD filePosixPermissions Q16@0:8
METHOD fileSize Q16@0:8
METHOD fileSystemFileNumber Q16@0:8
METHOD fileSystemNumber q16@0:8
METHOD fileType @16@0:8
METHOD initWithContentsOfURL:error: @32@0:8@16^@24
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD valueForKey: @24@0:8@16
METHOD valueForKeyPath: @24@0:8@16
METHOD writeToFile:atomically: B28@0:8@16B24
METHOD writeToURL:atomically: B28@0:8@16B24
METHOD writeToURL:error: B32@0:8@16^@24
METHOD _LS_BoolForKey: B24@0:8@16
METHOD ls_insertExtensionPointVersion: @24@0:8@16
METHOD _LS_integerForKey: Q24@0:8@16
METHOD _ls_normalizedPluginPlist @16@0:8
METHOD ls_fixupExtensionPointIdentifierKey @16@0:8
METHOD ls_hashQuery Q16@0:8
METHOD ls_parseQueryForIdentifiers: @24@0:8@16
METHOD ls_resolvePlugInKitInfoPlistWithDictionary: @24@0:8@16
METHOD MI_writeAtomicallyToURLMatchingCurrentFileMetadata:format:error: B40@0:8@16Q24^@32
METHOD MI_writeToURL:format:options:error: B48@0:8@16Q24Q32^@40
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD isEqual: B24@0:8@16
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD __getValue:forKey: B32@0:8^@16@24
METHOD _cfTypeID Q16@0:8
METHOD allKeys @16@0:8
METHOD containsObject: B24@0:8@16
METHOD countForObject: Q24@0:8@16
METHOD __apply:context: v32@0:8^?16^v24
METHOD keysSortedByValueUsingSelector: @24@0:8:16
METHOD _cfMutableCopy @16@0:8
METHOD _getObjects:andKeys:count: v40@0:8^@16^@24Q32
METHOD allKeysForObject: @24@0:8@16
METHOD allObjects @16@0:8
METHOD allValues @16@0:8
METHOD containsKey: B24@0:8@16
METHOD count Q16@0:8
METHOD countByEnumeratingWithState:objects:count: Q40@0:8^{?=Q^@^Q[5Q]}16^@24Q32
METHOD countForKey: Q24@0:8@16
METHOD descriptionWithLocale: @24@0:8@16
METHOD descriptionWithLocale:indent: @32@0:8@16Q24
METHOD encodeWithCoder: v24@0:8@16
METHOD enumerateKeysAndObjectsUsingBlock: v24@0:8@?16
METHOD enumerateKeysAndObjectsWithOptions:usingBlock: v32@0:8Q16@?24
METHOD getKeys: v24@0:8^@16
METHOD getObjects: v24@0:8^@16
METHOD getObjects:andKeys: v32@0:8^@16^@24
METHOD getObjects:andKeys:count: v40@0:8^@16^@24Q32
METHOD initWithCoder: @24@0:8@16
METHOD initWithDictionary: @24@0:8@16
METHOD initWithDictionary:copyItems: @28@0:8@16B24
METHOD initWithObject:forKey: @32@0:8@16@24
METHOD initWithObjects:forKeys: @32@0:8@16@24
METHOD initWithObjects:forKeys:count: @40@0:8r^@16r^@24Q32
METHOD initWithObjectsAndKeys: @24@0:8@16
METHOD invertedDictionary @16@0:8
METHOD isEqualToDictionary: B24@0:8@16
METHOD isNSDictionary__ B16@0:8
METHOD keyEnumerator @16@0:8
METHOD keyOfEntryPassingTest: @24@0:8@?16
METHOD keyOfEntryWithOptions:passingTest: @32@0:8Q16@?24
METHOD keysOfEntriesPassingTest: @24@0:8@?16
METHOD keysOfEntriesWithOptions:passingTest: @32@0:8Q16@?24
METHOD keysSortedByValueUsingComparator: @24@0:8@?16
METHOD keysSortedByValueWithOptions:usingComparator: @32@0:8Q16@?24
METHOD objectEnumerator @16@0:8
METHOD objectForKey: @24@0:8@16
METHOD objectForKeyedSubscript: @24@0:8@16
METHOD objectsForKeys:notFoundMarker: @32@0:8@16@24

=== CLASS NSError ===
SUPER: NSObject
SIZE: 40
PROTOCOLS: BSDescriptionProviding PQLValuable NSCopying NSSecureCoding
IVAR +8 0 _reserved ^v
IVAR +16 0 _code q
IVAR +24 0 _domain @"NSString"
IVAR +32 0 _userInfo @"NSDictionary"
CMETHOD _fp_errorWithPOSIXCode:itemURL:debugDescription:message: @44@0:8i16@20@28@36
CMETHOD fileProviderErrorForCollisionWithItem: @24@0:8@16
CMETHOD fileProviderErrorForNonExistentItemWithIdentifier: @24@0:8@16
CMETHOD fileProviderErrorForRejectedDeletionOfItem: @24@0:8@16
CMETHOD fp_disallowedByManagement: @24@0:8@16
CMETHOD fp_errorForCollisionWithURL: @24@0:8@16
CMETHOD fp_errorWithPOSIXCode: @20@0:8i16
CMETHOD fp_errorWithPOSIXCode:description: @28@0:8i16@20
CMETHOD fp_errorWithPOSIXCode:itemURL:debugDescription: @36@0:8i16@20@28
CMETHOD fp_externalDomainRejectedErrorWithUnderlyingError: @24@0:8@16
CMETHOD fp_initLocalizationStrings v16@0:8
CMETHOD fp_invalidArgumentError: @24@0:8@16
CMETHOD fp_translocatedError: @24@0:8@16
CMETHOD bs_errorWithDomain:code:configuration: @40@0:8@16q24@?32
CMETHOD MCErrorWithDomain:code:descriptionArray:errorType: @48@0:8@16q24@32@40
CMETHOD MCErrorWithDomain:code:descriptionArray:suggestion:USEnglishSuggestion:underlyingError:errorType:extraUserInfo: @80@0:8@16q24@32@40@48@56@64@72
CMETHOD MCErrorWithDomain:code:descriptionArray:suggestion:USEnglishSuggestion:underlyingError:errorType: @72@0:8@16q24@32@40@48@56@64
CMETHOD MCErrorWithDomain:code:descriptionArray:underlyingError:errorType: @56@0:8@16q24@32@40@48
CMETHOD rbs_errorClientNotAuthorized @16@0:8
CMETHOD rbs_errorClientNotEntitled:permanent: @28@0:8@16B24
CMETHOD errorWithMTLCaptureErrorCode: @24@0:8q16
CMETHOD aa_errorWithCode: @24@0:8q16
CMETHOD aa_errorWithCode:underlyingError: @32@0:8q16@24
CMETHOD aa_errorWithCode:userInfo: @32@0:8q16@24
CMETHOD aa_errorWithServerResponse: @24@0:8@16
CMETHOD ak_accountPrivacyConsentErrorWithCode: @24@0:8q16
CMETHOD ak_anisetteErrorWithCode:underlyingError: @32@0:8q16@24
CMETHOD ak_attestationErrorWithCode:underlyingError: @32@0:8q16@24
CMETHOD ak_deviceListErrorWithCode: @24@0:8q16
CMETHOD ak_errorWithCode: @24@0:8q16
CMETHOD ak_errorWithCode:underlyingError: @32@0:8q16@24
CMETHOD ak_errorWithCode:userInfo: @32@0:8q16@24
CMETHOD ak_generalErrorWithCode:errorDomain:underlyingError: @40@0:8q16@24@32
CMETHOD ak_livenessErrorWithCode: @24@0:8q16
CMETHOD ak_passkeyErrorWithCode: @24@0:8q16
CMETHOD ak_wrappedAnisetteError: @20@0:8i16
CMETHOD ak_wrappedAnisetteError:underlyingADIErrorCode: @28@0:8q16i24
CMETHOD aida_errorWithCode: @24@0:8q16
CMETHOD aida_errorWithCode:userInfo: @32@0:8q16@24
CMETHOD DMCErrorWithDomain:code:descriptionArray:errorType: @48@0:8@16q24@32@40
CMETHOD DMCErrorWithDomain:code:descriptionArray:suggestion:USEnglishSuggestion:underlyingError:errorType: @72@0:8@16q24@32@40@48@56@64
CMETHOD DMCErrorWithDomain:code:descriptionArray:underlyingError:errorType: @56@0:8@16q24@32@40@48
CMETHOD DMCErrorWithDomain:code:descriptionArray:suggestion:USEnglishSuggestion:underlyingError:errorType:addtionalUserInfo: @80@0:8@16q24@32@40@48@56@64@72
CMETHOD DEPErrorWithDomain:code:descriptionArray:errorType: @48@0:8@16q24@32@40
CMETHOD DEPErrorWithDomain:code:descriptionArray:underlyingError:errorType: @56@0:8@16q24@32@40@48
CMETHOD DEPErrorWithDomain:code:descriptionArray:suggestion:USEnglishSuggestion:underlyingError:errorType: @72@0:8@16q24@32@40@48@56@64
CMETHOD sceneMessageErrorWithCode: @24@0:8q16
CMETHOD _EX_errorWithCode:description: @32@0:8q16@24
CMETHOD _EX_errorWithCode:underlyingError: @32@0:8q16@24
CMETHOD _EX_hostIsLackingRequiredEntitlementErrorWithHostPID:requiredEntitlements: @28@0:8i16@20
CMETHOD _EX_parameterError @16@0:8
CMETHOD _EX_processExitedErrorWithName:pid: @28@0:8@16i24
CMETHOD _EX_unimplementedError @16@0:8
CMETHOD buildCheckedError: @24@0:8@16
CMETHOD _buildCheckedErrorForDomain:withCode:safeUnderlying:description: @48@0:8@16q24@32@40
CMETHOD _checkedDepthCount: q24@0:8@16
CMETHOD _checkedIsSafeUserInfo: B24@0:8@16
CMETHOD buildAndLogCheckedSUCoreError:underlying:description: @40@0:8q16@24@32
CMETHOD buildCheckedSUCoreError:underlying:description: @40@0:8q16@24@32
CMETHOD _un_descriptionForUNErrorCode: @24@0:8q16
CMETHOD _un_descriptionForUNPrivateErrorCode: @24@0:8q16
CMETHOD _updateUserInfo:withLocalizedDescription: @32@0:8@16@24
CMETHOD un_errorWithUNErrorCode:userInfo: @32@0:8q16@24
CMETHOD un_errorWithUNPrivateErrorCode:userInfo: @32@0:8q16@24
CMETHOD errorWithInfo: @24@0:8@16
CMETHOD ax_errorWithDomain:description: @32@0:8@16@24
CMETHOD ax_errorWithDomain:code:description: @40@0:8@16q24@32
CMETHOD ax_errorWithDomain:code:description:arguments: @48@0:8@16q24@32*40
CMETHOD genericErrorWithFile:function:lineNumber: @40@0:8r*16r*24q32
CMETHOD GEOErrorWithCode:reason: @32@0:8q16@24
CMETHOD GEOErrorWithCode:reason:userInfo: @40@0:8q16@24@32
CMETHOD GEOErrorWithCode: @24@0:8q16
CMETHOD GEOErrorWithCode:reason:underlyingError: @40@0:8q16@24@32
CMETHOD GEOErrorWithCode:userInfo: @32@0:8q16@24
CMETHOD _geo_errorFromXPCData: @24@0:8@16
CMETHOD _geo_errorFromXPCError: @24@0:8@16
CMETHOD _geo_errorWithDirectionsError: @24@0:8@16
CMETHOD geo_insufficientFilesystemCapacityWithBytesNeeded:bytesAvailable: @32@0:8Q16Q24
CMETHOD zilchDecoderErrorForNoSolution @16@0:8
CMETHOD logInternalError: v24@0:8@16
CMETHOD VisionCoreAssert:log: v28@0:8B16@20
CMETHOD VisionCoreErrorForCVReturnCode:localizedDescription: @28@0:8i16@20
CMETHOD VisionCoreErrorForCorruptedResourceWithLocalizedDescription: @24@0:8@16
CMETHOD VisionCoreErrorForE5RTErrorCode:localizedDescription: @28@0:8i16@20
CMETHOD VisionCoreErrorForE5RTLastErrorMessageAndCode: @20@0:8i16
CMETHOD VisionCoreErrorForEspressoErrorInfo:localizedDescription: @40@0:8{?=ii*}16@32
CMETHOD VisionCoreErrorForEspressoReturnStatus:localizedDescription: @28@0:8i16@20
CMETHOD VisionCoreErrorForFailedEspressoPlan:localizedDescription: @32@0:8^v16@24
CMETHOD VisionCoreErrorForFailedOperationWithLocalizedDescription: @24@0:8@16
CMETHOD VisionCoreErrorForInternalErrorWithLocalizedDescription: @24@0:8@16
CMETHOD VisionCoreErrorForInvalidArgumentWithLocalizedDescription: @24@0:8@16
CMETHOD VisionCoreErrorForInvalidOperationWithLocalizedDescription: @24@0:8@16
CMETHOD VisionCoreErrorForKernelReturnCode:localizedDescription: @28@0:8i16@20
CMETHOD VisionCoreErrorForMemoryAllocationFailure @16@0:8
CMETHOD VisionCoreErrorForMemoryAllocationFailureOfElementCount:size: @32@0:8Q16Q24
CMETHOD VisionCoreErrorForMemoryAllocationFailureOfSize: @24@0:8Q16
CMETHOD VisionCoreErrorForMemoryAllocationFailureWithLocalizedDescription: @24@0:8@16
CMETHOD VisionCoreErrorForUnavailableDescriptorIdentifier:version: @32@0:8@16@24
CMETHOD VisionCoreErrorForUnavailableResourceWithLocalizedDescription: @24@0:8@16
CMETHOD VisionCoreErrorForUnknownProcessingDescriptorIdentifier: @24@0:8@16
CMETHOD VisionCoreErrorForUnsupportedE5RTIOPortType: @24@0:8Q16
CMETHOD VisionCoreErrorWithCode:localizedDescription: @32@0:8q16@24
CMETHOD VisionCoreErrorWithCode:localizedDescription:underlyingError: @40@0:8q16@24@32
CMETHOD VisionCoreErrorWithCode:userInfo: @32@0:8q16@24
CMETHOD VisionCoreErrorWithDomain:code:userInfo: @40@0:8@16q24@32
CMETHOD _VisionCoreErrorForMemoryAllocationFailureWithLocalizedDescription: @24@0:8@16
CMETHOD _VisionCoreEspressoErrorWithLocalizedDescription: @24@0:8@16
CMETHOD CKErrorFromErrno @16@0:8
CMETHOD CKErrorWithPOSIXCode: @20@0:8i16
CMETHOD CKIsConstraintError: B24@0:8@16
CMETHOD CKIsDiskFullError: B24@0:8@16
CMETHOD CKIsGroupExistsError: B24@0:8@16
CMETHOD CKIsNoSuchTableError: B24@0:8@16
CMETHOD CKIsValidationError: B24@0:8@16
CMETHOD CKIsBusyDatabaseError: B24@0:8@16
CMETHOD CKIsCorruptDatabaseError: B24@0:8@16
CMETHOD CKIsForeignKeyConstraintError: B24@0:8@16
CMETHOD CKIsNoMatchingRowError: B24@0:8@16
CMETHOD CKIsNoUniqueRowError: B24@0:8@16
CMETHOD CKIsUniqueConstraintError: B24@0:8@16
CMETHOD errorWithDomain:code:description: @40@0:8@16q24@32
CMETHOD errorWithDomain:code:description:underlying: @48@0:8@16q24@32@40
CMETHOD errorWithCoreCryptoStatus:description:args: @36@0:8i16@20*28
CMETHOD errorWithCoreCryptoStatus:userInfo: @28@0:8i16@20
CMETHOD errorWithJoiningError:format: @32@0:8q16@24
CMETHOD errorWithJoiningError:format:arguments: @40@0:8q16@24*32
CMETHOD errorWithOSStatus:description:args: @36@0:8i16@20*28
CMETHOD errorWithOSStatus:userInfo: @28@0:8i16@20
CMETHOD brc_errorCantCallFPInSyncBubble @16@0:8
CMETHOD brc_errorItemProcessingDisabled @16@0:8
CMETHOD brc_errorFolderHierarchyTooDeep @16@0:8
CMETHOD brc_errorNoAppLibraryForBundle: @24@0:8@16
CMETHOD brc_unkownErrorWithDescription: @24@0:8@16
CMETHOD _getFirstCloudKitUnderlyingError: @24@0:8@16
CMETHOD br_errorFromErrno @16@0:8
CMETHOD br_errorWithDomain:code:description: @40@0:8@16q24@32
CMETHOD br_errorWithDomain:code:userInfo:description: @48@0:8@16q24@32@40
CMETHOD br_errorWithPOSIXCode: @20@0:8i16
CMETHOD br_errorWithPOSIXCode:description: @28@0:8i16@20
CMETHOD brc_addPartialError:forURL:toError: @40@0:8@16@24@32
CMETHOD brc_errorAcceptAlreadyInProgressForURL: @24@0:8@16
CMETHOD brc_errorAcceptShareFailedForItem: @24@0:8@16
CMETHOD brc_errorAcceptShareFailedWithUnderlyingError: @24@0:8@16
CMETHOD brc_errorAccountMismatch @16@0:8
CMETHOD brc_errorAccountSessionOpenFailed @16@0:8
CMETHOD brc_errorAppLibraryNotFound: @24@0:8@16
CMETHOD brc_errorBouncedItemNotKnownByServer @16@0:8
CMETHOD brc_errorBuddyFlowNeedsToRun @16@0:8
CMETHOD brc_errorCantCreateAsset @16@0:8
CMETHOD brc_errorCantRegisterBGSystemTask @16@0:8
CMETHOD brc_errorCellularStatusChanged @16@0:8
CMETHOD brc_errorClientZoneNotFound: @24@0:8@16
CMETHOD brc_errorCollisionWithItem: @24@0:8@16
CMETHOD brc_errorCompatibilityIssue @16@0:8
CMETHOD brc_errorCoreAnalyticsErrorCountMismatchWithExpected:actual: @32@0:8@16@24
CMETHOD brc_errorCorruptedDB @16@0:8
CMETHOD brc_errorDaemonShouldBeLoggedOut @16@0:8
CMETHOD brc_errorDamagedDocumentOnDiskWithUnderlyingError: @24@0:8@16
CMETHOD brc_errorDeletingNonEmptyDirectoryNonRecursively @16@0:8
CMETHOD brc_errorDocumentAtURL:isNotExternalToAppLibrary: @32@0:8@16@24
CMETHOD brc_errorDocumentEvicted @16@0:8
CMETHOD brc_errorDocumentIsNoLongerSharedAtIdentifier: @24@0:8@16
CMETHOD brc_errorDocumentIsNotGreedy @16@0:8
CMETHOD brc_errorDocumentIsNotShared @16@0:8
CMETHOD brc_errorDocumentIsNotSharedAtIdentifier: @24@0:8@16
CMETHOD brc_errorDocumentWithFilename:size:isTooLargeToUpload:localizedDescription: @48@0:8@16q24q32@40
CMETHOD brc_errorDownloadCancelled @16@0:8
CMETHOD brc_errorDriveDisabledOrAppLibraryDisabled @16@0:8
CMETHOD brc_errorExcludedFromSyncDueToFilename @16@0:8
CMETHOD brc_errorExcludedFromSyncUnderRoot @16@0:8
CMETHOD brc_errorFolderHasSharedSubitems @16@0:8
CMETHOD brc_errorFolderHasSharedSubitemsWithSharedByMeURLs:sharedToMeURLs: @32@0:8@16@24
CMETHOD brc_errorForRejectedDeletionOfItem: @24@0:8@16
CMETHOD brc_errorFromException: @24@0:8@16
CMETHOD brc_errorFunctionNotImplemented: @24@0:8@16
CMETHOD brc_errorImportObjectTypeMismatch @16@0:8
CMETHOD brc_errorInitialScanItemBouncedByServer @16@0:8
CMETHOD brc_errorInitialScanItemTypeMismatch @16@0:8
CMETHOD brc_errorInvalidParameter:value: @32@0:8@16@24
CMETHOD brc_errorItemAlreadyPartOfAShare @16@0:8
CMETHOD brc_errorItemAlreadyPausedFromSyncByBundleID: @24@0:8@16
CMETHOD brc_errorItemBusy @16@0:8
CMETHOD brc_errorItemChanged @16@0:8
CMETHOD brc_errorItemInTrash @16@0:8
CMETHOD brc_errorItemIneligibleFromSyncForInode:localizedDescription: @32@0:8@16@24
CMETHOD brc_errorItemNotFound: @24@0:8@16
CMETHOD brc_errorItemNotPausedFromSync @16@0:8
CMETHOD brc_errorItemNotShareable @16@0:8
CMETHOD brc_errorLoggedOut @16@0:8
CMETHOD brc_errorLoggedOutWithUnderlyingError: @24@0:8@16
CMETHOD brc_errorMDMRestrictsCrossPersonaClientApp @16@0:8
CMETHOD brc_errorMethodNotImplemented: @24@0:8:16
CMETHOD brc_errorNetworkUnreachable @16@0:8
CMETHOD brc_errorNetworkUnreachableDueToCellularConstraint @16@0:8
CMETHOD brc_errorNetworkUnreachableDueToCellularOverICDDisabled @16@0:8
CMETHOD brc_errorNoBRItemService @16@0:8
CMETHOD brc_errorNoDocument:underlyingPOSIXError: @28@0:8@16i24
CMETHOD brc_errorNoDocumentAtURL:underlyingError: @32@0:8@16@24
CMETHOD brc_errorNoEtagAvailableForDownloadOfItemWithIdentifier: @24@0:8@16
CMETHOD brc_errorNoEtagInContentSignature @16@0:8
CMETHOD brc_errorNoSuitableClientApp @16@0:8
CMETHOD brc_errorNotInCloud: @24@0:8@16
CMETHOD brc_errorNotOnDisk: @24@0:8@16
CMETHOD brc_errorNotRegularFile @16@0:8
CMETHOD brc_errorNotSupportedInCustomerBuild @16@0:8
CMETHOD brc_errorNotSupportedInFPFS @16@0:8
CMETHOD brc_errorOperationAlreadyRunning: @24@0:8@16
CMETHOD brc_errorOperationCancelled @16@0:8
CMETHOD brc_errorOperationNotImplemented: @24@0:8@16
CMETHOD brc_errorParentItemRemotelyDeleted: @24@0:8@16
CMETHOD brc_errorPathOutsideAnyCloudDocsAppLibraryAtURL: @24@0:8@16
CMETHOD brc_errorPermissionError: @24@0:8@16
CMETHOD brc_errorPermissionErrorAtURL: @24@0:8@16
CMETHOD brc_errorPostponeUpload @16@0:8
CMETHOD brc_errorRecordBouncedByServer @16@0:8
CMETHOD brc_errorRecordValidation @16@0:8
CMETHOD brc_errorRequestedVersionHasLocalEdits @16@0:8
CMETHOD brc_errorRescheduleDownloadForMoreRecentServerVersion @16@0:8
CMETHOD brc_errorShouldNotDownloadOverCellular @16@0:8
CMETHOD brc_errorStuckFPFSMigration @16@0:8
CMETHOD brc_errorSyncBlocked @16@0:8
CMETHOD brc_errorSyncDisabled: @24@0:8@16
CMETHOD brc_errorTCCAccessDenied @16@0:8
CMETHOD brc_errorThrottledWithDescription: @24@0:8@16
CMETHOD brc_errorThumbnailGenerationOperationTimedOut @16@0:8
CMETHOD brc_errorUnexpectedItemType:description: @32@0:8@16@24
CMETHOD brc_errorUnknownKey: @24@0:8@16
CMETHOD brc_errorUserCancelledDialog @16@0:8
CMETHOD brc_errorZoneReset @16@0:8
CMETHOD brc_genericDownloadErrorWithUnderlyingError: @24@0:8@16
CMETHOD newFromSqliteStatement:atIndex: @28@0:8^{sqlite3_stmt=}16i24
CMETHOD newFromSqliteValue: @24@0:8^{sqlite3_value=}16
CMETHOD errorWithSqliteCode:andMessage: @28@0:8i16@20
CMETHOD errorForDB:SQL: @32@0:8^{sqlite3=}16@24
CMETHOD errorForDB: @24@0:8^{sqlite3=}16
CMETHOD errorForDB:stmt: @32@0:8^{sqlite3=}16^{sqlite3_stmt=}24
CMETHOD fm_genericError @16@0:8
CMETHOD fm_timeoutError @16@0:8
CMETHOD fm_cancelledError @16@0:8
CMETHOD fm_errorWithCode: @24@0:8q16
CMETHOD _xct_error:description: @32@0:8q16@24
CMETHOD _xct_error:description:userInfo: @40@0:8q16@24@32
CMETHOD _registerWebKitErrors v16@0:8
CMETHOD _webKitErrorWithCode:failingURL: @28@0:8i16@20
CMETHOD _webKitErrorWithDomain:code:URL: @36@0:8@16i24@28
CMETHOD _webkit_addErrorsWithCodesAndDescriptions:inDomain: v32@0:8@16@24
CMETHOD _webkit_errorWithDomain:code:URL: @36@0:8@16i24@28
CMETHOD errorWithCode:debugDescription: @32@0:8q16@24
CMETHOD _errorWithCode:userInfo: @32@0:8q16@24
CMETHOD supportsSecureCoding B16@0:8
CMETHOD userInfoValueProviderForDomain: @?24@0:8@16
CMETHOD _cocoaErrorWithCode:path:url:underlying:variant:source:destination: @72@0:8q16@24@32@40@48@56@64
CMETHOD _readCorruptErrorWithFormat: @24@0:8@16
CMETHOD _registerBuiltInFormatters v16@0:8
CMETHOD _registerFormatter:forErrorKey:parameters: v40@0:8^?16@24r*32
CMETHOD _setFileNameLocalizationEnabled: v20@0:8B16
CMETHOD _web_addErrorsWithCodesAndDescriptions:inDomain: v32@0:8@16@24
CMETHOD _web_errorWithDomain:code:URL: @40@0:8@16q24@32
CMETHOD _web_errorWithDomain:code:failingURL: @40@0:8@16q24@32
CMETHOD errorWithDomain:code:userInfo: @40@0:8@16q24@32
CMETHOD setUserInfoValueProviderForDomain:provider: v32@0:8@16@?24
METHOD fp_isFileProviderError: B24@0:8q16
METHOD fp_isFileProviderInternalError: B24@0:8q16
METHOD fp_userInfoItem @16@0:8
METHOD fp_collidingURL @16@0:8
METHOD fp_annotatedErrorWithItem:variant: @32@0:8@16@24
METHOD fp_annotatedErrorWithItems:variant: @32@0:8@16@24
METHOD fp_annotatedErrorWithName: @24@0:8@16
METHOD fp_annotatedErrorWithName:path:variant: @40@0:8@16@24@32
METHOD fp_annotatedErrorWithOperationItem: @24@0:8@16
METHOD fp_annotatedErrorWithRecoveryAttempter:fpProviderDomainId: @32@0:8@16@24
METHOD fp_annotatedErrorWithURL:variant: @32@0:8@16@24
METHOD fp_asWarning @16@0:8
METHOD fp_genericPreflightError @16@0:8
METHOD fp_internalErrorForVendorErrorWithCallerDescription:itemCreationBlock: @32@0:8@16@?24
METHOD fp_internalUserInfoValueKey: @24@0:8@16
METHOD fp_isCocoaErrorCode: B24@0:8q16
METHOD fp_isFeatureUnsupportedError B16@0:8
METHOD fp_isGenericPreflightError B16@0:8
METHOD fp_isNameTooLongError B16@0:8
METHOD fp_isNotPermittedError B16@0:8
METHOD fp_isPOSIXErrorCode: B20@0:8i16
METHOD fp_isRemoteCrashError B16@0:8
METHOD fp_isSyncAnchorExpiredError B16@0:8
METHOD fp_isWarning B16@0:8
METHOD fp_prettyDescription @16@0:8
METHOD fp_prettyDescription: @24@0:8Q16
METHOD fp_recoverableErrorWithBlock:fpProviderDomainId:operationService: @40@0:8@?16@24@32
METHOD fp_strippedError @16@0:8
METHOD fp_unwrappedErrorForDomains: @24@0:8@16
METHOD fp_unwrappedInternalError @16@0:8
METHOD fp_userInfoFPItem @16@0:8
METHOD fp_userInfoValueForKey: @24@0:8@16
METHOD descriptionWithMultilinePrefix: @24@0:8@16
METHOD descriptionBuilderWithMultilinePrefix: @24@0:8@16
METHOD succinctDescription @16@0:8
METHOD succinctDescriptionBuilder @16@0:8
METHOD MCContainsErrorDomain:code: B32@0:8@16q24
METHOD MCUSEnglishDescription @16@0:8
METHOD MCCopyAsPrimaryError @16@0:8
METHOD MCErrorType @16@0:8
METHOD MCFindPrimaryError @16@0:8
METHOD MCUSEnglishSuggestion @16@0:8
METHOD MCVerboseDescription @16@0:8
METHOD rbs_isPermanentFailure B16@0:8
METHOD nr_filteredError @16@0:8
METHOD nr_safeDescription @16@0:8
METHOD ac_isUnrecoverableDatabaseError B16@0:8
METHOD ac_isDiskFullSQLError B16@0:8
METHOD ac_sanitizeObject: @24@0:8@16
METHOD ac_secureCodingError @16@0:8
METHOD _aa_userReadableError @16@0:8
METHOD aa_isAACustodianRecoveryError B16@0:8
METHOD aa_isAACustodianRecoveryErrorWithCode: B24@0:8q16
METHOD aa_isAAErrorWithCode: B24@0:8q16
METHOD aa_isAARecoverableError B16@0:8
METHOD aa_isAASignInErrorWithCode: B24@0:8q16
METHOD aa_isXPCError B16@0:8
METHOD aa_partialErrorsByName @16@0:8
METHOD isRecoverableError B16@0:8
METHOD ak_isUserCancelError B16@0:8
METHOD ak_isAppleIDSetupErrorWithCode: B24@0:8q16
METHOD ak_allUnderlyingErrors @16@0:8
METHOD ak_allUnderlyingErrorsWithMaxDepth: @24@0:8q16
METHOD ak_errorByAppendingUserInfo: @24@0:8@16
METHOD ak_errorsHeaderStringWithMessage @16@0:8
METHOD ak_isAdditionalCTASelected B16@0:8
METHOD ak_isAppleIDSetupCancelError B16@0:8
METHOD ak_isAuthenticationError B16@0:8
METHOD ak_isAuthenticationErrorWithCode: B24@0:8q16
METHOD ak_isEligibleForProxiedAuthFallback B16@0:8
METHOD ak_isIncompatibleDevicesError B16@0:8
METHOD ak_isLAUserCancelError B16@0:8
METHOD ak_isServerThrottlingError B16@0:8
METHOD ak_isServiceError B16@0:8
METHOD ak_isSurrogateAuthAlreadyInProgressError B16@0:8
METHOD ak_isUnableToPromptError B16@0:8
METHOD ak_isUserInitiatedError B16@0:8
METHOD ak_isUserSkippedError B16@0:8
METHOD ak_isUserTryAgainError B16@0:8
METHOD ak_isXPCServiceError B16@0:8
METHOD errorDescriptionIncludingUnderlyingErrorsWithMaxDepth: @24@0:8q16
METHOD isAccountNotProvisioned B16@0:8
METHOD DMCCopyAsPrimaryError @16@0:8
METHOD DMCErrorType @16@0:8
METHOD DMCUSEnglishDescription @16@0:8
METHOD DMCContainsErrorDomain:code: B32@0:8@16q24
METHOD DMCVerboseDescription @16@0:8
METHOD DMCFindPrimaryError @16@0:8
METHOD DMCUSEnglishSuggestion @16@0:8
METHOD DEPUSEnglishDescription @16@0:8
METHOD DEPFindPrimaryError @16@0:8
METHOD isBSServiceConnectionError B16@0:8
METHOD checkedDescription @16@0:8
METHOD checkedSummary @16@0:8
METHOD _checkedIsSafe: B20@0:8B16
METHOD checkedOfLayer: @24@0:8q16
METHOD checkedIndicationsMatchingMask: q24@0:8q16
METHOD checkedUserInfo @16@0:8
METHOD _checkedIndicationsMatching: q24@0:8q16
METHOD _checkedStackErrorAtDepth: @24@0:8q16
METHOD _deepestWithLayer @16@0:8
METHOD _errorInStackLayer q16@0:8
METHOD _errorInStackOfLayer: @24@0:8q16
METHOD checkedCode q16@0:8
METHOD checkedDepthCount q16@0:8
METHOD checkedDomain @16@0:8
METHOD checkedForDepthIndex: @24@0:8q16
METHOD checkedIndications q16@0:8
METHOD checkedIndicationsDescription @16@0:8
METHOD checkedIndicationsSummary @16@0:8
METHOD checkedLayer q16@0:8
METHOD checkedNameForCode @16@0:8
METHOD checkedSystemPartitionSize Q16@0:8
METHOD shouldFallbackToCustomerScan B16@0:8
METHOD augmentWithPrefix: @24@0:8@16
METHOD ax_nonRedundantDescription @16@0:8
METHOD _geo_newXPCData @16@0:8
METHOD _geo_directionsErrorInfo @16@0:8
METHOD _geo_etaTrafficUpdateErrorInfo @16@0:8
METHOD _geo_isNetworkError B16@0:8
METHOD _geo_isXPCInterruptedError B16@0:8
METHOD zilchDecoderTileLoadingError @16@0:8
METHOD CKClientSuitableUnderlyingError @16@0:8
METHOD CKAssignToContainerWithID: v24@0:8@16
METHOD CKClientSuitableError @16@0:8
METHOD CKDescriptionPropertiesWithPublic:private:shouldExpand: @28@0:8B16B20B24
METHOD CKHasCKErrorInUnderlyingErrors B16@0:8
METHOD CKIsCKError B16@0:8
METHOD CKIsNotFoundError B16@0:8
METHOD CKIsPOSIXErrorCode: B24@0:8q16
METHOD CKItemErrorForID: @24@0:8@16
METHOD CKSQLiteErrorMessage @16@0:8
METHOD CKClientSuitableErrorSpecificUserInfo @16@0:8
METHOD CKErrorScopedToZoneIDs: @24@0:8@16
METHOD CKHasTopLevelUnderlyingError B16@0:8
METHOD CKIsCKSQLiteError B16@0:8
METHOD CKIsObjectNotFoundError B16@0:8
METHOD CKIsXPCConnectionError B16@0:8
METHOD CKSQLiteCode i16@0:8
METHOD CKSQLiteExtendedCode i16@0:8
METHOD CKStringForWellKnownCKErrors @16@0:8
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD isCKComparisonError B16@0:8
METHOD isCloudCoreSessionNoLongerValidError B16@0:8
METHOD initWithCoreCryptoStatus:description:args: @36@0:8i16@20*28
METHOD initWithCoreCryptoStatus:userInfo: @28@0:8i16@20
METHOD initWithJoiningError:userInfo: @32@0:8q16@24
METHOD initWithOSStatus:description:args: @36@0:8i16@20*28
METHOD initWithOSStatus:userInfo: @28@0:8i16@20
METHOD _br_fileProviderErrorWithFallbackFileProviderErrorCode: @24@0:8q16
METHOD _br_getFileProviderDomainErrorCode: B24@0:8^q16
METHOD _br_populateErrorMessageOnUserInfo: v24@0:8@16
METHOD _br_populateUserInfoDictWithDomain:code:setSelfAsUnderlyingError: @36@0:8@16q24B32
METHOD _createWrappedErrorWithDomain:code: @32@0:8@16q24
METHOD _isTransientError:code: B32@0:8@16q24
METHOD br_errorDescription @16@0:8
METHOD br_fileProviderError @16@0:8
METHOD br_fileProviderErrorForDownloadFlow @16@0:8
METHOD br_isCKErrorCode: B24@0:8q16
METHOD br_isCKErrorCode:underlyingErrorCode: B32@0:8q16q24
METHOD br_isCloudDocsErrorCode: B24@0:8q16
METHOD br_isCocoaErrorCode: B24@0:8q16
METHOD br_isFileProviderErrorCode: B24@0:8q16
METHOD br_isGenericDownloadError B16@0:8
METHOD br_isNSURLErrorCode: B24@0:8q16
METHOD br_isNSXPCConnectionError B16@0:8
METHOD br_isPOSIXErrorCode: B24@0:8q16
METHOD br_underlyingPOSIXError @16@0:8
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD sqliteStatement @16@0:8
METHOD extendedSqliteCode q16@0:8
METHOD isSqliteErrorCode: B24@0:8q16
METHOD fm_isCancelledError B16@0:8
METHOD fm_isFileNotFoundError B16@0:8
METHOD fm_isTimeoutError B16@0:8
METHOD _initWithPluginErrorCode:contentURL:pluginPageURL:pluginName:MIMEType: @52@0:8i16@20@28@36@44
METHOD _webkit_initWithDomain:code:URL: @36@0:8@16i24@28
METHOD bls_shortLoggingString @16@0:8
METHOD bls_loggingString @16@0:8
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD _cfTypeID Q16@0:8
METHOD code q16@0:8
METHOD domain @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithDomain:code:userInfo: @40@0:8@16q24@32
METHOD localizedDescription @16@0:8
METHOD localizedFailureReason @16@0:8
METHOD localizedRecoverySuggestion @16@0:8
METHOD redactedDescription @16@0:8
METHOD userInfo @16@0:8
METHOD _web_failingURL @16@0:8
METHOD _callStackReturnAddresses @16@0:8
METHOD _cocoaErrorString: @24@0:8@16
METHOD _cocoaErrorString:fromBundle:tableName: @40@0:8@16@24@32
METHOD _cocoaErrorStringWithKind: @24@0:8@16
METHOD _cocoaErrorStringWithKind:variant: @32@0:8@16@24
METHOD _collectApplicableUserInfoFormatters:max: q32@0:8^^{?}16q24
METHOD _formatCocoaErrorString:parameters:applicableFormatters:count: @48@0:8@16r*24^^{?}32q40
METHOD _retainedUserInfoCallBackForKey: ^{__CFString=}24@0:8@16
METHOD _web_errorIsInDomain: B24@0:8@16
METHOD _web_initWithDomain:code:failingURL: @40@0:8@16q24@32
METHOD _web_initWithDomain_nowarn:code:URL: @40@0:8@16q24@32
METHOD _web_localizedDescription @16@0:8
METHOD helpAnchor @16@0:8
METHOD localizedRecoveryOptions @16@0:8
METHOD recoveryAttempter @16@0:8
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD underlyingErrors @16@0:8

=== CLASS NSException ===
SUPER: NSObject
SIZE: 40
PROTOCOLS: NSCopying NSSecureCoding
IVAR +8 0 name @"NSString"
IVAR +16 0 reason @"NSString"
IVAR +24 0 userInfo @"NSDictionary"
IVAR +32 0 reserved @
CMETHOD supportsSecureCoding B16@0:8
CMETHOD performBlockThrowingExceptionsAsErrors:error: B32@0:8@?16^@24
CMETHOD throwTestException v16@0:8
CMETHOD exceptionWithName:reason:userInfo: @40@0:8@16@24@32
CMETHOD exceptionWithName:reason:userInfo:osLogPack:size: @56@0:8@16@24@32^v40Q48
CMETHOD raise:format: v32@0:8@16@24
CMETHOD raise:format:arguments: v40@0:8@16@24*32
CMETHOD supportsSecureCoding B16@0:8
METHOD debugDescription @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD nr_safeDescription @16@0:8
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD name @16@0:8
METHOD _installStackTraceKeyIfNeeded B16@0:8
METHOD _isUnarchived B16@0:8
METHOD _markAsUnarchived v16@0:8
METHOD callStackReturnAddresses @16@0:8
METHOD callStackSymbols @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithName:reason:userInfo: @40@0:8@16@24@32
METHOD initWithName:reason:userInfo:osLogPack:size: @56@0:8@16@24@32^v40Q48
METHOD raise v16@0:8
METHOD reason @16@0:8
METHOD redactedDescription @16@0:8
METHOD userInfo @16@0:8

=== CLASS NSFileManager ===
SUPER: NSObject
SIZE: 32
IVAR +8 0 _delegate @"<NSFileManagerDelegate>"
IVAR +16 0 _weakDelegateValue @"NSValue"
IVAR +24 0 swiftBridge @"_NSFileManagerBridge"
CMETHOD _LS_frameworkFileManager @16@0:8
CMETHOD fm_setDataProtectionClass:forFileURL:error: B40@0:8q16@24^@32
CMETHOD _QLTRemoveTemporaryDirectoryAtURL: v24@0:8@16
CMETHOD triArbitraryFileInDirWithPath: @24@0:8@16
CMETHOD triHasFileProtection: B24@0:8@16
CMETHOD triIdempotentCreateDirectoryOrFaultWithPath: B24@0:8@16
CMETHOD triRemoveFileProtectionIfPresentForPath: B24@0:8@16
CMETHOD defaultManager @16@0:8
METHOD _cutIsPathOnMissingVolume: B24@0:8@16
METHOD cutCreateUniqueDirectoryWithName:atPath:ofType: @40@0:8@16@24@32
METHOD cutRandomTemporaryPathWithFileName: @24@0:8@16
METHOD cutUniqueFilename:atPath:ofType: @40@0:8@16@24@32
METHOD br_movePromisedItemAtURL:toURL:error: B40@0:8@16@24^@32
METHOD br_setFavoriteRank:onItemAtURL: v32@0:8@16@24
METHOD br_setLastOpenDate:onItemAtURL: v32@0:8@16@24
METHOD br_forceMoveItemAtURL:toURL:error: B40@0:8@16@24^@32
METHOD br_putBackTrashedItemAtURL:resultingURL:error: B40@0:8@16^@24^@32
METHOD br_putBackURLForTrashedItemAtURL:error: @32@0:8@16^@24
METHOD br_setPutBackInfoOnItemAtURL: v24@0:8@16
METHOD br_topLevelSharedFolderForURL:error: @32@0:8@16^@24
METHOD br_trashItemAtURL:resultingURL:error: B40@0:8@16^@24^@32
METHOD brc_createTemporaryFileInDirectory:withTemplate:error: @40@0:8@16@24^@32
METHOD brc_createTemporarySubdirectoryOfItem:withTemplate:error: @40@0:8@16@24^@32
METHOD _randomTemporaryPathWithSuffix: @24@0:8@16
METHOD _generateLinkForURL: @24@0:8@16
METHOD _isPathOnMissingVolume: B24@0:8@16
METHOD _moveItemAtPath:toPath:uniquePath:error:asCopy: B52@0:8@16@24^@32^@40B48
METHOD _randomSimilarFilePathAsPath: @24@0:8@16
METHOD _randomTemporaryPathWithFileName: @24@0:8@16
METHOD _randomTemporaryPathWithFileName:withAppendedPathComponent: @32@0:8@16@24
METHOD _randomTemporaryPathWithSuffix:fileName: @32@0:8@16@24
METHOD _randomTemporaryPathWithSuffix:fileName:withAppendedPathComponent: @40@0:8@16@24@32
METHOD _randomTemporaryPathWithSuffix:withAppendedPathComponent: @32@0:8@16@24
METHOD copyItemAtPath:toPath:uniquePath:error: B48@0:8@16@24^@32^@40
METHOD createUniqueDirectoryWithName:atPath:ofType: @40@0:8@16@24@32
METHOD makeDirectoriesInPath:mode: B28@0:8@16I24
METHOD moveItemAtPath:toPath:uniquePath:error: B48@0:8@16@24^@32^@40
METHOD uniqueFilename:atPath:ofType: @40@0:8@16@24@32
METHOD _webkit_createTemporaryDirectoryWithTemplatePrefix: @24@0:8@16
METHOD _webkit_pathWithUniqueFilenameForPath: @24@0:8@16
METHOD fp_trashItemAtURL:resultingItemURL:error: B40@0:8@16^@24^@32
METHOD fp_trashURLForItemAtURL:error: @32@0:8@16^@24
METHOD fp_createPathIfNeeded: v24@0:8@16
METHOD fp_putBackURLForTrashedItemAtURL:error: @32@0:8@16^@24
METHOD fp_setPutBackInfoOnItemAtURL: v24@0:8@16
METHOD gs_createTemporarySubdirectoryOfItem:withTemplate:error: @40@0:8@16@24^@32
METHOD if_auditTokenForExtendedAttributeNamed:ofItemAtURL: {?=[8I]}32@0:8@16@24
METHOD if_boolForExtendedAttributeName:ofItemAtURL: B32@0:8@16@24
METHOD if_removeExtendedAttributeName:ofItemAtURL: B32@0:8@16@24
METHOD if_setAuditToken:forExtendedAttributeNamed:ofItemAtURL: B64@0:8{?=[8I]}16@48@56
METHOD if_setBool:forExtendedAttributeNamed:ofItemAtURL: B36@0:8B16@20@28
METHOD _doc_destinationLocationExists: B24@0:8q16
METHOD _doc_importItemAtURL:toDestination:error: @40@0:8@16q24^@32
METHOD triCreateDirectoryForPath:isDirectory:error: @36@0:8@16B24^@28
METHOD triPath:relativeToParentPath: @32@0:8@16@24
METHOD triRemoveItemAtPath:error: B32@0:8@16^@24
METHOD triSafeCopyItemAtPath:toPath:error: B40@0:8@16@24^@32
METHOD feedbackLoggerDirectoryURL @16@0:8
METHOD urlForStoreWithId: @24@0:8@16
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD retain @16@0:8
METHOD delegate @16@0:8
METHOD setDelegate: v24@0:8@16
METHOD evictUbiquitousItemAtURL:error: B32@0:8@16^@24
METHOD getFileProviderMessageInterfacesForItemAtURL:completionHandler: v32@0:8@16@?24
METHOD URLForDirectory:inDomain:appropriateForURL:create:error: @52@0:8Q16Q24@32B40^@44
METHOD URLForPublishingUbiquitousItemAtURL:expirationDate:error: @40@0:8@16^@24^@32
METHOD URLsForDirectory:inDomains: @32@0:8Q16Q24
METHOD _URLForTrashingItemAtURL:create:error: @36@0:8@16B24^@28
METHOD contentsAtPath: @24@0:8@16
METHOD URLForUbiquityContainerIdentifier: @24@0:8@16
METHOD _URLForReplacingItemAtURL:error: @32@0:8@16^@24
METHOD subpathsAtPath: @24@0:8@16
METHOD _attributesOfItemAtPath:filterResourceFork:error: @36@0:8@16B24^@28
METHOD _attributesOfItemAtURL:filterResourceFork:error: @36@0:8@16B24^@28
METHOD _displayPathForPath: @24@0:8@16
METHOD _handleFaultedOutCloudDocFromSource:toDestination:handled:error: B48@0:8@16@24^B32^@40
METHOD _performRemoveFileAtPath: v24@0:8@16
METHOD _processCanAccessUbiquityIdentityToken B16@0:8
METHOD _processHasUbiquityContainerEntitlement B16@0:8
METHOD _processUsesCloudServices B16@0:8
METHOD _replaceItemAtURL:withItemAtURL:backupItemName:options:resultingItemURL:error: B64@0:8@16@24@32Q40^@48^@56
METHOD _safeDelegate @16@0:8
METHOD _web_backgroundRemoveFileAtPath: v24@0:8@16
METHOD _web_backgroundRemoveLeftoverFiles: v24@0:8@16
METHOD _web_carbonPathForPath_nowarn: @24@0:8@16
METHOD _web_changeFileAttributes_nowarn:atPath: B32@0:8@16@24
METHOD _web_changeFinderAttributes:forFileAtPath: B32@0:8@16@24
METHOD _web_createDirectoryAtPathWithIntermediateDirectories:attributes: B32@0:8@16@24
METHOD _web_createFileAtPath:contents:attributes: B40@0:8@16@24@32
METHOD _web_createFileAtPathWithIntermediateDirectories:contents:attributes:directoryAttributes: B48@0:8@16@24@32@40
METHOD _web_createIntermediateDirectoriesForPath_nowarn:attributes: B32@0:8@16@24
METHOD _web_fileExistsAtPath_nowarn:isDirectory:traverseLink: B36@0:8@16^B24B32
METHOD _web_noteFileChangedAtPath_nowarn: v24@0:8@16
METHOD _web_pathWithUniqueFilenameForPath: @24@0:8@16
METHOD _web_removeFileOnlyAtPath: B24@0:8@16
METHOD _web_startupVolumeName_nowarn @16@0:8
METHOD _web_visibleItemsInDirectoryAtPath: @24@0:8@16
METHOD attributesOfFileSystemForPath:error: @32@0:8@16^@24
METHOD attributesOfItemAtPath:error: @32@0:8@16^@24
METHOD changeCurrentDirectoryPath: B24@0:8@16
METHOD changeFileAttributes:atPath: B32@0:8@16@24
METHOD componentsToDisplayForPath: @24@0:8@16
METHOD containerURLForSecurityApplicationGroupIdentifier: @24@0:8@16
METHOD contentsEqualAtPath:andPath: B32@0:8@16@24
METHOD contentsOfDirectoryAtPath:error: @32@0:8@16^@24
METHOD contentsOfDirectoryAtURL:includingPropertiesForKeys:options:error: @48@0:8@16@24Q32^@40
METHOD copyItemAtPath:toPath:error: B40@0:8@16@24^@32
METHOD copyItemAtPath:toPath:options:error: B48@0:8@16@24Q32^@40
METHOD copyItemAtURL:toURL:error: B40@0:8@16@24^@32
METHOD copyItemAtURL:toURL:options:error: B48@0:8@16@24Q32^@40
METHOD createDirectoryAtPath:attributes: B32@0:8@16@24
METHOD createDirectoryAtPath:withIntermediateDirectories:attributes:error: B44@0:8@16B24@28^@36
METHOD createDirectoryAtURL:withIntermediateDirectories:attributes:error: B44@0:8@16B24@28^@36
METHOD createFileAtPath:contents:attributes: B40@0:8@16@24@32
METHOD createSymbolicLinkAtPath:pathContent: B32@0:8@16@24
METHOD createSymbolicLinkAtPath:withDestinationPath:error: B40@0:8@16@24^@32
METHOD createSymbolicLinkAtURL:withDestinationURL:error: B40@0:8@16@24^@32
METHOD currentDirectoryPath @16@0:8
METHOD destinationOfSymbolicLinkAtPath:error: @32@0:8@16^@24
METHOD directoryCanBeCreatedAtPath: B24@0:8@16
METHOD directoryContentsAtPath: @24@0:8@16
METHOD directoryContentsAtPath:matchingExtension:options:keepExtension: @44@0:8@16@24q32B40
METHOD directoryContentsAtPath:matchingExtension:options:keepExtension:error: @52@0:8@16@24q32B40^@44
METHOD displayNameAtPath: @24@0:8@16
METHOD enumeratorAtPath: @24@0:8@16
METHOD enumeratorAtURL:includingPropertiesForKeys:options:errorHandler: @48@0:8@16@24Q32@?40
METHOD fetchLatestRemoteVersionOfItemAtURL:completionHandler: v32@0:8@16@?24
METHOD fileAttributesAtPath:traverseLink: @28@0:8@16B24
METHOD fileExistsAtPath: B24@0:8@16
METHOD fileExistsAtPath:isDirectory: B32@0:8@16^B24
METHOD fileSystemAttributesAtPath: @24@0:8@16
METHOD fileSystemRepresentationWithPath: r*24@0:8@16
METHOD getFileProviderServicesForItemAtURL:completionHandler: v32@0:8@16@?24
METHOD getFileSystemRepresentation:maxLength:withPath: B40@0:8*16Q24@32
METHOD getRelationship:ofDirectory:inDomain:toItemAtURL:error: B56@0:8^q16Q24Q32@40^@48
METHOD getRelationship:ofDirectoryAtURL:toItemAtURL:error: B48@0:8^q16@24@32^@40
METHOD homeDirectoryForCurrentUser @16@0:8
METHOD homeDirectoryForUser: @24@0:8@16
METHOD isDeletableFileAtPath: B24@0:8@16
METHOD isExecutableFileAtPath: B24@0:8@16
METHOD isReadableFileAtPath: B24@0:8@16
METHOD isUbiquitousItemAtURL: B24@0:8@16
METHOD isWritableFileAtPath: B24@0:8@16
METHOD linkItemAtPath:toPath:error: B40@0:8@16@24^@32
METHOD linkItemAtURL:toURL:error: B40@0:8@16@24^@32
METHOD mountedVolumeURLsIncludingResourceValuesForKeys:options: @32@0:8@16Q24
METHOD moveItemAtPath:toPath:error: B40@0:8@16@24^@32
METHOD moveItemAtURL:toURL:error: B40@0:8@16@24^@32
METHOD moveItemAtURL:toURL:options:error: B48@0:8@16@24Q32^@40
METHOD pathContentOfSymbolicLinkAtPath: @24@0:8@16
METHOD pauseSyncForUbiquitousItemAtURL:completionHandler: v32@0:8@16@?24
METHOD removeFileAtPath:handler: B32@0:8@16@24
METHOD removeItemAtPath:error: B32@0:8@16^@24
METHOD removeItemAtURL:error: B32@0:8@16^@24
METHOD replaceItemAtURL:withItemAtURL:backupItemName:options:resultingItemURL:error: B64@0:8@16@24@32Q40^@48^@56
METHOD resumeSyncForUbiquitousItemAtURL:withBehavior:completionHandler: v40@0:8@16q24@?32
METHOD setAttributes:ofItemAtPath:error: B40@0:8@16@24^@32
METHOD setUbiquitous:itemAtURL:destinationURL:error: B44@0:8B16@20@28^@36
METHOD startDownloadingUbiquitousItemAtURL:error: B32@0:8@16^@24
METHOD stringWithFileSystemRepresentation:length: @32@0:8r*16Q24
METHOD subpathsOfDirectoryAtPath:error: @32@0:8@16^@24
METHOD synchronouslyGetFileProviderServiceWithName:forItemAtURL:completionHandler: v40@0:8@16@24@?32
METHOD synchronouslyGetFileProviderServicesForItemAtURL:completionHandler: v32@0:8@16@?24
METHOD temporaryDirectory @16@0:8
METHOD trashItemAtURL:resultingItemURL:error: B40@0:8@16^@24^@32
METHOD ubiquityIdentityToken @16@0:8
METHOD uploadLocalVersionOfUbiquitousItemAtURL:withConflictResolutionPolicy:completionHandler: v40@0:8@16q24@?32

=== CLASS NSJSONSerialization ===
SUPER: NSObject
SIZE: 8
CMETHOD _jsonifyObject: @24@0:8@16
CMETHOD jsonStringFromDictionary:options:error: @40@0:8@16Q24^@32
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD JSONObjectWithData:options:error: @40@0:8@16Q24^@32
CMETHOD JSONObjectWithStream:options:error: @40@0:8@16Q24^@32
CMETHOD dataWithJSONObject:options:error: @40@0:8@16Q24^@32
CMETHOD isValidJSONObject: B24@0:8@16
CMETHOD writeJSONObject:toStream:options:error: q48@0:8@16@24Q32^@40
METHOD init @16@0:8

=== CLASS NSKeyedArchiver ===
SUPER: NSCoder
SIZE: 128
IVAR +8 0 _stream ^v
IVAR +16 0 _flags AQ
IVAR +24 0 _delegate @"<NSKeyedArchiverDelegate>"
IVAR +32 0 _containers @"NSMutableArray"
IVAR +40 0 _objects @"NSMutableArray"
IVAR +48 0 _objRefMap ^{__CFDictionary=}
IVAR +56 0 _replacementMap ^{__CFDictionary=}
IVAR +64 0 _classNameMap ^{__CFDictionary=}
IVAR +72 0 _conditionals ^{__CFDictionary=}
IVAR +80 0 _classes ^{__CFDictionary=}
IVAR +88 0 _genericKey Q
IVAR +96 0 _cache r^^{__CFKeyedArchiverUID}
IVAR +104 0 _cacheSize Q
IVAR +112 0 _estimatedCount Q
IVAR +120 0 _visited ^{__CFSet=}
CMETHOD _ui_archivedInterprocessDataWithRootObject:requiringSecureCoding:error: @36@0:8@16B24^@28
CMETHOD nr_secureArchiveRootObject:toFile: B32@0:8@16@24
CMETHOD nr_secureArchiveRootObject:toFile:withOptions: B40@0:8@16@24Q32
CMETHOD nr_secureArchivedDataWithRootObject: @24@0:8@16
CMETHOD initialize v16@0:8
CMETHOD archivedDataWithRootObject:requiringSecureCoding:error: @36@0:8@16B24^@28
CMETHOD archiveRootObject:toFile: B32@0:8@16@24
CMETHOD archivedDataWithRootObject: @24@0:8@16
CMETHOD classNameForClass: @24@0:8#16
CMETHOD setClassName:forClass: v32@0:8@16#24
METHOD _ui_isInterprocess B16@0:8
METHOD _ui_setIsInterprocess: v20@0:8B16
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD _encodePropertyList:forKey: v32@0:8@16@24
METHOD allowsKeyedCoding B16@0:8
METHOD delegate @16@0:8
METHOD encodeBool:forKey: v28@0:8B16@20
METHOD encodeBytes:length:forKey: v40@0:8r*16Q24@32
METHOD encodeInt32:forKey: v28@0:8i16@20
METHOD encodeInt64:forKey: v32@0:8q16@24
METHOD encodeObject:forKey: v32@0:8@16@24
METHOD replaceObject:withObject: v32@0:8@16@24
METHOD setDelegate: v24@0:8@16
METHOD encodeArrayOfObjCType:count:at: v40@0:8r*16Q24r^v32
METHOD encodeConditionalObject:forKey: v32@0:8@16@24
METHOD _allowsValueCoding B16@0:8
METHOD _blobForCurrentObject @16@0:8
METHOD _encodeArrayOfObjects:forKey: v32@0:8@16@24
METHOD _initWithOutput: @24@0:8@16
METHOD _setBlobForCurrentObject: v24@0:8@16
METHOD classNameForClass: @24@0:8#16
METHOD encodeBycopyObject: v24@0:8@16
METHOD encodeByrefObject: v24@0:8@16
METHOD encodeBytes:length: v32@0:8r^v16Q24
METHOD encodeConditionalObject: v24@0:8@16
METHOD encodeDataObject: v24@0:8@16
METHOD encodeDouble:forKey: v32@0:8d16@24
METHOD encodeFloat:forKey: v28@0:8f16@20
METHOD encodeInt:forKey: v28@0:8i16@20
METHOD encodeObject: v24@0:8@16
METHOD encodeRootObject: v24@0:8@16
METHOD encodeValueOfObjCType:at: v32@0:8r*16r^v24
METHOD encodeValuesOfObjCTypes: v24@0:8r*16
METHOD encodedData @16@0:8
METHOD finishEncoding v16@0:8
METHOD initForWritingWithMutableData: @24@0:8@16
METHOD initRequiringSecureCoding: @20@0:8B16
METHOD outputFormat Q16@0:8
METHOD requiresSecureCoding B16@0:8
METHOD setClassName:forClass: v32@0:8@16#24
METHOD setOutputFormat: v24@0:8Q16
METHOD setRequiresSecureCoding: v20@0:8B16
METHOD systemVersion I16@0:8
METHOD versionForClassName: q24@0:8@16

=== CLASS NSKeyedUnarchiver ===
SUPER: NSCoder
SIZE: 136
IVAR +8 0 _delegate @"<NSKeyedUnarchiverDelegate>"
IVAR +16 0 _flags AQ
IVAR +24 0 _objRefMap ^{__CFDictionary=}
IVAR +32 0 _replacementMap ^{__CFDictionary=}
IVAR +40 0 _nameClassMap ^{__CFDictionary=}
IVAR +48 0 _tmpRefObjMap ^{__CFDictionary=}
IVAR +56 0 _refObjMap ^{__CFDictionary=}
IVAR +64 0 _genericKey i
IVAR +72 0 _offsetData ^{?={?=[5C]CCCQQQ}QQ}
IVAR +80 0 _containers ^{__CFArray=}
IVAR +88 0 _objects ^{__CFArray=}
IVAR +96 0 _data ^{__CFData=}
IVAR +104 0 _bytes r*
IVAR +112 0 _len Q
IVAR +120 0 _helper @"_NSKeyedUnarchiverHelper"
IVAR +128 0 _offsetObjMap ^{__CFDictionary=}
CMETHOD ls_unarchivedObjectOfClass:fromData:error: @40@0:8#16@24^@32
CMETHOD ids_secureUnarchiveObjectOfClass:withData: @32@0:8#16@24
CMETHOD secureUnarchiveData:withExpectedClass:otherAllowedClasses: @40@0:8@16#24@32
CMETHOD _in_safeUnarchivedObjectOfClass:fromData:error: @40@0:8#16@24^@32
CMETHOD _in_safeUnarchivedObjectOfClasses:fromData:error: @40@0:8@16@24^@32
CMETHOD nr_secureUnarchiveObjectOfClasses:withData: @32@0:8@16@24
CMETHOD nr_secureUnarchiveObjectOfClasses:withFile: @32@0:8@16@24
CMETHOD initialize v16@0:8
CMETHOD unarchivedObjectOfClass:fromData:error: @40@0:8#16@24^@32
CMETHOD unarchivedObjectOfClasses:fromData:error: @40@0:8@16@24^@32
CMETHOD _copyByArchiving: @24@0:8@16
CMETHOD _evaluateCycleSecurityRules: B24@0:8^{NSKeyedUnarchiverCycleEvaluationRules=BBBBB}16
CMETHOD _strictlyUnarchivedObjectOfClasses:fromData:error: @40@0:8@16@24^@32
CMETHOD _swift_checkClassAndWarnForKeyedArchiving:operation: i28@0:8#16i24
CMETHOD classForClassName: #24@0:8@16
CMETHOD setClass:forClassName: v32@0:8#16@24
CMETHOD unarchiveObjectWithData: @24@0:8@16
CMETHOD unarchiveObjectWithData:error: @32@0:8@16^@24
CMETHOD unarchiveObjectWithFile: @24@0:8@16
CMETHOD unarchiveTopLevelObjectWithData:error: @32@0:8@16^@24
CMETHOD unarchivedArrayOfObjectsOfClass:fromData:error: @40@0:8#16@24^@32
CMETHOD unarchivedArrayOfObjectsOfClasses:fromData:error: @40@0:8@16@24^@32
CMETHOD unarchivedDictionaryWithKeysOfClass:objectsOfClass:fromData:error: @48@0:8#16#24@32^@40
CMETHOD unarchivedDictionaryWithKeysOfClasses:objectsOfClasses:fromData:error: @48@0:8@16@24@32^@40
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD allowedClasses @16@0:8
METHOD allowsKeyedCoding B16@0:8
METHOD decodeBytesForKey:returnedLength: r*32@0:8@16^Q24
METHOD decodeInt64ForKey: q24@0:8@16
METHOD decodeObjectOfClass:forKey: @32@0:8#16@24
METHOD decodeObjectOfClasses:forKey: @32@0:8@16@24
METHOD decodingFailurePolicy q16@0:8
METHOD delegate @16@0:8
METHOD error @16@0:8
METHOD replaceObject:withObject: v32@0:8@16@24
METHOD setDelegate: v24@0:8@16
METHOD __setError: v24@0:8@16
METHOD _enableStrictSecureDecodingMode v16@0:8
METHOD decodeArrayOfObjCType:count:at: v40@0:8r*16Q24^v32
METHOD initWithStream: @24@0:8@16
METHOD _allowDecodingCyclesInSecureMode v16@0:8
METHOD _allowedClassNames @16@0:8
METHOD _allowsValueCoding B16@0:8
METHOD _blobForCurrentObject @16@0:8
METHOD _containsNextUnkeyedObject B16@0:8
METHOD _currentUniqueIdentifier I16@0:8
METHOD _decodeArrayOfObjectsForKey: @24@0:8@16
METHOD _decodeObjectOfClass: @24@0:8#16
METHOD _decodePropertyListForKey: @24@0:8@16
METHOD _decodingCyclesIsAllowed B16@0:8
METHOD _enforceExplicitPlistTypes v16@0:8
METHOD _enforceSubclassesMustBeExplicitlyMentionedWhenDecoded v16@0:8
METHOD _initForReadingFromData:error:throwLegacyExceptions: @36@0:8@16^@24B32
METHOD _initWithStream:data:topDict: @40@0:8^{__CFReadStream=}16@24^{__CFDictionary=}32
METHOD _replaceObject:withObject: v32@0:8@16@24
METHOD _setAllowedClassNames: v24@0:8@16
METHOD _strictSecureDecodingEnabled B16@0:8
METHOD _temporaryMapReplaceObject:withObject: v32@0:8@16@24
METHOD _validateAllowedClassesContainsClass:forKey: B32@0:8#16@24
METHOD _validateAllowedClassesContainsClassOfReference:forKey: B32@0:8@16@24
METHOD _willEnforceExplicitPlistTypes B16@0:8
METHOD classForClassName: #24@0:8@16
METHOD containsValueForKey: B24@0:8@16
METHOD decodeArrayOfObjectsOfClasses:forKey: @32@0:8@16@24
METHOD decodeBoolForKey: B24@0:8@16
METHOD decodeBytesWithReturnedLength: ^v24@0:8^Q16
METHOD decodeDataObject @16@0:8
METHOD decodeDictionaryWithKeysOfClasses:objectsOfClasses:forKey: @40@0:8@16@24@32
METHOD decodeDoubleForKey: d24@0:8@16
METHOD decodeFloatForKey: f24@0:8@16
METHOD decodeInt32ForKey: i24@0:8@16
METHOD decodeIntForKey: i24@0:8@16
METHOD decodeObject @16@0:8
METHOD decodeObjectForKey: @24@0:8@16
METHOD decodeValueOfObjCType:at: v32@0:8r*16^v24
METHOD decodeValuesOfObjCTypes: v24@0:8r*16
METHOD finishDecoding v16@0:8
METHOD initForReadingFromData:error: @32@0:8@16^@24
METHOD initForReadingWithData: @24@0:8@16
METHOD requiresSecureCoding B16@0:8
METHOD setAllowedClasses: v24@0:8@16
METHOD setClass:forClassName: v32@0:8#16@24
METHOD setDecodingFailurePolicy: v24@0:8q16
METHOD setRequiresSecureCoding: v20@0:8B16
METHOD systemVersion I16@0:8
METHOD versionForClassName: q24@0:8@16

=== CLASS NSMapTable ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: NSCopying NSSecureCoding NSFastEnumeration
CMETHOD unownedToStrongObjectsMapTable @16@0:8
CMETHOD alloc @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD _subclassesMustBeExplicitlyMentionedWhenDecoded B16@0:8
CMETHOD supportsSecureCoding B16@0:8
CMETHOD mapTableWithWeakToStrongObjects @16@0:8
CMETHOD mapTableWithStrongToWeakObjects @16@0:8
CMETHOD mapTableWithKeyOptions:valueOptions: @32@0:8Q16Q24
CMETHOD mapTableWithStrongToStrongObjects @16@0:8
CMETHOD mapTableWithWeakToWeakObjects @16@0:8
CMETHOD strongToStrongObjectsMapTable @16@0:8
CMETHOD strongToWeakObjectsMapTable @16@0:8
CMETHOD weakToStrongObjectsMapTable @16@0:8
CMETHOD weakToWeakObjectsMapTable @16@0:8
METHOD bs_each: v24@0:8@?16
METHOD bs_filter: @24@0:8@?16
METHOD bs_safeObjectForKey:ofType: @32@0:8@16#24
METHOD bs_setSafeObject:forKey: v32@0:8@16@24
METHOD bs_takeObjectForKey: @24@0:8@16
METHOD CKFlatMap: @24@0:8@?16
METHOD scn_enumerateKeysAndValuesUsingBlock: v24@0:8@?16
METHOD vfx_enumerateKeysAndValuesUsingBlock: v24@0:8@?16
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD allKeys @16@0:8
METHOD allValues @16@0:8
METHOD classForCoder #16@0:8
METHOD count Q16@0:8
METHOD countByEnumeratingWithState:objects:count: Q40@0:8^{?=Q^@^Q[5Q]}16^@24Q32
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD keyEnumerator @16@0:8
METHOD objectEnumerator @16@0:8
METHOD objectForKey: @24@0:8@16
METHOD removeAllObjects v16@0:8
METHOD removeObjectForKey: v24@0:8@16
METHOD setObject:forKey: v32@0:8@16@24
METHOD setItem:forKey: v32@0:8r^v16r^v24
METHOD getKeys:values: Q32@0:8r^^v16r^^v24
METHOD __capacity Q16@0:8
METHOD dictionaryRepresentation @16@0:8
METHOD enumerator @16@0:8
METHOD existingItemForSetItem:forAbsentKey: ^v32@0:8r^v16r^v24
METHOD initWithKeyOptions:valueOptions:capacity: @40@0:8Q16Q24Q32
METHOD initWithKeyPointerFunctions:valuePointerFunctions:capacity: @40@0:8@16@24Q32
METHOD keyPointerFunctions @16@0:8
METHOD mapMember:originalKey:value: B40@0:8r^v16r^^v24r^^v32
METHOD mutableDictionary @16@0:8
METHOD removeAllItems v16@0:8
METHOD replaceItem:forExistingKey: v32@0:8r^v16r^v24
METHOD setItem:forAbsentKey: v32@0:8r^v16r^v24
METHOD setItem:forKnownAbsentKey: v32@0:8r^v16r^v24
METHOD valuePointerFunctions @16@0:8

=== CLASS NSMutableArray ===
SUPER: NSArray
SIZE: 8
PROTOCOLS: GEOComposedRouteStepTransitInstructionMerging
CMETHOD copyNonRetainingArray @16@0:8
CMETHOD nonRetainingArray @16@0:8
CMETHOD arrayWithCapacity: @24@0:8Q16
METHOD classForCoder #16@0:8
METHOD initWithContentsOfFile: @24@0:8@16
METHOD initWithContentsOfURL: @24@0:8@16
METHOD applyDifference: v24@0:8@16
METHOD filterUsingPredicate: v24@0:8@16
METHOD initWithContentsOfURL:error: @32@0:8@16^@24
METHOD removeObjectsFromIndices:numIndices: v32@0:8^Q16Q24
METHOD sortUsingDescriptors: v24@0:8@16
METHOD bs_safeAddObject: v24@0:8@16
METHOD _set_syncQueue: v24@0:8@16
METHOD _kb_reverse v16@0:8
METHOD _listContainsOrderedItems B16@0:8
METHOD _set_listContainsOrderedItems: v20@0:8B16
METHOD _syncQueue @16@0:8
METHOD _ui_dequeue @16@0:8
METHOD _ui_enqueue: v24@0:8@16
METHOD _ui_peek @16@0:8
METHOD _uikbrtInsert:after: v32@0:8@16@24
METHOD _uikbrtInsert:before: v32@0:8@16@24
METHOD _uikbrtInsert:beforeItemPassingTest: v32@0:8@16@?24
METHOD _uikbrtRemove: v24@0:8@16
METHOD removeViewsFromSuperview v16@0:8
METHOD VNInsertObservationWithConfidence:limitedToN:providedByBlock: v36@0:8f16Q20@?28
METHOD _geo_filter: v24@0:8@?16
METHOD _transit_hasAnyFieldSet B16@0:8
METHOD _transit_mergeFrom: v24@0:8@16
METHOD removeFirstObject v16@0:8
METHOD __imRandomizeArray v16@0:8
METHOD im_shuffle v16@0:8
METHOD popFirstObject @16@0:8
METHOD aa_removeFirstObject @16@0:8
METHOD aa_removeLastObject @16@0:8
METHOD un_safeAddObject:class: v32@0:8@16#24
METHOD un_safeAddObject:classes: v32@0:8@16@24
METHOD axSafelyAddObject: v24@0:8@16
METHOD axSafelyAddObjectsFromArray: v24@0:8@16
METHOD ax_dequeueObject @16@0:8
METHOD ax_enqueueObject: v24@0:8@16
METHOD ax_lastEnqueuedObject @16@0:8
METHOD ax_nextDequeuedObject @16@0:8
METHOD ax_removeObjectsFromArrayUsingBlock: v24@0:8@?16
METHOD fm_safeAddObject: v24@0:8@16
METHOD parent @16@0:8
METHOD push: v24@0:8@16
METHOD top @16@0:8
METHOD pop @16@0:8
METHOD addPart: v24@0:8@16
METHOD addImage:address:size: v40@0:8[16C]16Q24Q32
METHOD addImageLegacy:address:size:name:path:arch: v64@0:8[16C]16Q24Q32r*40r*48r*56
METHOD addJITImage:size: v32@0:8Q16Q24
METHOD section_pop @16@0:8
METHOD section_push: v24@0:8@16
METHOD sortByAddressAndSetInferredSizes v16@0:8
METHOD avt_applyPoseRoundingBehaviour v16@0:8
METHOD if_addObjectIfNonNil: v24@0:8@16
METHOD triMoveFirstItemToFrontPassingTest: B24@0:8@?16
METHOD triRemoveFirstItemPassingTest: B24@0:8@?16
METHOD aaf_removeFirstObject @16@0:8
METHOD aaf_removeLastObject @16@0:8
METHOD _mutate v16@0:8
METHOD addObjectsFromOrderedSet:range: v40@0:8@16{_NSRange=QQ}24
METHOD insertObjectsFromArray:atIndex: v32@0:8@16Q24
METHOD setSet: v24@0:8@16
METHOD addObject: v24@0:8@16
METHOD addObjects:count: v32@0:8r^@16Q24
METHOD addObjectsFromArray: v24@0:8@16
METHOD addObjectsFromArray:range: v40@0:8@16{_NSRange=QQ}24
METHOD addObjectsFromOrderedSet: v24@0:8@16
METHOD addObjectsFromSet: v24@0:8@16
METHOD arrayByAddingObjectsFromArray: @24@0:8@16
METHOD exchangeObjectAtIndex:withObjectAtIndex: v32@0:8Q16Q24
METHOD initWithCapacity: @24@0:8Q16
METHOD initWithObjects:count: @32@0:8r^@16Q24
METHOD insertObject:atIndex: v32@0:8@16Q24
METHOD insertObjects:atIndexes: v32@0:8@16@24
METHOD insertObjects:count:atIndex: v40@0:8r^@16Q24Q32
METHOD insertObjectsFromArray:range:atIndex: v48@0:8@16{_NSRange=QQ}24Q40
METHOD insertObjectsFromOrderedSet:atIndex: v32@0:8@16Q24
METHOD insertObjectsFromOrderedSet:range:atIndex: v48@0:8@16{_NSRange=QQ}24Q40
METHOD insertObjectsFromSet:atIndex: v32@0:8@16Q24
METHOD moveObjectsAtIndexes:toIndex: v32@0:8@16Q24
METHOD removeAllObjects v16@0:8
METHOD removeFirstObject v16@0:8
METHOD removeLastObject v16@0:8
METHOD removeObject: v24@0:8@16
METHOD removeObject:inRange: v40@0:8@16{_NSRange=QQ}24
METHOD removeObjectAtIndex: v24@0:8Q16
METHOD removeObjectIdenticalTo: v24@0:8@16
METHOD removeObjectIdenticalTo:inRange: v40@0:8@16{_NSRange=QQ}24
METHOD removeObjectsAtIndexes: v24@0:8@16
METHOD removeObjectsAtIndexes:options:passingTest: v40@0:8@16Q24@?32
METHOD removeObjectsInArray: v24@0:8@16
METHOD removeObjectsInArray:range: v40@0:8@16{_NSRange=QQ}24
METHOD removeObjectsInOrderedSet: v24@0:8@16
METHOD removeObjectsInOrderedSet:range: v40@0:8@16{_NSRange=QQ}24
METHOD removeObjectsInRange: v32@0:8{_NSRange=QQ}16
METHOD removeObjectsInRange:inArray: v40@0:8{_NSRange=QQ}16@32
METHOD removeObjectsInRange:inArray:range: v56@0:8{_NSRange=QQ}16@32{_NSRange=QQ}40
METHOD removeObjectsInRange:inOrderedSet: v40@0:8{_NSRange=QQ}16@32
METHOD removeObjectsInRange:inOrderedSet:range: v56@0:8{_NSRange=QQ}16@32{_NSRange=QQ}40
METHOD removeObjectsInRange:inSet: v40@0:8{_NSRange=QQ}16@32
METHOD removeObjectsInSet: v24@0:8@16
METHOD removeObjectsPassingTest: v24@0:8@?16
METHOD removeObjectsWithOptions:passingTest: v32@0:8Q16@?24
METHOD replaceObject: v24@0:8@16
METHOD replaceObject:inRange: v40@0:8@16{_NSRange=QQ}24
METHOD replaceObjectAtIndex:withObject: v32@0:8Q16@24
METHOD replaceObjectsAtIndexes:withObjects: v32@0:8@16@24
METHOD replaceObjectsInRange:withObjects:count: v48@0:8{_NSRange=QQ}16r^@32Q40
METHOD replaceObjectsInRange:withObjectsFromArray: v40@0:8{_NSRange=QQ}16@32
METHOD replaceObjectsInRange:withObjectsFromArray:range: v56@0:8{_NSRange=QQ}16@32{_NSRange=QQ}40
METHOD replaceObjectsInRange:withObjectsFromOrderedSet: v40@0:8{_NSRange=QQ}16@32
METHOD replaceObjectsInRange:withObjectsFromOrderedSet:range: v56@0:8{_NSRange=QQ}16@32{_NSRange=QQ}40
METHOD replaceObjectsInRange:withObjectsFromSet: v40@0:8{_NSRange=QQ}16@32
METHOD setArray: v24@0:8@16
METHOD setObject:atIndex: v32@0:8@16Q24
METHOD setObject:atIndexedSubscript: v32@0:8@16Q24
METHOD setOrderedSet: v24@0:8@16
METHOD sortRange:options:usingComparator: v48@0:8{_NSRange=QQ}16Q32@?40
METHOD sortUsingComparator: v24@0:8@?16
METHOD sortUsingFunction:context: v32@0:8^?16^v24
METHOD sortUsingFunction:context:range: v48@0:8^?16^v24{_NSRange=QQ}32
METHOD sortUsingSelector: v24@0:8:16
METHOD sortWithOptions:usingComparator: v32@0:8Q16@?24
METHOD sortedArrayFromRange:options:usingComparator: @48@0:8{_NSRange=QQ}16Q32@?40

=== CLASS NSMutableDictionary ===
SUPER: NSDictionary
SIZE: 8
CMETHOD _dictionaryWithContentsOfDictionaries: @24@0:8@16
CMETHOD nonRetainingDictionary @16@0:8
CMETHOD nonRetainingKeyAndValueDictionary @16@0:8
CMETHOD retainingKeyDictionary @16@0:8
CMETHOD MI_dictionaryWithContentsOfURL:options:error: @40@0:8@16Q24^@32
CMETHOD dictionaryWithCapacity: @24@0:8Q16
CMETHOD dictionaryWithSharedKeySet: @24@0:8@16
METHOD classForCoder #16@0:8
METHOD initWithContentsOfFile: @24@0:8@16
METHOD initWithContentsOfURL: @24@0:8@16
METHOD __swift_setObject:forKeyedSubscript: v32@0:8@16@24
METHOD __swift_objectForKeyedSubscript: @24@0:8@16
METHOD _web_setBool:forKey: v28@0:8B16@20
METHOD _web_setInt:forKey: v28@0:8i16@20
METHOD _web_setObject:forUncopiedKey: v32@0:8@16@24
METHOD initWithContentsOfURL:error: @32@0:8@16^@24
METHOD setValue:forKey: v32@0:8@16@24
METHOD MCFilterRestrictionPayloadKeys: v24@0:8@16
METHOD MCDeepCopyMissingEntriesFromDictionary: v24@0:8@16
METHOD MCDeleteBoolRestriction: v24@0:8@16
METHOD MCFilterOutRestrictionPayloadKeys: v24@0:8@16
METHOD MCMutableDictionaryContainingValidatedKeysAndClasses:removeKeys:outError: @36@0:8@16B24^@28
METHOD MCSetBoolRestriction:value: v28@0:8@16B24
METHOD MCSetIntersectionSetting:values: v32@0:8@16@24
METHOD MCSetUnionRestriction:values: v32@0:8@16@24
METHOD MCSetValueRestriction:value: v32@0:8@16@24
METHOD MCValidateAndRemoveArrayOfClass:withKey:isRequired:allowZeroLengthString:outError: @48@0:8#16@24B32B36^@40
METHOD MCValidateAndRemoveNonZeroLengthStringWithKey:isRequired:outError: @36@0:8@16B24^@28
METHOD MCDeepCopyEntriesFromDictionary: v24@0:8@16
METHOD MCFixUpRestrictionsDictionaryForMDMReporting v16@0:8
METHOD MCSanitizeRestrictions v16@0:8
METHOD MCSetIntersectionRestriction:values: v32@0:8@16@24
METHOD MCSetObjectIfNotNil:forKey: v32@0:8@16@24
METHOD MCSetUnionSetting:values: v32@0:8@16@24
METHOD MCValidateAndRemoveArrayOfClass:withKey:isRequired:outError: @44@0:8#16@24B32^@36
METHOD MCValidateAndRemoveObjectOfClass:withKey:isRequired:outError: @44@0:8#16@24B32^@36
METHOD _MCFilterRestrictionPayloadKeys:filterOut: v28@0:8@16B24
METHOD bs_addObject:toCollectionClass:forKey: v40@0:8@16#24@32
METHOD bs_removeObject:fromCollectionForKey: v32@0:8@16@24
METHOD bs_setSafeObject:forKey: v32@0:8@16@24
METHOD bs_takeObjectForKey: @24@0:8@16
METHOD CKSynchronizedSetIfAbsentObject:forKey: B32@0:8@16@24
METHOD CKAddPropertySafelyForKey:value: v32@0:8@16@24
METHOD CKSynchronizedCount Q16@0:8
METHOD CKSynchronizedRemoveObjectForKey: v24@0:8@16
METHOD aa_removeObjectForKey: @24@0:8@16
METHOD un_safeSetObject:forKey: v32@0:8@16@24
METHOD axSafelyAddEntriesFromDictionary: v24@0:8@16
METHOD intents_setArrayOfWidgetPlistRepresentable:forKey:error: v40@0:8@16@24^@32
METHOD intents_setArrayOfWidgetPlistRepresentable:forKey:parameters:error: v48@0:8@16@24@32^@40
METHOD intents_setBoolIfTrue:forKey: v28@0:8B16@20
METHOD intents_setIntegerIfNonZero:forKey: v32@0:8q16@24
METHOD intents_setPlistSafeObject:forKey: v32@0:8@16@24
METHOD intents_setWidgetPlistRepresentable:forKey:error: v40@0:8@16@24^@32
METHOD intents_setWidgetPlistRepresentable:forKey:parameters:error: v48@0:8@16@24@32^@40
METHOD _createOrConvertToMutableDictionaryFromDictionary: @24@0:8@16
METHOD _mutableDictionaryAtKeyPath: @24@0:8@16
METHOD _overlayCustomValueAtKeyPath:intoTargetDictionary:fromSourceDictionary:handler: v48@0:8@16@24@32@?40
METHOD _overlayValueAtKey:intoTargetDictionary:fromSourceDictionary:targetTakePrecedent:nestedDictionaryHandler: v52@0:8@16@24@32B40@?44
METHOD pk_overlayDictionary:existingValuesTakePrecedent:exceptKeyPaths:exemptionHandler: v44@0:8@16B24@28@?36
METHOD pk_removeItemsAtKeyPaths: v24@0:8@16
METHOD _pas_setObject:forNonCopiedKey: v32@0:8@16@24
METHOD _processAdditionalInfo:forFilterInFiltersArray: v32@0:8@16@24
METHOD setAverageColorEnabled:includingOptimizations:withAdditionalInfoPromise: v32@0:8B16B20@?24
METHOD setBlurRadius:inputMaskImage:ignoringIdentity:includingOptimizations:withAdditionalInfoPromise: v48@0:8d16^{CGImage=}24B32B36@?40
METHOD setBrightness:ignoringIdentity:includingOptimizations:withAdditionalInfoPromise: v40@0:8d16B24B28@?32
METHOD setColorMatrix:ignoringIdentity:includingOptimizations:withAdditionalInfoPromise: v112@0:8{CAColorMatrix=ffffffffffffffffffff}16B96B100@?104
METHOD setCurvesInputValues:ignoringIdentity:includingOptimizations:withAdditionalInfoPromise: v40@0:8@16B24B28@?32
METHOD setLuminanceAmount:values:ignoringIdentity:includingOptimizations:withAdditionalInfoPromise: v48@0:8d16@24B32B36@?40
METHOD setSaturation:ignoringIdentity:includingOptimizations:withAdditionalInfoPromise: v40@0:8d16B24B28@?32
METHOD setTintColor:includingOptimizations:withAdditionalInfoPromise: v36@0:8@16B24@?28
METHOD setValue:forProperty:ofFilter:isCompositingFilter: v44@0:8@16@24@32B40
METHOD setValue:forProperty:ofFilterInFiltersArray: v40@0:8@16@24@32
METHOD setZoom:ignoringIdentity:includingOptimizations:withAdditionalInfoPromise: v40@0:8d16B24B28@?32
METHOD sortFiltersWithOrder: v24@0:8@16
METHOD safelySetObject:forKey: v32@0:8@16@24
METHOD fm_objectForKey:withDefaultValue: @32@0:8@16@?24
METHOD fm_safeSetObject:forKey: v32@0:8@16@24
METHOD fm_safelyMapKey:toObject: v32@0:8@16@24
METHOD fm_safelySetObject:forKey: v32@0:8@16@24
METHOD safelyMapKey:toObject: v32@0:8@16@24
METHOD osa_logTracker_shouldRotateLog: B24@0:8@16
METHOD addTurnstileInfoDesc:count:elSize: v32@0:8r^v16I24I28
METHOD addWaitInfoDesc:count:elSize: v32@0:8r^v16I24I28
METHOD osa_logTracker_getForSubtype:forOwner: Q32@0:8@16@24
METHOD osa_logTracker_incrementForSubtype:signature:filepath: v40@0:8@16@24r*32
METHOD osa_logTracker_incrementForSubtype_internal:signature:filepath:scan: v44@0:8@16@24r*32B40
METHOD osa_logTracker_isLog:byKey:count:withinLimit:withOptions:errorDescription: B64@0:8@16@24^Q32^Q40@48^@56
METHOD osa_logTracker_recordNixedDuplicate: v24@0:8r*16
METHOD osa_logTracker_trackLogTypes_internal:forOwner:rescan: v36@0:8@16@24B32
METHOD parsePortLabelContainer: v32@0:8{kcdata_iter=^{kcdata_item}^v}16
METHOD avt_applyPoseRoundingBehaviour v16@0:8
METHOD _OS_overlayDictionary: v24@0:8@16
METHOD if_setBoolIfYES:forKey: v28@0:8B16@20
METHOD if_setObjectIfNonNil:forKey: v32@0:8@16@24
METHOD if_popObjectForKey: @24@0:8@16
METHOD aaf_removeObjectForKey: @24@0:8@16
METHOD mfo_addEntriesFromDictionaryWithRecursion: v24@0:8@16
METHOD DMCSetObjectIfNotNil:forKey: v32@0:8@16@24
METHOD setSafeObject:forKey: v32@0:8@16@24
METHOD _mutate v16@0:8
METHOD __addObject:forKey: v32@0:8@16@24
METHOD __setObject:forKey: v32@0:8@16@24
METHOD addEntriesFromDictionary: v24@0:8@16
METHOD addObject:forKey: v32@0:8@16@24
METHOD addObjects:forKeys: v32@0:8@16@24
METHOD addObjects:forKeys:count: v40@0:8r^@16r^@24Q32
METHOD initWithCapacity: @24@0:8Q16
METHOD initWithObjects:forKeys:count: @40@0:8r^@16r^@24Q32
METHOD invert v16@0:8
METHOD removeAllObjects v16@0:8
METHOD removeEntriesInDictionary: v24@0:8@16
METHOD removeEntriesPassingTest: v24@0:8@?16
METHOD removeEntriesWithOptions:passingTest: v32@0:8Q16@?24
METHOD removeKeysForObject: v24@0:8@16
METHOD removeObjectForKey: v24@0:8@16
METHOD removeObjectsForKeys: v24@0:8@16
METHOD replaceObject:forKey: v32@0:8@16@24
METHOD replaceObjects:forKeys: v32@0:8@16@24
METHOD replaceObjects:forKeys:count: v40@0:8r^@16r^@24Q32
METHOD setDictionary: v24@0:8@16
METHOD setEntriesFromDictionary: v24@0:8@16
METHOD setObject:forKey: v32@0:8@16@24
METHOD setObject:forKeyedSubscript: v32@0:8@16@24
METHOD setObjects:forKeys: v32@0:8@16@24
METHOD setObjects:forKeys:count: v40@0:8r^@16r^@24Q32

=== CLASS NSMutableSet ===
SUPER: NSSet
SIZE: 8
CMETHOD nonRetainingSet @16@0:8
CMETHOD setWithCapacity: @24@0:8Q16
METHOD classForCoder #16@0:8
METHOD filterUsingPredicate: v24@0:8@16
METHOD bs_safeAddObject: v24@0:8@16
METHOD CKSynchronizedAddIfAbsent: B24@0:8@16
METHOD CKSynchronizedRemoveObject: v24@0:8@16
METHOD CKSynchronizedCount Q16@0:8
METHOD _geo_filter: v24@0:8@?16
METHOD axSafelyAddObject: v24@0:8@16
METHOD axSafelyAddObjectsFromArray: v24@0:8@16
METHOD ax_replaceWithMatchingObject:updatingWithBlock: v32@0:8@16@?24
METHOD fm_safeAddObject: v24@0:8@16
METHOD if_addObjectIfNonNil: v24@0:8@16
METHOD _mutate v16@0:8
METHOD addObjectsFromOrderedSet:range: v40@0:8@16{_NSRange=QQ}24
METHOD setSet: v24@0:8@16
METHOD addObject: v24@0:8@16
METHOD addObjects:count: v32@0:8r^@16Q24
METHOD addObjectsFromArray: v24@0:8@16
METHOD addObjectsFromArray:range: v40@0:8@16{_NSRange=QQ}24
METHOD addObjectsFromOrderedSet: v24@0:8@16
METHOD addObjectsFromSet: v24@0:8@16
METHOD initWithCapacity: @24@0:8Q16
METHOD initWithObjects:count: @32@0:8r^@16Q24
METHOD intersectOrderedSet: v24@0:8@16
METHOD intersectSet: v24@0:8@16
METHOD minusOrderedSet: v24@0:8@16
METHOD minusSet: v24@0:8@16
METHOD removeAllObjects v16@0:8
METHOD removeObject: v24@0:8@16
METHOD removeObjectsInArray: v24@0:8@16
METHOD removeObjectsInArray:range: v40@0:8@16{_NSRange=QQ}24
METHOD removeObjectsInOrderedSet: v24@0:8@16
METHOD removeObjectsInOrderedSet:range: v40@0:8@16{_NSRange=QQ}24
METHOD removeObjectsInSet: v24@0:8@16
METHOD removeObjectsPassingTest: v24@0:8@?16
METHOD removeObjectsWithOptions:passingTest: v32@0:8Q16@?24
METHOD replaceObject: v24@0:8@16
METHOD setArray: v24@0:8@16
METHOD setByAddingObjectsFromArray: @24@0:8@16
METHOD setByAddingObjectsFromSet: @24@0:8@16
METHOD setObject: v24@0:8@16
METHOD setOrderedSet: v24@0:8@16
METHOD unionOrderedSet: v24@0:8@16
METHOD unionSet: v24@0:8@16

=== CLASS NSMutableString ===
SUPER: NSString
SIZE: 8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD _subclassesMustBeExplicitlyMentionedWhenDecoded B16@0:8
CMETHOD stringWithCapacity: @24@0:8Q16
METHOD appendPrettyBOOL:withName:indent: v32@0:8B16@20i28
METHOD appendPrettyInt:withName:indent: v32@0:8i16@20i28
METHOD appendPrettyObject:withName:indent:showFullContent: v40@0:8@16@24i32B36
METHOD replaceNewlinesWithSpaces v16@0:8
METHOD _removeCharactersFromSet: v24@0:8^{__CFCharacterSet=}16
METHOD _removeOccurrencesOfCharacter: v20@0:8I16
METHOD _replaceOccurrencesOfCharacter:withCharacter: v24@0:8I16I20
METHOD appendPrettyBOOL:withName:andIndent:options: v40@0:8B16@20i28Q32
METHOD appendPrettyHex:withName:andIndent:options: v44@0:8q16@24i32Q36
METHOD appendPrettyInt:withName:andIndent:options: v44@0:8q16@24i32Q36
METHOD appendPrettyObject:withName:andIndent:options: v44@0:8@16@24i32Q36
METHOD appendToStringAtColumnWithContent:column:content:appendAsNewLine:addNewLine: v44@0:8^i16C24r*28B36B40
METHOD dd_appendSpaces: v20@0:8I16
METHOD appendPortLabelInfo:portlabels: v28@0:8i16@20
METHOD applyRegex:withReplacementTemplate: @32@0:8@16@?24
METHOD VisionCore_appendPaddingCharacter:toMinimumLength: v28@0:8S16Q20
METHOD VisionCore_prependPaddingCharacter:toMinimumLength: v28@0:8S16Q20
METHOD _cfAppendCString:length: v32@0:8r*16q24
METHOD _cfLowercase: v24@0:8r^v16
METHOD _cfNormalize: v24@0:8q16
METHOD _cfPad:length:padIndex: v32@0:8^{__CFString=}16I24I28
METHOD _cfTrim: v24@0:8^{__CFString=}16
METHOD _cfCapitalize: v24@0:8r^v16
METHOD _cfTrimWS v16@0:8
METHOD _cfUppercase: v24@0:8r^v16
METHOD appendCharacters:length: v32@0:8r^S16Q24
METHOD appendFormat: v24@0:8@16
METHOD appendString: v24@0:8@16
METHOD classForCoder #16@0:8
METHOD deleteCharactersInRange: v32@0:8{_NSRange=QQ}16
METHOD initWithCapacity: @24@0:8Q16
METHOD insertString:atIndex: v32@0:8@16Q24
METHOD replaceCharactersInRange:withString: v40@0:8{_NSRange=QQ}16@32
METHOD replaceOccurrencesOfString:withString:options:range: Q56@0:8@16@24Q32{_NSRange=QQ}40
METHOD setString: v24@0:8@16
METHOD _replaceOccurrencesOfRegularExpressionPattern:withTemplate:options:range: Q56@0:8@16@24Q32{_NSRange=QQ}40
METHOD _trimWithCharacterSet: v24@0:8@16
METHOD applyTransform:reverse:range:updatedRange: B52@0:8@16B24{_NSRange=QQ}28^{_NSRange=QQ}44
METHOD replaceCharactersInRange:withCString:length: v48@0:8{_NSRange=QQ}16r*32Q40
METHOD replaceCharactersInRange:withCharacters:length: v48@0:8{_NSRange=QQ}16r^S32Q40
METHOD replacementObjectForPortCoder: @24@0:8@16

=== CLASS NSNotificationCenter ===
SUPER: NSObject
SIZE: 32
IVAR +8 0 _impl ^{__CFNotificationCenter=}
IVAR +16 0 actorQueueManagerLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +24 0 _actorQueueManager @"_NotificationCenterActorQueueManager"
CMETHOD uikitCenter @16@0:8
CMETHOD load v16@0:8
CMETHOD _defaultCenterWithoutCreating @16@0:8
CMETHOD defaultCenter @16@0:8
METHOD postNotificationName: v24@0:8@16
METHOD __mainThreadPostNotification: v24@0:8@16
METHOD __mainThreadPostNotificationName:object: v32@0:8@16@24
METHOD __mainThreadPostNotificationName:object:userInfo: v40@0:8@16@24@32
METHOD dealloc v16@0:8
METHOD debugDescription @16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD isEmpty B16@0:8
METHOD removeObserver: v24@0:8@16
METHOD _addObserver:selector:name:object:options: Q56@0:8@16:24@32@40Q48
METHOD _addObserver:object:usingBlock: Q40@0:8@16@24@?32
METHOD _addObserverForName:object:queue:usingBlock: @48@0:8@16@24@32@?40
METHOD _getActorQueueManager @16@0:8
METHOD _initWithCFNotificationCenter: @24@0:8^{__CFNotificationCenter=}16
METHOD _removeObserver: v24@0:8Q16
METHOD _removeObserver:performSubclassCheck: v28@0:8Q16B24
METHOD addObserver:selector:name:object: v48@0:8@16:24@32@40
METHOD addObserverForName:object:queue:usingBlock: @48@0:8@16@24@32@?40
METHOD postNotification: v24@0:8@16
METHOD postNotificationName:object: v32@0:8@16@24
METHOD postNotificationName:object:userInfo: v40@0:8@16@24@32
METHOD removeObserver:name:object: v40@0:8@16@24@32

=== CLASS NSNull ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: CAAction CSCoderEncoder PQLBindable BMDSLNativeJSONArchiving CCDatabaseValue NSCopying NSSecureCoding
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
CMETHOD bmdsl_nativeSupportForEncodingAsJSON v16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD null @16@0:8
CMETHOD supportsSecureCoding B16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD valueForKey: @24@0:8@16
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD cksqlcs_bindBlob:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_bindInt64:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_bindText:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD runActionForKey:object:arguments: v40@0:8@16@24@32
METHOD CAMLType @16@0:8
METHOD _intents_readableTitleWithLocalizer:metadata: @32@0:8@16@24
METHOD encodeWithCSCoder: v24@0:8@16
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD databaseValue_toData @16@0:8
METHOD databaseValue_toNumber @16@0:8
METHOD databaseValue_toString @16@0:8
METHOD databaseValue_type q16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD autorelease @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD _cfTypeID Q16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16

=== CLASS NSNumber ===
SUPER: NSValue
SIZE: 8
PROTOCOLS: RBSProcessIdentifier NSFetchRequestResult CKRecordValue CUByteCodable INJSONSerializable INCodableAttributeRelationComparing _PASDistilledString PQLValuable _OSXPCObjectRepresentable BMDSLNativeJSONArchiving CCDatabaseValue
CMETHOD modelOriginNumberFromUserDefinedDictionary: @24@0:8@16
CMETHOD createWithBytesNoCopy:length:error: @40@0:8^v16Q24^@32
CMETHOD _intents_decodeWithJSONDecoder:codableDescription:from: @40@0:8@16@24@32
CMETHOD _pas_intBackedFloatNumber: @20@0:8f16
CMETHOD newFromSqliteStatement:atIndex: @28@0:8^{sqlite3_stmt=}16i24
CMETHOD newFromSqliteValue: @24@0:8^{sqlite3_value=}16
CMETHOD avt_numberWithFloat:roundingBehavior: @28@0:8f16@20
CMETHOD bmdsl_nativeSupportForEncodingAsJSON v16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD initialize v16@0:8
CMETHOD numberWithBool: @20@0:8B16
CMETHOD numberWithDouble: @24@0:8d16
CMETHOD numberWithLongLong: @24@0:8q16
CMETHOD numberWithUnsignedChar: @20@0:8C16
CMETHOD supportsSecureCoding B16@0:8
CMETHOD numberWithChar: @20@0:8c16
CMETHOD numberWithLong: @24@0:8q16
CMETHOD numberWithFloat: @20@0:8f16
CMETHOD numberWithInt: @20@0:8i16
CMETHOD numberWithInteger: @24@0:8q16
CMETHOD numberWithShort: @20@0:8s16
CMETHOD numberWithUnsignedInt: @20@0:8I16
CMETHOD numberWithUnsignedInteger: @24@0:8Q16
CMETHOD numberWithUnsignedLong: @24@0:8Q16
CMETHOD numberWithUnsignedLongLong: @24@0:8Q16
CMETHOD numberWithUnsignedShort: @20@0:8S16
METHOD matchesProcess: B24@0:8@16
METHOD rbs_pid i16@0:8
METHOD processPredicate @16@0:8
METHOD bs_CGFloatValue d16@0:8
METHOD br_isEqualToNumber: B24@0:8@16
METHOD br_round: @20@0:8I16
METHOD br_roundedLongLongValue q16@0:8
METHOD CKRoundedToMaximumDecimalPlaces: @24@0:8Q16
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD cksqlcs_appendSQLConstantValueToString: @24@0:8@16
METHOD cksqlcs_bindValue:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_doubleBindingValue: d24@0:8^@16
METHOD cksqlcs_int64BindingValue: q24@0:8^@16
METHOD localizedString @16@0:8
METHOD encodedBytesAndReturnLength:error: r*32@0:8^Q16^@24
METHOD encodedDataAndReturnError: @24@0:8^@16
METHOD CA_addValue:multipliedBy: @28@0:8@16i24
METHOD CA_distanceToValue: d24@0:8@16
METHOD CA_numericValueCount Q16@0:8
METHOD CA_interpolateValue:byFraction: @28@0:8@16f24
METHOD CA_copyRenderValue ^{Object=^^?{Atomic={?=i}}b8b24}16@0:8
METHOD CA_interpolateValues:::interpolator: @48@0:8@16@24@32r^{ValueInterpolator=ddddddddddddddB}40
METHOD CAMLType @16@0:8
METHOD CA_copyNumericValue: Q24@0:8^d16
METHOD CA_roundToIntegerFromValue: @24@0:8@16
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD _axDictionaryKeyReplacementRepresentation @16@0:8
METHOD _axReconstitutedRepresentationForDictionaryKeyReplacement @16@0:8
METHOD _axRecursivelyPropertyListCoercedRepresentationWithError: @24@0:8^@16
METHOD _axRecursivelyReconstitutedRepresentationFromPropertyListWithError: @24@0:8^@16
METHOD ak_booleanAsInteger @16@0:8
METHOD ak_bucketWithSize: q24@0:8q16
METHOD ak_isBoolean B16@0:8
METHOD _intents_compareValue:relation: B32@0:8@16Q24
METHOD _intents_encodeWithJSONEncoder:codableDescription: @32@0:8@16@24
METHOD _intents_isDouble B16@0:8
METHOD _intents_isInteger B16@0:8
METHOD _intents_readableTitleWithLocalizer:metadata: @32@0:8@16@24
METHOD _pas_intBackedFloatValue f16@0:8
METHOD _pas_revivedString @16@0:8
METHOD fm_isEqualToNumber:withPrecision: B32@0:8@16d24
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD avt_numberByRoundingWithBehavior: @24@0:8@16
METHOD _OS_xpcObjectRepresentation @16@0:8
METHOD databaseValue_doubleRepresentation d16@0:8
METHOD databaseValue_integerRepresentation q16@0:8
METHOD databaseValue_toData @16@0:8
METHOD databaseValue_toNumber @16@0:8
METHOD databaseValue_toString @16@0:8
METHOD databaseValue_type q16@0:8
METHOD asVisionCoreTensorDataType Q16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD isEqual: B24@0:8@16
METHOD initWithDouble: @24@0:8d16
METHOD charValue c16@0:8
METHOD doubleValue d16@0:8
METHOD floatValue f16@0:8
METHOD initWithChar: @20@0:8c16
METHOD initWithInt: @20@0:8i16
METHOD initWithLong: @24@0:8q16
METHOD initWithLongLong: @24@0:8q16
METHOD initWithShort: @20@0:8s16
METHOD initWithUnsignedChar: @20@0:8C16
METHOD initWithUnsignedInt: @20@0:8I16
METHOD initWithUnsignedLongLong: @24@0:8Q16
METHOD initWithUnsignedShort: @20@0:8S16
METHOD intValue i16@0:8
METHOD isNSNumber__ B16@0:8
METHOD longLongValue q16@0:8
METHOD longValue q16@0:8
METHOD shortValue s16@0:8
METHOD unsignedCharValue C16@0:8
METHOD unsignedIntValue I16@0:8
METHOD unsignedLongLongValue Q16@0:8
METHOD unsignedLongValue Q16@0:8
METHOD unsignedShortValue S16@0:8
METHOD _cfTypeID Q16@0:8
METHOD _cfNumberType q16@0:8
METHOD _getCString:length:multiplier: B36@0:8*16i24d28
METHOD _getValue:forType: C32@0:8^v16q24
METHOD _reverseCompare: q24@0:8@16
METHOD boolValue B16@0:8
METHOD classForCoder #16@0:8
METHOD compare: q24@0:8@16
METHOD descriptionWithLocale: @24@0:8@16
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD integerValue q16@0:8
METHOD isEqualToNumber: B24@0:8@16
METHOD redactedDescription @16@0:8
METHOD stringValue @16@0:8
METHOD unsignedIntegerValue Q16@0:8
METHOD _allowsDirectEncoding B16@0:8
METHOD decimalValue {?=b8b4b1b1b18[8S]}16@0:8
METHOD initWithBool: @20@0:8B16
METHOD initWithFloat: @20@0:8f16
METHOD initWithInteger: @24@0:8q16
METHOD initWithUnsignedInteger: @24@0:8Q16
METHOD initWithUnsignedLong: @24@0:8Q16

=== CLASS NSObject ===
SUPER: none
SIZE: 8
PROTOCOLS: VNComputeDeviceTypeProviding VNComputeDevicePerformanceScoreProviding CAAnimatableValue CARenderValue INEnumerable INCodableAttributeRelationComparing PQLResultSetInitializer CRComputeDeviceTypeProviding SwiftUI.PlatformAccessibilityElementProtocol NSObject
IVAR +0 0 isa #
CMETHOD dealloc v16@0:8
CMETHOD description @16@0:8
CMETHOD doesNotRecognizeSelector: v24@0:8:16
CMETHOD init @16@0:8
CMETHOD instanceMethodSignatureForSelector: @24@0:8:16
CMETHOD load v16@0:8
CMETHOD methodSignatureForSelector: @24@0:8:16
CMETHOD __allocWithZone_OA: @24@0:8^{_NSZone=}16
CMETHOD _copyDescription @16@0:8
CMETHOD __old_unswizzled_keyPathsForValuesAffectingValueForKey: @24@0:8@16
CMETHOD __old_unswizzled_automaticallyNotifiesObserversForKey: B24@0:8@16
CMETHOD _localClassNameForClass r*16@0:8
CMETHOD instanceMethodDescriptionForSelector: ^{objc_method_description=:*}24@0:8:16
CMETHOD methodDescriptionForSelector: ^{objc_method_description=:*}24@0:8:16
CMETHOD accessInstanceVariablesDirectly B16@0:8
CMETHOD _createMutableArrayValueGetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createMutableOrderedSetValueGetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createMutableSetValueGetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createOtherValueGetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createOtherValueSetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createValueGetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createValuePrimitiveGetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createValuePrimitiveSetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD _createValueSetterWithContainerClassID:key: @32@0:8@16@24
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
CMETHOD _keysForValuesAffectingValueForKey: @24@0:8@16
CMETHOD keyPathsForValuesAffectingValueForKey: @24@0:8@16
CMETHOD setKeys:triggerChangeNotificationsForDependentKey: v32@0:8@16@24
CMETHOD _shouldAddObservationForwardersForKey: B24@0:8@16
CMETHOD classFallbacksForKeyedArchiver @16@0:8
CMETHOD classForKeyedUnarchiver #16@0:8
CMETHOD load v16@0:8
CMETHOD version q16@0:8
CMETHOD implementsSelector: B24@0:8:16
CMETHOD instancesImplementSelector: B24@0:8:16
CMETHOD setVersion: v24@0:8q16
CMETHOD cancelPreviousPerformRequestsWithTarget: v24@0:8@16
CMETHOD cancelPreviousPerformRequestsWithTarget:selector:object: v40@0:8@16:24@32
CMETHOD replacementObjectForPortCoder: @24@0:8@16
CMETHOD SFSQLiteClassName @16@0:8
CMETHOD supportsRBSXPCSecureCoding B16@0:8
CMETHOD bs_isPlistableType B16@0:8
CMETHOD bs_isXPCObject B16@0:8
CMETHOD bs_secureDataFromObject: @24@0:8@16
CMETHOD bs_secureDecodedFromData: @24@0:8@16
CMETHOD bs_secureDecodedFromData:withAdditionalClasses: @32@0:8@16@24
CMETHOD bs_secureObjectFromData:ofClass: @32@0:8@16#24
CMETHOD bs_secureObjectFromData:ofClasses: @32@0:8@16@24
CMETHOD supportedCodings @16@0:8
CMETHOD supportsBSXPCSecureCoding B16@0:8
CMETHOD __accessibilityGuidedAccessRestrictionStateForIdentifier: q24@0:8@16
CMETHOD __accessibilityGuidedAccessStateEnabled B16@0:8
CMETHOD __accessibilityRequestGuidedAccessSession:completion: v28@0:8B16@?20
CMETHOD _installAppearanceSwizzlesForSetter: v24@0:8@16
CMETHOD _ui_normalizedTextRangesFromTextRanges: @24@0:8@16
CMETHOD _ui_textRanges:equalToTextRanges: B32@0:8@16@24
CMETHOD brc_swizzleInstanceMethod:with: B32@0:8:16:24
CMETHOD brc_swizzleClassMethod:with: B32@0:8:16:24
CMETHOD brc_swizzleClassMethod:with:newSel: B40@0:8:16#24:32
CMETHOD brc_swizzleClassMethod:with:newSel:usingBlock: v48@0:8:16#24:32@?40
CMETHOD brc_swizzleInstanceMethod:with:newSel: B40@0:8:16#24:32
CMETHOD brc_swizzleInstanceMethod:with:newSel:usingBlock: v48@0:8:16#24:32@?40
CMETHOD CKSQLiteClassName @16@0:8
CMETHOD _cksql_isTableEntry B16@0:8
CMETHOD CA_CAMLPropertyForKey: @24@0:8@16
CMETHOD CA_automaticallyNotifiesObservers: B24@0:8#16
CMETHOD CA_getterForProperty: ^?24@0:8r^{_CAPropertyInfo=Ib16b16[2:]^{__CFString}}16
CMETHOD CA_setterForProperty: ^?24@0:8r^{_CAPropertyInfo=Ib16b16[2:]^{__CFString}}16
CMETHOD CA_encodesPropertyConditionally:type: B24@0:8I16i20
CMETHOD _accessibilityPerformValidations: v24@0:8@16
CMETHOD intents_arrayOfWidgetPlistRepresentableInDict:key:error:resultTransformer: @48@0:8@16@24^@32@?40
CMETHOD intents_widgetPlistRepresentableInDict:key:error: @40@0:8@16@24^@32
CMETHOD isKeyExcludedFromWebScript: B24@0:8r*16
CMETHOD isSelectorExcludedFromWebScript: B24@0:8:16
CMETHOD _webkit_invokeOnMainThread @16@0:8
CMETHOD _swiftUI_platformViewDefinition r^v16@0:8
CMETHOD _swiftUI_platformColorDefinition r^v16@0:8
CMETHOD _isDeallocating B16@0:8
CMETHOD isFault B16@0:8
CMETHOD release Vv16@0:8
CMETHOD dealloc v16@0:8
CMETHOD isProxy B16@0:8
CMETHOD new @16@0:8
CMETHOD _tryRetain B16@0:8
CMETHOD alloc @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD allowsWeakReference B16@0:8
CMETHOD autorelease @16@0:8
CMETHOD class #16@0:8
CMETHOD conformsToProtocol: B24@0:8@16
CMETHOD copy @16@0:8
CMETHOD copyWithZone: @24@0:8^{_NSZone=}16
CMETHOD debugDescription @16@0:8
CMETHOD description @16@0:8
CMETHOD doesNotRecognizeSelector: v24@0:8:16
CMETHOD forwardInvocation: v24@0:8@16
CMETHOD forwardingTargetForSelector: @24@0:8:16
CMETHOD hash Q16@0:8
CMETHOD init @16@0:8
CMETHOD initialize v16@0:8
CMETHOD instanceMethodForSelector: ^?24@0:8:16
CMETHOD instanceMethodSignatureForSelector: @24@0:8:16
CMETHOD instancesRespondToSelector: B24@0:8:16
CMETHOD isAncestorOfObject: B24@0:8@16
CMETHOD isEqual: B24@0:8@16
CMETHOD isKindOfClass: B24@0:8#16
CMETHOD isMemberOfClass: B24@0:8#16
CMETHOD isSubclassOfClass: B24@0:8#16
CMETHOD methodForSelector: ^?24@0:8:16
CMETHOD methodSignatureForSelector: @24@0:8:16
CMETHOD mutableCopy @16@0:8
CMETHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
CMETHOD performSelector: @24@0:8:16
CMETHOD performSelector:withObject: @32@0:8:16@24
CMETHOD performSelector:withObject:withObject: @40@0:8:16@24@32
CMETHOD resolveClassMethod: B24@0:8:16
CMETHOD resolveInstanceMethod: B24@0:8:16
CMETHOD respondsToSelector: B24@0:8:16
CMETHOD retain @16@0:8
CMETHOD retainCount Q16@0:8
CMETHOD retainWeakReference B16@0:8
CMETHOD self @16@0:8
CMETHOD superclass #16@0:8
CMETHOD zone ^{_NSZone=}16@0:8
METHOD bs_isPlist B16@0:8
METHOD bs_isPlistableType B16@0:8
METHOD bs_secureEncoded @16@0:8
METHOD supportsBSXPCSecureCoding B16@0:8
METHOD NSRepresentation @16@0:8
METHOD RBSIsXPCObject B16@0:8
METHOD supportsRBSXPCSecureCoding B16@0:8
METHOD CA_addValue:multipliedBy: @28@0:8@16i24
METHOD CA_copyRenderValueWithColorspace: ^{Object=^^?{Atomic={?=i}}b8b24}24@0:8^{CGColorSpace=}16
METHOD CA_distanceToValue: d24@0:8@16
METHOD CA_numericValueCount Q16@0:8
METHOD CA_interpolateValue:byFraction: @28@0:8@16f24
METHOD CA_copyRenderValue ^{Object=^^?{Atomic={?=i}}b8b24}16@0:8
METHOD CAMLTypeSupportedForKey: B24@0:8@16
METHOD CA_interpolateValues:::interpolator: @48@0:8@16@24@32r^{ValueInterpolator=ddddddddddddddB}40
METHOD CA_prepareRenderValue v16@0:8
METHOD CAMLTypeForKey: @24@0:8@16
METHOD CAMLType @16@0:8
METHOD CA_archivingValueForKey: @24@0:8@16
METHOD CA_copyNumericValue: Q24@0:8^d16
METHOD CA_initialize_for_decoding v16@0:8
METHOD CA_roundToIntegerFromValue: @24@0:8@16
METHOD CA_validateValue:forKey: B32@0:8@16@24
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD pep_afterDelay: @24@0:8d16
METHOD pep_getInvocation: @24@0:8^@16
METHOD pep_onMainThread @16@0:8
METHOD pep_onMainThreadIfNecessary @16@0:8
METHOD pep_onOperationQueue: @24@0:8@16
METHOD pep_onOperationQueue:priority: @32@0:8@16q24
METHOD pep_onThread: @24@0:8@16
METHOD pep_onThread:immediateForMatchingThread: @28@0:8@16B24
METHOD NSRepresentation @16@0:8
METHOD un_safeBoolValue B16@0:8
METHOD stringValueSafe @16@0:8
METHOD doubleValueSafe d16@0:8
METHOD int64ValueSafe: q24@0:8^i16
METHOD boolValueSafe B16@0:8
METHOD boolValueSafe: B24@0:8^i16
METHOD doubleValueSafe: d24@0:8^i16
METHOD int64ValueSafe q16@0:8
METHOD stringValueSafe: @24@0:8^i16
METHOD utf8ValueSafe r*16@0:8
METHOD utf8ValueSafe: r*24@0:8^i16
METHOD _accessibilitySetValue:forKey:storageMode: v40@0:8@16@24q32
METHOD _accessibilityValueForKey: @24@0:8@16
METHOD safeValueForKey: @24@0:8@16
METHOD safeBoolForKey: B24@0:8@16
METHOD safeIvarForKey: ^v24@0:8@16
METHOD __axValueForKey: @24@0:8@16
METHOD _accessibilityBoolValueForKey: B24@0:8@16
METHOD _accessibilityIntegerValueForKey: q24@0:8@16
METHOD _accessibilityInterposesAsSystemApplication B16@0:8
METHOD _accessibilityPerformSafeValueKeyBlock:withKey:onClass: v40@0:8@?16@24#32
METHOD _accessibilityRemoveValueForKey: v24@0:8@16
METHOD _accessibilitySetAssignedValue:forKey: v32@0:8@16@24
METHOD _accessibilitySetBoolValue:forKey: v28@0:8B16@20
METHOD _accessibilitySetIntegerValue:forKey: v32@0:8q16@24
METHOD _accessibilitySetRetainedValue:forKey: v32@0:8@16@24
METHOD _accessibilitySetUnsignedIntegerValue:forKey: v32@0:8Q16@24
METHOD _accessibilityUnsignedIntegerValueForKey: Q24@0:8@16
METHOD _axDictionaryQueue @16@0:8
METHOD _axIsWrappedPointer B16@0:8
METHOD _axSetIsWrappedPointer: v20@0:8B16
METHOD _ax_appendPrettyDescriptionToString:indentationString:visitedCollections: v40@0:8@16@24@32
METHOD _safeValidatedValueForKey:expectedClass:expectedTypeEncoding: @40@0:8@16#24r*32
METHOD _safeValidatedValueForKey:expectedClass:possibleExpectedTypeEncodings: @40@0:8@16#24r*32
METHOD axSuperTrampoline @16@0:8
METHOD axTrampolineForClass: @24@0:8#16
METHOD ax_prettyDescription @16@0:8
METHOD handleFailoversForClassNamed: v24@0:8@16
METHOD safeArrayForKey: @24@0:8@16
METHOD safeCGFloatForKey: d24@0:8@16
METHOD safeCGPointForKey: {CGPoint=dd}24@0:8@16
METHOD safeCGRectForKey: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD safeCGSizeForKey: {CGSize=dd}24@0:8@16
METHOD safeDictionaryForKey: @24@0:8@16
METHOD safeDoubleForKey: d24@0:8@16
METHOD safeFloatForKey: f24@0:8@16
METHOD safeIntForKey: i24@0:8@16
METHOD safeIntegerForIvarKey:onClass: q32@0:8@16#24
METHOD safeIntegerForKey: q24@0:8@16
METHOD safeRangeForKey: {_NSRange=QQ}24@0:8@16
METHOD safeSetForKey: @24@0:8@16
METHOD safeStringForKey: @24@0:8@16
METHOD safeTimeIntervalForKey: d24@0:8@16
METHOD safeUIViewForKey: @24@0:8@16
METHOD safeUnsignedIntForKey: I24@0:8@16
METHOD safeUnsignedIntegerForKey: Q24@0:8@16
METHOD safeValueForKeyPath: @24@0:8@16
METHOD __im_afterDelay: @24@0:8d16
METHOD __im_afterDelay:modes: @32@0:8d16@24
METHOD __im_getInvocation: @24@0:8^@16
METHOD __im_onDetachedThread @16@0:8
METHOD __im_onMainThread @16@0:8
METHOD __im_onMainThreadIfNecessary @16@0:8
METHOD __im_onThread: @24@0:8@16
METHOD __im_onThread:immediateForMatchingThread: @28@0:8@16B24
METHOD isNull B16@0:8
METHOD performSelector:withObject:afterDelay:ignoreMenuTracking: v44@0:8:16@24d32B40
METHOD VNComputeDevicePerformanceScore q16@0:8
METHOD VNComputeDeviceType Q16@0:8
METHOD _crComputeDeviceType Q16@0:8
METHOD CKAssignToContainerWithID: v24@0:8@16
METHOD CKDescription @16@0:8
METHOD CKDescriptionPropertiesWithPublic:private:shouldExpand: @28@0:8B16B20B24
METHOD CKObjectDescriptionRedact:avoidShortDescription: @24@0:8B16B20
METHOD CKUnredactedDescription @16@0:8
METHOD CKDescriptionShouldPrintPointer B16@0:8
METHOD CKDescriptionClassName @16@0:8
METHOD CKDescriptionRedact:avoidShortDescription: @24@0:8B16B20
METHOD CKExpandedDescription @16@0:8
METHOD CKObjectDescriptionRedact: @20@0:8B16
METHOD CKPropertiesDescription @16@0:8
METHOD CKRedactedDescription @16@0:8
METHOD _CKDescriptionWithExpansion: @20@0:8B16
METHOD ckShortDescription @16@0:8
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD cksqlcs_appendSQLConstantValueToString: @24@0:8@16
METHOD cksqlcs_archivedObjectBindingValue: @24@0:8^@16
METHOD cksqlcs_bindArchivedObject:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_bindBlob:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_bindDouble:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_bindInt64:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_bindText:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_bindValue:index:db: @36@0:8^{sqlite3_stmt=}16i24@28
METHOD cksqlcs_blobBindingValue:destructor:error: r^v40@0:8^Q16^^?24^@32
METHOD cksqlcs_doubleBindingValue: d24@0:8^@16
METHOD cksqlcs_int64BindingValue: q24@0:8^@16
METHOD cksqlcs_textBindingValue:destructor:error: ^v40@0:8^i16^^?24^@32
METHOD _intents_compareValue:relation: B32@0:8@16Q24
METHOD _intents_indexingRepresentation @16@0:8
METHOD _intents_displayImageForLanguage: @24@0:8@16
METHOD _intents_displayImageWithLocalizer: @24@0:8@16
METHOD _intents_enumerateObjectsOfClass:withBlock: B32@0:8#16@?24
METHOD _intents_isValidKey: B24@0:8@16
METHOD _intents_localizedCopyForLanguage: @24@0:8@16
METHOD _intents_localizedCopyWithLocalizer: @24@0:8@16
METHOD _intents_readableDescriptionForLanguage: @24@0:8@16
METHOD _intents_readableDescriptionForLanguage:withMetadata: @32@0:8@16@24
METHOD _intents_readableDescriptionWithLocalizer: @24@0:8@16
METHOD _intents_readableDescriptionWithLocalizer:metadata: @32@0:8@16@24
METHOD _intents_readableSubtitleForLanguage: @24@0:8@16
METHOD _intents_readableSubtitleForLanguage:withMetadata: @32@0:8@16@24
METHOD _intents_readableSubtitleWithLocalizer: @24@0:8@16
METHOD _intents_readableSubtitleWithLocalizer:metadata: @32@0:8@16@24
METHOD _intents_readableTitleForLanguage: @24@0:8@16
METHOD _intents_readableTitleForLanguage:withMetadata: @32@0:8@16@24
METHOD _intents_readableTitleWithLocalizer: @24@0:8@16
METHOD _intents_readableTitleWithLocalizer:metadata: @32@0:8@16@24
METHOD _intents_setterForPropertyWithName: :24@0:8@16
METHOD _setterForProperty: @24@0:8@16
METHOD descriptionAtIndent: @24@0:8Q16
METHOD if_setValueIfNonNil:forKey: v32@0:8@16@24
METHOD if_setValueIfYES:forKey: v28@0:8B16@20
METHOD initFromPQLResultSet:error: @32@0:8@16^@24
METHOD fm_addNotificationBlockObserverForName:object:queue:usingBlock: @48@0:8@16@24@32@?40
METHOD _fm_addNotificationObserverProxy: v24@0:8@16
METHOD _fm_removeNotificationObserverProxy: v24@0:8@16
METHOD fm_addNotificationBlockObserverForObject:keyPath:options:usingBlock: @48@0:8@16@24Q32@?40
METHOD fm_associatedObjectForDescriptor: @24@0:8r^{?=*Q}16
METHOD fm_logID @16@0:8
METHOD fm_nullToNil @16@0:8
METHOD fm_removeNotificationBlockObserver: v24@0:8@16
METHOD fm_setAssociatedObject:assocatedObjectDescriptor: v32@0:8@16r^{?=*Q}24
METHOD SCN_setupDisplayLinkWithQueue:screen:policy: @40@0:8@16@24Q32
METHOD newLibraryWithSource:options:warnings:error: @48@0:8@16@24^@32^@40
METHOD className @16@0:8
METHOD accessibilityLabel @16@0:8
METHOD setAccessibilityLabel: v24@0:8@16
METHOD _uikit_variesByTraitCollections B16@0:8
METHOD accessibilityDirectTouchOptions Q16@0:8
METHOD accessibilitySetIdentification: v24@0:8@16
METHOD setAccessibilityDecrementBlock: v24@0:8@?16
METHOD setAccessibilityExpandedStatus: v24@0:8q16
METHOD setAccessibilityIncrementBlock: v24@0:8@?16
METHOD setIsAccessibilityElementBlock: v24@0:8@?16
METHOD _isGestureType: B24@0:8q16
METHOD _uikit_valueForTraitCollection: @24@0:8@16
METHOD accessibilityHitTest:withEvent: @40@0:8{CGPoint=dd}16@32
METHOD accessibilityLocalizedStringKey @16@0:8
METHOD accessibilityTextInputResponder @16@0:8
METHOD isAccessibilityElementByDefault B16@0:8
METHOD setAccessibilityAttributedHint: v24@0:8@16
METHOD setAccessibilityElementsHidden: v20@0:8B16
METHOD setAccessibilityHeaderElements: v24@0:8@16
METHOD setAccessibilityTextualContext: v24@0:8@16
METHOD _NSItemProviderTypeCoercion_coercedUIImageValueFromNSDataValue:error: @32@0:8@16^@24
METHOD _NSItemProviderTypeCoercion_coercedUIImageValueFromNSURLValue:error: @32@0:8@16^@24
METHOD __autorotationSanityCheckObjectFromSource:selector: @32@0:8@16:24
METHOD __isKindOfTypeSelectKeyInput B16@0:8
METHOD __isKindOfUICollectionView B16@0:8
METHOD __isKindOfUIRemoteViewController B16@0:8
METHOD __isKindOfUIResponder B16@0:8
METHOD __isKindOfUIScrollView B16@0:8
METHOD __isKindOfUIView B16@0:8
METHOD __isKindOfUIViewController B16@0:8
METHOD __isKindOfUIWindow B16@0:8
METHOD __ivarDescriptionForClass: @24@0:8#16
METHOD __methodDescriptionForClass: @24@0:8#16
METHOD __propertyDescriptionForClass: @24@0:8#16
METHOD _accessibilityFinalize v16@0:8
METHOD _accessibilityGetBlockForAttribute: ^v24@0:8q16
METHOD _accessibilityGetContextID I16@0:8
METHOD _accessibilitySetReturnBlock:forAttribute: v32@0:8^v16q24
METHOD _applyTraitStorageRecordsForTraitCollection: v24@0:8@16
METHOD _connectInterfaceBuilderEventConnection: v24@0:8@16
METHOD _internalAccessibilityAttributedHint @16@0:8
METHOD _internalAccessibilityAttributedLabel @16@0:8
METHOD _internalAccessibilityAttributedUserInputLabels @16@0:8
METHOD _internalAccessibilityAttributedValue @16@0:8
METHOD _internalSetAccessibilityAttributedHint: v24@0:8@16
METHOD _internalSetAccessibilityAttributedLabel: v24@0:8@16
METHOD _internalSetAccessibilityAttributedUserInputLabels: v24@0:8@16
METHOD _internalSetAccessibilityAttributedValue: v24@0:8@16
METHOD _isNSRangeValueObject B16@0:8
METHOD _ivarDescription @16@0:8
METHOD _keyboardActivate v16@0:8
METHOD _keyboardActivateEventDown: ^{__IOHIDEvent=}20@0:8B16
METHOD _methodDescription @16@0:8
METHOD _propertyDescription @16@0:8
METHOD _setTraitStorageList: v24@0:8@16
METHOD _shortMethodDescription @16@0:8
METHOD _textEffects_sourceCanGenerateTargetedPreviewForChunk:completion: v32@0:8@16@?24
METHOD _textEffects_sourceCanGenerateTargetedPreviewsWithCompletion: v24@0:8@?16
METHOD _textEffects_updatedTargetedPreviewGeometryForChunk:previous:completion: v64@0:8@16{CGRect={CGPoint=dd}{CGSize=dd}}24@?56
METHOD _traitStorageList @16@0:8
METHOD _ui_descriptionBuilder @16@0:8
METHOD _ui_isKindOfTextSelectionRect B16@0:8
METHOD _ui_isUIFocusRegionContainerProxy B16@0:8
METHOD _uikit_applyValueFromTraitStorage:forKeyPath: v32@0:8@16@24
METHOD accessibilityActivate B16@0:8
METHOD accessibilityActivationPoint {CGPoint=dd}16@0:8
METHOD accessibilityAssistiveTechnologyFocusedIdentifiers @16@0:8
METHOD accessibilityAttributedHint @16@0:8
METHOD accessibilityAttributedLabel @16@0:8
METHOD accessibilityAttributedUserInputLabels @16@0:8
METHOD accessibilityAttributedValue @16@0:8
METHOD accessibilityContainer @16@0:8
METHOD accessibilityContainerType q16@0:8
METHOD accessibilityCustomActions @16@0:8
METHOD accessibilityCustomRotors @16@0:8
METHOD accessibilityDecrement v16@0:8
METHOD accessibilityDragSourceDescriptors @16@0:8
METHOD accessibilityDropPointDescriptors @16@0:8
METHOD accessibilityElementAtIndex: @24@0:8q16
METHOD accessibilityElementCount q16@0:8
METHOD accessibilityElementDidBecomeFocused v16@0:8
METHOD accessibilityElementDidLoseFocus v16@0:8
METHOD accessibilityElementIsFocused B16@0:8
METHOD accessibilityElements @16@0:8
METHOD accessibilityElementsHidden B16@0:8
METHOD accessibilityExpandedStatus q16@0:8
METHOD accessibilityExpandedStatusBlock @?16@0:8
METHOD accessibilityFrame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD accessibilityHeaderElements @16@0:8
METHOD accessibilityHint @16@0:8
METHOD accessibilityIdentification @16@0:8
METHOD accessibilityIdentifier @16@0:8
METHOD accessibilityIncrement v16@0:8
METHOD accessibilityLanguage @16@0:8
METHOD accessibilityNavigationStyle q16@0:8
METHOD accessibilityNextTextNavigationElement @16@0:8
METHOD accessibilityPath @16@0:8
METHOD accessibilityPerformEscape B16@0:8
METHOD accessibilityPerformMagicTap B16@0:8
METHOD accessibilityPreviousTextNavigationElement @16@0:8
METHOD accessibilityRespondsToUserInteraction B16@0:8
METHOD accessibilityScroll: B24@0:8q16
METHOD accessibilityTextualContext @16@0:8
METHOD accessibilityTraits Q16@0:8
METHOD accessibilityUserInputLabels @16@0:8
METHOD accessibilityValue @16@0:8
METHOD accessibilityViewIsModal B16@0:8
METHOD accessibilityZoomInAtPoint: B32@0:8{CGPoint=dd}16
METHOD accessibilityZoomOutAtPoint: B32@0:8{CGPoint=dd}16
METHOD automationElements @16@0:8
METHOD awakeFromNib v16@0:8
METHOD conformsToProtocolCached: B24@0:8@16
METHOD defaultAccessibilityTraits Q16@0:8
METHOD indexOfAccessibilityElement: q24@0:8@16
METHOD isAccessibilityElement B16@0:8
METHOD isElementAccessibilityExposedToInterfaceBuilder B16@0:8
METHOD prepareForInterfaceBuilder v16@0:8
METHOD setAccessibilityActivateBlock: v24@0:8@?16
METHOD setAccessibilityActivationPoint: v32@0:8{CGPoint=dd}16
METHOD setAccessibilityActivationPointBlock: v24@0:8@?16
METHOD setAccessibilityAttributedHintBlock: v24@0:8@?16
METHOD setAccessibilityAttributedLabel: v24@0:8@16
METHOD setAccessibilityAttributedLabelBlock: v24@0:8@?16
METHOD setAccessibilityAttributedUserInputLabels: v24@0:8@16
METHOD setAccessibilityAttributedUserInputLabelsBlock: v24@0:8@?16
METHOD setAccessibilityAttributedValue: v24@0:8@16
METHOD setAccessibilityAttributedValueBlock: v24@0:8@?16
METHOD setAccessibilityContainer: v24@0:8@16
METHOD setAccessibilityContainerType: v24@0:8q16
METHOD setAccessibilityContainerTypeBlock: v24@0:8@?16
METHOD setAccessibilityCustomActions: v24@0:8@16
METHOD setAccessibilityCustomActionsBlock: v24@0:8@?16
METHOD setAccessibilityCustomRotors: v24@0:8@16
METHOD setAccessibilityCustomRotorsBlock: v24@0:8@?16
METHOD setAccessibilityDirectTouchOptions: v24@0:8Q16
METHOD setAccessibilityDragSourceDescriptors: v24@0:8@16
METHOD setAccessibilityDropPointDescriptors: v24@0:8@16
METHOD setAccessibilityElements: v24@0:8@16
METHOD setAccessibilityElementsBlock: v24@0:8@?16
METHOD setAccessibilityElementsHiddenBlock: v24@0:8@?16
METHOD setAccessibilityExpandedStatusBlock: v24@0:8@?16
METHOD setAccessibilityFrame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setAccessibilityFrameBlock: v24@0:8@?16
METHOD setAccessibilityHeaderElementsBlock: v24@0:8@?16
METHOD setAccessibilityHint: v24@0:8@16
METHOD setAccessibilityHintBlock: v24@0:8@?16
METHOD setAccessibilityIdentifier: v24@0:8@16
METHOD setAccessibilityIdentifierBlock: v24@0:8@?16
METHOD setAccessibilityLabelBlock: v24@0:8@?16
METHOD setAccessibilityLanguage: v24@0:8@16
METHOD setAccessibilityLanguageBlock: v24@0:8@?16
METHOD setAccessibilityMagicTapBlock: v24@0:8@?16
METHOD setAccessibilityNavigationStyle: v24@0:8q16
METHOD setAccessibilityNavigationStyleBlock: v24@0:8@?16
METHOD setAccessibilityNextTextNavigationElement: v24@0:8@16
METHOD setAccessibilityNextTextNavigationElementBlock: v24@0:8@?16
METHOD setAccessibilityPath: v24@0:8@16
METHOD setAccessibilityPathBlock: v24@0:8@?16
METHOD setAccessibilityPerformEscapeBlock: v24@0:8@?16
METHOD setAccessibilityPreviousTextNavigationElement: v24@0:8@16
METHOD setAccessibilityPreviousTextNavigationElementBlock: v24@0:8@?16
METHOD setAccessibilityRespondsToUserInteraction: v20@0:8B16
METHOD setAccessibilityRespondsToUserInteractionBlock: v24@0:8@?16
METHOD setAccessibilityShouldGroupAccessibilityChildrenBlock: v24@0:8@?16
METHOD setAccessibilityTextInputResponder: v24@0:8@16
METHOD setAccessibilityTextInputResponderBlock: v24@0:8@?16
METHOD setAccessibilityTextualContextBlock: v24@0:8@?16
METHOD setAccessibilityTraits: v24@0:8Q16
METHOD setAccessibilityTraitsBlock: v24@0:8@?16
METHOD setAccessibilityUserInputLabels: v24@0:8@16
METHOD setAccessibilityUserInputLabelsBlock: v24@0:8@?16
METHOD setAccessibilityValue: v24@0:8@16
METHOD setAccessibilityValueBlock: v24@0:8@?16
METHOD setAccessibilityViewIsModal: v20@0:8B16
METHOD setAccessibilityViewIsModalBlock: v24@0:8@?16
METHOD setAutomationElements: v24@0:8@16
METHOD setAutomationElementsBlock: v24@0:8@?16
METHOD setIsAccessibilityElement: v20@0:8B16
METHOD setShouldGroupAccessibilityChildren: v20@0:8B16
METHOD shouldGroupAccessibilityChildren B16@0:8
METHOD storedAccessibilityActivationPoint @16@0:8
METHOD storedAccessibilityContainerType @16@0:8
METHOD storedAccessibilityDirectTouchOptions @16@0:8
METHOD storedAccessibilityElementsHidden @16@0:8
METHOD storedAccessibilityFrame @16@0:8
METHOD storedAccessibilityIdentifier @16@0:8
METHOD storedAccessibilityNavigationStyle @16@0:8
METHOD storedAccessibilityNextTextNavigationElement @16@0:8
METHOD storedAccessibilityPreviousTextNavigationElement @16@0:8
METHOD storedAccessibilityRespondsToUserInteraction @16@0:8
METHOD storedAccessibilityTraits @16@0:8
METHOD storedAccessibilityViewIsModal @16@0:8
METHOD storedIsAccessibilityElement @16@0:8
METHOD storedShouldGroupAccessibilityChildren @16@0:8
METHOD uiPresentationManager @16@0:8
METHOD _webkit_invokeOnMainThread @16@0:8
METHOD accessibilityBrailleMapRenderer @?16@0:8
METHOD accessibilityBrailleMapRenderRegion {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD setAccessibilityBrailleMapRenderRegion: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setAccessibilityBrailleMapRenderer: v24@0:8@?16
METHOD knownRepresentedElement @16@0:8
METHOD rotorOwnerElement @16@0:8
METHOD swiftui_insertManagedSubview:atIndex: v32@0:8@16q24
METHOD _swiftui_setAccessibilityLabel: v24@0:8@16
METHOD swiftui_accessibilityLabel @16@0:8
METHOD swiftui_addManagedSubview:positioned:relativeTo: v40@0:8@16q24@32
METHOD _web_description @16@0:8
METHOD releaseOnMainThread v16@0:8
METHOD _accessibilityAttributedLocalizedString @16@0:8
METHOD isAXAttributedString B16@0:8
METHOD _axDictionaryKeyReplacementRepresentation @16@0:8
METHOD _axReconstitutedRepresentationForDictionaryKeyReplacement @16@0:8
METHOD _axRecursivelyPropertyListCoercedRepresentationWithError: @24@0:8^@16
METHOD _axRecursivelyReconstitutedRepresentationFromPropertyListWithError: @24@0:8^@16
METHOD _setAccessibilityAttributedLocalizedString: v24@0:8@16
METHOD description @16@0:8
METHOD doesNotRecognizeSelector: v24@0:8:16
METHOD methodSignatureForSelector: @24@0:8:16
METHOD ___tryRetain_OA B16@0:8
METHOD __dealloc_zombie v16@0:8
METHOD __retain_OA @16@0:8
METHOD __autorelease_OA @16@0:8
METHOD __release_OA Vv16@0:8
METHOD _copyDescription @16@0:8
METHOD isNSCFConstantString__ B16@0:8
METHOD isNSDate__ B16@0:8
METHOD isNSNumber__ B16@0:8
METHOD isNSString__ B16@0:8
METHOD isNSArray__ B16@0:8
METHOD isNSData__ B16@0:8
METHOD isNSDictionary__ B16@0:8
METHOD isNSObject__ B16@0:8
METHOD isNSOrderedSet__ B16@0:8
METHOD isNSSet__ B16@0:8
METHOD isNSTimeZone__ B16@0:8
METHOD isNSURL__ B16@0:8
METHOD isNSValue__ B16@0:8
METHOD _cfTypeID Q16@0:8
METHOD __NS_swiftOverlay_automaticallyNotifiesObserversForKey:foundationImplementation: B32@0:8@16@?24
METHOD __NS_swiftOverlay_keyPathsForValuesAffectingValueForKey:foundationImplementation: @32@0:8@16@?24
METHOD newTaggedNSStringWithASCIIBytes_:length_: @32@0:8r*16q24
METHOD classForArchiver #16@0:8
METHOD replacementObjectForArchiver: @24@0:8@16
METHOD _localClassNameForClass r*16@0:8
METHOD _conformsToProtocolNamed: B24@0:8r*16
METHOD methodDescriptionForSelector: ^{objc_method_description=:*}24@0:8:16
METHOD addObserver:forObservableKeyPath: @32@0:8@16@24
METHOD removeObservation:forObservableKeyPath: v32@0:8@16@24
METHOD setObservation:forObservingKeyPath: v32@0:8@16@24
METHOD setSharedObservers: v24@0:8@16
METHOD finishObserving v16@0:8
METHOD _destroyObserverList v16@0:8
METHOD _isToManyChangeInformation B16@0:8
METHOD _observerStorage ^@16@0:8
METHOD _observerStorageOfSize: ^v24@0:8Q16
METHOD _overrideUseFastBlockObservers B16@0:8
METHOD _receiveBox: v24@0:8@16
METHOD addChainedObservers: @24@0:8@16
METHOD addObservationTransformer: @24@0:8@?16
METHOD addObserver: @24@0:8@16
METHOD addObserverBlock: @24@0:8@?16
METHOD receiveObservedError: v24@0:8@16
METHOD receiveObservedValue: v24@0:8@16
METHOD removeObservation: v24@0:8@16
METHOD setValuesForKeysWithDictionary: v24@0:8@16
METHOD validateValue:forKeyPath:error: B40@0:8N^@16@24o^@32
METHOD dictionaryWithValuesForKeys: @24@0:8@16
METHOD mutableArrayValueForKey: @24@0:8@16
METHOD mutableArrayValueForKeyPath: @24@0:8@16
METHOD mutableOrderedSetValueForKey: @24@0:8@16
METHOD mutableOrderedSetValueForKeyPath: @24@0:8@16
METHOD mutableSetValueForKey: @24@0:8@16
METHOD mutableSetValueForKeyPath: @24@0:8@16
METHOD setNilValueForKey: v24@0:8@16
METHOD setValue:forKey: v32@0:8@16@24
METHOD setValue:forKeyPath: v32@0:8@16@24
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD validateValue:forKey:error: B40@0:8N^@16@24o^@32
METHOD valueForKey: @24@0:8@16
METHOD valueForKeyPath: @24@0:8@16
METHOD valueForUndefinedKey: @24@0:8@16
METHOD _isKVOA B16@0:8
METHOD observeValueForKeyPath:ofObject:change:context: v48@0:8@16@24@32^v40
METHOD _addObserver:forProperty:options:context: v48@0:8@16@24Q32^v40
METHOD _removeObserver:forProperty: v32@0:8@16@24
METHOD addObserver:forKeyPath:options:context: v48@0:8@16@24Q32^v40
METHOD removeObserver:forKeyPath: v32@0:8@16@24
METHOD removeObserver:forKeyPath:context: v40@0:8@16@24^v32
METHOD didChangeValueForKey: v24@0:8@16
METHOD willChangeValueForKey: v24@0:8@16
METHOD didChange:valuesAtIndexes:forKey: v40@0:8Q16@24@32
METHOD didChangeValueForKey:withSetMutation:usingObjects: v40@0:8@16Q24@32
METHOD willChange:valuesAtIndexes:forKey: v40@0:8Q16@24@32
METHOD willChangeValueForKey:withSetMutation:usingObjects: v40@0:8@16Q24@32
METHOD setObservationInfo: v24@0:8^v16
METHOD observationInfo ^v16@0:8
METHOD _didChangeValuesForKeys: v24@0:8@16
METHOD _notifyObserversOfChangeFromValuesForKeys:toValuesForKeys: v32@0:8@16@24
METHOD _willChangeValuesForKeys: v24@0:8@16
METHOD _changeValueForKey:key:key:usingBlock: v48@0:8@16@24@32@?40
METHOD _changeValueForKey:usingBlock: v32@0:8@16@?24
METHOD _changeValueForKeys:count:maybeOldValuesDict:maybeNewValuesDict:usingBlock: v56@0:8^@16Q24@32@40@?48
METHOD _didEndKeyValueObserving v16@0:8
METHOD _implicitObservationInfo @16@0:8
METHOD _notifyObserversForKeyPath:change: v32@0:8@16@24
METHOD _pendingChangeNotificationsArrayForKey:create: @28@0:8@16B24
METHOD _willBeginKeyValueObserving v16@0:8
METHOD classForKeyedArchiver #16@0:8
METHOD replacementObjectForKeyedArchiver: @24@0:8@16
METHOD classForCoder #16@0:8
METHOD _allowsDirectEncoding B16@0:8
METHOD awakeAfterUsingCoder: @24@0:8@16
METHOD implementsSelector: B24@0:8:16
METHOD replacementObjectForCoder: @24@0:8@16
METHOD autoContentAccessingProxy @16@0:8
METHOD performSelector:object:afterDelay: v40@0:8:16@24d32
METHOD performSelector:withObject:afterDelay: v40@0:8:16@24d32
METHOD performSelector:withObject:afterDelay:inModes: v48@0:8:16@24d32@40
METHOD performSelector:onThread:withObject:waitUntilDone: v44@0:8:16@24@32B40
METHOD performSelector:onThread:withObject:waitUntilDone:modes: v52@0:8:16@24@32B40@44
METHOD performSelectorInBackground:withObject: v32@0:8:16@24
METHOD performSelectorOnMainThread:withObject:waitUntilDone: v36@0:8:16@24B32
METHOD performSelectorOnMainThread:withObject:waitUntilDone:modes: v44@0:8:16@24B32@36
METHOD classForPortCoder #16@0:8
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD _isDeallocating B16@0:8
METHOD isFault B16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD isProxy B16@0:8
METHOD _tryRetain B16@0:8
METHOD allowsWeakReference B16@0:8
METHOD autorelease @16@0:8
METHOD class #16@0:8
METHOD conformsToProtocol: B24@0:8@16
METHOD copy @16@0:8
METHOD debugDescription @16@0:8
METHOD description @16@0:8
METHOD doesNotRecognizeSelector: v24@0:8:16
METHOD finalize v16@0:8
METHOD forwardInvocation: v24@0:8@16
METHOD forwardingTargetForSelector: @24@0:8:16
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD isKindOfClass: B24@0:8#16
METHOD isMemberOfClass: B24@0:8#16
METHOD methodForSelector: ^?24@0:8:16
METHOD methodSignatureForSelector: @24@0:8:16
METHOD mutableCopy @16@0:8
METHOD performSelector: @24@0:8:16
METHOD performSelector:withObject: @32@0:8:16@24
METHOD performSelector:withObject:withObject: @40@0:8:16@24@32
METHOD respondsToSelector: B24@0:8:16
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD retainWeakReference B16@0:8
METHOD self @16@0:8
METHOD superclass #16@0:8
METHOD zone ^{_NSZone=}16@0:8

=== CLASS NSPipe ===
SUPER: NSObject
SIZE: 8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD pipe @16@0:8
METHOD init @16@0:8
METHOD _closeOnDealloc v16@0:8
METHOD fileHandleForReading @16@0:8
METHOD fileHandleForWriting @16@0:8

=== CLASS NSPropertyListSerialization ===
SUPER: NSObject
SIZE: 8
CMETHOD MCSafePropertyListWithData:options:format:error: @48@0:8@16Q24^Q32o^@40
CMETHOD DMCSafePropertyListWithData:options:format:error: @48@0:8@16Q24^Q32o^@40
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD dataFromPropertyList:format:errorDescription: @40@0:8@16Q24o^@32
CMETHOD dataWithPropertyList:format:options:error: @48@0:8@16Q24Q32o^@40
CMETHOD propertyList:isValidForFormat: B32@0:8@16Q24
CMETHOD propertyListFromData:mutabilityOption:format:errorDescription: @48@0:8@16Q24^Q32o^@40
CMETHOD propertyListWithData:options:format:error: @48@0:8@16Q24^Q32o^@40
CMETHOD propertyListWithStream:options:format:error: @48@0:8@16Q24^Q32o^@40
CMETHOD writePropertyList:toStream:format:options:error: q56@0:8@16@24Q32Q40o^@48
METHOD init @16@0:8

=== CLASS NSRecursiveLock ===
SUPER: NSObject
SIZE: 104
PROTOCOLS: NSLocking
IVAR +8 0 _priv {?="m"{_opaque_pthread_mutex_t="__sig"q"__opaque"[56c]}"t"^{_opaque_pthread_t}"cnt"Q"cd"^{?}"n"@"NSString"}
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD lock v16@0:8
METHOD setName: v24@0:8@16
METHOD unlock v16@0:8
METHOD tryLock B16@0:8
METHOD lockBeforeDate: B24@0:8@16
METHOD isLocking B16@0:8

=== CLASS NSRegularExpression ===
SUPER: NSObject
SIZE: 40
PROTOCOLS: NSCopying NSSecureCoding
IVAR +8 0 _pattern @"NSString"
IVAR +16 0 _options Q
IVAR +24 0 _internal ^v
IVAR +32 0 _checkout i
CMETHOD _intents_sharedFormatRegularExpression @16@0:8
CMETHOD _intents_sharedFunctionRegularExpression @16@0:8
CMETHOD _intents_sharedOldFormatRegularExpression @16@0:8
CMETHOD _intents_sharedStringsDictFormatRegularExpression @16@0:8
CMETHOD initialize v16@0:8
CMETHOD supportsSecureCoding B16@0:8
CMETHOD escapedPatternForString: @24@0:8@16
CMETHOD escapedTemplateForString: @24@0:8@16
CMETHOD regularExpressionWithPattern:options:error: @40@0:8@16Q24^@32
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD isEqual: B24@0:8@16
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD options Q16@0:8
METHOD pattern @16@0:8
METHOD _captureGroupNumberWithName: Q24@0:8@16
METHOD enumerateMatchesInString:options:range:usingBlock: v56@0:8@16Q24{_NSRange=QQ}32@?48
METHOD firstMatchInString:options:range: @48@0:8@16Q24{_NSRange=QQ}32
METHOD initWithPattern:options:error: @40@0:8@16Q24^@32
METHOD matchesInString:options:range: @48@0:8@16Q24{_NSRange=QQ}32
METHOD numberOfCaptureGroups Q16@0:8
METHOD numberOfMatchesInString:options:range: Q48@0:8@16Q24{_NSRange=QQ}32
METHOD rangeOfFirstMatchInString:options:range: {_NSRange=QQ}48@0:8@16Q24{_NSRange=QQ}32
METHOD replaceMatchesInString:options:range:withTemplate: Q56@0:8@16Q24{_NSRange=QQ}32@48
METHOD replacementStringForResult:inString:offset:template: @48@0:8@16@24q32@40
METHOD stringByReplacingMatchesInString:options:range:withTemplate: @56@0:8@16Q24{_NSRange=QQ}32@48

=== CLASS NSSet ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: BSCollection CKDeepCopying PQLBindable NSCopying NSMutableCopying NSSecureCoding NSFastEnumeration
CMETHOD _subclassesMustBeExplicitlyMentionedWhenDecoded B16@0:8
CMETHOD supportsSecureCoding B16@0:8
CMETHOD setWithTrackedSet: @24@0:8@16
CMETHOD fm_setWithSafeObject: @24@0:8@16
CMETHOD aaf_empty @16@0:8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD set @16@0:8
CMETHOD setWithObjects: @24@0:8@16
CMETHOD newSetWithObjects:count: @32@0:8r^@16Q24
CMETHOD setWithArray: @24@0:8@16
CMETHOD setWithArray:copyItems: @28@0:8@16B24
CMETHOD setWithArray:range: @40@0:8@16{_NSRange=QQ}24
CMETHOD setWithArray:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
CMETHOD setWithObject: @24@0:8@16
CMETHOD setWithObjects:count: @32@0:8r^@16Q24
CMETHOD setWithOrderedSet: @24@0:8@16
CMETHOD setWithOrderedSet:copyItems: @28@0:8@16B24
CMETHOD setWithOrderedSet:range: @40@0:8@16{_NSRange=QQ}24
CMETHOD setWithOrderedSet:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
CMETHOD setWithSet: @24@0:8@16
CMETHOD setWithSet:copyItems: @28@0:8@16B24
CMETHOD supportsSecureCoding B16@0:8
METHOD classForCoder #16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD _distinctUnionOfSetsForKeyPath: @24@0:8@16
METHOD _maxForKeyPath: @24@0:8@16
METHOD _minForKeyPath: @24@0:8@16
METHOD _sumForKeyPath: @24@0:8@16
METHOD _avgForKeyPath: @24@0:8@16
METHOD _countForKeyPath: @24@0:8@16
METHOD _distinctUnionOfArraysForKeyPath: @24@0:8@16
METHOD _distinctUnionOfObjectsForKeyPath: @24@0:8@16
METHOD addObserver:forKeyPath:options:context: v48@0:8@16@24Q32^v40
METHOD filteredSetUsingPredicate: @24@0:8@16
METHOD removeObserver:forKeyPath: v32@0:8@16@24
METHOD removeObserver:forKeyPath:context: v40@0:8@16@24^v32
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD setValue:forKey: v32@0:8@16@24
METHOD sortedArrayUsingDescriptors: @24@0:8@16
METHOD valueForKey: @24@0:8@16
METHOD valueForKeyPath: @24@0:8@16
METHOD bs_map: @24@0:8@?16
METHOD bs_array @16@0:8
METHOD bs_compactMap: @24@0:8@?16
METHOD bs_containsObjectPassingTest: B24@0:8@?16
METHOD bs_dictionaryByPartitioning: @24@0:8@?16
METHOD bs_each: v24@0:8@?16
METHOD bs_filter: @24@0:8@?16
METHOD bs_firstObjectPassingTest: @24@0:8@?16
METHOD bs_orderedSet @16@0:8
METHOD bs_reduce:block: @32@0:8@16@?24
METHOD bs_set @16@0:8
METHOD ac_mapNullable: @24@0:8@?16
METHOD ac_map: @24@0:8@?16
METHOD initWithTrackedSet: @24@0:8@16
METHOD CKAssignToContainerWithID: v24@0:8@16
METHOD CKCompactMap: @24@0:8@?16
METHOD CKDeepCopy @16@0:8
METHOD CKDeepCopyWithLeafNodeCopyBlock: @24@0:8@?16
METHOD CKFilter: @24@0:8@?16
METHOD CKMap: @24@0:8@?16
METHOD cksqlcs_appendSQLConstantValueToString: @24@0:8@16
METHOD fbs_singleLineDescriptionOfBSActions @16@0:8
METHOD _geo_filtered: @24@0:8@?16
METHOD __imDeepCopy @16@0:8
METHOD __imForEach: v24@0:8@?16
METHOD __imSetByApplyingBlock: @24@0:8@?16
METHOD aa_setByRemovingObjectsFromSet: @24@0:8@16
METHOD aa_setByRemovingObject: @24@0:8@16
METHOD CAMLType @16@0:8
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD ax_filteredSetUsingBlock: @24@0:8@?16
METHOD ax_flatMappedSetUsingBlock: @24@0:8@?16
METHOD ax_mappedSetUsingBlock: @24@0:8@?16
METHOD _pas_filteredSetWithTest: @24@0:8@?16
METHOD _pas_mappedSetWithTransform: @24@0:8@?16
METHOD _pas_setByRemovingObject: @24@0:8@16
METHOD _pas_setByRemovingObjectsFromSet: @24@0:8@16
METHOD fm_any: B24@0:8@?16
METHOD fm_map: @24@0:8@?16
METHOD fm_setByRemovingObjectsFromSet: @24@0:8@16
METHOD fm_each: v24@0:8@?16
METHOD fm_filter: @24@0:8@?16
METHOD fm_firstObjectPassingTest: @24@0:8@?16
METHOD fm_setByFlattening @16@0:8
METHOD fm_setByIntersectingWithSet: @24@0:8@16
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD if_map: @24@0:8@?16
METHOD if_compactMap: @24@0:8@?16
METHOD aaf_filter: @24@0:8@?16
METHOD aaf_map: @24@0:8@?16
METHOD aaf_hasObjects B16@0:8
METHOD aaf_setByRemovingObjectsFromSet: @24@0:8@16
METHOD aaf_mapStoppable: @24@0:8@?16
METHOD aaf_setByRemovingObject: @24@0:8@16
METHOD _bmdsl_randomObjectForKey: @24@0:8@16
METHOD bm_setBySubtractingSet: @24@0:8@16
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD isEqual: B24@0:8@16
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD __applyValues:context: v32@0:8^?16^v24
METHOD initWithObject: @24@0:8@16
METHOD _cfTypeID Q16@0:8
METHOD containsObject: B24@0:8@16
METHOD countForObject: Q24@0:8@16
METHOD __getValue:forObj: B32@0:8^@16@24
METHOD member: @24@0:8@16
METHOD objectsWithOptions:passingTest: @32@0:8Q16@?24
METHOD allObjects @16@0:8
METHOD anyObject @16@0:8
METHOD count Q16@0:8
METHOD countByEnumeratingWithState:objects:count: Q40@0:8^{?=Q^@^Q[5Q]}16^@24Q32
METHOD descriptionWithLocale: @24@0:8@16
METHOD descriptionWithLocale:indent: @32@0:8@16Q24
METHOD encodeWithCoder: v24@0:8@16
METHOD enumerateObjectsUsingBlock: v24@0:8@?16
METHOD enumerateObjectsWithOptions:usingBlock: v32@0:8Q16@?24
METHOD getObjects: v24@0:8^@16
METHOD getObjects:count: v32@0:8^@16Q24
METHOD getObjects:range: v40@0:8^@16{_NSRange=QQ}24
METHOD initWithArray: @24@0:8@16
METHOD initWithArray:copyItems: @28@0:8@16B24
METHOD initWithArray:range: @40@0:8@16{_NSRange=QQ}24
METHOD initWithArray:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
METHOD initWithCoder: @24@0:8@16
METHOD initWithObjects: @24@0:8@16
METHOD initWithObjects:count: @32@0:8r^@16Q24
METHOD initWithOrderedSet: @24@0:8@16
METHOD initWithOrderedSet:copyItems: @28@0:8@16B24
METHOD initWithOrderedSet:range: @40@0:8@16{_NSRange=QQ}24
METHOD initWithOrderedSet:range:copyItems: @44@0:8@16{_NSRange=QQ}24B40
METHOD initWithSet: @24@0:8@16
METHOD initWithSet:copyItems: @28@0:8@16B24
METHOD intersectsOrderedSet: B24@0:8@16
METHOD intersectsSet: B24@0:8@16
METHOD isEqualToSet: B24@0:8@16
METHOD isNSSet__ B16@0:8
METHOD isSubsetOfOrderedSet: B24@0:8@16
METHOD isSubsetOfSet: B24@0:8@16
METHOD makeObjectsPerformSelector: v24@0:8:16
METHOD makeObjectsPerformSelector:withObject: v32@0:8:16@24
METHOD members:notFoundMarker: @32@0:8@16@24
METHOD objectEnumerator @16@0:8
METHOD objectPassingTest: @24@0:8@?16
METHOD objectWithOptions:passingTest: @32@0:8Q16@?24
METHOD objectsPassingTest: @24@0:8@?16
METHOD setByAddingObject: @24@0:8@16
METHOD setByAddingObjectsFromArray: @24@0:8@16
METHOD setByAddingObjectsFromSet: @24@0:8@16
METHOD sortedArrayUsingComparator: @24@0:8@?16
METHOD sortedArrayWithOptions:usingComparator: @32@0:8Q16@?24

=== CLASS NSSortDescriptor ===
SUPER: NSObject
SIZE: 40
PROTOCOLS: NSSecureCoding NSCopying
IVAR +8 0 _sortDescriptorFlags Q
IVAR +16 0 _key @"NSString"
IVAR +24 0 _selector :
IVAR +32 0 _selectorOrBlock @
CMETHOD initialize v16@0:8
CMETHOD supportsSecureCoding B16@0:8
CMETHOD _defaultSelectorName @16@0:8
CMETHOD sortDescriptorWithKey: @24@0:8@16
CMETHOD sortDescriptorWithKey:ascending: @28@0:8@16B24
CMETHOD sortDescriptorWithKey:ascending:comparator: @36@0:8@16B24@?28
CMETHOD sortDescriptorWithKey:ascending:reverseNullOrder: @32@0:8@16B24B28
CMETHOD sortDescriptorWithKey:ascending:selector: @36@0:8@16B24:28
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD isEqual: B24@0:8@16
METHOD selector :16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD key @16@0:8
METHOD allowEvaluation v16@0:8
METHOD initWithKey:ascending:selector: @36@0:8@16B24:28
METHOD _disallowEvaluation v16@0:8
METHOD _isEqualToSortDescriptor: B24@0:8@16
METHOD _selectorName @16@0:8
METHOD _setAscending: v20@0:8B16
METHOD _setKey: v24@0:8@16
METHOD _setSelectorName: v24@0:8@16
METHOD ascending B16@0:8
METHOD comparator @?16@0:8
METHOD compareObject:toObject: q32@0:8@16@24
METHOD initWithKey: @24@0:8@16
METHOD initWithKey:ascending: @28@0:8@16B24
METHOD initWithKey:ascending:comparator: @36@0:8@16B24@?28
METHOD initWithKey:ascending:reverseNullOrder: @32@0:8@16B24B28
METHOD initWithKey:ascending:reverseNullOrder:selector: @40@0:8@16B24B28:32
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD reverseNullOrder B16@0:8
METHOD reversedSortDescriptor @16@0:8
METHOD setReverseNullOrder: v20@0:8B16

=== CLASS NSString ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: _UIMenuImageOrName UIItemProviderReading UIItemProviderWriting UIItemProviderReadingAugmentationDesignating CKRecordValue CKXPCSuitableString CKShortDescription FBSApplicationIdentifying CUByteCodable INCodableAttributeRelationComparing INJSONSerializable _PASDistilledString CSCoderEncoder MTMaterialSettingsPropertyIdentityValueProviding ISCompositorResource PQLValuable _OSXPCObjectRepresentable CRCodable BMDSLNativeJSONArchiving CCDatabaseValue NSItemProviderReading NSItemProviderWriting NSCopying NSMutableCopying NSSecureCoding
CMETHOD gs_stringWithFileSystemRepresentation: @24@0:8r*16
CMETHOD stringWithFileSystemRepresentation:length: @32@0:8r*16Q24
CMETHOD stringWithFileSystemRepresentation: @24@0:8r*16
CMETHOD fp_commonParentPathForItemURLs: @24@0:8@16
CMETHOD _fpd_pathWithFileSystemRepresentation: @24@0:8r*16
CMETHOD fp_coordinatorReadingOptions: @24@0:8Q16
CMETHOD fp_defaultProviderDomainID @16@0:8
CMETHOD fp_fromParsedDiskIdentifier: @24@0:8q16
CMETHOD fp_hashForToken: @24@0:8@16
CMETHOD fp_maximumBounceLevel Q16@0:8
CMETHOD fp_pathWithFileSystemRepresentation: @24@0:8r*16
CMETHOD fp_providerDomainIDFromProviderID:domainIdentifier: @32@0:8@16@24
CMETHOD fp_representableHFSFileNameWithBase:suffix:extension:makeDotFile: @44@0:8@16@24@32B40
CMETHOD fp_wordTokenizer ^{__CFStringTokenizer=}16@0:8
CMETHOD fpfs_initWithFSEventsFlags: @20@0:8I16
CMETHOD setFp_defaultProviderDomainID: v24@0:8@16
CMETHOD ds_commonParentPathForItemURLs: @24@0:8@16
CMETHOD ds_fileNameHasClaimedFileExtension: B24@0:8@16
CMETHOD bs_stringWithUTF8String: @24@0:8r*16
CMETHOD MCMakeUUID @16@0:8
CMETHOD aa_handleForIDSDestination: @24@0:8@16
CMETHOD URLQueryValueAllowedCharacterSet @16@0:8
CMETHOD apsStringGUID @16@0:8
CMETHOD ak_base64EncodedJsonFromObject: @24@0:8@16
CMETHOD DMCMakeUUID @16@0:8
CMETHOD localizedUserNotificationStringForKey:arguments: @32@0:8@16@24
CMETHOD _pas_stringWithConsumedAllocaDescrNoCopy:bufferSize:encoding:nullTerminated:isExternalRepresentation: @56@0:8{?=^vB}16Q32Q40B48B52
CMETHOD _pas_distilledStringClasses @16@0:8
CMETHOD _pas_proxyStringByConcatenatingStrings: @24@0:8@16
CMETHOD _pas_stringWithDataNoCopy:encoding:nullTerminated: @36@0:8@16Q24B32
CMETHOD _pas_stringWithDataNoCopy:encoding:nullTerminated:isExternalRepresentation: @40@0:8@16Q24B32B36
CMETHOD createWithBytesNoCopy:length:error: @40@0:8^v16Q24^@32
CMETHOD bmdsl_nativeSupportForEncodingAsJSON v16@0:8
CMETHOD cutStringGUID @16@0:8
CMETHOD copyStringGUID @16@0:8
CMETHOD copyStringGUIDForObject: @24@0:8@16
CMETHOD generatedRoomNameForGroupChat @16@0:8
CMETHOD randomString @16@0:8
CMETHOD stringGUID @16@0:8
CMETHOD stringGUIDForObject: @24@0:8@16
CMETHOD _stringWithUnichar: @20@0:8I16
CMETHOD _bopomofoSet ^{USet=}16@0:8
CMETHOD _bopomofoToneSet ^{USet=}16@0:8
CMETHOD _bopomofoWithoutToneSet ^{USet=}16@0:8
CMETHOD _characterSetWithPattern: ^{USet=}24@0:8@16
CMETHOD _fullwidthLettersAndNumbersSet ^{USet=}16@0:8
CMETHOD _fullwidthLettersAndSymbolsSet ^{USet=}16@0:8
CMETHOD _hiraganaSet ^{USet=}16@0:8
CMETHOD _ideographSet ^{USet=}16@0:8
CMETHOD _japaneseLetterSet ^{USet=}16@0:8
CMETHOD _nonFullwidthLettersAndNumbersSet ^{USet=}16@0:8
CMETHOD _nonHiraganaKatakanaOrBopomofoSet ^{USet=}16@0:8
CMETHOD _nonHiraganaOrKatakanaSet ^{USet=}16@0:8
CMETHOD _nonIdeographicCharacterSet ^{USet=}16@0:8
CMETHOD _nonJapaneseLetterSet ^{USet=}16@0:8
CMETHOD _nonKatakanaOrKanjiSet ^{USet=}16@0:8
CMETHOD _nonKoreanCharacterSet ^{USet=}16@0:8
CMETHOD _string:matchesString: B32@0:8@16@24
CMETHOD _stringFromCharacterSet: @24@0:8^{USet=}16
CMETHOD _ti_string:matchesStringIgnoringNullity: B32@0:8@16@24
CMETHOD stringWithUnichar: @20@0:8I16
CMETHOD _lp_reverseEnumerateComponents:usingBlock: v32@0:8@16@?24
CMETHOD triHashStrings:withDataSalt: @32@0:8@16@24
CMETHOD triNullableStringsAreEqualWithString:andOther: B32@0:8@16@24
CMETHOD editDistance:string: q32@0:8@16@24
CMETHOD editDistance:string:threshold: q40@0:8@16@24q32
CMETHOD CKSuperscriptForLetter: @20@0:8c16
CMETHOD CKSuperscriptForNumber: @24@0:8Q16
CMETHOD _intents_decodeWithJSONDecoder:codableDescription:from: @40@0:8@16@24@32
CMETHOD deferredLocalizedIntentsStringWithFormat: @24@0:8@16
CMETHOD deferredLocalizedIntentsStringWithFormat:fromTable: @32@0:8@16@24
CMETHOD deferredLocalizedIntentsStringWithFormat:fromTable:arguments: @40@0:8@16@24*32
CMETHOD deferredLocalizedIntentsStringWithFormat:fromTable:bundle: @40@0:8@16@24@32
CMETHOD intents_makeFromWidgetPlistableRepresentation: @24@0:8@16
CMETHOD decodeFromDER:error: @32@0:8@16^@24
CMETHOD usesFontLeading B16@0:8
CMETHOD usesScreenFonts B16@0:8
CMETHOD defaultBaselineOffsetForFont: d24@0:8@16
CMETHOD defaultLineHeightForFont: d24@0:8@16
CMETHOD hyphenationFactor f16@0:8
CMETHOD setHyphenationFactor: v20@0:8f16
CMETHOD setShowsControlCharacters: v20@0:8B16
CMETHOD setShowsInvisibleCharacters: v20@0:8B16
CMETHOD setTypesetterBehavior: v24@0:8q16
CMETHOD setUsesFontLeading: v20@0:8B16
CMETHOD setUsesScreenFonts: v20@0:8B16
CMETHOD showsControlCharacters B16@0:8
CMETHOD showsInvisibleCharacters B16@0:8
CMETHOD typesetterBehavior q16@0:8
CMETHOD if_stringWithData: @24@0:8@16
CMETHOD if_hexStringFromData: @24@0:8@16
CMETHOD if_hexStringFromBytes:length: @32@0:8r*16Q24
CMETHOD br_emptyFilenameAlternativeName @16@0:8
CMETHOD br_accountSessionOpenErrorInfoPath @16@0:8
CMETHOD br_badFilenameAlternativeName @16@0:8
CMETHOD br_corruptedDBInfoPath @16@0:8
CMETHOD br_currentPersonaIDWithIsDataSeparated: @24@0:8^B16
CMETHOD br_currentSupportDir @16@0:8
CMETHOD br_newReadableFileSizeStringFromBytesCount: @24@0:8q16
CMETHOD br_pathForDirectory: @24@0:8Q16
CMETHOD br_pathWithDeviceID:fileID: @28@0:8i16Q20
CMETHOD br_pathWithFileSystemRepresentation: @24@0:8r*16
CMETHOD br_personaGroupDir @16@0:8
CMETHOD br_personaGroupDirForFPFS: @20@0:8B16
CMETHOD br_reimportDomainErrorInfoPath @16@0:8
CMETHOD br_representableHFSFileNameWithBase:suffix:extension:makeDotFile: @44@0:8@16@24@32B40
CMETHOD newFromSqliteStatement:atIndex: @28@0:8^{sqlite3_stmt=}16i24
CMETHOD newFromSqliteValue: @24@0:8^{sqlite3_value=}16
CMETHOD _ui_augmentingNSItemProviderReadingClass #16@0:8
CMETHOD _webkit_localCacheDirectoryWithBundleIdentifier: @24@0:8@16
CMETHOD mt_identityValueForMaterialSettingsProperty: @24@0:8@16
CMETHOD rtcStdStringForString: {basic_string<char, std::char_traits<char>, std::allocator<char>>={?=(__rep={__short=[23c]b7b1}{__long=*Qb63b1})}}24@0:8@16
CMETHOD rtcStringForStdString: @24@0:8r^v16
CMETHOD NSStringFromLSInstallPhase: @24@0:8Q16
CMETHOD NSStringFromLSInstallType: @24@0:8Q16
CMETHOD NSStringFromLSInstallState: @24@0:8Q16
CMETHOD stringWithFileSystemRepresentation:length: @32@0:8r*16Q24
CMETHOD stringWithFileSystemRepresentation: @24@0:8r*16
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD initialize v16@0:8
CMETHOD string @16@0:8
CMETHOD stringWithFormat: @24@0:8@16
CMETHOD stringWithUTF8String: @24@0:8r*16
CMETHOD _subclassesMustBeExplicitlyMentionedWhenDecoded B16@0:8
CMETHOD stringWithCString:encoding: @32@0:8r*16Q24
CMETHOD stringWithCharacters:length: @32@0:8r^S16Q24
CMETHOD supportsSecureCoding B16@0:8
CMETHOD localizedStringWithValidatedFormat:validFormatSpecifiers:error: @40@0:8@16@24^@32
CMETHOD _newStringFromUTF16InternalData:typeIdentifier:error: @40@0:8@16@24^@32
CMETHOD _newZStringWithCharacters:length: @32@0:8r^S16Q24
CMETHOD _newZStringWithString: @24@0:8@16
CMETHOD _newZStringWithUTF8String: @24@0:8r*16
CMETHOD _stringWithFormat:locale:options:arguments: @48@0:8@16@24@32*40
CMETHOD _stringWithValidatedFormat:validFormatSpecifiers:locale:arguments:error: @56@0:8@16@24@32*40^@48
CMETHOD _web_stringRepresentationForBytes: @24@0:8q16
CMETHOD availableStringEncodings r^Q16@0:8
CMETHOD defaultCStringEncoding Q16@0:8
CMETHOD localizedNameOfStringEncoding: @24@0:8Q16
CMETHOD localizedStringWithFormat: @24@0:8@16
CMETHOD objectWithItemProviderData:typeIdentifier:error: @40@0:8@16@24^@32
CMETHOD pathWithComponents: @24@0:8@16
CMETHOD readableTypeIdentifiersForItemProvider @16@0:8
CMETHOD stringEncodingForData:encodingOptions:convertedString:usedLossyConversion: Q48@0:8@16@24^@32^B40
CMETHOD stringWithBytes:length:encoding: @40@0:8r^v16Q24Q32
CMETHOD stringWithCString: @24@0:8r*16
CMETHOD stringWithCString:length: @32@0:8r*16Q24
CMETHOD stringWithContentsOfFile: @24@0:8@16
CMETHOD stringWithContentsOfFile:encoding:error: @40@0:8@16Q24^@32
CMETHOD stringWithContentsOfFile:usedEncoding:error: @40@0:8@16^Q24^@32
CMETHOD stringWithContentsOfURL: @24@0:8@16
CMETHOD stringWithContentsOfURL:encoding:error: @40@0:8@16Q24^@32
CMETHOD stringWithContentsOfURL:usedEncoding:error: @40@0:8@16^Q24^@32
CMETHOD stringWithFormat:locale: @32@0:8@16@24
CMETHOD stringWithString: @24@0:8@16
CMETHOD stringWithValidatedFormat:validFormatSpecifiers:error: @40@0:8@16@24^@32
CMETHOD writableTypeIdentifiersForItemProvider @16@0:8
METHOD validateGSName: B24@0:8o^@16
METHOD gs_issueExtension:error: @32@0:8r*16^@24
METHOD gs_issueReadExtensionIfNeededForAuditToken: @48@0:8{?=[8I]}16
METHOD gs_stringByUpdatingPathExtensionWithPathOrURL: @24@0:8@16
METHOD validateGSNameAllowingDot:error: B28@0:8B16^@20
METHOD fp_obfuscatedDotSeparatedComponents @16@0:8
METHOD fp_obfuscatedFilename @16@0:8
METHOD fp_obfuscatedPath @16@0:8
METHOD fp_realpath @16@0:8
METHOD fp_isiCloudDriveIdentifier B16@0:8
METHOD fp_getCrashDate @16@0:8
METHOD _fp_escapedStringForSearchQuery @16@0:8
METHOD fp_fpIdentifier @16@0:8
METHOD fp_toProviderID @16@0:8
METHOD fp_alwaysObfuscatedDotSeparatedComponents @16@0:8
METHOD fp_alwaysObfuscatedExtendedAttributeName @16@0:8
METHOD fp_alwaysObfuscatedFilename @16@0:8
METHOD fp_alwaysObfuscatedPath @16@0:8
METHOD fp_bouncedNameWithIndex: @24@0:8q16
METHOD fp_bouncedNameWithIndex:isDir: @28@0:8q16B24
METHOD fp_displayNameFromFilenameWithHiddenPathExtension:isFolder: @24@0:8B16B20
METHOD fp_enumerateTokensInRange:tokenizer:usingBlock: v48@0:8{_NSRange=QQ}16^{__CFStringTokenizer=}32@?40
METHOD fp_fileSystemRepresentation r*16@0:8
METHOD fp_filenameFromDisplayNameWithExtension: @24@0:8@16
METHOD fp_formatStringWithValues:error: @32@0:8@16^@24
METHOD fp_getParsedDiskIdentifier: B24@0:8^q16
METHOD fp_isCJKLanguageIdentifier B16@0:8
METHOD fp_isCiconiaDomain B16@0:8
METHOD fp_isValidDomainIdentifierWithError: B24@0:8^@16
METHOD fp_isValidProviderIdentifierWithError: B24@0:8^@16
METHOD fp_isiCloudDriveOrCloudDocsIdentifier B16@0:8
METHOD fp_libnotifyPerUserNotificationName @16@0:8
METHOD fp_localizedFormatWithKeys:fromDictionary:error: @40@0:8@16@24^@32
METHOD fp_obfuscatedExtendedAttributeName @16@0:8
METHOD fp_obfuscatedProviderDomainID @16@0:8
METHOD fp_pathExtension @16@0:8
METHOD fp_prettyPath @16@0:8
METHOD fp_prettyPathWithObfuscation: @20@0:8B16
METHOD fp_relativePathWithRealpath: @24@0:8@16
METHOD fp_representableHFSFileNameWithNumber:addedExtension:makeDotFile: @36@0:8@16@24B32
METHOD fp_representableHFSFileNameWithNumber:addedExtension:makeDotFile:isDir: @40@0:8@16@24B32B36
METHOD fp_representableHFSFileNameWithSuffix:addedExtension:makeDotFile:isDir: @40@0:8@16@24B32B36
METHOD fp_splitKeyPathInProperty:remainder: B32@0:8^@16^@24
METHOD fp_stringByDeletingPathBounceNo:andPathExtension: @32@0:8^@16^@24
METHOD fp_stringByDeletingPathBounceNo:andPathExtension:isFolder: @36@0:8^@16^@24B32
METHOD fp_stringByDeletingPathExtension @16@0:8
METHOD fp_toDomainIdentifier @16@0:8
METHOD fp_usesDSCopyEngine B16@0:8
METHOD fp_valueForKeyPath: @24@0:8@16
METHOD _initWithUTF8String:maxLength: @32@0:8r*16Q24
METHOD MCAppendGreenteaSuffix @16@0:8
METHOD MCHash I16@0:8
METHOD MCHashedFilenameWithPrefix:extension: @32@0:8@16@24
METHOD MCOldStyleSafeFilenameHashWithExtension: @24@0:8@16
METHOD MCSHA256DigestWithSalt: @24@0:8@16
METHOD MCHashedFilenameWithExtension: @24@0:8@16
METHOD MCHashedIdentifier @16@0:8
METHOD MCOldStyleSafeFilenameHash @16@0:8
METHOD MCRemoveAppExternalVersionIDParameter @16@0:8
METHOD MCSHA256DigestWithPasscodeSalt @16@0:8
METHOD isPasswordEquivalentToken B16@0:8
METHOD stringByAppendingPathExtensionForType: @24@0:8@16
METHOD stringByAppendingPathComponent:conformingToType: @32@0:8@16@24
METHOD enumerateComponentsSeparatedByCharactersInSet:usingBlock: v32@0:8@16@?24
METHOD CAMLType @16@0:8
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD ac_sha512HashString @16@0:8
METHOD _FTDataFromHexString @16@0:8
METHOD _FTDataFromBase64String @16@0:8
METHOD _shouldItalicize B16@0:8
METHOD aa_base64String @16@0:8
METHOD _phoneNumberDetector @16@0:8
METHOD aa_appearsToBeEmail B16@0:8
METHOD aa_appearsToBePhoneNumber B16@0:8
METHOD trim @16@0:8
METHOD unredactedSuffixOfLength: @24@0:8Q16
METHOD aaf_base64Padded @16@0:8
METHOD aaf_toBase64DecodedData @16@0:8
METHOD aaf_toSHA256String @16@0:8
METHOD aaf_toBase64EncodedString @16@0:8
METHOD aaf_toBase64DecodedString @16@0:8
METHOD aaf_toSHA256Data @16@0:8
METHOD aaf_urlEncoded @16@0:8
METHOD ak_numberObject @16@0:8
METHOD ak_isEmailAddress B16@0:8
METHOD ak_safeBase64String @16@0:8
METHOD ak_stringByZeroPaddingOccurencesOfString: @24@0:8@16
METHOD ak_truncatedCopy @16@0:8
METHOD DMCAppendGreenteaSuffix @16@0:8
METHOD dmc_substringWithPattern: @24@0:8@16
METHOD fbs_bundleIDFromAppID @16@0:8
METHOD fbs_looksLikeAnIdentityString B16@0:8
METHOD _OS_xpcObjectRepresentation @16@0:8
METHOD _IS_imageMetadataFromFileName @16@0:8
METHOD _IS_scaleableResourceMetadataFromFileName @16@0:8
METHOD imageMetadataFromFileName @16@0:8
METHOD scaleableResourceMetadataFromFileName @16@0:8
METHOD personaUniqueString @16@0:8
METHOD compareVersionString: q24@0:8@16
METHOD un_localizedStringKey @16@0:8
METHOD un_isFirstPartyIdentifier B16@0:8
METHOD un_localizedStringArguments @16@0:8
METHOD un_localizedStringValue @16@0:8
METHOD un_logDigest @16@0:8
METHOD un_stringWithMaxLength: @24@0:8Q16
METHOD un_unsignedLongLongValue Q16@0:8
METHOD _pas_distilledString @16@0:8
METHOD _pas_fastUTF8StringPtrWithOptions:encodedLength: r*32@0:8Q16^Q24
METHOD _pas_proxyArrayOfSubstringsWithRanges: @24@0:8@16
METHOD _pas_retainsConmingledBackingStore B16@0:8
METHOD _pas_revivedString @16@0:8
METHOD _pas_setRetainsConmingledBackingStore: v20@0:8B16
METHOD _pas_stringBackedByUTF8CString @16@0:8
METHOD encodedBytesAndReturnLength:error: r*32@0:8^Q16^@24
METHOD encodedDataAndReturnError: @24@0:8^@16
METHOD unpaddedString @16@0:8
METHOD unpaddedString @16@0:8
METHOD unpaddedString @16@0:8
METHOD stringByTrimmingColumnSensitive @16@0:8
METHOD stringByReplacingPathBeforeComponent:with: @32@0:8@16@24
METHOD stringByTrimming @16@0:8
METHOD databaseValue_textRepresentation r*16@0:8
METHOD databaseValue_toData @16@0:8
METHOD databaseValue_toNumber @16@0:8
METHOD databaseValue_toString @16@0:8
METHOD databaseValue_type q16@0:8
METHOD axCapitalizeFirstLetter @16@0:8
METHOD axContainsString: B24@0:8@16
METHOD axContainsString:options: B32@0:8@16q24
METHOD axIsGenericLanguageCode B16@0:8
METHOD axIsLanguageCode B16@0:8
METHOD axIsRegionalLanguageCode B16@0:8
METHOD axLanguageCode @16@0:8
METHOD axRegionCode @16@0:8
METHOD cutStringByResolvingAndStandardizingPath @16@0:8
METHOD unsignedIntValue I16@0:8
METHOD isDirectory B16@0:8
METHOD _stripFZIDPrefix @16@0:8
METHOD _URIFromCanonicalizedBusinessID @16@0:8
METHOD _URIFromCanonicalizedHardwareID @16@0:8
METHOD _FZBestGuessFZIDType q16@0:8
METHOD _FZIDFromEmail @16@0:8
METHOD _FZIDFromPhoneNumber @16@0:8
METHOD _FZIDType q16@0:8
METHOD _IDFromFZIDType: @24@0:8q16
METHOD _URIFromBusinessID @16@0:8
METHOD _URIFromCanonicalizedDSID @16@0:8
METHOD _URIFromCanonicalizedEmail @16@0:8
METHOD _URIFromCanonicalizedFZIDType: @24@0:8q16
METHOD _URIFromCanonicalizedPhoneNumber @16@0:8
METHOD _URIFromCanonicalizedPseudonymID @16@0:8
METHOD _URIFromCanonicalizedSIPID @16@0:8
METHOD _URIFromCanonicalizedTemporaryID @16@0:8
METHOD _URIFromDSID @16@0:8
METHOD _URIFromEmail @16@0:8
METHOD _URIFromFZIDType: @24@0:8q16
METHOD _URIFromHardwareID @16@0:8
METHOD _URIFromPhoneNumber @16@0:8
METHOD _URIFromPseudonymID @16@0:8
METHOD _URIFromSIPID @16@0:8
METHOD _URIFromTemporaryID @16@0:8
METHOD __rangeOfNewlineInRange: {_NSRange=QQ}32@0:8{_NSRange=QQ}16
METHOD __stringByStrippingAttachmentAndControlCharacters @16@0:8
METHOD __stringByStrippingControlCharacters @16@0:8
METHOD _appearsToBeBusinessID B16@0:8
METHOD _appearsToBeDSID B16@0:8
METHOD _appearsToBeEmail B16@0:8
METHOD _appearsToBeHardwareID B16@0:8
METHOD _appearsToBePhoneNumber B16@0:8
METHOD _appearsToBePseudonymID B16@0:8
METHOD _appearsToBeSIPID B16@0:8
METHOD _appearsToBeTemporaryID B16@0:8
METHOD _bestGuessURI @16@0:8
METHOD _bestGuessURIFromCanicalizedID @16@0:8
METHOD _imInitWithFormat:arguments: @32@0:8@16*24
METHOD _im_normalizedURIString @16@0:8
METHOD _md5Hash @16@0:8
METHOD _stripPotentialTokenURIWithToken: @24@0:8^@16
METHOD hasMobileMeSuffix B16@0:8
METHOD hexValue I16@0:8
METHOD isEqualToIgnoringCase: B24@0:8@16
METHOD localizedCompareToString: q24@0:8@16
METHOD mobileMeDomain @16@0:8
METHOD pathStringForDisplay @16@0:8
METHOD roomNameIsProbablyAutomaticallyGenerated B16@0:8
METHOD stringByAddingURLEscapes @16@0:8
METHOD stringByRemovingCharactersFromSet: @24@0:8@16
METHOD stringByRemovingURLEscapes @16@0:8
METHOD stringByRemovingWhitespace @16@0:8
METHOD stringByResolvingAndStandardizingPath @16@0:8
METHOD stringWithLTREmbedding @16@0:8
METHOD stripMobileMSuffixIfPresent @16@0:8
METHOD trimmedString @16@0:8
METHOD uniqueSavePath @16@0:8
METHOD urlFromString @16@0:8
METHOD pn_hasInternationalDirectDialingPrefix B16@0:8
METHOD destinationURIs @16@0:8
METHOD destinationLightweightStatus @16@0:8
METHOD _isNaturallyRTL B16@0:8
METHOD _containsBopomofoOnly B16@0:8
METHOD _containsBopomofoToneOnly B16@0:8
METHOD _containsCJScripts B16@0:8
METHOD _containsCJScriptsOnly B16@0:8
METHOD _containsEmoji B16@0:8
METHOD _containsEmojiOnly B16@0:8
METHOD _containsFullwidthLettersAndSymbolsOnly B16@0:8
METHOD _containsIdeographicCharacters B16@0:8
METHOD _containsJapanese B16@0:8
METHOD _containsJapaneseOnly B16@0:8
METHOD _containsSubstring: B24@0:8@16
METHOD _editDistanceFrom: Q24@0:8@16
METHOD _enumerateLongCharactersInRange:usingBlock: v40@0:8{_NSRange=QQ}16@?32
METHOD _firstGrapheme @16@0:8
METHOD _firstLongCharacter I16@0:8
METHOD _graphemeCount Q16@0:8
METHOD _isDelete B16@0:8
METHOD _isIdeographicGlyphs B16@0:8
METHOD _isNewlineOrReturn B16@0:8
METHOD _isOnlyIdeographs B16@0:8
METHOD _isPlainSpace B16@0:8
METHOD _isSpace B16@0:8
METHOD _isSpaceOrReturn B16@0:8
METHOD _lastGrapheme @16@0:8
METHOD _lastLongCharacter I16@0:8
METHOD _rangeOfBackwardDeletionClusterAtIndex: {_NSRange=QQ}24@0:8Q16
METHOD _rangeOfLongCharacterAtIndex: {_NSRange=QQ}24@0:8Q16
METHOD _stringByApplyingTransform: @24@0:8@16
METHOD _stringByComposingDiacriticsLogicalOrder:allowedCharacters: @28@0:8B16@?20
METHOD _stringByConvertingFromFullWidthToHalfWidth @16@0:8
METHOD _stringByConvertingFromHalfWidthToFullWidth @16@0:8
METHOD _stringByReplacingCharacter:withCharacter: @24@0:8I16I20
METHOD _stringByReplacingCharactersInSet:withCharacter: @28@0:8^{__CFCharacterSet=}16I24
METHOD _stringByTranscribingFromLanguage: @24@0:8@16
METHOD _stringByTranscribingUsingTokenizer: @24@0:8^{__CFStringTokenizer=}16
METHOD _stringByTransliteratingToZhuyin @16@0:8
METHOD _stringByTrimmingCharactersInCFCharacterSet: @24@0:8^{__CFCharacterSet=}16
METHOD _stringByTrimmingLastCharacter @16@0:8
METHOD isDelete B16@0:8
METHOD stringByReplacingCharactersInSet:withCharacter: @28@0:8^{__CFCharacterSet=}16I24
METHOD _stringByTransliteratingToPinyin @16@0:8
METHOD _stringByTransliteratingToPinyinAsFamilyName @16@0:8
METHOD _stringByTransliteratingToZhuyinAsFamilyName @16@0:8
METHOD isNaturallyRTL B16@0:8
METHOD isSpaceOrReturn B16@0:8
METHOD _containsKorean B16@0:8
METHOD isSpace B16@0:8
METHOD _UTF8SizeOfRange: Q32@0:8{_NSRange=QQ}16
METHOD _beginsWithPrimaryScriptForLanguage: B24@0:8@16
METHOD _containsBopomofoWithoutToneOnly B16@0:8
METHOD _containsCJKScriptsOnly B16@0:8
METHOD _containsCJKSymbolsAndPunctuation B16@0:8
METHOD _containsFullwidthLettersAndNumbers B16@0:8
METHOD _containsFullwidthLettersAndNumbersOnly B16@0:8
METHOD _containsHiraganaKatakanaOrBopomofo B16@0:8
METHOD _containsHiraganaOnly B16@0:8
METHOD _containsHiraganaOrKatakana B16@0:8
METHOD _containsIdeographsOrBopomofoOnly B16@0:8
METHOD _containsKatakanaOrKanji B16@0:8
METHOD _containsSymbolsAndPunctuationOnly B16@0:8
METHOD _contentsExclusivelyInCharacterSet: B24@0:8^{USet=}16
METHOD _contentsExclusivelyInScript: B20@0:8i16
METHOD _endsSentence B16@0:8
METHOD _endsWithHalfwidth B16@0:8
METHOD _firstChar S16@0:8
METHOD _graphemeAtIndex: @24@0:8Q16
METHOD _indexByTrimmingWordsAfterIndex: Q24@0:8Q16
METHOD _indexByTrimmingWordsBeforeIndex: Q24@0:8Q16
METHOD _indexFromStartingIndex:byIncrementingComposedCharacterSequenceCount: Q32@0:8Q16Q24
METHOD _isBasicLatin B16@0:8
METHOD _isLeftAssociative B16@0:8
METHOD _isLowercaseStringWithLocale: B24@0:8@16
METHOD _isModifierSymbol B16@0:8
METHOD _isTripledPunctuation B16@0:8
METHOD _looksLikeEmailAddress B16@0:8
METHOD _looksLikeNumberInput B16@0:8
METHOD _looksLikeURL B16@0:8
METHOD _rangeOfCharacterClusterAtIndex:withClusterOffset: {_NSRange=QQ}32@0:8Q16q24
METHOD _rangeOfString:fromLocation: {_NSRange=QQ}32@0:8@16Q24
METHOD _reverseEnumerateLongCharactersInRange:usingBlock: v40@0:8{_NSRange=QQ}16@?32
METHOD _shouldBePaddedWithSpaces B16@0:8
METHOD _stringByReplacingCharactersInSet:withString: @32@0:8^{__CFCharacterSet=}16@24
METHOD _stringByTransliteratingToPinyin: @20@0:8B16
METHOD _stringByTransliteratingToZhuyin: @20@0:8B16
METHOD _stringWithLongestWhitespaceDelimitedSuffixOfMaxLength: @24@0:8Q16
METHOD _ti_isKeyEquivalentMirroringCandidate B16@0:8
METHOD _ti_keyEquivalentMirroring @16@0:8
METHOD _ti_supplementalPrefixOfLastToken: S24@0:8@16
METHOD _trimmedOfLeadingNeutralCharacters @16@0:8
METHOD containsSubstring: B24@0:8@16
METHOD editDistanceFrom: Q24@0:8@16
METHOD endsSentence B16@0:8
METHOD isLeftAssociative B16@0:8
METHOD isNewlineOrReturn B16@0:8
METHOD isPlainSpace B16@0:8
METHOD isTripledPunctuation B16@0:8
METHOD looksLikeEmailAddress B16@0:8
METHOD looksLikeNumberInput B16@0:8
METHOD looksLikeURL B16@0:8
METHOD normalizeSmartQuotedStringForLocale: @24@0:8@16
METHOD normalizeSmartQuotedStringOnlySingleQuote @16@0:8
METHOD smartQuoteInsensitiveStringEquivalent:forLocale: B32@0:8@16@24
METHOD stringByReplacingCharacter:withCharacter: @24@0:8I16I20
METHOD stringByTrimmingCharactersInCFCharacterSet: @24@0:8^{__CFCharacterSet=}16
METHOD stringByTrimmingLastCharacter @16@0:8
METHOD _lp_userVisibleHost @16@0:8
METHOD _lp_hasCaseInsensitivePrefix: B24@0:8@16
METHOD _lp_hostByStrippingTopLevelDomain @16@0:8
METHOD _lp_similarityToString: f24@0:8@16
METHOD _lp_stringByTrimmingWhitespace @16@0:8
METHOD _lp_highLevelDomainFromHost @16@0:8
METHOD _lp_hasCaseInsensitiveSubstring:startingAt: B32@0:8@16Q24
METHOD _lp_highLevelDomainFromComponents:indexOfFirstHighLevelDomainComponent:indexOfFirstTopLevelDomainComponent: @40@0:8@16^Q24^Q32
METHOD _lp_lengthOfDeepSubdomainsFromComponents: Q24@0:8@16
METHOD _lp_simplifiedUserVisibleURLStringWithSimplifications:forDisplayOnly: @28@0:8Q16B24
METHOD _lp_stringByDeletingTrailingSlash @16@0:8
METHOD _lp_stringByDeletingUsernameAndPassword @16@0:8
METHOD _lp_stringForcingLeftToRightDirection @16@0:8
METHOD _geo_formattedString @16@0:8
METHOD _geo_serverFormattedString @16@0:8
METHOD triTrim @16@0:8
METHOD triFilenameForFactorName @16@0:8
METHOD triHashWithDataSalt: @24@0:8@16
METHOD triHashWithIntegerSalt: @24@0:8Q16
METHOD triIsPathSafe B16@0:8
METHOD triIsPathSafePlausibleUniqueId B16@0:8
METHOD triJavaHash Q16@0:8
METHOD triParseJson @16@0:8
METHOD triSanitizedPathComponentWithMaxLength:addHash:error: @36@0:8Q16B24^@28
METHOD triStringByResolvingSymlinksInPath @16@0:8
METHOD hasSuffixInsensitive: B24@0:8@16
METHOD stringWithSpaceAtEnds @16@0:8
METHOD VisionCore_stringPrependedWithPaddingCharacter:toMinimumLength: @28@0:8S16Q20
METHOD VisionCore_stringAppendedWithPaddingCharacter:toMinimumLength: @28@0:8S16Q20
METHOD _crStringByRemovingInvalidArabicDiacritics @16@0:8
METHOD _crContainsText B16@0:8
METHOD _crReplacedUkrainianApostrophes @16@0:8
METHOD _compositeRegexForReplacing:nonspaceLeft:nonspaceRight: @32@0:8@16B24B28
METHOD _crArrayOfComposedCharacters @16@0:8
METHOD _crContainsCharactersInSet: B24@0:8@16
METHOD _crConvertToUnicode32 Q16@0:8
METHOD _crCountConsecutiveCharactersAtIndex:fromSet: Q32@0:8Q16@24
METHOD _crDDFriendlyTextWithIndexMapping: @24@0:8^@16
METHOD _crEndsWithClosingPunctuation B16@0:8
METHOD _crEndsWithDigit B16@0:8
METHOD _crEndsWithEOS B16@0:8
METHOD _crEndsWithHyphen B16@0:8
METHOD _crEndsWithMOS B16@0:8
METHOD _crIsAllCaps B16@0:8
METHOD _crIsListItemMarker B16@0:8
METHOD _crIsProgrammingStatement B16@0:8
METHOD _crIsSentencePunctuatedIncludingWhitespace: B20@0:8B16
METHOD _crIsStartOfSentence B16@0:8
METHOD _crStartsWithBOS B16@0:8
METHOD _crStartsWithCharacterInSet: B24@0:8@16
METHOD _crStartsWithDigit B16@0:8
METHOD _crStartsWithListItemIndicator B16@0:8
METHOD _crStartsWithLowercase B16@0:8
METHOD _crStartsWithUppercase B16@0:8
METHOD _crStringByAppendingString:locale: @32@0:8@16@24
METHOD _crStringByAppendingString:locale:appendedStringRange: @40@0:8@16@24^{_NSRange=QQ}32
METHOD _crStringByAppendingString:locale:mergeHyphenatedWord: @36@0:8@16@24B32
METHOD _crStringByAppendingString:locale:mergeHyphenatedWord:allowWhitespaceDelimiter: @40@0:8@16@24B32B36
METHOD _crStringByAppendingString:locale:mergeHyphenatedWord:appendedStringRange: @44@0:8@16@24B32^{_NSRange=QQ}36
METHOD _crStringByRemovingParenthesizedText @16@0:8
METHOD _crStringByReplacingCharactersInSet:withString: @32@0:8@16@24
METHOD _crStringByReversingComposedCharacterSequences @16@0:8
METHOD _crStringByReversingExtendedGraphemeClusters @16@0:8
METHOD _crStringEndsWithColon B16@0:8
METHOD combinedTokenSequenceString @16@0:8
METHOD crCodableDataRepresentation @16@0:8
METHOD editDistanceFromString: q24@0:8@16
METHOD editDistanceFromString:threshold: q32@0:8@16q24
METHOD editDistanceFromStringIgnoringSpaces:threshold: q32@0:8@16q24
METHOD initWithCRCodableDataRepresentation: @24@0:8@16
METHOD safeSubstringWithRange: @32@0:8{_NSRange=QQ}16
METHOD stringWithSpaceAtEnds @16@0:8
METHOD CKSafeStringForURLPathComponent @16@0:8
METHOD CKBase64EncodedStructuredHeaderValueByteSequence @16@0:8
METHOD CKDPIdentifier_Device @16@0:8
METHOD CKDPIdentifier_Raw @16@0:8
METHOD CKDPIdentifier_ShareId @16@0:8
METHOD CKDPIdentifier_User @16@0:8
METHOD CKMangledDocumentNameForURLFragment @16@0:8
METHOD CKNilIfEmpty @16@0:8
METHOD CKProbablySafeHeaderValue @16@0:8
METHOD CKSHA256 @16@0:8
METHOD CKSafeHashStringForPathComponent @16@0:8
METHOD CKSafeStringForURLWithCharsToBeEscaped: @24@0:8@16
METHOD CKStringByReplacingUUIDsWithString: @24@0:8@16
METHOD CKSanitizedPath @16@0:8
METHOD CKBase64DecodedString @16@0:8
METHOD CKBase64EncodedURLSafeString @16@0:8
METHOD CKDPIdentifier_MergeableValue @16@0:8
METHOD CKDPIdentifier_Record @16@0:8
METHOD CKDPIdentifier_Subscription @16@0:8
METHOD CKDPIdentifier_Zone @16@0:8
METHOD CKIndentedString:skippingFirstLine: @28@0:8Q16B24
METHOD CKNilIfLengthZero @16@0:8
METHOD CKSHA256Base64 @16@0:8
METHOD CKSafeStringForPathComponent @16@0:8
METHOD CKUnmangledDocumentNameFromURLFragment @16@0:8
METHOD CKXPCSuitableString @16@0:8
METHOD _CKDPIdentifierWithType: @20@0:8i16
METHOD _CKSHA256HashData @16@0:8
METHOD ckShortDescription @16@0:8
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD cksqlcs_appendSQLConstantValueToString: @24@0:8@16
METHOD cksqlcs_textBindingValue:destructor:error: ^v40@0:8^i16^^?24^@32
METHOD _intents_compareValue:relation: B32@0:8@16Q24
METHOD _intents_allowedUnarchiverClassesForProtoAsClasses @16@0:8
METHOD _intents_allowedUnarchiverClassesForProtoAsStrings @16@0:8
METHOD _intents_decodeFromProto @16@0:8
METHOD _intents_encodeForProto @16@0:8
METHOD _intents_encodeWithJSONEncoder:codableDescription: @32@0:8@16@24
METHOD _intents_localizedCopyWithLocalizer: @24@0:8@16
METHOD _intents_readableTitleWithLocalizer:metadata: @32@0:8@16@24
METHOD intents_encodeForPlistRepresentationWithParameters: @24@0:8@16
METHOD localizeForLanguage: @24@0:8@16
METHOD c2UniformlyDistributedIdentifier Q16@0:8
METHOD _sizeWithSize:attributes: {CGSize=dd}40@0:8{CGSize=dd}16@32
METHOD boundingRectWithSize:options:attributes: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGSize=dd}16q32@40
METHOD boundingRectWithSize:options:attributes:context: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGSize=dd}16q32@40@48
METHOD drawAtPoint:withAttributes: v40@0:8{CGPoint=dd}16@32
METHOD drawInRect:withAttributes: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD drawWithRect:options:attributes: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16q48@56
METHOD drawWithRect:options:attributes:context: v72@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16q48@56@64
METHOD hasColorGlyphsInRange:attributes: B40@0:8{_NSRange=QQ}16@32
METHOD sizeWithAttributes: {CGSize=dd}24@0:8@16
METHOD stringByStrippingLeadingAndTrailingWhitespaceAndQuotes @16@0:8
METHOD if_ASCIIStringByLowercasingFirstCharacter @16@0:8
METHOD if_ASCIIStringByUppercasingFirstCharacter @16@0:8
METHOD if_stringByLowercasingFirstCharacter @16@0:8
METHOD if_stringByUppercasingFirstCharacter @16@0:8
METHOD sg_dataEnumeratorUsingEncoding: @24@0:8Q16
METHOD sg_dataEnumeratorUsingEncoding:nullTerminated: @28@0:8Q16B24
METHOD sg_md5Hash @16@0:8
METHOD sg_streamBytesUsingEncoding:nullTerminated:toBlock: v36@0:8Q16B24@?28
METHOD sg_streamBytesUsingEncoding:toBlock: v32@0:8Q16@?24
METHOD isMail B16@0:8
METHOD containsCJK B16@0:8
METHOD cs_escapedStringForSearchQuery @16@0:8
METHOD cs_fuzzyPrefixMatchString:locale: B32@0:8@16@24
METHOD cs_isCslinguistics B16@0:8
METHOD cs_isPommesCtl B16@0:8
METHOD encodeWithCSCoder: v24@0:8@16
METHOD isAllNumbersOrSpaces B16@0:8
METHOD isPhotos B16@0:8
METHOD isPommes B16@0:8
METHOD normalizeForSemanticSearch @16@0:8
METHOD _br_isExcludedWithMaximumDepth:inFPFS:isFile: B28@0:8I16B20B24
METHOD _br_nameWithAddedExtension:makeDotFile: @28@0:8@16B24
METHOD _br_pathSafeFileSystemRepresentationWithDefaultValue: r*24@0:8@16
METHOD br_compareToStringForHFS:isCaseSensitive: q28@0:8@16B24
METHOD br_decodeIndexStringToIndexSet @16@0:8
METHOD br_displayFilenameWithExtensionHidden: @20@0:8B16
METHOD br_fileSystemRepresentation r*16@0:8
METHOD br_filenameSafeFileSystemRepresentation r*16@0:8
METHOD br_isAbsolutePath B16@0:8
METHOD br_isBoostableItemIdentifier B16@0:8
METHOD br_isDocumentTooLargeForUpload:maxUploadDocumentSize: B28@0:8B16q20
METHOD br_isEqualToStringForHFS:isCaseSensitive: B28@0:8@16B24
METHOD br_isExcludedButPreservedAtLogOutWithFilenames:extensions: B32@0:8@16@24
METHOD br_isExcludedFromSyncInFPFSIsFile: B20@0:8B16
METHOD br_isExcludedWithMaximumDepth: B20@0:8I16
METHOD br_isInPackage B16@0:8
METHOD br_isPackageRoot B16@0:8
METHOD br_isSideFaultName B16@0:8
METHOD br_libnotifyPerPersonaNotificationName: @24@0:8@16
METHOD br_libnotifyPerUserNotificationName @16@0:8
METHOD br_nameIsRepresentableOnHFS B16@0:8
METHOD br_obfuscateAliasTarget @16@0:8
METHOD br_obfuscatedDotOrTildaSeparatedComponents @16@0:8
METHOD br_pathExtension @16@0:8
METHOD br_pathOfPackageRoot @16@0:8
METHOD br_pathRelativeToDirectory: @24@0:8Q16
METHOD br_pathRelativeToPackageRoot @16@0:8
METHOD br_pathRelativeToPath: @24@0:8@16
METHOD br_pathSafeFileSystemRepresentation r*16@0:8
METHOD br_realpath @16@0:8
METHOD br_realpathKeepingLastSymlink @16@0:8
METHOD br_representableDirectoryName @16@0:8
METHOD br_representableHFSFileNameWithNumber:addedExtension:makeDotFile: @36@0:8@16@24B32
METHOD br_sideFaultName @16@0:8
METHOD br_sideFaultPath @16@0:8
METHOD br_stringByBackslashEscapingCharactersInString: @24@0:8@16
METHOD br_stringByDeletingPathBounceNo: @24@0:8^Q16
METHOD br_stringByDeletingPathBounceNo:andPathExtension: @32@0:8^Q16^@24
METHOD br_stringByJSONEscaping @16@0:8
METHOD brc_representableHFSFileNameWithSuffix:addedExtension:makeDotFile: @36@0:8@16@24B32
METHOD brc_stringByDeletingPathExtension @16@0:8
METHOD removingROSPPrefix @16@0:8
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD _enumerateLongCharactersInRange:usingBlock: v40@0:8{_NSRange=QQ}16@?32
METHOD localeIdentifierWithUpdatedScript: @24@0:8@16
METHOD avt_diffAgainst:suppressCommonLines:completionHandler: v36@0:8@16B24@?28
METHOD SCN_safeHash Q16@0:8
METHOD scn_stringByReplacingCharactersInRanges:withStrings: @32@0:8@16@24
METHOD VFX_safeHash Q16@0:8
METHOD vfx_stringByReplacingCharactersInRanges:withStrings: @32@0:8@16@24
METHOD _initWithUTF8String:maxLength: @32@0:8r*16Q24
METHOD sizeWithFont:constrainedToSize: {CGSize=dd}40@0:8@16{CGSize=dd}24
METHOD sizeWithFont:minFontSize:actualFontSize:forWidth:lineBreakMode: {CGSize=dd}56@0:8@16d24^d32d40q48
METHOD _asMenuElementImage @16@0:8
METHOD _asMenuElementImageName @16@0:8
METHOD _drawInRect:withFont:lineBreakMode:alignment:lineSpacing:includeEmoji:truncationRect: {CGSize=dd}88@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64i72B76^{CGRect={CGPoint=dd}{CGSize=dd}}80
METHOD _legacy_drawAtPoint:forWidth:withFont:fontSize:lineBreakMode:baselineAdjustment: {CGSize=dd}72@0:8{CGPoint=dd}16d32@40d48q56q64
METHOD _legacy_drawAtPoint:forWidth:withFont:fontSize:lineBreakMode:baselineAdjustment:includeEmoji: {CGSize=dd}76@0:8{CGPoint=dd}16d32@40d48q56q64B72
METHOD _legacy_drawAtPoint:forWidth:withFont:lineBreakMode: {CGSize=dd}56@0:8{CGPoint=dd}16d32@40q48
METHOD _legacy_drawAtPoint:forWidth:withFont:lineBreakMode:letterSpacing: {CGSize=dd}64@0:8{CGPoint=dd}16d32@40q48d56
METHOD _legacy_drawAtPoint:forWidth:withFont:lineBreakMode:letterSpacing:includeEmoji: {CGSize=dd}68@0:8{CGPoint=dd}16d32@40q48d56B64
METHOD _legacy_drawAtPoint:forWidth:withFont:minFontSize:actualFontSize:lineBreakMode:baselineAdjustment: {CGSize=dd}80@0:8{CGPoint=dd}16d32@40d48^d56q64q72
METHOD _legacy_drawAtPoint:forWidth:withFont:minFontSize:actualFontSize:lineBreakMode:baselineAdjustment:includeEmoji: {CGSize=dd}84@0:8{CGPoint=dd}16d32@40d48^d56q64q72B80
METHOD _legacy_drawAtPoint:withFont: {CGSize=dd}40@0:8{CGPoint=dd}16@32
METHOD _legacy_drawInRect:withFont: {CGSize=dd}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _legacy_drawInRect:withFont:lineBreakMode: {CGSize=dd}64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56
METHOD _legacy_drawInRect:withFont:lineBreakMode:alignment: {CGSize=dd}72@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64
METHOD _legacy_drawInRect:withFont:lineBreakMode:alignment:lineSpacing: {CGSize=dd}76@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64i72
METHOD _legacy_drawInRect:withFont:lineBreakMode:alignment:lineSpacing:includeEmoji: {CGSize=dd}80@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64i72B76
METHOD _legacy_drawInRect:withFont:lineBreakMode:alignment:lineSpacing:includeEmoji:truncationRect: {CGSize=dd}88@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64i72B76^{CGRect={CGPoint=dd}{CGSize=dd}}80
METHOD _legacy_sizeWithFont: {CGSize=dd}24@0:8@16
METHOD _legacy_sizeWithFont:constrainedToSize: {CGSize=dd}40@0:8@16{CGSize=dd}24
METHOD _legacy_sizeWithFont:constrainedToSize:lineBreakMode: {CGSize=dd}48@0:8@16{CGSize=dd}24q40
METHOD _legacy_sizeWithFont:constrainedToSize:lineBreakMode:lineSpacing: {CGSize=dd}52@0:8@16{CGSize=dd}24q40i48
METHOD _legacy_sizeWithFont:forWidth:lineBreakMode: {CGSize=dd}40@0:8@16d24q32
METHOD _legacy_sizeWithFont:forWidth:lineBreakMode:letterSpacing: {CGSize=dd}48@0:8@16d24q32d40
METHOD _legacy_sizeWithFont:minFontSize:actualFontSize:forWidth:lineBreakMode: {CGSize=dd}56@0:8@16d24^d32d40q48
METHOD _optimizedSizeWithFont: {CGSize=dd}24@0:8@16
METHOD _uikit_stringByRemovingFirstMatchFromPrefixes: @24@0:8@16
METHOD _uikit_stringByTrimmingWhitespaceAndNewlines @16@0:8
METHOD _uikit_stringWithWritingDirection:asOverride: @28@0:8q16B24
METHOD _uikit_unescapedQueryValue @16@0:8
METHOD drawAtPoint:forWidth:withFont:fontSize:lineBreakMode:baselineAdjustment: {CGSize=dd}72@0:8{CGPoint=dd}16d32@40d48q56q64
METHOD drawAtPoint:forWidth:withFont:fontSize:lineBreakMode:baselineAdjustment:includeEmoji: {CGSize=dd}76@0:8{CGPoint=dd}16d32@40d48q56q64B72
METHOD drawAtPoint:forWidth:withFont:lineBreakMode: {CGSize=dd}56@0:8{CGPoint=dd}16d32@40q48
METHOD drawAtPoint:forWidth:withFont:lineBreakMode:letterSpacing: {CGSize=dd}64@0:8{CGPoint=dd}16d32@40q48d56
METHOD drawAtPoint:forWidth:withFont:lineBreakMode:letterSpacing:includeEmoji: {CGSize=dd}68@0:8{CGPoint=dd}16d32@40q48d56B64
METHOD drawAtPoint:forWidth:withFont:minFontSize:actualFontSize:lineBreakMode:baselineAdjustment: {CGSize=dd}80@0:8{CGPoint=dd}16d32@40d48^d56q64q72
METHOD drawAtPoint:forWidth:withFont:minFontSize:actualFontSize:lineBreakMode:baselineAdjustment:includeEmoji: {CGSize=dd}84@0:8{CGPoint=dd}16d32@40d48^d56q64q72B80
METHOD drawAtPoint:withFont: {CGSize=dd}40@0:8{CGPoint=dd}16@32
METHOD drawInRect:withFont: {CGSize=dd}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD drawInRect:withFont:lineBreakMode: {CGSize=dd}64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56
METHOD drawInRect:withFont:lineBreakMode:alignment: {CGSize=dd}72@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64
METHOD drawInRect:withFont:lineBreakMode:alignment:lineSpacing: {CGSize=dd}76@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64i72
METHOD drawInRect:withFont:lineBreakMode:alignment:lineSpacing:includeEmoji: {CGSize=dd}80@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48q56q64i72B76
METHOD queryKeysAndValues @16@0:8
METHOD sizeWithFont: {CGSize=dd}24@0:8@16
METHOD sizeWithFont:constrainedToSize:lineBreakMode: {CGSize=dd}48@0:8@16{CGSize=dd}24q40
METHOD sizeWithFont:constrainedToSize:lineBreakMode:lineSpacing: {CGSize=dd}52@0:8@16{CGSize=dd}24q40i48
METHOD sizeWithFont:forWidth:lineBreakMode: {CGSize=dd}40@0:8@16d24q32
METHOD sizeWithFont:forWidth:lineBreakMode:letterSpacing: {CGSize=dd}48@0:8@16d24q32d40
METHOD _web_decodeHostName @16@0:8
METHOD _web_bestURLForUserTypedString @16@0:8
METHOD _web_encodeHostName @16@0:8
METHOD _web_isUserVisibleURL B16@0:8
METHOD _web_possibleURLPrefixesForUserTypedString @16@0:8
METHOD _web_possibleURLsForForUserTypedString: @20@0:8B16
METHOD _web_possibleURLsForUserTypedString @16@0:8
METHOD _web_stringByAbbreviatingWithTildeInPath @16@0:8
METHOD _webkit_decodeHostName @16@0:8
METHOD _webkit_encodeHostName @16@0:8
METHOD _webkit_filenameByFixingIllegalCharacters @16@0:8
METHOD _webkit_hasCaseInsensitivePrefix: B24@0:8@16
METHOD _webkit_hasCaseInsensitiveSuffix: B24@0:8@16
METHOD _webkit_isCaseInsensitiveEqualToString: B24@0:8@16
METHOD _webkit_isFileURL B16@0:8
METHOD _webkit_isJavaScriptURL B16@0:8
METHOD _webkit_looksLikeAbsoluteURL B16@0:8
METHOD _webkit_rangeOfURLScheme {_NSRange=QQ}16@0:8
METHOD _webkit_scriptIfJavaScriptURL @16@0:8
METHOD _webkit_stringByReplacingValidPercentEscapes @16@0:8
METHOD _webkit_stringByTrimmingWhitespace @16@0:8
METHOD mt_isIdentityValueForMaterialSettingsProperty: B24@0:8@16
METHOD rtcStdString {basic_string<char, std::char_traits<char>, std::allocator<char>>={?=(__rep={__short=[23c]b7b1}{__long=*Qb63b1})}}16@0:8
METHOD _axDictionaryKeyReplacementRepresentation @16@0:8
METHOD _axReconstitutedRepresentationForDictionaryKeyReplacement @16@0:8
METHOD _axRecursivelyPropertyListCoercedRepresentationWithError: @24@0:8^@16
METHOD _axRecursivelyReconstitutedRepresentationFromPropertyListWithError: @24@0:8^@16
METHOD _axUnit:fromPosition:inDirection: {_NSRange=QQ}40@0:8Q16q24Q32
METHOD _ax_rangeOfNextUnitWithStartPosition:direction:withCharacterSet: {_NSRange=QQ}40@0:8q16Q24@32
METHOD axAttributedStringWithAttributes: @24@0:8@16
METHOD ax_lineFromPosition:inDirection: {_NSRange=QQ}32@0:8q16Q24
METHOD ax_lineRangeForPosition: {_NSRange=QQ}24@0:8q16
METHOD ax_paragraphFromPosition:inDirection: {_NSRange=QQ}32@0:8q16Q24
METHOD ax_sentenceFromPosition:inDirection: {_NSRange=QQ}32@0:8q16Q24
METHOD ax_wordFromPosition:inDirection: {_NSRange=QQ}32@0:8q16Q24
METHOD ls_matchesStringForPluginQuery: B24@0:8@16
METHOD ls_cleanForPluginQuery @16@0:8
METHOD ls_matchesForPluginQuery: B24@0:8@16
METHOD ls_visuallyOrderCharactersReturningError: @24@0:8^@16
METHOD _pb_fixCase: @20@0:8B16
METHOD _caseInsensitiveNumericCompare: q24@0:8@16
METHOD containsDotDotPathComponents B16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD mutableCopyWithZone: @24@0:8^{_NSZone=}16
METHOD _fastCStringContents: r*20@0:8B16
METHOD doubleValue d16@0:8
METHOD floatValue f16@0:8
METHOD getBytes:maxLength:usedLength:encoding:options:range:remainingRange: B80@0:8^v16Q24^Q32Q40Q48{_NSRange=QQ}56^{_NSRange=QQ}72
METHOD initWithFormat:arguments: @32@0:8@16*24
METHOD intValue i16@0:8
METHOD isNSString__ B16@0:8
METHOD length Q16@0:8
METHOD lengthOfBytesUsingEncoding: Q24@0:8Q16
METHOD longLongValue q16@0:8
METHOD UTF8String r*16@0:8
METHOD initWithUTF8String: @24@0:8r*16
METHOD _getCString:maxLength:encoding: B36@0:8*16Q24I32
METHOD cString r*16@0:8
METHOD fastestEncoding Q16@0:8
METHOD stringByAppendingPathComponent: @24@0:8@16
METHOD _cfTypeID Q16@0:8
METHOD initWithString: @24@0:8@16
METHOD stringByResolvingSymlinksInPath @16@0:8
METHOD _copyFormatStringWithConfiguration: @24@0:8@16
METHOD _createSubstringWithRange: @32@0:8{_NSRange=QQ}16
METHOD _encodingCantBeStoredInEightBitCFString C16@0:8
METHOD _fastCharacterContents r^S16@0:8
METHOD _fastestEncodingInCFStringEncoding I16@0:8
METHOD _isCString B16@0:8
METHOD _newSubstringWithRange:zone: @40@0:8{_NSRange=QQ}16^{_NSZone=}32
METHOD _pathByInsertingResolveFlags: @20@0:8I16
METHOD _pathResolveFlags I16@0:8
METHOD _queryResolveFlags I16@0:8
METHOD _smallestEncodingInCFStringEncoding I16@0:8
METHOD _stringRepresentation @16@0:8
METHOD _urlStringByInsertingPathResolveFlags: @20@0:8I16
METHOD _urlStringByInsertingQueryResolveFlags: @20@0:8I16
METHOD _urlStringByRemovingResolveFlags @16@0:8
METHOD boolValue B16@0:8
METHOD cStringLength Q16@0:8
METHOD cStringUsingEncoding: r*24@0:8Q16
METHOD characterAtIndex: S24@0:8Q16
METHOD classForCoder #16@0:8
METHOD compare: q24@0:8@16
METHOD compare:options:range:locale: q56@0:8@16Q24{_NSRange=QQ}32@48
METHOD componentsSeparatedByCharactersInSet: @24@0:8@16
METHOD dataUsingEncoding:allowLossyConversion: @28@0:8Q16B24
METHOD encodeWithCoder: v24@0:8@16
METHOD formatConfiguration @16@0:8
METHOD getCString:maxLength:encoding: B40@0:8*16Q24Q32
METHOD getCharacters:range: v40@0:8^S16{_NSRange=QQ}24
METHOD getFileSystemRepresentation:maxLength: B32@0:8*16Q24
METHOD getLineStart:end:contentsEnd:forRange: v56@0:8^Q16^Q24^Q32{_NSRange=QQ}40
METHOD getParagraphStart:end:contentsEnd:forRange: v56@0:8^Q16^Q24^Q32{_NSRange=QQ}40
METHOD hasPrefix: B24@0:8@16
METHOD hasSuffix: B24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithContentsOfFile: @24@0:8@16
METHOD initWithContentsOfURL: @24@0:8@16
METHOD integerValue q16@0:8
METHOD isEqualToString: B24@0:8@16
METHOD lastPathComponent @16@0:8
METHOD lowercaseStringWithLocale: @24@0:8@16
METHOD pathExtension @16@0:8
METHOD rangeOfCharacterFromSet:options:range: {_NSRange=QQ}48@0:8@16Q24{_NSRange=QQ}32
METHOD smallestEncoding Q16@0:8
METHOD stringByDeletingLastPathComponent @16@0:8
METHOD stringByReplacingOccurrencesOfString:withString: @32@0:8@16@24
METHOD stringByStandardizingPath @16@0:8
METHOD substringFromIndex: @24@0:8Q16
METHOD substringWithRange: @32@0:8{_NSRange=QQ}16
METHOD uppercaseStringWithLocale: @24@0:8@16
METHOD _initWithDataOfUnknownEncoding: @24@0:8@16
METHOD _web_stringByTrimmingWhitespace @16@0:8
METHOD containsString: B24@0:8@16
METHOD initWithFormat: @24@0:8@16
METHOD __baseAttributedString @16@0:8
METHOD __escapeString5991 @16@0:8
METHOD significantText {_NSRange=QQ}16@0:8
METHOD stringByAppendingPathExtension: @24@0:8@16
METHOD uppercaseString @16@0:8
METHOD _initWithFormat:locale:options: @40@0:8@16@24@32
METHOD _web_parseAsKeyValuePair_nowarn @16@0:8
METHOD commonPrefixWithString:options: @32@0:8@16Q24
METHOD localizedStandardRangeOfString: {_NSRange=QQ}24@0:8@16
METHOD lowercaseString @16@0:8
METHOD __swiftFillFileSystemRepresentationWithPointer:maxLength: B32@0:8*16q24
METHOD stringByRemovingPercentEncoding @16@0:8
METHOD _allowsDirectEncoding B16@0:8
METHOD _componentsSeparatedByCharactersInSet: @24@0:8^{__CFCharacterSet=}16
METHOD _flushRegularExpressionCaches v16@0:8
METHOD _getBlockStart:end:contentsEnd:forRange:stopAtLineSeparators: v60@0:8^Q16^Q24^Q32{_NSRange=QQ}40B56
METHOD _getBytesAsData:maxLength:usedLength:encoding:options:range:remainingRange: B80@0:8^@16Q24^Q32Q40Q48{_NSRange=QQ}56^{_NSRange=QQ}72
METHOD _getCharactersAsStringInRange: @32@0:8{_NSRange=QQ}16
METHOD _initWithBytesOfUnknownEncoding:length:copy:usedEncoding: @44@0:8*16Q24B32^Q36
METHOD _initWithFormat:locale:options:arguments: @48@0:8@16@24@32*40
METHOD _initWithFormat:options: @32@0:8@16@24
METHOD _initWithFormat:options:arguments: @40@0:8@16@24*32
METHOD _initWithValidatedFormat:validFormatSpecifiers:locale:options:error: @56@0:8@16@24@32@40^@48
METHOD _initWithValidatedFormat:validFormatSpecifiers:locale:options:error:arguments: @64@0:8@16@24@32@40^@48*56
METHOD _initWithValidatedFormat:validFormatSpecifiers:options:error: @48@0:8@16@24@32^@40
METHOD _initWithValidatedFormat:validFormatSpecifiers:options:error:arguments: @56@0:8@16@24@32^@40*48
METHOD _rangeOfCharacterFromSet:options:range: {_NSRange=QQ}48@0:8^{__CFCharacterSet=}16Q24{_NSRange=QQ}32
METHOD _rangeOfRegularExpressionPattern:options:range:locale: {_NSRange=QQ}56@0:8@16Q24{_NSRange=QQ}32@48
METHOD _stringByAddingPercentEncodingWithAllowedCharacters: @24@0:8^{__CFCharacterSet=}16
METHOD _stringByReplacingOccurrencesOfRegularExpressionPattern:withTemplate:options:range: @56@0:8@16@24Q32{_NSRange=QQ}40
METHOD _stringByResolvingSymlinksInPathUsingCache: @20@0:8B16
METHOD _stringByStandardizingPathUsingCache: @20@0:8B16
METHOD _stringByTrimmingCharactersInSet: @24@0:8^{__CFCharacterSet=}16
METHOD _web_HTTPStyleLanguageCode @16@0:8
METHOD _web_HTTPStyleLanguageCodeWithoutRegion @16@0:8
METHOD _web_URLFragment @16@0:8
METHOD _web_characterSetFromContentTypeHeader_nowarn @16@0:8
METHOD _web_countOfString: q24@0:8@16
METHOD _web_domainFromHost @16@0:8
METHOD _web_domainMatches: B24@0:8@16
METHOD _web_extractFourCharCode I16@0:8
METHOD _web_fileNameFromContentDispositionHeader_nowarn @16@0:8
METHOD _web_filenameByFixingIllegalCharacters @16@0:8
METHOD _web_fixedCarbonPOSIXPath @16@0:8
METHOD _web_hasCaseInsensitivePrefix: B24@0:8@16
METHOD _web_hasCountryCodeTLD B16@0:8
METHOD _web_isCaseInsensitiveEqualToString: B24@0:8@16
METHOD _web_isFileURL B16@0:8
METHOD _web_isJavaScriptURL B16@0:8
METHOD _web_looksLikeAbsoluteURL B16@0:8
METHOD _web_looksLikeIPAddress B16@0:8
METHOD _web_mimeTypeFromContentTypeHeader_nowarn @16@0:8
METHOD _web_parseAsKeyValuePairHandleQuotes_nowarn: @20@0:8B16
METHOD _web_rangeOfURLHost {_NSRange=QQ}16@0:8
METHOD _web_rangeOfURLResourceSpecifier_nowarn {_NSRange=QQ}16@0:8
METHOD _web_rangeOfURLScheme_nowarn {_NSRange=QQ}16@0:8
METHOD _web_rangeOfURLUserPasswordHostPort {_NSRange=QQ}16@0:8
METHOD _web_splitAtNonDateCommas_nowarn @16@0:8
METHOD _web_stringByCollapsingNonPrintingCharacters @16@0:8
METHOD _web_stringByExpandingTildeInPath @16@0:8
METHOD _web_stringByReplacingValidPercentEscapes_nowarn @16@0:8
METHOD _widthVariants @16@0:8
METHOD canBeConvertedToEncoding: B24@0:8Q16
METHOD capitalizedString @16@0:8
METHOD capitalizedStringWithLocale: @24@0:8@16
METHOD caseInsensitiveCompare: q24@0:8@16
METHOD compare:options: q32@0:8@16Q24
METHOD compare:options:range: q48@0:8@16Q24{_NSRange=QQ}32
METHOD completePathIntoString:caseSensitive:matchesIntoArray:filterTypes: Q44@0:8^@16B24^@28@36
METHOD componentsSeparatedByString: @24@0:8@16
METHOD dataUsingEncoding: @24@0:8Q16
METHOD decimalValue {?=b8b4b1b1b18[8S]}16@0:8
METHOD decomposedStringWithCanonicalMapping @16@0:8
METHOD decomposedStringWithCompatibilityMapping @16@0:8
METHOD displayableString @16@0:8
METHOD enumerateLinesUsingBlock: v24@0:8@?16
METHOD enumerateLinguisticTagsInRange:scheme:options:orthography:usingBlock: v64@0:8{_NSRange=QQ}16@32Q40@48@?56
METHOD enumerateSubstringsInRange:options:usingBlock: v48@0:8{_NSRange=QQ}16Q32@?40
METHOD fileSystemRepresentation r*16@0:8
METHOD getBytes:maxLength:filledLength:encoding:allowLossyConversion:range:remainingRange: B76@0:8*16Q24^Q32Q40B48{_NSRange=QQ}52^{_NSRange=QQ}68
METHOD getCString: v24@0:8*16
METHOD getCString:maxLength: v32@0:8*16Q24
METHOD getCString:maxLength:range:remainingRange: v56@0:8*16Q24{_NSRange=QQ}32^{_NSRange=QQ}48
METHOD getCharacters: v24@0:8^S16
METHOD getExternalRepresentation:extendedAttributes:forWritingToURLOrPath:usingEncoding:error: B56@0:8^@16^@24@32Q40^@48
METHOD initWithBytesNoCopy:length:encoding:deallocator: @48@0:8^v16Q24Q32@?40
METHOD initWithBytesNoCopy:length:encoding:freeWhenDone: @44@0:8^v16Q24Q32B40
METHOD initWithCString: @24@0:8r*16
METHOD initWithCString:encoding: @32@0:8r*16Q24
METHOD initWithCString:length: @32@0:8r*16Q24
METHOD initWithCStringNoCopy:length:freeWhenDone: @36@0:8*16Q24B32
METHOD initWithCharacters:length: @32@0:8r^S16Q24
METHOD initWithCharactersNoCopy:length:deallocator: @40@0:8^S16Q24@?32
METHOD initWithCharactersNoCopy:length:freeWhenDone: @36@0:8^S16Q24B32
METHOD initWithContentsOfFile:encoding:error: @40@0:8@16Q24^@32
METHOD initWithContentsOfFile:usedEncoding:error: @40@0:8@16^Q24^@32
METHOD initWithContentsOfURL:encoding:error: @40@0:8@16Q24^@32
METHOD initWithContentsOfURL:usedEncoding:error: @40@0:8@16^Q24^@32
METHOD initWithData:encoding: @32@0:8@16Q24
METHOD initWithData:usedEncoding: @32@0:8@16^Q24
METHOD initWithFormat:locale: @32@0:8@16@24
METHOD initWithFormat:locale:arguments: @40@0:8@16@24*32
METHOD initWithValidatedFormat:validFormatSpecifiers:arguments:error: @48@0:8@16@24*32^@40
METHOD initWithValidatedFormat:validFormatSpecifiers:error: @40@0:8@16@24^@32
METHOD initWithValidatedFormat:validFormatSpecifiers:locale:arguments:error: @56@0:8@16@24@32*40^@48
METHOD initWithValidatedFormat:validFormatSpecifiers:locale:error: @48@0:8@16@24@32^@40
METHOD isAbsolutePath B16@0:8
METHOD lineRangeForRange: {_NSRange=QQ}32@0:8{_NSRange=QQ}16
METHOD linguisticTagsInRange:scheme:options:orthography:tokenRanges: @64@0:8{_NSRange=QQ}16@32Q40@48^@56
METHOD loadDataWithTypeIdentifier:forItemProviderCompletionHandler: @32@0:8@16@?24
METHOD localizedCapitalizedString @16@0:8
METHOD localizedCaseInsensitiveCompare: q24@0:8@16
METHOD localizedCaseInsensitiveContainsString: B24@0:8@16
METHOD localizedCompare: q24@0:8@16
METHOD localizedHasPrefix: B24@0:8@16
METHOD localizedHasSuffix: B24@0:8@16
METHOD localizedLowercaseString @16@0:8
METHOD localizedStandardCompare: q24@0:8@16
METHOD localizedStandardContainsString: B24@0:8@16
METHOD localizedUppercaseString @16@0:8
METHOD lossyCString r*16@0:8
METHOD maximumLengthOfBytesUsingEncoding: Q24@0:8Q16
METHOD paragraphRangeForRange: {_NSRange=QQ}32@0:8{_NSRange=QQ}16
METHOD pathComponents @16@0:8
METHOD precomposedStringWithCanonicalMapping @16@0:8
METHOD precomposedStringWithCompatibilityMapping @16@0:8
METHOD propertyList @16@0:8
METHOD propertyListFromStringsFileFormat @16@0:8
METHOD quotedStringRepresentation @16@0:8
METHOD rangeOfCharacterFromSet: {_NSRange=QQ}24@0:8@16
METHOD rangeOfCharacterFromSet:options: {_NSRange=QQ}32@0:8@16Q24
METHOD rangeOfComposedCharacterSequenceAtIndex: {_NSRange=QQ}24@0:8Q16
METHOD rangeOfComposedCharacterSequencesForRange: {_NSRange=QQ}32@0:8{_NSRange=QQ}16
METHOD rangeOfString: {_NSRange=QQ}24@0:8@16
METHOD rangeOfString:options: {_NSRange=QQ}32@0:8@16Q24
METHOD rangeOfString:options:range: {_NSRange=QQ}48@0:8@16Q24{_NSRange=QQ}32
METHOD rangeOfString:options:range:locale: {_NSRange=QQ}56@0:8@16Q24{_NSRange=QQ}32@48
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD standardizedURLPath @16@0:8
METHOD stringByAbbreviatingWithTildeInPath @16@0:8
METHOD stringByAddingPercentEncodingWithAllowedCharacters: @24@0:8@16
METHOD stringByAddingPercentEscapes @16@0:8
METHOD stringByAddingPercentEscapesUsingEncoding: @24@0:8Q16
METHOD stringByAppendingFormat: @24@0:8@16
METHOD stringByAppendingString: @24@0:8@16
METHOD stringByApplyingTransform:reverse: @28@0:8@16B24
METHOD stringByDeletingPathExtension @16@0:8
METHOD stringByExpandingTildeInPath @16@0:8
METHOD stringByFoldingWithOptions:locale: @32@0:8Q16@24
METHOD stringByPaddingToLength:withString:startingAtIndex: @40@0:8Q16@24Q32
METHOD stringByRemovingPercentEscapes @16@0:8
METHOD stringByReplacingCharactersInRange:withString: @40@0:8{_NSRange=QQ}16@32
METHOD stringByReplacingOccurrencesOfString:withString:options:range: @56@0:8@16@24Q32{_NSRange=QQ}40
METHOD stringByReplacingPercentEscapesUsingEncoding: @24@0:8Q16
METHOD stringByTrimmingCharactersInSet: @24@0:8@16
METHOD stringsByAppendingPaths: @24@0:8@16
METHOD substringToIndex: @24@0:8Q16
METHOD variantFittingPresentationWidth: @24@0:8q16
METHOD writableTypeIdentifiersForItemProvider @16@0:8
METHOD writeToFile:atomically: B28@0:8@16B24
METHOD writeToFile:atomically:encoding:error: B44@0:8@16B24Q28^@36
METHOD writeToURL:atomically: B28@0:8@16B24
METHOD writeToURL:atomically:encoding:error: B44@0:8@16B24Q28^@36

=== CLASS NSTask ===
SUPER: NSObject
SIZE: 8
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD currentTaskDictionary @16@0:8
CMETHOD launchedTaskWithDictionary: @24@0:8@16
CMETHOD launchedTaskWithExecutableURL:arguments:error:terminationHandler: @48@0:8@16@24o^@32@?40
CMETHOD launchedTaskWithLaunchPath:arguments: @32@0:8@16@24
METHOD init @16@0:8
METHOD arguments @16@0:8
METHOD resume B16@0:8
METHOD setQualityOfService: v24@0:8q16
METHOD setEnvironment: v24@0:8@16
METHOD suspend B16@0:8
METHOD currentDirectoryPath @16@0:8
METHOD currentDirectoryURL @16@0:8
METHOD environment @16@0:8
METHOD executableURL @16@0:8
METHOD interrupt v16@0:8
METHOD isRunning B16@0:8
METHOD isSpawnedProcessDisclaimed B16@0:8
METHOD launch v16@0:8
METHOD launchAndReturnError: B24@0:8^@16
METHOD launchPath @16@0:8
METHOD launchRequirementData @16@0:8
METHOD processIdentifier i16@0:8
METHOD qualityOfService q16@0:8
METHOD setArguments: v24@0:8@16
METHOD setCurrentDirectoryPath: v24@0:8@16
METHOD setCurrentDirectoryURL: v24@0:8@16
METHOD setExecutableURL: v24@0:8@16
METHOD setLaunchPath: v24@0:8@16
METHOD setLaunchRequirementData: v24@0:8@16
METHOD setSpawnedProcessDisclaimed: v20@0:8B16
METHOD setStandardError: v24@0:8@16
METHOD setStandardInput: v24@0:8@16
METHOD setStandardOutput: v24@0:8@16
METHOD setTerminationHandler: v24@0:8@?16
METHOD standardError @16@0:8
METHOD standardInput @16@0:8
METHOD standardOutput @16@0:8
METHOD suspendCount q16@0:8
METHOD terminate v16@0:8
METHOD terminationHandler @?16@0:8
METHOD terminationReason q16@0:8
METHOD terminationStatus i16@0:8

=== CLASS NSURL ===
SUPER: NSObject
SIZE: 40
PROTOCOLS: NSItemProviderReading NSItemProviderWriting UIItemProviderReading UIItemProviderWriting CKXPCSuitableString INJSONSerializable PQLValuable NSSecureCoding NSCopying
IVAR +8 0 _urlString @"NSString"
IVAR +16 0 _baseURL @"NSURL"
IVAR +24 0 _clients ^v
IVAR +32 0 _reserved ^v
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD URLWithDataRepresentation:relativeToURL: @32@0:8@16@24
CMETHOD _cfurlWithString:encoding:relativeToURL:encodingInvalidCharacters:forceBaseURL: @44@0:8@16I24@28B36B40
CMETHOD _fileURLWithPath:isDirectory:relativeToURL: @36@0:8@16B24@28
CMETHOD _fileURLWithPath:pathStyle:isDirectory:relativeToURL: @44@0:8@16q24B32@36
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
CMETHOD fileURLWithPath: @24@0:8@16
CMETHOD _fileURLWithPath:relativeToURL: @32@0:8@16@24
CMETHOD URLByResolvingBookmarkData:options:relativeToURL:bookmarkDataIsStale:error: @56@0:8@16Q24@32^B40^@48
CMETHOD URLWithString: @24@0:8@16
CMETHOD URLWithString:relativeToURL: @32@0:8@16@24
CMETHOD _URLWithDataAsString:relativeToURL: @32@0:8@16@24
CMETHOD URLByResolvingAliasFileAtURL:options:error: @40@0:8@16Q24^@32
CMETHOD URLWithString:encodingInvalidCharacters: @28@0:8@16B24
CMETHOD _URLWithData:relativeToURL: @32@0:8@16@24
CMETHOD _fileURLWithPath:cachingResourceValuesForKeys:error: @40@0:8@16@24^@32
CMETHOD _urlWithDataRepresentation:relativeToURL:isAbsolute: @36@0:8@16@24B32
CMETHOD _urlWithString:relativeToURL:encodingInvalidCharacters: @36@0:8@16@24B32
CMETHOD _web_URLWithComponents: @80@0:8{?=@@@@q@@@}16
CMETHOD _web_URLWithString:relativeToURL: @32@0:8@16@24
CMETHOD absoluteURLWithDataRepresentation:relativeToURL: @32@0:8@16@24
CMETHOD fileURLWithFileSystemRepresentation:isDirectory:relativeToURL: @36@0:8r*16B24@28
CMETHOD fileURLWithPath:isDirectory: @28@0:8@16B24
CMETHOD fileURLWithPath:isDirectory:relativeToURL: @36@0:8@16B24@28
CMETHOD fileURLWithPath:relativeToURL: @32@0:8@16@24
CMETHOD fileURLWithPathComponents: @24@0:8@16
CMETHOD objectWithItemProviderData:typeIdentifier:error: @40@0:8@16@24^@32
CMETHOD readableTypeIdentifiersForItemProvider @16@0:8
CMETHOD writableTypeIdentifiersForItemProvider @16@0:8
CMETHOD uniqueDirectoryURLInPath: @24@0:8@16
CMETHOD URLWithDisplayIdentifier:forSearchResultDomain:andIdentifier: @36@0:8@16i24Q28
CMETHOD _allowsCreationOfFileURLFromItemProvider B16@0:8
CMETHOD _setAllowsCreationOfFileURLFromItemProvider: v20@0:8B16
CMETHOD mapsURLWithQuery: @24@0:8@16
CMETHOD mapsURLWithSourceAddress:destinationAddress: @32@0:8@16@24
CMETHOD ui_URLFromExportBookmark: @24@0:8@16
CMETHOD ui_cloudDocsContainerURL @16@0:8
CMETHOD ui_incomingDirectory: @20@0:8B16
CMETHOD _br_bookmarkableStringForURL:remoteOpeningAppWithBundleID:onlyAllowItemKnowByServer:completion: v44@0:8@16@24B32@?36
CMETHOD br_bookmarkableStringForURL:withEtag:completion: v36@0:8@16B24@?28
CMETHOD br_bookmarkableStringForURL:withEtag:onlyAllowItemKnowByServer:completion: v40@0:8@16B24B28@?32
CMETHOD br_containerIDsWithExternalReferencesTo:completionHandler: v32@0:8@16@?24
CMETHOD br_datalessMaterializationOffForBlock: v24@0:8@?16
CMETHOD br_documentURLFromBookmarkableString:completion: v32@0:8@16@?24
CMETHOD br_documentURLFromBookmarkableString:error: @32@0:8@16^@24
CMETHOD br_documentURLFromFileObjectID:error: @32@0:8@16^@24
CMETHOD br_isURL:syncRootOwnedByICloudDrive:withError: B40@0:8@16^B24^@32
CMETHOD br_setIOPolicy:type:forBlock: v32@0:8i16i20@?24
CMETHOD brc_ciconiaDumpDirForCurrentPersona @16@0:8
CMETHOD brc_ciconiaWorkDirForCurrentPersona @16@0:8
CMETHOD brc_fileURLWithFileDescriptor: @20@0:8i16
CMETHOD brc_fileURLWithVolumeDeviceID:fileID:isDirectory: @36@0:8@16@24B32
CMETHOD brc_fileURLWithVolumeDeviceID:fileID:isDirectory:withError: @44@0:8@16@24B32^@36
CMETHOD _geo_URLWithString:tokenSubstitutions: @32@0:8@16@24
CMETHOD aa_URLWithEndpoint: @24@0:8@16
CMETHOD _intents_decodeWithJSONDecoder:codableDescription:from: @40@0:8@16@24@32
CMETHOD _web_uniqueWebDataURL @16@0:8
CMETHOD _web_URLWithUserTypedString: @24@0:8@16
CMETHOD _webkit_URLWithUserTypedString: @24@0:8@16
CMETHOD _web_URLWithDataAsString: @24@0:8@16
CMETHOD _web_URLWithDataAsString:relativeToURL: @32@0:8@16@24
CMETHOD fp_homeDirectory @16@0:8
CMETHOD fp_lmdURL @16@0:8
CMETHOD _fp_createInTempDirectoryWithName:creationBlock:completion: v40@0:8@16@?24@?32
CMETHOD fp_additionalContainerPathsForBookmarks @16@0:8
CMETHOD fp_backupManifestDirectory @16@0:8
CMETHOD fp_cloudStorageDirectory @16@0:8
CMETHOD fp_createEmptyTempFileWithName:completion: v32@0:8@16@?24
CMETHOD fp_createEmptyTempPackageWithName:completion: v32@0:8@16@?24
CMETHOD fp_homeDirectoryForUserID: @20@0:8I16
CMETHOD fp_homeDirectoryPathForUserID: @20@0:8I16
CMETHOD fp_insecureTempDirectory @16@0:8
CMETHOD fp_insecureTempDirectoryIgnoringPersona @16@0:8
CMETHOD fp_insecureTempDirectoryIgnoringPersonaString @16@0:8
CMETHOD fp_personaSharedDirectory @16@0:8
CMETHOD fp_personaSharedDirectoryPathForUserID: @20@0:8I16
CMETHOD fp_secureTempDirectory @16@0:8
CMETHOD fp_secureTempDirectoryIgnoringPersona @16@0:8
CMETHOD fp_supportDirectory @16@0:8
CMETHOD fp_supportDirectoryForVolume: @24@0:8@16
CMETHOD fp_tempDirectoryForEnterprisePersona @16@0:8
CMETHOD fp_uncachedContainerURLForSecurityApplicationGroupIdentifier: @24@0:8@16
CMETHOD fp_uncachedContainerURLForSecurityApplicationGroupIdentifier:forPrimaryPersona: @28@0:8@16B24
CMETHOD __is__isNetBoot B16@0:8
CMETHOD __is__volumeTypeCodeFromURLProperties: I24@0:8@16
CMETHOD __is_coreTypesURL @16@0:8
CMETHOD _is_unregisteredPersonlityFileExtensions @16@0:8
CMETHOD newFromSqliteStatement:atIndex: @28@0:8^{sqlite3_stmt=}16i24
CMETHOD newFromSqliteValue: @24@0:8^{sqlite3_value=}16
CMETHOD _lp_URLWithUserTypedString:relativeToURL: @32@0:8@16@24
CMETHOD _lp_URLWithData:baseURL: @32@0:8@16@24
CMETHOD _QLCreateTemporaryReplacementURLForOriginalFileAtURL:withExtension:temporaryDirectoryURL: @40@0:8@16@24^@32
CMETHOD _QLTemporaryURLWithExtension:openingFileHandle:inDirectoryAtURL: @40@0:8@16^i24@32
CMETHOD triContainerURLWithPath:containerId:containerType: @40@0:8@16@24q32
CMETHOD triParseURLFromString: @24@0:8@16
CMETHOD triParseURLFromString:isDirectory: @28@0:8@16B24
CMETHOD coreGlyphsBundleURL @16@0:8
CMETHOD coreGlyphsPrivateBundleURL @16@0:8
CMETHOD __unurl @16@0:8
CMETHOD bookmarkDataWithContentsOfURL:error: @32@0:8@16^@24
CMETHOD resourceValuesForKeys:fromBookmarkData: @32@0:8@16@24
CMETHOD supportsSecureCoding B16@0:8
CMETHOD writeBookmarkData:toURL:options:error: B48@0:8@16@24Q32^@40
METHOD gs_URLByUpdatingPathExtensionWithPathOrURL: @24@0:8@16
METHOD gs_chmod: v20@0:8S16
METHOD gs_issueExtension:error: @32@0:8r*16^@24
METHOD gs_issueReadExtensionIfNeededForAuditToken: @48@0:8{?=[8I]}16
METHOD _QLNeedsCoordination B16@0:8
METHOD _QLFileSize @16@0:8
METHOD _QLIsDataLess B16@0:8
METHOD _QLIsThumbnailableWithError: B24@0:8^@16
METHOD _QLIssueFileExtensionWithSandboxType: @24@0:8r*16
METHOD _QLNeedsDownload B16@0:8
METHOD _QLUrlFileSize @16@0:8
METHOD _qlFastRealpathURL @16@0:8
METHOD ql_realpathURL @16@0:8
METHOD fp_lastEditorDeviceName @16@0:8
METHOD fp_lastEditorNameComponents @16@0:8
METHOD fp_fpfsProviderDomainID:error: @28@0:8B16^@20
METHOD fp_isDatalessWithError: @24@0:8^@16
METHOD fp_volumeUUID @16@0:8
METHOD fp_withReadWriteAccess: @24@0:8@?16
METHOD fp_checkSandboxFileMetadataRead B16@0:8
METHOD fp_deleteWithCompletionHandler: B24@0:8@?16
METHOD fp_matchesAlternateContentsURL: B24@0:8@16
METHOD fp_pathComponentDisplayMetadata @16@0:8
METHOD _fp_componentsRelativeToRoot: @24@0:8@16
METHOD _fp_lookupURLOfChildWithName:notMatchingFileID: @32@0:8@16@24
METHOD _fp_partOfAppInboxWithURLComponents: B24@0:8@16
METHOD _fp_relationshipToItemAtURL:bothAreRealpaths: q28@0:8@16B24
METHOD fp_addDocumentTrackingWithError: @24@0:8^@16
METHOD fp_addTestConflictLoserFromItemAtURL:lastEditorDeviceName:lastEditorUserName:error: @48@0:8@16@24@32^@40
METHOD fp_associateThumbnailFromDocumentAtURL:error: B32@0:8@16^@24
METHOD fp_associateThumbnailToVersionAtURL:thumbnailMetadata:error: B40@0:8@16@24^@32
METHOD fp_attachSecurityScopeFromURL: v24@0:8@16
METHOD fp_bouncedNameWithIndex: @24@0:8q16
METHOD fp_commonDirectDescendantOf: @24@0:8@16
METHOD fp_coordinatedDeleteWithHandler: v24@0:8@?16
METHOD fp_copyToTempFolderWithFilename:queue:precomputedItemSize:completion: @48@0:8@16@24Q32@?40
METHOD fp_copyToURL:queue:precomputedItemSize:replacePlaceholder:ignoreVFSSkipMtime:completion: @56@0:8@16@24Q32B40B44@?48
METHOD fp_copyToURL:queue:precomputedItemSize:replacePlaceholder:shouldCopyAppleDouble:ignoreVFSSkipMtime:completion: @60@0:8@16@24Q32B40B44B48@?52
METHOD fp_createSubFolder:completionHandler: B32@0:8@16@?24
METHOD fp_defaultMoverBlock @?16@0:8
METHOD fp_deleteAllowingCoordination:completionHandler: B28@0:8B16@?20
METHOD fp_deleteStaleBusyFileWithFileDescriptor:coordinatorPurposeIdentifier: B28@0:8i16@20
METHOD fp_directorySizeWithError: @24@0:8^@16
METHOD fp_existingURLOfChildWithName:isFolder: @28@0:8@16B24
METHOD fp_existingURLOfChildWithName:isFolder:notMatchingFileID:nextAvailableBounceNumber:forceFetchingBounceNumber: @48@0:8@16B24@28^@36B44
METHOD fp_fpfsProviderDomainID: @20@0:8B16
METHOD fp_fpfsProviderDomainID:skipTypeCheck:error: @32@0:8B16B20^@24
METHOD fp_fpfsRootURL @16@0:8
METHOD fp_getSize:error: B32@0:8^Q16^@24
METHOD fp_hasThumbnailOnImmutableDocument B16@0:8
METHOD fp_hideExtension: v20@0:8B16
METHOD fp_importUnderFolder:allowCoordination:completionHandler: B36@0:8@16B24@?28
METHOD fp_importUnderFolder:allowCoordination:usingBlock:completionHandler: B44@0:8@16B24@?28@?36
METHOD fp_importUnderFolder:completionHandler: B32@0:8@16@?24
METHOD fp_importUnderFolder:usingBlock:completionHandler: B40@0:8@16@?24@?32
METHOD fp_isAppInboxOrDescendants B16@0:8
METHOD fp_isFolder B16@0:8
METHOD fp_isInSyncableRootFast B16@0:8
METHOD fp_isLocationOrInLocation:relativeTo: B32@0:8@16@24
METHOD fp_isPackage B16@0:8
METHOD fp_isSymlink B16@0:8
METHOD fp_issueSandboxExtensionOfClass:report:error: @36@0:8r*16B24^@28
METHOD fp_makeWritableAndRemoveNonExportableAttributes v16@0:8
METHOD fp_makeWritableOnFD:error: B28@0:8i16^@20
METHOD fp_makeWritableWithError: B24@0:8^@16
METHOD fp_matchesApplicationContainerURL: B24@0:8@16
METHOD fp_matchesApplicationDataOrGroupContainerURL: B24@0:8@16
METHOD fp_matchesCloudDocsURL: B24@0:8@16
METHOD fp_matchesEDSLocation B16@0:8
METHOD fp_matchesFPFSURL: B24@0:8@16
METHOD fp_matchesFileProviderHeuristics: B20@0:8I16
METHOD fp_matchesFileProviderHeuristics:options: B28@0:8I16Q20
METHOD fp_matchesFileProviderURL: B24@0:8@16
METHOD fp_matchesLiveFilesURL: B24@0:8@16
METHOD fp_matchesOtherBookmarkContainersURL: B24@0:8@16
METHOD fp_matchesUbiquitousHeuristics @16@0:8
METHOD fp_mountOnName @16@0:8
METHOD fp_moveToTempFolderWithFilename:error: @32@0:8@16^@24
METHOD fp_moveUnderFolder:withNewName:allowBounce:allowCoordination:completionHandler: B48@0:8@16@24B32B36@?40
METHOD fp_moveUnderFolder:withNewName:allowBounce:allowCoordination:moveHandler:completionHandler: B56@0:8@16@24B32B36@?40@?48
METHOD fp_moveUnderFolder:withNewName:coordinationOptions:allowBounce:allowCoordination:completionHandler: B56@0:8@16@24Q32B40B44@?48
METHOD fp_moveUnderFolder:withNewName:coordinationOptions:allowBounce:allowCoordination:moveHandler:completionHandler: B64@0:8@16@24Q32B40B44@?48@?56
METHOD fp_physicalURL @16@0:8
METHOD fp_queued_moveUnderFolder:withNewName:coordinationOptions:allowBounce:allowCoordination:moveHandler:completionHandler: B64@0:8@16@24Q32B40B44@?48@?56
METHOD fp_realPathRelationshipToItemAtRealPathURL: q24@0:8@16
METHOD fp_realpathURL @16@0:8
METHOD fp_relationshipToItemAtURL: q24@0:8@16
METHOD fp_relativePathOf: @24@0:8@16
METHOD fp_relativePathWithRealpath: @24@0:8@16
METHOD fp_removeACLWithError: B24@0:8^@16
METHOD fp_removeFileProviderXattrsWithError: B24@0:8^@16
METHOD fp_renameWithNewName:allowCoordination:completionHandler: B36@0:8@16B24@?28
METHOD fp_renameWithNewName:completionHandler: B32@0:8@16@?24
METHOD fp_reparentUnderFolder:allowBouncing:allowCoordination:completionHandler: B40@0:8@16B24B28@?32
METHOD fp_reparentUnderFolder:allowBouncing:completionHandler: B36@0:8@16B24@?28
METHOD fp_reparentUnderFolder:allowCoordination:completionHandler: B36@0:8@16B24@?28
METHOD fp_reparentUnderFolder:withNewName:allowCoordination:completionHandler: B44@0:8@16@24B32@?36
METHOD fp_reparentUnderFolder:withNewName:completionHandler: B40@0:8@16@24@?32
METHOD fp_resolveDetachedRootLogicalLocation:error: @32@0:8^B16^@24
METHOD fp_scanForURLOfChildWithName:isFolder:maxChildrenCount:notMatchingFileID:nextAvailableBounceNumber: @52@0:8@16B24Q28@36^@44
METHOD fp_scopeDescription @16@0:8
METHOD fp_shortDescription @16@0:8
METHOD fp_trashUnderFolder:allowCoordination:completionHandler: B36@0:8@16B24@?28
METHOD fp_trashUnderFolder:completionHandler: B32@0:8@16@?24
METHOD fp_uniqueTempFolderWithError: @24@0:8^@16
METHOD fp_volumeUsesAppleDouble: B24@0:8@16
METHOD getMaxChildrenCount Q16@0:8
METHOD normalizedURL @16@0:8
METHOD URLByAppendingPathComponent:conformingToType: @32@0:8@16@24
METHOD URLByAppendingPathExtensionForType: @24@0:8@16
METHOD _IF_isOnBootVolume B16@0:8
METHOD _IF_isAliasFile B16@0:8
METHOD _IF_isDirectory B16@0:8
METHOD _IF_attributeModifiedDate @16@0:8
METHOD _IF_conformsToUTI: B24@0:8@16
METHOD _IF_contentModifiedDate @16@0:8
METHOD _IF_extendedAttributeForName: @24@0:8@16
METHOD _IF_fileSize q16@0:8
METHOD _IF_getResourceValue:forKey:error: B40@0:8o^@16@24o^@32
METHOD _IF_isBootVolume B16@0:8
METHOD _IF_isSymLink B16@0:8
METHOD _IF_isVolume B16@0:8
METHOD _IF_modifiedDate @16@0:8
METHOD _IF_setExtendedAttribute:forName:error: B40@0:8@16@24^@32
METHOD _IF_typeIdentifier @16@0:8
METHOD _IF_volumeURL @16@0:8
METHOD CAMLType @16@0:8
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD aa_endpoint @16@0:8
METHOD _EX_isDirectory B16@0:8
METHOD _EX_URLForBundleExecutable @16@0:8
METHOD _EX_containingApplicationBundleURL @16@0:8
METHOD _EX_isApplication B16@0:8
METHOD _EX_isContainedInDirectory: B24@0:8@16
METHOD _IS_dataContainerIconDecoration @16@0:8
METHOD __is__isPackage B16@0:8
METHOD __is_fileExists B16@0:8
METHOD __is__isSymLink B16@0:8
METHOD _IS_dataContainerIconResource @16@0:8
METHOD _IS_isDataContainer B16@0:8
METHOD __has_ResourceFork B16@0:8
METHOD __is__attributeModifiedDate @16@0:8
METHOD __is__conformsToUTI: B24@0:8@16
METHOD __is__contentModifiedDate @16@0:8
METHOD __is__getResourceValue:forKey:error: B40@0:8o^@16@24o^@32
METHOD __is__isAliasFile B16@0:8
METHOD __is__isDirectory B16@0:8
METHOD __is__isVolume B16@0:8
METHOD __is__modifiedDate @16@0:8
METHOD __is__volumeTypeCode I16@0:8
METHOD __is_accessFlags C16@0:8
METHOD __is_canonicalURL @16@0:8
METHOD __is_hasFileExtension: B24@0:8@16
METHOD __is_isAppExtension B16@0:8
METHOD __is_isApplication B16@0:8
METHOD __is_isBootVolume B16@0:8
METHOD __is_isBundleWithUnregisteredPersonality B16@0:8
METHOD __is_isOnBootVolume B16@0:8
METHOD __is_locked B16@0:8
METHOD __is_packageTypeCode I16@0:8
METHOD __is_resourceValuesForKeys:error: @32@0:8@16^@24
METHOD __is_typeIdentifier @16@0:8
METHOD __is_volumeURL @16@0:8
METHOD __imURLByAppendingQueryString: @24@0:8@16
METHOD _lp_simplifiedDisplayString @16@0:8
METHOD _lp_userVisibleStringUsesEncodedHost B16@0:8
METHOD _lp_userVisibleString @16@0:8
METHOD _lp_highLevelDomain @16@0:8
METHOD _lp_isHTTPFamilyURL B16@0:8
METHOD _lp_simplifiedStringForDisplayOnly: @20@0:8B16
METHOD _lp_simplifiedURLStringForFuzzyMatching @16@0:8
METHOD _lp_URLBySortingQueryItems @16@0:8
METHOD _lp_URLByDeletingCommonIndexPageNames @16@0:8
METHOD _lp_originalData @16@0:8
METHOD triPathAsOwner: @20@0:8B16
METHOD triIsContainerURL B16@0:8
METHOD triIsEqual: B24@0:8@16
METHOD triSaveURLToString @16@0:8
METHOD triURLByResolvingSymlinksInPathIncludingPrivate @16@0:8
METHOD removeItemAndReturnError: B24@0:8^@16
METHOD VisionCoreFileSystemPathAndReturnError: @24@0:8^@16
METHOD VisionCoreE5RTPathAndReturnError: r*24@0:8^@16
METHOD CKNoFollowFileURL @16@0:8
METHOD CKURLThroughSlug @16@0:8
METHOD CKPathAfterSlug @16@0:8
METHOD CKSanitizedPath @16@0:8
METHOD CKBladerunnerShareURLSlugBasedVettingKeySuffix @16@0:8
METHOD CKMarkFilePurgeable: B24@0:8^@16
METHOD CKShareURLSlugBasedApplicationName @16@0:8
METHOD CKURLSlug @16@0:8
METHOD CKXPCSuitableString @16@0:8
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD _intents_encodeWithJSONEncoder:codableDescription: @32@0:8@16@24
METHOD if_isContainedByDirectoryAtURL: B24@0:8@16
METHOD cs_addDocumentTracking B16@0:8
METHOD cs_isInMobileDocuments B16@0:8
METHOD br_URLByResolvingExternalDocumentReferenceWithError: @24@0:8^@16
METHOD br_isExternalDocumentReference B16@0:8
METHOD _br_isInSyncedLocationStrictly: B20@0:8B16
METHOD br_capabilityToMoveToURL:error: S32@0:8@16^@24
METHOD br_isInCloudDocsPrivateStorages B16@0:8
METHOD br_mightBeOnDataSeparatedVolume B16@0:8
METHOD _br_fetchItemServiceAsyncProxy: v24@0:8@?16
METHOD br_isPromiseURL B16@0:8
METHOD brc_appBundleID @16@0:8
METHOD _br_clientSideCollaborationServiceSyncProxy @16@0:8
METHOD _br_getAttributeValue:withSecondaryConnection:withError: @36@0:8@16B24^@28
METHOD _br_isInLocalHomeDirectoryUnderCurrentPersona B16@0:8
METHOD _br_isInLocalHomeDirectoryUnderPersona:needsPersonaSwitch: B28@0:8@16B24
METHOD _br_isInPersonaRoot: B24@0:8@16
METHOD _br_isInSyncedLocationWithCurrentPersonaID:strictly:foundHomeDirectory:adoptionError: B40@0:8@16B24B28@32
METHOD _br_isParentOfURL:strictly:ignoreHomeDirectoryCheck: B32@0:8@16B24B28
METHOD _br_isParentOfURL:strictly:withNonMateralizingIOPolicy:ignoreHomeDirectoryCheck: B36@0:8@16B24B28B32
METHOD _br_itemServiceSyncProxy @16@0:8
METHOD _br_mightBeInSyncedLocationUnderCurrentPersonaID:strictly: B28@0:8@16B24
METHOD br_URLByResolvingInProcessExternalDocumentReferenceWithProperties: @24@0:8@16
METHOD br_addFakeConflictLoserFromItemAtURL:lastEditorDeviceName:error: @40@0:8@16@24^@32
METHOD br_addFakeConflictLoserFromItemAtURL:lastEditorDeviceName:lastEditorUserName:error: @48@0:8@16@24@32^@40
METHOD br_bookmarkableStringForRemoteOpeningAppWithBundleID:completion: v32@0:8@16@?24
METHOD br_bookmarkableStringWithEtag:completion: v28@0:8B16@?20
METHOD br_bookmarkableStringWithEtag:onlyAllowItemKnowByServer:completion: v32@0:8B16B20@?24
METHOD br_cachedBookmarkData @16@0:8
METHOD br_cloudDocsContainer @16@0:8
METHOD br_containerID @16@0:8
METHOD br_containerIDIfIsDesktopOrDocumentsURL @16@0:8
METHOD br_containerIDIfIsDocumentsContainerURL @16@0:8
METHOD br_containerIDWithCurrentPersonaID: @24@0:8@16
METHOD br_containerIDWithCurrentPersonaID:needsPersonaSwitch: @28@0:8@16B24
METHOD br_containerIDsWithExternalReferencesWithHandler: v24@0:8@?16
METHOD br_creatorNameComponentsWithError: @24@0:8^@16
METHOD br_debugDescription @16@0:8
METHOD br_documentRecordIDWithError: @24@0:8^@16
METHOD br_externalDocumentPropertiesWithError: @24@0:8^@16
METHOD br_getBirthDate: B24@0:8^q16
METHOD br_getSyncRootWithError: @24@0:8^@16
METHOD br_getTagNames:error: B32@0:8^@16^@24
METHOD br_isConflictedWithHandler: v24@0:8@?16
METHOD br_isDatalessWithError: @24@0:8^@16
METHOD br_isDocumentsContainer B16@0:8
METHOD br_isExistWithNonMateralizingIOPolicy: B20@0:8B16
METHOD br_isIgnoredByFileProvider B16@0:8
METHOD br_isIgnoredByFileProviderWithError: B24@0:8^@16
METHOD br_isInCloudDocsPrivateStoragesForRemoteDocumentVersions B16@0:8
METHOD br_isInLocalHomeDirectory B16@0:8
METHOD br_isInMobileDocuments B16@0:8
METHOD br_isInSharedDocsContainer B16@0:8
METHOD br_isInSyncedDesktop B16@0:8
METHOD br_isInSyncedDocuments B16@0:8
METHOD br_isInSyncedLocation B16@0:8
METHOD br_isInTrash B16@0:8
METHOD br_isModifiedSinceShared B16@0:8
METHOD br_isParentOfURL: B24@0:8@16
METHOD br_isParentOfURL:ignoreHomeDirectoryCheck: B28@0:8@16B24
METHOD br_isParentOfURL:strictly: B28@0:8@16B24
METHOD br_isRootOwned B16@0:8
METHOD br_isStrictlyInSyncedLocation B16@0:8
METHOD br_isSymLink B16@0:8
METHOD br_isTopLevelSharedItem B16@0:8
METHOD br_itemID @16@0:8
METHOD br_lastEditorDeviceName @16@0:8
METHOD br_lastEditorName @16@0:8
METHOD br_lastEditorNameComponents @16@0:8
METHOD br_logicalURL @16@0:8
METHOD br_mightBeBRAlias B16@0:8
METHOD br_pathRelativeToMobileDocuments @16@0:8
METHOD br_pathRelativeToSyncedRootURL:currentPersonaID: @32@0:8@16@24
METHOD br_pathRelativeToSyncedRootURLForContainerID: @24@0:8@16
METHOD br_physicalURL @16@0:8
METHOD br_preCacheBookmarkData:versionEtag: v32@0:8@16@24
METHOD br_realpathURL @16@0:8
METHOD br_realpathURLWithIsDirectory: @20@0:8B16
METHOD br_setAccessTime:error: B32@0:8Q16^@24
METHOD br_setTagNames:error: B32@0:8@16^@24
METHOD br_typeIdentifierWithError: @24@0:8^@16
METHOD br_wouldBeExcludedFromSync B16@0:8
METHOD brc_appContainerID @16@0:8
METHOD brc_isDirectory:isExists:withError: B40@0:8^B16^B24^@32
METHOD brc_issueSandboxExtensionOfClass:error: @32@0:8r*16^@24
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD fileName @16@0:8
METHOD isiWorkDocument B16@0:8
METHOD coordinateReadingWithSaveToTempDir:completionHandler: v28@0:8B16@?20
METHOD coordinateReadingWithSaveToTempDir:options:completionHandler: v36@0:8B16Q20@?28
METHOD issueSandboxExtensionData @16@0:8
METHOD valueForQueryKey: @24@0:8@16
METHOD fm_preferencesPathURLForDomain: @24@0:8@16
METHOD preferencesPathURLForDomain: @24@0:8@16
METHOD _NSItemProviderArchive_customArchiveDictionary @16@0:8
METHOD _NSItemProviderArchive_didUnarchiveCustomDictionary: v24@0:8@16
METHOD isJavaScriptURL B16@0:8
METHOD _domain:subdomain: v32@0:8^@16^@24
METHOD _setTitle: v24@0:8@16
METHOD _title @16@0:8
METHOD isAccountURL B16@0:8
METHOD isHTTPOrHTTPSURL B16@0:8
METHOD isInternalUIKitURL B16@0:8
METHOD isSpringboardHandledURL B16@0:8
METHOD isWebcalURL B16@0:8
METHOD phobosURL @16@0:8
METHOD radarWebURL @16@0:8
METHOD searchResultDomain @16@0:8
METHOD searchResultIdentifier @16@0:8
METHOD ui_URLByResolvingSymlinksAndCopyingSecurityScope @16@0:8
METHOD ui_bookmarkForExportWithError: @24@0:8^@16
METHOD ui_canOpenInPlace B16@0:8
METHOD ui_downloadOperationForActivity: @24@0:8@16
METHOD ui_downloadOperationForActivity:inScene: @32@0:8@16@24
METHOD ui_hasReadSandboxExtended B16@0:8
METHOD ui_hasSandboxExtendedForClass: B24@0:8r*16
METHOD ui_isContentManaged B16@0:8
METHOD ui_isFileProviderURL B16@0:8
METHOD ui_isUnfulfilledPromiseURL B16@0:8
METHOD ui_issueReadSandboxExtensionWithError: @24@0:8^@16
METHOD ui_issueReadWriteSandboxExtensionWithError: @24@0:8^@16
METHOD ui_issueSandboxExtensionOfClass:error: @32@0:8r*16^@24
METHOD ui_resolveOnDiskBookmarkAndPromise @16@0:8
METHOD ui_scheduleForCleanup v16@0:8
METHOD ui_setIsContentManaged: v20@0:8B16
METHOD ui_setIsFileProviderURL: v20@0:8B16
METHOD _web_userVisibleString @16@0:8
METHOD _webkit_URLByRemovingFragment @16@0:8
METHOD _web_URLCString r*16@0:8
METHOD _web_schemeData @16@0:8
METHOD _web_hostString @16@0:8
METHOD _web_URLByRemovingUserInfo @16@0:8
METHOD _web_hostData @16@0:8
METHOD _web_isEmpty B16@0:8
METHOD _web_originalData @16@0:8
METHOD _web_originalDataAsString @16@0:8
METHOD _webkit_URLFromURLOrSchemelessFileURL @16@0:8
METHOD _webkit_canonicalize @16@0:8
METHOD _webkit_canonicalize_with_wtf @16@0:8
METHOD _webkit_isFileURL B16@0:8
METHOD _webkit_isJavaScriptURL B16@0:8
METHOD _webkit_scriptIfJavaScriptURL @16@0:8
METHOD _webkit_suggestedFilenameWithMIMEType: @24@0:8@16
METHOD _pb_isDirectory B16@0:8
METHOD _pb_isFileProvider B16@0:8
METHOD _web_setTitle: v24@0:8@16
METHOD _web_title @16@0:8
METHOD _isDeallocating B16@0:8
METHOD release Vv16@0:8
METHOD dealloc v16@0:8
METHOD _tryRetain B16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD isKindOfClass: B24@0:8#16
METHOD isMemberOfClass: B24@0:8#16
METHOD retain @16@0:8
METHOD retainCount Q16@0:8
METHOD baseURL @16@0:8
METHOD URLByAppendingPathExtension: @24@0:8@16
METHOD URLByDeletingPathExtension @16@0:8
METHOD _cfTypeID Q16@0:8
METHOD URLByDeletingLastPathComponent @16@0:8
METHOD initWithString: @24@0:8@16
METHOD _cfurl ^{__CFURL=}16@0:8
METHOD _encoding I16@0:8
METHOD absoluteString @16@0:8
METHOD absoluteURL @16@0:8
METHOD checkResourceIsReachableAndReturnError: B24@0:8^@16
METHOD encodeWithCoder: v24@0:8@16
METHOD fragment @16@0:8
METHOD getFileSystemRepresentation:maxLength: B32@0:8*16Q24
METHOD hasDirectoryPath B16@0:8
METHOD host @16@0:8
METHOD initFileURLWithPath: @24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD isFileURL B16@0:8
METHOD isNSURL__ B16@0:8
METHOD lastPathComponent @16@0:8
METHOD password @16@0:8
METHOD path @16@0:8
METHOD pathExtension @16@0:8
METHOD port @16@0:8
METHOD query @16@0:8
METHOD relativeString @16@0:8
METHOD scheme @16@0:8
METHOD user @16@0:8
METHOD URLByAppendingPathComponent: @24@0:8@16
METHOD URLByStandardizingPath @16@0:8
METHOD parameterString @16@0:8
METHOD _URLByEscapingSpacesAndControlChars @16@0:8
METHOD standardizedURL @16@0:8
METHOD URLByAppendingPathComponent:isDirectory: @28@0:8@16B24
METHOD URLByResolvingSymlinksInPath @16@0:8
METHOD _URLArchive @16@0:8
METHOD _clientsCreatingIfNecessary: ^{__CFDictionary=}20@0:8B16
METHOD _fixedUpSideFaultError: @24@0:8@16
METHOD _freeClients v16@0:8
METHOD _hostString @16@0:8
METHOD _initFileURLWithPath:cachingResourceValuesForKeys:error: @40@0:8@16@24^@32
METHOD _isAbsolute B16@0:8
METHOD _parameterString @16@0:8
METHOD _performWithPhysicalURL: v24@0:8@?16
METHOD _promiseExtensionConsume q16@0:8
METHOD _promiseExtensionRelease: v24@0:8q16
METHOD _securePath @16@0:8
METHOD _trueSelf @16@0:8
METHOD _valueFromFaultDictionary:forKey: @32@0:8@16@24
METHOD _web_URLByRemovingLastPathComponent_nowarn @16@0:8
METHOD _web_URLByRemovingUserAndPath_nowarn @16@0:8
METHOD _web_URLByRemovingUserAndQueryAndFragment_nowarn @16@0:8
METHOD _web_URLComponents {?=@@@@q@@@}16@0:8
METHOD _web_isJavaScriptURL B16@0:8
METHOD _web_scriptIfJavaScriptURL @16@0:8
METHOD _web_suggestedFilenameWithMIMEType: @24@0:8@16
METHOD checkPromisedItemIsReachableAndReturnError: B24@0:8^@16
METHOD dataRepresentation @16@0:8
METHOD fileSystemRepresentation r*16@0:8
METHOD getPromisedItemResourceValue:forKey:error: B40@0:8o^@16@24o^@32
METHOD initAbsoluteURLWithDataRepresentation:relativeToURL: @32@0:8@16@24
METHOD initByResolvingAliasFileAtURL:options:error: @40@0:8@16Q24^@32
METHOD initByResolvingBookmarkData:options:relativeToURL:bookmarkDataIsStale:error: @56@0:8@16Q24@32^B40^@48
METHOD initFileURLWithFileSystemRepresentation:isDirectory:relativeToURL: @36@0:8r*16B24@28
METHOD initFileURLWithPath:isDirectory: @28@0:8@16B24
METHOD initFileURLWithPath:isDirectory:relativeToURL: @36@0:8@16B24@28
METHOD initFileURLWithPath:relativeToURL: @32@0:8@16@24
METHOD initWithDataRepresentation:relativeToURL: @32@0:8@16@24
METHOD initWithScheme:host:path: @40@0:8@16@24@32
METHOD initWithString:encodingInvalidCharacters: @28@0:8@16B24
METHOD initWithString:relativeToURL: @32@0:8@16@24
METHOD initWithString:relativeToURL:encodingInvalidCharacters: @36@0:8@16@24B32
METHOD loadDataWithTypeIdentifier:forItemProviderCompletionHandler: @32@0:8@16@?24
METHOD pathComponents @16@0:8
METHOD promisedItemResourceValuesForKeys:error: @32@0:8@16^@24
METHOD relativePath @16@0:8
METHOD resourceSpecifier @16@0:8
METHOD writableTypeIdentifiersForItemProvider @16@0:8
METHOD mapsURL @16@0:8
METHOD fmipURL @16@0:8
METHOD conformsToOverridePatternWithKey: B24@0:8@16
METHOD fmfURL @16@0:8
METHOD iCloudEmailPrefsURL @16@0:8
METHOD iCloudSharingURL @16@0:8
METHOD iCloudSharingURL_noFragment @16@0:8
METHOD iTunesStoreURL @16@0:8
METHOD iWorkApplicationName @16@0:8
METHOD iWorkDocumentName @16@0:8
METHOD isiWorkURL B16@0:8
METHOD keynoteLiveURL @16@0:8
METHOD keynoteLiveURL_noFragment @16@0:8
METHOD ls_preferredLocalizations @16@0:8
METHOD ls_setPreferredLocalizations: v24@0:8@16
METHOD photosURL @16@0:8
METHOD MI_URLByAppendingPathComponents:lastIsDirectory: @28@0:8@16B24
METHOD MI_allAccessURLs @16@0:8
METHOD _URLByInsertingResolveFlags: @20@0:8I16
METHOD _URLByRemovingResolveFlags @16@0:8
METHOD _resolveFlags I16@0:8
METHOD bookmarkDataWithOptions:includingResourceValuesForKeys:relativeToURL:error: @48@0:8Q16@24@32^@40
METHOD filePathURL @16@0:8
METHOD fileReferenceURL @16@0:8
METHOD getResourceValue:forKey:error: B40@0:8o^@16@24o^@32
METHOD isFileReferenceURL B16@0:8
METHOD removeAllCachedResourceValues v16@0:8
METHOD removeCachedResourceValueForKey: v24@0:8@16
METHOD resourceValuesForKeys:error: @32@0:8@16^@24
METHOD setResourceValue:forKey:error: B40@0:8@16@24^@32
METHOD setResourceValues:error: B32@0:8@16^@24
METHOD setTemporaryResourceValue:forKey: v32@0:8@16@24
METHOD startAccessingSecurityScopedResource B16@0:8
METHOD stopAccessingSecurityScopedResource v16@0:8

=== CLASS NSUUID ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: BSXPCSecureCoding _PASDistilledString PQLValuable _OSXPCObjectRepresentable NSCopying NSSecureCoding
CMETHOD _LS_UUIDWithData:digestType: @32@0:8@16q24
CMETHOD _LS_nullUUID @16@0:8
CMETHOD supportsBSXPCSecureCoding B16@0:8
CMETHOD _geo_uuidForHighBytes:lowBytes: @32@0:8Q16Q24
CMETHOD _geo_dataForUUID @16@0:8
CMETHOD _geo_dataForWaypointUUID: @24@0:8@16
CMETHOD _geo_uuidForData: @24@0:8@16
CMETHOD _geo_uuidForWaypointUUID: @24@0:8@16
CMETHOD _geo_waypointUUIDForData: @24@0:8@16
CMETHOD _maps_UUIDWithData: @24@0:8@16
CMETHOD _IS_UUIDByXORingUUIDs: @24@0:8@16
CMETHOD _IS_UUIDWithBytes:size: @32@0:8r*16Q24
CMETHOD _IS_UUIDWithData: @24@0:8@16
CMETHOD _IS_UUIDWithInt64: @24@0:8q16
CMETHOD _IS_UUIDWithOSType: @20@0:8I16
CMETHOD _IS_UUIDWithString: @24@0:8@16
CMETHOD _IS_nullUUID @16@0:8
CMETHOD newFromSqliteStatement:atIndex: @28@0:8^{sqlite3_stmt=}16i24
CMETHOD newFromSqliteValue: @24@0:8^{sqlite3_value=}16
CMETHOD bm_bootSessionUUID @16@0:8
CMETHOD _IF_UUIDByXORingUUIDs: @24@0:8@16
CMETHOD _IF_UUIDWithBytes:size: @32@0:8r*16Q24
CMETHOD _IF_UUIDWithData: @24@0:8@16
CMETHOD _IF_UUIDWithDigestBytes:size: @32@0:8r^v16Q24
CMETHOD _IF_UUIDWithDouble: @24@0:8d16
CMETHOD _IF_UUIDWithInt64: @24@0:8q16
CMETHOD _IF_UUIDWithOSType: @20@0:8I16
CMETHOD _IF_UUIDWithString: @24@0:8@16
CMETHOD _IF_nullUUID @16@0:8
CMETHOD sa_deterministicUUIDv5ForNamespace:name: @32@0:8@16@24
CMETHOD sa_deterministicUUIDv5ForNamespaceUUID:sourceUUID: @32@0:8@16@24
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD supportsSecureCoding B16@0:8
CMETHOD UUID @16@0:8
CMETHOD _compatibilityBehavior B16@0:8
METHOD encodeWithBSXPCCoder: v24@0:8@16
METHOD initWithBSXPCCoder: @24@0:8@16
METHOD CKCompare: q24@0:8@16
METHOD ck_bindInStatement:atIndex: v32@0:8@16Q24
METHOD cksqlcs_blobBindingValue:destructor:error: r^v40@0:8^Q16^^?24^@32
METHOD _geo_data @16@0:8
METHOD _geo_getHighBytes:lowBytes: v32@0:8^Q16^Q24
METHOD _geo_waypointUUID @16@0:8
METHOD _maps_data @16@0:8
METHOD _axRecursivelyPropertyListCoercedRepresentationWithError: @24@0:8^@16
METHOD ak_uuidData @16@0:8
METHOD uuid @16@0:8
METHOD launchPersona @16@0:8
METHOD _pas_revivedString @16@0:8
METHOD encodeWithCSCoder: v24@0:8@16
METHOD fp_UUID @16@0:8
METHOD fp_UUIDWithObfuscation: @20@0:8B16
METHOD _IS_getUUIDBytes:hash64: v32@0:8*16^Q24
METHOD sqliteBind:index: v28@0:8^{sqlite3_stmt=}16i24
METHOD _OS_xpcObjectRepresentation @16@0:8
METHOD si_uuidBytes @16@0:8
METHOD MDUUIDData @16@0:8
METHOD _IF_getUUIDBytes:hash64: v32@0:8*16^Q24
METHOD sa_uuidBytes @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD UUIDString @16@0:8
METHOD classForCoder #16@0:8
METHOD compare: q24@0:8@16
METHOD encodeWithCoder: v24@0:8@16
METHOD getUUIDBytes: v24@0:8[16C]16
METHOD initWithCoder: @24@0:8@16
METHOD _cfUUIDString ^{__CFString=}16@0:8
METHOD initWithUUIDBytes: @24@0:8[16C]16
METHOD initWithUUIDString: @24@0:8@16

=== CLASS NSUserDefaults ===
SUPER: NSObject
SIZE: 40
IVAR +8 0 _kvo_ @
IVAR +16 0 _identifier_ ^{__CFString=}
IVAR +24 0 _container_ ^{__CFString=}
IVAR +32 0 _volatileDomainNames @"NSArray"
CMETHOD standardUserDefaults @16@0:8
CMETHOD _copyStandardUserDefaultsIfPresent @16@0:8
CMETHOD _web_addDefaultsChangeObserver v16@0:8
CMETHOD _web_defaultsDidChange v16@0:8
CMETHOD _web_preferredLanguageCode @16@0:8
CMETHOD resetStandardUserDefaults v16@0:8
CMETHOD setStandardUserDefaults: v24@0:8@16
CMETHOD _IMAgentObjectForKey: @24@0:8@16
CMETHOD _IMAppObjectForKey: @24@0:8@16
CMETHOD _IMObjectForKey:inDomain: @32@0:8@16@24
CMETHOD _IMSetObject:forKey:inDomain: v40@0:8@16@24@32
CMETHOD _webkit_preferredLanguageCode @16@0:8
CMETHOD c2DefaultsDomain @16@0:8
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD boolForKey: B24@0:8@16
METHOD objectForKey: @24@0:8@16
METHOD removeObjectForKey: v24@0:8@16
METHOD setObject:forKey: v32@0:8@16@24
METHOD synchronize B16@0:8
METHOD volatileDomainNames @16@0:8
METHOD setBool:forKey: v28@0:8B16@20
METHOD URLForKey: @24@0:8@16
METHOD setLong:forKey: v32@0:8q16@24
METHOD _didEndKeyValueObserving v16@0:8
METHOD _initWithSuiteName:container: @32@0:8@16@24
METHOD _willBeginKeyValueObserving v16@0:8
METHOD addSuiteNamed: v24@0:8@16
METHOD arrayForKey: @24@0:8@16
METHOD dataForKey: @24@0:8@16
METHOD dictionaryForKey: @24@0:8@16
METHOD dictionaryRepresentation @16@0:8
METHOD doubleForKey: d24@0:8@16
METHOD floatForKey: f24@0:8@16
METHOD initWithSuiteName: @24@0:8@16
METHOD initWithUser: @24@0:8@16
METHOD integerForKey: q24@0:8@16
METHOD longForKey: q24@0:8@16
METHOD objectForKey:inDomain: @32@0:8@16@24
METHOD objectIsForcedForKey: B24@0:8@16
METHOD objectIsForcedForKey:inDomain: B32@0:8@16@24
METHOD persistentDomainForName: @24@0:8@16
METHOD persistentDomainNames @16@0:8
METHOD registerDefaults: v24@0:8@16
METHOD removeObjectForKey:inDomain: v32@0:8@16@24
METHOD removePersistentDomainForName: v24@0:8@16
METHOD removeSuiteNamed: v24@0:8@16
METHOD removeVolatileDomainForName: v24@0:8@16
METHOD searchList @16@0:8
METHOD setDouble:forKey: v32@0:8d16@24
METHOD setFloat:forKey: v28@0:8f16@20
METHOD setInteger:forKey: v32@0:8q16@24
METHOD setObject:forKey:inDomain: v40@0:8@16@24@32
METHOD setPersistentDomain:forName: v32@0:8@16@24
METHOD setSearchList: v24@0:8@16
METHOD setURL:forKey: v32@0:8@16@24
METHOD setValue:forKey: v32@0:8@16@24
METHOD setVolatileDomain:forName: v32@0:8@16@24
METHOD stringArrayForKey: @24@0:8@16
METHOD stringForKey: @24@0:8@16
METHOD valueForKey: @24@0:8@16
METHOD volatileDomainForName: @24@0:8@16
METHOD bs_defaultExists: B24@0:8@16
METHOD bs_setDomain: v24@0:8@16
METHOD boolValueSafeForKey: B24@0:8@16
METHOD boolValueSafeForKey:status: B32@0:8@16^i24
METHOD doubleValueSafeForKey: d24@0:8@16
METHOD doubleValueSafeForKey:status: d32@0:8@16^i24
METHOD int64ValueSafeForKey: q24@0:8@16
METHOD int64ValueSafeForKey:status: q32@0:8@16^i24
METHOD stringValueSafeForKey: @24@0:8@16
METHOD stringValueSafeForKey:status: @32@0:8@16^i24
METHOD utf8ValueSafeForKey: r*24@0:8@16
METHOD utf8ValueSafeForKey:status: r*32@0:8@16^i24
METHOD doc_roleSpecificKeyForKey:configuration: @32@0:8@16@24
METHOD doc_setObject:forRoleKey:configuation: v40@0:8@16@24@32
METHOD doc_roleSpecificKeyForKey:configuration: @32@0:8@16@24
METHOD doc_setObject:forRoleKey:configuation: v40@0:8@16@24@32
METHOD _setIdentifier: v24@0:8^{__CFString=}16
METHOD _container ^{__CFString=}16@0:8
METHOD _identifier ^{__CFString=}16@0:8
METHOD _kvo @16@0:8
METHOD _observingCFPreferences B16@0:8
METHOD _setContainer: v24@0:8^{__CFURL=}16
METHOD _setKVO: v24@0:8@16
METHOD volatileDomainNames @16@0:8

=== CLASS NSValue ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: BSXPCSecureCoding MTFilterIdentityValueProviding MTMaterialSettingsPropertyIdentityValueProviding NSCopying NSSecureCoding
CMETHOD bs_valueWithCGAffineTransform: @64@0:8{CGAffineTransform=dddddd}16
CMETHOD bs_valueWithCGPoint: @32@0:8{CGPoint=dd}16
CMETHOD bs_valueWithCGRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
CMETHOD bs_valueWithCGSize: @32@0:8{CGSize=dd}16
CMETHOD supportsBSXPCSecureCoding B16@0:8
CMETHOD UIF_valueWithLineBreakContext: @40@0:8{?=QQB}16
CMETHOD valueWithCGAffineTransform: @64@0:8{CGAffineTransform=dddddd}16
CMETHOD valueWithUIEdgeInsets: @48@0:8{UIEdgeInsets=dddd}16
CMETHOD valueWithDirectionalEdgeInsets: @48@0:8{NSDirectionalEdgeInsets=dddd}16
CMETHOD _valueWithPressTrigger: @48@0:8{_UIPressTrigger=qqdB}16
CMETHOD _valueWithUICornerInsets: @80@0:8{_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16
CMETHOD _valueWithUIRectCornerRadii: @48@0:8{UIRectCornerRadii=dddd}16
CMETHOD valueWithCGPoint: @32@0:8{CGPoint=dd}16
CMETHOD valueWithCGRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
CMETHOD valueWithCGSize: @32@0:8{CGSize=dd}16
CMETHOD valueWithCGVector: @32@0:8{CGVector=dd}16
CMETHOD valueWithNSDirectionalEdgeInsets: @48@0:8{NSDirectionalEdgeInsets=dddd}16
CMETHOD valueWithUIKBHandwritingPoint: @40@0:8{?={CGPoint=dd}d}16
CMETHOD valueWithUIOffset: @32@0:8{UIOffset=dd}16
CMETHOD valueWithUISize3D: @40@0:8{?=ddd}16
CMETHOD _geo_valueWithGEOPlaceDataComponentKey: @32@0:8(_GEOPlaceDataComponentKey={?=QSSI}{?=IIII})16
CMETHOD valueWithCAColorMatrix: @96@0:8{CAColorMatrix=ffffffffffffffffffff}16
CMETHOD valueWithCACornerRadii: @80@0:8{CACornerRadii={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16
CMETHOD valueWithCATransform3D: @144@0:8{CATransform3D=dddddddddddddddd}16
CMETHOD valueWithCAPoint3D: @40@0:8{CAPoint3D=ddd}16
CMETHOD valueWithCGMatrixFilter: @96@0:8{CGMatrixFilter=ffffffffffffffffffff}16
CMETHOD _web_valueWithCGRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
CMETHOD valueWithCGAffineTransform: @64@0:8{CGAffineTransform=dddddd}16
CMETHOD valueWithDeltaScalars: @32@0:8{?=dd}16
CMETHOD mt_identityValueForFilter: @24@0:8@16
CMETHOD mt_identityValueForMaterialSettingsProperty: @24@0:8@16
CMETHOD SCN_valueWithCGPoint: @32@0:8{CGPoint=dd}16
CMETHOD SCN_valueWithSimdMatrix4: @80@0:8{?=[4]}16
CMETHOD valueWithSCNMatrix4: @80@0:8{SCNMatrix4=ffffffffffffffff}16
CMETHOD valueWithSCNVector3: @28@0:8{SCNVector3=fff}16
CMETHOD valueWithSCNVector4: @32@0:8{SCNVector4=ffff}16
CMETHOD avt_valueWithFloat3: @32@0:816
CMETHOD avt_valueWithFloat3_usableWithKVCForSCNVector3: @32@0:816
CMETHOD avt_valueWithFloat4: @32@0:816
CMETHOD avt_valueWithFloat4_usableWithKVCForSCNVector4: @32@0:816
CMETHOD avt_valueWithFloat4x4: @80@0:8{?=[4]}16
CMETHOD valueWithCGPoint: @32@0:8{CGPoint=dd}16
CMETHOD valueWithCMTime: @40@0:8{?=qiIq}16
CMETHOD valueWithCMTimeRange: @64@0:8{?={?=qiIq}{?=qiIq}}16
CMETHOD valueWithCMTimeMapping: @112@0:8{?={?={?=qiIq}{?=qiIq}}{?={?=qiIq}{?=qiIq}}}16
CMETHOD valueWithCMVideoDimensions: @24@0:8{?=ii}16
CMETHOD valueWithCLLocationCoordinate2D: @32@0:8{CLLocationCoordinate2D=dd}16
CMETHOD valueWithCMTime: @40@0:8{?=qiIq}16
CMETHOD valueWithCMTimeRange: @64@0:8{?={?=qiIq}{?=qiIq}}16
CMETHOD valueWithCMTimeMapping: @112@0:8{?={?={?=qiIq}{?=qiIq}}{?={?=qiIq}{?=qiIq}}}16
CMETHOD valueWithCMVideoDimensions: @24@0:8{?=ii}16
CMETHOD valueWithMIORange: @32@0:8{_MIORange=qq}16
CMETHOD valueWithMatrix4: @24@0:8@16
CMETHOD valueWithVector3: @24@0:8@16
CMETHOD valueWithVector4: @24@0:8@16
CMETHOD valueWithVFXFloat2: @24@0:816
CMETHOD valueWithVFXFloat3: @32@0:816
CMETHOD valueWithVFXMatrix4: @80@0:8{?=[4]}16
CMETHOD valueWithVFXFloat4: @32@0:816
CMETHOD VFXJSExportProtocol @16@0:8
CMETHOD VFX_valueWithCGPoint: @32@0:8{CGPoint=dd}16
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD supportsSecureCoding B16@0:8
CMETHOD valueWithRange: @32@0:8{_NSRange=QQ}16
CMETHOD valueWithPoint: @32@0:8{CGPoint=dd}16
CMETHOD value:withObjCType: @32@0:8r^v16r*24
CMETHOD valueWithBytes:objCType: @32@0:8r^v16r*24
CMETHOD valueWithEdgeInsets: @48@0:8{NSEdgeInsets=dddd}16
CMETHOD valueWithNonretainedObject: @24@0:8@16
CMETHOD valueWithPointer: @24@0:8r^v16
CMETHOD valueWithRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
CMETHOD valueWithSize: @32@0:8{CGSize=dd}16
CMETHOD valueWithWeakObject: @24@0:8@16
METHOD bs_CGPointValue {CGPoint=dd}16@0:8
METHOD bs_CGAffineTransformValue {CGAffineTransform=dddddd}16@0:8
METHOD bs_CGRectValue {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD bs_CGSizeValue {CGSize=dd}16@0:8
METHOD bs_getValue:ofSize: B32@0:8o^v16Q24
METHOD encodeWithBSXPCCoder: v24@0:8@16
METHOD initWithBSXPCCoder: @24@0:8@16
METHOD supportsBSXPCSecureCoding B16@0:8
METHOD UIF_lineBreakContextValue {?=QQB}16@0:8
METHOD CGPointValue {CGPoint=dd}16@0:8
METHOD CGAffineTransformValue {CGAffineTransform=dddddd}16@0:8
METHOD CGRectValue {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD UIEdgeInsetsValue {UIEdgeInsets=dddd}16@0:8
METHOD CGVectorValue {CGVector=dd}16@0:8
METHOD CGSizeValue {CGSize=dd}16@0:8
METHOD UIKBHandwritingPointValue {?={CGPoint=dd}d}16@0:8
METHOD UIOffsetValue {UIOffset=dd}16@0:8
METHOD UISize3DValue {?=ddd}16@0:8
METHOD _UICornerInsetsValue {_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD _UIPressTriggerValue {_UIPressTrigger=qqdB}16@0:8
METHOD _UIRectCornerRadiiValue {UIRectCornerRadii=dddd}16@0:8
METHOD directionalEdgeInsetsValue {NSDirectionalEdgeInsets=dddd}16@0:8
METHOD _geo_GEOPlaceDataComponentKeyValue (_GEOPlaceDataComponentKey={?=QSSI}{?=IIII})16@0:8
METHOD CA_addValue:multipliedBy: @28@0:8@16i24
METHOD CA_distanceToValue: d24@0:8@16
METHOD CA_numericValueCount Q16@0:8
METHOD CA_interpolateValue:byFraction: @28@0:8@16f24
METHOD CAColorMatrixValue {CAColorMatrix=ffffffffffffffffffff}16@0:8
METHOD CACornerRadiiValue {CACornerRadii={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD CATransform3DValue {CATransform3D=dddddddddddddddd}16@0:8
METHOD CA_copyRenderValue ^{Object=^^?{Atomic={?=i}}b8b24}16@0:8
METHOD CA_interpolateValues:::interpolator: @48@0:8@16@24@32r^{ValueInterpolator=ddddddddddddddB}40
METHOD CAMLType @16@0:8
METHOD CAPoint3DValue {CAPoint3D=ddd}16@0:8
METHOD CA_CGAffineTransformValue {CGAffineTransform=dddddd}16@0:8
METHOD CA_copyNumericValue: Q24@0:8^d16
METHOD CA_roundToIntegerFromValue: @24@0:8@16
METHOD encodeWithCAMLWriter: v24@0:8@16
METHOD CGMatrixFilterValue {CGMatrixFilter=ffffffffffffffffffff}16@0:8
METHOD CGSizeValue {CGSize=dd}16@0:8
METHOD _web_CGRectValue {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD cgAffineTransformValue {CGAffineTransform=dddddd}16@0:8
METHOD deltaScalarsValue {?=dd}16@0:8
METHOD mt_isIdentityValueForFilter: B24@0:8@16
METHOD mt_isIdentityValueForMaterialSettingsProperty: B24@0:8@16
METHOD SCNMatrix4Value {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD SCNVector4Value {SCNVector4=ffff}16@0:8
METHOD SCNVector3Value {SCNVector3=fff}16@0:8
METHOD SCN_CGPointValue {CGPoint=dd}16@0:8
METHOD SCN_simdMatrix4Value {?=[4]}16@0:8
METHOD avt_float3Value 16@0:8
METHOD avt_float4Value 16@0:8
METHOD avt_float4x4Value {?=[4]}16@0:8
METHOD CGPointValue {CGPoint=dd}16@0:8
METHOD CMTimeRangeValue {?={?=qiIq}{?=qiIq}}16@0:8
METHOD CMTimeValue {?=qiIq}16@0:8
METHOD CMVideoDimensionsValue {?=ii}16@0:8
METHOD CMTimeMappingValue {?={?={?=qiIq}{?=qiIq}}{?={?=qiIq}{?=qiIq}}}16@0:8
METHOD CMTimeRangeValue {?={?=qiIq}{?=qiIq}}16@0:8
METHOD CMTimeValue {?=qiIq}16@0:8
METHOD CMVideoDimensionsValue {?=ii}16@0:8
METHOD CMTimeMappingValue {?={?={?=qiIq}{?=qiIq}}{?={?=qiIq}{?=qiIq}}}16@0:8
METHOD MIORangeValue {_MIORange=qq}16@0:8
METHOD vector3 @16@0:8
METHOD matrix4 @16@0:8
METHOD vector4 @16@0:8
METHOD VFXFloat4Value 16@0:8
METHOD VFXFloat3Value 16@0:8
METHOD VFXFloat2Value 16@0:8
METHOD VFXMatrix4Value {?=[4]}16@0:8
METHOD VFX_numberOfChannels i16@0:8
METHOD VFX_valueForKey: @24@0:8@16
METHOD VFX_Description @16@0:8
METHOD VFX_CGPointValue {CGPoint=dd}16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD objCType r*16@0:8
METHOD classForCoder #16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD getValue: v24@0:8^v16
METHOD initWithCoder: @24@0:8@16
METHOD isNSValue__ B16@0:8
METHOD isEqualToValue: B24@0:8@16
METHOD edgeInsetsValue {NSEdgeInsets=dddd}16@0:8
METHOD weakObjectValue @16@0:8
METHOD _matchType:size: B32@0:8r*16Q24
METHOD _matchType:size:strict: B36@0:8r*16Q24B32
METHOD getValue:size: v32@0:8^v16Q24
METHOD initWithBytes:objCType: @32@0:8r^v16r*24
METHOD nonretainedObjectValue @16@0:8
METHOD pointValue {CGPoint=dd}16@0:8
METHOD pointerValue ^v16@0:8
METHOD rangeValue {_NSRange=QQ}16@0:8
METHOD rectValue {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD replacementObjectForPortCoder: @24@0:8@16
METHOD sizeValue {CGSize=dd}16@0:8

=== CLASS SCNCamera ===
SUPER: NSObject
SIZE: 440
PROTOCOLS: SCNAnimatable SCNTechniqueSupport NSCopying NSSecureCoding
IVAR +8 0 _camera ^{__C3DCamera={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}{?=b1b1b1b1b1b1b1dddfd(C3DMatrix4x4=[16f][4]{?=[4]}){?=[4]}dd}ffffiib1b1b1b1b1C(C3DMatrix4x4=[16f][4]{?=[4]})ffffffffffffiffffffffffffff{?=fffffii}^{__C3DEffectSlot}Q^{__C3DFXTechnique}^vf}
IVAR +16 0 _isPresentationInstance b1
IVAR +16 0 _custom b1
IVAR +16 0 _legacyFov b1
IVAR +16 0 _usesOrthographicProjection b1
IVAR +16 0 _automaticallyAdjustsZRange b1
IVAR +16 0 _fillMode b1
IVAR +16 0 _projectionDirection b1
IVAR +20 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +24 0 _animations @"SCNOrderedDictionary"
IVAR +32 0 _bindings @"NSMutableDictionary"
IVAR +40 0 _name @"NSString"
IVAR +48 0 _xFov f
IVAR +52 0 _yFov f
IVAR +56 0 _orthographicScale d
IVAR +64 0 _zNear d
IVAR +72 0 _zFar d
IVAR +80 0 _fieldOfView f
IVAR +84 0 _focalLength f
IVAR +88 0 _sensorSize f
IVAR +96 0 _lensShift 
IVAR +104 0 _postProjectionTransformTranslation 
IVAR +112 0 _postProjectionTransformScale 
IVAR +120 0 _fStop f
IVAR +124 0 _focusDistance f
IVAR +128 0 _dofIntensity f
IVAR +136 0 _bladeCount q
IVAR +144 0 _focalBlurSampleCount q
IVAR +152 0 _aspectRatio f
IVAR +160 0 _categoryBitMask Q
IVAR +168 0 _projectionTransform {SCNMatrix4="m11"f"m12"f"m13"f"m14"f"m21"f"m22"f"m23"f"m24"f"m31"f"m32"f"m33"f"m34"f"m41"f"m42"f"m43"f"m44"f}
IVAR +232 0 _technique @"SCNTechnique"
IVAR +240 0 _colorGrading @"SCNMaterialProperty"
IVAR +248 0 _wantsHDR B
IVAR +252 0 _whitePoint f
IVAR +256 0 _averageGray f
IVAR +260 0 _exposureOffset f
IVAR +264 0 _minimumExposure f
IVAR +268 0 _maximumExposure f
IVAR +272 0 _wantsExposureAdaptation B
IVAR +276 0 _exposureAdaptationDuration f
IVAR +280 0 _exposureAdaptationBrighteningSpeedFactor f
IVAR +284 0 _exposureAdaptationDarkeningSpeedFactor f
IVAR +288 0 _exposureAdaptationHistogramRangeHighProbability d
IVAR +296 0 _exposureAdaptationHistogramRangeLowProbability d
IVAR +304 0 _exposureAdaptationMode q
IVAR +312 0 _bloomIntensity f
IVAR +316 0 _bloomThreshold f
IVAR +320 0 _bloomIteration i
IVAR +324 0 _bloomIterationSpread f
IVAR +328 0 _bloomBlurRadius f
IVAR +332 0 _motionBlurIntensity f
IVAR +336 0 _vignettingPower f
IVAR +340 0 _vignettingIntensity f
IVAR +344 0 _colorFringeStrength f
IVAR +348 0 _colorFringeIntensity f
IVAR +352 0 _saturation f
IVAR +356 0 _contrast f
IVAR +360 0 _grainIntensity f
IVAR +364 0 _grainScale f
IVAR +368 0 _grainIsColored B
IVAR +372 0 _whiteBalanceTemperature f
IVAR +376 0 _whiteBalanceTint f
IVAR +384 0 _screenSpaceAmbientOcclusion {?="intensity"f"radius"f"bias"f"depthThreshold"f"normalThreshold"f"sampleCount"q"downSample"q}
IVAR +424 0 _grainTexture @"<MTLTexture>"
IVAR +432 0 _grainSlice f
CMETHOD supportsSecureCoding B16@0:8
CMETHOD camera @16@0:8
CMETHOD cameraWithCameraRef: @24@0:8^{__C3DCamera={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}{?=b1b1b1b1b1b1b1dddfd(C3DMatrix4x4=[16f][4]{?=[4]}){?=[4]}dd}ffffiib1b1b1b1b1C(C3DMatrix4x4=[16f][4]{?=[4]})ffffffffffffiffffffffffffff{?=fffffii}^{__C3DEffectSlot}Q^{__C3DFXTechnique}^vf}16
CMETHOD cameraWithMDLCamera: @24@0:8@16
CMETHOD keyPathsForValuesAffectingFieldOfView @16@0:8
CMETHOD keyPathsForValuesAffectingFocalLength @16@0:8
METHOD avt_setSimdProjectionTransform: v80@0:8{?=[4]}16
METHOD avt_simdPostProjectionTransform {?=[3]}16@0:8
METHOD avt_setSimdPostProjectionTransform: v64@0:8{?=[3]}16
METHOD avt_simdProjectionTransform {?=[4]}16@0:8
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD setName: v24@0:8@16
METHOD setIdentifier: v24@0:8@16
METHOD setAspectRatio: v24@0:8d16
METHOD setFocalLength: v24@0:8d16
METHOD aspectRatio d16@0:8
METHOD contrast d16@0:8
METHOD debugQuickLookObject @16@0:8
METHOD focalLength d16@0:8
METHOD saturation d16@0:8
METHOD setContrast: v24@0:8d16
METHOD setSaturation: v24@0:8d16
METHOD whitePoint d16@0:8
METHOD categoryBitMask Q16@0:8
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationForKey: @24@0:8@16
METHOD animationKeys @16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD scene @16@0:8
METHOD setCategoryBitMask: v24@0:8Q16
METHOD setFillMode: v24@0:8q16
METHOD fillMode q16@0:8
METHOD aperture d16@0:8
METHOD setAperture: v24@0:8d16
METHOD _registerAsObserver v16@0:8
METHOD setFieldOfView: v24@0:8d16
METHOD apertureBladeCount q16@0:8
METHOD fStop d16@0:8
METHOD fieldOfView d16@0:8
METHOD focusDistance d16@0:8
METHOD setApertureBladeCount: v24@0:8q16
METHOD setFStop: v24@0:8d16
METHOD setFocusDistance: v24@0:8d16
METHOD setZFar: v24@0:8d16
METHOD setZNear: v24@0:8d16
METHOD zFar d16@0:8
METHOD zNear d16@0:8
METHOD bloomBlurRadius d16@0:8
METHOD minimumExposure d16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD screenSpaceAmbientOcclusionBias d16@0:8
METHOD vignettingPower d16@0:8
METHOD focalBlurRadius d16@0:8
METHOD __CFObject ^v16@0:8
METHOD maximumExposure d16@0:8
METHOD setAverageGray: v24@0:8d16
METHOD _checkSettingsConsistency v16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _customEncodingOfSCNCamera: v24@0:8@16
METHOD _didDecodeSCNCamera: v24@0:8@16
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _scnAnimationForKey: @24@0:8@16
METHOD _scnBindings @16@0:8
METHOD _syncEntityObjCModel v16@0:8
METHOD _syncObjCAnimations v16@0:8
METHOD _syncObjCModel v16@0:8
METHOD _updateFieldOfView v16@0:8
METHOD _updateFocalLength v16@0:8
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__C3DAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD automaticallyAdjustsZRange B16@0:8
METHOD averageGray d16@0:8
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD bloomIntensity d16@0:8
METHOD bloomIteration q16@0:8
METHOD bloomIterationCount q16@0:8
METHOD bloomIterationSpread d16@0:8
METHOD bloomThreshold d16@0:8
METHOD cameraRef ^{__C3DCamera={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}{?=b1b1b1b1b1b1b1dddfd(C3DMatrix4x4=[16f][4]{?=[4]}){?=[4]}dd}ffffiib1b1b1b1b1C(C3DMatrix4x4=[16f][4]{?=[4]})ffffffffffffiffffffffffffff{?=fffffii}^{__C3DEffectSlot}Q^{__C3DFXTechnique}^vf}16@0:8
METHOD colorFringeIntensity d16@0:8
METHOD colorFringeStrength d16@0:8
METHOD colorGrading @16@0:8
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD debugQuickLookData @16@0:8
METHOD dofIntensity f16@0:8
METHOD exposureAdaptationBrighteningSpeedFactor d16@0:8
METHOD exposureAdaptationDarkeningSpeedFactor d16@0:8
METHOD exposureAdaptationDuration d16@0:8
METHOD exposureAdaptationHistogramRangeHighProbability d16@0:8
METHOD exposureAdaptationHistogramRangeLowProbability d16@0:8
METHOD exposureAdaptationMode q16@0:8
METHOD exposureOffset d16@0:8
METHOD fieldOfViewOrientation q16@0:8
METHOD focalBlurSampleCount q16@0:8
METHOD focalDistance d16@0:8
METHOD focalSize d16@0:8
METHOD grainIntensity d16@0:8
METHOD grainIsColored B16@0:8
METHOD grainScale d16@0:8
METHOD grainSlice d16@0:8
METHOD grainTexture @16@0:8
METHOD hasCustomProjectionTransform B16@0:8
METHOD initPresentationCameraWithCameraRef: @24@0:8^{__C3DCamera={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}{?=b1b1b1b1b1b1b1dddfd(C3DMatrix4x4=[16f][4]{?=[4]}){?=[4]}dd}ffffiib1b1b1b1b1C(C3DMatrix4x4=[16f][4]{?=[4]})ffffffffffffiffffffffffffff{?=fffffii}^{__C3DEffectSlot}Q^{__C3DFXTechnique}^vf}16
METHOD initWithCameraRef: @24@0:8^{__C3DCamera={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}{?=b1b1b1b1b1b1b1dddfd(C3DMatrix4x4=[16f][4]{?=[4]}){?=[4]}dd}ffffiib1b1b1b1b1C(C3DMatrix4x4=[16f][4]{?=[4]})ffffffffffffiffffffffffffff{?=fffffii}^{__C3DEffectSlot}Q^{__C3DFXTechnique}^vf}16
METHOD isAnimationForKeyPaused: B24@0:8@16
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD lensShift 16@0:8
METHOD motionBlurIntensity d16@0:8
METHOD orthographicScale d16@0:8
METHOD pauseAnimationForKey: v24@0:8@16
METHOD postProjectionTransform {CGAffineTransform=dddddd}16@0:8
METHOD presentationCamera @16@0:8
METHOD presentationInstance @16@0:8
METHOD projectionDirection q16@0:8
METHOD projectionTransform {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD projectionTransformWithViewportSize: {SCNMatrix4=ffffffffffffffff}32@0:8{CGSize=dd}16
METHOD removeAllAnimationsWithBlendOutDuration: v24@0:8d16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v32@0:8@16d24
METHOD removeAnimationForKey:fadeOutDuration: v32@0:8@16d24
METHOD resumeAnimationForKey: v24@0:8@16
METHOD sceneRef ^{__C3DScene=}16@0:8
METHOD screenSpaceAmbientOcclusionDepthThreshold d16@0:8
METHOD screenSpaceAmbientOcclusionDownSample q16@0:8
METHOD screenSpaceAmbientOcclusionIntensity d16@0:8
METHOD screenSpaceAmbientOcclusionNormalThreshold d16@0:8
METHOD screenSpaceAmbientOcclusionRadius d16@0:8
METHOD screenSpaceAmbientOcclusionSampleCount q16@0:8
METHOD sensorHeight d16@0:8
METHOD setAutomaticallyAdjustsZRange: v20@0:8B16
METHOD setBloomBlurRadius: v24@0:8d16
METHOD setBloomIntensity: v24@0:8d16
METHOD setBloomIteration: v24@0:8q16
METHOD setBloomIterationCount: v24@0:8q16
METHOD setBloomIterationSpread: v24@0:8d16
METHOD setBloomThreshold: v24@0:8d16
METHOD setColorFringeIntensity: v24@0:8d16
METHOD setColorFringeStrength: v24@0:8d16
METHOD setDofIntensity: v20@0:8f16
METHOD setExposureAdaptationBrighteningSpeedFactor: v24@0:8d16
METHOD setExposureAdaptationDarkeningSpeedFactor: v24@0:8d16
METHOD setExposureAdaptationDuration: v24@0:8d16
METHOD setExposureAdaptationHistogramRangeHighProbability: v24@0:8d16
METHOD setExposureAdaptationHistogramRangeLowProbability: v24@0:8d16
METHOD setExposureAdaptationMode: v24@0:8q16
METHOD setExposureOffset: v24@0:8d16
METHOD setFieldOfViewOrientation: v24@0:8q16
METHOD setFocalBlurRadius: v24@0:8d16
METHOD setFocalBlurSampleCount: v24@0:8q16
METHOD setFocalDistance: v24@0:8d16
METHOD setFocalSize: v24@0:8d16
METHOD setGrainIntensity: v24@0:8d16
METHOD setGrainIsColored: v20@0:8B16
METHOD setGrainScale: v24@0:8d16
METHOD setGrainSlice: v24@0:8d16
METHOD setGrainTexture: v24@0:8@16
METHOD setLensShift: v24@0:816
METHOD setMaximumExposure: v24@0:8d16
METHOD setMinimumExposure: v24@0:8d16
METHOD setMotionBlurIntensity: v24@0:8d16
METHOD setOrthographicScale: v24@0:8d16
METHOD setPostProjectionTransform: v64@0:8{CGAffineTransform=dddddd}16
METHOD setPostProjectionTransformScale: v24@0:816
METHOD setPostProjectionTransformTranslation: v24@0:816
METHOD setProjectionDirection: v24@0:8q16
METHOD setProjectionTransform: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD setScreenSpaceAmbientOcclusionBias: v24@0:8d16
METHOD setScreenSpaceAmbientOcclusionDepthThreshold: v24@0:8d16
METHOD setScreenSpaceAmbientOcclusionDownSample: v24@0:8q16
METHOD setScreenSpaceAmbientOcclusionIntensity: v24@0:8d16
METHOD setScreenSpaceAmbientOcclusionNormalThreshold: v24@0:8d16
METHOD setScreenSpaceAmbientOcclusionRadius: v24@0:8d16
METHOD setScreenSpaceAmbientOcclusionSampleCount: v24@0:8q16
METHOD setSensorHeight: v24@0:8d16
METHOD setSpeed:forAnimationKey: v32@0:8d16@24
METHOD setTechnique: v24@0:8@16
METHOD setUsesOrthographicProjection: v20@0:8B16
METHOD setVignettingIntensity: v24@0:8d16
METHOD setVignettingPower: v24@0:8d16
METHOD setWantsDepthOfField: v20@0:8B16
METHOD setWantsExposureAdaptation: v20@0:8B16
METHOD setWantsHDR: v20@0:8B16
METHOD setWhiteBalanceTemperature: v24@0:8d16
METHOD setWhiteBalanceTint: v24@0:8d16
METHOD setWhitePoint: v24@0:8d16
METHOD setXFov: v24@0:8d16
METHOD setXMag: v24@0:8d16
METHOD setYFov: v24@0:8d16
METHOD setYMag: v24@0:8d16
METHOD technique @16@0:8
METHOD unbindAnimatablePath: v24@0:8@16
METHOD useLegacyFov B16@0:8
METHOD usesOrthographicProjection B16@0:8
METHOD vignettingIntensity d16@0:8
METHOD wantsDepthOfField B16@0:8
METHOD wantsExposureAdaptation B16@0:8
METHOD wantsHDR B16@0:8
METHOD whiteBalanceTemperature d16@0:8
METHOD whiteBalanceTint d16@0:8
METHOD xFov d16@0:8
METHOD xMag d16@0:8
METHOD yFov d16@0:8
METHOD yMag d16@0:8

=== CLASS SCNGeometrySource ===
SUPER: NSObject
SIZE: 104
PROTOCOLS: NSSecureCoding
IVAR +8 0 _meshSource ^{__C3DMeshSource={__C3DGenericSource={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}
IVAR +16 0 _data @"NSData"
IVAR +24 0 _semantic @"NSString"
IVAR +32 0 _vectorCount q
IVAR +40 0 _componentType s
IVAR +42 0 _componentCount S
IVAR +48 0 _colorSpace ^{CGColorSpace=}
IVAR +56 0 _dataOffset q
IVAR +64 0 _dataStride q
IVAR +72 0 _mkSemantic C
IVAR +80 0 _mtlBuffer @"<MTLBuffer>"
IVAR +88 0 _mtlVertexFormat q
IVAR +96 0 _encodeDataAsHalf B
CMETHOD supportsSecureCoding B16@0:8
CMETHOD geometrySourceWithColorData:colorSpace:vectorCount:floatComponents:componentsPerVector:bytesPerComponent:dataOffset:dataStride: @76@0:8@16^{CGColorSpace=}24q32B40q44q52q60q68
CMETHOD _geometrySourceWithData:semantic:vectorCount:componentType:componentCount:dataOffset:dataStride: @68@0:8@16@24q32s40Q44q52q60
CMETHOD _geometrySourceWithSource:vertexFormat: @32@0:8@16Q24
CMETHOD dataByConvertingDoublesToFloats:count: @32@0:8r^d16q24
CMETHOD dataWithPointArray:count:bytesPerComponent: @40@0:8r^{CGPoint=dd}16q24^q32
CMETHOD dataWithVector3Array:count:bytesPerComponent: @40@0:8r^{SCNVector3=fff}16q24^q32
CMETHOD geometrySourceWithBuffer:vertexFormat:semantic:vertexCount:dataOffset:dataStride: @64@0:8@16Q24@32q40q48q56
CMETHOD geometrySourceWithColorComponents:count:hasAlpha:colorSpace: @44@0:8r^f16q24B32^{CGColorSpace=}36
CMETHOD geometrySourceWithData:semantic:vectorCount:floatComponents:componentsPerVector:bytesPerComponent:dataOffset:dataStride: @76@0:8@16@24q32B40q44q52q60q68
CMETHOD geometrySourceWithMDLVertexAttribute:mesh: @32@0:8@16@24
CMETHOD geometrySourceWithMeshSourceRef: @24@0:8^{__C3DMeshSource={__C3DGenericSource={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}16
CMETHOD geometrySourceWithNormals:count: @32@0:8r^{SCNVector3=fff}16q24
CMETHOD geometrySourceWithTextureCoordinates:count: @32@0:8r^{CGPoint=dd}16q24
CMETHOD geometrySourceWithVertices:count: @32@0:8r^{SCNVector3=fff}16q24
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD data @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD scene @16@0:8
METHOD semantic @16@0:8
METHOD floatComponents B16@0:8
METHOD __CFObject ^v16@0:8
METHOD _clearC3DCache v16@0:8
METHOD _componentType s16@0:8
METHOD _encodeDataAsHalf B16@0:8
METHOD _printData v16@0:8
METHOD _uninterleaveData:count:srcOffset:srcStride:dstStride: @56@0:8@16Q24Q32Q40Q48
METHOD bytesPerComponent q16@0:8
METHOD componentsPerVector q16@0:8
METHOD dataByConvertingColorData:colorSpace:newColorSpace:vectorCount:componentsPerVector:bytesPerComponent:dataOffset:dataStride:newDataOffset:newDataStride: @96@0:8@16^{CGColorSpace=}24^^{CGColorSpace}32q40q48q56q64q72^q80^q88
METHOD dataOffset q16@0:8
METHOD dataStride q16@0:8
METHOD initWithBuffer:vertexFormat:semantic:vertexCount:dataOffset:dataStride: @64@0:8@16Q24@32q40q48q56
METHOD initWithData:semantic:colorSpace:vectorCount:floatComponents:componentsPerVector:bytesPerComponent:dataOffset:dataStride: @84@0:8@16@24^{CGColorSpace=}32q40B48q52q60q68q76
METHOD initWithData:semantic:vectorCount:componentType:componentCount:dataOffset:dataStride: @68@0:8@16@24q32s40Q44q52q60
METHOD initWithMeshSource: @24@0:8^{__C3DMeshSource={__C3DGenericSource={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}16
METHOD meshSource ^{__C3DMeshSource={__C3DGenericSource={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}16@0:8
METHOD mkSemantic @16@0:8
METHOD sceneRef ^{__C3DScene=}16@0:8
METHOD setMkSemantic: v24@0:8@16
METHOD set_encodeDataAsHalf: v20@0:8B16
METHOD vectorCount q16@0:8

=== CLASS SCNGeometryTessellator ===
SUPER: NSObject
SIZE: 56
PROTOCOLS: NSCopying NSSecureCoding
IVAR +8 0 _clients @"NSMutableSet"
IVAR +16 0 _adaptive B
IVAR +17 0 _screenSpace B
IVAR +20 0 _maximumEdgeLength f
IVAR +24 0 _edgeTessellationFactor f
IVAR +28 0 _insideTessellationFactor f
IVAR +32 0 _tessellationFactorScale f
IVAR +40 0 _smoothingMode q
IVAR +48 0 _partitionMode Q
CMETHOD supportsSecureCoding B16@0:8
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD isAdaptive B16@0:8
METHOD setAdaptive: v20@0:8B16
METHOD addClient: v24@0:8@16
METHOD removeClient: v24@0:8@16
METHOD setTessellationPartitionMode: v24@0:8Q16
METHOD tessellationPartitionMode Q16@0:8
METHOD setScreenSpace: v20@0:8B16
METHOD _tessellatorValueForGeometry: {?=CfIC(?={?=ff}{?=f}{?=f}{?=Cb1b1})}24@0:8@16
METHOD adaptive B16@0:8
METHOD clientWillDie: v24@0:8@16
METHOD edgeTessellationFactor d16@0:8
METHOD insideTessellationFactor d16@0:8
METHOD isScreenSpace B16@0:8
METHOD maximumEdgeLength d16@0:8
METHOD screenSpace B16@0:8
METHOD setEdgeTessellationFactor: v24@0:8d16
METHOD setInsideTessellationFactor: v24@0:8d16
METHOD setMaximumEdgeLength: v24@0:8d16
METHOD setSmoothingMode: v24@0:8q16
METHOD setTessellationFactorScale: v24@0:8d16
METHOD smoothingMode q16@0:8
METHOD tessellationFactorScale d16@0:8
METHOD tessellatorValueDidChange v16@0:8
METHOD tessellatorValueDidChangeForClient: v24@0:8@16

=== CLASS SCNKeyedArchiver ===
SUPER: NSKeyedArchiver
SIZE: 144
IVAR +128 0 skipMorphTargets B
IVAR +136 0 options @"NSDictionary"
CMETHOD archivedDataWithRootObject:options: @32@0:8@16@24
METHOD dealloc v16@0:8
METHOD options @16@0:8
METHOD encodeValueOfObjCType:at: v32@0:8r*16r^v24
METHOD setOptions: v24@0:8@16
METHOD setSkipMorphTargets: v20@0:8B16
METHOD skipMorphTargets B16@0:8

=== CLASS SCNKeyedUnarchiver ===
SUPER: NSKeyedUnarchiver
SIZE: 184
IVAR +136 0 _documentURL @"NSURL"
IVAR +144 0 _context @"NSDictionary"
IVAR +152 0 _assetCatalog @"SCNAssetCatalog"
IVAR +160 0 _lookUpKey @"NSString"
IVAR +168 0 _lookUpFoundInstance @
IVAR +176 0 _allTargetsFromAnimCodec @"NSArray"
METHOD dealloc v16@0:8
METHOD context @16@0:8
METHOD setContext: v24@0:8@16
METHOD decodeValueOfObjCType:at: v32@0:8r*16^v24
METHOD documentURL @16@0:8
METHOD setDocumentURL: v24@0:8@16
METHOD allTargetsFromAnimCodec @16@0:8
METHOD assetCatalog @16@0:8
METHOD documentEnclosingURL @16@0:8
METHOD initForReadingWithData:secure: @28@0:8@16B24
METHOD lookUpFoundInstance @16@0:8
METHOD lookUpKey @16@0:8
METHOD setAllTargetsFromAnimCodec: v24@0:8@16
METHOD setAssetCatalog: v24@0:8@16
METHOD setLookUpFoundInstance: v24@0:8@16
METHOD setLookUpKey: v24@0:8@16

=== CLASS SCNMaterialProperty ===
SUPER: NSObject
SIZE: 136
PROTOCOLS: SCNAnimatable NSSecureCoding
IVAR +8 0 _isPresentationInstance b1
IVAR +8 0 _isCommonProfileProperty b1
IVAR +8 0 _sRGB b1
IVAR +8 0 _preventWarmup b1
IVAR +9 0 _propertyType c
IVAR +16 0 _parent @
IVAR +24 0 _customSlotName @"NSString"
IVAR +32 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +40 0 _animations @"SCNOrderedDictionary"
IVAR +48 0 _bindings @"NSMutableDictionary"
IVAR +56 0 _borderColor @"UIColor"
IVAR +64 0 _contents @
IVAR +72 0 _contentType C
IVAR +80 0 _mappingChannel q
IVAR +88 0 _minificationFilter C
IVAR +89 0 _magnificationFilter C
IVAR +90 0 _mipFilter C
IVAR +91 0 _wrapS C
IVAR +92 0 _wrapT C
IVAR +93 0 _textureComponents C
IVAR +96 0 _intensity f
IVAR +100 0 _maxAnisotropy f
IVAR +104 0 _customSlot ^{__C3DEffectSlot={__CFRuntimeBase=QAQ}{C3DColor4=(?=[4f]{?=ffff})}^v(?=^{__C3DImage}^v^{__C3DImageProxy}^{__C3DTexture}^v)b8b1b1b1b4c^{__C3DTextureSampler}^(C3DMatrix4x4)fi^v}
IVAR +112 0 _c3dImage ^{__C3DImage=}
IVAR +120 0 _contentTransform ^{SCNMatrix4=ffffffffffffffff}
IVAR +128 0 _runtimeResolvedPath @
CMETHOD supportsSecureCoding B16@0:8
CMETHOD _copyImageFromC3DImage: @24@0:8^{__C3DImage=}16
CMETHOD _createC3DImageFromImage: ^{__C3DImage=}24@0:8@16
CMETHOD captureDeviceOutputConsumer @16@0:8
CMETHOD captureDeviceOutputConsumerWithOptions: @24@0:8@16
CMETHOD copyC3DImageFromImage: ^{__C3DImage=}24@0:8@16
CMETHOD copyC3DImageFromImage:textureOptions:wasCached: ^{__C3DImage=}36@0:8@16i24^B28
CMETHOD copyImageFromC3DImage: @24@0:8^{__C3DImage=}16
CMETHOD dvt_supportedTypesForPropertyContents @16@0:8
CMETHOD materialPropertyWithContents: @24@0:8@16
CMETHOD precomputedLightingEnvironmentContentsWithData:error: @32@0:8@16^@24
CMETHOD precomputedLightingEnvironmentContentsWithURL:error: @32@0:8@16^@24
CMETHOD precomputedLightingEnvironmentDataForContents:device:error: @40@0:8@16@24^@32
METHOD avt_setSimdContentsTransform: v80@0:8{?=[4]}16
METHOD avt_simdContentsTransform {?=[4]}16@0:8
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD floatValue @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD parent @16@0:8
METHOD color @16@0:8
METHOD setColor: v24@0:8@16
METHOD propertyName @16@0:8
METHOD contents @16@0:8
METHOD image @16@0:8
METHOD intensity d16@0:8
METHOD setContents: v24@0:8@16
METHOD setImage: v24@0:8@16
METHOD setIntensity: v24@0:8d16
METHOD content @16@0:8
METHOD setBorderColor: v24@0:8@16
METHOD attachment @16@0:8
METHOD setAttachment: v24@0:8@16
METHOD _clearContents v16@0:8
METHOD _setColor: v24@0:8@16
METHOD _setParent: v24@0:8@16
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationForKey: @24@0:8@16
METHOD animationKeys @16@0:8
METHOD borderColor @16@0:8
METHOD contentsTransform {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD layer @16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD setContent: v24@0:8@16
METHOD setContentsTransform: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD setLayer: v24@0:8@16
METHOD setMagnificationFilter: v24@0:8q16
METHOD setMinificationFilter: v24@0:8q16
METHOD propertyType c16@0:8
METHOD magnificationFilter q16@0:8
METHOD minificationFilter q16@0:8
METHOD setMaxAnisotropy: v24@0:8d16
METHOD setMipFilter: v24@0:8q16
METHOD mappingChannel q16@0:8
METHOD mipFilter q16@0:8
METHOD setFloatValue: v24@0:8@16
METHOD setMappingChannel: v24@0:8q16
METHOD setTextureComponents: v24@0:8q16
METHOD textureComponents q16@0:8
METHOD avPlayer @16@0:8
METHOD setAvPlayer: v24@0:8@16
METHOD maxAnisotropy d16@0:8
METHOD _setImagePath:withResolvedPath: v32@0:8@16@24
METHOD _textureOptions i16@0:8
METHOD UIView @16@0:8
METHOD __allocateContentTransformIfNeeded v16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD __runtimeResolvedPath @16@0:8
METHOD _animationPathForKey: @24@0:8@16
METHOD setSRGBTexture: v20@0:8B16
METHOD unlinkCustomPropertyWithParent: v24@0:8@16
METHOD _updateMaterialTextureProvider: v24@0:8@16
METHOD __CFObject ^v16@0:8
METHOD skScene @16@0:8
METHOD textureProvider @16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _customDecodingOfSCNMaterialProperty: v24@0:8@16
METHOD _customEncodingOfSCNMaterialProperty: v24@0:8@16
METHOD _didDecodeSCNMaterialProperty: v24@0:8@16
METHOD _hasDefaultValues B16@0:8
METHOD _layerDidChange: v24@0:8@16
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _presentationMappingChannel q16@0:8
METHOD _scnAnimationForKey: @24@0:8@16
METHOD _scnBindings @16@0:8
METHOD _setC3DImageRef: v24@0:8^{__C3DImage=}16
METHOD _setupContentsFromC3DImage v16@0:8
METHOD _skSceneDidChange: v24@0:8@16
METHOD _syncObjCAnimations v16@0:8
METHOD _syncObjCModel v16@0:8
METHOD _updateC3DImageWithContents: v24@0:8@16
METHOD _updateMaterialAVPlayer: v24@0:8@16
METHOD _updateMaterialAttachment: v24@0:8@16
METHOD _updateMaterialBorderColor: v24@0:8@16
METHOD _updateMaterialCaptureDevice: v24@0:8@16
METHOD _updateMaterialCaptureDeviceOutputConsumerSource: v24@0:8@16
METHOD _updateMaterialColor: v24@0:8@16
METHOD _updateMaterialFilters v16@0:8
METHOD _updateMaterialImage: v24@0:8@16
METHOD _updateMaterialLayer: v24@0:8@16
METHOD _updateMaterialMTLTexture: v24@0:8@16
METHOD _updateMaterialNumber: v24@0:8@16
METHOD _updateMaterialProceduralContents: v24@0:8@16
METHOD _updateMaterialPropertyTransform: v80@0:8(C3DMatrix4x4=[16f][4]{?=[4]})16
METHOD _updateMaterialSKScene: v24@0:8@16
METHOD _updateMaterialSKTexture: v24@0:8@16
METHOD _updateMaterialUIComponent: v24@0:8@16
METHOD _updatePrecomputedLightingEnvironment: v24@0:8@16
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__C3DAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD borderColor4 {C3DColor4=(?=[4f]{?=ffff})}16@0:8
METHOD captureDevice @16@0:8
METHOD captureDeviceOutputConsumerSource @16@0:8
METHOD color4 {C3DColor4=(?=[4f]{?=ffff})}16@0:8
METHOD commonProfile ^{__C3DEffectCommonProfile={__CFRuntimeBase=QAQ}^{__C3DMaterial}i^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}^{__C3DEffectSlot}fffffCqBBb1b1b1b1b1b1b1b1b1b13}16@0:8
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD copyPropertiesFrom: v24@0:8@16
METHOD effectSlot ^{__C3DEffectSlot={__CFRuntimeBase=QAQ}{C3DColor4=(?=[4f]{?=ffff})}^v(?=^{__C3DImage}^v^{__C3DImageProxy}^{__C3DTexture}^v)b8b1b1b1b4c^{__C3DTextureSampler}^(C3DMatrix4x4)fi^v}16@0:8
METHOD effectSlotCreateIfNeeded: ^{__C3DEffectSlot={__CFRuntimeBase=QAQ}{C3DColor4=(?=[4f]{?=ffff})}^v(?=^{__C3DImage}^v^{__C3DImageProxy}^{__C3DTexture}^v)b8b1b1b1b4c^{__C3DTextureSampler}^(C3DMatrix4x4)fi^v}20@0:8B16
METHOD getC3DImageRef ^v16@0:8
METHOD initPresentationMaterialPropertyWithModelProperty: @24@0:8@16
METHOD initWithParent:andCustomName: @32@0:8@16@24
METHOD initWithParent:propertyType: @28@0:8@16c24
METHOD isAnimationForKeyPaused: B24@0:8@16
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD linkCustomPropertyWithParent:andCustomName: v32@0:8@16@24
METHOD mtlTexture @16@0:8
METHOD parentWillDie: v24@0:8@16
METHOD pauseAnimationForKey: v24@0:8@16
METHOD precomputedLightingEnvironment @16@0:8
METHOD presentationInstance @16@0:8
METHOD presentationMaterialProperty @16@0:8
METHOD proceduralContents @16@0:8
METHOD pvrtcData @16@0:8
METHOD removeAllAnimationsWithBlendOutDuration: v24@0:8d16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v32@0:8@16d24
METHOD removeAnimationForKey:fadeOutDuration: v32@0:8@16d24
METHOD resumeAnimationForKey: v24@0:8@16
METHOD sRGBTexture B16@0:8
METHOD sceneRef ^{__C3DScene=}16@0:8
METHOD setCaptureDevice: v24@0:8@16
METHOD setCaptureDeviceOutputConsumerSource: v24@0:8@16
METHOD setMtlTexture: v24@0:8@16
METHOD setPrecomputedLightingEnvironment: v24@0:8@16
METHOD setProceduralContents: v24@0:8@16
METHOD setSkScene: v24@0:8@16
METHOD setSkTexture: v24@0:8@16
METHOD setSpeed:forAnimationKey: v32@0:8d16@24
METHOD setTextureProvider: v24@0:8@16
METHOD setUIView: v24@0:8@16
METHOD setUIWindow: v24@0:8@16
METHOD setWrapS: v24@0:8q16
METHOD setWrapT: v24@0:8q16
METHOD skTexture @16@0:8
METHOD slotName @16@0:8
METHOD textureSampler ^{__C3DTextureSampler={__CFRuntimeBase=QAQ}iiiiii{C3DColor4=(?=[4f]{?=ffff})}fCiQ}16@0:8
METHOD unbindAnimatablePath: v24@0:8@16
METHOD wrapS q16@0:8
METHOD wrapT q16@0:8

=== CLASS SCNMorpher ===
SUPER: NSObject
SIZE: 168
PROTOCOLS: SCNAnimatable NSSecureCoding
IVAR +8 0 _morpher ^{__C3DMorph=}
IVAR +16 0 _isPresentationInstance b1
IVAR +24 0 _calculationMode q
IVAR +32 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +40 0 _animations @"SCNOrderedDictionary"
IVAR +48 0 _bindings @"NSMutableDictionary"
IVAR +56 0 _mainTargets @"NSArray"
IVAR +64 0 _weightCount Q
IVAR +72 0 _weights ^f
IVAR +80 0 _mainTargetsAndInBetweens @"NSArray"
IVAR +88 0 _inBetweenCounts @"NSArray"
IVAR +96 0 _inBetweenInfluenceWeights @"NSArray"
IVAR +104 0 _correctivesAndInBetweens @"NSArray"
IVAR +112 0 _correctiveDriverCounts @"NSArray"
IVAR +120 0 _correctiveDriverIndices @"NSArray"
IVAR +128 0 _correctiveInBetweenCounts @"NSArray"
IVAR +136 0 _correctiveInBetweenInfluenceWeights @"NSArray"
IVAR +144 0 _mainTargetNamesToIndexes @"NSDictionary"
IVAR +152 0 _name @"NSString"
IVAR +160 0 _unifyNormal B
IVAR +161 0 _useSparseTargets B
CMETHOD supportsSecureCoding B16@0:8
CMETHOD SCNUID_classForElementOfArray: #24@0:8@16
CMETHOD morpher @16@0:8
CMETHOD morpherWithMorphRef: @24@0:8^{__C3DMorph=}16
CMETHOD weightIndexStringForIndex: @24@0:8q16
METHOD avt_buildInternalSupportForCorrectivesWithBlock: v24@0:8@?16
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD setName: v24@0:8@16
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD valueForUndefinedKey: @24@0:8@16
METHOD setIdentifier: v24@0:8@16
METHOD weights @16@0:8
METHOD setWeights: v24@0:8@16
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationForKey: @24@0:8@16
METHOD animationKeys @16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD scene @16@0:8
METHOD setCalculationMode: v24@0:8q16
METHOD targets @16@0:8
METHOD setTargets: v24@0:8@16
METHOD calculationMode q16@0:8
METHOD _updateCorrectivesAndInBetween: v24@0:8@16
METHOD clearInBetweens v16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD inBetweenCounts @16@0:8
METHOD __CFObject ^v16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _customDecodingOfSCNMorpher: v24@0:8@16
METHOD _customEncodingOfSCNMorpher: v24@0:8@16
METHOD _didDecodeSCNMorpher: v24@0:8@16
METHOD _isUsingSparseTargets B16@0:8
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _presentationWeightForTargetAtIndex:token: d32@0:8Q16r^v24
METHOD _scnAnimationForKey: @24@0:8@16
METHOD _scnBindings @16@0:8
METHOD _syncEntityObjCModel v16@0:8
METHOD _syncObjCAnimations v16@0:8
METHOD _syncObjCModel v16@0:8
METHOD _updateTargetsAndInBetween: v24@0:8@16
METHOD _weightIndexForTargetNamed: q24@0:8@16
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__C3DAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD clearCorrectives v16@0:8
METHOD convertToAdditiveWithBaseGeometry: v24@0:8@16
METHOD convertToSparseWithBaseGeometry: v24@0:8@16
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD correctiveDriverCountForCorrectiveAtIndex: Q24@0:8Q16
METHOD correctiveDriverCounts @16@0:8
METHOD correctiveDriverIndices @16@0:8
METHOD correctiveDriverIndicesForCorrectiveAtIndex: @24@0:8Q16
METHOD correctiveInBetweenCounts @16@0:8
METHOD correctiveInBetweenWeights @16@0:8
METHOD correctives @16@0:8
METHOD correctivesAndInBetween @16@0:8
METHOD inBetweenTargetsForCorrectiveAtIndex: @24@0:8Q16
METHOD inBetweenTargetsForTargetAtIndex: @24@0:8Q16
METHOD inBetweenWeights @16@0:8
METHOD inBetweenWeightsForCorrectiveAtIndex: @24@0:8Q16
METHOD inBetweenWeightsForTargetAtIndex: @24@0:8Q16
METHOD initPresentationMorpherWithMorphRef: @24@0:8^{__C3DMorph=}16
METHOD initWithMorphRef: @24@0:8^{__C3DMorph=}16
METHOD isAnimationForKeyPaused: B24@0:8@16
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD morphRef ^{__C3DMorph=}16@0:8
METHOD pauseAnimationForKey: v24@0:8@16
METHOD presentationInstance @16@0:8
METHOD presentationMorpher @16@0:8
METHOD removeAllAnimationsWithBlendOutDuration: v24@0:8d16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v32@0:8@16d24
METHOD removeAnimationForKey:fadeOutDuration: v32@0:8@16d24
METHOD resumeAnimationForKey: v24@0:8@16
METHOD sceneRef ^{__C3DScene=}16@0:8
METHOD setShouldClearCPUDataAfterUpload: v20@0:8B16
METHOD setShouldMorphNormals: v20@0:8B16
METHOD setSpeed:forAnimationKey: v32@0:8d16@24
METHOD setTargets:withInBetweenTargetCounts:inBetweenWeights: v40@0:8@16@24@32
METHOD setTargetsAndInBetweens:inBetweenCounts:inBetweenWeights:correctives:driverCounts:driverIndices:inBetweenCounts:inBetweenWeights: v80@0:8@16@24@32@40@48@56@64@72
METHOD setUnifiesNormals: v20@0:8B16
METHOD setWeight:forTargetAtIndex: v32@0:8d16Q24
METHOD setWeight:forTargetNamed: v32@0:8d16@24
METHOD setWeightIncrementalThreshold: v20@0:8f16
METHOD shouldClearCPUDataAfterUpload B16@0:8
METHOD shouldMorphNormals B16@0:8
METHOD targetsAndInBetween @16@0:8
METHOD unbindAnimatablePath: v24@0:8@16
METHOD unifiesNormals B16@0:8
METHOD weightForTargetAtIndex: d24@0:8Q16
METHOD weightForTargetNamed: d24@0:8@16
METHOD weightIncrementalThreshold f16@0:8

=== CLASS SCNNode ===
SUPER: NSObject
SIZE: 264
PROTOCOLS: UIFocusItemContainer SCNTransactionCommandObject NSCopying NSSecureCoding SCNAnimatable SCNActionable SCNBoundingVolume
IVAR +8 0 _node ^{__C3DNode={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DNode}^{__C3DNode}^{__C3DNode}i{?=(C3DMatrix4x4=[16f][4]{?=[4]})(?=)}^(C3DMatrix4x4)BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1{?={?=SS}I}^{?}^{__C3DGeometry}^{__C3DDeformerStack}f{?=}}
IVAR +16 0 _parent @"SCNNode"
IVAR +24 0 _childNodes @"NSMutableArray"
IVAR +32 0 _presentationInstance @"SCNNode"
IVAR +40 0 _isPresentationInstance b1
IVAR +40 0 _lightLoaded b1
IVAR +40 0 _geometryLoaded b1
IVAR +40 0 _cameraLoaded b1
IVAR +40 0 _skinnerLoaded b1
IVAR +40 0 _morpherLoaded b1
IVAR +40 0 _paused b1
IVAR +40 0 _pausedByInheritance b1
IVAR +41 0 _affineUpToDate b1
IVAR +41 0 _transformUpToDate b1
IVAR +41 0 _hasPivot b1
IVAR +41 0 _isJoint b1
IVAR +41 0 _rotationRepresentation b2
IVAR +41 0 _movability b1
IVAR +41 0 _hidden b1
IVAR +42 0 _castsShadow b1
IVAR +42 0 _depthPrePass b1
IVAR +42 0 _ignoreAnimationWhenCopying_tmp b1
IVAR +42 0 _focusBehavior b2
IVAR +42 0 _isFocusableOrHasFocusableChild b1
IVAR +42 0 _authoringEnvironmentNode b1
IVAR +44 0 _hasComponentBitmask b13
IVAR +48 0 _transform {?="columns"[4]}
IVAR +112 0 _position 
IVAR +128 0 _rotation (?="eulerAngles""axisAngle""quaternion"{?="vector"})
IVAR +144 0 _scale 
IVAR +160 0 _opacity f
IVAR +168 0 _categoryBitMask Q
IVAR +176 0 _renderingOrder q
IVAR +184 0 _components @"SCNNodeComponent"
IVAR +192 0 _actions @"SCNOrderedDictionary"
IVAR +200 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +208 0 _animations @"SCNOrderedDictionary"
IVAR +216 0 _bindings @"NSMutableDictionary"
IVAR +224 0 _fixedBoundingBoxExtrema ^{SCNVector3=fff}
IVAR +232 0 _name @"NSString"
IVAR +240 0 _valueForKey @"NSMutableDictionary"
IVAR +248 0 _valueForKeyLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +256 0 _rendererDelegate @
CMETHOD resolveInstanceMethod: B24@0:8:16
CMETHOD supportsSecureCoding B16@0:8
CMETHOD node @16@0:8
CMETHOD keyPathsForValuesAffectingScale @16@0:8
CMETHOD localUp {SCNVector3=fff}16@0:8
CMETHOD _dumpNodeTree:tab: @32@0:8@16@24
CMETHOD keyPathsForValuesAffectingEulerAngles @16@0:8
CMETHOD keyPathsForValuesAffectingOrientation @16@0:8
CMETHOD keyPathsForValuesAffectingPosition @16@0:8
CMETHOD keyPathsForValuesAffectingRotation @16@0:8
CMETHOD keyPathsForValuesAffectingTransform @16@0:8
CMETHOD localFront {SCNVector3=fff}16@0:8
CMETHOD localRight {SCNVector3=fff}16@0:8
CMETHOD nodeWithGeometry: @24@0:8@16
CMETHOD nodeWithMDLAsset: @24@0:8@16
CMETHOD nodeWithMDLAsset:options: @32@0:8@16@24
CMETHOD nodeWithMDLObject: @24@0:8@16
CMETHOD nodeWithMDLObject:masterObjects:sceneNodes:skinnedMeshes:skelNodesMap:asset:options: @72@0:8@16@24@32@40^v48@56@64
CMETHOD nodeWithMDLObject:options: @32@0:8@16@24
CMETHOD nodeWithNodeRef: @24@0:8^{__C3DNode={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DNode}^{__C3DNode}^{__C3DNode}i{?=(C3DMatrix4x4=[16f][4]{?=[4]})(?=)}^(C3DMatrix4x4)BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1{?={?=SS}I}^{?}^{__C3DGeometry}^{__C3DDeformerStack}f{?=}}16
CMETHOD simdLocalFront 16@0:8
CMETHOD simdLocalRight 16@0:8
CMETHOD simdLocalUp 16@0:8
METHOD avt_enableSubdivisionOnHierarchyWithQuality:animoji: v28@0:8Q16B24
METHOD avt_setGeometryPrimitiveRangesFromFaceIndexRanges: v24@0:8@16
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD isHidden B16@0:8
METHOD setHidden: v20@0:8B16
METHOD setName: v24@0:8@16
METHOD dump v16@0:8
METHOD isPaused B16@0:8
METHOD position {SCNVector3=fff}16@0:8
METHOD removeAllActions v16@0:8
METHOD scale {SCNVector3=fff}16@0:8
METHOD setPosition: v28@0:8{SCNVector3=fff}16
METHOD setValue:forKeyPath: v32@0:8@16@24
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD transform {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD valueForKeyPath: @24@0:8@16
METHOD valueForUndefinedKey: @24@0:8@16
METHOD setScale: v28@0:8{SCNVector3=fff}16
METHOD actions @16@0:8
METHOD setIdentifier: v24@0:8@16
METHOD filters @16@0:8
METHOD opacity d16@0:8
METHOD setOrientation: v32@0:8{SCNVector4=ffff}16
METHOD debugQuickLookObject @16@0:8
METHOD frame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD orientation {SCNVector4=ffff}16@0:8
METHOD rotation {SCNVector4=ffff}16@0:8
METHOD setOpacity: v24@0:8d16
METHOD setRotation: v32@0:8{SCNVector4=ffff}16
METHOD setTransform: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD attributeForKey: @24@0:8@16
METHOD entity @16@0:8
METHOD setEntity: v24@0:8@16
METHOD constraints @16@0:8
METHOD quaternion {SCNVector4=ffff}16@0:8
METHOD setPaused: v20@0:8B16
METHOD parentNode @16@0:8
METHOD categoryBitMask Q16@0:8
METHOD setConstraints: v24@0:8@16
METHOD _setAttributes: v24@0:8@16
METHOD coordinateSpace @16@0:8
METHOD _isEligibleForFocusInteraction B16@0:8
METHOD _setParent: v24@0:8@16
METHOD _setScale: v32@0:816
METHOD _updateTransform v16@0:8
METHOD actionForKey: @24@0:8@16
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationForKey: @24@0:8@16
METHOD animationKeys @16@0:8
METHOD canBecomeFocused B16@0:8
METHOD childNodes @16@0:8
METHOD didUpdateFocusInContext:withAnimationCoordinator: v32@0:8@16@24
METHOD focusBehavior q16@0:8
METHOD focusItemContainer @16@0:8
METHOD focusItemsInRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD geometry @16@0:8
METHOD hasActions B16@0:8
METHOD hidden B16@0:8
METHOD parentFocusEnvironment @16@0:8
METHOD preferredFocusEnvironments @16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD renderInContext: v24@0:8^v16
METHOD scene @16@0:8
METHOD setCategoryBitMask: v24@0:8Q16
METHOD setFilters: v24@0:8@16
METHOD setGeometry: v24@0:8@16
METHOD setNeedsFocusUpdate v16@0:8
METHOD shouldUpdateFocusInContext: B24@0:8@16
METHOD updateFocusIfNeeded v16@0:8
METHOD setAttribute:forKey: v32@0:8@16@24
METHOD camera @16@0:8
METHOD setCamera: v24@0:8@16
METHOD setQuaternion: v32@0:8{SCNVector4=ffff}16
METHOD addChildNode: v24@0:8@16
METHOD enumerateChildNodesUsingBlock: v24@0:8@?16
METHOD indexOfChildNode: Q24@0:8@16
METHOD insertChildNode:atIndex: v32@0:8@16Q24
METHOD removeFromParentNode v16@0:8
METHOD _setPosition: v32@0:816
METHOD _registerAsObserver v16@0:8
METHOD lookAt: v28@0:8{SCNVector3=fff}16
METHOD setPhysicsBody: v24@0:8@16
METHOD physicsBody @16@0:8
METHOD isGizmo B16@0:8
METHOD __light @16@0:8
METHOD _enumerateChildNodesUsingBlock: B24@0:8@?16
METHOD __geometry @16@0:8
METHOD morpher @16@0:8
METHOD __morpher @16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD nodeRef ^{__C3DNode={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DNode}^{__C3DNode}^{__C3DNode}i{?=(C3DMatrix4x4=[16f][4]{?=[4]})(?=)}^(C3DMatrix4x4)BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1{?={?=SS}I}^{?}^{__C3DGeometry}^{__C3DDeformerStack}f{?=}}16@0:8
METHOD _appendFocusableNodesInRect:ofView:toFocusItems: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56
METHOD _assignComponent:toContainerWithType: v32@0:8@16q24
METHOD _audioPlayers @16@0:8
METHOD skinner @16@0:8
METHOD _bakeNodes:folderPath:inVertex:bakeAO:quality:attenuation:geomSetter:terminateSetter: v64@0:8@16@24B32B36f40f44@?48@?56
METHOD worldUp {SCNVector3=fff}16@0:8
METHOD _encodeNodePropertiesWithCoder: v24@0:8@16
METHOD _setQuaternion: v32@0:8{?=}16
METHOD addAudioPlayer: v24@0:8@16
METHOD getBoundingSphereCenter:radius: B32@0:8^{SCNVector3=fff}16^d24
METHOD isJoint B16@0:8
METHOD __CFObject ^v16@0:8
METHOD __camera @16@0:8
METHOD __insertObject:inChildNodesAtIndex: v32@0:8@16Q24
METHOD __removeObjectFromChildNodesAtIndex: v24@0:8Q16
METHOD __skinner @16@0:8
METHOD objectInParticleSystemsAtIndex: @24@0:8Q16
METHOD particleSystems @16@0:8
METHOD removeAllChilds v16@0:8
METHOD _addSkinnerWithMDLMesh:sceneNodes: v32@0:8@16@24
METHOD setCastsShadow: v20@0:8B16
METHOD setEulerAngles: v28@0:8{SCNVector3=fff}16
METHOD _associatedMDLObject @16@0:8
METHOD simdEulerAngles 16@0:8
METHOD simdOrientation {?=}16@0:8
METHOD _childNodesPassingTest:recursively:output: B36@0:8@?16B24@28
METHOD _childNodesWithAttribute:output:recursively: v36@0:8#16@24B32
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _copyRecursively @16@0:8
METHOD _customDecodingOfSCNNode: v24@0:8@16
METHOD _customEncodingOfSCNNode:usePresentationInstance: v28@0:8@16B24
METHOD _didDecodeSCNNode: v24@0:8@16
METHOD _dump: v24@0:8@16
METHOD _dumpTree @16@0:8
METHOD _euler 16@0:8
METHOD _findComponentWithType: @24@0:8q16
METHOD _focusFrameInView: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _initChildNodesArray v16@0:8
METHOD _isAReference B16@0:8
METHOD _isEffectivelyHidden B16@0:8
METHOD _particleSystems @16@0:8
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _quaternion {?=}16@0:8
METHOD _removeAction:forKey: v32@0:8@16@24
METHOD _removeComponentWithType: v24@0:8q16
METHOD _removeDeadParticleSystem: v24@0:8^{__C3DParticleSystem=}16
METHOD _scnAnimationForKey: @24@0:8@16
METHOD _scnBindings @16@0:8
METHOD _setComponent:withType: v32@0:8@16q24
METHOD _setHasFocusableChild v16@0:8
METHOD _setPausedOrPausedByInheritance: v20@0:8B16
METHOD _subdividedCopyWithSubdivisionLevel: @24@0:8q16
METHOD _syncEntityObjCModel v16@0:8
METHOD _syncObjCAnimations v16@0:8
METHOD _syncObjCModel v16@0:8
METHOD _syncObjCModelAfterC3DIOSceneLoadingWithNodeRef: v24@0:8^{__C3DNode={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DNode}^{__C3DNode}^{__C3DNode}i{?=(C3DMatrix4x4=[16f][4]{?=[4]})(?=)}^(C3DMatrix4x4)BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1{?={?=SS}I}^{?}^{__C3DGeometry}^{__C3DDeformerStack}f{?=}}16
METHOD _updateAffine v16@0:8
METHOD _updateFocusableCache v16@0:8
METHOD actionKeys @16@0:8
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD addParticleSystem: v24@0:8@16
METHOD animationManager ^{__C3DAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD audioPlayers @16@0:8
METHOD authoringCameraType q16@0:8
METHOD authoringEnvironmentCompanionNode @16@0:8
METHOD authoringEnvironmentNode B16@0:8
METHOD authoringEnvironmentPresentationNode @16@0:8
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD canAddChildNode: B24@0:8@16
METHOD castsShadow B16@0:8
METHOD childNodeWithName: @24@0:8@16
METHOD childNodeWithName:recursively: @28@0:8@16B24
METHOD childNodesPassingTest: @24@0:8@?16
METHOD childNodesPassingTest:recursively: @28@0:8@?16B24
METHOD childNodesWithAttribute:recursively: @28@0:8#16B24
METHOD clone @16@0:8
METHOD convertPosition:fromNode: {SCNVector3=fff}36@0:8{SCNVector3=fff}16@28
METHOD convertPosition:toNode: {SCNVector3=fff}36@0:8{SCNVector3=fff}16@28
METHOD convertTransform:fromNode: {SCNMatrix4=ffffffffffffffff}88@0:8{SCNMatrix4=ffffffffffffffff}16@80
METHOD convertTransform:toNode: {SCNMatrix4=ffffffffffffffff}88@0:8{SCNMatrix4=ffffffffffffffff}16@80
METHOD convertVector:fromNode: {SCNVector3=fff}36@0:8{SCNVector3=fff}16@28
METHOD convertVector:toNode: {SCNVector3=fff}36@0:8{SCNVector3=fff}16@28
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD countOfAudioPlayers Q16@0:8
METHOD countOfChildNodes Q16@0:8
METHOD countOfParticleSystems Q16@0:8
METHOD debugQuickLookData @16@0:8
METHOD enumerateHierarchyUsingBlock: v24@0:8@?16
METHOD enumerateNodesUsingBlock: v24@0:8@?16
METHOD eulerAngles {SCNVector3=fff}16@0:8
METHOD flattenedClone @16@0:8
METHOD flattenedCopy @16@0:8
METHOD getBoundingBox @16@0:8
METHOD getBoundingBoxMin:max: B32@0:8^{SCNVector3=fff}16^{SCNVector3=fff}24
METHOD getBoundingSphere @16@0:8
METHOD getFrustum:withViewport: B40@0:8^{?=[6(?={?=ffff})]}1624
METHOD hitTestWithSegmentFromPoint:toPoint:options: @48@0:8{SCNVector3=fff}16{SCNVector3=fff}28@40
METHOD initPresentationNodeWithNodeRef: @24@0:8^{__C3DNode={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DNode}^{__C3DNode}^{__C3DNode}i{?=(C3DMatrix4x4=[16f][4]{?=[4]})(?=)}^(C3DMatrix4x4)BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1{?={?=SS}I}^{?}^{__C3DGeometry}^{__C3DDeformerStack}f{?=}}16
METHOD initWithNodeRef: @24@0:8^{__C3DNode={__C3DEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__C3DScene}q}^{__C3DNode}^{__C3DNode}^{__C3DNode}i{?=(C3DMatrix4x4=[16f][4]{?=[4]})(?=)}^(C3DMatrix4x4)BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1{?={?=SS}I}^{?}^{__C3DGeometry}^{__C3DDeformerStack}f{?=}}16
METHOD insertObject:inAudioPlayersAtIndex: v32@0:8@16Q24
METHOD insertObject:inChildNodesAtIndex: v32@0:8@16Q24
METHOD insertObject:inParticleSystemsAtIndex: v32@0:8@16Q24
METHOD isAnimationForKeyPaused: B24@0:8@16
METHOD isFocusInteractionEnabled B16@0:8
METHOD isHittable B16@0:8
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD isPresentationInstance B16@0:8
METHOD jsChildNodesWithAttribute: @24@0:8@16
METHOD light @16@0:8
METHOD localRotateBy: v32@0:8{SCNVector4=ffff}16
METHOD localTranslateBy: v28@0:8{SCNVector3=fff}16
METHOD lookAt:up:localFront: v52@0:8{SCNVector3=fff}16{SCNVector3=fff}28{SCNVector3=fff}40
METHOD movabilityHint q16@0:8
METHOD mutableChildNodes @16@0:8
METHOD objectInAudioPlayersAtIndex: @24@0:8Q16
METHOD objectInChildNodesAtIndex: @24@0:8Q16
METHOD objectInChildNodesWithAttribute:firstOnly: @28@0:8@16B24
METHOD objectInChildNodesWithName: @24@0:8@16
METHOD parseSpecialKey:withPath:intoDestination: B40@0:8@16@24^@32
METHOD pauseAnimationForKey: v24@0:8@16
METHOD physicsField @16@0:8
METHOD pivot {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD postMorphingDeformers @16@0:8
METHOD postSkinningDeformers @16@0:8
METHOD presentationInstance @16@0:8
METHOD presentationNode @16@0:8
METHOD removeActionForKey: v24@0:8@16
METHOD removeAllAnimationsWithBlendOutDuration: v24@0:8d16
METHOD removeAllAudioPlayers v16@0:8
METHOD removeAllBindings v16@0:8
METHOD removeAllParticleSystems v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v32@0:8@16d24
METHOD removeAnimationForKey:fadeOutDuration: v32@0:8@16d24
METHOD removeAudioPlayer: v24@0:8@16
METHOD removeObjectFromAudioPlayersAtIndex: v24@0:8Q16
METHOD removeObjectFromChildNodesAtIndex: v24@0:8Q16
METHOD removeObjectFromParticleSystemsAtIndex: v24@0:8Q16
METHOD removeParticleSystem: v24@0:8@16
METHOD rendererDelegate @16@0:8
METHOD renderingOrder q16@0:8
METHOD replaceChildNode:with: v32@0:8@16@24
METHOD replaceObjectInAudioPlayerAtIndex:withObject: v32@0:8Q16@24
METHOD replaceObjectInChildNodesAtIndex:withObject: v32@0:8Q16@24
METHOD replaceObjectInParticleSystemsAtIndex:withObject: v32@0:8Q16@24
METHOD resumeAnimationForKey: v24@0:8@16
METHOD rotateBy:aroundTarget: v44@0:8{SCNVector4=ffff}16{SCNVector3=fff}32
METHOD rotationRepresentation q16@0:8
METHOD runAction: v24@0:8@16
METHOD runAction:completionHandler: v32@0:8@16@?24
METHOD runAction:forKey: v32@0:8@16@24
METHOD runAction:forKey:completionHandler: v40@0:8@16@24@?32
METHOD sceneRef ^{__C3DScene=}16@0:8
METHOD setAuthoringCameraType: v24@0:8q16
METHOD setAuthoringEnvironmentCompanionNode: v24@0:8@16
METHOD setAuthoringEnvironmentNode: v20@0:8B16
METHOD setAuthoringEnvironmentPresentationNode: v24@0:8@16
METHOD setBoundingBoxMin:max: v32@0:8^{SCNVector3=fff}16^{SCNVector3=fff}24
METHOD setFocusBehavior: v24@0:8q16
METHOD setGizmo: v20@0:8B16
METHOD setHittable: v20@0:8B16
METHOD setIsJoint: v20@0:8B16
METHOD setLight: v24@0:8@16
METHOD setMorpher: v24@0:8@16
METHOD setMovabilityHint: v24@0:8q16
METHOD setPhysicsField: v24@0:8@16
METHOD setPivot: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD setPostMorphingDeformers: v24@0:8@16
METHOD setPostSkinningDeformers: v24@0:8@16
METHOD setRendererDelegate: v24@0:8@16
METHOD setRenderingOrder: v24@0:8q16
METHOD setSimdEulerAngles: v32@0:816
METHOD setSimdOrientation: v32@0:8{?=}16
METHOD setSimdPivot: v80@0:8{?=[4]}16
METHOD setSimdPosition: v32@0:816
METHOD setSimdRotation: v32@0:816
METHOD setSimdScale: v32@0:816
METHOD setSimdTransform: v80@0:8{?=[4]}16
METHOD setSimdWorldOrientation: v32@0:8{?=}16
METHOD setSimdWorldPosition: v32@0:816
METHOD setSimdWorldTransform: v80@0:8{?=[4]}16
METHOD setSkinner: v24@0:8@16
METHOD setSpeed:forAnimationKey: v32@0:8d16@24
METHOD setUsesDepthPrePass: v20@0:8B16
METHOD setWorldOrientation: v32@0:8{SCNVector4=ffff}16
METHOD setWorldPosition: v28@0:8{SCNVector3=fff}16
METHOD setWorldTransform: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD simdConvertPosition:fromNode: 40@0:816@32
METHOD simdConvertPosition:toNode: 40@0:816@32
METHOD simdConvertTransform:fromNode: {?=[4]}88@0:8{?=[4]}16@80
METHOD simdConvertTransform:toNode: {?=[4]}88@0:8{?=[4]}16@80
METHOD simdConvertVector:fromNode: 40@0:816@32
METHOD simdConvertVector:toNode: 40@0:816@32
METHOD simdGetBoundingSphereCenter:radius: B32@0:8^16^f24
METHOD simdLocalRotateBy: v32@0:8{?=}16
METHOD simdLocalTranslateBy: v32@0:816
METHOD simdLookAt: v32@0:816
METHOD simdLookAt:up:localFront: v64@0:8163248
METHOD simdPivot {?=[4]}16@0:8
METHOD simdPosition 16@0:8
METHOD simdRotateBy:aroundTarget: v48@0:8{?=}1632
METHOD simdRotation 16@0:8
METHOD simdScale 16@0:8
METHOD simdTransform {?=[4]}16@0:8
METHOD simdWorldFront 16@0:8
METHOD simdWorldOrientation {?=}16@0:8
METHOD simdWorldPosition 16@0:8
METHOD simdWorldRight 16@0:8
METHOD simdWorldTransform {?=[4]}16@0:8
METHOD simdWorldUp 16@0:8
METHOD unbindAnimatablePath: v24@0:8@16
METHOD usesDepthPrePass B16@0:8
METHOD worldFront {SCNVector3=fff}16@0:8
METHOD worldOrientation {SCNVector4=ffff}16@0:8
METHOD worldPosition {SCNVector3=fff}16@0:8
METHOD worldRight {SCNVector3=fff}16@0:8
METHOD worldTransform {SCNMatrix4=ffffffffffffffff}16@0:8

=== CLASS SCNRenderer ===
SUPER: NSObject
SIZE: 448
PROTOCOLS: SCNMTLRenderContextCommandBufferStatusMonitor SCNMTLRenderContextResourceManagerMonitor SCNSceneRenderer SCNTechniqueSupport
IVAR +8 0 _scene @"SCNScene"
IVAR +16 0 _pointOfView @"SCNNode"
IVAR +24 0 _pointOfCulling @"SCNNode"
IVAR +32 0 _lock @"SCNRecursiveLock"
IVAR +40 0 __renderingQueue @"NSObject<OS_dispatch_queue>"
IVAR +48 0 __prepareQueue @"NSObject<OS_dispatch_queue>"
IVAR +56 0 __antialiasingMode Q
IVAR +64 0 __preparePixelFormat Q
IVAR +72 0 _framebufferInfo {?="frameBuffer"^{__C3DFramebuffer}"multisamplingFrameBuffer"^{__C3DFramebuffer}"drawableSize"}
IVAR +96 0 _mtlTexture @"<MTLTexture>"
IVAR +104 0 _viewpoints @"NSArray"
IVAR +112 0 _viewpointCoordinateSpace Q
IVAR +120 0 _pointOfViewWasSet B
IVAR +121 0 _shouldDeleteFramebuffer b1
IVAR +121 0 _rendersContinuously b1
IVAR +121 0 _isPrivateRenderer b1
IVAR +121 0 _isViewPrivateRenderer b1
IVAR +121 0 _renderingSnapshot b1
IVAR +121 0 _renderingPrepare b1
IVAR +121 0 _autoUpdate b1
IVAR +121 0 _disableLinearRendering b1
IVAR +128 0 _currentSceneTime d
IVAR +136 0 _currentSystemTime d
IVAR +144 0 _deltaTime d
IVAR +152 0 _forceSystemTime d
IVAR +160 0 _lastSystemTime d
IVAR +168 0 __nextFrameTime d
IVAR +176 0 _transitionContext @"SCNRendererTransitionContext"
IVAR +184 0 _playing B
IVAR +185 0 _loops B
IVAR +186 0 _isAnimating B
IVAR +188 0 _adaptativeState0 I
IVAR +192 0 _adaptativeEndFrame I
IVAR +196 0 _adaptativeTechniqueTimeStamp I
IVAR +200 0 _delegate @"<SCNSceneRendererDelegate>"
IVAR +208 0 _engineContext ^{__C3DEngineContext=}
IVAR +216 0 _renderingAPI Q
IVAR +224 0 __viewport {SCNVector4="x"f"y"f"z"f"w"f}
IVAR +240 0 __aspectRatio d
IVAR +256 0 __drawableSafeAreaInsets 
IVAR +272 0 _glContext @"EAGLContext"
IVAR +280 0 _renderContext @"SCNMTLRenderContext"
IVAR +288 0 _jitteringEnabled b1
IVAR +288 0 _temporalAntialiasingEnabled b1
IVAR +288 0 _frozen b1
IVAR +288 0 _shouldForwardSceneRendererDelegationMessagesToSelf b1
IVAR +288 0 _shouldForwardSceneRendererDelegationMessagesToPrivateRendererOwner b1
IVAR +292 0 _selfDelegationConformance {?="supportsUpdate"b1"supportsDidApplyAnimations"b1"supportsDidSimulatePhysics"b1"supportsDidApplyConstraints"b1"supportsWillRender"b1"supportsDidRender"b1"supportsInputTime"b1"supportsReadSubdivCache"b1"supportsWriteSubdivCache"b1"supportsMainPassCustomPostProcess"b1}
IVAR +296 0 _privateRendererOwnerDelegationConformance {?="supportsUpdate"b1"supportsDidApplyAnimations"b1"supportsDidSimulatePhysics"b1"supportsDidApplyConstraints"b1"supportsWillRender"b1"supportsDidRender"b1"supportsInputTime"b1"supportsReadSubdivCache"b1"supportsWriteSubdivCache"b1"supportsMainPassCustomPostProcess"b1}
IVAR +300 0 _delegationConformance {?="supportsUpdate"b1"supportsDidApplyAnimations"b1"supportsDidSimulatePhysics"b1"supportsDidApplyConstraints"b1"supportsWillRender"b1"supportsDidRender"b1"supportsInputTime"b1"supportsReadSubdivCache"b1"supportsWriteSubdivCache"b1"supportsMainPassCustomPostProcess"b1}
IVAR +304 0 _backgroundColor @"UIColor"
IVAR +320 0 _c3dBackgroundColor {C3DColor4=""(?="rgba"[4f]""{?="r"f"g"f"b"f"a"f}"simd")}
IVAR +336 0 _preloadRenderer @"SCNRenderer"
IVAR +344 0 _privateRendererOwner @"<SCNSceneRenderer>"
IVAR +352 0 _technique @"SCNTechnique"
IVAR +360 0 _snapshotRenderer @"SCNRenderer"
IVAR +368 0 _overlayRenderer @"__SKSCNRenderer"
IVAR +376 0 _overlayScene @
IVAR +384 0 _disableOverlays B
IVAR +388 0 _contentScaleFactor f
IVAR +392 0 _isRunningInExtension B
IVAR +400 0 _authoringEnvironment @"SCNAuthoringEnvironment"
IVAR +408 0 _debugOptions Q
IVAR +416 0 _showStatistics B
IVAR +417 0 _showAuthoringEnvironment B
IVAR +424 0 _statisticsTimeStamp d
IVAR +432 0 _resourceManagerMonitor @"<_SCNSceneRendererResourceManagerMonitor>"
IVAR +440 0 _commandBufferStatusMonitor @"<_SCNSceneCommandBufferStatusMonitor>"
CMETHOD rendererWithContext:options: @32@0:8@16@24
CMETHOD rendererWithDevice:options: @32@0:8@16@24
METHOD avt_simdProjectPoint: 32@0:816
METHOD avt_simdUnprojectPoint: 32@0:816
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD context ^v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD delegate @16@0:8
METHOD lock v16@0:8
METHOD setContext: v24@0:8@16
METHOD setDelegate: v24@0:8@16
METHOD unlock v16@0:8
METHOD commandQueue @16@0:8
METHOD device @16@0:8
METHOD workingColorSpace ^{CGColorSpace=}16@0:8
METHOD metalDevice @16@0:8
METHOD backgroundColor @16@0:8
METHOD setBackgroundColor: v24@0:8@16
METHOD viewport {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _setInterfaceOrientation: v24@0:8q16
METHOD _stop v16@0:8
METHOD _update: v24@0:8^{__C3DScene=}16
METHOD currentTime d16@0:8
METHOD isPlaying B16@0:8
METHOD scene @16@0:8
METHOD setFrozen: v20@0:8B16
METHOD setScene: v24@0:8@16
METHOD setCurrentTime: v24@0:8d16
METHOD nextFrameTime d16@0:8
METHOD render v16@0:8
METHOD hitTest:options: @40@0:8{CGPoint=dd}16@32
METHOD setPlaying: v20@0:8B16
METHOD _pause v16@0:8
METHOD colorPixelFormat Q16@0:8
METHOD currentRenderPassDescriptor @16@0:8
METHOD metalLayer @16@0:8
METHOD _installContext B16@0:8
METHOD _renderingQueue @16@0:8
METHOD currentViewport {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _UIOrientationDidChangeNotification: v24@0:8@16
METHOD prepareObject:shouldAbortBlock: B32@0:8@16@?24
METHOD _addGPUFrameCompletedHandler: v24@0:8@?16
METHOD _addGPUFrameScheduledHandler: v24@0:8@?16
METHOD _aspectRatio d16@0:8
METHOD setTemporalAntialiasingEnabled: v20@0:8B16
METHOD set_commandBufferStatusMonitor: v24@0:8@16
METHOD showsStatistics B16@0:8
METHOD snapshotAtTime: @24@0:8d16
METHOD MTLTexture @16@0:8
METHOD _installGLContextAndSetViewport v16@0:8
METHOD disableOverlays B16@0:8
METHOD __CFObject ^v16@0:8
METHOD __setTransitionContext: v24@0:8@16
METHOD _addGPUFramePresentedHandler: v24@0:8@?16
METHOD _allowGPUBackgroundExecution v16@0:8
METHOD _antialiasingMode Q16@0:8
METHOD setForceAsyncShaderCompilation: v20@0:8B16
METHOD setPointOfView: v24@0:8@16
METHOD _authoringEnvironment @16@0:8
METHOD set_systemTime: v24@0:8d16
METHOD _backingSize 16@0:8
METHOD unprojectPoint: {SCNVector3=fff}28@0:8{SCNVector3=fff}16
METHOD updateAndDrawStatisticsIfNeeded v16@0:8
METHOD _beginFrame v16@0:8
METHOD _c3dBackgroundColorDidChange v16@0:8
METHOD _clearBackBuffer v16@0:8
METHOD _collectCompilationErrors B16@0:8
METHOD _commandBufferStatusMonitor @16@0:8
METHOD _compilationErrors @16@0:8
METHOD _computeNextFrameTime d16@0:8
METHOD _computedLightingEnvironmentMapsPath @16@0:8
METHOD _contentsScaleFactor d16@0:8
METHOD _copyPassDescription @16@0:8
METHOD _copyPerformanceStatistics @16@0:8
METHOD _copyRenderGraphDescription @16@0:8
METHOD _createBackgroundColorImageWithSize: ^{CGImage=}32@0:8{CGSize=dd}16
METHOD _createOffscreenFramebufferIfNeeded v16@0:8
METHOD _createPrepareFramebufferIfNeeded v16@0:8
METHOD _createSnapshotAtTime:withSize:antialiasingMode: ^{CGImage=}48@0:8d16{CGSize=dd}24Q40
METHOD _createSnapshotAtTime:withSize:antialiasingMode:error: ^{CGImage=}56@0:8d16{CGSize=dd}24Q40^@48
METHOD _defaultPOVForScene: @24@0:8@16
METHOD _deleteGLFramebuffer v16@0:8
METHOD _didRenderScene: v24@0:8@16
METHOD _disableLinearRendering B16@0:8
METHOD _discardPendingGPUFrameCompletedHandlers v16@0:8
METHOD _discardPendingGPUFramePresentedHandlers v16@0:8
METHOD _discardPendingGPUFrameScheduledHandlers v16@0:8
METHOD _displayLinkStatsTack v16@0:8
METHOD _displayLinkStatsTick v16@0:8
METHOD _draw v16@0:8
METHOD _drawAtTime: v24@0:8d16
METHOD _drawOverlaySceneAtTime: v24@0:8d16
METHOD _drawScene: v24@0:8^{__C3DScene=}16
METHOD _drawSceneWithLegacyRenderer: B24@0:8^{__C3DScene=}16
METHOD _drawSceneWithNewRenderer: B24@0:8^{__C3DScene=}16
METHOD _drawWithJitteringPresentationMode v16@0:8
METHOD _drawableSafeAreaInsets 16@0:8
METHOD _enableARMode B16@0:8
METHOD _endFrame v16@0:8
METHOD _engineContext ^{__C3DEngineContext=}16@0:8
METHOD _getFrameIndex q16@0:8
METHOD _hitTest:viewport:options: @56@0:8{CGPoint=dd}16{CGSize=dd}32@48
METHOD _initWithOptions:isPrivateRenderer:privateRendererOwner:clearsOnDraw:context:renderingAPI: @56@0:8@16B24@28B36^v40Q48
METHOD _installViewport v16@0:8
METHOD _interfaceOrientationDidChange v16@0:8
METHOD _invalidateFramebuffer v16@0:8
METHOD _isNodeInsideFrustum:withPointOfView:viewport: B48@0:8@16@24{SCNVector4=ffff}32
METHOD _jitterAtStep:updateMainFramebuffer:redisplay:jitterer: v40@0:8Q16B24B28@32
METHOD _needsRedrawAsap B16@0:8
METHOD _needsRepetitiveRedraw B16@0:8
METHOD _nextFrameTime d16@0:8
METHOD _nodesInsideFrustumWithPointOfView:viewport: @40@0:8@16{SCNVector4=ffff}24
METHOD _overlaysDidUpdate: v24@0:8@16
METHOD _play v16@0:8
METHOD _preloadResource:abortHandler: B32@0:8@16@?24
METHOD _prepareForTransition:outgoingScene:outgoingPointOfView:completionHandler: v48@0:8@16@24@32@?40
METHOD _prepareGLRenderTarget v16@0:8
METHOD _prepareObject:shouldAbortBlock: B32@0:8@16@?24
METHOD _preparePixelFormat Q16@0:8
METHOD _preparePreloadRenderer: B24@0:8@16
METHOD _prepareRenderTarget v16@0:8
METHOD _prepareSKRenderer @16@0:8
METHOD _presentFramebuffer v16@0:8
METHOD _projectPoint:viewport: {SCNVector3=fff}44@0:8{SCNVector3=fff}16{SCNVector4=ffff}28
METHOD _projectPoints:count:viewport: v48@0:8^{SCNVector3=fff}16Q24{SCNVector4=ffff}32
METHOD _readSubdivCacheForHash: @24@0:8@16
METHOD _recordWithoutExecute B16@0:8
METHOD _releasePreloadRenderer v16@0:8
METHOD _reloadDebugOptions v16@0:8
METHOD _renderAtTime: v24@0:8d16
METHOD _renderAtTime:viewport:encoder:passDescriptor:commandQueue:commandBuffer: v88@0:8d16{CGRect={CGPoint=dd}{CGSize=dd}}24@56@64@72@80
METHOD _renderContextMetal @16@0:8
METHOD _renderGraphFrameRecordingAtPath:withCompletion: v32@0:8@16@?24
METHOD _renderSceneWithEngineContext:sceneTime: v32@0:8^{__C3DEngineContext=}16d24
METHOD _rendererContextGL ^{__C3DRendererContext={__CFRuntimeBase=QAQ}iIIIIfI^{__C3DTexture}^{__C3DStack}^vBBBBB^{__CFDictionary}I^{__CFDictionary}^{__CFDictionary}^{__CFDictionary}{C3DColor4=(?=[4f]{?=ffff})}^vq^{__C3DFXProgramObject}{__C3DEngineStats=IIIIIIIIIIIIIIIIIIIIIIIIdddddddddddddddIIIIIIIIIIIIIIIIIdIdIdddd[60d]Idd}{Cache=[8I]Ii^{__C3DBlendStates}I^{__C3DRasterizerStates}^{__C3DMesh}^{__C3DMeshElement}IIiI^vii}{?=[2I][5i][46{?=iII}][46I]^?^?^?^?^?^?^?^?^?}[2{VolatileObject=^{__C3DArray}II^{__CFArray}}]^{__C3DArray}I^{__CFDictionary}}16@0:8
METHOD _resolveAndDiscardGL v16@0:8
METHOD _resourceManagerMonitor @16@0:8
METHOD _runningInExtension v16@0:8
METHOD _screenTransform {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD _setBackingSize: v24@0:816
METHOD _setContentsScaleFactor: v24@0:8d16
METHOD _setSceneTime: v24@0:8d16
METHOD _setupOffscreenRendererWithSize: v32@0:8{CGSize=dd}16
METHOD _setupSKRendererIfNeeded @16@0:8
METHOD _shouldDelegateARCompositing B16@0:8
METHOD _shouldForwardSceneRendererDelegationMessagesToPrivateRendererOwner B16@0:8
METHOD _showsAuthoringEnvironment B16@0:8
METHOD _superSamplingFactor d16@0:8
METHOD _systemTime d16@0:8
METHOD _unprojectPoint:viewport: {SCNVector3=fff}44@0:8{SCNVector3=fff}16{SCNVector4=ffff}28
METHOD _updateEngineCallbacks v16@0:8
METHOD _updatePointOfView v16@0:8
METHOD _updateProbes:withProgress: v32@0:8@16@24
METHOD _updateSystemTimeAndDeltaTimeWithCurrentTime: v24@0:8d16
METHOD _updateWithSystemTime: v24@0:8d16
METHOD _viewport {SCNVector4=ffff}16@0:8
METHOD _wantsSceneRendererDelegationMessages B16@0:8
METHOD _willRenderScene: v24@0:8@16
METHOD _writeSubdivCacheForHash:dataProvider: v32@0:8@16@?24
METHOD adjustViewportForRendering: 32@0:816
METHOD audioEngine @16@0:8
METHOD audioEnvironmentNode @16@0:8
METHOD audioListener @16@0:8
METHOD autoAdjustCamera B16@0:8
METHOD autoenablesDefaultLighting B16@0:8
METHOD createSnapshot:error: ^{CGImage=}32@0:8d16^@24
METHOD currentCommandBuffer @16@0:8
METHOD currentRenderCommandEncoder @16@0:8
METHOD debugOptions Q16@0:8
METHOD depthPixelFormat Q16@0:8
METHOD forceAsyncShaderCompilation B16@0:8
METHOD frozen B16@0:8
METHOD hitTestWithSegmentFromPoint:toPoint:options: @48@0:8{SCNVector3=fff}16{SCNVector3=fff}28@40
METHOD isJitteringEnabled B16@0:8
METHOD isNodeInsideFrustum:withPointOfView: B32@0:8@16@24
METHOD isTemporalAntialiasingEnabled B16@0:8
METHOD isVertexAmplificationEnabled B16@0:8
METHOD jitteringEnabled B16@0:8
METHOD loops B16@0:8
METHOD nodesInsideFrustumWithPointOfView: @24@0:8@16
METHOD overlaySKScene @16@0:8
METHOD pointOfCulling @16@0:8
METHOD pointOfView @16@0:8
METHOD prepareObjects:withCompletionHandler: v32@0:8@16@?24
METHOD presentScene:withTransition:incomingPointOfView:completionHandler: v48@0:8@16@24@32@?40
METHOD privateRendererOwner @16@0:8
METHOD programWithNode:withMaterial: @32@0:8@16@24
METHOD projectPoint: {SCNVector3=fff}28@0:8{SCNVector3=fff}16
METHOD renderAtTime: v24@0:8d16
METHOD renderAtTime:commandBuffer:viewPoints: v40@0:8d16@24@32
METHOD renderAtTime:encoder:commandQueue:passDescriptor:viewPoints: v56@0:8d16@24@32@40@48
METHOD renderAtTime:encoder:commandQueue:passDescriptor:viewPoints:coordinateSpace: v64@0:8d16@24@32@40@48Q56
METHOD renderAtTime:viewport:commandBuffer:passDescriptor: v72@0:8d16{CGRect={CGPoint=dd}{CGSize=dd}}24@56@64
METHOD renderAtTime:viewport:encoder:passDescriptor:commandQueue: v80@0:8d16{CGRect={CGPoint=dd}{CGSize=dd}}24@56@64@72
METHOD renderContext:commandBufferDidCompleteWithError: v32@0:8@16@24
METHOD renderContext:didFallbackToDefaultTextureForSource:message: v40@0:8@16@24@32
METHOD renderMovieToURL:size:antialiasingMode:attributes:error: B64@0:8@16{CGSize=dd}24Q40@48^@56
METHOD renderWithCommandBuffer:viewPoints: v32@0:8@16@24
METHOD renderWithCommandBuffer:viewpoints:coordinateSpace: v40@0:8@16@24Q32
METHOD renderWithViewport:commandBuffer:passDescriptor: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56
METHOD renderingAPI Q16@0:8
METHOD resolvedBackgroundColorDidChange v16@0:8
METHOD sceneTime d16@0:8
METHOD setAudioListener: v24@0:8@16
METHOD setAutoAdjustCamera: v20@0:8B16
METHOD setAutoenablesDefaultLighting: v20@0:8B16
METHOD setDebugOptions: v24@0:8Q16
METHOD setDisableOverlays: v20@0:8B16
METHOD setJitteringEnabled: v20@0:8B16
METHOD setLoops: v20@0:8B16
METHOD setOverlaySKScene: v24@0:8@16
METHOD setPointOfCulling: v24@0:8@16
METHOD setRendersContinuously: v20@0:8B16
METHOD setScene:completionHandler: v32@0:8@16@?24
METHOD setSceneTime: v24@0:8d16
METHOD setShowsStatistics: v20@0:8B16
METHOD setTechnique: v24@0:8@16
METHOD setUsesReverseZ: v20@0:8B16
METHOD setVertexAmplificationEnabled: v20@0:8B16
METHOD set_antialiasingMode: v24@0:8Q16
METHOD set_aspectRatio: v24@0:8d16
METHOD set_collectCompilationErrors: v20@0:8B16
METHOD set_computedLightingEnvironmentMapsPath: v24@0:8@16
METHOD set_deltaTime: v24@0:8d16
METHOD set_disableLinearRendering: v20@0:8B16
METHOD set_drawableSafeAreaInsets: v32@0:816
METHOD set_enableARMode: v20@0:8B16
METHOD set_nextFrameTime: v24@0:8d16
METHOD set_preparePixelFormat: v24@0:8Q16
METHOD set_recordWithoutExecute: v20@0:8B16
METHOD set_resourceManagerMonitor: v24@0:8@16
METHOD set_screenTransform: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD set_shouldDelegateARCompositing: v20@0:8B16
METHOD set_shouldForwardSceneRendererDelegationMessagesToPrivateRendererOwner: v20@0:8B16
METHOD set_showsAuthoringEnvironment: v20@0:8B16
METHOD set_superSamplingFactor: v24@0:8d16
METHOD set_viewport: v32@0:8{SCNVector4=ffff}16
METHOD set_wantsSceneRendererDelegationMessages: v20@0:8B16
METHOD setupAuthoringEnvironment v16@0:8
METHOD snapshotAtTime:withSize:antialiasingMode: @48@0:8d16{CGSize=dd}24Q40
METHOD snapshotAtTime:withSize:antialiasingMode:error: @56@0:8d16{CGSize=dd}24Q40^@48
METHOD snapshotRendererWithSize: @32@0:8{CGSize=dd}16
METHOD stencilPixelFormat Q16@0:8
METHOD technique @16@0:8
METHOD temporalAntialiasingEnabled B16@0:8
METHOD updateAtTime: v24@0:8d16
METHOD updateCurrentTimeIfPlayingWithSystemTime: v24@0:8d16
METHOD updateProbes:atTime: v32@0:8@16d24
METHOD usesReverseZ B16@0:8
METHOD vertexAmplificationEnabled B16@0:8

=== CLASS SCNScene ===
SUPER: NSObject
SIZE: 192
PROTOCOLS: SCNTransactionCommandObject NSSecureCoding
IVAR +8 0 _scene ^{__C3DScene=}
IVAR +16 0 _sceneSource @"SCNSceneSource"
IVAR +24 0 _physicsWorld @"SCNPhysicsWorld"
IVAR +32 0 _rootNode @"SCNNode"
IVAR +40 0 _layerRootNode [4@"SCNNode"]
IVAR +72 0 _background @"SCNMaterialProperty"
IVAR +80 0 _environment @"SCNMaterialProperty"
IVAR +88 0 _userAttributes @"NSMutableDictionary"
IVAR +96 0 _fogStartDistance d
IVAR +104 0 _fogEndDistance d
IVAR +112 0 _fogDensityExponent d
IVAR +120 0 _fogColor @
IVAR +128 0 _wantsScreenSpaceReflection B
IVAR +136 0 _screenSpaceReflectionSampleCount q
IVAR +144 0 _screenSpaceReflectionMaxRayDistance d
IVAR +152 0 _screenSpaceReflectionStride d
IVAR +160 0 _paused B
IVAR +168 0 _sourceURL @"NSURL"
IVAR +176 0 _pausedForEditing B
IVAR +177 0 _allowsDefaultLightingEnvironmentFallback B
IVAR +184 0 _authoringEnvironment @"SCNAuthoringEnvironment"
CMETHOD avt_newSceneWithURL:options:error: @40@0:8@16@24^@32
CMETHOD avt_nodeNamed:forSceneAtURL:options:error: @48@0:8@16@24@32^@40
CMETHOD avt_rootNodeForSceneAtURL:options:error: @40@0:8@16@24^@32
CMETHOD avt_rootObjectForSceneAtURL:options:error: @40@0:8@16@24^@32
CMETHOD supportsSecureCoding B16@0:8
CMETHOD scene @16@0:8
CMETHOD canImportFileExtension: B24@0:8@16
CMETHOD sceneNamed:inDirectory:options: @40@0:8@16@24@32
CMETHOD _indexPathForNode: @24@0:8@16
CMETHOD canImportFileUTI: B24@0:8@16
CMETHOD jsConstructor :16@0:8
CMETHOD sceneNamed: @24@0:8@16
CMETHOD sceneNamed:options: @32@0:8@16@24
CMETHOD sceneWithData:atIndex:options: @40@0:8@16q24@32
CMETHOD sceneWithData:options: @32@0:8@16@24
CMETHOD sceneWithMDLAsset: @24@0:8@16
CMETHOD sceneWithMDLAsset:options: @32@0:8@16@24
CMETHOD sceneWithSceneRef: @24@0:8^{__C3DScene=}16
CMETHOD sceneWithURL:atIndex:options: @40@0:8@16q24@32
CMETHOD sceneWithURL:options: @32@0:8@16@24
CMETHOD sceneWithURL:options:error: @40@0:8@16@24^@32
CMETHOD supportedFileUTIsForExport @16@0:8
CMETHOD supportedFileUTIsForImport @16@0:8
METHOD avt_writeByArchivingRootNodeInsteadOfScene:toURL:options:error: B44@0:8B16@20@28^@36
METHOD avt_fixQuirksOfNewUSDSchemaWithOptions:handler: v32@0:8Q16@?24
METHOD avt_init @16@0:8
METHOD avt_removeDuplicateSkeletonRootWithHandler: v24@0:8@?16
METHOD avt_removeFaceSetsExportedAsDummyNodesWithHandler: v24@0:8@?16
METHOD avt_setInitialValuesExportedAsAnimationsWithWithOptions:handler: v32@0:8Q16@?24
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD lock v16@0:8
METHOD unlock v16@0:8
METHOD isPaused B16@0:8
METHOD rootNode @16@0:8
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD valueForUndefinedKey: @24@0:8@16
METHOD debugQuickLookObject @16@0:8
METHOD attributeForKey: @24@0:8@16
METHOD root @16@0:8
METHOD startTime d16@0:8
METHOD setPaused: v20@0:8B16
METHOD setStartTime: v24@0:8d16
METHOD frameRate d16@0:8
METHOD background @16@0:8
METHOD scene @16@0:8
METHOD endTime d16@0:8
METHOD setEndTime: v24@0:8d16
METHOD setAttribute:forKey: v32@0:8@16@24
METHOD playbackSpeed f16@0:8
METHOD setPlaybackSpeed: v20@0:8f16
METHOD setFrameRate: v24@0:8d16
METHOD _setRootNode: v24@0:8@16
METHOD setUpAxis: v28@0:8{SCNVector3=fff}16
METHOD upAxis {SCNVector3=fff}16@0:8
METHOD _scenes @16@0:8
METHOD setSceneSource: v24@0:8@16
METHOD __CFObject ^v16@0:8
METHOD particleSystems @16@0:8
METHOD _allowsDefaultLightingEnvironmentFallback B16@0:8
METHOD setScreenSpaceReflectionStride: v24@0:8d16
METHOD _clearSceneRef v16@0:8
METHOD _customDecodingOfSCNScene: v24@0:8@16
METHOD _customEncodingOfSCNScene: v24@0:8@16
METHOD _didDecodeSCNScene: v24@0:8@16
METHOD _didEncodeSCNScene: v24@0:8@16
METHOD _dumpToDisk v16@0:8
METHOD _exportAsMovieOperationWithDestinationURL:size:attributes:delegate:didEndSelector:userInfo: @72@0:8@16{CGSize=dd}24@40@48:56^v64
METHOD _nodeWithIndexPath: @24@0:8@16
METHOD _physicsWorldCreateIfNeeded: @20@0:8B16
METHOD _prettifyForPreview v16@0:8
METHOD _resetSceneTimeRange v16@0:8
METHOD _scaleSceneBy: v24@0:8d16
METHOD _setSourceURL: v24@0:8@16
METHOD _subnodeFromIndexPath: @24@0:8@16
METHOD _syncObjCModel v16@0:8
METHOD addParticleSystem:withTransform: v88@0:8@16{SCNMatrix4=ffffffffffffffff}24
METHOD addSceneAnimation:forKey:target: v40@0:8@16@24@32
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD copyAnimationChannelForKeyPath:property: @32@0:8@16@24
METHOD debugQuickLookObjectWithPointOfView: @24@0:8@16
METHOD exportAsMovieOperationWithDestinationURL:size:attributes:delegate:didEndSelector:userInfo: @72@0:8@16{CGSize=dd}24@40@48:56^v64
METHOD fogColor @16@0:8
METHOD fogDensityExponent d16@0:8
METHOD fogEndDistance d16@0:8
METHOD fogStartDistance d16@0:8
METHOD initForJavascript: @24@0:8@16
METHOD initWithSceneRef: @24@0:8^{__C3DScene=}16
METHOD isPausedForEditing B16@0:8
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD lightingEnvironment @16@0:8
METHOD physicsWorld @16@0:8
METHOD removeAllParticleSystems v16@0:8
METHOD removeParticleSystem: v24@0:8@16
METHOD rootNodeForLayer: @20@0:8i16
METHOD sceneRef ^{__C3DScene=}16@0:8
METHOD sceneSource @16@0:8
METHOD screenSpaceReflectionDepthThreshold d16@0:8
METHOD screenSpaceReflectionMaximumDistance d16@0:8
METHOD screenSpaceReflectionSampleCount q16@0:8
METHOD screenSpaceReflectionStride d16@0:8
METHOD setFogColor: v24@0:8@16
METHOD setFogDensityExponent: v24@0:8d16
METHOD setFogEndDistance: v24@0:8d16
METHOD setFogStartDistance: v24@0:8d16
METHOD setPausedForEditing: v20@0:8B16
METHOD setRootNode: v24@0:8@16
METHOD setRootNode:forLayer: v28@0:8@16i24
METHOD setScreenSpaceReflectionDepthThreshold: v24@0:8d16
METHOD setScreenSpaceReflectionMaximumDistance: v24@0:8d16
METHOD setScreenSpaceReflectionSampleCount: v24@0:8q16
METHOD setWantsScreenSpaceReflection: v20@0:8B16
METHOD set_allowsDefaultLightingEnvironmentFallback: v20@0:8B16
METHOD wantsScreenSpaceReflection B16@0:8
METHOD writeToURL:options: B32@0:8@16@24
METHOD writeToURL:options:delegate:progressHandler: B48@0:8@16@24@32@?40
METHOD writeToURLWithUSDKit: B24@0:8@16

=== CLASS SCNSkinner ===
SUPER: NSObject
SIZE: 40
PROTOCOLS: NSSecureCoding
IVAR +8 0 _skinner ^{__C3DSkinner=}
IVAR +16 0 _baseGeometry @"SCNGeometry"
IVAR +24 0 _bonesAndIndicesCompression B
IVAR +32 0 _skeleton @"SCNNode"
CMETHOD avt_skinnerByInterpolatingFromSkinner:toSkinner:factor:skeleton: @44@0:8@16@24f32@36
CMETHOD supportsSecureCoding B16@0:8
CMETHOD _createSkinnerWithBones:boneWeights:boneIndices:baseGeometry: ^{__C3DSkinner=}48@0:8@16@24@32@40
CMETHOD _createSkinnerWithCompressedData:bonesCount:vertexCount: ^{__C3DSkinner=}40@0:8@16Q24Q32
CMETHOD _skinnerWithBaseGeometry:skinnableGeometry:bones:boneInverseBindTransforms:bindMatrix: @112@0:8@16@24@32@40{SCNMatrix4=ffffffffffffffff}48
CMETHOD skinnerWithBaseGeometry:bones:boneInverseBindTransforms:boneWeights:boneIndices: @56@0:8@16@24@32@40@48
CMETHOD skinnerWithSkinnerRef: @24@0:8^{__C3DSkinner=}16
METHOD avt_setSimdBaseGeometryBindTransform: v80@0:8{?=[4]}16
METHOD avt_simdBaseGeometryBindTransform {?=[4]}16@0:8
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD scene @16@0:8
METHOD setSkeleton: v24@0:8@16
METHOD skeleton @16@0:8
METHOD joints @16@0:8
METHOD __CFObject ^v16@0:8
METHOD set_bonesAndIndicesCompression: v20@0:8B16
METHOD _bonesAndIndicesCompression B16@0:8
METHOD _setBaseGeometry: v24@0:8@16
METHOD _setSkeleton: B24@0:8@16
METHOD _syncObjCModel v16@0:8
METHOD baseGeometry @16@0:8
METHOD baseGeometryBindTransform {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD boneIndices @16@0:8
METHOD boneInverseBindTransforms @16@0:8
METHOD boneWeights @16@0:8
METHOD bones @16@0:8
METHOD initWithSkinnerRef: @24@0:8^{__C3DSkinner=}16
METHOD sceneRef ^{__C3DScene=}16@0:8
METHOD setBaseGeometry: v24@0:8@16
METHOD setBaseGeometryBindTransform: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD setBoneInverseBindTransforms: v24@0:8@16
METHOD setBones: v24@0:8@16
METHOD skinnerRef ^{__C3DSkinner=}16@0:8

=== CLASS SCNTransaction ===
SUPER: NSObject
SIZE: 8
CMETHOD _implementCEKWorkaroundIfNeeded v16@0:8
CMETHOD begin_CEKWorkaround v16@0:8
CMETHOD commit_CEKWorkaround v16@0:8
CMETHOD flush_CEKWorkaround v16@0:8
CMETHOD setAnimationDuration_CEKWorkaround: v24@0:8d16
CMETHOD lock v16@0:8
CMETHOD unlock v16@0:8
CMETHOD completionBlock @?16@0:8
CMETHOD currentState I16@0:8
CMETHOD setCompletionBlock: v24@0:8@?16
CMETHOD setValue:forKey: v32@0:8@16@24
CMETHOD valueForKey: @24@0:8@16
CMETHOD begin v16@0:8
CMETHOD commit v16@0:8
CMETHOD flush v16@0:8
CMETHOD setDisableActions: v20@0:8B16
CMETHOD animationDuration d16@0:8
CMETHOD animationTimingFunction @16@0:8
CMETHOD disableActions B16@0:8
CMETHOD setAnimationDuration: v24@0:8d16
CMETHOD setAnimationTimingFunction: v24@0:8@16
CMETHOD commitImmediate v16@0:8
CMETHOD checkUncommittedTransactions v16@0:8
CMETHOD enqueueCommandForObject:immediateTransactionBlock: v32@0:8@16@?24
CMETHOD immediateMode B16@0:8
CMETHOD immediateModeRestrictedContext ^{__C3DScene=}16@0:8
CMETHOD performPresentationInstanceQueriesInScene:usingBlock: v32@0:8@16@?24
CMETHOD postCommandWithContext:object:applyBlock: v40@0:8^{__C3DScene=}16@24@?32
CMETHOD postCommandWithContext:object:key:applyBlock: v48@0:8^{__C3DScene=}16@24@32@?40
CMETHOD postCommandWithContext:object:key:subscriptIndex:derivedKeyPath:applyBlock: v64@0:8^{__C3DScene=}16@24@32Q40@48@?56
CMETHOD postCommandWithContext:object:key:subscriptKey:derivedKeyPath:applyBlock: v64@0:8^{__C3DScene=}16@24@32@40@48@?56
CMETHOD postCommandWithContext:object:keyPath:applyBlock: v48@0:8^{__C3DScene=}16@24@32@?40
CMETHOD setImmediateMode: v20@0:8B16
CMETHOD setImmediateModeRestrictedContext: v24@0:8^{__C3DScene=}16
METHOD lock v16@0:8
METHOD unlock v16@0:8
METHOD begin v16@0:8
METHOD commit v16@0:8
METHOD flush v16@0:8
METHOD setDisableActions: v20@0:8B16
METHOD animationDuration d16@0:8
METHOD animationTimingFunction @16@0:8
METHOD disableActions B16@0:8
METHOD setAnimationDuration: v24@0:8d16
METHOD setAnimationTimingFunction: v24@0:8@16

=== CLASS SCNView ===
SUPER: UIView
SIZE: 608
PROTOCOLS: SCNSceneRenderer SCNTechniqueSupport
IVAR +408 0 _currentSystemTime d
IVAR +416 0 _lastUpdate d
IVAR +424 0 __ibSceneName @"NSString"
IVAR +432 0 __ibPreferredRenderingAPI Q
IVAR +440 0 _ibNoMultisampling b1
IVAR +448 0 _renderingAPI Q
IVAR +456 0 _isOpaque b1
IVAR +456 0 _rendersContinuously b1
IVAR +456 0 _firstDrawDone b1
IVAR +456 0 _drawOnMainThreadPending b1
IVAR +456 0 _viewIsOffscreen b1
IVAR +456 0 _appChangedColorAppearance b1
IVAR +456 0 _appIsDeactivated b1
IVAR +456 0 _autoPausedScene b1
IVAR +457 0 _inRenderQueueForLayerBackedGLRendering b1
IVAR +457 0 _disableLinearRendering b1
IVAR +457 0 _isInLiveResize b1
IVAR +458 0 _isHidden B
IVAR +459 0 _didTriggerRedrawWhileRendering B
IVAR +464 0 _delegate @
IVAR +472 0 _renderer @"SCNRenderer"
IVAR +480 0 _scene @"SCNScene"
IVAR +488 0 _displayLinkCreationRequested B
IVAR +489 0 _skipFramesIfNoDrawableAvailable B
IVAR +496 0 _displayLink @"SCNDisplayLink"
IVAR +504 0 _preferredFramePerSeconds q
IVAR +512 0 _backingLayer @"CALayer"
IVAR +520 0 _jitterer @"SCNJitterer"
IVAR +528 0 _lock @"SCNRecursiveLock"
IVAR +536 0 _backgroundColor @"UIColor"
IVAR +544 0 _boundsSize {CGSize="width"d"height"d}
IVAR +560 0 _snapshotImageData *
IVAR +568 0 _snapshotImageDataLength Q
IVAR +576 0 _navigationCameraController @"<SCNEventHandler>"
IVAR +584 0 _spriteKitEventHandler @"SCNSpriteKitEventHandler"
IVAR +592 0 _device @"<MTLDevice>"
IVAR +600 0 _controllerGestureRecognizers @"NSArray"
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
CMETHOD keyPathsForValuesAffectingValueForKey: @24@0:8@16
CMETHOD layerClass #16@0:8
CMETHOD lowLatency B16@0:8
CMETHOD _currentSCNViewFocusEnvironment @16@0:8
CMETHOD _isMetalSupported B16@0:8
CMETHOD _kvoKeysForwardedToRenderer @16@0:8
CMETHOD deviceForOptions: @24@0:8@16
CMETHOD displayLinkCallbackShouldReturnImmediately B16@0:8
CMETHOD displayLinkPolicy B16@0:8
CMETHOD renderingAPIForOptions: Q24@0:8@16
CMETHOD shouldObserveApplicationStateToPreventBackgroundGPUAccess B16@0:8
CMETHOD usesSeparateWorkGroup B16@0:8
METHOD avt_simdProjectPoint: 32@0:816
METHOD avt_simdUnprojectPoint: 32@0:816
METHOD avt_simdViewport 16@0:8
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD context ^v16@0:8
METHOD delegate @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD lock v16@0:8
METHOD setDelegate: v24@0:8@16
METHOD setHidden: v20@0:8B16
METHOD unlock v16@0:8
METHOD observeValueForKeyPath:ofObject:change:context: v48@0:8@16@24@32^v40
METHOD snapshot @16@0:8
METHOD commandQueue @16@0:8
METHOD device @16@0:8
METHOD isOpaque B16@0:8
METHOD workingColorSpace ^{CGColorSpace=}16@0:8
METHOD eventHandler @16@0:8
METHOD setEventHandler: v24@0:8@16
METHOD backgroundColor @16@0:8
METHOD initWithFrame: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setBackgroundColor: v24@0:8@16
METHOD setNeedsDisplay v16@0:8
METHOD didMoveToWindow v16@0:8
METHOD setDisplayLink: v24@0:8@16
METHOD _controlsOwnScaleFactor B16@0:8
METHOD _preferredFocusMovementStyle q16@0:8
METHOD _updateOpacity v16@0:8
METHOD displayLayer: v24@0:8@16
METHOD displayLink @16@0:8
METHOD drawRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD focusItemsInRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD hitTest:withEvent: @40@0:8{CGPoint=dd}16@32
METHOD isPlaying B16@0:8
METHOD layoutSubviews v16@0:8
METHOD safeAreaInsetsDidChange v16@0:8
METHOD scene @16@0:8
METHOD setContentScaleFactor: v24@0:8d16
METHOD setPreferredFramesPerSecond: v24@0:8q16
METHOD setScene: v24@0:8@16
METHOD touchesBegan:withEvent: v32@0:8@16@24
METHOD touchesCancelled:withEvent: v32@0:8@16@24
METHOD touchesEnded:withEvent: v32@0:8@16@24
METHOD touchesMoved:withEvent: v32@0:8@16@24
METHOD traitCollectionDidChange: v24@0:8@16
METHOD willMoveToWindow: v24@0:8@16
METHOD stop: v24@0:8@16
METHOD preferredFramesPerSecond q16@0:8
METHOD hitTest:options: @40@0:8{CGPoint=dd}16@32
METHOD setPlaying: v20@0:8B16
METHOD pause: v24@0:8@16
METHOD play: v24@0:8@16
METHOD renderer @16@0:8
METHOD _enterBackground: v24@0:8@16
METHOD _defaultBackgroundColor @16@0:8
METHOD colorPixelFormat Q16@0:8
METHOD currentRenderPassDescriptor @16@0:8
METHOD pauseDisplayLink v16@0:8
METHOD _flipY: d24@0:8d16
METHOD _renderingQueue @16@0:8
METHOD _selectRenderingAPIWithOptions: v24@0:8@16
METHOD currentViewport {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD prepareObject:shouldAbortBlock: B32@0:8@16@?24
METHOD _addGPUFrameCompletedHandler: v24@0:8@?16
METHOD _addGPUFrameScheduledHandler: v24@0:8@?16
METHOD _adjustBackingLayerPixelFormat v16@0:8
METHOD setEaglContext: v24@0:8@16
METHOD setIbSceneName: v24@0:8@16
METHOD setTemporalAntialiasingEnabled: v20@0:8B16
METHOD set_commandBufferStatusMonitor: v24@0:8@16
METHOD showsStatistics B16@0:8
METHOD _backgroundDidChange v16@0:8
METHOD SCN_displayLinkCallback: v24@0:8d16
METHOD __CFObject ^v16@0:8
METHOD _addGPUFramePresentedHandler: v24@0:8@?16
METHOD _allowGPUBackgroundExecution v16@0:8
METHOD setPointOfView: v24@0:8@16
METHOD _authoringEnvironment @16@0:8
METHOD skipFramesIfNoDrawableAvailable B16@0:8
METHOD unprojectPoint: {SCNVector3=fff}28@0:8{SCNVector3=fff}16
METHOD _canJitter B16@0:8
METHOD _checkAndUpdateDisplayLinkStateIfNeeded B16@0:8
METHOD _commandBufferStatusMonitor @16@0:8
METHOD _commonInit: v24@0:8@16
METHOD _createDisplayLinkIfNeeded v16@0:8
METHOD _disableLinearRendering B16@0:8
METHOD _discardPendingGPUFrameCompletedHandlers v16@0:8
METHOD _discardPendingGPUFramePresentedHandlers v16@0:8
METHOD _discardPendingGPUFrameScheduledHandlers v16@0:8
METHOD _drawAtTime: v24@0:8d16
METHOD _enableARMode B16@0:8
METHOD _enterForeground: v24@0:8@16
METHOD _flushDisplayLink v16@0:8
METHOD _ibPreferredRenderingAPI i16@0:8
METHOD _ibSceneName @16@0:8
METHOD _ibWantsMultisampling B16@0:8
METHOD _initializeDisplayLinkWithScreen:policy:completionHandler: v40@0:8@16Q24@?32
METHOD _isEditor B16@0:8
METHOD _jitterRedisplay v16@0:8
METHOD _renderOptions Q16@0:8
METHOD _renderThreadPriority d16@0:8
METHOD _resetContentsScaleFactor v16@0:8
METHOD _resourceManagerMonitor @16@0:8
METHOD _runFPSTestWithDuration: d24@0:8d16
METHOD _sceneDidUpdate: v24@0:8@16
METHOD _scnUpdateContentsGravity v16@0:8
METHOD _screenTransform {SCNMatrix4=ffffffffffffffff}16@0:8
METHOD _setNeedsDisplay v16@0:8
METHOD _shouldDelegateARCompositing B16@0:8
METHOD _showsAuthoringEnvironment B16@0:8
METHOD _superSamplingFactor d16@0:8
METHOD _supportsJitteringSyncRedraw B16@0:8
METHOD _systemTimeAnimationStarted: v24@0:8@16
METHOD _updateBackingSize {CGSize=dd}16@0:8
METHOD _updateContentsScaleFactor v16@0:8
METHOD _updateProbes:withProgress: v32@0:8@16@24
METHOD _viewport {SCNVector4=ffff}16@0:8
METHOD _wantsSceneRendererDelegationMessages B16@0:8
METHOD allowsCameraControl B16@0:8
METHOD antialiasingMode Q16@0:8
METHOD asynchronousResizing B16@0:8
METHOD audioEngine @16@0:8
METHOD audioEnvironmentNode @16@0:8
METHOD audioListener @16@0:8
METHOD autoenablesDefaultLighting B16@0:8
METHOD backingSizeForBoundSize: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD cameraControlConfiguration @16@0:8
METHOD currentRenderCommandEncoder @16@0:8
METHOD debugOptions Q16@0:8
METHOD defaultCameraController @16@0:8
METHOD depthPixelFormat Q16@0:8
METHOD drawableResizesAsynchronously B16@0:8
METHOD eaglContext @16@0:8
METHOD eventHandlerWantsRedraw v16@0:8
METHOD hitTestWithSegmentFromPoint:toPoint:options: @48@0:8{SCNVector3=fff}16{SCNVector3=fff}28@40
METHOD ibPreferredRenderingAPI i16@0:8
METHOD ibSceneName @16@0:8
METHOD ibWantsMultisampling B16@0:8
METHOD initWithFrame:options: @56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD isJitteringEnabled B16@0:8
METHOD isNodeInsideFrustum:withPointOfView: B32@0:8@16@24
METHOD isTemporalAntialiasingEnabled B16@0:8
METHOD loops B16@0:8
METHOD navigationCameraController @16@0:8
METHOD nodesInsideFrustumWithPointOfView: @24@0:8@16
METHOD overlaySKScene @16@0:8
METHOD pointOfCulling @16@0:8
METHOD pointOfView @16@0:8
METHOD prepareObjects:withCompletionHandler: v32@0:8@16@?24
METHOD presentScene:withTransition:incomingPointOfView:completionHandler: v48@0:8@16@24@32@?40
METHOD projectPoint: {SCNVector3=fff}28@0:8{SCNVector3=fff}16
METHOD renderingAPI Q16@0:8
METHOD rendersContinuously B16@0:8
METHOD resumeDisplayLink v16@0:8
METHOD sceneTime d16@0:8
METHOD scn_backingLayer @16@0:8
METHOD scn_inLiveResize B16@0:8
METHOD scn_setBackingLayer: v24@0:8@16
METHOD scn_setGestureRecognizers: v24@0:8@16
METHOD scn_updateGestureRecognizers v16@0:8
METHOD setAllowsCameraControl: v20@0:8B16
METHOD setAntialiasingMode: v24@0:8Q16
METHOD setAsynchronousResizing: v20@0:8B16
METHOD setAudioListener: v24@0:8@16
METHOD setAutoenablesDefaultLighting: v20@0:8B16
METHOD setDebugOptions: v24@0:8Q16
METHOD setDrawableResizesAsynchronously: v20@0:8B16
METHOD setIbPreferredRenderingAPI: v20@0:8i16
METHOD setIbWantsMultisampling: v20@0:8B16
METHOD setJitteringEnabled: v20@0:8B16
METHOD setLoops: v20@0:8B16
METHOD setNavigationCameraController: v24@0:8@16
METHOD setOverlaySKScene: v24@0:8@16
METHOD setPointOfCulling: v24@0:8@16
METHOD setPointOfView:animate: v28@0:8@16B24
METHOD setRendersContinuously: v20@0:8B16
METHOD setSceneTime: v24@0:8d16
METHOD setShowsStatistics: v20@0:8B16
METHOD setSkipFramesIfNoDrawableAvailable: v20@0:8B16
METHOD setTechnique: v24@0:8@16
METHOD setUsesReverseZ: v20@0:8B16
METHOD set_disableLinearRendering: v20@0:8B16
METHOD set_enableARMode: v20@0:8B16
METHOD set_ibPreferredRenderingAPI: v20@0:8i16
METHOD set_ibSceneName: v24@0:8@16
METHOD set_ibWantsMultisampling: v20@0:8B16
METHOD set_renderOptions: v24@0:8Q16
METHOD set_resourceManagerMonitor: v24@0:8@16
METHOD set_screenTransform: v80@0:8{SCNMatrix4=ffffffffffffffff}16
METHOD set_shouldDelegateARCompositing: v20@0:8B16
METHOD set_showsAuthoringEnvironment: v20@0:8B16
METHOD set_superSamplingFactor: v24@0:8d16
METHOD set_wantsSceneRendererDelegationMessages: v20@0:8B16
METHOD stencilPixelFormat Q16@0:8
METHOD switchToCameraNamed: v24@0:8@16
METHOD switchToNextCamera v16@0:8
METHOD technique @16@0:8
METHOD updateAtTime: v24@0:8d16
METHOD usesReverseZ B16@0:8

=== CLASS UIColor ===
SUPER: NSObject
SIZE: 24
PROTOCOLS: UIItemProviderReading UIItemProviderWriting NSItemProviderReading NSItemProviderWriting _UIViewMaterial NSSecureCoding NSCopying
IVAR +8 0 _systemColorName @"NSString"
IVAR +16 0 _cachedStyleString @"NSString"
CMETHOD color:::: @48@0:8d16d24d32d40
CMETHOD scn_colorWithC3DColor: @24@0:8r^{C3DColor4=(?=[4f]{?=ffff})}16
CMETHOD scn_colorWithLinearDisplayP3Red:green:blue:alpha: @48@0:8d16d24d32d40
CMETHOD scn_colorWithLinearSRGBRed:green:blue:alpha: @48@0:8d16d24d32d40
CMETHOD scn_colorWithModelIORed:green:blue:alpha:options: @56@0:8d16d24d32d40@48
CMETHOD avt_colorWithColor4: @32@0:816
CMETHOD color:::: @48@0:8d16d24d32d40
CMETHOD vfx_colorWithCFXColor: @24@0:8r^{CFXColor4=(?=[4f]{?=ffff})}16
CMETHOD vfx_colorWithCFXColor:ignoringColorSpace: @28@0:8r^{CFXColor4=(?=[4f]{?=ffff})}16B24
CMETHOD vfx_colorWithLinearDisplayP3Red:green:blue:alpha: @48@0:8d16d24d32d40
CMETHOD vfx_colorWithLinearSRGBRed:green:blue:alpha: @48@0:8d16d24d32d40
CMETHOD vfx_colorWithModelIORed:green:blue:alpha:options: @56@0:8d16d24d32d40@48
CMETHOD allocWithZone: @24@0:8^{_NSZone=}16
CMETHOD initialize v16@0:8
CMETHOD supportsSecureCoding B16@0:8
CMETHOD classFallbacksForKeyedArchiver @16@0:8
CMETHOD objectWithItemProviderData:typeIdentifier:error: @40@0:8@16@24^@32
CMETHOD readableTypeIdentifiersForItemProvider @16@0:8
CMETHOD writableTypeIdentifiersForItemProvider @16@0:8
CMETHOD blackColor @16@0:8
CMETHOD blueColor @16@0:8
CMETHOD clearColor @16@0:8
CMETHOD colorWithCGColor: @24@0:8^{CGColor=}16
CMETHOD colorWithRed:green:blue:alpha: @48@0:8d16d24d32d40
CMETHOD cyanColor @16@0:8
CMETHOD grayColor @16@0:8
CMETHOD greenColor @16@0:8
CMETHOD magentaColor @16@0:8
CMETHOD redColor @16@0:8
CMETHOD whiteColor @16@0:8
CMETHOD yellowColor @16@0:8
CMETHOD systemBlueColor @16@0:8
CMETHOD systemMintColor @16@0:8
CMETHOD systemPinkColor @16@0:8
CMETHOD _disambiguated_due_to_CIImage_colorWithCGColor: @24@0:8^{CGColor=}16
CMETHOD _disambiguated_due_to_CIImage_colorWithRed:green:blue:alpha: @48@0:8d16d24d32d40
CMETHOD _markedTextBackgroundColor @16@0:8
CMETHOD brownColor @16@0:8
CMETHOD colorWithDisplayP3Red:green:blue:alpha: @48@0:8d16d24d32d40
CMETHOD colorWithPatternImage: @24@0:8@16
CMETHOD colorWithWhite:alpha: @32@0:8d16d24
CMETHOD linkColor @16@0:8
CMETHOD secondaryLabelColor @16@0:8
CMETHOD selectionHighlightColor @16@0:8
CMETHOD systemGreenColor @16@0:8
CMETHOD systemOrangeColor @16@0:8
CMETHOD systemPurpleColor @16@0:8
CMETHOD systemRedColor @16@0:8
CMETHOD systemYellowColor @16@0:8
CMETHOD textGrammarIndicatorColor @16@0:8
CMETHOD _secondarySystemBackgroundColor @16@0:8
CMETHOD _systemGroupBackgroundCellColor @16@0:8
CMETHOD _vibrantLightFillDarkeningColor @16@0:8
CMETHOD systemDarkLightMidGrayTintColor @16@0:8
CMETHOD systemTealColor @16@0:8
CMETHOD tableCellGroupedBackgroundColor @16@0:8
CMETHOD tableGroupedSeparatorLightColor @16@0:8
CMETHOD _separatorColor @16@0:8
CMETHOD _switchOffColor @16@0:8
CMETHOD systemCyanColor @16@0:8
CMETHOD systemFillColor @16@0:8
CMETHOD systemGrayColor @16@0:8
CMETHOD tableCellFocusedBackgroundColor @16@0:8
CMETHOD tableCellbackgroundColorCarPlay @16@0:8
CMETHOD __halfTransparentBlackColor @16@0:8
CMETHOD __halfTransparentWhiteColor @16@0:8
CMETHOD _accessibilityButtonShapesBackgroundColorOnDark @16@0:8
CMETHOD _accessibilityButtonShapesBackgroundColorOnLight @16@0:8
CMETHOD _accessibilityButtonShapesDisabledBackgroundColorOnDark @16@0:8
CMETHOD _accessibilityButtonShapesNoBlendModeBackgroundColorOnDark @16@0:8
CMETHOD _accessibilityButtonShapesNoBlendModeBackgroundColorOnLight @16@0:8
CMETHOD _accessibilityDarkenedColorForColor: @24@0:8@16
CMETHOD _accessibilityLightenedColorForColor: @24@0:8@16
CMETHOD _alertControllerDimmingViewColor @16@0:8
CMETHOD _alertDefaultActionBackgroundColor @16@0:8
CMETHOD _alertDestructiveActionBackgroundColor @16@0:8
CMETHOD _alternateSystemInteractionTintColor @16@0:8
CMETHOD _apiColorNames @16@0:8
CMETHOD _barHairlineShadowColor @16@0:8
CMETHOD _barStyleBlackHairlineShadowColor @16@0:8
CMETHOD _carSystemFocusColor @16@0:8
CMETHOD _carSystemFocusLabelColor @16@0:8
CMETHOD _carSystemFocusPrimaryColor @16@0:8
CMETHOD _carSystemFocusSecondaryColor @16@0:8
CMETHOD _carSystemPrimaryColor @16@0:8
CMETHOD _carSystemQuaternaryColor @16@0:8
CMETHOD _carSystemSecondaryColor @16@0:8
CMETHOD _carSystemTertiaryColor @16@0:8
CMETHOD _colorWithRed:green:blue:alpha:boost: @56@0:8d16d24d32d40d48
CMETHOD _contentBackgroundColor @16@0:8
CMETHOD _controlForegroundColor @16@0:8
CMETHOD _controlHighlightColor @16@0:8
CMETHOD _controlShadowColor @16@0:8
CMETHOD _controlVibrantBottomBackgroundColor @16@0:8
CMETHOD _controlVibrantTopBackgroundColor @16@0:8
CMETHOD _convertColorPickerColor:fromUserInterfaceStyle:to: @40@0:8@16q24q32
CMETHOD _dimmingViewColor @16@0:8
CMETHOD _dynamicCatalogColorForNibEncodingWithName:genericColor: @32@0:8@16@24
CMETHOD _dynamicColorWithColorsByTraitCollection: @24@0:8@16
CMETHOD _dynamicTestColor @16@0:8
CMETHOD _externalBarBackgroundColor @16@0:8
CMETHOD _externalSystemDarkGrayColor @16@0:8
CMETHOD _externalSystemExtraDarkGrayColor @16@0:8
CMETHOD _externalSystemGrayColor @16@0:8
CMETHOD _externalSystemMidGrayColor @16@0:8
CMETHOD _externalSystemSuperDarkGrayColor @16@0:8
CMETHOD _externalSystemWhiteColor @16@0:8
CMETHOD _fillColor @16@0:8
CMETHOD _focusedCarSystemColor: @24@0:8@16
CMETHOD _grayColorForFontSize: @24@0:8d16
CMETHOD _groupTableHeaderFooterTextColor @16@0:8
CMETHOD _labelColor @16@0:8
CMETHOD _legibleForegroundColorForBackgroundColor:traitCollection: @32@0:8@16@24
CMETHOD _linkColor @16@0:8
CMETHOD _luminanceWithRed:green:blue: d40@0:8d16d24d32
CMETHOD _monochromeCellImageTintColor @16@0:8
CMETHOD _opaqueSeparatorColor @16@0:8
CMETHOD _pageControlIndicatorColor @16@0:8
CMETHOD _pageControlPlatterIndicatorColor @16@0:8
CMETHOD _placeholderTextColor @16@0:8
CMETHOD _plainTableHeaderFooterTextColor @16@0:8
CMETHOD _quaternaryFillColor @16@0:8
CMETHOD _quaternaryLabelColor @16@0:8
CMETHOD _searchBarBackgroundColor @16@0:8
CMETHOD _searchFieldDisabledBackgroundColor @16@0:8
CMETHOD _searchFieldPlaceholderTextClearButtonColor @16@0:8
CMETHOD _secondaryFillColor @16@0:8
CMETHOD _secondaryLabelColor @16@0:8
CMETHOD _secondarySystemGroupedBackgroundColor @16@0:8
CMETHOD _sidebarBackgroundColor @16@0:8
CMETHOD _splitViewBorderColor @16@0:8
CMETHOD _swiftColor @16@0:8
CMETHOD _swipedSidebarCellBackgroundColor @16@0:8
CMETHOD _switchOffImageColor @16@0:8
CMETHOD _systemBackgroundColor @16@0:8
CMETHOD _systemBackgroundSectionCellColor @16@0:8
CMETHOD _systemBackgroundSectionColor @16@0:8
CMETHOD _systemBlueColor2 @16@0:8
CMETHOD _systemChromeShadowColor @16@0:8
CMETHOD _systemColorSelectorTable @16@0:8
CMETHOD _systemColorWithName: @24@0:8@16
CMETHOD _systemColorWithUnvalidatedName: @24@0:8@16
CMETHOD _systemDestructiveTintColor @16@0:8
CMETHOD _systemGray2Color @16@0:8
CMETHOD _systemGray3Color @16@0:8
CMETHOD _systemGray4Color @16@0:8
CMETHOD _systemGray5Color @16@0:8
CMETHOD _systemGray6Color @16@0:8
CMETHOD _systemGroupBackgroundColor @16@0:8
CMETHOD _systemGroupedBackgroundColor @16@0:8
CMETHOD _systemInteractionTintColor @16@0:8
CMETHOD _systemMidGrayTintColor @16@0:8
CMETHOD _systemSelectedColor @16@0:8
CMETHOD _tertiaryFillColor @16@0:8
CMETHOD _tertiaryLabelColor @16@0:8
CMETHOD _tertiarySystemBackgroundColor @16@0:8
CMETHOD _tertiarySystemGroupedBackgroundColor @16@0:8
CMETHOD _textFieldBackgroundColor @16@0:8
CMETHOD _textFieldBorderColor @16@0:8
CMETHOD _textFieldDisabledBackgroundColor @16@0:8
CMETHOD _textFieldDisabledBorderColor @16@0:8
CMETHOD _tintColor @16@0:8
CMETHOD _translucentPaperTextureColor @16@0:8
CMETHOD _tvAppKeyColorOrDefaultTint @16@0:8
CMETHOD _tvInterfaceStyleDarkContentColor @16@0:8
CMETHOD _tvInterfaceStyleLightContentColor @16@0:8
CMETHOD _tvLabelOpacityAColor @16@0:8
CMETHOD _tvLabelOpacityBColor @16@0:8
CMETHOD _tvLabelOpacityCColor @16@0:8
CMETHOD _unfocusedCarSystemColor: @24@0:8@16
CMETHOD _vibrantDarkFillDodgeColor @16@0:8
CMETHOD _vibrantLightDividerBurnColor @16@0:8
CMETHOD _vibrantLightDividerDarkeningColor @16@0:8
CMETHOD _vibrantLightFillBurnColor @16@0:8
CMETHOD _vibrantLightSectionDelimiterDividerBurnColor @16@0:8
CMETHOD _vibrantLightSectionDelimiterDividerDarkeningColor @16@0:8
CMETHOD _webContentBackgroundColor @16@0:8
CMETHOD _windowBackgroundColor @16@0:8
CMETHOD candidateRowBackgroundColor @16@0:8
CMETHOD candidateRowHighlightedColor @16@0:8
CMETHOD colorNamed: @24@0:8@16
CMETHOD colorNamed:inBundle:compatibleWithTraitCollection: @40@0:8@16@24@32
CMETHOD colorWithCIColor: @24@0:8@16
CMETHOD colorWithDynamicProvider: @24@0:8@?16
CMETHOD colorWithHue:saturation:brightness:alpha: @48@0:8d16d24d32d40
CMETHOD colorWithRed:green:blue:alpha:exposure: @56@0:8d16d24d32d40d48
CMETHOD colorWithRed:green:blue:alpha:linearExposure: @56@0:8d16d24d32d40d48
CMETHOD darkGrayColor @16@0:8
CMETHOD darkTextColor @16@0:8
CMETHOD externalSystemGreenColor @16@0:8
CMETHOD externalSystemRedColor @16@0:8
CMETHOD externalSystemTealColor @16@0:8
CMETHOD groupTableViewBackgroundColor @16@0:8
CMETHOD infoTextOverPinStripeTextColor @16@0:8
CMETHOD insertionPointColor @16@0:8
CMETHOD labelColor @16@0:8
CMETHOD lightGrayColor @16@0:8
CMETHOD lightTextColor @16@0:8
CMETHOD lineSeparatorColor @16@0:8
CMETHOD noContentDarkGradientBackgroundColor @16@0:8
CMETHOD noContentLightGradientBackgroundColor @16@0:8
CMETHOD opaqueSeparatorColor @16@0:8
CMETHOD orangeColor @16@0:8
CMETHOD pinStripeColor @16@0:8
CMETHOD placeholderTextColor @16@0:8
CMETHOD purpleColor @16@0:8
CMETHOD quaternaryLabelColor @16@0:8
CMETHOD quaternarySystemFillColor @16@0:8
CMETHOD scrollViewTexturedBackgroundColor @16@0:8
CMETHOD secondarySystemBackgroundColor @16@0:8
CMETHOD secondarySystemFillColor @16@0:8
CMETHOD secondarySystemGroupedBackgroundColor @16@0:8
CMETHOD sectionHeaderBackgroundColor @16@0:8
CMETHOD sectionHeaderBorderColor @16@0:8
CMETHOD sectionHeaderOpaqueBackgroundColor @16@0:8
CMETHOD sectionListBorderColor @16@0:8
CMETHOD selectionGrabberColor @16@0:8
CMETHOD separatorColor @16@0:8
CMETHOD systemBackgroundColor @16@0:8
CMETHOD systemBlackColor @16@0:8
CMETHOD systemBrownColor @16@0:8
CMETHOD systemDarkBlueColor @16@0:8
CMETHOD systemDarkExtraLightGrayColor @16@0:8
CMETHOD systemDarkExtraLightGrayTintColor @16@0:8
CMETHOD systemDarkGrayColor @16@0:8
CMETHOD systemDarkGrayTintColor @16@0:8
CMETHOD systemDarkGreenColor @16@0:8
CMETHOD systemDarkLightGrayColor @16@0:8
CMETHOD systemDarkLightGrayTintColor @16@0:8
CMETHOD systemDarkLightMidGrayColor @16@0:8
CMETHOD systemDarkMidGrayColor @16@0:8
CMETHOD systemDarkMidGrayTintColor @16@0:8
CMETHOD systemDarkOrangeColor @16@0:8
CMETHOD systemDarkPinkColor @16@0:8
CMETHOD systemDarkPurpleColor @16@0:8
CMETHOD systemDarkRedColor @16@0:8
CMETHOD systemDarkTealColor @16@0:8
CMETHOD systemDarkYellowColor @16@0:8
CMETHOD systemExtraLightGrayColor @16@0:8
CMETHOD systemExtraLightGrayTintColor @16@0:8
CMETHOD systemGray2Color @16@0:8
CMETHOD systemGray3Color @16@0:8
CMETHOD systemGray4Color @16@0:8
CMETHOD systemGray5Color @16@0:8
CMETHOD systemGray6Color @16@0:8
CMETHOD systemGrayTintColor @16@0:8
CMETHOD systemGroupedBackgroundColor @16@0:8
CMETHOD systemIndigoColor @16@0:8
CMETHOD systemLightGrayColor @16@0:8
CMETHOD systemLightGrayTintColor @16@0:8
CMETHOD systemLightMidGrayColor @16@0:8
CMETHOD systemLightMidGrayTintColor @16@0:8
CMETHOD systemMidGrayColor @16@0:8
CMETHOD systemMidGrayTintColor @16@0:8
CMETHOD systemWhiteColor @16@0:8
CMETHOD tableBackgroundColor @16@0:8
CMETHOD tableCellBackgroundColor @16@0:8
CMETHOD tableCellBlueTextColor @16@0:8
CMETHOD tableCellDefaultSelectionTintColor @16@0:8
CMETHOD tableCellDisabledBackgroundColor @16@0:8
CMETHOD tableCellGrayTextColor @16@0:8
CMETHOD tableCellGroupedBackgroundColorLegacyWhite @16@0:8
CMETHOD tableCellGroupedSelectedBackgroundColor @16@0:8
CMETHOD tableCellHighlightedBackgroundColor @16@0:8
CMETHOD tableCellPlainBackgroundColor @16@0:8
CMETHOD tableCellPlainSelectedBackgroundColor @16@0:8
CMETHOD tableCellValue1BlueColor @16@0:8
CMETHOD tableCellValue2BlueColor @16@0:8
CMETHOD tableGroupedTopShadowColor @16@0:8
CMETHOD tablePlainHeaderFooterBackgroundColor @16@0:8
CMETHOD tablePlainHeaderFooterFloatingBackgroundColor @16@0:8
CMETHOD tableSelectionColor @16@0:8
CMETHOD tableSelectionGradientEndColor @16@0:8
CMETHOD tableSelectionGradientStartColor @16@0:8
CMETHOD tableSeparatorColor @16@0:8
CMETHOD tableSeparatorDarkColor @16@0:8
CMETHOD tableSeparatorLightColor @16@0:8
CMETHOD tableShadowColor @16@0:8
CMETHOD tertiaryLabelColor @16@0:8
CMETHOD tertiarySystemBackgroundColor @16@0:8
CMETHOD tertiarySystemFillColor @16@0:8
CMETHOD tertiarySystemGroupedBackgroundColor @16@0:8
CMETHOD textFieldAtomBlueColor @16@0:8
CMETHOD textFieldAtomPurpleColor @16@0:8
CMETHOD tintColor @16@0:8
CMETHOD underPageBackgroundColor @16@0:8
CMETHOD viewFlipsideBackgroundColor @16@0:8
METHOD g d16@0:8
METHOD r d16@0:8
METHOD a d16@0:8
METHOD b d16@0:8
METHOD scn_C3DColorIgnoringColorSpace:success: {C3DColor4=(?=[4f]{?=ffff})}28@0:8B16^B20
METHOD scn_colorComponentsForModelIO 16@0:8
METHOD avt_colorToColor4 16@0:8
METHOD g d16@0:8
METHOD r d16@0:8
METHOD a d16@0:8
METHOD b d16@0:8
METHOD vfx_CFXColorIgnoringColorSpace:success: {CFXColor4=(?=[4f]{?=ffff})}28@0:8B16^B20
METHOD vfx_colorComponentsForModelIO 16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD hash Q16@0:8
METHOD isEqual: B24@0:8@16
METHOD set v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD classForCoder #16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD loadDataWithTypeIdentifier:forItemProviderCompletionHandler: @32@0:8@16@?24
METHOD writableTypeIdentifiersForItemProvider @16@0:8
METHOD CGColor ^{CGColor=}16@0:8
METHOD cgColor ^{CGColor=}16@0:8
METHOD initWithCGColor: @24@0:8^{CGColor=}16
METHOD initWithRed:green:blue:alpha: @48@0:8d16d24d32d40
METHOD getWhite:alpha: B32@0:8^d16^d24
METHOD _systemColorName @16@0:8
METHOD alphaComponent d16@0:8
METHOD colorWithAlphaComponent: @24@0:8d16
METHOD getRed:green:blue:alpha: B48@0:8^d16^d24^d32^d40
METHOD setStroke v16@0:8
METHOD CIColor @16@0:8
METHOD colorByApplyingContentHeadroom: @24@0:8d16
METHOD setFill v16@0:8
METHOD _accessibilityNameWithLuma @16@0:8
METHOD _boost d16@0:8
METHOD _colorBlendedWithColor: @24@0:8@16
METHOD _colorBlendedWithColor:compositingFilter: @32@0:8@16@24
METHOD _colorBlendedWithColors: @24@0:8@16
METHOD _colorDifferenceFromColor: d24@0:8@16
METHOD _contentHeadroom d16@0:8
METHOD _debugCatalogBundleIdentifier @16@0:8
METHOD _debugName @16@0:8
METHOD _distanceFrom: d24@0:8@16
METHOD _initWithRed:green:blue:alpha:boost: @56@0:8d16d24d32d40d48
METHOD _inverseColor @16@0:8
METHOD _isDeepColor B16@0:8
METHOD _isDynamic B16@0:8
METHOD _isDynamicTintColor B16@0:8
METHOD _isOpaque B16@0:8
METHOD _isSimilarToColor:withinPercentage: B32@0:8@16d24
METHOD _luminance d16@0:8
METHOD _luminanceDifferenceFromColor: d24@0:8@16
METHOD _resolvedMaterialUsingTraitCollection:size: @40@0:8@16{CGSize=dd}24
METHOD _resolvedMaterialWithTraitCollection: @24@0:8@16
METHOD _setDebugCatalogBundleIdentifier: v24@0:8@16
METHOD _setDebugName: v24@0:8@16
METHOD _setSystemColorName: v24@0:8@16
METHOD _standardDynamicRangeColor @16@0:8
METHOD accessibilityName @16@0:8
METHOD colorSpaceName @16@0:8
METHOD colorWithProminence: @24@0:8q16
METHOD getHue:saturation:brightness:alpha: B48@0:8^d16^d24^d32^d40
METHOD initWithCIColor: @24@0:8@16
METHOD initWithDisplayP3Red:green:blue:alpha: @48@0:8d16d24d32d40
METHOD initWithDynamicProvider: @24@0:8@?16
METHOD initWithHue:saturation:brightness:alpha: @48@0:8d16d24d32d40
METHOD initWithItemProviderData:typeIdentifier:error: @40@0:8@16@24^@32
METHOD initWithPatternImage: @24@0:8@16
METHOD initWithRed:green:blue:alpha:exposure: @56@0:8d16d24d32d40d48
METHOD initWithRed:green:blue:alpha:linearExposure: @56@0:8d16d24d32d40d48
METHOD initWithWhite:alpha: @32@0:8d16d24
METHOD isPatternColor B16@0:8
METHOD linearExposure d16@0:8
METHOD prominence q16@0:8
METHOD resolvedColorWithTraitCollection: @24@0:8@16
METHOD standardDynamicRangeColor @16@0:8
METHOD styleString @16@0:8

=== CLASS UIDevice ===
SUPER: NSObject
SIZE: 40
IVAR +8 0 _numDeviceOrientationObservers q
IVAR +16 0 _batteryLevel f
IVAR +24 0 _remoteTouchSurfaceType Q
IVAR +32 0 _remoteHasMicrophone B
IVAR +33 0 _remoteHasMute B
IVAR +34 0 _remoteSupportsPushToTalk B
IVAR +36 0 _deviceFlags {?="batteryMonitoringEnabled"b1"proximityMonitoringEnabled"b1"expectsFaceContactInLandscape"b1"orientation"b3"batteryState"b2"proximityState"b1"hasTouchPadOverride"b1"hasTouchPad"b1"isHardwareKeyboardAvailable"b1}
CMETHOD observeValueForKeyPath:ofObject:change:context: v48@0:8@16@24@32^v40
CMETHOD currentDevice @16@0:8
CMETHOD invalidateSystemSoundEnablement v16@0:8
CMETHOD _hasHomeButton B16@0:8
CMETHOD _isLowEnd B16@0:8
CMETHOD _isWatch B16@0:8
CMETHOD _isWatchCompanion B16@0:8
CMETHOD currentDeviceOrientationAllowingAmbiguous: q20@0:8B16
CMETHOD modelSpecificLocalizedStringKeyForKey: @24@0:8@16
METHOD setSh_hostUserInterfaceIdiom: v24@0:8q16
METHOD sh_hostUserInterfaceIdiom q16@0:8
METHOD doc_symbolName @16@0:8
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD setValue:forKey: v32@0:8@16@24
METHOD systemVersion @16@0:8
METHOD setOrientation: v24@0:8q16
METHOD model @16@0:8
METHOD orientation q16@0:8
METHOD batteryState q16@0:8
METHOD _backlightLevel f16@0:8
METHOD _updateSystemSoundActiveStatus: v24@0:8@16
METHOD _enableDeviceOrientationEvents: v20@0:8B16
METHOD _supportsPencil B16@0:8
METHOD _clearGraphicsQualityOverride v16@0:8
METHOD _deviceInfoForKey: @24@0:8^{__CFString=}16
METHOD _feedbackSupportLevel q16@0:8
METHOD _graphicsQuality q16@0:8
METHOD _hardwareKeyboardAvailabilityChanged v16@0:8
METHOD _hasGraphicsQualityOverride B16@0:8
METHOD _hasTouchPad B16@0:8
METHOD _isHardwareKeyboardAvailable B16@0:8
METHOD _isSystemSoundEnabled B16@0:8
METHOD _keyboardGraphicsQuality q16@0:8
METHOD _loadRemoteDeviceInfoIfNeeded v16@0:8
METHOD _nativeScreenGamut q16@0:8
METHOD _performShimmedRequestIfPossibleForDeviceOrientation: v24@0:8q16
METHOD _playInputDeleteSound v16@0:8
METHOD _playInputSelectSound v16@0:8
METHOD _playSystemSound: v20@0:8I16
METHOD _predictionGraphicsQuality q16@0:8
METHOD _registerForSystemSounds: v24@0:8@16
METHOD _remoteHasMicrophoneCapability B16@0:8
METHOD _remoteTouchSurfaceType Q16@0:8
METHOD _setActiveUserInterfaceIdiom: v24@0:8q16
METHOD _setBacklightLevel: v20@0:8f16
METHOD _setBatteryLevel: v20@0:8f16
METHOD _setBatteryState: v24@0:8q16
METHOD _setExpectsFaceContactInLandscape: v20@0:8B16
METHOD _setGraphicsQualityOverride: v24@0:8q16
METHOD _setHasTouchPad: v20@0:8B16
METHOD _setProximityState: v20@0:8B16
METHOD _softwareDimmingAlpha f16@0:8
METHOD _supportsDeepColor B16@0:8
METHOD _supportsForceTouch B16@0:8
METHOD _supportsPushToTalk B16@0:8
METHOD _tapticEngine @16@0:8
METHOD _unregisterForSystemSounds: v24@0:8@16
METHOD batteryLevel f16@0:8
METHOD beginGeneratingDeviceOrientationNotifications v16@0:8
METHOD buildVersion @16@0:8
METHOD endGeneratingDeviceOrientationNotifications v16@0:8
METHOD identifierForVendor @16@0:8
METHOD isBatteryMonitoringEnabled B16@0:8
METHOD isGeneratingDeviceOrientationNotifications B16@0:8
METHOD isMultitaskingSupported B16@0:8
METHOD isProximityMonitoringEnabled B16@0:8
METHOD localizedModel @16@0:8
METHOD playInputClick v16@0:8
METHOD proximityState B16@0:8
METHOD setBatteryMonitoringEnabled: v20@0:8B16
METHOD setOrientation:animated: v28@0:8q16B24
METHOD setProximityMonitoringEnabled: v20@0:8B16
METHOD systemName @16@0:8
METHOD userInterfaceIdiom q16@0:8

=== CLASS UIFont ===
SUPER: NSObject
SIZE: 8
PROTOCOLS: NSCopying NSSecureCoding
CMETHOD defaultFontSize d16@0:8
CMETHOD _normalizedContentSizeCategory:default: @28@0:8@16B24
CMETHOD _preferredContentSizeCategory: @24@0:8Q16
CMETHOD preferredContentSizeCategory @16@0:8
CMETHOD _setDefaultFontSizesForUserInterfaceIdiom: v24@0:8q16
CMETHOD layoutMetrics @16@0:8
CMETHOD registerLayoutMetrics: v24@0:8#16
CMETHOD systemMinimumFontSize d16@0:8
CMETHOD supportsSecureCoding B16@0:8
CMETHOD classFallbacksForKeyedArchiver @16@0:8
CMETHOD _systemFontOfSize:width:traits: @36@0:8d16@24i32
CMETHOD fontWithFamilyName:traits:size: @36@0:8@16i24d28
CMETHOD systemFontOfSize:weight:design: @40@0:8d16d24@32
CMETHOD userFontOfSize: @24@0:8d16
CMETHOD _evictAllItemsFromFontAndFontDescriptorCaches v16@0:8
CMETHOD _fontWithDescriptor:size:textStyleForScaling:pointSizeForScaling:maximumPointSizeAfterScaling:forIB:legibilityWeight: @68@0:8@16d24@32d40d48B56q60
CMETHOD _fontWithName:size: @32@0:8@16d24
CMETHOD _isSupportedDynamicFontTextStyle: B24@0:8@16
CMETHOD _lightSystemFontOfSize: @24@0:8d16
CMETHOD _opticalBoldSystemFontOfSize: @24@0:8d16
CMETHOD _opticalSystemFontOfSize: @24@0:8d16
CMETHOD _pointSize:scaledLikeTextStyle:maximumPointSize:compatibleWithTraitCollection: d48@0:8d16@24d32@40
CMETHOD _pointSize:scaledLikeTextStyle:maximumPointSize:compatibleWithTraitCollection:roundSize: d52@0:8d16@24d32@40B48
CMETHOD _preferredFontForTextStyle:addingSymbolicTraits: @28@0:8@16I24
CMETHOD _preferredFontForTextStyle:addingSymbolicTraits:design:weight: @44@0:8@16I24@28d36
CMETHOD _preferredFontForTextStyle:addingSymbolicTraits:weight: @36@0:8@16I24d28
CMETHOD _preferredFontForTextStyle:design:variant: @40@0:8@16@24q32
CMETHOD _preferredFontForTextStyle:design:variant:compatibleWithTraitCollection: @48@0:8@16@24q32@40
CMETHOD _preferredFontForTextStyle:design:variant:maximumContentSizeCategory:compatibleWithTraitCollection: @56@0:8@16@24q32@40@48
CMETHOD _preferredFontForTextStyle:design:variant:weight:maximumContentSizeCategory:compatibleWithTraitCollection: @64@0:8@16@24q32d40@48@56
CMETHOD _preferredFontForTextStyle:design:variant:weight:maximumContentSizeCategory:compatibleWithTraitCollection:pointSize:pointSizeForScaling: @80@0:8@16@24q32@40@48@56d64d72
CMETHOD _preferredFontForTextStyle:design:weight: @40@0:8@16@24d32
CMETHOD _preferredFontForTextStyle:design:weight:maximumContentSizeCategory:compatibleWithTraitCollection: @56@0:8@16@24d32@40@48
CMETHOD _preferredFontForTextStyle:design:weight:symbolicTraits:maximumContentSizeCategory:compatibleWithTraitCollection:pointSize:pointSizeForScaling: @76@0:8@16@24@32I40@44@52d60d68
CMETHOD _preferredFontForTextStyle:maximumContentSizeCategory: @32@0:8@16@24
CMETHOD _preferredFontForTextStyle:maximumContentSizeCategory:compatibleWithTraitCollection: @40@0:8@16@24@32
CMETHOD _preferredFontForTextStyle:maximumPointSize:compatibleWithTraitCollection: @40@0:8@16d24@32
CMETHOD _preferredFontForTextStyle:variant: @32@0:8@16q24
CMETHOD _preferredFontForTextStyle:variant:maximumContentSizeCategory: @40@0:8@16q24@32
CMETHOD _preferredFontForTextStyle:weight: @32@0:8@16d24
CMETHOD _readableWidth d16@0:8
CMETHOD _setButtonFontSize: v24@0:8d16
CMETHOD _setLabelFontSize: v24@0:8d16
CMETHOD _setSmallSystemFontSize: v24@0:8d16
CMETHOD _setSystemFontSize: v24@0:8d16
CMETHOD _sharedFontCache @16@0:8
CMETHOD _sharedZeroPointFont @16@0:8
CMETHOD _supportedDynamicFontStyles @16@0:8
CMETHOD _systemFontsOfSize:traits: @28@0:8d16i24
CMETHOD _thinSystemFontOfSize: @24@0:8d16
CMETHOD _ultraLightSystemFontOfSize: @24@0:8d16
CMETHOD boldSystemFontOfSize: @24@0:8d16
CMETHOD buttonFontSize d16@0:8
CMETHOD defaultFontForTextStyle: @24@0:8@16
CMETHOD familyNames @16@0:8
CMETHOD fontNamesForFamilyName: @24@0:8@16
CMETHOD fontWithDescriptor:size: @32@0:8@16d24
CMETHOD fontWithMarkupDescription: @24@0:8@16
CMETHOD fontWithName:size: @32@0:8@16d24
CMETHOD fontWithName:size:traits: @36@0:8@16d24i32
CMETHOD ib_preferredFontForTextStyle: @24@0:8@16
CMETHOD italicSystemFontOfSize: @24@0:8d16
CMETHOD labelFontSize d16@0:8
CMETHOD monospacedDigitSystemFontOfSize:weight: @32@0:8d16d24
CMETHOD monospacedSystemFontOfSize:weight: @32@0:8d16d24
CMETHOD preferredFontForTextStyle: @24@0:8@16
CMETHOD preferredFontForTextStyle:compatibleWithTraitCollection: @32@0:8@16@24
CMETHOD preferredFontForUsage: @24@0:8@16
CMETHOD preferredFontForUsage:contentSizeCategoryName: @32@0:8@16@24
CMETHOD smallSystemFontSize d16@0:8
CMETHOD systemFontOfSize: @24@0:8d16
CMETHOD systemFontOfSize:traits: @28@0:8d16i24
CMETHOD systemFontOfSize:weight: @32@0:8d16d24
CMETHOD systemFontOfSize:weight:width: @40@0:8d16d24d32
CMETHOD systemFontSize d16@0:8
METHOD _bulletGlyph S16@0:8
METHOD _bulletGlyphWithOriginalFont:fontForBulletRendering: S32@0:8@16^@24
METHOD _cachedVariantWeight @16@0:8
METHOD _fontWithVariantWeight: @24@0:8Q16
METHOD _setCachedVariantWeight: v24@0:8@16
METHOD _ui_bulletStringWithFont: @24@0:8^@16
METHOD _variantWeight Q16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD classForCoder #16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD familyName @16@0:8
METHOD fontName @16@0:8
METHOD CTFont ^{__CTFont=}16@0:8
METHOD _backingCGSFont ^{CGFont=}16@0:8
METHOD _getLatin1Glyphs:advanceWidths: B32@0:8r^^S16r^^d24
METHOD _hasColorGlyphs B16@0:8
METHOD htmlMarkupDescriptionForWebKit: @20@0:8B16
METHOD leading d16@0:8
METHOD xHeight d16@0:8
METHOD _isHiraginoFont B16@0:8
METHOD _textMatrixTransformForContext: {CGAffineTransform=dddddd}24@0:8@16
METHOD initWithFamilyName:traits:size: @36@0:8@16i24d28
METHOD __isSystemFont B16@0:8
METHOD _alternateSystemFonts @16@0:8
METHOD _ascenderDeltaForBehavior: d24@0:8q16
METHOD _baseLineHeightForFont: d20@0:8B16
METHOD _bodyLeading d16@0:8
METHOD _defaultGlyphForChar: I20@0:8S16
METHOD _defaultLineHeightForUILayout d16@0:8
METHOD _familyName @16@0:8
METHOD _fontAdjustedForContentSizeCategoryCompatibleWithTraitCollection: @24@0:8@16
METHOD _fontAdjustedForCurrentContentSizeCategory @16@0:8
METHOD _fontScaledByScaleFactor: @24@0:8d16
METHOD _fontScaledLikeTextStyle:maximumPointSize:compatibleWithTraitCollection:forIB: @44@0:8@16d24@32B40
METHOD _isDefaultFace B16@0:8
METHOD _isTextStyleFont B16@0:8
METHOD _isUIFont B16@0:8
METHOD _kernOverride @16@0:8
METHOD _leading d16@0:8
METHOD _scaledValueForValue: d24@0:8d16
METHOD _scaledValueForValue:useLanguageAwareScaling: d28@0:8d16B24
METHOD _textStyle @16@0:8
METHOD _totalAdvancementForNativeGlyphs:count: d32@0:8r^S16q24
METHOD advancementForGlyph: {CGSize=dd}20@0:8S16
METHOD applyToGraphicsContext: v24@0:8@16
METHOD ascender d16@0:8
METHOD bestMatchingFontForCharacters:length:attributes:actualCoveredLength: @48@0:8r^S16Q24@32^Q40
METHOD boundingRectForFont {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD capHeight d16@0:8
METHOD coveredCharacterSet @16@0:8
METHOD descender d16@0:8
METHOD familyNameForCSSFontFamilyValueForWebKit: @20@0:8B16
METHOD fontDescriptor @16@0:8
METHOD fontWithSize: @24@0:8d16
METHOD getAdvancements:forCGGlyphs:count: v40@0:8^{CGSize=dd}16r^S24Q32
METHOD getBoundingRects:forCGGlyphs:count: v40@0:8^{CGRect={CGPoint=dd}{CGSize=dd}}16r^S24Q32
METHOD getCaretPositions:forGlyph:maximumLength: Q36@0:8^d16I24Q28
METHOD getVerticalOriginTranslations:forCGGlyphs:count: v40@0:8^{CGSize=dd}16r^S24Q32
METHOD glyphWithName: S24@0:8@16
METHOD htmlMarkupDescription @16@0:8
METHOD hyphenGlyphForLocale: I24@0:8@16
METHOD initWithMarkupDescription: @24@0:8@16
METHOD initWithName:size: @32@0:8@16d24
METHOD isFixedPitch B16@0:8
METHOD isIBFontMetricsScaledFont B16@0:8
METHOD isIBTextStyleFont B16@0:8
METHOD isSystemFont B16@0:8
METHOD isVertical B16@0:8
METHOD lastResortFont @16@0:8
METHOD lineHeight d16@0:8
METHOD markupDescription @16@0:8
METHOD markupDescriptionForWebKit:pointSize:sizeUnit: @32@0:8B16f20@24
METHOD maximumPointSizeAfterScaling d16@0:8
METHOD mostCompatibleStringEncoding Q16@0:8
METHOD numberOfGlyphs Q16@0:8
METHOD pointSize d16@0:8
METHOD pointSizeForScaling d16@0:8
METHOD readableWidth d16@0:8
METHOD renderingMode Q16@0:8
METHOD screenFontWithRenderingMode: @24@0:8Q16
METHOD setInContext: v24@0:8^{CGContext=}16
METHOD textStyleForScaling @16@0:8
METHOD traits i16@0:8
METHOD underlinePosition d16@0:8
METHOD underlineThickness d16@0:8
METHOD verticalFont @16@0:8

=== CLASS UIImage ===
SUPER: NSObject
SIZE: 144
PROTOCOLS: _UIMenuImageOrName UIItemProviderReading UIItemProviderWriting NSItemProviderReading NSItemProviderWriting UIItemProviderPresentationSizeProviding NSCopying NSSecureCoding
IVAR +8 0 _imageAsset @"UIImageAsset"
IVAR +16 0 _content @"_UIImageContent"
IVAR +24 0 _siblingImages @"NSMapTable"
IVAR +32 0 _configuration @"UIImageConfiguration"
IVAR +40 0 _contentInsets {UIEdgeInsets="top"d"left"d"bottom"d"right"d}
IVAR +72 0 _sizeInPixels {CGSize="width"d"height"d}
IVAR +88 0 _baselineOffsetFromBottom d
IVAR +96 0 _capHeight d
IVAR +104 0 _imageFlags {?="named"b1"asksContentForImageOrientation"b1"imageOrientation"b3"isHorizontallyFlippedImageGeneratedByFlippingRegularImage"b1"cached"b1"hasPattern"b1"isCIImage"b1"renderingMode"b2"suppressesAccessibilityHairlineThickening"b1"hasBaseline"b1"isBaselineExplicit"b1"areContentInsetsExplicit"b1"areAlignmentRectInsetsExplicit"b1"flipsForRightToLeftLayoutDirection"b1"hasCapHeight"b1"hasCommandBuffer"b1"hasLocalRenditionCache"b1}
IVAR +112 0 _alignmentRectInsets {UIEdgeInsets="top"d"left"d"bottom"d"right"d}
CMETHOD doc_AppIconForHostBundleIdentifier: @24@0:8@16
CMETHOD animatedImageWithHEICRepresentation: @24@0:8@16
CMETHOD animatedImageWithHEICSRepresentation: @24@0:8@16
CMETHOD animatedImageWithAPNGRepresentation: @24@0:8@16
CMETHOD avt_animatedImageWithDataRepresentation:ofType: @32@0:8@16@24
CMETHOD initialize v16@0:8
CMETHOD supportsSecureCoding B16@0:8
CMETHOD objectWithItemProviderData:typeIdentifier:error: @40@0:8@16@24^@32
CMETHOD readableTypeIdentifiersForItemProvider @16@0:8
CMETHOD writableTypeIdentifiersForItemProvider @16@0:8
CMETHOD imageWithCGImage: @24@0:8^{CGImage=}16
CMETHOD imageWithContentsOfFile: @24@0:8@16
CMETHOD imageWithData: @24@0:8@16
CMETHOD _iconForResourceProxy:format: @28@0:8@16i24
CMETHOD _systemImageNamed:variableValue:withConfiguration:allowPrivate: @44@0:8@16d24@32B40
CMETHOD _ISImageDescriptorNameForUIApplicationIconFormat: @20@0:8i16
CMETHOD __systemImageNamed: @24@0:8@16
CMETHOD __systemImageNamed:compatibleWithTraitCollection: @32@0:8@16@24
CMETHOD __systemImageNamed:withConfiguration: @32@0:8@16@24
CMETHOD __systemImageNamedSwift: @24@0:8@16
CMETHOD _animatedImageNamed:inBundle:compatibleWithTraitCollection:duration: @48@0:8@16@24@32d40
CMETHOD _animatedResizableImageNamed:inBundle:compatibleWithTraitCollection:capInsets:resizingMode:duration: @88@0:8@16@24@32{UIEdgeInsets=dddd}40q72d80
CMETHOD _applicationIconImageForBundleIdentifier:format: @28@0:8@16i24
CMETHOD _applicationIconImageForBundleIdentifier:format:scale: @36@0:8@16i24d28
CMETHOD _applicationIconImageForBundleIdentifier:format:scale:appearance:style: @52@0:8@16i24d28@36q44
CMETHOD _applyOrientation:toContentSizeInPixels: {CGSize=dd}40@0:8q16{CGSize=dd}24
CMETHOD _backgroundGradientWithStartColor:andEndColor: @32@0:8@16@24
CMETHOD _baseImageDescriptorForUIApplicationIconFormat: @20@0:8i16
CMETHOD _cachedImageForKey:fromBlock: @32@0:8@16@?24
CMETHOD _clearAssetCaches v16@0:8
CMETHOD _defaultBackgroundGradient @16@0:8
CMETHOD _deviceSpecificImageNamed: @24@0:8@16
CMETHOD _deviceSpecificImageNamed:inBundle: @32@0:8@16@24
CMETHOD _dropResourceReferencesForURL: v24@0:8@16
CMETHOD _edgeInsetsForStylePresetNames:scale:traitCollection: {UIEdgeInsets=dddd}40@0:8@16d24@32
CMETHOD _flushCache: v24@0:8@16
CMETHOD _flushSharedImageCache v16@0:8
CMETHOD _generateCompositedSymbolImageForAsset:usingLayers:configuration:alignUsingBaselines: @44@0:8@16@24@32B40
CMETHOD _horizontallyFlippedOrientationForOrientation: q24@0:8q16
CMETHOD _iconForResourceProxy:format:options: @36@0:8@16i24Q28
CMETHOD _iconVariantForUIApplicationIconFormat:idiom:scale: i36@0:8i16q20^d28
CMETHOD _iconVariantForUIApplicationIconFormat:scale: i28@0:8i16^d20
CMETHOD _idiomDefinedByPath: q24@0:8@16
CMETHOD _imageNamed:withTrait: @32@0:8@16@24
CMETHOD _imageWithCGPDFPage: @24@0:8^{CGPDFPage=}16
CMETHOD _imageWithCGPDFPage:scale:orientation: @40@0:8^{CGPDFPage=}16d24q32
CMETHOD _imageWithCGSVGDocument: @24@0:8^{CGSVGDocument=}16
CMETHOD _imageWithCGSVGDocument:scale:orientation: @40@0:8^{CGSVGDocument=}16d24q32
CMETHOD _isCGImageAlphaMask: B24@0:8^{CGImage=}16
CMETHOD _kitImageNamed:withTrait: @32@0:8@16@24
CMETHOD _legibilityImageSizeForSize:style: {CGSize=dd}40@0:8{CGSize=dd}16q32
CMETHOD _loadImageFromURL:completionHandler: v32@0:8@16@?24
CMETHOD _mirroredImageOrientationForOrientation: q24@0:8q16
CMETHOD _noiseImage @16@0:8
CMETHOD _scaleDefinedByPath: Q24@0:8@16
CMETHOD _systemImageNamed: @24@0:8@16
CMETHOD _systemImageNamed:fallback: @32@0:8@16@24
CMETHOD _systemImageNamed:fallback:withConfiguration: @40@0:8@16@24@32
CMETHOD _systemImageNamed:shape: @32@0:8@16q24
CMETHOD _systemImageNamed:shape:fill: @40@0:8@16q24q32
CMETHOD _systemImageNamed:shape:fill:withConfiguration: @48@0:8@16q24q32@40
CMETHOD _systemImageNamed:variableValue:withConfiguration: @40@0:8@16d24@32
CMETHOD _systemImageNamed:variant: @32@0:8@16Q24
CMETHOD _systemImageNamed:variant:withConfiguration: @40@0:8@16Q24@32
CMETHOD _systemImageNamed:withConfiguration: @32@0:8@16@24
CMETHOD _systemImageNamed:withConfiguration:allowPrivate: @36@0:8@16@24B32
CMETHOD _tintedImageForSize:withTint:effectsImage:maskImage:style: @60@0:8{CGSize=dd}16@32@40@48i56
CMETHOD _tintedImageForSize:withTint:maskImage:effectsImage:style: @60@0:8{CGSize=dd}16@32@40@48i56
CMETHOD _tintedImageForSize:withTint:maskImage:effectsImage:style:edgeInsets: @92@0:8{CGSize=dd}16@32@40@48i56{UIEdgeInsets=dddd}60
CMETHOD actionsImage @16@0:8
CMETHOD addImage @16@0:8
CMETHOD animatedImageNamed:duration: @32@0:8@16d24
CMETHOD animatedImageWithImages:duration: @32@0:8@16d24
CMETHOD animatedResizableImageNamed:capInsets:duration: @64@0:8@16{UIEdgeInsets=dddd}24d56
CMETHOD animatedResizableImageNamed:capInsets:resizingMode:duration: @72@0:8@16{UIEdgeInsets=dddd}24q56d64
CMETHOD checkmarkImage @16@0:8
CMETHOD imageAtPath: @24@0:8@16
CMETHOD imageFromAlbumArtData:height:width:bytesPerRow:cache: @40@0:8@16i24i28i32B36
CMETHOD imageNamed: @24@0:8@16
CMETHOD imageNamed:inBundle: @32@0:8@16@24
CMETHOD imageNamed:inBundle:compatibleWithTraitCollection: @40@0:8@16@24@32
CMETHOD imageNamed:inBundle:variableValue:withConfiguration: @48@0:8@16@24d32@40
CMETHOD imageNamed:inBundle:withConfiguration: @40@0:8@16@24@32
CMETHOD imageNamed:withConfiguration: @32@0:8@16@24
CMETHOD imageWithCGImage:scale:orientation: @40@0:8^{CGImage=}16d24q32
CMETHOD imageWithCIImage: @24@0:8@16
CMETHOD imageWithCIImage:scale:orientation: @40@0:8@16d24q32
CMETHOD imageWithContentsOfCPBitmapFile:flags: @28@0:8@16i24
CMETHOD imageWithData:scale: @32@0:8@16d24
CMETHOD kitImageNamed: @24@0:8@16
CMETHOD preferredSymbolImageNamed: @24@0:8@16
CMETHOD preferredSymbolImageNamed:size:compatibleWithTextStyle: @40@0:8@16q24@32
CMETHOD preferredSymbolImageNamed:size:compatibleWithTextStyle:traitCollection:inBundle: @56@0:8@16q24@32@40@48
CMETHOD removeImage @16@0:8
CMETHOD strokedCheckmarkImage @16@0:8
CMETHOD symbolImageNamed: @24@0:8@16
CMETHOD symbolImageNamed:size:compatibleWithFont: @40@0:8@16q24@32
CMETHOD symbolImageNamed:size:compatibleWithFont:traitCollection:inBundle: @56@0:8@16q24@32@40@48
CMETHOD symbolImageNamed:size:weight:compatibleWithFontSize: @48@0:8@16q24q32d40
CMETHOD symbolImageNamed:size:weight:compatibleWithFontSize:traitCollection:inBundle: @64@0:8@16q24q32d40@48@56
CMETHOD systemImageNamed: @24@0:8@16
CMETHOD systemImageNamed:compatibleWithTraitCollection: @32@0:8@16@24
CMETHOD systemImageNamed:variableValue:withConfiguration: @40@0:8@16d24@32
CMETHOD systemImageNamed:withConfiguration: @32@0:8@16@24
METHOD HEICRepresentation @16@0:8
METHOD HEICSRepresentation @16@0:8
METHOD APNGRepresentation @16@0:8
METHOD avt_dataRepresentationForTypeIdentifier: @24@0:8@16
METHOD copyByReorderingImagesWithFirstImageAtTime: @24@0:8d16
METHOD frameDelayInSeconds f16@0:8
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD hash Q16@0:8
METHOD init @16@0:8
METHOD isEqual: B24@0:8@16
METHOD .cxx_destruct v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithContentsOfFile: @24@0:8@16
METHOD initWithData: @24@0:8@16
METHOD duration d16@0:8
METHOD loadDataWithTypeIdentifier:forItemProviderCompletionHandler: @32@0:8@16@?24
METHOD scale d16@0:8
METHOD size {CGSize=dd}16@0:8
METHOD configuration @16@0:8
METHOD CGImage ^{CGImage=}16@0:8
METHOD padding {UIEdgeInsets=dddd}16@0:8
METHOD imageOrientation q16@0:8
METHOD images @16@0:8
METHOD initWithCGImage: @24@0:8^{CGImage=}16
METHOD initWithIOSurface: @24@0:8^{__IOSurface=}16
METHOD content @16@0:8
METHOD _CGPDFPage ^{CGPDFPage=}16@0:8
METHOD _CGPDFPageSize {CGSize=dd}16@0:8
METHOD _isSymbolImage B16@0:8
METHOD baselineOffsetFromBottom d16@0:8
METHOD drawAtPoint: v32@0:8{CGPoint=dd}16
METHOD drawInRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD hasBaseline B16@0:8
METHOD renderingMode q16@0:8
METHOD _bundle @16@0:8
METHOD _encodeDataWithCoder:imageName: v32@0:8@16@24
METHOD _imageOrientationConsideringRTL q16@0:8
METHOD _imageWithSize: @32@0:8{CGSize=dd}16
METHOD _isHierarchicalColorSymbolImage B16@0:8
METHOD _setImageAsset: v24@0:8@16
METHOD _stretchableImageWithCapInsets: @48@0:8{UIEdgeInsets=dddd}16
METHOD traitCollection @16@0:8
METHOD CIImage @16@0:8
METHOD _hasExplicitAlignmentRectInsets B16@0:8
METHOD _imageOrientationConsideringRTLForUserInterfaceLayoutDirection: q24@0:8q16
METHOD _initWithFilledSystemImageNamed:fillColor:symbolColor:withName: @48@0:8@16@24@32@40
METHOD _removeBaseline v16@0:8
METHOD _serializedData @16@0:8
METHOD _subimageInsets {UIEdgeInsets=dddd}16@0:8
METHOD _CGSVGDocument ^{CGSVGDocument=}16@0:8
METHOD _CGSVGDocumentSize {CGSize=dd}16@0:8
METHOD __baselineOffsetFromBottom d16@0:8
METHOD _applicationIconImageForFormat:precomposed: @24@0:8i16B20
METHOD _applicationIconImageForFormat:precomposed:scale: @32@0:8i16B20d24
METHOD _applyBackdropViewSettings: @24@0:8@16
METHOD _applyBackdropViewSettings:allowImageResizing: @28@0:8@16B24
METHOD _applyBackdropViewSettings:includeTints:includeBlur: @32@0:8@16B24B28
METHOD _applyBackdropViewSettings:includeTints:includeBlur:allowImageResizing: @36@0:8@16B24B28B32
METHOD _applyBackdropViewStyle:includeTints:includeBlur: @32@0:8q16B24B28
METHOD _applyBackdropViewStyle:includeTints:includeBlur:graphicsQuality: @40@0:8q16B24B28q32
METHOD _applyBackdropViewStyle:includeTints:includeBlur:graphicsQuality:allowImageResizing: @44@0:8q16B24B28q32B40
METHOD _asMenuElementImage @16@0:8
METHOD _asMenuElementImageName @16@0:8
METHOD _automaticSymbolConfiguration @16@0:8
METHOD _baselineOffsetFromBottom d16@0:8
METHOD _bezeledImageWithShadowRed:green:blue:alpha:fillRed:green:blue:alpha:drawShadow: @84@0:8d16d24d32d40d48d56d64d72B80
METHOD _cacheRendition:forKey: v32@0:8@16@24
METHOD _cachedRenditionForKey: @24@0:8@16
METHOD _calculateEdgeStatistics {?=ddddddddd}16@0:8
METHOD _calculateStatistics {?=ddddddddd}16@0:8
METHOD _calculateStatisticsOfEdge: {?=ddddddddd}20@0:8B16
METHOD _canEncodeAsCatalogData: B24@0:8@16
METHOD _canEncodeWithName:coder: B32@0:8@16@24
METHOD _capHeight d16@0:8
METHOD _colorForFlattening @16@0:8
METHOD _colorForName:withTraitCollection: @32@0:8@16@24
METHOD _conciseDescription @16@0:8
METHOD _configureImage:assumePreconfigured: v28@0:8@16B24
METHOD _contentInsets {UIEdgeInsets=dddd}16@0:8
METHOD _contentRectInPixels {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _contentStretchInPixels {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _copyIOSurface ^{__IOSurface=}16@0:8
METHOD _defaultConfiguration @16@0:8
METHOD _descriptionOmittingSymbolConfiguration: @20@0:8B16
METHOD _doubleBezeledImageWithExteriorShadowRed:green:blue:alpha:interiorShadowRed:green:blue:alpha:fillRed:green:blue:alpha: @112@0:8d16d24d32d40d48d56d64d72d80d88d96d104
METHOD _drawImageForLegibilitySettings:strength:size: v48@0:8@16d24{CGSize=dd}32
METHOD _drawImageForLegibilitySettings:strength:size:alphaOnly: v52@0:8@16d24{CGSize=dd}32B48
METHOD _drawImageForLegibilityStyle:size: v40@0:8q16{CGSize=dd}24
METHOD _drawInContext:rect:layout: v64@0:8^{CGContext=}16{CGRect={CGPoint=dd}{CGSize=dd}}24@56
METHOD _drawInContext:rect:layout:scale:applyContentsTransform: v76@0:8^{CGContext=}16{CGRect={CGPoint=dd}{CGSize=dd}}24@56d64B72
METHOD _effectiveRenderingModeWithSymbolConfiguration: q24@0:8@16
METHOD _encodePropertiesWithCoder: v24@0:8@16
METHOD _existingIdentityDescription @16@0:8
METHOD _flatImageWithColor: @24@0:8@16
METHOD _flatImageWithWhite:alpha: @32@0:8d16d24
METHOD _fullSize {CGSize=dd}16@0:8
METHOD _hasBaseline B16@0:8
METHOD _hasContentInsets B16@0:8
METHOD _hasExplicitBaseline B16@0:8
METHOD _hasExplicitContentInsets B16@0:8
METHOD _hasImageAsset B16@0:8
METHOD _hasVisibleContentInRect:atScale: B56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16d48
METHOD _horizontallyFlipImageOrientation v16@0:8
METHOD _identityDescription @16@0:8
METHOD _imageByApplyingSymbolVariant: @24@0:8@16
METHOD _imageByApplyingVariant:allowNone: @28@0:8Q16B24
METHOD _imageByCreatingBitmapRepresentationWithCompletionHandler: v24@0:8@?16
METHOD _imageByResizingToSize: @32@0:8{CGSize=dd}16
METHOD _imageForLegibilitySettings:strength: @32@0:8@16d24
METHOD _imageForLegibilitySettings:strength:alphaOnly: @36@0:8@16d24B32
METHOD _imageForLegibilityStyle: @24@0:8q16
METHOD _imageOrientationForSymbolLayerConsideringRTLForUserInterfaceLayoutDirection: q24@0:8q16
METHOD _imagePaddedByInsets: @48@0:8{UIEdgeInsets=dddd}16
METHOD _imagePreparedForScreen: @24@0:8@16
METHOD _imageScaledToProportion:interpolationQuality: @28@0:8d16i24
METHOD _imageThatSuppressesAccessibilityHairlineThickening @16@0:8
METHOD _imageTintedWithColor:renderingMode:withUpdatedCGImage: @36@0:8@16q24B32
METHOD _imageWithBitmapRepresentation @16@0:8
METHOD _imageWithBrightnessModifiedForLegibilityStyle: @24@0:8q16
METHOD _imageWithContent: @24@0:8@16
METHOD _imageWithContentInsets: @48@0:8{UIEdgeInsets=dddd}16
METHOD _imageWithContentInsets:withUpdatedCGImage: @52@0:8{UIEdgeInsets=dddd}16B48
METHOD _imageWithImageAsset: @24@0:8@16
METHOD _imageWithImageAsset:configuration: @32@0:8@16@24
METHOD _imageWithSize:content: @40@0:8{CGSize=dd}16@32
METHOD _imageWithStylePresets:tintColor:traitCollection: @40@0:8@16@24@32
METHOD _imageWithSymbolMetricsFromNamedVectorGlyph: @24@0:8@16
METHOD _imageWithVariableValue: @24@0:8d16
METHOD _initWithCGPDFPage: @24@0:8^{CGPDFPage=}16
METHOD _initWithCGPDFPage:scale:orientation: @40@0:8^{CGPDFPage=}16d24q32
METHOD _initWithCGSVGDocument: @24@0:8^{CGSVGDocument=}16
METHOD _initWithCGSVGDocument:scale:orientation: @40@0:8^{CGSVGDocument=}16d24q32
METHOD _initWithCompositedSymbolImageLayers:name: @32@0:8@16@24
METHOD _initWithCompositedSymbolImageLayers:name:alignUsingBaselines: @36@0:8@16@24B32
METHOD _initWithContent:orientation: @32@0:8@16q24
METHOD _initWithContentsOfLCRFile: @24@0:8@16
METHOD _initWithData:immediateLoadWithMaxSize:scale:renderingIntent: @56@0:8@16{CGSize=dd}24d40Q48
METHOD _initWithData:immediateLoadWithMaxSize:scale:renderingIntent:cache: @60@0:8@16{CGSize=dd}24d40Q48B56
METHOD _initWithData:preserveScale: @28@0:8@16B24
METHOD _initWithData:preserveScale:cache: @32@0:8@16B24B28
METHOD _initWithData:preserveScale:cache:scale: @40@0:8@16B24B28d32
METHOD _initWithData:scale: @32@0:8@16d24
METHOD _initWithFilledSystemImageNamed:fillColor: @32@0:8@16@24
METHOD _initWithFilledSystemImageNamed:fillColor:symbolColor: @40@0:8@16@24@32
METHOD _initWithIOSurface:imageOrientation: @32@0:8^{__IOSurface=}16q24
METHOD _initWithIOSurface:scale:orientation: @40@0:8^{__IOSurface=}16d24q32
METHOD _initWithOtherImage: @24@0:8@16
METHOD _initWithSDRIOSurface:HDRIOSurface:scale:orientation: @48@0:8^{__IOSurface=}16^{__IOSurface=}24d32q40
METHOD _inverseAlignmentRectInsets {UIEdgeInsets=dddd}16@0:8
METHOD _isAlphaMask B16@0:8
METHOD _isCGImageOnly B16@0:8
METHOD _isCached B16@0:8
METHOD _isColoredSymbolImage B16@0:8
METHOD _isDecompressing B16@0:8
METHOD _isIconImage B16@0:8
METHOD _isInvisibleAndGetIsTranslucent: B24@0:8^B16
METHOD _isMonochromeColorSymbolImage B16@0:8
METHOD _isMultiColorSymbolImage B16@0:8
METHOD _isNamed B16@0:8
METHOD _isPDFVector B16@0:8
METHOD _isPaletteColorSymbolImage B16@0:8
METHOD _isRTLImage B16@0:8
METHOD _isResizable B16@0:8
METHOD _isSVGVector B16@0:8
METHOD _isSameSymbolImageExceptVariableValue: B24@0:8@16
METHOD _isSubimage B16@0:8
METHOD _isTiledWhenStretchedToSize: B32@0:8{CGSize=dd}16
METHOD _localRenditionCache: @20@0:8B16
METHOD _metricsDescription @16@0:8
METHOD _mirrorImageOrientation v16@0:8
METHOD _outlinePath @16@0:8
METHOD _prepareForScreen:completionHandler: v32@0:8@16@?24
METHOD _primitiveImageAsset @16@0:8
METHOD _probeIsSeeThrough B16@0:8
METHOD _rasterizedImage @16@0:8
METHOD _removeBaselineExplicitly v16@0:8
METHOD _representsCIImageWhichSupportsIOSurfaceRendering B16@0:8
METHOD _representsLayeredImage B16@0:8
METHOD _resizableImageWithCapMask: @20@0:8i16
METHOD _resizableImageWithSubimageInsets:resizeInsets: @80@0:8{UIEdgeInsets=dddd}16{UIEdgeInsets=dddd}48
METHOD _scaleFromPDF d16@0:8
METHOD _setAlignmentRectInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setAlignmentRectInsetsExplicitly: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setAlwaysStretches: v20@0:8B16
METHOD _setBaselineOffsetFromBottom: v24@0:8d16
METHOD _setBaselineOffsetFromBottomExplicitly: v24@0:8d16
METHOD _setCached: v20@0:8B16
METHOD _setCapHeight: v24@0:8d16
METHOD _setCapInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setColorForFlattening: v24@0:8@16
METHOD _setConfiguration: v24@0:8@16
METHOD _setContentInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setContentInsetsExplicitly: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setIsFlippedInRightToLeft v16@0:8
METHOD _setLocalRenditionCache: v24@0:8@16
METHOD _setMidlineOffsetFromCenter: v24@0:8d16
METHOD _setNamed: v20@0:8B16
METHOD _setRenderingMode: v24@0:8q16
METHOD _setSubimageInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setSymbolMetricsFromNamedVectorGlyph: v24@0:8@16
METHOD _shouldDrawVectorContentDirectly B16@0:8
METHOD _sizeInPixels {CGSize=dd}16@0:8
METHOD _sizeInPixelsFromPDF {CGSize=dd}16@0:8
METHOD _sizeWithHairlineThickening:forTraitCollection: {CGSize=dd}28@0:8B16@20
METHOD _suppressesAccessibilityHairlineThickening B16@0:8
METHOD _swizzleContent: @24@0:8@16
METHOD _tiledPatternColor ^{CGColor=}16@0:8
METHOD alignmentRectInsets {UIEdgeInsets=dddd}16@0:8
METHOD capInsets {UIEdgeInsets=dddd}16@0:8
METHOD compositeToPoint:fromRect:operation:fraction: v76@0:8{CGPoint=dd}16{CGRect={CGPoint=dd}{CGSize=dd}}32i64d68
METHOD compositeToPoint:operation: v36@0:8{CGPoint=dd}16i32
METHOD compositeToPoint:operation:fraction: v44@0:8{CGPoint=dd}16i32d36
METHOD compositeToRect:fromRect:operation:fraction: v92@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16{CGRect={CGPoint=dd}{CGSize=dd}}48i80d84
METHOD contentInsets {UIEdgeInsets=dddd}16@0:8
METHOD draw1PartImageInRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD draw1PartImageInRect:fraction: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16d48
METHOD draw1PartImageInRect:fraction:operation: v60@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16d48i56
METHOD draw3PartImageWithSliceRects:inRect: v144@0:8{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}16{CGRect={CGPoint=dd}{CGSize=dd}}112
METHOD draw3PartImageWithSliceRects:inRect:fraction: v152@0:8{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}16{CGRect={CGPoint=dd}{CGSize=dd}}112d144
METHOD draw3PartImageWithSliceRects:inRect:operation:fraction: v156@0:8{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}16{CGRect={CGPoint=dd}{CGSize=dd}}112i144d148
METHOD draw9PartImageWithSliceRects:inRect: v336@0:8{?={?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}}16{CGRect={CGPoint=dd}{CGSize=dd}}304
METHOD draw9PartImageWithSliceRects:inRect:fraction: v344@0:8{?={?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}}16{CGRect={CGPoint=dd}{CGSize=dd}}304d336
METHOD draw9PartImageWithSliceRects:inRect:operation:fraction: v348@0:8{?={?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}{?={CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}{CGRect={CGPoint=dd}{CGSize=dd}}}}16{CGRect={CGPoint=dd}{CGSize=dd}}304i336d340
METHOD drawAsPatternInRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD drawAtPoint:blendMode:alpha: v44@0:8{CGPoint=dd}16i32d36
METHOD drawInRect:blendMode:alpha: v60@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16i48d52
METHOD flattenedImageWithColor: @24@0:8@16
METHOD flipsForRightToLeftLayoutDirection B16@0:8
METHOD hasContentInsets B16@0:8
METHOD hasMidline B16@0:8
METHOD hasPadding B16@0:8
METHOD hdrSurface ^{__IOSurface=}16@0:8
METHOD imageAsset @16@0:8
METHOD imageByAddingContentInsets: @48@0:8{UIEdgeInsets=dddd}16
METHOD imageByAddingPadding: @48@0:8{UIEdgeInsets=dddd}16
METHOD imageByApplyingSymbolConfiguration: @24@0:8@16
METHOD imageByPreparingForDisplay @16@0:8
METHOD imageByPreparingThumbnailOfSize: @32@0:8{CGSize=dd}16
METHOD imageFlippedForRightToLeftLayoutDirection @16@0:8
METHOD imageRef ^{CGImage=}16@0:8
METHOD imageRendererFormat @16@0:8
METHOD imageRestrictedToStandardDynamicRange @16@0:8
METHOD imageWithAlignmentRectInsets: @48@0:8{UIEdgeInsets=dddd}16
METHOD imageWithBaselineOffsetFromBottom: @24@0:8d16
METHOD imageWithConfiguration: @24@0:8@16
METHOD imageWithContentInsets: @48@0:8{UIEdgeInsets=dddd}16
METHOD imageWithHorizontallyFlippedOrientation @16@0:8
METHOD imageWithMidlineOffsetFromCenter: @24@0:8d16
METHOD imageWithPadding: @48@0:8{UIEdgeInsets=dddd}16
METHOD imageWithRenderingMode: @24@0:8q16
METHOD imageWithSymbolConfiguration: @24@0:8@16
METHOD imageWithTintColor: @24@0:8@16
METHOD imageWithTintColor:renderingMode: @32@0:8@16q24
METHOD imageWithoutBaseline @16@0:8
METHOD imageWithoutMidline @16@0:8
METHOD initWithCGImage:imageOrientation: @32@0:8^{CGImage=}16q24
METHOD initWithCGImage:scale:orientation: @40@0:8^{CGImage=}16d24q32
METHOD initWithCIImage: @24@0:8@16
METHOD initWithCIImage:scale:orientation: @40@0:8@16d24q32
METHOD initWithContentsOfFile:cache: @28@0:8@16B24
METHOD initWithData:cache: @28@0:8@16B24
METHOD initWithData:scale: @32@0:8@16d24
METHOD initWithItemProviderData:typeIdentifier:error: @40@0:8@16@24^@32
METHOD ioSurface ^{__IOSurface=}16@0:8
METHOD isFromStatusBarImageProvider B16@0:8
METHOD isHighDynamicRange B16@0:8
METHOD isSymbolImage B16@0:8
METHOD leftCapWidth q16@0:8
METHOD midlineOffsetFromCenter d16@0:8
METHOD patternColor @16@0:8
METHOD preferredPresentationSizeForItemProvider {CGSize=dd}16@0:8
METHOD prepareForDisplayWithCompletionHandler: v24@0:8@?16
METHOD prepareThumbnailOfSize:completionHandler: v40@0:8{CGSize=dd}16@?32
METHOD resizableImageWithCapInsets: @48@0:8{UIEdgeInsets=dddd}16
METHOD resizableImageWithCapInsets:resizingMode: @56@0:8{UIEdgeInsets=dddd}16q48
METHOD resizingMode q16@0:8
METHOD sdrSurface ^{__IOSurface=}16@0:8
METHOD setFlipsForRightToLeftLayoutDirection: v20@0:8B16
METHOD stretchableImageWithLeftCapWidth:topCapHeight: @32@0:8q16q24
METHOD symbolConfiguration @16@0:8
METHOD topCapHeight q16@0:8
METHOD variableValue d16@0:8
METHOD writeToCPBitmapFile:flags: B28@0:8@16i24

=== CLASS UILabel ===
SUPER: UIView
SIZE: 808
PROTOCOLS: _UIViewBaselineSpacing _UIMultilineTextContentSizing _UILabelVisualStyleSubject _UIViewLanguageAwareAdjusting NSCoding UIContentSizeCategoryAdjusting UILetterformAwareAdjusting
IVAR +408 0 _size {CGSize="width"d"height"d}
IVAR +424 0 _backgroundColor @"UIColor"
IVAR +432 0 _highlightedColor @"UIColor"
IVAR +440 0 _numberOfLines q
IVAR +448 0 _intrinsicSizeBaselineInfo {?="firstBaseline"d"lastBaseline"d"referenceBounds"{CGRect="origin"{CGPoint="x"d"y"d}"size"{CGSize="width"d"height"d}}"measuredNumberOfLines"q"bounds"{CGRect="origin"{CGPoint="x"d"y"d}"size"{CGSize="width"d"height"d}}}
IVAR +536 0 _previousBaselineOffsetFromBottom d
IVAR +544 0 _previousFirstLineBaseline d
IVAR +552 0 _content @"_UILabelContent"
IVAR +560 0 _synthesizedAttributedText @"NSAttributedString"
IVAR +568 0 _cachedSynthesizedTextAttributes @"NSDictionary"
IVAR +576 0 _fallbackColorsForUserInterfaceStyle @"NSMutableDictionary"
IVAR +584 0 _minimumFontSize d
IVAR +592 0 _lineSpacing q
IVAR +600 0 _layout @
IVAR +608 0 _scaledMetrics @"_UILabelLegacyScaledMetrics"
IVAR +616 0 _scaledMetricsTargetSize {CGSize="width"d"height"d}
IVAR +632 0 _intrinsicContentSizeCache @"_UITextSizeCache"
IVAR +640 0 _cuiCatalog @"CUICatalog"
IVAR +648 0 _textEncapsulation @"NSTextEncapsulation"
IVAR +656 0 _cuiStyleEffectConfiguration @"CUIStyleEffectConfiguration"
IVAR +664 0 _marqueeAnimations @"NSMutableDictionary"
IVAR +672 0 _marqueeMaskAnimations @"NSMutableDictionary"
IVAR +680 0 _configuration @"_UILabelConfiguration"
IVAR +688 0 _accessibilityButtonShapesChangedToken Q
IVAR +696 0 _lastSetColor @"UIColor"
IVAR +704 0 _lightSourceDescriptor @"_UIIntelligenceLightSourceDescriptor"
IVAR +712 0 _lightContainerView @"UIView"
IVAR +720 0 _marqueeRepeatCount Q
IVAR +728 0 _marqueeLoopPadding d
IVAR +736 0 _marqueeMinimumScaleFactor d
IVAR +744 0 _textLabelFlags {?="highlighted"b1"autosizeTextToFit"b1"supportMultiLineShrinkToFit"b1"autotrackTextToFit"b1"baselineAdjustment"b2"enabled"b1"explicitAlignment"b1"enablesMarqueeWhenAncestorFocused"b1"marqueeEnabled"b1"marqueeRunable"b1"marqueeRequired"b1"marqueeUpdatable"b1"usesExplicitPreferredMaxLayoutWidth"b1"drawsDebugBaselines"b1"drawsDebugGlyphPathBoundsClipping"b1"explicitBaselineOffset"b1"usesSimpleTextEffects"b1"wantsUnderlineForAccessibilityButtonShapesEnabled"b1"disableUpdateTextColorOnTraitCollectionChange"b1"textAlignmentFollowsWritingDirection"b1"textAlignmentMirrored"b1"shortcutIntrinsicContentSize"b1"multilineLabelRequiresCarefulMeasurement"b1"noNeedsDisplayCheckForBaselineCalculationNeeded"b1"overallWritingDirectionFollowsLayoutDirection"b1"hyphenationFactorIgnoredIfURLsDetected"b1"extendedAccessibilityAdjustments"b1"canUseUILabelLayer"b1"implementsDefaultAttributes"b1"textColorFollowsTintColor"b1"materialTextColorFollowsTintColor"b1"showsExpansionTextWhenTruncated"b1"adjustsFontForContentSizeCategory"b1"disableConfigurationUpdate"b1"temporarilyDisableHighlight"b1"wantsContentAwareTypesettingLanguage"b1"isExtremeSizingEnabled"b1"sizingRule"b1"verticalTextEnabled"b1"drawingLightReactiveLayer"b1"drawingLightInertLayer"b1"delegateRespondsToDidChangeGlyphPathsBoundingRect"b1"delegateRespondsToWillChangeGlyphPathsBoundingRect"b1}
IVAR +752 0 _preferredMaxLayoutWidth d
IVAR +760 0 _multilineContextWidth d
IVAR +768 0 _fontForShortcutBaselineCalculation @"UIFont"
IVAR +776 0 _preferredVibrancy q
IVAR +784 0 __visualStyle @"_UILabelVisualStyle"
IVAR +792 0 __impl @"<_UILabelImplProtocol>"
IVAR +800 0 __configuration @"_UILabelConfiguration"
CMETHOD _autoApplyMonochromaticTreatment B16@0:8
CMETHOD _defaultAttributes @16@0:8
CMETHOD _defaultColor @16@0:8
CMETHOD _insetRect:forAttributedString:withDefaultFont:inView: {CGRect={CGPoint=dd}{CGSize=dd}}72@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56@64
CMETHOD defaultFont @16@0:8
CMETHOD layerClass #16@0:8
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD _delegate @16@0:8
METHOD _setDelegate: v24@0:8@16
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD setEnabled: v20@0:8B16
METHOD isEnabled B16@0:8
METHOD setLineSpacing: v24@0:8q16
METHOD color @16@0:8
METHOD lineBreakMode q16@0:8
METHOD lineSpacing q16@0:8
METHOD setColor: v24@0:8@16
METHOD setLineBreakMode: v24@0:8q16
METHOD shadowColor @16@0:8
METHOD shadowOffset {CGSize=dd}16@0:8
METHOD setBounds: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setShadowOffset: v32@0:8{CGSize=dd}16
METHOD setText: v24@0:8@16
METHOD text @16@0:8
METHOD minimumFontSize d16@0:8
METHOD setShadowColor: v24@0:8@16
METHOD _commonInit v16@0:8
METHOD _drawsDebugBaselines B16@0:8
METHOD _hyphenationFactor f16@0:8
METHOD _image @16@0:8
METHOD _setDrawsDebugBaselines: v20@0:8B16
METHOD _setHyphenationFactor: v20@0:8f16
METHOD _setUsesSimpleTextEffects: v20@0:8B16
METHOD _usesSimpleTextEffects B16@0:8
METHOD allowsDefaultTighteningForTruncation B16@0:8
METHOD initWithFrame: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD intrinsicContentSize {CGSize=dd}16@0:8
METHOD lineBreakStrategy Q16@0:8
METHOD minimumScaleFactor d16@0:8
METHOD setAllowsDefaultTighteningForTruncation: v20@0:8B16
METHOD setFrame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setLineBreakStrategy: v24@0:8Q16
METHOD setMinimumScaleFactor: v24@0:8d16
METHOD _setCuiCatalog: v24@0:8@16
METHOD drawTextInRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setHighlighted: v20@0:8B16
METHOD setNeedsDisplay v16@0:8
METHOD _drawTextInRect:forceMultiline: {CGRect={CGPoint=dd}{CGSize=dd}}52@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16B48
METHOD isAccessibilityElementByDefault B16@0:8
METHOD rawSize {CGSize=dd}16@0:8
METHOD showsExpansionTextWhenTruncated B16@0:8
METHOD _accessibilityButtonShapesChangedNotification: v24@0:8@16
METHOD _accessibilityButtonShapesParametersDidChange v16@0:8
METHOD _actualScaleFactor d16@0:8
METHOD _addLightSourceView v16@0:8
METHOD _addViewsForLabelViewTextAttachments:previousLabelViewTextAttachments: v32@0:8@16@24
METHOD _ancestorWillUpdateFocusInContext:withAnimationCoordinator: v32@0:8@16@24
METHOD _applicationDidBecomeActiveNotification: v24@0:8@16
METHOD _applicationWillResignActiveNotification: v24@0:8@16
METHOD _associatedScalingLabel @16@0:8
METHOD _autolayoutSpacingAtEdge:forAttribute:inContainer:isGuide: d40@0:8i16q20@28B36
METHOD _autolayoutSpacingAtEdge:forAttribute:nextToNeighbor:edge:attribute:multiplier: d56@0:8i16q20@28i36q40d48
METHOD _baselineOffsetFromBottom d16@0:8
METHOD _baselineOffsetsAtSize: {?=dd}32@0:8{CGSize=dd}16
METHOD _capOffsetFromBoundsTop d16@0:8
METHOD _clipsGlyphPathFrame:shouldContinueSuperviewTraversal: B56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16^B48
METHOD _configuration @16@0:8
METHOD _content @16@0:8
METHOD _contentDidChange:fromContent: v32@0:8q16@24
METHOD _contentInsetsFromFonts {UIEdgeInsets=dddd}16@0:8
METHOD _cuiCatalog @16@0:8
METHOD _cuiStyleEffectConfiguration @16@0:8
METHOD _defaultAttributes @16@0:8
METHOD _didChangeFromIdiom:onScreen:traverseHierarchy: v36@0:8q16@24B32
METHOD _didMoveFromWindow:toWindow: v32@0:8@16@24
METHOD _disabledFontColor @16@0:8
METHOD _drawFullMarqueeTextInRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _drawTextInRect: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _drawTextInRect:baselineCalculationOnly: {CGRect={CGPoint=dd}{CGSize=dd}}52@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16B48
METHOD _drawingLightInertLayer B16@0:8
METHOD _drawingLightReactiveLayer B16@0:8
METHOD _drawingRectForBounds: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _drawsDebugGlyphPathBoundsClipping B16@0:8
METHOD _firstBaselineOffsetFromTop d16@0:8
METHOD _firstLineBaseline d16@0:8
METHOD _firstLineBaselineFrameOriginY d16@0:8
METHOD _firstLineBaselineOffsetFromBoundsTop d16@0:8
METHOD _firstLineCapFrameOriginY d16@0:8
METHOD _fontForShortcutBaselineCalculation @16@0:8
METHOD _fontInfoForBaselineSpacing @16@0:8
METHOD _geometryChanged:forAncestor: v32@0:8r^{?=Q{CGPoint=dd}{CGPoint=dd}{CGSize=dd}{CGPoint=dd}{CATransform3D=dddddddddddddddd}q@@@@}16@24
METHOD _glyphPathBoundsClippingDetected B16@0:8
METHOD _glyphPathBoundsIntersectionData @16@0:8
METHOD _glyphPathsBoundingRect {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _hasBaseline B16@0:8
METHOD _hasCustomAutolayoutNeighborSpacingForAttribute: B24@0:8^q16
METHOD _hasFontInfoForVerticalBaselineSpacing B16@0:8
METHOD _intelligenceBaseClass #16@0:8
METHOD _intelligenceCollectContentIn:collector: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _intrinsicSizeWithinSize: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD _invalidateBaselineConstraints v16@0:8
METHOD _invalidateLabelSize v16@0:8
METHOD _isExtremeSizingEnabled B16@0:8
METHOD _isMarqueeUpdatable B16@0:8
METHOD _lastLineBaseline d16@0:8
METHOD _lastLineBaselineFrameOriginY d16@0:8
METHOD _lightSourceDescriptor @16@0:8
METHOD _marqueeMinimumScaleFactor d16@0:8
METHOD _measuredNumberOfLines q16@0:8
METHOD _minimumFontSize d16@0:8
METHOD _monochromaticTreatmentStateDidChange v16@0:8
METHOD _multilineContextWidth d16@0:8
METHOD _multilineLabelRequiresCarefulMeasurement B16@0:8
METHOD _needsDoubleUpdateConstraintsPass B16@0:8
METHOD _nilBackgroundColor @16@0:8
METHOD _ola_willApplyMultilineTextWidthDisambiguationConstraint v16@0:8
METHOD _overallWritingDirectionFollowsLayoutDirection B16@0:8
METHOD _overrideTintColorAutomaticallyOverridesTintColor B16@0:8
METHOD _preferredMaxLayoutWidth d16@0:8
METHOD _preferredVibrancy q16@0:8
METHOD _prepareForFirstIntrinsicContentSizeCalculation v16@0:8
METHOD _prepareForSecondIntrinsicContentSizeCalculationWithLayoutEngineBounds: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _removeLightSourceView v16@0:8
METHOD _resetUsesExplicitPreferredMaxLayoutWidth v16@0:8
METHOD _setAssociatedScalingLabel: v24@0:8@16
METHOD _setConfiguration: v24@0:8@16
METHOD _setContent: v24@0:8@16
METHOD _setCuiStyleEffectConfiguration: v24@0:8@16
METHOD _setDefaultAttributes: v24@0:8@16
METHOD _setDrawingLightInertLayer: v20@0:8B16
METHOD _setDrawingLightReactiveLayer: v20@0:8B16
METHOD _setDrawsDebugGlyphPathBoundsClipping: v20@0:8B16
METHOD _setEnableMonochromaticTreatment: v20@0:8B16
METHOD _setExtremeSizingEnabled: v20@0:8B16
METHOD _setFallbackTextColor:forUserInterfaceStyle: v32@0:8@16q24
METHOD _setFirstLineBaselineFrameOriginY: v24@0:8d16
METHOD _setFirstLineCapFrameOriginY: v24@0:8d16
METHOD _setFont: v24@0:8@16
METHOD _setLastLineBaselineFrameOriginY: v24@0:8d16
METHOD _setLightSourceDescriptor: v24@0:8@16
METHOD _setLineBreakMode: v24@0:8q16
METHOD _setLineBreakStrategy: v24@0:8Q16
METHOD _setMarqueeMinimumScaleFactor: v24@0:8d16
METHOD _setMarqueeUpdatable: v20@0:8B16
METHOD _setMinimumFontSize: v24@0:8d16
METHOD _setMultilineContextWidth: v24@0:8d16
METHOD _setMultilineLabelRequiresCarefulMeasurement: v20@0:8B16
METHOD _setOverallWritingDirectionFollowsLayoutDirection: v20@0:8B16
METHOD _setPreferredVibrancy: v24@0:8q16
METHOD _setText: v24@0:8@16
METHOD _setTextAlignment: v24@0:8q16
METHOD _setTextAlignmentFollowsWritingDirection: v20@0:8B16
METHOD _setTextAlignmentMirrored: v20@0:8B16
METHOD _setTextColor: v24@0:8@16
METHOD _setTextColorFollowsTintColor: v20@0:8B16
METHOD _setTextEncapsulation: v24@0:8@16
METHOD _setUseShortcutIntrinsicContentSize: v20@0:8B16
METHOD _setVerticalTextEnabled: v20@0:8B16
METHOD _setVisualStyle: v24@0:8@16
METHOD _setWantsContentAwareTypesettingLanguage: v20@0:8B16
METHOD _setWantsUnderlineForAccessibilityButtonShapesEnabled: v20@0:8B16
METHOD _shouldCeilSizeToViewScale B16@0:8
METHOD _shouldInvalidateBaselineConstraintsForSize:oldSize: B48@0:8{CGSize=dd}16{CGSize=dd}32
METHOD _startMarqueeIfNecessary v16@0:8
METHOD _stopMarqueeWithRedisplay: v20@0:8B16
METHOD _stringDrawingContext @16@0:8
METHOD _stringDrawingOptions q16@0:8
METHOD _supportedTreatmentForTreatment: q24@0:8q16
METHOD _synthesizedAttributedText @16@0:8
METHOD _textAlignmentFollowsWritingDirection B16@0:8
METHOD _textAlignmentMirrored B16@0:8
METHOD _textColorFollowsTintColor B16@0:8
METHOD _textEncapsulation @16@0:8
METHOD _textRectForBounds:limitedToNumberOfLines:includingShadow: {CGRect={CGPoint=dd}{CGSize=dd}}60@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16q48B56
METHOD _tightBoundingBoxLayoutGuide @16@0:8
METHOD _tightBoundingRect {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _tightBoundingRectOfFirstLine {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _updateProperties v16@0:8
METHOD _updateScrollPocketInteraction v16@0:8
METHOD _updateSystemConstraints v16@0:8
METHOD _updateTextColorWithFallbackColorIfNeeded v16@0:8
METHOD _useShortcutIntrinsicContentSize B16@0:8
METHOD _verticalTextEnabled B16@0:8
METHOD _visualStyle @16@0:8
METHOD _wantsContentAwareTypesettingLanguage B16@0:8
METHOD _wantsUnderlineForAccessibilityButtonShapesEnabled B16@0:8
METHOD adjustsFontForContentSizeCategory B16@0:8
METHOD adjustsFontSizeToFitWidth B16@0:8
METHOD adjustsLetterSpacingToFitWidth B16@0:8
METHOD alignmentRectInsets {UIEdgeInsets=dddd}16@0:8
METHOD attributedText @16@0:8
METHOD baselineAdjustment q16@0:8
METHOD currentTextColor @16@0:8
METHOD defaultAccessibilityTraits Q16@0:8
METHOD drawRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD drawsUnderline B16@0:8
METHOD enablesMarqueeWhenAncestorFocused B16@0:8
METHOD font @16@0:8
METHOD highlightedTextColor @16@0:8
METHOD invalidateIntrinsicContentSize v16@0:8
METHOD isElementAccessibilityExposedToInterfaceBuilder B16@0:8
METHOD isHighlighted B16@0:8
METHOD largeContentTitle @16@0:8
METHOD layerWillDraw: v24@0:8@16
METHOD marqueeEnabled B16@0:8
METHOD marqueeLoopPadding d16@0:8
METHOD marqueeRepeatCount Q16@0:8
METHOD marqueeRunning B16@0:8
METHOD numberOfLines q16@0:8
METHOD preferredMaxLayoutWidth d16@0:8
METHOD preferredVibrancy q16@0:8
METHOD scrollPocketInteraction @16@0:8
METHOD setAdjustsFontForContentSizeCategory: v20@0:8B16
METHOD setAdjustsFontSizeToFitWidth: v20@0:8B16
METHOD setAdjustsLetterSpacingToFitWidth: v20@0:8B16
METHOD setAttributedText: v24@0:8@16
METHOD setBaselineAdjustment: v24@0:8q16
METHOD setDrawsUnderline: v20@0:8B16
METHOD setEnablesMarqueeWhenAncestorFocused: v20@0:8B16
METHOD setFont: v24@0:8@16
METHOD setHighlightedTextColor: v24@0:8@16
METHOD setMarqueeEnabled: v20@0:8B16
METHOD setMarqueeLoopPadding: v24@0:8d16
METHOD setMarqueeRepeatCount: v24@0:8Q16
METHOD setMarqueeRunning: v20@0:8B16
METHOD setMinimumFontSize: v24@0:8d16
METHOD setNumberOfLines: v24@0:8q16
METHOD setPreferredMaxLayoutWidth: v24@0:8d16
METHOD setPreferredVibrancy: v24@0:8q16
METHOD setRawSize: v32@0:8{CGSize=dd}16
METHOD setScrollPocketInteraction: v24@0:8@16
METHOD setSemanticContentAttribute: v24@0:8q16
METHOD setShadowBlur: v24@0:8d16
METHOD setShowsExpansionTextWhenTruncated: v20@0:8B16
METHOD setSizingRule: v24@0:8q16
METHOD setTextAlignment: v24@0:8q16
METHOD setTextColor: v24@0:8@16
METHOD setUserInteractionEnabled: v20@0:8B16
METHOD set_fontForShortcutBaselineCalculation: v24@0:8@16
METHOD shadowBlur d16@0:8
METHOD sizeThatFits: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD sizingRule q16@0:8
METHOD textAlignment q16@0:8
METHOD textColor @16@0:8
METHOD textRectForBounds: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD textRectForBounds:limitedToNumberOfLines: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16q48
METHOD textSize {CGSize=dd}16@0:8
METHOD textSizeForWidth: {CGSize=dd}24@0:8d16
METHOD tintColorDidChange v16@0:8
METHOD traitCollectionDidChange: v24@0:8@16

=== CLASS UITapGestureRecognizer ===
SUPER: UIGestureRecognizer
SIZE: 320
PROTOCOLS: UITapRecognizerDelegate
IVAR +280 0 _locationInView {CGPoint="x"d"y"d}
IVAR +296 0 _imp @"UITapRecognizer"
IVAR +304 0 _delaysRecognitionForGreaterTapCounts I
IVAR +308 0 _isSingleKeyPressGesture B
IVAR +312 0 _buttonType q
CMETHOD supportsSecureCoding B16@0:8
CMETHOD _supportsTouchContinuation B16@0:8
METHOD dealloc v16@0:8
METHOD .cxx_destruct v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD location {CGPoint=dd}16@0:8
METHOD locationInView: {CGPoint=dd}24@0:8@16
METHOD touches @16@0:8
METHOD _isGestureType: B24@0:8q16
METHOD _setButtonType: v24@0:8q16
METHOD numberOfTouches Q16@0:8
METHOD _allowableSeparation d16@0:8
METHOD _allowableTouchTimeSeparation d16@0:8
METHOD _appendSubclassDescription: v24@0:8@16
METHOD _buttonType q16@0:8
METHOD _canHandleTouches B16@0:8
METHOD _delaysRecognitionForGreaterTapCounts B16@0:8
METHOD _digitizerLocation {CGPoint=dd}16@0:8
METHOD _finalStateForRecognitionWithNumberOfTaps: q24@0:8Q16
METHOD _resetGestureRecognizer v16@0:8
METHOD _setAllowableSeparation: v24@0:8d16
METHOD _setAllowableTouchTimeSeparation: v24@0:8d16
METHOD _setDelaysRecognitionForGreaterTapCounts: v20@0:8B16
METHOD _shouldFailInResponseToPresses:withEvent: B32@0:8@16@24
METHOD _shouldReceivePress: B24@0:8@16
METHOD _touchSloppinessFactor d16@0:8
METHOD allowableMovement d16@0:8
METHOD buttonMaskRequired q16@0:8
METHOD canPreventGestureRecognizer: B24@0:8@16
METHOD centroid {CGPoint=dd}16@0:8
METHOD continuousTapRecognition B16@0:8
METHOD currentNumberOfTaps Q16@0:8
METHOD initWithTarget:action: @32@0:8@16:24
METHOD isSingleKeyPressGesture B16@0:8
METHOD locationOfTouch:inView: {CGPoint=dd}32@0:8Q16@24
METHOD maximumIntervalBetweenSuccessiveTaps d16@0:8
METHOD maximumSingleTapDuration d16@0:8
METHOD maximumTapDuration d16@0:8
METHOD numberOfTapsRequired Q16@0:8
METHOD numberOfTouchesRequired Q16@0:8
METHOD pressesBegan:withEvent: v32@0:8@16@24
METHOD pressesCancelled:withEvent: v32@0:8@16@24
METHOD pressesChanged:withEvent: v32@0:8@16@24
METHOD pressesEnded:withEvent: v32@0:8@16@24
METHOD resetTapCountForTapRecognizer: v24@0:8@16
METHOD setAllowableMovement: v24@0:8d16
METHOD setAllowedPressTypes: v24@0:8@16
METHOD setButtonMaskRequired: v24@0:8q16
METHOD setContinuousTapRecognition: v20@0:8B16
METHOD setIsSingleKeyPressGesture: v20@0:8B16
METHOD setMaximumIntervalBetweenSuccessiveTaps: v24@0:8d16
METHOD setMaximumSingleTapDuration: v24@0:8d16
METHOD setMaximumTapDuration: v24@0:8d16
METHOD setNumberOfTapsRequired: v24@0:8Q16
METHOD setNumberOfTouchesRequired: v24@0:8Q16
METHOD shouldRequireFailureOfGestureRecognizer: B24@0:8@16
METHOD tapIsPossibleForTapRecognizer: B24@0:8@16
METHOD tapRecognizerFailedToRecognizeTap: v24@0:8@16
METHOD tapRecognizerRecognizedTap: v24@0:8@16
METHOD touchesBegan:withEvent: v32@0:8@16@24
METHOD touchesCancelled:withEvent: v32@0:8@16@24
METHOD touchesEnded:withEvent: v32@0:8@16@24
METHOD touchesMoved:withEvent: v32@0:8@16@24

=== CLASS UIView ===
SUPER: UIResponder
SIZE: 408
PROTOCOLS: _UIPopoverPresentationControllerSourceItem_Internal _UIViewSubtreeMonitor _UIScrollViewScrollObserver_Internal NSISEngineDelegate NSISVariableDelegate _UILayoutItem _UIMultilineTextContentSizing UILargeContentViewerItem_Private UILargeContentViewerItem UITextEffectsOrdering UILayoutItem_Internal _UIMorphableInternal _UIFallbackEnvironment _UIMaskingCoordinateSpace _UIRelativeCornerMaskingProvider CALayerPrivateDelegate _UITraitEnvironmentInternal _UITraitTrackingSupporting _UITraitOverrideDelegate _UIStateTrackingSupporting _UIFocusEnvironmentPlatformSupport _UIFocusItemPlatformSupport _UIFocusItemUIKitAdditions _UIFocusItemDebuggable _UIGeometryChangeObserver _UIDropInteractionOwning UITraitChangeObservableInternal _UIFocusEnvironmentPrivate _UIFocusItemPrivate _UIFocusItemContainerPrivate _UIFocusItemForTVFrameworksOnly NSTextViewportRenderingSurface _UIAppearanceRestriction _UIDynamicReferenceSystem _UIGestureRecognizerContainer UITraitChangeObservable NSCoding UIAppearance UIAppearanceContainer UIDynamicItem UITraitEnvironment UICoordinateSpace UIFocusItem UIFocusItemContainer CALayerDelegate
IVAR +16 0 _constraintsExceptingSubviewAutoresizingConstraints @"NSMutableArray"
IVAR +24 0 _cachedTraitCollection @"UITraitCollection"
IVAR +32 0 _swiftAnimationInfo @
IVAR +40 0 _traitChangeRegistry @"_UITraitChangeRegistry"
IVAR +48 0 _layerRetained @"CALayer"
IVAR +56 0 _subviewCache @"NSArray"
IVAR +64 0 _window @"UIWindow"
IVAR +72 0 _gestureRecognizers @"NSArray"
IVAR +80 0 _viewDelegate @"UIViewController"
IVAR +88 0 _viewFlags {?="userInteractionDisabled"b1"implementsDrawRect"b1"implementsDidScroll"b1"implementsMouseTracking"b1"implementsIntrinsicContentSize"b1"hasBackgroundColor"b1"hasBackgroundColorSystemColorName"b1"hasInteractionTintColor"b1"hasOverrideTintColor"b1"isOpaque"b1"becomeFirstResponderWhenCapable"b1"isDeallocInitiated"b1"isInUIViewDealloc"b1"hasPreparedForWindowDealloc"b1"isFirstResponder"b1"isAncestorOfFirstResponder"b1"dontAutoresizeSubviews"b1"autoresizeMask"b6"patternBackground"b1"fixedBackgroundPattern"b1"dontAnimate"b1"superLayerIsView"b1"layerKitPatternDrawing"b1"multipleTouchEnabled"b1"exclusiveTouch"b1"hasViewController"b1"needsDidAppearOrDisappear"b1"deliversTouchesForGesturesToSuperview"b1"deliversPressesForGesturesToSuperview"b1"chargeEnabled"b1"skipsSubviewEnumeration"b1"needsDisplayOnBoundsChange"b1"hasTiledLayer"b1"hasContentSizeCategoryLimits"b1"traversalMark"b1"appearanceIsInvalid"b1"monitorsSubtree"b1"hostsAutolayoutEngine"b1"constraintsAreClean"b1"subviewLayoutConstraintsAreClean"b1"intrinsicContentSizeConstraintsAreClean"b1"strictDescendantNeedsDoubleUpdateConstraints"b1"strictDescendantNeedsDoubleUpdateConstraintsIsInvalid"b1"hasStoredLayoutEngineWidth"b1"determiningWidthForDoubleUpdateConstraints"b1"inSecondConstraintsPass"b1"potentiallyHasDanglyConstraints"b1"doesNotTranslateAutoresizingMaskIntoConstraints"b1"autolayoutIsClean"b1"autolayoutBoundsAreClean"b1"layoutFlushingDisabled"b1"layingOutFromConstraints"b1"wantsAutolayout"b1"subviewWantsAutolayout"b1"isApplyingValuesFromEngine"b1"autolayoutIsSendingSetBoundsWithNoChanges"b1"isResizingDueToParentResize"b1"isInLayoutSubviewsOrVCCallback"b1"isInUpdateProperties"b1"isInAnimatedLayout"b1"isSubviewUpdatingAutoresizingConstraints"b1"isUpdatingConstraints"b1"isReapplyingStillActiveBrokenConstraints"b1"isSuppressingUnsatisfiableConstraintsLoggingForNestedLayoutEngines"b1"isHostingUpdateConstraintsPassDuringLayout"b1"isRunningEngineLevelConstraintsPass"b1"isUpdatingLayoutEngineHostConstraints"b1"isExpectingToFlushPendingLayoutChangeNotifications"b1"invalidatesIntrinsicContentSizeForSubviewAutoLayoutChanges"b1"systemLayoutFittingSizeNeedsUpdate"b1"systemLayoutFittingSizeNeedsUpdateInWholeSubtree"b1"isCalculatingSystemLayoutFittingSize"b1"suppressEncapsulationConstraints"b1"suppressAutoresizingMaskConstraintsUpdate"b1"isFetchingSizeForTAMIC_NOEngineHost"b1"internallyHiddenForReason"b2"stayHiddenAfterBeingInternallyHiddenForReason"b1"skippedPreLayoutWhileInternallyHiddenForReason"b1"skippedLayoutWhileInternallyHiddenForReason"b1"isPendingHiddenForAnimation"b1"hasMaskView"b1"isSettingMaskView"b1"hasVisualAltitude"b1"hasBackdropMaskViews"b1"backdropMaskViewFlags"b5"delaysTouchesForSystemGestures"b1"subclassShouldDelayTouchForSystemGestures"b1"hasMotionEffects"b1"backdropOverlayMode"b2"tintAdjustmentMode"b2"isReferenceView"b1"focusState"b2"hasUserInterfaceIdiom"b1"userInterfaceIdiom"b3"ancestorDefinesTintColor"b1"ancestorDefinesTintAdjustmentMode"b1"ancestorIgnoresInvertColors"b1"needsUpdateProperties"b1"needsTraitCollectionDidChangePropagation"b1"isRootOfTraitCollectionDidChangePropagation"b1"implementsTraitCollectionForChildEnvironment"b1"implementsBaselineOffsetsAtSize"b1"coloredViewBounds"b1"coloredAlignmentRects"b1"preservesSuperviewMargins"b4"insettingLayoutMarginsFromSafeArea"b4"safeAreaInsetsFrozen"b1"viewDelegateContentOverlayInsetsAreClean"b1"hasGeometryObservers"b1"notifyObserversForBaselineChanges"b1"notifySuperviewForBaselineChanges"b1"observingGeometryChangesForSelfCount"b4"isObservingBoundingPathRotationNotificationsForWindow"b1"hasTraitStorageList"b1"cachedTraitCollectionIsValid"b1"hasTraitOverrides"b1"dontUpdateInferredLayoutMargins"b1"areLayoutMarginsDirectional"b1"implementsViewForBaselineLayout"b1"tracksFocusedAncestors"b1"hasLayoutArrangements"b1"isHiddenManagedByLayoutArrangement"b1"hasAddedFocusGuides"b1"hasFocusSpeedBumpEdges"b1"hasFocusableContentMargins"b1"focusInteractionDisabled"b1"shouldReverseLayoutDirection"b1"cannotBeParentTraitEnvironment"b1"needsContentsFormatUpdate"b1"accessibilityIgnoresInvertColors"b1"ignoresLayerTransformForSafeAreaInsets"b1"accessibilityInterfaceStyleIntent"b2"accessibilityResolvedInterfaceStyle"b2"shouldArchiveUIAppearanceTags"b1"wantsDeepColorDrawing"b1"preferredContentsFormat"b3"sceneDraggingBehaviorOnPan"b2"tagEnabled"b1"chargeSet"b1"ignoreBackdropViewsWhenHiding"b1"hasInteractionsArray"b1"hasHitTestDirectionalInsets"b1"hasLayoutDebuggingIdentifier"b1"hasAppIntentsIntelligenceProvider"b1"hasContentSizeNotificationToken"b1"hasPresentationControllerToNotifyOnLayoutSubviews"b1"hasWritingToolsCoordinator"b1"semanticContentAttribute"b3"hasDynamicBackgroundColor"b1"forceEffectiveThemeDidChange"b1"allowsHighContrastForBackgroundColor"b1"hasPendingTraitStorageConstraints"b1"hasPendingLayoutAfterTraitStorageConstraintsUpdate"b1"hasEverBeenInAWindow"b1"hasFocusGroupIdentifier"b2"hasFocusGroupPriority"b1"hasFocusEffect"b2"conformsToUIFocusItemScrollableContainer"b2"allowsSkippingLayout"b1"isResolvingTraitCollection"b1"needsLayoutAndDisplayOnTintColorChanges"b1"subviewNeedsAnimationRestorationMessage"b1"isHostingTrackingForAnimationRestoration"b1"implementsFocusItemsInRect"b1"isPrivateSubview"b1"wasPrivateSubview"b1"shouldAdaptToMaterials"b1"hasMultiLayerDelegate"b1"useMinimumSafeArea"b1"useMinimumSafeAreaFrozen"b1"minimumSafeAreaAccessed"b1"minimumSafeAreaIsClassicSafeArea"b1"minimumSafeAreaNeedsUpdate"b1"mt_hasCustomizedCaptureGroup"b1"mt_backgroundMergeBehavior"b2"shouldContinueRemovingFromSuperview"b1"isMaskingIntermediateLayer"b1"hasLayoutRules"b1"maskingConfigurationIsInvalid"b1"needsCornersUpdate"b1"invalidatesCornersForGeometryChange"b1"suppressesBackground"b1"glassBackgroundNeedsUpdate"b1"hasChildrenRequestingSubduing"b1"safeAreaCornerAdaptation"b3"isRenderedHorizontallyFlipped"b1"needsLayoutDuringTransactionCommitting"b1"selfOrDescendantNeedsToBeNotifiedOfVisibilityChange"b1"isInHiddenAncestor"b1}
IVAR +120 0 _unsatisfiableConstraintsLoggingSuspensionCount S
IVAR +128 0 _minimumSafeAreaInsets {UIEdgeInsets="top"d"left"d"bottom"d"right"d}
IVAR +160 0 _clippedSafeAreaCornerInsets (?="cornerInsets"{?="topLeftWidth"C"topLeftHeight"C"bottomLeftWidth"C"bottomLeftHeight"C"bottomRightWidth"C"bottomRightHeight"C"topRightWidth"C"topRightHeight"C}"packedInsets"Q)
IVAR +168 0 _layer @"CALayer"
IVAR +176 0 _viewBackingAux @"_UIViewBackingAux"
IVAR +184 0 _minXVariable @"NSISVariable"
IVAR +192 0 _minYVariable @"NSISVariable"
IVAR +200 0 _boundsWidthVariable @"NSISVariable"
IVAR +208 0 _boundsHeightVariable @"NSISVariable"
IVAR +216 0 _tintAdjustmentDimmingCount S
IVAR +218 0 _layoutSubviewsCount S
IVAR +220 0 _imminentLayoutSubviewsCount S
IVAR +222 0 _countOfFocusedAncestorTrackingViewsInSubtree S
IVAR +224 0 _layoutMarginsGuide @"UILayoutGuide"
IVAR +232 0 _typedStorage @"_UITypedStorage"
IVAR +240 0 _layoutEngine @"NSISEngine"
IVAR +248 0 _stashedLayoutVariableObservations @"NSMapTable"
IVAR +256 0 _internalConstraints @"NSMutableArray"
IVAR +264 0 _safeAreaLayoutGuide @"UILayoutGuide"
IVAR +272 0 _keyboardLayoutGuide @"UIKeyboardLayoutGuide"
IVAR +280 0 _readableContentGuide @"UILayoutGuide"
IVAR +288 0 __lastNotifiedTraitCollection @"UITraitCollection"
IVAR +296 0 __autoresizingMaskForPreviousAutoresizingLayoutConstraints Q
IVAR +304 0 __alignmentRectOriginCache @"_UIViewLayoutEngineRelativeAlignmentRectOriginCache"
IVAR +312 0 _rawLayoutMargins {UIEdgeInsets="top"d"left"d"bottom"d"right"d}
IVAR +344 0 _inferredLayoutMargins {UIEdgeInsets="top"d"left"d"bottom"d"right"d}
IVAR +376 0 _safeAreaInsets {UIEdgeInsets="top"d"left"d"bottom"d"right"d}
CMETHOD initialize v16@0:8
CMETHOD flush v16@0:8
CMETHOD _addCompletion: B24@0:8@?16
CMETHOD _animateWithDuration:delay:options:animations:start:completion: v64@0:8d16d24Q32@?40@?48@?56
CMETHOD _modifyAnimationsWithPreferredFrameRateRange:reason:animations: v44@0:8{CAFrameRateRange=fff}16@28@?36
CMETHOD _trackVelocity: v24@0:8@?16
CMETHOD appearanceMatchingProperties:whenContainedInInstancesOfClasses: @32@0:8@16@24
CMETHOD setAnimationRepeatAutoreverses: v20@0:8B16
CMETHOD _isInRetargetableAnimationBlock B16@0:8
CMETHOD _performWithState:trackingIdentifier:duration:delay:animations: v56@0:8@16@24d32d40@?48
CMETHOD _shouldTrackActionWithAnimator: B24@0:8@16
CMETHOD _supportsInvalidatingFocusCache B16@0:8
CMETHOD animateWithDuration:animations: v32@0:8d16@?24
CMETHOD appearanceForTraitCollection:whenContainedInInstancesOfClasses: @32@0:8@16@24
CMETHOD enableAnimation v16@0:8
CMETHOD setAnimationTransition:forView: v32@0:8q16@24
CMETHOD __swift_animateByRetargetingAnimations:completion: v32@0:8@?16@?24
CMETHOD __swift_animateUsingSpringBehavior:tracking:animations:completion: v44@0:8@16B24@?28@?36
CMETHOD __swift_animateUsingSpringInteractive:animations:completion: v36@0:8B16@?20@?28
CMETHOD __swift_animateUsingSpringWithDampingRatio:response:interactive:initialDampingRatio:initialResponse:dampingRatioSmoothing:responseSmoothing:targetSmoothing:projectionDeceleration:retargetImpulse:animations:completion: v108@0:8d16d24B32@36@44d52d60d68d76d84@?92@?100
CMETHOD __swift_animateUsingSpringWithTension:friction:interactive:animations:completion: v52@0:8d16d24B32@?36@?44
CMETHOD __swift_animateWithFrictionBounceAnimations:completion: v32@0:8@?16@?24
CMETHOD __swift_createTransformerWithInputAnimatableProperties:modelValueSetter:presentationValueSetter: v40@0:8@16@?24@?32
CMETHOD __swift_createTransformerWithInputAnimatableProperties:presentationValueChangedCallback: v32@0:8@16@?24
CMETHOD __swift_createUnsafeTransformerWithInputAnimatableProperties:modelValueSetter:presentationValueSetter: v40@0:8@16@?24@?32
CMETHOD __swift_performWithStartingVelocity:actionsWithAnimation: v32@0:8d16@?24
CMETHOD __swift_performWithoutRetargetingAnimations: v24@0:8@?16
CMETHOD __swift_trackVelocity: v24@0:8@?16
CMETHOD _addCompletionWithPosition: B24@0:8@?16
CMETHOD _addHierarchyTrackingVisitor: v24@0:8@16
CMETHOD _addOrPerformCompletion: v24@0:8@?16
CMETHOD _addOrPerformCompletionWithPosition: v24@0:8@?16
CMETHOD _allowsUnsupportedMacIdiomBehavior B16@0:8
CMETHOD _alongsideAnimations @?16@0:8
CMETHOD _animateByRetargetingAnimations:completion: v32@0:8@?16@?24
CMETHOD _animateInProcessAlongsideTransition: v24@0:8@?16
CMETHOD _animateInProcessKeyframesAlongsideTransitionWithOptions:animations: v32@0:8Q16@?24
CMETHOD _animateKeyframeWithID:relativeStartTime:relativeDuration:animations: v48@0:8@16d24d32@?40
CMETHOD _animateSystemChanges: v24@0:8@?16
CMETHOD _animateUsingDefaultDampedSpringWithDelay:initialSpringVelocity:options:animations:completion: v56@0:8d16d24Q32@?40@?48
CMETHOD _animateUsingDefaultTimingWithOptions:animations:completion: v40@0:8Q16@?24@?32
CMETHOD _animateUsingSpringBehavior:tracking:animations:completion: v44@0:8@16B24@?28@?36
CMETHOD _animateUsingSpringInteractive:animations:completion: v36@0:8B16@?20@?28
CMETHOD _animateUsingSpringWithDampingRatio:response:tracking:dampingRatioSmoothing:responseSmoothing:targetSmoothing:projectionDeceleration:animations:completion: v84@0:8d16d24B32d36d44d52d60@?68@?76
CMETHOD _animateUsingSpringWithDampingRatio:response:tracking:dampingRatioSmoothing:responseSmoothing:targetSmoothing:projectionDeceleration:retargetImpulse:animations:completion: v92@0:8d16d24B32d36d44d52d60d68@?76@?84
CMETHOD _animateUsingSpringWithDampingRatio:response:tracking:initialDampingRatio:initialResponse:dampingRatioSmoothing:responseSmoothing:targetSmoothing:projectionDeceleration:animations:completion: v100@0:8d16d24B32d36d44d52d60d68d76@?84@?92
CMETHOD _animateUsingSpringWithDuration:delay:options:mass:stiffness:damping:initialVelocity:animations:completion: v88@0:8d16d24Q32d40d48d56d64@?72@?80
CMETHOD _animateUsingSpringWithTension:friction:interactive:animations:completion: v52@0:8d16d24B32@?36@?44
CMETHOD _animateWithAnimationSettings:animations:completion: v40@0:8@16@?24@?32
CMETHOD _animateWithAttributes:animations:completion: v40@0:8@16@?24@?32
CMETHOD _animateWithDuration:delay:options:factory:animations:completion: v64@0:8d16d24Q32@40@?48@?56
CMETHOD _animateWithDuration:delay:options:factory:animations:start:completion: v72@0:8d16d24Q32@40@?48@?56@?64
CMETHOD _animateWithFilter:filterView:filterValue:duration:delay:options:completion: v68@0:8i16@20d28d36d44Q52@?60
CMETHOD _animateWithFrictionBounceAnimations:completion: v32@0:8@?16@?24
CMETHOD _animateWithSwiftUISpringExtraBounce:animations: v32@0:8d16@?24
CMETHOD _animateWithSwiftUISpringInteractive:animations: v28@0:8B16@?20
CMETHOD _animateWithSwiftUISpringInteractive:animations:completion: v36@0:8B16@?20@?28
CMETHOD _appearanceWhenContainedIn: @24@0:8@16
CMETHOD _autoApplyMonochromaticTreatment B16@0:8
CMETHOD _beginSuspendingMotionEffectsForReason: v24@0:8@16
CMETHOD _completeAnimationWithUUID:duration:curve:reverse: v44@0:8@16d24q32B40
CMETHOD _conditionallyModifyAnimations:withPreferredFrameRateRange:updateReason:animations: v44@0:8B16{CAFrameRateRange=fff}20I32@?36
CMETHOD _conditionallyPerformWithoutAnimation:layout: v28@0:8B16@?20
CMETHOD _createTransformerWithInputAnimatableProperties:modelValueSetter:presentationValueSetter: v40@0:8@16@?24@?32
CMETHOD _createTransformerWithInputAnimatableProperties:presentationValueChangedCallback: v32@0:8@16@?24
CMETHOD _createUnsafeTransformerWithInputAnimatableProperties:modelValueSetter:presentationValueSetter: v40@0:8@16@?24@?32
CMETHOD _currentAnimationAttributes @16@0:8
CMETHOD _currentAnimationCurve q16@0:8
CMETHOD _currentAnimationDuration d16@0:8
CMETHOD _currentAnimationSettings @16@0:8
CMETHOD _currentViewAnimationState @16@0:8
CMETHOD _defaultActionForLayer:forKey: @32@0:8@16@24
CMETHOD _defaultInteractionTintColorForIdiom: @24@0:8q16
CMETHOD _defaultUIViewActionForLayer:forKey: @32@0:8@16@24
CMETHOD _defaultUIViewAnimationForLayer:forKey: @32@0:8@16@24
CMETHOD _degreesToRotateFromInterfaceOrientation:toInterfaceOrientation: i32@0:8q16q24
CMETHOD _descriptionWithoutTextRedactionForObject: @24@0:8@16
CMETHOD _disableAnimationTracking: v24@0:8@16
CMETHOD _disableAnimationTracking:clearTrackedAnimations: v28@0:8@16B24
CMETHOD _disabledColorForTintColor: @24@0:8@16
CMETHOD _durationForRotationFromInterfaceOrientation:toInterfaceOrientation: d32@0:8q16q24
CMETHOD _durationForRotationFromInterfaceOrientation:toInterfaceOrientation:withBaseDuration: d40@0:8q16q24d32
CMETHOD _enableAnimationTracking @16@0:8
CMETHOD _enableAnimationTracking: @20@0:8B16
CMETHOD _enableLegacyRTL B16@0:8
CMETHOD _enableRTL B16@0:8
CMETHOD _enableToolsDebugAlignmentRects: v20@0:8B16
CMETHOD _enableToolsDebugColorViewBounds: v20@0:8B16
CMETHOD _endSuspendingMotionEffectsForReason: v24@0:8@16
CMETHOD _finalizeStoppedAnimationWithUUID:reverseAnimation: v28@0:8@16B24
CMETHOD _finalizeStoppedAnimationWithUUID:reverseAnimation:state:performCompletionsImmediately: v40@0:8@16B24@28B36
CMETHOD _finalizeStoppedAnimationWithUUID:updatingModelValues:reverseAnimation:state:performCompletionsImmediately: v44@0:8@16B24B28@32B40
CMETHOD _finishAnimationTracking v16@0:8
CMETHOD _hasInProcessProgressAnimator B16@0:8
CMETHOD _hostLayoutEngineOnlyTAMIC_YES B16@0:8
CMETHOD _inheritAnimationParameters v16@0:8
CMETHOD _initializeForIdiom: v24@0:8q16
CMETHOD _isAnimationTracking B16@0:8
CMETHOD _isInAnimationBlock B16@0:8
CMETHOD _isInAnimationBlockWithAnimationsEnabled B16@0:8
CMETHOD _isInKeyframeAnimationBlockWithAnimationsEnabled B16@0:8
CMETHOD _isInSystemAnimationBlockWithAnimationsEnabled B16@0:8
CMETHOD _isOnFluidParallaxDenyList B16@0:8
CMETHOD _legacyRTLPreferenceEnabled B16@0:8
CMETHOD _makeHybridPropertyAnimatorWithDuration:progressValue:progressValueReversed:progressValueUpdateReason:springAnimationBehavior: @48@0:8d16@24B32I36@40
CMETHOD _modifyAnimationsByDecomposingGeometricTypes:animations: v28@0:8B16@?20
CMETHOD _modifyAnimationsBySuppressingVelocityForVFD:animations: v28@0:8B16@?20
CMETHOD _modifyAnimationsWithPreferredFrameRateRange:updateReason:animations: v40@0:8{CAFrameRateRange=fff}16I28@?32
CMETHOD _motionEffectsEnabled B16@0:8
CMETHOD _motionEffectsSupported B16@0:8
CMETHOD _performForcedAppearanceModifications: v24@0:8@?16
CMETHOD _performGlassGroupUpdateOnExistingLayer: v24@0:8@?16
CMETHOD _performSystemAppearanceModifications: v24@0:8@?16
CMETHOD _performWithAnimation: v24@0:8@?16
CMETHOD _performWithAnimationTracking: @24@0:8@?16
CMETHOD _performWithDurationOverride:animations: v32@0:8d16@?24
CMETHOD _performWithInProcessProgressAnimating:block: v32@0:8@16@?24
CMETHOD _performWithStartingVelocity:actionsWithAnimation: v32@0:8d16@?24
CMETHOD _performWithoutAnimation: v24@0:8@?16
CMETHOD _performWithoutRetargetingAnimations: v24@0:8@?16
CMETHOD _preventsAppearanceProxyCustomization B16@0:8
CMETHOD _recenterMotionEffects v16@0:8
CMETHOD _registerClassForIdiomInitializationIfNeccessary v16@0:8
CMETHOD _removeHierarchyTrackingVisitor: v24@0:8@16
CMETHOD _resetHostLayoutEngineOnlyTAMIC_YES v16@0:8
CMETHOD _setAllowsUnsupportedMacIdiomBehavior: v20@0:8B16
CMETHOD _setAlongsideAnimations: v24@0:8@?16
CMETHOD _setAlongsideAnimations:toRunByEndOfBlock:animated: v36@0:8@?16@?24B32
CMETHOD _setAnimatedPropertiesEnabled: v20@0:8B16
CMETHOD _setAnimationAttributes: v24@0:8@16
CMETHOD _setAnimationAttributes:skipDelegateAssignment: v28@0:8@16B24
CMETHOD _setHostLayoutEngineOnlyTAMIC_YES v16@0:8
CMETHOD _setShouldEnableUIKitParallaxEffects: v20@0:8B16
CMETHOD _setupAnimationWithDuration:delay:view:options:factory:animations:start:animationStateGenerator:completion: v88@0:8d16d24@32Q40@48@?56@?64@?72@?80
CMETHOD _shouldRedactTextInDescription B16@0:8
CMETHOD _shouldTrackAnimationsWithAnimator B16@0:8
CMETHOD _startAnimationTracking @16@0:8
CMETHOD _stopAnimationWithUUID: v24@0:8@16
CMETHOD _stopAnimationWithUUID:updatingModelValues: v28@0:8@16B24
CMETHOD _testIfFirstView:secondView:areDescendantsOfView:results: v48@0:8@16@24@32[2B]40
CMETHOD _toolsDebugAlignmentRects B16@0:8
CMETHOD _toolsDebugColorViewBounds B16@0:8
CMETHOD _toolsDebugShouldDetectClippedViews B16@0:8
CMETHOD _transitionBackingOutermostLayerWithView:duration:options:animations:completion: v56@0:8@16d24Q32@?40@?48
CMETHOD _transitionWithView:duration:options:transitionOptions:completion: v56@0:8@16d24Q32@40@?48
CMETHOD _updateModelValues:forAnimationWithUUID:useInitialValues:animatable:stateBlock:animationBlock: v52@0:8B16@20B28B32@?36@?44
CMETHOD _updateModelValuesForAnimationWithUUID:useInitialValues:animatable:stateBlock:animationBlock: v48@0:8@16B24B28@?32@?40
CMETHOD _updateOrientationForMotionEngine: v24@0:8q16
CMETHOD _viewWithLayoutConstraints @16@0:8
CMETHOD _wantsDeepColorByDefault B16@0:8
CMETHOD addKeyframeWithRelativeStartTime:relativeDuration:animations: v40@0:8d16d24@?32
CMETHOD animateBridgedWithContext:animations:completion: v40@0:8@16@?24@?32
CMETHOD animateKeyframesWithDuration:delay:options:animations:completion: v56@0:8d16d24Q32@?40@?48
CMETHOD animateWithDuration:animations:completion: v40@0:8d16@?24@?32
CMETHOD animateWithDuration:delay:options:animations:completion: v56@0:8d16d24Q32@?40@?48
CMETHOD animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion: v72@0:8d16d24d32d40Q48@?56@?64
CMETHOD animateWithSpringDuration:bounce:initialSpringVelocity:delay:options:animations:completion: v72@0:8d16d24d32d40Q48@?56@?64
CMETHOD appearance @16@0:8
CMETHOD appearanceForTraitCollection: @24@0:8@16
CMETHOD appearanceForTraitCollection:whenContainedIn: @32@0:8@16#24
CMETHOD appearanceWhenContainedIn: @24@0:8#16
CMETHOD appearanceWhenContainedInInstancesOfClasses: @24@0:8@16
CMETHOD areAnimationsEnabled B16@0:8
CMETHOD beginAnimations: v24@0:8@16
CMETHOD beginAnimations:context: v32@0:8@16^v24
CMETHOD commitAnimations v16@0:8
CMETHOD conditionallyAnimate:withAnimation:layout:completion: v44@0:8B16@?20@?28@?36
CMETHOD disableAnimation v16@0:8
CMETHOD endAnimations v16@0:8
CMETHOD inheritedAnimationDuration d16@0:8
CMETHOD layerClass #16@0:8
CMETHOD modifyAnimationsWithRepeatCount:autoreverses:animations: v36@0:8d16B24@?28
CMETHOD performSystemAnimation:onViews:options:animations:completion: v56@0:8Q16@24Q32@?40@?48
CMETHOD performWithoutAnimation: v24@0:8@?16
CMETHOD removePropertyAnimatorAnimationsInView: v24@0:8@16
CMETHOD requiresConstraintBasedLayout B16@0:8
CMETHOD setAnimationAutoreverses: v20@0:8B16
CMETHOD setAnimationBeginsFromCurrentState: v20@0:8B16
CMETHOD setAnimationCurve: v24@0:8q16
CMETHOD setAnimationDelay: v24@0:8d16
CMETHOD setAnimationDelegate: v24@0:8@16
CMETHOD setAnimationDidStopSelector: v24@0:8:16
CMETHOD setAnimationDuration: v24@0:8d16
CMETHOD setAnimationFrameInterval: v24@0:8d16
CMETHOD setAnimationFromCurrentState: v20@0:8B16
CMETHOD setAnimationPosition: v32@0:8{CGPoint=dd}16
CMETHOD setAnimationPreventsAdditive: v20@0:8B16
CMETHOD setAnimationRepeatCount: v20@0:8f16
CMETHOD setAnimationStartDate: v24@0:8@16
CMETHOD setAnimationStartTime: v24@0:8d16
CMETHOD setAnimationTransition:forView:cache: v36@0:8q16@24B32
CMETHOD setAnimationWillStartSelector: v24@0:8:16
CMETHOD setAnimationsEnabled: v20@0:8B16
CMETHOD sticker_modifyAnimationsWithPreferredFrameRateRange:updateReason:animations: v40@0:8{CAFrameRateRange=fff}16I28@?32
CMETHOD throttledFlush v16@0:8
CMETHOD trackedAnimationsCount: Q24@0:8@16
CMETHOD transitionFromView:toView:duration:options:completion: v56@0:8@16@24d32Q40@?48
CMETHOD transitionWithView:duration:options:animations:completion: v56@0:8@16d24Q32@?40@?48
CMETHOD userInterfaceLayoutDirectionForSemanticContentAttribute: q24@0:8q16
CMETHOD userInterfaceLayoutDirectionForSemanticContentAttribute:relativeToLayoutDirection: q32@0:8q16q24
METHOD _printFormatterClass #16@0:8
METHOD viewPrintFormatter @16@0:8
METHOD drawRect:forViewPrintFormatter: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _printFormatterClass #16@0:8
METHOD viewPrintFormatter @16@0:8
METHOD drawRect:forViewPrintFormatter: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _objc_initiateDealloc v16@0:8
METHOD dealloc v16@0:8
METHOD debugDescription @16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD _setIdentifier: v24@0:8@16
METHOD _identifier @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD isHidden B16@0:8
METHOD setEnabled: v20@0:8B16
METHOD setHidden: v20@0:8B16
METHOD isEnabled B16@0:8
METHOD position {CGPoint=dd}16@0:8
METHOD setPosition: v32@0:8{CGPoint=dd}16
METHOD setValue:forKey: v32@0:8@16@24
METHOD size {CGSize=dd}16@0:8
METHOD snapshot @16@0:8
METHOD transform {CGAffineTransform=dddddd}16@0:8
METHOD alpha d16@0:8
METHOD bounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD center {CGPoint=dd}16@0:8
METHOD extent {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD frame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD isOpaque B16@0:8
METHOD origin {CGPoint=dd}16@0:8
METHOD setBounds: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setCenter: v32@0:8{CGPoint=dd}16
METHOD setSize: v32@0:8{CGSize=dd}16
METHOD setTransform: v64@0:8{CGAffineTransform=dddddd}16
METHOD interactions @16@0:8
METHOD setInteractions: v24@0:8@16
METHOD contentMode q16@0:8
METHOD tag q16@0:8
METHOD constraints @16@0:8
METHOD setOpaque: v20@0:8B16
METHOD backgroundColor @16@0:8
METHOD addSubview: v24@0:8@16
METHOD contentScaleFactor d16@0:8
METHOD convertRect:fromView: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertSize:toView: {CGSize=dd}40@0:8{CGSize=dd}16@32
METHOD initWithFrame: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD initWithSize: @32@0:8{CGSize=dd}16
METHOD intrinsicContentSize {CGSize=dd}16@0:8
METHOD isFirstResponder B16@0:8
METHOD needsDisplay B16@0:8
METHOD removeFromSuperview v16@0:8
METHOD setBackgroundColor: v24@0:8@16
METHOD setFrame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setNeedsDisplayInRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setNeedsLayout v16@0:8
METHOD superview @16@0:8
METHOD _alwaysHandleScrollerMouseEvent B16@0:8
METHOD _ancestorHasInvertFilterApplied B16@0:8
METHOD _backdropGroups @16@0:8
METHOD _canHaveWritingToolsCoordinator B16@0:8
METHOD _centerExpressionInContainer:vertical:contentInsetScale:engine: @44@0:8@16B24d28@36
METHOD _constraintsValidityDescription @16@0:8
METHOD _findAutolayoutHeightConstraint d16@0:8
METHOD _frameInCoordinateSpace:window: {CGRect={CGPoint=dd}{CGSize=dd}}32@0:8@16@24
METHOD _getGhostPortal @16@0:8
METHOD _informContainerThatSubviewsNeedUpdateConstraintsNeedingLayout: v20@0:8B16
METHOD _initWithLayer: @24@0:8@16
METHOD _is_needsLayout B16@0:8
METHOD _kb_description @16@0:8
METHOD _largeContentViewerItemAtPoint: @32@0:8{CGPoint=dd}16
METHOD _ola_isCandidateForMultilineTextWidthDisambiguationWhenArranged B16@0:8
METHOD _performPreLayoutUpdateOfLayer: v24@0:8@16
METHOD _previewingSegueTemplateStorage @16@0:8
METHOD _setInvalidatesIntrinsicContentSizeForSubviewAutoLayoutChanges: v20@0:8B16
METHOD _setOverrideUserInterfaceStyle: v24@0:8q16
METHOD _setSceneDraggingBehaviorOnPan: v24@0:8q16
METHOD _uimorphingView_getInitialAlpha d16@0:8
METHOD _vendAssertionForOverrideAlpha: @24@0:8d16
METHOD _visualAltitude d16@0:8
METHOD addLayoutGuide: v24@0:8@16
METHOD compositingMode q16@0:8
METHOD mt_visualEffect @16@0:8
METHOD nsli_descriptionIncludesPointer B16@0:8
METHOD preservesSuperviewLayoutMargins B16@0:8
METHOD resizableSnapshotViewFromRect:afterScreenUpdates:withCapInsets: @84@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16B48{UIEdgeInsets=dddd}52
METHOD setAnchorPoint: v32@0:8{CGPoint=dd}16
METHOD setNeedsDisplay v16@0:8
METHOD setTag: v24@0:8q16
METHOD snapshotViewAfterScreenUpdates: @20@0:8B16
METHOD traitCollection @16@0:8
METHOD _StatusBar_isInVisibleHierarchy B16@0:8
METHOD __swift_setVelocity:key:target: v36@0:8@16@24B32
METHOD _addBoundingPathChangeObserver: v24@0:8@16
METHOD _alignmentFrame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _ancestorCollectionReusableView @16@0:8
METHOD _canDrawContent B16@0:8
METHOD _clippingRectInCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _delaysTouchesForSystemGestures B16@0:8
METHOD _diagnoseFocusabilityForReport: v24@0:8@16
METHOD _enclosingScrollerIncludingSelf @16@0:8
METHOD _firstResponder @16@0:8
METHOD _imageFromRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _isView B16@0:8
METHOD _noteTraitsDidChangeRecursively v16@0:8
METHOD _outermostLayer @16@0:8
METHOD _screen @16@0:8
METHOD _setBackground: v24@0:8@16
METHOD _setCropInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setDisableLayoutFlushingCount: v24@0:8q16
METHOD _setIsAncestorOfFirstResponder: v20@0:8B16
METHOD _setMaximumContentSizeCategory: v24@0:8@16
METHOD _setMinimumContentSizeCategory: v24@0:8@16
METHOD _setNeedsNonDeferredFocusUpdate v16@0:8
METHOD _setProofreadingDecorationView: v24@0:8@16
METHOD _speedBumpEdges Q16@0:8
METHOD _uili_removeLayoutVariableObservationsOnlyToSupportTAMICChange: v20@0:8B16
METHOD _window @16@0:8
METHOD addConstraints: v24@0:8@16
METHOD addInteraction: v24@0:8@16
METHOD convertPoint:toCoordinateSpace: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD coordinateSpace @16@0:8
METHOD didMoveToWindow v16@0:8
METHOD findAndReplace: v24@0:8@16
METHOD hitRect {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD insetsLayoutMarginsFromSafeArea B16@0:8
METHOD isAccessibilityElementByDefault B16@0:8
METHOD nsis_shouldIntegralizeVariable: B24@0:8@16
METHOD recursivelyForceDisplayIfNeeded v16@0:8
METHOD setContentMode: v24@0:8q16
METHOD setFocusEffect: v24@0:8@16
METHOD setFrameOrigin: v32@0:8{CGPoint=dd}16
METHOD setTransform3D: v144@0:8{CATransform3D=dddddddddddddddd}16
METHOD useBlockyMagnificationInClassic B16@0:8
METHOD _UIViewDebuggingIsViewClipping B16@0:8
METHOD __isKindOfUIView B16@0:8
METHOD __isLandmarkView B16@0:8
METHOD __resolveBackgroundWithDependencyTracking v16@0:8
METHOD __swift_animatePropertyWithKey:currentValue:targetValue:newValueCallback: v48@0:8@16d24d32@?40
METHOD __swift_projectedTargetForKey:decelerationFactor: @32@0:8@16d24
METHOD __swift_removeAllRetargetableAnimations: v20@0:8B16
METHOD __swift_removeAllRetargetableAnimationsIfDetatchedFromContext v16@0:8
METHOD __swift_replaceInProcessAnimationForKey:behavior:interactive: v36@0:8@16@24B32
METHOD __swift_setPresentationValue:velocity:preferredFrameRateRangeMaximum:immediate:key: v52@0:8@16@24q32B40@44
METHOD __swift_stopSettingPresentationValueForKey: v24@0:8@16
METHOD __swift_velocityForKey:target: @28@0:8@16B24
METHOD __vis_layoutSublayersOfLayer: v24@0:8@16
METHOD _acceptsInauthenticTouches B16@0:8
METHOD _accessibilityAddItemsToDragSessionAtPoint3D: B40@0:8{CAPoint3D=ddd}16
METHOD _accessibilityAddItemsToDragSessionAtPoint: B32@0:8{CGPoint=dd}16
METHOD _accessibilityBeginDragAtPoint3D:endpoint:completion: v56@0:8{CAPoint3D=ddd}16@40@?48
METHOD _accessibilityBeginDragAtPoint:endpoint:completion: v48@0:8{CGPoint=dd}16@32@?40
METHOD _accessibilityCanAddItemsToDragSession B16@0:8
METHOD _accessibilityCanDrag B16@0:8
METHOD _accessibilityCanDrop B16@0:8
METHOD _accessibilityDragInteractionsForAddingItems @16@0:8
METHOD _accessibilityHigherContrastTintColorForColor: @24@0:8@16
METHOD _accessibilityInterfaceStyleIntent Q16@0:8
METHOD _accessibilityResolvedInterfaceStyle Q16@0:8
METHOD _accessibilitySetInterfaceStyleIntent: v24@0:8Q16
METHOD _accessibilitySetResolvedInterfaceStyle: v24@0:8Q16
METHOD _accessoryViewFrame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _accumulateViewConstraintsIntoArray: v24@0:8@16
METHOD _actingParentGestureRecognizerContainer @16@0:8
METHOD _actingParentViewForGestureRecognizers @16@0:8
METHOD _activeSizeToFitLayoutEngine @16@0:8
METHOD _activityItemsConfigurationAtLocation: @32@0:8{CGPoint=dd}16
METHOD _addBoundsMatchingConstraintsForView: v24@0:8@16
METHOD _addCGFloatLayoutRule: v24@0:8#16
METHOD _addCenterExpressionToExpression:isVertical: v28@0:8@16B24
METHOD _addConstraintPendingAnimatedChanges: v24@0:8@16
METHOD _addGlassGroupView:material: B32@0:8@16@24
METHOD _addLayoutRuleRegistration: v24@0:8@16
METHOD _addMotionEffect: v24@0:8@16
METHOD _addNSIntegerLayoutRule: v24@0:8#16
METHOD _addObjectLayoutRule: v24@0:8#16
METHOD _addSubview:positioned:relativeTo: v40@0:8@16q24@32
METHOD _addTrackedElementFor:with: v32@0:8@16@24
METHOD _alignmentBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _alignmentDebuggingOverlayCreateIfNecessary: @20@0:8B16
METHOD _alignmentRectForBounds: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _alignmentRectInsetsHaveChangedForChildImageView: v24@0:8@16
METHOD _alignmentRectOriginCache @16@0:8
METHOD _allLayoutEngines @16@0:8
METHOD _allSublayers @16@0:8
METHOD _allSubviews @16@0:8
METHOD _allowAssistanceInSubtree B16@0:8
METHOD _allowsArchivingAsSubview B16@0:8
METHOD _allowsFocusToLeaveViaHeading: B24@0:8Q16
METHOD _allowsHighContrastForBackgroundColor B16@0:8
METHOD _allowsLinkPreviewInteractionInViewServices B16@0:8
METHOD _allowsMonochromaticTreatment B16@0:8
METHOD _ancestorWillUpdateFocusInContext:withAnimationCoordinator: v32@0:8@16@24
METHOD _animatePropertyWithKey:currentValue:targetValue:newValueCallback: v48@0:8@16@24@32@?40
METHOD _appEntityIdentifier @16@0:8
METHOD _appIntentIdentifier @16@0:8
METHOD _appIntentsAnnotationsDebugDescription @16@0:8
METHOD _appearanceContainer @16@0:8
METHOD _appearanceGuideClass #16@0:8
METHOD _appearanceIsInvalid B16@0:8
METHOD _appearanceTraitCollection @16@0:8
METHOD _appliedContentSizeCategoryLimitsDescription @16@0:8
METHOD _appliesExclusiveTouchToSubviewTree B16@0:8
METHOD _applyAppearanceInvocations v16@0:8
METHOD _applyEffectiveCornerRadiiToLayer v16@0:8
METHOD _applyISEngineLayoutValuesToBoundsOnly: v20@0:8B16
METHOD _applyKeyPathsAndRelativeValues:forMotionEffect: B32@0:8@16@24
METHOD _applyMaskingConfiguration v16@0:8
METHOD _applyPendingTraitStorageConstraints v16@0:8
METHOD _applyResolvedShape: v24@0:8@16
METHOD _applyShape: v24@0:8@16
METHOD _associatedViewControllerForwardsAppearanceCallbacks:performHierarchyCheck:isRoot: B32@0:8@16B24B28
METHOD _autolayoutSpacingAtEdge:forAttribute:inContainer:isGuide: d40@0:8i16q20@28B36
METHOD _autolayoutSpacingAtEdge:forAttribute:nextToNeighbor:edge:attribute:multiplier: d56@0:8i16q20@28i36q40d48
METHOD _autolayoutTrace @16@0:8
METHOD _autolayoutTraceAtLevel:recursively: @28@0:8q16B24
METHOD _autolayoutTraceRecursively: @20@0:8B16
METHOD _autoresizingConstraints_frameDidChange v16@0:8
METHOD _axesForDerivingIntrinsicContentSizeFromLayoutSize Q16@0:8
METHOD _backdropMaskViewFlags q16@0:8
METHOD _backdropMaskViewForColorTint @16@0:8
METHOD _backdropMaskViewForFilters @16@0:8
METHOD _backdropMaskViewForFlag: @24@0:8q16
METHOD _backdropMaskViewForGrayscaleTint @16@0:8
METHOD _backdropMaskViews @16@0:8
METHOD _background @16@0:8
METHOD _backgroundCGColor ^{CGColor=}16@0:8
METHOD _backgroundColor @16@0:8
METHOD _backgroundMergeBehavior q16@0:8
METHOD _baselineOffsetFromBottom d16@0:8
METHOD _baselineOffsetFromNearestEdgeForLayoutAttribute: d24@0:8q16
METHOD _baselineOffsetsAtSize: {?=dd}32@0:8{CGSize=dd}16
METHOD _basicAnimationWithKeyPath: @24@0:8@16
METHOD _becomeFirstResponderWhenPossible B16@0:8
METHOD _beginDragWithInteractionTouches: B24@0:8@16
METHOD _beginDragWithTouches:orInitialCentroid:accessibilityEndpoint: B56@0:8@16{CAPoint3D=ddd}24@48
METHOD _beginOcclusion: v24@0:8@16
METHOD _beginOcclusion:suppressHDRIfNecessary: v28@0:8@16B24
METHOD _bottomLeadingConcentricLayoutPoint @16@0:8
METHOD _bottomLeftConcentricLayoutPoint @16@0:8
METHOD _bottomRightConcentricLayoutPoint @16@0:8
METHOD _bottomTrailingConcentricLayoutPoint @16@0:8
METHOD _boundingPath @16@0:8
METHOD _boundingPathForSubtree @16@0:8
METHOD _boundsForAlignmentRect: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _boundsForSceneDraggingConstrainedToSafeArea: {CGRect={CGPoint=dd}{CGSize=dd}}20@0:8B16
METHOD _boundsHeightVariable @16@0:8
METHOD _boundsWidthVariable @16@0:8
METHOD _bringAncestorControlledCollectionSubviewToFrontAmongCoplanarPeers v16@0:8
METHOD _cachedTraitCollectionIsValid B16@0:8
METHOD _calculateSubviewAlignmentFrame:superviewAlignmentBounds:forAutoresizingMask:preservingNonzeroSuperviewAlignmentBoundsOriginForCompatibility: v44@0:8^{CGRect={CGPoint=dd}{CGSize=dd}}16^{CGRect={CGPoint=dd}{CGSize=dd}}24Q32B40
METHOD _calculatedIntrinsicHeight d16@0:8
METHOD _calculatedSystemLayoutSizeFittingSize:withHorizontalFittingPriority:verticalFittingPriority:hasIntentionallyCollapsedHeight: {CGSize=dd}48@0:8{CGSize=dd}16f32f36^B40
METHOD _canBeParentTraitEnvironment B16@0:8
METHOD _canBeReusedInPickerView B16@0:8
METHOD _canBecomeFirstResponderWhenPossible B16@0:8
METHOD _canBecomeLayoutEngineDelegate B16@0:8
METHOD _canHandleStatusBarTouchAtLocation: B32@0:8{CGPoint=dd}16
METHOD _canHostViewControllerContentScrollView B16@0:8
METHOD _canPerformDefaultImplementationForStandardEditAction: B24@0:8:16
METHOD _canSkipTraitsAndOverlayUpdatesForViewControllerToNotifyOnLayoutResetState: B20@0:8B16
METHOD _childFocusViews @16@0:8
METHOD _childGestureRecognizerContainers @16@0:8
METHOD _childTraitTransformDidChange v16@0:8
METHOD _clearAnimationFilters v16@0:8
METHOD _clearBecomeFirstResponderWhenCapable v16@0:8
METHOD _clearConstraintsBrokenWhileUnsatisfiableConstraintsLoggingSuspended v16@0:8
METHOD _clearLayoutVariableObservationsOnlyToSupportTAMICChange: v20@0:8B16
METHOD _clearSafeAreaInsets v16@0:8
METHOD _clipCorners Q16@0:8
METHOD _clipCornersOfView: Q24@0:8@16
METHOD _clippedSafeAreaCornerInsets (?={?=CCCCCCCC}Q)16@0:8
METHOD _clippedSafeAreaCornerInsetsDidChangeFromOldCornerInsets: v24@0:8(?={?=CCCCCCCC}Q)16
METHOD _clippedSafeAreaCornerInsetsInSuperview: (?={?=CCCCCCCC}Q)24@0:8@16
METHOD _clippedViewHierarchyDescription @16@0:8
METHOD _clipsGlyphPathFrame:shouldContinueSuperviewTraversal: B56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16^B48
METHOD _collectExistingTraitCollectionsForTraitTracking: v24@0:8@?16
METHOD _collectKeyViews: v24@0:8@16
METHOD _collectKeyViews:visibilityTest:passingTest: v40@0:8@16@?24@?32
METHOD _collectKeyViews:visibilityTest:passingTest:subviewsTest: v48@0:8@16@?24@?32@?40
METHOD _colorViewBoundsOverlayCreateIfNecessary: @20@0:8B16
METHOD _compareGestureRecognizerContainer: q24@0:8@16
METHOD _compatibleBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _concentricEdgeInsetsForEdge:bounds:minimumEdgeInsets: {UIEdgeInsets=dddd}88@0:8Q16{CGRect={CGPoint=dd}{CGSize=dd}}24{UIEdgeInsets=dddd}56
METHOD _concentricPaddingForSubview:inCorner: {CGSize=dd}32@0:8@16Q24
METHOD _conciseParentDescription @16@0:8
METHOD _concreteDefaultLayoutMargins {UIEdgeInsets=dddd}16@0:8
METHOD _configureAutolayoutFlagsNeedingLayout: v20@0:8B16
METHOD _constantsForHorizontalAutoresizingConstraints:: v32@0:8^d16^d24
METHOD _constantsForVerticalAutoresizingConstraints:: v32@0:8^d16^d24
METHOD _constrainViewToSuperview v16@0:8
METHOD _constraintsArray @16@0:8
METHOD _constraintsBrokenWhileUnsatisfiableConstraintsLoggingSuspendedCreateIfNecessary: @20@0:8B16
METHOD _constraintsExceptingSubviewAutoresizingConstraints @16@0:8
METHOD _constraints_subviewWillChangeSuperview: v24@0:8@16
METHOD _containedInAbsoluteResponderChain B16@0:8
METHOD _containerConcentricRadiusForCorner: d24@0:8Q16
METHOD _containerForContentSizeConstraints @16@0:8
METHOD _containerForKeyplaneViews @16@0:8
METHOD _containerViewForLegacyFocusRing @16@0:8
METHOD _containingScrollView @16@0:8
METHOD _contentCompressionResistancePriorities {CGSize=dd}16@0:8
METHOD _contentHeightVariable @16@0:8
METHOD _contentHuggingDefault_isUsuallyFixedHeight B16@0:8
METHOD _contentHuggingDefault_isUsuallyFixedWidth B16@0:8
METHOD _contentHuggingPriorities {CGSize=dd}16@0:8
METHOD _contentMargin d16@0:8
METHOD _contentSizeCategoryLimitsDidChange v16@0:8
METHOD _contentSizeNotificationToken @16@0:8
METHOD _contentWidthVariable @16@0:8
METHOD _contentXOffsetVariable @16@0:8
METHOD _contentYOffsetVariable @16@0:8
METHOD _continuousCornerRadius d16@0:8
METHOD _controlsOwnScaleFactor B16@0:8
METHOD _convertToAutolayoutSizingIfNecessary v16@0:8
METHOD _convertViewPointToSceneSpaceForKeyboard: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _convertVisualAltitude:fromView: d32@0:8d16@24
METHOD _convertVisualAltitude:toView: d32@0:8d16@24
METHOD _cornerCurve @16@0:8
METHOD _cornerProviderInsets {UIEdgeInsets=dddd}16@0:8
METHOD _cornerRadius d16@0:8
METHOD _countOfFocusedAncestorTrackingViewsInSubtree Q16@0:8
METHOD _countOfMotionEffectsInSubtree Q16@0:8
METHOD _createIOSurfaceWithPadding: ^v48@0:8{UIEdgeInsets=dddd}16
METHOD _createJostledViewsIfNecessary v16@0:8
METHOD _cropInsets {UIEdgeInsets=dddd}16@0:8
METHOD _currentScreenScale d16@0:8
METHOD _currentUserInterfaceIdiom q16@0:8
METHOD _debuggableDescriptionForConstraintsAffectingAxis: @24@0:8q16
METHOD _debuggableDescriptionForConstraintsAffectingHorizontalAxis @16@0:8
METHOD _debuggableDescriptionForConstraintsAffectingVerticalAxis @16@0:8
METHOD _decodeLargeContentViewerPropertiesWithCoder: v24@0:8@16
METHOD _decrementHiddenManagedByLayoutArrangementCount v16@0:8
METHOD _defaultAutolayoutSpacing d16@0:8
METHOD _defaultFocusEffect @16@0:8
METHOD _defaultFocusRegionFrame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _defaultLayoutDescription @16@0:8
METHOD _defaultTintAdjustmentMode q16@0:8
METHOD _deferredAnimationForKey: @24@0:8@16
METHOD _deferredAnimationForKey:ignoringKeyFrames: @28@0:8@16B24
METHOD _definesDynamicTintColor B16@0:8
METHOD _definesTintColor B16@0:8
METHOD _descendantWithAmbiguousLayout @16@0:8
METHOD _descriptionForLayoutTrace @16@0:8
METHOD _detectAndHandleClippedView v16@0:8
METHOD _diagnoseFocusInteractionEligibilityForReport: v24@0:8@16
METHOD _didAddDependentConstraint: v24@0:8@16
METHOD _didChangeFromIdiom:onScreen:traverseHierarchy: v36@0:8q16@24B32
METHOD _didChangeKeyplaneWithContext: v24@0:8@16
METHOD _didInvalidateIntrinsicContentSize v16@0:8
METHOD _didMoveFromSuperview: v24@0:8@16
METHOD _didMoveFromWindow:toWindow: v32@0:8@16@24
METHOD _didRemoveDependentConstraint: v24@0:8@16
METHOD _didRemoveSubview: v24@0:8@16
METHOD _didScroll v16@0:8
METHOD _didUpdateFocusInContext: v24@0:8@16
METHOD _dimensionExpressionInContainer:vertical:useContentVariables:engine: @40@0:8@16B24B28@32
METHOD _disableDictationTouchCancellation B16@0:8
METHOD _disableGeometryObserverNotification B16@0:8
METHOD _disableLayoutFlushing v16@0:8
METHOD _disableLayoutFlushingCount q16@0:8
METHOD _disabledColor @16@0:8
METHOD _discardLayoutEngine: v24@0:8@16
METHOD _dontUpdateInferredLayoutMargins B16@0:8
METHOD _draggingSourceDelegate @16@0:8
METHOD _drawRectWithObservationTracking: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _drawsAsBackdropOverlay B16@0:8
METHOD _dummyFittingSizeInfo @16@0:8
METHOD _dumpClippedViewWithScreenshotIfNecessary v16@0:8
METHOD _dynamicDropInteraction @16@0:8
METHOD _dynamicLayoutGuidesMayNeedUpdate v16@0:8
METHOD _dynamicUserInterfaceTraitDidChange v16@0:8
METHOD _edgeExpressionInContainer:vertical:max:contentInsetScale:engine: @48@0:8@16B24B28d32@40
METHOD _edgesPropagatingSafeAreaInsetsToSubviews Q16@0:8
METHOD _effectiveBoundingPathAndBoundingPathView: @24@0:8^@16
METHOD _enableLayerKitPatternDrawing: v20@0:8B16
METHOD _enableLayoutFlushing v16@0:8
METHOD _enableMonochromaticTreatment B16@0:8
METHOD _enclosingInterfaceActionGroupView @16@0:8
METHOD _enclosingInterfaceActionRepresentationView @16@0:8
METHOD _enclosingScrollableScrollerIncludingSelf @16@0:8
METHOD _encodableSubviews @16@0:8
METHOD _encodeBackgroundColorWithCoder: v24@0:8@16
METHOD _encodeFrameWithCoder: v24@0:8@16
METHOD _encodeLargeContentViewerPropertiesWithCoder: v24@0:8@16
METHOD _endOcclusion: v24@0:8@16
METHOD _engineHostConstraints_frameDidChange v16@0:8
METHOD _engineHostingWidthConstraint @16@0:8
METHOD _ensureViewsAreInstalledInRelativeOrder:viewCount:insertionStartIndex: v40@0:8^@16q24q32
METHOD _enumerateDescendentViews: v24@0:8@?16
METHOD _eventReceivingWindow @16@0:8
METHOD _extantFocusItemsInRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _extraInfoForTraitTrace @16@0:8
METHOD _fakeShouldAnimatePropertyWithKey: B24@0:8@16
METHOD _fallbackTraitCollection ^v16@0:8
METHOD _faultInContentOffsetGuide v16@0:8
METHOD _faultInGuidesForConstraint: v24@0:8@16
METHOD _findInteractionIfExists @16@0:8
METHOD _finishTrackingForAnimationRestoration v16@0:8
METHOD _firstAncestorInteractionConformingToProtocol: @24@0:8@16
METHOD _firstBaselineOffsetFromTop d16@0:8
METHOD _firstCommonAncestorToView:givenCommonAncestor: @32@0:8@16@24
METHOD _flexInteractionGestureView @16@0:8
METHOD _flipsHorizontalAxis B16@0:8
METHOD _flushConstraintsPendingAnimatedChanges v16@0:8
METHOD _focusBehavior @16@0:8
METHOD _focusFallbackScroller @16@0:8
METHOD _focusGesturesForFailureRequirements @16@0:8
METHOD _focusGuideBehaviorForFocusMovement: Q24@0:8@16
METHOD _focusItemGuides @16@0:8
METHOD _focusRegionFrameInCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _focusSpeedBumpEdges Q16@0:8
METHOD _focusSystem @16@0:8
METHOD _focusSystemSceneComponent @16@0:8
METHOD _focusTouchSensitivityStyle q16@0:8
METHOD _focusableContentMargins {UIEdgeInsets=dddd}16@0:8
METHOD _focusedSound q16@0:8
METHOD _forceLayoutEngineSolutionInRationalEdges B16@0:8
METHOD _forceNilGlassGroupTraitOverride v16@0:8
METHOD _forwardsSystemLayoutFittingSizeToContentView: B24@0:8@16
METHOD _frameIgnoringLayerTransform {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _frameLayoutItem @16@0:8
METHOD _gatherKeyResponders:indexOfSelf:visibilityTest:passingTest:subviewsTest: v56@0:8@16^Q24@?32@?40@?48
METHOD _generateBackdropMaskImage @16@0:8
METHOD _generateBackdropMaskViewForFlag: @24@0:8q16
METHOD _generateDeferredAnimations: v24@0:8@16
METHOD _geometryChanged:forAncestor: v32@0:8r^{?=Q{CGPoint=dd}{CGPoint=dd}{CGSize=dd}{CGPoint=dd}{CATransform3D=dddddddddddddddd}q@@@@}16@24
METHOD _gestureRecognizerShouldReceiveTouch: B24@0:8@16
METHOD _gestureRecognizers @16@0:8
METHOD _getSourceCenter {CGPoint=dd}16@0:8
METHOD _glassEffect @16@0:8
METHOD _glassGroupTraitDidChangeWithView:previous: v32@0:8@16@24
METHOD _handleDoubleUpdateConstraintsIfNecessary v16@0:8
METHOD _handleLayoutArrangementConstraintsIfNecessary v16@0:8
METHOD _handleLayoutEngineHostingConstraintsIfNecessary v16@0:8
METHOD _handleSizeConstraintsAsAppropriate v16@0:8
METHOD _hasAmbiguousLayout B16@0:8
METHOD _hasAutolayoutHeightConstraint B16@0:8
METHOD _hasBackgroundMaterial B16@0:8
METHOD _hasBaseline B16@0:8
METHOD _hasCornerProvider B16@0:8
METHOD _hasCustomAutolayoutNeighborSpacingForAttribute: B24@0:8^q16
METHOD _hasDefaultImplementationForStandardEditAction: B24@0:8:16
METHOD _hasFontInfoForVerticalBaselineSpacing B16@0:8
METHOD _hasLayoutArrangements B16@0:8
METHOD _hasLayoutEngine B16@0:8
METHOD _hiddenManagedByLayoutArrangementCount q16@0:8
METHOD _hierarchyRepresentation @16@0:8
METHOD _hitTest:withEvent:windowServerHitTestWindow: @48@0:8{CGPoint=dd}16@32@40
METHOD _hitTestWithContext: @24@0:8@16
METHOD _hostsLayoutEngine B16@0:8
METHOD _hostsLayoutEngineAllowsTAMIC_NO B16@0:8
METHOD _idleModeLayoutAttributes @16@0:8
METHOD _ignoreBackdropViewsWhenHiding B16@0:8
METHOD _ignoreRemoveAllAnimations B16@0:8
METHOD _ignoresLayerTransformForSafeAreaInsets B16@0:8
METHOD _imageButtonMargin d16@0:8
METHOD _imageFromRect:gamut: @56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16q48
METHOD _inSecondConstraintsPass B16@0:8
METHOD _incrementHiddenManagedByLayoutArrangementCount v16@0:8
METHOD _inferredLayoutMargins {UIEdgeInsets=dddd}16@0:8
METHOD _inheritedInteractionTintColor @16@0:8
METHOD _inheritedRenderConfig @16@0:8
METHOD _initialValueForKey: @24@0:8@16
METHOD _initialValueForLayer:keyPath:usePresentationValue: @36@0:8@16@24B32
METHOD _initializeHostedLayoutEngine v16@0:8
METHOD _initializeLayoutEngine v16@0:8
METHOD _inscribedRectInBoundingPathByInsettingRect:onEdges:withOptions: {CGRect={CGPoint=dd}{CGSize=dd}}64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16Q48Q56
METHOD _insertPrivateSubview:aboveLayer: v32@0:8@16@24
METHOD _insertPrivateSubview:belowLayer: v32@0:8@16@24
METHOD _intelligenceBaseClass #16@0:8
METHOD _intelligenceCollectContentIn:collector: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _intelligenceCollectElementFor:in:using:transformToRoot: v72@0:8@16{CGRect={CGPoint=dd}{CGSize=dd}}24@56@?64
METHOD _intelligenceCollectRemoteContentIn:remoteContextWrapper: v56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _intelligenceCollectSubelementsIn:using:transformToRoot: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@?56
METHOD _intelligenceVisibleBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _interactionTintColor @16@0:8
METHOD _internalAppIntentsIntelligenceProvider @16@0:8
METHOD _internalConstraints @16@0:8
METHOD _internalFirstBaselineOffsetFromTop d16@0:8
METHOD _internalLastBaselineOffsetFromBottom d16@0:8
METHOD _intersectedSceneCornerRadii {CACornerRadii={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD _intrinsicContentSizeInvalidatedForChildView: v24@0:8@16
METHOD _intrinsicSizeWithinSize: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD _invalidateAppearance v16@0:8
METHOD _invalidateAppearanceForSubviewsOfClass: v24@0:8#16
METHOD _invalidateAppearanceForTraitCollection: v24@0:8@16
METHOD _invalidateBackground v16@0:8
METHOD _invalidateBaselineConstraints v16@0:8
METHOD _invalidateConfiguration v16@0:8
METHOD _invalidateGlassBackground v16@0:8
METHOD _invalidateIntrinsicContentSizeNeedingLayout: v20@0:8B16
METHOD _invalidateLayoutEngineHostConstraints v16@0:8
METHOD _invalidateMaskingConfigurationOnSizeChangeIfNecessary v16@0:8
METHOD _invalidateSubviewCache v16@0:8
METHOD _invalidateSystemLayoutSizeFittingSizeAtEngineDelegateLevel v16@0:8
METHOD _invalidatesIntrinsicContentSizeForSubviewAutoLayoutChanges B16@0:8
METHOD _isAncestorOfFirstResponder B16@0:8
METHOD _isBackgroundSolidColor B16@0:8
METHOD _isBackgroundSuppressed B16@0:8
METHOD _isBoundingPathNonRectangular B16@0:8
METHOD _isChargeEnabled B16@0:8
METHOD _isEligibleForFocusGivenAlpha B16@0:8
METHOD _isEligibleForFocusInteraction B16@0:8
METHOD _isEligibleForFocusOcclusion B16@0:8
METHOD _isFindAction: B24@0:8:16
METHOD _isFloatingLayoutItem B16@0:8
METHOD _isFocusDirectionFlippedHorizontally B16@0:8
METHOD _isFocusInteractionEnabled B16@0:8
METHOD _isFocusedOrAncestorOfFocusedView B16@0:8
METHOD _isHasBaselinePropertyChangeable B16@0:8
METHOD _isHiddenForReuse B16@0:8
METHOD _isInAWindow B16@0:8
METHOD _isInAnimatedLayout B16@0:8
METHOD _isInExclusiveTouchSubviewTree B16@0:8
METHOD _isInLayoutSubviews B16@0:8
METHOD _isInTransitionBlock B16@0:8
METHOD _isInternalDebugView B16@0:8
METHOD _isKnownUISearchBarComponentContainer B16@0:8
METHOD _isLazyFocusItemContainer B16@0:8
METHOD _isManuallyResizedBySuperview B16@0:8
METHOD _isMemberOfViewControllerHierarchy: B24@0:8@16
METHOD _isRenderedHorizontallyFlipped B16@0:8
METHOD _isResolvedBackgroundGlass B16@0:8
METHOD _isRootForKeyResponderCycle B16@0:8
METHOD _isScrollingEnabled B16@0:8
METHOD _isUnsatisfiableConstraintsLoggingSuspended B16@0:8
METHOD _is_layout v16@0:8
METHOD _is_setNeedsLayout v16@0:8
METHOD _keyboardOrientation q16@0:8
METHOD _la_isVisible B16@0:8
METHOD _largeContentStoredProperties @16@0:8
METHOD _largeContentStoredPropertiesCreatingIfNecessary: @20@0:8B16
METHOD _largeContentViewerGestureManager @16@0:8
METHOD _largestInscribedRectInBoundingPathWithCenter:aspectRatio: {CGRect={CGPoint=dd}{CGSize=dd}}40@0:8{CGPoint=dd}16d32
METHOD _lastNotifiedTraitCollection @16@0:8
METHOD _layer @16@0:8
METHOD _layoutDebuggingIdentifier @16@0:8
METHOD _layoutDebuggingTitle @16@0:8
METHOD _layoutDescriptionIfDifferentFromDefault @16@0:8
METHOD _layoutEngine @16@0:8
METHOD _layoutEngineCreateIfNecessary @16@0:8
METHOD _layoutEngineHostConstraints @16@0:8
METHOD _layoutEngineIfAvailable @16@0:8
METHOD _layoutEngineRelativeAlignmentRectOriginIsValid B16@0:8
METHOD _layoutEngine_isEngineMergingAllowedBetweenEngine:itemEngine:forConstraint:initialView: B48@0:8@16@24@32@40
METHOD _layoutGuide:adjustedLayoutFrameForFrame: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8@16{CGRect={CGPoint=dd}{CGSize=dd}}24
METHOD _layoutHeightDependsOnWidth B16@0:8
METHOD _layoutMarginsDidChangeFromOldMargins: v48@0:8{UIEdgeInsets=dddd}16
METHOD _layoutMarginsGuideIfExists @16@0:8
METHOD _layoutMarginsGuideIgnoresSystemMinimumMargins B16@0:8
METHOD _layoutMarginsWillChange v16@0:8
METHOD _layoutRect @16@0:8
METHOD _layoutSizeThatFits:fixedAxes: {CGSize=dd}40@0:8{CGSize=dd}16Q32
METHOD _layoutSubviewsWithObservationTracking v16@0:8
METHOD _layoutVariablesWithAmbiguousValue @16@0:8
METHOD _lfld_addConstraintsAffectingVariableValueChange: v24@0:8@16
METHOD _lfld_addGeometryChangeRecordWithPropertyName:value: v32@0:8@16@24
METHOD _lfld_addSetNeedsLayoutCallStack: v24@0:8@16
METHOD _lfld_addVariableChangeRecordForVariable:inLayoutEngine: v32@0:8@16@24
METHOD _lfld_constraintsAffectingVariableValueChanges @16@0:8
METHOD _lfld_count q16@0:8
METHOD _lfld_currentLayoutMethodName @16@0:8
METHOD _lfld_description @16@0:8
METHOD _lfld_discardLastCurrentLayoutMethodName v16@0:8
METHOD _lfld_geometryChangeRecords @16@0:8
METHOD _lfld_incrementCount v16@0:8
METHOD _lfld_minimalDescription @16@0:8
METHOD _lfld_prepareToResetCountIfNecessary v16@0:8
METHOD _lfld_pushCurrentLayoutMethodName: v24@0:8@16
METHOD _lfld_resetCount v16@0:8
METHOD _lfld_setNeedsLayoutCallStacks @16@0:8
METHOD _lfld_variableChangeRecords @16@0:8
METHOD _lightStyleRenderConfig B16@0:8
METHOD _localOverrideTraitCollection @16@0:8
METHOD _lowerExpressionOneLevelWithCurrentXExpression:YExpression:vertical:container:engine: @52@0:8@16@24B32@36@44
METHOD _makeSubtreePerformSelector:withObject: v32@0:8:16@24
METHOD _makeSubtreePerformSelector:withObject:withObject:copySublayers: v44@0:8:16@24@32B40
METHOD _makeTemporaryInternalConstraintsWithEngine:ignoreAutoresizingMaskConstraints:returningConstraintsForViewsNeedingSecondPass:currentTargetWidth: v44@0:8@16B24^@28d36
METHOD _marginsDescription @16@0:8
METHOD _maskView @16@0:8
METHOD _matchedViewIdentifier @16@0:8
METHOD _materialDidReceiveLuma: v24@0:8d16
METHOD _maximumContentSizeCategory @16@0:8
METHOD _measureViewWithSize:temporaryConstraints:suspendingSystemConstraints:withOptimizedEngineBlock: v52@0:8{CGSize=dd}16@32B40@?44
METHOD _mergeConstraintsBrokenWhileUnsatisfiableConstraintsLoggingSuspendedToAncestor: v24@0:8@16
METHOD _minXVariable @16@0:8
METHOD _minYVariable @16@0:8
METHOD _minimumContentSizeCategory @16@0:8
METHOD _minimumSafeAreaInsets {UIEdgeInsets=dddd}16@0:8
METHOD _mirrorMaskingConfigurationForProgrammaticallyModifiedLayerKeyPath: v24@0:8@16
METHOD _monitoredView:didMoveFromSuperview:toSuperview: v40@0:8@16@24@32
METHOD _monitoredView:willMoveFromSuperview:toSuperview: v40@0:8@16@24@32
METHOD _monitorsSubtree B16@0:8
METHOD _monitorsView: B24@0:8@16
METHOD _monochromaticContentEffect @16@0:8
METHOD _monochromaticTintColor @16@0:8
METHOD _monochromaticTreatment q16@0:8
METHOD _monochromaticTreatmentStateDidChange v16@0:8
METHOD _morphCenterPoint {CGPoint=dd}16@0:8
METHOD _morphContainerView @16@0:8
METHOD _morphInsets {UIEdgeInsets=dddd}16@0:8
METHOD _morphPreviewFromCurrentState:fallbackBackgroundColor:contentScale: @36@0:8B16@20d28
METHOD _morphView @16@0:8
METHOD _motionEffects @16@0:8
METHOD _motionEffectsAreSuspended B16@0:8
METHOD _multilineContextWidth d16@0:8
METHOD _mutableLayoutArrangements @16@0:8
METHOD _mutableLayoutGuides @16@0:8
METHOD _nearestViewController @16@0:8
METHOD _needsContentsFormatUpdate B16@0:8
METHOD _needsDoubleUpdateConstraintsPass B16@0:8
METHOD _needsLayoutOnAnimatedFrameChangeForNewFrame: B48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _needsToBeNotifiedOfVisibilityChange B16@0:8
METHOD _nextKeyResponder @16@0:8
METHOD _nilBackgroundColor @16@0:8
METHOD _normalInheritedTintColor @16@0:8
METHOD _notifyReferenceViewSizeChange v16@0:8
METHOD _nsis_bounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _nsis_contentSize {CGSize=dd}16@0:8
METHOD _nsis_origin {CGPoint=dd}16@0:8
METHOD _nsis_origin:bounds:inEngine: v40@0:8^{CGPoint=dd}16^{CGRect={CGPoint=dd}{CGSize=dd}}24@32
METHOD _observeScrollViewDidScroll: v24@0:8@16
METHOD _ola_shouldUseImprovedMultilineTextDisambiguation B16@0:8
METHOD _ola_willApplyMultilineTextWidthDisambiguationConstraint v16@0:8
METHOD _oldEngineHostConstraints_frameDidChange v16@0:8
METHOD _oldUpdateLayoutEngineHostConstraints v16@0:8
METHOD _old_nsli_lowerAttribute:intoExpression:withCoefficient:forConstraint: B44@0:8i16@20d28@36
METHOD _outlineShape @16@0:8
METHOD _overrideReparentingContainer @16@0:8
METHOD _overrideTintColor @16@0:8
METHOD _overrideTintColorAutomaticallyOverridesTintColor B16@0:8
METHOD _overrideUserInterfaceRenderingMode q16@0:8
METHOD _overrideUserInterfaceStyle q16@0:8
METHOD _overrideVibrancyTrait q16@0:8
METHOD _paddingForBaselineSpacingFromEdge:toNeighborEdge: d24@0:8i16i20
METHOD _parentDescription @16@0:8
METHOD _parentGestureRecognizerContainer @16@0:8
METHOD _parentTraitEnvironment @16@0:8
METHOD _parentalLayoutEngineDidChangeTo: v24@0:8@16
METHOD _pendingHiddenCount q16@0:8
METHOD _performSelectorTrackingTraitUsage:withInvalidationSelector: v32@0:8:16:24
METHOD _populateArchivedSubviews: v24@0:8@16
METHOD _populateInitialTraitCollection: v24@0:8@16
METHOD _portals @16@0:8
METHOD _preWhitetailUsesAutoresizingConstraints B16@0:8
METHOD _preferredConfigurationForFocusAnimation:inContext: @32@0:8q16@24
METHOD _preferredDurationForFocusAnimation:inContext: d32@0:8q16@24
METHOD _preferredDurationScaleFactorForFocusAnimation:inContext: d32@0:8q16@24
METHOD _preferredHoverEffect @16@0:8
METHOD _preferredHoverShape @16@0:8
METHOD _preferredMaxLayoutWidth d16@0:8
METHOD _prefersDrawingWithForcedScaleFactorInClassicMode B16@0:8
METHOD _prepareForFirstIntrinsicContentSizeCalculation v16@0:8
METHOD _prepareForLayerDump v16@0:8
METHOD _prepareForSecondIntrinsicContentSizeCalculationWithLayoutEngineBounds: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _prepareForWindowDealloc v16@0:8
METHOD _prepareForWindowHostingSceneRemoval v16@0:8
METHOD _presentationControllerToNotifyOnLayoutSubviews @16@0:8
METHOD _preventsPropagationOfVisibilityChanges B16@0:8
METHOD _previewingSegueTemplateStorageForLocation:inView: @40@0:8{CGPoint=dd}16@32
METHOD _previousFittingSizeInfo @16@0:8
METHOD _previousKeyResponder @16@0:8
METHOD _priorityForEngineHostConstraints f16@0:8
METHOD _privateSubview_setValue:forObservedLayerKeyPath: v32@0:8@16@24
METHOD _privateSubview_updateGeometryWithCenter:bounds: v64@0:8{CGPoint=dd}16{CGRect={CGPoint=dd}{CGSize=dd}}32
METHOD _processDidChangeRecursivelyFromOldTraits:toCurrentTraits:forceNotification: v36@0:8@16@24B32
METHOD _projectedTargetForKey:decelerationFactor: @32@0:8@16d24
METHOD _promoteSelfOrDescendantToFirstResponderIfNecessary v16@0:8
METHOD _proofreadingDecorationView @16@0:8
METHOD _proportionalFillLengthForOrderedArrangement:relevantParentAxis: d32@0:8@16q24
METHOD _providesCustomPointerInteraction B16@0:8
METHOD _providesCustomRemoteHoverInteraction B16@0:8
METHOD _proxyView @16@0:8
METHOD _raiseExceptionForBackgroundThreadLayerPropertyModification v16@0:8
METHOD _rawLayoutMargins {UIEdgeInsets=dddd}16@0:8
METHOD _recalculateStrictDescendantNeedsDoubleUpdateConstraints v16@0:8
METHOD _receiveVisitor: v24@0:8@16
METHOD _recordBaselineLoweringInfo B16@0:8
METHOD _rectToScrollToVisibleInCellInWindow: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _rectTuckedAgainstBoundingPathEdge:withSize:cornerRadii:minimumPadding: {CGRect={CGPoint=dd}{CGSize=dd}}72@0:8Q16d24{UIRectCornerRadii=dddd}32d64
METHOD _rectTuckedInBoundingPathCorner:withSize:cornerRadii:minimumPadding: {CGRect={CGPoint=dd}{CGSize=dd}}80@0:8Q16{CGSize=dd}24{UIRectCornerRadii=dddd}40d72
METHOD _recursiveConstraintsTraceAtLevel: @24@0:8q16
METHOD _recursiveInvalidateDescendantsNeedingDoubleUpdateConstraintsCollectingViews: v24@0:8@16
METHOD _recursiveLayoutEngineDescription @16@0:8
METHOD _recursiveMarginsDescription @16@0:8
METHOD _recursiveUpdateConstraintsIfNeededCollectingViews:forSecondPass: v28@0:8@16B24
METHOD _recursivelyNameLayerTree v16@0:8
METHOD _referenceView @16@0:8
METHOD _registerAuxiliaryChildEnvironmentForTraitInvalidations: v24@0:8@16
METHOD _registerForGeometryChanges v16@0:8
METHOD _registerForHDRAnimations v16@0:8
METHOD _registerForTraitTokenChanges:withHandler: @32@0:8@16@?24
METHOD _registerForTraitTokenChanges:withTarget:action: @40@0:8@16@24:32
METHOD _relaxLayoutEngineHostConstraintsForAxis: v24@0:8q16
METHOD _removeAllAnimations: v20@0:8B16
METHOD _removeAllAnimationsIncludingSubviewsTrackingForAnimationRestoration v16@0:8
METHOD _removeAllRetargetableAnimations: v20@0:8B16
METHOD _removeAutolayoutSizingConstraints v16@0:8
METHOD _removeBackdropMaskViews v16@0:8
METHOD _removeBoundingPathChangeObserver: v24@0:8@16
METHOD _removeColorViewBoundsOverlays v16@0:8
METHOD _removeMotionEffect: v24@0:8@16
METHOD _removePropertyAnimationsForLayerKeyPath: v24@0:8@16
METHOD _removeTrackedElementFor: v24@0:8@16
METHOD _replaceInProcessAnimationForKey:behavior:interactive: v36@0:8@16@24B32
METHOD _replaceLayer: v24@0:8@16
METHOD _representationOfHierarchyForXcode @16@0:8
METHOD _requiresExplicitLayoutMarginsGuideForAttribute:getAttributeForGuide: B32@0:8q16^i24
METHOD _resetContentRect v16@0:8
METHOD _resetContentStretch v16@0:8
METHOD _resetLayoutEngineHostConstraintsForAxis:collectingViews: v32@0:8q16@24
METHOD _resetNeedsSystemLayoutFittingSizeUpdateInSubtreeForLayoutEngine: v24@0:8@16
METHOD _resetToBeginningOfDoublePass v16@0:8
METHOD _resizeWithOldSuperviewSize: v32@0:8{CGSize=dd}16
METHOD _resolvedBackground @16@0:8
METHOD _resolvedBackgroundMaterial @16@0:8
METHOD _resolvedOutlineShape @16@0:8
METHOD _responderExternalTouchRectForWindow: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _responderSelectionRectForWindow: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _restoreRemovedAnimationsIncludingSubviews v16@0:8
METHOD _rootForKeyResponderCycle @16@0:8
METHOD _rootInputWindowController @16@0:8
METHOD _rootView @16@0:8
METHOD _rotaryFocusMovementAxis q16@0:8
METHOD _safeAreaCornerAdaptation q16@0:8
METHOD _safeAreaCornerInsets {_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD _safeAreaCornerInsetsDidChange v16@0:8
METHOD _safeAreaInsetsDidChangeFromOldInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _safeAreaInsetsForFrame:inSuperview: {UIEdgeInsets=dddd}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _safeAreaInsetsForFrame:inSuperview:ignoreViewController: {UIEdgeInsets=dddd}60@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48B56
METHOD _safeAreaInsetsFrozen B16@0:8
METHOD _safeAreaInsetsInSuperview: {UIEdgeInsets=dddd}24@0:8@16
METHOD _safeAreaInsetsWillChange v16@0:8
METHOD _safeAreaLayoutGuideIfExists @16@0:8
METHOD _safeAreaWidthExceedsReadableWidth B16@0:8
METHOD _scaleFromLayerTransforms {CGVector=dd}16@0:8
METHOD _sceneDraggingBehaviorOnPan q16@0:8
METHOD _scheduleFaultingInGuidesForConstraint: v24@0:8@16
METHOD _scheduleUpdateConstraintsPassAsEngineHostNeedingLayout: v20@0:8B16
METHOD _scriptingInfo @16@0:8
METHOD _scrollViewWantingUpdateInConstraint: @24@0:8@16
METHOD _scroller @16@0:8
METHOD _secureName I16@0:8
METHOD _sendUpdateConstraintsIfNecessaryForSecondPass: v20@0:8B16
METHOD _setAccessoryViewFrame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _setActiveSizeToFitLayoutEngine: v24@0:8@16
METHOD _setAlignmentRectOriginCache: v24@0:8@16
METHOD _setAllowsHighContrastForBackgroundColor: v20@0:8B16
METHOD _setAllowsMonochromaticTreatment: v20@0:8B16
METHOD _setAppEntityIdentifier: v24@0:8@16
METHOD _setAppIntentIdentifier: v24@0:8@16
METHOD _setAppearanceIsInvalid: v20@0:8B16
METHOD _setBackdropMaskView:forFlag: v32@0:8@16q24
METHOD _setBackdropMaskViewFlags: v24@0:8q16
METHOD _setBackgroundColor: v24@0:8@16
METHOD _setBackgroundIsSolidColor: v20@0:8B16
METHOD _setBackgroundMergeBehavior: v24@0:8q16
METHOD _setBoundingPath: v24@0:8@16
METHOD _setCanBeParentTraitEnvironment: v20@0:8B16
METHOD _setChargeEnabled: v20@0:8B16
METHOD _setClippedSafeAreaCornerInsets: v24@0:8(?={?=CCCCCCCC}Q)16
METHOD _setClippedSafeAreaCornerInsets:updateSubviewsDuringNextLayoutPass: v28@0:8(?={?=CCCCCCCC}Q)16B24
METHOD _setContentCompressionResistancePriorities: v32@0:8{CGSize=dd}16
METHOD _setContentHuggingPriorities: v32@0:8{CGSize=dd}16
METHOD _setContentRectInPixels:forContentSize: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16{CGSize=dd}48
METHOD _setContentSizeNotificationToken: v24@0:8@16
METHOD _setContentStretchInPixels:forContentSize:shouldTile: v68@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16{CGSize=dd}48B64
METHOD _setContinuousCornerRadius: v24@0:8d16
METHOD _setCornerProviderInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setCornerRadius: v24@0:8d16
METHOD _setCountOfFocusedAncestorTrackingViewsInSubtree: v24@0:8Q16
METHOD _setCountOfMotionEffectsInSubtree: v24@0:8Q16
METHOD _setDelaysTouchesForSystemGestures: v20@0:8B16
METHOD _setDisableDictationTouchCancellation: v20@0:8B16
METHOD _setDontUpdateInferredLayoutMargins: v20@0:8B16
METHOD _setDraggingSourceDelegate: v24@0:8@16
METHOD _setDrawsAsBackdropOverlay: v20@0:8B16
METHOD _setDrawsAsBackdropOverlayWithBlendMode: v24@0:8q16
METHOD _setDynamicDropInteraction: v24@0:8@16
METHOD _setEnableMonochromaticTreatment: v20@0:8B16
METHOD _setFirstResponder: v24@0:8@16
METHOD _setFlipsHorizontalAxis: v20@0:8B16
METHOD _setFocusInteractionEnabled: v20@0:8B16
METHOD _setFocusSpeedBumpEdges: v24@0:8Q16
METHOD _setFocusableContentMargins: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setFrameIgnoringLayerTransform: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _setFrameWithAlignmentRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _setGhostPortal: v24@0:8@16
METHOD _setGlassBackgroundNeedsUpdate v16@0:8
METHOD _setGlassContainerEffect: v24@0:8@16
METHOD _setGlassEffect: v24@0:8@16
METHOD _setHiddenForReuse: v20@0:8B16
METHOD _setHostsLayoutEngine: v20@0:8B16
METHOD _setIdleModeLayoutAttributes: v24@0:8@16
METHOD _setIgnoreBackdropViewsWhenHiding: v20@0:8B16
METHOD _setIgnoresLayerTransformForSafeAreaInsets: v20@0:8B16
METHOD _setInAnimatedLayout: v20@0:8B16
METHOD _setInSecondConstraintsPass: v20@0:8B16
METHOD _setInferredLayoutMargins: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setInteractionTintColor: v24@0:8@16
METHOD _setInternalAppIntentsIntelligenceProvider: v24@0:8@16
METHOD _setInternalConstraints: v24@0:8@16
METHOD _setLargeContentStoredProperties: v24@0:8@16
METHOD _setLargeContentViewerGestureManager: v24@0:8@16
METHOD _setLastNotifiedTraitCollection: v24@0:8@16
METHOD _setLayoutDebuggingIdentifier: v24@0:8@16
METHOD _setLayoutEngine: v24@0:8@16
METHOD _setLayoutMarginsGuide: v24@0:8@16
METHOD _setLayoutMarginsGuideIgnoresSystemMinimumMargins: v20@0:8B16
METHOD _setLocalOverrideTraitCollection: v24@0:8@16
METHOD _setMaskView: v24@0:8@16
METHOD _setMatchedViewIdentifier: v24@0:8@16
METHOD _setMonitorsSubtree: v20@0:8B16
METHOD _setMonochromaticTreatment: v24@0:8q16
METHOD _setMorphInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setMultilineContextWidth: v24@0:8d16
METHOD _setNeedsContentsFormatUpdate v16@0:8
METHOD _setNeedsContentsFormatUpdate: v20@0:8B16
METHOD _setNeedsUpdateConstraints v16@0:8
METHOD _setNeedsUpdateConstraintsNeedingLayout: v20@0:8B16
METHOD _setNeedsUpdateProperties v16@0:8
METHOD _setOverrideReparentingContainer: v24@0:8@16
METHOD _setOverrideTintColor: v24@0:8@16
METHOD _setOverrideUserInterfaceRenderingMode: v24@0:8q16
METHOD _setOverrideVibrancyTrait: v24@0:8q16
METHOD _setPresentationControllerToNotifyOnLayoutSubviews: v24@0:8@16
METHOD _setPresentationValue:forKey: v32@0:8@16@24
METHOD _setPresentationValue:velocity:preferredFrameRateRangeMaximum:forKey: v44@0:8@16@24i32@36
METHOD _setPreviewingSegueTemplateStorage: v24@0:8@16
METHOD _setPreviousFittingSizeInfo: v24@0:8@16
METHOD _setRawLayoutMargins: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setReadableContentGuide: v24@0:8@16
METHOD _setRenderConfig: v24@0:8@16
METHOD _setSafeAreaCornerAdaptation: v24@0:8q16
METHOD _setSafeAreaCornerInsets: v80@0:8{_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16
METHOD _setSafeAreaCornerInsets:updateSubviewsDuringNextLayoutPass: v84@0:8{_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16B80
METHOD _setSafeAreaInsetsFrozen: v20@0:8B16
METHOD _setSafeAreaInsetsFrozen:updateForUnfreeze: v24@0:8B16B20
METHOD _setShouldAdaptToMaterials: v20@0:8B16
METHOD _setShouldArchiveUIAppearanceTags: v20@0:8B16
METHOD _setShouldNotifyGeometryObserversForBaselineChanges: v20@0:8B16
METHOD _setShouldRasterize: v20@0:8B16
METHOD _setSourceCenter: v32@0:8{CGPoint=dd}16
METHOD _setSpeedBumpEdges: v24@0:8Q16
METHOD _setSubviewWantsAutolayoutTripWantsAutolayout: v20@0:8B16
METHOD _setTargetVelocity:forKey: v32@0:8@16@24
METHOD _setTouchInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD _setTracksFocusedAncestors: v20@0:8B16
METHOD _setTraitStorageConstraints: v24@0:8@16
METHOD _setTraitStorageList: v24@0:8@16
METHOD _setTraitStorageSubviews: v24@0:8@16
METHOD _setTransform3D: v144@0:8{CATransform3D=dddddddddddddddd}16
METHOD _setUserInterfaceIdiom: v24@0:8q16
METHOD _setVelocity:forKey: v32@0:8@16@24
METHOD _setViewDelegateContentOverlayInsetsAreClean: v20@0:8B16
METHOD _setViewsJostledDuringUpdateConstraintsPass: v24@0:8@16
METHOD _setVisualAltitude: v24@0:8d16
METHOD _setVisualAltitudeBias: v32@0:8{CGSize=dd}16
METHOD _setWantsAutolayout v16@0:8
METHOD _setWantsGlassAppearance: v20@0:8B16
METHOD _setWritingToolsCoordinator: v24@0:8@16
METHOD _shapeInCoordinateSpace: @24@0:8@16
METHOD _shouldAdaptToMaterials B16@0:8
METHOD _shouldAlwaysDiagnoseFocusInteractionEligibility B16@0:8
METHOD _shouldAnimatePropertyAdditivelyWithKey: B24@0:8@16
METHOD _shouldAnimatePropertyWithKey: B24@0:8@16
METHOD _shouldAppendTextInViewDescription B16@0:8
METHOD _shouldApplyExclusiveTouch B16@0:8
METHOD _shouldArchiveUIAppearanceTags B16@0:8
METHOD _shouldDecodeSubviews B16@0:8
METHOD _shouldDelayTouchForSystemGestures: B24@0:8@16
METHOD _shouldEnclosedScrollViewFlashIndicators: B24@0:8@16
METHOD _shouldIgnoreAutofillSave B16@0:8
METHOD _shouldInformFocusAboutBecomingVisible B16@0:8
METHOD _shouldInheritScreenScaleAsContentScaleFactor B16@0:8
METHOD _shouldInvalidateBaselineConstraintsForSize:oldSize: B48@0:8{CGSize=dd}16{CGSize=dd}32
METHOD _shouldInvalidateCornersForGeometryChange:ancestor: B32@0:8Q16@24
METHOD _shouldNotifyGeometryObservers B16@0:8
METHOD _shouldNotifyGeometryObserversForBaselineChanges B16@0:8
METHOD _shouldResignFirstResponderWithInteractionDisabled B16@0:8
METHOD _shouldReverseLayoutDirection B16@0:8
METHOD _shouldUpdateFocusInContext: B24@0:8@16
METHOD _shouldUseViewForSceneDraggingBehavior B16@0:8
METHOD _snipDangliesWithForce:repairIfPossibleForViewThatMoved:newSuperview:oldSuperview: v44@0:8B16@20@28@36
METHOD _sourceRectForPresentationInWindow: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _sourceViewForPresentationInWindow: @24@0:8@16
METHOD _sourceViewIfPortal @16@0:8
METHOD _startObservingVariablesOnlyToSupportTAMICChange: v20@0:8B16
METHOD _stashedLayoutVariableObservations @16@0:8
METHOD _stopObservingVariablesOnlyToSupportTAMICChange: v20@0:8B16
METHOD _strokeClippedViewIfNecessary v16@0:8
METHOD _style i16@0:8
METHOD _subclassImplementsDrawRect B16@0:8
METHOD _subscribeToScrollNotificationsIfNecessary: v24@0:8@16
METHOD _subviewPreventsSkipLayout: B24@0:8@16
METHOD _supportedTreatmentForTreatment: q24@0:8q16
METHOD _supportsBecomeFirstResponderWhenPossible B16@0:8
METHOD _supportsContentDimensionVariables B16@0:8
METHOD _suppressBackground @16@0:8
METHOD _switchToLayoutEngine: v24@0:8@16
METHOD _systemDefaultFocusGroupIdentifier @16@0:8
METHOD _systemDefaultFocusGroupPriority q16@0:8
METHOD _systemLayoutSizeFittingSize:withHorizontalFittingPriority:verticalFittingPriority: {CGSize=dd}40@0:8{CGSize=dd}16f32f36
METHOD _systemLayoutSizeFittingSize:withHorizontalFittingPriority:verticalFittingPriority:hasIntentionallyCollapsedHeight: {CGSize=dd}48@0:8{CGSize=dd}16f32f36^B40
METHOD _systemSpacingBelowView:multiplier: d32@0:8@16d24
METHOD _systemSpacingBelowView:systemSpacingInvalidationRecorder: d32@0:8@16^@24
METHOD _targetVelocityForKey: @24@0:8@16
METHOD _textButtonMargin d16@0:8
METHOD _textServicesResponderProxy @16@0:8
METHOD _throwForUnsupportedNonMacIdiomBehaviorWithReason: v24@0:8@16
METHOD _tintColorArchivingKey @16@0:8
METHOD _tintColorDidChange v16@0:8
METHOD _topLeadingConcentricLayoutPoint @16@0:8
METHOD _topLeftConcentricLayoutPoint @16@0:8
METHOD _topRightConcentricLayoutPoint @16@0:8
METHOD _topToBottomLeftToRightViewCompare: q24@0:8@16
METHOD _topTrailingConcentricLayoutPoint @16@0:8
METHOD _touchForceObservable @16@0:8
METHOD _touchInsets {UIEdgeInsets=dddd}16@0:8
METHOD _touchSloppinessFactor d16@0:8
METHOD _tracksFocusedAncestors B16@0:8
METHOD _traitCollectionDidChangeInternal: v24@0:8r^{_UITraitCollectionChangeDescription=@@{?=@[4Q]}B{_UITraitCollectionTraitChanges=BBBB}}16
METHOD _traitCollectionDidChangeOnSubtreeInternal: v24@0:8r^{_UITraitCollectionChangeDescription=@@{?=@[4Q]}B{_UITraitCollectionTraitChanges=BBBB}}16
METHOD _traitCollectionForChildEnvironment: @24@0:8@16
METHOD _traitOverridesDidChange v16@0:8
METHOD _traitStorageConstraints @16@0:8
METHOD _traitStorageSubviews @16@0:8
METHOD _traitTrace @16@0:8
METHOD _traitTrace: @24@0:8@16
METHOD _transform3D {CATransform3D=dddddddddddddddd}16@0:8
METHOD _tvAddsChildFocusItemsBeforeSelf B16@0:8
METHOD _tvAddsChildFocusItemsButNotSelf B16@0:8
METHOD _tvAllowsFocusInChildrenWhenFocused B16@0:8
METHOD _ui_addSubLayoutItem: v24@0:8@16
METHOD _ui_addToView:atIndex: v32@0:8@16q24
METHOD _ui_bounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _ui_frame {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _ui_insertSubLayoutItem:atIndex: v32@0:8@16q24
METHOD _ui_removeFromParentLayoutItem v16@0:8
METHOD _ui_superview @16@0:8
METHOD _ui_usesManualLayout B16@0:8
METHOD _ui_view @16@0:8
METHOD _uiib_hostsLayoutEngine B16@0:8
METHOD _uiib_invalidateAutoresizingConstraints v16@0:8
METHOD _uiib_layoutEngineCreatingIfNecessary @16@0:8
METHOD _uiib_setHostsLayoutEngine: v20@0:8B16
METHOD _uiib_tryToAddConstraint:roundingAdjustment:mutuallyExclusiveConstraints: B40@0:8@16d24^@32
METHOD _uili_existingBaseFrameVariables @16@0:8
METHOD _uili_existingObservationEligibleLayoutVariables @16@0:8
METHOD _uili_isFocusGuide B16@0:8
METHOD _uili_observableLayoutEngineForBaseFrameVariables: @20@0:8B16
METHOD _uili_requiresObservationForVariable: B24@0:8@16
METHOD _uili_stashLayoutVariableObservation:forVariable: v32@0:8@16@24
METHOD _uimorphingView_setInitialAlpha: v24@0:8d16
METHOD _uinavigationbar_prepareToAppearInNavigationItem:onLeft: v28@0:8@16B24
METHOD _uis_outline @16@0:8
METHOD _unapplyMotionEffect: B24@0:8@16
METHOD _unconditionallyWantsSetBoundsFromISEngineLayout B16@0:8
METHOD _undimmedTintColor @16@0:8
METHOD _unregisterAuxiliaryChildEnvironmentForTraitInvalidations: v24@0:8@16
METHOD _unregisterConcentricDependenciesIfNecessary v16@0:8
METHOD _unregisterForGeometryChanges v16@0:8
METHOD _unsubscribeToScrollNotificationsIfNecessary: v24@0:8@16
METHOD _updateCombinedInsetsIfNecessary v16@0:8
METHOD _updateConcentricConstraintsIfNecessary v16@0:8
METHOD _updateConstraintsIfNeededCollectingViews:forSecondPass: v28@0:8@16B24
METHOD _updateConstraintsIfNeededWithViewForVariableChangeNotifications: v24@0:8@16
METHOD _updateConstraintsWithObservationTracking v16@0:8
METHOD _updateCornerProvidersWithParentTraitCollection: v24@0:8@16
METHOD _updateCorners v16@0:8
METHOD _updateCornersWithObservationTracking v16@0:8
METHOD _updateDynamicBackgroundColor v16@0:8
METHOD _updateDynamicLayoutGuideConstraintsIfNeeded v16@0:8
METHOD _updateInferredLayoutMargins v16@0:8
METHOD _updateInferredLayoutMarginsFromSuperview: v24@0:8@16
METHOD _updateLayoutEngineHostConstraints v16@0:8
METHOD _updateLayoutMarginsGuideConstraintsIfNecessary v16@0:8
METHOD _updateManagedContent:neededWhen:update:setUp:tearDown: v52@0:8@16B24@?28@?36@?44
METHOD _updateProperties v16@0:8
METHOD _updatePropertiesIfNeeded v16@0:8
METHOD _updatePropertiesWithObservationTracking v16@0:8
METHOD _updateSafeAreaInsets v16@0:8
METHOD _updateSystemConstraints v16@0:8
METHOD _useContentDimensionVariablesForConstraintLowering B16@0:8
METHOD _userInterfaceIdiom q16@0:8
METHOD _usesMinimumSafeAreas B16@0:8
METHOD _velocityForKey: @24@0:8@16
METHOD _vendedBaselineViewDidMoveForFirst: v20@0:8B16
METHOD _vendedBaselineViewParametersDidChange v16@0:8
METHOD _viewControllerForAncestor @16@0:8
METHOD _viewControllerToNotifyOnLayoutSubviews @16@0:8
METHOD _viewDelegate @16@0:8
METHOD _viewDelegateContentOverlayInsetsAreClean B16@0:8
METHOD _viewDidMoveFromScreen:toScreen: v32@0:8@16@24
METHOD _viewForBaselineLayout @16@0:8
METHOD _viewForLoweringBaselineLayoutAttribute: @20@0:8i16
METHOD _viewHierarchyUnpreparedForConstraint: v24@0:8@16
METHOD _viewsJostledDuringUpdateConstraintsPass @16@0:8
METHOD _viewsJostledDuringUpdateConstraintsPassSuppressingDebugAssertion: @20@0:8B16
METHOD _visibilityDidChange v16@0:8
METHOD _visualAltitudeBias {CGSize=dd}16@0:8
METHOD _visualAltitudeSensitiveBoundsWithInfiniteEdges: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8Q16
METHOD _visualRecursiveDescription @16@0:8
METHOD _wantsAnimationRestoration B16@0:8
METHOD _wantsAutolayout B16@0:8
METHOD _wantsBaselineUpdatingFollowingConstraintsPass B16@0:8
METHOD _wantsConstraintBasedLayout B16@0:8
METHOD _wantsDeepDrawing B16@0:8
METHOD _wantsKeyCommandsWhenDeferred B16@0:8
METHOD _webCustomViewWillBeRemovedFromSuperview v16@0:8
METHOD _widthForButtonBarItemLayout d16@0:8
METHOD _willChangeToIdiom:onScreen: v32@0:8q16@24
METHOD _willMoveToWindow: v24@0:8@16
METHOD _willMoveToWindow:withAncestorView: v32@0:8@16@24
METHOD _willRemoveSubview: v24@0:8@16
METHOD _willUpdateFocusInContext: v24@0:8@16
METHOD _withUnsatisfiableConstraintsLoggingSuspendedIfEngineDelegateExists: v24@0:8@?16
METHOD _writingToolsCoordinator @16@0:8
METHOD accessibilityApplyInvertFilter v16@0:8
METHOD accessibilityHUDRepresentation @16@0:8
METHOD accessibilityIgnoresInvertColors B16@0:8
METHOD accessibilityInvertFilterApplied B16@0:8
METHOD accessibilityUnapplyInvertFilter v16@0:8
METHOD actionForLayer:forKey: @32@0:8@16@24
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD addConstraint: v24@0:8@16
METHOD addGestureRecognizer: v24@0:8@16
METHOD addMotionEffect: v24@0:8@16
METHOD alignmentRectForFrame: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD alignmentRectInsets {UIEdgeInsets=dddd}16@0:8
METHOD allowsGroupBlending B16@0:8
METHOD allowsGroupOpacity B16@0:8
METHOD anchorPoint {CGPoint=dd}16@0:8
METHOD appliedContentSizeCategoryLimitsDescription @16@0:8
METHOD autoresizesSubviews B16@0:8
METHOD autoresizingMask Q16@0:8
METHOD becomeFirstResponder B16@0:8
METHOD bottomAnchor @16@0:8
METHOD bringSubviewToFront: v24@0:8@16
METHOD canBecomeFocused B16@0:8
METHOD canPerformAction:withSender: B32@0:8:16@24
METHOD cancelMouseTracking B16@0:8
METHOD cancelTouchTracking B16@0:8
METHOD centerXAnchor @16@0:8
METHOD centerYAnchor @16@0:8
METHOD charge f16@0:8
METHOD clearsContextBeforeDrawing B16@0:8
METHOD clipsToBounds B16@0:8
METHOD compareTextEffectsOrdering: q24@0:8@16
METHOD constraintsAffectingLayoutForAxis: @24@0:8q16
METHOD constraintsAffectingLayoutForAxis:ofItem: @32@0:8q16@24
METHOD constraintsDidChangeInEngine: v24@0:8@16
METHOD containsView: B24@0:8@16
METHOD contentCompressionResistancePriorityForAxis: f24@0:8q16
METHOD contentHuggingPriorityForAxis: f24@0:8q16
METHOD contentStretch {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD contextIdentifier q16@0:8
METHOD convertPoint:fromCoordinateSpace: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD convertPoint:fromView: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD convertPoint:toView: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD convertRect:fromCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:fromMaskingCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:toCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:toMaskingCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:toView: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertSize:fromView: {CGSize=dd}40@0:8{CGSize=dd}16@32
METHOD cornerConfiguration @16@0:8
METHOD deferredBecomeFirstResponder v16@0:8
METHOD deliversPressesForGesturesToSuperview B16@0:8
METHOD deliversTouchesForGesturesToSuperview B16@0:8
METHOD didAddSubview: v24@0:8@16
METHOD didMoveToSuperview v16@0:8
METHOD didUpdateFocusInContext:withAnimationCoordinator: v32@0:8@16@24
METHOD directionalEdgeInsetsForLayoutRegion: {NSDirectionalEdgeInsets=dddd}24@0:8@16
METHOD directionalLayoutMargins {NSDirectionalEdgeInsets=dddd}16@0:8
METHOD drawLayer:inContext: v32@0:8@16^{CGContext=}24
METHOD drawRect: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD drawViewHierarchyInRect: B48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD drawViewHierarchyInRect:afterScreenUpdates: B52@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16B48
METHOD edgeInsetsForLayoutRegion: {UIEdgeInsets=dddd}24@0:8@16
METHOD edgesInsettingLayoutMarginsFromSafeArea Q16@0:8
METHOD edgesPreservingSuperviewLayoutMargins Q16@0:8
METHOD effectiveRadiusForCorner: d24@0:8Q16
METHOD effectiveUserInterfaceLayoutDirection q16@0:8
METHOD endEditing: B20@0:8B16
METHOD engine:markerForConstraintToBreakAmongConstraints: @32@0:8@16@24
METHOD engine:willBreakConstraint:dueToMutuallyExclusiveConstraints: v40@0:8@16@24@32
METHOD exchangeSubviewAtIndex:withSubviewAtIndex: v32@0:8q16q24
METHOD exerciseAmbiguityInLayout v16@0:8
METHOD find: v24@0:8@16
METHOD findNext: v24@0:8@16
METHOD findPrevious: v24@0:8@16
METHOD firstBaselineAnchor @16@0:8
METHOD focusEffect @16@0:8
METHOD focusGroupIdentifier @16@0:8
METHOD focusGroupPriority q16@0:8
METHOD focusGuides @16@0:8
METHOD focusItemContainer @16@0:8
METHOD focusItemDeferralMode q16@0:8
METHOD focusItemsInRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD forceDisplayIfNeeded v16@0:8
METHOD frameForAlignmentRect: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD frameInView: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD frameOrigin {CGPoint=dd}16@0:8
METHOD gestureRecognizerShouldBegin: B24@0:8@16
METHOD gestureRecognizers @16@0:8
METHOD hasAmbiguousLayout B16@0:8
METHOD heightAnchor @16@0:8
METHOD hitTest:forEvent: @40@0:8{CGPoint=dd}16^{__GSEvent=}32
METHOD hitTest:withEvent: @40@0:8{CGPoint=dd}16@32
METHOD hitTestDirectionalInsets {NSDirectionalEdgeInsets=dddd}16@0:8
METHOD hitTestInsets {UIEdgeInsets=dddd}16@0:8
METHOD hoverStyle @16@0:8
METHOD initWithLayer: @24@0:8@16
METHOD inputResponderController @16@0:8
METHOD insertSubview:above: v32@0:8@16@24
METHOD insertSubview:aboveSubview: v32@0:8@16@24
METHOD insertSubview:atIndex: v32@0:8@16q24
METHOD insertSubview:below: v32@0:8@16@24
METHOD insertSubview:belowSubview: v32@0:8@16@24
METHOD interactionTintColor @16@0:8
METHOD interactionTintColorDidChange v16@0:8
METHOD invalidateIntrinsicContentSize v16@0:8
METHOD isDescendantOfView: B24@0:8@16
METHOD isElementAccessibilityExposedToInterfaceBuilder B16@0:8
METHOD isExclusiveTouch B16@0:8
METHOD isFocused B16@0:8
METHOD isHiddenOrHasHiddenAncestor B16@0:8
METHOD isMultipleTouchEnabled B16@0:8
METHOD isTransparentFocusItem B16@0:8
METHOD isUserInteractionEnabled B16@0:8
METHOD keyboardLayoutGuide @16@0:8
METHOD keyboardSceneDelegate @16@0:8
METHOD largeContentImage @16@0:8
METHOD largeContentImageInsets {UIEdgeInsets=dddd}16@0:8
METHOD largeContentTitle @16@0:8
METHOD lastBaselineAnchor @16@0:8
METHOD layer @16@0:8
METHOD layerWillDraw: v24@0:8@16
METHOD layoutBelowIfNeeded v16@0:8
METHOD layoutGuideForLayoutRegion: @24@0:8@16
METHOD layoutGuides @16@0:8
METHOD layoutIfNeeded v16@0:8
METHOD layoutMargins {UIEdgeInsets=dddd}16@0:8
METHOD layoutMarginsDidChange v16@0:8
METHOD layoutMarginsFollowReadableWidth B16@0:8
METHOD layoutMarginsGuide @16@0:8
METHOD layoutSublayersOfLayer: v24@0:8@16
METHOD layoutSubviews v16@0:8
METHOD leadingAnchor @16@0:8
METHOD leftAnchor @16@0:8
METHOD maskView @16@0:8
METHOD maximumContentSizeCategory @16@0:8
METHOD minimumContentSizeCategory @16@0:8
METHOD motionEffects @16@0:8
METHOD movedFromSuperview: v24@0:8@16
METHOD movedFromWindow: v24@0:8@16
METHOD movedToSuperview: v24@0:8@16
METHOD movedToWindow: v24@0:8@16
METHOD mt_addPrivateSubview: v24@0:8@16
METHOD mt_backgroundEffects @16@0:8
METHOD mt_captureGroupName @16@0:8
METHOD mt_contentEffects @16@0:8
METHOD mt_setBackgroundEffects: v24@0:8@16
METHOD mt_setCaptureGroupName: v24@0:8@16
METHOD mt_setContentEffects: v24@0:8@16
METHOD mt_setVisualEffect: v24@0:8@16
METHOD needsDisplayOnBoundsChange B16@0:8
METHOD needsUpdateConstraints B16@0:8
METHOD newSnapshotWithRect: ^{CGImage=}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD nextResponder @16@0:8
METHOD nsis_descriptionOfVariable: @24@0:8@16
METHOD nsis_orientationHintForVariable: i24@0:8@16
METHOD nsis_valueOfVariable:didChangeInEngine: v32@0:8@16@24
METHOD nsis_valueOfVariableIsUserObservable: B24@0:8@16
METHOD nsli_addConstraint: v24@0:8@16
METHOD nsli_autoresizingMask Q16@0:8
METHOD nsli_boundsHeightVariable @16@0:8
METHOD nsli_boundsWidthVariable @16@0:8
METHOD nsli_canHostIndependentVariableAnchor B16@0:8
METHOD nsli_constraintWithAnchor:relatedBy:toAnchor:withSystemSpacingMultipliedBy: @48@0:8@16q24@32d40
METHOD nsli_contentHeightVariable @16@0:8
METHOD nsli_contentWidthVariable @16@0:8
METHOD nsli_contentXOffsetVariable @16@0:8
METHOD nsli_contentYOffsetVariable @16@0:8
METHOD nsli_convertSizeFromEngineSpace: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD nsli_convertSizeToEngineSpace: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD nsli_defaultResolvedValue:forSymbolicConstant:inConstraint:error: B48@0:8^d16@24@32^@40
METHOD nsli_description @16@0:8
METHOD nsli_engineToUserScalingCoefficients {CGSize=dd}16@0:8
METHOD nsli_heightVariable @16@0:8
METHOD nsli_installedConstraints @16@0:8
METHOD nsli_isCollectingConstraintChangesForLaterCoordinatedFlush: B24@0:8@16
METHOD nsli_isFlipped B16@0:8
METHOD nsli_isLegalConstraintItem B16@0:8
METHOD nsli_isRTL B16@0:8
METHOD nsli_layoutAnchorForAttribute: @24@0:8q16
METHOD nsli_layoutEngine @16@0:8
METHOD nsli_layoutMarginsItem @16@0:8
METHOD nsli_lowerAttribute:intoExpression:withCoefficient:container: B44@0:8i16@20d28@36
METHOD nsli_lowerAttribute:intoExpression:withCoefficient:forConstraint: B44@0:8i16@20d28@36
METHOD nsli_lowerAttribute:intoExpression:withCoefficient:forConstraint:onBehalfOfLayoutGuide: B52@0:8i16@20d28@36@44
METHOD nsli_marginOffsetForAttribute: d24@0:8q16
METHOD nsli_minXVariable @16@0:8
METHOD nsli_minYVariable @16@0:8
METHOD nsli_removeConstraint: B24@0:8@16
METHOD nsli_resolvedValue:forSymbolicConstant:inConstraint:error: B48@0:8^d16@24@32^@40
METHOD nsli_superitem @16@0:8
METHOD nsli_widthVariable @16@0:8
METHOD overrideUserInterfaceStyle q16@0:8
METHOD parentFocusEnvironment @16@0:8
METHOD pointInside:forEvent: B40@0:8{CGPoint=dd}16^{__GSEvent=}32
METHOD pointInside:withEvent: B40@0:8{CGPoint=dd}16@32
METHOD preferredFocusEnvironments @16@0:8
METHOD preferredFocusedView @16@0:8
METHOD readableContentGuide @16@0:8
METHOD recursiveDescription @16@0:8
METHOD reduceWidth: v24@0:8d16
METHOD registerBoundingPathObserverForCornerMaskingConfigurationChanges: v24@0:8@16
METHOD registerDescendant:forGeometryOrMaskingConfigurationChanges: @?32@0:8@16@?24
METHOD registerForTraitChanges:withAction: @32@0:8@16:24
METHOD registerForTraitChanges:withHandler: @32@0:8@16@?24
METHOD registerForTraitChanges:withTarget:action: @40@0:8@16@24:32
METHOD removeAllGestureRecognizers v16@0:8
METHOD removeConstraint: v24@0:8@16
METHOD removeConstraints: v24@0:8@16
METHOD removeGestureRecognizer: v24@0:8@16
METHOD removeInteraction: v24@0:8@16
METHOD removeLayoutGuide: v24@0:8@16
METHOD removeMotionEffect: v24@0:8@16
METHOD resizableSnapshotFromRect:withCapInsets: @80@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16{UIEdgeInsets=dddd}48
METHOD resizableSnapshotViewFromRect:withCapInsets: @80@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16{UIEdgeInsets=dddd}48
METHOD resizeSubviewsWithOldSize: v32@0:8{CGSize=dd}16
METHOD resizeWithOldSuperviewSize: v32@0:8{CGSize=dd}16
METHOD resolvedCornerRadiusForDescedant:context:corner: d40@0:8@16@24Q32
METHOD restoreUserActivityState: v24@0:8@16
METHOD rightAnchor @16@0:8
METHOD safeAreaInsets {UIEdgeInsets=dddd}16@0:8
METHOD safeAreaInsetsDidChange v16@0:8
METHOD safeAreaLayoutGuide @16@0:8
METHOD scalesLargeContentImage B16@0:8
METHOD scriptingInfoWithChildren @16@0:8
METHOD semanticContentAttribute q16@0:8
METHOD sendSubviewToBack: v24@0:8@16
METHOD setAccessibilityIgnoresInvertColors: v20@0:8B16
METHOD setAllowsGroupBlending: v20@0:8B16
METHOD setAllowsGroupOpacity: v20@0:8B16
METHOD setAlpha: v24@0:8d16
METHOD setAutoresizesSubviews: v20@0:8B16
METHOD setAutoresizingMask: v24@0:8Q16
METHOD setCharge: v20@0:8f16
METHOD setClearsContext: v20@0:8B16
METHOD setClearsContextBeforeDrawing: v20@0:8B16
METHOD setClipsSubviews: v20@0:8B16
METHOD setClipsToBounds: v20@0:8B16
METHOD setCompositingMode: v24@0:8q16
METHOD setContentCompressionResistancePriority:forAxis: v28@0:8f16q20
METHOD setContentHuggingPriority:forAxis: v28@0:8f16q20
METHOD setContentScaleFactor: v24@0:8d16
METHOD setContentStretch: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setContentsPosition: v20@0:8i16
METHOD setCornerConfiguration: v24@0:8@16
METHOD setDeliversPressesForGesturesToSuperview: v20@0:8B16
METHOD setDeliversTouchesForGesturesToSuperview: v20@0:8B16
METHOD setDirectionalLayoutMargins: v48@0:8{NSDirectionalEdgeInsets=dddd}16
METHOD setEdgesInsettingLayoutMarginsFromSafeArea: v24@0:8Q16
METHOD setEdgesPreservingSuperviewLayoutMargins: v24@0:8Q16
METHOD setExclusiveTouch: v20@0:8B16
METHOD setFixedBackgroundPattern: v20@0:8B16
METHOD setFocusGroupIdentifier: v24@0:8@16
METHOD setFocusGroupPriority: v24@0:8q16
METHOD setFrame:forFields: v52@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16i48
METHOD setGestureRecognizers: v24@0:8@16
METHOD setHitTestDirectionalInsets: v48@0:8{NSDirectionalEdgeInsets=dddd}16
METHOD setHitTestInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD setHoverStyle: v24@0:8@16
METHOD setInsetsLayoutMarginsFromSafeArea: v20@0:8B16
METHOD setInteractionTintColor: v24@0:8@16
METHOD setLargeContentImage: v24@0:8@16
METHOD setLargeContentImageInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD setLargeContentTitle: v24@0:8@16
METHOD setLayoutMargins: v48@0:8{UIEdgeInsets=dddd}16
METHOD setLayoutMarginsFollowReadableWidth: v20@0:8B16
METHOD setMaskView: v24@0:8@16
METHOD setMaximumContentSizeCategory: v24@0:8@16
METHOD setMinimumContentSizeCategory: v24@0:8@16
METHOD setMotionEffects: v24@0:8@16
METHOD setMultipleTouchEnabled: v20@0:8B16
METHOD setNeedsDisplayOnBoundsChange: v20@0:8B16
METHOD setNeedsFocusUpdate v16@0:8
METHOD setNeedsUpdateConstraints v16@0:8
METHOD setNeedsUpdateProperties v16@0:8
METHOD setOrigin: v32@0:8{CGPoint=dd}16
METHOD setOverrideUserInterfaceStyle: v24@0:8q16
METHOD setPreservesSuperviewLayoutMargins: v20@0:8B16
METHOD setRotationBy: v20@0:8f16
METHOD setSafeAreaInsets: v48@0:8{UIEdgeInsets=dddd}16
METHOD setScalesLargeContentImage: v20@0:8B16
METHOD setSemanticContentAttribute: v24@0:8q16
METHOD setShowsLargeContentViewer: v20@0:8B16
METHOD setSkipsSubviewEnumeration: v20@0:8B16
METHOD setSubduesSiblings:belowView: @28@0:8B16@20
METHOD setTintAdjustmentMode: v24@0:8q16
METHOD setTintColor: v24@0:8@16
METHOD setTranslatesAutoresizingMaskIntoConstraints: v20@0:8B16
METHOD setUserInteractionEnabled: v20@0:8B16
METHOD setViewTraversalMark: v20@0:8B16
METHOD setWantsDeepColorDrawing: v20@0:8B16
METHOD setZPosition: v24@0:8d16
METHOD set_ui_frame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD set_ui_usesManualLayout: v20@0:8B16
METHOD shouldUpdateFocusInContext: B24@0:8@16
METHOD showsLargeContentViewer B16@0:8
METHOD sizeThatFits: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD sizeToFit v16@0:8
METHOD skipsSubviewEnumeration B16@0:8
METHOD snapshotView @16@0:8
METHOD solutionDidChangeInEngine: v24@0:8@16
METHOD stopSettingPresentationValueForKey: v24@0:8@16
METHOD subviews @16@0:8
METHOD systemLayoutSizeFittingSize: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD systemLayoutSizeFittingSize:withHorizontalFittingPriority:verticalFittingPriority: {CGSize=dd}40@0:8{CGSize=dd}16f32f36
METHOD textEffectsVisibilityLevel i16@0:8
METHOD textEffectsVisibilityLevelInKeyboardWindow i16@0:8
METHOD textInputView @16@0:8
METHOD tintAdjustmentMode q16@0:8
METHOD tintColor @16@0:8
METHOD tintColorDidChange v16@0:8
METHOD topAnchor @16@0:8
METHOD trackedState q16@0:8
METHOD trailingAnchor @16@0:8
METHOD traitCollectionDidChange: v24@0:8@16
METHOD traitOverrides @16@0:8
METHOD transform3D {CATransform3D=dddddddddddddddd}16@0:8
METHOD translatesAutoresizingMaskIntoConstraints B16@0:8
METHOD unregisterForTraitChanges: v24@0:8@16
METHOD updateConstraints v16@0:8
METHOD updateConstraintsIfNeeded v16@0:8
METHOD updateFocusIfNeeded v16@0:8
METHOD updateProperties v16@0:8
METHOD updatePropertiesIfNeeded v16@0:8
METHOD updateTraitsIfNeeded v16@0:8
METHOD updateUserActivityState: v24@0:8@16
METHOD viewDidMoveToSuperview v16@0:8
METHOD viewForBaselineLayout @16@0:8
METHOD viewForFirstBaselineLayout @16@0:8
METHOD viewForLastBaselineLayout @16@0:8
METHOD viewTraversalMark B16@0:8
METHOD viewWillMoveToSuperview: v24@0:8@16
METHOD viewWithTag: @24@0:8q16
METHOD visibleBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD wantsDeepColorDrawing B16@0:8
METHOD widthAnchor @16@0:8
METHOD willMoveToSuperview: v24@0:8@16
METHOD willMoveToWindow: v24@0:8@16
METHOD willRemoveSubview: v24@0:8@16
METHOD window @16@0:8
METHOD zPosition d16@0:8

=== CLASS UIWindow ===
SUPER: UIView
SIZE: 920
PROTOCOLS: NSISEngineDelegate _UIOrientationDebugDescriptionProviding _UIFocusEventRecognizerDelegate _UIForcedOrientationTransactionHandler _UIPassthroughScrollInteractionDelegate _UIFocusMovementActionForwarding _UIContextBindable
IVAR +408 0 _debugName @"NSString"
IVAR +416 0 _sceneOrientation q
IVAR +424 0 _sceneClientOrientation q
IVAR +432 0 _notedOverlayInsetChange B
IVAR +440 0 _delegateViewController @"UIViewController"
IVAR +448 0 _windowLevel d
IVAR +456 0 _windowSublevel d
IVAR +464 0 _layerContext @"CAContext"
IVAR +472 0 _contextBinder @"_UIContextBinder"
IVAR +480 0 _firstResponder @"UIResponder"
IVAR +488 0 _touchData @
IVAR +496 0 _viewOrientation q
IVAR +504 0 _previousSceneOrientationForCounterRotation q
IVAR +512 0 _exclusiveTouchView @"UIView"
IVAR +520 0 _undoManager @"NSUndoManager"
IVAR +528 0 _sceneTransformLayer @"CALayer"
IVAR +536 0 _transformLayer @"CALayer"
IVAR +544 0 _rootLayer @"CALayer"
IVAR +552 0 _rotationViewControllers @"NSMutableArray"
IVAR +560 0 _rootViewController @"UIViewController"
IVAR +568 0 _subtreeMonitors @"NSMutableSet"
IVAR +576 0 _windowFlags {?="delegateWillRotate"b1"delegateDidRotate"b1"delegateWillAnimateFirstHalf"b1"delegateDidAnimationFirstHalf"b1"delegateWillAnimateSecondHalf"b1"initializationComplete"b1"dontBecomeKeyOnOrderFront"b1"inGesture"b1"autorotates"b1"autorotationRegistered"b1"isRotating"b1"isUsingOnePartRotationAnimation"b1"disableAutorotationCount"b4"needsAutorotationWhenReenabled"b1"forceTwoPartRotationAnimation"b1"orderKeyboardInAfterRotating"b1"roundedCorners"b4"resizesToFullScreen"b1"keepContextInBackground"b1"forceVisibleOnInit"b1"settingFirstResponder"b1"windowResizedToFullScreen"b1"statusBarFollowsOrientation"b1"secure"b1"isSceneSized"b1"didSetRestorationIdentifier"b1"resigningFirstResponderFromHost"b1"needsBoundingPathUpdate"b1"avoidUpdatingSafeAreaInsets"b1"sceneIsWindowScene"b1"needsFramePositionAdjustmentWhenWindowSceneIsAttached"b1"enqueuedDeferredOrientationUpdate"b1"isNotifyingColorTraitChangeForSubtree"b1"needsCleanupOfOrientationTransaction"b1"wantsSuperlayerSecurityAnalysis"b1}
IVAR +584 0 _windowController @
IVAR +592 0 _systemGestureGateForGestures @"_UISystemGestureGateGestureRecognizer"
IVAR +600 0 _systemGestureGateForTouches @"_UISystemGestureGateGestureRecognizer"
IVAR +608 0 _systemGateForGESTouches @"_UIGESGateGestureRecognizer"
IVAR +616 0 _systemGestureGateForHomeAffordance @"_UIHomeAffordanceGateGestureRecognizer"
IVAR +624 0 _traitCollection @"UITraitCollection"
IVAR +632 0 _destinationTraitCollection @"UITraitCollection"
IVAR +640 0 _containedGestureRecognizerMaximumState q
IVAR +648 0 _lastTouchTimestamp d
IVAR +656 0 _systemGesturesArePossible b1
IVAR +664 0 _verticalSizeClassStateRestorationOverride q
IVAR +672 0 _horizontalSizeClassStateRestorationOverride q
IVAR +680 0 _accessibilityHUD @"UIAccessibilityHUDView"
IVAR +688 0 _windowLevelObservers @"NSHashTable"
IVAR +696 0 _roleHint @"NSString"
IVAR +704 0 _interfaceOrientationMapResolver @"<BSInterfaceOrientationMapResolving>"
IVAR +712 0 _lowestLiveResizeSnapshot @"UIView"
IVAR +720 0 _passthroughScrollInteraction @"_UIPassthroughScrollInteraction"
IVAR +728 0 _lastPropagatedStatusBarHeight d
IVAR +736 0 _topSafeAreaInsetScrollPocketInteraction @"_UIScrollPocketInteraction"
IVAR +744 0 _topTapInteraction @"_UIDoubleTapInteraction"
IVAR +752 0 _shouldDisableTransformLayerScalingForSnapshotting B
IVAR +753 0 _wantsResponderWithoutKeyboard B
IVAR +754 0 _suppressFirstResponderWhenUserInteractionDisabled B
IVAR +755 0 _canResizeToFitContent B
IVAR +756 0 __usesLegacySupportedOrientationChecks B
IVAR +757 0 ___hostViewUnderlapsStatusBar B
IVAR +758 0 __containedGestureRecognizersShouldRespectGestureServerInstructions B
IVAR +760 0 _rootPresentationController @"_UIRootPresentationController"
IVAR +768 0 _traitCollectionChangeTransitionCoordinator @"_UIViewControllerNullAnimationTransitionCoordinator"
IVAR +776 0 _deferredOrientationUpdate @"_UIWindowOrientationUpdate"
IVAR +784 0 _windowInternalConstraints @"NSArray"
IVAR +792 0 _rootViewConstraints @"NSArray"
IVAR +800 0 _primaryKeyboardTrackingGuide @"UIKeyboardLayoutGuide"
IVAR +808 0 _currentKeyboardTrackingLayoutGuides @"NSMutableArray"
IVAR +816 0 _scrollPocketCollectorInteraction @"_UIScrollPocketCollectorInteraction"
IVAR +824 0 _windowHostingScene @"UIScene<_UISceneUIWindowHosting>"
IVAR +832 0 _overrideParentTraitEnvironment @"<_UITraitEnvironmentInternal>"
IVAR +840 0 _lastFirstResponder @"UIResponder"
IVAR +848 0 _lastFirstResponderInteractionState @
IVAR +856 0 _lastNextResponder @"UIResponder"
IVAR +864 0 _rememberedFocusedItem @"<UIFocusItem>"
IVAR +872 0 __orientationTransactionToken @"_UIForcedOrientationTransactionToken"
IVAR +880 0 _toWindowOrientation q
IVAR +888 0 _fromWindowOrientation q
IVAR +896 0 __animationController @"_UIWindowAnimationController"
IVAR +904 0 __shouldPreventRotationHook @?
IVAR +912 0 _focusEventRecognizer @"_UIFocusEventRecognizer"
CMETHOD initialize v16@0:8
CMETHOD keyWindow @16@0:8
CMETHOD _isSystemWindow B16@0:8
CMETHOD adjustForAccessibilityIfNeeded: v24@0:8@16
CMETHOD _hitTestToPoint:scenePointZ:forEvent:windowServerHitTestWindow: @56@0:8{CGPoint=dd}16d32@40@48
CMETHOD _pushKeyWindow: v24@0:8@16
CMETHOD _allWindowsKeepContextInBackground B16@0:8
CMETHOD _applicationKeyWindow @16@0:8
CMETHOD _enumerateWindowsIncludingInternalWindows:onlyVisibleWindows:allowMutation:withBlock: v36@0:8B16B20B24@?28
CMETHOD _externalKeyWindow @16@0:8
CMETHOD _findWindowForControllingOverallAppearance @16@0:8
CMETHOD _findWindowForControllingOverallAppearanceInWindowScene: @24@0:8@16
CMETHOD _findWithDisplayPoint: @32@0:8{CGPoint=dd}16
CMETHOD _globalHitTestForLocation:sceneLocationZ:inWindowServerHitTestWindow:withEvent: @56@0:8{CGPoint=dd}16d32@40@48
CMETHOD _isSecure B16@0:8
CMETHOD _needsPassthroughInteraction B16@0:8
CMETHOD _noteStatusBarHeightChanged:oldHeight: v32@0:8d16d24
CMETHOD _popKeyWindow: v24@0:8@16
CMETHOD _preferredStatusBarStyleInWindow:resolvedStyle:withPartStyles:animationProvider: q48@0:8@16^q24^@32^@40
CMETHOD _preferredStatusBarVisibilityForWindow:targetOrientation:animationProvider: i40@0:8@16q24^@32
CMETHOD _prefersStatusBarHiddenInWindow:animationProvider: B32@0:8@16^@24
CMETHOD _removeWindowFromStack: v24@0:8@16
CMETHOD _setAllWindowsKeepContextInBackground: v20@0:8B16
CMETHOD _setTransformLayerRotationsAreEnabled: v20@0:8B16
CMETHOD _shouldSoftAssertOnSetScreen B16@0:8
CMETHOD _synchronizeDrawing v16@0:8
CMETHOD _synchronizeDrawingAcrossProcesses I16@0:8
CMETHOD _synchronizeDrawingAcrossProcessesOverPort: v20@0:8I16
CMETHOD _synchronizeDrawingAcrossProcessesOverPort:withPreCommitHandler: v28@0:8I16@?20
CMETHOD _synchronizeDrawingWithCAFence:preCommitHandler: v32@0:8@16@?24
CMETHOD _synchronizeDrawingWithFence: v24@0:8@16
CMETHOD _synchronizeDrawingWithFence:preCommitHandler: v32@0:8@16@?24
CMETHOD _synchronizeDrawingWithPreCommitHandler: v24@0:8@?16
CMETHOD _synchronizedDrawingFence @16@0:8
CMETHOD _temporary_shouldSizeWindowsAutomaticallyPlistOverrideSet B16@0:8
CMETHOD _topVisibleWindowPassingTest: @24@0:8@?16
CMETHOD _transformLayerRotationsAreEnabled B16@0:8
CMETHOD _unregisterChargedView: v24@0:8@16
CMETHOD _windowWithContextId: @20@0:8I16
CMETHOD adjustFocusForAccessibilityIfNeeded: v24@0:8@16
CMETHOD allWindowsIncludingInternalWindows:onlyVisibleWindows: @24@0:8B16B20
CMETHOD allWindowsIncludingInternalWindows:onlyVisibleWindows:forScreen: @32@0:8B16B20@24
CMETHOD constrainFrameToScreen: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
CMETHOD createIOSurfaceFromDisplayConfiguration: ^v24@0:8@16
CMETHOD createIOSurfaceFromScreen: ^v24@0:8@16
CMETHOD createIOSurfaceOnScreen:withContextIds:count:frame:baseTransform: ^v120@0:8@16r^I24Q32{CGRect={CGPoint=dd}{CGSize=dd}}40{CGAffineTransform=dddddd}72
CMETHOD createIOSurfaceOnScreen:withContextIds:count:frame:usePurpleGfx:outTransform: ^v84@0:8@16r^I24Q32{CGRect={CGPoint=dd}{CGSize=dd}}40B72^{CGAffineTransform=dddddd}76
CMETHOD createIOSurfaceWithContextIds:count:frame: ^v64@0:8r^I16Q24{CGRect={CGPoint=dd}{CGSize=dd}}32
CMETHOD createIOSurfaceWithContextIds:count:frame:outTransform: ^v72@0:8r^I16Q24{CGRect={CGPoint=dd}{CGSize=dd}}32^{CGAffineTransform=dddddd}64
CMETHOD createIOSurfaceWithContextIds:count:frame:usePurpleGfx:outTransform: ^v76@0:8r^I16Q24{CGRect={CGPoint=dd}{CGSize=dd}}32B64^{CGAffineTransform=dddddd}68
CMETHOD createScreenIOSurface ^v16@0:8
CMETHOD layerClass #16@0:8
CMETHOD restrictedSplashboardClasses @16@0:8
CMETHOD setRestrictedSplashboardClasses: v24@0:8@16
CMETHOD setShouldRestrictViewsForSplashboard: v20@0:8B16
CMETHOD shouldRestrictViewsForSplashboard B16@0:8
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD delegate @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD sendEvent: v24@0:8@16
METHOD setDelegate: v24@0:8@16
METHOD setHidden: v20@0:8B16
METHOD level d16@0:8
METHOD screen @16@0:8
METHOD setBounds: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setCenter: v32@0:8{CGPoint=dd}16
METHOD setContentView: v24@0:8@16
METHOD _commonInit v16@0:8
METHOD contentView @16@0:8
METHOD initWithFrame: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD removeFromSuperview v16@0:8
METHOD representation @16@0:8
METHOD setFrame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _addWindowLevelChangedObserver: v24@0:8@16
METHOD _adjustFramePositionIfNecessary v16@0:8
METHOD _appearsInLoupe B16@0:8
METHOD _centerExpressionInContainer:vertical:contentInsetScale:engine: @44@0:8@16B24d28@36
METHOD _constrainsHoverEventHitTesting B16@0:8
METHOD _forceTwoPartRotationAnimation: v20@0:8B16
METHOD _normalizedCornerSafeAreaInsets {_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD _overriddenInterfaceOrientation q16@0:8
METHOD _sceneBoundsInWindowOrientation {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _setWindowInterfaceOrientation: v24@0:8q16
METHOD _willChangeToSize:orientation:screen:withTransitionCoordinator: v56@0:8{CGSize=dd}16q32@40@48
METHOD addKeyboardLayoutGuideIfNeeded: v24@0:8@16
METHOD becomeKeyWindow v16@0:8
METHOD isInterfaceAutorotationDisabled B16@0:8
METHOD setAutorotates: v20@0:8B16
METHOD setWindowLevel: v24@0:8d16
METHOD traitCollection @16@0:8
METHOD __sizeClassPair {?=qq}16@0:8
METHOD _constrainTouchLocationToScene: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _firstResponder @16@0:8
METHOD _focusResponder @16@0:8
METHOD _handleDeviceOrientationChange: v24@0:8@16
METHOD _ignoresHitTest B16@0:8
METHOD _invalidateAuxiliaryChildTraits v16@0:8
METHOD _isLoweringAnchoringConstraints B16@0:8
METHOD _layerForTimeOffsetModification @16@0:8
METHOD _moveWithEvent: v24@0:8@16
METHOD _overrideParentTraitEnvironment @16@0:8
METHOD _screen @16@0:8
METHOD _setRootPresentationController: v24@0:8@16
METHOD _window @16@0:8
METHOD _windowOwnsInterfaceOrientation B16@0:8
METHOD createIOSurface ^v16@0:8
METHOD isUsingOnePartRotationAnimation B16@0:8
METHOD keyboardDidHide v16@0:8
METHOD resignKeyWindow v16@0:8
METHOD setWindowScene: v24@0:8@16
METHOD _StatusBar_fbsScene @16@0:8
METHOD __clientsForRotationCallbacks @16@0:8
METHOD __hostViewUnderlapsStatusBar B16@0:8
METHOD __isKindOfUIWindow B16@0:8
METHOD __isLandmarkView B16@0:8
METHOD __setHostViewUnderlapsStatusBar: v20@0:8B16
METHOD _accessibilityHUDContainerViewForView: @24@0:8@16
METHOD _activityItemsConfigurationForScene @16@0:8
METHOD _addLayoutRuleRegistration: v24@0:8@16
METHOD _addRotationViewController: v24@0:8@16
METHOD _addWindowTopTapRegion v16@0:8
METHOD _adjustSizeClassesAndResizeWindowToFrame: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _adjustWindowOrientationForTransitionWithSupportedOrientations:preferredOrientation:reason: @40@0:8Q16q24@32
METHOD _adjustedWindowLevelFromLevel: d24@0:8d16
METHOD _allowsLinkPreviewInteractionInViewServices B16@0:8
METHOD _allowsOcclusionDetectionOverride B16@0:8
METHOD _alwaysGetsContexts B16@0:8
METHOD _animationController @16@0:8
METHOD _appearanceContainer @16@0:8
METHOD _associatingSceneLayer @16@0:8
METHOD _autolayout_windowDidChangeBoundsFrom: v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _autolayout_windowDidChangeCenterFrom: v32@0:8{CGPoint=dd}16
METHOD _automaticContainerBackgroundIsGlass B16@0:8
METHOD _becomeFirstResponderWhenPossible B16@0:8
METHOD _bindableLevel d16@0:8
METHOD _bindingDescription {?=@BBBBBBBBBB}16@0:8
METHOD _bindingLayer @16@0:8
METHOD _boundContext @16@0:8
METHOD _boundingPath @16@0:8
METHOD _cachedTraitCollectionIsValid B16@0:8
METHOD _canActAsKeyWindowForScreen: B24@0:8@16
METHOD _canAffectStatusBarAppearance B16@0:8
METHOD _canBecomeKeyWindow B16@0:8
METHOD _canBecomeLayoutEngineDelegate B16@0:8
METHOD _canDisableMirroring B16@0:8
METHOD _canIgnoreInteractionEvents B16@0:8
METHOD _canPromoteFromKeyWindowStack B16@0:8
METHOD _canUpdateSceneFocus B16@0:8
METHOD _chargeMultiplicationFactor d16@0:8
METHOD _classicOffset d16@0:8
METHOD _cleanupOrientationTransactionIfNecessary v16@0:8
METHOD _clearPendingKeyboardChanges v16@0:8
METHOD _clearSizeClassesForStateRestoration v16@0:8
METHOD _clientsForRotation @16@0:8
METHOD _clippedSafeAreaCornerInsetsInSuperview: (?={?=CCCCCCCC}Q)24@0:8@16
METHOD _commonInitAttachedWindow:debugName:scene: v36@0:8B16@20@28
METHOD _commonInitDebugName:uiScene: v32@0:8@16@24
METHOD _configureContextOptions: v24@0:8@16
METHOD _configureRootLayer:sceneTransformLayer:transformLayer: v40@0:8@16@24@32
METHOD _constraints_subviewWillChangeSuperview: v24@0:8@16
METHOD _containedGestureRecognizersShouldRespectGestureServerInstructions B16@0:8
METHOD _containedInAbsoluteResponderChain B16@0:8
METHOD _contextBinder @16@0:8
METHOD _contextId I16@0:8
METHOD _contextOptionsWithInitialOptions: @24@0:8@16
METHOD _convertDoublePointFromSceneReferenceSpace: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _convertDoublePointToSceneReferenceSpace: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _convertOffset:fromWindow: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD _convertOffset:toWindow: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD _convertOffsetFromSceneReferenceSpace: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _convertOffsetToSceneReferenceSpace: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _convertPointFromSceneReferenceSpace: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _convertPointToSceneReferenceSpace: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _convertRectFromSceneReferenceSpace: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _convertRectToSceneReferenceSpace: {CGRect={CGPoint=dd}{CGSize=dd}}48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD _convertVisualAltitude:fromWindow: d32@0:8d16@24
METHOD _convertVisualAltitude:toWindow: d32@0:8d16@24
METHOD _createForcedOrientationTransactionTokenWithSupportedOrientations:preferredOrientation:forImmediateCommit:reason: @44@0:8Q16q24B32@36
METHOD _createKeyboardDismissalGestureRecognizer v16@0:8
METHOD _createOtherSystemGateGestureRecognizersIfNeeded v16@0:8
METHOD _createSystemGestureGateGestureRecognizerIfNeeded v16@0:8
METHOD _currentKeyboardTrackingLayoutGuides @16@0:8
METHOD _debugName @16@0:8
METHOD _deepestActionResponder @16@0:8
METHOD _deferredOrientationUpdate @16@0:8
METHOD _definesDynamicTintColor B16@0:8
METHOD _delegateViewController @16@0:8
METHOD _descendantWithAmbiguousLayout @16@0:8
METHOD _didCreateRootPresentationController v16@0:8
METHOD _didMoveFromScene:toScene: v32@0:8@16@24
METHOD _didMoveFromScreen:toScreen: v32@0:8@16@24
METHOD _didSnapshot v16@0:8
METHOD _didUpdateFocusInContext: v24@0:8@16
METHOD _disableAutomaticKeyboardBehavior B16@0:8
METHOD _disableAutomaticKeyboardUI B16@0:8
METHOD _dismissAccessibilityHUD v16@0:8
METHOD _edgeForTouch: Q24@0:8@16
METHOD _edgesForSystemGesturesTouchDelay Q16@0:8
METHOD _eventRoutingScene @16@0:8
METHOD _exclusiveTouchView @16@0:8
METHOD _executeDeferredOrientationUpdate v16@0:8
METHOD _expectedWindowInternalConstraintsCount Q16@0:8
METHOD _extendsScreenSceneLifetime B16@0:8
METHOD _finishedFirstHalfRotation:finished:context: v36@0:8@16B24@28
METHOD _finishedFullRotation:context:skipNotification: v32@0:8B16@20B28
METHOD _finishedFullRotation:finished:context: v40@0:8@16@24@32
METHOD _focusEventRecognizer @16@0:8
METHOD _focusEventRecognizer:didRecognizeFocusMovementRequest: B32@0:8@16@24
METHOD _focusMovementSystemForFocusEventRecognizer: @24@0:8@16
METHOD _focusSystemGesturesForFailureRequirements @16@0:8
METHOD _forwardFocusMovementAction: v24@0:8@16
METHOD _fromWindowOrientation q16@0:8
METHOD _guardSizeTransitionFromAnimations B16@0:8
METHOD _handleSBActiveInterfaceOrientationChange: v24@0:8@16
METHOD _handleStatusBarOrientationChange: v24@0:8@16
METHOD _hasAmbiguousLayout B16@0:8
METHOD _hasContext B16@0:8
METHOD _hasSystemGestureGate B16@0:8
METHOD _hitTestLocation:sceneLocationZ:inScene:withWindowServerHitTestWindow:event: @64@0:8{CGPoint=dd}16d32@40@48@56
METHOD _hostingHandle @16@0:8
METHOD _hostingWindow @16@0:8
METHOD _includeInDefaultImageSnapshot B16@0:8
METHOD _initWithFrame:attached: @52@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16B48
METHOD _initWithFrame:debugName: @56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD _initWithFrame:debugName:attached: @60@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48B56
METHOD _initWithFrame:debugName:displayConfiguration: @64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56
METHOD _initWithFrame:debugName:scene:attached: @68@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56B64
METHOD _initWithFrame:debugName:windowScene: @64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56
METHOD _initWithOrientation: @24@0:8q16
METHOD _initialGuessInterfaceOrientation q16@0:8
METHOD _initializeLayoutEngine v16@0:8
METHOD _initializeLayoutEngineDiscardingOldIfNeeded: v20@0:8B16
METHOD _installFocusEventRecognizer v16@0:8
METHOD _installFocusIfNeededForFocusSystemSceneComponent: v24@0:8@16
METHOD _intelligenceBaseClass #16@0:8
METHOD _interfaceOrientationForSceneSafeAreaInsetsIncludingStatusBar: q20@0:8B16
METHOD _interfaceOrientationForSupportedOrientations:preferredOrientation: q32@0:8Q16q24
METHOD _interfaceOrientationMapResolver @16@0:8
METHOD _invalidateWindowInternalConstraints v16@0:8
METHOD _isAlwaysKeyboardWindow B16@0:8
METHOD _isApplicationKeyWindow B16@0:8
METHOD _isConstrainedByScreenJail B16@0:8
METHOD _isExternallyPlaced B16@0:8
METHOD _isHostedInAnotherProcess B16@0:8
METHOD _isHostingPortalViews B16@0:8
METHOD _isInAWindow B16@0:8
METHOD _isRemoteInputHostWindow B16@0:8
METHOD _isRemoteKeyboardWindow B16@0:8
METHOD _isResigningFirstResponderFromHost B16@0:8
METHOD _isSceneSized B16@0:8
METHOD _isScrollingEnabledForView: B24@0:8@16
METHOD _isSecure B16@0:8
METHOD _isSettingFirstResponder B16@0:8
METHOD _isStatusBarWindow B16@0:8
METHOD _isSystemGestureWindow B16@0:8
METHOD _isTextEffectsWindow B16@0:8
METHOD _isTextEffectsWindowHosting B16@0:8
METHOD _isTextEffectsWindowNotificationOwner B16@0:8
METHOD _isVisible B16@0:8
METHOD _isWindowServerHostingManaged B16@0:8
METHOD _keyboardDismissalGestureRecognized: v24@0:8@16
METHOD _keyboardSceneSettings @16@0:8
METHOD _lastFirstResponder @16@0:8
METHOD _lastFirstResponderInteractionState @16@0:8
METHOD _lastNextResponder @16@0:8
METHOD _layerForCoordinateSpaceConversion @16@0:8
METHOD _layoutEngineCreateIfNecessary @16@0:8
METHOD _layoutEngineIfAvailable @16@0:8
METHOD _legacySetRotatableViewOrientation:duration: v32@0:8q16d24
METHOD _legacySetRotatableViewOrientation:duration:force: v36@0:8q16d24B32
METHOD _legacySetRotatableViewOrientation:updateStatusBar:duration:force: v40@0:8q16B24d28B36
METHOD _mainQueue_makeKeyAndVisible v16@0:8
METHOD _makeExternalKeyWindow v16@0:8
METHOD _managedSafeAreaInsets {UIEdgeInsets=dddd}16@0:8
METHOD _matchDeviceOrientation v16@0:8
METHOD _needsShakesWhenInactive B16@0:8
METHOD _normalInheritedTintColor @16@0:8
METHOD _normalizedSafeAreaInsets {UIEdgeInsets=dddd}16@0:8
METHOD _noteOverlayInsetsDidChange v16@0:8
METHOD _notifyRotatableViewOrientation:duration: v32@0:8q16d24
METHOD _obtainKeyboardLayoutGuideTransitionAssertionForReason: @24@0:8@16
METHOD _orderFrontWithoutMakingKey v16@0:8
METHOD _orientationDebugDescription @16@0:8
METHOD _orientationDebugDescriptionBuilderWithMultilinePrefix: @24@0:8@16
METHOD _orientationDebugDescriptionWithMultilinePrefix: @24@0:8@16
METHOD _orientationForClassicPresentation q16@0:8
METHOD _orientationForRootTransform q16@0:8
METHOD _orientationForSceneTransform q16@0:8
METHOD _orientationForViewTransform q16@0:8
METHOD _orientationInSceneSpace q16@0:8
METHOD _orientationTransactionToken @16@0:8
METHOD _overlayInsets {UIEdgeInsets=dddd}16@0:8
METHOD _overrideTargetWindowForPathIndex:forEvent:windowServerHitTestWindow: @40@0:8Q16@24@32
METHOD _overridingPreferredFocusEnvironment @16@0:8
METHOD _parentGestureRecognizerContainer @16@0:8
METHOD _parentTraitEnvironment @16@0:8
METHOD _parentWillTransitionToTraitCollection: v24@0:8@16
METHOD _performTouchContinuationWithOverrideHitTestedView: v24@0:8@16
METHOD _populateInitialTraitCollection: v24@0:8@16
METHOD _positionHeaderView:andFooterView:outsideContentViewForInterfaceOrientation: v40@0:8@16@24q32
METHOD _preferredInterfaceOrientationForRootViewController q16@0:8
METHOD _prefersFocusContainment B16@0:8
METHOD _prepareHierarchyForWindowHostingSceneRemoval v16@0:8
METHOD _preventsRootPresentationController B16@0:8
METHOD _primaryKeyboardTrackingGuide @16@0:8
METHOD _propagateTraitCollectionChangedForStateRestorationWithTransitionCoordinator: v24@0:8@16
METHOD _recursivePocketDescription @16@0:8
METHOD _redundantConstraints @16@0:8
METHOD _referenceFrameFromSceneUsingScreenBounds: {CGRect={CGPoint=dd}{CGSize=dd}}20@0:8B16
METHOD _registerChargedView: v24@0:8@16
METHOD _registerScrollToTopView: v24@0:8@16
METHOD _registerSubtreeMonitor: v24@0:8@16
METHOD _registeredScrollToTopViews @16@0:8
METHOD _rememberedFocusedItem @16@0:8
METHOD _remoteContentParent @16@0:8
METHOD _removeAllViewControllersFromWindowHierarchyFromDealloc: v20@0:8B16
METHOD _removeFocusEventRecognizer v16@0:8
METHOD _removeFocusIfNeededForFocusSystemSceneComponent: v24@0:8@16
METHOD _removeRotationViewController: v24@0:8@16
METHOD _removeWindowLevelChangedObserver: v24@0:8@16
METHOD _requiresKeyboardPresentationFence B16@0:8
METHOD _resetFocusEventRecognizer v16@0:8
METHOD _resizeWindowFrameToSceneBoundsIfNecessary B16@0:8
METHOD _resizeWindowToFullScreenIfNecessary v16@0:8
METHOD _responderForKeyEvents @16@0:8
METHOD _responderSelectionContainerViewForResponder: @24@0:8@16
METHOD _responderWindow @16@0:8
METHOD _restoreFirstResponder v16@0:8
METHOD _retryHandleStatusBarChangeIfNecessary v16@0:8
METHOD _reversesLinearFocusWrapping B16@0:8
METHOD _roleHint @16@0:8
METHOD _rootForKeyResponderCycle @16@0:8
METHOD _rootPresentationController @16@0:8
METHOD _rootSheetPresentationController @16@0:8
METHOD _rootViewConstraints @16@0:8
METHOD _rootViewConstraintsUpdateIfNecessaryForView: @24@0:8@16
METHOD _rotateToBounds:withAnimator:transitionContext: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56
METHOD _rotateWindowToOrientation:updateStatusBar:duration:skipCallbacks: v40@0:8q16B24d28B36
METHOD _rotationDuration d16@0:8
METHOD _rotationViewControllers @16@0:8
METHOD _safeAreaCornerInsets {_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD _safeAreaInsetsInSuperview: {UIEdgeInsets=dddd}24@0:8@16
METHOD _scene @16@0:8
METHOD _sceneBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _sceneBoundsDidChange v16@0:8
METHOD _sceneClientOrientation q16@0:8
METHOD _sceneOrientation q16@0:8
METHOD _sceneReferenceBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _sceneSafeAreaCornerInsets {_UICornerInsets={CGSize=dd}{CGSize=dd}{CGSize=dd}{CGSize=dd}}16@0:8
METHOD _sceneSafeAreaInsetsIncludingStatusBar: {UIEdgeInsets=dddd}20@0:8B16
METHOD _sceneSettingsSafeAreaCornerInsetsDidChange v16@0:8
METHOD _sceneSettingsSafeAreaInsetsDidChange v16@0:8
METHOD _scrollToTopViewsUnderScreenPointIfNecessary:resultHandler: v40@0:8{CGPoint=dd}16@?32
METHOD _sendButtonsForEvent: v24@0:8@16
METHOD _sendTouchesForEvent: v24@0:8@16
METHOD _setAnimationController: v24@0:8@16
METHOD _setBoundContext: v24@0:8@16
METHOD _setContainedGestureRecognizersShouldRespectGestureServerInstructions: v20@0:8B16
METHOD _setContextBinder: v24@0:8@16
METHOD _setDeferredOrientationUpdate: v24@0:8@16
METHOD _setDelegateViewController: v24@0:8@16
METHOD _setExclusiveTouchView: v24@0:8@16
METHOD _setFirstResponder: v24@0:8@16
METHOD _setFromWindowOrientation: v24@0:8q16
METHOD _setHidden:forced: v24@0:8B16B20
METHOD _setInterfaceOrientationMapResolver: v24@0:8@16
METHOD _setIsLoweringAnchoringConstraints: v20@0:8B16
METHOD _setIsResigningFirstResponderFromHost: v20@0:8B16
METHOD _setIsSettingFirstResponder: v20@0:8B16
METHOD _setLastFirstResponder: v24@0:8@16
METHOD _setLastFirstResponderInteractionState: v24@0:8@16
METHOD _setLastNextResponder: v24@0:8@16
METHOD _setNeedsBoundingPathUpdate v16@0:8
METHOD _setOrientationTransactionToken: v24@0:8@16
METHOD _setOverrideParentTraitEnvironment: v24@0:8@16
METHOD _setRememberedFocusedItem: v24@0:8@16
METHOD _setRoleHint: v24@0:8@16
METHOD _setRootViewConstraints: v24@0:8@16
METHOD _setRotatableClient:toOrientation:updateStatusBar:duration:force:isRotating: v52@0:8@16q24B32d36B44B48
METHOD _setRotatableViewOrientation:duration: v32@0:8q16d24
METHOD _setRotatableViewOrientation:duration:force: v36@0:8q16d24B32
METHOD _setRotatableViewOrientation:updateStatusBar:duration:force: v40@0:8q16B24d28B36
METHOD _setScene: v24@0:8@16
METHOD _setSecure: v20@0:8B16
METHOD _setShouldDisableTransformLayerScalingForSnapshotting: v20@0:8B16
METHOD _setShouldPreventRotationHook: v24@0:8@?16
METHOD _setStateRestorationVerticalSizeClass:horizontalSizeClass: v32@0:8q16q24
METHOD _setSuppressFirstResponderWhenUserInteractionDisabled: v20@0:8B16
METHOD _setSystemGestureRecognitionIsPossible:andTouchesAreCancelled: v24@0:8B16B20
METHOD _setToWindowOrientation: v24@0:8q16
METHOD _setTraitCollectionChangeTransitionCoordinator: v24@0:8@16
METHOD _setWantsResponderWithoutKeyboard: v20@0:8B16
METHOD _setWantsSuperlayerSecurityAnalysis: v20@0:8B16
METHOD _setWindowControlsStatusBarOrientation: v20@0:8B16
METHOD _setWindowHostingScene: v24@0:8@16
METHOD _setWindowInternalConstraints: v24@0:8@16
METHOD _shouldAdjustSizeClassesAndResizeWindow B16@0:8
METHOD _shouldAutorotateToInterfaceOrientation: B24@0:8q16
METHOD _shouldAutorotateToInterfaceOrientation:checkForDismissal:isRotationDisabled: B36@0:8q16B24^B28
METHOD _shouldControlAutorotation B16@0:8
METHOD _shouldCreateContextAsSecure B16@0:8
METHOD _shouldDelayTouchForSystemGestures: B24@0:8@16
METHOD _shouldDisableTransformLayerScalingForSnapshotting B16@0:8
METHOD _shouldForceTraitPropagationThroughHierarchy B16@0:8
METHOD _shouldInstallRootPresentationController B16@0:8
METHOD _shouldPrepareScreenForWindow B16@0:8
METHOD _shouldPreventRotationHook @?16@0:8
METHOD _shouldPropagateTraitCollectionChanges B16@0:8
METHOD _shouldRecognizeEventsInFocusEventRecognizer: B24@0:8@16
METHOD _shouldResizeWithScene B16@0:8
METHOD _shouldTextEffectsWindowBeHostedForView: B24@0:8@16
METHOD _shouldUseRemoteContext B16@0:8
METHOD _showAccessibilityHUDItem:forView: v32@0:8@16@24
METHOD _slideHeaderView:andFooterView:offScreen:forInterfaceOrientation: v44@0:8@16@24B32q36
METHOD _subclassPreferredFocusedViewPrioritizationType q16@0:8
METHOD _subtreeMonitorsForView: @24@0:8@16
METHOD _supportedInterfaceOrientationsConsultingApp: Q20@0:8B16
METHOD _supportedInterfaceOrientationsForRootViewController Q16@0:8
METHOD _supportsBecomeFirstResponderWhenPossible B16@0:8
METHOD _supportsFocus B16@0:8
METHOD _suppressFirstResponderWhenUserInteractionDisabled B16@0:8
METHOD _switchToLayoutEngine: v24@0:8@16
METHOD _systemGestureRecognitionIsPossible B16@0:8
METHOD _systemReferenceAngle d16@0:8
METHOD _systemReferenceAngleMode Q16@0:8
METHOD _targetForStolenStatusBarTouchesAtPoint:withEvent:excludingWindow: @48@0:8{CGPoint=dd}16@32@40
METHOD _targetWindowForPathIndex:atPoint:scenePointZ:forEvent:windowServerHitTestWindow: @64@0:8q16{CGPoint=dd}24d40@48@56
METHOD _tintColorDidChange v16@0:8
METHOD _toWindowOrientation q16@0:8
METHOD _touchData @16@0:8
METHOD _touchSloppinessFactor d16@0:8
METHOD _traitCollectionChangeTransitionCoordinator @16@0:8
METHOD _traitCollectionForSize:parentCollection: @40@0:8{CGSize=dd}16@32
METHOD _traitCollectionForSize:parentCollection:traitOverrideApplicator: @48@0:8{CGSize=dd}16@32@?40
METHOD _traitCollectionWhenRotated @16@0:8
METHOD _traitOverridesDidChange v16@0:8
METHOD _traitOverridesWillChange:withApplicator: v32@0:8@16@?24
METHOD _transformDisplayToWindowCoordinates: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD _transformLayerIncludesScreenRotation B16@0:8
METHOD _transformLayerShouldMaskToBounds: v20@0:8B16
METHOD _uiWindowSceneFromFBSScene: @24@0:8@16
METHOD _uiib_candidateRedundantConstraints @16@0:8
METHOD _uiib_invalidateWindowInternalConstraints v16@0:8
METHOD _uiib_layoutEngineCreatingIfNecessary @16@0:8
METHOD _undoManagerForValidatingUndoRedoCommands @16@0:8
METHOD _unregisterChargedView: v24@0:8@16
METHOD _unregisterScrollToTopView: v24@0:8@16
METHOD _unregisterSubtreeMonitor: v24@0:8@16
METHOD _updateAutorotationResponse: v20@0:8B16
METHOD _updateAuxiliaryChildTraitsIfNeeded v16@0:8
METHOD _updateConstraintsIfNeededWithViewForVariableChangeNotifications: v24@0:8@16
METHOD _updateInterfaceOrientationFromActiveInterfaceOrientation v16@0:8
METHOD _updateInterfaceOrientationFromActiveInterfaceOrientation: v20@0:8B16
METHOD _updateInterfaceOrientationFromActiveInterfaceOrientationIfRotationEnabled: v20@0:8B16
METHOD _updateInterfaceOrientationFromDeviceOrientation v16@0:8
METHOD _updateInterfaceOrientationFromDeviceOrientation: v20@0:8B16
METHOD _updateInterfaceOrientationFromDeviceOrientationIfRotationEnabled: v20@0:8B16
METHOD _updateIsSceneSizedFlag v16@0:8
METHOD _updateLayerOrderingAndSetLayerHidden: v20@0:8B16
METHOD _updateLayerOrderingAndSetLayerHidden:actionBlock: v28@0:8B16@?20
METHOD _updateOrientationPreferencesAnimated: v20@0:8B16
METHOD _updateRootViewConstraintsForInterfaceOrientationAndStatusBarHeight v16@0:8
METHOD _updateSystemConstraints v16@0:8
METHOD _updateToInterfaceOrientation:animated: v28@0:8q16B24
METHOD _updateToInterfaceOrientation:duration:force: v36@0:8q16d24B32
METHOD _updateToNotificationProvidedInterfaceOrientation:animated: v28@0:8q16B24
METHOD _updateTransformLayer v16@0:8
METHOD _updateWindowEngineHostConstraintsWithSizing: v20@0:8B16
METHOD _updateWindowTraits v16@0:8
METHOD _updateWindowTraitsAndNotify: v20@0:8B16
METHOD _updatesSafeAreaInsetsOnRead B16@0:8
METHOD _usableBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _usableSceneBounds {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _usesLegacySupportedOrientationChecks B16@0:8
METHOD _usesWindowServerHitTesting B16@0:8
METHOD _viewTransformForInterfaceOrientation: {CGAffineTransform=dddddd}24@0:8q16
METHOD _wantsFocusEngine B16@0:8
METHOD _wantsResponderWithoutKeyboard B16@0:8
METHOD _wantsSceneAssociation B16@0:8
METHOD _wantsSuperlayerSecurityAnalysis B16@0:8
METHOD _willSnapshot v16@0:8
METHOD _willTransitionToTraitCollection:withTransitionCoordinator: v32@0:8@16@24
METHOD _willUpdateFocusInContext: v24@0:8@16
METHOD _windowCanDynamicallySpecifySupportedInterfaceOrientations B16@0:8
METHOD _windowControlsStatusBarOrientation B16@0:8
METHOD _windowHostingScene @16@0:8
METHOD _windowHostingSceneTraitCollection @16@0:8
METHOD _windowInterfaceOrientation q16@0:8
METHOD _windowInternalConstraints @16@0:8
METHOD _windowInternalConstraints_centerDidChange v16@0:8
METHOD _windowInternalConstraints_sizeDidChange v16@0:8
METHOD _windowOwnsInterfaceOrientationTransform B16@0:8
METHOD _writeLayerTreeToPath: v24@0:8@16
METHOD addRootViewControllerViewIfPossible v16@0:8
METHOD autorotates B16@0:8
METHOD awakeFromNib v16@0:8
METHOD becomeFirstResponder B16@0:8
METHOD beginDisablingInterfaceAutorotation v16@0:8
METHOD bitsPerComponent i16@0:8
METHOD canBecomeKeyWindow B16@0:8
METHOD canPerformAction:withSender: B32@0:8:16@24
METHOD canResizeToFitContent B16@0:8
METHOD cancelOrientationTransaction: v24@0:8@16
METHOD commitOrientationTransaction:animated: v28@0:8@16B24
METHOD convertDeviceToWindow: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD convertPoint:fromWindow: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD convertPoint:toWindow: {CGPoint=dd}40@0:8{CGPoint=dd}16@32
METHOD convertRect:fromCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:fromWindow: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:toCoordinateSpace: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertRect:toWindow: {CGRect={CGPoint=dd}{CGSize=dd}}56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD convertWindowToDevice: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD createIOSurfaceWithFrame: ^v48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD endDisablingInterfaceAutorotation v16@0:8
METHOD endDisablingInterfaceAutorotationAnimated: v20@0:8B16
METHOD exerciseAmbiguityInLayout v16@0:8
METHOD firstResponder @16@0:8
METHOD handleStatusBarChangeFromHeight:toHeight: v32@0:8d16d24
METHOD hasAmbiguousLayout B16@0:8
METHOD inhibitManualTransform B16@0:8
METHOD inhibitSetupOrientation B16@0:8
METHOD inhibitTextEffectsRotation B16@0:8
METHOD initWithContentRect: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD initWithWindowScene: @24@0:8@16
METHOD insetForDismissedKeyboardGuide d16@0:8
METHOD interfaceOrientation q16@0:8
METHOD isElementAccessibilityExposedToInterfaceBuilder B16@0:8
METHOD isInternalWindow B16@0:8
METHOD isKeyWindow B16@0:8
METHOD isRotating B16@0:8
METHOD isTrackingKeyboard B16@0:8
METHOD isTransparentFocusItem B16@0:8
METHOD keepContextInBackground B16@0:8
METHOD keyboardLayoutGuideScrollViewOffset d16@0:8
METHOD layoutSubviews v16@0:8
METHOD layoutViewsForTrackedGuides v16@0:8
METHOD makeKey: v24@0:8@16
METHOD makeKeyAndOrderFront: v24@0:8@16
METHOD makeKeyAndVisible v16@0:8
METHOD makeKeyWindow v16@0:8
METHOD matchDeviceOrientation: v24@0:8@16
METHOD moveKeyboardLayoutGuideOverEdge:layoutViews: B28@0:8Q16B24
METHOD nextResponder @16@0:8
METHOD orderFront: v24@0:8@16
METHOD orderOut: v24@0:8@16
METHOD parentFocusEnvironment @16@0:8
METHOD passthroughScrollInteraction:shouldInteractAtLocation:withEvent: B48@0:8@16{CGPoint=dd}24@40
METHOD passthroughScrollInteractionDidRecognize:atLocation: B40@0:8@16{CGPoint=dd}24
METHOD preferredFocusEnvironments @16@0:8
METHOD preferredFocusedView @16@0:8
METHOD redo: v24@0:8@16
METHOD removeKeyboardLayoutGuideIfNeeded: v24@0:8@16
METHOD resizesToFullScreen B16@0:8
METHOD restorationIdentifier @16@0:8
METHOD rootViewController @16@0:8
METHOD safeAreaAspectFitLayoutGuide @16@0:8
METHOD safeAreaInsets {UIEdgeInsets=dddd}16@0:8
METHOD setAutorotates:forceUpdateInterfaceOrientation: v24@0:8B16B20
METHOD setBecomeKeyOnOrderFront: v20@0:8B16
METHOD setCanResizeToFitContent: v20@0:8B16
METHOD setKeepContextInBackground: v20@0:8B16
METHOD setLevel: v24@0:8d16
METHOD setResizesToFullScreen: v20@0:8B16
METHOD setRestorationIdentifier: v24@0:8@16
METHOD setRootViewController: v24@0:8@16
METHOD setScreen: v24@0:8@16
METHOD set_currentKeyboardTrackingLayoutGuides: v24@0:8@16
METHOD setupForOrientation: v24@0:8q16
METHOD traitCollectionDidChange: v24@0:8@16
METHOD undo: v24@0:8@16
METHOD undoManager @16@0:8
METHOD updateGuideForKeyboardPlacement: v24@0:8@16
METHOD warpPoint: {CGPoint=dd}32@0:8{CGPoint=dd}16
METHOD windowLevel d16@0:8
METHOD windowScene @16@0:8

=== CLASS VFXAnimation ===
SUPER: NSObject
SIZE: 136
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable VFXAnimation NSCopying NSSecureCoding
IVAR +8 0 _animationRef ^{__CFXAnimation=}
IVAR +16 0 _keyPath @"NSString"
IVAR +24 0 _duration d
IVAR +32 0 _repeatCount f
IVAR +40 0 _timeOffset d
IVAR +48 0 _beginTime d
IVAR +56 0 _autoreverses B
IVAR +57 0 _removedOnCompletion B
IVAR +58 0 _applyOnCompletion B
IVAR +59 0 _additive B
IVAR +60 0 _cumulative B
IVAR +61 0 _fillForward B
IVAR +62 0 _fillBackward B
IVAR +64 0 _timingFunction @"VFXTimingFunction"
IVAR +72 0 _animationEvents @"NSArray"
IVAR +80 0 _animationDidStart @?
IVAR +88 0 _animationDidStop @?
IVAR +96 0 _userInfo @"NSMutableDictionary"
IVAR +104 0 _userInfoLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +112 0 _caAnimationCache @
IVAR +120 0 _userAnimation @
IVAR +128 0 _didMutate B
CMETHOD supportsSecureCoding B16@0:8
CMETHOD animationNamed: @24@0:8@16
CMETHOD animationWithCAAnimation: @24@0:8@16
CMETHOD animationWithContentsOfURL: @24@0:8@16
CMETHOD animationWithMDLTransform: @24@0:8@16
CMETHOD componentCountAtKeyPath:target: q32@0:8@16@24
CMETHOD animationFromWorld: @24@0:8@16
CMETHOD animationWithCFXAnimation: @24@0:8^{__CFXAnimation=}16
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD keyPath @16@0:8
METHOD duration d16@0:8
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD valueForUndefinedKey: @24@0:8@16
METHOD setDuration: v24@0:8d16
METHOD beginTime d16@0:8
METHOD setBeginTime: v24@0:8d16
METHOD setTimingFunction: v24@0:8@16
METHOD timingFunction @16@0:8
METHOD setRepeatCount: v20@0:8f16
METHOD autoreverses B16@0:8
METHOD isAdditive B16@0:8
METHOD repeatCount f16@0:8
METHOD setAdditive: v20@0:8B16
METHOD setAutoreverses: v20@0:8B16
METHOD setKeyPath: v24@0:8@16
METHOD setRemovedOnCompletion: v20@0:8B16
METHOD setTimeOffset: v24@0:8d16
METHOD subAnimations @16@0:8
METHOD timeOffset d16@0:8
METHOD isCumulative B16@0:8
METHOD isRemovedOnCompletion B16@0:8
METHOD repeatDuration f16@0:8
METHOD setCumulative: v20@0:8B16
METHOD setRepeatDuration: v20@0:8f16
METHOD _didMutate v16@0:8
METHOD animationEvents @16@0:8
METHOD blendInDuration d16@0:8
METHOD __CFObject ^v16@0:8
METHOD _optimizeKeyframesWithTarget: v24@0:8@16
METHOD _setAnimationRef: v24@0:8^{__CFXAnimation=}16
METHOD animationDidStart @?16@0:8
METHOD animationDidStop @?16@0:8
METHOD animationRef ^{__CFXAnimation=}16@0:8
METHOD blendOutDuration d16@0:8
METHOD caAnimation @16@0:8
METHOD fillsBackward B16@0:8
METHOD fillsForward B16@0:8
METHOD initWithCAAnimation: @24@0:8@16
METHOD isAppliedOnCompletion B16@0:8
METHOD prepareWithTarget:implicitDuration: v32@0:8@16d24
METHOD setAnimationDidStart: v24@0:8@?16
METHOD setAnimationDidStop: v24@0:8@?16
METHOD setAnimationEvents: v24@0:8@16
METHOD setAppliedOnCompletion: v20@0:8B16
METHOD setBlendInDuration: v24@0:8d16
METHOD setBlendOutDuration: v24@0:8d16
METHOD setFillsBackward: v20@0:8B16
METHOD setFillsForward: v20@0:8B16
METHOD userAnimation @16@0:8
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD decodeAnimation: @24@0:8@16
METHOD encodeAnimation: @24@0:8@16
METHOD initWithCFXAnimation: @24@0:8^{__CFXAnimation=}16

=== CLASS VFXAnimationEvent ===
SUPER: NSObject
SIZE: 24
IVAR +8 0 _eventTime d
IVAR +16 0 _eventBlock @?
CMETHOD animationEventWithKeyTime:block: @28@0:8f16@?20
METHOD dealloc v16@0:8
METHOD init @16@0:8
METHOD setTime: v24@0:8d16
METHOD time d16@0:8
METHOD eventBlock @?16@0:8
METHOD setEventBlock: v24@0:8@?16

=== CLASS VFXAnimationPlayer ===
SUPER: NSObject
SIZE: 96
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable VFXAnimatable NSCopying NSSecureCoding
IVAR +8 0 _world @"VFXWorld"
IVAR +16 0 _worldReferenceCounter I
IVAR +20 0 _isPresentationObject b1
IVAR +24 0 _playerRef ^{__CFXAnimationPlayer=}
IVAR +32 0 _animation @"VFXAnimation"
IVAR +40 0 _weight f
IVAR +44 0 _speed f
IVAR +48 0 _paused B
IVAR +56 0 _timeSource Q
IVAR +64 0 _timeOrigin Q
IVAR +72 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +80 0 _animations @"VFXOrderedDictionary"
IVAR +88 0 _bindings @"NSMutableDictionary"
CMETHOD supportsSecureCoding B16@0:8
CMETHOD animationPlayerWithAnimation: @24@0:8@16
CMETHOD animationPlayerWithAnimationPlayerRef: @24@0:8^{__CFXAnimationPlayer=}16
CMETHOD animationPlayerWithVFXAnimation: @24@0:8@16
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD stop v16@0:8
METHOD setWeight: v20@0:8f16
METHOD weight f16@0:8
METHOD commonInit v16@0:8
METHOD animation @16@0:8
METHOD setSpeed: v20@0:8f16
METHOD speed f16@0:8
METHOD paused B16@0:8
METHOD setPaused: v20@0:8B16
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationKeys @16@0:8
METHOD play v16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD setBlendFactor: v20@0:8f16
METHOD blendFactor f16@0:8
METHOD world @16@0:8
METHOD _setAnimation: v24@0:8@16
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD __CFObject ^v16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _syncObjCAnimations v16@0:8
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__CFXAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD animationPlayerRef ^{__CFXAnimationPlayer=}16@0:8
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD initWithAnimationPlayerRef: @24@0:8^{__CFXAnimationPlayer=}16
METHOD prepareWithTarget:implicitDuration: v32@0:8@16d24
METHOD removeAllAnimationsWithBlendOutDuration: v20@0:8f16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v28@0:8@16f24
METHOD stopWithBlendOutDuration: v24@0:8d16
METHOD unbindAnimatablePath: v24@0:8@16
METHOD setWorld: v24@0:8@16
METHOD _vfxDeprecatedAddAnimation:forKey: v32@0:8@16@24
METHOD timeSource Q16@0:8
METHOD presentationObject @16@0:8
METHOD setTimeOrigin: v24@0:8Q16
METHOD setTimeSource: v24@0:8Q16
METHOD _copyBindingsFrom: v24@0:8@16
METHOD _setSourceObject:forBinding: v32@0:8@16@24
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD _vfxAnimationForKey: @24@0:8@16
METHOD _vfxBindings @16@0:8
METHOD addWorldReference: v24@0:8@16
METHOD enumerateAnimationReferencesUsingBlock: v24@0:8@?16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD initWithVFXAnimation: @24@0:8@16
METHOD removeWorldReference: v24@0:8@16
METHOD setUsesAbsoluteTime: v20@0:8B16
METHOD timeOrigin Q16@0:8
METHOD usesAbsoluteTime B16@0:8
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXCamera ===
SUPER: NSObject
SIZE: 312
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable VFXCopyingRemappable VFXAnimatable NSCopying NSSecureCoding
IVAR +8 0 _camera ^{__CFXCamera={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}{?=b1b1b1b3ffff{?=[4]}{?=[4]}}fff^{__CFXCameraEffectDepthOfField}^{__CFXCameraEffectMotionBlur}^{__CFXCameraEffectGrain}^{__CFXCameraEffectExposure}^{__CFXCameraEffectToneMapping}^{__CFXCameraEffectBloom}^{__CFXCameraEffectVignetting}^{__CFXCameraEffectLensBlur}^{__CFXCameraEffectColorFringe}^{__CFXCameraEffectColorGrading}^{__CFXCameraEffectChromaticTransform}^{__CFXCameraEffectDoughnutBokeh}^{__CFXCameraEffectSSAO}b1b1b1b1{?=[4]}Q}
IVAR +16 0 _world @"VFXWorld"
IVAR +24 0 _worldReferenceCounter I
IVAR +28 0 _isPresentationObject b1
IVAR +28 0 _custom b1
IVAR +28 0 _usesOrthographicProjection b1
IVAR +28 0 _automaticallyAdjustsZRange b1
IVAR +28 0 _fillMode b3
IVAR +32 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +40 0 _animations @"VFXOrderedDictionary"
IVAR +48 0 _bindings @"NSMutableDictionary"
IVAR +56 0 _name @"NSString"
IVAR +64 0 _orthographicScale f
IVAR +72 0 _zNear d
IVAR +80 0 _zFar d
IVAR +88 0 _fieldOfView f
IVAR +92 0 _focalLength f
IVAR +96 0 _sensorSize f
IVAR +104 0 _filmOffset 
IVAR +112 0 _postProjectionTransformTranslation 
IVAR +120 0 _postProjectionTransformScale 
IVAR +128 0 _focusDistance f
IVAR +136 0 _categoryBitMask Q
IVAR +144 0 _projectionTransform {?="columns"[4]}
IVAR +208 0 _depthOfField @"VFXCameraEffectDepthOfField"
IVAR +216 0 _motionBlur @"VFXCameraEffectMotionBlur"
IVAR +224 0 _grain @"VFXCameraEffectGrain"
IVAR +232 0 _exposure @"VFXCameraEffectExposure"
IVAR +240 0 _toneMapping @"VFXCameraEffectToneMapping"
IVAR +248 0 _bloom @"VFXCameraEffectBloom"
IVAR +256 0 _colorGrading @"VFXCameraEffectColorGrading"
IVAR +264 0 _colorFringe @"VFXCameraEffectColorFringe"
IVAR +272 0 _vignetting @"VFXCameraEffectVignetting"
IVAR +280 0 _lensBlur @"VFXCameraEffectLensBlur"
IVAR +288 0 _chromaticTransform @"VFXCameraEffectChromaticTransform"
IVAR +296 0 _doughnutBokeh @"VFXCameraEffectDoughnutBokeh"
IVAR +304 0 _wantsHDR B
CMETHOD supportsSecureCoding B16@0:8
CMETHOD camera @16@0:8
CMETHOD cameraWithCameraRef: @24@0:8^{__CFXCamera={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}{?=b1b1b1b3ffff{?=[4]}{?=[4]}}fff^{__CFXCameraEffectDepthOfField}^{__CFXCameraEffectMotionBlur}^{__CFXCameraEffectGrain}^{__CFXCameraEffectExposure}^{__CFXCameraEffectToneMapping}^{__CFXCameraEffectBloom}^{__CFXCameraEffectVignetting}^{__CFXCameraEffectLensBlur}^{__CFXCameraEffectColorFringe}^{__CFXCameraEffectColorGrading}^{__CFXCameraEffectChromaticTransform}^{__CFXCameraEffectDoughnutBokeh}^{__CFXCameraEffectSSAO}b1b1b1b1{?=[4]}Q}16
CMETHOD cameraWithMDLCamera: @24@0:8@16
CMETHOD keyPathsForValuesAffectingFieldOfView @16@0:8
CMETHOD keyPathsForValuesAffectingFocalLength @16@0:8
CMETHOD presentationCameraWithCameraRef: @24@0:8^{__CFXCamera={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}{?=b1b1b1b3ffff{?=[4]}{?=[4]}}fff^{__CFXCameraEffectDepthOfField}^{__CFXCameraEffectMotionBlur}^{__CFXCameraEffectGrain}^{__CFXCameraEffectExposure}^{__CFXCameraEffectToneMapping}^{__CFXCameraEffectBloom}^{__CFXCameraEffectVignetting}^{__CFXCameraEffectLensBlur}^{__CFXCameraEffectColorFringe}^{__CFXCameraEffectColorGrading}^{__CFXCameraEffectChromaticTransform}^{__CFXCameraEffectDoughnutBokeh}^{__CFXCameraEffectSSAO}b1b1b1b1{?=[4]}Q}16
METHOD _implementCEKWorkaroundIfNeeded v16@0:8
METHOD avt_setSimdProjectionTransform: v80@0:8{?=[4]}16
METHOD avt_simdPostProjectionTransform {?=[3]}16@0:8
METHOD avt_setSimdPostProjectionTransform: v64@0:8{?=[3]}16
METHOD avt_simdProjectionTransform {?=[4]}16@0:8
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD setName: v24@0:8@16
METHOD setValue:forKey: v32@0:8@16@24
METHOD valueForKey: @24@0:8@16
METHOD valueForKeyPath: @24@0:8@16
METHOD setIdentifier: v24@0:8@16
METHOD setFocalLength: v20@0:8f16
METHOD debugQuickLookObject @16@0:8
METHOD exposure @16@0:8
METHOD focalLength f16@0:8
METHOD setExposure: v24@0:8@16
METHOD categoryBitMask Q16@0:8
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationKeys @16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD setCategoryBitMask: v24@0:8Q16
METHOD setFillMode: v24@0:8q16
METHOD fillMode q16@0:8
METHOD world @16@0:8
METHOD _registerAsObserver v16@0:8
METHOD setFieldOfView: v20@0:8f16
METHOD fieldOfView f16@0:8
METHOD focusDistance f16@0:8
METHOD setFocusDistance: v20@0:8f16
METHOD setZFar: v20@0:8f16
METHOD setZNear: v20@0:8f16
METHOD zFar f16@0:8
METHOD zNear f16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD __CFObject ^v16@0:8
METHOD _checkSettingsConsistency v16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _syncObjCAnimations v16@0:8
METHOD _updateFieldOfView v16@0:8
METHOD _updateFocalLength v16@0:8
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__CFXAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD automaticallyAdjustsZRange B16@0:8
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD cameraRef ^{__CFXCamera={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}{?=b1b1b1b3ffff{?=[4]}{?=[4]}}fff^{__CFXCameraEffectDepthOfField}^{__CFXCameraEffectMotionBlur}^{__CFXCameraEffectGrain}^{__CFXCameraEffectExposure}^{__CFXCameraEffectToneMapping}^{__CFXCameraEffectBloom}^{__CFXCameraEffectVignetting}^{__CFXCameraEffectLensBlur}^{__CFXCameraEffectColorFringe}^{__CFXCameraEffectColorGrading}^{__CFXCameraEffectChromaticTransform}^{__CFXCameraEffectDoughnutBokeh}^{__CFXCameraEffectSSAO}b1b1b1b1{?=[4]}Q}16@0:8
METHOD colorGrading @16@0:8
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD debugQuickLookData @16@0:8
METHOD hasCustomProjectionTransform B16@0:8
METHOD initPresentationCameraWithCameraRef: @24@0:8^{__CFXCamera={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}{?=b1b1b1b3ffff{?=[4]}{?=[4]}}fff^{__CFXCameraEffectDepthOfField}^{__CFXCameraEffectMotionBlur}^{__CFXCameraEffectGrain}^{__CFXCameraEffectExposure}^{__CFXCameraEffectToneMapping}^{__CFXCameraEffectBloom}^{__CFXCameraEffectVignetting}^{__CFXCameraEffectLensBlur}^{__CFXCameraEffectColorFringe}^{__CFXCameraEffectColorGrading}^{__CFXCameraEffectChromaticTransform}^{__CFXCameraEffectDoughnutBokeh}^{__CFXCameraEffectSSAO}b1b1b1b1{?=[4]}Q}16
METHOD initWithCameraRef: @24@0:8^{__CFXCamera={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}{?=b1b1b1b3ffff{?=[4]}{?=[4]}}fff^{__CFXCameraEffectDepthOfField}^{__CFXCameraEffectMotionBlur}^{__CFXCameraEffectGrain}^{__CFXCameraEffectExposure}^{__CFXCameraEffectToneMapping}^{__CFXCameraEffectBloom}^{__CFXCameraEffectVignetting}^{__CFXCameraEffectLensBlur}^{__CFXCameraEffectColorFringe}^{__CFXCameraEffectColorGrading}^{__CFXCameraEffectChromaticTransform}^{__CFXCameraEffectDoughnutBokeh}^{__CFXCameraEffectSSAO}b1b1b1b1{?=[4]}Q}16
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD orthographicScale f16@0:8
METHOD postProjectionTransform {CGAffineTransform=dddddd}16@0:8
METHOD presentationCamera @16@0:8
METHOD projectionDirection q16@0:8
METHOD projectionTransform {?=[4]}16@0:8
METHOD projectionTransformWithViewportSize: {?=[4]}32@0:8{CGSize=dd}16
METHOD removeAllAnimationsWithBlendOutDuration: v20@0:8f16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v28@0:8@16f24
METHOD sensorHeight f16@0:8
METHOD setAutomaticallyAdjustsZRange: v20@0:8B16
METHOD setOrthographicScale: v20@0:8f16
METHOD setPostProjectionTransform: v64@0:8{CGAffineTransform=dddddd}16
METHOD setPostProjectionTransformScale: v24@0:816
METHOD setPostProjectionTransformTranslation: v24@0:816
METHOD setProjectionDirection: v24@0:8q16
METHOD setProjectionTransform: v80@0:8{?=[4]}16
METHOD setSensorHeight: v20@0:8f16
METHOD setUsesOrthographicProjection: v20@0:8B16
METHOD setWantsHDR: v20@0:8B16
METHOD unbindAnimatablePath: v24@0:8@16
METHOD usesOrthographicProjection B16@0:8
METHOD wantsHDR B16@0:8
METHOD setWorld: v24@0:8@16
METHOD _vfxDeprecatedAddAnimation:forKey: v32@0:8@16@24
METHOD bloom @16@0:8
METHOD chromaticTransform @16@0:8
METHOD lensBlur @16@0:8
METHOD presentationObject @16@0:8
METHOD setFilmOffset: v24@0:816
METHOD grain @16@0:8
METHOD setGrain: v24@0:8@16
METHOD setColorFringe: v24@0:8@16
METHOD setToneMapping: v24@0:8@16
METHOD _copyBindingsFrom: v24@0:8@16
METHOD _customEncodingOfVFXCamera: v24@0:8@16
METHOD _didDecodeVFXCamera: v24@0:8@16
METHOD _setSourceObject:forBinding: v32@0:8@16@24
METHOD _updateEntityModelFromPresentation v16@0:8
METHOD _updateEntityPresentationFromModel v16@0:8
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD _valueForSimdVectorKeyPath: @24@0:8@16
METHOD _vfxAnimationForKey: @24@0:8@16
METHOD _vfxBindings @16@0:8
METHOD addWorldReference: v24@0:8@16
METHOD colorFringe @16@0:8
METHOD copyTo:withContext: v32@0:8@16@24
METHOD depthOfField @16@0:8
METHOD doughnutBokeh @16@0:8
METHOD enumerateAnimationReferencesUsingBlock: v24@0:8@?16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD filmOffset 16@0:8
METHOD isPresentationObject B16@0:8
METHOD makeUniqueID v16@0:8
METHOD motionBlur @16@0:8
METHOD projectionTransformValue @16@0:8
METHOD rawFloat2ForKey:value: B32@0:8@16^24
METHOD removeWorldReference: v24@0:8@16
METHOD setBloom: v24@0:8@16
METHOD setChromaticTransform: v24@0:8@16
METHOD setColorGrading: v24@0:8@16
METHOD setDepthOfField: v24@0:8@16
METHOD setDoughnutBokeh: v24@0:8@16
METHOD setLensBlur: v24@0:8@16
METHOD setMotionBlur: v24@0:8@16
METHOD setProjectionTransformValue: v24@0:8@16
METHOD setVignetting: v24@0:8@16
METHOD toneMapping @16@0:8
METHOD vignetting @16@0:8
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXCamera_CEKWorkaround ===
SUPER: VFXCamera
SIZE: 312
METHOD setFocalLength: v24@0:8d16
METHOD focalLength d16@0:8
METHOD sensorHeight d16@0:8
METHOD setSensorHeight: v24@0:8d16

=== CLASS VFXKeyedArchiver ===
SUPER: NSKeyedArchiver
SIZE: 144
IVAR +128 0 skipMorphTargets B
IVAR +136 0 options @"NSDictionary"
CMETHOD archivedDataWithRootObject:options: @32@0:8@16@24
METHOD dealloc v16@0:8
METHOD options @16@0:8
METHOD encodeValueOfObjCType:at: v32@0:8r*16r^v24
METHOD setOptions: v24@0:8@16
METHOD setSkipMorphTargets: v20@0:8B16
METHOD skipMorphTargets B16@0:8

=== CLASS VFXKeyedUnarchiver ===
SUPER: NSKeyedUnarchiver
SIZE: 176
IVAR +136 0 _documentURL @"NSURL"
IVAR +144 0 _context @"NSDictionary"
IVAR +152 0 _lookUpKey @"NSString"
IVAR +160 0 _lookUpFoundInstance @
IVAR +168 0 _allTargetsFromAnimCodec @"NSArray"
METHOD dealloc v16@0:8
METHOD context @16@0:8
METHOD setContext: v24@0:8@16
METHOD decodeValueOfObjCType:at: v32@0:8r*16^v24
METHOD documentURL @16@0:8
METHOD setDocumentURL: v24@0:8@16
METHOD allTargetsFromAnimCodec @16@0:8
METHOD documentEnclosingURL @16@0:8
METHOD initForReadingWithData:secure: @28@0:8@16B24
METHOD lookUpFoundInstance @16@0:8
METHOD lookUpKey @16@0:8
METHOD setAllTargetsFromAnimCodec: v24@0:8@16
METHOD setLookUpFoundInstance: v24@0:8@16
METHOD setLookUpKey: v24@0:8@16

=== CLASS VFXMaterialProperty ===
SUPER: NSObject
SIZE: 120
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable VFXAnimatable NSSecureCoding
IVAR +8 0 _isPresentationObject b1
IVAR +8 0 _isCommonProfileProperty b1
IVAR +8 0 _colorManaged b1
IVAR +8 0 _preventWarmup b1
IVAR +9 0 _propertyType c
IVAR +16 0 _parent @
IVAR +24 0 _commonProfile ^{__CFXCommonProfile={__CFRuntimeBase=QAQ}^{__CFXMaterial}C^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}ffffCiBb1b1b1b1b1b1b13}
IVAR +32 0 _parentRef ^v
IVAR +40 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +48 0 _animations @"VFXOrderedDictionary"
IVAR +56 0 _bindings @"NSMutableDictionary"
IVAR +64 0 _contents @
IVAR +72 0 _contentType C
IVAR +73 0 _mappingChannel C
IVAR +74 0 _minificationFilter b2
IVAR +74 0 _magnificationFilter b2
IVAR +74 0 _mipFilter b2
IVAR +75 0 _wrapS b3
IVAR +75 0 _wrapT b3
IVAR +76 0 _textureComponents b4
IVAR +77 0 _maxAnisotropy b5
IVAR +80 0 _intensity f
IVAR +88 0 _customMaterialPropertyName @"NSString"
IVAR +96 0 _customMaterialProperty ^{__CFXMaterialProperty={__CFRuntimeBase=QAQ}(?=^{__CFXImage}^{__CFXImageProxy}^{__CFXTexture}^v^v^v{CFXColor4=(?=[4f]{?=ffff})})^vq^vb8b1b4c{?=b8b8b8b8b8b8b8b7b1}^{?}fi^v}
IVAR +104 0 _contentTransform ^{?={?=[4]}(?=)}
IVAR +112 0 _runtimeResolvedURL @
CMETHOD supportsSecureCoding B16@0:8
CMETHOD captureDeviceOutputConsumer @16@0:8
CMETHOD captureDeviceOutputConsumerWithOptions: @24@0:8@16
CMETHOD materialPropertyWithContents: @24@0:8@16
CMETHOD precomputedLightingEnvironmentContentsWithData:error: @32@0:8@16^@24
CMETHOD precomputedLightingEnvironmentContentsWithURL:error: @32@0:8@16^@24
CMETHOD _createCFXImageFromImage: ^{__CFXImage=}24@0:8@16
CMETHOD copyCFXImageFromImage: ^{__CFXImage=}24@0:8@16
CMETHOD copyCFXImageFromImage:textureOptions: ^{__CFXImage=}28@0:8@16C24
CMETHOD copyCFXImageFromImage:textureOptions:wasCached: ^{__CFXImage=}36@0:8@16C24^B28
CMETHOD precomputedLightingEnvironmentDataForContents:radianceTextureSize:device:error: @48@0:8@16Q24@32^@40
METHOD avt_setSimdContentsTransform: v80@0:8{?=[4]}16
METHOD avt_simdContentsTransform {?=[4]}16@0:8
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD floatValue @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD parent @16@0:8
METHOD setValue:forKey: v32@0:8@16@24
METHOD valueForKey: @24@0:8@16
METHOD color @16@0:8
METHOD setColor: v24@0:8@16
METHOD propertyName @16@0:8
METHOD contents @16@0:8
METHOD image @16@0:8
METHOD intensity f16@0:8
METHOD setContents: v24@0:8@16
METHOD setImage: v24@0:8@16
METHOD setIntensity: v20@0:8f16
METHOD _setColor: v24@0:8@16
METHOD _setParent: v24@0:8@16
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationKeys @16@0:8
METHOD contentsScale 16@0:8
METHOD contentsTransform {?=[4]}16@0:8
METHOD layer @16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD setContentsScale: v32@0:816
METHOD setContentsTransform: v80@0:8{?=[4]}16
METHOD setLayer: v24@0:8@16
METHOD setMagnificationFilter: v24@0:8q16
METHOD setMinificationFilter: v24@0:8q16
METHOD propertyType c16@0:8
METHOD magnificationFilter q16@0:8
METHOD minificationFilter q16@0:8
METHOD setMaxAnisotropy: v24@0:8Q16
METHOD setMipFilter: v24@0:8q16
METHOD world @16@0:8
METHOD mappingChannel q16@0:8
METHOD mipFilter q16@0:8
METHOD setFloatValue: v24@0:8@16
METHOD setMappingChannel: v24@0:8q16
METHOD setTextureComponents: v24@0:8q16
METHOD textureComponents q16@0:8
METHOD avPlayer @16@0:8
METHOD setAvPlayer: v24@0:8@16
METHOD maxAnisotropy Q16@0:8
METHOD _textureOptions C16@0:8
METHOD UIView @16@0:8
METHOD __allocateContentTransformIfNeeded v16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD _animationPathForKey: @24@0:8@16
METHOD unlinkCustomPropertyWithParent: v24@0:8@16
METHOD _updateMaterialTextureProvider: v24@0:8@16
METHOD __CFObject ^v16@0:8
METHOD textureProvider @16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _hasDefaultValues B16@0:8
METHOD _layerDidChange: v24@0:8@16
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _presentationMappingChannel q16@0:8
METHOD _syncObjCAnimations v16@0:8
METHOD _updateMaterialAVPlayer: v24@0:8@16
METHOD _updateMaterialCaptureDevice: v24@0:8@16
METHOD _updateMaterialCaptureDeviceOutputConsumerSource: v24@0:8@16
METHOD _updateMaterialColor: v24@0:8@16
METHOD _updateMaterialImage: v24@0:8@16
METHOD _updateMaterialLayer: v24@0:8@16
METHOD _updateMaterialMTLTexture: v24@0:8@16
METHOD _updateMaterialNumber: v24@0:8@16
METHOD _updateMaterialUIComponent: v24@0:8@16
METHOD _updatePrecomputedLightingEnvironment: v24@0:8@16
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__CFXAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD captureDevice @16@0:8
METHOD captureDeviceOutputConsumerSource @16@0:8
METHOD color4 {CFXColor4=(?=[4f]{?=ffff})}16@0:8
METHOD commonProfile ^{__CFXCommonProfile={__CFRuntimeBase=QAQ}^{__CFXMaterial}C^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}^{__CFXMaterialProperty}ffffCiBb1b1b1b1b1b1b13}16@0:8
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD initPresentationMaterialPropertyWithModelProperty: @24@0:8@16
METHOD initWithParent:andCustomName: @32@0:8@16@24
METHOD initWithParent:propertyType: @28@0:8@16c24
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD linkCustomPropertyWithParent:andCustomName: v32@0:8@16@24
METHOD mtlTexture @16@0:8
METHOD parentWillDie: v24@0:8@16
METHOD precomputedLightingEnvironment @16@0:8
METHOD presentationMaterialProperty @16@0:8
METHOD removeAllAnimationsWithBlendOutDuration: v20@0:8f16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v28@0:8@16f24
METHOD setCaptureDevice: v24@0:8@16
METHOD setCaptureDeviceOutputConsumerSource: v24@0:8@16
METHOD setMtlTexture: v24@0:8@16
METHOD setPrecomputedLightingEnvironment: v24@0:8@16
METHOD setTextureProvider: v24@0:8@16
METHOD setUIView: v24@0:8@16
METHOD setUIWindow: v24@0:8@16
METHOD setWrapS: v24@0:8q16
METHOD setWrapT: v24@0:8q16
METHOD textureSampler {?=b8b8b8b8b8b8b8b7b1}16@0:8
METHOD unbindAnimatablePath: v24@0:8@16
METHOD wrapS q16@0:8
METHOD wrapT q16@0:8
METHOD _vfxDeprecatedAddAnimation:forKey: v32@0:8@16@24
METHOD presentationObject @16@0:8
METHOD assetValue @16@0:8
METHOD setAssetValue: v24@0:8@16
METHOD copyPropertiesFrom:copyContext: v32@0:8@16@24
METHOD materialPropertyCreateIfNeeded: ^{__CFXMaterialProperty={__CFRuntimeBase=QAQ}(?=^{__CFXImage}^{__CFXImageProxy}^{__CFXTexture}^v^v^v{CFXColor4=(?=[4f]{?=ffff})})^vq^vb8b1b4c{?=b8b8b8b8b8b8b8b7b1}^{?}fi^v}20@0:8B16
METHOD __runtimeResolvedURL @16@0:8
METHOD _clearContentsForDeallocation: v20@0:8B16
METHOD _copyBindingsFrom: v24@0:8@16
METHOD _customDecodingOfVFXMaterialProperty: v24@0:8@16
METHOD _customEncodingOfVFXMaterialProperty: v24@0:8@16
METHOD _didDecodeVFXMaterialProperty: v24@0:8@16
METHOD _setImagePath:withResolvedURL: v32@0:8@16@24
METHOD _setSourceObject:forBinding: v32@0:8@16@24
METHOD _updateCFXImageWithContents: v24@0:8@16
METHOD _updateMaterialAsset: v24@0:8@16
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD _updateSampler v16@0:8
METHOD _vfxAnimationForKey: @24@0:8@16
METHOD _vfxBindings @16@0:8
METHOD contentsAbsoluteURL @16@0:8
METHOD contentsAsCGImage ^{CGImage=}16@0:8
METHOD contentsOffset 16@0:8
METHOD contentsRotation f16@0:8
METHOD copyBitmap ^{CGContext=}16@0:8
METHOD enumerateAnimationReferencesUsingBlock: v24@0:8@?16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD flagAsPresentationObject v16@0:8
METHOD getCFXImageRef ^v16@0:8
METHOD isColorManaged B16@0:8
METHOD isPresentationObject B16@0:8
METHOD linearExtendedSRGBColor 16@0:8
METHOD materialProperty ^{__CFXMaterialProperty={__CFRuntimeBase=QAQ}(?=^{__CFXImage}^{__CFXImageProxy}^{__CFXTexture}^v^v^v{CFXColor4=(?=[4f]{?=ffff})})^vq^vb8b1b4c{?=b8b8b8b8b8b8b8b7b1}^{?}fi^v}16@0:8
METHOD materialPropertyName @16@0:8
METHOD resolvedURLForContents: @24@0:8@16
METHOD setColorManaged: v20@0:8B16
METHOD setContentsOffset: v32@0:816
METHOD setContentsRotation: v20@0:8f16
METHOD setLinearExtendedSRGBColor: v32@0:816
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXMesh ===
SUPER: NSObject
SIZE: 72
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable VFXGeometry
IVAR +8 0 _world @"VFXWorld"
IVAR +16 0 _worldReferenceCounter I
IVAR +24 0 _mesh ^{__CFXMesh=}
IVAR +32 0 _isPresentationObject b1
IVAR +40 0 _sources @"NSMutableArray"
IVAR +48 0 _elements @"NSMutableArray"
IVAR +56 0 _sourceChannels @"NSArray"
IVAR +64 0 _name @"NSString"
CMETHOD supportsSecureCoding B16@0:8
CMETHOD mesh @16@0:8
CMETHOD meshWithSources:elements: @32@0:8@16@24
CMETHOD meshWithSources:elements:sourceChannels: @40@0:8@16@24@32
CMETHOD meshWithMeshRef: @24@0:8^{__CFXMesh=}16
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD setName: v24@0:8@16
METHOD setIdentifier: v24@0:8@16
METHOD boundingBox {?=[2]}16@0:8
METHOD debugQuickLookObject @16@0:8
METHOD setBoundingBox: v48@0:8{?=[2]}16
METHOD primitiveType q16@0:8
METHOD world @16@0:8
METHOD setPrimitiveType: v24@0:8q16
METHOD _renderableCopy @16@0:8
METHOD getBoundingSphereCenter:radius: B32@0:8^16^f24
METHOD interleavedCopy @16@0:8
METHOD __CFObject ^v16@0:8
METHOD _discardOriginalTopology v16@0:8
METHOD _releaseCachedSourcesAndElements v16@0:8
METHOD debugQuickLookData @16@0:8
METHOD keyForNodeAttributes @16@0:8
METHOD setWorld: v24@0:8@16
METHOD meshElements @16@0:8
METHOD meshSourceChannels @16@0:8
METHOD meshSources @16@0:8
METHOD meshDescription @16@0:8
METHOD meshRef ^{__CFXMesh=}16@0:8
METHOD _meshByRebuildingNormals @16@0:8
METHOD _meshByRemovingSkinnerSources @16@0:8
METHOD _meshByWeldingVerticesWithThreshold:normalThreshold: @24@0:8f16f20
METHOD _rebuildMeshElementsFromPresentation v16@0:8
METHOD _rebuildMeshSourcesFromPresentation v16@0:8
METHOD _updateEntityModelFromPresentation v16@0:8
METHOD _updateEntityPresentationFromModel v16@0:8
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD addWorldReference: v24@0:8@16
METHOD debugQuickLookObjectWithWorld: @24@0:8@16
METHOD decodeMeshWithCoder: v24@0:8@16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD initWithMeshRef: @24@0:8^{__CFXMesh=}16
METHOD makeUniqueID v16@0:8
METHOD meshElementAtIndex: @24@0:8q16
METHOD meshElementCount q16@0:8
METHOD meshSourcesForSemantic: @24@0:8@16
METHOD removeWorldReference: v24@0:8@16
METHOD setMeshRef: v24@0:8^{__CFXMesh=}16
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXMeshSource ===
SUPER: NSObject
SIZE: 120
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable NSSecureCoding
IVAR +8 0 _meshSource ^{__CFXMeshSource={__CFXGenericSource={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}
IVAR +16 0 _world @"VFXWorld"
IVAR +24 0 _worldReferenceCounter I
IVAR +28 0 _isPresentationObject b1
IVAR +32 0 _data @"NSData"
IVAR +40 0 _semantic @"NSString"
IVAR +48 0 _vectorCount q
IVAR +56 0 _componentType s
IVAR +58 0 _componentCount S
IVAR +64 0 _colorSpace ^{CGColorSpace=}
IVAR +72 0 _dataOffset q
IVAR +80 0 _dataStride q
IVAR +88 0 _mkSemantic C
IVAR +96 0 _mtlBuffer @"<MTLBuffer>"
IVAR +104 0 _mtlVertexFormat q
IVAR +112 0 _encodeDataAsHalf B
CMETHOD supportsSecureCoding B16@0:8
CMETHOD geometrySourceWithColorData:colorSpace:vectorCount:floatComponents:componentsPerVector:bytesPerComponent:dataOffset:dataStride: @76@0:8@16^{CGColorSpace=}24q32B40q44q52q60q68
CMETHOD dataByConvertingDoublesToFloats:count: @32@0:8r^d16q24
CMETHOD dataWithPointArray:count:bytesPerComponent: @40@0:8r^{CGPoint=dd}16q24^q32
CMETHOD dataWithVector3Array:count:bytesPerComponent: @40@0:8r^16q24^q32
CMETHOD meshSourceWithData:semantic:vectorCount:floatComponents:componentsPerVector:bytesPerComponent:dataOffset:dataStride: @76@0:8@16@24q32B40q44q52q60q68
CMETHOD _meshSourceWithData:semantic:vectorCount:componentType:componentCount:dataOffset:dataStride: @68@0:8@16@24q32s40Q44q52q60
CMETHOD _modelSourceWithSource:vertexFormat: @32@0:8@16Q24
CMETHOD meshSourceWithBuffer:vertexFormat:semantic:vertexCount:dataOffset:dataStride: @64@0:8@16Q24@32q40q48q56
CMETHOD meshSourceWithColorComponents:count:hasAlpha:colorSpace: @44@0:8r^f16q24B32^{CGColorSpace=}36
CMETHOD meshSourceWithMDLVertexAttribute:mesh: @32@0:8@16@24
CMETHOD meshSourceWithMeshSourceRef: @24@0:8^{__CFXMeshSource={__CFXGenericSource={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}16
CMETHOD meshSourceWithNormals:count: @32@0:8r^16q24
CMETHOD meshSourceWithTextureCoordinates:count: @32@0:8r^{CGPoint=dd}16q24
CMETHOD meshSourceWithVertices:count: @32@0:8r^16q24
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD data @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD mutableData @16@0:8
METHOD semantic @16@0:8
METHOD world @16@0:8
METHOD floatComponents B16@0:8
METHOD __CFObject ^v16@0:8
METHOD _componentType s16@0:8
METHOD _encodeDataAsHalf B16@0:8
METHOD _printData v16@0:8
METHOD _uninterleaveData:count:srcOffset:srcStride:dstStride: @56@0:8@16Q24Q32Q40Q48
METHOD bytesPerComponent q16@0:8
METHOD componentsPerVector q16@0:8
METHOD dataByConvertingColorData:colorSpace:newColorSpace:vectorCount:componentsPerVector:bytesPerComponent:dataOffset:dataStride:newDataOffset:newDataStride: @96@0:8@16^{CGColorSpace=}24^^{CGColorSpace}32q40q48q56q64q72^q80^q88
METHOD dataOffset q16@0:8
METHOD dataStride q16@0:8
METHOD initWithBuffer:vertexFormat:semantic:vertexCount:dataOffset:dataStride: @64@0:8@16Q24@32q40q48q56
METHOD initWithData:semantic:colorSpace:vectorCount:floatComponents:componentsPerVector:bytesPerComponent:dataOffset:dataStride: @84@0:8@16@24^{CGColorSpace=}32q40B48q52q60q68q76
METHOD initWithData:semantic:vectorCount:componentType:componentCount:dataOffset:dataStride: @68@0:8@16@24q32s40Q44q52q60
METHOD initWithMeshSource: @24@0:8^{__CFXMeshSource={__CFXGenericSource={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}16
METHOD meshSource ^{__CFXMeshSource={__CFXGenericSource={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXSourceAccessor}(?=^{__CFData}^v^v)qb1b1b1}SCC}16@0:8
METHOD mkSemantic @16@0:8
METHOD setMkSemantic: v24@0:8@16
METHOD set_encodeDataAsHalf: v20@0:8B16
METHOD vectorCount q16@0:8
METHOD setWorld: v24@0:8@16
METHOD _clearCFXCache v16@0:8
METHOD addWorldReference: v24@0:8@16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD removeWorldReference: v24@0:8@16
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXModelTessellator ===
SUPER: NSObject
SIZE: 56
PROTOCOLS: NSCopying NSSecureCoding
IVAR +8 0 _clients @"NSMutableSet"
IVAR +16 0 _adaptive B
IVAR +17 0 _screenSpace B
IVAR +20 0 _maximumEdgeLength f
IVAR +24 0 _edgeTessellationFactor f
IVAR +28 0 _insideTessellationFactor f
IVAR +32 0 _tessellationFactorScale f
IVAR +40 0 _smoothingMode q
IVAR +48 0 _partitionMode Q
CMETHOD supportsSecureCoding B16@0:8
CMETHOD modelTessellator @16@0:8
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD isAdaptive B16@0:8
METHOD setAdaptive: v20@0:8B16
METHOD addClient: v24@0:8@16
METHOD removeClient: v24@0:8@16
METHOD setTessellationPartitionMode: v24@0:8Q16
METHOD tessellationPartitionMode Q16@0:8
METHOD setScreenSpace: v20@0:8B16
METHOD adaptive B16@0:8
METHOD clientWillDie: v24@0:8@16
METHOD edgeTessellationFactor f16@0:8
METHOD insideTessellationFactor f16@0:8
METHOD isScreenSpace B16@0:8
METHOD maximumEdgeLength f16@0:8
METHOD screenSpace B16@0:8
METHOD setEdgeTessellationFactor: v20@0:8f16
METHOD setInsideTessellationFactor: v20@0:8f16
METHOD setMaximumEdgeLength: v20@0:8f16
METHOD setSmoothingMode: v24@0:8q16
METHOD setTessellationFactorScale: v20@0:8f16
METHOD smoothingMode q16@0:8
METHOD tessellationFactorScale f16@0:8
METHOD tessellatorValueDidChange v16@0:8
METHOD tessellatorValueDidChangeForClient: v24@0:8@16
METHOD _tessellatorValueForModel: {?=CfIC(?={?=ff}{?=f}{?=f}{?=Cb1b1})}24@0:8@16

=== CLASS VFXModelWrapDeformer ===
SUPER: VFXModelDeformer
SIZE: 48
IVAR +8 0 _innerLayerNode @"VFXNode"
IVAR +16 0 _outerLayerNode @"VFXNode"
IVAR +24 0 _parameters @"VFXModelWrapDeformerParameters"
IVAR +32 0 _isLegacySingleLayerDeformer B
IVAR +40 0 _legacyDrivingNode @"VFXNode"
CMETHOD supportsSecureCoding B16@0:8
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD initWithDrivingNode:parameters: @32@0:8@16@24
METHOD _getDeformedMeshBoundingBox: B24@0:8^{?=}16
METHOD dependencyNodeAtIndex: @24@0:8Q16
METHOD drivingNode @16@0:8
METHOD initParametersIfNeededForDeformedNode: v24@0:8@16
METHOD initWithInnerLayerNode:outerLayerNode:parameters: @40@0:8@16@24@32
METHOD newDeformerInstanceForNode:outputs:computeVertexCount:context: @48@0:8@16Q24Q32@40
METHOD requiredInputs Q16@0:8
METHOD supportedOutputs Q16@0:8
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24

=== CLASS VFXModelWrapDeformerParameters ===
SUPER: NSObject
SIZE: 248
PROTOCOLS: NSSecureCoding
IVAR +8 0 _vertexCount I
IVAR +16 0 _bindingMode Q
IVAR +24 0 _bindingData {?="pointIndices"^v"pointIndicesStride"Q"pointIndicesFormat"Q"barycentricCoords"^v"barycentricCoordsStride"Q"barycentricCoordsFormat"Q"innerLayerInfluences"^f"innerLayerInfluencesLength"Q"innerLayerTNBs"^f"outerLayerTNBs"^f"tnbMatricesLength"Q"innerLayerOffsets"^f"outerLayerOffsets"^f"offsetsLength"Q"legacyOffsetsOrTransforms"^f"legacyOffsetsOrTransformsLength"Q}
IVAR +160 0 _deformedToDrivingBindingTransform {?="columns"[4]}
IVAR +224 0 _isLegacySingleLayerDeformer B
IVAR +232 0 _legacyDrivingNodeUVChannel Q
IVAR +240 0 _legacyDeformedNodeUVChannel Q
CMETHOD supportsSecureCoding B16@0:8
METHOD dealloc v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD bindingMode Q16@0:8
METHOD extraLayerMeshesWithDrivingMesh0:drivingMesh1: @32@0:8^{__CFXMesh=}16^{__CFXMesh=}24
METHOD initParametersIfNeededWithDrivingNodeRef:deformedNodeRef: v32@0:8^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}16^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}24
METHOD initParametersIfNeededWithInnerLayerNodeRef:outerLayerNodeRef:deformedNodeRef: v40@0:8^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}16^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}24^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}32
METHOD initWithDrivingNode:deformedNode:bindingMode:bindingTransform:drivingNodeUVChannel:deformedNodeUVChannel: @120@0:8@16@24Q32{?=[4]}40Q104Q112
METHOD initWithInnerLayerNode:outerLayerNode:deformedNode:bindingMode:bindingTransform: @112@0:8@16@24@32Q40{?=[4]}48

=== CLASS VFXMorpher ===
SUPER: NSObject
SIZE: 176
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable VFXAnimatable NSSecureCoding
IVAR +8 0 _morpher ^{__CFXMorph=}
IVAR +16 0 _world @"VFXWorld"
IVAR +24 0 _worldReferenceCounter I
IVAR +28 0 _isPresentationObject b1
IVAR +32 0 _calculationMode q
IVAR +40 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +48 0 _animations @"VFXOrderedDictionary"
IVAR +56 0 _bindings @"NSMutableDictionary"
IVAR +64 0 _mainTargets @"NSArray"
IVAR +72 0 _weightCount Q
IVAR +80 0 _weights ^f
IVAR +88 0 _mainTargetsAndInBetweens @"NSArray"
IVAR +96 0 _inBetweenCounts @"NSArray"
IVAR +104 0 _inBetweenInfluenceWeights @"NSArray"
IVAR +112 0 _correctivesAndInBetweens @"NSArray"
IVAR +120 0 _correctiveDriverCounts @"NSArray"
IVAR +128 0 _correctiveDriverIndices @"NSArray"
IVAR +136 0 _correctiveInBetweenCounts @"NSArray"
IVAR +144 0 _correctiveInBetweenInfluenceWeights @"NSArray"
IVAR +152 0 _mainTargetNamesToIndexes @"NSDictionary"
IVAR +160 0 _name @"NSString"
IVAR +168 0 _unifyNormal B
IVAR +169 0 _useSparseTargets B
CMETHOD supportsSecureCoding B16@0:8
CMETHOD morpher @16@0:8
CMETHOD morpherWithMorphRef: @24@0:8^{__CFXMorph=}16
CMETHOD weightIndexStringForIndex: @24@0:8q16
CMETHOD VFXUID_classForElementOfArray: #24@0:8@16
CMETHOD presentationMorpherWithMorpherRef: @24@0:8^{__CFXMorpher={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXGeometry}^{__CFXMorph}II^fII}16
METHOD avt_buildInternalSupportForCorrectivesWithBlock: v24@0:8@?16
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD setName: v24@0:8@16
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD valueForUndefinedKey: @24@0:8@16
METHOD setIdentifier: v24@0:8@16
METHOD weights @16@0:8
METHOD setWeights: v24@0:8@16
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationKeys @16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD setCalculationMode: v24@0:8q16
METHOD targets @16@0:8
METHOD setTargets: v24@0:8@16
METHOD calculationMode q16@0:8
METHOD world @16@0:8
METHOD _updateCorrectivesAndInBetween: v24@0:8@16
METHOD clearInBetweens v16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD inBetweenCounts @16@0:8
METHOD __CFObject ^v16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _isUsingSparseTargets B16@0:8
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _presentationWeightForTargetAtIndex:token: f32@0:8Q16r^v24
METHOD _syncObjCAnimations v16@0:8
METHOD _updateTargetsAndInBetween: v24@0:8@16
METHOD _weightIndexForTargetNamed: q24@0:8@16
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__CFXAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD clearCorrectives v16@0:8
METHOD convertToAdditiveWithBaseGeometry: v24@0:8@16
METHOD convertToSparseWithBaseGeometry: v24@0:8@16
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD correctiveDriverCountForCorrectiveAtIndex: Q24@0:8Q16
METHOD correctiveDriverCounts @16@0:8
METHOD correctiveDriverIndices @16@0:8
METHOD correctiveDriverIndicesForCorrectiveAtIndex: @24@0:8Q16
METHOD correctiveInBetweenCounts @16@0:8
METHOD correctiveInBetweenWeights @16@0:8
METHOD correctives @16@0:8
METHOD correctivesAndInBetween @16@0:8
METHOD inBetweenTargetsForCorrectiveAtIndex: @24@0:8Q16
METHOD inBetweenTargetsForTargetAtIndex: @24@0:8Q16
METHOD inBetweenWeights @16@0:8
METHOD inBetweenWeightsForCorrectiveAtIndex: @24@0:8Q16
METHOD inBetweenWeightsForTargetAtIndex: @24@0:8Q16
METHOD initPresentationMorpherWithMorphRef: @24@0:8^{__CFXMorph=}16
METHOD initWithMorphRef: @24@0:8^{__CFXMorph=}16
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD morphRef ^{__CFXMorph=}16@0:8
METHOD presentationMorpher @16@0:8
METHOD removeAllAnimationsWithBlendOutDuration: v20@0:8f16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v28@0:8@16f24
METHOD setShouldClearCPUDataAfterUpload: v20@0:8B16
METHOD setShouldMorphNormals: v20@0:8B16
METHOD setTargets:withInBetweenTargetCounts:inBetweenWeights: v40@0:8@16@24@32
METHOD setTargetsAndInBetweens:inBetweenCounts:inBetweenWeights:correctives:driverCounts:driverIndices:inBetweenCounts:inBetweenWeights: v80@0:8@16@24@32@40@48@56@64@72
METHOD setUnifiesNormals: v20@0:8B16
METHOD setWeight:forTargetAtIndex: v28@0:8f16Q20
METHOD setWeight:forTargetNamed: v28@0:8f16@20
METHOD setWeightIncrementalThreshold: v20@0:8f16
METHOD shouldClearCPUDataAfterUpload B16@0:8
METHOD shouldMorphNormals B16@0:8
METHOD targetsAndInBetween @16@0:8
METHOD unbindAnimatablePath: v24@0:8@16
METHOD unifiesNormals B16@0:8
METHOD weightForTargetAtIndex: f24@0:8Q16
METHOD weightForTargetNamed: f24@0:8@16
METHOD weightIncrementalThreshold f16@0:8
METHOD setWorld: v24@0:8@16
METHOD _vfxDeprecatedAddAnimation:forKey: v32@0:8@16@24
METHOD presentationObject @16@0:8
METHOD _copyBindingsFrom: v24@0:8@16
METHOD _customDecodingOfVFXMorpher: v24@0:8@16
METHOD _customEncodingOfVFXMorpher: v24@0:8@16
METHOD _didDecodeVFXMorpher: v24@0:8@16
METHOD _setSourceObject:forBinding: v32@0:8@16@24
METHOD _updateEntityModelFromPresentation v16@0:8
METHOD _updateEntityPresentationFromModel v16@0:8
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD _vfxAnimationForKey: @24@0:8@16
METHOD _vfxBindings @16@0:8
METHOD addWorldReference: v24@0:8@16
METHOD enumerateAnimationReferencesUsingBlock: v24@0:8@?16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD isPresentationObject B16@0:8
METHOD makeUniqueID v16@0:8
METHOD removeWorldReference: v24@0:8@16
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXNode ===
SUPER: NSObject
SIZE: 264
PROTOCOLS: VFXBehaviorSupport VFXParameterizable NSObject VFXWorldReference VFXReferenceEnumerable VFXCopyingRemappable VFXEntityProvider UIFocusItemContainer VFXTransactionCommandObject NSCopying NSSecureCoding VFXAnimatable VFXBehaviorSupport VFXParameterizable VFXBoundingBox VFXStateSupport
IVAR +8 0 _node ^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}
IVAR +16 0 _world @"VFXWorld"
IVAR +24 0 _parent @"VFXNode"
IVAR +32 0 _childNodes @"NSMutableArray"
IVAR +40 0 _presentationObject @"VFXNode"
IVAR +48 0 _isPresentationObject b1
IVAR +48 0 _paused b1
IVAR +48 0 _pausedByInheritance b1
IVAR +48 0 _affineUpToDate b1
IVAR +48 0 _transformUpToDate b1
IVAR +48 0 _hasPivot b1
IVAR +48 0 _isJoint b1
IVAR +48 0 _isGizmo b1
IVAR +49 0 _isEyeSightFrame b1
IVAR +49 0 _isHandTrackingRoot b1
IVAR +49 0 _rotationRepresentation b2
IVAR +49 0 _hidden b1
IVAR +49 0 _castsShadow b1
IVAR +49 0 _depthPrePass b1
IVAR +49 0 _focusBehavior b2
IVAR +50 0 _isFocusableOrHasFocusableChild b1
IVAR +50 0 _isAuthoring b1
IVAR +50 0 _editorLocked b1
IVAR +52 0 _hasComponentBitmask b15
IVAR +54 0 _physicsBodyCountInHierarchy S
IVAR +64 0 _transform {?="columns"[4]}
IVAR +128 0 _position 
IVAR +144 0 _rotation (?="eulerAngles""axisAngle""quaternion"{?="vector"})
IVAR +160 0 _scale 
IVAR +176 0 _opacity f
IVAR +184 0 _categoryBitMask Q
IVAR +192 0 _renderingOrder q
IVAR +200 0 _components @"VFXNodeComponent"
IVAR +208 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +216 0 _animations @"VFXOrderedDictionary"
IVAR +224 0 _bindings @"NSMutableDictionary"
IVAR +232 0 _fixedBoundingBoxExtrema ^
IVAR +240 0 _name @"NSString"
IVAR +248 0 _valueForKey @"NSMutableDictionary"
IVAR +256 0 _valueForKeyLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
CMETHOD supportsSecureCoding B16@0:8
CMETHOD node @16@0:8
CMETHOD keyPathsForValuesAffectingScale @16@0:8
CMETHOD localUp 16@0:8
CMETHOD _dumpNodeTree:tab: @32@0:8@16@24
CMETHOD keyPathsForValuesAffectingEulerAngles @16@0:8
CMETHOD keyPathsForValuesAffectingOrientation @16@0:8
CMETHOD keyPathsForValuesAffectingPosition @16@0:8
CMETHOD keyPathsForValuesAffectingRotation @16@0:8
CMETHOD keyPathsForValuesAffectingTransform @16@0:8
CMETHOD localFront 16@0:8
CMETHOD localRight 16@0:8
CMETHOD nodeWithMDLAsset: @24@0:8@16
CMETHOD nodeWithMDLObject: @24@0:8@16
CMETHOD nodeWithNodeRef: @24@0:8^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}16
CMETHOD nodeWithModel: @24@0:8@16
CMETHOD localRightValue @16@0:8
CMETHOD localFrontValue @16@0:8
CMETHOD localUpValue @16@0:8
CMETHOD nodeWithMDLObject:masterObjects:worldNodes:skinnedMeshes:skelNodesMap:asset:options:context:mpuScale: @84@0:8@16@24@32@40^v48@56@64@72f80
CMETHOD nodeWithMDLObject:options:context: @40@0:8@16@24@32
CMETHOD nodeWithSceneKitNode:options: @32@0:8@16@24
METHOD _implementCEKWorkaroundIfNeeded v16@0:8
METHOD avt_enableSubdivisionOnHierarchyWithQuality:animoji: v28@0:8Q16B24
METHOD avt_setGeometryPrimitiveRangesFromFaceIndexRanges: v24@0:8@16
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD name @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD isHidden B16@0:8
METHOD setHidden: v20@0:8B16
METHOD setName: v24@0:8@16
METHOD state @16@0:8
METHOD dump v16@0:8
METHOD isPaused B16@0:8
METHOD position 16@0:8
METHOD scale 16@0:8
METHOD setPosition: v32@0:816
METHOD setValue:forKey: v32@0:8@16@24
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD transform {?=[4]}16@0:8
METHOD valueForKey: @24@0:8@16
METHOD valueForKeyPath: @24@0:8@16
METHOD valueForUndefinedKey: @24@0:8@16
METHOD setState: v24@0:8@16
METHOD setScale: v32@0:816
METHOD parameters @16@0:8
METHOD setIdentifier: v24@0:8@16
METHOD opacity f16@0:8
METHOD setOrientation: v32@0:8{?=}16
METHOD boundingBox {?=[2]}16@0:8
METHOD debugQuickLookObject @16@0:8
METHOD model @16@0:8
METHOD orientation {?=}16@0:8
METHOD rotation 16@0:8
METHOD setModel: v24@0:8@16
METHOD setOpacity: v20@0:8f16
METHOD setRotation: v32@0:816
METHOD setTransform: v80@0:8{?=[4]}16
METHOD setBoundingBox: v48@0:8{?=[2]}16
METHOD scaleValue @16@0:8
METHOD constraints @16@0:8
METHOD states @16@0:8
METHOD quaternion {?=}16@0:8
METHOD setPaused: v20@0:8B16
METHOD isVisible B16@0:8
METHOD parentNode @16@0:8
METHOD categoryBitMask Q16@0:8
METHOD setConstraints: v24@0:8@16
METHOD _setAttributes: v24@0:8@16
METHOD _setParent: v24@0:8@16
METHOD _setScale: v32@0:816
METHOD _updateTransform v16@0:8
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationKeys @16@0:8
METHOD canBecomeFocused B16@0:8
METHOD childNodes @16@0:8
METHOD focusBehavior q16@0:8
METHOD hidden B16@0:8
METHOD isHiddenOrHasHiddenAncestor B16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD setCategoryBitMask: v24@0:8Q16
METHOD camera @16@0:8
METHOD setCamera: v24@0:8@16
METHOD world @16@0:8
METHOD setIsVisible: v20@0:8B16
METHOD copyWithOptions: @24@0:8Q16
METHOD setQuaternion: v32@0:8{?=}16
METHOD addChildNode: v24@0:8@16
METHOD enumerateChildNodesUsingBlock: v24@0:8@?16
METHOD indexOfChildNode: Q24@0:8@16
METHOD insertChildNode:atIndex: v32@0:8@16Q24
METHOD removeFromParentNode v16@0:8
METHOD _setPosition: v32@0:816
METHOD _registerAsObserver v16@0:8
METHOD lookAt: v32@0:816
METHOD setPhysicsBody: v24@0:8@16
METHOD physicsBody @16@0:8
METHOD setStateManager: v24@0:8@16
METHOD stateManager @16@0:8
METHOD isGizmo B16@0:8
METHOD __light @16@0:8
METHOD _enumerateChildNodesUsingBlock: B24@0:8@?16
METHOD morpher @16@0:8
METHOD __morpher @16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD nodeRef ^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}16@0:8
METHOD _appendFocusableNodesInRect:ofView:toFocusItems: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56
METHOD _assignComponent:toContainerWithType: v32@0:8@16q24
METHOD _audioPlayers @16@0:8
METHOD skinner @16@0:8
METHOD _bakeNodes:folderPath:inVertex:bakeAO:quality:attenuation:geomSetter:terminateSetter: v64@0:8@16@24B32B36f40f44@?48@?56
METHOD worldUp 16@0:8
METHOD _encodeNodePropertiesWithCoder: v24@0:8@16
METHOD _setQuaternion: v32@0:8{?=}16
METHOD addAudioPlayer: v24@0:8@16
METHOD getBoundingSphereCenter:radius: B32@0:8^16^f24
METHOD isJoint B16@0:8
METHOD __CFObject ^v16@0:8
METHOD __camera @16@0:8
METHOD __skinner @16@0:8
METHOD removeAllChilds v16@0:8
METHOD setCastsShadow: v20@0:8B16
METHOD setEulerAngles: v32@0:816
METHOD _childNodesPassingTest:recursively:output: B36@0:8@?16B24@28
METHOD _childNodesWithAttribute:output:recursively: v36@0:8#16@24B32
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _dump: v24@0:8@16
METHOD _dumpTree @16@0:8
METHOD _euler 16@0:8
METHOD _findComponentWithType: @24@0:8q16
METHOD _focusFrameInView: {CGRect={CGPoint=dd}{CGSize=dd}}24@0:8@16
METHOD _isAReference B16@0:8
METHOD _isEffectivelyHidden B16@0:8
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _quaternion {?=}16@0:8
METHOD _removeComponentWithType: v24@0:8q16
METHOD _setComponent:withType: v32@0:8@16q24
METHOD _setHasFocusableChild v16@0:8
METHOD _setPausedOrPausedByInheritance: v20@0:8B16
METHOD _subdividedCopyWithSubdivisionLevel: @24@0:8q16
METHOD _syncObjCAnimations v16@0:8
METHOD _updateAffine v16@0:8
METHOD _updateFocusableCache v16@0:8
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__CFXAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD audioPlayers @16@0:8
METHOD authoringCameraType q16@0:8
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD canAddChildNode: B24@0:8@16
METHOD castsShadow B16@0:8
METHOD childNodeWithName: @24@0:8@16
METHOD childNodeWithName:recursively: @28@0:8@16B24
METHOD childNodesPassingTest: @24@0:8@?16
METHOD childNodesPassingTest:recursively: @28@0:8@?16B24
METHOD childNodesWithAttribute:recursively: @28@0:8#16B24
METHOD clone @16@0:8
METHOD convertPosition:fromNode: 40@0:816@32
METHOD convertPosition:toNode: 40@0:816@32
METHOD convertTransform:fromNode: {?=[4]}88@0:8{?=[4]}16@80
METHOD convertTransform:toNode: {?=[4]}88@0:8{?=[4]}16@80
METHOD convertVector:fromNode: 40@0:816@32
METHOD convertVector:toNode: 40@0:816@32
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD countOfAudioPlayers Q16@0:8
METHOD countOfChildNodes Q16@0:8
METHOD debugQuickLookData @16@0:8
METHOD enumerateHierarchyUsingBlock: v24@0:8@?16
METHOD eulerAngles 16@0:8
METHOD flattenedClone @16@0:8
METHOD flattenedCopy @16@0:8
METHOD getBoundingBox @16@0:8
METHOD getBoundingBoxMin:max: B32@0:8^16^24
METHOD getBoundingSphere @16@0:8
METHOD getFrustum:withViewport: B40@0:8^{?=[6{?=}]}1624
METHOD hitTestWithSegmentFromPoint:toPoint:options: @56@0:81632@48
METHOD initPresentationNodeWithNodeRef: @24@0:8^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}16
METHOD initWithNodeRef: @24@0:8^{__CFXNode={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXNode}^{__CFXNode}^{__CFXNode}i{?={?=[4]}(?=)}^{?}BfQib1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b1b3b1b1b1b1b1b1{?={?=SS}I}^{?}^{__CFXModel}^{__CFXDeformerStack}f{?=}}16
METHOD insertObject:inAudioPlayersAtIndex: v32@0:8@16Q24
METHOD insertObject:inChildNodesAtIndex: v32@0:8@16Q24
METHOD isFocusInteractionEnabled B16@0:8
METHOD isHittable B16@0:8
METHOD isPausedOrPausedByInheritance B16@0:8
METHOD jsChildNodesWithAttribute: @24@0:8@16
METHOD light @16@0:8
METHOD localRotateBy: v32@0:8{?=}16
METHOD localTranslateBy: v32@0:816
METHOD lookAt:up:localFront: v64@0:8163248
METHOD mutableChildNodes @16@0:8
METHOD objectInAudioPlayersAtIndex: @24@0:8Q16
METHOD objectInChildNodesAtIndex: @24@0:8Q16
METHOD objectInChildNodesWithAttribute:firstOnly: @28@0:8@16B24
METHOD objectInChildNodesWithName: @24@0:8@16
METHOD parseSpecialKey:withPath:intoDestination: B40@0:8@16@24^@32
METHOD pivot {?=[4]}16@0:8
METHOD presentationNode @16@0:8
METHOD removeAllAnimationsWithBlendOutDuration: v20@0:8f16
METHOD removeAllAudioPlayers v16@0:8
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v28@0:8@16f24
METHOD removeAudioPlayer: v24@0:8@16
METHOD removeObjectFromAudioPlayersAtIndex: v24@0:8Q16
METHOD removeObjectFromChildNodesAtIndex: v24@0:8Q16
METHOD renderingOrder q16@0:8
METHOD replaceChildNode:with: v32@0:8@16@24
METHOD replaceObjectInAudioPlayerAtIndex:withObject: v32@0:8Q16@24
METHOD replaceObjectInChildNodesAtIndex:withObject: v32@0:8Q16@24
METHOD rotateBy:aroundTarget: v48@0:8{?=}1632
METHOD rotationRepresentation q16@0:8
METHOD setAuthoringCameraType: v24@0:8q16
METHOD setBoundingBoxMin:max: v32@0:8^16^24
METHOD setFocusBehavior: v24@0:8q16
METHOD setGizmo: v20@0:8B16
METHOD setHittable: v20@0:8B16
METHOD setIsJoint: v20@0:8B16
METHOD setLight: v24@0:8@16
METHOD setMorpher: v24@0:8@16
METHOD setPivot: v80@0:8{?=[4]}16
METHOD setRenderingOrder: v24@0:8q16
METHOD setSkinner: v24@0:8@16
METHOD setUsesDepthPrePass: v20@0:8B16
METHOD setWorldOrientation: v32@0:8{?=}16
METHOD setWorldPosition: v32@0:816
METHOD setWorldTransform: v80@0:8{?=[4]}16
METHOD unbindAnimatablePath: v24@0:8@16
METHOD usesDepthPrePass B16@0:8
METHOD worldFront 16@0:8
METHOD worldOrientation {?=}16@0:8
METHOD worldPosition 16@0:8
METHOD worldRight 16@0:8
METHOD worldTransform {?=[4]}16@0:8
METHOD particleEmitter @16@0:8
METHOD behaviorGraph @16@0:8
METHOD setWorld: v24@0:8@16
METHOD _vfxDeprecatedAddAnimation:forKey: v32@0:8@16@24
METHOD deepClone @16@0:8
METHOD drawCallCount I16@0:8
METHOD presentationObject @16@0:8
METHOD deformers @16@0:8
METHOD setDeformers: v24@0:8@16
METHOD modelChanged v16@0:8
METHOD setScaleValue: v24@0:8@16
METHOD graphController @16@0:8
METHOD convertTransformValue:fromNode: @32@0:8@16@24
METHOD lookAtLocation: v24@0:8@16
METHOD script_rootNode @16@0:8
METHOD setIsAuthoring: v20@0:8B16
METHOD _addSkinnerWithMDLMesh:worldNodes: v32@0:8@16@24
METHOD worldFrontValue @16@0:8
METHOD worldRightValue @16@0:8
METHOD __model @16@0:8
METHOD isEyeSightFrame B16@0:8
METHOD _cloneWithOption:copyContext: @32@0:8Q16@24
METHOD _copyBindingsFrom: v24@0:8@16
METHOD _copyRecursively:copyContext: @32@0:8Q16@24
METHOD _copyWithOptions:to:copyContext: v40@0:8Q16@24@32
METHOD _customDecodingOfVFXNode: v24@0:8@16
METHOD _customEncodingOfVFXNode:usePresentationObject: v28@0:8@16B24
METHOD _deepCloneWithContext: @24@0:8@16
METHOD _didDecodeVFXNode: v24@0:8@16
METHOD _propagatePhysicsBodyCountChange: v20@0:8i16
METHOD _remapNodeReferences:nullifyIfAbsent: v28@0:8@16B24
METHOD _setSourceObject:forBinding: v32@0:8@16@24
METHOD _updateEntityModelFromPresentation v16@0:8
METHOD _updateEntityPresentationFromModel v16@0:8
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD _valueForSimdVectorKeyPath: @24@0:8@16
METHOD _vfxAnimationForKey: @24@0:8@16
METHOD _vfxBindings @16@0:8
METHOD addAnimationAsset:forKey: v32@0:8@16@24
METHOD addWorldReference: v24@0:8@16
METHOD authoringTargetNode @16@0:8
METHOD bridgedComponentNames @16@0:8
METHOD cloneWithOption: @24@0:8Q16
METHOD convertPositionValue:fromNode: @32@0:8@16@24
METHOD convertPositionValue:toNode: @32@0:8@16@24
METHOD convertTransformValue:toNode: @32@0:8@16@24
METHOD convertVectorValue:fromNode: @32@0:8@16@24
METHOD convertVectorValue:toNode: @32@0:8@16@24
METHOD copyTo:withContext: v32@0:8@16@24
METHOD copyWithOptions:to: v32@0:8Q16@24
METHOD coreEntity q16@0:8
METHOD coreEntityManager @16@0:8
METHOD debugQuickLookObjectWithWorld: @24@0:8@16
METHOD deepCloneWithContext: @24@0:8@16
METHOD editorLocked B16@0:8
METHOD enumerateAnimationReferencesUsingBlock: v24@0:8@?16
METHOD enumerateDrawCallsUsingBlock:context: v32@0:8@?16^{?=@?@^{__CFXRenderingOverride}@^{__CFXWorld}^{__CFXNode}}24
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD eulerAnglesValue @16@0:8
METHOD forceField @16@0:8
METHOD graphController: v24@0:8@16
METHOD hasAncestor: B24@0:8@16
METHOD hasPhysicBody B16@0:8
METHOD hitTestWithSegmentFrom:toPoint:options: @40@0:8@16@24@32
METHOD isAuthoring B16@0:8
METHOD isHandTrackingRoot B16@0:8
METHOD isPresentationObject B16@0:8
METHOD localRotateByValue: v24@0:8@16
METHOD localTranslateByValue: v24@0:8@16
METHOD lookAtLocation:up:localFront: v40@0:8@16@24@32
METHOD makeUniqueID v16@0:8
METHOD orientationValue @16@0:8
METHOD particleCollider @16@0:8
METHOD pivotValue @16@0:8
METHOD positionValue @16@0:8
METHOD prefab @16@0:8
METHOD rawFloat3ForKey:value: B32@0:8@16^24
METHOD rawFloat4ForKey:value: B32@0:8@16^24
METHOD removeWorldReference: v24@0:8@16
METHOD resetPhysicsBodyTransformInHierarchy v16@0:8
METHOD rotateBy:around: v32@0:8@16@24
METHOD rotationValue @16@0:8
METHOD setAuthoringTargetNode: v24@0:8@16
METHOD setBehaviorGraph: v24@0:8@16
METHOD setEditorLocked: v20@0:8B16
METHOD setEulerAnglesValue: v24@0:8@16
METHOD setForceField: v24@0:8@16
METHOD setIsEyeSightFrame: v20@0:8B16
METHOD setIsHandTrackingRoot: v20@0:8B16
METHOD setOrientationValue: v24@0:8@16
METHOD setParticleCollider: v24@0:8@16
METHOD setParticleEmitter: v24@0:8@16
METHOD setPivotValue: v24@0:8@16
METHOD setPositionValue: v24@0:8@16
METHOD setPrefab: v24@0:8@16
METHOD setRotationValue: v24@0:8@16
METHOD setStateNamed: v24@0:8@16
METHOD setWorldOrientationValue: v24@0:8@16
METHOD setWorldPositionValue: v24@0:8@16
METHOD setWorldTransformValue: v24@0:8@16
METHOD worldOrientationValue @16@0:8
METHOD worldPositionValue @16@0:8
METHOD worldRef ^{__CFXWorld=}16@0:8
METHOD worldTransformValue @16@0:8
METHOD worldUpValue @16@0:8

=== CLASS VFXNode_CEKWorkaround ===
SUPER: VFXNode
SIZE: 264
METHOD camera @16@0:8

=== CLASS VFXParametricModel ===
SUPER: VFXModel
SIZE: 304
IVAR +176 0 _type q
IVAR +184 0 _width f
IVAR +188 0 _height f
IVAR +192 0 _length f
IVAR +196 0 _radius f
IVAR +200 0 _chamferRadius f
IVAR +204 0 _topRadius f
IVAR +208 0 _pipeRadius f
IVAR +212 0 _innerRadius f
IVAR +216 0 _segmentCount q
IVAR +224 0 _widthSegmentCount q
IVAR +232 0 _heightSegmentCount q
IVAR +240 0 _lengthSegmentCount q
IVAR +248 0 _chamferSegmentCount q
IVAR +256 0 _cornerSegmentCount q
IVAR +264 0 _pipeSegmentCount q
IVAR +272 0 _capSegmentCount q
IVAR +280 0 _radialSegmentCount q
IVAR +288 0 _radialSpan f
IVAR +292 0 _spheregeodesic B
IVAR +293 0 _spherehemispheric B
IVAR +296 0 _primitiveType q
CMETHOD supportsSecureCoding B16@0:8
CMETHOD pyramidWithWidth:height:length: @28@0:8f16f20f24
CMETHOD torusWithRingRadius:pipeRadius: @24@0:8f16f20
CMETHOD capsuleWithCapRadius:height: @24@0:8f16f20
CMETHOD coneWithTopRadius:bottomRadius:height: @28@0:8f16f20f24
CMETHOD cylinderWithRadius:height: @24@0:8f16f20
CMETHOD planeWithWidth:height: @24@0:8f16f20
CMETHOD sphereWithRadius: @20@0:8f16
CMETHOD tubeWithInnerRadius:outerRadius:height: @28@0:8f16f20f24
CMETHOD cubeWithWidth:height:length:chamferRadius: @32@0:8f16f20f24f28
CMETHOD unitCube @16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD description @16@0:8
METHOD init @16@0:8
METHOD length f16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD setLength: v20@0:8f16
METHOD setWidth: v20@0:8f16
METHOD width f16@0:8
METHOD height f16@0:8
METHOD mesh @16@0:8
METHOD radius f16@0:8
METHOD setHeight: v20@0:8f16
METHOD setRadius: v20@0:8f16
METHOD primitiveType q16@0:8
METHOD cornerRadius f16@0:8
METHOD setCornerRadius: v20@0:8f16
METHOD presentationModel @16@0:8
METHOD segmentCount q16@0:8
METHOD setSegmentCount: v24@0:8q16
METHOD _notifyModelChanged v16@0:8
METHOD setPrimitiveType: v24@0:8q16
METHOD __createCFObject ^{__CFXModel={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXGeometry}^{__CFXMaterial}^{__CFArray}^{__CFSet}^{__CFArray}^{?}b1^{?}{?=CB{?=BCCC}^{__CFXMeshElement}^{__CFXMeshSource}^{__CFXMesh}^v^v}{?=CfIC(?={?=ff}{?=f}{?=f}{?=Cb1b1})}C}16@0:8
METHOD setHemispheric: v20@0:8B16
METHOD setInnerRadius: v20@0:8f16
METHOD capSegmentCount q16@0:8
METHOD getBoundingSphereCenter:radius: B32@0:8^16^f24
METHOD _setupObjCModelFrom: v24@0:8@16
METHOD chamferRadius f16@0:8
METHOD chamferSegmentCount q16@0:8
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD cornerSegmentCount q16@0:8
METHOD geodesic B16@0:8
METHOD getBoundingBoxMin:max: B32@0:8^16^24
METHOD heightSegmentCount q16@0:8
METHOD innerRadius f16@0:8
METHOD isGeodesic B16@0:8
METHOD isHemispheric B16@0:8
METHOD lengthSegmentCount q16@0:8
METHOD pipeRadius f16@0:8
METHOD pipeSegmentCount q16@0:8
METHOD radialSegmentCount q16@0:8
METHOD radialSpan f16@0:8
METHOD setCapSegmentCount: v24@0:8q16
METHOD setChamferRadius: v20@0:8f16
METHOD setChamferSegmentCount: v24@0:8q16
METHOD setCornerSegmentCount: v24@0:8q16
METHOD setGeodesic: v20@0:8B16
METHOD setHeightSegmentCount: v24@0:8q16
METHOD setLengthSegmentCount: v24@0:8q16
METHOD setPipeRadius: v20@0:8f16
METHOD setPipeSegmentCount: v24@0:8q16
METHOD setRadialSegmentCount: v24@0:8q16
METHOD setRadialSpan: v20@0:8f16
METHOD setTopRadius: v20@0:8f16
METHOD setWidthSegmentCount: v24@0:8q16
METHOD topRadius f16@0:8
METHOD widthSegmentCount q16@0:8
METHOD _sphereType i16@0:8
METHOD _updateModelFromPresentation v16@0:8
METHOD _updateModelFromPresentation: v24@0:8^{__CFXParametricGeometry={__CFXModel={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXGeometry}^{__CFXMaterial}^{__CFArray}^{__CFSet}^{__CFArray}^{?}b1^{?}{?=CB{?=BCCC}^{__CFXMeshElement}^{__CFXMeshSource}^{__CFXMesh}^v^v}{?=CfIC(?={?=ff}{?=f}{?=f}{?=Cb1b1})}C}{?=fffffffffiiiiiiiiiiI}{?=^?^?^?^?^?^?}^{__CFData}}16
METHOD _updatePresentationFromModel v16@0:8
METHOD _updateSphereType v16@0:8
METHOD bridgedComponentNames @16@0:8
METHOD initPresentationParametricModelWithParametricGeometryRef: @24@0:8^{__CFXParametricGeometry={__CFXModel={__CFXEntity={__CFRuntimeBase=QAQ}^v^{__CFString}^{__CFString}^{__CFDictionary}^{__CFXWorld}q}^{__CFXGeometry}^{__CFXMaterial}^{__CFArray}^{__CFSet}^{__CFArray}^{?}b1^{?}{?=CB{?=BCCC}^{__CFXMeshElement}^{__CFXMeshSource}^{__CFXMesh}^v^v}{?=CfIC(?={?=ff}{?=f}{?=f}{?=Cb1b1})}C}{?=fffffffffiiiiiiiiiiI}{?=^?^?^?^?^?^?}^{__CFData}}16
METHOD initUninitialized @16@0:8
METHOD initWithDefaultMaterial @16@0:8
METHOD parametricType q16@0:8
METHOD setParametricType: v24@0:8q16

=== CLASS VFXPhysicsBody ===
SUPER: NSObject
SIZE: 264
PROTOCOLS: VFXReferenceEnumerable VFXCopyingRemappable NSCopying NSSecureCoding
IVAR +8 0 _node @"VFXNode"
IVAR +16 0 _mass f
IVAR +20 0 _charge f
IVAR +24 0 _friction f
IVAR +28 0 _restitution f
IVAR +32 0 _rollingFriction f
IVAR +36 0 _continuousCollisionDetectionThreshold f
IVAR +40 0 _defaultShape B
IVAR +48 0 _physicsShape @"VFXPhysicsShape"
IVAR +56 0 _type q
IVAR +64 0 _damping f
IVAR +80 0 _angularVelocity 
IVAR +96 0 _angularDamping f
IVAR +112 0 _velocityFactor 
IVAR +128 0 _angularVelocityFactor 
IVAR +144 0 _velocity 
IVAR +160 0 _ignoreGravity B
IVAR +164 0 _linearRestingThreshold f
IVAR +168 0 _angularRestingThreshold f
IVAR +172 0 _explicitMomentOfInertia B
IVAR +176 0 _momentOfInertia 
IVAR +192 0 _centerOfMassOffset 
IVAR +208 0 _categoryBitMask Q
IVAR +216 0 _collisionBitMask Q
IVAR +224 0 _contactTestBitMask Q
IVAR +232 0 _allowsResting B
IVAR +240 0 _body ^v
IVAR +248 0 _btShapeWrapper @"VFXBtShapeWrapper"
IVAR +256 0 _active B
CMETHOD supportsSecureCoding B16@0:8
CMETHOD bodyWithType:shape: @32@0:8q16@24
CMETHOD dynamicBody @16@0:8
CMETHOD kinematicBody @16@0:8
CMETHOD staticBody @16@0:8
CMETHOD _generateDefaultShapeForNode: @24@0:8@16
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD _activate v16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD setType: v24@0:8q16
METHOD type q16@0:8
METHOD setValue:forKey: v32@0:8@16@24
METHOD valueForKey: @24@0:8@16
METHOD isActive B16@0:8
METHOD commonInit v16@0:8
METHOD damping f16@0:8
METHOD mass f16@0:8
METHOD setDamping: v20@0:8f16
METHOD setMass: v20@0:8f16
METHOD categoryBitMask Q16@0:8
METHOD angularVelocity 16@0:8
METHOD setRestitution: v20@0:8f16
METHOD _owner @16@0:8
METHOD _setOwner: v24@0:8@16
METHOD angularDamping f16@0:8
METHOD charge f16@0:8
METHOD collisionBitMask Q16@0:8
METHOD friction f16@0:8
METHOD isResting B16@0:8
METHOD resetTransform v16@0:8
METHOD restitution f16@0:8
METHOD setAffectedByGravity: v20@0:8B16
METHOD setAngularDamping: v20@0:8f16
METHOD setAngularVelocity: v32@0:816
METHOD setCategoryBitMask: v24@0:8Q16
METHOD setCharge: v20@0:8f16
METHOD setCollisionBitMask: v24@0:8Q16
METHOD setContactTestBitMask: v24@0:8Q16
METHOD setFriction: v20@0:8f16
METHOD setResting: v20@0:8B16
METHOD setVelocity: v32@0:816
METHOD velocity 16@0:8
METHOD _handle ^v16@0:8
METHOD momentOfInertia 16@0:8
METHOD moveToPosition: v32@0:816
METHOD rollingFriction f16@0:8
METHOD _createBody ^v16@0:8
METHOD _ownerWillDie v16@0:8
METHOD _removeOwner v16@0:8
METHOD allowsResting B16@0:8
METHOD angularRestingThreshold f16@0:8
METHOD angularSleepingThreshold f16@0:8
METHOD angularVelocityFactor 16@0:8
METHOD applyForce:atPosition:impulse: v52@0:81632B48
METHOD applyForce:impulse: v36@0:816B32
METHOD applyTorque:impulse: v36@0:816B32
METHOD centerOfMassOffset 16@0:8
METHOD clearAllForces v16@0:8
METHOD contactTestBitMask Q16@0:8
METHOD continuousCollisionDetection f16@0:8
METHOD continuousCollisionDetectionThreshold f16@0:8
METHOD initWithType:shape: @32@0:8q16@24
METHOD isAffectedByGravity B16@0:8
METHOD linearRestingThreshold f16@0:8
METHOD linearSleepingThreshold f16@0:8
METHOD moveToTransform: v80@0:8{?=[4]}16
METHOD physicsShape @16@0:8
METHOD resetToTransform: v80@0:8{?=[4]}16
METHOD rotateToAxisAngle: v32@0:816
METHOD setAllowsResting: v20@0:8B16
METHOD setAngularRestingThreshold: v20@0:8f16
METHOD setAngularSleepingThreshold: v20@0:8f16
METHOD setAngularVelocityFactor: v32@0:816
METHOD setCenterOfMassOffset: v32@0:816
METHOD setContinuousCollisionDetectionThreshold: v20@0:8f16
METHOD setLinearRestingThreshold: v20@0:8f16
METHOD setLinearSleepingThreshold: v20@0:8f16
METHOD setMomentOfInertia: v32@0:816
METHOD setPhysicsShape: v24@0:8@16
METHOD setRollingFriction: v20@0:8f16
METHOD setUsesDefaultMomentOfInertia: v20@0:8B16
METHOD setVelocityFactor: v32@0:816
METHOD updateGlobalScale: v24@0:8d16
METHOD usesDefaultMomentOfInertia B16@0:8
METHOD velocityFactor 16@0:8
METHOD hasDefaultShape B16@0:8
METHOD invalidateShape v16@0:8
METHOD _setBtShape: v24@0:8@16
METHOD _setPhysicsShape: v24@0:8@16
METHOD _updateCollisionShape v16@0:8
METHOD angularVelocityFactorValue @16@0:8
METHOD angularVelocityValue @16@0:8
METHOD applyForceValue:atPosition:impulse: v36@0:8@16@24B32
METHOD applyForceValue:impulse: v28@0:8@16B24
METHOD applyTorqueValue:impulse: v28@0:8@16B24
METHOD cleanCollisionCache v16@0:8
METHOD copyTo:withContext: v32@0:8@16@24
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD flagAsActive: v20@0:8B16
METHOD momentOfInertiaValue @16@0:8
METHOD setAngularVelocityFactorValue: v24@0:8@16
METHOD setAngularVelocityValue: v24@0:8@16
METHOD setMomentOfInertiaValue: v24@0:8@16
METHOD setVelocityFactorValue: v24@0:8@16
METHOD setVelocityValue: v24@0:8@16
METHOD updateDefaultShape v16@0:8
METHOD velocityFactorValue @16@0:8
METHOD velocityValue @16@0:8
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXPhysicsConeTwistJoint ===
SUPER: VFXPhysicsJoint
SIZE: 192
IVAR +48 0 _definition {?="frameA"{?="columns"[4]}"frameB"{?="columns"[4]}"maximumAngularLimit1"f"maximumAngularLimit2"f"maximumTwistAngle"f}
CMETHOD supportsSecureCoding B16@0:8
CMETHOD jointWithBody:frame: @88@0:8@16{?=[4]}24
CMETHOD jointWithBodyA:frameA:bodyB:frameB: @160@0:8@16{?=[4]}24@88{?=[4]}96
METHOD init @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD setValue:forKey: v32@0:8@16@24
METHOD valueForKey: @24@0:8@16
METHOD frameA {?=[4]}16@0:8
METHOD frameB {?=[4]}16@0:8
METHOD initWithBody:frame: @88@0:8@16{?=[4]}24
METHOD initWithBodyA:frameA:bodyB:frameB: @160@0:8@16{?=[4]}24@88{?=[4]}96
METHOD maximumAngularLimit1 f16@0:8
METHOD maximumAngularLimit2 f16@0:8
METHOD maximumTwistAngle f16@0:8
METHOD setFrameA: v80@0:8{?=[4]}16
METHOD setFrameB: v80@0:8{?=[4]}16
METHOD setMaximumAngularLimit1: v20@0:8f16
METHOD setMaximumAngularLimit2: v20@0:8f16
METHOD setMaximumTwistAngle: v20@0:8f16
METHOD copyFrom: v24@0:8@16
METHOD _createConstraint ^{btTypedConstraint=^^?ii(?=i^v)fBBi^{btRigidBody}^{btRigidBody}ff^{btJointFeedback}}16@0:8
METHOD _twistHandle ^{btConeTwistConstraint=^^?ii(?=i^v)fBBi^{btRigidBody}^{btRigidBody}ff^{btJointFeedback}[3{btJacobianEntry={btVector3=(?=[4f])}{btVector3=(?=[4f])}{btVector3=(?=[4f])}{btVector3=(?=[4f])}{btVector3=(?=[4f])}f}]{btTransform={btMatrix3x3=[3{btVector3=(?=[4f])}]}{btVector3=(?=[4f])}}{btTransform={btMatrix3x3=[3{btVector3=(?=[4f])}]}{btVector3=(?=[4f])}}ffffffff{btVector3=(?=[4f])}{btVector3=(?=[4f])}ffffffffBBBBff{btVector3=(?=[4f])}BB{btQuaternion=(?=[4f])}f{btVector3=(?=[4f])}ifff}16@0:8

=== CLASS VFXPhysicsShape ===
SUPER: NSObject
SIZE: 112
PROTOCOLS: VFXReferenceEnumerable VFXCopyingRemappable NSCopying NSSecureCoding
IVAR +8 0 _referenceObject @
IVAR +16 0 _transforms @"NSArray"
IVAR +32 0 _scale 
IVAR +48 0 _nodeScale 
IVAR +64 0 _margin f
IVAR +72 0 _type q
IVAR +80 0 _flattened B
IVAR +88 0 _physicsBodies ^{__CFArray=}
IVAR +96 0 _physicsBodiesLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +104 0 _shape @"VFXBtShapeWrapper"
CMETHOD supportsSecureCoding B16@0:8
CMETHOD shapeWithShapes:transforms: @32@0:8@16@24
CMETHOD shapeWithModel: @24@0:8@16
CMETHOD defaultShapeForModel: @24@0:8@16
CMETHOD shapeWithNode:flattened: @28@0:8@16B24
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD invalidate v16@0:8
METHOD setType: v24@0:8q16
METHOD type q16@0:8
METHOD scale 16@0:8
METHOD setValue:forKey: v32@0:8@16@24
METHOD valueForKey: @24@0:8@16
METHOD setScale: v32@0:816
METHOD model @16@0:8
METHOD setModel: v24@0:8@16
METHOD commonInit v16@0:8
METHOD scaleValue @16@0:8
METHOD initWithContent: @24@0:8@16
METHOD margin f16@0:8
METHOD setMargin: v20@0:8f16
METHOD transforms @16@0:8
METHOD didChange v16@0:8
METHOD _updateScale v16@0:8
METHOD setShapes: v24@0:8@16
METHOD shapes @16@0:8
METHOD _setTransforms: v24@0:8@16
METHOD setScaleValue: v24@0:8@16
METHOD _customDecodingOfVFXPhysicsShape: v24@0:8@16
METHOD _customEncodingOfVFXPhysicsShape: v24@0:8@16
METHOD _setNodeScale: v32@0:816
METHOD _setShapeObject: v24@0:8@16
METHOD _shapeHandle: @24@0:8^{__CFXNode=}16
METHOD copyTo:withContext: v32@0:8@16@24
METHOD didAddToPhysicsBody: v24@0:8@16
METHOD didRemoveFromPhysicsBody: v24@0:8@16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD flattened B16@0:8
METHOD setFlattened: v20@0:8B16
METHOD setShapeNode: v24@0:8@16
METHOD shapeNode @16@0:8

=== CLASS VFXRenderer ===
SUPER: NSObject
SIZE: 392
PROTOCOLS: VFXMTLRenderContextCommandBufferStatusMonitor VFXMTLRenderContextResourceManagerMonitor VFXWorldRenderer
IVAR +8 0 _world @"VFXWorld"
IVAR +16 0 _pointOfView @"VFXNode"
IVAR +24 0 _pointOfCulling @"VFXNode"
IVAR +32 0 _lock @"VFXRecursiveLock"
IVAR +40 0 __renderingQueue @"NSObject<OS_dispatch_queue>"
IVAR +48 0 __antialiasingMode Q
IVAR +56 0 _pixelFormat Q
IVAR +64 0 _viewpoints @"NSArray"
IVAR +72 0 _viewpointCoordinateSpace Q
IVAR +80 0 _pointOfViewWasSet B
IVAR +81 0 _drawablePropertiesDidChange b1
IVAR +81 0 _rendersContinuously b1
IVAR +81 0 _isPrivateRenderer b1
IVAR +81 0 _isViewPrivateRenderer b1
IVAR +88 0 _time d
IVAR +96 0 _deltaTime d
IVAR +104 0 _nextFrameTime d
IVAR +112 0 _isAnimating B
IVAR +116 0 _adaptativeState0 I
IVAR +120 0 _adaptativeEndFrame I
IVAR +128 0 _delegate @
IVAR +136 0 _engineContext ^{__CFXEngineContext=}
IVAR +144 0 _coreShaderCache @
IVAR +160 0 __viewport 
IVAR +176 0 __drawableSafeAreaInsets 
IVAR +192 0 __drawableSize {CGSize="width"d"height"d}
IVAR +208 0 _lastOptionsHash Q
IVAR +216 0 _renderContext @"VFXMTLRenderContext"
IVAR +224 0 _additiveWritesToAlpha b1
IVAR +224 0 _jitteringEnabled b1
IVAR +224 0 _temporalAntialiasingEnabled b1
IVAR +224 0 _frozen b1
IVAR +224 0 _imguiFrameStarted b1
IVAR +224 0 _triggersEnabled b1
IVAR +224 0 _shouldForwardWorldRendererDelegationMessagesToSelf b1
IVAR +224 0 _shouldForwardWorldRendererDelegationMessagesToPrivateRendererOwner b1
IVAR +228 0 _selfDelegationConformance {?="supportsUpdate"b1"supportsDidApplyAnimations"b1"supportsDidSimulatePhysics"b1"supportsDidApplyConstraints"b1"supportsWillRender"b1"supportsDidRender"b1"supportsInputTime"b1"supportsReadSubdivCache"b1"supportsWriteSubdivCache"b1"supportsMainPassCustomPostProcess"b1"supportsDidPresent"b1}
IVAR +232 0 _privateRendererOwnerDelegationConformance {?="supportsUpdate"b1"supportsDidApplyAnimations"b1"supportsDidSimulatePhysics"b1"supportsDidApplyConstraints"b1"supportsWillRender"b1"supportsDidRender"b1"supportsInputTime"b1"supportsReadSubdivCache"b1"supportsWriteSubdivCache"b1"supportsMainPassCustomPostProcess"b1"supportsDidPresent"b1}
IVAR +236 0 _delegationConformance {?="supportsUpdate"b1"supportsDidApplyAnimations"b1"supportsDidSimulatePhysics"b1"supportsDidApplyConstraints"b1"supportsWillRender"b1"supportsDidRender"b1"supportsInputTime"b1"supportsReadSubdivCache"b1"supportsWriteSubdivCache"b1"supportsMainPassCustomPostProcess"b1"supportsDidPresent"b1}
IVAR +240 0 _backgroundColor @"UIColor"
IVAR +256 0 _cfxBackgroundColor {CFXColor4=""(?="rgba"[4f]""{?="r"f"g"f"b"f"a"f}"simd")}
IVAR +272 0 _privateRendererOwner @"<VFXWorldRenderer>"
IVAR +280 0 _legacyRenderer @"_TtC3VFX17VFXRendererLegacy"
IVAR +288 0 _contentScaleFactor f
IVAR +296 0 _authoringEnvironment @"VFXAuthoringEnvironment"
IVAR +304 0 _debugOptions Q
IVAR +312 0 _debugUIOptions Q
IVAR +320 0 _showStatistics B
IVAR +321 0 _showAuthoringEnvironment B
IVAR +322 0 _cameraIsManipulated B
IVAR +323 0 _keepResourceManagerWhenDealloc B
IVAR +328 0 _statisticsTimeStamp d
IVAR +336 0 _resourceManagerMonitor @"<_VFXWorldRendererResourceManagerMonitor>"
IVAR +344 0 _commandBufferStatusMonitor @"<_VFXWorldCommandBufferStatusMonitor>"
IVAR +352 0 _customRenderGraphEnabled B
IVAR +360 0 _renderGraph @"VFXRenderGraph"
IVAR +368 0 _renderMode Q
IVAR +376 0 _rendererKind Q
IVAR +384 0 _isSideBySideStereo B
IVAR +385 0 _emulateStereo B
IVAR +386 0 _emulateRRM B
IVAR +387 0 _shouldCaptureNextMetalFrame B
IVAR +388 0 _captureMetalFrameStarted B
IVAR +389 0 _isSetupForRE B
CMETHOD rendererWithDevice:options: @32@0:8@16@24
CMETHOD rendererWithCommandQueue:options: @32@0:8@16@24
CMETHOD allocatedTextureCount q16@0:8
CMETHOD allocatedBufferCount q16@0:8
CMETHOD logSharedResources v16@0:8
CMETHOD remoteDecoder @16@0:8
CMETHOD remoteEncoder @16@0:8
METHOD avt_simdProjectPoint: 32@0:816
METHOD avt_simdUnprojectPoint: 32@0:816
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD .cxx_destruct v16@0:8
METHOD delegate @16@0:8
METHOD lock v16@0:8
METHOD setDelegate: v24@0:8@16
METHOD unlock v16@0:8
METHOD statistics @16@0:8
METHOD setPixelFormat: v24@0:8Q16
METHOD commandQueue @16@0:8
METHOD device @16@0:8
METHOD pixelFormat Q16@0:8
METHOD setBinaryArchives: v24@0:8@16
METHOD setTexture: v24@0:8@16
METHOD workingColorSpace ^{CGColorSpace=}16@0:8
METHOD texture @16@0:8
METHOD metalDevice @16@0:8
METHOD backgroundColor @16@0:8
METHOD setBackgroundColor: v24@0:8@16
METHOD viewport {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _screenSize 16@0:8
METHOD _setInterfaceOrientation: v24@0:8q16
METHOD effect @16@0:8
METHOD renderMode Q16@0:8
METHOD scene @16@0:8
METHOD setEffect: v24@0:8@16
METHOD setFrozen: v20@0:8B16
METHOD setRenderMode: v24@0:8Q16
METHOD setScene: v24@0:8@16
METHOD nextFrameTime d16@0:8
METHOD render v16@0:8
METHOD hitTest:options: @40@0:8{CGPoint=dd}16@32
METHOD world @16@0:8
METHOD currentRenderPassDescriptor @16@0:8
METHOD metalLayer @16@0:8
METHOD binaryArchives @16@0:8
METHOD _renderingQueue @16@0:8
METHOD currentViewport {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD _UIOrientationDidChangeNotification: v24@0:8@16
METHOD prepareObject:shouldAbortBlock: B32@0:8@16@?24
METHOD _addGPUFrameCompletedHandler: v24@0:8@?16
METHOD _addGPUFrameScheduledHandler: v24@0:8@?16
METHOD setTemporalAntialiasingEnabled: v20@0:8B16
METHOD set_commandBufferStatusMonitor: v24@0:8@16
METHOD showsStatistics B16@0:8
METHOD __CFObject ^v16@0:8
METHOD _addGPUFramePresentedHandler: v24@0:8@?16
METHOD _allowGPUBackgroundExecution v16@0:8
METHOD setForceAsyncShaderCompilation: v20@0:8B16
METHOD setPointOfView: v24@0:8@16
METHOD _authoringEnvironment @16@0:8
METHOD _backingSize {CGSize=dd}16@0:8
METHOD unprojectPoint: 32@0:816
METHOD _beginFrame v16@0:8
METHOD _clearBackBuffer v16@0:8
METHOD _collectCompilationErrors B16@0:8
METHOD _commandBufferStatusMonitor @16@0:8
METHOD _compilationErrors @16@0:8
METHOD _computeNextFrameTime d16@0:8
METHOD _computedLightingEnvironmentMapsPath @16@0:8
METHOD _contentsScaleFactor f16@0:8
METHOD _copyPerformanceStatistics @16@0:8
METHOD _createBackgroundColorImageWithSize: ^{CGImage=}32@0:8{CGSize=dd}16
METHOD _discardPendingGPUFrameCompletedHandlers v16@0:8
METHOD _discardPendingGPUFramePresentedHandlers v16@0:8
METHOD _discardPendingGPUFrameScheduledHandlers v16@0:8
METHOD _displayLinkStatsTack v16@0:8
METHOD _displayLinkStatsTick v16@0:8
METHOD _drawableSafeAreaInsets 16@0:8
METHOD _enableARMode B16@0:8
METHOD _endFrame v16@0:8
METHOD _engineContext ^{__CFXEngineContext=}16@0:8
METHOD _hitTest:viewport:options: @56@0:8{CGPoint=dd}16{CGSize=dd}32@48
METHOD _interfaceOrientationDidChange v16@0:8
METHOD _isNodeInsideFrustum:withPointOfView:viewport: B48@0:8@16@2432
METHOD _jitterAtStep:updateMainFramebuffer:redisplay:jitterer: v40@0:8Q16B24B28@32
METHOD _needsRedrawAsap B16@0:8
METHOD _needsRepetitiveRedraw B16@0:8
METHOD _nodesInsideFrustumWithPointOfView:viewport: @40@0:8@1624
METHOD _projectPoint:viewport: 48@0:81632
METHOD _projectPoints:count:viewport: v48@0:8^16Q2432
METHOD _readSubdivCacheForHash: @24@0:8@16
METHOD _renderContextMetal @16@0:8
METHOD _resourceManagerMonitor @16@0:8
METHOD _screenTransform {?=[4]}16@0:8
METHOD _setBackingSize: v32@0:8{CGSize=dd}16
METHOD _setContentsScaleFactor: v20@0:8f16
METHOD _shouldDelegateARCompositing B16@0:8
METHOD _showsAuthoringEnvironment B16@0:8
METHOD _superSamplingFactor f16@0:8
METHOD _unprojectPoint:viewport: 48@0:81632
METHOD _updateEngineCallbacks v16@0:8
METHOD _viewport 16@0:8
METHOD _writeSubdivCacheForHash:dataProvider: v32@0:8@16@?24
METHOD antialiasingMode Q16@0:8
METHOD audioEngine @16@0:8
METHOD audioEnvironmentNode @16@0:8
METHOD audioListener @16@0:8
METHOD autoAdjustCamera B16@0:8
METHOD autoenablesDefaultLighting B16@0:8
METHOD currentCommandBuffer @16@0:8
METHOD currentRenderCommandEncoder @16@0:8
METHOD debugOptions Q16@0:8
METHOD forceAsyncShaderCompilation B16@0:8
METHOD frozen B16@0:8
METHOD hitTestWithSegmentFromPoint:toPoint:options: @56@0:81632@48
METHOD isJitteringEnabled B16@0:8
METHOD isNodeInsideFrustum:withPointOfView: B32@0:8@16@24
METHOD isTemporalAntialiasingEnabled B16@0:8
METHOD isVertexAmplificationEnabled B16@0:8
METHOD jitteringEnabled B16@0:8
METHOD nodesInsideFrustumWithPointOfView: @24@0:8@16
METHOD pointOfCulling @16@0:8
METHOD pointOfView @16@0:8
METHOD prepareObjects:withCompletionHandler: v32@0:8@16@?24
METHOD privateRendererOwner @16@0:8
METHOD programWithNode:withMaterial: @32@0:8@16@24
METHOD projectPoint: 32@0:816
METHOD renderContext:commandBufferDidCompleteWithError: v32@0:8@16@24
METHOD renderContext:didFallbackToDefaultTextureForSource:message: v40@0:8@16@24@32
METHOD renderMovieToURL:size:antialiasingMode:attributes:error: B64@0:8@16{CGSize=dd}24Q40@48^@56
METHOD renderWithViewport:commandBuffer:passDescriptor: v64@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56
METHOD resolvedBackgroundColorDidChange v16@0:8
METHOD setAntialiasingMode: v24@0:8Q16
METHOD setAudioListener: v24@0:8@16
METHOD setAutoAdjustCamera: v20@0:8B16
METHOD setAutoenablesDefaultLighting: v20@0:8B16
METHOD setDebugOptions: v24@0:8Q16
METHOD setJitteringEnabled: v20@0:8B16
METHOD setPointOfCulling: v24@0:8@16
METHOD setRendersContinuously: v20@0:8B16
METHOD setShowsStatistics: v20@0:8B16
METHOD setVertexAmplificationEnabled: v20@0:8B16
METHOD set_collectCompilationErrors: v20@0:8B16
METHOD set_computedLightingEnvironmentMapsPath: v24@0:8@16
METHOD set_drawableSafeAreaInsets: v32@0:816
METHOD set_enableARMode: v20@0:8B16
METHOD set_resourceManagerMonitor: v24@0:8@16
METHOD set_screenTransform: v80@0:8{?=[4]}16
METHOD set_shouldDelegateARCompositing: v20@0:8B16
METHOD set_superSamplingFactor: v20@0:8f16
METHOD set_viewport: v32@0:816
METHOD setupAuthoringEnvironment v16@0:8
METHOD temporalAntialiasingEnabled B16@0:8
METHOD updateAtTime: v24@0:8d16
METHOD vertexAmplificationEnabled B16@0:8
METHOD setWorld: v24@0:8@16
METHOD initWithCommandQueue: @24@0:8@16
METHOD setRendererKind: v24@0:8Q16
METHOD setRenderGraph: v24@0:8@16
METHOD _initWithDevice:options:isPrivateRenderer:privateRendererOwner:clearsOnDraw: @48@0:8@16@24B32@36B44
METHOD additiveWritesToAlpha B16@0:8
METHOD renderGraph @16@0:8
METHOD setAdditiveWritesToAlpha: v20@0:8B16
METHOD set_wantsWorldRendererDelegationMessages: v20@0:8B16
METHOD snapshotWithSize: @32@0:8{CGSize=dd}16
METHOD setPostRenderCallback: v24@0:8@?16
METHOD encodeWithCommandBuffer: v24@0:8@16
METHOD _render v16@0:8
METHOD renderWithTextureAttachmentProvider:options: v32@0:8@16@24
METHOD _legacyRenderer @16@0:8
METHOD _worldDidChange v16@0:8
METHOD hasMissingParticlePipelineState B16@0:8
METHOD unprojectPoints:count:viewport: v80@0:8^16Q24{?=dddddd}32
METHOD _cfxBackgroundColorDidChange v16@0:8
METHOD _createSnapshotWithSize:error: ^{CGImage=}40@0:8{CGSize=dd}16^@32
METHOD _currentProjectionMatrix {?=[4]}16@0:8
METHOD _currentViewMatrix {?=[4]}16@0:8
METHOD _defaultPOVForWorld: @24@0:8@16
METHOD _didPresentAtTime: v24@0:8d16
METHOD _didRenderWorld: v24@0:8@16
METHOD _drawablePropertiesDidChange v16@0:8
METHOD _endImGuiFrameAndRender v16@0:8
METHOD _initWithDevice:commandQueue:options:isPrivateRenderer:privateRendererOwner:clearsOnDraw: @56@0:8@16@24@32B40@44B52
METHOD _legacyAdditiveWritesToAlpha B16@0:8
METHOD _newLayeredRenderTargetWithSize:arrayLength: @36@0:8{CGSize=dd}16I32
METHOD _newRenderTargetWithSize: @32@0:8{CGSize=dd}16
METHOD _renderWithViewport:encoder:passDescriptor:commandQueue:commandBuffer: v80@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48@56@64@72
METHOD _renderWorldOrRemoteData v16@0:8
METHOD _rendererForPrepare @16@0:8
METHOD _setLegacyAdditiveWritesToAlpha: v20@0:8B16
METHOD _shouldForwardWorldRendererDelegationMessagesToPrivateRendererOwner B16@0:8
METHOD _startCaptureIfNeeded v16@0:8
METHOD _stopCapture v16@0:8
METHOD _supportsDidPresentDelegate B16@0:8
METHOD _triggersEnabled B16@0:8
METHOD _unprojectPoints:count:viewport: v48@0:8^16Q2432
METHOD _updateProbes:progress:completionHandler: v40@0:8@16@24@?32
METHOD _wantsWorldRendererDelegationMessages B16@0:8
METHOD _willRenderWorld: v24@0:8@16
METHOD beginShaderCacheRecording: v24@0:8@16
METHOD canRecycleParticleBuffers B16@0:8
METHOD captureNextFrame v16@0:8
METHOD clearBackBufferWithUpdate: v24@0:8@16
METHOD debugUIOptions Q16@0:8
METHOD decodeAndEnumerateRemoteFrame:usingBlock: v32@0:8@16@?24
METHOD decodeRemoteFrame:skipDrawCalls: v28@0:8@16B24
METHOD depthTexture @16@0:8
METHOD drawStatisticsIfNeeded v16@0:8
METHOD enableDeferredRendering B16@0:8
METHOD encodeRemoteFrameWithBuffers:textures: @32@0:8@16@24
METHOD finalizeEncoding v16@0:8
METHOD gpuDevice ^{__CFXGPUDevice=}16@0:8
METHOD hasImGuiFrameStarted B16@0:8
METHOD hasRenderableObjects B16@0:8
METHOD isEmulatingRRM B16@0:8
METHOD isEmulatingStereo B16@0:8
METHOD isSideBySideStereo B16@0:8
METHOD keepResourceManagerWhenDealloc B16@0:8
METHOD legacyRenderer @16@0:8
METHOD makeCompatibleRenderer @16@0:8
METHOD postRenderCallback @?16@0:8
METHOD projectPoints:count:viewport: v80@0:8^16Q24{?=dddddd}32
METHOD recordedShaderSourceCode @16@0:8
METHOD renderToTexture: v24@0:8@16
METHOD renderToTexture:options: v32@0:8@16@24
METHOD renderWithCommandBuffer:viewPoints:mode: v40@0:8@16@24Q32
METHOD rendererKind Q16@0:8
METHOD resourceConsumer @16@0:8
METHOD script_hitTest:options: @32@0:816@24
METHOD setCanRecycleParticleBuffers: v20@0:8B16
METHOD setDebugUIOptions: v24@0:8Q16
METHOD setDepthTexture: v24@0:8@16
METHOD setEmulateRRM: v20@0:8B16
METHOD setEmulateStereo: v20@0:8B16
METHOD setEnableDeferredRendering: v20@0:8B16
METHOD setKeepResourceManagerWhenDealloc: v20@0:8B16
METHOD setMetalDisplayLinkUpdate: v24@0:8@16
METHOD setNextFrameTime: v24@0:8d16
METHOD setShouldLoadFinalTexture: v20@0:8B16
METHOD setSideBySideStereo: v20@0:8B16
METHOD setWorld:completionHandler: v32@0:8@16@?24
METHOD set_legacyRenderer: v24@0:8@16
METHOD set_shouldForwardWorldRendererDelegationMessagesToPrivateRendererOwner: v20@0:8B16
METHOD set_triggersEnabled: v20@0:8B16
METHOD setupLegacyRendererWithCommandQueue: @24@0:8@16
METHOD shaderCacheRecordingEnabled B16@0:8
METHOD shouldLoadFinalTexture B16@0:8
METHOD showsDebugUI B16@0:8
METHOD snapshotImageWithSize: @32@0:8{CGSize=dd}16
METHOD snapshotImageWithSize:deltaTime: @40@0:8{CGSize=dd}16d32
METHOD snapshotWithSize:deltaTime: @40@0:8{CGSize=dd}16d32
METHOD startManipulatingPointOfView v16@0:8
METHOD stopManipulatingPointOfView v16@0:8
METHOD transferRenderGraphResourcesFrom: v24@0:8@16
METHOD updateProbes:atTime:completionHandler: v40@0:8@16d24@?32
METHOD viewWillDie v16@0:8

=== CLASS VFXSkinner ===
SUPER: NSObject
SIZE: 64
PROTOCOLS: VFXWorldReference VFXReferenceEnumerable NSSecureCoding
IVAR +8 0 _skinner ^{__CFXSkinner=}
IVAR +16 0 _isPresentationObject b1
IVAR +24 0 _world @"VFXWorld"
IVAR +32 0 _worldReferenceCounter I
IVAR +40 0 _baseGeometry @"<VFXGeometry>"
IVAR +48 0 _skeleton @"VFXNode"
IVAR +56 0 _bonesAndIndicesCompression B
CMETHOD avt_skinnerByInterpolatingFromSkinner:toSkinner:factor:skeleton: @44@0:8@16@24f32@36
CMETHOD supportsSecureCoding B16@0:8
CMETHOD _createSkinnerWithCompressedData:bonesCount:vertexCount: ^{__CFXSkinner=}40@0:8@16Q24Q32
CMETHOD skinnerWithBaseGeometry:bones:boneInverseBindTransforms:boneWeights:boneIndices: @56@0:8@16@24@32@40@48
CMETHOD skinnerWithSkinnerRef: @24@0:8^{__CFXSkinner=}16
CMETHOD skinnerWithBaseMesh:bones:boneInverseBindTransforms:boneWeights:boneIndices: @56@0:8@16@24@32@40@48
CMETHOD _createSkinnerWithBones:boneWeights:boneIndices:baseMesh: ^{__CFXSkinner=}48@0:8@16@24@32@40
METHOD avt_setSimdBaseMeshBindTransform: v80@0:8{?=[4]}16
METHOD avt_simdBaseGeometryBindTransform {?=[4]}16@0:8
METHOD dealloc v16@0:8
METHOD copy @16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD world @16@0:8
METHOD setSkeleton: v24@0:8@16
METHOD skeleton @16@0:8
METHOD joints @16@0:8
METHOD __CFObject ^v16@0:8
METHOD set_bonesAndIndicesCompression: v20@0:8B16
METHOD _bonesAndIndicesCompression B16@0:8
METHOD _setBaseGeometry: v24@0:8@16
METHOD _setSkeleton: B24@0:8@16
METHOD baseGeometry @16@0:8
METHOD baseGeometryBindTransform {?=[4]}16@0:8
METHOD boneIndices @16@0:8
METHOD boneInverseBindTransforms @16@0:8
METHOD boneWeights @16@0:8
METHOD bones @16@0:8
METHOD initWithSkinnerRef: @24@0:8^{__CFXSkinner=}16
METHOD setBaseGeometryBindTransform: v80@0:8{?=[4]}16
METHOD setBoneInverseBindTransforms: v24@0:8@16
METHOD setBones: v24@0:8@16
METHOD skinnerRef ^{__CFXSkinner=}16@0:8
METHOD setWorld: v24@0:8@16
METHOD baseMesh @16@0:8
METHOD baseMeshBindTransform {?=[4]}16@0:8
METHOD setBaseMeshBindTransform: v80@0:8{?=[4]}16
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD addWorldReference: v24@0:8@16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD removeWorldReference: v24@0:8@16
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXTransaction ===
SUPER: NSObject
SIZE: 8
CMETHOD lock v16@0:8
CMETHOD unlock v16@0:8
CMETHOD completionBlock @?16@0:8
CMETHOD currentState I16@0:8
CMETHOD duration d16@0:8
CMETHOD setCompletionBlock: v24@0:8@?16
CMETHOD setValue:forKey: v32@0:8@16@24
CMETHOD valueForKey: @24@0:8@16
CMETHOD begin v16@0:8
CMETHOD commit v16@0:8
CMETHOD setDuration: v24@0:8d16
CMETHOD flush v16@0:8
CMETHOD beginTime d16@0:8
CMETHOD setBeginTime: v24@0:8d16
CMETHOD setTimingFunction: v24@0:8@16
CMETHOD timingFunction @16@0:8
CMETHOD setDisableActions: v20@0:8B16
CMETHOD animationDuration d16@0:8
CMETHOD animationTimingFunction @16@0:8
CMETHOD disableActions B16@0:8
CMETHOD setAnimationDuration: v24@0:8d16
CMETHOD setAnimationTimingFunction: v24@0:8@16
CMETHOD commitImmediate v16@0:8
CMETHOD checkUncommittedTransactions v16@0:8
CMETHOD enqueueCommandForObject:immediateTransactionBlock: v32@0:8@16@?24
CMETHOD immediateMode B16@0:8
CMETHOD immediateModeRestrictedContext ^{__CFXWorld=}16@0:8
CMETHOD setImmediateMode: B20@0:8B16
CMETHOD setImmediateModeRestrictedContext: v24@0:8^{__CFXWorld=}16
CMETHOD performPresentationObjectQueriesInWorld:usingBlock: v32@0:8@16@?24
CMETHOD setImmediateModeWithAtomicTime: v24@0:8d16
CMETHOD postCommandAvoidingImmediateModeWithWorldRef:applyBlock: v32@0:8^v16@?24
CMETHOD postCommandWithObject:applyBlock: v32@0:8@16@?24
CMETHOD postCommandWithObject:key:applyBlock: v40@0:8@16@24@?32
CMETHOD postCommandWithObject:key:subscriptIndex:derivedKeyPath:applyBlock: v56@0:8@16@24Q32@40@?48
CMETHOD postCommandWithObject:key:subscriptKey:derivedKeyPath:applyBlock: v56@0:8@16@24@32@40@?48
CMETHOD postCommandWithObject:keyPath:applyBlock: v40@0:8@16@24@?32
CMETHOD postCommandWithWorldRef:applyBlock: v32@0:8^v16@?24
CMETHOD postReleaseCommandWithCFXObject: v24@0:8^v16
CMETHOD setAnimationDurationAsFloat: v20@0:8f16
CMETHOD setCurrentThreadImmediateMode: v20@0:8B16
METHOD lock v16@0:8
METHOD unlock v16@0:8
METHOD begin v16@0:8
METHOD commit v16@0:8
METHOD flush v16@0:8
METHOD setDisableActions: v20@0:8B16
METHOD animationDuration d16@0:8
METHOD animationTimingFunction @16@0:8
METHOD disableActions B16@0:8
METHOD setAnimationDuration: v24@0:8d16
METHOD setAnimationTimingFunction: v24@0:8@16

=== CLASS VFXView ===
SUPER: UIView
SIZE: 600
PROTOCOLS: VFXWorldRenderer
IVAR +408 0 _currentSystemTime d
IVAR +416 0 _lastUpdate d
IVAR +424 0 _isOpaque b1
IVAR +424 0 _rendersContinuously b1
IVAR +424 0 _wantsHDR b1
IVAR +424 0 _firstDrawDone b1
IVAR +424 0 _drawOnMainThreadPending b1
IVAR +424 0 _viewIsOffscreen b1
IVAR +424 0 _appChangedColorAppearance b1
IVAR +424 0 _appIsDeactivated b1
IVAR +425 0 _autoPausedWorld b1
IVAR +425 0 _inRenderQueueForLayerBackedGLRendering b1
IVAR +425 0 _isInLiveResize b1
IVAR +425 0 _usesCustomScaleFactor b1
IVAR +425 0 _usesCustomPixelFormat b1
IVAR +425 0 _usesCustomColorSpace b1
IVAR +426 0 _isHidden B
IVAR +427 0 _lowLatency B
IVAR +428 0 _didTriggerRedrawWhileRendering B
IVAR +432 0 _delegate @
IVAR +440 0 _renderer @"VFXRenderer"
IVAR +448 0 _world @"VFXWorld"
IVAR +456 0 _displayLinkCreationRequested B
IVAR +464 0 _displayLink @"VFXDisplayLink"
IVAR +472 0 _preferredFramePerSeconds q
IVAR +480 0 _backingLayer @"CAMetalLayer"
IVAR +488 0 _otherMouseEventMonitor @
IVAR +496 0 _shouldHandleOtherMouseButtonDrag B
IVAR +504 0 _jitterer @"VFXJitterer"
IVAR +512 0 _lock @"VFXRecursiveLock"
IVAR +520 0 _backgroundColor @"UIColor"
IVAR +528 0 _boundsSize {CGSize="width"d"height"d}
IVAR +544 0 _snapshotImageData *
IVAR +552 0 _snapshotImageDataLength Q
IVAR +560 0 _navigationCameraController @"<VFXEventHandler>"
IVAR +568 0 _imguiHandleMouseDown B
IVAR +576 0 _device @"<MTLDevice>"
IVAR +584 0 _controllerGestureRecognizers @"NSArray"
IVAR +592 0 _legacyView @"_TtC3VFX13VFXViewLegacy"
CMETHOD automaticallyNotifiesObserversForKey: B24@0:8@16
CMETHOD keyPathsForValuesAffectingValueForKey: @24@0:8@16
CMETHOD layerClass #16@0:8
CMETHOD _kvoKeysForwardedToRenderer @16@0:8
CMETHOD deviceForOptions: @24@0:8@16
CMETHOD shouldObserveApplicationStateToPreventBackgroundGPUAccess B16@0:8
METHOD avt_simdProjectPoint: 32@0:816
METHOD avt_simdUnprojectPoint: 32@0:816
METHOD avt_simdViewport 16@0:8
METHOD dealloc v16@0:8
METHOD description @16@0:8
METHOD init @16@0:8
METHOD delegate @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD initWithCoder: @24@0:8@16
METHOD lock v16@0:8
METHOD setDelegate: v24@0:8@16
METHOD setHidden: v20@0:8B16
METHOD unlock v16@0:8
METHOD observeValueForKeyPath:ofObject:change:context: v48@0:8@16@24@32^v40
METHOD snapshot @16@0:8
METHOD statistics @16@0:8
METHOD setPixelFormat: v24@0:8Q16
METHOD setScaleFactor: v24@0:8d16
METHOD colorSpace ^{CGColorSpace=}16@0:8
METHOD commandQueue @16@0:8
METHOD device @16@0:8
METHOD isOpaque B16@0:8
METHOD pixelFormat Q16@0:8
METHOD scaleFactor d16@0:8
METHOD setBinaryArchives: v24@0:8@16
METHOD setColorSpace: v24@0:8^{CGColorSpace=}16
METHOD workingColorSpace ^{CGColorSpace=}16@0:8
METHOD eventHandler @16@0:8
METHOD setEventHandler: v24@0:8@16
METHOD backgroundColor @16@0:8
METHOD contentScaleFactor d16@0:8
METHOD initWithFrame: @48@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16
METHOD setBackgroundColor: v24@0:8@16
METHOD setNeedsDisplay v16@0:8
METHOD didMoveToWindow v16@0:8
METHOD setDisplayLink: v24@0:8@16
METHOD _controlsOwnScaleFactor B16@0:8
METHOD _screenSize 16@0:8
METHOD _updateOpacity v16@0:8
METHOD displayLink @16@0:8
METHOD effect @16@0:8
METHOD hitTest:withEvent: @40@0:8{CGPoint=dd}16@32
METHOD invalidateDisplayLink v16@0:8
METHOD layoutSubviews v16@0:8
METHOD lowLatency B16@0:8
METHOD renderMode Q16@0:8
METHOD resizingMode C16@0:8
METHOD safeAreaInsetsDidChange v16@0:8
METHOD scene @16@0:8
METHOD setContentScaleFactor: v24@0:8d16
METHOD setEffect: v24@0:8@16
METHOD setLowLatency: v20@0:8B16
METHOD setPreferredFramesPerSecond: v24@0:8q16
METHOD setRenderMode: v24@0:8Q16
METHOD setResizingMode: v20@0:8C16
METHOD setScene: v24@0:8@16
METHOD touchesBegan:withEvent: v32@0:8@16@24
METHOD touchesCancelled:withEvent: v32@0:8@16@24
METHOD touchesEnded:withEvent: v32@0:8@16@24
METHOD touchesMoved:withEvent: v32@0:8@16@24
METHOD traitCollectionDidChange: v24@0:8@16
METHOD willMoveToWindow: v24@0:8@16
METHOD framebufferOnly B16@0:8
METHOD preferredFramesPerSecond q16@0:8
METHOD setFramebufferOnly: v20@0:8B16
METHOD hitTest:options: @40@0:8{CGPoint=dd}16@32
METHOD world @16@0:8
METHOD renderer @16@0:8
METHOD _enterBackground: v24@0:8@16
METHOD applyConfiguration: v24@0:8@16
METHOD _defaultBackgroundColor @16@0:8
METHOD currentRenderPassDescriptor @16@0:8
METHOD pauseDisplayLink v16@0:8
METHOD binaryArchives @16@0:8
METHOD _flipY: f20@0:8f16
METHOD _renderingQueue @16@0:8
METHOD currentViewport {CGRect={CGPoint=dd}{CGSize=dd}}16@0:8
METHOD prepareObject:shouldAbortBlock: B32@0:8@16@?24
METHOD _addGPUFrameCompletedHandler: v24@0:8@?16
METHOD _addGPUFrameScheduledHandler: v24@0:8@?16
METHOD _adjustBackingLayerPixelFormat v16@0:8
METHOD setTemporalAntialiasingEnabled: v20@0:8B16
METHOD set_commandBufferStatusMonitor: v24@0:8@16
METHOD showsStatistics B16@0:8
METHOD _backgroundDidChange v16@0:8
METHOD __CFObject ^v16@0:8
METHOD _addGPUFramePresentedHandler: v24@0:8@?16
METHOD _allowGPUBackgroundExecution v16@0:8
METHOD setPointOfView: v24@0:8@16
METHOD _authoringEnvironment @16@0:8
METHOD unprojectPoint: 32@0:816
METHOD _canJitter B16@0:8
METHOD _checkAndUpdateDisplayLinkStateIfNeeded B16@0:8
METHOD _commandBufferStatusMonitor @16@0:8
METHOD _commonInit: v24@0:8@16
METHOD _contentsScaleFactor f16@0:8
METHOD _createDisplayLinkIfNeeded v16@0:8
METHOD _discardPendingGPUFrameCompletedHandlers v16@0:8
METHOD _discardPendingGPUFramePresentedHandlers v16@0:8
METHOD _discardPendingGPUFrameScheduledHandlers v16@0:8
METHOD _enableARMode B16@0:8
METHOD _enterForeground: v24@0:8@16
METHOD _isEditor B16@0:8
METHOD _jitterRedisplay v16@0:8
METHOD _renderThreadPriority d16@0:8
METHOD _resetContentsScaleFactor v16@0:8
METHOD _resourceManagerMonitor @16@0:8
METHOD _screenTransform {?=[4]}16@0:8
METHOD _setNeedsDisplay v16@0:8
METHOD _shouldDelegateARCompositing B16@0:8
METHOD _showsAuthoringEnvironment B16@0:8
METHOD _superSamplingFactor f16@0:8
METHOD _systemTimeAnimationStarted: v24@0:8@16
METHOD _updateBackingSize {CGSize=dd}16@0:8
METHOD _updateContentsScaleFactor v16@0:8
METHOD _viewport 16@0:8
METHOD allowsCameraControl B16@0:8
METHOD antialiasingMode Q16@0:8
METHOD audioEngine @16@0:8
METHOD audioEnvironmentNode @16@0:8
METHOD audioListener @16@0:8
METHOD autoenablesDefaultLighting B16@0:8
METHOD backingSizeForBoundSize: {CGSize=dd}32@0:8{CGSize=dd}16
METHOD cameraControlConfiguration @16@0:8
METHOD currentRenderCommandEncoder @16@0:8
METHOD debugOptions Q16@0:8
METHOD defaultCameraController @16@0:8
METHOD eventHandlerWantsRedraw v16@0:8
METHOD hitTestWithSegmentFromPoint:toPoint:options: @56@0:81632@48
METHOD initWithFrame:options: @56@0:8{CGRect={CGPoint=dd}{CGSize=dd}}16@48
METHOD isJitteringEnabled B16@0:8
METHOD isNodeInsideFrustum:withPointOfView: B32@0:8@16@24
METHOD isTemporalAntialiasingEnabled B16@0:8
METHOD navigationCameraController @16@0:8
METHOD nodesInsideFrustumWithPointOfView: @24@0:8@16
METHOD pointOfCulling @16@0:8
METHOD pointOfView @16@0:8
METHOD prepareObjects:withCompletionHandler: v32@0:8@16@?24
METHOD projectPoint: 32@0:816
METHOD rendersContinuously B16@0:8
METHOD resumeDisplayLink v16@0:8
METHOD setAllowsCameraControl: v20@0:8B16
METHOD setAntialiasingMode: v24@0:8Q16
METHOD setAudioListener: v24@0:8@16
METHOD setAutoenablesDefaultLighting: v20@0:8B16
METHOD setDebugOptions: v24@0:8Q16
METHOD setJitteringEnabled: v20@0:8B16
METHOD setNavigationCameraController: v24@0:8@16
METHOD setPointOfCulling: v24@0:8@16
METHOD setPointOfView:animate: v28@0:8@16B24
METHOD setRendersContinuously: v20@0:8B16
METHOD setShowsStatistics: v20@0:8B16
METHOD setWantsHDR: v20@0:8B16
METHOD set_enableARMode: v20@0:8B16
METHOD set_resourceManagerMonitor: v24@0:8@16
METHOD set_screenTransform: v80@0:8{?=[4]}16
METHOD set_shouldDelegateARCompositing: v20@0:8B16
METHOD set_superSamplingFactor: v20@0:8f16
METHOD switchToCameraNamed: v24@0:8@16
METHOD switchToNextCamera v16@0:8
METHOD updateAtTime: v24@0:8d16
METHOD wantsHDR B16@0:8
METHOD setWorld: v24@0:8@16
METHOD setRendererKind: v24@0:8Q16
METHOD setRenderGraph: v24@0:8@16
METHOD _drawWithUpdate: v24@0:8@16
METHOD additiveWritesToAlpha B16@0:8
METHOD renderGraph @16@0:8
METHOD setAdditiveWritesToAlpha: v20@0:8B16
METHOD set_wantsWorldRendererDelegationMessages: v20@0:8B16
METHOD setPostRenderCallback: v24@0:8@?16
METHOD setWantsExtendedDynamicRange: v20@0:8B16
METHOD _worldDidUpdateEnabledTriggers: v24@0:8@16
METHOD set_legacyView: v24@0:8@16
METHOD setupLegacyView @16@0:8
METHOD triggersEnabled B16@0:8
METHOD _resizeIfNeeded v16@0:8
METHOD _initializeDisplayLinkWithCompletionHandler: v24@0:8@?16
METHOD _legacyView @16@0:8
METHOD _rendererForPrepare @16@0:8
METHOD _updateProbes:progress: v32@0:8@16@24
METHOD _wantsWorldRendererDelegationMessages B16@0:8
METHOD _worldDidUpdate: v24@0:8@16
METHOD debugUIOptions Q16@0:8
METHOD displayLink:didUpdate: v32@0:8@16@24
METHOD isEmulatingRRM B16@0:8
METHOD isEmulatingStereo B16@0:8
METHOD legacyView @16@0:8
METHOD postRenderCallback @?16@0:8
METHOD renderWithCompletion: v24@0:8@?16
METHOD renderWithPresentWithTransaction:completion: v28@0:8B16@?20
METHOD rendererKind Q16@0:8
METHOD script_hitTest:options: @32@0:816@24
METHOD setDebugUIOptions: v24@0:8Q16
METHOD setEmulateRRM: v20@0:8B16
METHOD setEmulateStereo: v20@0:8B16
METHOD setTriggersEnabled: v20@0:8B16
METHOD showsDebugUI B16@0:8
METHOD updateLayerLatency v16@0:8
METHOD vfx_backingLayer @16@0:8
METHOD vfx_inLiveResize B16@0:8
METHOD vfx_setBackingLayer: v24@0:8@16
METHOD vfx_setGestureRecognizers: v24@0:8@16
METHOD vfx_updateGestureRecognizers v16@0:8
METHOD wantsExtendedDynamicRange B16@0:8

=== CLASS VFXWorld ===
SUPER: NSObject
SIZE: 328
PROTOCOLS: VFXBehaviorSupport VFXParameterizable VFXWorldReference VFXReferenceEnumerable VFXEntityProvider VFXTransactionCommandObject VFXBehaviorSupport VFXAnimatable VFXStateSupport VFXParameterizable NSSecureCoding NSCopying
IVAR +8 0 _world ^{__CFXWorld=}
IVAR +16 0 _isPresentationObject b1
IVAR +24 0 _presentationObject @"VFXWorld"
IVAR +32 0 _assetPathResolver @"<VFXAssetPathResolver>"
IVAR +40 0 _defaultRenderGraph @"VFXRenderGraph"
IVAR +48 0 _defaultPointOfView @"VFXNode"
IVAR +56 0 _preferredConfiguration @"VFXViewConfiguration"
IVAR +64 0 _physicsWorld @"VFXPhysicsWorld"
IVAR +72 0 _rootNode @"VFXNode"
IVAR +80 0 _layerRootNode [4@"VFXNode"]
IVAR +112 0 _background @"VFXMaterialProperty"
IVAR +120 0 _environment @"VFXMaterialProperty"
IVAR +128 0 _userAttributes @"NSMutableDictionary"
IVAR +136 0 _fogStartDistance f
IVAR +140 0 _fogEndDistance f
IVAR +144 0 _fogDensityExponent f
IVAR +152 0 _fogColor @
IVAR +160 0 _wantsScreenSpaceAmbientOcclusion B
IVAR +164 0 _screenSpaceAmbientOcclusionIntensity f
IVAR +168 0 _screenSpaceAmbientOcclusionRadius f
IVAR +172 0 _screenSpaceAmbientOcclusionEnableBentNormal B
IVAR +176 0 _screenSpaceAmbientOcclusionQuality q
IVAR +184 0 _wantsScreenSpaceReflection B
IVAR +192 0 _screenSpaceReflectionQuality q
IVAR +200 0 _screenSpaceReflectionThicknessMode q
IVAR +208 0 _screenSpaceReflectionObjectThickness f
IVAR +216 0 _clock @"VFXClock"
IVAR +224 0 _lastUpdateTime d
IVAR +232 0 _assetRegistry @"VFXAssetRegistry"
IVAR +240 0 _behaviorGraph @"VFXBehaviorGraph"
IVAR +248 0 _stateManager @"VFXStateManager"
IVAR +256 0 _shaderCacheConfigurations @"NSArray"
IVAR +264 0 _coreEntityManager ^{__CFXCoreEntityManager=}
IVAR +272 0 _modelToPresentationRemapTable @"VFXBidirectionalRemapTable"
IVAR +280 0 _allowsDefaultLightingEnvironmentFallback B
IVAR +288 0 _authoringEnvironment2 @"VFXAuthoringEnvironment2"
IVAR +296 0 _triggerManager @"VFXTriggerManager"
IVAR +304 0 _animationsLock {os_unfair_lock_s="_os_unfair_lock_opaque"I}
IVAR +312 0 _animations @"VFXOrderedDictionary"
IVAR +320 0 _bindings @"NSMutableDictionary"
CMETHOD avt_newWorldWithURL:options:error: @40@0:8@16@24^@32
CMETHOD avt_nodeNamed:forWorldAtURL:options:error: @48@0:8@16@24@32^@40
CMETHOD avt_rootNodeForWorldAtURL:options:error: @40@0:8@16@24^@32
CMETHOD avt_rootObjectForWorldAtURL:options:error: @40@0:8@16@24^@32
CMETHOD supportsSecureCoding B16@0:8
CMETHOD world @16@0:8
CMETHOD canImportFileExtension: B24@0:8@16
CMETHOD _indexPathForNode: @24@0:8@16
CMETHOD canImportFileUTI: B24@0:8@16
CMETHOD jsConstructor :16@0:8
CMETHOD supportedFileUTIsForExport @16@0:8
CMETHOD supportedFileUTIsForImport @16@0:8
CMETHOD worldWithURL:options:error: @40@0:8@16@24^@32
CMETHOD worldWithSceneKitScene:options: @32@0:8@16@24
CMETHOD worldNamed:inDirectory:options: @40@0:8@16@24@32
CMETHOD worldNamed: @24@0:8@16
CMETHOD worldNamed:options: @32@0:8@16@24
CMETHOD worldWithData:options:error: @40@0:8@16@24^@32
CMETHOD worldWithMDLAsset: @24@0:8@16
CMETHOD worldWithMDLAsset:options: @32@0:8@16@24
CMETHOD worldWithSCNURL:options:error: @40@0:8@16@24^@32
CMETHOD worldWithWorldRef: @24@0:8^{__CFXWorld=}16
METHOD _implementCEKWorkaroundIfNeeded v16@0:8
METHOD avt_writeByArchivingRootNodeInsteadOfScene:toURL:options:error: B44@0:8B16@20@28^@36
METHOD avt_fixQuirksOfNewUSDSchemaWithOptions:handler: v32@0:8Q16@?24
METHOD avt_init @16@0:8
METHOD avt_removeDuplicateSkeletonRootWithHandler: v24@0:8@?16
METHOD avt_removeFaceSetsExportedAsDummyNodesWithHandler: v24@0:8@?16
METHOD avt_setInitialValuesExportedAsAnimationsWithWithOptions:handler: v32@0:8Q16@?24
METHOD dealloc v16@0:8
METHOD copyWithZone: @24@0:8^{_NSZone=}16
METHOD init @16@0:8
METHOD encodeWithCoder: v24@0:8@16
METHOD identifier @16@0:8
METHOD initWithCoder: @24@0:8@16
METHOD lock v16@0:8
METHOD state @16@0:8
METHOD unlock v16@0:8
METHOD initWithOptions: @24@0:8@16
METHOD rootNode @16@0:8
METHOD setValue:forUndefinedKey: v32@0:8@16@24
METHOD valueForUndefinedKey: @24@0:8@16
METHOD setState: v24@0:8@16
METHOD parameters @16@0:8
METHOD setIdentifier: v24@0:8@16
METHOD debugQuickLookObject @16@0:8
METHOD root @16@0:8
METHOD states @16@0:8
METHOD startTime d16@0:8
METHOD setStartTime: v24@0:8d16
METHOD frameRate d16@0:8
METHOD addAnimation: v24@0:8@16
METHOD addAnimation:forKey: v32@0:8@16@24
METHOD animationKeys @16@0:8
METHOD background @16@0:8
METHOD clock @16@0:8
METHOD lastUpdateTime d16@0:8
METHOD removeAllAnimations v16@0:8
METHOD removeAnimationForKey: v24@0:8@16
METHOD scene @16@0:8
METHOD setLastUpdateTime: v24@0:8d16
METHOD endTime d16@0:8
METHOD setEndTime: v24@0:8d16
METHOD assets @16@0:8
METHOD world @16@0:8
METHOD dataRepresentationWithOptions: @24@0:8@16
METHOD playbackSpeed f16@0:8
METHOD setPlaybackSpeed: v20@0:8f16
METHOD setFrameRate: v24@0:8d16
METHOD restart v16@0:8
METHOD preferredConfiguration @16@0:8
METHOD setUpAxis: v32@0:816
METHOD upAxis 16@0:8
METHOD stateManager @16@0:8
METHOD __removeAnimation:forKey: B32@0:8@16@24
METHOD __CFObject ^v16@0:8
METHOD _allowsDefaultLightingEnvironmentFallback B16@0:8
METHOD _copyAnimationsFrom: v24@0:8@16
METHOD _dumpToDisk v16@0:8
METHOD _exportAsMovieOperationWithDestinationURL:size:attributes:delegate:didEndSelector:userInfo: @72@0:8@16{CGSize=dd}24@40@48:56^v64
METHOD _nodeWithIndexPath: @24@0:8@16
METHOD _pauseAnimation:forKey:pausedByNode: v32@0:8B16@20B28
METHOD _physicsWorldCreateIfNeeded: @20@0:8B16
METHOD _subnodeFromIndexPath: @24@0:8@16
METHOD _syncObjCAnimations v16@0:8
METHOD addAnimationPlayer:forKey: v32@0:8@16@24
METHOD animationManager ^{__CFXAnimationManager=}16@0:8
METHOD animationPlayerForKey: @24@0:8@16
METHOD authoringEnvironment2 @16@0:8
METHOD bindAnimatablePath:toObject:withKeyPath:options: v48@0:8@16@24@32@40
METHOD copyAnimationChannelForKeyPath:animation: @32@0:8@16@24
METHOD copyAnimationChannelForKeyPath:property: @32@0:8@16@24
METHOD debugQuickLookObjectWithPointOfView: @24@0:8@16
METHOD exportAsMovieOperationWithDestinationURL:size:attributes:delegate:didEndSelector:userInfo: @72@0:8@16{CGSize=dd}24@40@48:56^v64
METHOD fogColor @16@0:8
METHOD fogDensityExponent f16@0:8
METHOD fogEndDistance f16@0:8
METHOD fogStartDistance f16@0:8
METHOD initForJavascript: @24@0:8@16
METHOD lightingEnvironment @16@0:8
METHOD physicsWorld @16@0:8
METHOD removeAllAnimationsWithBlendOutDuration: v20@0:8f16
METHOD removeAllBindings v16@0:8
METHOD removeAnimationForKey:blendOutDuration: v28@0:8@16f24
METHOD rootNodeForLayer: @20@0:8i16
METHOD screenSpaceAmbientOcclusionIntensity f16@0:8
METHOD screenSpaceAmbientOcclusionRadius f16@0:8
METHOD setFogColor: v24@0:8@16
METHOD setFogDensityExponent: v20@0:8f16
METHOD setFogEndDistance: v20@0:8f16
METHOD setFogStartDistance: v20@0:8f16
METHOD setRootNode: v24@0:8@16
METHOD setRootNode:forLayer: v28@0:8@16i24
METHOD setScreenSpaceAmbientOcclusionIntensity: v20@0:8f16
METHOD setScreenSpaceAmbientOcclusionRadius: v20@0:8f16
METHOD setWantsScreenSpaceReflection: v20@0:8B16
METHOD set_allowsDefaultLightingEnvironmentFallback: v20@0:8B16
METHOD unbindAnimatablePath: v24@0:8@16
METHOD wantsScreenSpaceReflection B16@0:8
METHOD writeToURLWithUSDKit: B24@0:8@16
METHOD assetRegistry @16@0:8
METHOD behaviorGraph @16@0:8
METHOD _vfxDeprecatedAddAnimation:forKey: v32@0:8@16@24
METHOD prepareForRenderer:progressHandler: v32@0:8@16@?24
METHOD mergeWorld:parentNode:parentAssetNode: v40@0:8@16@24@32
METHOD prepareWithRenderer: v24@0:8@16
METHOD presentationObject @16@0:8
METHOD presentationScene @16@0:8
METHOD setPeerPid: v20@0:8i16
METHOD setPeerTaskIdentity: v20@0:8I16
METHOD updateMemoryOwnership v16@0:8
METHOD defaultPointOfView @16@0:8
METHOD writeToURL:options:progressHandler: B40@0:8@16@24@?32
METHOD triggerManager @16@0:8
METHOD sendSignalWithIdentifier:delay: v28@0:8@16f24
METHOD setFogColor_linearExtendedSRGB: v32@0:816
METHOD stopReplication v16@0:8
METHOD _worlds @16@0:8
METHOD peerPid i16@0:8
METHOD _clearWorldRef v16@0:8
METHOD _copyAndCompile: @20@0:8B16
METHOD _copyBindingsFrom: v24@0:8@16
METHOD _copyInto:compile: v28@0:8@16B24
METHOD _mergeWorld:parentNode:parentAssetNode:remapEntities: v44@0:8@16@24@32B40
METHOD _remapEntities:srcWorldIdentifier: v32@0:8@16@24
METHOD _remapObjects:remapTable: v32@0:8@16^{__CFDictionary=}24
METHOD _scaleWorldBy: v20@0:8f16
METHOD _sendSignalWithIdentifier:delay: v28@0:8@16f24
METHOD _setRootNode:immediate: v28@0:8@16B24
METHOD _setSourceObject:forBinding: v32@0:8@16@24
METHOD _updateModelFromPresentation v16@0:8
METHOD _updatePresentationFromModel v16@0:8
METHOD _vfxAnimationForKey: @24@0:8@16
METHOD _vfxBindings @16@0:8
METHOD assetPathResolver @16@0:8
METHOD bridgedComponentNames @16@0:8
METHOD buildIdentifierRemapTable @16@0:8
METHOD cleanupPrefabsReferences v16@0:8
METHOD cloneModelToPresentationAndStartReplicationStream v16@0:8
METHOD collectCoreEntityHandles @16@0:8
METHOD commonInit: v20@0:8B16
METHOD copyAndCompileScripts @16@0:8
METHOD coreEntity q16@0:8
METHOD defaultRenderGraph @16@0:8
METHOD enumerateAnimationReferencesUsingBlock: v24@0:8@?16
METHOD enumerateReferencesForOperation:usingBlock: v32@0:8q16@?24
METHOD fogColor_linearExtendedSRGB 16@0:8
METHOD initPresentationWorldWithWorldRef: @24@0:8^{__CFXWorld=}16
METHOD initWithWorldRef: @24@0:8^{__CFXWorld=}16
METHOD initializeCoreEntityManagerWithInfo:error: B32@0:8@16^@24
METHOD isPresentationObject B16@0:8
METHOD loadCoreEntityManagerFromURL:options:infoOut:error: B48@0:8@16@24@32^@40
METHOD loadMDLAsset:options:context: v40@0:8@16@24@32
METHOD loadSCN:options:error: v40@0:8@16@24^@32
METHOD migrateCoreEntityManagerWithInfo:error: B32@0:8@16^@24
METHOD mutex ^{_opaque_pthread_mutex_t=q[56c]}16@0:8
METHOD peerTaskIdentity I16@0:8
METHOD presentationEntityFromModel: q24@0:8q16
METHOD presentationWorld @16@0:8
METHOD remapTable @16@0:8
METHOD replicateToRuntimeAndStartReplicationWithOptions: v24@0:8@16
METHOD resolveVFXCoreAndTagReferences v16@0:8
METHOD screenSpaceAmbientOcclusionEnableBentNormal B16@0:8
METHOD screenSpaceAmbientOcclusionQuality q16@0:8
METHOD screenSpaceReflectionObjectThickness f16@0:8
METHOD screenSpaceReflectionQuality q16@0:8
METHOD screenSpaceReflectionThicknessMode q16@0:8
METHOD setAssetPathResolver: v24@0:8@16
METHOD setAuthoringEnvironment2: v24@0:8@16
METHOD setBehaviorGraph: v24@0:8@16
METHOD setDefaultPointOfView: v24@0:8@16
METHOD setDefaultRenderGraph: v24@0:8@16
METHOD setReplicationDelegate: v24@0:8@16
METHOD setScreenSpaceAmbientOcclusionEnableBentNormal: v20@0:8B16
METHOD setScreenSpaceAmbientOcclusionQuality: v24@0:8q16
METHOD setScreenSpaceReflectionObjectThickness: v20@0:8f16
METHOD setScreenSpaceReflectionQuality: v24@0:8q16
METHOD setScreenSpaceReflectionThicknessMode: v24@0:8q16
METHOD setShaderCacheConfigurations: v24@0:8@16
METHOD setStateNamed: v24@0:8@16
METHOD setWantsScreenSpaceAmbientOcclusion: v20@0:8B16
METHOD shaderCacheConfigurations @16@0:8
METHOD snapshotWithSize:pointOfView: @40@0:8{CGSize=dd}16@32
METHOD startRuntimeThread v16@0:8
METHOD wantsScreenSpaceAmbientOcclusion B16@0:8
METHOD worldRef ^{__CFXWorld=}16@0:8

=== CLASS VFXWorld_CEKWorkaround ===
SUPER: VFXWorld
SIZE: 328

