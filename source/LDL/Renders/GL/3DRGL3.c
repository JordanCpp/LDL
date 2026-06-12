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
    GLuint vertex;
    GLuint fragment;
    GLuint program;

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
"uniform mat4 uProj; uniform mat4 uView; uniform mat4 uWorld;\n"
"out vec3 vColor;\n"
"out vec2 vTexCoord;\n"
"void main() {\n"
"   gl_Position = uProj * uView * uWorld * vec4(aPos, 1.0);\n"
"   vColor = aColor;\n"
"   vTexCoord = aTexCoord;\n"
"}\n";

const char* fShaderSrc =
"#version 330 core\n"
"in vec3 vColor;\n"
"in vec2 vTexCoord;\n"
"uniform sampler2D uTexture;\n"
"uniform bool uHasTexture;\n"
"out vec4 FragColor;\n"
"void main() {\n"
"   vec4 texColor = uHasTexture ? texture(uTexture, vTexCoord) : vec4(1.0);\n"
"   FragColor = vec4(vColor, 1.0) * texColor;\n"
"}\n";

void LDL_3DRenderOpenGL3Init(LDL_3DRenderOpenGL3* render, LDL_Result* result, LDL_Window* window)
{
    if (render && result && window)
    {
        render->Result    = result;
        render->Window    = window;
        render->Loader    = LDL_OpenGLLoaderNew(result, 3, 0);
        render->Shader.ID = CompileShader(vShaderSrc, fShaderSrc);

        render->Shader.uProjLoc    = glGetUniformLocation(render->Shader.ID, "uProj");
        render->Shader.uViewLoc    = glGetUniformLocation(render->Shader.ID, "uView");
        render->Shader.uWorldLoc   = glGetUniformLocation(render->Shader.ID, "uWorld");
        render->Shader.uTextureLoc = glGetUniformLocation(render->Shader.ID, "uTexture");
    }
}

void LDL_3DRenderOpenGL3Deinit(LDL_3DRenderOpenGL3* render)
{
    if (render)
    {
        if (render->Shader.ID > 0) 
        {
            glDeleteProgram(render->Shader.ID);
        }

        if (render->Loader)
        {
            LDL_OpenGLLoaderFree(render->Loader);
        }
    }
}

void LDL_3DRenderOpenGL3Begin(LDL_3DRenderOpenGL3* render)
{
    LDL_Vec2i size;

    if (render && render->Window)
    {
        size = LDL_WindowGetSize(render->Window);
        glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y);
        glUseProgram(render->Shader.ID);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
}

void LDL_3DRenderOpenGL3End(LDL_3DRenderOpenGL3* render)
{
    if (render && render->Window)
    {
        LDL_WindowPresent(render->Window);
    }
}

void LDL_3DRenderOpenGL3Clear(LDL_3DRenderOpenGL3* render, float r, float g, float b)
{
    glClearColor(r, g, b, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LDL_3DRenderOpenGL3VertexDraw(LDL_3DRenderOpenGL3* render, LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer)
{
    if (vertexBuffer && vertexBuffer->VBO > 0)
    {
        glBindVertexArray(vertexBuffer->VAO);
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertexBuffer->Count);
        glBindVertexArray(0);
    }
}

void LDL_3DRenderOpenGL3BindTexture(LDL_3DRenderOpenGL3* render, LDL_TextureOpenGL* texture)
{
    if (render && texture && texture->Id > 0)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture->Id);
        glUniform1i(render->Shader.uTextureLoc, 0);
        glUseProgram(render->Shader.ID);
    }
}

LDL_3DRenderOpenGL3VertexBuffer* LDL_3DRenderOpenGL3VertexBufferNew(size_t fvf)
{
    LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer = (LDL_3DRenderOpenGL3VertexBuffer*)malloc(sizeof(LDL_3DRenderOpenGL3VertexBuffer));

    if (vertexBuffer)
    {
        vertexBuffer->Format = fvf;
        vertexBuffer->Count  = 0;
        vertexBuffer->Stride = 0;

        glGenVertexArrays(1, &vertexBuffer->VAO);
        glGenBuffers(1, &vertexBuffer->VBO);

        return vertexBuffer;
    }

    return NULL;
}

void LDL_3DRenderOpenGL3VertexBufferFree(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer)
{
    if (vertexBuffer)
    {
        if (vertexBuffer->VBO > 0)
        {
            glDeleteBuffers(1, &vertexBuffer->VBO);
        }

        if (vertexBuffer->VAO > 0)
        {
            glDeleteVertexArrays(1, &vertexBuffer->VAO);
        }
        
        free(vertexBuffer);
    }
}

void LDL_3DRenderOpenGL3VertexBufferCopy(LDL_3DRenderOpenGL3VertexBuffer* vertexBuffer, size_t stride, size_t count, void* source)
{
    size_t totalSize;
    size_t currentOffset;

    if (vertexBuffer && source)
    {
        vertexBuffer->Count  = count;
        vertexBuffer->Stride = stride;
        totalSize            = stride * count;

        glBindVertexArray(vertexBuffer->VAO);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->VBO);
        glBufferData(GL_ARRAY_BUFFER, totalSize, source, GL_DYNAMIC_DRAW);

        currentOffset = 0;

        if (vertexBuffer->Format & LDL_FVF_XYZ)
        {
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (GLsizei)vertexBuffer->Stride, (void*)currentOffset);
            currentOffset += sizeof(float) * 3;
        }
        else if (vertexBuffer->Format & LDL_FVF_XYZW)
        {
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, (GLsizei)vertexBuffer->Stride, (void*)currentOffset);
            currentOffset += sizeof(float) * 4;
        }

        if (vertexBuffer->Format & LDL_FVF_COLOR)
        {
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (GLsizei)vertexBuffer->Stride, (void*)currentOffset);
            currentOffset += sizeof(float) * 3;
        }

        if (vertexBuffer->Format & LDL_FVF_NORMAL)
        {
            glEnableVertexAttribArray(2);
            glEnableVertexAttribArray(3);
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, (GLsizei)vertexBuffer->Stride, (void*)currentOffset);
            currentOffset += sizeof(float) * 3;
        }

        if (vertexBuffer->Format & LDL_FVF_TEXCOORD)
        {
            glEnableVertexAttribArray(3);
            glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, (GLsizei)vertexBuffer->Stride, (void*)currentOffset);
            currentOffset += sizeof(float) * 2;
        }

        glBindVertexArray(0);
    }
}

void LDL_3DRenderOpenGL3SetWorld(LDL_3DRenderOpenGL3* render, const float* matrix) 
{
    if (render)
    {
        glUniformMatrix4fv(render->Shader.uWorldLoc, 1, GL_FALSE, matrix);
    }
}

void LDL_3DRenderOpenGL3SetView(LDL_3DRenderOpenGL3* render, const float* matrix)
{
    if (render)
    {
        glUniformMatrix4fv(render->Shader.uViewLoc, 1, GL_FALSE, matrix);
    }
}

void LDL_3DRenderOpenGL3SetProjection(LDL_3DRenderOpenGL3* render, const float* matrix)
{
    if (render)
    {
        glUniformMatrix4fv(render->Shader.uProjLoc, 1, GL_FALSE, matrix);
    }
}
