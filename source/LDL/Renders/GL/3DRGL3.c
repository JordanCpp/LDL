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
#include <LDL/OpenGL/GL3_0.h>
#include <LDL/Renders/GL/3DRGL3.h>

static GLuint CompileShader(const char* vSource, const char* fSource) 
{
    GLuint vertex, fragment, program;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vSource, NULL);
    glCompileShader(vertex);

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fSource, NULL);
    glCompileShader(fragment);

    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return program;
}

const char* vShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec3 aNormal;\n"
"layout (location = 3) in vec2 aTexCoord;\n"
"uniform mat4 uProj; uniform mat4 uView;\n"
"out vec3 vColor;\n"
"void main() {\n"
"   gl_Position = uProj * uView * vec4(aPos, 1.0);\n"
"   vColor = aColor;\n"
"}\n";

const char* fShaderSrc =
"#version 330 core\n"
"in vec3 vColor;\n"
"out vec4 FragColor;\n"
"void main() { FragColor = vec4(vCR, 1.0); }\n";

void LDL_3DRenderOpenGL3Init(LDL_3DRenderOpenGL3* render, LDL_Result* result, LDL_Window* window)
{
    if (render && result && window)
    {
        render->Result = result;
        render->Window = window;
        render->Loader = LDL_OpenGLLoaderNew(result, 3, 3);
        render->Shader.ID = CompileShader(vShaderSrc, fShaderSrc);
    }
}

void LDL_3DRenderOpenGL3Deinit(LDL_3DRenderOpenGL3* render)
{
    if (render)
    {
        if (render->Loader)
        {
            LDL_OpenGLLoaderFree(render->Loader);
        }
    }
}

void LDL_3DRenderOpenGL3Begin(LDL_3DRenderOpenGL3* render)
{
    glUseProgram(render->Shader.ID);
}

void LDL_3DRenderOpenGL3End(LDL_3DRenderOpenGL3* render)
{
    if (render && render->Window)
    {
        LDL_WindowPresent(render->Window);
    }
}

void LDL_3DRenderOpenGL3VertexDraw(LDL_3DRenderOpenGL3* render, LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer)
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

LDL_3DRenderOpenGL3VertexBuffer* LDL_3DRenderOpenGL3VertexBufferNew(size_t fvf)
{
    LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer = (LDL_3DRenderOpenGL3VertexBuffer*)malloc(sizeof(LDL_3DRenderOpenGL3VertexBuffer));

    if (vertexBuffer)
    {
        vertexBuffer->Format = fvf;
        vertexBuffer->Count = 0;
        vertexBuffer->Size = 0;
        vertexBuffer->Data = NULL;

        return vertexBuffer;
    }

    return NULL;
}

void LDL_3DRenderOpenGL3VertexBufferFree(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer)
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

void LDL_3DRenderOpenGL3VertexBufferCopy(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer, size_t size, size_t count, void* source)
{
    if (vertexBuffer)
    {
        vertexBuffer->Count = count;
        vertexBuffer->Size = size;
        vertexBuffer->Data = (void*)malloc(size * count);

        if (vertexBuffer->Data)
        {
            memcpy(vertexBuffer->Data, source, size * count);
        }
    }
}
