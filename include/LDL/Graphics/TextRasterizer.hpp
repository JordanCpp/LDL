#ifndef LDL_Graphics_TextRasterizer_hpp
#define LDL_Graphics_TextRasterizer_hpp

#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <LDL/Loaders/FontLoader.hpp>

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
			void Create(LDL::Loaders::FontLoader * fontBufferLoader, size_t size, const std::string& text);
		private:
			LDL::Allocators::Allocator* _Allocator;
			LDL::Graphics::CpuImage* _Result;
			uint8_t* _Bitmap;
		};
	}
}

#endif 