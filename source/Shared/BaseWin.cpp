#include <LDL/Low/BaseWin.hpp>

LDL_BaseWindow::LDL_BaseWindow(const LDL_Point2u& pos, const LDL_Point2u& size, const char* title) :
	_Pos(pos),
	_Size(size),
	_Title(title)
{
}

LDL_BaseWindow::~LDL_BaseWindow()
{
}

const LDL_Point2u& LDL_BaseWindow::Pos()
{
	return _Pos;
}

const LDL_Point2u& LDL_BaseWindow::Size()
{
	return _Size;
}

void LDL_BaseWindow::Size(const LDL_Point2u& size)
{
	_Size = size;
}

const char* LDL_BaseWindow::Title()
{
	return _Title.CStr();
}

void LDL_BaseWindow::Title(const char* source)
{
	_Title.Assign(source);
}
