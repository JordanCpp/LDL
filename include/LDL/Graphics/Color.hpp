// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Color_hpp
#define LDL_Graphics_Color_hpp

#include <LDL/std/stdint.hpp>

namespace LDL
{
	class Color
	{
	public:
		Color() :
			r(0),
			g(0),
			b(0),
			a(255)
		{
		}

		Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255) :
			r(red),
			g(green),
			b(blue),
			a(alpha)
		{
		}

		uint32_t toInt() const
		{
			return (uint32_t)((r << 24) | (g << 16) | (b << 8) | a);
		}

		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
}

#endif    
