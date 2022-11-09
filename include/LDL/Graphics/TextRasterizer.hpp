#ifndef LDL_Graphics_TextRasterizer_hpp
#define LDL_Graphics_TextRasterizer_hpp

#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <LDL/Loaders/FontBufferLoader.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextRasterizer
		{
		public:
			TextRasterizer();
			~TextRasterizer();
			LDL::Graphics::CpuImage* Result();
			void Create(LDL::Loaders::FontBufferLoader * fontBufferLoader, size_t size, const std::string& text);
		private:
			LDL::Graphics::CpuImage* _Result;
			uint8_t* _Bitmap;
		};
	}
}

#endif 