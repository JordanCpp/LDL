// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Window_h
#define LDL_Window_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Events.h>
#include <LDLC/LDL_Enums.h>
#include <LDLC/LDL_RenderContext.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Window LDL_Window;

LDL_LIBRARY LDL_Window* LDL_WindowNew(LDL_RenderContext* renderContext, size_t x, size_t y, size_t w, size_t h, const char* title, size_t mode);
LDL_LIBRARY void LDL_WindowFree(LDL_Window* window);
LDL_LIBRARY bool LDL_WindowRunning(LDL_Window* window);
LDL_LIBRARY bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event);
LDL_LIBRARY bool LDL_WindowWaitEvent(LDL_Window* window, LDL_Event* event);
LDL_LIBRARY void LDL_WindowStopEvent(LDL_Window* window);
LDL_LIBRARY void LDL_WindowSetTitle(LDL_Window* window, const char* title);
LDL_LIBRARY const char* LDL_WindowGetTitle(LDL_Window* window);
LDL_LIBRARY size_t LDL_WindowGetPosX(LDL_Window* window);
LDL_LIBRARY size_t LDL_WindowGetPosY(LDL_Window* window);
LDL_LIBRARY size_t LDL_WindowGetSizeX(LDL_Window* window);
LDL_LIBRARY size_t LDL_WindowGetSizeY(LDL_Window* window);

#ifdef __cplusplus
}
#endif

#endif
