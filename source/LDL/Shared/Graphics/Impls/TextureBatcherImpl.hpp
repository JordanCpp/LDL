// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Impls_SpriteBatcherImpl_hpp
#define LDL_Graphics_Impls_SpriteBatcherImpl_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	class SpriteBatcherImpl
	{
	public:
		virtual ~SpriteBatcherImpl() {};
		virtual void Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize) = 0;
		virtual void Clear() = 0;
	};
}

#endif    
