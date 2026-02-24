// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_ImageResizer_hpp
#define LDL_Graphics_ImageResizer_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	class LDL_LIBRARY ImageResizer
	{
	public:
		ImageResizer(const Vec2u& size);
		Surface* Resize(const Vec2u& size, Surface* surface);
	private:
		Surface _surface;
	};
}

#endif    
