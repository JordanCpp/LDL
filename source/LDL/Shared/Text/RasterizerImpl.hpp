// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Text_RasterizerImpl_hpp
#define LDL_Text_RasterizerImpl_hpp

#include <string>
#include <LDL/Text/Font.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/PixelCopier.hpp>
#include <LDL/Graphics/PixelConverter.hpp>

namespace LDL
{
	class LDL_LIBRARY RasterizerImpl
	{
	public:
		RasterizerImpl(const Vec2u& bufferSize);
		~RasterizerImpl();
		Surface* Result();
		bool RenderText(const std::string& text, Font* font, const Color& color);
	private:
		PixelConverter _pixelConverter;
		PixelCopier    _pixelCopier;
		Surface        _symbolBuffer;
		Surface        _textBuffer;
	};
}

#endif    
