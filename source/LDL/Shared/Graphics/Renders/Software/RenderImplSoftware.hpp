// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_RenderImpl_hpp
#define LDL_Graphics_Software_RenderImpl_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/PixelCopier.hpp>
#include <LDL/Graphics/PixelResizer.hpp>
#include <LDL/Graphics/PixelPainter.hpp>
#include <LDL/Graphics/SpriteBatcher.hpp>
#include <LDL/Shared/Graphics/Base/BaseRender.hpp>
#include <LDL/Shared/Graphics/Impls/RenderImpl.hpp>
#include <LDL/Shared/Graphics/Renders/Software/TextureImplSoftware.hpp>

namespace LDL
{
	class RenderImplSoftware : public RenderImpl
	{
	public:
		RenderImplSoftware(Result& result, RenderContextImpl* renderContextImpl, Window* window);
		void Buffer(uint8_t* dst);
		void Begin();
		void End();
		const Vec2u& Size();
		const Color& GetColor();
		void Clear();
		void SetColor(const Color& color);
		void Pixel(const Vec2u& pos);
		void Fill(const Vec2u& pos, const Vec2u& size);
		void Line(const Vec2u& pos1, const Vec2u& pos2);
		void Draw(Texture* image, const Vec2u& pos);
		void Draw(Texture* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Surface* image, const Vec2u& pos);
		void Draw(Surface* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(SpriteBatcher* textureBatcher);
	private:
		Result&       _result;
		LDL::Color    _color;
		Window*       _window;
		Surface       _canvas;
		PixelPainter  _pixelPainter;
		PixelCopier   _pixelCopier;
		PixelResizer  _imageResizer;
	};
}

#endif   
