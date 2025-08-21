#include "FunctionsImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../GLX.hpp"

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
        throw RuntimeError("glXGetProcAddress failes: " + std::string(name));

    return result;
}