// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Time/Ticks.hpp>
#include <LDL/Platforms/Windows/Windows.hpp>

size_t LDL::Time::Ticks()
{
	return timeGetTime();
}

void LDL::Time::Delay(size_t count)
{
	Sleep((DWORD)count);
}
