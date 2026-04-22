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

#ifndef LDL_OpenGL_GLLoad_H
#define LDL_OpenGL_GLLoad_H

#include <LDL/Config.h>
#include <LDL/Types.h>
#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_OpenGLLoader LDL_OpenGLLoader;

LDL_LIBRARY LDL_OpenGLLoader* LDL_OpenGLLoaderNew(LDL_Result* result, size_t major, size_t minor);
LDL_LIBRARY void LDL_OpenGLLoaderFree(LDL_OpenGLLoader* loader);

#ifdef __cplusplus
}
#endif

#endif
