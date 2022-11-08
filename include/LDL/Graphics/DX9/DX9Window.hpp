#ifndef LDL_Graphics_DX9Window_hpp
#define LDL_Graphics_DX9Window_hpp

#if ((_WIN32 || _WIN64) && LDL_GPU_SUPPORT_DIRECTX9)
#include <LDL/Platforms/Windows/Graphics/DX9Window.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::Windows::DX9Window DX9Window;
	}
}
#else
#error Not implementation: Graphics::Window
#endif

#endif 