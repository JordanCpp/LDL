// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Utils_PotTextureSizer_hpp
#define LDL_Graphics_Utils_PotTextureSizer_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace Utils
		{
			class PotTextureSizer
			{
			public:
				size_t Calc(const Math::Vec2u& size);
			private:
			};
		}
	}
}                                       

#endif
