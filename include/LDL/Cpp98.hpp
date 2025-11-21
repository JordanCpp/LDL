// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Cpp98_hpp
#define LDL_Cpp98_hpp

#include <LDL/LDL.hpp>

namespace LDL
{
	class Result : public LDL_Result
	{
	public:
	private:
	};

	class Vec2u: public LDL_Vec2u
	{
	public:
		Vec2u();
		Vec2u(uint32_t x, uint32_t);
	};

	class RenderContext : public LDL_RenderContext
	{
	public:
	private:
	};

	class Window
	{
	public:
		Window(Result& result, RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode);
		~Window();
		bool Running();
		void Present();
		void PollEvents();
		bool GetEvent(LDL_Event& event);
		bool WaitEvent(LDL_Event& event);
		void StopEvent();
		void Title(const char* title);
		const char* Title();
		const Vec2u& Size();
		const Vec2u& Pos();
		void* NativeHandle();
	private:
		Vec2u        _vec;
		LDL_IWindow* _window;
	};
}

#endif
