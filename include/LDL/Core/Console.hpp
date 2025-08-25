// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Console_hpp
#define LDL_Core_Console_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
    namespace Core
    {
		class ConsoleImpl;

		class LDL_LIBRARY Console
		{
		public:
			Console();
			~Console();
			void Write(const char* text);
		private:
			ConsoleImpl* _impl;
		};
    }
}

#endif
