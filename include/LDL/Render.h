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

#ifndef LDL_Render_H
#define LDL_Render_H

#include <LDL/Color.h>
#include <LDL/Window.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Texture LDL_Texture;
typedef struct LDL_Render LDL_Render;

// New and Free
LDL_LIBRARY LDL_Render* LDL_RenderNew(LDL_Result* result, LDL_Context* context, LDL_Window* window);
LDL_LIBRARY void LDL_RenderFree(LDL_Render* render);

// Get and Set
LDL_LIBRARY LDL_Color LDL_RenderGetColor(LDL_Render* render);
LDL_LIBRARY void LDL_RenderSetColor(LDL_Render* render, LDL_Color color);

// Draw
LDL_LIBRARY void LDL_RenderClear(LDL_Render* render);
LDL_LIBRARY void LDL_RenderLine2i(LDL_Render* render, LDL_Vec2i first, LDL_Vec2i last);
LDL_LIBRARY void LDL_RenderFill2i(LDL_Render* render, LDL_Vec2i first, LDL_Vec2i last);
LDL_LIBRARY void LDL_RenderDraw(LDL_Render* render, LDL_Texture* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);
// Present
LDL_LIBRARY void LDL_RenderBegin(LDL_Render* render);
LDL_LIBRARY void LDL_RenderEnd(LDL_Render* render);

#ifdef __cplusplus
}
#endif 

#endif
