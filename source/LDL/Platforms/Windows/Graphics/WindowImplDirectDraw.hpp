// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_DirectDraw_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_DirectDraw_WindowImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/Platforms/WindowImpl.hpp>
#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>
#include <LDL/Platforms/Windows/DirectX/DirectDraw.hpp>

namespace LDL
{
	class WindowImplDirectDraw : public WindowImpl
	{
	public:
		WindowImplDirectDraw(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode = WindowMode::Resized);
		~WindowImplDirectDraw();
		bool Running();
		void Present();
		void PollEvents();
		bool GetEvent(Event& event);
		bool WaitEvent(Event& event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const Vec2u& Size();
		const Vec2u& Pos();
		void* NativeHandle();
	private:
		IDirectDraw*        _directDraw;
		IDirectDrawSurface* _primary;
		IDirectDrawSurface* _screen;
		IDirectDrawClipper* _clipper;
		Result&             _result;
		MainWindow          _window;
	};
}

#endif  
