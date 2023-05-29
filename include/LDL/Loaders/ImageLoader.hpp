#ifndef LDL_Loaders_ImageLoader_hpp
#define LDL_Loaders_ImageLoader_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Allocators/Allocator.hpp>
#include <LDL/Graphics/Color.hpp>
#include <string>

namespace LDL
{
	namespace Loaders
	{
		class LDL_EXPORT ImageLoader
		{
		public:
			ImageLoader(LDL::Allocators::Allocator* allocator);
			~ImageLoader();
			void Clear();
			const Math::Vec2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			void CopyIf(uint8_t* dstPixels, uint8_t* srcPixels, size_t bytes, const LDL::Graphics::Color& color, uint8_t alpha);
			void Load(const std::string& path);
			void Load(const LDL::Graphics::Color& color, const std::string& path);
			void Load(uint8_t * data, size_t bytes);
			void Load(const LDL::Graphics::Color& color, uint8_t* data, size_t bytes);
		private:
			LDL::Allocators::Allocator* _Allocator;
			LDL::Math::Vec2u _Size;
			uint8_t _BytesPerPixel;
			uint8_t* _Pixels;
		};
	}
}

#endif      