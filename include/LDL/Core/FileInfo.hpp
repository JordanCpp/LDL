// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_FileInfo_hpp
#define LDL_Core_FileInfo_hpp

#include <string>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	class LDL_LIBRARY FileInfo
	{
	public:
		const std::string& Name();
		void Name(const std::string& source);
	private:
		std::string _name;
	};
}

#endif
