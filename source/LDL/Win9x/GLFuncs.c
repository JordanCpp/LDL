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

#include <LDL/Win9x/WinX.h>
#include <LDL/Win9x/GLFuncs.h>

void LDL_OpenGLFunctionsInit(LDL_OpenGLFunctions* openGLFunctions, LDL_Result* result)
{
	if (openGLFunctions)
	{
		openGLFunctions->Result  = result;
		openGLFunctions->Library = LDL_LibraryNew(result);

		if (LDL_ResultIsOk(result))
		{
			if (!LDL_LibraryOpen(openGLFunctions->Library, "OpenGL32.dll"))
			{
				LDL_OpenGLFunctionsDeinit(openGLFunctions);
			}
		}
	}
}

void LDL_OpenGLFunctionsDeinit(LDL_OpenGLFunctions* openGLFunctions)
{
	if (openGLFunctions)
	{
		if (openGLFunctions->Library)
		{
			LDL_LibraryFree(openGLFunctions->Library);
		}
	}
}

bool IsValid(LDL_VoidFuncPtr ptr)
{
	return (ptr == 0 || (ptr == (LDL_VoidFuncPtr)0x1) || (ptr == (LDL_VoidFuncPtr)0x2) || (ptr == (LDL_VoidFuncPtr)0x3) || (ptr == (LDL_VoidFuncPtr)-1));
}

LDL_VoidFuncPtr LDL_OpenGLFunctionsGetFunction(LDL_OpenGLFunctions* openGLFunctions, const char* name)
{
	LDL_VoidFuncPtr result = (LDL_VoidFuncPtr)wglGetProcAddress(name);

	if (IsValid(result))
	{
		result = LDL_LibraryGetFunction(openGLFunctions->Library, name);
	}

	return result;
}
