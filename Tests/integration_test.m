// integration_test.m — Full pipeline: AvatarFaceTracking → TrackingDataBuilder → Apple → morph weight
// This simulates what our Swift code does, but in ObjC for direct verification

#import <Foundation/Foundation.h>
#import <SceneKit/SceneKit.h>
#import <dlfcn.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import <simd/simd.h>
#import <math.h>
#import <QuartzCore/QuartzCore.h>

static int passed = 0, failed = 0;

typedef float (*WFunc)(id, SEL, NSUInteger);
typedef struct { id morpher; id node; long long targetIndex; BOOL isEnabled; } MI;
typedef MI (*MIFunc)(id, SEL, NSUInteger);
typedef SCNVector3 (*V3Func)(id, SEL);

// Apple's real blendshape order (verified via runtime)
static const char *appleOrder[] = {
    "eyeBlinkLeft", "eyeBlinkRight", "eyeSquintLeft", "eyeSquintRight",
    "eyeLookDownLeft", "eyeLookDownRight", "eyeLookInLeft", "eyeLookInRight",
    "eyeWideLeft", "eyeWideRight", "eyeLookOutLeft", "eyeLookOutRight",
    "eyeLookUpLeft", "eyeLookUpRight", "browDownLeft", "browDownRight",
    "browInnerUp", "browOuterUpLeft", "browOuterUpRight", "jawOpen",
    "mouthClose", "jawLeft", "jawRight", "jawForward",
    "mouthUpperUpLeft", "mouthUpperUpRight", "mouthLowerDownLeft", "mouthLowerDownRight",
    "mouthRollUpper", "mouthRollLower", "mouthSmileLeft", "mouthSmileRight",
    "mouthDimpleLeft", "mouthDimpleRight", "mouthStretchLeft", "mouthStretchRight",
    "mouthFrownLeft", "mouthFrownRight", "mouthPressLeft", "mouthPressRight",
    "mouthPucker", "mouthFunnel", "mouthLeft", "mouthRight",
    "mouthShrugLower", "mouthShrugUpper", "noseSneerLeft", "noseSneerRight",
    "cheekPuff", "cheekSquintLeft", "cheekSquintRight"
};

static int indexForName(const char *name) {
    for (int i = 0; i < 51; i++) {
        if (strcmp(appleOrder[i], name) == 0) return i;
    }
    return -1;
}

// Simulate TrackingDataBuilder.build(from:)
static void buildBuffer(uint8_t *buf, NSDictionary<NSString*, NSNumber*> *blendshapes,
                        float qx, float qy, float qz, float qw, BOOL cameraSpace) {
    memset(buf, 0, 480);
    
    // Timestamp
    double ts = CACurrentMediaTime();
    memcpy(buf + 0x00, &ts, 8);
    
    // Orientation
    memcpy(buf + 0x20, &qx, 4);
    memcpy(buf + 0x24, &qy, 4);
    memcpy(buf + 0x28, &qz, 4);
    memcpy(buf + 0x2C, &qw, 4);
    
    // cameraSpace
    buf[0x30] = cameraSpace ? 1 : 0;
    
    // Initialize all to -1.0 sentinel
    float sentinel = -1.0f;
    for (int i = 0; i < 51; i++) {
        memcpy(buf + 0x34 + i*4, &sentinel, 4);
        memcpy(buf + 0x100 + i*4, &sentinel, 4);
    }
    memcpy(buf + 0x1CC, &sentinel, 4);
    memcpy(buf + 0x1D0, &sentinel, 4);
    
    // Write blendshapes
    for (NSString *name in blendshapes) {
        float val = blendshapes[name].floatValue;
        
        if ([name isEqualToString:@"tongueOut"]) {
            memcpy(buf + 0x1CC, &val, 4);
            memcpy(buf + 0x1D0, &val, 4);
            continue;
        }
        
        int idx = indexForName(name.UTF8String);
        if (idx < 0) continue;
        memcpy(buf + 0x34 + idx*4, &val, 4);
        memcpy(buf + 0x100 + idx*4, &val, 4);
    }
}

int main() {
    @autoreleasepool {
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY);
        fprintf(stderr, "=== Integration Test: Full Pipeline ===\n\n");
        
        Class animojiCls = NSClassFromString(@"AVTAnimoji");
        id animoji = ((id(*)(id,SEL,NSString*))objc_msgSend)(
            (id)animojiCls, sel_registerName("animojiNamed:"), @"cat");
        ((void(*)(id,SEL))objc_msgSend)(animoji, sel_registerName("loadIfNeeded"));
        
        typedef id (*ObjFunc)(id, SEL);
        ObjFunc objFn = (ObjFunc)objc_msgSend;
        WFunc wFn = (WFunc)objc_msgSend;
        SEL wSel = sel_registerName("weightForTargetAtIndex:");
        V3Func v3Fn = (V3Func)objc_msgSend;
        
        MI morphInfos[51];
        for (int i = 0; i < 51; i++) {
            morphInfos[i] = ((MIFunc)objc_msgSend)(animoji,
                sel_registerName("morphInfoForARKitBlendShapeIndex:"), (NSUInteger)i);
        }
        
        id neckNode = objFn(animoji, sel_registerName("neckNode"));
        
        // ============================================
        fprintf(stderr, "--- Test 1: Smile expression ---\n");
        // ============================================
        {
            NSDictionary *bs = @{
                @"mouthSmileLeft": @0.8f,
                @"mouthSmileRight": @0.8f,
                @"cheekSquintLeft": @0.3f,
                @"cheekSquintRight": @0.3f,
            };
            
            uint8_t buf[480] __attribute__((aligned(16)));
            buildBuffer(buf, bs, 0, 0, 0, 1, YES);
            
            NSData *data = [NSData dataWithBytes:buf length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji,
                sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
            
            int correct = 0, total = 0;
            for (NSString *name in bs) {
                int idx = indexForName(name.UTF8String);
                MI info = morphInfos[idx];
                if (!info.isEnabled) continue;
                
                float expected = [bs[name] floatValue];
                float got = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
                total++;
                if (fabsf(got - expected) < 1e-5f) correct++;
                else fprintf(stderr, "  %s: expected=%.3f got=%.3f\n", name.UTF8String, expected, got);
            }
            if (correct == total) { passed++; fprintf(stderr, "  ✅ Smile: %d/%d exact\n", correct, total); }
            else { failed++; fprintf(stderr, "  ❌ Smile: %d/%d\n", correct, total); }
        }
        
        // ============================================
        fprintf(stderr, "\n--- Test 2: Wink expression ---\n");
        // ============================================
        {
            NSDictionary *bs = @{
                @"eyeBlinkLeft": @0.9f,
                @"mouthSmileLeft": @0.5f,
                @"mouthSmileRight": @0.3f,
            };
            
            uint8_t buf[480] __attribute__((aligned(16)));
            buildBuffer(buf, bs, 0, 0, 0, 1, YES);
            
            NSData *data = [NSData dataWithBytes:buf length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji,
                sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
            
            // eyeBlinkLeft has blink correction: pow(min(0.9*1.1, 1), 2/3)
            float blinkExpected = powf(fminf(0.9f * 1.1f, 1.0f), 2.0f/3.0f);
            
            int blinkIdx = indexForName("eyeBlinkLeft");
            MI blinkInfo = morphInfos[blinkIdx];
            float blinkGot = wFn(blinkInfo.morpher, wSel, (NSUInteger)blinkInfo.targetIndex);
            
            int smileLIdx = indexForName("mouthSmileLeft");
            MI smileLInfo = morphInfos[smileLIdx];
            float smileLGot = wFn(smileLInfo.morpher, wSel, (NSUInteger)smileLInfo.targetIndex);
            
            fprintf(stderr, "  eyeBlinkLeft: expected=%.6f got=%.6f\n", blinkExpected, blinkGot);
            fprintf(stderr, "  mouthSmileLeft: expected=0.5 got=%.6f\n", smileLGot);
            
            if (fabsf(blinkGot - blinkExpected) < 1e-5f && fabsf(smileLGot - 0.5f) < 1e-5f) {
                passed++;
                fprintf(stderr, "  ✅ Wink with blink correction exact\n");
            } else {
                failed++;
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- Test 3: Talking expression with tongue ---\n");
        // ============================================
        {
            NSDictionary *bs = @{
                @"jawOpen": @0.6f,
                @"mouthClose": @0.3f,
                @"tongueOut": @0.4f,
            };
            
            uint8_t buf[480] __attribute__((aligned(16)));
            buildBuffer(buf, bs, 0, 0, 0, 1, YES);
            
            NSData *data = [NSData dataWithBytes:buf length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji,
                sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
            
            int jawIdx = indexForName("jawOpen");
            float jawGot = wFn(morphInfos[jawIdx].morpher, wSel, (NSUInteger)morphInfos[jawIdx].targetIndex);
            
            // tongueOut goes to params, not blendshapes — jawOpen should be unaffected
            fprintf(stderr, "  jawOpen: expected=0.6 got=%.6f\n", jawGot);
            
            if (fabsf(jawGot - 0.6f) < 1e-5f) {
                passed++;
                fprintf(stderr, "  ✅ Talking expression exact\n");
            } else {
                failed++;
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- Test 4: Head turn + expression ---\n");
        // ============================================
        {
            NSDictionary *bs = @{
                @"jawOpen": @0.4f,
                @"mouthSmileLeft": @0.6f,
            };
            
            // 20° yaw
            float angle = 20.0f * M_PI / 180.0f;
            float qy = sinf(angle / 2.0f);
            float qw = cosf(angle / 2.0f);
            
            uint8_t buf[480] __attribute__((aligned(16)));
            buildBuffer(buf, bs, 0, qy, 0, qw, YES);
            
            NSData *data = [NSData dataWithBytes:buf length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji,
                sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
            
            // Check blendshapes
            int jawIdx = indexForName("jawOpen");
            float jawGot = wFn(morphInfos[jawIdx].morpher, wSel, (NSUInteger)morphInfos[jawIdx].targetIndex);
            
            int smileIdx = indexForName("mouthSmileLeft");
            float smileGot = wFn(morphInfos[smileIdx].morpher, wSel, (NSUInteger)morphInfos[smileIdx].targetIndex);
            
            // Check head rotation
            SCNVector3 euler = v3Fn(neckNode, sel_registerName("eulerAngles"));
            float yawDeg = euler.z * 180.0f / M_PI;
            
            fprintf(stderr, "  jawOpen: %.6f (expected 0.4)\n", jawGot);
            fprintf(stderr, "  mouthSmileLeft: %.6f (expected 0.6)\n", smileGot);
            fprintf(stderr, "  neckNode yaw: %.1f° (expected 20°)\n", yawDeg);
            
            if (fabsf(jawGot - 0.4f) < 1e-5f &&
                fabsf(smileGot - 0.6f) < 1e-5f &&
                fabsf(yawDeg - 20.0f) < 0.1f) {
                passed++;
                fprintf(stderr, "  ✅ Head turn + expression exact\n");
            } else {
                failed++;
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- Test 5: All 51 blendshapes at once ---\n");
        // ============================================
        {
            NSMutableDictionary *bs = [NSMutableDictionary dictionary];
            for (int i = 0; i < 51; i++) {
                float val = 0.1f + (float)i * 0.017f;
                if (val > 1.0f) val = 1.0f;
                bs[@(appleOrder[i])] = @(val);
            }
            
            uint8_t buf[480] __attribute__((aligned(16)));
            buildBuffer(buf, bs, 0, 0, 0, 1, YES);
            
            NSData *data = [NSData dataWithBytes:buf length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji,
                sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
            
            int exact = 0, total = 0;
            for (int i = 0; i < 51; i++) {
                MI info = morphInfos[i];
                if (!info.isEnabled) continue;
                
                float input = [bs[@(appleOrder[i])] floatValue];
                float expected = input;
                
                // Apply blink correction for index 0,1
                if (i == 0 || i == 1) {
                    float w = fmaxf(0, input);
                    float scaled = fminf(w * 1.1f, 1.0f);
                    expected = scaled > 0 ? powf(scaled, 2.0f/3.0f) : 0.0f;
                }
                
                float got = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
                total++;
                if (fabsf(got - expected) < 1e-5f) exact++;
                else fprintf(stderr, "  [%d] %s: expected=%.6f got=%.6f\n", i, appleOrder[i], expected, got);
            }
            fprintf(stderr, "  %d/%d exact\n", exact, total);
            if (exact == total) { passed++; fprintf(stderr, "  ✅ All 51 blendshapes exact\n"); }
            else { failed++; }
        }
        
        // ============================================
        fprintf(stderr, "\n--- Test 6: Preset → sentinel behavior ---\n");
        // ============================================
        {
            // First set all to known values
            NSMutableDictionary *fullBS = [NSMutableDictionary dictionary];
            for (int i = 0; i < 51; i++) {
                fullBS[@(appleOrder[i])] = @(0.5f);
            }
            uint8_t buf1[480] __attribute__((aligned(16)));
            buildBuffer(buf1, fullBS, 0, 0, 0, 1, YES);
            NSData *data1 = [NSData dataWithBytes:buf1 length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji,
                sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data1, NO);
            
            // Now apply sparse preset (only jawOpen + smile)
            NSDictionary *sparse = @{
                @"jawOpen": @0.3f,
                @"mouthSmileLeft": @0.7f,
            };
            uint8_t buf2[480] __attribute__((aligned(16)));
            buildBuffer(buf2, sparse, 0, 0, 0, 1, YES);
            NSData *data2 = [NSData dataWithBytes:buf2 length:480];
            ((UFunc)objc_msgSend)(animoji,
                sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data2, NO);
            
            // jawOpen should be 0.3, smile should be 0.7
            // Other blendshapes should STILL be 0.5 (sentinel preserves)
            int jawIdx = indexForName("jawOpen");
            float jawGot = wFn(morphInfos[jawIdx].morpher, wSel, (NSUInteger)morphInfos[jawIdx].targetIndex);
            
            int smileIdx = indexForName("mouthSmileLeft");
            float smileGot = wFn(morphInfos[smileIdx].morpher, wSel, (NSUInteger)morphInfos[smileIdx].targetIndex);
            
            // Check a blendshape that was NOT in the sparse set
            int noseIdx = indexForName("noseSneerLeft");
            float noseGot = wFn(morphInfos[noseIdx].morpher, wSel, (NSUInteger)morphInfos[noseIdx].targetIndex);
            
            fprintf(stderr, "  jawOpen: %.6f (expected 0.3)\n", jawGot);
            fprintf(stderr, "  mouthSmileLeft: %.6f (expected 0.7)\n", smileGot);
            fprintf(stderr, "  noseSneerLeft: %.6f (expected 0.5, preserved by sentinel)\n", noseGot);
            
            if (fabsf(jawGot - 0.3f) < 1e-5f &&
                fabsf(smileGot - 0.7f) < 1e-5f &&
                fabsf(noseGot - 0.5f) < 1e-5f) {
                passed++;
                fprintf(stderr, "  ✅ Sparse preset with sentinel preservation exact\n");
            } else {
                failed++;
            }
        }
        
        fprintf(stderr, "\n=== Results: %d passed, %d failed ===\n", passed, failed);
        return failed > 0 ? 1 : 0;
    }
}
