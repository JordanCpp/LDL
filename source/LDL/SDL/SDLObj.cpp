// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL/SDL_loadso.h>
#include <LDL/Library.hpp>
#include <LDL/New.hpp>

void* SDL_LoadObject(const char* sofile)
{
	LDL_ILibrary* library = CreateLibraryImpl(sofile);

	return (void*)library;
}

void* SDL_LoadFunction(void* handle, const char* name)
{
	LDL_ILibrary* library = (LDL_ILibrary*)handle;

	return (void*)library->Function(name);
}

void SDL_UnloadObject(void* handle)
{
	if (handle)
	{
		LDL_ILibrary* library = (LDL_ILibrary*)handle;

		delete library;

		SDL_free(handle);
	}
}
