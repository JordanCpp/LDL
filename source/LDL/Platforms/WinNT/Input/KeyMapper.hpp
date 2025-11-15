// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_Input_KeyMapper_hpp
#define LDL_Platforms_WinNT_Input_KeyMapper_hpp

#include <LDL/Shared/Input/KeyMapping.hpp>
#include <LDL/Platforms/WinNT/WinError.hpp>

namespace LDL
{
	class KeyMapper
	{
	public:
		KeyMapper();
		uint8_t ConvertKey(size_t key);
	private:
		KeyMapping _keyMapping;
	};
}

#endif   
