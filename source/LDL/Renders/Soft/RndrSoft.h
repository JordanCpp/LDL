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

#ifndef LDL_Renders_Soft_RndrSoft_H
#define LDL_Renders_Soft_RndrSoft_H

#include <LDL/Window.h>
#include <LDL/Surface.h>
#include <LDL/2DRender.h>
#include <LDL/Renders/BaseRndr.h>

typedef struct LDL_2DRenderSoftware
{
    LDL_Result*       Result;
    LDL_Window*       Window;
    LDL_BaseRender    BaseRender;
} LDL_2DRenderSoftware;

void LDL_2DRenderSoftwareInit(LDL_2DRenderSoftware* render, LDL_Result* result, LDL_Window* window);
void LDL_2DRenderSoftwareDeinit(LDL_2DRenderSoftware* render);

size_t LDL_2DRenderSoftwareGetLayer(LDL_2DRenderSoftware* render);
void LDL_2DRenderSoftwareSetLayer(LDL_2DRenderSoftware* render, size_t layer);

LDL_Color LDL_2DRenderSoftwareGetColor(LDL_2DRenderSoftware* render);
void LDL_2DRenderSoftwareSetColor(LDL_2DRenderSoftware* render, LDL_Color color);

void LDL_2DRenderSoftwareClear(LDL_2DRenderSoftware* render);
void LDL_2DRenderSoftwareLine2i(LDL_2DRenderSoftware* render, LDL_Vec2i first, LDL_Vec2i last);
void LDL_2DRenderSoftwareFill2i(LDL_2DRenderSoftware* render, LDL_Vec2i first, LDL_Vec2i last);

void LDL_2DRenderSoftwareBegin(LDL_2DRenderSoftware* render);
void LDL_2DRenderSoftwareEnd(LDL_2DRenderSoftware* render);

void LDL_2DRenderSoftwareDraw(LDL_2DRenderSoftware* render, LDL_Surface* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);

#endif
