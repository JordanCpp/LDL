// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Context.hpp>

LDL_RenderContext::LDL_RenderContext(size_t mode) :
	_mode(mode)
{
}

LDL_RenderContext::~LDL_RenderContext()
{
}

size_t LDL_RenderContext::Mode()
{
    return _mode;
}
