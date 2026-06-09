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

#include <math.h>
#include <stdlib.h>
#include <LDL/ErrorMsg.h>
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/BufferGL.h>

static int CompareCommands(const void* a, const void* b) 
{
    const LDL_DrawCommand* cmdA = (const LDL_DrawCommand*)a;
    const LDL_DrawCommand* cmdB = (const LDL_DrawCommand*)b;

    if (cmdA->Layer < cmdB->Layer)
    {
        return -1;
    }
     
    if (cmdA->Layer > cmdB->Layer)
    {
        return 1;
    }

    if (cmdA->TextureId < cmdB->TextureId)
    {
        return -1;
    }
     
    if (cmdA->TextureId > cmdB->TextureId)
    {
        return 1;
    }

    return 0;
}

void LDL_BufferOpenGLInit(LDL_BufferOpenGL* buffer, LDL_Result* result)
{
    if (buffer)
    {
        buffer->Result = result;

        buffer->Commands = (LDL_DrawCommand*)malloc(sizeof(LDL_DrawCommand) * LDL_DrawCommandMax);
        if (buffer->Commands == NULL)
        {
            LDL_BufferOpenGLDeinit(buffer);
            LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
            return;
        }

        buffer->VertexBuffer = (LDL_Vertex*)malloc(sizeof(LDL_Vertex) * LDL_VerticesMax);
        if (buffer->VertexBuffer == NULL)
        {
            LDL_BufferOpenGLDeinit(buffer);
            LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
            return;
        }

        buffer->Batches = (LDL_Batch*)malloc(sizeof(LDL_Batch) * LDL_BatchesMax);
        if (buffer->Batches == NULL)
        {
            LDL_BufferOpenGLDeinit(buffer);
            LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
            return;
        }

        buffer->CommandCount = 0;
        buffer->VertexCount = 0;
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

void LDL_BufferOpenGLAddTexture(LDL_BufferOpenGL* buffer, size_t layer, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize, LDL_Vec2i quadSize)
{
    LDL_DrawCommand* cmd;

    if (buffer && buffer->CommandCount < LDL_DrawCommandMax)
    {
        cmd            = &buffer->Commands[buffer->CommandCount++];
        cmd->Type      = LDL_CommandIsTexture;
        cmd->Layer     = layer;
        cmd->TextureId = texture->Id;
        cmd->DstPos    = dstPos  ? *dstPos  : LDL_GetVec2i(0, 0);
        cmd->DstSize   = dstSize ? *dstSize : texture->Size;
        cmd->SrcPos    = srcPos  ? *srcPos  : LDL_GetVec2i(0, 0);
        cmd->SrcSize   = srcSize ? *srcSize : texture->Size;
        cmd->QuadSize  = quadSize;
    }
}

void LDL_BufferOpenGLAddLine(LDL_BufferOpenGL* buffer, LDL_Color color, size_t layer, LDL_Vec2i first, LDL_Vec2i last)
{
    LDL_DrawCommand* cmd;

    if (buffer && buffer->CommandCount < LDL_DrawCommandMax)
    {
        cmd            = &buffer->Commands[buffer->CommandCount++];
        cmd->Type      = LDL_CommandIsLine;
        cmd->Color     = color;
        cmd->Layer     = layer;
        cmd->TextureId = 0;
        cmd->DstPos    = first;
        cmd->DstSize   = last;
    }
}

void LDL_BufferOpenGLAddFill(LDL_BufferOpenGL* buffer, LDL_Color color, size_t layer, LDL_Vec2i first, LDL_Vec2i last)
{
    LDL_DrawCommand* cmd;

    if (buffer && buffer->CommandCount < LDL_DrawCommandMax)
    {
        cmd            = &buffer->Commands[buffer->CommandCount++];
        cmd->Type      = LDL_CommandIsFill;
        cmd->Color     = color;
        cmd->Layer     = layer;
        cmd->TextureId = 0;
        cmd->DstPos    = first;
        cmd->DstSize   = last;
    }
}

void LDL_BufferOpenGLCalc(LDL_BufferOpenGL* buffer)
{
    size_t i;
    float  x;
    float  y;
    float  w;
    float  h;
    float  u1;
    float  v1;
    float  u2;
    float  v2;
    LDL_Batch*       batch;
    LDL_Vertex*      vertex;
    LDL_GLColor      color;
    LDL_DrawCommand* command;
    float  dx, dy, nx, ny, len;

    qsort(buffer->Commands, buffer->CommandCount, sizeof(LDL_DrawCommand), CompareCommands);

    buffer->VertexCount = 0;
    buffer->BatchCount  = 0;

    for (i = 0; i < buffer->CommandCount; ++i)
    {
        command = &buffer->Commands[i];

        if (buffer->BatchCount == 0 
            || command->Layer != buffer->Batches[buffer->BatchCount - 1].Layer 
            || command->TextureId != buffer->Batches[buffer->BatchCount - 1].TextureId)
        {
            buffer->BatchCount++;
            buffer->Batches[buffer->BatchCount - 1].TextureId   = command->TextureId;
            buffer->Batches[buffer->BatchCount - 1].Layer       = command->Layer;
            buffer->Batches[buffer->BatchCount - 1].FirstVertex = buffer->VertexCount;
            buffer->Batches[buffer->BatchCount - 1].VertexCount = 0;
        }

        batch  = &buffer->Batches[buffer->BatchCount - 1];
        vertex = &buffer->VertexBuffer[buffer->VertexCount];
        color  = LDL_GLNormalize(command->Color);

        switch (command->Type)
        {
        case LDL_CommandIsFill:
            x = (float)command->DstPos.x;
            y = (float)command->DstPos.y;
            w = (float)command->DstSize.x;
            h = (float)command->DstSize.y;

            vertex[0].x = x;      
            vertex[0].y = y;      
            vertex[0].u = 0; 
            vertex[0].v = 0;

            vertex[1].x = x + w;  
            vertex[1].y = y;      
            vertex[1].u = 1; 
            vertex[1].v = 0;

            vertex[2].x = x + w;  
            vertex[2].y = y + h;  
            vertex[2].u = 1; 
            vertex[2].v = 1;

            vertex[3].x = x;      
            vertex[3].y = y;      
            vertex[3].u = 0; 
            vertex[3].v = 0;

            vertex[4].x = x + w;  
            vertex[4].y = y + h;  
            vertex[4].u = 1; 
            vertex[4].v = 1;

            vertex[5].x = x;      
            vertex[5].y = y + h;  
            vertex[5].u = 0; 
            vertex[5].v = 1;

            vertex[0].r = color.r;
            vertex[0].g = color.g;
            vertex[0].b = color.b;
            vertex[0].a = color.a;
            vertex[0].u = 0;
            vertex[0].v = 0;

            vertex[1].r = color.r;
            vertex[1].g = color.g;
            vertex[1].b = color.b;
            vertex[1].a = color.a;
            vertex[1].u = 0;
            vertex[1].v = 0;

            vertex[2].r = color.r;
            vertex[2].g = color.g;
            vertex[2].b = color.b;
            vertex[2].a = color.a;
            vertex[2].u = 0;
            vertex[2].v = 0;

            vertex[3].r = color.r;
            vertex[3].g = color.g;
            vertex[3].b = color.b;
            vertex[3].a = color.a;
            vertex[3].u = 0;
            vertex[3].v = 0;

            vertex[4].r = color.r;
            vertex[4].g = color.g;
            vertex[4].b = color.b;
            vertex[4].a = color.a;
            vertex[4].u = 0;
            vertex[4].v = 0;

            vertex[5].r = color.r;
            vertex[5].g = color.g;
            vertex[5].b = color.b;
            vertex[5].a = color.a;
            vertex[5].u = 0;
            vertex[5].v = 0;

            buffer->VertexCount += 6;
            batch->VertexCount += 6;
            break;

        case LDL_CommandIsLine:
            x = (float)command->DstPos.x;
            y = (float)command->DstPos.y;
            dx = (float)command->DstSize.x - x;
            dy = (float)command->DstSize.y - y;

            nx = -dy;
            ny = dx;
            len = (float)sqrt(nx * nx + ny * ny);
            if (len > 0.0f) 
            { 
                nx /= len; 
                ny /= len; 
            }

            nx *= 0.5f;
            ny *= 0.5f;

            vertex[0].x = x + nx; 
            vertex[0].y = y + ny;
            vertex[1].x = (x + dx) + nx; 
            vertex[1].y = (y + dy) + ny;
            vertex[2].x = (x + dx) - nx; 
            vertex[2].y = (y + dy) - ny;
            vertex[3].x = x + nx; 
            vertex[3].y = y + ny;
            vertex[4].x = (x + dx) - nx; 
            vertex[4].y = (y + dy) - ny;
            vertex[5].x = x - nx; 
            vertex[5].y = y - ny;

            vertex[0].r = color.r;
            vertex[0].g = color.g;
            vertex[0].b = color.b;
            vertex[0].a = color.a;
            vertex[0].u = 0;
            vertex[0].v = 0;

            vertex[1].r = color.r;
            vertex[1].g = color.g;
            vertex[1].b = color.b;
            vertex[1].a = color.a;
            vertex[1].u = 0;
            vertex[1].v = 0;

            vertex[2].r = color.r;
            vertex[2].g = color.g;
            vertex[2].b = color.b;
            vertex[2].a = color.a;
            vertex[2].u = 0;
            vertex[2].v = 0;

            vertex[3].r = color.r;
            vertex[3].g = color.g;
            vertex[3].b = color.b;
            vertex[3].a = color.a;
            vertex[3].u = 0;
            vertex[3].v = 0;

            vertex[4].r = color.r;
            vertex[4].g = color.g;
            vertex[4].b = color.b;
            vertex[4].a = color.a;
            vertex[4].u = 0;
            vertex[4].v = 0;

            vertex[5].r = color.r;
            vertex[5].g = color.g;
            vertex[5].b = color.b;
            vertex[5].a = color.a;
            vertex[5].u = 0;
            vertex[5].v = 0;

            buffer->VertexCount += 6;
            batch->VertexCount += 6;
            break;

        case LDL_CommandIsTexture:
            x  = (float)command->DstPos.x;
            y  = (float)command->DstPos.y;
            w  = (float)command->DstSize.x;
            h  = (float)command->DstSize.y;
            u1 = (float)command->SrcPos.x / (float)command->QuadSize.x;
            v1 = (float)command->SrcPos.y / (float)command->QuadSize.y;
            u2 = ((float)command->SrcPos.x + (float)command->SrcSize.x) / (float)command->QuadSize.x;
            v2 = ((float)command->SrcPos.y + (float)command->SrcSize.y) / (float)command->QuadSize.y;

            vertex[0].x = x;
            vertex[0].y = y;
            vertex[0].u = u1;
            vertex[0].v = v1;
            vertex[0].r = 1.0f;
            vertex[0].g = 1.0f;
            vertex[0].b = 1.0f;
            vertex[0].a = 1.0f;

            vertex[1].x = x + w;
            vertex[1].y = y;
            vertex[1].u = u2;
            vertex[1].v = v1;
            vertex[1].r = 1.0f;
            vertex[1].g = 1.0f;
            vertex[1].b = 1.0f;
            vertex[1].a = 1.0f;

            vertex[2].x = x + w;
            vertex[2].y = y + h;
            vertex[2].u = u2;
            vertex[2].v = v2;
            vertex[2].r = 1.0f;
            vertex[2].g = 1.0f;
            vertex[2].b = 1.0f;
            vertex[2].a = 1.0f;

            vertex[3].x = x;
            vertex[3].y = y;
            vertex[3].u = u1;
            vertex[3].v = v1;
            vertex[3].r = 1.0f;
            vertex[3].g = 1.0f;
            vertex[3].b = 1.0f;
            vertex[3].a = 1.0f;

            vertex[4].x = x + w;
            vertex[4].y = y + h;
            vertex[4].u = u2;
            vertex[4].v = v2;
            vertex[4].r = 1.0f;
            vertex[4].g = 1.0f;
            vertex[4].b = 1.0f;
            vertex[4].a = 1.0f;

            vertex[5].x = x;
            vertex[5].y = y + h;
            vertex[5].u = u1;
            vertex[5].v = v2;
            vertex[5].r = 1.0f;
            vertex[5].g = 1.0f;
            vertex[5].b = 1.0f;
            vertex[5].a = 1.0f;

            buffer->VertexCount += 6;
            batch->VertexCount  += 6;
            break;
        }
    }
}
