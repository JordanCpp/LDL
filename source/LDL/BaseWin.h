
#ifndef LDL_BaseWin_H
#define LDL_BaseWin_H

#include <LDL/Types.h>
#include <LDL/Vec2i.h>

enum
{
	LDL_BaseWindowTitleMax = 64
};

typedef struct LDL_BaseWindow
{
	size_t    Mode;
	LDL_Vec2i Pos;
	LDL_Vec2i Size;
	char      Title[LDL_BaseWindowTitleMax];
} LDL_BaseWindow;

void LDL_BaseWindowInit(LDL_BaseWindow* baseWindow, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
bool LDL_BaseWindowHasMode(LDL_BaseWindow* baseWindow, size_t mode);
LDL_Vec2i LDL_BaseWindowGetPos(LDL_BaseWindow* baseWindow);
LDL_Vec2i LDL_BaseWindowGetSize(LDL_BaseWindow* baseWindow);
const char* LDL_BaseWindowGetTitle(LDL_BaseWindow* baseWindow);

#endif
