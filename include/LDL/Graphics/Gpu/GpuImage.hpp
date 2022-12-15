#ifndef LDL_Graphics_GpuImage_hpp
#define LDL_Graphics_GpuImage_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuImageImpl;

		class GpuImage : public LDL::Core::FastPimpl
		{
		public:
			GpuImage(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels);
			~GpuImage();
			const Point2u& Size();
			size_t Id();
		private:
			GpuImageImpl* _GpuImageImpl;
		};
	}
}

#endif    