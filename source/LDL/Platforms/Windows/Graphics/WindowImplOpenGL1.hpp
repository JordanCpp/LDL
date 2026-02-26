// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_OpenGL1_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL1_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/APIs/OpenGL/OpenGLLoader.hpp>
#include <LDL/Shared/Graphics/Impls/WindowImpl.hpp>
#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>

namespace LDL
{
	class WindowImplOpenGL1 : public WindowImpl
	{
	public:
		WindowImplOpenGL1(Result& result, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode = WindowMode::Resized);
		~WindowImplOpenGL1();
		bool Running();
		void Present();
		void PollEvents();
		bool GetEvent(Event& event);
		bool WaitEvent(Event& event);
		void StopEvent();
		void Title(const std::string& title);
		const std::string& Title();
		const Vec2u& Size();
		const Vec2u& Pos();
		void* NativeHandle();
	private:
		Result&       _result;
		HGLRC         _context;
		MainWindow    _mainWindow;
		OpenGLLoader  _loader;
	};
}

#endif  
