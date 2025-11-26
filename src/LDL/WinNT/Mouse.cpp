// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Mouse.hpp>
#include <LDL/Assert.hpp>
#include <LDL/WinNT/Windows.hpp>

LDL_Vec2u LDL_Mouse::Pos()
{
    return _pos;
}

void LDL_Mouse::Pos(const LDL_Vec2u& pos)
{
    bool result = SetCursorPos((int)pos.x, (int)pos.y);
    LDL_ASSERT_DETAIL(result, "SetCursorPos failed");
}

void LDL_Mouse::Hide()
{
    ShowCursor(FALSE);
}

void LDL_Mouse::Show()
{
    ShowCursor(TRUE);
}
