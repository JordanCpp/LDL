// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_Graphics_MainWindow_hpp
#define LDL_Platforms_WinNT_Graphics_MainWindow_hpp

#include <LDL/Result.hpp>
#include <LDL/Eventer.hpp>
#include <LDL/BaseWin.hpp>

class LDL_MainWindow
{
public:
	LDL_MainWindow(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode);
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
private:
	LDL_Result&    _result;
	LDL_BaseWindow _baseWindow;
	LDL_Eventer    _eventer;
};

#endif   
