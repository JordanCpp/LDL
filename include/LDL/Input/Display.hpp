// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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
