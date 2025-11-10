// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <LDL/Core/MemoryManager.hpp>
#include <LDL/APIs/GLUT/glutMemory.hpp>

using namespace LDL;

glutMemory::glutMemory()
{
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);
}
