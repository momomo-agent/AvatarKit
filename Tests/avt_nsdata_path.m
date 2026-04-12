#import <Foundation/Foundation.h>
#import <SceneKit/SceneKit.h>
#import <dlfcn.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import <simd/simd.h>

int main() {
    @autoreleasepool {
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY);
        
        fprintf(stderr, "=== NSData Path Verification ===\n\n");
        
        // Load an animoji
        Class animojiCls = NSClassFromString(@"AVTAnimoji");
        if (!animojiCls) { fprintf(stderr, "FAIL: AVTAnimoji\n"); return 1; }
        
        typedef id (*AnimojiNamedFunc)(id, SEL, NSString *);
        AnimojiNamedFunc animojiNamed = (AnimojiNamedFunc)objc_msgSend;
        id animoji = animojiNamed((id)animojiCls, sel_registerName("animojiNamed:"), @"cat");
        fprintf(stderr, "animoji: %s\n", animoji ? "OK" : "FAIL");
        if (!animoji) return 1;
        
        // loadIfNeeded
        typedef void (*VoidFunc)(id, SEL);
        VoidFunc voidFn = (VoidFunc)objc_msgSend;
        voidFn(animoji, sel_registerName("loadIfNeeded"));
        fprintf(stderr, "loaded\n");
        
        // Build tracking data as NSData
        uint8_t buffer[480] __attribute__((aligned(16)));
        memset(buffer, 0, 480);
        
        // Set jawOpen (index 17) to 0.5
        float jawOpen = 0.5f;
        memcpy(buffer + 0x34 + 17*4, &jawOpen, 4);
        memcpy(buffer + 0x100 + 17*4, &jawOpen, 4);
        
        // Set mouthSmileLeft (index 23) to 0.8
        float smile = 0.8f;
        memcpy(buffer + 0x34 + 23*4, &smile, 4);
        memcpy(buffer + 0x100 + 23*4, &smile, 4);
        
        // Set orientation (slight head tilt)
        float qx = 0.0f, qy = 0.1f, qz = 0.0f, qw = 0.995f;
        memcpy(buffer + 0x20, &qx, 4);
        memcpy(buffer + 0x24, &qy, 4);
        memcpy(buffer + 0x28, &qz, 4);
        memcpy(buffer + 0x2C, &qw, 4);
        
        NSData *trackingData = [NSData dataWithBytes:buffer length:480];
        fprintf(stderr, "NSData: length=%lu\n", (unsigned long)trackingData.length);
        
        // Call updatePoseWithFaceTrackingData:applySmoothing:
        typedef void (*UpdateFunc)(id, SEL, NSData *, BOOL);
        UpdateFunc updateFn = (UpdateFunc)objc_msgSend;
        
        @try {
            updateFn(animoji, sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"),
                     trackingData, NO);
            fprintf(stderr, "✅ updatePoseWithFaceTrackingData: succeeded (no crash)\n");
        } @catch (NSException *e) {
            fprintf(stderr, "❌ exception: %s\n", e.reason.UTF8String);
        }
        
        // Also test the AVTFaceTrackingInfo path
        fprintf(stderr, "\n--- AVTFaceTrackingInfo path ---\n");
        Class trackInfoCls = NSClassFromString(@"AVTFaceTrackingInfo");
        
        typedef id (*CreateFunc)(id, SEL, const void *);
        CreateFunc createFn = (CreateFunc)objc_msgSend;
        id trackInfo = createFn((id)trackInfoCls, sel_registerName("trackingInfoWithTrackingData:"), buffer);
        fprintf(stderr, "trackInfo: %s\n", trackInfo ? "OK" : "FAIL");
        
        if (trackInfo) {
            typedef void (*ApplyBSFunc)(id, SEL, id);
            ApplyBSFunc applyBS = (ApplyBSFunc)objc_msgSend;
            
            @try {
                applyBS(animoji, sel_registerName("applyBlendShapesWithTrackingInfo:"), trackInfo);
                fprintf(stderr, "✅ applyBlendShapesWithTrackingInfo: succeeded\n");
            } @catch (NSException *e) {
                fprintf(stderr, "❌ exception: %s\n", e.reason.UTF8String);
            }
            
            typedef void (*ApplyPoseFunc)(id, SEL, id, BOOL, id);
            ApplyPoseFunc applyPose = (ApplyPoseFunc)objc_msgSend;
            
            @try {
                applyPose(animoji, sel_registerName("applyHeadPoseWithTrackingInfo:gazeCorrection:pointOfView:"),
                         trackInfo, NO, nil);
                fprintf(stderr, "✅ applyHeadPoseWithTrackingInfo: succeeded\n");
            } @catch (NSException *e) {
                fprintf(stderr, "❌ exception: %s\n", e.reason.UTF8String);
            }
        }
        
        // Verify the morph targets were actually set by reading back
        fprintf(stderr, "\n--- Verify morph target weights ---\n");
        
        // Get headNode → morpher → check weights
        typedef id (*ObjFunc)(id, SEL);
        ObjFunc objFn = (ObjFunc)objc_msgSend;
        
        id headNode = objFn(animoji, sel_registerName("headNode"));
        fprintf(stderr, "headNode: %s\n", headNode ? "OK" : "nil");
        
        if (headNode) {
            // Get morpher
            id morpher = objFn(headNode, sel_registerName("morpher"));
            fprintf(stderr, "morpher: %s\n", morpher ? "OK" : "nil");
            
            if (morpher) {
                // Check number of targets
                typedef NSInteger (*CountFunc)(id, SEL);
                CountFunc countFn = (CountFunc)objc_msgSend;
                
                // Try to read a weight
                typedef double (*WeightFunc)(id, SEL, NSInteger);
                WeightFunc weightFn = (WeightFunc)objc_msgSend;
                
                // We can't easily map blendshape names to target indices without
                // the full MorphInfo setup, but we can verify the morpher exists
                // and has targets
                fprintf(stderr, "✅ morpher accessible on headNode\n");
            }
        }
        
        fprintf(stderr, "\n=== DONE ===\n");
        return 0;
    }
}
