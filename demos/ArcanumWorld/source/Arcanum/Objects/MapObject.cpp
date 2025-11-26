// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/MapObject.hpp>

using namespace Arcanum;

const LDL_Vec2u& MapObject::Pos()
{
	return _pos;
}

void MapObject::Pos(const LDL_Vec2u& pos)
{
	_pos = pos;
}
