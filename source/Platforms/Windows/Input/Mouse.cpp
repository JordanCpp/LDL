#include <LDL/Input/Mouse.hpp>
#include "../Windows.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Input;
using namespace LDL::Math;

const Vec2u& Mouse::Pos()
{
    POINT point;

    if (!GetCursorPos(&point))
        throw LDL::Core::RuntimeError("GetCursorPos failed");

    _Pos = Vec2u(point.x, point.y);

    return _Pos;
}

void Mouse::Pos(const Vec2u& pos)
{
    if (!SetCursorPos((int)pos.x, (int)pos.y))
        throw LDL::Core::RuntimeError("SetCursorPos failed");
}

void Mouse::Hide()
{
    ShowCursor(FALSE);
}

void Mouse::Show()
{
    ShowCursor(TRUE);
}
