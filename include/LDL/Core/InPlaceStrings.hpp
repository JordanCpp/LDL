// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_InPlaceStrings_hpp
#define LDL_Core_InPlaceStrings_hpp

#include <LDL/Core/InPlaceString.hpp>

namespace LDL
{
	typedef InPlaceString<128> AssertString;
	typedef InPlaceString<128> TitleString;
	typedef InPlaceString<128> ErrorString;
	typedef InPlaceString<512> FileString;
}

#endif
