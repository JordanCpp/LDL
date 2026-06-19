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

#ifndef LDL_Renders_Soft_TexSoft_H
#define LDL_Renders_Soft_TexSoft_H

#include <LDL/Vec2i.h>
#include <LDL/Result.h>
#include <LDL/Palette.h>
#include <LDL/Context.h>
#include <LDL/Surface.h>

typedef struct LDL_TextureSoftware
{
	LDL_Result*  Result;
	LDL_Surface* Surface;
} LDL_TextureSoftware;

LDL_TextureSoftware* LDL_TextureSoftwareCreateFromSize(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size);
LDL_TextureSoftware* LDL_TextureSoftwareCreateFromPixels(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels);
LDL_TextureSoftware* LDL_TextureSoftwareCreateFromSurface(LDL_Result* result, LDL_Surface* surface);
void LDL_TextureSoftwareDestroy(LDL_TextureSoftware* texture);

LDL_Vec2i LDL_TextureSoftwareGetSize(LDL_TextureSoftware* texture);

#endif
