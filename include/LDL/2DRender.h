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

#ifndef LDL_2DRender_H
#define LDL_2DRender_H

#include <LDL/Color.h>
#include <LDL/Window.h>
#include <LDL/Texture.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_2DRender LDL_2DRender;

LDL_LIBRARY LDL_2DRender* LDL_2DRenderCreate(LDL_Result* result, LDL_Context* context, LDL_Window* window);
LDL_LIBRARY void LDL_2DRenderDestroy(LDL_2DRender* render);

LDL_LIBRARY size_t LDL_2DRenderGetLayer(LDL_2DRender* render);
LDL_LIBRARY void LDL_2DRenderSetLayer(LDL_2DRender* render, size_t layer);

LDL_LIBRARY LDL_Color LDL_2DRenderGetColor(LDL_2DRender* render);
LDL_LIBRARY void LDL_2DRenderSetColor(LDL_2DRender* render, LDL_Color color);

LDL_LIBRARY void LDL_2DRenderClear(LDL_2DRender* render);
LDL_LIBRARY void LDL_2DRenderLine(LDL_2DRender* render, LDL_Vec2i first, LDL_Vec2i last);
LDL_LIBRARY void LDL_2DRenderFill(LDL_2DRender* render, LDL_Vec2i first, LDL_Vec2i last);
LDL_LIBRARY void LDL_2DRenderDraw(LDL_2DRender* render, LDL_Texture* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);

LDL_LIBRARY void LDL_2DRenderBegin(LDL_2DRender* render);
LDL_LIBRARY void LDL_2DRenderEnd(LDL_2DRender* render);

#ifdef __cplusplus
}
#endif 

#endif
