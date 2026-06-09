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

#ifndef LDL_Renders_GL_2DRGL1_H
#define LDL_Renders_GL_2DRGL1_H

#include <LDL/Mat4f.h>
#include <LDL/2DRender.h>
#include <LDL/Window.h>
#include <LDL/Renders/BaseRndr.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/Renders/GL/GLUtils.h>
#include <LDL/Renders/GL/BufferGL.h>

typedef struct LDL_2DRenderOpenGL1
{
    LDL_Result*       Result;
    LDL_Window*       Window;
    LDL_OpenGLLoader* Loader;
    LDL_BaseRender    BaseRender;
    LDL_Mat4f         Projection;
    LDL_Mat4f         ModelView;
    LDL_BufferOpenGL  Buffer;
} LDL_2DRenderOpenGL1;

void LDL_2DRenderOpenGL1Init(LDL_2DRenderOpenGL1* render, LDL_Result* result, LDL_Window* window);
void LDL_2DRenderOpenGL1Deinit(LDL_2DRenderOpenGL1* render);

size_t LDL_2DRenderOpenGL1GetLayer(LDL_2DRenderOpenGL1* render);
void LDL_2DRenderOpenGL1SetLayer(LDL_2DRenderOpenGL1* render, size_t layer);

LDL_Color LDL_2DRenderOpenGL1GetColor(LDL_2DRenderOpenGL1* render);
void LDL_2DRenderOpenGL1SetColor(LDL_2DRenderOpenGL1* render, LDL_Color color);

void LDL_2DRenderOpenGL1Clear(LDL_2DRenderOpenGL1* render);
void LDL_2DRenderOpenGL1Line2i(LDL_2DRenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last);
void LDL_2DRenderOpenGL1Fill2i(LDL_2DRenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last);

void LDL_2DRenderOpenGL1Begin(LDL_2DRenderOpenGL1* render);
void LDL_2DRenderOpenGL1End(LDL_2DRenderOpenGL1* render);

void LDL_2DRenderOpenGL1Draw(LDL_2DRenderOpenGL1* render, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);

#endif
