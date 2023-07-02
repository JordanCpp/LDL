#include "WindowImplOpenGL1.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <assert.h>
#include <iostream>

using namespace LDL::Math;
using namespace LDL::Graphics;

WindowImplOpenGL1::WindowImplOpenGL1(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
    _OpenGLLoader.Init(1, 2);
}

WindowImplOpenGL1::~WindowImplOpenGL1()
{
}

void WindowImplOpenGL1::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void WindowImplOpenGL1::Present()
{
}

const Vec2u& WindowImplOpenGL1::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplOpenGL1::Pos()
{
    return _Window.Pos();
}

bool WindowImplOpenGL1::Running()
{
    return _Window.Running();
}

void WindowImplOpenGL1::PollEvents()
{
    _Window.PollEvents();
}

bool WindowImplOpenGL1::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplOpenGL1::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplOpenGL1::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplOpenGL1::Title()
{
    return _Window.Title();
}

void WindowImplOpenGL1::Title(const std::string& title)
{
    _Window.Title(title);
}