// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL3/SDL_error.h>
#include <LDL/APIs/SDL3/SDL_Application.hpp>

using namespace LDL;

const char* SDL_GetError(void)
{
	return App().GetResult().Message();
}
