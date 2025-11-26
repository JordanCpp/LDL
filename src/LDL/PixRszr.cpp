// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/PixRszer.hpp>

LDL_PixelResizer::LDL_PixelResizer(const LDL_Vec2u& size) :
	_surface(LDL_PixelFormat::RGBA32, size)
{
	LDL_UNUSED(size);
}

LDL_Surface* LDL_PixelResizer::LDL_Resize(const LDL_Vec2u& size, LDL_Surface* surface)
{
	LDL_UNUSED(size);
	LDL_UNUSED(surface);

	return &_surface;
}
