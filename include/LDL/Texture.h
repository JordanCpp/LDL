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

#ifndef LDL_Texture_H
#define LDL_Texture_H

#include <LDL/Vec2i.h>
#include <LDL/Context.h>
#include <LDL/PixFrmt.h>
#include <LDL/Enums.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Texture LDL_Texture;

LDL_LIBRARY LDL_Texture* LDL_TextureNewFromPixels(LDL_Context* context, size_t pixelFormat, LDL_Vec2i size, uint8_t* pixels);
LDL_LIBRARY LDL_Texture* LDL_TextureNewFromSize(LDL_Context* context, size_t pixelFormat, LDL_Vec2i size);
LDL_LIBRARY void LDL_TextureFree(LDL_Texture* texture);

LDL_LIBRARY LDL_Vec2i LDL_TextureGetSize(LDL_Texture* texture);

#ifdef __cplusplus
}
#endif 

#endif
