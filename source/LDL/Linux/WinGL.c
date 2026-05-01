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

#include <LDL/Linux/WinGL.h>
#include <LDL/OpenGL/GLTypes.h>

void LDL_WindowOpenGLInit(LDL_WindowOpenGL *window, LDL_Result *result, LDL_Vec2i pos, LDL_Vec2i size, const char *title, size_t mode)
{
    LDL_MainWindowInit(&window->MainWindow, result, pos, size, title, mode);

    GLint major = 0;
    GLint minor = 0;

    int queryVersion = glXQueryVersion(window->MainWindow.Display, &major, &minor);
    if (!queryVersion)
    {
        LDL_ResultAddMessage(result, "Error: glXQueryVersion\n");
        return;
    }

    GLint ga[] = {
        GLX_RGBA,
        GLX_DOUBLEBUFFER,
        GLX_DEPTH_SIZE, 24,
        GLX_STENCIL_SIZE, 8,
        GLX_RED_SIZE, 8,
        GLX_GREEN_SIZE, 8,
        GLX_BLUE_SIZE, 8,
        GLX_SAMPLE_BUFFERS, 0,
        GLX_SAMPLES, 0,
        None};

    window->Visual = glXChooseVisual(window->MainWindow.Display, window->MainWindow.Screen, ga);
    if (!window->Visual)
    {
        LDL_ResultAddMessage(result, "Error: glXChooseVisual\n");
        return;
    }

    XSetWindowAttributes wa;
    wa.border_pixel      = BlackPixel(window->MainWindow.Display, window->MainWindow.Screen);
    wa.background_pixel  = WhitePixel(window->MainWindow.Display, window->MainWindow.Screen);
    wa.override_redirect = True;
    wa.colormap          = XCreateColormap(window->MainWindow.Display, window->MainWindow.Root, window->Visual->visual, AllocNone);
    wa.event_mask        = ExposureMask;

    size_t x = LDL_BaseWindowGetPos(&window->MainWindow.BaseWindow).x;
    size_t y = LDL_BaseWindowGetPos(&window->MainWindow.BaseWindow).y;
    size_t w = LDL_BaseWindowGetSize(&window->MainWindow.BaseWindow).x;
    size_t h = LDL_BaseWindowGetSize(&window->MainWindow.BaseWindow).y;

    window->MainWindow.Window = XCreateWindow(window->MainWindow.Display, window->MainWindow.Root, x, y, w, h, 0, window->Visual->depth, InputOutput, window->Visual->visual, CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &wa);
    if (!window->MainWindow.Window)
    {
        LDL_ResultAddMessage(result, "Error: XCreateWindow\n");
        return;
    }

    int selectInput = XSelectInput(window->MainWindow.Display, window->MainWindow.Window, window->MainWindow.EventMask);
    if (!selectInput)
    {
        LDL_ResultAddMessage(result, "Error: XSelectInput\n");
        return;
    }

    window->Context = glXCreateContext(window->MainWindow.Display, window->Visual, NULL, 1);
    if (!window->Context)
    {
        LDL_ResultAddMessage(result, "Error: glXCreateContext\n");
        return;
    }

    int makeCurrent = glXMakeCurrent(window->MainWindow.Display, window->MainWindow.Window, window->Context);
    if (!makeCurrent)
    {
        LDL_ResultAddMessage(result, "Error: glXMakeCurrent\n");
        return;
    }

    LDL_WindowOpenGLSetTitle(window, LDL_WindowOpenGLGetTitle(window));

    XClearWindow(window->MainWindow.Display, window->MainWindow.Window);
    XMapRaised(window->MainWindow.Display, window->MainWindow.Window);
}

void LDL_WindowOpenGLDeinit(LDL_WindowOpenGL *window)
{
    if (window)
    {
        if (window->MainWindow.Display && window->Context)
        {
            glXDestroyContext(window->MainWindow.Display, window->Context);
        }

        LDL_MainWindowDeinit(&window->MainWindow);
    }
}

LDL_Vec2i LDL_WindowOpenGLGetPos(LDL_WindowOpenGL *window)
{
    if (window)
    {
        return LDL_MainWindowGetPos(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_WindowOpenGLGetSize(LDL_WindowOpenGL *window)
{
    if (window)
    {
        return LDL_MainWindowGetSize(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

bool LDL_WindowOpenGLGetEvent(LDL_WindowOpenGL *window, LDL_Event *event)
{
    if (window && event)
    {
        return LDL_MainWindowGetEvent(&window->MainWindow, event);
    }

    return false;
}

void LDL_WindowOpenGLPresent(LDL_WindowOpenGL *window)
{
    glXSwapBuffers(window->MainWindow.Display, window->MainWindow.Window);
}

void LDL_WindowOpenGLStopEvent(LDL_WindowOpenGL *window)
{
    if (window)
    {
        LDL_MainWindowStopEvent(&window->MainWindow);
    }
}

bool LDL_WindowOpenGLIsRunning(LDL_WindowOpenGL *window)
{
    if (window)
    {
        return LDL_MainWindowIsRunning(&window->MainWindow);
    }

    return false;
}

const char *LDL_WindowOpenGLGetTitle(LDL_WindowOpenGL *window)
{
    if (window)
    {
        return LDL_MainWindowGetTitle(&window->MainWindow);
    }

    return NULL;
}

void LDL_WindowOpenGLSetTitle(LDL_WindowOpenGL *window, const char *title)
{
    if (window && title)
    {
        LDL_MainWindowSetTitle(&window->MainWindow, title);
    }
}
