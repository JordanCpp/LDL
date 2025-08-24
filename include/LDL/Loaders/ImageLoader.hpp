// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Loaders_ImageLoader_hpp
#define LDL_Loaders_ImageLoader_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/Allocators/Allocator.hpp>
#include <LDL/Containers/inplace_strings.hpp>

namespace LDL
{
	namespace Loaders
	{
		class LDL_LIBRARY ImageLoader
		{
		public:
			ImageLoader(Allocators::Allocator* allocator);
			~ImageLoader();
			void Clear();
			const Math::Vec2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			void CopyIf(uint8_t* dstPixels, uint8_t* srcPixels, size_t bytes, const Graphics::Color& color, uint8_t alpha);
			void Load(const char* path);
			void Load(const Graphics::Color& color, const char* path);
			void Load(uint8_t * data, size_t bytes);
			void Load(const Graphics::Color& color, uint8_t* data, size_t bytes);
		private:
			AssertString _assert;
			Allocators::Allocator* _allocator;
			Math::Vec2u            _size;
			uint8_t                _bytesPerPixel;
			uint8_t*               _pixels;
		};
	}
}

#endif     
