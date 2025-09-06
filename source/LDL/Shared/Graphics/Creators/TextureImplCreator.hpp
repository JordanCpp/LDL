// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Creators_TextureImplCreator_hpp
#define LDL_Graphics_Creators_TextureImplCreator_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Shared/Graphics/Impls/TextureImpl.hpp>

namespace LDL
{
	class TextureImplCreator
	{
	public:
		TextureImpl* Create(uint8_t* memory, RenderContext* renderContext, size_t pixelFormat, const Vec2u& size, uint8_t* pixels);
		TextureImpl* Create(uint8_t* memory, RenderContext* renderContext, size_t pixelFormat, const Vec2u& size);
		TextureImpl* Create(uint8_t* memory, RenderContext* renderContext, Surface* surface);
	};
}

#endif   
