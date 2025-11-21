// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/BaseRndr.hpp>

LDL_BaseRender::LDL_BaseRender(const LDL_Vec2u& size) :
	_size(size)
{
}

const LDL_Vec2u& LDL_BaseRender::Size()
{
	return _size;
}

const LDL_Color& LDL_BaseRender::GetColor()
{
	return _current;
}

void LDL_BaseRender::SetColor(const LDL_Color& color)
{
	_current = color;
}
