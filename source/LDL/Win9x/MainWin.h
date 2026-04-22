
#ifndef LDL_Win9x_MainWin_H
#define LDL_Win9x_MainWin_H

#include <LDL/Result.h>
#include <LDL/BaseWin.h>
#include <LDL/EventH.h>
#include <LDL/Win9x/WinX.h>
#include <LDL/Win9x/KMapper.h>
#include <LDL/Win9x/WinError.h>

typedef struct LDL_MainWindow
{
	HWND             Hwnd;
	LDL_BaseWindow   BaseWindow;
	LDL_WindowError  WindowError;
	LDL_KeyMapper    KeyMapper;
	LDL_EventHandler EventHandler;
} LDL_MainWindow;

void LDL_MainWindowInit(LDL_MainWindow* mainWindow, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
void LDL_MainWindowDeinit(LDL_MainWindow* mainWindow);

LDL_Vec2i LDL_MainWindowGetPos(LDL_MainWindow* mainWindow);
void LDL_MainWindowPollEvents(LDL_MainWindow* mainWindow);
bool LDL_MainWindowGetEvent(LDL_MainWindow* mainWindow, LDL_Event* event);
void LDL_MainWindowStopEvent(LDL_MainWindow* mainWindow);
bool LDL_MainWindowIsRunning(LDL_MainWindow* mainWindow);

#endif
