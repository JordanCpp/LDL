#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <assert.h>
#include <string.h>

LDL::Graphics::CpuImage::CpuImage(LDL::Loaders::ImageLoader* imageLoader) :
	_Allocator(NULL),
	_BytesPerPixel(0),
	_Pixels(NULL)
{
	assert(imageLoader != NULL);

	_Size = imageLoader->Size();
	_BytesPerPixel = imageLoader->BytesPerPixel();
	_Pixels = imageLoader->Pixels();

	assert(_Size.PosX() > 0);
	assert(_Size.PosY() > 0);
	assert(_BytesPerPixel > 0);
	assert(imageLoader->Pixels() != NULL);

	Copy(imageLoader);
}

LDL::Graphics::CpuImage::CpuImage(const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel) :
	_Allocator(NULL),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Size.PosX() > 0);
	assert(_Size.PosY() > 0);
	assert(_BytesPerPixel > 0);

	_Pixels = new uint8_t[_Size.PosX() * _Size.PosY() * _BytesPerPixel];
}

LDL::Graphics::CpuImage::~CpuImage()
{
	if (_Allocator != NULL)
		_Allocator->Deallocate(_Pixels);
	else
		delete[] _Pixels;
}

const LDL::Graphics::Point2u& LDL::Graphics::CpuImage::Size()
{
	return _Size;
}

uint8_t LDL::Graphics::CpuImage::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* LDL::Graphics::CpuImage::Pixels()
{
	return _Pixels;
}

LDL::Graphics::Color LDL::Graphics::CpuImage::Pixel(const LDL::Graphics::Point2u& pos)
{
	size_t i = ((Size().PosX() * pos.PosY()) + pos.PosX()) * _BytesPerPixel;

	return LDL::Graphics::Color(_Pixels[i], _Pixels[i + 1], _Pixels[i + 2]);
}

void LDL::Graphics::CpuImage::Copy(LDL::Loaders::ImageLoader* imageLoader)
{
	size_t bytes = _Size.PosX() * _Size.PosY() * _BytesPerPixel;

	_Pixels = new uint8_t[bytes];

	memcpy(_Pixels, imageLoader->Pixels(), bytes);
}