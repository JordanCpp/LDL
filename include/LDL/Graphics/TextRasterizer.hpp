#ifndef LDL_Graphics_TextRasterizer_hpp
#define LDL_Graphics_TextRasterizer_hpp

#include <LDL/Graphics/Surface.hpp>
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
			Surface* Result();
			void Create(LDL::Loaders::FontLoader * fontBufferLoader, size_t size, const std::string& text);
		private:
			LDL::Allocators::Allocator* _Allocator;
			Surface* _Result;
			uint8_t* _Bitmap;
		};
	}
}

#endif 