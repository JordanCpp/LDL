// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Ticks.hpp>
#include <LDL/FpsLimit.hpp>

LDL_FpsLimiter::LDL_FpsLimiter(size_t fps) :
	_fps(fps), 
	_startTime(0)
{
}

void LDL_FpsLimiter::Mark()
{
	_startTime = LDL_Ticks();
}

void LDL_FpsLimiter::Throttle() const
{
	size_t frameTimeMs = 1000 / _fps;
	size_t elapsed     = LDL_Ticks() - _startTime;

	if (elapsed < frameTimeMs)
	{
		size_t sleepMs = frameTimeMs - elapsed;

		LDL_Delay(sleepMs);
	}
}
