// layer3_final.m — Layer 3 final verification
#import <Foundation/Foundation.h>
#import <SceneKit/SceneKit.h>
#import <dlfcn.h>
#import <objc/runtime.h>
#import <objc/message.h>
#import <simd/simd.h>
#import <math.h>

static int passed = 0, failed = 0;

typedef id (*ObjFunc)(id, SEL);
typedef SCNVector3 (*V3Func)(id, SEL);

static void applyPose(id animoji, float qx, float qy, float qz, float qw) {
    uint8_t buf[480] __attribute__((aligned(16)));
    memset(buf, 0, 480);
    float sentinel = -1.0f;
    for (int i = 0; i < 51; i++) {
        memcpy(buf + 0x34 + i*4, &sentinel, 4);
        memcpy(buf + 0x100 + i*4, &sentinel, 4);
    }
    memcpy(buf + 0x1CC, &sentinel, 4);
    memcpy(buf + 0x1D0, &sentinel, 4);
    memcpy(buf + 0x20, &qx, 4);
    memcpy(buf + 0x24, &qy, 4);
    memcpy(buf + 0x28, &qz, 4);
    memcpy(buf + 0x2C, &qw, 4);
    buf[0x30] = 1; // cameraSpace=YES
    
    NSData *data = [NSData dataWithBytes:buf length:480];
    typedef void (*UFunc)(id, SEL, NSData *, BOOL);
    ((UFunc)objc_msgSend)(animoji,
        sel_registerName("updatePoseWithFaceTrackingData:applySmoothing:"), data, NO);
}

#define CHECK(cond, msg) do { \
    if (cond) { passed++; fprintf(stderr, "  ✅ %s\n", msg); } \
    else { failed++; fprintf(stderr, "  ❌ %s\n", msg); } \
} while(0)

int main() {
    @autoreleasepool {
        dlopen("/System/Library/PrivateFrameworks/AvatarKit.framework/AvatarKit", RTLD_LAZY);
        fprintf(stderr, "=== Layer 3 Final: Head Pose Bit-Exact ===\n\n");
        
        Class animojiCls = NSClassFromString(@"AVTAnimoji");
        id animoji = ((id(*)(id,SEL,NSString*))objc_msgSend)(
            (id)animojiCls, sel_registerName("animojiNamed:"), @"cat");
        ((void(*)(id,SEL))objc_msgSend)(animoji, sel_registerName("loadIfNeeded"));
        
        ObjFunc objFn = (ObjFunc)objc_msgSend;
        V3Func v3Fn = (V3Func)objc_msgSend;
        SEL eulerSel = sel_registerName("eulerAngles");
        id neckNode = objFn(animoji, sel_registerName("neckNode"));
        
        // ============================================
        fprintf(stderr, "--- 1. Y rotation (yaw) → neckNode Z euler ---\n");
        // ============================================
        {
            float angles[] = {-60, -45, -30, -20, -15, -10, -5, 0, 5, 10, 15, 20, 30, 45, 60};
            int n = sizeof(angles)/sizeof(angles[0]);
            int exact = 0;
            
            for (int i = 0; i < n; i++) {
                applyPose(animoji, 0, 0, 0, 1); // reset
                
                float rad = angles[i] * M_PI / 180.0f;
                float qy = sinf(rad / 2.0f);
                float qw = cosf(rad / 2.0f);
                applyPose(animoji, 0, qy, 0, qw);
                
                SCNVector3 euler = v3Fn(neckNode, eulerSel);
                float outputZ = euler.z * 180.0f / M_PI;
                float delta = fabsf(outputZ - angles[i]);
                
                if (delta < 0.1f) exact++;
                else fprintf(stderr, "  input=%.0f° output=%.1f° delta=%.2f°\n", angles[i], outputZ, delta);
            }
            fprintf(stderr, "  %d/%d exact\n", exact, n);
            CHECK(exact == n, "Y rotation → Z euler 1:1 mapping");
        }
        
        // ============================================
        fprintf(stderr, "\n--- 2. X rotation (pitch) → neckNode X euler ---\n");
        // ============================================
        {
            float angles[] = {-30, -20, -10, 0, 10, 20, 30};
            int n = sizeof(angles)/sizeof(angles[0]);
            int exact = 0;
            
            for (int i = 0; i < n; i++) {
                applyPose(animoji, 0, 0, 0, 1);
                
                float rad = angles[i] * M_PI / 180.0f;
                float qx = sinf(rad / 2.0f);
                float qw = cosf(rad / 2.0f);
                applyPose(animoji, qx, 0, 0, qw);
                
                SCNVector3 euler = v3Fn(neckNode, eulerSel);
                float outputX = euler.x * 180.0f / M_PI;
                float delta = fabsf(outputX - angles[i]);
                
                if (delta < 0.1f) exact++;
                else fprintf(stderr, "  input=%.0f° outputX=%.1f° delta=%.2f°\n", angles[i], outputX, delta);
            }
            fprintf(stderr, "  %d/%d X exact\n", exact, n);
            CHECK(exact == n, "X rotation → X euler 1:1 mapping");
            
            // Also check Y — pitch seems to affect both X and Y
            fprintf(stderr, "  X pitch also affects Y euler:\n");
            for (int i = 0; i < n; i++) {
                applyPose(animoji, 0, 0, 0, 1);
                float rad = angles[i] * M_PI / 180.0f;
                float qx = sinf(rad / 2.0f);
                float qw = cosf(rad / 2.0f);
                applyPose(animoji, qx, 0, 0, qw);
                SCNVector3 euler = v3Fn(neckNode, eulerSel);
                fprintf(stderr, "    pitch=%.0f° → Y=%.1f°\n", angles[i], euler.y*180/M_PI);
            }
        }
        
        // ============================================
        fprintf(stderr, "\n--- 3. Z rotation (roll) → ignored ---\n");
        // ============================================
        {
            float angles[] = {-30, -15, 0, 15, 30};
            int n = sizeof(angles)/sizeof(angles[0]);
            int ignored = 0;
            
            for (int i = 0; i < n; i++) {
                applyPose(animoji, 0, 0, 0, 1);
                
                float rad = angles[i] * M_PI / 180.0f;
                float qz = sinf(rad / 2.0f);
                float qw = cosf(rad / 2.0f);
                applyPose(animoji, 0, 0, qz, qw);
                
                SCNVector3 euler = v3Fn(neckNode, eulerSel);
                float total = sqrtf(euler.x*euler.x + euler.y*euler.y + euler.z*euler.z) * 180/M_PI;
                if (total < 0.1f) ignored++;
                else fprintf(stderr, "  roll=%.0f° → total=%.1f° (not ignored!)\n", angles[i], total);
            }
            fprintf(stderr, "  %d/%d ignored\n", ignored, n);
            CHECK(ignored == n, "Z rotation (roll) is ignored");
        }
        
        // ============================================
        fprintf(stderr, "\n--- 4. Combined pitch+yaw ---\n");
        // ============================================
        {
            // 15° pitch + 20° yaw
            applyPose(animoji, 0, 0, 0, 1);
            
            float pitchRad = 15.0f * M_PI / 180.0f;
            float yawRad = 20.0f * M_PI / 180.0f;
            
            // Quaternion: pitch(X) * yaw(Y)
            float px = sinf(pitchRad/2), pw = cosf(pitchRad/2);
            float yy = sinf(yawRad/2), yw = cosf(yawRad/2);
            
            // q = qPitch * qYaw
            float qx = pw*0 + px*yw + 0*yy - 0*0;  // simplified
            float qy = pw*yy + 0*yw - px*0 + 0*0;
            float qz = pw*0 - 0*yy + 0*yw + px*0;
            float qw2 = pw*yw - px*0 - 0*yy - 0*0;
            
            // Actually just do it properly
            // qPitch = (sin(p/2), 0, 0, cos(p/2))
            // qYaw = (0, sin(y/2), 0, cos(y/2))
            // q = qPitch * qYaw
            float spx = sinf(pitchRad/2), cpx = cosf(pitchRad/2);
            float syy = sinf(yawRad/2), cyy = cosf(yawRad/2);
            
            float rx = spx * cyy;
            float ry = cpx * syy;
            float rz = -spx * syy;
            float rw = cpx * cyy;
            
            applyPose(animoji, rx, ry, rz, rw);
            
            SCNVector3 euler = v3Fn(neckNode, eulerSel);
            fprintf(stderr, "  pitch=15° yaw=20° → euler=(%.1f°, %.1f°, %.1f°)\n",
                euler.x*180/M_PI, euler.y*180/M_PI, euler.z*180/M_PI);
            
            // Expected: X≈15°, Z≈20° (based on axis mapping)
            float deltaX = fabsf(euler.x*180/M_PI - 15.0f);
            float deltaZ = fabsf(euler.z*180/M_PI - 20.0f);
            CHECK(deltaX < 1.0f && deltaZ < 1.0f, "combined pitch+yaw maps correctly");
        }
        
        // ============================================
        fprintf(stderr, "\n--- 5. Identity reset ---\n");
        // ============================================
        {
            // Apply some rotation
            float rad = 30.0f * M_PI / 180.0f;
            applyPose(animoji, 0, sinf(rad/2), 0, cosf(rad/2));
            SCNVector3 before = v3Fn(neckNode, eulerSel);
            
            // Reset to identity
            applyPose(animoji, 0, 0, 0, 1);
            SCNVector3 after = v3Fn(neckNode, eulerSel);
            
            float total = sqrtf(after.x*after.x + after.y*after.y + after.z*after.z) * 180/M_PI;
            fprintf(stderr, "  before: (%.1f°, %.1f°, %.1f°)\n",
                before.x*180/M_PI, before.y*180/M_PI, before.z*180/M_PI);
            fprintf(stderr, "  after reset: (%.1f°, %.1f°, %.1f°)\n",
                after.x*180/M_PI, after.y*180/M_PI, after.z*180/M_PI);
            CHECK(total < 0.1f, "identity quaternion resets to zero");
        }
        
        fprintf(stderr, "\n=== Results: %d passed, %d failed ===\n", passed, failed);
        return failed > 0 ? 1 : 0;
    }
}
