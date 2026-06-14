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

#ifndef LDL_Image_H
#define LDL_Image_H

#include <LDL/Vec2i.h>
#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_ImageLoader LDL_ImageLoader;

LDL_LIBRARY LDL_ImageLoader* LDL_ImageLoaderCreate(LDL_Result* result);
LDL_LIBRARY void LDL_ImageLoaderDestroy(LDL_ImageLoader* imageLoader);
LDL_LIBRARY void LDL_ImageLoaderClear(LDL_ImageLoader* imageLoader);

LDL_LIBRARY void LDL_ImageLoaderLoadFromFile(LDL_ImageLoader* imageLoader, const char* path);
LDL_LIBRARY LDL_Vec2i LDL_ImageLoaderGetSize(LDL_ImageLoader* imageLoader);
LDL_LIBRARY uint8_t* LDL_ImageLoaderGetPixels(LDL_ImageLoader* imageLoader);
LDL_LIBRARY uint8_t LDL_ImageLoaderGetPixelFormat(LDL_ImageLoader* imageLoader);

#ifdef __cplusplus
}
#endif 

#endif
