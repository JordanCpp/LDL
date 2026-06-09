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

#ifndef LDL_Surface_H
#define LDL_Surface_H

#include <LDL/Vec2i.h>
#include <LDL/Color.h>
#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Surface LDL_Surface;

LDL_LIBRARY void LDL_SurfaceDestroy(LDL_Surface* surface);
LDL_LIBRARY LDL_Surface* LDL_SurfaceCreateFromCapacity(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i capacity);
LDL_LIBRARY LDL_Surface* LDL_SurfaceCreateFromSize(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size);
LDL_LIBRARY LDL_Surface* LDL_SurfaceCreateFromPixels(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels);

LDL_LIBRARY LDL_Vec2i LDL_SurfaceGetCapacity(LDL_Surface* surface);
LDL_LIBRARY LDL_Vec2i LDL_SurfaceGetSize(LDL_Surface* surface);
LDL_LIBRARY uint8_t LDL_SurfaceGetBytesPerPixel(LDL_Surface* surface);
LDL_LIBRARY uint8_t* LDL_SurfaceGetPixels(LDL_Surface* surface);
LDL_LIBRARY uint8_t LDL_SurfaceGetPixelFormat(LDL_Surface* surface);
LDL_LIBRARY size_t LDL_SurfaceGetPitch(LDL_Surface* surface);
LDL_LIBRARY void LDL_SurfaceSetColorKey(LDL_Surface* surface, LDL_Color color);
LDL_LIBRARY LDL_Color LDL_SurfaceGetColorKey(LDL_Surface* surface);
LDL_LIBRARY bool LDL_SurfaceIsColorKey(LDL_Surface* surface);

#ifdef __cplusplus
}
#endif 

#endif
