#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Time/Ticks.hpp>

using namespace LDL::Time;

FpsLimiter::FpsLimiter(size_t fps) :
	_fps(fps), 
	_ticks(0)
{
}

void FpsLimiter::Mark()
{
	_ticks = Ticks();
}

void FpsLimiter::Throttle() const
{
	if (1000 / _fps > Ticks() - _ticks)
	{
		Delay(1000 / _fps - (Ticks() - _ticks));
	}
}
