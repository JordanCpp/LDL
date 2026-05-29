/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <LDL/Color.h>

LDL_Color LDL_ColorRgb(uint8_t r, uint8_t g, uint8_t b)
{
	LDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 0;

	return color;
}

LDL_Color LDL_ColorRgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	LDL_Color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;

	return color;
}
