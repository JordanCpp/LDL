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

#ifndef LDL_Result_H
#define LDL_Result_H

#include <LDL/Config.h>
#include <LDL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Result LDL_Result;

LDL_LIBRARY LDL_Result* LDL_ResultNew();
LDL_LIBRARY void LDL_ResultFree(LDL_Result* result);
LDL_LIBRARY bool LDL_ResultIsOk(LDL_Result* result);
LDL_LIBRARY bool LDL_ResultIsFail(LDL_Result* result);
LDL_LIBRARY const char* LDL_ResultGetMessage(LDL_Result* result);
LDL_LIBRARY void LDL_ResultAddMessage(LDL_Result* result, const char* format, ...);

#ifdef __cplusplus
}
#endif 

#endif
