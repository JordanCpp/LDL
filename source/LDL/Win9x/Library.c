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

#include <stdlib.h>
#include <LDL/Library.h>
#include <LDL/Win9x/WinX.h>

struct LDL_Library
{
	HMODULE     Module;
	LDL_Result* Result;
};

LDL_Library* LDL_LibraryNew(LDL_Result* result)
{
	LDL_Library* library = (LDL_Library*)malloc(sizeof(LDL_Library));

	if (library)
	{
		library->Module = NULL;
		library->Result = result;

		return library;
	}

	return NULL;
}

void LDL_LibraryFree(LDL_Library* library)
{
	if (library)
	{
		if (library->Module != NULL)
		{
			FreeLibrary(library->Module);
		}

		free(library);
	}
}

bool LDL_LibraryOpen(LDL_Library* library, const char* path)
{
	if (library)
	{
		LDL_LibraryClose(library);

		library->Module = LoadLibraryA(path);

		if (library->Module == NULL && library->Result)
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
	if (library && library->Module != NULL)
	{
		FreeLibrary(library->Module);
		library->Module = NULL;
	}
}

LDL_VoidFuncPtr LDL_LibraryGetFunction(LDL_Library* library, const char* name)
{
	LDL_VoidFuncPtr result = NULL;

	if (library)
	{
		if (library->Module)
		{
			result = (LDL_VoidFuncPtr)GetProcAddress(library->Module, name);

			if (result == NULL && library->Result)
			{
				LDL_ResultAddMessage(library->Result, "GetProcAddress failed: %s\n", name);
			}
		}
	}

	return result;
}
