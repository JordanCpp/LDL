// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Creators_RenderImplCreator_hpp
#define LDL_Graphics_Creators_RenderImplCreator_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Shared/Graphics/Impls/RenderImpl.hpp>

namespace LDL
{
	class RenderImplCreator
	{
	public:
		RenderImpl* Create(uint8_t* memory, Result& result, RenderContext& renderContext, Window* window);
	};
}

#endif    
