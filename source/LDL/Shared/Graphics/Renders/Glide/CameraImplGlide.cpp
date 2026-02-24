// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/Glide/CameraImplGlide.hpp>

using namespace LDL;

CameraImplGlide::CameraImplGlide(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_renderImpl(renderImpl),
	_pos(pos),
	_size(size)
{
}

const Vec2u& CameraImplGlide::Pos()
{
	return _pos;
}

const Vec2u& CameraImplGlide::Size()
{
	return _size;
}

void CameraImplGlide::Pos(const Vec2u& pos)
{
}

void CameraImplGlide::Size(const Vec2u& size)
{
}
