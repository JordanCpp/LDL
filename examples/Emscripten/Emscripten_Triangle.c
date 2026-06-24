/*
 * Minimal LDL + WebGL example: Textured spinning triangle.
 *
 * Uses ONLY WebGL-compatible GL calls (GLES 2.0 / OpenGL 2.0 core)
 *
 * NO fixed-function pipeline (glBegin/glEnd/glRotatef/etc.) is used,
 * because WebGL does not implement it.  Fixed-function entry points
 * return NULL from emscripten_GetProcAddress(), so calling them through
 * the LDL function-pointer table causes "indirect call to null" /
 * "called_user_callback" at runtime.
 */

#include <stdio.h>
#include <math.h>

#include <LDL/LDL.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/OpenGL/GL1_0.h>
#include <LDL/OpenGL/GL1_1.h>
#include <LDL/OpenGL/GL1_5.h>
#include <LDL/OpenGL/GL2_0.h>

#if defined(__EMSCRIPTEN__)
#  include <emscripten.h>
#  include <emscripten/html5.h>
#endif

static const char* g_VertSrc =
    "attribute vec2 a_pos;\n"
    "attribute vec2 a_uv;\n"
    "varying   vec2 v_uv;\n"
    "uniform   float u_angle;\n"
    "void main() {\n"
    "    float c = cos(u_angle);\n"
    "    float s = sin(u_angle);\n"
    "    vec2 r = vec2(c * a_pos.x - s * a_pos.y,\n"
    "                  s * a_pos.x + c * a_pos.y);\n"
    "    gl_Position = vec4(r, 0.0, 1.0);\n"
    "    v_uv = a_uv;\n"
    "}\n";

static const char* g_FragSrc =
    "precision mediump float;\n"
    "varying   vec2      v_uv;\n"
    "uniform   sampler2D u_tex;\n"
    "void main() {\n"
    "    gl_FragColor = texture2D(u_tex, v_uv);\n"
    "}\n";

static const float g_Verts[] = {
     0.0f,  0.7f,  0.5f, 0.0f,
    -0.7f, -0.5f,  0.0f, 1.0f,
     0.7f, -0.5f,  1.0f, 1.0f
};

static LDL_Result*  g_Result  = NULL;
static LDL_Context* g_Context = NULL;
static LDL_Window*  g_Window  = NULL;

static GLuint g_Program  = 0;
static GLuint g_VBO      = 0;
static GLuint g_Texture  = 0;
static GLint  g_LocAngle = -1;
static GLint  g_LocPos   = -1;
static GLint  g_LocUV    = -1;
static GLint  g_LocTex   = -1;
static float  g_Angle    = 0.0f;

static GLuint CompileShader(GLenum type, const char* src)
{
    GLuint shader = glCreateShader(type);
    GLint  ok     = 0;

    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);

    if (!ok)
    {
        char buf[512];
        glGetShaderInfoLog(shader, (GLsizei)sizeof(buf), NULL, buf);
        printf("Shader compile error: %s\n", buf);
    }

    return shader;
}

static GLuint BuildProgram(void)
{
    GLuint vert    = CompileShader(GL_VERTEX_SHADER,   g_VertSrc);
    GLuint frag    = CompileShader(GL_FRAGMENT_SHADER, g_FragSrc);
    GLuint program = glCreateProgram();
    GLint  ok      = 0;

    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &ok);

    if (!ok)
    {
        char buf[512];
        glGetProgramInfoLog(program, (GLsizei)sizeof(buf), NULL, buf);
        printf("Program link error: %s\n", buf);
    }

    glDeleteShader(vert);
    glDeleteShader(frag);

    return program;
}

static GLuint LoadBmpTexture(const char* path)
{
    GLuint           texId  = 0;
    LDL_BmpLoader*   loader = NULL;

    loader = LDL_BmpLoaderCreate(g_Result);
    if (!loader)
    {
        printf("LDL_BmpLoaderCreate failed\n");
        return 0;
    }

    if (!LDL_BmpLoaderLoadFromFile(loader, path))
    {
        printf("Failed to load BMP: %s\n", path);
        LDL_BmpLoaderDestroy(loader);
        return 0;
    }

    printf("Loaded %s  size=%dx%d\n",
           path,
           LDL_BmpLoaderGetSize(loader).x,
           LDL_BmpLoaderGetSize(loader).y);

    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    {
        LDL_Vec2i  sz  = LDL_BmpLoaderGetSize(loader);
        uint8_t*   px  = LDL_BmpLoaderGetPixels(loader);
        uint8_t    bpp = LDL_BmpLoaderGetBytesPerPixels(loader);
        GLenum     fmt = (bpp == 4) ? GL_RGBA : GL_RGB;

        glTexImage2D(GL_TEXTURE_2D, 0, (GLint)fmt,
                     (GLsizei)sz.x, (GLsizei)sz.y,
                     0, fmt, GL_UNSIGNED_BYTE, px);
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    LDL_BmpLoaderDestroy(loader);
    return texId;
}

#if defined(__EMSCRIPTEN__)
EMSCRIPTEN_KEEPALIVE
#endif
static void MainLoop(void)
{
    LDL_Event event;

    while (LDL_WindowGetEvent(g_Window, &event))
    {
        if (event.Type == LDL_EventIsQuit ||
            LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
        {
            LDL_WindowStopEvent(g_Window);
        }
    }

    if (!LDL_WindowIsRunning(g_Window) || LDL_ResultIsFail(g_Result))
    {
#if defined(__EMSCRIPTEN__)
        emscripten_cancel_main_loop();
#endif
        if (g_Texture) glDeleteTextures(1, &g_Texture);
        if (g_VBO)     glDeleteBuffers(1, &g_VBO);
        if (g_Program) glDeleteProgram(g_Program);

        LDL_WindowDestroy(g_Window);
        LDL_ContextDestroy(g_Context);

        if (LDL_ResultIsFail(g_Result))
            printf("Error: %s\n", LDL_ResultGetMessage(g_Result));

        LDL_ResultDestroy(g_Result);
        g_Window  = NULL;
        g_Context = NULL;
        g_Result  = NULL;
        return;
    }

    glClearColor(0.10f, 0.10f, 0.14f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(g_Program);

    glUniform1f(g_LocAngle, g_Angle);
    g_Angle += 0.02f;

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, g_Texture);
    glUniform1i(g_LocTex, 0);

    glBindBuffer(GL_ARRAY_BUFFER, g_VBO);

    glEnableVertexAttribArray((GLuint)g_LocPos);
    glVertexAttribPointer((GLuint)g_LocPos, 2, GL_FLOAT, GL_FALSE,
                          (GLsizei)(4 * sizeof(float)),
                          (void*)0);

    glEnableVertexAttribArray((GLuint)g_LocUV);
    glVertexAttribPointer((GLuint)g_LocUV,  2, GL_FLOAT, GL_FALSE,
                          (GLsizei)(4 * sizeof(float)),
                          (void*)(2 * sizeof(float)));

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray((GLuint)g_LocPos);
    glDisableVertexAttribArray((GLuint)g_LocUV);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(0);

    LDL_WindowPresent(g_Window);
}

int main(void)
{
    LDL_Vec2i pos  = LDL_GetVec2i(0, 0);
    LDL_Vec2i size = LDL_GetVec2i(800, 600);
    LDL_OpenGLLoader* loader = NULL;

    g_Result  = LDL_ResultCreate();
    g_Context = LDL_ContextCreate(g_Result, LDL_ContextOpenGLLegacy);
    g_Window  = LDL_WindowCreate(g_Result, g_Context,
                                  pos, size,
                                  "LDL Emscripten - Textured Triangle", 0);

    if (LDL_ResultIsFail(g_Result))
    {
        printf("Init error: %s\n", LDL_ResultGetMessage(g_Result));
        LDL_WindowDestroy(g_Window);
        LDL_ContextDestroy(g_Context);
        LDL_ResultDestroy(g_Result);
        return 1;
    }

    loader = LDL_OpenGLLoaderNew(g_Result, 2, 0);
    if (!loader || LDL_ResultIsFail(g_Result))
    {
        printf("GL loader error: %s\n", LDL_ResultGetMessage(g_Result));
        LDL_WindowDestroy(g_Window);
        LDL_ContextDestroy(g_Context);
        LDL_ResultDestroy(g_Result);
        return 1;
    }
    LDL_OpenGLLoaderFree(loader);

    g_Program  = BuildProgram();
    g_LocAngle = glGetUniformLocation(g_Program, "u_angle");
    g_LocTex   = glGetUniformLocation(g_Program, "u_tex");
    g_LocPos   = glGetAttribLocation(g_Program,  "a_pos");
    g_LocUV    = glGetAttribLocation(g_Program,  "a_uv");

    glGenBuffers(1, &g_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, g_VBO);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)sizeof(g_Verts),
                 g_Verts, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    g_Texture = LoadBmpTexture("Files/LDL_24_256.bmp");
    if (!g_Texture)
    {
        printf("Texture load failed — check Files/ directory\n");
    }

    glViewport(0, 0, size.x, size.y);

#if defined(__EMSCRIPTEN__)
    emscripten_set_main_loop(MainLoop, 0, 1);
#else
    while (LDL_WindowIsRunning(g_Window) && LDL_ResultIsOk(g_Result))
        MainLoop();
#endif

    return 0;
}
