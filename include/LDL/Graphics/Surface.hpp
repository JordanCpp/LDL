// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Surface_hpp
#define LDL_Graphics_Surface_hpp

#include <LDL/Math/Vec2u.hpp>
#include <LDL/STL/vector.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/Graphics/PixelFormat.hpp>

namespace LDL
{
	class LDL_LIBRARY Surface
	{
	public:
		Surface(size_t pixelFormat, const Vec2u& size);
		Surface(size_t pixelFormat, const Vec2u& size, uint8_t* pixels);
		Surface(size_t pixelFormat, const Vec2u& size, const Vec2u& capacity);
		Surface(size_t pixelFormat, const Vec2u& size, const Vec2u& capacity, uint8_t* pixels);
		~Surface();
		void ColorKey(const LDL::Color& key);
		const LDL::Color& ColorKey();
		bool Enabled();
		const Vec2u& Capacity();
		const Vec2u& Size();
		void Resize(const Vec2u& size);
		void Clear();
		uint8_t BytesPerPixel();
		uint8_t* Pixels();
		size_t Format();
	private:
		bool            _enabled;
		LDL::Color      _key;
		size_t          _pixelFormat;
		Vec2u           _capacity;
		Vec2u           _size;
		vector<uint8_t> _pixels;
	};
}

#endif 
