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

#include <LDL/Linux/GLX.h>
#include <LDL/Linux/GLFuncs.h>

void LDL_OpenGLFunctionsInit(LDL_OpenGLFunctions* openGLFunctions, LDL_Result* result)
{
	if (openGLFunctions)
	{
		openGLFunctions->Result  = result;
		openGLFunctions->Library = LDL_LibraryCreate(result);
	}
}

void LDL_OpenGLFunctionsDeinit(LDL_OpenGLFunctions* openGLFunctions)
{
	if (openGLFunctions && openGLFunctions->Library)
	{
		LDL_LibraryDestroy(openGLFunctions->Library);
	}
}

LDL_VoidFuncPtr LDL_OpenGLFunctionsGetFunction(LDL_OpenGLFunctions* openGLFunctions, const char* name)
{
	LDL_VoidFuncPtr result = glXGetProcAddress((const GLubyte*)name);;

	return result;
}
