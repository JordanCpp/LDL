// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Format.hpp>
#include <LDL/Window.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/WinSoft.hpp>
    #include <LDL/WinNT/WinGL1.hpp>
    #include <LDL/WinNT/WinGL3.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/Graphics/WindowImplSoftware.hpp>
    #include <LDL/Win9X/Graphics/WindowImplOpenGL1.hpp>
    #include <LDL/Win9X/Graphics/WindowImplOpenGL3.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/Graphics/Software/WindowImplSoftware.hpp>
    #include <LDL/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp>
    #include <LDL/Linux/Graphics/OpenGL3/WindowImplOpenGL3.hpp>
#endif

LDL_IWindow* LDL_CreateWindow(LDL_Result& result, LDL_RenderContext& renderContext, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode)
{
	size_t renderMode = renderContext.Mode();

	if (mode >= LDL_RenderMode::Max)
	{
		LDL_Formatter formatter;

		result.Message(formatter.Format("Unknown graphics mode: %d\n", mode));
		return NULL;
	}

	LDL_IWindow* impl = NULL;

	switch (renderMode)
	{
	case LDL_RenderMode::Software:
		impl = new WindowImplSoftware(result, pos, size, title, mode);
		break;
	case LDL_RenderMode::OpenGL1:
		impl = new WindowImplOpenGL1(result, pos, size, title, mode);
		break;
	case LDL_RenderMode::OpenGL3:
		impl = new WindowImplOpenGL3(result, pos, size, title, mode);
		break;
	}

	return impl;
}
