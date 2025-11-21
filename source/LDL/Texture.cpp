// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Enums.hpp>
#include <LDL/Texture.hpp>

#if defined(LDL_WINDOWS_NT) || defined(LDL_WINDOWS_9X) || defined(__unix__)
    #include <LDL/Renders/GL1/TexGL1.hpp>
    #include <LDL/Renders/GL3/TexGL3.hpp>
    #include <LDL/Renders/Soft/TexSoft.hpp>
#else
    #include <LDL/Renders/Soft/TexSoft.hpp>
#endif

LDL_ITexture* LDL_CreateTexture(LDL_RenderContext* renderContext, size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < LDL_RenderMode::Max, "Unknown graphics mode");

	LDL_ITexture* result = NULL;

	switch (mode)
	{
	case LDL_RenderMode::Software:
		result = new TextureImplSoftware(renderContext, pixelFormat, size, pixels);
		break;

#if defined(LDL_WINDOWS_NT) || defined(LDL_WINDOWS_9X) || defined(__unix__)
	case LDL_RenderMode::OpenGL1:
		result = new LDL_TextureOpenGL1(renderContext, pixelFormat, size, pixels);
		break;
	case LDL_RenderMode::OpenGL3:
		result = new TextureImplOpenGL3(renderContext, pixelFormat, size, pixels);
		break;
#endif

	}

	return result;
}

LDL_ITexture* LDL_CreateTexture(LDL_RenderContext* renderContext, size_t pixelFormat, const LDL_Vec2u& size)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < LDL_RenderMode::Max, "Unknown graphics mode");

	LDL_ITexture* result = NULL;

	switch (mode)
	{
	case LDL_RenderMode::Software:
		result = new TextureImplSoftware(renderContext, pixelFormat, size);
		break;

#if defined(LDL_WINDOWS_NT) || defined(LDL_WINDOWS_9X) || defined(__unix__)
	case LDL_RenderMode::OpenGL1:
		result = new LDL_TextureOpenGL1(renderContext, pixelFormat, size);
		break;
	case LDL_RenderMode::OpenGL3:
		result = new  TextureImplOpenGL3(renderContext, pixelFormat, size);
		break;
#endif

	}

	return result;
}

LDL_ITexture* LDL_CreateTexture(LDL_RenderContext* renderContext, LDL_Surface* surface)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < LDL_RenderMode::Max, "Unknown graphics mode");

	LDL_ITexture* result = NULL;

	switch (mode)
	{
#if defined(LDL_WINDOWS_NT) || defined(LDL_WINDOWS_9X) || defined(__unix__)
	case LDL_RenderMode::OpenGL1:
		result = new LDL_TextureOpenGL1(renderContext, surface);
#endif

	}

	return result;
}
