// e2e_correct_order.m — E2E with Apple's real blendshape order
#import <Foundation/Foundation.h>
#import <SceneKit/SceneKit.h>
#import <dlfcn.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import <math.h>

static int passed = 0, failed = 0;

typedef id (*ObjFunc)(id, SEL);
typedef float (*WFunc)(id, SEL, NSUInteger);
typedef struct { id morpher; id node; long long targetIndex; BOOL isEnabled; } MI;
typedef MI (*MIFunc)(id, SEL, NSUInteger);
typedef void (*ApplyFunc)(id, SEL, const float *, const float *);

int main() {
    @autoreleasepool {
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY);
        fprintf(stderr, "=== E2E with Correct Apple Order ===\n\n");
        
        Class animojiCls = NSClassFromString(@"AVTAnimoji");
        id animoji = ((id(*)(id,SEL,NSString*))objc_msgSend)((id)animojiCls, sel_registerName("animojiNamed:"), @"cat");
        ((void(*)(id,SEL))objc_msgSend)(animoji, sel_registerName("loadIfNeeded"));
        
        ObjFunc objFn = (ObjFunc)objc_msgSend;
        WFunc wFn = (WFunc)objc_msgSend;
        SEL wSel = sel_registerName("weightForTargetAtIndex:");
        
        typedef id (*NameFunc)(id, SEL, NSUInteger);
        NameFunc nameFn = (NameFunc)objc_msgSend;
        SEL nameSel = sel_registerName("blendShapeNameForARKitBlendShapeIndex:");
        
        MI morphInfos[51];
        for (int i = 0; i < 51; i++) {
            morphInfos[i] = ((MIFunc)objc_msgSend)(animoji, sel_registerName("morphInfoForARKitBlendShapeIndex:"), (NSUInteger)i);
        }
        
        // Test 1: Each blendshape individually at 0.5
        fprintf(stderr, "--- 1. Individual blendshape test (input=0.5) ---\n");
        {
            int exact = 0, corrected = 0, total = 0;
            for (int idx = 0; idx < 51; idx++) {
                MI info = morphInfos[idx];
                if (!info.isEnabled || !info.morpher) continue;
                NSString *name = nameFn(animoji, nameSel, (NSUInteger)idx);
                
                float bs[51], params[1] = {-1.0f};
                for (int i = 0; i < 51; i++) bs[i] = 0.0f;
                ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
                
                for (int i = 0; i < 51; i++) bs[i] = -1.0f;
                bs[idx] = 0.5f;
                ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
                
                float w = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
                total++;
                
                if (fabsf(w - 0.5f) < 1e-5f) {
                    exact++;
                } else {
                    corrected++;
                    float blinkExp = powf(fminf(0.5f * 1.1f, 1.0f), 2.0f/3.0f);
                    if (fabsf(w - blinkExp) < 1e-5f) {
                        fprintf(stderr, "  [%2d] %s: 0.5 → %.6f (BLINK CORRECTION)\n", idx, name.UTF8String, w);
                    } else {
                        fprintf(stderr, "  [%2d] %s: 0.5 → %.6f (UNKNOWN)\n", idx, name.UTF8String, w);
                    }
                }
            }
            fprintf(stderr, "  %d exact, %d corrected, %d total\n", exact, corrected, total);
        }
        
        // Test 2: All 51 × 6 values
        fprintf(stderr, "\n--- 2. All blendshapes × 6 values ---\n");
        {
            float testVals[] = {0.0f, 0.1f, 0.25f, 0.5f, 0.75f, 1.0f};
            int numVals = 6;
            int totalExact = 0, totalTested = 0;
            
            for (int idx = 0; idx < 51; idx++) {
                MI info = morphInfos[idx];
                if (!info.isEnabled || !info.morpher) continue;
                for (int v = 0; v < numVals; v++) {
                    float bs[51], params[1] = {-1.0f};
                    for (int i = 0; i < 51; i++) bs[i] = -1.0f;
                    bs[idx] = testVals[v];
                    ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
                    float w = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
                    totalTested++;
                    if (fabsf(w - testVals[v]) < 1e-5f) totalExact++;
                }
            }
            fprintf(stderr, "  %d/%d exact\n", totalExact, totalTested);
            if (totalExact == totalTested) { passed++; fprintf(stderr, "  ✅ ALL bit-exact\n"); }
            else { failed++; fprintf(stderr, "  ❌ %d differ\n", totalTested - totalExact); }
        }
        
        // Test 3: Sentinel
        fprintf(stderr, "\n--- 3. Sentinel behavior ---\n");
        {
            MI info = morphInfos[19]; // jawOpen
            float bs[51], params[1] = {-1.0f};
            
            for (int i = 0; i < 51; i++) bs[i] = -1.0f;
            bs[19] = 0.8f;
            ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
            float w1 = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
            
            for (int i = 0; i < 51; i++) bs[i] = -1.0f;
            ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
            float w2 = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
            
            for (int i = 0; i < 51; i++) bs[i] = -1.0f;
            bs[19] = 0.0f;
            ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
            float w3 = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
            
            fprintf(stderr, "  set=0.8: %.6f, sentinel: %.6f, zero: %.6f\n", w1, w2, w3);
            if (fabsf(w1-0.8f)<1e-5f && fabsf(w2-0.8f)<1e-5f && fabsf(w3)<1e-5f) {
                passed++; fprintf(stderr, "  ✅ Sentinel correct\n");
            } else { failed++; }
        }
        
        // Test 4: NSData path
        fprintf(stderr, "\n--- 4. NSData path ---\n");
        {
            float bs[51], params[1] = {-1.0f};
            for (int i = 0; i < 51; i++) bs[i] = 0.0f;
            ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
            
            uint8_t buf[480] __attribute__((aligned(16)));
            memset(buf, 0, 480);
            float sentinel = -1.0f;
            for (int i = 0; i < 51; i++) {
                memcpy(buf + 0x34 + i*4, &sentinel, 4);
                memcpy(buf + 0x100 + i*4, &sentinel, 4);
            }
            memcpy(buf + 0x1CC, &sentinel, 4);
            memcpy(buf + 0x1D0, &sentinel, 4);
            
            float jawOpen = 0.65f, smile = 0.9f;
            memcpy(buf + 0x34 + 19*4, &jawOpen, 4);
            memcpy(buf + 0x100 + 19*4, &jawOpen, 4);
            memcpy(buf + 0x34 + 30*4, &smile, 4);
            memcpy(buf + 0x100 + 30*4, &smile, 4);
            float qw = 1.0f;
            memcpy(buf + 0x2C, &qw, 4);
            
            NSData *data = [NSData dataWithBytes:buf length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji, sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
            
            float jawW = wFn(morphInfos[19].morpher, wSel, (NSUInteger)morphInfos[19].targetIndex);
            float smileW = wFn(morphInfos[30].morpher, wSel, (NSUInteger)morphInfos[30].targetIndex);
            fprintf(stderr, "  jawOpen: %.6f, smile: %.6f\n", jawW, smileW);
            if (fabsf(jawW-0.65f)<1e-5f && fabsf(smileW-0.9f)<1e-5f) {
                passed++; fprintf(stderr, "  ✅ NSData exact\n");
            } else { failed++; }
        }
        
        // Test 5: Head rotation
        fprintf(stderr, "\n--- 5. Head rotation ---\n");
        {
            uint8_t buf[480] __attribute__((aligned(16)));
            memset(buf, 0, 480);
            float sentinel = -1.0f;
            for (int i = 0; i < 51; i++) {
                memcpy(buf + 0x34 + i*4, &sentinel, 4);
                memcpy(buf + 0x100 + i*4, &sentinel, 4);
            }
            memcpy(buf + 0x1CC, &sentinel, 4);
            memcpy(buf + 0x1D0, &sentinel, 4);
            
            float angle = 30.0f * M_PI / 180.0f;
            float qy = sinf(angle / 2.0f);
            float qw = cosf(angle / 2.0f);
            memcpy(buf + 0x24, &qy, 4);
            memcpy(buf + 0x2C, &qw, 4);
            buf[0x30] = 1; // cameraSpace
            
            NSData *data = [NSData dataWithBytes:buf length:480];
            typedef void (*UFunc)(id, SEL, NSData *, BOOL);
            ((UFunc)objc_msgSend)(animoji, sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
            
            id headNode = objFn(animoji, sel_registerName("headNode"));
            if ([headNode respondsToSelector:sel_registerName("orientation")]) {
                typedef SCNQuaternion (*QFunc)(id, SEL);
                SCNQuaternion q = ((QFunc)objc_msgSend)(headNode, sel_registerName("orientation"));
                float totalAngle = 2.0f * acosf(fabsf(q.w)) * 180.0f / M_PI;
                fprintf(stderr, "  orientation: (%.4f, %.4f, %.4f, %.4f) angle=%.1f°\n", q.x, q.y, q.z, q.w, totalAngle);
                if (totalAngle > 10.0f) { passed++; fprintf(stderr, "  ✅ rotation applied\n"); }
                else { failed++; fprintf(stderr, "  ❌ rotation too small\n"); }
            }
        }
        
        fprintf(stderr, "\n=== Results: %d passed, %d failed ===\n", passed, failed);
        return failed > 0 ? 1 : 0;
    }
}
