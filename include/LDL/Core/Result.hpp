// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Result_hpp
#define LDL_Core_Result_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/InPlaceStrings.hpp>

namespace LDL
{
	class LDL_LIBRARY Result
	{
	public:
		Result();
		bool Ok();
		void Message(const char* message);
		void Message(const char* message, const char* detail);
		const char* Message();
		void Clear();
	private:
		bool        _ok;
		ErrorString _message;
	};
}

#endif
