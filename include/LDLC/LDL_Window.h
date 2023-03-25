#ifndef LDL_Window_h
#define LDL_Window_h

#include <LDLC/LDL_Events.h>

typedef struct LDL_Window LDL_Window;

LDL_Window* LDL_WindowNew(size_t x, size_t y, size_t w, size_t h, const char* title, size_t mode);
void LDL_WindowFree(LDL_Window* window);
bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event);
bool LDL_WindowWaitEvent(LDL_Window* window, LDL_Event* event);
void LDL_WindowStopEvent(LDL_Window* window);
void LDL_WindowSetTitle(LDL_Window* window, const char* title);
const char* LDL_WindowGetTitle(LDL_Window* window);
size_t LDL_WindowGetPosX(LDL_Window* window);
size_t LDL_WindowGetPosY(LDL_Window* window);
size_t LDL_WindowGetSizeX(LDL_Window* window);
size_t LDL_WindowGetSizeY(LDL_Window* window);

#endif