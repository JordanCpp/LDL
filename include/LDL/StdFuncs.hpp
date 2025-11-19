// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_StdFuncs_hpp
#define LDL_Core_StdFuncs_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

LDL_LIBRARY int LDL_abs(int x);
LDL_LIBRARY void* LDL_malloc(size_t bytes);
LDL_LIBRARY void LDL_free(void* ptr);
LDL_LIBRARY size_t LDL_strlcpy(char* dst, const char* src, size_t size);
LDL_LIBRARY size_t LDL_strlen(const char* src);
LDL_LIBRARY void* LDL_memcpy(void* dst, const void* src, size_t size);
LDL_LIBRARY void* LDL_memset(void* ptr, int value, size_t num);

#endif
