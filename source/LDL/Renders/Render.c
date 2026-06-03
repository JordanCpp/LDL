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
#include <LDL/Render.h>
#include <LDL/Renders/Texture.h>
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/RndrGL1.h>
#include <LDL/Renders/GL/RndrGL2.h>
#include <LDL/Renders/GL/RndrGL3.h>

struct LDL_Render
{
	LDL_Result*       Result;
	LDL_Context*      Context;
	LDL_Window*       Window;
	LDL_RenderOpenGL1 RenderOpenGL1;
	LDL_RenderOpenGL2 RenderOpenGL2;
	LDL_RenderOpenGL3 RenderOpenGL3;
};

LDL_Render* LDL_RenderNew(LDL_Result* result, LDL_Context* context, LDL_Window* window)
{
	if (result && context && window)
	{
		LDL_Render* render = (LDL_Render*)malloc(sizeof(LDL_Render));
		if (render == NULL)
		{
			LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
			return NULL;
		}

		if (render)
		{
			render->Result  = result;
			render->Context = context;
			render->Window  = window;

			switch (LDL_ContextGet(render->Context))
			{
			case LDL_ContextOpenGLLegacy:
				LDL_RenderOpenGL1Init(&render->RenderOpenGL1, result, window);
				break;
			case LDL_ContextOpenGLHybrid:
				LDL_RenderOpenGL2Init(&render->RenderOpenGL2, result, window);
				break;
			case LDL_ContextOpenGLModern:
				LDL_RenderOpenGL3Init(&render->RenderOpenGL3, result, window);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1Deinit(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2Deinit(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3Deinit(&render->RenderOpenGL3);
			break;
		};
		
		free(render);
	}
}

size_t LDL_RenderGetLayer(LDL_Render* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			return LDL_RenderOpenGL1GetLayer(&render->RenderOpenGL1);
		case LDL_ContextOpenGLHybrid:
			return LDL_RenderOpenGL2GetLayer(&render->RenderOpenGL2);
		case LDL_ContextOpenGLModern:
			return LDL_RenderOpenGL3GetLayer(&render->RenderOpenGL3);
		};
	}

	return 0;
}

void LDL_RenderSetLayer(LDL_Render* render, size_t layer)
{
	if (render && render->Context)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1SetLayer(&render->RenderOpenGL1, layer);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2SetLayer(&render->RenderOpenGL2, layer);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3SetLayer(&render->RenderOpenGL3, layer);
			break;
		};
	}
}

LDL_Color LDL_RenderGetColor(LDL_Render* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			return LDL_RenderOpenGL1GetColor(&render->RenderOpenGL1);
		case LDL_ContextOpenGLHybrid:
			return LDL_RenderOpenGL2GetColor(&render->RenderOpenGL2);
		case LDL_ContextOpenGLModern:
			return LDL_RenderOpenGL3GetColor(&render->RenderOpenGL3);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1SetColor(&render->RenderOpenGL1, color);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2SetColor(&render->RenderOpenGL2, color);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3SetColor(&render->RenderOpenGL3, color);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1Clear(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2Clear(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3Clear(&render->RenderOpenGL3);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1Line2i(&render->RenderOpenGL1, first, last);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2Line2i(&render->RenderOpenGL2, first, last);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3Line2i(&render->RenderOpenGL3, first, last);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1Fill2i(&render->RenderOpenGL1, first, last);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2Fill2i(&render->RenderOpenGL2, first, last);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3Fill2i(&render->RenderOpenGL3, first, last);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1Begin(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2Begin(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3Begin(&render->RenderOpenGL3);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1End(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2End(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3End(&render->RenderOpenGL3);
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
		case LDL_ContextOpenGLLegacy:
			LDL_RenderOpenGL1Draw(&render->RenderOpenGL1, texture->TextureOpenGL, dstPos, dstSize, srcPos, srcSize);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_RenderOpenGL2Draw(&render->RenderOpenGL2, texture->TextureOpenGL, dstPos, dstSize, srcPos, srcSize);
			break;
		case LDL_ContextOpenGLModern:
			LDL_RenderOpenGL3Draw(&render->RenderOpenGL3, texture->TextureOpenGL, dstPos, dstSize, srcPos, srcSize);
			break;
		};
	}
}
