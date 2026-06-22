/*
 * Minimal LDL + WebGL example: spinning coloured triangle.
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
#include <string.h>
#include <math.h>

#include <LDL/LDL.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/OpenGL/GL1_0.h>
#include <LDL/OpenGL/GL1_5.h>
#include <LDL/OpenGL/GL2_0.h>

#if defined(__EMSCRIPTEN__)
#  include <emscripten.h>
#  include <emscripten/html5.h>
#endif

static const char* g_VertSrc =
    "attribute vec2 a_pos;\n"
    "attribute vec3 a_color;\n"
    "varying   vec3 v_color;\n"
    "uniform   float u_angle;\n"
    "void main() {\n"
    "    float c = cos(u_angle);\n"
    "    float s = sin(u_angle);\n"
    "    vec2 r = vec2(c * a_pos.x - s * a_pos.y,\n"
    "                  s * a_pos.x + c * a_pos.y);\n"
    "    gl_Position = vec4(r, 0.0, 1.0);\n"
    "    v_color = a_color;\n"
    "}\n";

static const char* g_FragSrc =
    "precision mediump float;\n"
    "varying vec3 v_color;\n"
    "void main() {\n"
    "    gl_FragColor = vec4(v_color, 1.0);\n"
    "}\n";

static const float g_Verts[] = {
     0.0f,  0.6f,  1.0f, 0.2f, 0.2f,
    -0.6f, -0.4f,  0.2f, 1.0f, 0.2f,
     0.6f, -0.4f,  0.2f, 0.2f, 1.0f
};

static LDL_Result*  g_Result  = NULL;
static LDL_Context* g_Context = NULL;
static LDL_Window*  g_Window  = NULL;

static GLuint g_Program  = 0;
static GLuint g_VBO      = 0;
static GLint  g_LocAngle = -1;
static GLint  g_LocPos   = -1;
static GLint  g_LocColor = -1;
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

    glBindBuffer(GL_ARRAY_BUFFER, g_VBO);

    glEnableVertexAttribArray((GLuint)g_LocPos);
    glVertexAttribPointer((GLuint)g_LocPos, 2, GL_FLOAT, GL_FALSE,
                          (GLsizei)(5 * sizeof(float)),
                          (void*)0);

    glEnableVertexAttribArray((GLuint)g_LocColor);
    glVertexAttribPointer((GLuint)g_LocColor, 3, GL_FLOAT, GL_FALSE,
                          (GLsizei)(5 * sizeof(float)),
                          (void*)(2 * sizeof(float)));

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray((GLuint)g_LocPos);
    glDisableVertexAttribArray((GLuint)g_LocColor);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);

    LDL_WindowPresent(g_Window);
}

int main(void)
{
    LDL_Vec2i pos  = LDL_GetVec2i(0, 0);
    LDL_Vec2i size = LDL_GetVec2i(800, 600);

    g_Result  = LDL_ResultCreate();
    g_Context = LDL_ContextCreate(g_Result, LDL_ContextOpenGLLegacy);
    g_Window  = LDL_WindowCreate(g_Result, g_Context,
                                  pos, size,
                                  "LDL Emscripten - Triangle", 0);

    if (LDL_ResultIsFail(g_Result))
    {
        printf("Init error: %s\n", LDL_ResultGetMessage(g_Result));
        LDL_WindowDestroy(g_Window);
        LDL_ContextDestroy(g_Context);
        LDL_ResultDestroy(g_Result);
        return 1;
    }

    /*
     * REQUIRED: Initialize the GL function pointer table.
     *
     * For WebGL 1 (GLES 2.0) we request major=2, minor=0.
     * This loads all entry points through GL 2.0, which is the full
     * set available in WebGL 1. Requesting 1.x would miss glCreateShader
     * and other shader-pipeline functions.
     */
    {
        LDL_OpenGLLoader* loader = LDL_OpenGLLoaderNew(g_Result, 2, 0);
        if (!loader || LDL_ResultIsFail(g_Result))
        {
            printf("GL loader error: %s\n", LDL_ResultGetMessage(g_Result));
            LDL_WindowDestroy(g_Window);
            LDL_ContextDestroy(g_Context);
            LDL_ResultDestroy(g_Result);
            return 1;
        }
        LDL_OpenGLLoaderFree(loader);
    }

    g_Program  = BuildProgram();
    g_LocAngle = glGetUniformLocation(g_Program, "u_angle");
    g_LocPos   = glGetAttribLocation(g_Program, "a_pos");
    g_LocColor = glGetAttribLocation(g_Program, "a_color");

    glGenBuffers(1, &g_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, g_VBO);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)sizeof(g_Verts),
                 g_Verts, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glViewport(0, 0, size.x, size.y);

#if defined(__EMSCRIPTEN__)
    emscripten_set_main_loop(MainLoop, 0, 1);
#else
    while (LDL_WindowIsRunning(g_Window) && LDL_ResultIsOk(g_Result))
        MainLoop();
#endif

    return 0;
}
