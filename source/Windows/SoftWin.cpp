#include "SoftWin.hpp"

LDL_SoftWindow::LDL_SoftWindow(LDL_ErrorHandler* errorHandler, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode) :
	_ErrorHandler(errorHandler),
	_MainWindow(errorHandler, pos, size, title, mode)
{
	ZeroMemory(&_BITMAPINFO, sizeof(_BITMAPINFO));
}

bool LDL_SoftWindow::Running()
{
	return _MainWindow.Running();
}

void LDL_SoftWindow::Present(LDL_ISurface* surface)
{
	_BITMAPINFO.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
	_BITMAPINFO.bmiHeader.biWidth       = (LONG)Size().x;
	_BITMAPINFO.bmiHeader.biHeight      = -(LONG)Size().y;
	_BITMAPINFO.bmiHeader.biPlanes      = 1;
	_BITMAPINFO.bmiHeader.biBitCount    = surface->Bpp() * 8;
	_BITMAPINFO.bmiHeader.biCompression = BI_RGB;

	if (SetDIBitsToDevice(_MainWindow._HDC, 0, 0, (DWORD)Size().x, (DWORD)Size().y, 0, 0, 0, (UINT)Size().y, surface->Pixels(), &_BITMAPINFO, DIB_RGB_COLORS) == 0)
	{
		_ErrorHandler->Message("SetDIBitsToDevice failed");
	}
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
