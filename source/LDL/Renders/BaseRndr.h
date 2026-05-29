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

#ifndef LDL_BaseRndr_H
#define LDL_BaseRndr_H

#include <LDL/Color.h>

typedef struct LDL_BaseRender
{
	LDL_Color Color;
} LDL_BaseRender;

void LDL_BaseRenderInit(LDL_BaseRender* baseRender, LDL_Color color);
LDL_Color LDL_BaseRenderGetColor(LDL_BaseRender* baseRender);
void LDL_BaseRenderSetColor(LDL_BaseRender* baseRender, LDL_Color color);

#endif
