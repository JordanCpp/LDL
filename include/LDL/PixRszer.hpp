// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_PixRszer_hpp
#define LDL_PixRszer_hpp

#include <LDL/Vec2.hpp>
#include <LDL/Surface.hpp>

class LDL_LIBRARY LDL_PixelResizer
{
public:
	LDL_PixelResizer(const LDL_Vec2u& size);
	LDL_Surface* LDL_Resize(const LDL_Vec2u& size, LDL_Surface* surface);
private:
	LDL_Surface _surface;
};

#endif    
