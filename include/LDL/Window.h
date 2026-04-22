
#ifndef LDL_Window_H
#define LDL_Window_H

#include <LDL/Result.h>
#include <LDL/Vec2i.h>
#include <LDL/Events.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Window LDL_Window;

LDL_LIBRARY LDL_Window* LDL_WindowNew(LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
LDL_LIBRARY void LDL_WindowFree(LDL_Window* window);

LDL_LIBRARY bool LDL_WindowIsRunning(LDL_Window* window);
LDL_LIBRARY void LDL_WindowStopEvent(LDL_Window* window);
LDL_LIBRARY bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event);

LDL_LIBRARY void LDL_WindowPresent(LDL_Window* window);

#ifdef __cplusplus
}
#endif 

#endif
