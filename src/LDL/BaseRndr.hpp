// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_BaseRndr_hpp
#define LDL_BaseRndr_hpp

#include <LDL/Config.hpp>
#include <LDL/Vec2u.hpp>
#include <LDL/Color.hpp>

class LDL_LIBRARY LDL_BaseRender
{
public:
	LDL_BaseRender(const LDL_Vec2u& size);
	const LDL_Vec2u& Size();
	const LDL_Color& GetColor();
	void SetColor(const LDL_Color& color);
public:
	LDL_Color _current;
	LDL_Vec2u _size;
};

#endif    
