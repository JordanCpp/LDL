#include "SoftWin.hpp"
#include <dos.h>

LDL_SoftWin::LDL_SoftWin(LDL_ErrorHandler* errorHandler, LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title) :
	_ErrorHandler(errorHandler),
	_BaseWindow(pos, size, title),
	_Context(context)
{
	if (_BaseWindow.Size().x != 320 && _BaseWindow.Size().y != 200)
	{
		_ErrorHandler->Message("Window resolution not support");
	}

	InitMouse();
}

LDL_SoftWin::~LDL_SoftWin()
{
	union REGS regs;

	regs.h.ah = 0x00;
	regs.h.al = 0x03;

	int86(0x10, &regs, &regs);
}

bool LDL_SoftWin::Running()
{
	return _Eventer.Running();
}

void LDL_SoftWin::Present()
{
}

void LDL_SoftWin::PollEvents()
{
	LDL_Event event;

	if (MousePress(0x00))
	{
		event.Type = LDL_Events::IsMouseClick;
		event.Mouse.State = LDL_ButtonState::Pressed;
		event.Mouse.Button = LDL_MouseButton::Left;
		event.Mouse.PosX = 0;
		event.Mouse.PosY = 0;

		_Eventer.Push(event);
	}

	if (MousePress(0x01))
	{
		event.Type = LDL_Events::IsMouseClick;
		event.Mouse.State = LDL_ButtonState::Pressed;
		event.Mouse.Button = LDL_MouseButton::Right;
		event.Mouse.PosX = 0;
		event.Mouse.PosY = 0;

		_Eventer.Push(event);
	}

	if (MousePress(0x02))
	{
		event.Type = LDL_Events::IsMouseClick;
		event.Mouse.State = LDL_ButtonState::Pressed;
		event.Mouse.Button = LDL_MouseButton::Middle;
		event.Mouse.PosX = 0;
		event.Mouse.PosY = 0;

		_Eventer.Push(event);
	}
}

bool LDL_SoftWin::GetEvent(LDL_Event& event)
{
	if (!_Eventer.Empty())
	{
		_Eventer.Pop(event);

		return true;
	}

	return false;
}

bool LDL_SoftWin::WaitEvent(LDL_Event& event)
{
	return false;
}

void LDL_SoftWin::StopEvent()
{
}

void LDL_SoftWin::Title(const char* title)
{
	_BaseWindow.Title(title);
}

const char* LDL_SoftWin::Title()
{
	return _BaseWindow.Title();
}

const LDL_Point2u& LDL_SoftWin::Size()
{
	return _BaseWindow.Size();
}

const LDL_Point2u& LDL_SoftWin::Pos()
{
	return _BaseWindow.Pos();
}

bool LDL_SoftWin::InitMouse()
{
	union REGS regs;

	regs.x.ax = 0;

	int86(0x33, &regs, &regs);

	bool result = regs.x.ax;

	if (!result)
	{
		_ErrorHandler->Message("Mouse not found!");
	}

	return _ErrorHandler->Ok();
}

bool LDL_SoftWin::MousePress(size_t button)
{
	union REGS regs;

	regs.x.ax = 0x05;
	regs.x.bx = button;

	int86(0x33, &regs, &regs);

	return regs.x.bx;
}
