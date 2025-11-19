// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_MainWindow_hpp
#define LDL_Platforms_Windows_Graphics_MainWindow_hpp

#include <LDL/Core/Result.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Shared/Events/Eventer.hpp>
#include <LDL/Platforms/Win9X/WinError.hpp>
#include <LDL/Platforms/Win9X/Windows.hpp>
#include <LDL/Shared/Graphics/Base/BaseWindow.hpp>
#include <LDL/Platforms/Win9X/Input/KeyMapper.hpp>

namespace LDL
{
	class MainWindow
	{
	public:
		MainWindow(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode);
		~MainWindow();
		bool Running();
		void PollEvents();
		bool GetEvent(LDL_Event& event);
		bool WaitEvent(LDL_Event& event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const LDL_Vec2u& Size();
		const LDL_Vec2u& Pos();
	private:
		uint8_t ConvertKey(size_t key);
		static LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam);
		LRESULT CALLBACK Handler(UINT Message, WPARAM WParam, LPARAM LParam);
		KeyMapper       _keyMapper;
		WindowError     _windowError;
		LDL_BaseWindow      _baseWindow;
		LDL_Result&         _result;
		LDL_Eventer         _eventer;
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
