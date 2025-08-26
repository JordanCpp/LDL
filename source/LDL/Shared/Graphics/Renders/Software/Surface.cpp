// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/Surface.hpp>
#include <LDL/Core/Assert.hpp>
#include <LDL/std/string.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

Surface::Surface(const Vec2u& size, uint8_t bytesPerPixel) :
	_bytesPerPixel(bytesPerPixel),
	_enabled(false),
	_capacity(size),
	_size(_capacity)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	LDL_ASSERT(_bytesPerPixel > 0);

	_pixels.resize(_size.x * _size.y * _bytesPerPixel);
}

Surface::Surface(const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_bytesPerPixel(bytesPerPixel),
	_enabled(false),
	_capacity(size),
	_size(_capacity)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	LDL_ASSERT(_bytesPerPixel > 0);

	LDL_ASSERT(pixels != NULL);

	_pixels.resize(_size.x * _size.y * _bytesPerPixel);
	LDL::memcpy(_pixels.data(), pixels, _pixels.size());
}

Surface::Surface(const Vec2u& size, const Vec2u& capacity, uint8_t bytesPerPixel) :
	_bytesPerPixel(bytesPerPixel),
	_enabled(false),
	_capacity(capacity),
	_size(size)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	LDL_ASSERT(_bytesPerPixel > 0);

	_pixels.resize(_size.x * _size.y * _bytesPerPixel);
}

Surface::Surface(const Vec2u& size, const Vec2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel) :
	_bytesPerPixel(bytesPerPixel),
	_enabled(false),
	_capacity(capacity),
	_size(size)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	LDL_ASSERT(_bytesPerPixel > 0);

	LDL_ASSERT(pixels != NULL);

	_pixels.resize(_size.x * _size.y * _bytesPerPixel);
	LDL::memcpy(_pixels.data(), pixels, _pixels.size());
}

Surface::~Surface()
{
}

void Surface::ColorKey(const Graphics::Color& key)
{
	_enabled = true;
	_key     = key;
}

const LDL::Graphics::Color& Surface::ColorKey()
{
	return _key;
}

bool Surface::Enabled()
{
	return _enabled;
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
	{
		_size = size;
	}
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
	return _pixels.data();
}

Color Surface::Pixel(const Vec2u& pos)
{
	size_t i = ((Size().x * pos.y) + pos.x) * _bytesPerPixel;

	return Color(_pixels[i], _pixels[i + 1], _pixels[i + 2]);
}
