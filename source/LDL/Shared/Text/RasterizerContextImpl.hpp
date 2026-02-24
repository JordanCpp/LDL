// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Text_RasterizerContextImpl_hpp
#define LDL_Text_RasterizerContextImpl_hpp

#include <LDL/Core/Types.hpp>
#include "FreeType.hpp"

namespace LDL
{
	class LDL_LIBRARY RasterizerContextImpl
	{
	public:
		RasterizerContextImpl();
		~RasterizerContextImpl();
		FT_Library GetLibrary();
	private:
		FT_Library _library;
	};
}

#endif    
