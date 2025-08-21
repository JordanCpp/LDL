#include <LDL/APIs/OpenGL/OpenGL_Functions.hpp>

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Graphics/OpenGLFunctionsImpl.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Graphics/OpenGL/FunctionsImpl.hpp>
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
