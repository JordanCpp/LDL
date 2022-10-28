#ifndef LDL_Events_Event_hpp
#define LDL_Events_Event_hpp

#include <cstdint>
#include <cstddef>

namespace LDL
{
	namespace Events
	{
		enum
		{
			IsQuit = 1,
			IsMouseMove,
			IsMouseClick
		};

		class Quit
		{
		public:
			uint8_t Type;
		};

		class Mouse
		{

		public:
			enum
			{
				ButtonLeft,
				ButtonRight
			};

			enum
			{
				StateUp,
				StateDown
			};

			uint8_t Type;
			size_t PosX;
			size_t PosY;
			uint8_t State;
			uint8_t Button;
		};

		class Event
		{
		public:
			union
			{
				uint8_t Type;
				Events::Quit Quit;
				Events::Mouse Mouse;
			};
		};
	}
}

#endif