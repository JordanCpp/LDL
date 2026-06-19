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
#include <LDL/2DRender.h>
#include <LDL/Renders/Texture.h>
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/2DRGL1.h>
#include <LDL/Renders/GL/2DRGL2.h>
#include <LDL/Renders/GL/2DRGL3.h>
#include <LDL/Renders/Soft/RndrSoft.h>

struct LDL_2DRender
{
	LDL_ContextType      ContextType;
	LDL_Result*          Result;
	LDL_Window*          Window;
	LDL_2DRenderOpenGL1  RenderOpenGL1;
	LDL_2DRenderOpenGL2  RenderOpenGL2;
	LDL_2DRenderOpenGL3  RenderOpenGL3;
	LDL_2DRenderSoftware RenderSoftware;
};

LDL_2DRender* LDL_2DRenderCreate(LDL_Result* result, LDL_Context* context, LDL_Window* window)
{
	if (result && context && window)
	{
		LDL_2DRender* render = (LDL_2DRender*)malloc(sizeof(LDL_2DRender));
		if (render == NULL)
		{
			LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
			return NULL;
		}

		if (render)
		{
			render->Result      = result;
			render->Window      = window;
			render->ContextType = LDL_ContextGet(context);

			switch (render->ContextType)
			{
			case LDL_ContextOpenGLLegacy:
				LDL_2DRenderOpenGL1Init(&render->RenderOpenGL1, result, window);
				break;
			case LDL_ContextOpenGLHybrid:
				LDL_2DRenderOpenGL2Init(&render->RenderOpenGL2, result, window);
				break;
			case LDL_ContextOpenGLModern:
				LDL_2DRenderOpenGL3Init(&render->RenderOpenGL3, result, window);
				break;
			case LDL_ContextSoftware:
				LDL_2DRenderSoftwareInit(&render->RenderSoftware, result, window);
				break;
			};
			
			return render;
		}
	}

	return NULL;
}

void LDL_2DRenderDestroy(LDL_2DRender* render)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1Deinit(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2Deinit(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3Deinit(&render->RenderOpenGL3);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareDeinit(&render->RenderSoftware);
			break;
		};
		
		free(render);
	}
}

size_t LDL_2DRenderGetLayer(LDL_2DRender* render)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			return LDL_2DRenderOpenGL1GetLayer(&render->RenderOpenGL1);
		case LDL_ContextOpenGLHybrid:
			return LDL_2DRenderOpenGL2GetLayer(&render->RenderOpenGL2);
		case LDL_ContextOpenGLModern:
			return LDL_2DRenderOpenGL3GetLayer(&render->RenderOpenGL3);
		case LDL_ContextSoftware:
			return LDL_2DRenderSoftwareGetLayer(&render->RenderSoftware);
		};
	}

	return 0;
}

void LDL_2DRenderSetLayer(LDL_2DRender* render, size_t layer)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1SetLayer(&render->RenderOpenGL1, layer);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2SetLayer(&render->RenderOpenGL2, layer);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3SetLayer(&render->RenderOpenGL3, layer);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareSetLayer(&render->RenderSoftware, layer);
			break;
		};
	}
}

LDL_Color LDL_2DRenderGetColor(LDL_2DRender* render)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			return LDL_2DRenderOpenGL1GetColor(&render->RenderOpenGL1);
		case LDL_ContextOpenGLHybrid:
			return LDL_2DRenderOpenGL2GetColor(&render->RenderOpenGL2);
		case LDL_ContextOpenGLModern:
			return LDL_2DRenderOpenGL3GetColor(&render->RenderOpenGL3);
		case LDL_ContextSoftware:
			return LDL_2DRenderSoftwareGetColor(&render->RenderSoftware);
		};
	}

	return LDL_ColorRgba(0, 0, 0, 0);
}

void LDL_2DRenderSetColor(LDL_2DRender* render, LDL_Color color)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1SetColor(&render->RenderOpenGL1, color);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2SetColor(&render->RenderOpenGL2, color);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3SetColor(&render->RenderOpenGL3, color);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareSetColor(&render->RenderSoftware, color);
			break;
		};
	}
}

void LDL_2DRenderClear(LDL_2DRender* render)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1Clear(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2Clear(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3Clear(&render->RenderOpenGL3);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareClear(&render->RenderSoftware);
			break;
		};
	}
}

void LDL_2DRenderLine(LDL_2DRender* render, LDL_Vec2i first, LDL_Vec2i last)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1Line2i(&render->RenderOpenGL1, first, last);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2Line2i(&render->RenderOpenGL2, first, last);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3Line2i(&render->RenderOpenGL3, first, last);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareLine2i(&render->RenderSoftware, first, last);
			break;
		};	
	}
}

void LDL_2DRenderFill(LDL_2DRender* render, LDL_Vec2i first, LDL_Vec2i last)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1Fill2i(&render->RenderOpenGL1, first, last);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2Fill2i(&render->RenderOpenGL2, first, last);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3Fill2i(&render->RenderOpenGL3, first, last);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareFill2i(&render->RenderSoftware, first, last);
			break;
		};
	}
}

void LDL_2DRenderBegin(LDL_2DRender* render)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1Begin(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2Begin(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3Begin(&render->RenderOpenGL3);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareBegin(&render->RenderSoftware);
			break;
		};
	}
}

void LDL_2DRenderEnd(LDL_2DRender* render)
{
	if (render)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1End(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2End(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3End(&render->RenderOpenGL3);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareEnd(&render->RenderSoftware);
			break;
		};
	}
}

void LDL_2DRenderDraw(LDL_2DRender* render, LDL_Texture* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
	if (render && texture)
	{
		switch (render->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
			LDL_2DRenderOpenGL1Draw(&render->RenderOpenGL1, texture->TextureOpenGL, dstPos, dstSize, srcPos, srcSize);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_2DRenderOpenGL2Draw(&render->RenderOpenGL2, texture->TextureOpenGL, dstPos, dstSize, srcPos, srcSize);
			break;
		case LDL_ContextOpenGLModern:
			LDL_2DRenderOpenGL3Draw(&render->RenderOpenGL3, texture->TextureOpenGL, dstPos, dstSize, srcPos, srcSize);
			break;
		case LDL_ContextSoftware:
			LDL_2DRenderSoftwareDraw(&render->RenderSoftware, texture->TextureSoftware->Surface, dstPos, dstSize, srcPos, srcSize);
			break;
		};
	}
}
