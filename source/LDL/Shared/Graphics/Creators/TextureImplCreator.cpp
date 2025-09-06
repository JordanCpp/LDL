// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Shared/Graphics/Creators/TextureImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/TextureImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Software/TextureImplSoftware.hpp>

using namespace LDL;

TextureImpl* TextureImplCreator::Create(uint8_t* memory, RenderContext* renderContext, size_t pixelFormat, const Vec2u& size, uint8_t* pixels)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new(memory) TextureImplSoftware(renderContext->GetRenderContextImpl(), pixelFormat, size, pixels);
		break;
	case RenderMode::OpenGL1:
		result = new(memory) TextureImplOpenGL1(renderContext->GetRenderContextImpl(), pixelFormat, size, pixels);
		break;
	case RenderMode::OpenGL3:
		result = new(memory) TextureImplOpenGL3(renderContext->GetRenderContextImpl(), pixelFormat, size, pixels);
		break;
	}

	return result;
}

TextureImpl* TextureImplCreator::Create(uint8_t* memory, RenderContext* renderContext, size_t pixelFormat, const Vec2u& size)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new(memory) TextureImplSoftware(renderContext->GetRenderContextImpl(), pixelFormat, size);
		break;
	case RenderMode::OpenGL1:
		result = new(memory) TextureImplOpenGL1(renderContext->GetRenderContextImpl(), pixelFormat, size);
		break;
	case RenderMode::OpenGL3:
		result = new(memory) TextureImplOpenGL3(renderContext->GetRenderContextImpl(), pixelFormat, size);
		break;
	}

	return result;
}

TextureImpl* TextureImplCreator::Create(uint8_t* memory, RenderContext* renderContext, Surface* surface)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::OpenGL1:
		result = new(memory) TextureImplOpenGL1(renderContext->GetRenderContextImpl(), surface);
	}

	return result;
}
