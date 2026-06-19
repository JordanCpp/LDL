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

#ifndef LDL_Renders_Soft_PixCopy_H
#define LDL_Renders_Soft_PixCopy_H

#include <LDL/Vec2i.h>
#include <LDL/Color.h>

void LDL_PixelCopy(uint8_t* dstPixels, size_t dstFormat, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, size_t srcFormat, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize, bool isColorKey, LDL_Color colorKey);

#endif
