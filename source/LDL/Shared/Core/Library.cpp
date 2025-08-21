#include <LDL/Core/Library.hpp>

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Core/LibraryImpl.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Core/LibraryImpl.hpp>
#endif

using namespace LDL::Core;

Library::Library(const std::string& path) :
    _impl(new LDL::Core::LibraryImpl(path))
{
}

Library::~Library()
{
    _impl->~LibraryImpl();
}

LDL::VoidFuncPtr Library::Function(const std::string& name)
{
    return (LDL::VoidFuncPtr)_impl->Function(name);
}
