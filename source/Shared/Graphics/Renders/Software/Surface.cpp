#include <LDL/Graphics/Surface.hpp>
#include <assert.h>
#include <string.h>

using namespace LDL::Graphics;
using namespace LDL::Math;

Surface::Surface(const Vec2u& size, uint8_t bytesPerPixel) :
	_Capacity(size),
	_Size(_Capacity),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.x > 0);
	assert(_Capacity.y > 0);

	assert(_Size.x > 0);
	assert(_Size.y > 0);

	assert(_BytesPerPixel > 0);

	size_t bytes = _Size.x * _Size.y * _BytesPerPixel;

	_Pixels = new uint8_t[bytes];
}

Surface::Surface(const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Capacity(size),
	_Size(_Capacity),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.x > 0);
	assert(_Capacity.y > 0);

	assert(_Size.x > 0);
	assert(_Size.y > 0);

	assert(_BytesPerPixel > 0);

	assert(pixels != NULL);

	size_t bytes = _Size.x * _Size.y * _BytesPerPixel;

	_Pixels = new uint8_t[_Size.x * _Size.y * _BytesPerPixel];

	memcpy(_Pixels, pixels, bytes);
}

Surface::Surface(const Vec2u& size, const Vec2u& capacity, uint8_t bytesPerPixel) :
	_Capacity(capacity),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.x > 0);
	assert(_Capacity.y > 0);

	assert(_Size.x > 0);
	assert(_Size.y > 0);

	assert(_BytesPerPixel > 0);

	size_t bytes = _Size.x * _Size.y * _BytesPerPixel;

	_Pixels = new uint8_t[bytes];
}

Surface::Surface(const Vec2u& size, const Vec2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Capacity(capacity),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.x > 0);
	assert(_Capacity.y > 0);

	assert(_Size.x > 0);
	assert(_Size.y > 0);

	assert(_BytesPerPixel > 0);

	assert(pixels != NULL);

	size_t bytes = _Size.x * _Size.y * _BytesPerPixel;

	_Pixels = new uint8_t[_Size.x * _Size.y * _BytesPerPixel];

	memcpy(_Pixels, pixels, bytes);
}

Surface::~Surface()
{
	delete[] _Pixels;
}

const Vec2u& Surface::Capacity()
{
	return _Capacity;
}

const Vec2u& Surface::Size()
{
	return _Size;
}

void Surface::Resize(const Vec2u& size)
{
	if (size.x <= Capacity().x && size.y <= Capacity().y)
		_Size = size;
}

void Surface::Clear()
{
	Resize(Vec2u(0, 0));
}

uint8_t Surface::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* Surface::Pixels()
{
	return _Pixels;
}

Color Surface::Pixel(const Vec2u& pos)
{
	size_t i = ((Size().x * pos.y) + pos.x) * _BytesPerPixel;

	return Color(_Pixels[i], _Pixels[i + 1], _Pixels[i + 2]);
}
