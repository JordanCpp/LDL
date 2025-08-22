// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Text_RasterizerContext_hpp
#define LDL_Text_RasterizerContext_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Text
	{
		class RasterizerContextImpl;

		class LDL_LIBRARY RasterizerContext
		{
		public:
			RasterizerContext();
			~RasterizerContext();
			RasterizerContextImpl* GetRasterizerContextImpl();
		private:
			RasterizerContextImpl* _impl;
		};
	}
}

#endif    
