// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Time_Ticks_hpp
#define LDL_Time_Ticks_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	LDL_LIBRARY size_t Ticks();
	LDL_LIBRARY void Delay(size_t count);
}

#endif    
