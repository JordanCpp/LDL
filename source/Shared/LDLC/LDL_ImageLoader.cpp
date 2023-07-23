#include <LDLC/LDL_ImageLoader.h>
#include <LDL/Loaders/ImageLoader.hpp>

using namespace LDL::Loaders;
using namespace LDL::Graphics;
using namespace LDL::Allocators;

struct LDL_ImageLoader
{
	ImageLoader _ImageLoader;
	LDL_ImageLoader(void* allocator);
};

LDL_ImageLoader::LDL_ImageLoader(void* allocator) :
	_ImageLoader((Allocator*)allocator)
{
}

LDL_ImageLoader* LDL_ImageLoaderNew(void* allocator)
{
	LDL_ImageLoader* p = new LDL_ImageLoader(allocator);

	return p;
}

void LDL_ImageLoaderFree(LDL_ImageLoader* ptr)
{
	delete ptr;
}

size_t LDL_ImageLoaderGetSizeX(LDL_ImageLoader * imageLoader)
{
	return imageLoader->_ImageLoader.Size().x;
}

size_t LDL_ImageLoaderGetSizeY(LDL_ImageLoader* imageLoader)
{
	return imageLoader->_ImageLoader.Size().y;
}

uint8_t LDL_ImageLoaderGetBytesPerPixel(LDL_ImageLoader* imageLoader)
{
	return imageLoader->_ImageLoader.BytesPerPixel();
}

uint8_t* LDL_ImageLoaderGetPixels(LDL_ImageLoader* imageLoader)
{
	return imageLoader->_ImageLoader.Pixels();
}

void LDL_ImageLoaderLoadFromFile(LDL_ImageLoader* imageLoader, const char* path)
{
	imageLoader->_ImageLoader.Load(path);
}

void LDL_ImageLoaderLoadColorKeyFromFile(LDL_ImageLoader* imageLoader, uint8_t r, uint8_t g, uint8_t b, uint8_t a, const char* path)
{
	imageLoader->_ImageLoader.Load(Color(r,g,b,a), path);
}

void LDL_ImageLoaderLoadFromMemory(LDL_ImageLoader* imageLoader, uint8_t* data, size_t bytes)
{
	imageLoader->_ImageLoader.Load(data, bytes);
}

void LDL_ImageLoaderLoadColorKeyFromMemory(LDL_ImageLoader* imageLoader, uint8_t r, uint8_t g, uint8_t b, uint8_t a, uint8_t* data, size_t bytes)
{
	imageLoader->_ImageLoader.Load(Color(r, g, b, a), data, bytes);
}
