// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Text_FontImpl_hpp
#define LDL_Text_FontImpl_hpp

#include <LDL/Core/Types.hpp>
#include "RasterizerContextImpl.hpp"

namespace LDL
{
	class LDL_LIBRARY FontImpl
	{
	public:
		FontImpl(RasterizerContextImpl* rasterizerContextImpl, size_t fontSize, uint8_t* font, size_t size);
		~FontImpl();
		FT_Face GetFace();
	private:
		FT_Face _face;
	};
}

#endif    
