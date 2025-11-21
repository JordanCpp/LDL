// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Input/Mouse.hpp>

using namespace LDL;

LDL_Vec2u LDL_Mouse::Pos()
{
    return _pos;
}

void LDL_Mouse::Pos(const LDL_Vec2u& pos)
{
}
