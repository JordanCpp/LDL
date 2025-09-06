// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_OpenGL3_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL3_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/APIs/OpenGL/OpenGL_Loader.hpp>
#include <LDL/Shared/Graphics/Impls/WindowImpl.hpp>
#include  <LDL/Platforms/Windows/Graphics/MainWindow.hpp>

namespace LDL
{
	class WindowImplOpenGL3 : public WindowImpl
	{
	public:
		WindowImplOpenGL3(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode = WindowMode::Resized);
		~WindowImplOpenGL3();
		bool Running();
		void PollEvents();
		void Present();
		bool GetEvent(Event& event);
		bool WaitEvent(Event& event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const Vec2u& Size();
		const Vec2u& Pos();
		void* NativeHandle();
	private:
		Result&       _result;
		MainWindow    _mainWindow;
		HGLRC         _hglrc;
		OpenGLLoader  _OpenGLLoader;
	};
}

#endif  
