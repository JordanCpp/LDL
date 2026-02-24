// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "FontImpl.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL;

FontImpl::FontImpl(RasterizerContextImpl* rasterizerContextImpl, size_t fontSize, uint8_t* font, size_t size) :
	_face(NULL)
{
	FT_Error error = FT_New_Memory_Face(rasterizerContextImpl->GetLibrary(), font, (FT_Long)size, 0, &_face);
	LDL_ASSERT_DETAIL(error == 0, "FT_Init_FreeType failed");

	error = FT_Set_Pixel_Sizes(_face, 0, (FT_Long)fontSize);
	LDL_ASSERT_DETAIL(error == 0, "FT_Set_Pixel_Sizes failed");
}

FontImpl::~FontImpl()
{
	FT_Done_Face(_face);
}

FT_Face FontImpl::GetFace()
{
	return _face;
}
