// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Result_hpp
#define LDL_Result_hpp

#include <LDL/Config.hpp>
#include <LDL/StrView.hpp>
#include <LDL/StrTypes.hpp>

class LDL_LIBRARY LDL_Result
{
public:
	LDL_Result();
	bool Ok();
	void Message(const char* message);
	void Message(const char* message, const char* detail);
	const char* Message();
	void Clear();
private:
	bool           _ok;
	LDL_StringView _message;
	char           _bufferMessage[LDL_ErrorMax];
};

#endif
