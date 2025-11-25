// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Window_hpp
#define LDL_Window_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/Result.hpp>
#include <LDL/Events.hpp>
#include <LDL/Context.hpp>

class LDL_IWindow
{
public:
	virtual ~LDL_IWindow() {};
	virtual bool Running() = 0;
	virtual void Present() = 0;
	virtual void PollEvents() = 0;
	virtual bool GetEvent(LDL_Event& event) = 0;
	virtual bool WaitEvent(LDL_Event& event) = 0;
	virtual void StopEvent() = 0;
	virtual void Title(const char* title) = 0;
	virtual const char* Title() = 0;
	virtual const LDL_Vec2u& Size() = 0;
	virtual const LDL_Vec2u& Pos() = 0;
	virtual void* NativeHandle() = 0;
};

LDL_IWindow* LDL_CreateWindow(LDL_Result& result, LDL_RenderContext& renderContext, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode);

#endif
