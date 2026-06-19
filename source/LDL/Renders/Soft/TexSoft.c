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

#include <stdlib.h>
#include <LDL/PixFrmt.h>
#include <LDL/ErrorMsg.h>
#include <LDL/Renders/Soft/TexSoft.h>

LDL_TextureSoftware* LDL_TextureSoftwareCreateFromSize(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size)
{
	LDL_TextureSoftware* texture = (LDL_TextureSoftware*)malloc(sizeof(LDL_TextureSoftware));

	if (texture)
	{
		texture->Surface = LDL_SurfaceCreateFromSize(result, pixelFormat, size);

		return texture;
	}

	return NULL;
}

LDL_TextureSoftware* LDL_TextureSoftwareCreateFromPixels(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	LDL_TextureSoftware* texture = (LDL_TextureSoftware*)malloc(sizeof(LDL_TextureSoftware));

	if (texture)
	{
		texture->Surface = LDL_SurfaceCreateFromPixels(result, pixelFormat, size, pixels);
		
		return texture;
	}

	return NULL;
}

LDL_TextureSoftware* LDL_TextureSoftwareCreateFromSurface(LDL_Result* result, LDL_Surface* surface)
{
	LDL_TextureSoftware* texture = (LDL_TextureSoftware*)malloc(sizeof(LDL_TextureSoftware));

	if (texture)
	{
		texture->Surface = LDL_SurfaceCreateFromPixels(result, LDL_SurfaceGetPixelFormat(surface), LDL_SurfaceGetSize(surface), LDL_SurfaceGetPixels(surface));
		
		if (LDL_SurfaceIsColorKey(surface))
		{
			LDL_SurfaceSetColorKey(texture->Surface, LDL_SurfaceGetColorKey(surface));
		}

		return texture;
	}

	return NULL;
}

void LDL_TextureSoftwareDestroy(LDL_TextureSoftware* texture)
{
	if (texture)
	{
		if (texture->Surface)
		{
			LDL_SurfaceDestroy(texture->Surface);
		}

		free(texture);
	}
}

LDL_Vec2i LDL_TextureSoftwareGetSize(LDL_TextureSoftware* texture)
{
	if (texture && texture->Surface)
	{
		return LDL_SurfaceGetSize(texture->Surface);
	}

	return LDL_GetVec2i(0, 0);
}
