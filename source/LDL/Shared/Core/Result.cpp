// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Result.hpp>

using namespace LDL::Core;

Result::Result() :
	_ok(true)
{
}

bool Result::Ok()
{
	return _ok;
}

void Result::Message(const char* message)
{
	_message = message;
}

void Result::Message(const char* message, const char* detail)
{
	_message = message;
	_message += detail;
}

const char* Result::Message()
{
	return _message.c_str();
}
