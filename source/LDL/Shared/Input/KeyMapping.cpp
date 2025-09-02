// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/Shared/Input/KeyMapping.hpp>

using namespace LDL;

KeyMapping::KeyMapping()
{
    _table.reserve(DefaultCount);
}

void KeyMapping::Add(const KeyMap& keyMap)
{
	_table.push_back(keyMap);
}

uint8_t KeyMapping::FindKey(size_t key)
{
    for (size_t i = 0; i < _table.size(); i++) 
    {
        if (_table[i].GetCode() == key) 
        {
            return _table[i].GetKey();
        }
    }

    return KeyboardKey::Unknown;
}
