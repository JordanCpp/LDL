#ifndef LDL_Events_Event_hpp
#define LDL_Events_Event_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Events/Mouse.hpp>
#include <LDL/Events/Quit.hpp>
#include <LDL/Events/Resize.hpp>

namespace LDL
{
	namespace Events
	{
		enum
		{
			IsQuit = 1,
			IsMouseMove,
			IsMouseClick,
			IsResize
		};

		class Event
		{
		public:
			union
			{
				uint8_t Type;
				LDL::Events::Quit Quit;
				LDL::Events::Mouse Mouse;
				LDL::Events::Resize Resize;
			};
		};
	}
}

#endif