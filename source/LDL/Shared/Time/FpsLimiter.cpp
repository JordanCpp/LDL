// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Time/Ticks.hpp>

using namespace LDL::Time;

FpsLimiter::FpsLimiter(size_t fps) :
	_fps(fps), 
	_startTime(0)
{
}

void FpsLimiter::Mark()
{
	_startTime = Ticks();
}

void FpsLimiter::Throttle() const
{
	uint32_t frameTimeMs = 1000 / _fps;
	uint32_t elapsed     = Ticks() - _startTime;

	if (elapsed < frameTimeMs)
	{
		uint32_t sleepMs = frameTimeMs - elapsed;

		Delay(sleepMs);
	}
}
