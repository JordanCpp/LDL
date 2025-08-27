// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_TextureImpl_hpp
#define LDL_Graphics_TextureImpl_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	class TextureImpl
	{
	public:
		virtual ~TextureImpl() {};
		virtual void Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel) = 0;
		virtual void Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize) = 0;
		virtual const Vec2u& Size() = 0;
		virtual const Vec2u& Quad() = 0;
	private:
	};
}

#endif    
