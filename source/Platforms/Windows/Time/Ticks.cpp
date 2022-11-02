#include <LDL/Time/Ticks.hpp>
#include <Windows.h>

size_t LDL::Time::Ticks()
{
#if defined(WIN64)
	return GetTickCount64();
#else
	return GetTickCount();
#endif  
}

void LDL::Time::Delay(size_t count)
{
	Sleep((DWORD)count);
}