// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Video.hpp>

LDL_VideoMode::LDL_VideoMode() :
	_bitsPerPixel(0)
{
}

LDL_VideoMode::LDL_VideoMode(const LDL_Vec2u& size, size_t bytesPerPixel) :
	_bitsPerPixel(bytesPerPixel),
	_size(size)
{
}

const LDL_Vec2u& LDL_VideoMode::Size()
{
	return _size;
}

size_t LDL_VideoMode::BitsPerPixel()
{
	return _bitsPerPixel;
}
