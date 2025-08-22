#include <LDL/Shared/Graphics/Base/BaseWindow.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

BaseWindow::BaseWindow(const Vec2u& pos, const Vec2u& size, const std::string& title):
    _pos(pos),
    _size(size),
    _title(title)
{
}

const Vec2u& BaseWindow::Pos()
{
    return _pos;
}

const Vec2u& BaseWindow::Size()
{
    return _size;
}

void BaseWindow::Size(const Vec2u& size)
{
    _size = size;
}

const std::string& BaseWindow::Title()
{
    return _title;
}

void BaseWindow::Title(const std::string& source)
{
    _title = source;
}
