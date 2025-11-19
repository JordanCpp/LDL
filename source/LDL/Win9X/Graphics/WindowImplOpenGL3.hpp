// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_OpenGL3_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL3_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/Shared/Graphics/Impls/WindowImpl.hpp>
#include <LDL/Platforms/Win9X/Graphics/MainWindow.hpp>

namespace LDL
{
	class LDL_WindowOpenGL3 : public WindowImpl
	{
	public:
		LDL_WindowOpenGL3(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode = LDL_WindowMode::Resized);
		~LDL_WindowOpenGL3();
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
		LDL_MainWindow   _mainWindow;
		HGLRC        _hglrc;
	};
}

#endif  
