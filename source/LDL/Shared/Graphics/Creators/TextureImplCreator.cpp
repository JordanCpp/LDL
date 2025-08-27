// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "TextureImplCreator.hpp"

#include "../Renders/Software/TextureImplSoftware.hpp"
#include "../Renders/OpenGL1/TextureImplOpenGL1.hpp"
#include "../Renders/OpenGL3/TextureImplOpenGL3.hpp"

#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Core/Assert.hpp>

using namespace LDL;

TextureImpl* TextureImplCreator::Create(uint8_t* memory, RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new(memory) TextureImplSoftware(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	case RenderMode::OpenGL1:
		result = new(memory) TextureImplOpenGL1(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	case RenderMode::OpenGL3:
		result = new(memory) TextureImplOpenGL3(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	}

	return result;
}

TextureImpl* TextureImplCreator::Create(uint8_t* memory, RenderContext* renderContext, const Vec2u& size, uint8_t bytesPerPixel)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new(memory) TextureImplSoftware(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	case RenderMode::OpenGL1:
		result = new(memory) TextureImplOpenGL1(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	case RenderMode::OpenGL3:
		result = new(memory) TextureImplOpenGL3(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
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
