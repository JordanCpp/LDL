// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Enums_RenderMode_hpp
#define LDL_Enums_RenderMode_hpp

namespace LDL
{
	class RenderMode
	{
	public:
		enum
		{
			Software = 1,
			OpenGL1,
			OpenGL3,
			DirectDraw,
			Glide,
			Direct3D6,
			Max
		};
	};
}

#endif
