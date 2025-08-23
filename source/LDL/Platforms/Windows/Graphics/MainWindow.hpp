// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_MainWindow_hpp
#define LDL_Platforms_Windows_Graphics_MainWindow_hpp

#include <LDL/Platforms/Windows/Windows.hpp>
#include <LDL/Shared/Graphics/Base/BaseWindow.hpp>
#include <LDL/Shared/Events/Eventer.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Core/Result.hpp>

namespace LDL
{
	namespace Graphics
	{
		class MainWindow
		{
		public:
			MainWindow(Core::Result& result, const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode);
			~MainWindow();
			bool Running();
			void PollEvents();
			bool GetEvent(Events::Event& event);
			bool WaitEvent(Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
		private:
			uint8_t ConvertKey(size_t key);
			static LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam);
			LRESULT CALLBACK Handler(UINT Message, WPARAM WParam, LPARAM LParam);
			BaseWindow      _baseWindow;
			Core::Result&   _result;
			Events::Eventer _eventer;
			WNDCLASS        _windowClass;
			HINSTANCE       _instance;
			MSG             _msg;
			ATOM            _atom;
		public:
			HWND            _hwnd;
			HDC             _hdc;
		};
	}
}

#endif   
