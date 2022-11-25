#ifndef LDL_Events_Keyboard_hpp
#define LDL_Events_Keyboard_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Enums/ButtonState.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

namespace LDL
{
	namespace Events
	{
		class Keyboard
		{
		public:
			uint8_t Type;
			uint8_t State;
			size_t Key;
		};
	}
}

#endif