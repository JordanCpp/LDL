
#include <LDL/Library.h>
#include <LDL/Win9x/WinX.h>

typedef struct LDL_Library
{
	HMODULE     Module;
	LDL_Result* Result;
} LDL_Library;

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
	library->Module = LoadLibrary(path);

	if (library->Module == NULL)
	{
		LDL_ResultAddMessage(library->Result, "Load library failed: %s\n", path);

		return false;
	}

	return true;
}

void LDL_LibraryClose(LDL_Library* library)
{
	if (library->Module != NULL)
	{
		FreeLibrary(library->Module);
	}
}

LDL_VoidFuncPtr LDL_LibraryGetFunction(LDL_Library* library, const char* name)
{
	LDL_VoidFuncPtr result = NULL;

	if (library->Module)
	{
		result = (LDL_VoidFuncPtr)GetProcAddress(library->Module, name);

		if (result == NULL)
		{
			LDL_ResultAddMessage(library->Result, "GetProcAddress failed: %s\n", name);
		}
	}

	return result;
}
