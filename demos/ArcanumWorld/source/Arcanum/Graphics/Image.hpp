// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Graphics_Image_hpp
#define Arcanum_Graphics_Image_hpp

#include <LDL/Texture.hpp>
#include <LDL/Context.hpp>

namespace Arcanum
{
	class Image
	{
	public:
		Image(LDL_RenderContext* renderContext, const LDL_Vec2u& size, uint8_t* pixels, const LDL_Vec2u& offset, const LDL_Vec2u& delta);
		LDL_ITexture* GetTexture();
		const LDL_Vec2u& Offset();
		const LDL_Vec2u& Delta();
	private:
		LDL_ITexture* _texture;
	    LDL_Vec2u     _offset;
	    LDL_Vec2u     _delta;
	};
}

#endif    
