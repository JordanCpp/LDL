#ifndef LDL_Events_Mouse_hpp
#define LDL_Events_Mouse_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Events
	{
		class Mouse
		{
		public:
			enum
			{
				Left,
				Right,
				Up,
				Down
			};
			uint8_t Type;
			size_t PosX;
			size_t PosY;
			uint8_t State;
			uint8_t Button;
		};
	}
}

#endif