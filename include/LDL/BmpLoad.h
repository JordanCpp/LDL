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

#ifndef LDL_BmpLoad_H
#define LDL_BmpLoad_H

#include <LDL/Types.h>
#include <LDL/Vec2i.h>
#include <LDL/Config.h>
#include <LDL/Result.h>
#include <LDL/PixFrmt.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_BmpLoader LDL_BmpLoader;

LDL_LIBRARY LDL_BmpLoader* LDL_BmpLoaderNew(LDL_Result* result);
LDL_LIBRARY void LDL_BmpLoaderFree(LDL_BmpLoader* loader);

LDL_LIBRARY LDL_Vec2i LDL_BmpLoaderGetSize(LDL_BmpLoader* loader);
LDL_LIBRARY uint8_t* LDL_BmpLoaderGetPixels(LDL_BmpLoader* loader);
LDL_LIBRARY uint8_t LDL_BmpLoaderGetPixelFormat(LDL_BmpLoader* loader);
LDL_LIBRARY uint8_t LDL_BmpLoaderGetBytesPerPixels(LDL_BmpLoader* loader);

LDL_LIBRARY bool LDL_BmpLoaderLoadFromFile(LDL_BmpLoader* loader, const char* path);

#ifdef __cplusplus
}
#endif 

#endif
