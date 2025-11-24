// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Video_hpp
#define LDL_Video_hpp

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
	size_t     _bitsPerPixel;
	LDL_Vec2u  _size;
};

#endif
