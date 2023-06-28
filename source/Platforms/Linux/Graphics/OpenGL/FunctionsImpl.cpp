#include "FunctionsImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

OpenGLFunctionsImpl::OpenGLFunctionsImpl(const char* path) :
    _Library(path)
{
}

LDL::VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    return NULL;
}