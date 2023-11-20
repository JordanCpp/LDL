#ifndef LDL_Graphics_Color_hpp
#define LDL_Graphics_Color_hpp

#include <LDL/Config.hpp>

namespace LDL
{
	namespace Graphics
	{
		class Color
		{
		public:
			Color() :
#if defined(LDL_CONFIG_COLOR_BGRA)
				b(0),
				g(0),
				r(0),
#else
				r(0),
				g(0),
				b(0),
#endif
				a(255)
			{
			}

			Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255) :
#if defined(LDL_CONFIG_COLOR_BGRA)
				b(blue),
				g(green),
				r(red),
#else
				r(red),
				g(green),
				b(blue),
#endif
				a(alpha)
			{
			}

			uint32_t toInt() const
			{
				return (uint32_t)((r << 24) | (g << 16) | (b << 8) | a);
			}

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
