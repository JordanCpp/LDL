#ifndef LDL_Input_Mouse_hpp
#define LDL_Input_Mouse_hpp

#include <LDL/Config.hpp>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Input
	{
		class LDL_LIBRARY Mouse
		{
		public:
			const Math::Vec2u& Pos();
			void Pos(const Math::Vec2u& pos);
			void Hide();
			void Show();
		private:
			LDL::Math::Vec2u _Pos;
		};
	}
}

#endif  
