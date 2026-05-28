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

#ifndef LDL_Renders_GL1_RndrGL1_H
#define LDL_Renders_GL1_RndrGL1_H

#include <LDL/Mat4f.h>
#include <LDL/Render.h>
#include <LDL/Renders/BaseRndr.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/OpenGL/GL1_2.h>

typedef struct LDL_TextureOpenGL1 LDL_TextureOpenGL1;

typedef struct LDL_RenderOpenGL1
{
	LDL_Result*       Result;
	LDL_Window*       Window;
	LDL_OpenGLLoader* Loader;
	LDL_BaseRender    BaseRender;
	LDL_Mat4f         Projection;
	LDL_Mat4f         ModelView;
} LDL_RenderOpenGL1;

void LDL_RenderOpenGL1Init(LDL_RenderOpenGL1* render, LDL_Result* result, LDL_Window* window);
void LDL_RenderOpenGL1Deinit(LDL_RenderOpenGL1* render);

LDL_Color LDL_RenderOpenGL1GetColor(LDL_RenderOpenGL1* render);
void LDL_RenderOpenGL1SetColor(LDL_RenderOpenGL1* render, LDL_Color color);

void LDL_RenderOpenGL1Clear(LDL_RenderOpenGL1* render);
void LDL_RenderOpenGL1Line2i(LDL_RenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last);
void LDL_RenderOpenGL1Fill2i(LDL_RenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last);

void LDL_RenderOpenGL1Begin(LDL_RenderOpenGL1* render);
void LDL_RenderOpenGL1End(LDL_RenderOpenGL1* render);

void LDL_RenderOpenGL1Draw(LDL_RenderOpenGL1* render, LDL_TextureOpenGL1* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);

#endif
