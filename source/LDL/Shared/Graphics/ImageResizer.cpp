// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/ImageResizer.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

ImageResizer::ImageResizer(const Vec2u& size) :
	_surface(size, 4)
{
}

Surface* ImageResizer::Resize(const Vec2u& size, Surface* surface)
{
	return &_surface;
}
