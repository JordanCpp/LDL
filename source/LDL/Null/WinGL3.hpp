// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_Graphics_OpenGL3_WindowImpl_hpp
#define LDL_Platforms_WinNT_Graphics_OpenGL3_WindowImpl_hpp

#include <LDL/Window.hpp>
#include <LDL/WinNT/MainWin.hpp>

namespace LDL
{
	class WindowImplOpenGL3 : public LDL_IWindow
	{
	public:
		WindowImplOpenGL3(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode = LDL_WindowMode::Resized);
		~WindowImplOpenGL3();
		bool Running();
		void PollEvents();
		void Present();
		bool GetEvent(LDL_Event& event);
		bool WaitEvent(LDL_Event& event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const LDL_Vec2u& Size();
		const LDL_Vec2u& Pos();
		void* NativeHandle();
	private:
		LDL_Result&      _result;
		MainWindow   _mainWindow;
		HGLRC        _hglrc;
	};
}

#endif  
