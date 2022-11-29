#include "DX5Image.hpp"
#include <assert.h>

LDL::Graphics::DX5Image::DX5Image(const LDL::Graphics::Point2u& size, size_t bytesPerPixel, uint8_t* pixels):
	_Id(0)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	assert(pixels != NULL);
}

LDL::Graphics::DX5Image::~DX5Image()
{
}

const LDL::Graphics::Point2u& LDL::Graphics::DX5Image::Size()
{
	return _Size;
}

const size_t LDL::Graphics::DX5Image::Id()
{
	return _Id;
}