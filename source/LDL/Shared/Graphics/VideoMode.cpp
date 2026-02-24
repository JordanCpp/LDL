// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/VideoMode.hpp>

using namespace LDL;

VideoMode::VideoMode() :
	_bitsPerPixel(0)
{
}

VideoMode::VideoMode(const Vec2u& size, size_t bytesPerPixel) :
	_size(size),
	_bitsPerPixel(bytesPerPixel)
{
}

const Vec2u& VideoMode::Size()
{
	return _size;
}

size_t VideoMode::BitsPerPixel()
{
	return _bitsPerPixel;
}
