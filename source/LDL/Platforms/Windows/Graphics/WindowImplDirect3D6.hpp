// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_WindowImplDirect3D6_hpp
#define LDL_Platforms_Windows_Graphics_WindowImplDirect3D6_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/Shared/Graphics/Impls/WindowImpl.hpp>
#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>

namespace LDL
{
	class WindowImplDirect3D6 : public WindowImpl
	{
	public:
		WindowImplDirect3D6(Result& result, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode = WindowMode::Resized);
		~WindowImplDirect3D6();
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
		Result&     _result;
		MainWindow  _mainWindow;
	};
}

#endif
