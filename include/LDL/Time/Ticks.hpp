#ifndef LDL_Time_Ticks_hpp
#define LDL_Time_Ticks_hpp

#include <cstddef>

namespace LDL
{
	namespace Time
	{
		size_t Ticks();
		void Delay(size_t count);
	}
}

#endif    