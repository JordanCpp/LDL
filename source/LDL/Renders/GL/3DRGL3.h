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

#ifndef LDL_Renders_GL_3DRGL3_H
#define LDL_Renders_GL_3DRGL3_H

#include <LDL/3DRender.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/OpenGL/GLTypes.h>

typedef struct LDL_ShaderProgram
{
    GLuint ID;
} LDL_ShaderProgram;

typedef struct LDL_3DRenderOpenGL3VertexBuffer
{
    size_t Format;
    size_t Count;
    size_t Size;
    void*  Data;
} LDL_3DRenderOpenGL3VertexBuffer;

typedef struct LDL_3DRenderOpenGL3
{
    LDL_ShaderProgram Shader;
    LDL_Result*       Result;
    LDL_Window*       Window;
    LDL_OpenGLLoader* Loader;
} LDL_3DRenderOpenGL3;

void LDL_3DRenderOpenGL3Init(LDL_3DRenderOpenGL3* render, LDL_Result* result, LDL_Window* window);
void LDL_3DRenderOpenGL3Deinit(LDL_3DRenderOpenGL3* render);
void LDL_3DRenderOpenGL3Begin(LDL_3DRenderOpenGL3* render);
void LDL_3DRenderOpenGL3End(LDL_3DRenderOpenGL3* render);
void LDL_3DRenderOpenGL3VertexDraw(LDL_3DRenderOpenGL3* render, LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer);

LDL_3DRenderOpenGL3VertexBuffer* LDL_3DRenderOpenGL3VertexBufferNew(size_t fvf);
void LDL_3DRenderOpenGL3VertexBufferFree(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL3VertexBufferCopy(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer, size_t size, size_t count, void* source);


#endif
