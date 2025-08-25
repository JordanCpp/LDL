// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_FileInfo_hpp
#define LDL_Core_FileInfo_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/STL/inplace_strings.hpp>

namespace LDL
{
	namespace Core
	{
		class LDL_LIBRARY FileInfo
		{
		public:
			const char* Name();
			void Name(const char* source);
		private:
			FileString _name;
		};
	}
}

#endif
