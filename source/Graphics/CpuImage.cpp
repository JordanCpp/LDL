#include <LDL/Graphics/CpuImage.hpp>

LDL::Graphics::CpuImage::CpuImage() :
	_BytesPerPixel(0),
	_Pixels(nullptr)
{
}

const LDL::Graphics::Point2u& LDL::Graphics::CpuImage::Size()
{
	return _Size;
}

size_t LDL::Graphics::CpuImage::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* LDL::Graphics::CpuImage::Pixels()
{
	return _Pixels;
}