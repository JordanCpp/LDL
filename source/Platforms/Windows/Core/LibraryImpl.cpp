#include "LibraryImpl.hpp"
#include <assert.h>
#include <LDL/Core/RuntimeError.hpp>

LDL::Core::LibraryImpl::LibraryImpl(const std::string& path) :
    _HMODULE(NULL)
{
    _HMODULE = LoadLibrary(path.c_str());

    assert(_HMODULE != NULL);
}

LDL::Core::LibraryImpl::~LibraryImpl()
{
    assert(_HMODULE != NULL);

    FreeLibrary(_HMODULE);
}

void* LDL::Core::LibraryImpl::Function(const std::string& name)
{
    void* result = GetProcAddress(_HMODULE, name.c_str());

    if (result == NULL)
        throw LDL::Core::RuntimeError("GetProcAddress failed: " + name);

    return result;
}