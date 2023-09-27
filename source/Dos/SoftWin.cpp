#include "SoftWin.hpp"
#include <LDL/Low/Errors.hpp>
#include <dos.h>

LDL_SoftWindow::LDL_SoftWindow(LDL_IRenderContext* context, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title) :
	_BaseWindow(pos, size, title),
	_Context(context)
{
	if (_BaseWindow.Size().x != 320 && _BaseWindow.Size().y != 200)
	{
		LDL_AddError("Window resolution not support");
	}

	InitMouse();
}

LDL_SoftWindow::~LDL_SoftWindow()
{
	union REGS regs;

	regs.h.ah = 0x00;
	regs.h.al = 0x03;

	int86(0x10, &regs, &regs);
}

bool LDL_SoftWindow::Running()
{
	return _Eventer.Running();
}

void LDL_SoftWindow::Present()
{
}

void LDL_SoftWindow::PollEvents()
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

bool LDL_SoftWindow::GetEvent(LDL_Event& event)
{
	if (!_Eventer.Empty())
	{
		_Eventer.Pop(event);

		return true;
	}

	return false;
}

bool LDL_SoftWindow::WaitEvent(LDL_Event& event)
{
	return false;
}

void LDL_SoftWindow::StopEvent()
{
}

void LDL_SoftWindow::Title(const char* title)
{
	_BaseWindow.Title(title);
}

const char* LDL_SoftWindow::Title()
{
	return _BaseWindow.Title();
}

const LDL_Vec2u& LDL_SoftWindow::Size()
{
	return _BaseWindow.Size();
}

const LDL_Vec2u& LDL_SoftWindow::Pos()
{
	return _BaseWindow.Pos();
}

bool LDL_SoftWindow::InitMouse()
{
	union REGS regs;

	regs.x.ax = 0;

	int86(0x33, &regs, &regs);

	bool result = regs.x.ax;

	if (!result)
	{
		LDL_AddError("Mouse not found!");
		return false;
	}

	return true;
}

bool LDL_SoftWindow::MousePress(size_t button)
{
	union REGS regs;

	regs.x.ax = 0x05;
	regs.x.bx = button;

	int86(0x33, &regs, &regs);

	return regs.x.bx;
}
