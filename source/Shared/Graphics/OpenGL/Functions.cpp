#include <LDL/OpenGL/OpenGL_Functions.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/OpenGL/FunctionsImpl.hpp"
#elif defined(__unix__)
#include "../../Platforms/Linux/Graphics/OpenGL/FunctionsImpl.hpp"
#endif


using namespace LDL::Graphics;

OpenGLFunctions::OpenGLFunctions() :
    _FunctionsImpl(new OpenGLFunctionsImpl("opengl32"))
{
}

LDL::VoidFuncPtr OpenGLFunctions::Function(const char* name)
{
    return _FunctionsImpl->Function(name);
}