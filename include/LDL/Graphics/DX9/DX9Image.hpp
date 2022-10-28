#ifndef LDL_Graphics_DX9Image_hpp
#define LDL_Graphics_DX9Image_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class DX9Image
		{
		public:
			DX9Image(const LDL::Graphics::Point2u & size, size_t bytesPerPixel, uint8_t* pixels);
			~DX9Image();
			const LDL::Graphics::Point2u& Size();
			const size_t Id();
		private:
			size_t _Id;
			LDL::Graphics::Point2u _Size;
		};
	}
}

#endif    