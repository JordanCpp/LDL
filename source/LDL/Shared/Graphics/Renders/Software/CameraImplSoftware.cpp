// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>
#include <LDL/Shared/Graphics/Renders/Software/CameraImplSoftware.hpp>

using namespace LDL::Graphics;
using namespace LDL;

CameraImplSoftware::CameraImplSoftware(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_impl(renderImpl),
	_pos(pos),
	_size(size)
{
}

const Vec2u& CameraImplSoftware::Pos()
{
	return _pos;
}

const Vec2u& CameraImplSoftware::Size()
{
	return _size;
}

void CameraImplSoftware::Pos(const Vec2u& pos)
{
	_pos = pos;
}

void CameraImplSoftware::Size(const Vec2u& size)
{
	_size = size;
}
