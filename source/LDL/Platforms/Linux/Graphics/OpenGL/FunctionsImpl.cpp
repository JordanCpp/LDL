#include "FunctionsImpl.hpp"
#include "../GLX.hpp"
#include <stdexcept>

using namespace LDL::Core;
using namespace LDL::Graphics;

OpenGLFunctionsImpl::OpenGLFunctionsImpl(const char* path) :
    _Library(path)
{
}

LDL::VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    LDL::VoidFuncPtr result = glXGetProcAddress((const GLubyte*)name);

    if (result == NULL)
        throw std::runtime_error("glXGetProcAddress failes: " + std::string(name));

    return result;
}