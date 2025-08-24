// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Window_hpp
#define LDL_Graphics_Window_hpp

#include <string>
#include <LDL/Events/Event.hpp>
#include <LDL/Math/Vec2.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Core/Result.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl;

		class LDL_LIBRARY Window
		{
		public:
			Window(Core::Result& result, RenderContext& renderContext, const Math::Vec2u& pos, const Math::Vec2u& size, const char* title, size_t mode = Enums::WindowMode::Resized);
			~Window();
			bool Running();
			void PollEvents();
			bool GetEvent(Events::Event& event);
			bool WaitEvent(Events::Event& event);
			void StopEvent();
			void Title(const char* title);
			const char* Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			WindowImpl* GetWindowImpl();
			void* NativeHandle();
		private:
			WindowImpl* _impl;
		};
	}
}

#endif 
