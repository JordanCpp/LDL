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

#include <string.h>
#include <LDL/PixFrmt.h>
#include <LDL/Win9x/WinSoft.h>

void LDL_WindowSoftwareInit(LDL_WindowSoftware* window, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
    LDL_WindowError windowError;

    if (window && result)
    {
        LDL_WindowErrorInit(&windowError);

        window->Result = result;
        memset(&window->BitmapInfo, 0, sizeof(BITMAPINFO));

        LDL_MainWindowInit(&window->MainWindow, result, pos, size, title, mode);
        window->Screen = LDL_SurfaceCreateFromSize(result, LDL_PixelFormatBGR24, LDL_WindowSoftwareGetSize(window));

        window->DeviceContext = GetDC(window->MainWindow.Hwnd);
        if (window->DeviceContext == NULL)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&windowError));
            return;
        }
    }
}

void LDL_WindowSoftwareDeinit(LDL_WindowSoftware* window)
{
    if (window)
    {
        if (window->DeviceContext)
        {
            ReleaseDC(window->MainWindow.Hwnd, window->DeviceContext);
            window->DeviceContext = NULL;
        }

        LDL_MainWindowDeinit(&window->MainWindow);
    }
}

LDL_Vec2i LDL_WindowSoftwareGetPos(LDL_WindowSoftware* window)
{
    if (window)
    {
        return LDL_MainWindowGetPos(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_WindowSoftwareGetSize(LDL_WindowSoftware* window)
{
    if (window)
    {
        return LDL_MainWindowGetSize(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

const char* LDL_WindowSoftwareGetTitle(LDL_WindowSoftware* window)
{
    if (window)
    {
        return LDL_MainWindowGetTitle(&window->MainWindow);
    }

    return NULL;
}

void LDL_WindowSoftwareSetTitle(LDL_WindowSoftware* window, const char* title)
{
    if (window)
    {
        LDL_MainWindowSetTitle(&window->MainWindow, title);
    }
}

bool LDL_WindowSoftwareGetEvent(LDL_WindowSoftware* window, LDL_Event* event)
{
    if (window && event)
    {
        return LDL_MainWindowGetEvent(&window->MainWindow, event);
    }

    return false;
}

void LDL_WindowSoftwarePresent(LDL_WindowSoftware* window)
{
    if (window && window->Screen)
    {
        window->BitmapInfo.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
        window->BitmapInfo.bmiHeader.biWidth       = (LONG)LDL_WindowSoftwareGetSize(window).x;
        window->BitmapInfo.bmiHeader.biHeight      = -(LONG)LDL_WindowSoftwareGetSize(window).y;
        window->BitmapInfo.bmiHeader.biPlanes      = 1;
        window->BitmapInfo.bmiHeader.biBitCount    = LDL_BytesPerPixelFromPixelFormat(LDL_SurfaceGetBytesPerPixel(window->Screen)) * 8;
        window->BitmapInfo.bmiHeader.biCompression = BI_RGB;
        
        SetDIBitsToDevice(window->DeviceContext, 0, 0, (DWORD)LDL_WindowSoftwareGetSize(window).x, (DWORD)LDL_WindowSoftwareGetSize(window).y, 0, 0, 0, (UINT)LDL_WindowSoftwareGetSize(window).y, LDL_SurfaceGetPixels(window->Screen), &window->BitmapInfo, DIB_RGB_COLORS);
    }
}

void LDL_WindowSoftwareStopEvent(LDL_WindowSoftware* window)
{
    if (window)
    {
        LDL_MainWindowStopEvent(&window->MainWindow);
    }
}

bool LDL_WindowSoftwareIsRunning(LDL_WindowSoftware* window)
{
    if (window)
    {
        return LDL_MainWindowIsRunning(&window->MainWindow);
    }

    return false;
}
