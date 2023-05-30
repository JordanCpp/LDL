#ifndef LDL_Graphics_Color_hpp
#define LDL_Graphics_Color_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Config.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT Color
		{
		public:
			Color();
			Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
			uint32_t toInt() const;

        #if defined(LDL_CONFIG_COLOR_BGRA)
			uint8_t b;
			uint8_t g;
			uint8_t r;
        #else
			uint8_t r;
			uint8_t g;
			uint8_t b;
        #endif
			uint8_t a;
		};
	}
}

#endif    