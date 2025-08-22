// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Time_FpsLimiter_hpp
#define LDL_Time_FpsLimiter_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Time
	{
		class LDL_LIBRARY FpsLimiter
		{
		public:
			FpsLimiter(size_t fps = 60);
			void Mark();
			void Throttle() const;
		private:
			size_t _fps;
			size_t _ticks;
		};
	}
}

#endif    
