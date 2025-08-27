// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WindowImpl_hpp
#define LDL_Platforms_WindowImpl_hpp

#include <LDL/Events/Event.hpp>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	class WindowImpl
	{
	public:
		virtual ~WindowImpl() {};
		virtual bool Running() = 0;
		virtual void Present() = 0;
		virtual void PollEvents() = 0;
		virtual bool GetEvent(Event& event) = 0;
		virtual bool WaitEvent(Event& event) = 0;
		virtual void StopEvent() = 0;
		virtual void Title(const char* title) = 0;
		virtual const char* Title() = 0;
		virtual const Vec2u& Size() = 0;
		virtual const Vec2u& Pos() = 0;
		virtual void* NativeHandle() = 0;
	private:
	};
}

#endif   
