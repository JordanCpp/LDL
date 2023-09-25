#include "Library.hpp"
#include <assert.h>
#include <dlfcn.h>

LDL_Library::LDL_Library(const char* path) :
	_Library(NULL)
{
  _Library = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
}

LDL_Library::~LDL_Library()
{
	if (_Library != NULL)
	{
		dlclose(_Library);
	}
}

LDL_VoidFuncPtr LDL_Library::Function(const char *name)
{
	LDL_VoidFuncPtr result = (LDL_VoidFuncPtr)dlsym(_Library, name);

	return result;
}