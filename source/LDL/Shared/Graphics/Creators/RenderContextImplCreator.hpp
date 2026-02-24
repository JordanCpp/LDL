// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Creators_RenderContext_hpp
#define LDL_Graphics_Creators_RenderContext_hpp

#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Shared/Graphics/Impls/RenderContextImpl.hpp>

namespace LDL
{
	class RenderContextImplCreator
	{
	public:
		RenderContextImpl* Create(size_t mode);
	};
}

#endif  
