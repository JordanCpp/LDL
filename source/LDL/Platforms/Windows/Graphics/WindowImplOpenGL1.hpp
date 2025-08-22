// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_OpenGL1_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL1_WindowImpl_hpp

#include "MainWindow.hpp"
#include "../../WindowImpl.hpp"
#include <LDL/Graphics/Window.hpp>
#include <LDL/APIs/OpenGL/OpenGLLoader.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImplOpenGL1: public WindowImpl
		{
		public:
			WindowImplOpenGL1(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImplOpenGL1();
			bool Running();
			void Present();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			void* NativeHandle();
		private:
			HGLRC _HGLRC;
			MainWindow _Window;
			OpenGLLoader _OpenGLLoader;
		};
	}
}

#endif  
