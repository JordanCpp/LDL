// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Format.hpp>
#include <LDL/Window.hpp>
#include <LDL/WinNT/WinSoft.hpp>
#include <LDL/WinNT/WinGL1.hpp>
#include <LDL/WinNT/WinGL3.hpp>

LDL_IWindow* LDL_CreateWindow(LDL_Result& result, LDL_RenderContext& renderContext, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode)
{
	size_t renderMode = renderContext.Mode();

	if (renderMode >= LDL_RenderMode::Max)
	{
		LDL_Formatter formatter;

		result.Message(formatter.Format("Unknown graphics mode: %d\n", renderMode));
		return NULL;
	}

	LDL_IWindow* impl = NULL;

	switch (renderMode)
	{
	case LDL_RenderMode::Software:
		impl = new LDL_WindowSoftware(result, pos, size, title, mode);
		break;
	case LDL_RenderMode::OpenGL1:
		impl = new LDL_WindowOpenGL1(result, pos, size, title, mode);
		break;
	case LDL_RenderMode::OpenGL3:
		impl = new LDL_WindowOpenGL3(result, pos, size, title, mode);
		break;
	}

	return impl;
}
