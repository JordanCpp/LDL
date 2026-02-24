// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Text_Rasterizer_hpp
#define LDL_Text_Rasterizer_hpp

#include <LDL/Text/Font.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Color.hpp>
#include <string>

namespace LDL
{
	class RasterizerImpl;

	class LDL_LIBRARY Rasterizer
	{
	public:
		Rasterizer(const Vec2u& bufferSize);
		~Rasterizer();
		RasterizerImpl* GetRasterizerImpl();
		Surface* Result();
		bool RenderText(const std::string& text, Font* font, const Color& color);
	private:
		RasterizerImpl* _impl;
	};
}

#endif    
