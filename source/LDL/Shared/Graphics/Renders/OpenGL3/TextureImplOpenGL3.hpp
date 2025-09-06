// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_TextureImpl_hpp
#define LDL_Graphics_OpenGL3_TextureImpl_hpp

#include <LDL/Graphics/Surface.hpp>
#include <LDL/Shared/Graphics/Impls/TextureImpl.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/RenderContextImplOpenGL3.hpp>

namespace LDL
{
	class RenderImpl;

	class TextureImplOpenGL3 : public TextureImpl
	{
	public:
		TextureImplOpenGL3(RenderContextImpl* renderContextImpl, size_t pixelFormat, const Vec2u& size, uint8_t* pixels);
		TextureImplOpenGL3(RenderContextImpl* renderContextImpl, size_t pixelFormat, const Vec2u& size);
		~TextureImplOpenGL3();
		const Vec2u& Size();
		const Vec2u& Quad();
		size_t Id();
		void Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
		void Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize);
	private:
		RenderContextImpl* _renderContextImpl;
		size_t             _id;
		Vec2u              _size;
		Vec2u              _quad;
	};
}

#endif    
