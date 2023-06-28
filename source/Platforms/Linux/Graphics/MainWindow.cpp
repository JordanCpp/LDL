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
	_Window   = XCreateSimpleWindow(_Display, RootWindowOfScreen(_Screen), _BaseWindow.Pos().x, _BaseWindow.Pos().y, _BaseWindow.Size().x, _BaseWindow.Size().y, 1, BlackPixel(_Display, _ScreenId), WhitePixel(_Display, _ScreenId));
        
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
    
    XNextEvent(_Display, &event);
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