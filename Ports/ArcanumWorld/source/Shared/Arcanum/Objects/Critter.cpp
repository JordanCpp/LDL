// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/Critter.hpp>

using namespace LDL::Math;
using namespace Arcanum::Objects;

void Critter::Init(CritterScript* script)
{
	_Script = script;
}

const Vec2u& Critter::Pos()
{
	return _MapObject.Pos();
}

void Critter::Pos(const Vec2u& pos)
{
	_MapObject.Pos(pos);
}