// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_VideoMode_hpp
#define LDL_Graphics_VideoMode_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>
#include <LDL/Vec2u.hpp>

class LDL_LIBRARY LDL_VideoMode
{
public:
	enum
	{
		Limit = 32
	};
	LDL_VideoMode();
	LDL_VideoMode(const LDL_Vec2u& size, size_t bytesPerPixel);
	const LDL_Vec2u& Size();
	size_t BitsPerPixel();
private:
	LDL_Vec2u  _size;
	size_t _bitsPerPixel;
};

#endif
