#ifndef Arcanum_Objects_MapObject_hpp
#define Arcanum_Objects_MapObject_hpp

#include <LDL/Math/Vec2.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class MapObject
		{
		public:
			const LDL::Vec2u& Pos();
			void Pos(const LDL::Vec2u& pos);
		private:
			LDL::Vec2u _Pos;
		};
	}
}

#endif