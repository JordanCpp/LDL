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

#include <stdlib.h>
#include <LDL/Palette.h>

struct LDL_Palette
{
	LDL_Color Colors[LDL_PaletteMax];
};

LDL_Palette* LDL_PaletteCreate()
{
	LDL_Palette* palette = (LDL_Palette*)malloc(sizeof(LDL_Palette));

	return palette;
}

void LDL_PaletteDestroy(LDL_Palette* palette)
{
	if (palette)
	{
		free(palette);
	}
}

LDL_Color LDL_PaletteGet(LDL_Palette* palette, size_t index)
{
	if (palette && index < LDL_PaletteMax)
	{
		return palette->Colors[index];
	}

	return LDL_ColorRgb(0, 0, 0);
}

void LDL_PaletteSet(LDL_Palette* palette, size_t index, LDL_Color color)
{
	if (palette && index < LDL_PaletteMax)
	{
		palette->Colors[index] = color;
	}
}
