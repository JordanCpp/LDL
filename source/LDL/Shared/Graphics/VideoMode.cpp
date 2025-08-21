#include <LDL/Graphics/VideoMode.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

VideoMode::VideoMode() :
	_bitsPerPixel(0)
{
}

VideoMode::VideoMode(const Vec2u& size, size_t bytesPerPixel) :
	_size(size),
	_bitsPerPixel(bytesPerPixel)
{
}

const Vec2u& VideoMode::Size()
{
	return _size;
}

size_t VideoMode::BitsPerPixel()
{
	return _bitsPerPixel;
}
