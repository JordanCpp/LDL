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

#include <stdlib.h>
#include <LDL/PixFrmt.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/Renders/GL/GLUtils.h>
#include <LDL/Renders/GL1/TexGL1.h>

GLint BppToFormat(uint8_t bpp)
{
	return bpp == 3 ? GL_RGB : GL_RGBA;
}

LDL_TextureOpenGL1* LDL_TextureOpenGL1NewFromSize(size_t pixelFormat, LDL_Vec2i size)
{
	GLint format = 0;
	int quadSize;
	uint8_t bpp = LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	LDL_TextureOpenGL1* texture = (LDL_TextureOpenGL1*)malloc(sizeof(LDL_TextureOpenGL1));

	if (texture)
	{
		texture->Size  = size;
		format         = BppToFormat(bpp);
		quadSize       = SelectTextureSize(texture->Size);
		texture->Quad  = LDL_GetVec2i(quadSize, quadSize);
		texture->Id    = CreateTexture((GLsizei)texture->Quad.x, (GLsizei)texture->Quad.y, format);

		return texture;
	}

	return NULL;
}

LDL_TextureOpenGL1* LDL_TextureOpenGL1NewFromPixels(size_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	GLint format = 0;
	uint8_t bpp  = LDL_BytesPerPixelFromPixelFormat(pixelFormat);
	LDL_TextureOpenGL1* texture = LDL_TextureOpenGL1NewFromSize(pixelFormat, size);

	if (texture)
	{
		format = BppToFormat(bpp);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, (GLsizei)texture->Size.x, (GLsizei)texture->Size.y, format, GL_UNSIGNED_BYTE, pixels);
	}

	return texture;
}

void LDL_TextureOpenGL1Free(LDL_TextureOpenGL1* texture)
{
	if (texture)
	{
		DeleteTexture(texture->Id);
		free(texture);
	}
}

LDL_Vec2i LDL_TextureOpenGL1GetSize(LDL_TextureOpenGL1* texture)
{
	if (texture)
	{
		return texture->Size;
	}

	return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_TextureOpenGL1GetQuad(LDL_TextureOpenGL1* texture)
{
	if (texture)
	{
		return texture->Quad;
	}

	return LDL_GetVec2i(0, 0);
}
