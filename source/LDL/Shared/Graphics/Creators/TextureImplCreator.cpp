// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Shared/Graphics/Creators/TextureImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/Software/TextureImplSoftware.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/TextureImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Glide/TextureImplGlide.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

TextureImpl* TextureImplCreator::Create(RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new TextureImplSoftware(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	case RenderMode::OpenGL1:
		result = new TextureImplOpenGL1(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	case RenderMode::OpenGL3:
		result = new TextureImplOpenGL3(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	case RenderMode::Glide:
		result = new TextureImplGlide(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	}

	return result;
}

TextureImpl* TextureImplCreator::Create(RenderContext* renderContext, const Vec2u& size, uint8_t bytesPerPixel)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new TextureImplSoftware(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	case RenderMode::OpenGL1:
		result = new TextureImplOpenGL1(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	case RenderMode::OpenGL3:
		result = new TextureImplOpenGL3(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	}

	return result;
}
