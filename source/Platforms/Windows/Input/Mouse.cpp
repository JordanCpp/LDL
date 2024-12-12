#include <LDL/Input/Mouse.hpp>
#include <LDL/Core/Assert.hpp>
#include "../Windows.hpp"

using namespace LDL::Input;
using namespace LDL::Math;

const Vec2u& Mouse::Pos()
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
