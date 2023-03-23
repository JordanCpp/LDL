#ifndef LDL_Input_Display_hpp
#define LDL_Input_Display_hpp

#include <LDL/Graphics/VideoMode.hpp>
#include <vector>

namespace LDL
{
	namespace Input
	{
		class LDL_EXPORT Display
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

#endif     