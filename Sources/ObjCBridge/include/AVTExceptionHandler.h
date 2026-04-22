#import <Foundation/Foundation.h>

/// ObjC exception handler for VFX framework crashes.
/// VFX can throw NSRangeException during initial render if the scene
/// graph isn't fully built when Metal shaders are still compiling.
/// Swift cannot catch ObjC exceptions, so we need this bridge.

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT BOOL AVTTryPerform(void (NS_NOESCAPE ^block)(void),
                                      NSException * _Nullable * _Nullable outException);

NS_ASSUME_NONNULL_END
