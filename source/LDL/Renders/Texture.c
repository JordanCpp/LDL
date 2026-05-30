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
#include <LDL/Texture.h>
#include <LDL/Renders/Texture.h>
#include <LDL/Renders/GL1/TexGL1.h>

LDL_Texture* LDL_TextureNewFromPixels(LDL_Context* context, size_t pixelFormat, LDL_Vec2i size, uint8_t* pixels)
{
	LDL_Texture* texture;

	if (context)
	{
		texture = (LDL_Texture*)malloc(sizeof(LDL_Texture));

		if (texture)
		{
			texture->Context = context;

			switch (LDL_ContextGet(context))
			{
			case LDL_ContextOpenGLLegacy:
				texture->TextureOpenGL1 = LDL_TextureOpenGL1NewFromPixels(pixelFormat, size, pixels);
				return texture;
			}
		}
	}

	return NULL;
}

LDL_Texture* LDL_TextureNewFromSize(LDL_Context* context, size_t pixelFormat, LDL_Vec2i size)
{
	LDL_Texture* texture;

	if (context)
	{
		texture = (LDL_Texture*)malloc(sizeof(LDL_Texture));

		if (texture)
		{
			texture->Context = context;

			switch (LDL_ContextGet(context))
			{
			case LDL_ContextOpenGLLegacy:
				texture->TextureOpenGL1 = LDL_TextureOpenGL1NewFromSize(pixelFormat, size);
				return texture;
			}
		}
	}

	return NULL;
}

void LDL_TextureFree(LDL_Texture* texture)
{
	if (texture)
	{
		if (texture->Context)
		{
			switch (LDL_ContextGet(texture->Context))
			{
			case LDL_ContextOpenGLLegacy:
				LDL_TextureOpenGL1Free(texture->TextureOpenGL1);
				break;
			}
		}
	}
}

LDL_Vec2i LDL_TextureGetSize(LDL_Texture* texture)
{
	if (texture)
	{
		if (texture->Context)
		{
			switch (LDL_ContextGet(texture->Context))
			{
			case LDL_ContextOpenGLLegacy:
				return LDL_TextureOpenGL1GetSize(texture->TextureOpenGL1);
			}
		}
	}

	return LDL_GetVec2i(0, 0);
}
