// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_VideoMode_hpp
#define LDL_Graphics_VideoMode_hpp

#include <LDL/Config.hpp>
#include <LDL/std/stddef.hpp>
#include <LDL/Math/Vec2u.hpp>

namespace LDL
{
	class LDL_LIBRARY VideoMode
	{
	public:
		enum
		{
			Limit = 32
		};
		VideoMode();
		VideoMode(const Vec2u& size, size_t bytesPerPixel);
		const Vec2u& Size();
		size_t BitsPerPixel();
	private:
		Vec2u  _size;
		size_t _bitsPerPixel;
	};
}

#endif    
