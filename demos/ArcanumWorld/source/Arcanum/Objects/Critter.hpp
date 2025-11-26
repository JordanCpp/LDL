// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_Critter_hpp
#define Arcanum_Objects_Critter_hpp

#include <Arcanum/Objects/CritterScript.hpp>
#include <Arcanum/Gameplay/StatCritter.hpp>
#include <Arcanum/Objects/MapObject.hpp>

namespace Arcanum
{
	class CritterScript;

	class Critter
	{
	public:
		void Init(CritterScript* script);
		const LDL_Vec2u& Pos();
		void Pos(const LDL_Vec2u& pos);
	private:
		CritterScript* _script;
		MapObject      _mapObject;
		StatCritter    _statCritter;
	};
}

#endif
