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
#include <LDL/Renders/GL/TexGL.h>

typedef struct LDL_3DRenderOpenGL2VertexBuffer
{
    GLuint VBO;
    size_t Format;
    size_t Count;
    size_t Stride;
    void*  Data;
} LDL_3DRenderOpenGL2VertexBuffer;

typedef struct LDL_ShaderProgram
{
    GLuint ID;
    GLint  uProjLoc;
    GLint  uViewLoc;
    GLint  uWorldLoc;
    GLint  uTextureLoc;
} LDL_ShaderProgram;

typedef struct LDL_3DRenderOpenGL2
{
    LDL_Result*       Result;
    LDL_Window*       Window;
    LDL_OpenGLLoader* Loader;
    LDL_ShaderProgram Shader;
} LDL_3DRenderOpenGL2;

void LDL_3DRenderOpenGL2Init(LDL_3DRenderOpenGL2* render, LDL_Result* result, LDL_Window* window);
void LDL_3DRenderOpenGL2Deinit(LDL_3DRenderOpenGL2* render);
void LDL_3DRenderOpenGL2Begin(LDL_3DRenderOpenGL2* render);
void LDL_3DRenderOpenGL2End(LDL_3DRenderOpenGL2* render);
void LDL_3DRenderOpenGL2Clear(LDL_3DRenderOpenGL2* render, float r, float g, float b);
void LDL_3DRenderOpenGL2VertexDraw(LDL_3DRenderOpenGL2* render, LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL2BindTexture(LDL_3DRenderOpenGL2* render, LDL_TextureOpenGL* texture);

LDL_3DRenderOpenGL2VertexBuffer* LDL_3DRenderOpenGL2VertexBufferCreate(size_t fvf);
void LDL_3DRenderOpenGL2VertexBufferDestroy(LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer);
void LDL_3DRenderOpenGL2VertexBufferCopy(LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer, size_t size, size_t count, void* source);

void LDL_3DRenderOpenGL2SetWorld(LDL_3DRenderOpenGL2* render, const float* matrix);
void LDL_3DRenderOpenGL2SetView(LDL_3DRenderOpenGL2* render, const float* matrix);
void LDL_3DRenderOpenGL2SetProjection(LDL_3DRenderOpenGL2* render, const float* matrix);

#endif
