#include <LDL/Time/FpsCounter.hpp>

LDL::Time::FpsCounter::FpsCounter() :
	_Current(0),
	_Delta(0),
	_Old(0),
	_Fps(0)
{
}

void LDL::Time::FpsCounter::Start()
{
	_Current = LDL::Time::Ticks();
}

bool LDL::Time::FpsCounter::Calc()
{
	_Fps++;

	_Delta = LDL::Time::Ticks() - _Current;

	_Old += _Delta;

	if (_Old >= 1000)
	{
		return  true;
	}

	return false;
}

size_t LDL::Time::FpsCounter::Fps()
{
	return _Fps;
}

void LDL::Time::FpsCounter::Clear()
{
	_Fps = 0;
	_Old = 0;
}