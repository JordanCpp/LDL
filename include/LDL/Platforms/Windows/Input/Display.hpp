#ifndef LDL_Platforms_Windows_Input_Display_hpp
#define LDL_Platforms_Windows_Input_Display_hpp

#include <LDL/Graphics/VideoMode.hpp>
#include <vector>

namespace LDL
{
	namespace Input
	{
		namespace Windows
		{
			class Display
			{
			public:
				Display();
				const std::vector<LDL::Graphics::VideoMode>& Modes();
				const LDL::Graphics::VideoMode& Current();
			private:
				LDL::Graphics::VideoMode _VideoMode;
				std::vector<LDL::Graphics::VideoMode> _VideoModes;
			};
		}
	}
}
#endif     