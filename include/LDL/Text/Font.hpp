// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Text_Font_hpp
#define LDL_Text_Font_hpp

#include <LDL/Text/RasterizerContext.hpp>

namespace LDL
{
	class FontImpl;

	class LDL_LIBRARY Font
	{
	public:
		Font(RasterizerContext* rasterizerContext, size_t fontSize, uint8_t* font, size_t size);
		~Font();
		FontImpl* GetFontImpl();
	private:
		FontImpl* _impl;
	};
}

#endif    
