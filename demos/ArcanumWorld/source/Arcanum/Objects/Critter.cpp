// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/Critter.hpp>

using namespace Arcanum;

void Critter::Init(CritterScript* script)
{
	_script = script;
}

const LDL_Vec2u& Critter::Pos()
{
	return _mapObject.Pos();
}

void Critter::Pos(const LDL_Vec2u& pos)
{
	_mapObject.Pos(pos);
}
