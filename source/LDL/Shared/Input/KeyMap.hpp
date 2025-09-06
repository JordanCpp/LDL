// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_Input_KeyMap_hpp
#define LDL_Shared_Input_KeyMap_hpp

#include <LDL/std/stddef.hpp>
#include <LDL/std/stdint.hpp>

namespace LDL
{
	class KeyMap
	{
	public:
		KeyMap();
		KeyMap(uint32_t code, uint8_t key);
		uint32_t GetCode();
		uint8_t GetKey();
	private:
		uint8_t  _key;
		uint32_t _code;
	};
}

#endif   
