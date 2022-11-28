#include <LDL/Graphics/VideoMode.hpp>

LDL::Graphics::VideoMode::VideoMode() :
	_BitsPerPixel(0)
{
}

LDL::Graphics::VideoMode::VideoMode(const LDL::Graphics::Point2u& size, size_t bytesPerPixel) :
	_Size(size),
	_BitsPerPixel(bytesPerPixel)
{
}

const LDL::Graphics::Point2u& LDL::Graphics::VideoMode::Size()
{
	return _Size;
}

size_t LDL::Graphics::VideoMode::BitsPerPixel()
{
	return _BitsPerPixel;
}