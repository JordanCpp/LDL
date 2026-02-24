// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/Camera.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/CameraImplOpenGL1.hpp>

using namespace LDL;

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
