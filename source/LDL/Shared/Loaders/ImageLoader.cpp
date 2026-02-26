// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <LDL/Core/Assert.hpp>
#include <LDL/Loaders/ImageLoader.hpp>

using namespace LDL;

static LDL::Allocator* stbImageAllocator;

#define STBI_MALLOC(sz)  stbImageAllocator->Allocate(sz);
#define STBI_FREE(p)     stbImageAllocator->Deallocate(p) 

void* ReallocateSized(void* ptr, size_t Oldbytes, size_t Newbytes)
{
	void* result = NULL;

	if (!ptr)
	{
		result = stbImageAllocator->Allocate(Newbytes);
	}
	else
	{
		if (Oldbytes < Newbytes)
		{
			result = stbImageAllocator->Allocate(Newbytes);
			memcpy(result, ptr, Oldbytes);
		}
		else
		{
			result = ptr;
		}
	}

	return result;
}

#define STBI_REALLOC_SIZED(p,oldsz,newsz)  ReallocateSized(p, oldsz, newsz)

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_THREAD_LOCALS
#define STBI_NO_SIMD
#include "../../../dependencies/stb/stb_image.h"  

using namespace LDL;

ImageLoader::ImageLoader(Allocator* allocator) :
	_allocator(allocator),
	_bytesPerPixel(0),
	_pixels(NULL)
{
	assert(allocator != NULL);

	stbImageAllocator = _allocator;
}

ImageLoader::~ImageLoader()
{
	Clear();
}

void ImageLoader::Clear()
{
	_allocator->Reset();
	_pixels = NULL;
	_size = Vec2u(0, 0);
	_bytesPerPixel = 0;
}

const Vec2u& ImageLoader::Size()
{
	return _size;
}

uint8_t ImageLoader::BytesPerPixel()
{
	return _bytesPerPixel;
}

uint8_t* ImageLoader::Pixels()
{
	return _pixels;
}

void ImageLoader::CopyIf(uint8_t* dstPixels, uint8_t * srcPixels, size_t bytes, const Color& color, uint8_t alpha)
{
	for (size_t i = 0; i < bytes; i++)
	{
		if (srcPixels[3 * i + 0] == color.r && srcPixels[3 * i + 1] == color.g && srcPixels[3 * i + 2] == color.b)
		{
			dstPixels[4 * i + 0] = 0;
			dstPixels[4 * i + 1] = 0;
			dstPixels[4 * i + 2] = 0;
			dstPixels[4 * i + 3] = 0;
		}
		else
		{
			dstPixels[4 * i + 0] = srcPixels[3 * i + 0];
			dstPixels[4 * i + 1] = srcPixels[3 * i + 1];
			dstPixels[4 * i + 2] = srcPixels[3 * i + 2];
			dstPixels[4 * i + 3] = alpha;
		}

		_pixels = dstPixels;
		_bytesPerPixel = 4;
	}
}

void ImageLoader::Load(const char* path)
{
	LDL_ASSERT_DETAIL(path != NULL, "Argument path is empty");

	Clear();

	int width         = 0;
	int height        = 0;
	int bytesPerPixel = 0;

	_pixels = stbi_load(path, &width, &height, &bytesPerPixel, STBI_default);

	_assert = "stbi_load ";
	_assert += path;
	_assert += " failed";

	LDL_ASSERT_DETAIL(_pixels != NULL, _assert.c_str());

	_size = Vec2u(width, height);
	_bytesPerPixel = bytesPerPixel;
}

void ImageLoader::Load(const Color& color, const char* path)
{
	Load(path);

	uint8_t* srcPixels = Pixels();

	size_t dstBytes = Size().x * Size().y * 4;

	uint8_t* dstPixels = (uint8_t*)_allocator->Allocate(dstBytes);

	CopyIf(dstPixels, srcPixels, dstBytes, color, 255);
}

void ImageLoader::Load(uint8_t* data, size_t bytes)
{
	assert(data != NULL);
	assert(bytes > 0);

	Clear();

	int width         = 0;
	int height        = 0;
	int bytesPerPixel = 0;

	_pixels = stbi_load_from_memory(data, (int)bytes, &width, &height, &bytesPerPixel, 0);

	LDL_ASSERT_DETAIL(_pixels != NULL, "stbi_load_from_memory failed");

	_size = Vec2u(width, height);
	_bytesPerPixel = bytesPerPixel;
}

void ImageLoader::Load(const Color& color, uint8_t* data, size_t bytes)
{
	Load(data, bytes);

	uint8_t* srcPixels = Pixels();

	size_t dstBytes = Size().x * Size().y * 4;

	uint8_t* dstPixels = (uint8_t*)_allocator->Allocate(dstBytes);

	CopyIf(dstPixels, srcPixels, dstBytes, color, 255);
}
