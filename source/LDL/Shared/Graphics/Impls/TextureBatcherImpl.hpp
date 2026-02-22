// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_TextureBatcherImpl_hpp
#define LDL_Graphics_TextureBatcherImpl_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureBatcherImpl
		{
		public:
			virtual ~TextureBatcherImpl() {};
			virtual void Draw(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize) = 0;
			virtual void Clear() = 0;
		};
	}
}

#endif    
