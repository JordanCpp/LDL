#ifndef LDL_Graphics_Utils_PotTextureSizer_hpp
#define LDL_Graphics_Utils_PotTextureSizer_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace Utils
		{
			class PotTextureSizer
			{
			public:
				size_t Calc(const Point2u& size);
			private:
			};
		}
	}
}                                       

#endif