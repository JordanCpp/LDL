// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Impls_RenderContextImpl_hpp
#define LDL_Graphics_Impls_RenderContextImpl_hpp

#include <LDL/std/stddef.hpp>

namespace LDL
{
	class RenderContextImpl
	{
	public:
		virtual ~RenderContextImpl() {};
		virtual size_t Mode() = 0;
	};
}

#endif    
