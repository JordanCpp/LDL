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

#ifndef LDL_Renders_GL_TexGL_H
#define LDL_Renders_GL_TexGL_H

#include <LDL/Vec2i.h>
#include <LDL/Result.h>
#include <LDL/Palette.h>
#include <LDL/Context.h>
#include <LDL/OpenGL/GLTypes.h>

typedef struct LDL_TextureOpenGL
{
	GLuint       Id;
	LDL_Result*  Result;
	LDL_Vec2i    Size;
	LDL_Vec2i    Quad;
} LDL_TextureOpenGL;

LDL_TextureOpenGL* LDL_TextureOpenGLNewFromSize(LDL_Result* result, size_t pixelFormat, LDL_Vec2i size);
LDL_TextureOpenGL* LDL_TextureOpenGLNewFromPixels(LDL_Result* result, size_t pixelFormat, LDL_Vec2i size, uint8_t* pixels);
void LDL_TextureOpenGLFree(LDL_TextureOpenGL* texture);

LDL_Vec2i LDL_TextureOpenGLGetSize(LDL_TextureOpenGL* texture);
LDL_Vec2i LDL_TextureOpenGLGetQuad(LDL_TextureOpenGL* texture);

#endif
