// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Library_hpp
#define LDL_Library_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

typedef void(*LDL_VoidFuncPtr)(void);

class LDL_ILibrary
{
public:
	virtual ~LDL_ILibrary() {};
	virtual LDL_VoidFuncPtr Function(const char* name) = 0;
};

LDL_ILibrary* LDL_CreateLibrary(const char* name);

#endif    
