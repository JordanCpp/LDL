// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/Direct3D6/CameraImplDirect3D6.hpp>

using namespace LDL;

CameraImplDirect3D6::CameraImplDirect3D6(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_impl(renderImpl),
	_pos(pos),
	_size(size)
{
}

const Vec2u& CameraImplDirect3D6::Pos()
{
	return _pos;
}

const Vec2u& CameraImplDirect3D6::Size()
{
	return _size;
}

void CameraImplDirect3D6::Pos(const Vec2u& pos)
{
}

void CameraImplDirect3D6::Size(const Vec2u& size)
{
}
