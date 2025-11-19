// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Color_hpp
#define LDL_Graphics_Color_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

class LDL_LIBRARY LDL_Color
{
public:
	LDL_Color();
	LDL_Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
	uint32_t toInt() const;

	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

#endif
