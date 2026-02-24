// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Renders_Glide_RenderImplGlide_hpp
#define LDL_Graphics_Renders_Glide_RenderImplGlide_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/APIs/Glide/GlideLoader.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>
#include <LDL/Shared/Graphics/Impls/RenderImpl.hpp>

namespace LDL
{
	class RenderImplGlide : public RenderImpl
	{
	public:
		RenderImplGlide(Result& result, RenderContextImpl* renderContextImpl, Window* window);
		~RenderImplGlide();
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
		void Draw(Surface* image, const Vec2u& pos);
		void Draw(Surface* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Texture* image, const Vec2u& pos);
		void Draw(Texture* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(TextureBatcher* textureBatcher);
	private:
		Result&            _result;
		Glide::GlideLoader _glideLoader;
		Window*            _window;
		Color              _color;
		RenderContextImpl* _renderContextImpl;
	};
}

#endif    
