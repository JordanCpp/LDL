// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/New.hpp>
#include <LDL/MemMngr.hpp>

LDL_MemoryManager* LDL_MemoryManager::_instance = NULL;
char LDL_MemoryManager::_bytes[LDL_MemoryManager::SizeOf];

LDL_MemoryManager::LDL_MemoryManager() :
	_mallocFunc(NULL),
	_callocFunc(NULL),
	_reallocFunc(NULL),
	_freeFunc(NULL)
{
}

LDL_MemoryManager::~LDL_MemoryManager()
{
	_mallocFunc  = NULL;
	_callocFunc  = NULL;
	_reallocFunc = NULL;
	_freeFunc    = NULL;
	_instance    = NULL;
}

LDL_MemoryManager& LDL_MemoryManager::Instance()
{
	if (_instance == NULL)
	{
		_instance = new(&_bytes) LDL_MemoryManager();
	}

	return *_instance;
}

bool LDL_MemoryManager::Functions(mallocFunc malloc_func, callocFunc calloc_func, reallocFunc realloc_func, freeFunc free_func)
{
	_mallocFunc  = malloc_func;
	_callocFunc  = calloc_func;
	_reallocFunc = realloc_func;
	_freeFunc    = free_func;

	return true;
}

mallocFunc LDL_MemoryManager::GetMalloc()
{
	return _mallocFunc;
}

callocFunc LDL_MemoryManager::GetCalloc()
{
	return _callocFunc;
}

reallocFunc LDL_MemoryManager::GetRealloc()
{
	return _reallocFunc;
}

freeFunc LDL_MemoryManager::GetFree()
{
	return _freeFunc;
}
