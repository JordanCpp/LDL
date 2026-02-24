#ifndef Arcanum_Objects_Critter_hpp
#define Arcanum_Objects_Critter_hpp

#include <Arcanum/Objects/CritterScript.hpp>
#include <Arcanum/Gameplay/StatCritter.hpp>
#include <Arcanum/Objects/MapObject.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class CritterScript;

		class Critter
		{
		public:
			void Init(CritterScript* script);
			const LDL::Vec2u& Pos();
			void Pos(const LDL::Vec2u& pos);
		private:
			MapObject _MapObject;
			CritterScript* _Script;
			Gameplay::StatCritter _StatCritter;
		};
	}
}

#endif