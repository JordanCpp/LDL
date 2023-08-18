#ifndef Arcanum_Scripts_PlayerScript_hpp
#define Arcanum_Scripts_PlayerScript_hpp

#include <Arcanum/Objects/CritterScript.hpp>

namespace Arcanum
{
	namespace Scripts
	{
		class PlayerScript: public Objects::CritterScript
		{
		public:
			void MapEnter();
		private:
		};
	}
}

#endif