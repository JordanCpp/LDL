// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/Color.hpp>

using namespace LDL;

Color::Color() :
	r(0),
	g(0),
	b(0),
	a(255)
{
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
	r(red),
	g(green),
	b(blue),
	a(alpha)
{
}

uint32_t Color::toInt() const
{
	return (uint32_t)((r << 24) | (g << 16) | (b << 8) | a);
}
