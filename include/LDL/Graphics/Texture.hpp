// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Texture_hpp
#define LDL_Graphics_Texture_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl;

		class LDL_LIBRARY Texture
		{
		public:
			Texture(RenderContext* renderContext, const Math::Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
			Texture(RenderContext* renderContext, const Math::Vec2u& size, uint8_t bytesPerPixel);
			~Texture();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface * surface, const Math::Vec2u& srcSize);
			const Math::Vec2u& Size();
			TextureImpl* GetTextureImpl();
		private:
			TextureImpl* _impl;
		};
	}
}

#endif    
