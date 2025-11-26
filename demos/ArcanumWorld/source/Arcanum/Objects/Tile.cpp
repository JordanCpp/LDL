// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/Tile.hpp>

using namespace Arcanum;

Tile::Tile() :
	_body(NULL)
{
}

const LDL_Vec2u& Tile::Pos()
{
	return _mapObject.Pos();
}

void Tile::Pos(const LDL_Vec2u& pos)
{
	_mapObject.Pos(pos);
}

void Tile::Init(Sprite* sprite)
{
	_body = sprite;
}

Sprite* Tile::Body()
{
	return _body;
}
