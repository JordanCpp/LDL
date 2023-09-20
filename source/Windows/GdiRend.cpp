#include "GdiRend.hpp"
#include "GdiWin.hpp"

LDL_GdiRender::LDL_GdiRender(LDL_IRenderContext* context, LDL_IWindow* window) :
	_RenderContext(context),
	_Window(window),
	_GdiWindow(NULL),
	_BaseRender(window->Size())
{
	_GdiWindow = (LDL_GdiWindow*)_Window;

	ZeroMemory(&_PaintStruct, sizeof(PAINTSTRUCT));
	_Pen   = CreatePen(PS_SOLID, 1, RGB(_BaseRender.Color().r, _BaseRender.Color().g, _BaseRender.Color().b));
	_Brush = CreateSolidBrush(RGB(_BaseRender.Color().r, _BaseRender.Color().g, _BaseRender.Color().b));

	SelectObject(_GdiWindow->_MainWindow._HDC, _Pen);
}

LDL_GdiRender::~LDL_GdiRender()
{
	DeleteObject(_Pen);
	DeleteObject(_Brush);
}

void LDL_GdiRender::SetColor(const LDL_Color& color)
{
	if (!_BaseRender.Color().Equal(color))
	{
		DeleteObject(_Pen);
		_Pen = CreatePen(PS_SOLID, 1, RGB(color.r, color.g, color.b));
		SelectObject(_GdiWindow->_MainWindow._HDC, _Pen);

		DeleteObject(_Brush);
		_Brush = CreateSolidBrush(RGB(color.r, color.g, color.b));
	}

	_BaseRender.SetColor(color);
}

void LDL_GdiRender::Line(const LDL_Point2u& first, const LDL_Point2u& last)
{
	POINT point;

	MoveToEx(_GdiWindow->_MainWindow._HDC, first.x, first.y, &point);
	LineTo(_GdiWindow->_MainWindow._HDC, last.x, last.y);
}

void LDL_GdiRender::Fill(const LDL_Point2u& pos, const LDL_Point2u& size)
{
	RECT rect;

	rect.left   = pos.x;
	rect.top    = pos.y;
	rect.right  = pos.x + size.x;
	rect.bottom = pos.y + size.y;

	FillRect(_GdiWindow->_MainWindow._HDC, &rect, _Brush);
}

void LDL_GdiRender::Clear()
{
}

void LDL_GdiRender::Begin()
{
	_GdiWindow->_MainWindow._HDC = BeginPaint(_GdiWindow->_MainWindow._HWND, &_PaintStruct);
}

void LDL_GdiRender::End()
{
	EndPaint(_GdiWindow->_MainWindow._HWND, &_PaintStruct);
}

void LDL_GdiRender::Draw(LDL_Surface& surface, const LDL_Point2u& pos)
{
}
