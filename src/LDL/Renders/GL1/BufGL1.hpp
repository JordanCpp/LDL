// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL1_BufGL1_hpp
#define LDL_Renders_GL1_BufGL1_hpp

#include <LDL/Vec2.hpp>
#include <LDL/Color.hpp>
#include <LDL/PVector.hpp>
#include <LDL/Texture.hpp>
#include <LDL/Renders/GL1/BatchGL1.hpp>

class LDL_TextureElement
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

class LDL_LineElement
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

class LDL_FillElement
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

class LDL_ClearElement
{
public:
	uint8_t type;
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

class LDL_TextureBatcherElement
{
public:
	uint8_t     type;
	size_t      texture;
	size_t      count;
	Quad* quads;
};

class LDL_RenderElement
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
		LDL_TextureElement        textureElement;
		LDL_LineElement           lineElement;
		LDL_FillElement           fillElement;
		LDL_ClearElement          clearElement;
		LDL_TextureBatcherElement textureBatcherElement;
	};
};

class LDL_RenderBuffer
{
public:
	LDL_RenderBuffer();
	void Reset();
	void Texture(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize, size_t textureId, size_t textureQuad);
	void Line(const LDL_Vec2u& first, const LDL_Vec2u& last, const LDL_Color& color);
	void Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color);
	void TextureBatcher(size_t textureId, size_t count, Quad* quads);
	void Clear(const LDL_Color& color);
	void Draw();
	void Draw(LDL_TextureElement& src);
	void Draw(LDL_LineElement& src);
	void Draw(LDL_FillElement& src);
	void Draw(LDL_ClearElement& src);
	void Draw(LDL_TextureBatcherElement& src);
private:
	LDL_PodVector<LDL_RenderElement> _elements;
};

#endif    
