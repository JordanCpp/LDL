// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_STL_inplace_strings_hpp
#define LDL_STL_inplace_strings_hpp

#include <LDL/STL/inplace_string.hpp>

namespace LDL
{
	typedef inplace_string<128> AssertString;
	typedef inplace_string<128> TitleString;
	typedef inplace_string<128> ErrorString;
	typedef inplace_string<512> FileString;
}

#endif
