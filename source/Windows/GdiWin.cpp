#include "GdiWin.hpp"

LDL_GdiWindow::LDL_GdiWindow(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
	_MainWindow(pos, size, title, mode)
{
}

bool LDL_GdiWindow::Running()
{
	return _MainWindow.Running();
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

const LDL_Vec2u& LDL_GdiWindow::Size()
{
	return _MainWindow.Size();
}

const LDL_Vec2u& LDL_GdiWindow::Pos()
{
	return _MainWindow.Pos();
}
