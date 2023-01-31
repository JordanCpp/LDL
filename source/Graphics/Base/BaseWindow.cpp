#include <LDL/Graphics/Base/BaseWindow.hpp>

using namespace LDL::Graphics;

BaseWindow::BaseWindow(const Point2u& pos, const Point2u& size, const std::string& title):
    _Pos(pos),
    _Size(size),
    _Title(title)
{
}

const Point2u& BaseWindow::Pos()
{
    return _Pos;
}

const Point2u& BaseWindow::Size()
{
    return _Size;
}

void BaseWindow::Size(const Point2u& size)
{
    _Size = size;
}

const Point2u& BaseWindow::View()
{
    return _View;
}

void BaseWindow::View(const Point2u& size)
{
    _View = size;
}

const std::string& BaseWindow::Title()
{
    return _Title;
}

void BaseWindow::Title(const std::string& source)
{
    _Title = source;
}