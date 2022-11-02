#ifndef LDL_Loaders_ImageBufferLoader_hpp
#define LDL_Loaders_ImageBufferLoader_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Allocators/Allocator.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>
#include <string>

namespace LDL
{
	namespace Loaders
	{
		class ImageBufferLoader
		{
		public:
			ImageBufferLoader(LDL::Allocators::Allocator* allocator);
			~ImageBufferLoader();
			void Clear();
			const LDL::Graphics::Point2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			void Load(const std::string& path);
			void Load(const LDL::Graphics::Color& color, const std::string& path);
		private:
			LDL::Allocators::Allocator* _Allocator;
			LDL::Graphics::Point2u _Size;
			uint8_t _BytesPerPixel;
			uint8_t* _Pixels;
		};
	}
}

#endif     