#include <LDL/Graphics/Base/BaseWindow.hpp>

LDL::Graphics::BaseWindow::BaseWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title):
    _Pos(pos),
    _Size(size),
    _Title(title)
{
}

const LDL::Graphics::Point2u& LDL::Graphics::BaseWindow::Pos()
{
    return _Pos;
}

const LDL::Graphics::Point2u& LDL::Graphics::BaseWindow::Size()
{
    return _Size;
}

const std::string& LDL::Graphics::BaseWindow::Title()
{
    return _Title;
}

void LDL::Graphics::BaseWindow::Title(const std::string& source)
{
    _Title = source;
}