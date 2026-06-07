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
#include <string.h>
#include <LDL/PixFrmt.h>
#include <LDL/Surface.h>
#include <LDL/ErrorMsg.h>

struct LDL_Surface
{
	bool        Enabled;
	uint8_t     PixelFormat;
	LDL_Color   ColorKey;
	LDL_Result* Result;
	LDL_Vec2i   Capacity;
	LDL_Vec2i   Size;
	uint8_t*    Pixels;
};

void LDL_SurfaceFree(LDL_Surface* surface)
{
	if (surface)
	{
		if (surface->Pixels)
		{
			free(surface->Pixels);
		}

		free(surface);
	}
}

LDL_Surface* LDL_SurfaceNewFromCapacity(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i capacity)
{
	size_t total;
	LDL_Surface* surface;

	if (result == NULL)
	{
		return NULL;
	}

	surface = (LDL_Surface*)malloc(sizeof(LDL_Surface));
	if (surface == NULL)
	{
		LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
		return NULL;
	}

	surface->Enabled     = false;
	surface->PixelFormat = pixelFormat;
	surface->Result      = result;
	surface->Capacity    = capacity;
	surface->Size        = LDL_GetVec2i(0, 0);

	total = capacity.x * capacity.y * LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	surface->Pixels = (uint8_t*)malloc(total);
	if (surface->Pixels == NULL)
	{
		free(surface);
		LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
		return NULL;
	}


	return surface;
}

LDL_Surface* LDL_SurfaceNewFromSize(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size)
{
	LDL_Surface* surface = LDL_SurfaceNewFromCapacity(result, pixelFormat, size);

	if (surface)
	{
		surface->Size = surface->Capacity;
	}

	return surface;
}

LDL_Surface* LDL_SurfaceNewFromPixels(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	LDL_Surface* surface = LDL_SurfaceNewFromSize(result, pixelFormat, size);

	if (surface)
	{
		memcpy(surface->Pixels, pixels, size.x * size.y * LDL_BytesPerPixelFromPixelFormat(pixelFormat));
	}

	return surface;
}

LDL_Vec2i LDL_SurfaceGetCapacity(LDL_Surface* surface)
{
	if (surface)
	{
		return surface->Capacity;
	}

	return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_SurfaceGetSize(LDL_Surface* surface)
{
	if (surface)
	{
		return surface->Size;
	}

	return LDL_GetVec2i(0, 0);
}

uint8_t LDL_SurfaceGetBytesPerPixel(LDL_Surface* surface)
{
	if (surface)
	{
		return LDL_BytesPerPixelFromPixelFormat(surface->PixelFormat);
	}

	return 0;
}

uint8_t* LDL_SurfaceGetPixels(LDL_Surface* surface)
{
	if (surface)
	{
		return surface->Pixels;
	}

	return NULL;
}

uint8_t LDL_SurfaceGetPixelFormat(LDL_Surface* surface)
{
	if (surface)
	{
		return surface->PixelFormat;
	}

	return 0;
}

size_t LDL_SurfaceGetPitch(LDL_Surface* surface)
{
	if (surface)
	{
		return LDL_SurfaceGetBytesPerPixel(surface) * LDL_SurfaceGetSize(surface).x;
	}

	return 0;
}

void LDL_SurfaceSetColorKey(LDL_Surface* surface, LDL_Color color)
{
	if (surface)
	{
		surface->Enabled  = true;
		surface->ColorKey = color;
	}
}

LDL_Color LDL_SurfaceGetColorKey(LDL_Surface* surface)
{
	if (surface && surface->Enabled)
	{
		return surface->ColorKey;
	}

	return LDL_ColorRgb(0, 0, 0);
}

bool LDL_SurfaceIsColorKey(LDL_Surface* surface)
{
	if (surface)
	{
		return surface->Enabled;
	}

	return false;
}
