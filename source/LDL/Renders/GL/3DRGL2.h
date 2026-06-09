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

#ifndef LDL_Renders_GL_3DRGL2_H
#define LDL_Renders_GL_3DRGL2_H

#include <LDL/3DRender.h>
#include <LDL/OpenGL/GLLoad.h>

typedef struct LDL_3DRenderOpenGL2VertexBuffer
{
    size_t       Format;
    size_t       Count;
    size_t       Size;
    void* Data;
} LDL_3DRenderOpenGL2VertexBuffer;

typedef struct LDL_3DRenderOpenGL2
{
    LDL_Result* Result;
    LDL_Window* Window;
    LDL_OpenGLLoader* Loader;
} LDL_3DRenderOpenGL2;

void LDL_3DRenderOpenGL2Init(LDL_3DRenderOpenGL2* render, LDL_Result* result, LDL_Window* window);
void LDL_3DRenderOpenGL2Deinit(LDL_3DRenderOpenGL2* render);
void LDL_3DRenderOpenGL2Begin(LDL_3DRenderOpenGL2* render);
void LDL_3DRenderOpenGL2End(LDL_3DRenderOpenGL2* render);
void LDL_3DRenderOpenGL2VertexDraw(LDL_3DRenderOpenGL2* render, LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer);

LDL_3DRenderOpenGL2VertexBuffer* LDL_3DRenderOpenGL2VertexBufferNew(size_t fvf);
void LDL_3DRenderOpenGL2VertexBufferFree(LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL2VertexBufferCopy(LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer, size_t size, size_t count, void* source);


#endif
