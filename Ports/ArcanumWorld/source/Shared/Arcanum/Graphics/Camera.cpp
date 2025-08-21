#include <Arcanum/Graphics/Camera.hpp>

using namespace Arcanum::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Math;

Camera::Camera(const Vec2u& pos, const Vec2u& size) :
	_Area(pos, size),
	_Step(25)
{
}

const Vec2u& Camera::Pos()
{
	return _Area.Pos();
}

const Vec2u& Camera::Size()
{
	return _Area.Size();
}

void Camera::Move(const Vec2u& pos)
{
	_Area.Pos(pos.x, pos.y);
}

void Camera::Handle(Event& event)
{
	size_t x = Pos().x;
	size_t y = Pos().y;

	if (event.IsKeyPressed(KeyboardKey::W))
	{
		y += _Step;
	}

	if (event.IsKeyPressed(KeyboardKey::S))
	{
		y -= _Step;
	}

	if (event.IsKeyPressed(KeyboardKey::A))
	{
		x += _Step;
	}

	if (event.IsKeyPressed(KeyboardKey::D))
	{
		x -= _Step;
	}

	Move(Vec2u(x, y));
}