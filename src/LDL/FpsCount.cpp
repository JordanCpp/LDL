// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/FpsCount.hpp>

LDL_FpsCounter::LDL_FpsCounter() :
    _startTime(0),
    _accumulator(0),
    _frameCount(0),
    _lastFps(0)
{
}

void LDL_FpsCounter::Start()
{
    _startTime = LDL_Ticks();
}

bool LDL_FpsCounter::Calc()
{
    size_t currentTime = LDL_Ticks();
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

size_t LDL_FpsCounter::Fps() const
{
    return _lastFps;
}
