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

#include <LDL/Win9x/WinGL1.h>

void LDL_WindowOpenGL1Init(LDL_WindowOpenGL1* window, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
    PIXELFORMATDESCRIPTOR pfd;
    LDL_WindowError windowError;
    int format;

    if (window && result)
    {
        LDL_WindowErrorInit(&windowError);

        window->Result = result;
        window->DeviceContext = NULL;
        window->OpenGLContext = NULL;

        LDL_MainWindowInit(&window->MainWindow, result, pos, size, title, mode);

        memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

        window->DeviceContext = GetDC(window->MainWindow.Hwnd);
        if (window->DeviceContext == NULL)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&windowError));
            return;
        }

        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 24;
        pfd.cDepthBits = 16;
        pfd.iLayerType = PFD_MAIN_PLANE;

        format = ChoosePixelFormat(window->DeviceContext, &pfd);
        if (format == 0)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&windowError));
            return;
        }

        if (!SetPixelFormat(window->DeviceContext, format, &pfd))
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&windowError));
            return;
        }

        window->OpenGLContext = wglCreateContext(window->DeviceContext);
        if (window->OpenGLContext == NULL)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&windowError));
            return;
        }

        if (!wglMakeCurrent(window->DeviceContext, window->OpenGLContext))
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&windowError));
            return;
        }
    }
}

void LDL_WindowOpenGL1Deinit(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        if (window->OpenGLContext)
        {
            wglMakeCurrent(NULL, NULL);
            wglDeleteContext(window->OpenGLContext);
            window->OpenGLContext = NULL;
        }

        if (window->DeviceContext)
        {
            ReleaseDC(window->MainWindow.Hwnd, window->DeviceContext);
            window->DeviceContext = NULL;
        }

        LDL_MainWindowDeinit(&window->MainWindow);
    }
}

LDL_Vec2i LDL_WindowOpenGL1GetPos(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        return LDL_MainWindowGetPos(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_WindowOpenGL1GetSize(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        return LDL_MainWindowGetSize(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

bool LDL_WindowOpenGL1GetEvent(LDL_WindowOpenGL1* window, LDL_Event* event)
{
    if (window && event)
    {
        return LDL_MainWindowGetEvent(&window->MainWindow, event);
    }

    return false;
}

void LDL_WindowOpenGL1Present(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        SwapBuffers(window->DeviceContext);
    }
}

void LDL_WindowOpenGL1StopEvent(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        LDL_MainWindowStopEvent(&window->MainWindow);
    }
}

bool LDL_WindowOpenGL1IsRunning(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        return LDL_MainWindowIsRunning(&window->MainWindow);
    }

    return false;
}
