// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Time_FpsCounter_hpp
#define LDL_Time_FpsCounter_hpp

#include <LDL/Time/Ticks.hpp>

namespace LDL
{
	namespace Time
	{
		class LDL_LIBRARY FpsCounter
		{
		public:
			FpsCounter();
			void Start();
			bool Calc();
			size_t Fps();
			void Clear();
		private:
			size_t _current;
			size_t _delta;
			size_t _old;
			size_t _fps;
		};
	}
}

#endif     
