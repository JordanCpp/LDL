#ifndef LDL_Graphics_PixelCopier_hpp
#define LDL_Graphics_PixelCopier_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class PixelCopier
		{
		public:
			void Copy(Surface* srcSurf, Surface* dstSurf, const Point2u& pos);
		private:
		};
	}
}

#endif 