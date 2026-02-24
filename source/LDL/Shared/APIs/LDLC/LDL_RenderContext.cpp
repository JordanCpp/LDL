// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/LDLC/LDL_RenderContext.hpp>

using namespace LDL;

LDL_RenderContext::LDL_RenderContext()
{
}

LDL_RenderContext* LDL_RenderContextNew()
{
	LDL_RenderContext* p = new LDL_RenderContext;

	return p;
}

void LDL_RenderContextFree(LDL_RenderContext* renderContext)
{
	delete renderContext;
}

void LDL_RenderContextGetContext(LDL_RenderContext* renderContext)
{
	renderContext->_renderContext.Context();
}
