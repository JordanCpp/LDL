// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/FileInfo.hpp>

using namespace LDL;

const char* FileInfo::Name()
{
	return _name.c_str();
}

void FileInfo::Name(const char* source)
{
	_name = source;
}
