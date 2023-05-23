#ifndef LDL_Events_Event_hpp
#define LDL_Events_Event_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Events/Mouse.hpp>
#include <LDL/Events/Quit.hpp>
#include <LDL/Events/Resize.hpp>
#include <LDL/Events/Keyboard.hpp>
#include <LDL/Events/GainedFocus.hpp>
#include <LDL/Events/LostFocus.hpp>

namespace LDL
{
	namespace Events
	{
		enum
		{
			IsQuit = 1,
			IsMouseMove,
			IsMouseClick,
			IsResize,
			IsKeyboard,
			IsGainedFocus,
			IsLostFocus,
			IsMouseScroll
		};

		class Event
		{
		public:
			union
			{
				uint8_t Type;
				LDL::Events::Quit        Quit;
				LDL::Events::Mouse       Mouse;
				LDL::Events::Resize      Resize;
				LDL::Events::Keyboard    Keyboard;
				LDL::Events::GainedFocus GainedFocus;
				LDL::Events::LostFocus   LostFocus;
			};

			bool IsKeyPressed(size_t key)
			{
				return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == Enums::ButtonState::Pressed);
			}

			bool IsKeyReleased(size_t key)
			{
				return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == Enums::ButtonState::Released);
			}

			bool IsMousePressed(size_t key)
			{
				return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == Enums::ButtonState::Pressed);
			}

			bool IsMouseReleased(size_t key)
			{
				return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == Enums::ButtonState::Released);
			}
		};
	}
}

#endif