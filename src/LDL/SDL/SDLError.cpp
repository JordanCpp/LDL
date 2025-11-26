// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL/error.h>
#include <LDL/Format.hpp>
#include <LDL/SDL/SDLApp.hpp>

void SDL_SetError(const char* fmt, ...)
{
	LDL_Formatter formatter;

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
