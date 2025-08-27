// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Utils_KeyMap_hpp
#define LDL_Platforms_Utils_KeyMap_hpp

#include <LDL/std/stddef.hpp>
#include <LDL/std/stdint.hpp>

namespace LDL
{
	class KeyMap
	{
	public:
		KeyMap(size_t code, uint8_t key);
		size_t GetCode();
		uint8_t GetKey();
	private:
		uint8_t _key;
		size_t  _code;
	};
}

#endif   
