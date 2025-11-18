// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Graphics/TextureImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/TextureImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Software/TextureImplSoftware.hpp>

using namespace LDL;

ITexture* LDL::CreateTextureImpl(RenderContext* renderContext, size_t pixelFormat, const Vec2u& size, uint8_t* pixels)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	ITexture* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new TextureImplSoftware(renderContext, pixelFormat, size, pixels);
		break;
	case RenderMode::OpenGL1:
		result = new TextureImplOpenGL1(renderContext, pixelFormat, size, pixels);
		break;
	case RenderMode::OpenGL3:
		result = new TextureImplOpenGL3(renderContext, pixelFormat, size, pixels);
		break;
	}

	return result;
}

ITexture* LDL::CreateTextureImpl(RenderContext* renderContext, size_t pixelFormat, const Vec2u& size)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	ITexture* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new TextureImplSoftware(renderContext, pixelFormat, size);
		break;
	case RenderMode::OpenGL1:
		result = new TextureImplOpenGL1(renderContext, pixelFormat, size);
		break;
	case RenderMode::OpenGL3:
		result = new  TextureImplOpenGL3(renderContext, pixelFormat, size);
		break;
	}

	return result;
}

ITexture* LDL::CreateTextureImpl(RenderContext* renderContext, Surface* surface)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	ITexture* result = NULL;

	switch (mode)
	{
	case RenderMode::OpenGL1:
		result = new TextureImplOpenGL1(renderContext, surface);
	}

	return result;
}
