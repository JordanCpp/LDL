// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Graphics/Camera.hpp>

using namespace Arcanum::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Math;

Camera::Camera(const Vec2u& pos, const Vec2u& size) :
	_step(25),
	_area(pos, size)
{
}

const Vec2u& Camera::Pos()
{
	return _area.Pos();
}

const Vec2u& Camera::Size()
{
	return _area.Size();
}

void Camera::Move(const Vec2u& pos)
{
	_area.Pos(pos.x, pos.y);
}

void Camera::Handle(Event& event)
{
	uint32_t x = Pos().x;
	uint32_t y = Pos().y;

	if (event.IsKeyPressed(KeyboardKey::W))
	{
		y += _step;
	}

	if (event.IsKeyPressed(KeyboardKey::S))
	{
		y -= _step;
	}

	if (event.IsKeyPressed(KeyboardKey::A))
	{
		x += _step;
	}

	if (event.IsKeyPressed(KeyboardKey::D))
	{
		x -= _step;
	}

	Move(Vec2u(x, y));
}