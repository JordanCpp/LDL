#ifndef LDL_Graphics_Window_hpp
#define LDL_Graphics_Window_hpp

#if (_WIN32 || _WIN64)
#include <LDL/Platforms/Windows/Graphics/Window.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::Windows::Window Window;
	}
}
#else
#error Not implementation: Graphics::Window
#endif

#endif 