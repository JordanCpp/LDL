// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Gameplay/StatCritter.hpp>

using namespace Arcanum;

StatValue<int>& StatCritter::Strength()
{
	return _Strength;
}

StatValue<int>& StatCritter::Constitution()
{
	return _Constitution;
}

StatValue<int>& StatCritter::Dexterity()
{
	return _Dexterity;
}

StatValue<int>& StatCritter::Beauty()
{
	return _Beauty;
}

StatValue<int>& StatCritter::Intelligence()
{
	return _Intelligence;
}

StatValue<int>& StatCritter::Willpower()
{
	return _Willpower;
}

StatValue<int>& StatCritter::Perception()
{
	return _Perception;
}

StatValue<int>& StatCritter::Charisma()
{
	return _Charisma;
}
