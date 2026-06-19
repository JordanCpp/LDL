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
#include <LDL/Texture.h>
#include <LDL/Renders/Texture.h>
#include <LDL/Renders/GL/TexGL.h>

LDL_Texture* LDL_TextureCreateFromPixels(LDL_Result* result, LDL_Context* context, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	LDL_Texture* texture = NULL;

	if (context)
	{
		texture = (LDL_Texture*)malloc(sizeof(LDL_Texture));
		if (texture == NULL)
		{
			LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
			return NULL;
		}

		if (texture)
		{
			texture->ContextType = LDL_ContextGet(context);

			switch (texture->ContextType)
			{
			case LDL_ContextOpenGLLegacy:
			case LDL_ContextOpenGLHybrid:
			case LDL_ContextOpenGLModern:
				texture->TextureOpenGL = LDL_TextureOpenGLCreateFromPixels(result, pixelFormat, size, pixels);
				return texture;
			case LDL_ContextSoftware:
				texture->TextureSoftware = LDL_TextureSoftwareCreateFromPixels(result, pixelFormat, size, pixels);
				return texture;
			}
		}
	}

	if (texture)
	{
		free(texture);
	}

	return NULL;
}

LDL_Texture* LDL_TextureCreateFromSize(LDL_Result* result, LDL_Context* context, uint8_t pixelFormat, LDL_Vec2i size)
{
	LDL_Texture* texture = NULL;

	if (context)
	{
		texture = (LDL_Texture*)malloc(sizeof(LDL_Texture));
		if (texture == NULL)
		{
			LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
			return NULL;
		}

		if (texture)
		{
			texture->ContextType = LDL_ContextGet(context);

			switch (texture->ContextType)
			{
			case LDL_ContextOpenGLLegacy:
			case LDL_ContextOpenGLHybrid:
			case LDL_ContextOpenGLModern:
				texture->TextureOpenGL = LDL_TextureOpenGLCreateFromSize(result, pixelFormat, size);
				return texture;
			case LDL_ContextSoftware:
				texture->TextureSoftware = LDL_TextureSoftwareCreateFromSize(result, pixelFormat, size);
				return texture;
			}
		}
	}

	if (texture)
	{
		free(texture);
	}

	return NULL;
}

LDL_Texture* LDL_TextureCreateFromSurface(LDL_Result* result, LDL_Context* context, LDL_Surface* surface)
{
	LDL_Texture* texture = NULL;

	if (context)
	{
		texture = (LDL_Texture*)malloc(sizeof(LDL_Texture));
		if (texture == NULL)
		{
			LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
			return NULL;
		}

		if (texture)
		{
			texture->ContextType = LDL_ContextGet(context);

			switch (texture->ContextType)
			{
			case LDL_ContextOpenGLLegacy:
			case LDL_ContextOpenGLHybrid:
			case LDL_ContextOpenGLModern:
				texture->TextureOpenGL = LDL_TextureOpenGLCreateFromSurface(result, surface);
				return texture;
			case LDL_ContextSoftware:
				texture->TextureSoftware = LDL_TextureSoftwareCreateFromSurface(result, surface);
				return texture;
			}
		}
	}

	if (texture)
	{
		free(texture);
	}

	return NULL;
}

void LDL_TextureDestroy(LDL_Texture* texture)
{
	if (texture)
	{

		switch (texture->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
		case LDL_ContextOpenGLModern:
			LDL_TextureOpenGLDestroy(texture->TextureOpenGL);
			break;
		case LDL_ContextSoftware:
			LDL_TextureSoftwareDestroy(texture->TextureSoftware);
			break;
		}
	}
}

LDL_Vec2i LDL_TextureGetSize(LDL_Texture* texture)
{
	if (texture)
	{
		switch (texture->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
		case LDL_ContextOpenGLModern:
			return LDL_TextureOpenGLGetSize(texture->TextureOpenGL);
		case LDL_ContextSoftware:
			return LDL_TextureSoftwareGetSize(texture->TextureSoftware);
		}
	}

	return LDL_GetVec2i(0, 0);
}
