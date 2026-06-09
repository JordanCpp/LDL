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

#ifndef LDL_Library_H
#define LDL_Library_H

#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Library LDL_Library;

LDL_LIBRARY LDL_Library* LDL_LibraryCreate(LDL_Result* result);
LDL_LIBRARY void LDL_LibraryDestroy(LDL_Library* library);
LDL_LIBRARY bool LDL_LibraryOpen(LDL_Library* library, const char* path);
LDL_LIBRARY void LDL_LibraryClose(LDL_Library* library);
LDL_LIBRARY LDL_VoidFuncPtr LDL_LibraryGetFunction(LDL_Library* library, const char* name);

#ifdef __cplusplus
}
#endif 

#endif
