#include <LDL/Low/FpsLimit.hpp>
#include <LDL/Low/Ticks.hpp>

LDL_FpsLimiter::LDL_FpsLimiter(size_t fps) :
	_Fps(fps), 
	_Ticks(0)
{
}

void LDL_FpsLimiter::Mark()
{
	_Ticks = LDL_Ticks();
}

void LDL_FpsLimiter::Throttle() const
{
	if (1000 / _Fps > LDL_Ticks() - _Ticks)
	{
		LDL_Delay(1000 / _Fps - (LDL_Ticks() - _Ticks));
	}
}
