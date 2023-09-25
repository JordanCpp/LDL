#include "GL1Win.hpp"
#include <LDL/Low/Errors.hpp>
#include <LDL/OpenGL/OpenGLTypes.hpp>
#include <LDL/OpenGL/OpenGL_Constants.hpp>

LDL_GL1Window::LDL_GL1Window(const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode) :
	_MainWindow(pos, size, title, mode)
{
    GLint major = 0;
    GLint minor = 0;

    glXQueryVersion(_MainWindow._Display, &major, &minor);

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

    _Visual = glXChooseVisual(_MainWindow._Display, _MainWindow._Screen, glxAttribs);

    if (_Visual == NULL)
        LDL_AddError("glXChooseVisual failed");

    XSetWindowAttributes windowAttribs;

    windowAttribs.border_pixel = BlackPixel(_MainWindow._Display, _MainWindow._Screen);
    windowAttribs.background_pixel = WhitePixel(_MainWindow._Display, _MainWindow._Screen);
    windowAttribs.override_redirect = True;
    windowAttribs.colormap = XCreateColormap(_MainWindow._Display, RootWindow(_MainWindow._Display, _MainWindow._Screen), _Visual->visual, AllocNone);
    windowAttribs.event_mask = ExposureMask;

    _MainWindow._Window = XCreateWindow(_MainWindow._Display, RootWindow(_MainWindow._Display, _MainWindow._Screen), 0, 0, 800, 600, 0, _Visual->depth, InputOutput, _Visual->visual, CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &windowAttribs);

    XSelectInput(_MainWindow._Display, _MainWindow._Window, _MainWindow._EventMask);

    _Context = glXCreateContext(_MainWindow._Display, _Visual, NULL, GL_TRUE);

    glXMakeCurrent(_MainWindow._Display, _MainWindow._Window, _Context);

    _OpenGLLoader.Init(1, 2);

    _MainWindow.Title(title);

    XClearWindow(_MainWindow._Display, _MainWindow._Window);
	XMapRaised(_MainWindow._Display, _MainWindow._Window); 
}

LDL_GL1Window::~LDL_GL1Window()
{
    glXDestroyContext(_MainWindow._Display, _Context);
}

bool LDL_GL1Window::Present()
{
    glXSwapBuffers(_MainWindow._Display, _MainWindow._Window);

    return true;
}

bool LDL_GL1Window::Running()
{
	return _MainWindow.Running();
}

void LDL_GL1Window::PollEvents()
{
	_MainWindow.PollEvents();
}

bool LDL_GL1Window::GetEvent(LDL_Event& event)
{
	return _MainWindow.GetEvent(event);
}

bool LDL_GL1Window::WaitEvent(LDL_Event& event)
{
	return _MainWindow.WaitEvent(event);
}

void LDL_GL1Window::StopEvent()
{
	_MainWindow.StopEvent();
}

void LDL_GL1Window::Title(const char* title)
{
	_MainWindow.Title(title);
}

const char* LDL_GL1Window::Title()
{
	return _MainWindow.Title();
}

const LDL_Point2u& LDL_GL1Window::Size()
{
	return _MainWindow.Size();
}

const LDL_Point2u& LDL_GL1Window::Pos()
{
	return _MainWindow.Pos();
}
