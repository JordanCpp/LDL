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

#ifndef LDL_Ttf_H
#define LDL_Ttf_H

#include <LDL/Vec2i.h>
#include <LDL/Result.h>
#include <LDL/Color.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Font LDL_Font;
typedef struct LDL_Rasterizer LDL_Rasterizer;

LDL_Font* LDL_FontLoad(LDL_Result* result, const char* path, int size);
void LDL_FontDestroy(LDL_Font* font);

LDL_Rasterizer* LDL_RasterizerCreate(LDL_Result* result);
void LDL_RasterizerDestroy(LDL_Rasterizer* rasterizer);
void LDL_RasterizerText(LDL_Rasterizer* rasterizer, LDL_Font* font, LDL_Color color, const char* utf8_text);
LDL_Vec2i LDL_RasterizerGetSize(LDL_Rasterizer* rasterizer);
uint8_t* LDL_RasterizerGetPixels(LDL_Rasterizer* rasterizer);
uint8_t LDL_RasterizerGetPixelFormat(LDL_Rasterizer* rasterizer);

#ifdef __cplusplus
}
#endif 

#endif
