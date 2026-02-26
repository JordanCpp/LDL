// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Loaders_ImageLoader_hpp
#define LDL_Loaders_ImageLoader_hpp

#include <string>
#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	class LDL_LIBRARY ImageLoader
	{
	public:
		ImageLoader(Allocator* allocator);
		~ImageLoader();
		void Clear();
		const Vec2u& Size();
		uint8_t BytesPerPixel();
		uint8_t* Pixels();
		void CopyIf(uint8_t* dstPixels, uint8_t* srcPixels, size_t bytes, const Color& color, uint8_t alpha);
		void Load(const char* path);
		void Load(const Color& color, const char* path);
		void Load(uint8_t* data, size_t bytes);
		void Load(const Color& color, uint8_t* data, size_t bytes);
	private:
		std::string  _assert;
		Allocator*   _allocator;
		Vec2u        _size;
		uint8_t      _bytesPerPixel;
		uint8_t*     _pixels;
	};
}

#endif     
