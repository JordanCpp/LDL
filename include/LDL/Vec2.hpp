// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Vec2_hpp
#define LDL_Vec2_hpp

#include <LDL/Types.hpp>

template<class T>
class LDL_Vec2
{
public:
	LDL_Vec2()
	{
		x = T();
		y = T();
	}

	LDL_Vec2(T v1, T v2)
	{
		x = v1;
		y = v2;
	}

	T x;
	T y;
};

#endif     
