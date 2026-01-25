// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Enums.hpp>
#include <LDL/Assert.hpp>
#include <LDL/Render.hpp>
#include <LDL/Format.hpp>
#include <LDL/OpenGL/GLLoader.hpp>
#include <LDL/Renders/GL1/RndrGL1.hpp>
#include <LDL/Renders/GL3/RndrGL3.hpp>
#include <LDL/Renders/Soft/RndrSoft.hpp>

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
		impl = new LDL_RenderSoftware(result, &renderContext, window);
		break;
	case LDL_RenderMode::OpenGL1:
	{
		LDL_OpenGLLoader loader(result);
		loader.Init(1, 1);

		impl = new LDL_RenderOpenGL1(result, &renderContext, window);
		break;
	}
	case LDL_RenderMode::OpenGL3:
	{
		LDL_OpenGLLoader loader(result);
		loader.Init(3, 3);

		impl = new LDL_RenderOpenGL3(result, &renderContext, window);
		break;
	}
	}

	return impl;
}
