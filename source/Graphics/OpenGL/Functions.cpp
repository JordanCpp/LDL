#include <LDL/OpenGL/OpenGL_Functions.hpp>
#include "../../Platforms/Windows/Graphics/OpenGL/FunctionsImpl.hpp"

using namespace LDL::Graphics;

Functions::Functions() :
    _GpuFunctionsImpl(new FunctionsImpl("opengl32"))
{
}

LDL::VoidFuncPtr Functions::Function(const char* name)
{
    return _GpuFunctionsImpl->Function(name);
}