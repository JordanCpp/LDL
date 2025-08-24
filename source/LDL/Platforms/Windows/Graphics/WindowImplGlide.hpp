// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_WindowImplGlide_hpp
#define LDL_Platforms_Windows_Graphics_WindowImplGlide_hpp

#include "MainWindow.hpp"
#include "../../WindowImpl.hpp"
#include <LDL/Graphics/Window.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImplGlide : public WindowImpl
		{
		public:
			WindowImplGlide(Core::Result& result, const Math::Vec2u& pos, const Math::Vec2u& size, const char* title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImplGlide();
			bool Running();
			void Present();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const char* title);
			const char* Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			void* NativeHandle();
		private:
			Core::Result& _result;
			MainWindow    _Window;
		};
	}
}

#endif  
