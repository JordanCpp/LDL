#ifndef LDL_Time_Ticks_hpp
#define LDL_Time_Ticks_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Time
	{
		LDL_EXPORT size_t Ticks();
		LDL_EXPORT void Delay(size_t count);
	}
}

#endif    