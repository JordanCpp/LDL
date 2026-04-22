
#include <LDL/BaseWin.h>
#include <LDL/StrSpan.h>

void LDL_BaseWindowInit(LDL_BaseWindow* baseWindow, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	LDL_StringSpan strTitle;

	if (baseWindow)
	{
		baseWindow->Pos  = pos;
		baseWindow->Size = size;

		strTitle = LDL_GetStringSpan(baseWindow->Title, LDL_BaseWindowTitleMax);
		LDL_StringSpanCopy(&strTitle, title);
	}
}

bool LDL_BaseWindowHasMode(LDL_BaseWindow* baseWindow, size_t mode)
{
	return (baseWindow->Mode & mode) != 0;
}

LDL_Vec2i LDL_BaseWindowGetPos(LDL_BaseWindow* baseWindow)
{
	if (baseWindow)
	{
		return baseWindow->Pos;
	}

	return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_BaseWindowGetSize(LDL_BaseWindow* baseWindow)
{
	if (baseWindow)
	{
		return baseWindow->Size;
	}

	return LDL_GetVec2i(0, 0);
}

const char* LDL_BaseWindowGetTitle(LDL_BaseWindow* baseWindow)
{
	return baseWindow->Title;
}
