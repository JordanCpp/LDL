#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <string.h>

static LDL::Allocators::Allocator* StbImageAllocator;

#define STBI_MALLOC(sz)                    StbImageAllocator->Allocate(sz);
#define STBI_FREE(p)                       StbImageAllocator->Deallocate(p) 

void* ReallocateSized(void* ptr, size_t Oldbytes, size_t Newbytes)
{
	void* result = NULL;

	if (!ptr)
	{
		result = StbImageAllocator->Allocate(Newbytes);
	}
	else
	{
		if (Oldbytes < Newbytes)
		{
			result = StbImageAllocator->Allocate(Newbytes);
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
#include "../dependencies/stb/stb_image.h"  

using namespace LDL::Graphics;
using namespace LDL::Loaders;
using namespace LDL::Math;

ImageLoader::ImageLoader(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator),
	_BytesPerPixel(0),
	_Pixels(NULL)
{
	assert(allocator != NULL);

	StbImageAllocator = _Allocator;
}

ImageLoader::~ImageLoader()
{
	Clear();
}

void ImageLoader::Clear()
{
	_Allocator->Reset();
	_Pixels = NULL;
	_Size = Vec2u(0, 0);
	_BytesPerPixel = 0;
}

const Vec2u& ImageLoader::Size()
{
	return _Size;
}

uint8_t ImageLoader::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* ImageLoader::Pixels()
{
	return _Pixels;
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

		_Pixels = dstPixels;
		_BytesPerPixel = 4;
	}
}

void ImageLoader::Load(const std::string& path)
{
	if (path.empty())
		throw LDL::Core::RuntimeError("Argument path is empty");

	Clear();

	int width         = 0;
	int height        = 0;
	int bytesPerPixel = 0;

	_Pixels = stbi_load(path.c_str(), &width, &height, &bytesPerPixel, STBI_default);

	if (width <= 0 || height <= 0 || bytesPerPixel <= 0 || _Pixels == NULL)
		throw LDL::Core::RuntimeError("stbi_load " + path + " failed");

	_Size = Vec2u(width, height);
	_BytesPerPixel = bytesPerPixel;
}

void ImageLoader::Load(const Color& color, const std::string& path)
{
	Load(path);

	uint8_t* srcPixels = Pixels();

	size_t dstBytes = Size().x * Size().y * 4;

	uint8_t* dstPixels = (uint8_t*)_Allocator->Allocate(dstBytes);

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

	_Pixels = stbi_load_from_memory(data, (int)bytes, &width, &height, &bytesPerPixel, 0);

	if (width <= 0 || height <= 0 || bytesPerPixel <= 0 || _Pixels == NULL)
		throw LDL::Core::RuntimeError("stbi_load_from_memory failed");

	_Size = Vec2u(width, height);
	_BytesPerPixel = bytesPerPixel;
}

void ImageLoader::Load(const Color& color, uint8_t* data, size_t bytes)
{
	Load(data, bytes);

	uint8_t* srcPixels = Pixels();

	size_t dstBytes = Size().x * Size().y * 4;

	uint8_t* dstPixels = (uint8_t*)_Allocator->Allocate(dstBytes);

	CopyIf(dstPixels, srcPixels, dstBytes, color, 255);
}