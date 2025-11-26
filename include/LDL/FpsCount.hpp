// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_FpsCount_hpp
#define LDL_FpsCount_hpp

#include <LDL/Ticks.hpp>
#include <LDL/Types.hpp>

class LDL_LIBRARY LDL_FpsCounter
{
public:
	LDL_FpsCounter();
	void Start();
	bool Calc();
	size_t Fps() const;
private:
	size_t _startTime;
	size_t _accumulator;
	size_t _frameCount;
	size_t _lastFps;
};

#endif     
