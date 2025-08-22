// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Library_hpp
#define LDL_Core_Library_hpp

#include <LDL/Core/Types.hpp>
#include <string>

namespace LDL
{
	typedef void(*VoidFuncPtr)(void);

	namespace Core
	{
		class LibraryImpl;

		class LDL_LIBRARY Library
		{
		public:
			Library(const std::string& path);
			~Library();
			VoidFuncPtr Function(const std::string& name);
		private:
			LibraryImpl* _impl;
		};
	}
}

#endif    
