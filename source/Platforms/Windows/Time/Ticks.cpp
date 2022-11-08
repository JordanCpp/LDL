#include <LDL/Time/Ticks.hpp>
#include <Windows.h>

size_t LDL::Time::Ticks()
{
	return timeGetTime();
}

void LDL::Time::Delay(size_t count)
{
	Sleep((DWORD)count);
}