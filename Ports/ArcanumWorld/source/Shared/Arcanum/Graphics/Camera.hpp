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
			Camera(const LDL::Vec2u& pos, const LDL::Vec2u& size);
			const LDL::Vec2u& Pos();
			const LDL::Vec2u& Size();
			void Move(const LDL::Vec2u& pos);
			void Handle(LDL::Event& event);
		private:
			uint32_t   _step;
			LDL::Rectu _area;
		};
	}
}

#endif    