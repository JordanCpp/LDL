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

#include <LDL/Renders/Soft/PixCopy.h>
#include <LDL/Renders/Soft/PixPaint.h>
#include <LDL/Renders/Soft/RndrSoft.h>

void LDL_2DRenderSoftwareInit(LDL_2DRenderSoftware* render, LDL_Result* result, LDL_Window* window)
{
    if (render && result && window)
    {
        render->Result = result;
        render->Window = window;

        LDL_BaseRenderInit(&render->BaseRender, LDL_ColorRgb(0, 0, 0));
    }
}

void LDL_2DRenderSoftwareDeinit(LDL_2DRenderSoftware* render)
{
    if (render)
    {
    }
}

size_t LDL_2DRenderSoftwareGetLayer(LDL_2DRenderSoftware* render)
{
    return render ? LDL_BaseRenderGetLayer(&render->BaseRender) : 0;
}

void LDL_2DRenderSoftwareSetLayer(LDL_2DRenderSoftware* render, size_t layer)
{
    if (render)
    {
        LDL_BaseRenderSetLayer(&render->BaseRender, layer);
    }
}

LDL_Color LDL_2DRenderSoftwareGetColor(LDL_2DRenderSoftware* render)
{
    return render ? LDL_BaseRenderGetColor(&render->BaseRender) : LDL_ColorRgb(0, 0, 0);
}

void LDL_2DRenderSoftwareSetColor(LDL_2DRenderSoftware* render, LDL_Color color)
{
    LDL_BaseRenderSetColor(&render->BaseRender, color);
}

void LDL_2DRenderSoftwareClear(LDL_2DRenderSoftware* render)
{
    LDL_Surface* surface;

    if (render)
    {
        surface = LDL_WindowGetScreen(render->Window);

        LDL_PixelPaintClear(
            LDL_SurfaceGetPixelFormat(surface),
            LDL_SurfaceGetPixels(surface),
            LDL_SurfaceGetSize(surface),
            LDL_2DRenderSoftwareGetColor(render));
    }
}

void LDL_2DRenderSoftwareBegin(LDL_2DRenderSoftware* render)
{
    if (render)
    {
    }
}

void LDL_2DRenderSoftwareEnd(LDL_2DRenderSoftware* render)
{
    if (render->Window)
    {
        LDL_WindowPresent(render->Window);
    }
}

void LDL_2DRenderSoftwareDraw(LDL_2DRenderSoftware* render, LDL_Surface* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
    LDL_Surface* surface;

    if (render)
    {
        surface = LDL_WindowGetScreen(render->Window);

        LDL_PixelCopy(
            LDL_SurfaceGetPixels(surface),
            LDL_SurfaceGetPixelFormat(surface),
            LDL_SurfaceGetSize(surface),
            dstPos ? *dstPos : LDL_GetVec2i(0, 0),
            dstSize ? *dstSize : LDL_SurfaceGetSize(surface),
            LDL_SurfaceGetPixels(texture),
            LDL_SurfaceGetPixelFormat(texture),
            LDL_SurfaceGetSize(texture),
            srcPos ? *srcPos : LDL_GetVec2i(0, 0),
            srcSize ? *srcSize : LDL_SurfaceGetSize(texture),
            LDL_SurfaceIsColorKey(texture),
            LDL_SurfaceGetColorKey(texture));
    }
}

void LDL_2DRenderSoftwareLine2i(LDL_2DRenderSoftware* render, LDL_Vec2i first, LDL_Vec2i last)
{
    LDL_Surface* surface;

    if (render)
    {
        surface = LDL_WindowGetScreen(render->Window);
        LDL_PixelPaintLine(
            LDL_SurfaceGetPixelFormat(surface),
            LDL_SurfaceGetPixels(surface),
            LDL_SurfaceGetSize(surface),
            first,
            last,
            LDL_2DRenderSoftwareGetColor(render));
    }
}

void LDL_2DRenderSoftwareFill2i(LDL_2DRenderSoftware* render, LDL_Vec2i first, LDL_Vec2i last)
{
    LDL_Surface* surface;

    if (render)
    {
        surface = LDL_WindowGetScreen(render->Window);
        LDL_PixelPaintFill(
            LDL_SurfaceGetPixelFormat(surface),
            LDL_SurfaceGetPixels(surface),
            LDL_SurfaceGetSize(surface),
            first,
            last,
            LDL_2DRenderSoftwareGetColor(render));
    }
}
