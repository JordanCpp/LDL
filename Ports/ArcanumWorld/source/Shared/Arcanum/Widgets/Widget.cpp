// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Widgets/Widget.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace Arcanum::Widgets;

Widget::Widget(Render* render, const Vec2u& pos, const Vec2u& size) :
	_render(render),
	_area(pos, size)
{
}

Widget::~Widget()
{
}

const Vec2u Widget::Pos()
{
	return _area.Pos();
}

const Vec2u Widget::Size()
{
	return _area.Size();
}

Render* Widget::GetRender()
{
	return _render;
}