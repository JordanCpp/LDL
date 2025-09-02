// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Impls_ScreenShotterImpl_hpp
#define LDL_Graphics_Impls_ScreenShotterImpl_hpp

namespace LDL
{
	class ScreenShotterImpl
	{
	public:
		virtual ~ScreenShotterImpl() {};
		virtual void Shot() = 0;
	};
}

#endif    
