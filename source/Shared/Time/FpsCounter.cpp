#include <LDL/Time/FpsCounter.hpp>

using namespace LDL::Time;

FpsCounter::FpsCounter() :
	_Current(0),
	_Delta(0),
	_Old(0),
	_Fps(0)
{
}

void FpsCounter::Start()
{
	_Current = Ticks();
}

bool FpsCounter::Calc()
{
	_Fps++;

	_Delta = Ticks() - _Current;

	_Old += _Delta;

	if (_Old >= 1000)
	{
		return  true;
	}

	return false;
}

size_t FpsCounter::Fps()
{
	return _Fps;
}

void FpsCounter::Clear()
{
	_Fps = 0;
	_Old = 0;
}