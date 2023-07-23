#include <LDL/Core/Library.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Core/LibraryImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Core/LibraryImpl.hpp"
#endif

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
