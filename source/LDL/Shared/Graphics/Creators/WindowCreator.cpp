// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Core/Formatter.hpp>
#include <LDL/Graphics/WindowImplCreator.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/Graphics/WindowImplSoftware.hpp>
    #include <LDL/WinNT/Graphics/WindowImplOpenGL1.hpp>
    #include <LDL/WinNT/Graphics/WindowImplOpenGL3.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/Graphics/WindowImplSoftware.hpp>
    #include <LDL/Win9X/Graphics/WindowImplOpenGL1.hpp>
    #include <LDL/Win9X/Graphics/WindowImplOpenGL3.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/Graphics/Software/WindowImplSoftware.hpp>
    #include <LDL/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp>
    #include <LDL/Linux/Graphics/OpenGL3/WindowImplOpenGL3.hpp>
#endif

using namespace LDL;

IWindow* LDL::CreateWindowImpl(Result& result, RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode)
{
	size_t renderMode = renderContext.Mode();

	if (mode >= RenderMode::Max)
	{
		Formatter formatter;

		result.Message(formatter.Format("Unknown graphics mode: %d\n", mode));
		return NULL;
	}

	IWindow* impl = NULL;

	switch (renderMode)
	{
	case RenderMode::Software:
		impl = new WindowImplSoftware(result, pos, size, title, mode);
		break;
	case RenderMode::OpenGL1:
		impl = new WindowImplOpenGL1(result, pos, size, title, mode);
		break;
	case RenderMode::OpenGL3:
		impl = new WindowImplOpenGL3(result, pos, size, title, mode);
		break;
	}

	return impl;
}
