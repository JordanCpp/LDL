/*
Copyright(C) 2026 AslanD (Ztry8)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_macOS_WinGL_H
#define LDL_macOS_WinGL_H

#include <LDL/macOS/MainWin.h>

typedef struct LDL_WindowOpenGL
{
    void* PixelFormat; 
    void* Context;   
    LDL_Result* Result;
    LDL_MainWindow MainWindow;
} LDL_WindowOpenGL;

void LDL_WindowOpenGLInit(LDL_WindowOpenGL* window, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
void LDL_WindowOpenGLDeinit(LDL_WindowOpenGL* window);

LDL_Vec2i LDL_WindowOpenGLGetPos(LDL_WindowOpenGL* window);
LDL_Vec2i LDL_WindowOpenGLGetSize(LDL_WindowOpenGL* window);

bool LDL_WindowOpenGLGetEvent(LDL_WindowOpenGL* window, LDL_Event* event);
void LDL_WindowOpenGLStopEvent(LDL_WindowOpenGL* window);
bool LDL_WindowOpenGLIsRunning(LDL_WindowOpenGL* window);

const char* LDL_WindowOpenGLGetTitle(LDL_WindowOpenGL* window);
void LDL_WindowOpenGLSetTitle(LDL_WindowOpenGL* window, const char* title);

void LDL_WindowOpenGLPresent(LDL_WindowOpenGL* window);

#endif