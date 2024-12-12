#ifndef LDL_Graphics_VideoMode_hpp
#define LDL_Graphics_VideoMode_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY VideoMode
		{
		public:
			enum
			{
				Limit = 32
			};
			VideoMode();
			VideoMode(const Math::Vec2u& size, size_t bytesPerPixel);
			const Math::Vec2u& Size();
			size_t BitsPerPixel();
		private:
			LDL::Math::Vec2u _size;
			size_t           _bitsPerPixel;
		};
	}
}

#endif    
