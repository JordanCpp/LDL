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

#include <stdio.h>
#include <stdlib.h>
#include <LDL/OpenGL/GL2_0.h>
#include <LDL/Renders/GL/TexGL.h>
#include <LDL/Renders/GL/RndrGL2.h>
#include <LDL/Renders/GL/GLUtils.h>

static const char* vertexShaderSource =
"#version 110\n"
"attribute vec2 aPosition;\n"
"attribute vec2 aTexCoord;\n"
"attribute vec4 aColor;\n"
"uniform mat4 uProjection;\n"
"uniform mat4 uModelView;\n"
"varying vec2 vTexCoord;\n"
"varying vec4 vColor;\n"
"void main() {\n"
"    gl_Position = uProjection * uModelView * vec4(aPosition, 0.0, 1.0);\n"
"    vTexCoord = aTexCoord;\n"
"    vColor = aColor;\n"
"}\n";

static const char* fragmentShaderSource =
"#version 110\n"
"uniform sampler2D uTexture;\n"
"uniform int uUseTexture;\n"
"varying vec2 vTexCoord;\n"
"varying vec4 vColor;\n"
"void main() {\n"
"    if (uUseTexture == 1) {\n"
"        gl_FragColor = texture2D(uTexture, vTexCoord) * vColor;\n"
"    } else {\n"
"        gl_FragColor = vColor;\n"
"    }\n"
"}\n";

static GLuint CompileShader(GLenum type, const char* source)
{
    GLuint shader;
    GLint compiled;
    GLint infoLen;
    char* infoLog;

    shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        infoLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 1)
        {
            infoLog = (char*)malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            printf("Error compiling shader: %s\n", infoLog);
            free(infoLog);
        }
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

static void InitShaderProgram(LDL_ShaderProgram* shader)
{
    GLint linked;
    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    shader->program = glCreateProgram();
    glAttachShader(shader->program, vertexShader);
    glAttachShader(shader->program, fragmentShader);

    /* 
        Bind attribute locations(matching your buffer structure) 
    */
    glBindAttribLocation(shader->program, 0, "aPosition");
    glBindAttribLocation(shader->program, 1, "aTexCoord");
    glBindAttribLocation(shader->program, 2, "aColor");

    glLinkProgram(shader->program);

    glGetProgramiv(shader->program, GL_LINK_STATUS, &linked);
    if (!linked)
    {
        printf("Error linking shader program\n");
    }

    /*
        Get uniform locations
    */
    shader->aPosition   = glGetAttribLocation(shader->program, "aPosition");
    shader->aTexCoord   = glGetAttribLocation(shader->program, "aTexCoord");
    shader->aColor      = glGetAttribLocation(shader->program, "aColor");
    shader->uProjection = glGetUniformLocation(shader->program, "uProjection");
    shader->uModelView  = glGetUniformLocation(shader->program, "uModelView");
    shader->uTexture    = glGetUniformLocation(shader->program, "uTexture");
    shader->uUseTexture = glGetUniformLocation(shader->program, "uUseTexture");

    /*
        Clean up shaders after linking
    */
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void LDL_RenderOpenGL2Init(LDL_RenderOpenGL2* render, LDL_Result* result, LDL_Window* window)
{
    if (!render) return;

    render->Result = result;
    render->Window = window;

    LDL_BaseRenderInit(&render->BaseRender, LDL_ColorRgb(255, 255, 255));
    LDL_BufferOpenGLInit(&render->Buffer, render->Result);

    LDL_Mat4fIdentity(&render->Projection);
    LDL_Mat4fIdentity(&render->ModelView);

    render->Loader = LDL_OpenGLLoaderNew(result, 2, 1);

    InitShaderProgram(&render->Shader);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void LDL_RenderOpenGL2Deinit(LDL_RenderOpenGL2* render)
{
    if (render)
    {
        LDL_BufferOpenGLDeinit(&render->Buffer);

        if (render->Shader.program)
        {
            glDeleteProgram(render->Shader.program);
        }

        if (render->Loader)
        {
            LDL_OpenGLLoaderFree(render->Loader);
        }
    }
}

size_t LDL_RenderOpenGL2GetLayer(LDL_RenderOpenGL2* render)
{
    if (render)
    {
        return LDL_BaseRenderGetLayer(&render->BaseRender);
    }

    return 0;
}

void LDL_RenderOpenGL2SetLayer(LDL_RenderOpenGL2* render, size_t layer)
{
    if (render)
    {
        LDL_BaseRenderSetLayer(&render->BaseRender, layer);
    }
}

LDL_Color LDL_RenderOpenGL2GetColor(LDL_RenderOpenGL2* render)
{
    return LDL_BaseRenderGetColor(&render->BaseRender);
}

void LDL_RenderOpenGL2SetColor(LDL_RenderOpenGL2* render, LDL_Color color)
{
    LDL_BaseRenderSetColor(&render->BaseRender, color);
}

void LDL_RenderOpenGL2Clear(LDL_RenderOpenGL2* render)
{
    LDL_Color   srcColor = LDL_RenderOpenGL2GetColor(render);
    LDL_GLColor dstColor = LDL_GLNormalize(srcColor);

    glClearColor(dstColor.r, dstColor.g, dstColor.b, dstColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LDL_RenderOpenGL2Begin(LDL_RenderOpenGL2* render)
{
    LDL_Vec2i size;

    if (render && render->Window)
    {
        LDL_BufferOpenGLClear(&render->Buffer);

        size = LDL_WindowGetSize(render->Window);
        glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y);
        LDL_Mat4fOrtho(&render->Projection, 0.0f, (float)size.x, (float)size.y, 0.0f, 0.0f, 1.0f);

        glUseProgram(render->Shader.program);
        glUniformMatrix4fv(render->Shader.uProjection, 1, GL_FALSE, LDL_Mat4fGetValues(&render->Projection));
        glUniformMatrix4fv(render->Shader.uModelView, 1, GL_FALSE, LDL_Mat4fGetValues(&render->ModelView));
        glUniform1i(render->Shader.uTexture, 0);
    }
}

void LDL_RenderOpenGL2End(LDL_RenderOpenGL2* render)
{
    size_t i;
    LDL_Batch* batch;

    if (render)
    {
        LDL_BufferOpenGLCalc(&render->Buffer);

        if (render->Buffer.BatchCount > 0)
        {
            glEnableVertexAttribArray(render->Shader.aPosition);
            glEnableVertexAttribArray(render->Shader.aTexCoord);
            glEnableVertexAttribArray(render->Shader.aColor);

            for (i = 0; i < render->Buffer.BatchCount; ++i)
            {
                batch = &render->Buffer.Batches[i];

                if (batch->TextureId != 0)
                {
                    glBindTexture(GL_TEXTURE_2D, batch->TextureId);
                    glUniform1i(render->Shader.uUseTexture, 1);
                }
                else
                {
                    glUniform1i(render->Shader.uUseTexture, 0);
                }

       
                glVertexAttribPointer(render->Shader.aPosition, 2, GL_FLOAT, GL_FALSE, sizeof(LDL_Vertex), &render->Buffer.VertexBuffer[batch->FirstVertex].x);
                glVertexAttribPointer(render->Shader.aTexCoord, 2, GL_FLOAT, GL_FALSE, sizeof(LDL_Vertex), &render->Buffer.VertexBuffer[batch->FirstVertex].u);
                glVertexAttribPointer(render->Shader.aColor, 4, GL_FLOAT, GL_FALSE, sizeof(LDL_Vertex), &render->Buffer.VertexBuffer[batch->FirstVertex].r);

                glDrawArrays(GL_TRIANGLES, 0, (GLsizei)batch->VertexCount);
            }

            glDisableVertexAttribArray(render->Shader.aColor);
            glDisableVertexAttribArray(render->Shader.aTexCoord);
            glDisableVertexAttribArray(render->Shader.aPosition);
        }

        glUseProgram(0);

        if (render->Window)
        {
            LDL_WindowPresent(render->Window);
        }
    }
}

void LDL_RenderOpenGL2Draw(LDL_RenderOpenGL2* render, LDL_TextureOpenGL* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize)
{
    if (render)
    {
        LDL_BufferOpenGLAddTexture(&render->Buffer, LDL_RenderOpenGL2GetLayer(render), texture, dstPos, dstSize, srcPos, srcSize, texture->Quad);
    }
}

void LDL_RenderOpenGL2Line2i(LDL_RenderOpenGL2* render, LDL_Vec2i first, LDL_Vec2i last)
{
    if (render)
    {
        LDL_BufferOpenGLAddLine(&render->Buffer, LDL_RenderOpenGL2GetColor(render), LDL_RenderOpenGL2GetLayer(render), first, last);
    }
}

void LDL_RenderOpenGL2Fill2i(LDL_RenderOpenGL2* render, LDL_Vec2i first, LDL_Vec2i last)
{
    if (render)
    {
        LDL_BufferOpenGLAddFill(&render->Buffer, LDL_RenderOpenGL2GetColor(render), LDL_RenderOpenGL2GetLayer(render), first, last);
    }
}
