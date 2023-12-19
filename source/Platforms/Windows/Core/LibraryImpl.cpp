#include "LibraryImpl.hpp"
#include <assert.h>
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL;
using namespace LDL::Core;

LibraryImpl::LibraryImpl(const std::string& path) :
    _HMODULE(NULL)
{
    _HMODULE = LoadLibrary(path.c_str());

    if (_HMODULE == NULL)
        throw RuntimeError("LoadLibrary failed: " + path);
}

LibraryImpl::~LibraryImpl()
{
    assert(_HMODULE != NULL);

    FreeLibrary(_HMODULE);
}

VoidFuncPtr LibraryImpl::Function(const std::string& name)
{
    VoidFuncPtr result = (VoidFuncPtr)GetProcAddress(_HMODULE, name.c_str());

    if (result == NULL)
        throw RuntimeError("GetProcAddress failed: " + name);

    return result;
}
