// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Enums.hpp>
#include <LDL/Assert.hpp>
#include <LDL/Render.hpp>
#include <LDL/Format.hpp>

#if defined(LDL_WINDOWS_NT) || defined(LDL_WINDOWS_9X) || defined(__unix__)
    #include <LDL/OpenGL/GLLoader.hpp>
    #include <LDL/Renders/GL1/RndrGL1.hpp>
    #include <LDL/Renders/GL3/RndrGL3.hpp>
    #include <LDL/Renders/Soft/RndrSoft.hpp>
#else
    #include <LDL/Renders/Soft/RndrSoft.hpp>
#endif

LDL_IRender* LDL_CreateRender(LDL_Result& result, LDL_RenderContext& renderContext, LDL_IWindow* window)
{
	size_t mode = renderContext.Mode();

	if (mode >= LDL_RenderMode::Max)
	{
		LDL_Formatter formatter;

		result.Message(formatter.Format("Unknown graphics mode: %d\n", mode));
		return NULL;
	}

	LDL_IRender* impl = NULL;

	switch (mode)
	{
	case LDL_RenderMode::Software:
		impl = new RenderImplSoftware(result, &renderContext, window);
		break;

#if defined(LDL_WINDOWS_NT) || defined(LDL_WINDOWS_9X) || defined(__unix__)
	case LDL_RenderMode::OpenGL1:
	{
		OpenGLLoader loader(result);
		loader.Init(1, 1);

		impl = new RenderImplOpenGL1(result, &renderContext, window);
		break;
	}
	case LDL_RenderMode::OpenGL3:
	{
		OpenGLLoader loader(result);
		loader.Init(3, 3);

		impl = new RenderImplOpenGL3(result, &renderContext, window);
		break;
	}
#endif

	}

	return impl;
}
