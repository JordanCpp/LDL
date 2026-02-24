// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <assert.h>
#include <string.h>
#include <LDL/Graphics/Surface.hpp>

using namespace LDL;

Surface::Surface(const Vec2u& size, uint8_t bytesPerPixel) :
	_capacity(size),
	_size(_capacity),
	_bytesPerPixel(bytesPerPixel),
	_pixels(NULL)
{
	assert(_capacity.x > 0);
	assert(_capacity.y > 0);

	assert(_size.x > 0);
	assert(_size.y > 0);

	assert(_bytesPerPixel > 0);

	size_t bytes = _size.x * _size.y * _bytesPerPixel;

	_pixels = new uint8_t[bytes];
}

Surface::Surface(const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_capacity(size),
	_size(_capacity),
	_bytesPerPixel(bytesPerPixel),
	_pixels(NULL)
{
	assert(_capacity.x > 0);
	assert(_capacity.y > 0);

	assert(_size.x > 0);
	assert(_size.y > 0);

	assert(_bytesPerPixel > 0);

	assert(pixels != NULL);

	size_t bytes = _size.x * _size.y * _bytesPerPixel;

	_pixels = new uint8_t[_size.x * _size.y * _bytesPerPixel];

	memcpy(_pixels, pixels, bytes);
}

Surface::Surface(const Vec2u& size, const Vec2u& capacity, uint8_t bytesPerPixel) :
	_capacity(capacity),
	_size(size),
	_bytesPerPixel(bytesPerPixel),
	_pixels(NULL)
{
	assert(_capacity.x > 0);
	assert(_capacity.y > 0);

	assert(_size.x > 0);
	assert(_size.y > 0);

	assert(_bytesPerPixel > 0);

	size_t bytes = _size.x * _size.y * _bytesPerPixel;

	_pixels = new uint8_t[bytes];
}

Surface::Surface(const Vec2u& size, const Vec2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel) :
	_capacity(capacity),
	_size(size),
	_bytesPerPixel(bytesPerPixel),
	_pixels(NULL)
{
	assert(_capacity.x > 0);
	assert(_capacity.y > 0);

	assert(_size.x > 0);
	assert(_size.y > 0);

	assert(_bytesPerPixel > 0);

	assert(pixels != NULL);

	size_t bytes = _size.x * _size.y * _bytesPerPixel;

	_pixels = new uint8_t[_size.x * _size.y * _bytesPerPixel];

	memcpy(_pixels, pixels, bytes);
}

Surface::~Surface()
{
	delete[] _pixels;
}

const Vec2u& Surface::Capacity()
{
	return _capacity;
}

const Vec2u& Surface::Size()
{
	return _size;
}

void Surface::Resize(const Vec2u& size)
{
	if (size.x <= Capacity().x && size.y <= Capacity().y)
		_size = size;
}

void Surface::Clear()
{
	Resize(Vec2u(0, 0));
}

uint8_t Surface::BytesPerPixel()
{
	return _bytesPerPixel;
}

uint8_t* Surface::Pixels()
{
	return _pixels;
}

Color Surface::Pixel(const Vec2u& pos)
{
	size_t i = ((Size().x * pos.y) + pos.x) * _bytesPerPixel;

	return Color(_pixels[i], _pixels[i + 1], _pixels[i + 2]);
}
