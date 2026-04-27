/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <dlfcn.h> 
#include <stdlib.h>
#include <LDL/Library.h>

typedef struct LDL_Library
{
	LDL_Result* Result;
	void*       Library;
} LDL_Library;

LDL_Library* LDL_LibraryNew(LDL_Result* result)
{
	LDL_Library* library = (LDL_Library*)malloc(sizeof(LDL_Library));

	if (library)
	{
		library->Library = NULL;
		library->Result  = result;

		return library;
	}

	return NULL;
}

void LDL_LibraryFree(LDL_Library* library)
{
	if (library)
	{
		if (library->Library != NULL)
		{
			dlclose(library->Library);
		}

		free(library);
	}
}

bool LDL_LibraryOpen(LDL_Library* library, const char* path)
{
	if (library)
	{
		LDL_LibraryClose(library);

		library->Library = dlopen(path, RTLD_NOW | RTLD_GLOBAL);

		if (library->Library == NULL && library->Result)
		{
			LDL_ResultAddMessage(library->Result, "Load library failed: %s\n", path);

			return false;
		}

		return true;
	}

	return false;
}

void LDL_LibraryClose(LDL_Library* library)
{
	if (library && library->Library != NULL)
	{
		dlclose(library->Library);
		library->Library = NULL;
	}
}

LDL_VoidFuncPtr LDL_LibraryGetFunction(LDL_Library* library, const char* name)
{
	LDL_VoidFuncPtr result = NULL;

	if (library)
	{
		if (library->Library)
		{
			result = (LDL_VoidFuncPtr)dlsym(library->Library, name);

			if (result == NULL && library->Result)
			{
				LDL_ResultAddMessage(library->Result, "GetProcAddress failed: %s\n", name);
			}
		}
	}

	return result;
}
