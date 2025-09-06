// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Input/KeyMap.hpp>

using namespace LDL;

KeyMap::KeyMap() :
	_key(0),
	_code(0)
{
}

KeyMap::KeyMap(uint32_t code, uint8_t key) :
	_key(key),
	_code(code)
{
}

uint32_t KeyMap::GetCode()
{
	return _code;
}

uint8_t KeyMap::GetKey()
{
	return _key;
}
