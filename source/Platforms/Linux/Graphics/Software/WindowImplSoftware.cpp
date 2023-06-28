#include "WindowImplSoftware.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <assert.h>

using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImplSoftware::WindowImplSoftware(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

WindowImplSoftware::~WindowImplSoftware()
{
}

void WindowImplSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void WindowImplSoftware::Present()
{
}

const Vec2u& WindowImplSoftware::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplSoftware::Pos()
{
    return _Window.Pos();
}

bool WindowImplSoftware::Running()
{
    return _Window.Running();
}

void WindowImplSoftware::PollEvents()
{
    _Window.PollEvents();
}

bool WindowImplSoftware::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplSoftware::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplSoftware::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplSoftware::Title()
{
    return _Window.Title();
}

void WindowImplSoftware::Title(const std::string& title)
{
    _Window.Title(title);
}