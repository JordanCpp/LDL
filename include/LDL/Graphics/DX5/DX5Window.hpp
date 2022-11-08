#ifndef LDL_Graphics_DX5Window_hpp
#define LDL_Graphics_DX5Window_hpp

#if ((_WIN32 || _WIN64) && LDL_GPU_SUPPORT_DIRECTX5)
#include <LDL/Platforms/Windows/Graphics/DX5Window.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::Windows::DX5Window DX5Window;
	}
}
#else
#error Not implementation: Graphics::Window
#endif

#endif 