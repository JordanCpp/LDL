// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/KeyMap.hpp>

LDL_KeyMap::LDL_KeyMap() :
	_key(0),
	_code(0)
{
}

LDL_KeyMap::LDL_KeyMap(uint32_t code, uint8_t key) :
	_key(key),
	_code(code)
{
}

uint32_t LDL_KeyMap::GetCode()
{
	return _code;
}

uint8_t LDL_KeyMap::GetKey()
{
	return _key;
}
