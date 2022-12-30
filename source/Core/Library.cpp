#include <LDL/Core/Library.hpp>
#include "../Platforms/Windows/Core/LibraryImpl.hpp"

using namespace LDL::Core;

Library::Library(const std::string& path) :
    _LibraryImpl(new LDL::Core::LibraryImpl(path))
{
}

Library::~Library()
{
    _LibraryImpl->~LibraryImpl();
}

LDL::VoidFuncPtr Library::Function(const std::string& name)
{
    return (LDL::VoidFuncPtr)_LibraryImpl->Function(name);
}