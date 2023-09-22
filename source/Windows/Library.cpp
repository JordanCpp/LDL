#include "Library.hpp"
#include <assert.h>

LDL_Library::LDL_Library(const char* path) :
	_HMODULE(NULL)
{
	_HMODULE = LoadLibrary(path);

	assert(_HMODULE != NULL);
}

LDL_Library::~LDL_Library()
{
	assert(_HMODULE != NULL);

	FreeLibrary(_HMODULE);
}

LDL_VoidFuncPtr LDL_Library::Function(const char* name)
{
	LDL_VoidFuncPtr result = (LDL_VoidFuncPtr)GetProcAddress(_HMODULE, name);

	return result;
}