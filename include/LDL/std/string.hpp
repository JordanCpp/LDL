// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_std_string_hpp
#define LDL_std_string_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	LDL_LIBRARY size_t strlcpy(char* dst, const char* src, size_t size);
	LDL_LIBRARY size_t strlen(const char* src);

	LDL_LIBRARY void* memcpy(void* dst, const void* src, size_t size);
	LDL_LIBRARY void* memset(void* ptr, int value, size_t num);
}

#endif
