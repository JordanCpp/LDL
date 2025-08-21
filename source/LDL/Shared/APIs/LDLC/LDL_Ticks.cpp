#include <LDLC/LDL_Ticks.h>
#include <LDL/Time/Ticks.hpp>

using namespace LDL::Time;

size_t LDL_Ticks()
{
	return Ticks();
}

void LDL_Delay(size_t count)
{
	Delay(count);
}
