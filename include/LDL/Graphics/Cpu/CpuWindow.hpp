#ifndef LDL_Graphics_Cpu_CpuWindow_hpp
#define LDL_Graphics_Cpu_CpuWindow_hpp

#if (_WIN32 || _WIN64)
#include <LDL/Platforms/Windows/Graphics/CpuWindow.hpp>

namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::Windows::CpuWindow CpuWindow;
	}
}
#else
#error Not support: OpenGL
#endif  

#endif    