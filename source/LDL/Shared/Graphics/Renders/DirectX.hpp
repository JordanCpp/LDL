// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Render_DirectX_hpp
#define LDL_Graphics_Render_DirectX_hpp

#include <LDL/std/string.hpp>

inline void ZeroMemory(void* dst, size_t size)
{
	LDL::memset(dst, 0, size);
}

#endif