// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Time/FpsCounter.hpp>

using namespace LDL;

FpsCounter::FpsCounter() :
    _startTime(0),
    _accumulator(0),
    _frameCount(0),
    _lastFps(0)
{
}

void FpsCounter::Start()
{
    _startTime = Ticks();
}

bool FpsCounter::Calc()
{
    size_t currentTime = Ticks();
    size_t delta       = currentTime - _startTime;

    _accumulator += delta;
    _frameCount++;

    if (_accumulator >= 1000)
    {
        _accumulator -= 1000;
        _lastFps      = _frameCount;
        _frameCount   = 0;

        return true;
    }

    return false;
}

size_t FpsCounter::Fps() const
{
    return _lastFps;
}
