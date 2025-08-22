// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_WindowImplDirect3D6_hpp
#define LDL_Platforms_Windows_Graphics_WindowImplDirect3D6_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/Platforms/WindowImpl.hpp>
#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImplDirect3D6 : public WindowImpl
		{
		public:
			WindowImplDirect3D6(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = Enums::WindowMode::Resized);
			~WindowImplDirect3D6();
			bool Running();
			void Present();
			void PollEvents();
			bool GetEvent(Events::Event& event);
			bool WaitEvent(Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
			void* NativeHandle();
		private:
			MainWindow _Window;
		};
	}
}

#endif
