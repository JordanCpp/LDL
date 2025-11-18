// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Graphics//RenderContext.hpp>

using namespace LDL;

RenderContext::RenderContext(size_t mode) :
	_mode(mode)
{
}

RenderContext::~RenderContext()
{
}

size_t RenderContext::Mode()
{
    return _mode;
}
