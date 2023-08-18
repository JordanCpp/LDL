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
			const LDL::Math::Vec2u& Pos();
			void Pos(const LDL::Math::Vec2u& pos);
		private:
			LDL::Math::Vec2u _Pos;
		};
	}
}

#endif