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
#include <LDL/Renders/GL/TexGL.h>

typedef struct LDL_3DRenderOpenGL3ShaderProgram
{
    GLuint ID;
    GLint  uProjLoc;
    GLint  uViewLoc;
    GLint  uWorldLoc;
    GLint  uTextureLoc;
} LDL_3DRenderOpenGL3ShaderProgram;

typedef struct LDL_3DRenderOpenGL3VertexBuffer
{
    GLuint VAO;
    GLuint VBO;
    size_t Format;
    size_t Count;
    size_t Stride;
} LDL_3DRenderOpenGL3VertexBuffer;

typedef struct LDL_3DRenderOpenGL3
{
    LDL_3DRenderOpenGL3ShaderProgram Shader;
    LDL_Result*       Result;
    LDL_Window*       Window;
    LDL_OpenGLLoader* Loader;
} LDL_3DRenderOpenGL3;

void LDL_3DRenderOpenGL3Init(LDL_3DRenderOpenGL3* render, LDL_Result* result, LDL_Window* window);
void LDL_3DRenderOpenGL3Deinit(LDL_3DRenderOpenGL3* render);
void LDL_3DRenderOpenGL3Begin(LDL_3DRenderOpenGL3* render);
void LDL_3DRenderOpenGL3End(LDL_3DRenderOpenGL3* render);
void LDL_3DRenderOpenGL3Clear(LDL_3DRenderOpenGL3* render, float r, float g, float b);
void LDL_3DRenderOpenGL3VertexDraw(LDL_3DRenderOpenGL3* render, LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL3BindTexture(LDL_3DRenderOpenGL3* render, LDL_TextureOpenGL* texture);

LDL_3DRenderOpenGL3VertexBuffer* LDL_3DRenderOpenGL3VertexBufferCreate(size_t fvf);
void LDL_3DRenderOpenGL3VertexBufferDestroy(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL3VertexBufferCopy(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer, size_t stride, size_t count, void* source);

void LDL_3DRenderOpenGL3SetWorld(LDL_3DRenderOpenGL3* render, const float* matrix);
void LDL_3DRenderOpenGL3SetView(LDL_3DRenderOpenGL3* render, const float* matrix);
void LDL_3DRenderOpenGL3SetProjection(LDL_3DRenderOpenGL3* render, const float* matrix);

#endif
