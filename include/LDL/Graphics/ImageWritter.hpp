// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_ImageWriter_hpp
#define LDL_Graphics_ImageWriter_hpp

#include <LDL/Config.hpp>
#include <LDL/std/stddef.hpp>
#include <LDL/Math/Vec2u.hpp>

namespace LDL
{
	class LDL_LIBRARY ImageWriter
	{
	public:
		void Save(const char* path, const Vec2u& size, size_t bytesPerPixel, uint8_t* pixels);
	private:
	};
}

#endif    
