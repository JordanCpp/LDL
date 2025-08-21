#include "WindowImplGlide.hpp"

using namespace LDL::Events;
using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImplGlide::WindowImplGlide(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

WindowImplGlide::~WindowImplGlide()
{
    wglMakeCurrent(NULL, NULL);
    ReleaseDC(_Window._HWND, _Window._HDC);
}

bool WindowImplGlide::Running()
{
    return _Window.Running();
}

void WindowImplGlide::Present()
{
}

void WindowImplGlide::PollEvents()
{
    _Window.PollEvents();
}

const Vec2u& WindowImplGlide::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplGlide::Pos()
{
    return _Window.Pos();
}

bool WindowImplGlide::GetEvent(Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplGlide::WaitEvent(Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplGlide::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplGlide::Title()
{
    return _Window.Title();
}

void WindowImplGlide::Title(const std::string& title)
{
    _Window.Title(title);
}

void* WindowImplGlide::NativeHandle()
{
    return _Window._HWND;
}
