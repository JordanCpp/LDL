// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Palette.hpp>

LDL_Palette::LDL_Palette()
{
	for (size_t i = 0; i < Count(); i++)
	{
		_colors[i].r = 0;
		_colors[i].g = 0;
		_colors[i].b = 0;
		_colors[i].a = 0;
	}
}

LDL_Color* LDL_Palette::Colors()
{
	return _colors;
}

size_t LDL_Palette::Count()
{
	return Max;
}
