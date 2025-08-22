// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Text/RasterizerContext.hpp>
#include "RasterizerContextImpl.hpp"

using namespace LDL::Text;

RasterizerContext::RasterizerContext() :
	_impl(new RasterizerContextImpl)
{
}

RasterizerContext::~RasterizerContext()
{
	delete _impl;
}

RasterizerContextImpl* RasterizerContext::GetRasterizerContextImpl()
{
	return _impl;
}
