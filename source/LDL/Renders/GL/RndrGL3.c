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

#include <LDL/OpenGL/GL3_0.h>
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/RndrGL3.h>
#include <LDL/Renders/GL/GLUtils.h>

static const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec2 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"layout (location = 2) in vec4 aColor;\n"
"uniform mat4 uProjection;\n"
"out vec2 TexCoord;\n"
"out vec4 FragColor;\n"
"void main() {\n"
"   gl_Position = uProjection * vec4(aPos, 0.0, 1.0);\n"
"   TexCoord = aTexCoord;\n"
"   FragColor = aColor;\n"
"}\0";

static const char* fragmentShaderSource =
"#version 330 core\n"
"in vec2 TexCoord;\n"
"in vec4 FragColor;\n"
"uniform sampler2D uTexture;\n"
"uniform bool uUseTexture;\n"
"out vec4 FinalColor;\n"
"void main() {\n"
"   if(uUseTexture) {\n"
"       FinalColor = texture(uTexture, TexCoord) * FragColor;\n"
"   } else {\n"
"       FinalColor = FragColor;\n"
"   }\n"
"}\0";

static GLuint CompileShader(GLenum type, const char* source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    return shader;
}

void LDL_RenderOpenGL3Init(LDL_RenderOpenGL3* render, LDL_Result* result, LDL_Window* window)
{
    GLsizei stride;
    GLuint vs;
    GLuint fs;

    if (!render) return;

    render->Result = result;
    render->Window = window;

    LDL_BaseRenderInit(&render->BaseRender, LDL_ColorRgb(0, 0, 0));
    LDL_BufferOpenGLInit(&render->Buffer);

    LDL_Mat4fIdentity(&render->Projection);
    LDL_Mat4fIdentity(&render->ModelView);

    render->Loader = LDL_OpenGLLoaderNew(result, 3, 0);

    vs = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    render->ShaderProgram = glCreateProgram();

    glAttachShader(render->ShaderProgram, vs);
    glAttachShader(render->ShaderProgram, fs);

    glLinkProgram(render->ShaderProgram);

    glDeleteShader(vs);
    glDeleteShader(fs);

    render->ProjLoc   = glGetUniformLocation(render->ShaderProgram, "uProjection");
    render->UseTexLoc = glGetUniformLocation(render->ShaderProgram, "uUseTexture");

    glGenVertexArrays(1, &render->VAO);
    glGenBuffers(1, &render->VBO);

    glBindVertexArray(render->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, render->VBO);

    // Layout description based on LDL_Vertex:
    // pos: 2f, uv: 2f, color: 4f = 8 floats total (stride = 8 * 4 bytes)
    stride = sizeof(LDL_Vertex);

    // Attribute 0: Position (x, y)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void*)0);

    // Attribute 1: TexCoords (u, v)
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(2 * sizeof(float)));

    // Attribute 2: Color (r, g, b, a)
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, stride, (void*)(4 * sizeof(float)));

    glBindVertexArray(0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void LDL_RenderOpenGL3Deinit(LDL_RenderOpenGL3* render)
{
    if (render)
    {
        glDeleteProgram(render->ShaderProgram);
        glDeleteVertexArrays(1, &render->VAO);
        glDeleteBuffers(1, &render->VBO);

        LDL_BufferOpenGLDeinit(&render->Buffer);

        if (render->Loader)
        {
            LDL_OpenGLLoaderFree(render->Loader);
        }
    }
}

size_t LDL_RenderOpenGL3GetLayer(LDL_RenderOpenGL3* render)
{
    if (render)
    {
        return LDL_BaseRenderGetLayer(&render->BaseRender);
    }

    return 0;
}

void LDL_RenderOpenGL3SetLayer(LDL_RenderOpenGL3* render, size_t layer)
{
    if (render)
    {
        LDL_BaseRenderSetLayer(&render->BaseRender, layer);
    }
}

LDL_Color LDL_RenderOpenGL3GetColor(LDL_RenderOpenGL3* render)
{
    return LDL_BaseRenderGetColor(&render->BaseRender);
}

void LDL_RenderOpenGL3SetColor(LDL_RenderOpenGL3* render, LDL_Color color)
{
    LDL_BaseRenderSetColor(&render->BaseRender, color);
}

void LDL_RenderOpenGL3Clear(LDL_RenderOpenGL3* render)
{
    LDL_Color srcColor   = LDL_RenderOpenGL3GetColor(render);
    LDL_GLColor dstColor = LDL_GLNormalize(srcColor);

    glClearColor(dstColor.r, dstColor.g, dstColor.b, dstColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LDL_RenderOpenGL3Begin(LDL_RenderOpenGL3* render)
{
    LDL_Vec2i size;

    if (render && render->Window)
    {
        LDL_BufferOpenGLClear(&render->Buffer);

        size = LDL_WindowGetSize(render->Window);
        glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y);

        LDL_Mat4fOrtho(&render->Projection, 0.0f, (float)size.x, (float)size.y, 0.0f, 0.0f, 1.0f);
    }
}

void LDL_RenderOpenGL3End(LDL_RenderOpenGL3* render)
{
    size_t i;
    LDL_Batch* batch;

    if (!render) return;

    LDL_BufferOpenGLCalc(&render->Buffer);

    if (render->Buffer.BatchCount > 0)
    {
        glBindVertexArray(render->VAO);
        glBindBuffer(GL_ARRAY_BUFFER, render->VBO);
        glBufferData(GL_ARRAY_BUFFER, render->Buffer.VertexCount * sizeof(LDL_Vertex), render->Buffer.VertexBuffer, GL_STREAM_DRAW);

        glUseProgram(render->ShaderProgram);
        glUniformMatrix4fv(render->ProjLoc, 1, GL_FALSE, LDL_Mat4fGetValues(&render->Projection));

        for (i = 0; i < render->Buffer.BatchCount; ++i)
        {
            batch = &render->Buffer.Batches[i];

            if (batch->textureId != 0)
            {
                glBindTexture(GL_TEXTURE_2D, batch->textureId);
                glUniform1i(render->UseTexLoc, 1);
            }
            else
            {
                glUniform1i(render->UseTexLoc, 0);
            }

            glDrawArrays(GL_TRIANGLES, (GLint)batch->firstVertex, (GLsizei)batch->vertexCount);
        }

        glBindVertexArray(0);
        glUseProgram(0);
    }

    if (render->Window)
    {
        LDL_WindowPresent(render->Window);
    }
}

void LDL_RenderOpenGL3Draw(LDL_RenderOpenGL3* render, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
    if (render)
    {
        LDL_BufferOpenGLAddTexture(&render->Buffer, LDL_RenderOpenGL3GetLayer(render), texture, dstPos, dstSize, srcPos, srcSize);
    }
}

void LDL_RenderOpenGL3Line2i(LDL_RenderOpenGL3* render, LDL_Vec2i first, LDL_Vec2i last)
{
    if (render)
    {
        LDL_BufferOpenGLAddLine(&render->Buffer, LDL_RenderOpenGL3GetColor(render), LDL_RenderOpenGL3GetLayer(render), first, last);
    }
}

void LDL_RenderOpenGL3Fill2i(LDL_RenderOpenGL3* render, LDL_Vec2i first, LDL_Vec2i last)
{
    if (render)
    {
        LDL_BufferOpenGLAddFill(&render->Buffer, LDL_RenderOpenGL3GetColor(render), LDL_RenderOpenGL3GetLayer(render), first, last);
    }
}
