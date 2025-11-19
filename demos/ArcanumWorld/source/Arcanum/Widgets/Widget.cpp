// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Widgets/Widget.hpp>

using namespace Arcanum;

Widget::Widget(LDL_IRender* render, const LDL_Vec2u& pos, const LDL_Vec2u& size) :
	_render(render),
	_area(pos, size)
{
}

Widget::~Widget()
{
}

const LDL_Vec2u Widget::Pos()
{
	return _area.Pos();
}

const LDL_Vec2u Widget::Size()
{
	return _area.Size();
}

LDL_IRender* Widget::GetRender()
{
	return _render;
}
