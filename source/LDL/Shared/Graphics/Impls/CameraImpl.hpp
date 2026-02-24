// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_CameraImpl_hpp
#define LDL_Graphics_CameraImpl_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	class CameraImpl
	{
	public:
		virtual ~CameraImpl() {}
		virtual const Vec2u& Pos() = 0;
		virtual const Vec2u& Size() = 0;
		virtual void Pos(const Vec2u& pos) = 0;
		virtual void Size(const Vec2u& size) = 0;
	};
}

#endif    
