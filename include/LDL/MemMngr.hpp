// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_MemoryManager_hpp
#define LDL_Core_MemoryManager_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

typedef void* (*mallocFunc) (size_t size);
typedef void* (*callocFunc) (size_t nmemb, size_t size);
typedef void* (*reallocFunc)(void* mem, size_t size);
typedef void  (*freeFunc)   (void* mem);

class LDL_LIBRARY LDL_MemoryManager
{
public:
	static LDL_MemoryManager& Instance();
	bool Functions(mallocFunc malloc_func, callocFunc calloc_func, reallocFunc realloc_func, freeFunc free_func);
	mallocFunc  GetMalloc();
	callocFunc  GetCalloc();
	reallocFunc GetRealloc();
	freeFunc    GetFree();
private:
	enum
	{
		SizeOf = 64
	};

	LDL_MemoryManager();
	~LDL_MemoryManager();

	LDL_MemoryManager(const LDL_MemoryManager&);
	LDL_MemoryManager& operator=(const LDL_MemoryManager&);

	mallocFunc  _mallocFunc;
	callocFunc  _callocFunc;
	reallocFunc _reallocFunc;
	freeFunc    _freeFunc;

	static LDL_MemoryManager* _instance;
	static char _bytes[SizeOf];
};

#endif
