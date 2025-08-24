// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "WindowImplCreator.hpp"

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Graphics/WindowImplSoftware.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplOpenGL1.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplOpenGL3.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplDirectDraw.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplGlide.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplDirect3D6.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Graphics/Software/WindowImplSoftware.hpp>
#include <LDL/Platforms/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp>
#include <LDL/Platforms/Linux/Graphics/OpenGL3/WindowImplOpenGL3.hpp>
#include <LDL/Platforms/Linux/Graphics/Glide/WindowImplGlide.hpp>
#endif

#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

WindowImpl* WindowImplCreator::Create(Result& result, RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode)
{
	size_t renderMode = renderContext.Mode();
	LDL_ASSERT_DETAIL(renderMode < RenderMode::Max, "Unknown graphics mode");

	WindowImpl* impl = NULL;

	switch (renderMode)
	{
#if defined(_WIN32)
	case RenderMode::DirectDraw:
		impl = new WindowImplDirectDraw(result, pos, size, title, mode);
		break;

	case RenderMode::Direct3D6:
		impl = new WindowImplDirect3D6(result, pos, size, title, mode);
		break;
#endif
	case RenderMode::Software:
		impl = new WindowImplSoftware(result, pos, size, title, mode);
		break;
	case RenderMode::OpenGL1:
		impl = new WindowImplOpenGL1(result, pos, size, title, mode);
		break;
	case RenderMode::OpenGL3:
		impl = new WindowImplOpenGL3(result, pos, size, title, mode);
		break;
	case RenderMode::Glide:
		impl = new WindowImplGlide(result, pos, size, title, mode);
		break;
	}

	return impl;
}
