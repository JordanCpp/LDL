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

#ifndef LDL_macOS_MainWin_H
#define LDL_macOS_MainWin_H

#include <LDL/Result.h>
#include <LDL/EventH.h>
#include <LDL/BaseWin.h>
#include <LDL/macOS/KMapper.h> 

typedef struct LDL_MainWindow
{
    void* NSApp;          
    void* Window;         
    void* WindowDelegate; 
    void* View;           
    LDL_BaseWindow   BaseWindow;
    LDL_KeyMapper    KeyMapper;
    LDL_EventHandler EventHandler;
} LDL_MainWindow;

void LDL_MainWindowInit(LDL_MainWindow* mainWindow, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
void LDL_MainWindowDeinit(LDL_MainWindow* mainWindow);

LDL_Vec2i LDL_MainWindowGetPos(LDL_MainWindow* mainWindow);
LDL_Vec2i LDL_MainWindowGetSize(LDL_MainWindow* mainWindow);

const char* LDL_MainWindowGetTitle(LDL_MainWindow* mainWindow);
void LDL_MainWindowSetTitle(LDL_MainWindow* mainWindow, const char* title);

void LDL_MainWindowPollEvents(LDL_MainWindow* mainWindow);
bool LDL_MainWindowGetEvent(LDL_MainWindow* mainWindow, LDL_Event* event);
void LDL_MainWindowStopEvent(LDL_MainWindow* mainWindow);
bool LDL_MainWindowIsRunning(LDL_MainWindow* mainWindow);

#endif