// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Palette_hpp
#define LDL_Graphics_Palette_hpp

#include <LDL/Graphics/Color.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY Palette
		{
		public:
			enum
			{
				Max = 256
			};
			Palette();
			Color* Colors();
			size_t Count();
		private:
			Color _colors[Max];
		};
	}
}

#endif    