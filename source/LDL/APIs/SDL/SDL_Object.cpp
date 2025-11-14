// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL/SDL_loadso.h>
#include <LDL/Core/Library.hpp>
#include <LDL/STL/new.hpp>

using namespace LDL;

void* SDL_LoadObject(const char* sofile)
{
	void* memory = SDL_malloc(sizeof(Library));

	Library* library = new(memory) Library(sofile);

	return (void*)library;
}

void* SDL_LoadFunction(void* handle, const char* name)
{
	Library* library = (Library*)handle;

	return (void*)library->Function(name);
}

void SDL_UnloadObject(void* handle)
{
	if (handle)
	{
		Library* library = (Library*)handle;

		library->~Library();
		SDL_free(handle);
	}
}
