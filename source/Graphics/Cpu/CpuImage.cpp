#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <assert.h>

LDL::Graphics::CpuImage::CpuImage(const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel, uint8_t* pixels) :
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Size.PosX() > 0);
	assert(_Size.PosY() > 0);
	assert(_BytesPerPixel > 0);
	assert(pixels != NULL);

	size_t bytes = _Size.PosX() * _Size.PosY() * _BytesPerPixel;

	_Pixels = new uint8_t[bytes];

	memcpy(_Pixels, pixels, bytes);
}

LDL::Graphics::CpuImage::CpuImage(const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel) :
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