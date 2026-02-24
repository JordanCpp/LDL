// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL_FpsCounter.h>
#include <LDL/Time/FpsCounter.hpp>

using namespace LDL;

struct LDL_FpsCounter
{
	FpsCounter _fpsCounter;
};

LDL_FpsCounter* LDL_FpsCounterNew()
{
	LDL_FpsCounter* p = new LDL_FpsCounter();

	return p;
}

void LDL_FpsCounterFree(LDL_FpsCounter* fpsCounter)
{
	delete fpsCounter;
}

void LDL_FpsCounterStart(LDL_FpsCounter* fpsCounter)
{
	fpsCounter->_fpsCounter.Start();
}

bool LDL_FpsCounterCalc(LDL_FpsCounter* fpsCounter)
{
	return fpsCounter->_fpsCounter.Calc();
}

size_t LDL_FpsCounterGetFps(LDL_FpsCounter* fpsCounter)
{
	return fpsCounter->_fpsCounter.Fps();
}
