// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Surface_hpp
#define LDL_Graphics_Surface_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/STL/vector.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/Graphics/PixelFormat.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY Surface
		{
		public:
			Surface(const Math::Vec2u& size, uint8_t bytesPerPixel);
			Surface(const Math::Vec2u& size, uint8_t * pixels, uint8_t bytesPerPixel);
			Surface(const Math::Vec2u& size, const Math::Vec2u& capacity, uint8_t bytesPerPixel);
			Surface(const Math::Vec2u& size, const Math::Vec2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel);
			~Surface();
			void ColorKey(const Graphics::Color& key);
			const Graphics::Color& ColorKey();
			bool Enabled();
			const Math::Vec2u& Capacity();
			const Math::Vec2u& Size();
			void Resize(const Math::Vec2u& size);
			void Clear();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			Color Pixel(const Math::Vec2u& pos);
		private:
			uint8_t         _bytesPerPixel;
			bool            _enabled;
			Graphics::Color _key;
			Math::Vec2u     _capacity;
			Math::Vec2u     _size;
			vector<uint8_t> _pixels;
		};
	}
}

#endif 
