#include <LDL/Time/Ticks.hpp>
#include "../Windows.hpp"

size_t LDL::Time::Ticks()
{
	return timeGetTime();
}

void LDL::Time::Delay(size_t count)
{
	Sleep((DWORD)count);
}