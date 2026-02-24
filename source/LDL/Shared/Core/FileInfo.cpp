// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/FileInfo.hpp>

using namespace LDL;

const std::string& FileInfo::Name()
{
	return _name;
}

void FileInfo::Name(const std::string& source)
{
	_name = source;
}
