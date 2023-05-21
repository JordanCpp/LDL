#ifndef LDL_Window_h
#define LDL_Window_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Events.h>
#include <LDLC/LDL_Enums.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Window LDL_Window;

LDL_EXPORT LDL_Window* LDL_WindowNew(size_t x, size_t y, size_t w, size_t h, const char* title, size_t mode);
LDL_EXPORT void LDL_WindowFree(LDL_Window* window);
LDL_EXPORT bool LDL_WindowRunning(LDL_Window* window);
LDL_EXPORT void LDL_WindowPollEvents(LDL_Window* window);
LDL_EXPORT bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event);
LDL_EXPORT bool LDL_WindowWaitEvent(LDL_Window* window, LDL_Event* event);
LDL_EXPORT void LDL_WindowStopEvent(LDL_Window* window);
LDL_EXPORT void LDL_WindowSetTitle(LDL_Window* window, const char* title);
LDL_EXPORT const char* LDL_WindowGetTitle(LDL_Window* window);
LDL_EXPORT size_t LDL_WindowGetPosX(LDL_Window* window);
LDL_EXPORT size_t LDL_WindowGetPosY(LDL_Window* window);
LDL_EXPORT size_t LDL_WindowGetSizeX(LDL_Window* window);
LDL_EXPORT size_t LDL_WindowGetSizeY(LDL_Window* window);

#ifdef __cplusplus
}
#endif

#endif