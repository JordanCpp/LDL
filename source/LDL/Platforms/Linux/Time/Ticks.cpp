// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <unistd.h>
#include <sys/time.h>
#include <LDL/Time/Ticks.hpp>

size_t LDL::Ticks()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void LDL::Delay(size_t count)
{
	if (count >= 1000)
	{
		sleep(count / 1000);
	}

	usleep((count % 1000) * 1000);
}
