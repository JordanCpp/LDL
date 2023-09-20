#include "GdiWin.hpp"

LDL_GdiWindow::LDL_GdiWindow(LDL_ErrorHandler* errorHandler, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode) :
	_ErrorHandler(errorHandler),
	_MainWindow(errorHandler, pos, size, title, mode)
{
}

bool LDL_GdiWindow::Running()
{
	return _MainWindow.Running();
}

void LDL_GdiWindow::Present()
{
}

void LDL_GdiWindow::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
}

void LDL_GdiWindow::PollEvents()
{
	_MainWindow.PollEvents();
}

bool LDL_GdiWindow::GetEvent(LDL_Event& event)
{
	return _MainWindow.GetEvent(event);
}

bool LDL_GdiWindow::WaitEvent(LDL_Event& event)
{
	return _MainWindow.WaitEvent(event);
}

void LDL_GdiWindow::StopEvent()
{
	_MainWindow.StopEvent();
}

void LDL_GdiWindow::Title(const char* title)
{
	_MainWindow.Title(title);
}

const char* LDL_GdiWindow::Title()
{
	return _MainWindow.Title();
}

const LDL_Point2u& LDL_GdiWindow::Size()
{
	return _MainWindow.Size();
}

const LDL_Point2u& LDL_GdiWindow::Pos()
{
	return _MainWindow.Pos();
}
