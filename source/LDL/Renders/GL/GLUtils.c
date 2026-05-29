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

#include <LDL/OpenGL/GL1_2.h>
#include <LDL/Renders/GL/GLUtils.h>

enum
{
	TextureCount = 12
};

const uint32_t TextureSizes[TextureCount] = { 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 };

size_t MaxTextureSize()
{
	GLint result = 0;

	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &result);

	return result;
}

bool IsMaxTextureSize(LDL_Vec2i resolutionSize, int textureSize)
{
	if (textureSize >= resolutionSize.x && textureSize >= resolutionSize.y)
	{
		return true;
	}

	return false;
}

int SelectTextureSize(LDL_Vec2i size)
{
	size_t i;
	size_t w = size.x;
	size_t h = size.y;

	for (i = 0; i < TextureCount; i++)
	{
		if (w <= TextureSizes[i] && h <= TextureSizes[i])
		{
			return TextureSizes[i];
		}
	}

	return 0;
}

GLuint CreateTexture(GLsizei width, GLsizei height, GLint format)
{
	GLuint result = 0;

	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, NULL);

	return result;
}

void DeleteTexture(GLuint id)
{
	glDeleteTextures(1, &id);
}

LDL_GLColor LDL_GLNormalize(LDL_Color color)
{
	LDL_GLColor clr;

	clr.r = color.r / 255.0f;
	clr.g = color.g / 255.0f;
	clr.b = color.b / 255.0f;
	clr.a = color.a / 255.0f;

	return clr;
}

void DrawQuad(LDL_Vec2i dstPos, LDL_Vec2i dstSize, LDL_Vec2i srcPos, LDL_Vec2i srcSize, size_t textureSize)
{
	float x1 = (float)(dstPos.x);
	float y1 = (float)(dstPos.y);
	float x2 = (float)(dstPos.x + dstSize.x);
	float y2 = (float)(dstPos.y + dstSize.y);

	float u1 = (float)(srcPos.x) / textureSize;
	float v1 = (float)(srcPos.y) / textureSize;
	float u2 = (float)(srcPos.x + srcSize.x) / textureSize;
	float v2 = (float)(srcPos.y + srcSize.y) / textureSize;

	glBegin(GL_QUADS);
	glTexCoord2f(u1, v1); glVertex2f(x1, y1);
	glTexCoord2f(u2, v1); glVertex2f(x2, y1);
	glTexCoord2f(u2, v2); glVertex2f(x2, y2);
	glTexCoord2f(u1, v2); glVertex2f(x1, y2);
	glEnd();
}
