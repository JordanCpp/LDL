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

#include <LDL/OpenGL/GL1_2.h>
#include <LDL/Renders/GL1/TexGL1.h>
#include <LDL/Renders/GL1/RndrGL1.h>
#include <LDL/Renders/GL/GLUtils.h>

void LDL_RenderOpenGL1Init(LDL_RenderOpenGL1* render, LDL_Result* result, LDL_Window* window)
{
	if (render)
	{
		render->Result = result;
		render->Window = window;

		LDL_Mat4fIdentity(&render->Projection);
		LDL_Mat4fIdentity(&render->ModelView);

		render->Loader = LDL_OpenGLLoaderNew(result, 1, 2);
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void LDL_RenderOpenGL1Deinit(LDL_RenderOpenGL1* render)
{
	if (render)
	{
		if (render->Loader)
		{
			LDL_OpenGLLoaderFree(render->Loader);
		}
	}
}

LDL_Color LDL_RenderOpenGL1GetColor(LDL_RenderOpenGL1* render)
{
	return LDL_BaseRenderGetColor(&render->BaseRender);
}

void LDL_RenderOpenGL1SetColor(LDL_RenderOpenGL1* render, LDL_Color color)
{
	LDL_BaseRenderSetColor(&render->BaseRender, color);
}

void LDL_RenderOpenGL1Clear(LDL_RenderOpenGL1* render)
{
	LDL_Color   srcColor = LDL_RenderOpenGL1GetColor(render);
	LDL_GLColor dstColor = LDL_GLNormalize(srcColor);

	glClearColor(dstColor.r, dstColor.g, dstColor.b, dstColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LDL_RenderOpenGL1Line2i(LDL_RenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last)
{
	if (render && render->Window)
	{
		LDL_Color   srcColor = LDL_RenderOpenGL1GetColor(render);
		LDL_GLColor dstColor = LDL_GLNormalize(srcColor);

		glBegin(GL_LINES);
		glColor4f(dstColor.r, dstColor.g, dstColor.b, dstColor.a);
		glVertex2i(first.x, first.y);
		glVertex2i(last.x, last.y);
		glEnd();
	}
}

void LDL_RenderOpenGL1Fill2i(LDL_RenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last)
{
	if (render && render->Window)
	{
		LDL_Color   srcColor = LDL_RenderOpenGL1GetColor(render);
		LDL_GLColor dstColor = LDL_GLNormalize(srcColor);

		float x1 = (float)first.x;
		float y1 = (float)first.y;
		float x2 = (float)last.x;
		float y2 = (float)last.y;

		glBegin(GL_TRIANGLE_FAN);
		glColor4f(dstColor.r, dstColor.g, dstColor.b, dstColor.a);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
		glEnd();
	}
}

void LDL_RenderOpenGL1Begin(LDL_RenderOpenGL1* render)
{
	if (render && render->Window)
	{
		LDL_Vec2i size = LDL_WindowGetSize(render->Window);

		glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y);

		LDL_Mat4fOrtho(&render->Projection, 0.0f, (float)size.x, (float)size.y, 0.0f, 0.0f, 1.0f);

		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(LDL_Mat4fGetValues(&render->Projection));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(LDL_Mat4fGetValues(&render->ModelView));
	}
}

void LDL_RenderOpenGL1End(LDL_RenderOpenGL1* render)
{
	if (render && render->Window)
	{
		LDL_WindowPresent(render->Window);
	}
}

void LDL_RenderOpenGL1Draw(LDL_RenderOpenGL1* render, LDL_TextureOpenGL1* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
	LDL_Vec2i dPos;
	LDL_Vec2i dSize;
	LDL_Vec2i sPos;
	LDL_Vec2i sSize;

	if (render && texture)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture->Id);

		 dPos  = dstPos  ? *dstPos  : LDL_GetVec2i(0, 0);
		 dSize = dstSize ? *dstSize : texture->Size;
		 sPos  = srcPos  ? *srcPos  : LDL_GetVec2i(0, 0);
		 sSize = srcSize ? *srcSize : texture->Size;

		DrawQuad(dPos, dSize, sPos, sSize, texture->Quad.x);

		glDisable(GL_TEXTURE_2D);
	}
}
