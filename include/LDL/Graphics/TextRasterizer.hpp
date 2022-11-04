#ifndef LDL_Graphics_TextRasterizer_hpp
#define LDL_Graphics_TextRasterizer_hpp

#include <LDL/Allocators/Allocator.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextRasterizer
		{
		public:
			TextRasterizer(LDL::Allocators::Allocator* allocator);
			~TextRasterizer();
			LDL::Graphics::CpuImage* Result();
		private:
			LDL::Allocators::Allocator* _Allocator;
			LDL::Graphics::CpuImage* _Result;
		};
	}
}

#endif 