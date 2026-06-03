/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_FpsCount_H
#define LDL_FpsCount_H

#include <LDL/Result.h>
#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_FpsCounter LDL_FpsCounter;

LDL_LIBRARY LDL_FpsCounter* LDL_FpsCounterNew(LDL_Result* result);
LDL_LIBRARY void LDL_FpsCounterFree(LDL_FpsCounter* fpsCounter);
LDL_LIBRARY void LDL_FpsCounterStart(LDL_FpsCounter* fpsCounter);
LDL_LIBRARY bool LDL_FpsCounterCalc(LDL_FpsCounter* fpsCounter);
LDL_LIBRARY size_t LDL_FpsCounterFps(LDL_FpsCounter* fpsCounter);

#ifdef __cplusplus
}
#endif 

#endif
