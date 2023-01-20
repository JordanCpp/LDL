#ifndef LDL_Config_hpp
#define LDL_Config_hpp

#include <LDL/Core/Types.hpp>

#if defined(_WIN32) || defined(WIN32)
#define LDL_CONFIG_COLOR_BGRA
#endif

namespace LDL
{
	namespace Config
	{
		const size_t BytesPerPixelDefault = 4;
	}
}

#endif    