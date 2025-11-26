// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Palette_hpp
#define LDL_Palette_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>
#include <LDL/Color.hpp>

class LDL_LIBRARY LDL_Palette
{
public:
	enum
	{
		Max = 256
	};
	LDL_Palette();
	LDL_Color* Colors();
	size_t Count();
private:
	LDL_Color _colors[Max];
};

#endif
