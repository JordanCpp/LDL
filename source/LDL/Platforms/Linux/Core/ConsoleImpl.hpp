// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Linux_Core_ConsoleImpl_hpp
#define LDL_Platforms_Linux_Core_ConsoleImpl_hpp

#include <string>

namespace LDL
{
	namespace Core
	{
		class ConsoleImpl
		{
		public:
			ConsoleImpl();
			void Write(const std::string& text);
		private:
		};
	}
}

#endif    
