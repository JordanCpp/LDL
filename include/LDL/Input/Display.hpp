#ifndef LDL_Input_Display_hpp
#define LDL_Input_Display_hpp

#include <LDL/Graphics/VideoMode.hpp>
#include <vector>

namespace LDL
{
	namespace Input
	{
		class LDL_LIBRARY Display
		{
		public:
			Display();
			const std::vector<Graphics::VideoMode>& Modes();
			const Graphics::VideoMode& Current();
		private:
			Graphics::VideoMode              _videoMode;
			std::vector<Graphics::VideoMode> _videoModes;
		};
	}
}

#endif     
