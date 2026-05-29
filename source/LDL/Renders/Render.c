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
#include <LDL/Render.h>
#include <LDL/Renders/Texture.h>
#include <LDL/Renders/GL1/RndrGL1.h>
#include <LDL/Renders/GL1/TexGL1.h>

typedef struct LDL_Render
{
	LDL_Result*       Result;
	LDL_Context*      Context;
	LDL_Window*       Window;
	LDL_RenderOpenGL1 RenderOpenGL1;
} LDL_Render;

LDL_Render* LDL_RenderNew(LDL_Result* result, LDL_Context* context, LDL_Window* window)
{
	if (result && context && window)
	{
		LDL_Render* render = (LDL_Render*)malloc(sizeof(LDL_Render));

		if (render)
		{
			render->Result  = result;
			render->Context = context;
			render->Window  = window;

			switch (LDL_ContextGet(render->Context))
			{
			case LDL_ContextOpenGL1:
				LDL_RenderOpenGL1Init(&render->RenderOpenGL1, result, window);
				break;
			};
			
			return render;
		}
	}

	return NULL;
}

void LDL_RenderFree(LDL_Render* render)
{
	if (render && render->Context)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1Deinit(&render->RenderOpenGL1);
			break;
		};
		
		free(render);
	}
}

LDL_Color LDL_RenderGetColor(LDL_Render* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			return LDL_RenderOpenGL1GetColor(&render->RenderOpenGL1);
		};
	}

	return LDL_ColorRgba(0, 0, 0, 0);
}

void LDL_RenderSetColor(LDL_Render* render, LDL_Color color)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1SetColor(&render->RenderOpenGL1, color);
			break;
		};
	}
}

void LDL_RenderClear(LDL_Render* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1Clear(&render->RenderOpenGL1);
			break;
		};
	}
}

void LDL_RenderLine2i(LDL_Render* render, LDL_Vec2i first, LDL_Vec2i last)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1Line2i(&render->RenderOpenGL1, first, last);
			break;
		};	
	}
}

void LDL_RenderFill2i(LDL_Render* render, LDL_Vec2i first, LDL_Vec2i last)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1Fill2i(&render->RenderOpenGL1, first, last);
			break;
		};
	}
}

void LDL_RenderBegin(LDL_Render* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1Begin(&render->RenderOpenGL1);
			break;
		};
	}
}

void LDL_RenderEnd(LDL_Render* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1End(&render->RenderOpenGL1);
			break;
		};
	}
}

void LDL_RenderDraw(LDL_Render* render, LDL_Texture* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
	if (render && texture)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_RenderOpenGL1Draw(&render->RenderOpenGL1, texture->TextureOpenGL1, dstPos, dstSize, srcPos, srcSize);
			break;
		};
	}
}
