#ifndef LDL_Events_Mouse_hpp
#define LDL_Events_Mouse_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Enums/MouseButton.hpp>
#include <LDL/Enums/ButtonState.hpp>
#include <LDL/Enums/MouseScroll.hpp>

namespace LDL
{
	namespace Events
	{
		class Mouse
		{
		public:
			uint8_t Type;
			size_t  PosX;
			size_t  PosY;
			uint8_t State;
			uint8_t Button;
			size_t  Scroll;
			size_t  Delta;
		};
	}
}

#endif