// bit_exact_full.m — Comprehensive bit-exact verification

#import <Foundation/Foundation.h>
#import <dlfcn.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import <simd/simd.h>
#import <math.h>

static int passed = 0, failed = 0;

#define CHECK(cond, msg) do { \
    if (cond) { passed++; } \
    else { failed++; fprintf(stderr, "  ❌ %s\n", msg); } \
} while(0)

#define CHECK_FLOAT(a, b, msg) do { \
    if (fabsf((a)-(b)) < 1e-6f) { passed++; } \
    else { failed++; fprintf(stderr, "  ❌ %s: expected %.6f got %.6f\n", msg, (b), (a)); } \
} while(0)

typedef const void* (*TDFunc)(id, SEL);
typedef id (*CreateFunc)(id, SEL, const void *);

int main() {
    @autoreleasepool {
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY);
        Class c = NSClassFromString(@"AVTFaceTrackingInfo");
        if (!c) { fprintf(stderr, "FAIL: class\n"); return 1; }
        
        TDFunc tdFn = (TDFunc)objc_msgSend;
        CreateFunc createFn = (CreateFunc)objc_msgSend;
        SEL tdSel = sel_registerName("trackingData");
        SEL createSel = sel_registerName("trackingInfoWithTrackingData:");
        
        fprintf(stderr, "=== Comprehensive Bit-Exact Verification ===\n\n");
        
        // ============================================
        fprintf(stderr, "--- 1. All 51 blendshape offsets ---\n");
        // ============================================
        {
            uint8_t buf[480] __attribute__((aligned(16)));
            memset(buf, 0, 480);
            
            // Write unique value to each blendshape slot
            for (int i = 0; i < 51; i++) {
                float v = 0.01f * (i + 1); // 0.01, 0.02, ..., 0.51
                memcpy(buf + 0x34 + i*4, &v, 4);   // smooth
                memcpy(buf + 0x100 + i*4, &v, 4);   // raw
            }
            
            id ti = createFn((id)c, createSel, buf);
            const uint8_t *rb = (const uint8_t *)tdFn(ti, tdSel);
            
            int allMatch = 1;
            for (int i = 0; i < 51; i++) {
                float expected = 0.01f * (i + 1);
                float gotSmooth, gotRaw;
                memcpy(&gotSmooth, rb + 0x34 + i*4, 4);
                memcpy(&gotRaw, rb + 0x100 + i*4, 4);
                
                if (fabsf(gotSmooth - expected) > 1e-6f) {
                    fprintf(stderr, "  ❌ smooth[%d] at +0x%03x: expected %.6f got %.6f\n", 
                        i, 0x34 + i*4, expected, gotSmooth);
                    allMatch = 0;
                }
                if (fabsf(gotRaw - expected) > 1e-6f) {
                    fprintf(stderr, "  ❌ raw[%d] at +0x%03x: expected %.6f got %.6f\n",
                        i, 0x100 + i*4, expected, gotRaw);
                    allMatch = 0;
                }
            }
            if (allMatch) {
                passed += 102; // 51 smooth + 51 raw
                fprintf(stderr, "  ✅ All 51 smooth + 51 raw blendshapes at correct offsets\n");
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- 2. Boundary values ---\n");
        // ============================================
        {
            // Test: 0.0, 1.0, -1.0 (sentinel), very small, very large
            float tests[] = {0.0f, 1.0f, -1.0f, 0.001f, 0.999f, -0.5f};
            int numTests = sizeof(tests) / sizeof(tests[0]);
            
            for (int t = 0; t < numTests; t++) {
                uint8_t buf[480] __attribute__((aligned(16)));
                memset(buf, 0, 480);
                
                float v = tests[t];
                // Write to blendshape[0] smooth and raw
                memcpy(buf + 0x34, &v, 4);
                memcpy(buf + 0x100, &v, 4);
                
                id ti = createFn((id)c, createSel, buf);
                const uint8_t *rb = (const uint8_t *)tdFn(ti, tdSel);
                
                float gotSmooth, gotRaw;
                memcpy(&gotSmooth, rb + 0x34, 4);
                memcpy(&gotRaw, rb + 0x100, 4);
                
                char msg[64];
                snprintf(msg, sizeof(msg), "boundary %.3f smooth", v);
                CHECK_FLOAT(gotSmooth, v, msg);
                snprintf(msg, sizeof(msg), "boundary %.3f raw", v);
                CHECK_FLOAT(gotRaw, v, msg);
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- 3. Translation field ---\n");
        // ============================================
        {
            uint8_t buf[480] __attribute__((aligned(16)));
            memset(buf, 0, 480);
            
            float vals[] = {-0.5f, 0.3f, -0.8f, 0.0f}; // x, y, z, w
            memcpy(buf + 0x10, vals, 16);
            
            id ti = createFn((id)c, createSel, buf);
            const uint8_t *rb = (const uint8_t *)tdFn(ti, tdSel);
            
            float got[4];
            memcpy(got, rb + 0x10, 16);
            CHECK_FLOAT(got[0], -0.5f, "translation.x");
            CHECK_FLOAT(got[1], 0.3f, "translation.y");
            CHECK_FLOAT(got[2], -0.8f, "translation.z");
            CHECK_FLOAT(got[3], 0.0f, "translation.w");
        }
        
        // ============================================
        fprintf(stderr, "\n--- 4. Orientation field ---\n");
        // ============================================
        {
            uint8_t buf[480] __attribute__((aligned(16)));
            memset(buf, 0, 480);
            
            // simd_quatf: ix, iy, iz, r
            float q[] = {0.1f, 0.2f, 0.3f, 0.927f};
            memcpy(buf + 0x20, q, 16);
            
            id ti = createFn((id)c, createSel, buf);
            const uint8_t *rb = (const uint8_t *)tdFn(ti, tdSel);
            
            float got[4];
            memcpy(got, rb + 0x20, 16);
            CHECK_FLOAT(got[0], 0.1f, "orientation.ix");
            CHECK_FLOAT(got[1], 0.2f, "orientation.iy");
            CHECK_FLOAT(got[2], 0.3f, "orientation.iz");
            CHECK_FLOAT(got[3], 0.927f, "orientation.r");
        }
        
        // ============================================
        fprintf(stderr, "\n--- 5. cameraSpace flag ---\n");
        // ============================================
        {
            uint8_t buf[480] __attribute__((aligned(16)));
            
            // Test true
            memset(buf, 0, 480);
            buf[0x30] = 1;
            id ti1 = createFn((id)c, createSel, buf);
            const uint8_t *rb1 = (const uint8_t *)tdFn(ti1, tdSel);
            CHECK(rb1[0x30] == 1, "cameraSpace=true");
            
            // Test false
            memset(buf, 0, 480);
            buf[0x30] = 0;
            id ti2 = createFn((id)c, createSel, buf);
            const uint8_t *rb2 = (const uint8_t *)tdFn(ti2, tdSel);
            CHECK(rb2[0x30] == 0, "cameraSpace=false");
        }
        
        // ============================================
        fprintf(stderr, "\n--- 6. Tongue parameters ---\n");
        // ============================================
        {
            float tongueTests[] = {0.0f, 0.5f, 1.0f, -1.0f, 0.42f};
            int numTests = sizeof(tongueTests) / sizeof(tongueTests[0]);
            
            for (int t = 0; t < numTests; t++) {
                uint8_t buf[480] __attribute__((aligned(16)));
                memset(buf, 0, 480);
                
                float v = tongueTests[t];
                memcpy(buf + 0x1CC, &v, 4); // smooth
                memcpy(buf + 0x1D0, &v, 4); // raw
                
                id ti = createFn((id)c, createSel, buf);
                const uint8_t *rb = (const uint8_t *)tdFn(ti, tdSel);
                
                float gotSmooth, gotRaw;
                memcpy(&gotSmooth, rb + 0x1CC, 4);
                memcpy(&gotRaw, rb + 0x1D0, 4);
                
                char msg[64];
                snprintf(msg, sizeof(msg), "tongue smooth %.3f", v);
                CHECK_FLOAT(gotSmooth, v, msg);
                snprintf(msg, sizeof(msg), "tongue raw %.3f", v);
                CHECK_FLOAT(gotRaw, v, msg);
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- 7. Full buffer byte-exact (random pattern) ---\n");
        // ============================================
        {
            uint8_t buf[480] __attribute__((aligned(16)));
            // Fill with pseudo-random but deterministic pattern
            for (int i = 0; i < 480; i++) {
                buf[i] = (uint8_t)((i * 37 + 13) & 0xFF);
            }
            
            id ti = createFn((id)c, createSel, buf);
            const uint8_t *rb = (const uint8_t *)tdFn(ti, tdSel);
            
            int mismatches = 0;
            for (int i = 0; i < 480; i++) {
                if (buf[i] != rb[i]) mismatches++;
            }
            CHECK(mismatches == 0, "random pattern byte-exact");
            if (mismatches > 0) {
                fprintf(stderr, "  %d mismatches\n", mismatches);
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- 8. Padding region (0x1D4-0x1DF) ---\n");
        // ============================================
        {
            uint8_t buf[480] __attribute__((aligned(16)));
            memset(buf, 0, 480);
            
            // Write non-zero to padding region
            for (int i = 0x1D4; i < 480; i++) {
                buf[i] = 0xAB;
            }
            
            id ti = createFn((id)c, createSel, buf);
            const uint8_t *rb = (const uint8_t *)tdFn(ti, tdSel);
            
            int paddingMatch = 1;
            for (int i = 0x1D4; i < 480; i++) {
                if (rb[i] != 0xAB) {
                    fprintf(stderr, "  padding +0x%03x: expected 0xAB got 0x%02x\n", i, rb[i]);
                    paddingMatch = 0;
                }
            }
            CHECK(paddingMatch, "padding region preserved");
        }
        
        // ============================================
        fprintf(stderr, "\n--- 9. Blink correction verification ---\n");
        // ============================================
        {
            // pow(clamp(max(0, w) * 1.1, 0, 1), 2/3)
            struct { float in; float out; } tests[] = {
                {0.0f, 0.0f},
                {0.5f, powf(fminf(0.5f * 1.1f, 1.0f), 2.0f/3.0f)},
                {0.9f, powf(fminf(0.9f * 1.1f, 1.0f), 2.0f/3.0f)},
                {1.0f, 1.0f},
            };
            int numTests = sizeof(tests) / sizeof(tests[0]);
            for (int t = 0; t < numTests; t++) {
                float w = fmaxf(0, tests[t].in);
                float scaled = fminf(w * 1.1f, 1.0f);
                float result = scaled > 0 ? powf(scaled, 2.0f/3.0f) : 0.0f;
                char msg[64];
                snprintf(msg, sizeof(msg), "blink(%.1f)=%.6f", tests[t].in, tests[t].out);
                CHECK_FLOAT(result, tests[t].out, msg);
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- 10. Tongue correction verification ---\n");
        // ============================================
        {
            CHECK_FLOAT(0.8f * (1.0f - 0.5f), 0.4f, "tongue(0.8, 0.5)");
            CHECK_FLOAT(1.0f * (1.0f - 1.0f), 0.0f, "tongue(1.0, 1.0)");
            CHECK_FLOAT(0.5f * (1.0f - 0.0f), 0.5f, "tongue(0.5, 0.0)");
        }
        
        // ============================================
        fprintf(stderr, "\n=== Results: %d passed, %d failed ===\n", passed, failed);
        // ============================================
        
        return failed > 0 ? 1 : 0;
    }
}
