// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "CameraImplOpenGL1.hpp"
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImplOpenGL1::CameraImplOpenGL1(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_renderImpl(renderImpl),
	_pos(pos),
	_size(size)
{
}

const Vec2u& CameraImplOpenGL1::Pos()
{
	return _pos;
}

const Vec2u& CameraImplOpenGL1::Size()
{
	return _size;
}

void CameraImplOpenGL1::Pos(const Vec2u& pos)
{
	LDL_UNUSED(pos);
	//_RenderImpl->_ModelView = Translate(_RenderImpl->_ModelView, Vec3f((float)pos.x, (float)pos.y, 0.0f));
}

void CameraImplOpenGL1::Size(const Vec2u& size)
{
	LDL_UNUSED(size);
}
