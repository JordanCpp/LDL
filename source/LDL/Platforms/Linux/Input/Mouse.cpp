#include <LDL/Input/Mouse.hpp>
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Input;
using namespace LDL::Math;

const Vec2u& Mouse::Pos()
{
    return _Pos;
}

void Mouse::Pos(const Vec2u& pos)
{
}