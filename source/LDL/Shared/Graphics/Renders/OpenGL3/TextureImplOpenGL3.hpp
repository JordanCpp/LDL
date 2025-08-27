// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_TextureImpl_hpp
#define LDL_Graphics_OpenGL3_TextureImpl_hpp

#include "RenderContextImplOpenGL3.hpp"
#include <LDL/Graphics/Surface.hpp>
#include "../../Impls/TextureImpl.hpp"

namespace LDL
{
	class RenderImpl;

	class TextureImplOpenGL3 : public TextureImpl
	{
	public:
		TextureImplOpenGL3(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
		TextureImplOpenGL3(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel);
		~TextureImplOpenGL3();
		const Vec2u& Size();
		const Vec2u& Quad();
		size_t Id();
		void Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
		void Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize);
	private:
		RenderContextImpl* _RenderContextImpl;
		size_t _Id;
		Vec2u _Size;
		Vec2u _Quad;
	};
}

#endif    
