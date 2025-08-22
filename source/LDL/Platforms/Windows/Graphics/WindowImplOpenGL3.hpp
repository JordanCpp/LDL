// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_OpenGL3_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL3_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/APIs/OpenGL/OpenGLLoader.hpp>
#include "MainWindow.hpp"
#include "../../WindowImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class WindowImplOpenGL3 : public WindowImpl
		{
		public:
			WindowImplOpenGL3(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImplOpenGL3();
			bool Running();
			void PollEvents();
			void Present();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			void* NativeHandle();
		private:
			MainWindow _Window;
			HGLRC _HGLRC;
			OpenGLLoader _OpenGLLoader;
		};
	}
}

#endif  
