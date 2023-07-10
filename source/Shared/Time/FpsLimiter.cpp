#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Time/Ticks.hpp>

using namespace LDL::Time;

FpsLimiter::FpsLimiter(size_t fps) :
	_Fps(fps), 
	_Ticks(0)
{
}

void FpsLimiter::Mark()
{
	_Ticks = Ticks();
}

void FpsLimiter::Throttle() const
{
	if (1000 / _Fps > Ticks() - _Ticks)
	{
		Delay(1000 / _Fps - (Ticks() - _Ticks));
	}
}