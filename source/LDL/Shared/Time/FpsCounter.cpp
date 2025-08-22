// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Time/FpsCounter.hpp>

using namespace LDL::Time;

FpsCounter::FpsCounter() :
	_current(0),
	_delta(0),
	_old(0),
	_fps(0)
{
}

void FpsCounter::Start()
{
	_current = Ticks();
}

bool FpsCounter::Calc()
{
	_fps++;

	_delta = Ticks() - _current;

	_old += _delta;

	if (_old >= 1000)
	{
		return  true;
	}

	return false;
}

size_t FpsCounter::Fps()
{
	return _fps;
}

void FpsCounter::Clear()
{
	_fps = 0;
	_old = 0;
}
