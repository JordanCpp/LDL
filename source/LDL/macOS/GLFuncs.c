/*
Copyright(C) 2026 AslanD (Ztry8)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <LDL/macOS/GLFuncs.h>

static const char* LDL_OpenGLFrameworkPath =
    "/System/Library/Frameworks/OpenGL.framework/OpenGL";

void LDL_OpenGLFunctionsInit(LDL_OpenGLFunctions* openGLFunctions, LDL_Result* result)
{
    if (openGLFunctions && result)
    {
        openGLFunctions->Result  = result;
        openGLFunctions->Library = LDL_LibraryNew(result);

        if (openGLFunctions->Library)
        {
            LDL_LibraryOpen(openGLFunctions->Library, LDL_OpenGLFrameworkPath);
        }
    }
}

void LDL_OpenGLFunctionsDeinit(LDL_OpenGLFunctions* openGLFunctions)
{
    if (openGLFunctions && openGLFunctions->Library)
    {
        LDL_LibraryFree(openGLFunctions->Library);
        openGLFunctions->Library = NULL;
    }
}

LDL_VoidFuncPtr LDL_OpenGLFunctionsGetFunction(LDL_OpenGLFunctions* openGLFunctions, const char* name)
{
    if (openGLFunctions && openGLFunctions->Library && name)
    {
        return LDL_LibraryGetFunction(openGLFunctions->Library, name);
    }

    return NULL;
}