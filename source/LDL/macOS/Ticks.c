/*
Copyright(C) 2026 AslanD (Ztry8)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <mach/mach_time.h>
#include <unistd.h>
#include <LDL/Ticks.h>

static mach_timebase_info_data_t LDL_TimebaseInfo;
static int                       LDL_TimebaseReady = 0;

static void LDL_EnsureTimebase(void)
{
    if (!LDL_TimebaseReady)
    {
        mach_timebase_info(&LDL_TimebaseInfo);
        LDL_TimebaseReady = 1;
    }
}

size_t LDL_Ticks(void)
{
    LDL_EnsureTimebase();

    uint64_t ticks = mach_absolute_time();

    /* Convert to nanoseconds, then to milliseconds */
    uint64_t nanos = ticks * LDL_TimebaseInfo.numer / LDL_TimebaseInfo.denom;

    return (size_t)(nanos / 1000000ULL);
}

void LDL_Delay(size_t count)
{
    if (count >= 1000)
    {
        sleep((unsigned int)(count / 1000));
    }

    usleep((useconds_t)((count % 1000) * 1000));
}
