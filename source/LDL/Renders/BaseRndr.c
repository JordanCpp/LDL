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

#include <LDL/Renders/BaseRndr.h>

void LDL_BaseRenderInit(LDL_BaseRender* baseRender, LDL_Color color)
{
	if (baseRender)
	{
		LDL_BaseRenderSetColor(baseRender, color);
	}
}

LDL_Color LDL_BaseRenderGetColor(LDL_BaseRender* baseRender)
{
	LDL_Color color;

	if (baseRender)
	{
		return baseRender->Color;
	}
	else
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
		color.a = 0;

		return color;
	}
}

void LDL_BaseRenderSetColor(LDL_BaseRender* baseRender, LDL_Color color)
{
	if (baseRender)
	{
		baseRender->Color = color;
	}
}
