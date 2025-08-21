#include "BaseWindow.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

BaseWindow::BaseWindow(const Vec2u& pos, const Vec2u& size, const std::string& title):
    _Pos(pos),
    _Size(size),
    _Title(title)
{
}

const Vec2u& BaseWindow::Pos()
{
    return _Pos;
}

const Vec2u& BaseWindow::Size()
{
    return _Size;
}

void BaseWindow::Size(const Vec2u& size)
{
    _Size = size;
}

const std::string& BaseWindow::Title()
{
    return _Title;
}

void BaseWindow::Title(const std::string& source)
{
    _Title = source;
}
