// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/StdFuncs.hpp>
#include <LDL/Assert.hpp>
#include <LDL/Surface.hpp>

LDL_Surface::LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size) :
	_enabled(false),
	_pixelFormat(pixelFormat),
	_capacity(size),
	_size(_capacity)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	_pixels.resize(_size.x * _size.y * LDL_BytesPerPixelFromPixelFormat(_pixelFormat));
}

LDL_Surface::LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels) :
	_enabled(false),
	_pixelFormat(pixelFormat),
	_capacity(size),
	_size(_capacity)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	LDL_ASSERT(pixels != NULL);

	_pixels.resize(_size.x * _size.y * LDL_BytesPerPixelFromPixelFormat(_pixelFormat));
	LDL_memcpy(_pixels.data(), pixels, _pixels.size());
}

LDL_Surface::LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size, const LDL_Vec2u& capacity) :
	_enabled(false),
	_pixelFormat(pixelFormat),
	_capacity(capacity),
	_size(size)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	_pixels.resize(_size.x * _size.y * LDL_BytesPerPixelFromPixelFormat(_pixelFormat));
}

LDL_Surface::LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size, const LDL_Vec2u& capacity, uint8_t* pixels) :
	_enabled(false),
	_pixelFormat(pixelFormat),
	_capacity(capacity),
	_size(size)
{
	LDL_ASSERT(_capacity.x > 0);
	LDL_ASSERT(_capacity.y > 0);

	LDL_ASSERT(_size.x > 0);
	LDL_ASSERT(_size.y > 0);

	LDL_ASSERT(pixels != NULL);

	_pixels.resize(_size.x * _size.y * LDL_BytesPerPixelFromPixelFormat(_pixelFormat));
	LDL_memcpy(_pixels.data(), pixels, _pixels.size());
}

LDL_Surface::~LDL_Surface()
{
}

void LDL_Surface::ColorKey(const LDL_Color& key)
{
	_enabled = true;
	_key     = key;
}

const LDL_Color& LDL_Surface::ColorKey()
{
	return _key;
}

bool LDL_Surface::Enabled()
{
	return _enabled;
}

const LDL_Vec2u& LDL_Surface::Capacity()
{
	return _capacity;
}

const LDL_Vec2u& LDL_Surface::Size()
{
	return _size;
}

void LDL_Surface::LDL_Resize(const LDL_Vec2u& size)
{
	if (size.x <= Capacity().x && size.y <= Capacity().y)
	{
		_size = size;
	}
}

void LDL_Surface::Clear()
{
	LDL_Resize(LDL_Vec2u(0, 0));
}

uint8_t LDL_Surface::BytesPerPixel()
{
	return LDL_BytesPerPixelFromPixelFormat(_pixelFormat);
}

uint8_t* LDL_Surface::Pixels()
{
	return _pixels.data();
}

size_t LDL_Surface::Format()
{
	return _pixelFormat;
}

size_t LDL_Surface::Pitch()
{
	return BytesPerPixel() * Size().x;
}
