#include "LibraryImpl.hpp"
#include <assert.h>
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;

LibraryImpl::LibraryImpl(const std::string& path) :
    _HMODULE(NULL)
{
    _HMODULE = LoadLibrary(path.c_str());

    assert(_HMODULE != NULL);
}

LibraryImpl::~LibraryImpl()
{
    assert(_HMODULE != NULL);

    FreeLibrary(_HMODULE);
}

LDL::VoidFuncPtr LibraryImpl::Function(const std::string& name)
{
    LDL::VoidFuncPtr result = (LDL::VoidFuncPtr)GetProcAddress(_HMODULE, name.c_str());

    if (result == NULL)
        throw LDL::Core::RuntimeError("GetProcAddress failed: " + name);

    return result;
}
