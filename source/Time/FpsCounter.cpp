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
	_Current = clock();
}

bool LDL::Time::FpsCounter::Calc()
{
	_Delta = clock() - _Current;

	if (_Delta > 0)
		_Fps = CLOCKS_PER_SEC / _Delta;

	_Old += _Delta;

	if (_Old >= CLOCKS_PER_SEC)
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