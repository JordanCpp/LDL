#ifndef LDL_FpsLimiter_h
#define LDL_FpsLimiter_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_FpsLimiter LDL_FpsLimiter;

LDL_EXPORT LDL_FpsLimiter* LDL_FpsLimiterNew(size_t fps);
LDL_EXPORT void LDL_FpsLimiterFree(LDL_FpsLimiter* fpsLimiter);
LDL_EXPORT void LDL_FpsLimiterMark(LDL_FpsLimiter* fpsLimiter);
LDL_EXPORT void LDL_FpsLimiterThrottle(LDL_FpsLimiter* fpsLimiter);

#ifdef __cplusplus
}
#endif

#endif