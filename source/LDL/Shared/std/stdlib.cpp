// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/stdlib.hpp>
#include <LDL/Core/MemoryManager.hpp>

void* LDL::LDL_malloc(size_t bytes)
{
	return LDL::MemoryManager::Instance().GetMalloc()(bytes);
}

void LDL::LDL_free(void* ptr)
{
	LDL::MemoryManager::Instance().GetFree()(ptr);
}
