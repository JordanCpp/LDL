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

#include <LDL/Image.h>
#include <LDL/PixFrmt.h>

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include <../dependencies/stb/stb_image.h>

struct LDL_ImageLoader
{
	uint8_t     Format;
	LDL_Vec2i   Size;
	uint8_t*    Pixels;
	LDL_Result* Result;
};

LDL_ImageLoader* LDL_ImageLoaderCreate(LDL_Result* result)
{
	LDL_ImageLoader* imageLoader = (LDL_ImageLoader*)malloc(sizeof(LDL_ImageLoader));

	if (imageLoader)
	{
		imageLoader->Size   = LDL_GetVec2i(0, 0);
		imageLoader->Pixels = NULL;
		imageLoader->Result = result;

		return imageLoader;
	}

	return NULL;
}

void LDL_ImageLoaderClear(LDL_ImageLoader* imageLoader)
{
	if (imageLoader && imageLoader->Pixels)
	{
		imageLoader->Size = LDL_GetVec2i(0, 0);
		stbi_image_free(imageLoader->Pixels);
		imageLoader->Pixels = NULL;
	}
}

void LDL_ImageLoaderDestroy(LDL_ImageLoader* imageLoader)
{
	if (imageLoader)
	{
		LDL_ImageLoaderClear(imageLoader);

		free(imageLoader);
	}
}

void LDL_ImageLoaderLoadFromFile(LDL_ImageLoader* imageLoader, const char* path)
{
	int w;
	int	h;
	int c;

	if (!imageLoader)
	{
		return;
	}

	if (!imageLoader->Result)
	{
		return;
	}

	if (!path)
	{
		LDL_ResultAddMessage(imageLoader->Result, "LDL_ImageLoad: Argument path is NULL\n");
		return;
	}

	if (imageLoader->Pixels)
	{
		LDL_ImageLoaderClear(imageLoader);
	}

	imageLoader->Pixels = stbi_load(path, &w, &h, &c, STBI_default);

	if (!imageLoader->Pixels)
	{
		LDL_ResultAddMessage(imageLoader->Result, "LDL_ImageLoad: Can't open file: %s %s\n", path, stbi_failure_reason());
		return;
	}

	imageLoader->Format = c == 4 ? LDL_PixelFormatRGBA32 : LDL_PixelFormatRGB24;
	imageLoader->Size   = LDL_GetVec2i(w, h);
}

LDL_Vec2i LDL_ImageLoaderGetSize(LDL_ImageLoader* imageLoader)
{
	return imageLoader ? imageLoader->Size : LDL_GetVec2i(0, 0);
}

uint8_t* LDL_ImageLoaderGetPixels(LDL_ImageLoader* imageLoader)
{
	return imageLoader ? imageLoader->Pixels : NULL;
}

uint8_t LDL_ImageLoaderGetPixelFormat(LDL_ImageLoader* imageLoader)
{
	return imageLoader ? imageLoader->Format : LDL_PixelFormatUnknown;
}
