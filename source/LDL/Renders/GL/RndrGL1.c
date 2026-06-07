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
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/RndrGL1.h>
#include <LDL/Renders/GL/GLUtils.h>

void LDL_RenderOpenGL1Init(LDL_RenderOpenGL1* render, LDL_Result* result, LDL_Window* window)
{
    if (render)
    {
        render->Result = result;
        render->Window = window;

        LDL_BaseRenderInit(&render->BaseRender, LDL_ColorRgb(0, 0, 0));
        LDL_BufferOpenGLInit(&render->Buffer, render->Result);

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
        LDL_BufferOpenGLDeinit(&render->Buffer);

        if (render->Loader)
        {
            LDL_OpenGLLoaderFree(render->Loader);
        }
    }
}

size_t LDL_RenderOpenGL1GetLayer(LDL_RenderOpenGL1* render)
{
    if (render)
    {
        return LDL_BaseRenderGetLayer(&render->BaseRender);
    }

    return 0;
}

void LDL_RenderOpenGL1SetLayer(LDL_RenderOpenGL1* render, size_t layer)
{
    if (render)
    {
        LDL_BaseRenderSetLayer(&render->BaseRender, layer);
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

void LDL_RenderOpenGL1Begin(LDL_RenderOpenGL1* render)
{
    LDL_Vec2i size;

    if (render && render->Window)
    {
        LDL_BufferOpenGLClear(&render->Buffer);

        size = LDL_WindowGetSize(render->Window);
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
    size_t i;
    LDL_Batch* batch;

    if (render)
    {
        LDL_BufferOpenGLCalc(&render->Buffer);

        if (render->Buffer.BatchCount > 0)
        {
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glEnableClientState(GL_COLOR_ARRAY);

            for (i = 0; i < render->Buffer.BatchCount; ++i)
            {
                batch = &render->Buffer.Batches[i];

                if (batch->TextureId != 0)
                {
                    glBindTexture(GL_TEXTURE_2D, batch->TextureId);
                    glEnable(GL_TEXTURE_2D);
                }
                else
                {
                    glDisable(GL_TEXTURE_2D);
                }

                glVertexPointer  (2, GL_FLOAT, sizeof(LDL_Vertex), &render->Buffer.VertexBuffer[batch->FirstVertex].x);
                glTexCoordPointer(2, GL_FLOAT, sizeof(LDL_Vertex), &render->Buffer.VertexBuffer[batch->FirstVertex].u);
                glColorPointer   (4, GL_FLOAT, sizeof(LDL_Vertex), &render->Buffer.VertexBuffer[batch->FirstVertex].r);

                glDrawArrays(GL_TRIANGLES, 0, (GLsizei)batch->VertexCount);
            }

            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glEnableClientState(GL_TEXTURE_2D);
        }

        if (render->Window)
        {
            LDL_WindowPresent(render->Window);
        }
    }
}

void LDL_RenderOpenGL1Draw(LDL_RenderOpenGL1* render, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
    if (render)
    {
        LDL_BufferOpenGLAddTexture(&render->Buffer, LDL_RenderOpenGL1GetLayer(render), texture, dstPos, dstSize, srcPos, srcSize, texture->Quad);
    }
}

void LDL_RenderOpenGL1Line2i(LDL_RenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last)
{
    if (render)
    {
        LDL_BufferOpenGLAddLine(&render->Buffer, LDL_RenderOpenGL1GetColor(render), LDL_RenderOpenGL1GetLayer(render), first, last);
    }
}

void LDL_RenderOpenGL1Fill2i(LDL_RenderOpenGL1* render, LDL_Vec2i first, LDL_Vec2i last)
{
    if (render)
    {
        LDL_BufferOpenGLAddFill(&render->Buffer, LDL_RenderOpenGL1GetColor(render), LDL_RenderOpenGL1GetLayer(render), first, last);
    }
}
