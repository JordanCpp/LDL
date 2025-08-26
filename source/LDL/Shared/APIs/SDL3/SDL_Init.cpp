// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <SDL3/SDL_init.h>
#include <LDL/Core/MemoryManager.hpp>
#include <LDL/Core/Config.hpp>

using namespace LDL::Core;

bool SDL_Init(SDL_InitFlags flags)
{
	LDL_UNUSED(flags);

	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	return false;
}
