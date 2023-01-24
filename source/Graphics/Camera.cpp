#include <LDL/Graphics/Camera.hpp>

using namespace LDL::Graphics;

Camera::Camera(const Point2u& pos, const Point2u& size) :
	_Pos(pos),
	_Size(size)
{
}

const Point2u& Camera::Pos()
{
	return _Pos;
}

const Point2u& Camera::Size()
{
	return _Size;
}

void LDL::Graphics::Camera::PosX(size_t x)
{
	_Pos.PosX(x);
}

void LDL::Graphics::Camera::PosY(size_t y)
{
	_Pos.PosY(y);
}

void LDL::Graphics::Camera::SizeX(size_t x)
{
	_Size.PosX(x);
}

void LDL::Graphics::Camera::SizeY(size_t y)
{
	_Size.PosY(y);
}