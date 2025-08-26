// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_CritterScript_hpp
#define Arcanum_Objects_CritterScript_hpp

#include <Arcanum/Objects/Script.hpp>
#include <Arcanum/Objects/Critter.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Critter;

		class CritterScript : public Script
		{
		public:
			Critter* Self();
			void Init(Critter* critter);
		private:
			Critter* _Critter;
		};
	}
}

#endif