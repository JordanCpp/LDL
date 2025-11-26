// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/New.hpp>
#include <LDL/Library.hpp>
#include <LDL/SDL/loadso.h>
#include <LDL/SDL/SDLApp.hpp>

void* SDL_LoadObject(const char* sofile)
{
	LDL_ILibrary* library = LDL_CreateLibrary(App().GetResult());

	if (library->Open(sofile))
	{
		return (void*)library;
	}

	return NULL;
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
	}
}
