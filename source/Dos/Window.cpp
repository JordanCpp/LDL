#include "Window.hpp"
#include <dos.h>

LDL_ImpWindow::LDL_ImpWindow(LDL_ErrorHandler* errorHandler, LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title) :
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

LDL_ImpWindow::~LDL_ImpWindow()
{
	union REGS regs;

	regs.h.ah = 0x00;
	regs.h.al = 0x03;

	int86(0x10, &regs, &regs);
}

bool LDL_ImpWindow::Running()
{
	return _Eventer.Running();
}

void LDL_ImpWindow::Present()
{
}

void LDL_ImpWindow::PollEvents()
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

bool LDL_ImpWindow::GetEvent(LDL_Event& event)
{
	if (!_Eventer.Empty())
	{
		_Eventer.Pop(event);

		return true;
	}

	return false;
}

bool LDL_ImpWindow::WaitEvent(LDL_Event& event)
{
	return false;
}

void LDL_ImpWindow::StopEvent()
{
}

void LDL_ImpWindow::Title(const char* title)
{
	_BaseWindow.Title(title);
}

const char* LDL_ImpWindow::Title()
{
	return _BaseWindow.Title();
}

const LDL_Point2u& LDL_ImpWindow::Size()
{
	return _BaseWindow.Size();
}

const LDL_Point2u& LDL_ImpWindow::Pos()
{
	return _BaseWindow.Pos();
}

bool LDL_ImpWindow::InitMouse()
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

bool LDL_ImpWindow::MousePress(size_t button)
{
	union REGS regs;

	regs.x.ax = 0x05;
	regs.x.bx = button;

	int86(0x33, &regs, &regs);

	return regs.x.bx;
}
