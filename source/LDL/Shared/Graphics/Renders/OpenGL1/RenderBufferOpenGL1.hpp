// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL1_RenderBuffer_hpp
#define LDL_Graphics_OpenGL1_RenderBuffer_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/Graphics/Texture.hpp>
#include "TextureBatcherImplOpenGL1.hpp"
#include <vector>

namespace LDL
{
	class TextureElement
	{
	public:
		uint8_t   type;
		uint16_t  textureId;
		uint16_t  textureQuad;
		uint16_t  dstPosX;
		uint16_t  dstPosY;
		uint16_t  dstSizeX;
		uint16_t  dstSizeY;
		uint16_t  srcPosX;
		uint16_t  srcPosY;
		uint16_t  srcSizeX;
		uint16_t  srcSizeY;
	};

	class LineElement
	{
	public:
		uint8_t  type;
		uint8_t  r;
		uint8_t  g;
		uint8_t  b;
		uint16_t firstX;
		uint16_t firstY;
		uint16_t lastX;
		uint16_t lastY;
	};

	class FillElement
	{
	public:
		uint8_t  type;
		uint8_t  r;
		uint8_t  g;
		uint8_t  b;
		uint16_t posX;
		uint16_t posY;
		uint16_t sizeX;
		uint16_t sizeY;
	};

	class ClearElement
	{
	public:
		uint8_t type;
		uint8_t r;
		uint8_t g;
		uint8_t b;
	};

	class TextureBatcherElement
	{
	public:
		uint8_t     type;
		size_t      texture;
		size_t      count;
		Util::Quad* quads;
	};

	class RenderElement
	{
	public:
		enum
		{
			IsTexture = 1,
			IsLine,
			IsFill,
			IsClear,
			IsTextureBatcher
		};

		uint8_t type;

		union
		{
			TextureElement        textureElement;
			LineElement           lineElement;
			FillElement           fillElement;
			ClearElement          clearElement;
			TextureBatcherElement textureBatcherElement;
		};
	};

	class RenderBuffer
	{
	public:
		RenderBuffer();
		void Reset();
		void Texture(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize, size_t textureId, size_t textureQuad);
		void Line(const Vec2u& first, const Vec2u& last, const Color& color);
		void Fill(const Vec2u& pos, const Vec2u& size, const Color& color);
		void TextureBatcher(size_t textureId, size_t count, Util::Quad* quads);
		void Clear(const Color& color);
		void Draw();
		void Draw(TextureElement& src);
		void Draw(LineElement& src);
		void Draw(FillElement& src);
		void Draw(ClearElement& src);
		void Draw(TextureBatcherElement& src);
	private:
		std::vector<RenderElement> _elements;
	};
}

#endif    
