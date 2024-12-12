#ifndef LDL_Time_Ticks_hpp
#define LDL_Time_Ticks_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Time
	{
		LDL_LIBRARY size_t Ticks();
		LDL_LIBRARY void Delay(size_t count);
	}
}

#endif    
