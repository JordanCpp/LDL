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
			void Copy(Surface* srcSurf, Surface* dstSurf, const Math::Vec2u& pos);
			void Copy8(Surface* srcSurf, Surface* dstSurf, const Math::Vec2u& pos);
			void Copy16(Surface* srcSurf, Surface* dstSurf, const Math::Vec2u& pos);
			void Copy24(Surface* srcSurf, Surface* dstSurf, const Math::Vec2u& pos);
			void Copy32(Surface* srcSurf, Surface* dstSurf, const Math::Vec2u& pos);
		private:
		};
	}
}

#endif 