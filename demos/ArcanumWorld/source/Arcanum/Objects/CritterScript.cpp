// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/CritterScript.hpp>

using namespace Arcanum;

Critter* CritterScript::Self()
{
	return _critter;
}

void CritterScript::Init(Critter* critter)
{
	_critter = critter;
}
