// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Linux_WinSoft_hpp
#define LDL_Linux_WinSoft_hpp

#include <LDL/Window.hpp>
#include <LDL/Linux/MainWin.hpp>

class LDL_WindowSoftware : public LDL_IWindow
{
public:
	LDL_WindowSoftware(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode = LDL_WindowMode::Resized);
	~LDL_WindowSoftware();
	void Present(uint8_t* pixels, uint8_t bytesPerPixel);
	void Present();
	bool Running();
	void PollEvents();
	bool GetEvent(LDL_Event& event);
	bool WaitEvent(LDL_Event& event);
	void StopEvent();
	void Title(const char* title);
	const char* Title();
	const LDL_Vec2u& Size();
	const LDL_Vec2u& Pos();
	void* NativeHandle();
private:
	LDL_MainWindow _Window;
};

#endif
