#include "LibraryImpl.hpp"
#include <assert.h>
#include <dlfcn.h>

using namespace LDL::Core;

LibraryImpl::LibraryImpl(const std::string& path)
{
    _Library = dlopen(path.c_str(), RTLD_NOW | RTLD_GLOBAL);
}

LibraryImpl::~LibraryImpl()
{
    if (_Library != NULL)
        dlclose(_Library);
}

LDL::VoidFuncPtr LibraryImpl::Function(const std::string& name)
{
    return (LDL::VoidFuncPtr)dlsym(_Library, name.c_str());
}