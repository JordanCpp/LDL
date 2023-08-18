#ifndef LDL_FpsCounter_h
#define LDL_FpsCounter_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_FpsCounter LDL_FpsCounter;

LDL_LIBRARY LDL_FpsCounter* LDL_FpsCounterNew();
LDL_LIBRARY void LDL_FpsCounterFree(LDL_FpsCounter* fpsCounter);
LDL_LIBRARY void LDL_FpsCounterStart(LDL_FpsCounter* fpsCounter);
LDL_LIBRARY bool LDL_FpsCounterCalc(LDL_FpsCounter* fpsCounter);
LDL_LIBRARY size_t LDL_FpsCounterGetFps(LDL_FpsCounter* fpsCounter);
LDL_LIBRARY void LDL_FpsCounterClear(LDL_FpsCounter* fpsCounter);

#ifdef __cplusplus
}
#endif

#endif
