// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Graphics/Camera.hpp>

using namespace Arcanum;

Camera::Camera(const LDL_Vec2u& pos, const LDL_Vec2u& size) :
	_step(25),
	_area(pos, size)
{
}

const LDL_Vec2u& Camera::Pos()
{
	return _area.Pos();
}

const LDL_Vec2u& Camera::Size()
{
	return _area.Size();
}

void Camera::Move(const LDL_Vec2u& pos)
{
	_area.Pos(pos.x, pos.y);
}

void Camera::Handle(LDL_Event& event)
{
	uint32_t x = Pos().x;
	uint32_t y = Pos().y;

	if (event.IsKeyPressed(LDL_KeyboardKey::W))
	{
		y += _step;
	}

	if (event.IsKeyPressed(LDL_KeyboardKey::S))
	{
		y -= _step;
	}

	if (event.IsKeyPressed(LDL_KeyboardKey::A))
	{
		x += _step;
	}

	if (event.IsKeyPressed(LDL_KeyboardKey::D))
	{
		x -= _step;
	}

	Move(LDL_Vec2u(x, y));
}
