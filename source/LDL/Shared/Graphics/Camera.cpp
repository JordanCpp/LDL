#include <LDL/Graphics/Camera.hpp>

#include "Renders/OpenGL1/CameraImplOpenGL1.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

Camera::Camera(Render* render, const Vec2u& pos, const Vec2u& size)
{
	_impl = new CameraImplOpenGL1(render->GetRenderImpl(), pos, size);
}

CameraImpl* Camera::GetCameraImpl()
{
	return _impl;
}

const Vec2u& Camera::Pos()
{
	return _impl->Pos();
}

const Vec2u& Camera::Size()
{
	return _impl->Size();
}

void Camera::Pos(const Vec2u& pos)
{
	_impl->Pos(pos);
}

void Camera::Size(const Vec2u& size)
{
	_impl->Size(size);
}
