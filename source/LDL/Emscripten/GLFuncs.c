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

/*
 * OpenGL function resolver for Emscripten/WebGL.
 *
 * Emscripten statically links all GL symbols into the .wasm module;
 * emscripten_GetProcAddress() is the canonical way to retrieve a
 * function pointer by name at runtime without opening a shared library.
 *
 * Reference:
 *   https://emscripten.org/docs/porting/multimedia_and_graphics/OpenGL-support.html
 */

#include <emscripten.h>
#include <LDL/Emscripten/GLFuncs.h>

extern void* emscripten_GetProcAddress(const char* name);

void LDL_OpenGLFunctionsInit(LDL_OpenGLFunctions* openGLFunctions,
                              LDL_Result* result)
{
    if (openGLFunctions)
    {
        openGLFunctions->Result  = result;
        openGLFunctions->Library = NULL; /* no dynamic library on Emscripten */
    }
}

void LDL_OpenGLFunctionsDeinit(LDL_OpenGLFunctions* openGLFunctions)
{
    (void)openGLFunctions;
}

LDL_VoidFuncPtr LDL_OpenGLFunctionsGetFunction(
    LDL_OpenGLFunctions* openGLFunctions, const char* name)
{
    LDL_VoidFuncPtr ptr = NULL;

    (void)openGLFunctions;

    if (name)
    {
        ptr = (LDL_VoidFuncPtr)emscripten_GetProcAddress(name);

        if (!ptr && openGLFunctions && openGLFunctions->Result)
        {
            LDL_ResultAddMessage(openGLFunctions->Result,
                "LDL_OpenGLFunctionsGetFunction: symbol not found: %s\n", name);
        }
    }

    return ptr;
}
