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

#ifndef LDL_Window_H
#define LDL_Window_H

#include <LDL/Result.h>
#include <LDL/Vec2i.h>
#include <LDL/Events.h>
#include <LDL/Context.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Window LDL_Window;

LDL_LIBRARY LDL_Window* LDL_WindowNew(LDL_Result* result, LDL_Context* context, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
LDL_LIBRARY void LDL_WindowFree(LDL_Window* window);

LDL_LIBRARY bool LDL_WindowIsRunning(LDL_Window* window);
LDL_LIBRARY void LDL_WindowStopEvent(LDL_Window* window);
LDL_LIBRARY bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event);

LDL_LIBRARY LDL_Vec2i LDL_WindowGetSize(LDL_Window* window);

LDL_LIBRARY const char* LDL_WindowGetTitle(LDL_Window* window);
LDL_LIBRARY void LDL_WindowSetTitle(LDL_Window* window, const char* title);

LDL_LIBRARY void LDL_WindowPresent(LDL_Window* window);

#ifdef __cplusplus
}
#endif 

#endif
