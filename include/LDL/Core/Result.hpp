// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Result_hpp
#define LDL_Core_Result_hpp

#include <LDL/STL/InplaceStrings.hpp>

namespace LDL
{
	class LDL_LIBRARY Result
	{
	public:
		Result();
		bool Ok();
		void Message(const char* message);
		const char* Message();
	private:
		bool        _ok;
		ErrorString _message;
	};
}

#endif