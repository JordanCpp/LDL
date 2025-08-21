#include "WindowImplGlide.hpp"
#include <assert.h>
#include <stdexcept>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;

WindowImplGlide::WindowImplGlide(const Vec2u &pos, const Vec2u &size, const std::string &title, size_t mode) : 
    _Window(pos, size, title, mode)
{
    GLint major = 0;
    GLint minor = 0;

    glXQueryVersion(_Window._Display, &major, &minor);

    GLint ga[] = {
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

    _Visual = glXChooseVisual(_Window._Display, _Window._Screen, ga);

    if (_Visual == NULL)
        throw std::runtime_error("glXChooseVisual failed");

    XSetWindowAttributes wa;

    wa.border_pixel      = BlackPixel(_Window._Display, _Window._Screen);
    wa.background_pixel  = WhitePixel(_Window._Display, _Window._Screen);
    wa.override_redirect = True;
    wa.colormap          = XCreateColormap(_Window._Display, _Window._Root, _Visual->visual, AllocNone);
    wa.event_mask        = ExposureMask;
    
    size_t x = pos.x;
    size_t y = pos.y;
    size_t w = size.x;
    size_t h = size.y;

    _Window._Window = XCreateWindow(_Window._Display, _Window._Root, x, y, w, h, 0, _Visual->depth, InputOutput, _Visual->visual, CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &wa);

    XSelectInput(_Window._Display, _Window._Window, _Window._EventMask);

    _Context = glXCreateContext(_Window._Display, _Visual, NULL, GL_TRUE);

    glXMakeCurrent(_Window._Display, _Window._Window, _Context);

    _OpenGLLoader.Init(1, 2);

    _Window.Title(title);

    _Window.Show();
}

WindowImplGlide::~WindowImplGlide()
{
    glXDestroyContext(_Window._Display, _Context);
}

void WindowImplGlide::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void WindowImplGlide::Present()
{
    glXSwapBuffers(_Window._Display, _Window._Window);
}

const Vec2u& WindowImplGlide::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplGlide::Pos()
{
    return _Window.Pos();
}

bool WindowImplGlide::Running()
{
    return _Window.Running();
}

void WindowImplGlide::PollEvents()
{
    _Window.PollEvents();
}

bool WindowImplGlide::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplGlide::WaitEvent(LDL::Events::Event& event)
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
    return NULL;
}