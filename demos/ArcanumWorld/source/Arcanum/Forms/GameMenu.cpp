// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Forms/GameMenu.hpp>

using namespace LDL;
using namespace Arcanum;

GameMenu::GameMenu(Render& render) :
	Form(render, Vec2u(0, 0), render.Size()),
	_button(render, Vec2u(0, 0), Vec2u(300, 300))
{
	Attach(&_button);
}
