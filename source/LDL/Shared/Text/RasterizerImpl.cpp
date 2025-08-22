// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RasterizerImpl.hpp"
#include "FontImpl.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Text;
using namespace LDL::Math;
using namespace LDL::Graphics;

RasterizerImpl::RasterizerImpl(const Vec2u& bufferSize) :
	_SymbolBuffer(Vec2u(100, 100), Vec2u(100, 100), 4),
	_TextBuffer(bufferSize, bufferSize, 4)
{
}

RasterizerImpl::~RasterizerImpl()
{
}

Surface* RasterizerImpl::Result()
{
	return &_TextBuffer;
}

bool RasterizerImpl::RenderText(const std::string& text, Font* font, const Color& color)
{
	if (text.empty())
		return false;

	FT_Face face = font->GetFontImpl()->GetFace();

	size_t posX = 0;
	size_t posY = 0;

	_PixelConverter.Fill(_TextBuffer.Pixels(), _TextBuffer.Size(), _TextBuffer.BytesPerPixel(), Color(255, 255, 255));

	for (size_t i = 0; i < text.size(); i++)
	{
		FT_UInt index = FT_Get_Char_Index(face, text[i]);
		LDL_ASSERT_DETAIL(index, "FT_Get_Char_Index failed");

		FT_Error error = FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);
		LDL_ASSERT_DETAIL(error, "FT_Load_Glyph failed");

		error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
		LDL_ASSERT_DETAIL(error, "FT_Render_Glyph failed");

		FT_Bitmap bitmap = face->glyph->bitmap;

		_SymbolBuffer.Resize(Vec2u(bitmap.width, bitmap.rows));

		uint8_t* pixels = _SymbolBuffer.Pixels();

		for (size_t y = 0; y < bitmap.rows; y++)
		{
			for (size_t x = 0; x < bitmap.width; x++)
			{
				size_t k = y * bitmap.pitch + x;
				size_t j = y * bitmap.pitch + x;

#if defined(LDL_CONFIG_COLOR_BGRA)
				pixels[j * 4 + 0] = color.b;
				pixels[j * 4 + 1] = color.g;
				pixels[j * 4 + 2] = color.r;
#else
				pixels[j * 4 + 0] = color.r;
				pixels[j * 4 + 1] = color.g;
				pixels[j * 4 + 2] = color.b;
#endif

				pixels[j * 4 + 3] = bitmap.buffer[k];
			}
		}

		_PixelCopier.Copy32(&_SymbolBuffer, &_TextBuffer, Vec2u(posX, 0));

		posX += 35;
	}

	return true;
}
