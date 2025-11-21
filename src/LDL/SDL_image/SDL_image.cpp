// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <LDL/SDL/SDL_image.h>
#include <LDL/SDL/video.h>
#include <LDL/SDL/error.h>
#include <LDL/PixFrmt.hpp>

SDL_Surface* IMG_Load(const char* file)
{
	if (file == NULL)
	{
		SDL_SetError("Parametr %s is NULL\n", "file");

		return NULL;
	}

	SDL_Surface* result = NULL;

	int width    = 0;
	int	height   = 0;
	int channels = 0;
	Uint8* data  = stbi_load(file, &width, &height, &channels, STBI_default);

	if (data)
	{
		size_t pixelFormat = channels == 4 ? LDL_PixelFormat::RGBA32 : LDL_PixelFormat::RGB24;

		result = SDL_CreateRGBSurfaceFromPixels(pixelFormat, data, width, height, channels, 0, 0, 0, 0, 0);

		stbi_image_free(data);
	}
	else
	{
		SDL_SetError("Can't open file: %s\n", file);
	}

	return result;
}
