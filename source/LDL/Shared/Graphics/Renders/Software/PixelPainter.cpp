// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/math.hpp>
#include <LDL/Core/Assert.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL;

PixelPainter::PixelPainter() :
	_red(0),
	_green(0),
	_blue(0),
	_alpha(0),
	_target(NULL),
	_width(0),
	_height(0),
	_bytesPerPixel(0),
	_pixels(NULL)
{
}

PixelPainter::~PixelPainter()
{
}

Surface* PixelPainter::Target()
{
	return _target;
}

const Vec2u& PixelPainter::Size()
{
	_size = Vec2u(_width, _height);

	return _size;
}

uint8_t PixelPainter::BytesPerPixel()
{
	return _bytesPerPixel;
}

uint8_t* PixelPainter::Pixels()
{
	return _pixels;
}

const LDL::Color& LDL::PixelPainter::Color()
{
	return _color;
}

void LDL::PixelPainter::Color(const LDL::Color& color)
{
	_color = color;

	_red   = _color.r;
	_green = _color.g;
	_blue  = _color.b;
	_alpha = _color.a;
}

void PixelPainter::Clear()
{
	size_t size = _width * _height * _bytesPerPixel;

	size_t i = 0;

	switch(_bytesPerPixel)
	{
  case 4:
	  for (i = 0; i < size; i += 4)
	  {
#if defined(LDL_CONFIG_COLOR_BGRA)
		  _pixels[i]     = _blue;
		  _pixels[i + 2] = _red;
#else
		  _pixels[i]     = _red;
		  _pixels[i + 2] = _blue;
#endif
		  _pixels[i + 1] = _green;
		  _pixels[i + 3] = _alpha;
	  }
	  break;
  case 3:
	  for (i = 0; i < size; i += 3)
	  {
#if defined(LDL_CONFIG_COLOR_BGRA)
		  _pixels[i] = _blue;
		  _pixels[i + 2] = _red;
#else
		  _pixels[i]     = _red;
		  _pixels[i + 2] = _blue;
#endif
		  _pixels[i + 1] = _green;
	  }
	  break;
  case 2:
	  for (i = 0; i < size; i += 2)
	  {
		  _pixels[i]     = _red;
		  _pixels[i + 1] = _green;
	  }
	  break;
  default:
	  for (i = 0; i < size; i++)
	  {
		  _pixels[i] = _red;
	  }
	}
}

void PixelPainter::Bind(Surface* source)
{
	LDL_ASSERT(source != NULL);

	_target = source;

	_width = _target->Size().x;
	_height = _target->Size().y;
	_bytesPerPixel = _target->BytesPerPixel();
	_pixels = _target->Pixels();
}

void PixelPainter::Pixel(const Vec2u& pos)
{
	size_t i = (_width * pos.y + pos.x) * _bytesPerPixel;

	if (i < _width * _height * _bytesPerPixel)
	{
		switch (_bytesPerPixel)
		{
		case 4:
#if defined(LDL_CONFIG_COLOR_BGRA)
			_pixels[i]     = _blue;
			_pixels[i + 2] = _red;
#else
			_pixels[i]     = _red;
			_pixels[i + 2] = _blue;
#endif
			_pixels[i + 1] = _green;
			_pixels[i + 3] = _alpha;
			break;
		case 3:
#if defined(LDL_CONFIG_COLOR_BGRA)
			_pixels[i]     = _blue;
			_pixels[i + 2] = _red;
#else
			_pixels[i]     = _red;
			_pixels[i + 2] = _blue;
#endif
			_pixels[i + 1] = _green;
			break;
		case 2:
			_pixels[i]     = _red;
			_pixels[i + 1] = _green;
			break;
		default:
			_pixels[i]     = _red;
		}
	}
}

const LDL::Color& PixelPainter::GetPixel(const Vec2u& pos)
{
	size_t i = (_width * pos.y + pos.x) * _bytesPerPixel;

	LDL_ASSERT(i < _width * _height * _bytesPerPixel);

	switch (_bytesPerPixel)
	{
	case 4:
#if defined(LDL_CONFIG_COLOR_BGRA)
		_colorGetPixel = LDL::Color(_pixels[i + 2], _pixels[i + 1], _pixels[i], _pixels[i + 3]);
#else
		_colorGetPixel = LDL::Color(_pixels[i], _pixels[i + 1], _pixels[i + 2], _pixels[i + 3]);
#endif
		break;
	case 3:
#if defined(LDL_CONFIG_COLOR_BGRA)
		_colorGetPixel = LDL::Color(_pixels[i + 2], _pixels[i + 1], _pixels[i], 0);
#else
		_colorGetPixel = LDL::Color(_pixels[i], _pixels[i + 1], _pixels[i + 2], 0);
#endif
		break;
	case 2:
		_colorGetPixel = LDL::Color(_pixels[i], _pixels[i + 1], 0, 0);
		break;
	default:
		_colorGetPixel = LDL::Color(_pixels[i], 0, 0, 0);
	}

	return _colorGetPixel;
}

void PixelPainter::Fill(const Vec2u& pos, const Vec2u& size)
{
	LDL_ASSERT(size.x > 0);
	LDL_ASSERT(size.y > 0);

	uint32_t x = pos.x;
	uint32_t y = pos.y;

	for (uint32_t i = 0; i < size.x; i++)
	{
		for (uint32_t j = 0; j < size.y; j++)
		{
			Pixel(Vec2u(x + i, y + j));
		}
	}
}

void PixelPainter::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	int x1 = (int)pos1.x;
	int y1 = (int)pos1.y;

	int x2 = (int)pos2.x;
	int y2 = (int)pos2.y;

	int deltaX;
	int deltaY;
	int signX;
	int signY;
	int error;
	int error2;

	deltaX = LDL::abs(x2 - x1);
	deltaY = LDL::abs(y2 - y1);
	signX = x1 < x2 ? 1 : -1;
	signY = y1 < y2 ? 1 : -1;

	error = deltaX - deltaY;

	Pixel(Vec2u(x2, y2));

	while (x1 != x2 || y1 != y2)
	{
		Pixel(Vec2u(x1, y1));

		error2 = error * 2;

		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}

		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}
