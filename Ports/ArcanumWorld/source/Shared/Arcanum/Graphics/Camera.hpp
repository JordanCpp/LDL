#ifndef Arcanum_Graphics_Camera_hpp
#define Arcanum_Graphics_Camera_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Math/Rect.hpp>
#include <LDL/Events/Event.hpp>

namespace Arcanum
{
	namespace Graphics
	{
		class Camera
		{
		public:
			Camera(const LDL::Math::Vec2u& pos, const LDL::Math::Vec2u& size);
			const LDL::Math::Vec2u& Pos();
			const LDL::Math::Vec2u& Size();
			void Move(const LDL::Math::Vec2u& pos);
			void Handle(LDL::Events::Event& event);
		private:
			LDL::Math::Rectu _Area;
			size_t _Step;
		};
	}
}

#endif    