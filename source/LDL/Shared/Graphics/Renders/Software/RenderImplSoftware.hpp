// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_RenderImpl_hpp
#define LDL_Graphics_Software_RenderImpl_hpp

#include "../../Base/BaseRender.hpp"
#include <LDL/Graphics/Window.hpp>
#include "TextureImplSoftware.hpp"
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/PixelPainter.hpp>
#include <LDL/Graphics/PixelCopier.hpp>
#include <LDL/Graphics/ImageResizer.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>
#include "../../Impls/RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImplSoftware : public RenderImpl
		{
		public:
			RenderImplSoftware(RenderContextImpl* renderContextImpl, Window* window);
			void Buffer(uint8_t * dst);
			void Begin();
			void End();
			const Math::Vec2u& Size();
			const Graphics::Color& Color();
			void Clear();
			void Color(const Graphics::Color& color);
			void Pixel(const Math::Vec2u& pos);
			void Fill(const Math::Vec2u& pos, const Math::Vec2u& size);
			void Line(const Math::Vec2u& pos1, const Math::Vec2u& pos2);
			void Draw(Texture* image, const Math::Vec2u& pos);
			void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(TextureBatcher* textureBatcher);
		private:
			Window*      _window;
			Surface      _canvas;
			PixelPainter _pixelPainter;
			PixelCopier  _pixelCopier;
			ImageResizer _imageResizer;
		};
	}
}

#endif   
