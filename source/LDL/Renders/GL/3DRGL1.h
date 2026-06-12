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

#ifndef LDL_Renders_GL_3DRGL1_H
#define LDL_Renders_GL_3DRGL1_H

#include <LDL/3DRender.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/Renders/GL/TexGL.h>

typedef struct LDL_3DRenderOpenGL1VertexBuffer
{
    size_t Format;
    size_t Count;
    size_t Size;
    void*  Data;
} LDL_3DRenderOpenGL1VertexBuffer;

typedef struct LDL_3DRenderOpenGL1
{
    LDL_Result*       Result;
    LDL_Window*       Window;
    LDL_OpenGLLoader* Loader;
    float             World[16];
    float             View[16];
    float             Projection[16];
} LDL_3DRenderOpenGL1;

void LDL_3DRenderOpenGL1Init(LDL_3DRenderOpenGL1* render, LDL_Result* result, LDL_Window* window);
void LDL_3DRenderOpenGL1Deinit(LDL_3DRenderOpenGL1* render);
void LDL_3DRenderOpenGL1Begin(LDL_3DRenderOpenGL1* render);
void LDL_3DRenderOpenGL1End(LDL_3DRenderOpenGL1* render);
void LDL_3DRenderOpenGL1Clear(LDL_3DRenderOpenGL1* render, float r, float g, float b);
void LDL_3DRenderOpenGL1VertexDraw(LDL_3DRenderOpenGL1* render, LDL_3DRenderOpenGL1VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL1BindTexture(LDL_3DRenderOpenGL1* render, LDL_TextureOpenGL* texture);

LDL_3DRenderOpenGL1VertexBuffer* LDL_3DRenderOpenGL1VertexBufferNew(size_t fvf);
void LDL_3DRenderOpenGL1VertexBufferFree(LDL_3DRenderOpenGL1VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL1VertexBufferCopy(LDL_3DRenderOpenGL1VertexBuffer* vertexBuffer, size_t size, size_t count, void* source);

void LDL_3DRenderOpenGL1SetWorld(LDL_3DRenderOpenGL1* render, const float* matrix);
void LDL_3DRenderOpenGL1SetView(LDL_3DRenderOpenGL1* render, const float* matrix);
void LDL_3DRenderOpenGL1SetProjection(LDL_3DRenderOpenGL1* render, const float* matrix);


#endif
