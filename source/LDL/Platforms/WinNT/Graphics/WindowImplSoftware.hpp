// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_Software_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_Software_WindowImpl_hpp

#include <LDL/Shared/Graphics/Impls/WindowImpl.hpp>
#include <LDL/Platforms/WinNT/Graphics/MainWindow.hpp>

namespace LDL
{
	class WindowImplSoftware : public WindowImpl
	{
	public:
		WindowImplSoftware(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode = WindowMode::Resized);
		~WindowImplSoftware();
		void Present(uint8_t* pixels, uint8_t bytesPerPixel);
		void Present();
		bool Running();
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
		Result&    _result;
		MainWindow _mainWindow;
		BITMAPINFO _bitmapInfo;
	};
}

#endif    
