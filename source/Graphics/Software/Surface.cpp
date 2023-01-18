#include <LDL/Graphics/Surface.hpp>
#include <assert.h>
#include <string.h>

using namespace LDL::Graphics;

Surface::Surface(const Point2u& size, uint8_t bytesPerPixel) :
	_Capacity(size),
	_Size(_Capacity),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.PosX() > 0);
	assert(_Capacity.PosY() > 0);

	assert(_Size.PosX() > 0);
	assert(_Size.PosY() > 0);

	assert(_BytesPerPixel > 0);

	size_t bytes = _Size.PosX() * _Size.PosY() * _BytesPerPixel;

	_Pixels = new uint8_t[bytes];
}

Surface::Surface(const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Capacity(size),
	_Size(_Capacity),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.PosX() > 0);
	assert(_Capacity.PosY() > 0);

	assert(_Size.PosX() > 0);
	assert(_Size.PosY() > 0);

	assert(_BytesPerPixel > 0);

	assert(pixels != NULL);

	size_t bytes = _Size.PosX() * _Size.PosY() * _BytesPerPixel;

	_Pixels = new uint8_t[_Size.PosX() * _Size.PosY() * _BytesPerPixel];

	memcpy(_Pixels, pixels, bytes);
}

Surface::Surface(const Point2u& size, const Point2u& capacity, uint8_t bytesPerPixel) :
	_Capacity(capacity),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.PosX() > 0);
	assert(_Capacity.PosY() > 0);

	assert(_Size.PosX() > 0);
	assert(_Size.PosY() > 0);

	assert(_BytesPerPixel > 0);

	size_t bytes = _Size.PosX() * _Size.PosY() * _BytesPerPixel;

	_Pixels = new uint8_t[bytes];
}

Surface::Surface(const Point2u& size, const Point2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Capacity(capacity),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	assert(_Capacity.PosX() > 0);
	assert(_Capacity.PosY() > 0);

	assert(_Size.PosX() > 0);
	assert(_Size.PosY() > 0);

	assert(_BytesPerPixel > 0);

	assert(pixels != NULL);

	size_t bytes = _Size.PosX() * _Size.PosY() * _BytesPerPixel;

	_Pixels = new uint8_t[_Size.PosX() * _Size.PosY() * _BytesPerPixel];

	memcpy(_Pixels, pixels, bytes);
}

Surface::~Surface()
{
	delete[] _Pixels;
}

const Point2u& Surface::Capacity()
{
	return _Capacity;
}

const Point2u& Surface::Size()
{
	return _Size;
}

void Surface::Resize(const Point2u& size)
{
	if (size.PosX() <= Capacity().PosX() && size.PosY() <= Capacity().PosY())
		_Size = size;
}

void Surface::Clear()
{
	Resize(Point2u(0, 0));
}

uint8_t Surface::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* Surface::Pixels()
{
	return _Pixels;
}

Color Surface::Pixel(const Point2u& pos)
{
	size_t i = ((Size().PosX() * pos.PosY()) + pos.PosX()) * _BytesPerPixel;

	return Color(_Pixels[i], _Pixels[i + 1], _Pixels[i + 2]);
}