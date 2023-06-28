#include "LibraryImpl.hpp"
#include <assert.h>
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;

LibraryImpl::LibraryImpl(const std::string& path)
{
}

LibraryImpl::~LibraryImpl()
{
}

LDL::VoidFuncPtr LibraryImpl::Function(const std::string& name)
{
    return NULL;
}