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

#ifndef LDL_Renders_GL_GLUtils_H
#define LDL_Renders_GL_GLUtils_H

#include <LDL/Vec2i.h>
#include <LDL/Color.h>
#include <LDL/OpenGL/GLTypes.h>

typedef struct LDL_GLColor
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
} LDL_GLColor;

size_t MaxTextureSize();
bool IsMaxTextureSize(LDL_Vec2i resolutionSize, int textureSize);
int SelectTextureSize(LDL_Vec2i size);
GLuint CreateTexture(GLsizei width, GLsizei height, GLint format);
void DeleteTexture(GLuint id);
LDL_GLColor LDL_GLNormalize(LDL_Color color);
void DrawQuad(LDL_Vec2i dstPos, LDL_Vec2i dstSize, LDL_Vec2i srcPos, LDL_Vec2i srcSize, size_t textureSize);

#endif
