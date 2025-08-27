// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/Scenery.hpp>

using namespace LDL;
using namespace Arcanum;

Scenery::Scenery() :
	_body(NULL)
{
}

void Scenery::Init(Sprite* sprite)
{
	_body = sprite;
}

Sprite* Scenery::Body()
{
	return _body;
}

const Vec2u& Scenery::Pos()
{
	return _mapObject.Pos();
}

void Scenery::Pos(const Vec2u& pos)
{
	_mapObject.Pos(pos);
}
