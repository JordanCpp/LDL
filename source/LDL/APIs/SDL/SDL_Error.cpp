// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL/SDL_error.h>
#include <LDL/Core/Formatter.hpp>
#include <LDL/APIs/SDL/SDL_Application.hpp>

using namespace LDL;

void SDL_SetError(const char* fmt, ...)
{
	Formatter formatter;

	App().GetResult().Message(formatter.Format(fmt));
}

char* SDL_GetError(void)
{
	return (char*)App().GetResult().Message();
}

void SDL_ClearError(void)
{
	App().GetResult().Clear();
}
