// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Linux_Graphics_MainWindow_hpp
#define LDL_Platforms_Linux_Graphics_MainWindow_hpp

#include <LDL/Shared/Graphics/Base/BaseWindow.hpp>
#include <LDL/Shared/Events/Eventer.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_1.hpp>

#include "GLX.hpp"

namespace LDL
{
	namespace Graphics
	{
		class MainWindow
		{
		public:
			MainWindow(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode);
			~MainWindow();
			bool Running();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			void Show();
		private:
			BaseWindow _BaseWindow;
			size_t ConvertKey(size_t key);
			LDL::Events::Eventer _Eventer;
		public:
			Display* _Display;
			int      _Screen;
			Window   _Root;
			Window   _Window;
			size_t   _EventMask;
		};
	}
}

#endif   
