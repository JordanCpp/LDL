#include <LDL/Graphics/VideoMode.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

VideoMode::VideoMode() :
	_BitsPerPixel(0)
{
}

VideoMode::VideoMode(const Vec2u& size, size_t bytesPerPixel) :
	_Size(size),
	_BitsPerPixel(bytesPerPixel)
{
}

const Vec2u& VideoMode::Size()
{
	return _Size;
}

size_t VideoMode::BitsPerPixel()
{
	return _BitsPerPixel;
}