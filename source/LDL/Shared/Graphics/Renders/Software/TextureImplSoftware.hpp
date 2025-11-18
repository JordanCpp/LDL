// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_TextureImpl_hpp
#define LDL_Graphics_Software_TextureImpl_hpp

#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>

namespace LDL
{
	class IRender;

	class TextureImplSoftware : public ITexture
	{
	public:
		TextureImplSoftware(RenderContext* renderContextImpl, size_t pixelFormat, const Vec2u& size, uint8_t* pixels);
		TextureImplSoftware(RenderContext* renderContextImpl, size_t pixelFormat, const Vec2u& size);
		~TextureImplSoftware();
		void Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
		void Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize);
		const Vec2u& Size();
		const Vec2u& Quad();
		Surface* GetSurface();
	private:
		Vec2u   _size;
		Surface _surface;
	};
}

#endif    
