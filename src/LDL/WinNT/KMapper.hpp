// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_WinNT_KMapper_hpp
#define LDL_WinNT_KMapper_hpp

#include <LDL/Mapping.hpp>
#include <LDL/WinNT/WinError.hpp>

class LDL_KeyMapper
{
public:
	LDL_KeyMapper();
	uint8_t ConvertKey(size_t key);
private:
	LDL_KeyMapping _keyMapping;
};

#endif   
