#include <LDL/Graphics/Gpu/GpuFunctions.hpp>
#include "../../Platforms/Windows/Graphics/GL1/GpuFunctionsImpl.hpp"

using namespace LDL::Graphics;

GpuFunctions::GpuFunctions() :
    _GpuFunctionsImpl(new GpuFunctionsImpl("opengl32"))
{
}

void* GpuFunctions::Function(const char* name)
{
    return _GpuFunctionsImpl->Function(name);
}