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
		private:
			LDL::Allocators::Allocator* _Allocator;
		};
	}
}

#endif 