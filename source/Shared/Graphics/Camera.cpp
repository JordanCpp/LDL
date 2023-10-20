#include <LDL/Graphics/Camera.hpp>

#include "Renders/OpenGL1/CameraImplOpenGL1.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

Camera::Camera(Render* render, const Vec2u& pos, const Vec2u& size)
{
	_CameraImpl = new CameraImplOpenGL1(render->GetRenderImpl(), pos, size);
}

CameraImpl* Camera::GetCameraImpl()
{
	return _CameraImpl;
}

const Vec2u& Camera::Pos()
{
	return _CameraImpl->Pos();
}

const Vec2u& Camera::Size()
{
	return _CameraImpl->Size();
}

void Camera::Pos(const Vec2u& pos)
{
	_CameraImpl->Pos(pos);
}

void Camera::Size(const Vec2u& size)
{
	_CameraImpl->Size(size);
}
