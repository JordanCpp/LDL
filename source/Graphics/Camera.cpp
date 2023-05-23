#include <LDL/Graphics/Camera.hpp>
#include "../Graphics/OpenGL1/CameraImpl.hpp"

#ifdef LDL_RENDER_OPENGL1
#include "OpenGL1/RenderImpl.hpp"
#endif

using namespace LDL::Graphics;

Camera::Camera(Render* render, const Point2u& pos, const Point2u& size) :
	_CameraImpl(new CameraImpl(render->GetRenderImpl(), pos, size))
{
}

CameraImpl* LDL::Graphics::Camera::GetCameraImpl()
{
	return _CameraImpl;
}

const Point2u& Camera::Pos()
{
	return _CameraImpl->Pos();
}

const Point2u& Camera::Size()
{
	return _CameraImpl->Size();
}

void Camera::Pos(const Point2u& pos)
{
	_CameraImpl->Pos(pos);
}

void Camera::Size(const Point2u& size)
{
	_CameraImpl->Size(size);
}