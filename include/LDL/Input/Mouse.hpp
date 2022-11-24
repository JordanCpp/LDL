#ifndef LDL_Input_Mouse_hpp
#define LDL_Input_Mouse_hpp

#if defined(WIN32) || defined(WIN64)
#include <LDL/Platforms/Windows/Input/Mouse.hpp>
namespace LDL
{
	namespace Input
	{
		typedef LDL::Input::Windows::Mouse Mouse;
	}
}
#else
#error Not implementation: Input::Mouse
#endif

#endif 