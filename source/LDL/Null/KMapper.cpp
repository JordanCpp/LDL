// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Enums.hpp>
#include <LDL/Null/KMapper.hpp>

LDL_KeyMapper::LDL_KeyMapper()
{
}

uint8_t LDL_KeyMapper::ConvertKey(size_t key)
{
    return _keyMapping.FindKey(key);
}
