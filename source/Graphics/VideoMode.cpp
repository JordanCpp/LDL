#include <LDL/Graphics/VideoMode.hpp>

using namespace LDL::Graphics;

VideoMode::VideoMode() :
	_BitsPerPixel(0)
{
}

VideoMode::VideoMode(const Point2u& size, size_t bytesPerPixel) :
	_Size(size),
	_BitsPerPixel(bytesPerPixel)
{
}

const Point2u& VideoMode::Size()
{
	return _Size;
}

size_t VideoMode::BitsPerPixel()
{
	return _BitsPerPixel;
}