// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Formats/Msg.hpp>

using namespace Arcanum;

size_t Msg::Number()
{
	return _Number;
}

void Msg::Number(size_t value)
{
	_Number = value;
}

const std::string& Msg::Content()
{
	return _Content;
}

void Msg::Content(const std::string& value)
{
	_Content = value;
}
