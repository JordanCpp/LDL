// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelPainter_hpp
#define LDL_Graphics_PixelPainter_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	class LDL_LIBRARY PixelPainter
	{
	public:
		PixelPainter();
		~PixelPainter();
		Surface* Target();
		const Vec2u& Size();
		uint8_t BytesPerPixel();
		uint8_t* Pixels();
		const Color& GetColor();
		void SetColor(const Color& color);
		void Clear();
		void Bind(Surface* source);
		void Pixel(const Vec2u& pos);
		const Color& GetPixel(const Vec2u& pos);
		void Fill(const Vec2u& pos, const Vec2u& size);
		void Line(const Vec2u& pos1, const Vec2u& pos2);
	private:
		uint8_t   _red;
		uint8_t   _green;
		uint8_t   _blue;
		uint8_t   _alpha;
		Surface*  _target;
		size_t    _width;
		size_t    _height;
		uint8_t   _bytesPerPixel;
		uint8_t*  _pixels;
		Vec2u     _size;
		Color     _color;
		Color     _colorGetPixel;
	};
}

#endif 
