// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/APIs/OpenGL/OpenGL_Loader.hpp>
#include <LDL/Shared/Graphics/Creators/RenderImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/RenderImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/RenderImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Software/RenderImplSoftware.hpp>

using namespace LDL;

RenderImpl* RenderImplCreator::Create(uint8_t* memory, Result& result, RenderContext& renderContext, Window* window)
{
	size_t mode = renderContext.Mode();

	if (mode >= RenderMode::Max)
	{
		result.Message("Unknown graphics mode");
		return NULL;
	}

	RenderImpl* impl = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		impl = new(memory) RenderImplSoftware(result, renderContext.GetRenderContextImpl(), window);
		break;
	case RenderMode::OpenGL1:
	{
		OpenGLLoader loader;
		loader.Init(1, 1);

		impl = new(memory) RenderImplOpenGL1(result, renderContext.GetRenderContextImpl(), window);
		break;
	}
	case RenderMode::OpenGL3:
	{
		OpenGLLoader loader;
		loader.Init(3, 3);

		impl = new(memory) RenderImplOpenGL3(result, renderContext.GetRenderContextImpl(), window);
		break;
	}
	}

	return impl;
}
