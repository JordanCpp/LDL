// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_Graphics_OpenGL1_WindowImpl_hpp
#define LDL_Platforms_WinNT_Graphics_OpenGL1_WindowImpl_hpp

#include <LDL/Window.hpp>
#include <LDL/WinNT/Windows.hpp>
#include <LDL/WinNT/MainWin.hpp>

namespace LDL
{
	class WindowImplOpenGL1 : public LDL_IWindow
	{
	public:
		WindowImplOpenGL1(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode = LDL_WindowMode::Resized);
		~WindowImplOpenGL1();
		bool Running();
		void Present();
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
		LDL_Result&     _result;
		HGLRC       _hglrc;
		MainWindow  _window;
	};
}

#endif  
