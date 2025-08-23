// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Input/Mouse.hpp>
#include <LDL/Core/Assert.hpp>
#include <LDL/Platforms/Windows/Windows.hpp>

using namespace LDL::Input;
using namespace LDL::Math;

Vec2u Mouse::Pos()
{
    POINT point;

    bool result = GetCursorPos(&point);
    LDL_ASSERT_DETAIL(result, "GetCursorPos failed");

    _pos = Vec2u(point.x, point.y);

    return _pos;
}

void Mouse::Pos(const Vec2u& pos)
{
    bool result = SetCursorPos((int)pos.x, (int)pos.y);
    LDL_ASSERT_DETAIL(result, "SetCursorPos failed");
}

void Mouse::Hide()
{
    ShowCursor(FALSE);
}

void Mouse::Show()
{
    ShowCursor(TRUE);
}
