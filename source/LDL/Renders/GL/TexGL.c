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
#include <string.h>
#include <LDL/ErrorMsg.h>
#include <LDL/PixFrmt.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/GLUtils.h>

GLenum BppToFormat(uint8_t bpp)
{
	return bpp == 3 ? GL_RGB : GL_RGBA;
}

uint8_t* ExpandRGB24WithColorKey(LDL_Surface* surface, LDL_Color key)
{
	size_t i;
	uint8_t r;
	uint8_t g;
	uint8_t b;
	bool isKey;
	const size_t width = (size_t)LDL_SurfaceGetSize(surface).x;
	const size_t height = (size_t)LDL_SurfaceGetSize(surface).y;
	const size_t total = width * height;
	const uint8_t* src = LDL_SurfaceGetPixels(surface);
	uint8_t* pixels = (uint8_t*)malloc(total * 4);

	if (pixels == NULL)
	{
		return NULL;
	}

	for (i = 0; i < total; ++i)
	{
		r = src[i * 3 + 0];
		g = src[i * 3 + 1];
		b = src[i * 3 + 2];

		isKey = (r == key.r && g == key.g && b == key.b);

		pixels[i * 4 + 0] = r;
		pixels[i * 4 + 1] = g;
		pixels[i * 4 + 2] = b;
		pixels[i * 4 + 3] = isKey ? 0 : 255;
	}

	return pixels;
}

void ApplyColorKeyRGBA(uint8_t* pixels, size_t totalPixels, LDL_Color key)
{
	size_t i;
	uint8_t r;
	uint8_t g;
	uint8_t b;

	for (i = 0; i < totalPixels; ++i)
	{
		r = pixels[i * 4 + 0];
		g = pixels[i * 4 + 1];
		b = pixels[i * 4 + 2];

		if (r == key.r && g == key.g && b == key.b)
		{
			pixels[i * 4 + 3] = 0;
		}
	}
}

void SwapRedBlue(uint8_t* pixels, size_t totalPixels)
{
	size_t i;
	uint8_t r;
	uint8_t b;

	for (i = 0; i < totalPixels; ++i)
	{
		b = pixels[i * 4 + 0];
		r = pixels[i * 4 + 2];

		pixels[i * 4 + 0] = r;
		pixels[i * 4 + 2] = b;
	}
}

uint8_t* CopyWithColorKeyRGBA(LDL_Surface* surface, LDL_Color key)
{
	const size_t width  = (size_t)LDL_SurfaceGetSize(surface).x;
	const size_t height = (size_t)LDL_SurfaceGetSize(surface).y;
	const size_t total  = width * height;

	uint8_t* pixels = (uint8_t*)malloc(total * 4);

	if (pixels == NULL)
	{
		return NULL;
	}

	memcpy(pixels, LDL_SurfaceGetPixels(surface), total * 4);
	ApplyColorKeyRGBA(pixels, total, key);

	return pixels;
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
	format = BppToFormat(bpp);
	quadSize = SelectTextureSize(texture->Size);
	texture->Quad = LDL_GetVec2i(quadSize, quadSize);
	texture->Id = CreateTexture((GLsizei)texture->Quad.x, (GLsizei)texture->Quad.y, format);

	return texture;
}

LDL_TextureOpenGL* LDL_TextureOpenGLCreateFromPixels(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	GLenum format = 0;
	uint8_t bpp = LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	LDL_TextureOpenGL* texture = LDL_TextureOpenGLCreateFromSize(result, pixelFormat, size);

	if (texture == NULL)
	{
		return NULL;
	}

	if (pixels == NULL)
	{
		LDL_ResultAddMessage(result, LDL_ErrorInvalidArgument(), "pixels");
		LDL_TextureOpenGLDestroy(texture);
		return NULL;
	}

	format = BppToFormat(bpp);

	glTexSubImage2D(
		GL_TEXTURE_2D, 0, 0, 0,
		(GLsizei)texture->Size.x,
		(GLsizei)texture->Size.y,
		format,
		GL_UNSIGNED_BYTE,
		pixels);

	return texture;
}

LDL_TextureOpenGL* LDL_TextureOpenGLCreateFromSurface(LDL_Result* result, LDL_Surface* surface)
{
	uint8_t   pixelFormat;
	uint8_t   bpp;
	LDL_Vec2i size;
	size_t    totalPixels;
	LDL_Color key;
	uint8_t* pixels;
	LDL_TextureOpenGL* texture = NULL;

	if (result == NULL)
	{
		return NULL;
	}

	if (surface == NULL)
	{
		LDL_ResultAddMessage(result, LDL_ErrorInvalidArgument(), "surface");
		return NULL;
	}

	pixelFormat = LDL_SurfaceGetPixelFormat(surface);
	bpp = LDL_SurfaceGetBytesPerPixel(surface);
	size = LDL_SurfaceGetSize(surface);
	totalPixels = (size_t)size.x * (size_t)size.y;

	if (LDL_SurfaceIsColorKey(surface))
	{
		key = LDL_SurfaceGetColorKey(surface);
		pixels = NULL;

		if (bpp == 3)
		{
			pixels = ExpandRGB24WithColorKey(surface, key);

			if (pixels == NULL)
			{
				LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
				return NULL;
			}

			texture = LDL_TextureOpenGLCreateFromPixels(result, LDL_PixelFormatRGBA32, size, pixels);

			free(pixels);
		}
		else if (bpp == 4)
		{
			pixels = CopyWithColorKeyRGBA(surface, key);

			if (pixels == NULL)
			{
				LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
				return NULL;
			}

			texture = LDL_TextureOpenGLCreateFromPixels(result, pixelFormat, size, pixels);

			free(pixels);
		}
		else
		{
			LDL_ResultAddMessage(result, LDL_ErrorInvalidArgument(), "unsupported pixel format");
			return NULL;
		}

		return texture;
	}

	if (pixelFormat == LDL_PixelFormatBGRA32)
	{
		pixels = (uint8_t*)malloc(totalPixels * 4);

		if (pixels == NULL)
		{
			LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
			return NULL;
		}

		memcpy(pixels, LDL_SurfaceGetPixels(surface), totalPixels * 4);
		SwapRedBlue(pixels, totalPixels);

		texture = LDL_TextureOpenGLCreateFromPixels(result, LDL_PixelFormatRGBA32, size, pixels);

		free(pixels);
	}
	else
	{
		texture = LDL_TextureOpenGLCreateFromPixels(result, pixelFormat, size, LDL_SurfaceGetPixels(surface));
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
