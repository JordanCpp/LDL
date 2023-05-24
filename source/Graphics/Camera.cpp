#include <LDL/Graphics/Camera.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/CameraImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/CameraImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/CameraImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/CameraImpl.hpp"
#elif LDL_RENDER_DIRECTX1
#include "DirectDraw/CameraImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/CameraImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/CameraImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/CameraImpl.hpp"
#endif

using namespace LDL::Graphics;

Camera::Camera(Render* render, const Point2u& pos, const Point2u& size) :
	_CameraImpl(new CameraImpl(render->GetRenderImpl(), pos, size))
{
}

CameraImpl* Camera::GetCameraImpl()
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