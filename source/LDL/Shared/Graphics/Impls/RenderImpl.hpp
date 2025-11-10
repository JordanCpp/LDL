// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Impls_RenderImpl_hpp
#define LDL_Graphics_Impls_RenderImpl_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/SpriteBatcher.hpp>

namespace LDL
{
	class RenderImpl
	{
	public:
		virtual ~RenderImpl() {};
		virtual void Buffer(uint8_t* dst) = 0;
		virtual void Begin() = 0;
		virtual void End() = 0;
		virtual const Vec2u& Size() = 0;
		virtual const Color& GetColor() = 0;
		virtual void Clear() = 0;
		virtual void SetColor(const LDL::Color& color) = 0;
		virtual void Pixel(const Vec2u& pos) = 0;
		virtual void Fill(const Vec2u& pos, const Vec2u& size) = 0;
		virtual void Line(const Vec2u& pos1, const Vec2u& pos2) = 0;
		virtual void Draw(Texture* image, const Vec2u& pos) = 0;
		virtual void Draw(Texture* image, const Vec2u& pos, const Vec2u& size) = 0;
		virtual void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize) = 0;
		virtual void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize) = 0;
		virtual void Draw(Surface* image, const Vec2u& pos) = 0;
		virtual void Draw(Surface* image, const Vec2u& pos, const Vec2u& size) = 0;
		virtual void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize) = 0;
		virtual void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize) = 0;
		virtual void Draw(SpriteBatcher* textureBatcher) = 0;
	};
}

#endif    
