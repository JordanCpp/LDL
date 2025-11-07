// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/STL/new.hpp>
#include <LDL/Core/MemoryManager.hpp>

using namespace LDL;

MemoryManager* MemoryManager::_instance = NULL;
char MemoryManager::_bytes[SizeOf];

MemoryManager::MemoryManager() :
	_mallocFunc(NULL),
	_callocFunc(NULL),
	_reallocFunc(NULL),
	_freeFunc(NULL)
{
}

MemoryManager::~MemoryManager()
{
	_mallocFunc  = NULL;
	_callocFunc  = NULL;
	_reallocFunc = NULL;
	_freeFunc    = NULL;
	_instance    = NULL;
}

MemoryManager& MemoryManager::Instance()
{
	if (_instance == NULL)
	{
		_instance = new(&_bytes) MemoryManager();
	}

	return *_instance;
}

bool MemoryManager::Functions(mallocFunc malloc_func, callocFunc calloc_func, reallocFunc realloc_func, freeFunc free_func)
{
	_mallocFunc  = malloc_func;
	_callocFunc  = calloc_func;
	_reallocFunc = realloc_func;
	_freeFunc    = free_func;

	return true;
}

mallocFunc MemoryManager::GetMalloc()
{
	return _mallocFunc;
}

callocFunc MemoryManager::GetCalloc()
{
	return _callocFunc;
}

reallocFunc MemoryManager::GetRealloc()
{
	return _reallocFunc;
}

freeFunc MemoryManager::GetFree()
{
	return _freeFunc;
}
