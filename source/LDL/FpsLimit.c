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
#include <LDL/FpsLimit.h>

struct LDL_FpsLimiter
{
	size_t Fps;
	size_t Start;
};

LDL_FpsLimiter* LDL_FpsLimiterCreate(LDL_Result* result, size_t fps)
{
    LDL_FpsLimiter* fpsLimiter;

    if (fps == 0)
    {
        if (result)
        {
            LDL_ResultAddMessage(result, "FPS cannot be zero"); /* или ваш аналог ошибки */
        }

        return NULL;
    }

    fpsLimiter = (LDL_FpsLimiter*)malloc(sizeof(LDL_FpsLimiter));

    if (fpsLimiter == NULL)
    {
        if (result)
        {
            LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
        }
    }
    else
    {
        fpsLimiter->Fps = fps;
        fpsLimiter->Start = 0;
    }

    return fpsLimiter;
}

void LDL_FpsLimiterDestroy(LDL_FpsLimiter* fpsLimiter)
{
    if (fpsLimiter)
    {
        free(fpsLimiter);
    }
}

void LDL_FpsLimiterMark(LDL_FpsLimiter* fpsLimiter)
{
    if (fpsLimiter)
    {
        fpsLimiter->Start = LDL_Ticks();
    }
}

void LDL_FpsLimiterThrottle(LDL_FpsLimiter* fpsLimiter)
{
    size_t sleepMs;
    size_t elapsed;
    size_t frameTimeMs;

    if (fpsLimiter)
    {
        if (fpsLimiter->Fps == 0)
        {
            return;
        }

        frameTimeMs = 1000 / fpsLimiter->Fps;
        elapsed = LDL_Ticks() - fpsLimiter->Start;

        if (elapsed < frameTimeMs)
        {
            sleepMs = frameTimeMs - elapsed;
            LDL_Delay(sleepMs);
        }
    }
}
