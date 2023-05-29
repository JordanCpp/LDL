#ifndef LDL_Graphics_Utils_PotTextureSizer_hpp
#define LDL_Graphics_Utils_PotTextureSizer_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace Utils
		{
			class PotTextureSizer
			{
			public:
				size_t Calc(const Math::Vec2u& size);
			private:
			};
		}
	}
}                                       

#endif