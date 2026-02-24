// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Direct3D6_TextureImpl_hpp
#define LDL_Graphics_Direct3D6_TextureImpl_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Shared/Graphics/Impls/TextureImpl.hpp>
#include <LDL/Shared/Graphics/Renders/Direct3D6/RenderContextImplDirect3D6.hpp>

namespace LDL
{
	class RenderImpl;

	class TextureImplDirect3D6 : public TextureImpl
	{
	public:
		TextureImplDirect3D6(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
		TextureImplDirect3D6(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel);
		~TextureImplDirect3D6();
		void Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
		void Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize);
		const Vec2u& Size();
		const Vec2u& Quad();
	private:
		RenderContextImpl* _renderContextImpl;
		Vec2u              _size;
		Vec2u              _quad;
	};
}

#endif    
