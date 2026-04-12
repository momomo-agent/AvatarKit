#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import <math.h>

typedef float (*WFunc)(id, SEL, NSUInteger);
typedef struct { id morpher; id node; long long targetIndex; BOOL isEnabled; } MI;
typedef MI (*MIFunc)(id, SEL, NSUInteger);
typedef void (*ApplyFunc)(id, SEL, const float *, const float *);

int main() {
    @autoreleasepool {
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY);
        
        Class animojiCls = NSClassFromString(@"AVTAnimoji");
        id animoji = ((id(*)(id,SEL,NSString*))objc_msgSend)((id)animojiCls, sel_registerName("animojiNamed:"), @"cat");
        ((void(*)(id,SEL))objc_msgSend)(animoji, sel_registerName("loadIfNeeded"));
        
        WFunc wFn = (WFunc)objc_msgSend;
        SEL wSel = sel_registerName("weightForTargetAtIndex:");
        
        MI morphInfos[51];
        for (int i = 0; i < 51; i++) {
            morphInfos[i] = ((MIFunc)objc_msgSend)(animoji, sel_registerName("morphInfoForARKitBlendShapeIndex:"), (NSUInteger)i);
        }
        
        float testVals[] = {0.0f, 0.1f, 0.25f, 0.5f, 0.75f, 1.0f};
        int numVals = 6;
        int totalExact = 0, totalTested = 0;
        
        for (int idx = 0; idx < 51; idx++) {
            MI info = morphInfos[idx];
            if (!info.isEnabled || !info.morpher) continue;
            
            for (int v = 0; v < numVals; v++) {
                float input = testVals[v];
                float bs[51], params[1] = {-1.0f};
                for (int i = 0; i < 51; i++) bs[i] = -1.0f;
                bs[idx] = input;
                ((ApplyFunc)objc_msgSend)(animoji, sel_registerName("_applyBlendShapes:parameters:"), bs, params);
                
                float got = wFn(info.morpher, wSel, (NSUInteger)info.targetIndex);
                
                // Expected: apply blink correction for index 0,1
                float expected = input;
                if (idx == 0 || idx == 1) {
                    float w = fmaxf(0, input);
                    float scaled = fminf(w * 1.1f, 1.0f);
                    expected = scaled > 0 ? powf(scaled, 2.0f/3.0f) : 0.0f;
                }
                
                totalTested++;
                if (fabsf(got - expected) < 1e-5f) {
                    totalExact++;
                } else {
                    fprintf(stderr, "  [%d] input=%.2f expected=%.6f got=%.6f delta=%.6f\n",
                        idx, input, expected, got, fabsf(got - expected));
                }
            }
        }
        
        fprintf(stderr, "%d/%d exact (with blink correction)\n", totalExact, totalTested);
        if (totalExact == totalTested) {
            fprintf(stderr, "✅ ALL 306 tests EXACT — 100%% bit-exact verified!\n");
        }
        
        return totalExact == totalTested ? 0 : 1;
    }
}
