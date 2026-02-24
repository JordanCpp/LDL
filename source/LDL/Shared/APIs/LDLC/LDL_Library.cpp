// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL_Library.h>
#include <LDL/Core/Library.hpp>

using namespace LDL;

struct LDL_Library
{
	Library _library;
	LDL_Library(const char* path);
};

LDL_Library::LDL_Library(const char* path) :
	_library(path)
{
}

LDL_Library* LDL_LibraryNew(const char * path)
{
	LDL_Library* p = new LDL_Library(path);

	return p;
}

void LDL_LibraryFree(LDL_Library* library)
{
	delete library;
}

LDL_VoidFuncPtr LDL_LibraryFunction(LDL_Library* library, const char* path)
{
	return library->_library.Function(path);
}
