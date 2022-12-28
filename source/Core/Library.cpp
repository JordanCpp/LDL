#include <LDL/Core/Library.hpp>
#include "../Platforms/Windows/Core/LibraryImpl.hpp"

LDL::Core::Library::Library(const std::string& path) :
    _LibraryImpl(new LDL::Core::LibraryImpl(path))
{
}

LDL::Core::Library::~Library()
{
    _LibraryImpl->~LibraryImpl();
}

void* LDL::Core::Library::Function(const std::string& name)
{
    return _LibraryImpl->Function(name);
}