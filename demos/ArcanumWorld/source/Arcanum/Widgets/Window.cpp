// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Widgets/Window.hpp>

using namespace LDL;
using namespace Arcanum;

Arcanum::Window::Window(Render& render, const Vec2u& pos, const Vec2u& size) :
	Widget(render, pos, size)
{
}

void Arcanum::Window::Attach(Widget* widget)
{
	_container.Append(widget);
}

void Arcanum::Window::Draw()
{
	_container.Draw();
}
