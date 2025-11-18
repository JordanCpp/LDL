// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Creators_WindowImplCreator_hpp
#define LDL_Graphics_Creators_WindowImplCreator_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Core/Result.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Graphics/Window.hpp>

namespace LDL
{
	IWindow* CreateWindowImpl(Result& result, RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode);
}

#endif
