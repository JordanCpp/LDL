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

#ifndef LDL_Win9x_GLFuncs_H
#define LDL_Win9x_GLFuncs_H

#include <LDL/Library.h>
#include <LDL/Win9x/GLFuncs.h>

typedef struct LDL_OpenGLFunctions
{
	LDL_Result*  Result;
	LDL_Library* Library;
} LDL_OpenGLFunctions;

LDL_LIBRARY void LDL_OpenGLFunctionsInit(LDL_OpenGLFunctions* openGLFunctions, LDL_Result* result);
LDL_LIBRARY void LDL_OpenGLFunctionsDeinit(LDL_OpenGLFunctions* openGLFunctions);
LDL_LIBRARY LDL_VoidFuncPtr LDL_OpenGLFunctionsGetFunction(LDL_OpenGLFunctions* openGLFunctions, const char* name);

#endif
