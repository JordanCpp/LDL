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

#ifndef LDL_3DRender_H
#define LDL_3DRender_H

#include <LDL/Color.h>
#include <LDL/Window.h>
#include <LDL/Texture.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
    LDL_FVF_XYZ      = (1 << 0),
    LDL_FVF_XYZW     = (1 << 1),
    LDL_FVF_COLOR    = (1 << 2),
    LDL_FVF_NORMAL   = (1 << 3),
    LDL_FVF_TEXCOORD = (1 << 4)
};

typedef struct LDL_3DRender LDL_3DRender;
typedef struct LDL_VertexBuffer LDL_VertexBuffer;

LDL_LIBRARY LDL_3DRender* LDL_3DRenderCreate(LDL_Result* result, LDL_Context* context, LDL_Window* window);
LDL_LIBRARY void LDL_3DRenderDestroy(LDL_3DRender* render);

LDL_LIBRARY void LDL_3DRenderBegin(LDL_3DRender* render);
LDL_LIBRARY void LDL_3DRenderEnd(LDL_3DRender* render);

LDL_LIBRARY void LDL_3DRenderClear(LDL_3DRender* render, float r, float g, float b);
LDL_LIBRARY void LDL_3DRenderDraw(LDL_3DRender* render, LDL_VertexBuffer* vertexBuffer);

LDL_LIBRARY LDL_VertexBuffer* LDL_VertexBufferNew(LDL_Context* context, size_t fvf);
LDL_LIBRARY void LDL_VertexBufferFree(LDL_VertexBuffer* vertexBuffer);
LDL_LIBRARY void LDL_VertexBufferSet(LDL_VertexBuffer* vertexBuffer);
LDL_LIBRARY void LDL_VertexBufferCopy(LDL_VertexBuffer* vertexBuffer, size_t size, size_t count, void* source);

LDL_LIBRARY void LDL_3DRenderSetWorld(LDL_3DRender* render, const float* matrix);
LDL_LIBRARY void LDL_3DRenderSetView(LDL_3DRender* render, const float* matrix);
LDL_LIBRARY void LDL_3DRenderSetProjection(LDL_3DRender* render, const float* matrix);

#ifdef __cplusplus
}
#endif 

#endif
