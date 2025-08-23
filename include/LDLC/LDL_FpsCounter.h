// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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

#ifdef __cplusplus
}
#endif

#endif
