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

#ifndef LDL_Renders_Soft_PixPaint_H
#define LDL_Renders_Soft_PixPaint_H

#include <LDL/Vec2i.h>
#include <LDL/Color.h>

void LDL_PixelPaintClearBGR24(uint8_t* pixels, LDL_Vec2i size, LDL_Color color);
void LDL_PixelPaintClearRGB24(uint8_t* pixels, LDL_Vec2i size, LDL_Color color);
void LDL_PixelPaintClear(size_t pixelFormat, uint8_t* pixels, LDL_Vec2i size, LDL_Color color);

void LDL_PixelPaintLineBGR24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color);
void LDL_PixelPaintLineRGB24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color);
void LDL_PixelPaintLine(size_t pixelFormat, uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color);

void LDL_PixelPaintFillBGR24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color);
void LDL_PixelPaintFillRGB24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color);
void LDL_PixelPaintFill(size_t pixelFormat, uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color);

#endif
