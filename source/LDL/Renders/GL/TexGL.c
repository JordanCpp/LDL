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
#include <LDL/ErrorMsg.h>
#include <LDL/PixFrmt.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/GLUtils.h>

GLenum BppToFormat(uint8_t bpp)
{
	return bpp == 3 ? GL_RGB : GL_RGBA;
}

LDL_TextureOpenGL* LDL_TextureOpenGLNewFromSize(LDL_Result* result, size_t pixelFormat, LDL_Vec2i size)
{
	GLenum format = 0;
	int quadSize;
	uint8_t bpp = LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	LDL_TextureOpenGL* texture = (LDL_TextureOpenGL*)malloc(sizeof(LDL_TextureOpenGL));
	if (texture == NULL)
	{
		LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
		return NULL;
	}

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

LDL_TextureOpenGL* LDL_TextureOpenGLNewFromPixels(LDL_Result* result, size_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	GLenum format = 0;
	uint8_t bpp  = LDL_BytesPerPixelFromPixelFormat(pixelFormat);
	LDL_TextureOpenGL* texture = LDL_TextureOpenGLNewFromSize(result, pixelFormat, size);

	if (texture)
	{
		format = BppToFormat(bpp);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, (GLsizei)texture->Size.x, (GLsizei)texture->Size.y, format, GL_UNSIGNED_BYTE, pixels);
	}

	return texture;
}

void LDL_TextureOpenGLFree(LDL_TextureOpenGL* texture)
{
	if (texture)
	{
		DeleteTexture(texture->Id);
		free(texture);
	}
}

LDL_Vec2i LDL_TextureOpenGLGetSize(LDL_TextureOpenGL* texture)
{
	if (texture)
	{
		return texture->Size;
	}

	return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_TextureOpenGLGetQuad(LDL_TextureOpenGL* texture)
{
	if (texture)
	{
		return texture->Quad;
	}

	return LDL_GetVec2i(0, 0);
}
