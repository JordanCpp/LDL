// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Result.hpp>

LDL_Result::LDL_Result() :
	_ok(true)
{
}

bool LDL_Result::Ok()
{
	return _ok;
}

void LDL_Result::Message(const char* message)
{
	_message = message;
}

void LDL_Result::Message(const char* message, const char* detail)
{
	_message = message;
	_message += detail;
}

const char* LDL_Result::Message()
{
	return _message.c_str();
}

void LDL_Result::Clear()
{
	_ok = false;
	_message.clear();
}
