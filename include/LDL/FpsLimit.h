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

#ifndef LDL_FpsLimit_H
#define LDL_FpsLimit_H

#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	LDL_FpsLimiterDefault = 60
};

typedef struct LDL_FpsLimiter LDL_FpsLimiter;

LDL_LIBRARY LDL_FpsLimiter* LDL_FpsLimiterCreate(LDL_Result* result, size_t fps);
LDL_LIBRARY void LDL_FpsLimiterDestroy(LDL_FpsLimiter* fpsLimiter);
LDL_LIBRARY void LDL_FpsLimiterMark(LDL_FpsLimiter* fpsLimiter);
LDL_LIBRARY void LDL_FpsLimiterThrottle(LDL_FpsLimiter* fpsLimiter);

#ifdef __cplusplus
}
#endif 

#endif
