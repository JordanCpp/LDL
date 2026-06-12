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
#include <LDL/3DRender.h>
#include <LDL/Renders/GL/3DRGL1.h>
#include <LDL/Renders/GL/3DRGL2.h>
#include <LDL/Renders/GL/3DRGL3.h>
#include <LDL/Renders/Texture.h>

struct LDL_VertexBuffer
{
	LDL_Context*                     Context;
	LDL_3DRenderOpenGL1VertexBuffer* OpenGL1VertexBuffer;
	LDL_3DRenderOpenGL2VertexBuffer* OpenGL2VertexBuffer;
	LDL_3DRenderOpenGL3VertexBuffer* OpenGL3VertexBuffer;
};

struct LDL_3DRender
{
	LDL_Result*         Result;
	LDL_Context*        Context;
	LDL_Window*         Window;
	LDL_3DRenderOpenGL1 RenderOpenGL1;
	LDL_3DRenderOpenGL2 RenderOpenGL2;
	LDL_3DRenderOpenGL3 RenderOpenGL3;
};

LDL_3DRender* LDL_3DRenderCreate(LDL_Result* result, LDL_Context* context, LDL_Window* window)
{
	if (result && context && window)
	{
		LDL_3DRender* render = (LDL_3DRender*)malloc(sizeof(LDL_3DRender));

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
				LDL_3DRenderOpenGL1Init(&render->RenderOpenGL1, result, window);
				break;
			case LDL_ContextOpenGLHybrid:
				LDL_3DRenderOpenGL2Init(&render->RenderOpenGL2, result, window);
				break;
			case LDL_ContextOpenGLModern:
				LDL_3DRenderOpenGL3Init(&render->RenderOpenGL3, result, window);
				break;
			};

			return render;
		}
	}

	return NULL;
}

void LDL_3DRenderDestroy(LDL_3DRender* render)
{
	if (render && render->Context)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1Deinit(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2Deinit(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3Deinit(&render->RenderOpenGL3);
			break;
		};

		free(render);
	}
}

void LDL_3DRenderBegin(LDL_3DRender* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1Begin(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2Begin(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3Begin(&render->RenderOpenGL3);
			break;
		};
	}
}

void LDL_3DRenderEnd(LDL_3DRender* render)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1End(&render->RenderOpenGL1);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2End(&render->RenderOpenGL2);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3End(&render->RenderOpenGL3);
			break;
		};
	}
}

void LDL_3DRenderClear(LDL_3DRender* render, float r, float g, float b)
{
	if (render)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1Clear(&render->RenderOpenGL1, r, g, b);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2Clear(&render->RenderOpenGL2, r, g, b);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3Clear(&render->RenderOpenGL3, r, g, b);
			break;
		};
	}
}

void LDL_3DRenderDraw(LDL_3DRender* render, LDL_VertexBuffer* vertexBuffer)
{
	if (render && vertexBuffer)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1VertexDraw(&render->RenderOpenGL1, vertexBuffer->OpenGL1VertexBuffer);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2VertexDraw(&render->RenderOpenGL2, vertexBuffer->OpenGL2VertexBuffer);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3VertexDraw(&render->RenderOpenGL3, vertexBuffer->OpenGL3VertexBuffer);
			break;
		};
	}
}

void LDL_3DRenderBindTexture(LDL_3DRender* render, LDL_Texture* texture)
{
	if (render && texture)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1BindTexture(&render->RenderOpenGL1, texture->TextureOpenGL);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2BindTexture(&render->RenderOpenGL2, texture->TextureOpenGL);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3BindTexture(&render->RenderOpenGL3, texture->TextureOpenGL);
			break;
		};
	}
}

LDL_VertexBuffer* LDL_VertexBufferNew(LDL_Context* context, size_t fvf)
{
	LDL_VertexBuffer* vertexBuffer = (LDL_VertexBuffer*)malloc(sizeof(LDL_VertexBuffer*));

	if (vertexBuffer && context)
	{
		vertexBuffer->Context = context;

		switch (LDL_ContextGet(context))
		{
		case LDL_ContextOpenGLLegacy:
			vertexBuffer->OpenGL1VertexBuffer = LDL_3DRenderOpenGL1VertexBufferNew(fvf);
			return vertexBuffer;
		case LDL_ContextOpenGLHybrid:
			vertexBuffer->OpenGL2VertexBuffer = LDL_3DRenderOpenGL2VertexBufferNew(fvf);
			return vertexBuffer;
		case LDL_ContextOpenGLModern:
			vertexBuffer->OpenGL3VertexBuffer = LDL_3DRenderOpenGL3VertexBufferNew(fvf);
			return vertexBuffer;
		};
	}

	return NULL;
}

void LDL_VertexBufferFree(LDL_VertexBuffer* vertexBuffer)
{
	if (vertexBuffer && vertexBuffer->Context)
	{
		switch (LDL_ContextGet(vertexBuffer->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1VertexBufferFree(vertexBuffer->OpenGL1VertexBuffer);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2VertexBufferFree(vertexBuffer->OpenGL2VertexBuffer);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3VertexBufferFree(vertexBuffer->OpenGL3VertexBuffer);
			break;
		};

		free(vertexBuffer);
	}
}

void LDL_VertexBufferCopy(LDL_VertexBuffer* vertexBuffer, size_t size, size_t count, void* source)
{
	if (vertexBuffer)
	{
		switch (LDL_ContextGet(vertexBuffer->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1VertexBufferCopy(vertexBuffer->OpenGL1VertexBuffer, size, count, source);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2VertexBufferCopy(vertexBuffer->OpenGL2VertexBuffer, size, count, source);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3VertexBufferCopy(vertexBuffer->OpenGL3VertexBuffer, size, count, source);
			break;
		};
	}
}

void LDL_3DRenderSetWorld(LDL_3DRender* render, const float* matrix)
{
	if (render && matrix)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1SetWorld(&render->RenderOpenGL1, matrix);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2SetWorld(&render->RenderOpenGL2, matrix);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3SetWorld(&render->RenderOpenGL3, matrix);
			break;
		};
	}
}

void LDL_3DRenderSetView(LDL_3DRender* render, const float* matrix)
{
	if (render && matrix)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1SetView(&render->RenderOpenGL1, matrix);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2SetView(&render->RenderOpenGL2, matrix);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3SetView(&render->RenderOpenGL3, matrix);
			break;
		};
	}
}

void LDL_3DRenderSetProjection(LDL_3DRender* render, const float* matrix)
{
	if (render && matrix)
	{
		switch (LDL_ContextGet(render->Context))
		{
		case LDL_ContextOpenGLLegacy:
			LDL_3DRenderOpenGL1SetProjection(&render->RenderOpenGL1, matrix);
			break;
		case LDL_ContextOpenGLHybrid:
			LDL_3DRenderOpenGL2SetProjection(&render->RenderOpenGL2, matrix);
			break;
		case LDL_ContextOpenGLModern:
			LDL_3DRenderOpenGL3SetProjection(&render->RenderOpenGL3, matrix);
			break;
		};
	}
}
