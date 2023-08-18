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