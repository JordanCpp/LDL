#include "MainWindow.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;

size_t MainWindow::ConvertKey(size_t key)
{
    return LDL::Enums::KeyboardKey::Unknown;
}

MainWindow::MainWindow(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _BaseWindow(pos, size, title)
{
    _Display = XOpenDisplay(NULL);
    if (_Display == NULL)
        throw RuntimeError("XOpenDisplay failed");

    _Screen   = DefaultScreenOfDisplay(_Display);
	_ScreenId = DefaultScreen(_Display);

        
    GLint majorGLX = 0; 
    GLint minorGLX = 0;

        glXQueryVersion(_Display, &majorGLX, &minorGLX);

GLint glxAttribs[] = {
	GLX_RGBA,
	GLX_DOUBLEBUFFER,
	GLX_DEPTH_SIZE,     24,
	GLX_STENCIL_SIZE,   8,
	GLX_RED_SIZE,       8,
	GLX_GREEN_SIZE,     8,
	GLX_BLUE_SIZE,      8,
	GLX_SAMPLE_BUFFERS, 0,
	GLX_SAMPLES,        0,
	None
};
XVisualInfo* visual = glXChooseVisual(_Display, _ScreenId, glxAttribs);

XSetWindowAttributes windowAttribs;
	windowAttribs.border_pixel = BlackPixel(_Display, _ScreenId);
	windowAttribs.background_pixel = WhitePixel(_Display, _ScreenId);
	windowAttribs.override_redirect = True;
	windowAttribs.colormap = XCreateColormap(_Display, RootWindow(_Display, _ScreenId), visual->visual, AllocNone);
	windowAttribs.event_mask = ExposureMask;
	_Window = XCreateWindow(_Display, RootWindow(_Display, _ScreenId), 0, 0, 800, 600, 0, visual->depth, InputOutput, visual->visual, CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &windowAttribs);


	GLXContext context = glXCreateContext(_Display, visual, NULL, GL_TRUE);
	glXMakeCurrent(_Display, _Window, context);

	XClearWindow(_Display, _Window);
	XMapRaised(_Display, _Window);
}

MainWindow::~MainWindow()
{
    XDestroyWindow(_Display, _Window);
	XFree(_Screen);
	XCloseDisplay(_Display);
}

bool MainWindow::Running()
{
    return _Eventer.Running();
}

void MainWindow::PollEvents()
{
    XEvent event;
    
    //XNextEvent(_Display, &event);

    glXSwapBuffers(_Display, _Window);
}

bool MainWindow::GetEvent(LDL::Events::Event& event)
{
    if (!_Eventer.Empty())
    {
        _Eventer.Pop(event);

        return true;
    }

    return false;
}

bool MainWindow::WaitEvent(LDL::Events::Event& event)
{
    return _Eventer.Running();
}

void MainWindow::StopEvent()
{
    _Eventer.Stop();
}

void MainWindow::Title(const std::string& title)
{
    _BaseWindow.Title(title);
}

const std::string& MainWindow::Title()
{
    return _BaseWindow.Title();
}

const Vec2u& MainWindow::Size()
{
    return _BaseWindow.Size();
}

const Vec2u& MainWindow::Pos()
{
    return _BaseWindow.Pos();
}