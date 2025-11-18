// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/APIs/OpenGL/OpenGL_Loader.hpp>
#include <LDL/Graphics/RenderCreator.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/RenderImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/RenderImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Software/RenderImplSoftware.hpp>
#include <LDL/Core/Formatter.hpp>

using namespace LDL;

IRender* LDL::CreateRenderImpl(Result& result, RenderContext& renderContext, IWindow* window)
{
	size_t mode = renderContext.Mode();

	if (mode >= RenderMode::Max)
	{
		Formatter formatter;

		result.Message(formatter.Format("Unknown graphics mode: %d\n", mode));
		return NULL;
	}

	IRender* impl = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		impl = new RenderImplSoftware(result, &renderContext, window);
		break;
	case RenderMode::OpenGL1:
	{
		OpenGLLoader loader(result);
		loader.Init(1, 1);

		impl = new RenderImplOpenGL1(result, &renderContext, window);
		break;
	}
	case RenderMode::OpenGL3:
	{
		OpenGLLoader loader(result);
		loader.Init(3, 3);

		impl = new RenderImplOpenGL3(result, &renderContext, window);
		break;
	}
	}

	return impl;
}
