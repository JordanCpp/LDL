#include <LDL/Low/FpsCount.hpp>
#include <LDL/Low/Ticks.hpp>

LDL_FpsCounter::LDL_FpsCounter() :
	_Current(0),
	_Delta(0),
	_Old(0),
	_Fps(0)
{
}

void LDL_FpsCounter::Start()
{
	_Current = LDL_Ticks();
}

bool LDL_FpsCounter::Calc()
{
	_Fps++;

	_Delta = LDL_Ticks() - _Current;

	_Old += _Delta;

	if (_Old >= 1000)
	{
		return  true;
	}

	return false;
}

size_t LDL_FpsCounter::Fps()
{
	return _Fps;
}

void LDL_FpsCounter::Clear()
{
	_Fps = 0;
	_Old = 0;
}
