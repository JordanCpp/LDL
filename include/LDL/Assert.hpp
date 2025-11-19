// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Assert_hpp
#define LDL_Assert_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

LDL_LIBRARY void LDL_Assert(bool condition, const char* description, const char* detail, const char* file, int line);

#define LDL_ASSERT(x)            LDL_Assert(x, #x, "", __FILE__, __LINE__)
#define LDL_ASSERT_DETAIL(x, y)  LDL_Assert(x, #x,  y, __FILE__, __LINE__)

#endif
