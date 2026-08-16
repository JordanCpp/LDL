/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <stdlib.h>
#include <LDL/Ticks.h>
#include <LDL/ErrorMsg.h>
#include <LDL/FpsCount.h>

struct LDL_FpsCounter
{ 
	size_t StartTime;
	size_t Accumulator;
	size_t FrameCount;
	size_t LastFps;
};

LDL_FpsCounter* LDL_FpsCounterCreate(LDL_Result* result)
{
    LDL_FpsCounter* fpsCounter = (LDL_FpsCounter*)malloc(sizeof(LDL_FpsCounter));

    if (fpsCounter == NULL)
    {
        if (result)
        {
            LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
        }

        return NULL;
    }

    fpsCounter->StartTime   = 0;
    fpsCounter->Accumulator = 0;
    fpsCounter->FrameCount  = 0;
    fpsCounter->LastFps     = 0;

    return fpsCounter;
}

void LDL_FpsCounterDestroy(LDL_FpsCounter* fpsCounter)
{
    if (fpsCounter)
    {
        free(fpsCounter);
    }
}

void LDL_FpsCounterStart(LDL_FpsCounter* fpsCounter)
{
    if (fpsCounter)
    {
        fpsCounter->StartTime = LDL_Ticks();
    }
}

bool LDL_FpsCounterCalc(LDL_FpsCounter* fpsCounter)
{
    size_t curTime;
    size_t delta;

    if (fpsCounter)
    {
        curTime = LDL_Ticks();
        delta   = curTime - fpsCounter->StartTime;

        fpsCounter->StartTime    = curTime;
        fpsCounter->Accumulator += delta;
        fpsCounter->FrameCount++;

        if (fpsCounter->Accumulator >= 1000)
        {
            fpsCounter->Accumulator = 0;
            fpsCounter->LastFps     = fpsCounter->FrameCount;
            fpsCounter->FrameCount  = 0;

            return true;
        }
    }

    return false;
}

size_t LDL_FpsCounterFps(LDL_FpsCounter* fpsCounter)
{
    return fpsCounter ? fpsCounter->LastFps : 0;
}
