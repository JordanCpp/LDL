#include "WindowImplOpenGL1.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <assert.h>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;

WindowImplOpenGL1::WindowImplOpenGL1(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
    GLint major = 0; 
    GLint minor = 0;

    glXQueryVersion(_Window._Display, &major, &minor);

    GLint glxAttribs[] = {
        GLX_RGBA,
        GLX_DOUBLEBUFFER,
        GLX_DEPTH_SIZE, 24,
        GLX_STENCIL_SIZE, 8,
        GLX_RED_SIZE, 8,
        GLX_GREEN_SIZE, 8,
        GLX_BLUE_SIZE, 8,
        GLX_SAMPLE_BUFFERS, 0,
        GLX_SAMPLES, 0,
        None};

    _Visual = glXChooseVisual(_Window._Display, _Window._ScreenId, glxAttribs);

    if (_Visual == NULL)
        throw RuntimeError("glXChooseVisual failed");

    XSetWindowAttributes windowAttribs;

    windowAttribs.border_pixel      = BlackPixel(_Window._Display, _Window._ScreenId);
    windowAttribs.background_pixel  = WhitePixel(_Window._Display, _Window._ScreenId);
    windowAttribs.override_redirect = True;
    windowAttribs.colormap          = XCreateColormap(_Window._Display, RootWindow(_Window._Display, _Window._ScreenId), _Visual->visual, AllocNone);
    windowAttribs.event_mask        = ExposureMask;
    _Window._Window                 = XCreateWindow(_Window._Display, RootWindow(_Window._Display, _Window._ScreenId), 0, 0, 800, 600, 0, _Visual->depth, InputOutput, _Visual->visual, CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &windowAttribs);

    XSelectInput(_Window._Display, _Window._Window, KeyPressMask | ButtonMotionMask);

    _Context = glXCreateContext(_Window._Display, _Visual, NULL, GL_TRUE);
    
    glXMakeCurrent(_Window._Display, _Window._Window, _Context);

    _OpenGLLoader.Init(1, 2);

    _Window.Title(title);
    
    _Window.Show();
}

WindowImplOpenGL1::~WindowImplOpenGL1()
{
    glXDestroyContext(_Window._Display, _Context);
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