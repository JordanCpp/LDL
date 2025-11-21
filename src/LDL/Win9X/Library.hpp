// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Win9X_Library_hpp
#define LDL_Win9X_Library_hpp

#include <LDL/Library.hpp>
#include <LDL/Win9X/Windows.hpp>

class LDL_Library : public LDL_ILibrary
{
public:
	LDL_Library(const char* path);
	~LDL_Library();
	VoidFuncPtr Function(const char* name);
private:
	HMODULE _module;
};

#endif    
