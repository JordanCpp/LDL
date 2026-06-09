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
#include <LDL/Mat4f.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/Renders/GL/3DRGL1.h>

void LDL_3DRenderOpenGL1Init(LDL_3DRenderOpenGL1* render, LDL_Result* result, LDL_Window* window)
{
    float identity[16] =
    {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };

    if (render && result && window)
    {
        render->Result = result;
        render->Window = window;
        render->Loader = LDL_OpenGLLoaderNew(result, 1, 2);

        memcpy(render->World,      identity, sizeof(render->World));
        memcpy(render->View,       identity, sizeof(render->View));
        memcpy(render->Projection, identity, sizeof(render->Projection));
    }
}

void LDL_3DRenderOpenGL1Deinit(LDL_3DRenderOpenGL1* render)
{
    if (render)
    {
        if (render->Loader)
        {
            LDL_OpenGLLoaderFree(render->Loader);
        }
    }
}

void LDL_3DRenderOpenGL1Begin(LDL_3DRenderOpenGL1* render)
{
    LDL_Vec2i size;
    LDL_Mat4f modelView;
    
    size = LDL_WindowGetSize(render->Window);
    glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y);

    LDL_Mat4fMultiply(&modelView, (const LDL_Mat4f*)&render->View, (const LDL_Mat4f*)&render->World);

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(render->Projection);

    /*
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(modelView);
    */
}

void LDL_3DRenderOpenGL1End(LDL_3DRenderOpenGL1* render)
{
    if (render && render->Window)
    {
        LDL_WindowPresent(render->Window);
    }
}

void LDL_3DRenderOpenGL1VertexDraw(LDL_3DRenderOpenGL1* render, LDL_3DRenderOpenGL1VertexBuffer* vertexBuffer)
{
    size_t currentOffset = 0;

    if (vertexBuffer && vertexBuffer->Data)
    {
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        if (vertexBuffer->Format & LDL_FVF_XYZ)
        {
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(3, GL_FLOAT, (GLsizei)vertexBuffer->Size, (uint8_t*)vertexBuffer->Data + currentOffset);
            currentOffset += sizeof(float) * 3;
        }
        else if (vertexBuffer->Format & LDL_FVF_XYZW)
        {
            glEnableClientState(GL_VERTEX_ARRAY);
            glVertexPointer(4, GL_FLOAT, (GLsizei)vertexBuffer->Size, (uint8_t*)vertexBuffer->Data + currentOffset);
            currentOffset += sizeof(float) * 4;
        }

        if (vertexBuffer->Format & LDL_FVF_COLOR)
        {
            glEnableClientState(GL_COLOR_ARRAY);
            glColorPointer(3, GL_FLOAT, (GLsizei)vertexBuffer->Size, (uint8_t*)vertexBuffer->Data + currentOffset);
            currentOffset += sizeof(float) * 3;
        }

        if (vertexBuffer->Format & LDL_FVF_NORMAL)
        {
            glEnableClientState(GL_NORMAL_ARRAY);
            glNormalPointer(GL_FLOAT, (GLsizei)vertexBuffer->Size, (uint8_t*)vertexBuffer->Data + currentOffset);
            currentOffset += sizeof(float) * 3;
        }

        if (vertexBuffer->Format & LDL_FVF_TEXCOORD)
        {
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glTexCoordPointer(2, GL_FLOAT, (GLsizei)vertexBuffer->Size, (uint8_t*)vertexBuffer->Data + currentOffset);
            currentOffset += sizeof(float) * 2;
        }

        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertexBuffer->Count);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
}

LDL_3DRenderOpenGL1VertexBuffer* LDL_3DRenderOpenGL1VertexBufferNew(size_t fvf)
{
    LDL_3DRenderOpenGL1VertexBuffer* vertexBuffer = (LDL_3DRenderOpenGL1VertexBuffer*)malloc(sizeof(LDL_3DRenderOpenGL1VertexBuffer));

    if (vertexBuffer)
    {
        vertexBuffer->Format = fvf;
        vertexBuffer->Count  = 0;
        vertexBuffer->Size   = 0;
        vertexBuffer->Data   = NULL;

        return vertexBuffer;
    }

    return NULL;
}

void LDL_3DRenderOpenGL1VertexBufferFree(LDL_3DRenderOpenGL1VertexBuffer* vertexBuffer)
{
    if (vertexBuffer)
    {
        if (vertexBuffer->Data)
        {
            free(vertexBuffer->Data);
        }

        free(vertexBuffer);
    }
}

void LDL_3DRenderOpenGL1VertexBufferCopy(LDL_3DRenderOpenGL1VertexBuffer* vertexBuffer, size_t size, size_t count, void* source)
{
    if (vertexBuffer)
    {
        vertexBuffer->Count = count;
        vertexBuffer->Size  = size;
        vertexBuffer->Data  = (void*)malloc(size * count);

        if (vertexBuffer->Data)
        {
            memcpy(vertexBuffer->Data, source, size * count);
        }
    }
}

void LDL_3DRenderOpenGL1SetWorld(LDL_3DRenderOpenGL1* render, const float* matrix)
{
    if (render && matrix)
    {
        memcpy(render->World, matrix, 16 * sizeof(float));
    }
}

void LDL_3DRenderOpenGL1SetView(LDL_3DRenderOpenGL1* render, const float* matrix)
{
    if (render && matrix)
    {
        memcpy(render->View, matrix, 16 * sizeof(float));
    }
}

void LDL_3DRenderOpenGL1SetProjection(LDL_3DRenderOpenGL1* render, const float* matrix)
{
    if (render && matrix)
    {
        memcpy(render->Projection, matrix, 16 * sizeof(float));
    }
}
