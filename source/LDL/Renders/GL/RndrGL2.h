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

#ifndef LDL_Renders_GL2_RndrGL2_H
#define LDL_Renders_GL2_RndrGL2_H

#include <LDL/Mat4f.h>
#include <LDL/Window.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/Renders/BaseRndr.h>
#include <LDL/Renders/GL/GLUtils.h>
#include <LDL/Renders/GL/BufferGL.h>

typedef struct LDL_TextureOpenGL LDL_TextureOpenGL;

typedef struct LDL_ShaderProgram
{
    GLuint program;
    GLint  aPosition;
    GLint  aTexCoord;
    GLint  aColor;
    GLint  uProjection;
    GLint  uModelView;
    GLint  uTexture;
    GLint  uUseTexture;
} LDL_ShaderProgram;

typedef struct LDL_RenderOpenGL2
{
    LDL_Result*       Result;
    LDL_Window*       Window;
    LDL_OpenGLLoader* Loader;
    LDL_BaseRender    BaseRender;
    LDL_Mat4f         Projection;
    LDL_Mat4f         ModelView;
    LDL_BufferOpenGL  Buffer;
    LDL_ShaderProgram Shader;
} LDL_RenderOpenGL2;

void LDL_RenderOpenGL2Init(LDL_RenderOpenGL2* render, LDL_Result* result, LDL_Window* window);
void LDL_RenderOpenGL2Deinit(LDL_RenderOpenGL2* render);

size_t LDL_RenderOpenGL2GetLayer(LDL_RenderOpenGL2* render);
void LDL_RenderOpenGL2SetLayer(LDL_RenderOpenGL2* render, size_t layer);

LDL_Color LDL_RenderOpenGL2GetColor(LDL_RenderOpenGL2* render);
void LDL_RenderOpenGL2SetColor(LDL_RenderOpenGL2* render, LDL_Color color);

void LDL_RenderOpenGL2Clear(LDL_RenderOpenGL2* render);
void LDL_RenderOpenGL2Line2i(LDL_RenderOpenGL2* render, LDL_Vec2i first, LDL_Vec2i last);
void LDL_RenderOpenGL2Fill2i(LDL_RenderOpenGL2* render, LDL_Vec2i first, LDL_Vec2i last);

void LDL_RenderOpenGL2Begin(LDL_RenderOpenGL2* render);
void LDL_RenderOpenGL2End(LDL_RenderOpenGL2* render);

void LDL_RenderOpenGL2Draw(LDL_RenderOpenGL2* render, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);

#endif
