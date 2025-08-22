// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "fstream.hpp"

using namespace std;

fstream::fstream()
{
}
fstream::fstream(const char* path, int mode)
{
}

bool fstream::open(const char* path, int mode)
{
	return false;
}

bool fstream::is_open()
{
	return false;
}

void fstream::close()
{
}
