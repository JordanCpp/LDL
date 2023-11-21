#ifndef Arcanum_Gameplay_StatCritter_hpp
#define Arcanum_Gameplay_StatCritter_hpp

#include <Arcanum/Gameplay/StatValue.hpp>

namespace Arcanum
{
	namespace Gameplay
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
}

#endif    