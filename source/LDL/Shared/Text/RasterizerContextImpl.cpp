// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RasterizerContextImpl.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL;

RasterizerContextImpl::RasterizerContextImpl()
{
	FT_Error error = FT_Init_FreeType(&_library);
	LDL_ASSERT_DETAIL(error == 0, "FT_Init_FreeType failed");
}

RasterizerContextImpl::~RasterizerContextImpl()
{
	FT_Done_FreeType(_library);
}

FT_Library RasterizerContextImpl::GetLibrary()
{
	return _library;
}
