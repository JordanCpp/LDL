// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Gameplay_StatCritter_hpp
#define Arcanum_Gameplay_StatCritter_hpp

#include <Arcanum/Gameplay/StatValue.hpp>

namespace Arcanum
{
	class StatCritter
	{
	public:
		StatValue<int>& Strength();
		StatValue<int>& Constitution();
		StatValue<int>& Dexterity();
		StatValue<int>& Beauty();
		StatValue<int>& Intelligence();
		StatValue<int>& Willpower();
		StatValue<int>& Perception();
		StatValue<int>& Charisma();
	private:
		StatValue<int> _Strength;
		StatValue<int> _Constitution;
		StatValue<int> _Dexterity;
		StatValue<int> _Beauty;
		StatValue<int> _Intelligence;
		StatValue<int> _Willpower;
		StatValue<int> _Perception;
		StatValue<int> _Charisma;
		StatValue<int> _HitPoints;
	};
}

#endif    
