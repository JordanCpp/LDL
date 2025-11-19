// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <LDL/MemMngr.hpp>
#include <LDL/SDL3/SDL_Memory.hpp>

SDL_Memory::SDL_Memory()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);
}
