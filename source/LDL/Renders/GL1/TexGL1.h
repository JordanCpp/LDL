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

#ifndef LDL_Renders_GL1_TexGL1_H
#define LDL_Renders_GL1_TexGL1_H

#include <LDL/Vec2i.h>
#include <LDL/Context.h>
#include <LDL/OpenGL/GLTypes.h>

typedef struct LDL_TextureOpenGL1
{
	GLuint       Id;
	LDL_Vec2i    Size;
	LDL_Vec2i    Quad;
} LDL_TextureOpenGL1;

LDL_TextureOpenGL1* LDL_TextureOpenGL1NewFromSize(size_t pixelFormat, LDL_Vec2i size);
LDL_TextureOpenGL1* LDL_TextureOpenGL1NewFromPixels(size_t pixelFormat, LDL_Vec2i size, uint8_t* pixels);
void LDL_TextureOpenGL1Free(LDL_TextureOpenGL1* texture);

LDL_Vec2i LDL_TextureOpenGL1GetSize(LDL_TextureOpenGL1* texture);
LDL_Vec2i LDL_TextureOpenGL1GetQuad(LDL_TextureOpenGL1* texture);

#endif
