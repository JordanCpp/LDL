// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Linux_Graphics_MainWindow_hpp
#define LDL_Platforms_Linux_Graphics_MainWindow_hpp

#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Shared/Events/Eventer.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_1.hpp>
#include <LDL/Platforms/Linux/Graphics/GLX.hpp>
#include <LDL/Shared/Graphics/Base/BaseWindow.hpp>

namespace LDL
{
	class MainWindow
	{
	public:
		MainWindow(const Vec2u &pos, const Vec2u &size, const char* title, size_t mode);
		~MainWindow();
		bool Running();
		void PollEvents();
		bool GetEvent(Event &event);
		bool WaitEvent(Event &event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const Vec2u &Size();
		const Vec2u &Pos();
		void Show();
	private:
		BaseWindow _BaseWindow;
		size_t ConvertKey(size_t key);
		Eventer _Eventer;
	public:
		Display *_Display;
		int      _Screen;
		Window   _Root;
		Window   _Window;
		size_t   _EventMask;
	};
}

#endif
