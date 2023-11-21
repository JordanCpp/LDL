#ifndef Arcanum_Objects_Scenery_hpp
#define Arcanum_Objects_Scenery_hpp

#include <Arcanum/Graphics/Sprite.hpp>
#include <Arcanum/Objects/MapObject.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Scenery
		{
		public:
			Scenery();
			void Init(Graphics::Sprite* sprite);
			Graphics::Sprite* Body();
			const LDL::Math::Vec2u& Pos();
			void Pos(const LDL::Math::Vec2u& pos);
		private:
			MapObject _MapObject;
			Graphics::Sprite* _Body;
		};
	}
}

#endif