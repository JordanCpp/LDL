#include <LDL/Graphics/Camera.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/CameraImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/CameraImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/CameraImplOpenGL1.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/CameraImpl.hpp"
#elif LDL_RENDER_DIRECT_DRAW
#include "DirectDraw/CameraImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/CameraImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/CameraImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/CameraImpl.hpp"
#endif

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