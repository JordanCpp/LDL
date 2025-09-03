// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Render_hpp
#define LDL_Graphics_Render_hpp

#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Graphics/SpriteBatcher.hpp>

namespace LDL
{
	class RenderImpl;
	class Texture;

	class LDL_LIBRARY Render
	{
	public:
		enum
		{
			SizeOf = 1024
		};
		Render(Result& result, RenderContext& renderContext, Window* window);
		~Render();
		RenderImpl* GetRenderImpl();
		void Buffer(uint8_t* dst);
		void Begin();
		void End();
		const Vec2u& Size();
		const LDL::Color& Color();
		void Clear();
		void Color(const LDL::Color& color);
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
		RenderImpl* _impl;
		uint8_t     _memory[SizeOf];
	};
}

#endif 
