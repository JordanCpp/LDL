// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_ScreenShotter_hpp
#define LDL_Graphics_ScreenShotter_hpp

#include <LDL/Graphics/Render.hpp>

namespace LDL
{
	namespace Graphics
	{
		class ScreenShotterImpl;

		class ScreenShotter
		{
		public:
			ScreenShotter(const char* path, const char* name, Render* render, Surface* image);
			~ScreenShotter();
			void Shot();
		private:
			ScreenShotterImpl* _impl;
		};
	}
}

#endif  
