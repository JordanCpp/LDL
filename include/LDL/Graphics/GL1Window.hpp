#ifndef LDL_Graphics_GL1Window_hpp
#define LDL_Graphics_GL1Window_hpp

#if (_WIN32 || _WIN64)
#include <LDL/Platforms/Windows/Graphics/GL1Window.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::Windows::GL1Window GL1Window;
	}
}
#else
#error Not implementation: Graphics::Window
#endif

#endif 