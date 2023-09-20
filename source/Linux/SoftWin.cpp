#include "SoftWin.hpp"

LDL_SoftWindow::LDL_SoftWindow(LDL_ErrorHandler* errorHandler, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode) :
	_ErrorHandler(errorHandler),
	_MainWindow(errorHandler, pos, size, title, mode),
	_Screen(NULL)
{
	//XClearWindow(_MainWindow._Display, _MainWindow._Window);
	//XMapRaised(_MainWindow._Display, _MainWindow._Window);
	XMapWindow(_MainWindow._Display, _MainWindow._Window);
}

bool LDL_SoftWindow::Running()
{
	return _MainWindow.Running();
}

void LDL_SoftWindow::Present()
{
}

void LDL_SoftWindow::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
	if (!_Screen)
	{
		_Screen = XCreateImage(_MainWindow._Display, _MainWindow._Visual, DefaultDepth(_MainWindow._Display, _MainWindow._Screen), ZPixmap, 0, (char*)pixels, _MainWindow.Size().x, _MainWindow.Size().y, 32, 0);
	}

	XPutImage(_MainWindow._Display, _MainWindow._Root, DefaultGC(_MainWindow._Display, _MainWindow._Screen), _Screen, 0, 0, 0, 0, _MainWindow.Size().x, _MainWindow.Size().y);
}

void LDL_SoftWindow::PollEvents()
{
	_MainWindow.PollEvents();
}

bool LDL_SoftWindow::GetEvent(LDL_Event& event)
{
	return _MainWindow.GetEvent(event);
}

bool LDL_SoftWindow::WaitEvent(LDL_Event& event)
{
	return _MainWindow.WaitEvent(event);
}

void LDL_SoftWindow::StopEvent()
{
	_MainWindow.StopEvent();
}

void LDL_SoftWindow::Title(const char* title)
{
	_MainWindow.Title(title);
}

const char* LDL_SoftWindow::Title()
{
	return _MainWindow.Title();
}

const LDL_Point2u& LDL_SoftWindow::Size()
{
	return _MainWindow.Size();
}

const LDL_Point2u& LDL_SoftWindow::Pos()
{
	return _MainWindow.Pos();
}
