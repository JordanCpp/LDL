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
	namespace Graphics
	{
		class RenderImpl;

		class TextureImplOpenGL3 : public TextureImpl
		{
		public:
			TextureImplOpenGL3(RenderContextImpl* renderContextImpl, const Math::Vec2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
			TextureImplOpenGL3(RenderContextImpl* renderContextImpl, const Math::Vec2u& size, uint8_t bytesPerPixel);
			~TextureImplOpenGL3();
			const Math::Vec2u& Size();
			const Math::Vec2u& Quad();
			size_t Id();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface* surface, const Math::Vec2u& srcSize);
		private:
			RenderContextImpl* _RenderContextImpl;
			size_t _Id;
			Math::Vec2u _Size;
			Math::Vec2u _Quad;
		};
	}
}

#endif    
