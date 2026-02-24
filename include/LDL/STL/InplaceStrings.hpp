// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_STL_InplaceStrings_hpp
#define LDL_STL_InplaceStrings_hpp

#include <LDL/STL/InplaceString.hpp>

namespace LDL
{
	typedef InplaceString<256> AssertString;
	typedef InplaceString<256> TitleString;
	typedef InplaceString<512> ErrorString;
}

#endif
