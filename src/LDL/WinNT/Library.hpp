// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_WinNT_Library_hpp
#define LDL_WinNT_Library_hpp

#include <LDL/Result.hpp>
#include <LDL/Library.hpp>
#include <LDL/WinNT/Windows.hpp>

class LDL_Library : public LDL_ILibrary
{
public:
	LDL_Library(LDL_Result& result);
	~LDL_Library();
	bool Open(const char* path);
	LDL_VoidFuncPtr Function(const char* name);
private:
	HMODULE    _module;
	LDL_Result _result;
};

#endif    
