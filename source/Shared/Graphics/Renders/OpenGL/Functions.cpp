#include <LDL/OpenGL/OpenGL_Functions.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/OpenGLFunctionsImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Graphics/OpenGL/FunctionsImpl.hpp"
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
