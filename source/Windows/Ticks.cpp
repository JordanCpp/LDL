#include <LDL/Low/Ticks.hpp>
#include <Windows.h>

size_t LDL_Ticks()
{
	return timeGetTime();
}

void LDL_Delay(size_t count)
{
	Sleep((DWORD)count);
}
