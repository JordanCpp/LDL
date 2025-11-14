// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_MainWindow_hpp
#define LDL_Platforms_Windows_Graphics_MainWindow_hpp

#include <LDL/Core/Result.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Shared/Events/Eventer.hpp>
#include <LDL/Platforms/Windows/WinError.hpp>
#include <LDL/Platforms/Windows/Windows.hpp>
#include <LDL/Shared/Graphics/Base/BaseWindow.hpp>
#include <LDL/Platforms/Windows/Input/KeyMapper.hpp>

namespace LDL
{
	class MainWindow
	{
	public:
		MainWindow(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode);
		~MainWindow();
		bool Running();
		void PollEvents();
		bool GetEvent(Event& event);
		bool WaitEvent(Event& event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const Vec2u& Size();
		const Vec2u& Pos();
	private:
		uint8_t ConvertKey(size_t key);
		static LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam);
		LRESULT CALLBACK Handler(UINT Message, WPARAM WParam, LPARAM LParam);
		KeyMapper       _keyMapper;
		WindowError     _windowError;
		BaseWindow      _baseWindow;
		Result&         _result;
		Eventer         _eventer;
		WNDCLASS        _windowClass;
		HINSTANCE       _instance;
		MSG             _msg;
		ATOM            _atom;
	public:
		HWND            _hwnd;
		HDC             _hdc;
	};
}

#endif   
