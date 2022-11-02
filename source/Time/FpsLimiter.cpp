#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Time/Ticks.hpp>

LDL::Time::FpsLimiter::FpsLimiter(size_t fps) :
	_Fps(fps), 
	_Ticks(0)
{
}

void LDL::Time::FpsLimiter::Mark()
{
	_Ticks = LDL::Time::Ticks();
}

void LDL::Time::FpsLimiter::Throttle() const
{
	if (1000 / _Fps > LDL::Time::Ticks() - _Ticks)
	{
		LDL::Time::Delay(1000 / _Fps - (LDL::Time::Ticks() - _Ticks));
	}
}