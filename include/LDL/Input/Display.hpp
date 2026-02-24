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
			const std::vector<VideoMode>& Modes();
			const VideoMode& Current();
		private:
			VideoMode              _videoMode;
			std::vector<VideoMode> _videoModes;
		};
	}
}

#endif     
