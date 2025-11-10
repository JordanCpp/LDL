// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Base/BaseRender.hpp>

using namespace LDL;

BaseRender::BaseRender(const Vec2u& size) :
	_size(size)
{
}

const Vec2u& BaseRender::Size()
{
	return _size;
}

const Color& BaseRender::GetColor()
{
	return _current;
}

void BaseRender::SetColor(const Color& color)
{
	_current = color;
}
