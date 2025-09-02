// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Window_hpp
#define LDL_Graphics_Window_hpp

#include <LDL/Math/Vec2u.hpp>
#include <LDL/Core/Result.hpp>
#include <LDL/Events/Event.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Graphics/RenderContext.hpp>

namespace LDL
{
	class WindowImpl;

	class LDL_LIBRARY Window
	{
	public:
		enum
		{
			SizeOf = 2048
		};
		Window(Result& result, RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode = WindowMode::Resized);
		~Window();
		bool Running();
		void PollEvents();
		bool GetEvent(Event& event);
		bool WaitEvent(Event& event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const Vec2u& Size();
		const Vec2u& Pos();
		WindowImpl* GetWindowImpl();
		void* NativeHandle();
	private:
		WindowImpl* _impl;
		uint8_t     _memory[SizeOf];
	};
}

#endif
