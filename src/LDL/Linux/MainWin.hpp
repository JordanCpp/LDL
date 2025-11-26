// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Linux_MainWin_hpp
#define LDL_Linux_MainWin_hpp

#include <LDL/Enums.hpp>
#include <LDL/Eventer.hpp>
#include <LDL/OpenGL/GL1_1.hpp>
#include <LDL/Linux/GLX.hpp>
#include <LDL/BaseWin.hpp>

class LDL_MainWindow
{
public:
	LDL_MainWindow(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode);
	~LDL_MainWindow();
	bool Running();
	void PollEvents();
	bool GetEvent(LDL_Event& event);
	bool WaitEvent(LDL_Event& event);
	void StopEvent();
	void Title(const char* title);
	const char* Title();
	const LDL_Vec2u& Size();
	const LDL_Vec2u& Pos();
	void Show();
private:
	LDL_BaseWindow _BaseWindow;
	size_t ConvertKey(size_t key);
	LDL_Eventer _Eventer;
public:
	Display* _Display;
	int      _Screen;
	Window   _Root;
	Window   _Window;
	size_t   _EventMask;
};

#endif
