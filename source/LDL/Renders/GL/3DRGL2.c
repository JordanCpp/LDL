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
#include <LDL/OpenGL/GL2_0.h>
#include <LDL/Renders/GL/3DRGL2.h>

const char* vShaderSrcGL2 =
"#version 120\n"
"attribute vec3 aPos;\n"
"attribute vec3 aColor;\n"
"attribute vec3 aNormal;\n"
"attribute vec2 aTexCoord;\n"
"uniform mat4 uProj;\n"
"uniform mat4 uView;\n"
"uniform mat4 uWorld;\n"
"varying vec3 vColor;\n"
"varying vec2 vTexCoord;\n"
"void main() {\n"
"   gl_Position = uProj * uView * uWorld * vec4(aPos, 1.0);\n"
"   vColor = aColor;\n"
"   vTexCoord = aTexCoord;\n"
"}\n";

const char* fShaderSrcGL2 =
"#version 120\n"
"varying vec3 vColor;\n"
"varying vec2 vTexTcoord;\n" // В GLSL 1.20 нужно быть внимательным с именами
"uniform sampler2D uTexture;\n"
"uniform bool uHasTexture;\n"
"void main() {\n"
"   vec4 texColor = uHasTexture ? texture2D(uTexture, vTexCoord) : vec4(1.0);\n" // В 2.0 используем texture2D
"   gl_FragColor = vec4(vColor, 1.0) * texColor;\n"
"}\n";

static GLuint CompileShaderFull(const char* vSource, const char* fSource)
{
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vSource, NULL);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fSource, NULL);
    glCompileShader(fs);

    GLuint prog = glCreateProgram();
    glAttachShader(prog, vs);
    glAttachShader(prog, fs);
    glLinkProgram(prog);

    glDeleteShader(vs);
    glDeleteShader(fs);
    return prog;
}

void LDL_3DRenderOpenGL2Init(LDL_3DRenderOpenGL2* render, LDL_Result* result, LDL_Window* window)
{
    if (render && result && window)
    {
        render->Result = result;
        render->Window = window;
        render->Loader = LDL_OpenGLLoaderNew(result, 2, 0);

        render->Shader.ID          = CompileShaderFull(vShaderSrcGL2, fShaderSrcGL2);
        render->Shader.uProjLoc    = glGetUniformLocation(render->Shader.ID, "uProj");
        render->Shader.uViewLoc    = glGetUniformLocation(render->Shader.ID, "uView");
        render->Shader.uWorldLoc   = glGetUniformLocation(render->Shader.ID, "uWorld");
        render->Shader.uTextureLoc = glGetUniformLocation(render->Shader.ID, "uTexture");
    }
}

void LDL_3DRenderOpenGL2Deinit(LDL_3DRenderOpenGL2* render)
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

void LDL_3DRenderOpenGL2Begin(LDL_3DRenderOpenGL2* render)
{
    if (render && render->Shader.ID > 0)
    {
        glUseProgram(render->Shader.ID);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);
    }
}

void LDL_3DRenderOpenGL2End(LDL_3DRenderOpenGL2* render)
{
    if (render && render->Window)
    {
        LDL_WindowPresent(render->Window);
    }
}

void LDL_3DRenderOpenGL2Clear(LDL_3DRenderOpenGL2* render, float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LDL_3DRenderOpenGL2VertexDraw(LDL_3DRenderOpenGL2* render, LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer)
{
    if (render && vertexBuffer && vertexBuffer->VBO > 0)
    {
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->VBO);

        size_t offset = 0;
        size_t stride = vertexBuffer->Stride;

        if (vertexBuffer->Format & LDL_FVF_XYZ)
        {
            glEnableVertexAttribArray(0); // aPos
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (GLsizei)stride, (void*)offset);
            offset += sizeof(float) * 3;
        }
        if (vertexBuffer->Format & LDL_FVF_XYZW)
        {
            glEnableVertexAttribArray(0); // aPos
            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, (GLsizei)stride, (void*)offset);
            offset += sizeof(float) * 4;
        }

        if (vertexBuffer->Format & LDL_FVF_COLOR)
        {
            glEnableVertexAttribArray(1); // aColor
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, (GLsizei)stride, (void*)offset);
            offset += sizeof(float) * 3;
        }

        if (vertexBuffer->Format & LDL_FVF_NORMAL)
        {
            glEnableVertexAttribArray(2); // aNormal
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, (GLsizei)stride, (void*)offset);
            offset += sizeof(float) * 3;
        }

        if (vertexBuffer->Format & LDL_FVF_TEXCOORD)
        {
            glEnableVertexAttribArray(3); // aTexCoord
            glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, (GLsizei)stride, (void*)offset);
            offset += sizeof(float) * 2;
        }

        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertexBuffer->Count);

        // Сброс состояний
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

void LDL_3DRenderOpenGL2BindTexture(LDL_3DRenderOpenGL2* render, LDL_TextureOpenGL* texture)
{
    if (render && texture && texture->Id > 0)
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture->Id);
        glUniform1i(render->Shader.uTextureLoc, 0);
    }
}

LDL_3DRenderOpenGL2VertexBuffer* LDL_3DRenderOpenGL2VertexBufferNew(size_t fvf)
{
    LDL_3DRenderOpenGL2VertexBuffer* vBuffer = (LDL_3DRenderOpenGL2VertexBuffer*)malloc(sizeof(LDL_3DRenderOpenGL2VertexBuffer));

    if (vBuffer)
    {
        vBuffer->Format = fvf;
        vBuffer->Count = 0;

        glGenBuffers(1, &vBuffer->VBO);
        glBindBuffer(GL_ARRAY_BUFFER, vBuffer->VBO);

        return vBuffer;
    }

    return NULL;
}

void LDL_3DRenderOpenGL2VertexBufferFree(LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer)
{
    if (vertexBuffer)
    {
        if (vertexBuffer->VBO > 0)
        {
            glDeleteBuffers(1, &vertexBuffer->VBO);
        }

        free(vertexBuffer);
    }
}

void LDL_3DRenderOpenGL2VertexBufferCopy(LDL_3DRenderOpenGL2VertexBuffer* vertexBuffer, size_t size, size_t count, void* source)
{
    if (vertexBuffer && source && count > 0)
    {
        size_t dataSize = count * vertexBuffer->Stride;

        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->VBO);

        glBufferSubData(GL_ARRAY_BUFFER, 0, dataSize, source);

        vertexBuffer->Count = count;
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

void LDL_3DRenderOpenGL2SetWorld(LDL_3DRenderOpenGL2* render, const float* matrix)
{
    if (render && render->Shader.ID > 0 && matrix)
    {
        glUniformMatrix4fv(render->Shader.uWorldLoc, 1, GL_FALSE, matrix);
    }
}

void LDL_3DRenderOpenGL2SetView(LDL_3DRenderOpenGL2* render, const float* matrix)
{
    if (render && render->Shader.ID > 0 && matrix)
    {
        glUniformMatrix4fv(render->Shader.uViewLoc, 1, GL_FALSE, matrix);
    }
}

void LDL_3DRenderOpenGL2SetProjection(LDL_3DRenderOpenGL2* render, const float* matrix)
{
    if (render && render->Shader.ID > 0 && matrix)
    {
        glUniformMatrix4fv(render->Shader.uProjLoc, 1, GL_FALSE, matrix);
    }
}
