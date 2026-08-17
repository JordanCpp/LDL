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

LDL_TextureOpenGL* LDL_TextureOpenGLCreateFromSize(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size)
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

	texture->Size = size;
	format        = BppToFormat(bpp);
	quadSize      = SelectTextureSize(texture->Size);
	texture->Quad = LDL_GetVec2i(quadSize, quadSize);
	texture->Id   = CreateTexture((GLsizei)texture->Quad.x, (GLsizei)texture->Quad.y, format);

	return texture;
}

LDL_TextureOpenGL* LDL_TextureOpenGLCreateFromPixels(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	GLenum format              = 0;
	uint8_t bpp                = LDL_BytesPerPixelFromPixelFormat(pixelFormat);
	LDL_TextureOpenGL* texture = LDL_TextureOpenGLCreateFromSize(result, pixelFormat, size);

	if (texture)
	{
		format = BppToFormat(bpp);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, (GLsizei)texture->Size.x, (GLsizei)texture->Size.y, format, GL_UNSIGNED_BYTE, pixels);
	}

	return texture;
}

LDL_TextureOpenGL* LDL_TextureOpenGLCreateFromSurface(LDL_Result* result, LDL_Surface* surface)
{
	size_t i;
	size_t totalPixels;
	uint8_t* src;
	LDL_Color key;
	bool isKeyColor;
	uint8_t* pixels;
	LDL_TextureOpenGL* texture = NULL;

	if (!result)
	{
		return NULL;
	}

	if (!surface)
	{
		LDL_ResultAddMessage(result, LDL_ErrorInvalidArgument(), "surface");
		return NULL;
	}

	if (LDL_SurfaceIsColorKey(surface))
	{
		size_t width  = (size_t)LDL_SurfaceGetSize(surface).x;
		size_t height = (size_t)LDL_SurfaceGetSize(surface).y;

		pixels = (uint8_t*)malloc(width * height * 4);

		if (!pixels)
		{
			LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
			return NULL;
		}

		src         = LDL_SurfaceGetPixels(surface);
		key         = LDL_SurfaceGetColorKey(surface);
		totalPixels = width * height;

		if (LDL_SurfaceGetBytesPerPixel(surface) == 3)
		{
			for (i = 0; i < totalPixels; i++)
			{
				uint8_t r = src[i * 3 + 0];
				uint8_t g = src[i * 3 + 1];
				uint8_t b = src[i * 3 + 2];

				isKeyColor = (r == key.r && g == key.g && b == key.b);

				pixels[i * 4 + 0] = r;
				pixels[i * 4 + 1] = g;
				pixels[i * 4 + 2] = b;
				pixels[i * 4 + 3] = isKeyColor ? 0 : 255;
			}

			texture = LDL_TextureOpenGLCreateFromPixels(result, LDL_PixelFormatRGBA32, LDL_SurfaceGetSize(surface), pixels);

			free(pixels);
		}
		else
		{
			free(pixels);
		}
	}
	else
	{
		texture = LDL_TextureOpenGLCreateFromPixels(result, LDL_PixelFormatRGB24, LDL_SurfaceGetSize(surface), LDL_SurfaceGetPixels(surface));
	}

	return texture;
}

void LDL_TextureOpenGLDestroy(LDL_TextureOpenGL* texture)
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
