// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Surface_hpp
#define LDL_Graphics_Surface_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>

namespace LDL
{
	class LDL_LIBRARY Surface
	{
	public:
		Surface(const Vec2u& size, uint8_t bytesPerPixel);
		Surface(const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
		Surface(const Vec2u& size, const Vec2u& capacity, uint8_t bytesPerPixel);
		Surface(const Vec2u& size, const Vec2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel);
		~Surface();
		const Vec2u& Capacity();
		const Vec2u& Size();
		void Resize(const Vec2u& size);
		void Clear();
		uint8_t BytesPerPixel();
		uint8_t* Pixels();
		Color Pixel(const Vec2u& pos);
	private:
		Vec2u     _capacity;
		Vec2u     _size;
		uint8_t   _bytesPerPixel;
		uint8_t*  _pixels;
	};
}

#endif 
