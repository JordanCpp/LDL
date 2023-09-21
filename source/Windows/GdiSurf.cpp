#include "GdiSurf.hpp"

LDL_GdiSurface::LDL_GdiSurface(LDL_IWindow* window, const LDL_Point2u& size, uint8_t bpp) :
	_CompatibleDC(NULL),
	_Bitmap(NULL),
	_Window(window),
	_GdiWindow(NULL),
	_Surface(size, bpp)
{
	_GdiWindow = (LDL_GdiWindow*)window;

	_CompatibleDC = CreateCompatibleDC(_GdiWindow->_MainWindow._HDC);
	_Bitmap = CreateBitmap((int)_Surface.Size().x, (int)_Surface.Size().y, 1, bpp * 8, _Surface.Pixels());
	SelectObject(_CompatibleDC, _Bitmap);
}

LDL_GdiSurface::LDL_GdiSurface(LDL_IWindow* window, const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp) :
	_CompatibleDC(NULL),
	_Bitmap(NULL),
	_Window(window),
	_GdiWindow(NULL),
	_Surface(size, bytes, bpp)
{
	_GdiWindow = (LDL_GdiWindow*)window;

	_CompatibleDC = CreateCompatibleDC(_GdiWindow->_MainWindow._HDC);
	_Bitmap = CreateBitmap((int)_Surface.Size().x, (int)_Surface.Size().y, 1, bpp * 8, _Surface.Pixels());
	SelectObject(_CompatibleDC, _Bitmap);
}

LDL_GdiSurface::~LDL_GdiSurface()
{
	DeleteObject(_Bitmap);
	DeleteDC(_CompatibleDC);
}

uint8_t LDL_FAR* LDL_GdiSurface::Pixels()
{
	return _Surface.Pixels();
}

uint8_t LDL_GdiSurface::Bpp()
{
	return _Surface.Bpp();
}

const LDL_Point2u& LDL_GdiSurface::Size()
{
	return _Surface.Size();
}
