
#ifndef LDL_Win9x_WinGL1_H
#define LDL_Win9x_WinGL1_H

#include <LDL/Win9x/MainWin.h>

typedef struct LDL_WindowOpenGL1
{
	LDL_Result*    Result;
	HDC            DeviceContext;
	HGLRC          OpenGLContext;
	LDL_MainWindow MainWindow;
} LDL_WindowOpenGL1;

void LDL_WindowOpenGL1Init(LDL_WindowOpenGL1* window, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
void LDL_WindowOpenGL1Deinit(LDL_WindowOpenGL1* window);

LDL_Vec2i LDL_WindowOpenGL1GetPos(LDL_WindowOpenGL1* window);

bool LDL_WindowOpenGL1GetEvent(LDL_WindowOpenGL1* window, LDL_Event* event);
void LDL_WindowOpenGL1StopEvent(LDL_WindowOpenGL1* window);
bool LDL_WindowOpenGL1IsRunning(LDL_WindowOpenGL1* window);

void LDL_WindowOpenGL1Present(LDL_WindowOpenGL1* window);

#endif
