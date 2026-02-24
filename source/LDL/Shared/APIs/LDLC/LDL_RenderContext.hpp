// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_RenderContext_hpp
#define LDL_RenderContext_hpp

#include <LDLC/LDL_RenderContext.h>
#include <LDL/Graphics/RenderContext.hpp>

struct LDL_RenderContext
{
	LDL::RenderContext _renderContext;
	LDL_RenderContext();
};

#endif
