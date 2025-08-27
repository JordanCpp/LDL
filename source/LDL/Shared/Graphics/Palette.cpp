// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/Palette.hpp>

using namespace LDL;

Palette::Palette()
{
	for (size_t i = 0; i < Count(); i++)
	{
		_colors[i].r = 0;
		_colors[i].g = 0;
		_colors[i].b = 0;
		_colors[i].a = 0;
	}
}

Color* Palette::Colors()
{
	return _colors;
}

size_t Palette::Count()
{
	return Max;
}
