#include "GL1Win.hpp"
#include <LDL/Low/Errors.hpp>

LDL_GL1Window::LDL_GL1Window(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
	_HGLRC(NULL),
	_MainWindow(pos, size, title, mode)
{
    if (InitDC())
    {
        if (InitPixelFormat())
        {
            if (InitContext())
            {
                if (InitOpenGL())
                {
                }
            }
        }
    }
}

LDL_GL1Window::~LDL_GL1Window()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);

    ReleaseDC(_MainWindow._HWND, _MainWindow._HDC);
}

bool LDL_GL1Window::Present()
{
    if (!SwapBuffers(_MainWindow._HDC))
    {
        LDL_AddError("SwapBuffers failed");
        return false;
    }

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

const LDL_Vec2u& LDL_GL1Window::Size()
{
	return _MainWindow.Size();
}

const LDL_Vec2u& LDL_GL1Window::Pos()
{
	return _MainWindow.Pos();
}

bool LDL_GL1Window::InitDC()
{
    _MainWindow._HDC = GetDC(_MainWindow._HWND);

    if (_MainWindow._HDC == NULL)
    {
        LDL_AddError("GetDC failed");
        return false;
    }

    return true;
}

bool LDL_GL1Window::InitPixelFormat()
{
    PIXELFORMATDESCRIPTOR pfd;

    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(_MainWindow._HDC, &pfd);

    if (format == 0)
    {
        LDL_AddError("ChoosePixelFormat failed");
        return false;
    }
    else
    {
        if (!SetPixelFormat(_MainWindow._HDC, format, &pfd))
        {
            LDL_AddError("SetPixelFormat failed");
            return false;
        }
    }

    return true;
}

bool LDL_GL1Window::InitContext()
{
    _HGLRC = wglCreateContext(_MainWindow._HDC);

    if (_HGLRC == NULL)
    {
        LDL_AddError("wglCreateContext failed");
        return false;
    }
    else
    {
        if (!wglMakeCurrent(_MainWindow._HDC, _HGLRC))
        {
            LDL_AddError("wglMakeCurrent failed");
            return false;
        }
    }

    return true;
}

bool LDL_GL1Window::InitOpenGL()
{
    return  _OpenGLLoader.Init(1, 1);
}
