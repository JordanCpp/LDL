// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelWriter_hpp
#define LDL_Graphics_PixelWriter_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>
#include <LDL/Math/Vec2u.hpp>

namespace LDL
{
	class LDL_LIBRARY PixelWriter
	{
	public:
		void Save(const char* path, const Vec2u& size, size_t bytesPerPixel, uint8_t* pixels);
	private:
	};
}

#endif    
