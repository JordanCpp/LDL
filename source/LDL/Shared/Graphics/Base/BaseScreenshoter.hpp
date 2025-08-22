// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_BaseScreenShotter_hpp
#define LDL_Graphics_BaseScreenShotter_hpp

#include <LDL/Core/Convert.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY BaseScreenShotter
		{
		public:
			const std::string Prefix();
		private:
			std::string   _prefix;
			Core::Convert _converter;
		};
	}
}

#endif    
