// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_RenderContextImpl_hpp
#define LDL_Graphics_Software_RenderContextImpl_hpp

#include <LDL/Shared/Graphics/Impls/RenderContextImpl.hpp>

namespace LDL
{
	class RenderContextImplSoftware : public RenderContextImpl
	{
	public:
		RenderContextImplSoftware(size_t mode);
		size_t Mode();
	private:
		size_t _mode;
	};
}

#endif    
