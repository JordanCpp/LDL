#include <LDL/Input/Mouse.hpp>
#include "../Windows.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Input;
using namespace LDL::Graphics;

const Point2u& Mouse::Pos()
{
    POINT point;

    if (!GetCursorPos(&point))
        throw LDL::Core::RuntimeError("GetCursorPos failed");

    _Pos = Point2u(point.x, point.y);

    return _Pos;
}

void Mouse::Pos(const Point2u& pos)
{
    if (!SetCursorPos((int)pos.PosX(), (int)pos.PosY()))
        throw LDL::Core::RuntimeError("SetCursorPos failed");
}