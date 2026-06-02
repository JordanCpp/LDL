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
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/BufferGL.h>

static int CompareCommands(const void* a, const void* b)
{
    const LDL_DrawCommand* cmdA = (const LDL_DrawCommand*)a;
    const LDL_DrawCommand* cmdB = (const LDL_DrawCommand*)b;

    if (cmdA->layer != cmdB->layer)
    {
        return cmdA->layer - cmdB->layer;
    }

    return (int)(cmdA->textureId - cmdB->textureId);
}

void LDL_BufferOpenGLInit(LDL_BufferOpenGL* buffer)
{
    if (buffer)
    {
        buffer->Commands     = (LDL_DrawCommand*)malloc(sizeof(LDL_DrawCommand) * MAX_COMMANDS);
        buffer->CommandCount = 0;

        buffer->VertexBuffer = (LDL_Vertex*)malloc(sizeof(LDL_Vertex) * MAX_VERTICES);
        buffer->VertexCount  = 0;

        buffer->Batches    = (LDL_Batch*)malloc(sizeof(LDL_Batch) * MAX_BATCHES);
        buffer->BatchCount = 0;
    }
}

void LDL_BufferOpenGLDeinit(LDL_BufferOpenGL* buffer)
{
    if (buffer)
    {
        if (buffer->Commands)
        {
            free(buffer->Commands);
        }

        if (buffer->VertexBuffer)
        {
            free(buffer->VertexBuffer);
        }

        if (buffer->Batches)
        {
            free(buffer->Batches);
        }
    }
}

void LDL_BufferOpenGLClear(LDL_BufferOpenGL* buffer)
{
    if (buffer)
    {
        buffer->CommandCount = 0;
    }
}

void LDL_BufferOpenGLAddTexture(LDL_BufferOpenGL* buffer, size_t layer, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
    LDL_DrawCommand* cmd;

    if (buffer && buffer->CommandCount < MAX_COMMANDS)
    {
        cmd            = &buffer->Commands[buffer->CommandCount++];
        cmd->type      = LDL_CommandIsTexture;
        cmd->layer     = layer;
        cmd->textureId = texture->Id;
        cmd->dstPos    = dstPos  ? *dstPos  : LDL_GetVec2i(0, 0);
        cmd->dstSize   = dstSize ? *dstSize : texture->Size;
        cmd->srcPos    = srcPos  ? *srcPos  : LDL_GetVec2i(0, 0);
        cmd->srcSize   = srcSize ? *srcSize : texture->Size;
    }
}

void LDL_BufferOpenGLAddLine(LDL_BufferOpenGL* buffer, LDL_Color color, size_t layer, LDL_Vec2i first, LDL_Vec2i last)
{
}

void LDL_BufferOpenGLAddFill(LDL_BufferOpenGL* buffer, LDL_Color color, size_t layer, LDL_Vec2i first, LDL_Vec2i last)
{
}

void LDL_BufferOpenGLCalc(LDL_BufferOpenGL* buffer)
{
    size_t i;
    LDL_DrawCommand* cmd;
    LDL_Batch* batch;
    LDL_Vertex* v;
    LDL_Color c;
    LDL_GLColor cl;
    float x;
    float y;
    float w;
    float h;
    float u1;
    float v1;
    float u2;
    float v2;

    qsort(buffer->Commands, buffer->CommandCount, sizeof(LDL_DrawCommand), CompareCommands);

    buffer->VertexCount = 0;
    buffer->BatchCount  = 0;

    for (i = 0; i < buffer->CommandCount; ++i)
    {
        cmd = &buffer->Commands[i];

        if (buffer->BatchCount == 0 || cmd->layer != buffer->Batches[buffer->BatchCount - 1].layer || cmd->textureId != buffer->Batches[buffer->BatchCount - 1].textureId)
        {
            buffer->BatchCount++;
            buffer->Batches[buffer->BatchCount - 1].textureId   = cmd->textureId;
            buffer->Batches[buffer->BatchCount - 1].layer       = cmd->layer;
            buffer->Batches[buffer->BatchCount - 1].firstVertex = buffer->VertexCount;
            buffer->Batches[buffer->BatchCount - 1].vertexCount = 0;
        }

        batch = &buffer->Batches[buffer->BatchCount - 1];
        v     = &buffer->VertexBuffer[buffer->VertexCount];
        c     = cmd->color;
        cl    = LDL_GLNormalize(c);

        if (cmd->type == LDL_CommandIsTexture)
        {
            x  = (float) cmd->dstPos.x;
            y  = (float) cmd->dstPos.y;
            w  = (float) cmd->dstSize.x;
            h  = (float) cmd->dstSize.y;
            u1 = (float) cmd->srcPos.x / cmd->srcSize.x;
            v1 = (float) cmd->srcPos.y / cmd->srcSize.y;
            u2 = (float)(cmd->srcPos.x + cmd->srcSize.x) / cmd->srcSize.x;
            v2 = (float)(cmd->srcPos.y + cmd->srcSize.y) / cmd->srcSize.y;

            v[0].x = x;
            v[0].y = y;
            v[0].u = u1;
            v[0].v = v1;
            v[0].r = 1.0f;
            v[0].g = 1.0f;
            v[0].b = 1.0f;
            v[0].a = 1.0f;

            v[1].x = x + w;
            v[1].y = y;
            v[1].u = u2;
            v[1].v = v1;
            v[1].r = 1.0f;
            v[1].g = 1.0f;
            v[1].b = 1.0f;
            v[1].a = 1.0f;

            v[2].x = x + w;
            v[2].y = y + h;
            v[2].u = u2;
            v[2].v = v2;
            v[2].r = 1.0f;
            v[2].g = 1.0f;
            v[2].b = 1.0f;
            v[2].a = 1.0f;

            v[3].x = x;
            v[3].y = y;
            v[3].u = u1;
            v[3].v = v1;
            v[3].r = 1.0f;
            v[3].g = 1.0f;
            v[3].b = 1.0f;
            v[3].a = 1.0f;

            v[4].x = x + w;
            v[4].y = y + h;
            v[4].u = u2;
            v[4].v = v2;
            v[4].r = 1.0f;
            v[4].g = 1.0f;
            v[4].b = 1.0f;
            v[4].a = 1.0f;

            v[5].x = x;
            v[5].y = y + h;
            v[5].u = u1;
            v[5].v = v2;
            v[5].r = 1.0f;
            v[5].g = 1.0f;
            v[5].b = 1.0f;
            v[5].a = 1.0f;


            /*
            v[0] = (LDL_Vertex){ x,   y,   u1, v1, 1.0f, 1.0f, 1.0f, 1.0f };
            v[1] = (LDL_Vertex){ x + w, y,   u2, v1,1.0f, 1.0f, 1.0f, 1.0f };
            v[2] = (LDL_Vertex){ x + w, y + h, u2, v2, 1.0f, 1.0f, 1.0f, 1.0f };
            v[3] = (LDL_Vertex){ x,   y,   u1, v1, 1.0f, 1.0f, 1.0f, 1.0f };
            v[4] = (LDL_Vertex){ x + w, y + h, u2, v2, 1.0f, 1.0f, 1.0f, 1.0f };
            v[5] = (LDL_Vertex){ x,   y + h, u1, v2, 1.0f, 1.0f, 1.0f, 1.0f };
            */

            buffer->VertexCount += 6;
            batch->vertexCount += 6;
        }
    }
}
