// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Widgets/Button.hpp>

using namespace Arcanum;

Button::Button(LDL_IRender* render, const LDL_Vec2u& pos, const LDL_Vec2u& size) :
	Widget(render, pos, size)
{
}

void Button::Draw()
{
	GetRender()->SetColor(LDL_Color(192, 192, 192));
	GetRender()->Fill(Pos(), Size());
}
