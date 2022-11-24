#ifndef LDL_Input_Display_hpp
#define LDL_Input_Display_hpp

#if defined(WIN32) || defined(WIN64)
#include <LDL/Platforms/Windows/Input/Display.hpp>
namespace LDL
{
	namespace Input
	{
		typedef LDL::Input::Windows::Display Display;
	}
}
#else
#error Not implementation: Input::Display
#endif

#endif 