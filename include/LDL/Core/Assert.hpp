// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Assert_hpp
#define LDL_Core_Assert_hpp

#include <LDL/Config.hpp>
#include <LDL/std/stddef.hpp>
#include <LDL/std/stdbool.hpp>

namespace LDL
{
	LDL_LIBRARY void Assert(bool condition, const char* description, const char* detail, const char* file, size_t line);
}

#define LDL_ASSERT(x)            LDL::Assert(x, #x, "", __FILE__, __LINE__)
#define LDL_ASSERT_DETAIL(x, y)  LDL::Assert(x, #x,  y, __FILE__, __LINE__)

#endif    
