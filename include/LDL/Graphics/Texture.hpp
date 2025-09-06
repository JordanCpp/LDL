// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Texture_hpp
#define LDL_Graphics_Texture_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/RenderContext.hpp>

namespace LDL
{
	class TextureImpl;

	class LDL_LIBRARY Texture
	{
	public:
		enum
		{
			SizeOf = 64
		};
		Texture(RenderContext* renderContext, size_t pixelFormat, const Vec2u& size, uint8_t* pixels);
		Texture(RenderContext* renderContext, size_t pixelFormat, const Vec2u& size);
		Texture(RenderContext* renderContext, Surface* surface);
		~Texture();
		void Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
		void Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize);
		const Vec2u& Size();
		TextureImpl* GetTextureImpl();
	private:
		TextureImpl* _impl;
		uint8_t      _memory[SizeOf];
	};
}

#endif    
