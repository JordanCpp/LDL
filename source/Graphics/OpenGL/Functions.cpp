#include <LDL/OpenGL/OpenGL_Functions.hpp>
#include "../../Platforms/Windows/Graphics/OpenGL/FunctionsImpl.hpp"

using namespace LDL::Graphics;

OpenGLFunctions::OpenGLFunctions() :
    _FunctionsImpl(new OpenGLFunctionsImpl("opengl32"))
{
}

LDL::VoidFuncPtr OpenGLFunctions::Function(const char* name)
{
    return _FunctionsImpl->Function(name);
}