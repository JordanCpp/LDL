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

#ifndef LDL_Renders_GL_BufferGL_H
#define LDL_Renders_GL_BufferGL_H

#include <LDL/Vec2i.h>
#include <LDL/Color.h>
#include <LDL/OpenGL/GLTypes.h>
#include <LDL/Renders/GL/GLUtils.h>

enum
{
    MAX_COMMANDS = 10000,
    MAX_VERTICES = 60000,
    MAX_BATCHES  = 1024
};

typedef struct LDL_Vertex
{
    float x;
    float y;
    float u;
    float v;
    float r;
    float g;
    float b;
    float a;
} LDL_Vertex;

typedef enum LDL_CommandType
{
    LDL_CommandIsTexture,
    LDL_CommandIsLine,
    LDL_CommandIsFill
} LDL_CommandType;

typedef struct LDL_DrawCommand
{
    LDL_CommandType type;
    size_t          layer;
    GLuint          textureId;
    LDL_Color       color;
    LDL_Vec2i       dstPos;
    LDL_Vec2i       dstSize;
    LDL_Vec2i       srcPos;
    LDL_Vec2i       srcSize;
    LDL_Vec2i       p1;
    LDL_Vec2i       p2;
} LDL_DrawCommand;

typedef struct LDL_Batch
{
    GLuint textureId;
    size_t layer;
    size_t firstVertex;
    size_t vertexCount;
} LDL_Batch;

typedef struct LDL_TextureOpenGL LDL_TextureOpenGL;

typedef struct LDL_BufferOpenGL
{
    LDL_DrawCommand*  Commands;
    size_t            CommandCount;
    LDL_Vertex*       VertexBuffer;
    size_t            VertexCount;
    LDL_Batch*        Batches;
    size_t            BatchCount;
} LDL_BufferOpenGL;

void LDL_BufferOpenGLInit(LDL_BufferOpenGL* buffer);
void LDL_BufferOpenGLDeinit(LDL_BufferOpenGL* buffer);
void LDL_BufferOpenGLClear(LDL_BufferOpenGL* buffer);
void LDL_BufferOpenGLAddTexture(LDL_BufferOpenGL* buffer, size_t layer, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);
void LDL_BufferOpenGLAddLine(LDL_BufferOpenGL* buffer, LDL_Color color, size_t layer, LDL_Vec2i first, LDL_Vec2i last);
void LDL_BufferOpenGLAddFill(LDL_BufferOpenGL* buffer, LDL_Color color, size_t layer, LDL_Vec2i first, LDL_Vec2i last);
void LDL_BufferOpenGLCalc(LDL_BufferOpenGL* buffer);

#endif
