
#include <LDL/Ticks.h>
#include <LDL/Win9x/WinX.h>

size_t LDL_Ticks()
{
	return timeGetTime();
}

void LDL_Delay(size_t count)
{
	Sleep((DWORD)count);
}
