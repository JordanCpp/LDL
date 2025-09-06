// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/PixelResizer.hpp>

using namespace LDL;

PixelResizer::PixelResizer(const Vec2u& size) :
	_surface(PixelFormat::RGBA32, size)
{
	LDL_UNUSED(size);
}

Surface* PixelResizer::Resize(const Vec2u& size, Surface* surface)
{
	LDL_UNUSED(size);
	LDL_UNUSED(surface);

	return &_surface;
}
