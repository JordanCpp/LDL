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

#ifndef LDL_Palette_H
#define LDL_Palette_H

#include <LDL/Color.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
	LDL_PaletteMax = 256
};

typedef struct LDL_Palette LDL_Palette;

LDL_LIBRARY LDL_Palette* LDL_PaletteCreate();
LDL_LIBRARY void LDL_PaletteDestroy(LDL_Palette* palette);

LDL_LIBRARY LDL_Color LDL_PaletteGet(LDL_Palette* palette, size_t index);
LDL_LIBRARY void LDL_PaletteSet(LDL_Palette* palette, size_t index, LDL_Color color);

#ifdef __cplusplus
}
#endif 

#endif
